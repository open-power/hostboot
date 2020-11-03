/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/perv/reg00004.H $         */
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

#ifndef __PERV_REG00004_H_
#define __PERV_REG00004_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
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
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_ABIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_ABIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_ABIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_ABIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_ABIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_ABIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_EBIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_EBIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_EBIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_EBIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_EBIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_EBIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_RESERVED_2I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_RESERVED_2I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_RESERVED_2I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_RESERVED_2I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_RESERVED_2I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_RESERVED_2I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_RESERVED_3I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_RESERVED_3I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_RESERVED_3I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_RESERVED_3I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_RESERVED_3I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_RESERVED_3I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_TC_DIAG_PORT0_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_TC_DIAG_PORT0_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_TC_DIAG_PORT0_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_TC_DIAG_PORT0_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_TC_DIAG_PORT0_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_TC_DIAG_PORT0_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_TC_DIAG_PORT1_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_TC_DIAG_PORT1_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_TC_DIAG_PORT1_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_TC_DIAG_PORT1_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_TC_DIAG_PORT1_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_TC_DIAG_PORT1_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_RESERVED_6I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_RESERVED_6I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_RESERVED_6I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_RESERVED_6I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_RESERVED_6I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_RESERVED_6I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_RESERVED_6I]

//>> SET_[CPLT_STAT0_PLL_DESTOUT]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_PLL_DESTOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_PLL_DESTOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_PLL_DESTOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_PLL_DESTOUT]

//>> SET_[CPLT_STAT0_PLL_DESTOUT]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_PLL_DESTOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_PLL_DESTOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_PLL_DESTOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_PLL_DESTOUT]

//>> SET_[CPLT_STAT0_PLL_DESTOUT]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_PLL_DESTOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_PLL_DESTOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_PLL_DESTOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_PLL_DESTOUT]

//>> CLEAR_[CPLT_STAT0_PLL_DESTOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_PLL_DESTOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_PLL_DESTOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_PLL_DESTOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_PLL_DESTOUT]

//>> GET_[CPLT_STAT0_PLL_DESTOUT]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_PLL_DESTOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_PLL_DESTOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_PLL_DESTOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_PLL_DESTOUT]

//>> GET_[CPLT_STAT0_PLL_DESTOUT]
static inline bool GET_CPLT_STAT0_PLL_DESTOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_PLL_DESTOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_PLL_DESTOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_PLL_DESTOUT]

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
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_CC_CTRL_OPCG_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_CC_CTRL_OPCG_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_CC_CTRL_OPCG_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_CC_CTRL_OPCG_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_CC_CTRL_OPCG_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_CC_CTRL_OPCG_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC]

//>> SET_[CPLT_STAT0_IOPCI_TC_HSSPRTREADYA]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_IOPCI_TC_HSSPRTREADYA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_IOPCI_TC_HSSPRTREADYA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_IOPCI_TC_HSSPRTREADYA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_IOPCI_TC_HSSPRTREADYA]

//>> SET_[CPLT_STAT0_IOPCI_TC_HSSPRTREADYA]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_IOPCI_TC_HSSPRTREADYA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_IOPCI_TC_HSSPRTREADYA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_IOPCI_TC_HSSPRTREADYA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_IOPCI_TC_HSSPRTREADYA]

//>> SET_[CPLT_STAT0_IOPCI_TC_HSSPRTREADYA]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_IOPCI_TC_HSSPRTREADYA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_IOPCI_TC_HSSPRTREADYA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_IOPCI_TC_HSSPRTREADYA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_IOPCI_TC_HSSPRTREADYA]

//>> CLEAR_[CPLT_STAT0_IOPCI_TC_HSSPRTREADYA]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_IOPCI_TC_HSSPRTREADYA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_IOPCI_TC_HSSPRTREADYA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_IOPCI_TC_HSSPRTREADYA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_IOPCI_TC_HSSPRTREADYA]

//>> GET_[CPLT_STAT0_IOPCI_TC_HSSPRTREADYA]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_IOPCI_TC_HSSPRTREADYA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_IOPCI_TC_HSSPRTREADYA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_IOPCI_TC_HSSPRTREADYA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_IOPCI_TC_HSSPRTREADYA]

//>> GET_[CPLT_STAT0_IOPCI_TC_HSSPRTREADYA]
static inline bool GET_CPLT_STAT0_IOPCI_TC_HSSPRTREADYA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_IOPCI_TC_HSSPRTREADYA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_IOPCI_TC_HSSPRTREADYA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_IOPCI_TC_HSSPRTREADYA]

//>> SET_[CPLT_STAT0_FREE_USAGE_10I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_10I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_10I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_10I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_10I]

//>> SET_[CPLT_STAT0_FREE_USAGE_10I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_10I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_10I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_10I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_10I]

//>> SET_[CPLT_STAT0_FREE_USAGE_10I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_10I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_FREE_USAGE_10I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_10I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_10I]

//>> CLEAR_[CPLT_STAT0_FREE_USAGE_10I]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_FREE_USAGE_10I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_FREE_USAGE_10I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_10I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_FREE_USAGE_10I]

//>> GET_[CPLT_STAT0_FREE_USAGE_10I]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_FREE_USAGE_10I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_FREE_USAGE_10I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_10I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_10I]

//>> GET_[CPLT_STAT0_FREE_USAGE_10I]
static inline bool GET_CPLT_STAT0_FREE_USAGE_10I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_FREE_USAGE_10I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_10I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_10I]

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
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR]

//>> SET_[CPLT_STAT0_IOPCI_TC_HSSPRTREADYB]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_IOPCI_TC_HSSPRTREADYB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_IOPCI_TC_HSSPRTREADYB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_IOPCI_TC_HSSPRTREADYB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_IOPCI_TC_HSSPRTREADYB]

//>> SET_[CPLT_STAT0_IOPCI_TC_HSSPRTREADYB]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_IOPCI_TC_HSSPRTREADYB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_IOPCI_TC_HSSPRTREADYB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_IOPCI_TC_HSSPRTREADYB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_IOPCI_TC_HSSPRTREADYB]

//>> SET_[CPLT_STAT0_IOPCI_TC_HSSPRTREADYB]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_IOPCI_TC_HSSPRTREADYB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_IOPCI_TC_HSSPRTREADYB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_IOPCI_TC_HSSPRTREADYB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_IOPCI_TC_HSSPRTREADYB]

