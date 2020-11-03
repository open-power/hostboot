/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/eq/reg00002.H $           */
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

#ifndef __EQ_REG00002_H_
#define __EQ_REG00002_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
{
#endif


//>> PREP_[CPLT_STAT0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_STAT0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_STAT0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_STAT0]

//>> GET_[CPLT_STAT0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_STAT0(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_STAT0;
#endif
    return fapi2::getScom(i_target, CPLT_STAT0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_STAT0]

//>> PUT_[CPLT_STAT0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_STAT0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return fapi2::putScom(i_target, CPLT_STAT0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_STAT0]


//>> SET_[CPLT_STAT0_ABIST_DONE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_ABIST_DONE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_ABIST_DONE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_STAT0_ABIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_ABIST_DONE_DC]

//>> SET_[CPLT_STAT0_ABIST_DONE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_ABIST_DONE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_ABIST_DONE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_STAT0_ABIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_ABIST_DONE_DC]

//>> SET_[CPLT_STAT0_ABIST_DONE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_ABIST_DONE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_ABIST_DONE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_STAT0_ABIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_ABIST_DONE_DC]

//>> CLEAR_[CPLT_STAT0_ABIST_DONE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_ABIST_DONE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_ABIST_DONE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_STAT0_ABIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_ABIST_DONE_DC]

//>> GET_[CPLT_STAT0_ABIST_DONE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_ABIST_DONE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_ABIST_DONE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_STAT0_ABIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_ABIST_DONE_DC]

//>> GET_[CPLT_STAT0_ABIST_DONE_DC]
static inline bool GET_CPLT_STAT0_ABIST_DONE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_ABIST_DONE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_STAT0_ABIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_ABIST_DONE_DC]

//>> SET_[CPLT_STAT0_EBIST_DONE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_EBIST_DONE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_EBIST_DONE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_STAT0_EBIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_EBIST_DONE_DC]

//>> SET_[CPLT_STAT0_EBIST_DONE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_EBIST_DONE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_EBIST_DONE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_STAT0_EBIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_EBIST_DONE_DC]

//>> SET_[CPLT_STAT0_EBIST_DONE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_EBIST_DONE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_EBIST_DONE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_STAT0_EBIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_EBIST_DONE_DC]

//>> CLEAR_[CPLT_STAT0_EBIST_DONE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_EBIST_DONE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_EBIST_DONE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_STAT0_EBIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_EBIST_DONE_DC]

//>> GET_[CPLT_STAT0_EBIST_DONE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_EBIST_DONE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_EBIST_DONE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_STAT0_EBIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_EBIST_DONE_DC]

//>> GET_[CPLT_STAT0_EBIST_DONE_DC]
static inline bool GET_CPLT_STAT0_EBIST_DONE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_EBIST_DONE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_STAT0_EBIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_EBIST_DONE_DC]

//>> SET_[CPLT_STAT0_RESERVED_2I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_RESERVED_2I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_RESERVED_2I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_STAT0_RESERVED_2I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_RESERVED_2I]

//>> SET_[CPLT_STAT0_RESERVED_2I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_RESERVED_2I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_RESERVED_2I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_STAT0_RESERVED_2I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_RESERVED_2I]

//>> SET_[CPLT_STAT0_RESERVED_2I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_RESERVED_2I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_RESERVED_2I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_STAT0_RESERVED_2I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_RESERVED_2I]

//>> CLEAR_[CPLT_STAT0_RESERVED_2I]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_RESERVED_2I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_RESERVED_2I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_STAT0_RESERVED_2I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_RESERVED_2I]

//>> GET_[CPLT_STAT0_RESERVED_2I]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_RESERVED_2I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_RESERVED_2I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_STAT0_RESERVED_2I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_RESERVED_2I]

//>> GET_[CPLT_STAT0_RESERVED_2I]
static inline bool GET_CPLT_STAT0_RESERVED_2I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_RESERVED_2I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_STAT0_RESERVED_2I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_RESERVED_2I]

//>> SET_[CPLT_STAT0_RESERVED_3I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_RESERVED_3I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_RESERVED_3I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_STAT0_RESERVED_3I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_RESERVED_3I]

//>> SET_[CPLT_STAT0_RESERVED_3I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_RESERVED_3I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_RESERVED_3I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_STAT0_RESERVED_3I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_RESERVED_3I]

//>> SET_[CPLT_STAT0_RESERVED_3I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_RESERVED_3I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_RESERVED_3I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_STAT0_RESERVED_3I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_RESERVED_3I]

//>> CLEAR_[CPLT_STAT0_RESERVED_3I]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_RESERVED_3I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_RESERVED_3I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_STAT0_RESERVED_3I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_RESERVED_3I]

//>> GET_[CPLT_STAT0_RESERVED_3I]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_RESERVED_3I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_RESERVED_3I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_STAT0_RESERVED_3I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_RESERVED_3I]

//>> GET_[CPLT_STAT0_RESERVED_3I]
static inline bool GET_CPLT_STAT0_RESERVED_3I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_RESERVED_3I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_STAT0_RESERVED_3I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_RESERVED_3I]

//>> SET_[CPLT_STAT0_TC_DIAG_PORT0_OUT]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_TC_DIAG_PORT0_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_TC_DIAG_PORT0_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_STAT0_TC_DIAG_PORT0_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_TC_DIAG_PORT0_OUT]

//>> SET_[CPLT_STAT0_TC_DIAG_PORT0_OUT]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_TC_DIAG_PORT0_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_TC_DIAG_PORT0_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_STAT0_TC_DIAG_PORT0_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_TC_DIAG_PORT0_OUT]

//>> SET_[CPLT_STAT0_TC_DIAG_PORT0_OUT]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_TC_DIAG_PORT0_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_TC_DIAG_PORT0_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_STAT0_TC_DIAG_PORT0_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_TC_DIAG_PORT0_OUT]

//>> CLEAR_[CPLT_STAT0_TC_DIAG_PORT0_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_TC_DIAG_PORT0_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_TC_DIAG_PORT0_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_STAT0_TC_DIAG_PORT0_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_TC_DIAG_PORT0_OUT]

//>> GET_[CPLT_STAT0_TC_DIAG_PORT0_OUT]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_TC_DIAG_PORT0_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_TC_DIAG_PORT0_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_STAT0_TC_DIAG_PORT0_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_TC_DIAG_PORT0_OUT]

//>> GET_[CPLT_STAT0_TC_DIAG_PORT0_OUT]
static inline bool GET_CPLT_STAT0_TC_DIAG_PORT0_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_TC_DIAG_PORT0_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_STAT0_TC_DIAG_PORT0_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_TC_DIAG_PORT0_OUT]

//>> SET_[CPLT_STAT0_TC_DIAG_PORT1_OUT]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_TC_DIAG_PORT1_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_TC_DIAG_PORT1_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_STAT0_TC_DIAG_PORT1_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_TC_DIAG_PORT1_OUT]

//>> SET_[CPLT_STAT0_TC_DIAG_PORT1_OUT]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_TC_DIAG_PORT1_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_TC_DIAG_PORT1_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_STAT0_TC_DIAG_PORT1_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_TC_DIAG_PORT1_OUT]

//>> SET_[CPLT_STAT0_TC_DIAG_PORT1_OUT]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_TC_DIAG_PORT1_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_TC_DIAG_PORT1_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_STAT0_TC_DIAG_PORT1_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_TC_DIAG_PORT1_OUT]

//>> CLEAR_[CPLT_STAT0_TC_DIAG_PORT1_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_TC_DIAG_PORT1_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_TC_DIAG_PORT1_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_STAT0_TC_DIAG_PORT1_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_TC_DIAG_PORT1_OUT]

//>> GET_[CPLT_STAT0_TC_DIAG_PORT1_OUT]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_TC_DIAG_PORT1_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_TC_DIAG_PORT1_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_STAT0_TC_DIAG_PORT1_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_TC_DIAG_PORT1_OUT]

//>> GET_[CPLT_STAT0_TC_DIAG_PORT1_OUT]
static inline bool GET_CPLT_STAT0_TC_DIAG_PORT1_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_TC_DIAG_PORT1_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_STAT0_TC_DIAG_PORT1_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_TC_DIAG_PORT1_OUT]

//>> SET_[CPLT_STAT0_RESERVED_6I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_RESERVED_6I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_RESERVED_6I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_STAT0_RESERVED_6I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_RESERVED_6I]

//>> SET_[CPLT_STAT0_RESERVED_6I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_RESERVED_6I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_RESERVED_6I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_STAT0_RESERVED_6I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_RESERVED_6I]

//>> SET_[CPLT_STAT0_RESERVED_6I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_RESERVED_6I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_RESERVED_6I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_STAT0_RESERVED_6I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_RESERVED_6I]

//>> CLEAR_[CPLT_STAT0_RESERVED_6I]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_RESERVED_6I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_RESERVED_6I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_STAT0_RESERVED_6I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_RESERVED_6I]

//>> GET_[CPLT_STAT0_RESERVED_6I]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_RESERVED_6I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_RESERVED_6I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_STAT0_RESERVED_6I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_RESERVED_6I]

//>> GET_[CPLT_STAT0_RESERVED_6I]
static inline bool GET_CPLT_STAT0_RESERVED_6I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_RESERVED_6I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_STAT0_RESERVED_6I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_RESERVED_6I]

//>> SET_[CPLT_STAT0_CC_CTRL_OPCG_DONE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_CC_CTRL_OPCG_DONE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_STAT0_CC_CTRL_OPCG_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_CC_CTRL_OPCG_DONE_DC]

//>> SET_[CPLT_STAT0_CC_CTRL_OPCG_DONE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_CC_CTRL_OPCG_DONE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_STAT0_CC_CTRL_OPCG_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_CC_CTRL_OPCG_DONE_DC]

//>> SET_[CPLT_STAT0_CC_CTRL_OPCG_DONE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_CC_CTRL_OPCG_DONE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_STAT0_CC_CTRL_OPCG_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_CC_CTRL_OPCG_DONE_DC]

//>> CLEAR_[CPLT_STAT0_CC_CTRL_OPCG_DONE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_CC_CTRL_OPCG_DONE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_STAT0_CC_CTRL_OPCG_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_CC_CTRL_OPCG_DONE_DC]

//>> GET_[CPLT_STAT0_CC_CTRL_OPCG_DONE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_CC_CTRL_OPCG_DONE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_STAT0_CC_CTRL_OPCG_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_CC_CTRL_OPCG_DONE_DC]

//>> GET_[CPLT_STAT0_CC_CTRL_OPCG_DONE_DC]
static inline bool GET_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_CC_CTRL_OPCG_DONE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_STAT0_CC_CTRL_OPCG_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_CC_CTRL_OPCG_DONE_DC]

//>> SET_[CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC]

//>> SET_[CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC]

//>> SET_[CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC]

//>> CLEAR_[CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC]

//>> GET_[CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC]

//>> GET_[CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC]
static inline bool GET_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC]

//>> SET_[CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR]

//>> SET_[CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR]

//>> SET_[CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR]

//>> CLEAR_[CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR]

//>> GET_[CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR]

//>> GET_[CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR]
static inline bool GET_CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR]

//>> SET_[CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR]

//>> SET_[CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR]

//>> SET_[CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR]

//>> CLEAR_[CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR]

//>> GET_[CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR]

//>> GET_[CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR]
static inline bool GET_CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR]

//>> SET_[CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED]

//>> SET_[CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED]

//>> SET_[CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED]

//>> CLEAR_[CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED]

//>> GET_[CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED]

//>> GET_[CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED]
static inline bool GET_CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED]

//>> SET_[CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT,
           CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT]

//>> SET_[CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT,
           CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT]

//>> GET_[CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT,
           CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT]

//>> SET_[CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID]

//>> SET_[CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID]

//>> SET_[CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID]

//>> CLEAR_[CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID]

//>> GET_[CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID]

//>> GET_[CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID]
static inline bool GET_CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID]

//>> SET_[CPLT_STAT0_GLOBAL_FEH_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_GLOBAL_FEH_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_GLOBAL_FEH_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_STAT0_GLOBAL_FEH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_GLOBAL_FEH_DC]

//>> SET_[CPLT_STAT0_GLOBAL_FEH_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_GLOBAL_FEH_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_GLOBAL_FEH_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_STAT0_GLOBAL_FEH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_GLOBAL_FEH_DC]

//>> SET_[CPLT_STAT0_GLOBAL_FEH_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_GLOBAL_FEH_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_GLOBAL_FEH_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_STAT0_GLOBAL_FEH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_GLOBAL_FEH_DC]

//>> CLEAR_[CPLT_STAT0_GLOBAL_FEH_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_GLOBAL_FEH_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_GLOBAL_FEH_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_STAT0_GLOBAL_FEH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_GLOBAL_FEH_DC]

//>> GET_[CPLT_STAT0_GLOBAL_FEH_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_GLOBAL_FEH_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_GLOBAL_FEH_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_STAT0_GLOBAL_FEH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_GLOBAL_FEH_DC]

//>> GET_[CPLT_STAT0_GLOBAL_FEH_DC]
static inline bool GET_CPLT_STAT0_GLOBAL_FEH_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_GLOBAL_FEH_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_STAT0_GLOBAL_FEH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_GLOBAL_FEH_DC]

