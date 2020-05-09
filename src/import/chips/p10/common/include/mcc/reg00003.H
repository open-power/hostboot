/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mcc/reg00003.H $          */
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

#ifndef __MCC_REG00003_H_
#define __MCC_REG00003_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> PREP_[USTL_USTLMCHWFM]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_USTL_USTLMCHWFM(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLMCHWFM;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[USTL_USTLMCHWFM]

//>> GET_[USTL_USTLMCHWFM]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_USTL_USTLMCHWFM(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLMCHWFM;
#endif
    return fapi2::getScom(i_target, USTL_USTLMCHWFM, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[USTL_USTLMCHWFM]

//>> PUT_[USTL_USTLMCHWFM]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_USTL_USTLMCHWFM(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return fapi2::putScom(i_target, USTL_USTLMCHWFM, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[USTL_USTLMCHWFM]


//>> SET_[USTL_USTLMCHWFM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLMCHWFM_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return o_data.insertFromRight<USTL_USTLMCHWFM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLMCHWFM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLMCHWFM_ENABLE]

//>> SET_[USTL_USTLMCHWFM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLMCHWFM_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return o_data.insertFromRight<USTL_USTLMCHWFM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLMCHWFM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLMCHWFM_ENABLE]

//>> SET_[USTL_USTLMCHWFM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLMCHWFM_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return o_data.setBit<USTL_USTLMCHWFM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLMCHWFM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLMCHWFM_ENABLE]

//>> CLEAR_[USTL_USTLMCHWFM_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLMCHWFM_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return o_data.clearBit<USTL_USTLMCHWFM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLMCHWFM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLMCHWFM_ENABLE]

//>> GET_[USTL_USTLMCHWFM_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_USTL_USTLMCHWFM_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return i_data.extractToRight<USTL_USTLMCHWFM_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLMCHWFM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLMCHWFM_ENABLE]

//>> GET_[USTL_USTLMCHWFM_ENABLE]
static inline bool GET_USTL_USTLMCHWFM_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return i_data.getBit<USTL_USTLMCHWFM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLMCHWFM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLMCHWFM_ENABLE]

//>> SET_[USTL_USTLMCHWFM_FAIL_THRESH]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLMCHWFM_FAIL_THRESH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return o_data.insertFromRight<USTL_USTLMCHWFM_FAIL_THRESH,
           USTL_USTLMCHWFM_FAIL_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLMCHWFM_FAIL_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLMCHWFM_FAIL_THRESH]

//>> SET_[USTL_USTLMCHWFM_FAIL_THRESH]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLMCHWFM_FAIL_THRESH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return o_data.insertFromRight<USTL_USTLMCHWFM_FAIL_THRESH,
           USTL_USTLMCHWFM_FAIL_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLMCHWFM_FAIL_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLMCHWFM_FAIL_THRESH]

//>> GET_[USTL_USTLMCHWFM_FAIL_THRESH]
static inline fapi2::buffer<uint64_t>& GET_USTL_USTLMCHWFM_FAIL_THRESH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return i_data.extractToRight<USTL_USTLMCHWFM_FAIL_THRESH,
           USTL_USTLMCHWFM_FAIL_THRESH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLMCHWFM_FAIL_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLMCHWFM_FAIL_THRESH]

//>> SET_[USTL_USTLMCHWFM_WINDOW_SIZE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLMCHWFM_WINDOW_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return o_data.insertFromRight<USTL_USTLMCHWFM_WINDOW_SIZE,
           USTL_USTLMCHWFM_WINDOW_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLMCHWFM_WINDOW_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLMCHWFM_WINDOW_SIZE]

//>> SET_[USTL_USTLMCHWFM_WINDOW_SIZE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLMCHWFM_WINDOW_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return o_data.insertFromRight<USTL_USTLMCHWFM_WINDOW_SIZE,
           USTL_USTLMCHWFM_WINDOW_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLMCHWFM_WINDOW_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLMCHWFM_WINDOW_SIZE]