//>> CLEAR_[CPLT_STAT0_IOPCI_TC_HSSPRTREADYB]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_IOPCI_TC_HSSPRTREADYB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_IOPCI_TC_HSSPRTREADYB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_IOPCI_TC_HSSPRTREADYB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_IOPCI_TC_HSSPRTREADYB]

//>> GET_[CPLT_STAT0_IOPCI_TC_HSSPRTREADYB]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_IOPCI_TC_HSSPRTREADYB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_IOPCI_TC_HSSPRTREADYB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_IOPCI_TC_HSSPRTREADYB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_IOPCI_TC_HSSPRTREADYB]

//>> GET_[CPLT_STAT0_IOPCI_TC_HSSPRTREADYB]
static inline bool GET_CPLT_STAT0_IOPCI_TC_HSSPRTREADYB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_IOPCI_TC_HSSPRTREADYB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_IOPCI_TC_HSSPRTREADYB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_IOPCI_TC_HSSPRTREADYB]

//>> SET_[CPLT_STAT0_FREE_USAGE_11I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_11I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_11I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_11I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_11I]

//>> SET_[CPLT_STAT0_FREE_USAGE_11I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_11I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_11I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_11I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_11I]

//>> SET_[CPLT_STAT0_FREE_USAGE_11I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_11I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_FREE_USAGE_11I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_11I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_11I]

//>> CLEAR_[CPLT_STAT0_FREE_USAGE_11I]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_FREE_USAGE_11I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_FREE_USAGE_11I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_11I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_FREE_USAGE_11I]

//>> GET_[CPLT_STAT0_FREE_USAGE_11I]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_FREE_USAGE_11I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_FREE_USAGE_11I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_11I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_11I]

//>> GET_[CPLT_STAT0_FREE_USAGE_11I]
static inline bool GET_CPLT_STAT0_FREE_USAGE_11I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_FREE_USAGE_11I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_11I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_11I]

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
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR chip: %x, ec: %x",
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
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR chip: %x, ec: %x",
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
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR chip: %x, ec: %x",
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
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR chip: %x, ec: %x",
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
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR chip: %x, ec: %x",
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
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR]

//>> SET_[CPLT_STAT0_FREE_USAGE_12I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_12I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_12I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_12I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_12I]

//>> SET_[CPLT_STAT0_FREE_USAGE_12I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_12I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_12I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_12I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_12I]

//>> SET_[CPLT_STAT0_FREE_USAGE_12I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_12I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_FREE_USAGE_12I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_12I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_12I]

//>> CLEAR_[CPLT_STAT0_FREE_USAGE_12I]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_FREE_USAGE_12I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_FREE_USAGE_12I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_12I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_FREE_USAGE_12I]

//>> GET_[CPLT_STAT0_FREE_USAGE_12I]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_FREE_USAGE_12I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_FREE_USAGE_12I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_12I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_12I]

//>> GET_[CPLT_STAT0_FREE_USAGE_12I]
static inline bool GET_CPLT_STAT0_FREE_USAGE_12I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_FREE_USAGE_12I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_12I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_12I]

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
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED]

//>> SET_[CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN]

//>> SET_[CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN]

//>> SET_[CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN]

//>> CLEAR_[CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN]

//>> GET_[CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN]

//>> GET_[CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN]
static inline bool GET_CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN]

//>> SET_[CPLT_STAT0_FREE_USAGE_13I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_13I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_13I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_13I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_13I]

//>> SET_[CPLT_STAT0_FREE_USAGE_13I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_13I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_13I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_13I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_13I]

//>> SET_[CPLT_STAT0_FREE_USAGE_13I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_13I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_FREE_USAGE_13I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_13I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_13I]

//>> CLEAR_[CPLT_STAT0_FREE_USAGE_13I]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_FREE_USAGE_13I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_FREE_USAGE_13I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_13I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_FREE_USAGE_13I]

//>> GET_[CPLT_STAT0_FREE_USAGE_13I]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_FREE_USAGE_13I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_FREE_USAGE_13I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_13I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_13I]

//>> GET_[CPLT_STAT0_FREE_USAGE_13I]
static inline bool GET_CPLT_STAT0_FREE_USAGE_13I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_FREE_USAGE_13I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_13I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_13I]

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
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT]

//>> SET_[CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN]

//>> SET_[CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN]

//>> SET_[CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN]

//>> CLEAR_[CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN]

//>> GET_[CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN]

//>> GET_[CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN]
static inline bool GET_CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN]

//>> SET_[CPLT_STAT0_FREE_USAGE_14I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_14I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_14I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_14I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_14I]

//>> SET_[CPLT_STAT0_FREE_USAGE_14I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_14I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_14I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_14I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_14I]

//>> SET_[CPLT_STAT0_FREE_USAGE_14I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_14I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_FREE_USAGE_14I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_14I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_14I]

//>> CLEAR_[CPLT_STAT0_FREE_USAGE_14I]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_FREE_USAGE_14I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_FREE_USAGE_14I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_14I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_FREE_USAGE_14I]

//>> GET_[CPLT_STAT0_FREE_USAGE_14I]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_FREE_USAGE_14I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_FREE_USAGE_14I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_14I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_14I]

//>> GET_[CPLT_STAT0_FREE_USAGE_14I]
static inline bool GET_CPLT_STAT0_FREE_USAGE_14I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_FREE_USAGE_14I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_14I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_14I]

//>> SET_[CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN]

//>> SET_[CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN]

//>> SET_[CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN]

//>> CLEAR_[CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN]

//>> GET_[CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN]

//>> GET_[CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN]
static inline bool GET_CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN]

//>> SET_[CPLT_STAT0_FREE_USAGE_15I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_15I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_15I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_15I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_15I]

//>> SET_[CPLT_STAT0_FREE_USAGE_15I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_15I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_15I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_15I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_15I]

//>> SET_[CPLT_STAT0_FREE_USAGE_15I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_15I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_FREE_USAGE_15I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_15I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_15I]

//>> CLEAR_[CPLT_STAT0_FREE_USAGE_15I]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_FREE_USAGE_15I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_FREE_USAGE_15I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_15I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_FREE_USAGE_15I]

//>> GET_[CPLT_STAT0_FREE_USAGE_15I]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_FREE_USAGE_15I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_FREE_USAGE_15I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_15I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_15I]

//>> GET_[CPLT_STAT0_FREE_USAGE_15I]
static inline bool GET_CPLT_STAT0_FREE_USAGE_15I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_FREE_USAGE_15I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_15I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_15I]

//>> SET_[CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN]

//>> SET_[CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN]

//>> SET_[CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN]

//>> CLEAR_[CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN]