//>> SET_[CPLT_STAT0_FREE_USAGE_25I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_25I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_25I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_25I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_25I]

//>> SET_[CPLT_STAT0_FREE_USAGE_25I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_25I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_25I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_25I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_25I]

//>> SET_[CPLT_STAT0_FREE_USAGE_25I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_25I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_FREE_USAGE_25I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_25I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_25I]

//>> CLEAR_[CPLT_STAT0_FREE_USAGE_25I]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_FREE_USAGE_25I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_FREE_USAGE_25I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_25I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_FREE_USAGE_25I]

//>> GET_[CPLT_STAT0_FREE_USAGE_25I]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_FREE_USAGE_25I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_FREE_USAGE_25I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_25I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_25I]

//>> GET_[CPLT_STAT0_FREE_USAGE_25I]
static inline bool GET_CPLT_STAT0_FREE_USAGE_25I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_FREE_USAGE_25I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_25I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_25I]

//>> SET_[CPLT_STAT0_FREE_USAGE_26I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_26I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_26I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_26I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_26I]

//>> SET_[CPLT_STAT0_FREE_USAGE_26I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_26I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_26I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_26I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_26I]

//>> SET_[CPLT_STAT0_FREE_USAGE_26I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_26I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_FREE_USAGE_26I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_26I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_26I]

//>> CLEAR_[CPLT_STAT0_FREE_USAGE_26I]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_FREE_USAGE_26I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_FREE_USAGE_26I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_26I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_FREE_USAGE_26I]

//>> GET_[CPLT_STAT0_FREE_USAGE_26I]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_FREE_USAGE_26I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_FREE_USAGE_26I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_26I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_26I]

//>> GET_[CPLT_STAT0_FREE_USAGE_26I]
static inline bool GET_CPLT_STAT0_FREE_USAGE_26I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_FREE_USAGE_26I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_26I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_26I]

//>> SET_[CPLT_STAT0_FREE_USAGE_27I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_27I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_27I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_27I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_27I]

//>> SET_[CPLT_STAT0_FREE_USAGE_27I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_27I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_27I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_27I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_27I]

//>> SET_[CPLT_STAT0_FREE_USAGE_27I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_27I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_FREE_USAGE_27I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_27I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_27I]

//>> CLEAR_[CPLT_STAT0_FREE_USAGE_27I]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_FREE_USAGE_27I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_FREE_USAGE_27I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_27I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_FREE_USAGE_27I]

//>> GET_[CPLT_STAT0_FREE_USAGE_27I]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_FREE_USAGE_27I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_FREE_USAGE_27I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_27I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_27I]

//>> GET_[CPLT_STAT0_FREE_USAGE_27I]
static inline bool GET_CPLT_STAT0_FREE_USAGE_27I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_FREE_USAGE_27I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_27I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_27I]

//>> SET_[CPLT_STAT0_FREE_USAGE_28I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_28I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_28I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_28I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_28I]

//>> SET_[CPLT_STAT0_FREE_USAGE_28I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_28I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_28I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_28I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_28I]

//>> SET_[CPLT_STAT0_FREE_USAGE_28I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_28I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_FREE_USAGE_28I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_28I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_28I]

//>> CLEAR_[CPLT_STAT0_FREE_USAGE_28I]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_FREE_USAGE_28I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_FREE_USAGE_28I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_28I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_FREE_USAGE_28I]

//>> GET_[CPLT_STAT0_FREE_USAGE_28I]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_FREE_USAGE_28I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_FREE_USAGE_28I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_28I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_28I]

//>> GET_[CPLT_STAT0_FREE_USAGE_28I]
static inline bool GET_CPLT_STAT0_FREE_USAGE_28I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_FREE_USAGE_28I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_28I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_28I]

//>> SET_[CPLT_STAT0_FREE_USAGE_29I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_29I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_29I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_29I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_29I]

//>> SET_[CPLT_STAT0_FREE_USAGE_29I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_29I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_29I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_29I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_29I]

//>> SET_[CPLT_STAT0_FREE_USAGE_29I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_29I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_FREE_USAGE_29I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_29I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_29I]

//>> CLEAR_[CPLT_STAT0_FREE_USAGE_29I]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_FREE_USAGE_29I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_FREE_USAGE_29I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_29I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_FREE_USAGE_29I]

//>> GET_[CPLT_STAT0_FREE_USAGE_29I]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_FREE_USAGE_29I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_FREE_USAGE_29I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_29I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_29I]

//>> GET_[CPLT_STAT0_FREE_USAGE_29I]
static inline bool GET_CPLT_STAT0_FREE_USAGE_29I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_FREE_USAGE_29I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_29I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_29I]

//>> SET_[CPLT_STAT0_FREE_USAGE_30I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_30I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_30I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_30I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_30I]

//>> SET_[CPLT_STAT0_FREE_USAGE_30I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_30I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_30I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_30I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_30I]

//>> SET_[CPLT_STAT0_FREE_USAGE_30I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_30I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_FREE_USAGE_30I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_30I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_30I]

//>> CLEAR_[CPLT_STAT0_FREE_USAGE_30I]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_FREE_USAGE_30I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_FREE_USAGE_30I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_30I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_FREE_USAGE_30I]

//>> GET_[CPLT_STAT0_FREE_USAGE_30I]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_FREE_USAGE_30I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_FREE_USAGE_30I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_30I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_30I]

//>> GET_[CPLT_STAT0_FREE_USAGE_30I]
static inline bool GET_CPLT_STAT0_FREE_USAGE_30I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_FREE_USAGE_30I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_30I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_30I]

//>> SET_[CPLT_STAT0_FREE_USAGE_31I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_31I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_31I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_31I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_31I]

//>> SET_[CPLT_STAT0_FREE_USAGE_31I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_31I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_31I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_31I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_31I]

//>> SET_[CPLT_STAT0_FREE_USAGE_31I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_31I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_FREE_USAGE_31I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_31I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_31I]

//>> CLEAR_[CPLT_STAT0_FREE_USAGE_31I]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_FREE_USAGE_31I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_FREE_USAGE_31I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_31I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_FREE_USAGE_31I]

//>> GET_[CPLT_STAT0_FREE_USAGE_31I]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_FREE_USAGE_31I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_FREE_USAGE_31I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_31I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_31I]

//>> GET_[CPLT_STAT0_FREE_USAGE_31I]
static inline bool GET_CPLT_STAT0_FREE_USAGE_31I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_FREE_USAGE_31I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_STAT0_FREE_USAGE_31I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_31I]

//>> PREP_[EPS_THERM_WSUB2_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_THERM_WSUB2_MODE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB2_MODE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EPS_THERM_WSUB2_MODE_REG]

//>> GET_[EPS_THERM_WSUB2_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_THERM_WSUB2_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB2_MODE_REG;
#endif
    return fapi2::getScom(i_target, EPS_THERM_WSUB2_MODE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EPS_THERM_WSUB2_MODE_REG]

//>> PUT_[EPS_THERM_WSUB2_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_THERM_WSUB2_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return fapi2::putScom(i_target, EPS_THERM_WSUB2_MODE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_THERM_WSUB2_MODE_REG]


//>> SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]

//>> CLEAR_[EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]

//>> GET_[EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]

//>> GET_[EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]
static inline bool GET_EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT]

//>> CLEAR_[EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT]

//>> GET_[EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT]

//>> GET_[EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT]
static inline bool GET_EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA,
           EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA,
           EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA]

//>> GET_[EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA,
           EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA]

//>> CLEAR_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA]

//>> GET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA]

//>> GET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA]
static inline bool GET_EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT,
           EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT,
           EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT]

//>> GET_[EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT,
           EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA,
           EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA,
           EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA]

//>> GET_[EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA,
           EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE]

//>> CLEAR_[EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE]

//>> GET_[EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE]

//>> GET_[EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE]
static inline bool GET_EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL]

//>> CLEAR_[EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL]

//>> GET_[EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL]

//>> GET_[EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL]
static inline bool GET_EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK]

//>> CLEAR_[EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK]

//>> GET_[EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK]

//>> GET_[EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK]
static inline bool GET_EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL,
           EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL,
           EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL]

//>> GET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL,
           EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1,
           EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1,
           EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1]

//>> GET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1,
           EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2,
           EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2,
           EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2]

//>> GET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2,
           EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3]

//>> SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3]

//>> CLEAR_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3]

//>> GET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3]

//>> GET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3]
static inline bool GET_EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_MODE_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3]

//>> PREP_[QME_DUCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_DUCR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_DUCR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_DUCR]

//>> GET_[QME_DUCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_DUCR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_DUCR;
#endif
    return fapi2::getScom(i_target, QME_DUCR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_DUCR]

//>> PUT_[QME_DUCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_DUCR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return fapi2::putScom(i_target, QME_DUCR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_DUCR]


//>> SET_[QME_DUCR_FDCR_DELAY_C0]
static inline fapi2::buffer<uint64_t>& SET_QME_DUCR_FDCR_DELAY_C0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return o_data.insertFromRight<QME_DUCR_FDCR_DELAY_C0,
           QME_DUCR_FDCR_DELAY_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_DUCR_FDCR_DELAY_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DUCR_FDCR_DELAY_C0]

//>> SET_[QME_DUCR_FDCR_DELAY_C0]
static inline fapi2::buffer<uint64_t>& SET_QME_DUCR_FDCR_DELAY_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return o_data.insertFromRight<QME_DUCR_FDCR_DELAY_C0,
           QME_DUCR_FDCR_DELAY_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_DUCR_FDCR_DELAY_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DUCR_FDCR_DELAY_C0]

//>> GET_[QME_DUCR_FDCR_DELAY_C0]
static inline fapi2::buffer<uint64_t>& GET_QME_DUCR_FDCR_DELAY_C0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return i_data.extractToRight<QME_DUCR_FDCR_DELAY_C0,
           QME_DUCR_FDCR_DELAY_C0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_DUCR_FDCR_DELAY_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_DUCR_FDCR_DELAY_C0]

//>> SET_[QME_DUCR_FDCR_DELAY_C1]
static inline fapi2::buffer<uint64_t>& SET_QME_DUCR_FDCR_DELAY_C1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return o_data.insertFromRight<QME_DUCR_FDCR_DELAY_C1,
           QME_DUCR_FDCR_DELAY_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_DUCR_FDCR_DELAY_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DUCR_FDCR_DELAY_C1]

//>> SET_[QME_DUCR_FDCR_DELAY_C1]
static inline fapi2::buffer<uint64_t>& SET_QME_DUCR_FDCR_DELAY_C1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return o_data.insertFromRight<QME_DUCR_FDCR_DELAY_C1,
           QME_DUCR_FDCR_DELAY_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_DUCR_FDCR_DELAY_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DUCR_FDCR_DELAY_C1]

//>> GET_[QME_DUCR_FDCR_DELAY_C1]
static inline fapi2::buffer<uint64_t>& GET_QME_DUCR_FDCR_DELAY_C1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return i_data.extractToRight<QME_DUCR_FDCR_DELAY_C1,
           QME_DUCR_FDCR_DELAY_C1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_DUCR_FDCR_DELAY_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_DUCR_FDCR_DELAY_C1]

//>> SET_[QME_DUCR_FDCR_DELAY_C2]
static inline fapi2::buffer<uint64_t>& SET_QME_DUCR_FDCR_DELAY_C2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return o_data.insertFromRight<QME_DUCR_FDCR_DELAY_C2,
           QME_DUCR_FDCR_DELAY_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_DUCR_FDCR_DELAY_C2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DUCR_FDCR_DELAY_C2]

//>> SET_[QME_DUCR_FDCR_DELAY_C2]
static inline fapi2::buffer<uint64_t>& SET_QME_DUCR_FDCR_DELAY_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return o_data.insertFromRight<QME_DUCR_FDCR_DELAY_C2,
           QME_DUCR_FDCR_DELAY_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_DUCR_FDCR_DELAY_C2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DUCR_FDCR_DELAY_C2]

//>> GET_[QME_DUCR_FDCR_DELAY_C2]
static inline fapi2::buffer<uint64_t>& GET_QME_DUCR_FDCR_DELAY_C2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return i_data.extractToRight<QME_DUCR_FDCR_DELAY_C2,
           QME_DUCR_FDCR_DELAY_C2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_DUCR_FDCR_DELAY_C2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_DUCR_FDCR_DELAY_C2]

//>> SET_[QME_DUCR_FDCR_DELAY_C3]
static inline fapi2::buffer<uint64_t>& SET_QME_DUCR_FDCR_DELAY_C3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return o_data.insertFromRight<QME_DUCR_FDCR_DELAY_C3,
           QME_DUCR_FDCR_DELAY_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_DUCR_FDCR_DELAY_C3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DUCR_FDCR_DELAY_C3]

//>> SET_[QME_DUCR_FDCR_DELAY_C3]
static inline fapi2::buffer<uint64_t>& SET_QME_DUCR_FDCR_DELAY_C3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return o_data.insertFromRight<QME_DUCR_FDCR_DELAY_C3,
           QME_DUCR_FDCR_DELAY_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_DUCR_FDCR_DELAY_C3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DUCR_FDCR_DELAY_C3]

