/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pauc/reg00002.H $         */
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

#ifndef __PAUC_REG00002_H_
#define __PAUC_REG00002_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace pauc
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_ABIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_ABIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_ABIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_ABIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_ABIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_ABIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_ABIST_DONE_DC]

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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_RESERVED_2I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_RESERVED_2I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_RESERVED_2I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_RESERVED_2I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_RESERVED_2I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_RESERVED_2I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_RESERVED_3I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_RESERVED_3I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_RESERVED_3I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_RESERVED_3I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_RESERVED_3I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_RESERVED_3I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_TC_DIAG_PORT0_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_TC_DIAG_PORT0_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_TC_DIAG_PORT0_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_TC_DIAG_PORT0_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_TC_DIAG_PORT0_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_TC_DIAG_PORT0_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_TC_DIAG_PORT1_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_TC_DIAG_PORT1_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_TC_DIAG_PORT1_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_TC_DIAG_PORT1_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_TC_DIAG_PORT1_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_TC_DIAG_PORT1_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_RESERVED_6I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_RESERVED_6I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_RESERVED_6I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_RESERVED_6I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_RESERVED_6I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_RESERVED_6I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_CC_CTRL_OPCG_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_CC_CTRL_OPCG_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_CC_CTRL_OPCG_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_CC_CTRL_OPCG_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_CC_CTRL_OPCG_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_CC_CTRL_OPCG_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC]

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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_10I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_10I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_10I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_10I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_10I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_10I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_10I]

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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_11I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_11I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_11I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_11I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_11I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_11I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_11I]

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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_12I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_12I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_12I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_12I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_12I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_12I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_12I]

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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_13I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_13I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_13I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_13I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_13I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_13I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_13I]

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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_14I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_14I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_14I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_14I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_14I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_14I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_14I]

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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_15I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_15I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_15I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_15I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_15I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_15I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_15I]

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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_16I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_16I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_16I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_16I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_16I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_16I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_16I]

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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_17I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_17I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_17I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_17I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_17I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_17I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_17I]

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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_18I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_18I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_18I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_18I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_18I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_18I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_18I]

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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_19I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_19I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_19I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_19I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_19I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_19I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_19I]

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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_20I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_20I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_20I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_20I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_20I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_20I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_20I]

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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_21I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_21I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_21I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_21I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_21I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_21I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_22I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_22I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_22I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_22I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_22I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_22I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_23I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_23I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_23I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_23I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_23I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_23I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_23I]

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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_GLOBAL_FEH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_GLOBAL_FEH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_GLOBAL_FEH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_GLOBAL_FEH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_GLOBAL_FEH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_GLOBAL_FEH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_25I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_25I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_25I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_25I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_25I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_25I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_26I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_26I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_26I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_26I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_26I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_26I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_27I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_27I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_27I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_27I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_27I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_27I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_28I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_28I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_28I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_28I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_28I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_28I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_29I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_29I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_29I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_29I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_29I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_29I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_30I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_30I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_30I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_30I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_30I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_30I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_31I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_31I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_31I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_31I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_31I chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_STAT0_FREE_USAGE_31I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_STAT0_FREE_USAGE_31I]

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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_ANY_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_ANY_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_ANY_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_ANY_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_ANY_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_ANY_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_RESERVED1S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_RESERVED1S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_RESERVED1S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_RESERVED1S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_RESERVED1S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_RESERVED1S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_RESERVED2S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_RESERVED2S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_RESERVED2S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_RESERVED2S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_RESERVED2S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_RESERVED2S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_RESERVED3S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_RESERVED3S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_RESERVED3S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_RESERVED3S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_RESERVED3S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_RESERVED3S chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access SPATTN_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SPATTN_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access SPATTN_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access SPATTN_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SPATTN_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access SPATTN_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_IN35]

//>> PREP_[PHY_SCOM_MAC_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PHY_SCOM_MAC_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PHY_SCOM_MAC_FIR_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PHY_SCOM_MAC_FIR_REG_RW]

//>> GET_[PHY_SCOM_MAC_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PHY_SCOM_MAC_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PHY_SCOM_MAC_FIR_REG_RW;
#endif
    return fapi2::getScom(i_target, PHY_SCOM_MAC_FIR_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_RW]