//>> GET_[CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN]

//>> GET_[CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN]
static inline bool GET_CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN]

//>> SET_[CPLT_STAT0_FREE_USAGE_16I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_16I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_16I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_16I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_16I]

//>> SET_[CPLT_STAT0_FREE_USAGE_16I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_16I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_16I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_16I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_16I]

//>> SET_[CPLT_STAT0_FREE_USAGE_16I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_16I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_FREE_USAGE_16I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_16I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_16I]

//>> CLEAR_[CPLT_STAT0_FREE_USAGE_16I]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_FREE_USAGE_16I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_FREE_USAGE_16I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_16I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_FREE_USAGE_16I]

//>> GET_[CPLT_STAT0_FREE_USAGE_16I]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_FREE_USAGE_16I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_FREE_USAGE_16I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_16I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_16I]

//>> GET_[CPLT_STAT0_FREE_USAGE_16I]
static inline bool GET_CPLT_STAT0_FREE_USAGE_16I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_FREE_USAGE_16I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_16I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_16I]

//>> SET_[CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN]

//>> SET_[CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN]

//>> SET_[CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN]

//>> CLEAR_[CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN]

//>> GET_[CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN]

//>> GET_[CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN]
static inline bool GET_CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN]

//>> SET_[CPLT_STAT0_FREE_USAGE_17I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_17I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_17I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_17I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_17I]

//>> SET_[CPLT_STAT0_FREE_USAGE_17I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_17I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_17I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_17I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_17I]

//>> SET_[CPLT_STAT0_FREE_USAGE_17I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_17I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_FREE_USAGE_17I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_17I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_17I]

//>> CLEAR_[CPLT_STAT0_FREE_USAGE_17I]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_FREE_USAGE_17I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_FREE_USAGE_17I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_17I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_FREE_USAGE_17I]

//>> GET_[CPLT_STAT0_FREE_USAGE_17I]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_FREE_USAGE_17I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_FREE_USAGE_17I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_17I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_17I]

//>> GET_[CPLT_STAT0_FREE_USAGE_17I]
static inline bool GET_CPLT_STAT0_FREE_USAGE_17I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_FREE_USAGE_17I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_17I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_17I]

//>> SET_[CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN]

//>> SET_[CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN]

//>> SET_[CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN]

//>> CLEAR_[CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN]

//>> GET_[CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN]

//>> GET_[CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN]
static inline bool GET_CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN]

//>> SET_[CPLT_STAT0_FREE_USAGE_18I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_18I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_18I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_18I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_18I]

//>> SET_[CPLT_STAT0_FREE_USAGE_18I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_18I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_18I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_18I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_18I]

//>> SET_[CPLT_STAT0_FREE_USAGE_18I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_18I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_FREE_USAGE_18I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_18I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_18I]

//>> CLEAR_[CPLT_STAT0_FREE_USAGE_18I]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_FREE_USAGE_18I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_FREE_USAGE_18I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_18I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_FREE_USAGE_18I]

//>> GET_[CPLT_STAT0_FREE_USAGE_18I]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_FREE_USAGE_18I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_FREE_USAGE_18I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_18I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_18I]

//>> GET_[CPLT_STAT0_FREE_USAGE_18I]
static inline bool GET_CPLT_STAT0_FREE_USAGE_18I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_FREE_USAGE_18I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_18I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_18I]

//>> SET_[CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN]

//>> SET_[CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN]

//>> SET_[CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN]

//>> CLEAR_[CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN]

//>> GET_[CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN]

//>> GET_[CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN]
static inline bool GET_CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN]

//>> SET_[CPLT_STAT0_FREE_USAGE_19I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_19I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_19I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_19I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_19I]

//>> SET_[CPLT_STAT0_FREE_USAGE_19I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_19I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_19I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_19I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_19I]

//>> SET_[CPLT_STAT0_FREE_USAGE_19I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_19I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_FREE_USAGE_19I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_19I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_19I]

//>> CLEAR_[CPLT_STAT0_FREE_USAGE_19I]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_FREE_USAGE_19I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_FREE_USAGE_19I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_19I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_FREE_USAGE_19I]

//>> GET_[CPLT_STAT0_FREE_USAGE_19I]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_FREE_USAGE_19I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_FREE_USAGE_19I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_19I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_19I]

//>> GET_[CPLT_STAT0_FREE_USAGE_19I]
static inline bool GET_CPLT_STAT0_FREE_USAGE_19I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_FREE_USAGE_19I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_19I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_19I]

//>> SET_[CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN]

//>> SET_[CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN]

//>> SET_[CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN]

//>> CLEAR_[CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN]

//>> GET_[CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN]

//>> GET_[CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN]
static inline bool GET_CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN]

//>> SET_[CPLT_STAT0_FREE_USAGE_20I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_20I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_20I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_20I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_20I]

//>> SET_[CPLT_STAT0_FREE_USAGE_20I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_20I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_20I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_20I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_20I]

//>> SET_[CPLT_STAT0_FREE_USAGE_20I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_20I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_FREE_USAGE_20I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_20I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_20I]

//>> CLEAR_[CPLT_STAT0_FREE_USAGE_20I]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_FREE_USAGE_20I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_FREE_USAGE_20I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_20I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_FREE_USAGE_20I]

//>> GET_[CPLT_STAT0_FREE_USAGE_20I]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_FREE_USAGE_20I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_FREE_USAGE_20I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_20I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_20I]

//>> GET_[CPLT_STAT0_FREE_USAGE_20I]
static inline bool GET_CPLT_STAT0_FREE_USAGE_20I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_FREE_USAGE_20I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_20I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_20I]

//>> SET_[CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN]

//>> SET_[CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN]

//>> SET_[CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN]

//>> CLEAR_[CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN]

//>> GET_[CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN]

//>> GET_[CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN]
static inline bool GET_CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN]

//>> SET_[CPLT_STAT0_FREE_USAGE_21I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_21I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_21I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_21I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_21I]

//>> SET_[CPLT_STAT0_FREE_USAGE_21I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_21I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_21I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_21I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_21I]

//>> SET_[CPLT_STAT0_FREE_USAGE_21I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_21I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_FREE_USAGE_21I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_21I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_21I]

//>> CLEAR_[CPLT_STAT0_FREE_USAGE_21I]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_FREE_USAGE_21I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_FREE_USAGE_21I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_21I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_FREE_USAGE_21I]

//>> GET_[CPLT_STAT0_FREE_USAGE_21I]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_FREE_USAGE_21I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_FREE_USAGE_21I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_21I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_21I]