//>> GET_[QME_DUCR_FDCR_DELAY_C3]
static inline fapi2::buffer<uint64_t>& GET_QME_DUCR_FDCR_DELAY_C3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return i_data.extractToRight<QME_DUCR_FDCR_DELAY_C3,
           QME_DUCR_FDCR_DELAY_C3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_DUCR_FDCR_DELAY_C3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_DUCR_FDCR_DELAY_C3]

//>> SET_[QME_DUCR_FDCR_CAL_ADJUST_C0]
static inline fapi2::buffer<uint64_t>& SET_QME_DUCR_FDCR_CAL_ADJUST_C0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return o_data.insertFromRight<QME_DUCR_FDCR_CAL_ADJUST_C0,
           QME_DUCR_FDCR_CAL_ADJUST_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_DUCR_FDCR_CAL_ADJUST_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DUCR_FDCR_CAL_ADJUST_C0]

//>> SET_[QME_DUCR_FDCR_CAL_ADJUST_C0]
static inline fapi2::buffer<uint64_t>& SET_QME_DUCR_FDCR_CAL_ADJUST_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return o_data.insertFromRight<QME_DUCR_FDCR_CAL_ADJUST_C0,
           QME_DUCR_FDCR_CAL_ADJUST_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_DUCR_FDCR_CAL_ADJUST_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DUCR_FDCR_CAL_ADJUST_C0]

//>> GET_[QME_DUCR_FDCR_CAL_ADJUST_C0]
static inline fapi2::buffer<uint64_t>& GET_QME_DUCR_FDCR_CAL_ADJUST_C0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return i_data.extractToRight<QME_DUCR_FDCR_CAL_ADJUST_C0,
           QME_DUCR_FDCR_CAL_ADJUST_C0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_DUCR_FDCR_CAL_ADJUST_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_DUCR_FDCR_CAL_ADJUST_C0]

//>> SET_[QME_DUCR_FDCR_CAL_ADJUST_C1]
static inline fapi2::buffer<uint64_t>& SET_QME_DUCR_FDCR_CAL_ADJUST_C1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return o_data.insertFromRight<QME_DUCR_FDCR_CAL_ADJUST_C1,
           QME_DUCR_FDCR_CAL_ADJUST_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_DUCR_FDCR_CAL_ADJUST_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DUCR_FDCR_CAL_ADJUST_C1]

//>> SET_[QME_DUCR_FDCR_CAL_ADJUST_C1]
static inline fapi2::buffer<uint64_t>& SET_QME_DUCR_FDCR_CAL_ADJUST_C1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return o_data.insertFromRight<QME_DUCR_FDCR_CAL_ADJUST_C1,
           QME_DUCR_FDCR_CAL_ADJUST_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_DUCR_FDCR_CAL_ADJUST_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DUCR_FDCR_CAL_ADJUST_C1]

//>> GET_[QME_DUCR_FDCR_CAL_ADJUST_C1]
static inline fapi2::buffer<uint64_t>& GET_QME_DUCR_FDCR_CAL_ADJUST_C1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return i_data.extractToRight<QME_DUCR_FDCR_CAL_ADJUST_C1,
           QME_DUCR_FDCR_CAL_ADJUST_C1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_DUCR_FDCR_CAL_ADJUST_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_DUCR_FDCR_CAL_ADJUST_C1]

//>> SET_[QME_DUCR_FDCR_CAL_ADJUST_C2]
static inline fapi2::buffer<uint64_t>& SET_QME_DUCR_FDCR_CAL_ADJUST_C2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return o_data.insertFromRight<QME_DUCR_FDCR_CAL_ADJUST_C2,
           QME_DUCR_FDCR_CAL_ADJUST_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_DUCR_FDCR_CAL_ADJUST_C2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DUCR_FDCR_CAL_ADJUST_C2]

//>> SET_[QME_DUCR_FDCR_CAL_ADJUST_C2]
static inline fapi2::buffer<uint64_t>& SET_QME_DUCR_FDCR_CAL_ADJUST_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return o_data.insertFromRight<QME_DUCR_FDCR_CAL_ADJUST_C2,
           QME_DUCR_FDCR_CAL_ADJUST_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_DUCR_FDCR_CAL_ADJUST_C2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DUCR_FDCR_CAL_ADJUST_C2]

//>> GET_[QME_DUCR_FDCR_CAL_ADJUST_C2]
static inline fapi2::buffer<uint64_t>& GET_QME_DUCR_FDCR_CAL_ADJUST_C2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return i_data.extractToRight<QME_DUCR_FDCR_CAL_ADJUST_C2,
           QME_DUCR_FDCR_CAL_ADJUST_C2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_DUCR_FDCR_CAL_ADJUST_C2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_DUCR_FDCR_CAL_ADJUST_C2]

//>> SET_[QME_DUCR_FDCR_CAL_ADJUST_C3]
static inline fapi2::buffer<uint64_t>& SET_QME_DUCR_FDCR_CAL_ADJUST_C3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return o_data.insertFromRight<QME_DUCR_FDCR_CAL_ADJUST_C3,
           QME_DUCR_FDCR_CAL_ADJUST_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_DUCR_FDCR_CAL_ADJUST_C3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DUCR_FDCR_CAL_ADJUST_C3]

//>> SET_[QME_DUCR_FDCR_CAL_ADJUST_C3]
static inline fapi2::buffer<uint64_t>& SET_QME_DUCR_FDCR_CAL_ADJUST_C3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return o_data.insertFromRight<QME_DUCR_FDCR_CAL_ADJUST_C3,
           QME_DUCR_FDCR_CAL_ADJUST_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_DUCR_FDCR_CAL_ADJUST_C3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DUCR_FDCR_CAL_ADJUST_C3]

//>> GET_[QME_DUCR_FDCR_CAL_ADJUST_C3]
static inline fapi2::buffer<uint64_t>& GET_QME_DUCR_FDCR_CAL_ADJUST_C3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return i_data.extractToRight<QME_DUCR_FDCR_CAL_ADJUST_C3,
           QME_DUCR_FDCR_CAL_ADJUST_C3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_DUCR_FDCR_CAL_ADJUST_C3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_DUCR_FDCR_CAL_ADJUST_C3]

//>> SET_[QME_DUCR_CORE_UPDATE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_DUCR_CORE_UPDATE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return o_data.insertFromRight<QME_DUCR_CORE_UPDATE_ENABLE,
           QME_DUCR_CORE_UPDATE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_DUCR_CORE_UPDATE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DUCR_CORE_UPDATE_ENABLE]

//>> SET_[QME_DUCR_CORE_UPDATE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_DUCR_CORE_UPDATE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return o_data.insertFromRight<QME_DUCR_CORE_UPDATE_ENABLE,
           QME_DUCR_CORE_UPDATE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_DUCR_CORE_UPDATE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DUCR_CORE_UPDATE_ENABLE]

//>> GET_[QME_DUCR_CORE_UPDATE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_DUCR_CORE_UPDATE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return i_data.extractToRight<QME_DUCR_CORE_UPDATE_ENABLE,
           QME_DUCR_CORE_UPDATE_ENABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_DUCR_CORE_UPDATE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_DUCR_CORE_UPDATE_ENABLE]

//>> SET_[QME_DUCR_RESERVED_44_63]
static inline fapi2::buffer<uint64_t>& SET_QME_DUCR_RESERVED_44_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return o_data.insertFromRight<QME_DUCR_RESERVED_44_63,
           QME_DUCR_RESERVED_44_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_DUCR_RESERVED_44_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DUCR_RESERVED_44_63]

//>> SET_[QME_DUCR_RESERVED_44_63]
static inline fapi2::buffer<uint64_t>& SET_QME_DUCR_RESERVED_44_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return o_data.insertFromRight<QME_DUCR_RESERVED_44_63,
           QME_DUCR_RESERVED_44_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_DUCR_RESERVED_44_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DUCR_RESERVED_44_63]

//>> GET_[QME_DUCR_RESERVED_44_63]
static inline fapi2::buffer<uint64_t>& GET_QME_DUCR_RESERVED_44_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DUCR));
#endif
    return i_data.extractToRight<QME_DUCR_RESERVED_44_63,
           QME_DUCR_RESERVED_44_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_DUCR_RESERVED_44_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_DUCR_RESERVED_44_63]

//>> PREP_[QME_EISR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_EISR_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_EISR_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_EISR_RW]

//>> GET_[QME_EISR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_EISR_RW(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_EISR_RW;
#endif
    return fapi2::getScom(i_target, QME_EISR_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_EISR_RW]

//>> PUT_[QME_EISR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_EISR_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_EISR_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_EISR_RW]

//>> PREP_[QME_EISR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_EISR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_EISR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_EISR_WO_CLEAR]

//>> GET_[QME_EISR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_EISR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_EISR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, QME_EISR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_EISR_WO_CLEAR]

//>> PUT_[QME_EISR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_EISR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_EISR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_EISR_WO_CLEAR]

//>> PREP_[QME_EISR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_EISR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_EISR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_EISR_WO_OR]

//>> GET_[QME_EISR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_EISR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_EISR_WO_OR;
#endif
    return fapi2::getScom(i_target, QME_EISR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_EISR_WO_OR]

//>> PUT_[QME_EISR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_EISR_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_EISR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_EISR_WO_OR]


//>> SET_[QME_EISR_DEBUGGER]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_DEBUGGER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_DEBUGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_DEBUGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_DEBUGGER]

//>> SET_[QME_EISR_DEBUGGER]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_DEBUGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_DEBUGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_DEBUGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_DEBUGGER]

//>> SET_[QME_EISR_DEBUGGER]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_DEBUGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.setBit<QME_EISR_DEBUGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_EISR_DEBUGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_DEBUGGER]

//>> CLEAR_[QME_EISR_DEBUGGER]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_EISR_DEBUGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.clearBit<QME_EISR_DEBUGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_EISR_DEBUGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_EISR_DEBUGGER]

//>> GET_[QME_EISR_DEBUGGER]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_DEBUGGER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_DEBUGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_DEBUGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_DEBUGGER]

//>> GET_[QME_EISR_DEBUGGER]
static inline bool GET_QME_EISR_DEBUGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.getBit<QME_EISR_DEBUGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_EISR_DEBUGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_DEBUGGER]

//>> SET_[QME_EISR_DEBUG_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_DEBUG_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_DEBUG_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_DEBUG_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_DEBUG_TRIGGER]

//>> SET_[QME_EISR_DEBUG_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_DEBUG_TRIGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_DEBUG_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_DEBUG_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_DEBUG_TRIGGER]

//>> SET_[QME_EISR_DEBUG_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_DEBUG_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.setBit<QME_EISR_DEBUG_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_EISR_DEBUG_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_DEBUG_TRIGGER]

//>> CLEAR_[QME_EISR_DEBUG_TRIGGER]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_EISR_DEBUG_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.clearBit<QME_EISR_DEBUG_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_EISR_DEBUG_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_EISR_DEBUG_TRIGGER]

//>> GET_[QME_EISR_DEBUG_TRIGGER]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_DEBUG_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_DEBUG_TRIGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_DEBUG_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_DEBUG_TRIGGER]

//>> GET_[QME_EISR_DEBUG_TRIGGER]
static inline bool GET_QME_EISR_DEBUG_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.getBit<QME_EISR_DEBUG_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_EISR_DEBUG_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_DEBUG_TRIGGER]

//>> SET_[QME_EISR_SYSTEM_CHECKSTOP]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_SYSTEM_CHECKSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_SYSTEM_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_SYSTEM_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_SYSTEM_CHECKSTOP]

//>> SET_[QME_EISR_SYSTEM_CHECKSTOP]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_SYSTEM_CHECKSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_SYSTEM_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_SYSTEM_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_SYSTEM_CHECKSTOP]

//>> SET_[QME_EISR_SYSTEM_CHECKSTOP]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_SYSTEM_CHECKSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.setBit<QME_EISR_SYSTEM_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_EISR_SYSTEM_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_SYSTEM_CHECKSTOP]

//>> CLEAR_[QME_EISR_SYSTEM_CHECKSTOP]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_EISR_SYSTEM_CHECKSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.clearBit<QME_EISR_SYSTEM_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_EISR_SYSTEM_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_EISR_SYSTEM_CHECKSTOP]

//>> GET_[QME_EISR_SYSTEM_CHECKSTOP]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_SYSTEM_CHECKSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_SYSTEM_CHECKSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_SYSTEM_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_SYSTEM_CHECKSTOP]

//>> GET_[QME_EISR_SYSTEM_CHECKSTOP]
static inline bool GET_QME_EISR_SYSTEM_CHECKSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.getBit<QME_EISR_SYSTEM_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_EISR_SYSTEM_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_SYSTEM_CHECKSTOP]

//>> SET_[QME_EISR_LFIR_INDICATION]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_LFIR_INDICATION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_LFIR_INDICATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_LFIR_INDICATION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_LFIR_INDICATION]

//>> SET_[QME_EISR_LFIR_INDICATION]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_LFIR_INDICATION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_LFIR_INDICATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_LFIR_INDICATION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_LFIR_INDICATION]

//>> SET_[QME_EISR_LFIR_INDICATION]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_LFIR_INDICATION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.setBit<QME_EISR_LFIR_INDICATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_EISR_LFIR_INDICATION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_LFIR_INDICATION]