//>> PUT_[PHY_SCOM_MAC_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PHY_SCOM_MAC_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PHY_SCOM_MAC_FIR_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PHY_SCOM_MAC_FIR_REG_RW]

//>> PREP_[PHY_SCOM_MAC_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PHY_SCOM_MAC_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PHY_SCOM_MAC_FIR_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PHY_SCOM_MAC_FIR_REG_WO_AND]

//>> GET_[PHY_SCOM_MAC_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PHY_SCOM_MAC_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PHY_SCOM_MAC_FIR_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, PHY_SCOM_MAC_FIR_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_WO_AND]

//>> PUT_[PHY_SCOM_MAC_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PHY_SCOM_MAC_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PHY_SCOM_MAC_FIR_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PHY_SCOM_MAC_FIR_REG_WO_AND]

//>> PREP_[PHY_SCOM_MAC_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PHY_SCOM_MAC_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PHY_SCOM_MAC_FIR_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PHY_SCOM_MAC_FIR_REG_WO_OR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PHY_SCOM_MAC_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PHY_SCOM_MAC_FIR_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, PHY_SCOM_MAC_FIR_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_WO_OR]

//>> PUT_[PHY_SCOM_MAC_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PHY_SCOM_MAC_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PHY_SCOM_MAC_FIR_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PHY_SCOM_MAC_FIR_REG_WO_OR]


//>> SET_[PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR]

//>> CLEAR_[PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR]
static inline bool GET_PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR]

//>> CLEAR_[PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR]
static inline bool GET_PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR]

//>> CLEAR_[PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR]
static inline bool GET_PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR]

//>> CLEAR_[PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR]
static inline bool GET_PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR]

//>> CLEAR_[PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR]
static inline bool GET_PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR]

//>> CLEAR_[PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR]
static inline bool GET_PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR]

//>> CLEAR_[PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR]
static inline bool GET_PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR]

//>> CLEAR_[PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR]
static inline bool GET_PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR]

//>> CLEAR_[PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR]
static inline bool GET_PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR]

//>> CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR]
static inline fapi2::buffer<uint64_t>& GET_PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR]
static inline bool GET_PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_INT_HWERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR]

//>> CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR]
static inline fapi2::buffer<uint64_t>& GET_PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR]
static inline bool GET_PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_EXT_HWERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT]

//>> CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT]
static inline fapi2::buffer<uint64_t>& GET_PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT]
static inline bool GET_PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG]

//>> CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG]
static inline fapi2::buffer<uint64_t>& GET_PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG]
static inline bool GET_PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_HALT_DEBUG]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_HALTED]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_HALTED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_HALTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_HALTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_HALTED]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_HALTED]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_HALTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_HALTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_HALTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_HALTED]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_HALTED]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_HALTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PHY_SCOM_MAC_FIR_REG_PPE_HALTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_HALTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_HALTED]

//>> CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_HALTED]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_SCOM_MAC_FIR_REG_PPE_HALTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PHY_SCOM_MAC_FIR_REG_PPE_HALTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_HALTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_HALTED]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_HALTED]
static inline fapi2::buffer<uint64_t>& GET_PHY_SCOM_MAC_FIR_REG_PPE_HALTED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PHY_SCOM_MAC_FIR_REG_PPE_HALTED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_HALTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_HALTED]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_HALTED]
static inline bool GET_PHY_SCOM_MAC_FIR_REG_PPE_HALTED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PHY_SCOM_MAC_FIR_REG_PPE_HALTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_HALTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_HALTED]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT]

//>> CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT]
static inline bool GET_PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_WATCHDOG_TIMEOUT]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK]

//>> CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK]
static inline fapi2::buffer<uint64_t>& GET_PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK]
static inline bool GET_PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_MISSED_SCRUB_TICK]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR]

//>> CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR]
static inline bool GET_PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR]

//>> CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR]
static inline bool GET_PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT]

//>> CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT]
static inline fapi2::buffer<uint64_t>& GET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT]
static inline bool GET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_ABORT]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR]

//>> CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR]
static inline bool GET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_FATAL_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING]