//>> GET_[CPLT_STAT0_FREE_USAGE_21I]
static inline bool GET_CPLT_STAT0_FREE_USAGE_21I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_FREE_USAGE_21I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_21I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_21I]

//>> SET_[CPLT_STAT0_FREE_USAGE_22I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_22I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_22I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_22I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_22I]

//>> SET_[CPLT_STAT0_FREE_USAGE_22I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_22I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_22I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_22I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_22I]

//>> SET_[CPLT_STAT0_FREE_USAGE_22I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_22I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_FREE_USAGE_22I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_22I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_22I]

//>> CLEAR_[CPLT_STAT0_FREE_USAGE_22I]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_FREE_USAGE_22I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_FREE_USAGE_22I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_22I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_FREE_USAGE_22I]

//>> GET_[CPLT_STAT0_FREE_USAGE_22I]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_FREE_USAGE_22I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_FREE_USAGE_22I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_22I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_22I]

//>> GET_[CPLT_STAT0_FREE_USAGE_22I]
static inline bool GET_CPLT_STAT0_FREE_USAGE_22I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_FREE_USAGE_22I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_22I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_22I]

//>> SET_[CPLT_STAT0_FREE_USAGE_23I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_23I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_23I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_23I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_23I]

//>> SET_[CPLT_STAT0_FREE_USAGE_23I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_23I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.insertFromRight<CPLT_STAT0_FREE_USAGE_23I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_23I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_23I]

//>> SET_[CPLT_STAT0_FREE_USAGE_23I]
static inline fapi2::buffer<uint64_t>& SET_CPLT_STAT0_FREE_USAGE_23I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.setBit<CPLT_STAT0_FREE_USAGE_23I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_23I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_STAT0_FREE_USAGE_23I]

//>> CLEAR_[CPLT_STAT0_FREE_USAGE_23I]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_STAT0_FREE_USAGE_23I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return o_data.clearBit<CPLT_STAT0_FREE_USAGE_23I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_23I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_STAT0_FREE_USAGE_23I]

//>> GET_[CPLT_STAT0_FREE_USAGE_23I]
static inline fapi2::buffer<uint64_t>& GET_CPLT_STAT0_FREE_USAGE_23I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.extractToRight<CPLT_STAT0_FREE_USAGE_23I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_23I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_23I]

//>> GET_[CPLT_STAT0_FREE_USAGE_23I]
static inline bool GET_CPLT_STAT0_FREE_USAGE_23I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_STAT0));
#endif
    return i_data.getBit<CPLT_STAT0_FREE_USAGE_23I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_23I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_23I]

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
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_GLOBAL_FEH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_GLOBAL_FEH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_GLOBAL_FEH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_GLOBAL_FEH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_GLOBAL_FEH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_GLOBAL_FEH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_25I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_25I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_25I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_25I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_25I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_25I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_26I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_26I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_26I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_26I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_26I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_26I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_27I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_27I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_27I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_27I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_27I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_27I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_28I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_28I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_28I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_28I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_28I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_28I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_29I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_29I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_29I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_29I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_29I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_29I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_30I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_30I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_30I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_30I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_30I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_30I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_31I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_31I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_31I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_31I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_31I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_STAT0_FREE_USAGE_31I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
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
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
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
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
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
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
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
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
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
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
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
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
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
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
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
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
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
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
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
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
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
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
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
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1 chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1 chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1 chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2 chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2 chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2 chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3]

//>> PREP_[FSXCOMP_FSXLOG_PERV_CTRL0_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_PERV_CTRL0_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL0_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_PERV_CTRL0_FSI]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_PERV_CTRL0_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL0_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL0_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_FSI]

//>> PUT_[FSXCOMP_FSXLOG_PERV_CTRL0_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_PERV_CTRL0_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL0_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_PERV_CTRL0_FSI]

//>> PREP_[FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_PERV_CTRL0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_PERV_CTRL0_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL0_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_PERV_CTRL0_RW]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_PERV_CTRL0_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL0_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL0_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_RW]

//>> PUT_[FSXCOMP_FSXLOG_PERV_CTRL0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_PERV_CTRL0_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL0_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_PERV_CTRL0_RW]


//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_3_6_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_3_6_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_3_6_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_3_6_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_3_6_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_3_6_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_3_6_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_3_6_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_3_6_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_3_6_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_3_6_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_3_6_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_3_6_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_3_6_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_3_6_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_3_6_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_3_6_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_3_6_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_10_12_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_10_12_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_10_12_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_10_12_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_10_12_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_10_12_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_10_12_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_10_12_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_10_12_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_10_12_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_10_12_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_10_12_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_10_12_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_10_12_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_10_12_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_10_12_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_10_12_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_10_12_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_19_21_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_19_21_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_19_21_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_19_21_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_19_21_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_19_21_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_19_21_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_19_21_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_19_21_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_19_21_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_19_21_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_19_21_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_19_21_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_19_21_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_19_21_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_19_21_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_19_21_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_19_21_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_26_27_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_26_27_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_26_27_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_26_27_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_26_27_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_26_27_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_26_27_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_26_27_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_26_27_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_26_27_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_26_27_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_26_27_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_26_27_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_26_27_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_26_27_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_26_27_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_26_27_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_26_27_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL0_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL0_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL0_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL0_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL0_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL0_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL0_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL0_RW]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL0_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL0_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL0_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_RW]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL0_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL0_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL0_RW]


//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPCFSI_OPB_SW0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_TPCFSI_OPB_SW0_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_TPCFSI_OPB_SW0_FENCE_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL0_TPCFSI_OPB_SW0_FENCE_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_TPCFSI_OPB_SW0_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPCFSI_OPB_SW0_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPCFSI_OPB_SW0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_TPCFSI_OPB_SW0_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_TPCFSI_OPB_SW0_FENCE_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL0_TPCFSI_OPB_SW0_FENCE_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_TPCFSI_OPB_SW0_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPCFSI_OPB_SW0_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPCFSI_OPB_SW0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_TPCFSI_OPB_SW0_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_TPCFSI_OPB_SW0_FENCE_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL0_TPCFSI_OPB_SW0_FENCE_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_TPCFSI_OPB_SW0_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPCFSI_OPB_SW0_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_6_7_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_6_7_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_6_7_SPARE,
           FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_6_7_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_6_7_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_6_7_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_6_7_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_6_7_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_6_7_SPARE,
           FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_6_7_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_6_7_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_6_7_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_6_7_SPARE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_6_7_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_6_7_SPARE,
           FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_6_7_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_6_7_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_6_7_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_CMD]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_CMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_CMD,
           FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_CMD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_CMD]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_CMD]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_CMD,
           FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_CMD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_CMD]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_CMD]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_CMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_CMD,
           FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_CMD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_CMD]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC]