//>> CLEAR_[QME_EISR_LFIR_INDICATION]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_EISR_LFIR_INDICATION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.clearBit<QME_EISR_LFIR_INDICATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_EISR_LFIR_INDICATION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_EISR_LFIR_INDICATION]

//>> GET_[QME_EISR_LFIR_INDICATION]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_LFIR_INDICATION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_LFIR_INDICATION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_LFIR_INDICATION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_LFIR_INDICATION]

//>> GET_[QME_EISR_LFIR_INDICATION]
static inline bool GET_QME_EISR_LFIR_INDICATION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.getBit<QME_EISR_LFIR_INDICATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_EISR_LFIR_INDICATION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_LFIR_INDICATION]

//>> SET_[QME_EISR_QOS_UPDATE]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_QOS_UPDATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_QOS_UPDATE,
           QME_EISR_QOS_UPDATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_QOS_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_QOS_UPDATE]

//>> SET_[QME_EISR_QOS_UPDATE]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_QOS_UPDATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_QOS_UPDATE,
           QME_EISR_QOS_UPDATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_QOS_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_QOS_UPDATE]

//>> GET_[QME_EISR_QOS_UPDATE]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_QOS_UPDATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_QOS_UPDATE,
           QME_EISR_QOS_UPDATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_QOS_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_QOS_UPDATE]

//>> SET_[QME_EISR_BCE_BUSY]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_BCE_BUSY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_BCE_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_BCE_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_BCE_BUSY]

//>> SET_[QME_EISR_BCE_BUSY]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_BCE_BUSY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_BCE_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_BCE_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_BCE_BUSY]

//>> SET_[QME_EISR_BCE_BUSY]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_BCE_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.setBit<QME_EISR_BCE_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_EISR_BCE_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_BCE_BUSY]

//>> CLEAR_[QME_EISR_BCE_BUSY]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_EISR_BCE_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.clearBit<QME_EISR_BCE_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_EISR_BCE_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_EISR_BCE_BUSY]

//>> GET_[QME_EISR_BCE_BUSY]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_BCE_BUSY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_BCE_BUSY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_BCE_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_BCE_BUSY]

//>> GET_[QME_EISR_BCE_BUSY]
static inline bool GET_QME_EISR_BCE_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.getBit<QME_EISR_BCE_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_EISR_BCE_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_BCE_BUSY]

//>> SET_[QME_EISR_RS4_BUSY]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_RS4_BUSY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_RS4_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_RS4_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_RS4_BUSY]

//>> SET_[QME_EISR_RS4_BUSY]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_RS4_BUSY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_RS4_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_RS4_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_RS4_BUSY]

//>> SET_[QME_EISR_RS4_BUSY]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_RS4_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.setBit<QME_EISR_RS4_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_EISR_RS4_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_RS4_BUSY]

//>> CLEAR_[QME_EISR_RS4_BUSY]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_EISR_RS4_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.clearBit<QME_EISR_RS4_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_EISR_RS4_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_EISR_RS4_BUSY]

//>> GET_[QME_EISR_RS4_BUSY]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_RS4_BUSY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_RS4_BUSY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_RS4_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_RS4_BUSY]

//>> GET_[QME_EISR_RS4_BUSY]
static inline bool GET_QME_EISR_RS4_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.getBit<QME_EISR_RS4_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_EISR_RS4_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_RS4_BUSY]

//>> SET_[QME_EISR_RESCLK_TARGET_ASSIST]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_RESCLK_TARGET_ASSIST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_RESCLK_TARGET_ASSIST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_RESCLK_TARGET_ASSIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_RESCLK_TARGET_ASSIST]

//>> SET_[QME_EISR_RESCLK_TARGET_ASSIST]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_RESCLK_TARGET_ASSIST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_RESCLK_TARGET_ASSIST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_RESCLK_TARGET_ASSIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_RESCLK_TARGET_ASSIST]

//>> SET_[QME_EISR_RESCLK_TARGET_ASSIST]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_RESCLK_TARGET_ASSIST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.setBit<QME_EISR_RESCLK_TARGET_ASSIST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_EISR_RESCLK_TARGET_ASSIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_RESCLK_TARGET_ASSIST]

//>> CLEAR_[QME_EISR_RESCLK_TARGET_ASSIST]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_EISR_RESCLK_TARGET_ASSIST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.clearBit<QME_EISR_RESCLK_TARGET_ASSIST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_EISR_RESCLK_TARGET_ASSIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_EISR_RESCLK_TARGET_ASSIST]

//>> GET_[QME_EISR_RESCLK_TARGET_ASSIST]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_RESCLK_TARGET_ASSIST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_RESCLK_TARGET_ASSIST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_RESCLK_TARGET_ASSIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_RESCLK_TARGET_ASSIST]

//>> GET_[QME_EISR_RESCLK_TARGET_ASSIST]
static inline bool GET_QME_EISR_RESCLK_TARGET_ASSIST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.getBit<QME_EISR_RESCLK_TARGET_ASSIST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_EISR_RESCLK_TARGET_ASSIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_RESCLK_TARGET_ASSIST]

//>> SET_[QME_EISR_RESCLK_DONE_ASSIST]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_RESCLK_DONE_ASSIST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_RESCLK_DONE_ASSIST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_RESCLK_DONE_ASSIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_RESCLK_DONE_ASSIST]

//>> SET_[QME_EISR_RESCLK_DONE_ASSIST]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_RESCLK_DONE_ASSIST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_RESCLK_DONE_ASSIST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_RESCLK_DONE_ASSIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_RESCLK_DONE_ASSIST]

//>> SET_[QME_EISR_RESCLK_DONE_ASSIST]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_RESCLK_DONE_ASSIST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.setBit<QME_EISR_RESCLK_DONE_ASSIST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_EISR_RESCLK_DONE_ASSIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_RESCLK_DONE_ASSIST]

//>> CLEAR_[QME_EISR_RESCLK_DONE_ASSIST]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_EISR_RESCLK_DONE_ASSIST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.clearBit<QME_EISR_RESCLK_DONE_ASSIST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_EISR_RESCLK_DONE_ASSIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_EISR_RESCLK_DONE_ASSIST]

//>> GET_[QME_EISR_RESCLK_DONE_ASSIST]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_RESCLK_DONE_ASSIST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_RESCLK_DONE_ASSIST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_RESCLK_DONE_ASSIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_RESCLK_DONE_ASSIST]

//>> GET_[QME_EISR_RESCLK_DONE_ASSIST]
static inline bool GET_QME_EISR_RESCLK_DONE_ASSIST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.getBit<QME_EISR_RESCLK_DONE_ASSIST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_EISR_RESCLK_DONE_ASSIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_RESCLK_DONE_ASSIST]

//>> SET_[QME_EISR_PITCH_UPDATE]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_PITCH_UPDATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_PITCH_UPDATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_PITCH_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_PITCH_UPDATE]

//>> SET_[QME_EISR_PITCH_UPDATE]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_PITCH_UPDATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_PITCH_UPDATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_PITCH_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_PITCH_UPDATE]

//>> SET_[QME_EISR_PITCH_UPDATE]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_PITCH_UPDATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.setBit<QME_EISR_PITCH_UPDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_EISR_PITCH_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_PITCH_UPDATE]

//>> CLEAR_[QME_EISR_PITCH_UPDATE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_EISR_PITCH_UPDATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.clearBit<QME_EISR_PITCH_UPDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_EISR_PITCH_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_EISR_PITCH_UPDATE]

//>> GET_[QME_EISR_PITCH_UPDATE]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_PITCH_UPDATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_PITCH_UPDATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_PITCH_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_PITCH_UPDATE]

//>> GET_[QME_EISR_PITCH_UPDATE]
static inline bool GET_QME_EISR_PITCH_UPDATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.getBit<QME_EISR_PITCH_UPDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_EISR_PITCH_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_PITCH_UPDATE]

//>> SET_[QME_EISR_WOCR_UPDATE]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_WOCR_UPDATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_WOCR_UPDATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_WOCR_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_WOCR_UPDATE]

//>> SET_[QME_EISR_WOCR_UPDATE]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_WOCR_UPDATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_WOCR_UPDATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_WOCR_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_WOCR_UPDATE]

//>> SET_[QME_EISR_WOCR_UPDATE]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_WOCR_UPDATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.setBit<QME_EISR_WOCR_UPDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_EISR_WOCR_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_WOCR_UPDATE]

//>> CLEAR_[QME_EISR_WOCR_UPDATE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_EISR_WOCR_UPDATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.clearBit<QME_EISR_WOCR_UPDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_EISR_WOCR_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_EISR_WOCR_UPDATE]

//>> GET_[QME_EISR_WOCR_UPDATE]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_WOCR_UPDATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_WOCR_UPDATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_WOCR_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_WOCR_UPDATE]

//>> GET_[QME_EISR_WOCR_UPDATE]
static inline bool GET_QME_EISR_WOCR_UPDATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.getBit<QME_EISR_WOCR_UPDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_EISR_WOCR_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_WOCR_UPDATE]

//>> SET_[QME_EISR_TBR_CYCLES_ROLLED]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_TBR_CYCLES_ROLLED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_TBR_CYCLES_ROLLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_TBR_CYCLES_ROLLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_TBR_CYCLES_ROLLED]

//>> SET_[QME_EISR_TBR_CYCLES_ROLLED]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_TBR_CYCLES_ROLLED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_TBR_CYCLES_ROLLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_TBR_CYCLES_ROLLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_TBR_CYCLES_ROLLED]

//>> SET_[QME_EISR_TBR_CYCLES_ROLLED]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_TBR_CYCLES_ROLLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.setBit<QME_EISR_TBR_CYCLES_ROLLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_EISR_TBR_CYCLES_ROLLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_TBR_CYCLES_ROLLED]

//>> CLEAR_[QME_EISR_TBR_CYCLES_ROLLED]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_EISR_TBR_CYCLES_ROLLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.clearBit<QME_EISR_TBR_CYCLES_ROLLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_EISR_TBR_CYCLES_ROLLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_EISR_TBR_CYCLES_ROLLED]

//>> GET_[QME_EISR_TBR_CYCLES_ROLLED]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_TBR_CYCLES_ROLLED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_TBR_CYCLES_ROLLED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_TBR_CYCLES_ROLLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_TBR_CYCLES_ROLLED]

//>> GET_[QME_EISR_TBR_CYCLES_ROLLED]
static inline bool GET_QME_EISR_TBR_CYCLES_ROLLED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.getBit<QME_EISR_TBR_CYCLES_ROLLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_EISR_TBR_CYCLES_ROLLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_TBR_CYCLES_ROLLED]

//>> SET_[QME_EISR_TBR_TIMEBASE_ROLLED]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_TBR_TIMEBASE_ROLLED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_TBR_TIMEBASE_ROLLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_TBR_TIMEBASE_ROLLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_TBR_TIMEBASE_ROLLED]

//>> SET_[QME_EISR_TBR_TIMEBASE_ROLLED]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_TBR_TIMEBASE_ROLLED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_TBR_TIMEBASE_ROLLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_TBR_TIMEBASE_ROLLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_TBR_TIMEBASE_ROLLED]

//>> SET_[QME_EISR_TBR_TIMEBASE_ROLLED]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_TBR_TIMEBASE_ROLLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.setBit<QME_EISR_TBR_TIMEBASE_ROLLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_EISR_TBR_TIMEBASE_ROLLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_TBR_TIMEBASE_ROLLED]

//>> CLEAR_[QME_EISR_TBR_TIMEBASE_ROLLED]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_EISR_TBR_TIMEBASE_ROLLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.clearBit<QME_EISR_TBR_TIMEBASE_ROLLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_EISR_TBR_TIMEBASE_ROLLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_EISR_TBR_TIMEBASE_ROLLED]

//>> GET_[QME_EISR_TBR_TIMEBASE_ROLLED]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_TBR_TIMEBASE_ROLLED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_TBR_TIMEBASE_ROLLED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_TBR_TIMEBASE_ROLLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_TBR_TIMEBASE_ROLLED]

//>> GET_[QME_EISR_TBR_TIMEBASE_ROLLED]
static inline bool GET_QME_EISR_TBR_TIMEBASE_ROLLED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.getBit<QME_EISR_TBR_TIMEBASE_ROLLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_EISR_TBR_TIMEBASE_ROLLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_TBR_TIMEBASE_ROLLED]

//>> SET_[QME_EISR_DOORBELL_0]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_DOORBELL_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_DOORBELL_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_DOORBELL_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_DOORBELL_0]

//>> SET_[QME_EISR_DOORBELL_0]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_DOORBELL_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_DOORBELL_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_DOORBELL_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_DOORBELL_0]

//>> SET_[QME_EISR_DOORBELL_0]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_DOORBELL_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.setBit<QME_EISR_DOORBELL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_EISR_DOORBELL_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_DOORBELL_0]

//>> CLEAR_[QME_EISR_DOORBELL_0]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_EISR_DOORBELL_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.clearBit<QME_EISR_DOORBELL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_EISR_DOORBELL_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_EISR_DOORBELL_0]

//>> GET_[QME_EISR_DOORBELL_0]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_DOORBELL_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_DOORBELL_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_DOORBELL_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_DOORBELL_0]