//>> GET_[USTL_USTLMCHWFM_WINDOW_SIZE]
static inline fapi2::buffer<uint64_t>& GET_USTL_USTLMCHWFM_WINDOW_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return i_data.extractToRight<USTL_USTLMCHWFM_WINDOW_SIZE,
           USTL_USTLMCHWFM_WINDOW_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLMCHWFM_WINDOW_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLMCHWFM_WINDOW_SIZE]

//>> SET_[USTL_USTLMCHWFM_TSCALE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLMCHWFM_TSCALE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return o_data.insertFromRight<USTL_USTLMCHWFM_TSCALE,
           USTL_USTLMCHWFM_TSCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLMCHWFM_TSCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLMCHWFM_TSCALE]

//>> SET_[USTL_USTLMCHWFM_TSCALE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLMCHWFM_TSCALE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return o_data.insertFromRight<USTL_USTLMCHWFM_TSCALE,
           USTL_USTLMCHWFM_TSCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLMCHWFM_TSCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLMCHWFM_TSCALE]

//>> GET_[USTL_USTLMCHWFM_TSCALE]
static inline fapi2::buffer<uint64_t>& GET_USTL_USTLMCHWFM_TSCALE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return i_data.extractToRight<USTL_USTLMCHWFM_TSCALE,
           USTL_USTLMCHWFM_TSCALE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLMCHWFM_TSCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLMCHWFM_TSCALE]

//>> SET_[USTL_USTLMCHWFM_SCOM_COMMAND_VALID]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLMCHWFM_SCOM_COMMAND_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return o_data.insertFromRight<USTL_USTLMCHWFM_SCOM_COMMAND_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLMCHWFM_SCOM_COMMAND_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLMCHWFM_SCOM_COMMAND_VALID]

//>> SET_[USTL_USTLMCHWFM_SCOM_COMMAND_VALID]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLMCHWFM_SCOM_COMMAND_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return o_data.insertFromRight<USTL_USTLMCHWFM_SCOM_COMMAND_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLMCHWFM_SCOM_COMMAND_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLMCHWFM_SCOM_COMMAND_VALID]

//>> SET_[USTL_USTLMCHWFM_SCOM_COMMAND_VALID]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLMCHWFM_SCOM_COMMAND_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return o_data.setBit<USTL_USTLMCHWFM_SCOM_COMMAND_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLMCHWFM_SCOM_COMMAND_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLMCHWFM_SCOM_COMMAND_VALID]

//>> CLEAR_[USTL_USTLMCHWFM_SCOM_COMMAND_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLMCHWFM_SCOM_COMMAND_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return o_data.clearBit<USTL_USTLMCHWFM_SCOM_COMMAND_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLMCHWFM_SCOM_COMMAND_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLMCHWFM_SCOM_COMMAND_VALID]

//>> GET_[USTL_USTLMCHWFM_SCOM_COMMAND_VALID]
static inline fapi2::buffer<uint64_t>& GET_USTL_USTLMCHWFM_SCOM_COMMAND_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return i_data.extractToRight<USTL_USTLMCHWFM_SCOM_COMMAND_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLMCHWFM_SCOM_COMMAND_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLMCHWFM_SCOM_COMMAND_VALID]

//>> GET_[USTL_USTLMCHWFM_SCOM_COMMAND_VALID]
static inline bool GET_USTL_USTLMCHWFM_SCOM_COMMAND_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return i_data.getBit<USTL_USTLMCHWFM_SCOM_COMMAND_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLMCHWFM_SCOM_COMMAND_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLMCHWFM_SCOM_COMMAND_VALID]

//>> SET_[USTL_USTLMCHWFM_SCOM_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLMCHWFM_SCOM_COMMAND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return o_data.insertFromRight<USTL_USTLMCHWFM_SCOM_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLMCHWFM_SCOM_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLMCHWFM_SCOM_COMMAND]

//>> SET_[USTL_USTLMCHWFM_SCOM_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLMCHWFM_SCOM_COMMAND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return o_data.insertFromRight<USTL_USTLMCHWFM_SCOM_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLMCHWFM_SCOM_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLMCHWFM_SCOM_COMMAND]

//>> SET_[USTL_USTLMCHWFM_SCOM_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLMCHWFM_SCOM_COMMAND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return o_data.setBit<USTL_USTLMCHWFM_SCOM_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLMCHWFM_SCOM_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLMCHWFM_SCOM_COMMAND]