//>> PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI]

//>> PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI]

//>> PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_RW]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_RW]

//>> PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_RW]


//>> SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_SR_SCRATCH_REGISTER_4]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_SR_SCRATCH_REGISTER_4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_SR_SCRATCH_REGISTER_4,
           FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_SR_SCRATCH_REGISTER_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_SR_SCRATCH_REGISTER_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_SR_SCRATCH_REGISTER_4]

//>> SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_SR_SCRATCH_REGISTER_4]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_SR_SCRATCH_REGISTER_4(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_SR_SCRATCH_REGISTER_4,
           FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_SR_SCRATCH_REGISTER_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_SR_SCRATCH_REGISTER_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_SR_SCRATCH_REGISTER_4]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_SR_SCRATCH_REGISTER_4]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_SR_SCRATCH_REGISTER_4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_SR_SCRATCH_REGISTER_4,
           FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_SR_SCRATCH_REGISTER_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_SR_SCRATCH_REGISTER_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_SR_SCRATCH_REGISTER_4]

//>> PREP_[FSXCOMP_FSXLOG_SNS1LTH_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SNS1LTH_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SNS1LTH_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SNS1LTH_FSI]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SNS1LTH_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SNS1LTH_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SNS1LTH_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_FSI]

//>> PUT_[FSXCOMP_FSXLOG_SNS1LTH_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SNS1LTH_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SNS1LTH_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SNS1LTH_FSI]

//>> PREP_[FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_SNS1LTH_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SNS1LTH_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SNS1LTH_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SNS1LTH_RO]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SNS1LTH_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SNS1LTH_RO;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SNS1LTH_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_RO]

//>> PUT_[FSXCOMP_FSXLOG_SNS1LTH_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SNS1LTH_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SNS1LTH_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SNS1LTH_RO]


//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_SWITCHED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SWITCHED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHED]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_SWITCHED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SWITCHED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHED]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_SWITCHED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SWITCHED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHED]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHED]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_SWITCHED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SWITCHED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHED]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHED]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_SWITCHED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SWITCHED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHED]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHED]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_SWITCHED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SWITCHED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHED]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31]

//>> SET_[FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31]

//>> CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31]

//>> GET_[FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31]
static inline bool GET_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SNS1LTH_FSI, FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31]

//>> PREP_[REC_ERR_REG3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REC_ERR_REG3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REC_ERR_REG3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REC_ERR_REG3]

//>> GET_[REC_ERR_REG3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REC_ERR_REG3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REC_ERR_REG3;
#endif
    return fapi2::getScom(i_target, REC_ERR_REG3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REC_ERR_REG3]

//>> PUT_[REC_ERR_REG3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REC_ERR_REG3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return fapi2::putScom(i_target, REC_ERR_REG3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REC_ERR_REG3]


//>> SET_[REC_ERR_REG3_48_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_48_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_48_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_48_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_48_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_48_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_48_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_48_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_48_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_48_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_48_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_48_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.setBit<REC_ERR_REG3_48_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG3_48_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_48_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG3_48_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG3_48_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.clearBit<REC_ERR_REG3_48_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG3_48_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG3_48_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_48_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_48_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_48_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_48_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_48_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_48_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG3_48_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.getBit<REC_ERR_REG3_48_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG3_48_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_48_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_48_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_48_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_48_ERROR_CODE,
           REC_ERR_REG3_48_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_48_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_48_ERROR_CODE]

//>> SET_[REC_ERR_REG3_48_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_48_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_48_ERROR_CODE,
           REC_ERR_REG3_48_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_48_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_48_ERROR_CODE]

//>> GET_[REC_ERR_REG3_48_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_48_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_48_ERROR_CODE,
           REC_ERR_REG3_48_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_48_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_48_ERROR_CODE]

//>> SET_[REC_ERR_REG3_49_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_49_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_49_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_49_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_49_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_49_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_49_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_49_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_49_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_49_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_49_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_49_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.setBit<REC_ERR_REG3_49_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG3_49_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_49_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG3_49_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG3_49_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.clearBit<REC_ERR_REG3_49_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG3_49_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG3_49_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_49_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_49_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_49_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_49_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_49_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_49_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG3_49_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.getBit<REC_ERR_REG3_49_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG3_49_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_49_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_49_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_49_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_49_ERROR_CODE,
           REC_ERR_REG3_49_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_49_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_49_ERROR_CODE]

//>> SET_[REC_ERR_REG3_49_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_49_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_49_ERROR_CODE,
           REC_ERR_REG3_49_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_49_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_49_ERROR_CODE]

//>> GET_[REC_ERR_REG3_49_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_49_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_49_ERROR_CODE,
           REC_ERR_REG3_49_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_49_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_49_ERROR_CODE]

//>> SET_[REC_ERR_REG3_50_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_50_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_50_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_50_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_50_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_50_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_50_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_50_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_50_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_50_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_50_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_50_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.setBit<REC_ERR_REG3_50_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG3_50_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_50_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG3_50_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG3_50_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.clearBit<REC_ERR_REG3_50_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG3_50_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG3_50_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_50_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_50_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_50_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_50_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_50_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_50_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG3_50_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.getBit<REC_ERR_REG3_50_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG3_50_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_50_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_50_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_50_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_50_ERROR_CODE,
           REC_ERR_REG3_50_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_50_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_50_ERROR_CODE]

//>> SET_[REC_ERR_REG3_50_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_50_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_50_ERROR_CODE,
           REC_ERR_REG3_50_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_50_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_50_ERROR_CODE]

//>> GET_[REC_ERR_REG3_50_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_50_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_50_ERROR_CODE,
           REC_ERR_REG3_50_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_50_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_50_ERROR_CODE]

//>> SET_[REC_ERR_REG3_51_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_51_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_51_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_51_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_51_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_51_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_51_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_51_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_51_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_51_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_51_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_51_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.setBit<REC_ERR_REG3_51_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG3_51_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_51_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG3_51_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG3_51_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.clearBit<REC_ERR_REG3_51_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG3_51_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG3_51_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_51_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_51_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_51_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_51_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_51_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_51_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG3_51_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.getBit<REC_ERR_REG3_51_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG3_51_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_51_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_51_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_51_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_51_ERROR_CODE,
           REC_ERR_REG3_51_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_51_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_51_ERROR_CODE]