//>> GET_[QME_EISR_DOORBELL_0]
static inline bool GET_QME_EISR_DOORBELL_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.getBit<QME_EISR_DOORBELL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_EISR_DOORBELL_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_DOORBELL_0]

//>> SET_[QME_EISR_DOORBELL_1]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_DOORBELL_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_DOORBELL_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_DOORBELL_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_DOORBELL_1]

//>> SET_[QME_EISR_DOORBELL_1]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_DOORBELL_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_DOORBELL_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_DOORBELL_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_DOORBELL_1]

//>> SET_[QME_EISR_DOORBELL_1]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_DOORBELL_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.setBit<QME_EISR_DOORBELL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_EISR_DOORBELL_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_DOORBELL_1]

//>> CLEAR_[QME_EISR_DOORBELL_1]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_EISR_DOORBELL_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.clearBit<QME_EISR_DOORBELL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_EISR_DOORBELL_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_EISR_DOORBELL_1]

//>> GET_[QME_EISR_DOORBELL_1]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_DOORBELL_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_DOORBELL_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_DOORBELL_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_DOORBELL_1]

//>> GET_[QME_EISR_DOORBELL_1]
static inline bool GET_QME_EISR_DOORBELL_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.getBit<QME_EISR_DOORBELL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_EISR_DOORBELL_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_DOORBELL_1]

//>> SET_[QME_EISR_DOORBELL_2]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_DOORBELL_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_DOORBELL_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_DOORBELL_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_DOORBELL_2]

//>> SET_[QME_EISR_DOORBELL_2]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_DOORBELL_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_DOORBELL_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_DOORBELL_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_DOORBELL_2]

//>> SET_[QME_EISR_DOORBELL_2]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_DOORBELL_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.setBit<QME_EISR_DOORBELL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_EISR_DOORBELL_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_DOORBELL_2]

//>> CLEAR_[QME_EISR_DOORBELL_2]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_EISR_DOORBELL_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.clearBit<QME_EISR_DOORBELL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_EISR_DOORBELL_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_EISR_DOORBELL_2]

//>> GET_[QME_EISR_DOORBELL_2]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_DOORBELL_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_DOORBELL_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_DOORBELL_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_DOORBELL_2]

//>> GET_[QME_EISR_DOORBELL_2]
static inline bool GET_QME_EISR_DOORBELL_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.getBit<QME_EISR_DOORBELL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_EISR_DOORBELL_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_DOORBELL_2]

//>> SET_[QME_EISR_PMCR_UPDATE]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_PMCR_UPDATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_PMCR_UPDATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_PMCR_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_PMCR_UPDATE]

//>> SET_[QME_EISR_PMCR_UPDATE]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_PMCR_UPDATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_PMCR_UPDATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_PMCR_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_PMCR_UPDATE]

//>> SET_[QME_EISR_PMCR_UPDATE]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_PMCR_UPDATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.setBit<QME_EISR_PMCR_UPDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_EISR_PMCR_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_PMCR_UPDATE]

//>> CLEAR_[QME_EISR_PMCR_UPDATE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_EISR_PMCR_UPDATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.clearBit<QME_EISR_PMCR_UPDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_EISR_PMCR_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_EISR_PMCR_UPDATE]

//>> GET_[QME_EISR_PMCR_UPDATE]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_PMCR_UPDATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_PMCR_UPDATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_PMCR_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_PMCR_UPDATE]

//>> GET_[QME_EISR_PMCR_UPDATE]
static inline bool GET_QME_EISR_PMCR_UPDATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.getBit<QME_EISR_PMCR_UPDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_EISR_PMCR_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_PMCR_UPDATE]

//>> SET_[QME_EISR_DOORBELL_A]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_DOORBELL_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_DOORBELL_A,
           QME_EISR_DOORBELL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_DOORBELL_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_DOORBELL_A]

//>> SET_[QME_EISR_DOORBELL_A]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_DOORBELL_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_DOORBELL_A,
           QME_EISR_DOORBELL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_DOORBELL_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_DOORBELL_A]

//>> GET_[QME_EISR_DOORBELL_A]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_DOORBELL_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_DOORBELL_A,
           QME_EISR_DOORBELL_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_DOORBELL_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_DOORBELL_A]

//>> SET_[QME_EISR_DOORBELL_3]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_DOORBELL_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_DOORBELL_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_DOORBELL_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_DOORBELL_3]

//>> SET_[QME_EISR_DOORBELL_3]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_DOORBELL_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_DOORBELL_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_DOORBELL_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_DOORBELL_3]

//>> SET_[QME_EISR_DOORBELL_3]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_DOORBELL_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.setBit<QME_EISR_DOORBELL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_EISR_DOORBELL_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_DOORBELL_3]

//>> CLEAR_[QME_EISR_DOORBELL_3]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_EISR_DOORBELL_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.clearBit<QME_EISR_DOORBELL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_EISR_DOORBELL_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_EISR_DOORBELL_3]

//>> GET_[QME_EISR_DOORBELL_3]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_DOORBELL_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_DOORBELL_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_DOORBELL_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_DOORBELL_3]

//>> GET_[QME_EISR_DOORBELL_3]
static inline bool GET_QME_EISR_DOORBELL_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.getBit<QME_EISR_DOORBELL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_EISR_DOORBELL_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_DOORBELL_3]

//>> SET_[QME_EISR_DOORBELL_4]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_DOORBELL_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_DOORBELL_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_DOORBELL_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_DOORBELL_4]

//>> SET_[QME_EISR_DOORBELL_4]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_DOORBELL_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_DOORBELL_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_DOORBELL_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_DOORBELL_4]

//>> SET_[QME_EISR_DOORBELL_4]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_DOORBELL_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.setBit<QME_EISR_DOORBELL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_EISR_DOORBELL_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_DOORBELL_4]

//>> CLEAR_[QME_EISR_DOORBELL_4]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_EISR_DOORBELL_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.clearBit<QME_EISR_DOORBELL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_EISR_DOORBELL_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_EISR_DOORBELL_4]

//>> GET_[QME_EISR_DOORBELL_4]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_DOORBELL_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_DOORBELL_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_DOORBELL_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_DOORBELL_4]

//>> GET_[QME_EISR_DOORBELL_4]
static inline bool GET_QME_EISR_DOORBELL_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.getBit<QME_EISR_DOORBELL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_EISR_DOORBELL_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_DOORBELL_4]

//>> SET_[QME_EISR_SPAREA]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_SPAREA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_SPAREA,
           QME_EISR_SPAREA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_SPAREA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_SPAREA]

//>> SET_[QME_EISR_SPAREA]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_SPAREA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_SPAREA,
           QME_EISR_SPAREA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_SPAREA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_SPAREA]

//>> GET_[QME_EISR_SPAREA]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_SPAREA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_SPAREA,
           QME_EISR_SPAREA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_SPAREA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_SPAREA]

//>> SET_[QME_EISR_DOORBELL_B]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_DOORBELL_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_DOORBELL_B,
           QME_EISR_DOORBELL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_DOORBELL_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_DOORBELL_B]

//>> SET_[QME_EISR_DOORBELL_B]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_DOORBELL_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_DOORBELL_B,
           QME_EISR_DOORBELL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_DOORBELL_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_DOORBELL_B]

//>> GET_[QME_EISR_DOORBELL_B]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_DOORBELL_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_DOORBELL_B,
           QME_EISR_DOORBELL_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_DOORBELL_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_DOORBELL_B]

//>> SET_[QME_EISR_SPAREB]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_SPAREB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_SPAREB,
           QME_EISR_SPAREB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_SPAREB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_SPAREB]

//>> SET_[QME_EISR_SPAREB]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_SPAREB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_SPAREB,
           QME_EISR_SPAREB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_SPAREB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_SPAREB]

//>> GET_[QME_EISR_SPAREB]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_SPAREB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_SPAREB,
           QME_EISR_SPAREB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_SPAREB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_SPAREB]

//>> SET_[QME_EISR_MMA_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_MMA_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_MMA_ACTIVE,
           QME_EISR_MMA_ACTIVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_MMA_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_MMA_ACTIVE]

//>> SET_[QME_EISR_MMA_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_MMA_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_MMA_ACTIVE,
           QME_EISR_MMA_ACTIVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_MMA_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_MMA_ACTIVE]

//>> GET_[QME_EISR_MMA_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_MMA_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_MMA_ACTIVE,
           QME_EISR_MMA_ACTIVE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_MMA_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_MMA_ACTIVE]

//>> SET_[QME_EISR_SPC_WKUP_RISE]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_SPC_WKUP_RISE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_SPC_WKUP_RISE,
           QME_EISR_SPC_WKUP_RISE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_SPC_WKUP_RISE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_SPC_WKUP_RISE]

//>> SET_[QME_EISR_SPC_WKUP_RISE]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_SPC_WKUP_RISE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_SPC_WKUP_RISE,
           QME_EISR_SPC_WKUP_RISE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_SPC_WKUP_RISE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_SPC_WKUP_RISE]

//>> GET_[QME_EISR_SPC_WKUP_RISE]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_SPC_WKUP_RISE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_SPC_WKUP_RISE,
           QME_EISR_SPC_WKUP_RISE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_SPC_WKUP_RISE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_SPC_WKUP_RISE]

//>> SET_[QME_EISR_SPC_WKUP_FALL]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_SPC_WKUP_FALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_SPC_WKUP_FALL,
           QME_EISR_SPC_WKUP_FALL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_SPC_WKUP_FALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_SPC_WKUP_FALL]

//>> SET_[QME_EISR_SPC_WKUP_FALL]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_SPC_WKUP_FALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_SPC_WKUP_FALL,
           QME_EISR_SPC_WKUP_FALL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_SPC_WKUP_FALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_SPC_WKUP_FALL]

//>> GET_[QME_EISR_SPC_WKUP_FALL]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_SPC_WKUP_FALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_SPC_WKUP_FALL,
           QME_EISR_SPC_WKUP_FALL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_SPC_WKUP_FALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_SPC_WKUP_FALL]

//>> SET_[QME_EISR_REG_WKUP_HIPRI]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_REG_WKUP_HIPRI(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_REG_WKUP_HIPRI,
           QME_EISR_REG_WKUP_HIPRI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_REG_WKUP_HIPRI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_REG_WKUP_HIPRI]

//>> SET_[QME_EISR_REG_WKUP_HIPRI]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_REG_WKUP_HIPRI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_REG_WKUP_HIPRI,
           QME_EISR_REG_WKUP_HIPRI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_REG_WKUP_HIPRI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_REG_WKUP_HIPRI]

//>> GET_[QME_EISR_REG_WKUP_HIPRI]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_REG_WKUP_HIPRI(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_REG_WKUP_HIPRI,
           QME_EISR_REG_WKUP_HIPRI_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_REG_WKUP_HIPRI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_REG_WKUP_HIPRI]

//>> SET_[QME_EISR_REG_WKUP_LOPRI]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_REG_WKUP_LOPRI(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_REG_WKUP_LOPRI,
           QME_EISR_REG_WKUP_LOPRI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_REG_WKUP_LOPRI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_REG_WKUP_LOPRI]

//>> SET_[QME_EISR_REG_WKUP_LOPRI]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_REG_WKUP_LOPRI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_REG_WKUP_LOPRI,
           QME_EISR_REG_WKUP_LOPRI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_REG_WKUP_LOPRI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_REG_WKUP_LOPRI]

//>> GET_[QME_EISR_REG_WKUP_LOPRI]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_REG_WKUP_LOPRI(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_REG_WKUP_LOPRI,
           QME_EISR_REG_WKUP_LOPRI_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_REG_WKUP_LOPRI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_REG_WKUP_LOPRI]

//>> SET_[QME_EISR_PM_STATE_ACTIVE_HIPRI]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_PM_STATE_ACTIVE_HIPRI(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_PM_STATE_ACTIVE_HIPRI,
           QME_EISR_PM_STATE_ACTIVE_HIPRI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_PM_STATE_ACTIVE_HIPRI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_PM_STATE_ACTIVE_HIPRI]

//>> SET_[QME_EISR_PM_STATE_ACTIVE_HIPRI]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_PM_STATE_ACTIVE_HIPRI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_PM_STATE_ACTIVE_HIPRI,
           QME_EISR_PM_STATE_ACTIVE_HIPRI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_PM_STATE_ACTIVE_HIPRI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_PM_STATE_ACTIVE_HIPRI]

//>> GET_[QME_EISR_PM_STATE_ACTIVE_HIPRI]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_PM_STATE_ACTIVE_HIPRI(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_PM_STATE_ACTIVE_HIPRI,
           QME_EISR_PM_STATE_ACTIVE_HIPRI_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_PM_STATE_ACTIVE_HIPRI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_PM_STATE_ACTIVE_HIPRI]

//>> SET_[QME_EISR_PM_STATE_ACTIVE_LOPRI]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_PM_STATE_ACTIVE_LOPRI(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_PM_STATE_ACTIVE_LOPRI,
           QME_EISR_PM_STATE_ACTIVE_LOPRI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_PM_STATE_ACTIVE_LOPRI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_PM_STATE_ACTIVE_LOPRI]