//>> CLEAR_[USTL_USTLMCHWFM_SCOM_COMMAND]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLMCHWFM_SCOM_COMMAND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return o_data.clearBit<USTL_USTLMCHWFM_SCOM_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLMCHWFM_SCOM_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLMCHWFM_SCOM_COMMAND]

//>> GET_[USTL_USTLMCHWFM_SCOM_COMMAND]
static inline fapi2::buffer<uint64_t>& GET_USTL_USTLMCHWFM_SCOM_COMMAND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return i_data.extractToRight<USTL_USTLMCHWFM_SCOM_COMMAND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLMCHWFM_SCOM_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLMCHWFM_SCOM_COMMAND]

//>> GET_[USTL_USTLMCHWFM_SCOM_COMMAND]
static inline bool GET_USTL_USTLMCHWFM_SCOM_COMMAND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return i_data.getBit<USTL_USTLMCHWFM_SCOM_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLMCHWFM_SCOM_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLMCHWFM_SCOM_COMMAND]

//>> SET_[USTL_USTLMCHWFM_SUB_CHANNEL_SELECT]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return o_data.insertFromRight<USTL_USTLMCHWFM_SUB_CHANNEL_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLMCHWFM_SUB_CHANNEL_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLMCHWFM_SUB_CHANNEL_SELECT]

//>> SET_[USTL_USTLMCHWFM_SUB_CHANNEL_SELECT]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return o_data.insertFromRight<USTL_USTLMCHWFM_SUB_CHANNEL_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLMCHWFM_SUB_CHANNEL_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLMCHWFM_SUB_CHANNEL_SELECT]

//>> SET_[USTL_USTLMCHWFM_SUB_CHANNEL_SELECT]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return o_data.setBit<USTL_USTLMCHWFM_SUB_CHANNEL_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLMCHWFM_SUB_CHANNEL_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLMCHWFM_SUB_CHANNEL_SELECT]

//>> CLEAR_[USTL_USTLMCHWFM_SUB_CHANNEL_SELECT]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return o_data.clearBit<USTL_USTLMCHWFM_SUB_CHANNEL_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLMCHWFM_SUB_CHANNEL_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLMCHWFM_SUB_CHANNEL_SELECT]

//>> GET_[USTL_USTLMCHWFM_SUB_CHANNEL_SELECT]
static inline fapi2::buffer<uint64_t>& GET_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return i_data.extractToRight<USTL_USTLMCHWFM_SUB_CHANNEL_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLMCHWFM_SUB_CHANNEL_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLMCHWFM_SUB_CHANNEL_SELECT]

//>> GET_[USTL_USTLMCHWFM_SUB_CHANNEL_SELECT]
static inline bool GET_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return i_data.getBit<USTL_USTLMCHWFM_SUB_CHANNEL_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLMCHWFM_SUB_CHANNEL_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLMCHWFM_SUB_CHANNEL_SELECT]

//>> SET_[USTL_USTLMCHWFM_HWFM_STATUS]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLMCHWFM_HWFM_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return o_data.insertFromRight<USTL_USTLMCHWFM_HWFM_STATUS,
           USTL_USTLMCHWFM_HWFM_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLMCHWFM_HWFM_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLMCHWFM_HWFM_STATUS]

//>> SET_[USTL_USTLMCHWFM_HWFM_STATUS]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLMCHWFM_HWFM_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return o_data.insertFromRight<USTL_USTLMCHWFM_HWFM_STATUS,
           USTL_USTLMCHWFM_HWFM_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLMCHWFM_HWFM_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLMCHWFM_HWFM_STATUS]

//>> GET_[USTL_USTLMCHWFM_HWFM_STATUS]
static inline fapi2::buffer<uint64_t>& GET_USTL_USTLMCHWFM_HWFM_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLMCHWFM));
#endif
    return i_data.extractToRight<USTL_USTLMCHWFM_HWFM_STATUS,
           USTL_USTLMCHWFM_HWFM_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLMCHWFM_HWFM_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLMCHWFM_HWFM_STATUS]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