//>> SET_[REC_ERR_REG3_51_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_51_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_51_ERROR_CODE,
           REC_ERR_REG3_51_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_51_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_51_ERROR_CODE]

//>> GET_[REC_ERR_REG3_51_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_51_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_51_ERROR_CODE,
           REC_ERR_REG3_51_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_51_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_51_ERROR_CODE]

//>> SET_[REC_ERR_REG3_52_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_52_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_52_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_52_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_52_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_52_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_52_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_52_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_52_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_52_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_52_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_52_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.setBit<REC_ERR_REG3_52_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG3_52_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_52_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG3_52_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG3_52_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.clearBit<REC_ERR_REG3_52_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG3_52_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG3_52_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_52_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_52_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_52_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_52_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_52_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_52_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG3_52_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.getBit<REC_ERR_REG3_52_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG3_52_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_52_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_52_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_52_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_52_ERROR_CODE,
           REC_ERR_REG3_52_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_52_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_52_ERROR_CODE]

//>> SET_[REC_ERR_REG3_52_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_52_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_52_ERROR_CODE,
           REC_ERR_REG3_52_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_52_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_52_ERROR_CODE]

//>> GET_[REC_ERR_REG3_52_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_52_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_52_ERROR_CODE,
           REC_ERR_REG3_52_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_52_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_52_ERROR_CODE]

//>> SET_[REC_ERR_REG3_53_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_53_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_53_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_53_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_53_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_53_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_53_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_53_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_53_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_53_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_53_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_53_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.setBit<REC_ERR_REG3_53_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG3_53_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_53_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG3_53_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG3_53_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.clearBit<REC_ERR_REG3_53_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG3_53_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG3_53_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_53_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_53_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_53_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_53_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_53_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_53_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG3_53_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.getBit<REC_ERR_REG3_53_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG3_53_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_53_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_53_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_53_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_53_ERROR_CODE,
           REC_ERR_REG3_53_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_53_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_53_ERROR_CODE]

//>> SET_[REC_ERR_REG3_53_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_53_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_53_ERROR_CODE,
           REC_ERR_REG3_53_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_53_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_53_ERROR_CODE]

//>> GET_[REC_ERR_REG3_53_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_53_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_53_ERROR_CODE,
           REC_ERR_REG3_53_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_53_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_53_ERROR_CODE]

//>> SET_[REC_ERR_REG3_54_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_54_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_54_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_54_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_54_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_54_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_54_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_54_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_54_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_54_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_54_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_54_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.setBit<REC_ERR_REG3_54_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG3_54_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_54_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG3_54_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG3_54_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.clearBit<REC_ERR_REG3_54_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG3_54_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG3_54_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_54_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_54_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_54_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_54_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_54_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_54_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG3_54_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.getBit<REC_ERR_REG3_54_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG3_54_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_54_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_54_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_54_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_54_ERROR_CODE,
           REC_ERR_REG3_54_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_54_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_54_ERROR_CODE]

//>> SET_[REC_ERR_REG3_54_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_54_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_54_ERROR_CODE,
           REC_ERR_REG3_54_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_54_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_54_ERROR_CODE]

//>> GET_[REC_ERR_REG3_54_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_54_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_54_ERROR_CODE,
           REC_ERR_REG3_54_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_54_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_54_ERROR_CODE]

//>> SET_[REC_ERR_REG3_55_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_55_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_55_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_55_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_55_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_55_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_55_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_55_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_55_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_55_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_55_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_55_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.setBit<REC_ERR_REG3_55_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG3_55_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_55_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG3_55_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG3_55_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.clearBit<REC_ERR_REG3_55_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG3_55_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG3_55_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_55_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_55_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_55_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_55_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_55_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_55_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG3_55_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.getBit<REC_ERR_REG3_55_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG3_55_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_55_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_55_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_55_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_55_ERROR_CODE,
           REC_ERR_REG3_55_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_55_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_55_ERROR_CODE]

//>> SET_[REC_ERR_REG3_55_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_55_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_55_ERROR_CODE,
           REC_ERR_REG3_55_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_55_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_55_ERROR_CODE]

//>> GET_[REC_ERR_REG3_55_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_55_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_55_ERROR_CODE,
           REC_ERR_REG3_55_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_55_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_55_ERROR_CODE]

//>> SET_[REC_ERR_REG3_56_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_56_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_56_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_56_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_56_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_56_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_56_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_56_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_56_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_56_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_56_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_56_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.setBit<REC_ERR_REG3_56_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG3_56_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_56_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG3_56_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG3_56_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.clearBit<REC_ERR_REG3_56_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG3_56_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG3_56_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_56_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_56_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_56_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_56_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_56_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_56_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG3_56_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.getBit<REC_ERR_REG3_56_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG3_56_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_56_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_56_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_56_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_56_ERROR_CODE,
           REC_ERR_REG3_56_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_56_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_56_ERROR_CODE]

//>> SET_[REC_ERR_REG3_56_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_56_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_56_ERROR_CODE,
           REC_ERR_REG3_56_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_56_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_56_ERROR_CODE]

//>> GET_[REC_ERR_REG3_56_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_56_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_56_ERROR_CODE,
           REC_ERR_REG3_56_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_56_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_56_ERROR_CODE]

//>> SET_[REC_ERR_REG3_57_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_57_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_57_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_57_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_57_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_57_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_57_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_57_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_57_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_57_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_57_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_57_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.setBit<REC_ERR_REG3_57_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG3_57_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_57_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG3_57_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG3_57_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.clearBit<REC_ERR_REG3_57_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG3_57_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG3_57_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_57_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_57_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_57_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_57_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_57_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_57_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG3_57_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.getBit<REC_ERR_REG3_57_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG3_57_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_57_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_57_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_57_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_57_ERROR_CODE,
           REC_ERR_REG3_57_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_57_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_57_ERROR_CODE]

//>> SET_[REC_ERR_REG3_57_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_57_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_57_ERROR_CODE,
           REC_ERR_REG3_57_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_57_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_57_ERROR_CODE]

//>> GET_[REC_ERR_REG3_57_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_57_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_57_ERROR_CODE,
           REC_ERR_REG3_57_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_57_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_57_ERROR_CODE]