//>> CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING]
static inline fapi2::buffer<uint64_t>& GET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING]
static inline bool GET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_WARNING]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR]

//>> CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR]
static inline bool GET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_DFT_ERROR]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN]

//>> CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN]
static inline fapi2::buffer<uint64_t>& GET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN]
static inline bool GET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED]

//>> CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED]
static inline fapi2::buffer<uint64_t>& GET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED]
static inline bool GET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_THREAD_LOCKED]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_6]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_CODE_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_6]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_6]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_CODE_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_6]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_6]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PHY_SCOM_MAC_FIR_REG_PPE_CODE_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_6]

//>> CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_6]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_SCOM_MAC_FIR_REG_PPE_CODE_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PHY_SCOM_MAC_FIR_REG_PPE_CODE_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_6]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_6]
static inline fapi2::buffer<uint64_t>& GET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PHY_SCOM_MAC_FIR_REG_PPE_CODE_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_6]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_6]
static inline bool GET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PHY_SCOM_MAC_FIR_REG_PPE_CODE_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_6]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_7]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_CODE_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_7]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_7]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PHY_SCOM_MAC_FIR_REG_PPE_CODE_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_7]

//>> SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_7]
static inline fapi2::buffer<uint64_t>& SET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PHY_SCOM_MAC_FIR_REG_PPE_CODE_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_7]

//>> CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_7]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_SCOM_MAC_FIR_REG_PPE_CODE_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PHY_SCOM_MAC_FIR_REG_PPE_CODE_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_7]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_7]
static inline fapi2::buffer<uint64_t>& GET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PHY_SCOM_MAC_FIR_REG_PPE_CODE_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_7]

//>> GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_7]
static inline bool GET_PHY_SCOM_MAC_FIR_REG_PPE_CODE_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_SCOM_MAC_FIR_REG_RW, PHY_SCOM_MAC_FIR_REG_WO_AND, PHY_SCOM_MAC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PHY_SCOM_MAC_FIR_REG_PPE_CODE_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_SCOM_MAC_FIR_REG_PPE_CODE_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_SCOM_MAC_FIR_REG_PPE_CODE_7]

//>> PREP_[PB_FP23_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_FP23_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_FP23_CFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_FP23_CFG]

//>> GET_[PB_FP23_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_FP23_CFG(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_FP23_CFG;
#endif
    return fapi2::getScom(i_target, PB_FP23_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_FP23_CFG]

//>> PUT_[PB_FP23_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_FP23_CFG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return fapi2::putScom(i_target, PB_FP23_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_FP23_CFG]


//>> SET_[PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.setBit<PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]

//>> CLEAR_[PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.clearBit<PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]

//>> GET_[PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& GET_PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.extractToRight<PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]

//>> GET_[PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]
static inline bool GET_PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.getBit<PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_FP23_CFG_2_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_2_DISABLE_GATHERING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP23_CFG_2_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_DISABLE_GATHERING]

//>> SET_[PB_FP23_CFG_2_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_DISABLE_GATHERING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_2_DISABLE_GATHERING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP23_CFG_2_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_DISABLE_GATHERING]

//>> SET_[PB_FP23_CFG_2_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_DISABLE_GATHERING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.setBit<PB_FP23_CFG_2_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP23_CFG_2_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_DISABLE_GATHERING]

//>> CLEAR_[PB_FP23_CFG_2_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP23_CFG_2_DISABLE_GATHERING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.clearBit<PB_FP23_CFG_2_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP23_CFG_2_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP23_CFG_2_DISABLE_GATHERING]

//>> GET_[PB_FP23_CFG_2_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& GET_PB_FP23_CFG_2_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.extractToRight<PB_FP23_CFG_2_DISABLE_GATHERING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP23_CFG_2_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_2_DISABLE_GATHERING]

//>> GET_[PB_FP23_CFG_2_DISABLE_GATHERING]
static inline bool GET_PB_FP23_CFG_2_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.getBit<PB_FP23_CFG_2_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP23_CFG_2_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_2_DISABLE_GATHERING]

//>> SET_[PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.setBit<PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION]

//>> CLEAR_[PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.clearBit<PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION]