//>> SET_[QME_EISR_PM_STATE_ACTIVE_LOPRI]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_PM_STATE_ACTIVE_LOPRI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_PM_STATE_ACTIVE_LOPRI,
           QME_EISR_PM_STATE_ACTIVE_LOPRI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_PM_STATE_ACTIVE_LOPRI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_PM_STATE_ACTIVE_LOPRI]

//>> GET_[QME_EISR_PM_STATE_ACTIVE_LOPRI]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_PM_STATE_ACTIVE_LOPRI(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_PM_STATE_ACTIVE_LOPRI,
           QME_EISR_PM_STATE_ACTIVE_LOPRI_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_PM_STATE_ACTIVE_LOPRI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_PM_STATE_ACTIVE_LOPRI]

//>> SET_[QME_EISR_CPMS_INTERRUPT0]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_CPMS_INTERRUPT0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_CPMS_INTERRUPT0,
           QME_EISR_CPMS_INTERRUPT0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_CPMS_INTERRUPT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_CPMS_INTERRUPT0]

//>> SET_[QME_EISR_CPMS_INTERRUPT0]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_CPMS_INTERRUPT0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_CPMS_INTERRUPT0,
           QME_EISR_CPMS_INTERRUPT0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_CPMS_INTERRUPT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_CPMS_INTERRUPT0]

//>> GET_[QME_EISR_CPMS_INTERRUPT0]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_CPMS_INTERRUPT0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_CPMS_INTERRUPT0,
           QME_EISR_CPMS_INTERRUPT0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_CPMS_INTERRUPT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_CPMS_INTERRUPT0]

//>> SET_[QME_EISR_CPMS_INTERRUPT1]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_CPMS_INTERRUPT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_CPMS_INTERRUPT1,
           QME_EISR_CPMS_INTERRUPT1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISR_CPMS_INTERRUPT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_CPMS_INTERRUPT1]

//>> SET_[QME_EISR_CPMS_INTERRUPT1]
static inline fapi2::buffer<uint64_t>& SET_QME_EISR_CPMS_INTERRUPT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EISR_CPMS_INTERRUPT1,
           QME_EISR_CPMS_INTERRUPT1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISR_CPMS_INTERRUPT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISR_CPMS_INTERRUPT1]

//>> GET_[QME_EISR_CPMS_INTERRUPT1]
static inline fapi2::buffer<uint64_t>& GET_QME_EISR_CPMS_INTERRUPT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISR_RW, QME_EISR_WO_CLEAR, QME_EISR_WO_OR));
#endif
    return i_data.extractToRight<QME_EISR_CPMS_INTERRUPT1,
           QME_EISR_CPMS_INTERRUPT1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISR_CPMS_INTERRUPT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISR_CPMS_INTERRUPT1]

//>> PREP_[QME_LFIRACT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_LFIRACT1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_LFIRACT1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_LFIRACT1]

//>> GET_[QME_LFIRACT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_LFIRACT1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_LFIRACT1;
#endif
    return fapi2::getScom(i_target, QME_LFIRACT1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_LFIRACT1]

//>> PUT_[QME_LFIRACT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_LFIRACT1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_LFIRACT1));
#endif
    return fapi2::putScom(i_target, QME_LFIRACT1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_LFIRACT1]


//>> SET_[QME_LFIRACT1_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_QME_LFIRACT1_FIR_ACTION1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_LFIRACT1));
#endif
    return o_data.insertFromRight<QME_LFIRACT1_FIR_ACTION1,
           QME_LFIRACT1_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_LFIRACT1_FIR_ACTION1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_LFIRACT1_FIR_ACTION1]

//>> SET_[QME_LFIRACT1_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_QME_LFIRACT1_FIR_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_LFIRACT1));
#endif
    return o_data.insertFromRight<QME_LFIRACT1_FIR_ACTION1,
           QME_LFIRACT1_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_LFIRACT1_FIR_ACTION1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_LFIRACT1_FIR_ACTION1]

//>> GET_[QME_LFIRACT1_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_QME_LFIRACT1_FIR_ACTION1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_LFIRACT1));
#endif
    return i_data.extractToRight<QME_LFIRACT1_FIR_ACTION1,
           QME_LFIRACT1_FIR_ACTION1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_LFIRACT1_FIR_ACTION1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_LFIRACT1_FIR_ACTION1]

//>> PREP_[QME_SCOM_XIICAC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCOM_XIICAC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCOM_XIICAC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SCOM_XIICAC]

//>> GET_[QME_SCOM_XIICAC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCOM_XIICAC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCOM_XIICAC;
#endif
    return fapi2::getScom(i_target, QME_SCOM_XIICAC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SCOM_XIICAC]

//>> PUT_[QME_SCOM_XIICAC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCOM_XIICAC(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIICAC));
#endif
    return fapi2::putScom(i_target, QME_SCOM_XIICAC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SCOM_XIICAC]


//>> SET_[QME_SCOM_XIICAC_ICACHE_TAG_ADDR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIICAC_ICACHE_TAG_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIICAC));
#endif
    return o_data.insertFromRight<QME_SCOM_XIICAC_ICACHE_TAG_ADDR,
           QME_SCOM_XIICAC_ICACHE_TAG_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIICAC_ICACHE_TAG_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIICAC_ICACHE_TAG_ADDR]

//>> SET_[QME_SCOM_XIICAC_ICACHE_TAG_ADDR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIICAC_ICACHE_TAG_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIICAC));
#endif
    return o_data.insertFromRight<QME_SCOM_XIICAC_ICACHE_TAG_ADDR,
           QME_SCOM_XIICAC_ICACHE_TAG_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIICAC_ICACHE_TAG_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIICAC_ICACHE_TAG_ADDR]

//>> GET_[QME_SCOM_XIICAC_ICACHE_TAG_ADDR]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIICAC_ICACHE_TAG_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIICAC));
#endif
    return i_data.extractToRight<QME_SCOM_XIICAC_ICACHE_TAG_ADDR,
           QME_SCOM_XIICAC_ICACHE_TAG_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIICAC_ICACHE_TAG_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIICAC_ICACHE_TAG_ADDR]

//>> SET_[QME_SCOM_XIICAC_ICACHE_ERR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIICAC_ICACHE_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIICAC));
#endif
    return o_data.insertFromRight<QME_SCOM_XIICAC_ICACHE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIICAC_ICACHE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIICAC_ICACHE_ERR]

//>> SET_[QME_SCOM_XIICAC_ICACHE_ERR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIICAC_ICACHE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIICAC));
#endif
    return o_data.insertFromRight<QME_SCOM_XIICAC_ICACHE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIICAC_ICACHE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIICAC_ICACHE_ERR]

//>> SET_[QME_SCOM_XIICAC_ICACHE_ERR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIICAC_ICACHE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIICAC));
#endif
    return o_data.setBit<QME_SCOM_XIICAC_ICACHE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIICAC_ICACHE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIICAC_ICACHE_ERR]

//>> CLEAR_[QME_SCOM_XIICAC_ICACHE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIICAC_ICACHE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIICAC));
#endif
    return o_data.clearBit<QME_SCOM_XIICAC_ICACHE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIICAC_ICACHE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIICAC_ICACHE_ERR]

//>> GET_[QME_SCOM_XIICAC_ICACHE_ERR]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIICAC_ICACHE_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIICAC));
#endif
    return i_data.extractToRight<QME_SCOM_XIICAC_ICACHE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIICAC_ICACHE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIICAC_ICACHE_ERR]

//>> GET_[QME_SCOM_XIICAC_ICACHE_ERR]
static inline bool GET_QME_SCOM_XIICAC_ICACHE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIICAC));
#endif
    return i_data.getBit<QME_SCOM_XIICAC_ICACHE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIICAC_ICACHE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIICAC_ICACHE_ERR]

//>> SET_[QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIICAC));
#endif
    return o_data.insertFromRight<QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING]

//>> SET_[QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIICAC));
#endif
    return o_data.insertFromRight<QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING]

//>> SET_[QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIICAC));
#endif
    return o_data.setBit<QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING]

//>> CLEAR_[QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIICAC));
#endif
    return o_data.clearBit<QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING]

//>> GET_[QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIICAC));
#endif
    return i_data.extractToRight<QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING]

//>> GET_[QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING]
static inline bool GET_QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIICAC));
#endif
    return i_data.getBit<QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING]

//>> SET_[QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIICAC));
#endif
    return o_data.insertFromRight<QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING]

//>> SET_[QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIICAC));
#endif
    return o_data.insertFromRight<QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING]

//>> SET_[QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIICAC));
#endif
    return o_data.setBit<QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING]

//>> CLEAR_[QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIICAC));
#endif
    return o_data.clearBit<QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING]

//>> GET_[QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIICAC));
#endif
    return i_data.extractToRight<QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING]

//>> GET_[QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING]
static inline bool GET_QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIICAC));
#endif
    return i_data.getBit<QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING]

//>> SET_[QME_SCOM_XIICAC_ICACHE_VALID]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIICAC_ICACHE_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIICAC));
#endif
    return o_data.insertFromRight<QME_SCOM_XIICAC_ICACHE_VALID,
           QME_SCOM_XIICAC_ICACHE_VALID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIICAC_ICACHE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIICAC_ICACHE_VALID]

//>> SET_[QME_SCOM_XIICAC_ICACHE_VALID]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIICAC_ICACHE_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIICAC));
#endif
    return o_data.insertFromRight<QME_SCOM_XIICAC_ICACHE_VALID,
           QME_SCOM_XIICAC_ICACHE_VALID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIICAC_ICACHE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIICAC_ICACHE_VALID]

//>> GET_[QME_SCOM_XIICAC_ICACHE_VALID]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIICAC_ICACHE_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIICAC));
#endif
    return i_data.extractToRight<QME_SCOM_XIICAC_ICACHE_VALID,
           QME_SCOM_XIICAC_ICACHE_VALID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIICAC_ICACHE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIICAC_ICACHE_VALID]

//>> PREP_[QME_SCOM_XISGB]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCOM_XISGB(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCOM_XISGB;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SCOM_XISGB]

//>> GET_[QME_SCOM_XISGB]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCOM_XISGB(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCOM_XISGB;
#endif
    return fapi2::getScom(i_target, QME_SCOM_XISGB, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SCOM_XISGB]

//>> PUT_[QME_SCOM_XISGB]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCOM_XISGB(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISGB));
#endif
    return fapi2::putScom(i_target, QME_SCOM_XISGB, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SCOM_XISGB]


//>> SET_[QME_SCOM_XISGB_STORE_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISGB_STORE_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISGB));
#endif
    return o_data.insertFromRight<QME_SCOM_XISGB_STORE_ADDRESS,
           QME_SCOM_XISGB_STORE_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XISGB_STORE_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISGB_STORE_ADDRESS]

//>> SET_[QME_SCOM_XISGB_STORE_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISGB_STORE_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISGB));
#endif
    return o_data.insertFromRight<QME_SCOM_XISGB_STORE_ADDRESS,
           QME_SCOM_XISGB_STORE_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XISGB_STORE_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISGB_STORE_ADDRESS]

//>> GET_[QME_SCOM_XISGB_STORE_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XISGB_STORE_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISGB));
#endif
    return i_data.extractToRight<QME_SCOM_XISGB_STORE_ADDRESS,
           QME_SCOM_XISGB_STORE_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XISGB_STORE_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XISGB_STORE_ADDRESS]

//>> SET_[QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISGB));
#endif
    return o_data.insertFromRight<QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> SET_[QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISGB));
#endif
    return o_data.insertFromRight<QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> SET_[QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISGB));
#endif
    return o_data.setBit<QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> CLEAR_[QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISGB));
#endif
    return o_data.clearBit<QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> GET_[QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISGB));
#endif
    return i_data.extractToRight<QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> GET_[QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline bool GET_QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISGB));
#endif
    return i_data.getBit<QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> SET_[QME_SCOM_XISGB_SGB_BYTE_VALID]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISGB_SGB_BYTE_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISGB));
#endif
    return o_data.insertFromRight<QME_SCOM_XISGB_SGB_BYTE_VALID,
           QME_SCOM_XISGB_SGB_BYTE_VALID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XISGB_SGB_BYTE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISGB_SGB_BYTE_VALID]

//>> SET_[QME_SCOM_XISGB_SGB_BYTE_VALID]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISGB_SGB_BYTE_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISGB));
#endif
    return o_data.insertFromRight<QME_SCOM_XISGB_SGB_BYTE_VALID,
           QME_SCOM_XISGB_SGB_BYTE_VALID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XISGB_SGB_BYTE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISGB_SGB_BYTE_VALID]

//>> GET_[QME_SCOM_XISGB_SGB_BYTE_VALID]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XISGB_SGB_BYTE_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISGB));
#endif
    return i_data.extractToRight<QME_SCOM_XISGB_SGB_BYTE_VALID,
           QME_SCOM_XISGB_SGB_BYTE_VALID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XISGB_SGB_BYTE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XISGB_SGB_BYTE_VALID]

//>> SET_[QME_SCOM_XISGB_SGB_FLUSH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISGB_SGB_FLUSH_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISGB));
#endif
    return o_data.insertFromRight<QME_SCOM_XISGB_SGB_FLUSH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XISGB_SGB_FLUSH_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISGB_SGB_FLUSH_PENDING]