//>> SET_[REC_ERR_REG3_58_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_58_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_58_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_58_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_58_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_58_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_58_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_58_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_58_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_58_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_58_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_58_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.setBit<REC_ERR_REG3_58_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG3_58_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_58_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG3_58_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG3_58_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.clearBit<REC_ERR_REG3_58_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG3_58_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG3_58_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_58_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_58_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_58_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_58_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_58_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_58_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG3_58_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.getBit<REC_ERR_REG3_58_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG3_58_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_58_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_58_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_58_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_58_ERROR_CODE,
           REC_ERR_REG3_58_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_58_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_58_ERROR_CODE]

//>> SET_[REC_ERR_REG3_58_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_58_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_58_ERROR_CODE,
           REC_ERR_REG3_58_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_58_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_58_ERROR_CODE]

//>> GET_[REC_ERR_REG3_58_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_58_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_58_ERROR_CODE,
           REC_ERR_REG3_58_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_58_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_58_ERROR_CODE]

//>> SET_[REC_ERR_REG3_59_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_59_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_59_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_59_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_59_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_59_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_59_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_59_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_59_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_59_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_59_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_59_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.setBit<REC_ERR_REG3_59_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG3_59_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_59_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG3_59_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG3_59_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.clearBit<REC_ERR_REG3_59_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG3_59_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG3_59_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_59_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_59_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_59_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_59_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_59_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_59_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG3_59_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.getBit<REC_ERR_REG3_59_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG3_59_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_59_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_59_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_59_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_59_ERROR_CODE,
           REC_ERR_REG3_59_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_59_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_59_ERROR_CODE]

//>> SET_[REC_ERR_REG3_59_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_59_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_59_ERROR_CODE,
           REC_ERR_REG3_59_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_59_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_59_ERROR_CODE]

//>> GET_[REC_ERR_REG3_59_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_59_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_59_ERROR_CODE,
           REC_ERR_REG3_59_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_59_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_59_ERROR_CODE]

//>> SET_[REC_ERR_REG3_60_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_60_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_60_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_60_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_60_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_60_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_60_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_60_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_60_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_60_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_60_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_60_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.setBit<REC_ERR_REG3_60_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG3_60_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_60_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG3_60_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG3_60_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.clearBit<REC_ERR_REG3_60_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG3_60_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG3_60_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_60_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_60_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_60_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_60_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_60_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_60_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG3_60_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.getBit<REC_ERR_REG3_60_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG3_60_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_60_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_60_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_60_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_60_ERROR_CODE,
           REC_ERR_REG3_60_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_60_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_60_ERROR_CODE]

//>> SET_[REC_ERR_REG3_60_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_60_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_60_ERROR_CODE,
           REC_ERR_REG3_60_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_60_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_60_ERROR_CODE]

//>> GET_[REC_ERR_REG3_60_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_60_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_60_ERROR_CODE,
           REC_ERR_REG3_60_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_60_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_60_ERROR_CODE]

//>> SET_[REC_ERR_REG3_61_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_61_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_61_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_61_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_61_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_61_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_61_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_61_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_61_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_61_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_61_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_61_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.setBit<REC_ERR_REG3_61_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG3_61_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_61_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG3_61_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG3_61_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.clearBit<REC_ERR_REG3_61_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG3_61_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG3_61_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_61_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_61_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_61_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_61_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_61_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_61_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG3_61_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.getBit<REC_ERR_REG3_61_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG3_61_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_61_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_61_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_61_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_61_ERROR_CODE,
           REC_ERR_REG3_61_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_61_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_61_ERROR_CODE]

//>> SET_[REC_ERR_REG3_61_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_61_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_61_ERROR_CODE,
           REC_ERR_REG3_61_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_61_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_61_ERROR_CODE]

//>> GET_[REC_ERR_REG3_61_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_61_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_61_ERROR_CODE,
           REC_ERR_REG3_61_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_61_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_61_ERROR_CODE]

//>> SET_[REC_ERR_REG3_62_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_62_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_62_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_62_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_62_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_62_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_62_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_62_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_62_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_62_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_62_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_62_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.setBit<REC_ERR_REG3_62_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG3_62_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_62_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG3_62_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG3_62_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.clearBit<REC_ERR_REG3_62_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG3_62_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG3_62_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_62_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_62_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_62_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_62_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_62_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_62_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG3_62_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.getBit<REC_ERR_REG3_62_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG3_62_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_62_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_62_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_62_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_62_ERROR_CODE,
           REC_ERR_REG3_62_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_62_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_62_ERROR_CODE]

//>> SET_[REC_ERR_REG3_62_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_62_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_62_ERROR_CODE,
           REC_ERR_REG3_62_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_62_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_62_ERROR_CODE]

//>> GET_[REC_ERR_REG3_62_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_62_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_62_ERROR_CODE,
           REC_ERR_REG3_62_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_62_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_62_ERROR_CODE]

//>> SET_[REC_ERR_REG3_63_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_63_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_63_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_63_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_63_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_63_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_63_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_63_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_63_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_63_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_63_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_63_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.setBit<REC_ERR_REG3_63_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG3_63_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_63_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG3_63_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG3_63_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.clearBit<REC_ERR_REG3_63_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG3_63_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG3_63_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_63_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_63_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_63_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_63_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_63_RESPONSE_BIT]

//>> GET_[REC_ERR_REG3_63_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG3_63_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.getBit<REC_ERR_REG3_63_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG3_63_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_63_RESPONSE_BIT]

//>> SET_[REC_ERR_REG3_63_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_63_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_63_ERROR_CODE,
           REC_ERR_REG3_63_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG3_63_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_63_ERROR_CODE]

//>> SET_[REC_ERR_REG3_63_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG3_63_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_REG3_63_ERROR_CODE,
           REC_ERR_REG3_63_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG3_63_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG3_63_ERROR_CODE]

//>> GET_[REC_ERR_REG3_63_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG3_63_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG3));
#endif
    return i_data.extractToRight<REC_ERR_REG3_63_ERROR_CODE,
           REC_ERR_REG3_63_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG3_63_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG3_63_ERROR_CODE]

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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_ANY_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_ANY_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_ANY_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_ANY_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_ANY_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_ANY_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_RESERVED1S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_RESERVED1S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_RESERVED1S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_RESERVED1S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_RESERVED1S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_RESERVED1S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_RESERVED2S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_RESERVED2S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_RESERVED2S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_RESERVED2S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_RESERVED2S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_RESERVED2S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_RESERVED3S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_RESERVED3S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_RESERVED3S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_RESERVED3S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_RESERVED3S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_RESERVED3S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN35]

//>> PREP_[TOD_LOAD_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_LOAD_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_LOAD_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_LOAD_REG]