//>> GET_[PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& GET_PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.extractToRight<PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION]

//>> GET_[PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION]
static inline bool GET_PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.getBit<PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.setBit<PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]

//>> CLEAR_[PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.clearBit<PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]

//>> GET_[PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& GET_PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.extractToRight<PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]

//>> GET_[PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]
static inline bool GET_PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.getBit<PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_FP23_CFG_2_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_LL_CREDIT_FW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_2_LL_CREDIT_FW_LIMIT,
           PB_FP23_CFG_2_LL_CREDIT_FW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP23_CFG_2_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_LL_CREDIT_FW_LIMIT]

//>> SET_[PB_FP23_CFG_2_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_LL_CREDIT_FW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_2_LL_CREDIT_FW_LIMIT,
           PB_FP23_CFG_2_LL_CREDIT_FW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP23_CFG_2_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_LL_CREDIT_FW_LIMIT]

//>> GET_[PB_FP23_CFG_2_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_FP23_CFG_2_LL_CREDIT_FW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.extractToRight<PB_FP23_CFG_2_LL_CREDIT_FW_LIMIT,
           PB_FP23_CFG_2_LL_CREDIT_FW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP23_CFG_2_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_2_LL_CREDIT_FW_LIMIT]

//>> SET_[PB_FP23_CFG_2_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_LL_CREDIT_HW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_2_LL_CREDIT_HW_LIMIT,
           PB_FP23_CFG_2_LL_CREDIT_HW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP23_CFG_2_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_LL_CREDIT_HW_LIMIT]

//>> SET_[PB_FP23_CFG_2_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_LL_CREDIT_HW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_2_LL_CREDIT_HW_LIMIT,
           PB_FP23_CFG_2_LL_CREDIT_HW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP23_CFG_2_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_LL_CREDIT_HW_LIMIT]

//>> GET_[PB_FP23_CFG_2_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_FP23_CFG_2_LL_CREDIT_HW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.extractToRight<PB_FP23_CFG_2_LL_CREDIT_HW_LIMIT,
           PB_FP23_CFG_2_LL_CREDIT_HW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP23_CFG_2_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_2_LL_CREDIT_HW_LIMIT]

//>> SET_[PB_FP23_CFG_2_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_LL_CREDIT_QW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_2_LL_CREDIT_QW_LIMIT,
           PB_FP23_CFG_2_LL_CREDIT_QW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP23_CFG_2_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_LL_CREDIT_QW_LIMIT]

//>> SET_[PB_FP23_CFG_2_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_LL_CREDIT_QW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_2_LL_CREDIT_QW_LIMIT,
           PB_FP23_CFG_2_LL_CREDIT_QW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP23_CFG_2_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_LL_CREDIT_QW_LIMIT]

//>> GET_[PB_FP23_CFG_2_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_FP23_CFG_2_LL_CREDIT_QW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.extractToRight<PB_FP23_CFG_2_LL_CREDIT_QW_LIMIT,
           PB_FP23_CFG_2_LL_CREDIT_QW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP23_CFG_2_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_2_LL_CREDIT_QW_LIMIT]

//>> SET_[PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.setBit<PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]

//>> CLEAR_[PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.clearBit<PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]

//>> GET_[PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& GET_PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.extractToRight<PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]

//>> GET_[PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]
static inline bool GET_PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.getBit<PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_FP23_CFG_23_CMD_EXP_TIME]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_23_CMD_EXP_TIME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_23_CMD_EXP_TIME,
           PB_FP23_CFG_23_CMD_EXP_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP23_CFG_23_CMD_EXP_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_23_CMD_EXP_TIME]

//>> SET_[PB_FP23_CFG_23_CMD_EXP_TIME]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_23_CMD_EXP_TIME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_23_CMD_EXP_TIME,
           PB_FP23_CFG_23_CMD_EXP_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP23_CFG_23_CMD_EXP_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_23_CMD_EXP_TIME]

//>> GET_[PB_FP23_CFG_23_CMD_EXP_TIME]
static inline fapi2::buffer<uint64_t>& GET_PB_FP23_CFG_23_CMD_EXP_TIME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.extractToRight<PB_FP23_CFG_23_CMD_EXP_TIME,
           PB_FP23_CFG_23_CMD_EXP_TIME_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP23_CFG_23_CMD_EXP_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_23_CMD_EXP_TIME]