//>> SET_[QME_SCOM_XISGB_SGB_FLUSH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISGB_SGB_FLUSH_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISGB));
#endif
    return o_data.insertFromRight<QME_SCOM_XISGB_SGB_FLUSH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XISGB_SGB_FLUSH_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISGB_SGB_FLUSH_PENDING]

//>> SET_[QME_SCOM_XISGB_SGB_FLUSH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISGB_SGB_FLUSH_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISGB));
#endif
    return o_data.setBit<QME_SCOM_XISGB_SGB_FLUSH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XISGB_SGB_FLUSH_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISGB_SGB_FLUSH_PENDING]

//>> CLEAR_[QME_SCOM_XISGB_SGB_FLUSH_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XISGB_SGB_FLUSH_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISGB));
#endif
    return o_data.clearBit<QME_SCOM_XISGB_SGB_FLUSH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XISGB_SGB_FLUSH_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XISGB_SGB_FLUSH_PENDING]

//>> GET_[QME_SCOM_XISGB_SGB_FLUSH_PENDING]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XISGB_SGB_FLUSH_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISGB));
#endif
    return i_data.extractToRight<QME_SCOM_XISGB_SGB_FLUSH_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XISGB_SGB_FLUSH_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XISGB_SGB_FLUSH_PENDING]

//>> GET_[QME_SCOM_XISGB_SGB_FLUSH_PENDING]
static inline bool GET_QME_SCOM_XISGB_SGB_FLUSH_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISGB));
#endif
    return i_data.getBit<QME_SCOM_XISGB_SGB_FLUSH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XISGB_SGB_FLUSH_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XISGB_SGB_FLUSH_PENDING]

//>> PREP_[QME_SCRB_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCRB_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCRB_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SCRB_RW]

//>> GET_[QME_SCRB_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCRB_RW(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCRB_RW;
#endif
    return fapi2::getScom(i_target, QME_SCRB_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SCRB_RW]

//>> PUT_[QME_SCRB_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCRB_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCRB_RW, QME_SCRB_WO_CLEAR, QME_SCRB_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_SCRB_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SCRB_RW]

//>> PREP_[QME_SCRB_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCRB_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCRB_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SCRB_WO_CLEAR]

//>> GET_[QME_SCRB_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCRB_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCRB_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, QME_SCRB_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SCRB_WO_CLEAR]

//>> PUT_[QME_SCRB_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCRB_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCRB_RW, QME_SCRB_WO_CLEAR, QME_SCRB_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_SCRB_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SCRB_WO_CLEAR]

//>> PREP_[QME_SCRB_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCRB_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCRB_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SCRB_WO_OR]

//>> GET_[QME_SCRB_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCRB_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCRB_WO_OR;
#endif
    return fapi2::getScom(i_target, QME_SCRB_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SCRB_WO_OR]

//>> PUT_[QME_SCRB_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCRB_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCRB_RW, QME_SCRB_WO_CLEAR, QME_SCRB_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_SCRB_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SCRB_WO_OR]


//>> SET_[QME_SCRB_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_SCRB_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCRB_RW, QME_SCRB_WO_CLEAR, QME_SCRB_WO_OR));
#endif
    return o_data.insertFromRight<QME_SCRB_DATA,
           QME_SCRB_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCRB_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCRB_DATA]

//>> SET_[QME_SCRB_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_SCRB_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCRB_RW, QME_SCRB_WO_CLEAR, QME_SCRB_WO_OR));
#endif
    return o_data.insertFromRight<QME_SCRB_DATA,
           QME_SCRB_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCRB_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCRB_DATA]

//>> GET_[QME_SCRB_DATA]
static inline fapi2::buffer<uint64_t>& GET_QME_SCRB_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCRB_RW, QME_SCRB_WO_CLEAR, QME_SCRB_WO_OR));
#endif
    return i_data.extractToRight<QME_SCRB_DATA,
           QME_SCRB_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCRB_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCRB_DATA]

//>> PREP_[QME_THOR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_THOR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_THOR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_THOR]

//>> GET_[QME_THOR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_THOR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_THOR;
#endif
    return fapi2::getScom(i_target, QME_THOR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_THOR]

//>> PUT_[QME_THOR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_THOR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_THOR));
#endif
    return fapi2::putScom(i_target, QME_THOR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_THOR]


//>> SET_[QME_THOR_TSR_OVERRIDE_EN]
static inline fapi2::buffer<uint64_t>& SET_QME_THOR_TSR_OVERRIDE_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_THOR));
#endif
    return o_data.insertFromRight<QME_THOR_TSR_OVERRIDE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_THOR_TSR_OVERRIDE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_THOR_TSR_OVERRIDE_EN]

//>> SET_[QME_THOR_TSR_OVERRIDE_EN]
static inline fapi2::buffer<uint64_t>& SET_QME_THOR_TSR_OVERRIDE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_THOR));
#endif
    return o_data.insertFromRight<QME_THOR_TSR_OVERRIDE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_THOR_TSR_OVERRIDE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_THOR_TSR_OVERRIDE_EN]

//>> SET_[QME_THOR_TSR_OVERRIDE_EN]
static inline fapi2::buffer<uint64_t>& SET_QME_THOR_TSR_OVERRIDE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_THOR));
#endif
    return o_data.setBit<QME_THOR_TSR_OVERRIDE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_THOR_TSR_OVERRIDE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_THOR_TSR_OVERRIDE_EN]

//>> CLEAR_[QME_THOR_TSR_OVERRIDE_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_THOR_TSR_OVERRIDE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_THOR));
#endif
    return o_data.clearBit<QME_THOR_TSR_OVERRIDE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_THOR_TSR_OVERRIDE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_THOR_TSR_OVERRIDE_EN]

//>> GET_[QME_THOR_TSR_OVERRIDE_EN]
static inline fapi2::buffer<uint64_t>& GET_QME_THOR_TSR_OVERRIDE_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_THOR));
#endif
    return i_data.extractToRight<QME_THOR_TSR_OVERRIDE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_THOR_TSR_OVERRIDE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_THOR_TSR_OVERRIDE_EN]

//>> GET_[QME_THOR_TSR_OVERRIDE_EN]
static inline bool GET_QME_THOR_TSR_OVERRIDE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_THOR));
#endif
    return i_data.getBit<QME_THOR_TSR_OVERRIDE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_THOR_TSR_OVERRIDE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_THOR_TSR_OVERRIDE_EN]

//>> SET_[QME_THOR_PTSR_OVERRIDE_SEL]
static inline fapi2::buffer<uint64_t>& SET_QME_THOR_PTSR_OVERRIDE_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_THOR));
#endif
    return o_data.insertFromRight<QME_THOR_PTSR_OVERRIDE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_THOR_PTSR_OVERRIDE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_THOR_PTSR_OVERRIDE_SEL]

//>> SET_[QME_THOR_PTSR_OVERRIDE_SEL]
static inline fapi2::buffer<uint64_t>& SET_QME_THOR_PTSR_OVERRIDE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_THOR));
#endif
    return o_data.insertFromRight<QME_THOR_PTSR_OVERRIDE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_THOR_PTSR_OVERRIDE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_THOR_PTSR_OVERRIDE_SEL]

//>> SET_[QME_THOR_PTSR_OVERRIDE_SEL]
static inline fapi2::buffer<uint64_t>& SET_QME_THOR_PTSR_OVERRIDE_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_THOR));
#endif
    return o_data.setBit<QME_THOR_PTSR_OVERRIDE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_THOR_PTSR_OVERRIDE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_THOR_PTSR_OVERRIDE_SEL]

//>> CLEAR_[QME_THOR_PTSR_OVERRIDE_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_THOR_PTSR_OVERRIDE_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_THOR));
#endif
    return o_data.clearBit<QME_THOR_PTSR_OVERRIDE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_THOR_PTSR_OVERRIDE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_THOR_PTSR_OVERRIDE_SEL]

//>> GET_[QME_THOR_PTSR_OVERRIDE_SEL]
static inline fapi2::buffer<uint64_t>& GET_QME_THOR_PTSR_OVERRIDE_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_THOR));
#endif
    return i_data.extractToRight<QME_THOR_PTSR_OVERRIDE_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_THOR_PTSR_OVERRIDE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_THOR_PTSR_OVERRIDE_SEL]

//>> GET_[QME_THOR_PTSR_OVERRIDE_SEL]
static inline bool GET_QME_THOR_PTSR_OVERRIDE_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_THOR));
#endif
    return i_data.getBit<QME_THOR_PTSR_OVERRIDE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_THOR_PTSR_OVERRIDE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_THOR_PTSR_OVERRIDE_SEL]

//>> SET_[QME_THOR_TSR_OVERRIDE_VAL]
static inline fapi2::buffer<uint64_t>& SET_QME_THOR_TSR_OVERRIDE_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_THOR));
#endif
    return o_data.insertFromRight<QME_THOR_TSR_OVERRIDE_VAL,
           QME_THOR_TSR_OVERRIDE_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_THOR_TSR_OVERRIDE_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_THOR_TSR_OVERRIDE_VAL]

//>> SET_[QME_THOR_TSR_OVERRIDE_VAL]
static inline fapi2::buffer<uint64_t>& SET_QME_THOR_TSR_OVERRIDE_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_THOR));
#endif
    return o_data.insertFromRight<QME_THOR_TSR_OVERRIDE_VAL,
           QME_THOR_TSR_OVERRIDE_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_THOR_TSR_OVERRIDE_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_THOR_TSR_OVERRIDE_VAL]

//>> GET_[QME_THOR_TSR_OVERRIDE_VAL]
static inline fapi2::buffer<uint64_t>& GET_QME_THOR_TSR_OVERRIDE_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_THOR));
#endif
    return i_data.extractToRight<QME_THOR_TSR_OVERRIDE_VAL,
           QME_THOR_TSR_OVERRIDE_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_THOR_TSR_OVERRIDE_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_THOR_TSR_OVERRIDE_VAL]

//>> PREP_[SPATTN]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SPATTN(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SPATTN;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SPATTN]

//>> GET_[SPATTN]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SPATTN(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SPATTN;
#endif
    return fapi2::getScom(i_target, SPATTN, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SPATTN]

//>> PUT_[SPATTN]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SPATTN(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return fapi2::putScom(i_target, SPATTN, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SPATTN]


//>> SET_[SPATTN_ANY_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_ANY_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_ANY_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_ANY_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_ANY_SPATTN]

//>> SET_[SPATTN_ANY_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_ANY_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_ANY_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_ANY_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_ANY_SPATTN]

//>> SET_[SPATTN_ANY_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_ANY_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_ANY_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_ANY_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_ANY_SPATTN]

//>> CLEAR_[SPATTN_ANY_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_ANY_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_ANY_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_ANY_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_ANY_SPATTN]

//>> GET_[SPATTN_ANY_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_ANY_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_ANY_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_ANY_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_ANY_SPATTN]

//>> GET_[SPATTN_ANY_SPATTN]
static inline bool GET_SPATTN_ANY_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_ANY_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_ANY_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_ANY_SPATTN]

//>> SET_[SPATTN_RESERVED1S]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_RESERVED1S(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_RESERVED1S,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_RESERVED1S chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_RESERVED1S]

//>> SET_[SPATTN_RESERVED1S]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_RESERVED1S(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_RESERVED1S,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_RESERVED1S chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_RESERVED1S]

//>> SET_[SPATTN_RESERVED1S]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_RESERVED1S(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_RESERVED1S>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_RESERVED1S chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_RESERVED1S]

//>> CLEAR_[SPATTN_RESERVED1S]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_RESERVED1S(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_RESERVED1S>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_RESERVED1S chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_RESERVED1S]

//>> GET_[SPATTN_RESERVED1S]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_RESERVED1S(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_RESERVED1S,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_RESERVED1S chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_RESERVED1S]

//>> GET_[SPATTN_RESERVED1S]
static inline bool GET_SPATTN_RESERVED1S(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_RESERVED1S>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_RESERVED1S chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_RESERVED1S]

//>> SET_[SPATTN_RESERVED2S]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_RESERVED2S(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_RESERVED2S,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_RESERVED2S chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_RESERVED2S]

//>> SET_[SPATTN_RESERVED2S]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_RESERVED2S(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_RESERVED2S,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_RESERVED2S chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_RESERVED2S]

//>> SET_[SPATTN_RESERVED2S]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_RESERVED2S(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_RESERVED2S>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_RESERVED2S chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_RESERVED2S]

//>> CLEAR_[SPATTN_RESERVED2S]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_RESERVED2S(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_RESERVED2S>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_RESERVED2S chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_RESERVED2S]

//>> GET_[SPATTN_RESERVED2S]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_RESERVED2S(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_RESERVED2S,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_RESERVED2S chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_RESERVED2S]

//>> GET_[SPATTN_RESERVED2S]
static inline bool GET_SPATTN_RESERVED2S(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_RESERVED2S>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_RESERVED2S chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_RESERVED2S]

//>> SET_[SPATTN_RESERVED3S]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_RESERVED3S(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_RESERVED3S,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_RESERVED3S chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_RESERVED3S]