//>> GET_[TOD_LOAD_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_LOAD_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_LOAD_REG;
#endif
    return fapi2::getScom(i_target, TOD_LOAD_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_LOAD_REG]

//>> PUT_[TOD_LOAD_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_LOAD_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_LOAD_REG));
#endif
    return fapi2::putScom(i_target, TOD_LOAD_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_LOAD_REG]


//>> SET_[TOD_LOAD_REG_LOAD_TOD_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TOD_LOAD_REG_LOAD_TOD_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_LOAD_REG));
#endif
    return o_data.insertFromRight<TOD_LOAD_REG_LOAD_TOD_VALUE,
           TOD_LOAD_REG_LOAD_TOD_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_LOAD_REG_LOAD_TOD_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_LOAD_REG_LOAD_TOD_VALUE]

//>> SET_[TOD_LOAD_REG_LOAD_TOD_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TOD_LOAD_REG_LOAD_TOD_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_LOAD_REG));
#endif
    return o_data.insertFromRight<TOD_LOAD_REG_LOAD_TOD_VALUE,
           TOD_LOAD_REG_LOAD_TOD_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_LOAD_REG_LOAD_TOD_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_LOAD_REG_LOAD_TOD_VALUE]

//>> GET_[TOD_LOAD_REG_LOAD_TOD_VALUE]
static inline fapi2::buffer<uint64_t>& GET_TOD_LOAD_REG_LOAD_TOD_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_LOAD_REG));
#endif
    return i_data.extractToRight<TOD_LOAD_REG_LOAD_TOD_VALUE,
           TOD_LOAD_REG_LOAD_TOD_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_LOAD_REG_LOAD_TOD_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_LOAD_REG_LOAD_TOD_VALUE]

//>> SET_[TOD_LOAD_REG_WOF]
static inline fapi2::buffer<uint64_t>& SET_TOD_LOAD_REG_WOF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_LOAD_REG));
#endif
    return o_data.insertFromRight<TOD_LOAD_REG_WOF,
           TOD_LOAD_REG_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_LOAD_REG_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_LOAD_REG_WOF]

//>> SET_[TOD_LOAD_REG_WOF]
static inline fapi2::buffer<uint64_t>& SET_TOD_LOAD_REG_WOF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_LOAD_REG));
#endif
    return o_data.insertFromRight<TOD_LOAD_REG_WOF,
           TOD_LOAD_REG_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_LOAD_REG_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_LOAD_REG_WOF]

//>> GET_[TOD_LOAD_REG_WOF]
static inline fapi2::buffer<uint64_t>& GET_TOD_LOAD_REG_WOF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_LOAD_REG));
#endif
    return i_data.extractToRight<TOD_LOAD_REG_WOF,
           TOD_LOAD_REG_WOF_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_LOAD_REG_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_LOAD_REG_WOF]

//>> PREP_[TOD_PRI_PORT_1_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_PRI_PORT_1_CTRL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_PRI_PORT_1_CTRL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_PRI_PORT_1_CTRL_REG]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_PRI_PORT_1_CTRL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_PRI_PORT_1_CTRL_REG;
#endif
    return fapi2::getScom(i_target, TOD_PRI_PORT_1_CTRL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG]

//>> PUT_[TOD_PRI_PORT_1_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_PRI_PORT_1_CTRL_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return fapi2::putScom(i_target, TOD_PRI_PORT_1_CTRL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_PRI_PORT_1_CTRL_REG]


//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_PORT_1_RX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_PORT_1_RX_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_PORT_1_RX_SELECT,
           TOD_PRI_PORT_1_CTRL_REG_PRI_PORT_1_RX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_PORT_1_RX_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_PORT_1_RX_SELECT]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_PORT_1_RX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_PORT_1_RX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_PORT_1_RX_SELECT,
           TOD_PRI_PORT_1_CTRL_REG_PRI_PORT_1_RX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_PORT_1_RX_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_PORT_1_RX_SELECT]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_PORT_1_RX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_1_CTRL_REG_PRI_PORT_1_RX_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_1_CTRL_REG_PRI_PORT_1_RX_SELECT,
           TOD_PRI_PORT_1_CTRL_REG_PRI_PORT_1_RX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_PORT_1_RX_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_PORT_1_RX_SELECT]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.setBit<TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03]

//>> CLEAR_[TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03]
static inline bool GET_TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.getBit<TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_SELECT,
           TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_SELECT]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_SELECT,
           TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_SELECT]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_SELECT,
           TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_SELECT]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_SELECT,
           TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_SELECT]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_SELECT,
           TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_SELECT]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_SELECT,
           TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_SELECT]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_SELECT,
           TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_SELECT]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_SELECT,
           TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_SELECT]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_SELECT,
           TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_SELECT]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_SELECT,
           TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_SELECT]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_SELECT,
           TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_SELECT]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_SELECT,
           TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_SELECT]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_SELECT,
           TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_SELECT]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_SELECT,
           TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_SELECT]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_SELECT,
           TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_SELECT]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_SELECT,
           TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_SELECT]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_SELECT,
           TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_SELECT]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_SELECT,
           TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_SELECT]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_SELECT,
           TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_SELECT]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_SELECT,
           TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_SELECT]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_SELECT,
           TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_SELECT]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_SELECT,
           TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_SELECT]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_SELECT,
           TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_SELECT]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_SELECT,
           TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_SELECT]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.setBit<TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE]

//>> CLEAR_[TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE]
static inline bool GET_TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.getBit<TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.setBit<TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE]

//>> CLEAR_[TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE]
static inline bool GET_TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.getBit<TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.setBit<TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE]

//>> CLEAR_[TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE]
static inline bool GET_TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.getBit<TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.setBit<TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE]

//>> CLEAR_[TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE]
static inline bool GET_TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.getBit<TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.setBit<TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE]

//>> CLEAR_[TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE]
static inline bool GET_TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.getBit<TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.setBit<TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE]

//>> CLEAR_[TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE]
static inline bool GET_TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.getBit<TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.setBit<TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE]

//>> CLEAR_[TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE]
static inline bool GET_TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.getBit<TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.setBit<TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE]

//>> CLEAR_[TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE]
static inline bool GET_TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.getBit<TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_28_31]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_28_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_28_31,
           TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_28_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_28_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_28_31]

//>> SET_[TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_28_31]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_28_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_28_31,
           TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_28_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_28_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_28_31]

//>> GET_[TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_28_31]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_28_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_28_31,
           TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_28_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_28_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_28_31]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