//>> SET_[PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.setBit<PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]

//>> CLEAR_[PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.clearBit<PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]

//>> GET_[PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.extractToRight<PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]

//>> GET_[PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]
static inline bool GET_PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.getBit<PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.setBit<PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]

//>> CLEAR_[PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.clearBit<PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]

//>> GET_[PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& GET_PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.extractToRight<PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]

//>> GET_[PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]
static inline bool GET_PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.getBit<PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_FP23_CFG_2_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_PRS_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_2_PRS_SPARE,
           PB_FP23_CFG_2_PRS_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP23_CFG_2_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_PRS_SPARE]

//>> SET_[PB_FP23_CFG_2_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_2_PRS_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_2_PRS_SPARE,
           PB_FP23_CFG_2_PRS_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP23_CFG_2_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_2_PRS_SPARE]

//>> GET_[PB_FP23_CFG_2_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_FP23_CFG_2_PRS_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.extractToRight<PB_FP23_CFG_2_PRS_SPARE,
           PB_FP23_CFG_2_PRS_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP23_CFG_2_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_2_PRS_SPARE]

//>> SET_[PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.setBit<PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]

//>> CLEAR_[PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.clearBit<PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]

//>> GET_[PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& GET_PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.extractToRight<PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]

//>> GET_[PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]
static inline bool GET_PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.getBit<PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_FP23_CFG_3_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_3_DISABLE_GATHERING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP23_CFG_3_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_DISABLE_GATHERING]

//>> SET_[PB_FP23_CFG_3_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_DISABLE_GATHERING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_3_DISABLE_GATHERING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP23_CFG_3_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_DISABLE_GATHERING]

//>> SET_[PB_FP23_CFG_3_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_DISABLE_GATHERING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.setBit<PB_FP23_CFG_3_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP23_CFG_3_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_DISABLE_GATHERING]

//>> CLEAR_[PB_FP23_CFG_3_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP23_CFG_3_DISABLE_GATHERING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.clearBit<PB_FP23_CFG_3_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP23_CFG_3_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP23_CFG_3_DISABLE_GATHERING]

//>> GET_[PB_FP23_CFG_3_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& GET_PB_FP23_CFG_3_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.extractToRight<PB_FP23_CFG_3_DISABLE_GATHERING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP23_CFG_3_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_3_DISABLE_GATHERING]

//>> GET_[PB_FP23_CFG_3_DISABLE_GATHERING]
static inline bool GET_PB_FP23_CFG_3_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.getBit<PB_FP23_CFG_3_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP23_CFG_3_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_3_DISABLE_GATHERING]

//>> SET_[PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.setBit<PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION]

//>> CLEAR_[PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.clearBit<PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION]

//>> GET_[PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& GET_PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.extractToRight<PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION]

//>> GET_[PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION]
static inline bool GET_PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.getBit<PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.setBit<PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]

//>> CLEAR_[PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.clearBit<PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]

//>> GET_[PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& GET_PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.extractToRight<PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]

//>> GET_[PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]
static inline bool GET_PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.getBit<PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_FP23_CFG_3_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_LL_CREDIT_FW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_3_LL_CREDIT_FW_LIMIT,
           PB_FP23_CFG_3_LL_CREDIT_FW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP23_CFG_3_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_LL_CREDIT_FW_LIMIT]

//>> SET_[PB_FP23_CFG_3_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_LL_CREDIT_FW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_3_LL_CREDIT_FW_LIMIT,
           PB_FP23_CFG_3_LL_CREDIT_FW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP23_CFG_3_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_LL_CREDIT_FW_LIMIT]

//>> GET_[PB_FP23_CFG_3_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_FP23_CFG_3_LL_CREDIT_FW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.extractToRight<PB_FP23_CFG_3_LL_CREDIT_FW_LIMIT,
           PB_FP23_CFG_3_LL_CREDIT_FW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP23_CFG_3_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_3_LL_CREDIT_FW_LIMIT]