//>> SET_[SPATTN_RESERVED3S]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_RESERVED3S(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_RESERVED3S,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_RESERVED3S chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_RESERVED3S]

//>> SET_[SPATTN_RESERVED3S]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_RESERVED3S(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_RESERVED3S>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_RESERVED3S chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_RESERVED3S]

//>> CLEAR_[SPATTN_RESERVED3S]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_RESERVED3S(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_RESERVED3S>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_RESERVED3S chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_RESERVED3S]

//>> GET_[SPATTN_RESERVED3S]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_RESERVED3S(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_RESERVED3S,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_RESERVED3S chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_RESERVED3S]

//>> GET_[SPATTN_RESERVED3S]
static inline bool GET_SPATTN_RESERVED3S(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_RESERVED3S>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_RESERVED3S chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_RESERVED3S]

//>> SET_[SPATTN_PERV]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_PERV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_PERV]

//>> SET_[SPATTN_PERV]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_PERV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_PERV]

//>> SET_[SPATTN_PERV]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_PERV]

//>> CLEAR_[SPATTN_PERV]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_PERV]

//>> GET_[SPATTN_PERV]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_PERV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_PERV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_PERV]

//>> GET_[SPATTN_PERV]
static inline bool GET_SPATTN_PERV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_PERV]

//>> SET_[SPATTN_IN05]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN05]

//>> SET_[SPATTN_IN05]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN05]

//>> SET_[SPATTN_IN05]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN05]

//>> CLEAR_[SPATTN_IN05]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN05]

//>> GET_[SPATTN_IN05]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN05]

//>> GET_[SPATTN_IN05]
static inline bool GET_SPATTN_IN05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN05]

//>> SET_[SPATTN_IN06]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN06]

//>> SET_[SPATTN_IN06]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN06]

//>> SET_[SPATTN_IN06]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN06]

//>> CLEAR_[SPATTN_IN06]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN06]

//>> GET_[SPATTN_IN06]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN06]

//>> GET_[SPATTN_IN06]
static inline bool GET_SPATTN_IN06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN06]

//>> SET_[SPATTN_IN07]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN07]

//>> SET_[SPATTN_IN07]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN07]

//>> SET_[SPATTN_IN07]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN07]

//>> CLEAR_[SPATTN_IN07]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN07]

//>> GET_[SPATTN_IN07]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN07]

//>> GET_[SPATTN_IN07]
static inline bool GET_SPATTN_IN07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN07]

//>> SET_[SPATTN_IN08]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN08]

//>> SET_[SPATTN_IN08]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN08]

//>> SET_[SPATTN_IN08]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN08]

//>> CLEAR_[SPATTN_IN08]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN08]

//>> GET_[SPATTN_IN08]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN08]

//>> GET_[SPATTN_IN08]
static inline bool GET_SPATTN_IN08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN08]

//>> SET_[SPATTN_IN09]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN09]

//>> SET_[SPATTN_IN09]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN09]

//>> SET_[SPATTN_IN09]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN09]

//>> CLEAR_[SPATTN_IN09]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN09]

//>> GET_[SPATTN_IN09]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN09]

//>> GET_[SPATTN_IN09]
static inline bool GET_SPATTN_IN09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN09]

//>> SET_[SPATTN_IN10]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN10]

//>> SET_[SPATTN_IN10]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN10]

//>> SET_[SPATTN_IN10]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN10]

//>> CLEAR_[SPATTN_IN10]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN10]

//>> GET_[SPATTN_IN10]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN10]

//>> GET_[SPATTN_IN10]
static inline bool GET_SPATTN_IN10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN10]

//>> SET_[SPATTN_IN11]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN11]

//>> SET_[SPATTN_IN11]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN11]

//>> SET_[SPATTN_IN11]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN11]

//>> CLEAR_[SPATTN_IN11]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN11]

//>> GET_[SPATTN_IN11]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN11]

//>> GET_[SPATTN_IN11]
static inline bool GET_SPATTN_IN11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN11]

//>> SET_[SPATTN_IN12]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN12]

//>> SET_[SPATTN_IN12]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN12]

//>> SET_[SPATTN_IN12]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN12]

//>> CLEAR_[SPATTN_IN12]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN12]

//>> GET_[SPATTN_IN12]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN12]

//>> GET_[SPATTN_IN12]
static inline bool GET_SPATTN_IN12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN12]

//>> SET_[SPATTN_IN13]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN13]

//>> SET_[SPATTN_IN13]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN13]

//>> SET_[SPATTN_IN13]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN13]

//>> CLEAR_[SPATTN_IN13]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN13]

//>> GET_[SPATTN_IN13]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN13]

//>> GET_[SPATTN_IN13]
static inline bool GET_SPATTN_IN13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN13]

//>> SET_[SPATTN_IN14]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN14]

//>> SET_[SPATTN_IN14]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN14]

//>> SET_[SPATTN_IN14]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN14]

//>> CLEAR_[SPATTN_IN14]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN14]

//>> GET_[SPATTN_IN14]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN14]

//>> GET_[SPATTN_IN14]
static inline bool GET_SPATTN_IN14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN14]

//>> SET_[SPATTN_IN15]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN15]

//>> SET_[SPATTN_IN15]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN15]

//>> SET_[SPATTN_IN15]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN15]

//>> CLEAR_[SPATTN_IN15]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN15]

//>> GET_[SPATTN_IN15]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN15]

//>> GET_[SPATTN_IN15]
static inline bool GET_SPATTN_IN15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN15]

//>> SET_[SPATTN_IN16]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN16]

//>> SET_[SPATTN_IN16]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN16]

//>> SET_[SPATTN_IN16]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN16]

//>> CLEAR_[SPATTN_IN16]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN16]

//>> GET_[SPATTN_IN16]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN16]

//>> GET_[SPATTN_IN16]
static inline bool GET_SPATTN_IN16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN16]

//>> SET_[SPATTN_IN17]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN17]

//>> SET_[SPATTN_IN17]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN17]

//>> SET_[SPATTN_IN17]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN17]

//>> CLEAR_[SPATTN_IN17]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN17]

//>> GET_[SPATTN_IN17]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN17]

//>> GET_[SPATTN_IN17]
static inline bool GET_SPATTN_IN17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN17]

//>> SET_[SPATTN_IN18]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN18]

//>> SET_[SPATTN_IN18]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN18]

//>> SET_[SPATTN_IN18]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN18]

//>> CLEAR_[SPATTN_IN18]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN18]

//>> GET_[SPATTN_IN18]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN18]

//>> GET_[SPATTN_IN18]
static inline bool GET_SPATTN_IN18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN18]

//>> SET_[SPATTN_IN19]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN19]

//>> SET_[SPATTN_IN19]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN19]

//>> SET_[SPATTN_IN19]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN19]

//>> CLEAR_[SPATTN_IN19]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN19]

//>> GET_[SPATTN_IN19]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN19]

//>> GET_[SPATTN_IN19]
static inline bool GET_SPATTN_IN19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN19]

//>> SET_[SPATTN_IN20]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN20]

//>> SET_[SPATTN_IN20]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN20]

//>> SET_[SPATTN_IN20]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN20]

//>> CLEAR_[SPATTN_IN20]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN20]

//>> GET_[SPATTN_IN20]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN20]

//>> GET_[SPATTN_IN20]
static inline bool GET_SPATTN_IN20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN20]

//>> SET_[SPATTN_IN21]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN21]

//>> SET_[SPATTN_IN21]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN21]

//>> SET_[SPATTN_IN21]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN21]

//>> CLEAR_[SPATTN_IN21]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN21]

//>> GET_[SPATTN_IN21]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN21]

//>> GET_[SPATTN_IN21]
static inline bool GET_SPATTN_IN21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN21]

//>> SET_[SPATTN_IN22]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN22]

//>> SET_[SPATTN_IN22]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN22]

//>> SET_[SPATTN_IN22]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN22]

//>> CLEAR_[SPATTN_IN22]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN22]

//>> GET_[SPATTN_IN22]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN22]

//>> GET_[SPATTN_IN22]
static inline bool GET_SPATTN_IN22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN22]

//>> SET_[SPATTN_IN23]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN23]

//>> SET_[SPATTN_IN23]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN23]

//>> SET_[SPATTN_IN23]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN23]

//>> CLEAR_[SPATTN_IN23]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN23]

//>> GET_[SPATTN_IN23]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN23]

//>> GET_[SPATTN_IN23]
static inline bool GET_SPATTN_IN23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN23]

//>> SET_[SPATTN_IN24]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN24]

//>> SET_[SPATTN_IN24]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN24]

//>> SET_[SPATTN_IN24]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN24]

//>> CLEAR_[SPATTN_IN24]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN24]

//>> GET_[SPATTN_IN24]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN24]

//>> GET_[SPATTN_IN24]
static inline bool GET_SPATTN_IN24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN24]

//>> SET_[SPATTN_IN25]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN25]

//>> SET_[SPATTN_IN25]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN25]

//>> SET_[SPATTN_IN25]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN25]

//>> CLEAR_[SPATTN_IN25]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN25]

//>> GET_[SPATTN_IN25]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN25]

//>> GET_[SPATTN_IN25]
static inline bool GET_SPATTN_IN25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN25]

//>> SET_[SPATTN_IN26]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN26]

//>> SET_[SPATTN_IN26]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN26]

//>> SET_[SPATTN_IN26]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN26]

//>> CLEAR_[SPATTN_IN26]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN26]

//>> GET_[SPATTN_IN26]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN26]

//>> GET_[SPATTN_IN26]
static inline bool GET_SPATTN_IN26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN26]

//>> SET_[SPATTN_IN27]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN27]

//>> SET_[SPATTN_IN27]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN27]

//>> SET_[SPATTN_IN27]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN27]

//>> CLEAR_[SPATTN_IN27]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN27]

//>> GET_[SPATTN_IN27]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN27]

//>> GET_[SPATTN_IN27]
static inline bool GET_SPATTN_IN27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN27]

//>> SET_[SPATTN_IN28]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN28]

//>> SET_[SPATTN_IN28]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN28]

//>> SET_[SPATTN_IN28]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN28]

//>> CLEAR_[SPATTN_IN28]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN28]

//>> GET_[SPATTN_IN28]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN28]

//>> GET_[SPATTN_IN28]
static inline bool GET_SPATTN_IN28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN28]

//>> SET_[SPATTN_IN29]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN29]

//>> SET_[SPATTN_IN29]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN29]

//>> SET_[SPATTN_IN29]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN29]

//>> CLEAR_[SPATTN_IN29]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN29]

//>> GET_[SPATTN_IN29]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN29]

//>> GET_[SPATTN_IN29]
static inline bool GET_SPATTN_IN29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN29]

//>> SET_[SPATTN_IN30]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN30]

//>> SET_[SPATTN_IN30]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN30]

//>> SET_[SPATTN_IN30]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN30]

//>> CLEAR_[SPATTN_IN30]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN30]

//>> GET_[SPATTN_IN30]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN30]

//>> GET_[SPATTN_IN30]
static inline bool GET_SPATTN_IN30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN30]

//>> SET_[SPATTN_IN31]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN31]

//>> SET_[SPATTN_IN31]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN31]

//>> SET_[SPATTN_IN31]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN31]

//>> CLEAR_[SPATTN_IN31]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN31]

//>> GET_[SPATTN_IN31]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN31]

//>> GET_[SPATTN_IN31]
static inline bool GET_SPATTN_IN31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN31]

//>> SET_[SPATTN_IN32]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN32]

//>> SET_[SPATTN_IN32]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN32]

//>> SET_[SPATTN_IN32]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN32]

//>> CLEAR_[SPATTN_IN32]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN32]

//>> GET_[SPATTN_IN32]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN32]

//>> GET_[SPATTN_IN32]
static inline bool GET_SPATTN_IN32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN32]

//>> SET_[SPATTN_IN33]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN33]

//>> SET_[SPATTN_IN33]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN33]

//>> SET_[SPATTN_IN33]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN33]

//>> CLEAR_[SPATTN_IN33]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN33]

//>> GET_[SPATTN_IN33]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN33]

//>> GET_[SPATTN_IN33]
static inline bool GET_SPATTN_IN33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN33]

//>> SET_[SPATTN_IN34]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN34]

//>> SET_[SPATTN_IN34]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN34]

//>> SET_[SPATTN_IN34]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN34]

//>> CLEAR_[SPATTN_IN34]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN34]

//>> GET_[SPATTN_IN34]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN34]

//>> GET_[SPATTN_IN34]
static inline bool GET_SPATTN_IN34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN34]

//>> SET_[SPATTN_IN35]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SPATTN_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN35]

//>> SET_[SPATTN_IN35]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.insertFromRight<SPATTN_IN35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SPATTN_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN35]

//>> SET_[SPATTN_IN35]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_IN35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.setBit<SPATTN_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SPATTN_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_IN35]

//>> CLEAR_[SPATTN_IN35]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_IN35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return o_data.clearBit<SPATTN_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SPATTN_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_IN35]

//>> GET_[SPATTN_IN35]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_IN35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.extractToRight<SPATTN_IN35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SPATTN_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN35]

//>> GET_[SPATTN_IN35]
static inline bool GET_SPATTN_IN35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN));
#endif
    return i_data.getBit<SPATTN_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SPATTN_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN35]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