//>> SET_[PB_FP23_CFG_3_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_LL_CREDIT_HW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_3_LL_CREDIT_HW_LIMIT,
           PB_FP23_CFG_3_LL_CREDIT_HW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP23_CFG_3_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_LL_CREDIT_HW_LIMIT]

//>> SET_[PB_FP23_CFG_3_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_LL_CREDIT_HW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_3_LL_CREDIT_HW_LIMIT,
           PB_FP23_CFG_3_LL_CREDIT_HW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP23_CFG_3_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_LL_CREDIT_HW_LIMIT]

//>> GET_[PB_FP23_CFG_3_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_FP23_CFG_3_LL_CREDIT_HW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.extractToRight<PB_FP23_CFG_3_LL_CREDIT_HW_LIMIT,
           PB_FP23_CFG_3_LL_CREDIT_HW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP23_CFG_3_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_3_LL_CREDIT_HW_LIMIT]

//>> SET_[PB_FP23_CFG_3_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_LL_CREDIT_QW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_3_LL_CREDIT_QW_LIMIT,
           PB_FP23_CFG_3_LL_CREDIT_QW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP23_CFG_3_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_LL_CREDIT_QW_LIMIT]

//>> SET_[PB_FP23_CFG_3_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_LL_CREDIT_QW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_3_LL_CREDIT_QW_LIMIT,
           PB_FP23_CFG_3_LL_CREDIT_QW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP23_CFG_3_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_LL_CREDIT_QW_LIMIT]

//>> GET_[PB_FP23_CFG_3_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_FP23_CFG_3_LL_CREDIT_QW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.extractToRight<PB_FP23_CFG_3_LL_CREDIT_QW_LIMIT,
           PB_FP23_CFG_3_LL_CREDIT_QW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP23_CFG_3_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_3_LL_CREDIT_QW_LIMIT]

//>> SET_[PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.setBit<PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]

//>> CLEAR_[PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.clearBit<PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]

//>> GET_[PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& GET_PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.extractToRight<PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]

//>> GET_[PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]
static inline bool GET_PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.getBit<PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_FP23_CFG_3_FMR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_FMR_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_3_FMR_SPARE,
           PB_FP23_CFG_3_FMR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP23_CFG_3_FMR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_FMR_SPARE]

//>> SET_[PB_FP23_CFG_3_FMR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_FMR_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_3_FMR_SPARE,
           PB_FP23_CFG_3_FMR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP23_CFG_3_FMR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_FMR_SPARE]

//>> GET_[PB_FP23_CFG_3_FMR_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_FP23_CFG_3_FMR_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.extractToRight<PB_FP23_CFG_3_FMR_SPARE,
           PB_FP23_CFG_3_FMR_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP23_CFG_3_FMR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_3_FMR_SPARE]

//>> SET_[PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.setBit<PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]

//>> CLEAR_[PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.clearBit<PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]

//>> GET_[PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.extractToRight<PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]

//>> GET_[PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]
static inline bool GET_PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.getBit<PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.setBit<PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]

//>> CLEAR_[PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.clearBit<PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]

//>> GET_[PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& GET_PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.extractToRight<PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]

//>> GET_[PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]
static inline bool GET_PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.getBit<PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_FP23_CFG_3_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_PRS_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_3_PRS_SPARE,
           PB_FP23_CFG_3_PRS_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP23_CFG_3_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_PRS_SPARE]

//>> SET_[PB_FP23_CFG_3_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_FP23_CFG_3_PRS_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_FP23_CFG_3_PRS_SPARE,
           PB_FP23_CFG_3_PRS_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP23_CFG_3_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP23_CFG_3_PRS_SPARE]

//>> GET_[PB_FP23_CFG_3_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_FP23_CFG_3_PRS_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP23_CFG));
#endif
    return i_data.extractToRight<PB_FP23_CFG_3_PRS_SPARE,
           PB_FP23_CFG_3_PRS_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP23_CFG_3_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP23_CFG_3_PRS_SPARE]

//>> PREP_[DL_PPE_WRAP_XIXCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DL_PPE_WRAP_XIXCR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DL_PPE_WRAP_XIXCR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DL_PPE_WRAP_XIXCR]

//>> GET_[DL_PPE_WRAP_XIXCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DL_PPE_WRAP_XIXCR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DL_PPE_WRAP_XIXCR;
#endif
    return fapi2::getScom(i_target, DL_PPE_WRAP_XIXCR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DL_PPE_WRAP_XIXCR]

//>> PUT_[DL_PPE_WRAP_XIXCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DL_PPE_WRAP_XIXCR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DL_PPE_WRAP_XIXCR));
#endif
    return fapi2::putScom(i_target, DL_PPE_WRAP_XIXCR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DL_PPE_WRAP_XIXCR]


//>> SET_[DL_PPE_WRAP_XIXCR_PPE_XIXCR_XCR]
static inline fapi2::buffer<uint64_t>& SET_DL_PPE_WRAP_XIXCR_PPE_XIXCR_XCR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DL_PPE_WRAP_XIXCR));
#endif
    return o_data.insertFromRight<DL_PPE_WRAP_XIXCR_PPE_XIXCR_XCR,
           DL_PPE_WRAP_XIXCR_PPE_XIXCR_XCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access DL_PPE_WRAP_XIXCR_PPE_XIXCR_XCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DL_PPE_WRAP_XIXCR_PPE_XIXCR_XCR]

//>> SET_[DL_PPE_WRAP_XIXCR_PPE_XIXCR_XCR]
static inline fapi2::buffer<uint64_t>& SET_DL_PPE_WRAP_XIXCR_PPE_XIXCR_XCR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DL_PPE_WRAP_XIXCR));
#endif
    return o_data.insertFromRight<DL_PPE_WRAP_XIXCR_PPE_XIXCR_XCR,
           DL_PPE_WRAP_XIXCR_PPE_XIXCR_XCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access DL_PPE_WRAP_XIXCR_PPE_XIXCR_XCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DL_PPE_WRAP_XIXCR_PPE_XIXCR_XCR]

//>> GET_[DL_PPE_WRAP_XIXCR_PPE_XIXCR_XCR]
static inline fapi2::buffer<uint64_t>& GET_DL_PPE_WRAP_XIXCR_PPE_XIXCR_XCR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DL_PPE_WRAP_XIXCR));
#endif
    return i_data.extractToRight<DL_PPE_WRAP_XIXCR_PPE_XIXCR_XCR,
           DL_PPE_WRAP_XIXCR_PPE_XIXCR_XCR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access DL_PPE_WRAP_XIXCR_PPE_XIXCR_XCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DL_PPE_WRAP_XIXCR_PPE_XIXCR_XCR]

//>> SET_[DL_PPE_WRAP_XIXCR_NULL_CTR]
static inline fapi2::buffer<uint64_t>& SET_DL_PPE_WRAP_XIXCR_NULL_CTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DL_PPE_WRAP_XIXCR));
#endif
    return o_data.insertFromRight<DL_PPE_WRAP_XIXCR_NULL_CTR,
           DL_PPE_WRAP_XIXCR_NULL_CTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access DL_PPE_WRAP_XIXCR_NULL_CTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DL_PPE_WRAP_XIXCR_NULL_CTR]

//>> SET_[DL_PPE_WRAP_XIXCR_NULL_CTR]
static inline fapi2::buffer<uint64_t>& SET_DL_PPE_WRAP_XIXCR_NULL_CTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DL_PPE_WRAP_XIXCR));
#endif
    return o_data.insertFromRight<DL_PPE_WRAP_XIXCR_NULL_CTR,
           DL_PPE_WRAP_XIXCR_NULL_CTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access DL_PPE_WRAP_XIXCR_NULL_CTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DL_PPE_WRAP_XIXCR_NULL_CTR]

//>> GET_[DL_PPE_WRAP_XIXCR_NULL_CTR]
static inline fapi2::buffer<uint64_t>& GET_DL_PPE_WRAP_XIXCR_NULL_CTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DL_PPE_WRAP_XIXCR));
#endif
    return i_data.extractToRight<DL_PPE_WRAP_XIXCR_NULL_CTR,
           DL_PPE_WRAP_XIXCR_NULL_CTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access DL_PPE_WRAP_XIXCR_NULL_CTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DL_PPE_WRAP_XIXCR_NULL_CTR]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
