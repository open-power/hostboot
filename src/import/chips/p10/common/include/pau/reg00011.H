/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pau/reg00011.H $          */
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

#ifndef __PAU_REG00011_H_
#define __PAU_REG00011_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


//>> PREP_[FIR_REG_1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FIR_REG_1_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR_REG_1_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FIR_REG_1_RW]

//>> GET_[FIR_REG_1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FIR_REG_1_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR_REG_1_RW;
#endif
    return fapi2::getScom(i_target, FIR_REG_1_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FIR_REG_1_RW]

//>> PUT_[FIR_REG_1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FIR_REG_1_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return fapi2::putScom(i_target, FIR_REG_1_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FIR_REG_1_RW]

//>> PREP_[FIR_REG_1_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FIR_REG_1_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR_REG_1_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FIR_REG_1_WO_AND]

//>> GET_[FIR_REG_1_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FIR_REG_1_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR_REG_1_WO_AND;
#endif
    return fapi2::getScom(i_target, FIR_REG_1_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FIR_REG_1_WO_AND]

//>> PUT_[FIR_REG_1_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FIR_REG_1_WO_AND(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return fapi2::putScom(i_target, FIR_REG_1_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FIR_REG_1_WO_AND]

//>> PREP_[FIR_REG_1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FIR_REG_1_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR_REG_1_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FIR_REG_1_WO_OR]

//>> GET_[FIR_REG_1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FIR_REG_1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR_REG_1_WO_OR;
#endif
    return fapi2::getScom(i_target, FIR_REG_1_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FIR_REG_1_WO_OR]

//>> PUT_[FIR_REG_1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FIR_REG_1_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return fapi2::putScom(i_target, FIR_REG_1_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FIR_REG_1_WO_OR]


//>> SET_[FIR_REG_1_NDL_BRK0_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK0_STALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK0_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_NDL_BRK0_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK0_STALL]

//>> SET_[FIR_REG_1_NDL_BRK0_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK0_STALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK0_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_NDL_BRK0_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK0_STALL]

//>> SET_[FIR_REG_1_NDL_BRK0_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK0_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_NDL_BRK0_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_NDL_BRK0_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK0_STALL]

//>> CLEAR_[FIR_REG_1_NDL_BRK0_STALL]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_NDL_BRK0_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_NDL_BRK0_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_NDL_BRK0_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_NDL_BRK0_STALL]

//>> GET_[FIR_REG_1_NDL_BRK0_STALL]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_NDL_BRK0_STALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_NDL_BRK0_STALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_NDL_BRK0_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK0_STALL]

//>> GET_[FIR_REG_1_NDL_BRK0_STALL]
static inline bool GET_FIR_REG_1_NDL_BRK0_STALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_NDL_BRK0_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_NDL_BRK0_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK0_STALL]

//>> SET_[FIR_REG_1_NDL_BRK0_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK0_NOSTALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK0_NOSTALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_NDL_BRK0_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK0_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK0_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK0_NOSTALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK0_NOSTALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_NDL_BRK0_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK0_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK0_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK0_NOSTALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_NDL_BRK0_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_NDL_BRK0_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK0_NOSTALL]

//>> CLEAR_[FIR_REG_1_NDL_BRK0_NOSTALL]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_NDL_BRK0_NOSTALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_NDL_BRK0_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_NDL_BRK0_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_NDL_BRK0_NOSTALL]

//>> GET_[FIR_REG_1_NDL_BRK0_NOSTALL]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_NDL_BRK0_NOSTALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_NDL_BRK0_NOSTALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_NDL_BRK0_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK0_NOSTALL]

//>> GET_[FIR_REG_1_NDL_BRK0_NOSTALL]
static inline bool GET_FIR_REG_1_NDL_BRK0_NOSTALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_NDL_BRK0_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_NDL_BRK0_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK0_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK1_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK1_STALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK1_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_NDL_BRK1_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK1_STALL]

//>> SET_[FIR_REG_1_NDL_BRK1_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK1_STALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK1_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_NDL_BRK1_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK1_STALL]

//>> SET_[FIR_REG_1_NDL_BRK1_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK1_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_NDL_BRK1_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_NDL_BRK1_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK1_STALL]

//>> CLEAR_[FIR_REG_1_NDL_BRK1_STALL]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_NDL_BRK1_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_NDL_BRK1_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_NDL_BRK1_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_NDL_BRK1_STALL]

//>> GET_[FIR_REG_1_NDL_BRK1_STALL]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_NDL_BRK1_STALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_NDL_BRK1_STALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_NDL_BRK1_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK1_STALL]

//>> GET_[FIR_REG_1_NDL_BRK1_STALL]
static inline bool GET_FIR_REG_1_NDL_BRK1_STALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_NDL_BRK1_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_NDL_BRK1_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK1_STALL]

//>> SET_[FIR_REG_1_NDL_BRK1_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK1_NOSTALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK1_NOSTALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_NDL_BRK1_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK1_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK1_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK1_NOSTALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK1_NOSTALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_NDL_BRK1_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK1_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK1_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK1_NOSTALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_NDL_BRK1_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_NDL_BRK1_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK1_NOSTALL]

//>> CLEAR_[FIR_REG_1_NDL_BRK1_NOSTALL]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_NDL_BRK1_NOSTALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_NDL_BRK1_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_NDL_BRK1_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_NDL_BRK1_NOSTALL]

//>> GET_[FIR_REG_1_NDL_BRK1_NOSTALL]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_NDL_BRK1_NOSTALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_NDL_BRK1_NOSTALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_NDL_BRK1_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK1_NOSTALL]

//>> GET_[FIR_REG_1_NDL_BRK1_NOSTALL]
static inline bool GET_FIR_REG_1_NDL_BRK1_NOSTALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_NDL_BRK1_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_NDL_BRK1_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK1_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK2_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK2_STALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK2_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_NDL_BRK2_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK2_STALL]

//>> SET_[FIR_REG_1_NDL_BRK2_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK2_STALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK2_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_NDL_BRK2_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK2_STALL]

//>> SET_[FIR_REG_1_NDL_BRK2_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK2_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_NDL_BRK2_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_NDL_BRK2_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK2_STALL]

//>> CLEAR_[FIR_REG_1_NDL_BRK2_STALL]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_NDL_BRK2_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_NDL_BRK2_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_NDL_BRK2_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_NDL_BRK2_STALL]

//>> GET_[FIR_REG_1_NDL_BRK2_STALL]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_NDL_BRK2_STALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_NDL_BRK2_STALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_NDL_BRK2_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK2_STALL]

//>> GET_[FIR_REG_1_NDL_BRK2_STALL]
static inline bool GET_FIR_REG_1_NDL_BRK2_STALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_NDL_BRK2_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_NDL_BRK2_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK2_STALL]

//>> SET_[FIR_REG_1_NDL_BRK2_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK2_NOSTALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK2_NOSTALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_NDL_BRK2_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK2_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK2_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK2_NOSTALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK2_NOSTALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_NDL_BRK2_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK2_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK2_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK2_NOSTALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_NDL_BRK2_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_NDL_BRK2_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK2_NOSTALL]

//>> CLEAR_[FIR_REG_1_NDL_BRK2_NOSTALL]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_NDL_BRK2_NOSTALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_NDL_BRK2_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_NDL_BRK2_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_NDL_BRK2_NOSTALL]

//>> GET_[FIR_REG_1_NDL_BRK2_NOSTALL]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_NDL_BRK2_NOSTALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_NDL_BRK2_NOSTALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_NDL_BRK2_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK2_NOSTALL]

//>> GET_[FIR_REG_1_NDL_BRK2_NOSTALL]
static inline bool GET_FIR_REG_1_NDL_BRK2_NOSTALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_NDL_BRK2_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_NDL_BRK2_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK2_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK3_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK3_STALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK3_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_NDL_BRK3_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK3_STALL]

//>> SET_[FIR_REG_1_NDL_BRK3_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK3_STALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK3_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_NDL_BRK3_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK3_STALL]

//>> SET_[FIR_REG_1_NDL_BRK3_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK3_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_NDL_BRK3_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_NDL_BRK3_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK3_STALL]

//>> CLEAR_[FIR_REG_1_NDL_BRK3_STALL]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_NDL_BRK3_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_NDL_BRK3_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_NDL_BRK3_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_NDL_BRK3_STALL]

//>> GET_[FIR_REG_1_NDL_BRK3_STALL]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_NDL_BRK3_STALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_NDL_BRK3_STALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_NDL_BRK3_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK3_STALL]

//>> GET_[FIR_REG_1_NDL_BRK3_STALL]
static inline bool GET_FIR_REG_1_NDL_BRK3_STALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_NDL_BRK3_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_NDL_BRK3_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK3_STALL]

//>> SET_[FIR_REG_1_NDL_BRK3_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK3_NOSTALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK3_NOSTALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_NDL_BRK3_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK3_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK3_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK3_NOSTALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK3_NOSTALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_NDL_BRK3_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK3_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK3_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK3_NOSTALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_NDL_BRK3_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_NDL_BRK3_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK3_NOSTALL]

//>> CLEAR_[FIR_REG_1_NDL_BRK3_NOSTALL]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_NDL_BRK3_NOSTALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_NDL_BRK3_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_NDL_BRK3_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_NDL_BRK3_NOSTALL]

//>> GET_[FIR_REG_1_NDL_BRK3_NOSTALL]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_NDL_BRK3_NOSTALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_NDL_BRK3_NOSTALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_NDL_BRK3_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK3_NOSTALL]

//>> GET_[FIR_REG_1_NDL_BRK3_NOSTALL]
static inline bool GET_FIR_REG_1_NDL_BRK3_NOSTALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_NDL_BRK3_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_NDL_BRK3_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK3_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK4_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK4_STALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK4_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_NDL_BRK4_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK4_STALL]

//>> SET_[FIR_REG_1_NDL_BRK4_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK4_STALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK4_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_NDL_BRK4_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK4_STALL]

//>> SET_[FIR_REG_1_NDL_BRK4_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK4_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_NDL_BRK4_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_NDL_BRK4_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK4_STALL]

//>> CLEAR_[FIR_REG_1_NDL_BRK4_STALL]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_NDL_BRK4_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_NDL_BRK4_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_NDL_BRK4_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_NDL_BRK4_STALL]

//>> GET_[FIR_REG_1_NDL_BRK4_STALL]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_NDL_BRK4_STALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_NDL_BRK4_STALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_NDL_BRK4_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK4_STALL]

//>> GET_[FIR_REG_1_NDL_BRK4_STALL]
static inline bool GET_FIR_REG_1_NDL_BRK4_STALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_NDL_BRK4_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_NDL_BRK4_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK4_STALL]

//>> SET_[FIR_REG_1_NDL_BRK4_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK4_NOSTALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK4_NOSTALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_NDL_BRK4_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK4_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK4_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK4_NOSTALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK4_NOSTALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_NDL_BRK4_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK4_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK4_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK4_NOSTALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_NDL_BRK4_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_NDL_BRK4_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK4_NOSTALL]

//>> CLEAR_[FIR_REG_1_NDL_BRK4_NOSTALL]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_NDL_BRK4_NOSTALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_NDL_BRK4_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_NDL_BRK4_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_NDL_BRK4_NOSTALL]

//>> GET_[FIR_REG_1_NDL_BRK4_NOSTALL]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_NDL_BRK4_NOSTALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_NDL_BRK4_NOSTALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_NDL_BRK4_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK4_NOSTALL]

//>> GET_[FIR_REG_1_NDL_BRK4_NOSTALL]
static inline bool GET_FIR_REG_1_NDL_BRK4_NOSTALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_NDL_BRK4_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_NDL_BRK4_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK4_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK5_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK5_STALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK5_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_NDL_BRK5_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK5_STALL]

//>> SET_[FIR_REG_1_NDL_BRK5_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK5_STALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK5_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_NDL_BRK5_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK5_STALL]

//>> SET_[FIR_REG_1_NDL_BRK5_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK5_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_NDL_BRK5_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_NDL_BRK5_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK5_STALL]

//>> CLEAR_[FIR_REG_1_NDL_BRK5_STALL]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_NDL_BRK5_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_NDL_BRK5_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_NDL_BRK5_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_NDL_BRK5_STALL]

//>> GET_[FIR_REG_1_NDL_BRK5_STALL]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_NDL_BRK5_STALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_NDL_BRK5_STALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_NDL_BRK5_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK5_STALL]

//>> GET_[FIR_REG_1_NDL_BRK5_STALL]
static inline bool GET_FIR_REG_1_NDL_BRK5_STALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_NDL_BRK5_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_NDL_BRK5_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK5_STALL]

//>> SET_[FIR_REG_1_NDL_BRK5_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK5_NOSTALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK5_NOSTALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_NDL_BRK5_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK5_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK5_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK5_NOSTALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK5_NOSTALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_NDL_BRK5_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK5_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK5_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK5_NOSTALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_NDL_BRK5_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_NDL_BRK5_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK5_NOSTALL]

//>> CLEAR_[FIR_REG_1_NDL_BRK5_NOSTALL]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_NDL_BRK5_NOSTALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_NDL_BRK5_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_NDL_BRK5_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_NDL_BRK5_NOSTALL]

//>> GET_[FIR_REG_1_NDL_BRK5_NOSTALL]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_NDL_BRK5_NOSTALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_NDL_BRK5_NOSTALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_NDL_BRK5_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK5_NOSTALL]

//>> GET_[FIR_REG_1_NDL_BRK5_NOSTALL]
static inline bool GET_FIR_REG_1_NDL_BRK5_NOSTALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_NDL_BRK5_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_NDL_BRK5_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK5_NOSTALL]

//>> SET_[FIR_REG_1_MISC_REG_RING_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_MISC_REG_RING_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_MISC_REG_RING_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_MISC_REG_RING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_MISC_REG_RING_ERR]

//>> SET_[FIR_REG_1_MISC_REG_RING_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_MISC_REG_RING_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_MISC_REG_RING_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_MISC_REG_RING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_MISC_REG_RING_ERR]

//>> SET_[FIR_REG_1_MISC_REG_RING_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_MISC_REG_RING_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_MISC_REG_RING_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_MISC_REG_RING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_MISC_REG_RING_ERR]

//>> CLEAR_[FIR_REG_1_MISC_REG_RING_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_MISC_REG_RING_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_MISC_REG_RING_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_MISC_REG_RING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_MISC_REG_RING_ERR]

//>> GET_[FIR_REG_1_MISC_REG_RING_ERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_MISC_REG_RING_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_MISC_REG_RING_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_MISC_REG_RING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_MISC_REG_RING_ERR]

//>> GET_[FIR_REG_1_MISC_REG_RING_ERR]
static inline bool GET_FIR_REG_1_MISC_REG_RING_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_MISC_REG_RING_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_MISC_REG_RING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_MISC_REG_RING_ERR]

//>> SET_[FIR_REG_1_MISC_INT_RA_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_MISC_INT_RA_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_MISC_INT_RA_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_MISC_INT_RA_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_MISC_INT_RA_PERR]

//>> SET_[FIR_REG_1_MISC_INT_RA_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_MISC_INT_RA_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_MISC_INT_RA_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_MISC_INT_RA_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_MISC_INT_RA_PERR]

//>> SET_[FIR_REG_1_MISC_INT_RA_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_MISC_INT_RA_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_MISC_INT_RA_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_MISC_INT_RA_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_MISC_INT_RA_PERR]

//>> CLEAR_[FIR_REG_1_MISC_INT_RA_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_MISC_INT_RA_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_MISC_INT_RA_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_MISC_INT_RA_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_MISC_INT_RA_PERR]

//>> GET_[FIR_REG_1_MISC_INT_RA_PERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_MISC_INT_RA_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_MISC_INT_RA_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_MISC_INT_RA_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_MISC_INT_RA_PERR]

//>> GET_[FIR_REG_1_MISC_INT_RA_PERR]
static inline bool GET_FIR_REG_1_MISC_INT_RA_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_MISC_INT_RA_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_MISC_INT_RA_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_MISC_INT_RA_PERR]

//>> SET_[FIR_REG_1_MISC_DA_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_MISC_DA_ADDR_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_MISC_DA_ADDR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_MISC_DA_ADDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_MISC_DA_ADDR_PERR]

//>> SET_[FIR_REG_1_MISC_DA_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_MISC_DA_ADDR_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_MISC_DA_ADDR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_MISC_DA_ADDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_MISC_DA_ADDR_PERR]

//>> SET_[FIR_REG_1_MISC_DA_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_MISC_DA_ADDR_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_MISC_DA_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_MISC_DA_ADDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_MISC_DA_ADDR_PERR]

//>> CLEAR_[FIR_REG_1_MISC_DA_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_MISC_DA_ADDR_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_MISC_DA_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_MISC_DA_ADDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_MISC_DA_ADDR_PERR]

//>> GET_[FIR_REG_1_MISC_DA_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_MISC_DA_ADDR_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_MISC_DA_ADDR_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_MISC_DA_ADDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_MISC_DA_ADDR_PERR]

//>> GET_[FIR_REG_1_MISC_DA_ADDR_PERR]
static inline bool GET_FIR_REG_1_MISC_DA_ADDR_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_MISC_DA_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_MISC_DA_ADDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_MISC_DA_ADDR_PERR]

//>> SET_[FIR_REG_1_MISC_CTRL_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_MISC_CTRL_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_MISC_CTRL_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_MISC_CTRL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_MISC_CTRL_PERR]

//>> SET_[FIR_REG_1_MISC_CTRL_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_MISC_CTRL_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_MISC_CTRL_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_MISC_CTRL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_MISC_CTRL_PERR]

//>> SET_[FIR_REG_1_MISC_CTRL_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_MISC_CTRL_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_MISC_CTRL_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_MISC_CTRL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_MISC_CTRL_PERR]

//>> CLEAR_[FIR_REG_1_MISC_CTRL_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_MISC_CTRL_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_MISC_CTRL_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_MISC_CTRL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_MISC_CTRL_PERR]

//>> GET_[FIR_REG_1_MISC_CTRL_PERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_MISC_CTRL_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_MISC_CTRL_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_MISC_CTRL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_MISC_CTRL_PERR]

//>> GET_[FIR_REG_1_MISC_CTRL_PERR]
static inline bool GET_FIR_REG_1_MISC_CTRL_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_MISC_CTRL_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_MISC_CTRL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_MISC_CTRL_PERR]

//>> SET_[FIR_REG_1_FIR1_RSVD_16]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_FIR1_RSVD_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_FIR1_RSVD_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_FIR1_RSVD_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_FIR1_RSVD_16]

//>> SET_[FIR_REG_1_FIR1_RSVD_16]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_FIR1_RSVD_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_FIR1_RSVD_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_FIR1_RSVD_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_FIR1_RSVD_16]

//>> SET_[FIR_REG_1_FIR1_RSVD_16]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_FIR1_RSVD_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_FIR1_RSVD_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_FIR1_RSVD_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_FIR1_RSVD_16]

//>> CLEAR_[FIR_REG_1_FIR1_RSVD_16]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_FIR1_RSVD_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_FIR1_RSVD_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_FIR1_RSVD_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_FIR1_RSVD_16]

//>> GET_[FIR_REG_1_FIR1_RSVD_16]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_FIR1_RSVD_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_FIR1_RSVD_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_FIR1_RSVD_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_FIR1_RSVD_16]

//>> GET_[FIR_REG_1_FIR1_RSVD_16]
static inline bool GET_FIR_REG_1_FIR1_RSVD_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_FIR1_RSVD_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_FIR1_RSVD_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_FIR1_RSVD_16]

//>> SET_[FIR_REG_1_ATS_TVT_ENTRY_INVALID]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_TVT_ENTRY_INVALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_TVT_ENTRY_INVALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_ATS_TVT_ENTRY_INVALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_TVT_ENTRY_INVALID]

//>> SET_[FIR_REG_1_ATS_TVT_ENTRY_INVALID]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_TVT_ENTRY_INVALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_TVT_ENTRY_INVALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_ATS_TVT_ENTRY_INVALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_TVT_ENTRY_INVALID]

//>> SET_[FIR_REG_1_ATS_TVT_ENTRY_INVALID]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_TVT_ENTRY_INVALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_ATS_TVT_ENTRY_INVALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_ATS_TVT_ENTRY_INVALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_TVT_ENTRY_INVALID]

//>> CLEAR_[FIR_REG_1_ATS_TVT_ENTRY_INVALID]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_ATS_TVT_ENTRY_INVALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_ATS_TVT_ENTRY_INVALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_ATS_TVT_ENTRY_INVALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_ATS_TVT_ENTRY_INVALID]

//>> GET_[FIR_REG_1_ATS_TVT_ENTRY_INVALID]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_ATS_TVT_ENTRY_INVALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_ATS_TVT_ENTRY_INVALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_ATS_TVT_ENTRY_INVALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_TVT_ENTRY_INVALID]

//>> GET_[FIR_REG_1_ATS_TVT_ENTRY_INVALID]
static inline bool GET_FIR_REG_1_ATS_TVT_ENTRY_INVALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_ATS_TVT_ENTRY_INVALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_ATS_TVT_ENTRY_INVALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_TVT_ENTRY_INVALID]

//>> SET_[FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR]

//>> SET_[FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR]

//>> SET_[FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR]

//>> CLEAR_[FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR]

//>> GET_[FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR]

//>> GET_[FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR]
static inline bool GET_FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR]

//>> SET_[FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR]

//>> SET_[FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR]

//>> SET_[FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR]

//>> CLEAR_[FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR]

//>> GET_[FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR]

//>> GET_[FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR]
static inline bool GET_FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR]

//>> SET_[FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR]

//>> SET_[FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR]

//>> SET_[FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR]

//>> CLEAR_[FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR]

//>> GET_[FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR]

//>> GET_[FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR]
static inline bool GET_FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR]

//>> SET_[FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR]

//>> SET_[FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR]

//>> SET_[FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR]

//>> CLEAR_[FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR]

//>> GET_[FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR]

//>> GET_[FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR]
static inline bool GET_FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR]

//>> SET_[FIR_REG_1_ATS_TCE_REQ_TO_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_TCE_REQ_TO_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_TCE_REQ_TO_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_ATS_TCE_REQ_TO_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_TCE_REQ_TO_ERR]

//>> SET_[FIR_REG_1_ATS_TCE_REQ_TO_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_TCE_REQ_TO_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_TCE_REQ_TO_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_ATS_TCE_REQ_TO_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_TCE_REQ_TO_ERR]

//>> SET_[FIR_REG_1_ATS_TCE_REQ_TO_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_TCE_REQ_TO_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_ATS_TCE_REQ_TO_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_ATS_TCE_REQ_TO_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_TCE_REQ_TO_ERR]

//>> CLEAR_[FIR_REG_1_ATS_TCE_REQ_TO_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_ATS_TCE_REQ_TO_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_ATS_TCE_REQ_TO_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_ATS_TCE_REQ_TO_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_ATS_TCE_REQ_TO_ERR]

//>> GET_[FIR_REG_1_ATS_TCE_REQ_TO_ERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_ATS_TCE_REQ_TO_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_ATS_TCE_REQ_TO_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_ATS_TCE_REQ_TO_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_TCE_REQ_TO_ERR]

//>> GET_[FIR_REG_1_ATS_TCE_REQ_TO_ERR]
static inline bool GET_FIR_REG_1_ATS_TCE_REQ_TO_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_ATS_TCE_REQ_TO_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_ATS_TCE_REQ_TO_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_TCE_REQ_TO_ERR]

//>> SET_[FIR_REG_1_ATS_TCD_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_TCD_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_TCD_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_ATS_TCD_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_TCD_PERR]

//>> SET_[FIR_REG_1_ATS_TCD_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_TCD_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_TCD_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_ATS_TCD_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_TCD_PERR]

//>> SET_[FIR_REG_1_ATS_TCD_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_TCD_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_ATS_TCD_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_ATS_TCD_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_TCD_PERR]

//>> CLEAR_[FIR_REG_1_ATS_TCD_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_ATS_TCD_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_ATS_TCD_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_ATS_TCD_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_ATS_TCD_PERR]

//>> GET_[FIR_REG_1_ATS_TCD_PERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_ATS_TCD_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_ATS_TCD_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_ATS_TCD_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_TCD_PERR]

//>> GET_[FIR_REG_1_ATS_TCD_PERR]
static inline bool GET_FIR_REG_1_ATS_TCD_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_ATS_TCD_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_ATS_TCD_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_TCD_PERR]

//>> SET_[FIR_REG_1_ATS_TDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_TDR_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_TDR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_ATS_TDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_TDR_PERR]

//>> SET_[FIR_REG_1_ATS_TDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_TDR_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_TDR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_ATS_TDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_TDR_PERR]

//>> SET_[FIR_REG_1_ATS_TDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_TDR_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_ATS_TDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_ATS_TDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_TDR_PERR]

//>> CLEAR_[FIR_REG_1_ATS_TDR_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_ATS_TDR_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_ATS_TDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_ATS_TDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_ATS_TDR_PERR]

//>> GET_[FIR_REG_1_ATS_TDR_PERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_ATS_TDR_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_ATS_TDR_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_ATS_TDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_TDR_PERR]

//>> GET_[FIR_REG_1_ATS_TDR_PERR]
static inline bool GET_FIR_REG_1_ATS_TDR_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_ATS_TDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_ATS_TDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_TDR_PERR]

//>> SET_[FIR_REG_1_ATS_AT_EA_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_AT_EA_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_AT_EA_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_ATS_AT_EA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_AT_EA_UE]

//>> SET_[FIR_REG_1_ATS_AT_EA_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_AT_EA_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_AT_EA_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_ATS_AT_EA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_AT_EA_UE]

//>> SET_[FIR_REG_1_ATS_AT_EA_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_AT_EA_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_ATS_AT_EA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_ATS_AT_EA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_AT_EA_UE]

//>> CLEAR_[FIR_REG_1_ATS_AT_EA_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_ATS_AT_EA_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_ATS_AT_EA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_ATS_AT_EA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_ATS_AT_EA_UE]

//>> GET_[FIR_REG_1_ATS_AT_EA_UE]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_ATS_AT_EA_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_ATS_AT_EA_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_ATS_AT_EA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_AT_EA_UE]

//>> GET_[FIR_REG_1_ATS_AT_EA_UE]
static inline bool GET_FIR_REG_1_ATS_AT_EA_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_ATS_AT_EA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_ATS_AT_EA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_AT_EA_UE]

//>> SET_[FIR_REG_1_ATS_AT_EA_CE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_AT_EA_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_AT_EA_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_ATS_AT_EA_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_AT_EA_CE]

//>> SET_[FIR_REG_1_ATS_AT_EA_CE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_AT_EA_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_AT_EA_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_ATS_AT_EA_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_AT_EA_CE]

//>> SET_[FIR_REG_1_ATS_AT_EA_CE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_AT_EA_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_ATS_AT_EA_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_ATS_AT_EA_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_AT_EA_CE]

//>> CLEAR_[FIR_REG_1_ATS_AT_EA_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_ATS_AT_EA_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_ATS_AT_EA_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_ATS_AT_EA_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_ATS_AT_EA_CE]

//>> GET_[FIR_REG_1_ATS_AT_EA_CE]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_ATS_AT_EA_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_ATS_AT_EA_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_ATS_AT_EA_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_AT_EA_CE]

//>> GET_[FIR_REG_1_ATS_AT_EA_CE]
static inline bool GET_FIR_REG_1_ATS_AT_EA_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_ATS_AT_EA_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_ATS_AT_EA_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_AT_EA_CE]

//>> SET_[FIR_REG_1_ATS_AT_TDRMEM_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_AT_TDRMEM_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_AT_TDRMEM_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_ATS_AT_TDRMEM_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_AT_TDRMEM_UE]

//>> SET_[FIR_REG_1_ATS_AT_TDRMEM_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_AT_TDRMEM_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_AT_TDRMEM_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_ATS_AT_TDRMEM_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_AT_TDRMEM_UE]

//>> SET_[FIR_REG_1_ATS_AT_TDRMEM_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_AT_TDRMEM_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_ATS_AT_TDRMEM_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_ATS_AT_TDRMEM_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_AT_TDRMEM_UE]

//>> CLEAR_[FIR_REG_1_ATS_AT_TDRMEM_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_ATS_AT_TDRMEM_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_ATS_AT_TDRMEM_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_ATS_AT_TDRMEM_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_ATS_AT_TDRMEM_UE]

//>> GET_[FIR_REG_1_ATS_AT_TDRMEM_UE]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_ATS_AT_TDRMEM_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_ATS_AT_TDRMEM_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_ATS_AT_TDRMEM_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_AT_TDRMEM_UE]

//>> GET_[FIR_REG_1_ATS_AT_TDRMEM_UE]
static inline bool GET_FIR_REG_1_ATS_AT_TDRMEM_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_ATS_AT_TDRMEM_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_ATS_AT_TDRMEM_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_AT_TDRMEM_UE]

//>> SET_[FIR_REG_1_ATS_AT_TDRMEM_CE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_AT_TDRMEM_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_AT_TDRMEM_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_ATS_AT_TDRMEM_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_AT_TDRMEM_CE]

//>> SET_[FIR_REG_1_ATS_AT_TDRMEM_CE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_AT_TDRMEM_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_AT_TDRMEM_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_ATS_AT_TDRMEM_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_AT_TDRMEM_CE]

//>> SET_[FIR_REG_1_ATS_AT_TDRMEM_CE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_AT_TDRMEM_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_ATS_AT_TDRMEM_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_ATS_AT_TDRMEM_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_AT_TDRMEM_CE]

//>> CLEAR_[FIR_REG_1_ATS_AT_TDRMEM_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_ATS_AT_TDRMEM_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_ATS_AT_TDRMEM_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_ATS_AT_TDRMEM_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_ATS_AT_TDRMEM_CE]

//>> GET_[FIR_REG_1_ATS_AT_TDRMEM_CE]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_ATS_AT_TDRMEM_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_ATS_AT_TDRMEM_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_ATS_AT_TDRMEM_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_AT_TDRMEM_CE]

//>> GET_[FIR_REG_1_ATS_AT_TDRMEM_CE]
static inline bool GET_FIR_REG_1_ATS_AT_TDRMEM_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_ATS_AT_TDRMEM_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_ATS_AT_TDRMEM_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_AT_TDRMEM_CE]

//>> SET_[FIR_REG_1_ATS_AT_RSPOUT_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_AT_RSPOUT_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_AT_RSPOUT_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_ATS_AT_RSPOUT_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_AT_RSPOUT_UE]

//>> SET_[FIR_REG_1_ATS_AT_RSPOUT_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_AT_RSPOUT_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_AT_RSPOUT_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_ATS_AT_RSPOUT_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_AT_RSPOUT_UE]

//>> SET_[FIR_REG_1_ATS_AT_RSPOUT_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_AT_RSPOUT_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_ATS_AT_RSPOUT_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_ATS_AT_RSPOUT_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_AT_RSPOUT_UE]

//>> CLEAR_[FIR_REG_1_ATS_AT_RSPOUT_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_ATS_AT_RSPOUT_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_ATS_AT_RSPOUT_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_ATS_AT_RSPOUT_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_ATS_AT_RSPOUT_UE]

//>> GET_[FIR_REG_1_ATS_AT_RSPOUT_UE]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_ATS_AT_RSPOUT_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_ATS_AT_RSPOUT_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_ATS_AT_RSPOUT_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_AT_RSPOUT_UE]

//>> GET_[FIR_REG_1_ATS_AT_RSPOUT_UE]
static inline bool GET_FIR_REG_1_ATS_AT_RSPOUT_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_ATS_AT_RSPOUT_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_ATS_AT_RSPOUT_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_AT_RSPOUT_UE]

//>> SET_[FIR_REG_1_ATS_AT_RSPOUT_CE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_AT_RSPOUT_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_AT_RSPOUT_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_ATS_AT_RSPOUT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_AT_RSPOUT_CE]

//>> SET_[FIR_REG_1_ATS_AT_RSPOUT_CE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_AT_RSPOUT_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_AT_RSPOUT_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_ATS_AT_RSPOUT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_AT_RSPOUT_CE]

//>> SET_[FIR_REG_1_ATS_AT_RSPOUT_CE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_AT_RSPOUT_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_ATS_AT_RSPOUT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_ATS_AT_RSPOUT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_AT_RSPOUT_CE]

//>> CLEAR_[FIR_REG_1_ATS_AT_RSPOUT_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_ATS_AT_RSPOUT_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_ATS_AT_RSPOUT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_ATS_AT_RSPOUT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_ATS_AT_RSPOUT_CE]

//>> GET_[FIR_REG_1_ATS_AT_RSPOUT_CE]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_ATS_AT_RSPOUT_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_ATS_AT_RSPOUT_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_ATS_AT_RSPOUT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_AT_RSPOUT_CE]

//>> GET_[FIR_REG_1_ATS_AT_RSPOUT_CE]
static inline bool GET_FIR_REG_1_ATS_AT_RSPOUT_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_ATS_AT_RSPOUT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_ATS_AT_RSPOUT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_AT_RSPOUT_CE]

//>> SET_[FIR_REG_1_ATS_TVT_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_TVT_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_TVT_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_ATS_TVT_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_TVT_PERR]

//>> SET_[FIR_REG_1_ATS_TVT_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_TVT_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_TVT_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_ATS_TVT_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_TVT_PERR]

//>> SET_[FIR_REG_1_ATS_TVT_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_TVT_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_ATS_TVT_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_ATS_TVT_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_TVT_PERR]

//>> CLEAR_[FIR_REG_1_ATS_TVT_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_ATS_TVT_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_ATS_TVT_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_ATS_TVT_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_ATS_TVT_PERR]

//>> GET_[FIR_REG_1_ATS_TVT_PERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_ATS_TVT_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_ATS_TVT_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_ATS_TVT_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_TVT_PERR]

//>> GET_[FIR_REG_1_ATS_TVT_PERR]
static inline bool GET_FIR_REG_1_ATS_TVT_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_ATS_TVT_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_ATS_TVT_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_TVT_PERR]

//>> SET_[FIR_REG_1_ATS_IODA_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_IODA_ADDR_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_IODA_ADDR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_ATS_IODA_ADDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_IODA_ADDR_PERR]

//>> SET_[FIR_REG_1_ATS_IODA_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_IODA_ADDR_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_IODA_ADDR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_ATS_IODA_ADDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_IODA_ADDR_PERR]

//>> SET_[FIR_REG_1_ATS_IODA_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_IODA_ADDR_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_ATS_IODA_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_ATS_IODA_ADDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_IODA_ADDR_PERR]

//>> CLEAR_[FIR_REG_1_ATS_IODA_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_ATS_IODA_ADDR_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_ATS_IODA_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_ATS_IODA_ADDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_ATS_IODA_ADDR_PERR]

//>> GET_[FIR_REG_1_ATS_IODA_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_ATS_IODA_ADDR_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_ATS_IODA_ADDR_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_ATS_IODA_ADDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_IODA_ADDR_PERR]

//>> GET_[FIR_REG_1_ATS_IODA_ADDR_PERR]
static inline bool GET_FIR_REG_1_ATS_IODA_ADDR_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_ATS_IODA_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_ATS_IODA_ADDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_IODA_ADDR_PERR]

//>> SET_[FIR_REG_1_ATS_PAU_CTRL_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_PAU_CTRL_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_PAU_CTRL_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_ATS_PAU_CTRL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_PAU_CTRL_PERR]

//>> SET_[FIR_REG_1_ATS_PAU_CTRL_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_PAU_CTRL_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_PAU_CTRL_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_ATS_PAU_CTRL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_PAU_CTRL_PERR]

//>> SET_[FIR_REG_1_ATS_PAU_CTRL_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_PAU_CTRL_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_ATS_PAU_CTRL_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_ATS_PAU_CTRL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_PAU_CTRL_PERR]

//>> CLEAR_[FIR_REG_1_ATS_PAU_CTRL_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_ATS_PAU_CTRL_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_ATS_PAU_CTRL_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_ATS_PAU_CTRL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_ATS_PAU_CTRL_PERR]

//>> GET_[FIR_REG_1_ATS_PAU_CTRL_PERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_ATS_PAU_CTRL_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_ATS_PAU_CTRL_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_ATS_PAU_CTRL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_PAU_CTRL_PERR]

//>> GET_[FIR_REG_1_ATS_PAU_CTRL_PERR]
static inline bool GET_FIR_REG_1_ATS_PAU_CTRL_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_ATS_PAU_CTRL_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_ATS_PAU_CTRL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_PAU_CTRL_PERR]

//>> SET_[FIR_REG_1_ATS_PAU_TOR_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_PAU_TOR_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_PAU_TOR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_ATS_PAU_TOR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_PAU_TOR_PERR]

//>> SET_[FIR_REG_1_ATS_PAU_TOR_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_PAU_TOR_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_PAU_TOR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_ATS_PAU_TOR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_PAU_TOR_PERR]

//>> SET_[FIR_REG_1_ATS_PAU_TOR_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_PAU_TOR_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_ATS_PAU_TOR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_ATS_PAU_TOR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_PAU_TOR_PERR]

//>> CLEAR_[FIR_REG_1_ATS_PAU_TOR_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_ATS_PAU_TOR_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_ATS_PAU_TOR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_ATS_PAU_TOR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_ATS_PAU_TOR_PERR]

//>> GET_[FIR_REG_1_ATS_PAU_TOR_PERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_ATS_PAU_TOR_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_ATS_PAU_TOR_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_ATS_PAU_TOR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_PAU_TOR_PERR]

//>> GET_[FIR_REG_1_ATS_PAU_TOR_PERR]
static inline bool GET_FIR_REG_1_ATS_PAU_TOR_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_ATS_PAU_TOR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_ATS_PAU_TOR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_PAU_TOR_PERR]

//>> SET_[FIR_REG_1_ATS_INVAL_IODA_TBL_SEL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_INVAL_IODA_TBL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_INVAL_IODA_TBL_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_ATS_INVAL_IODA_TBL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_INVAL_IODA_TBL_SEL]

//>> SET_[FIR_REG_1_ATS_INVAL_IODA_TBL_SEL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_INVAL_IODA_TBL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_INVAL_IODA_TBL_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_ATS_INVAL_IODA_TBL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_INVAL_IODA_TBL_SEL]

//>> SET_[FIR_REG_1_ATS_INVAL_IODA_TBL_SEL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_INVAL_IODA_TBL_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_ATS_INVAL_IODA_TBL_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_ATS_INVAL_IODA_TBL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_INVAL_IODA_TBL_SEL]

//>> CLEAR_[FIR_REG_1_ATS_INVAL_IODA_TBL_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_ATS_INVAL_IODA_TBL_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_ATS_INVAL_IODA_TBL_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_ATS_INVAL_IODA_TBL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_ATS_INVAL_IODA_TBL_SEL]

//>> GET_[FIR_REG_1_ATS_INVAL_IODA_TBL_SEL]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_ATS_INVAL_IODA_TBL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_ATS_INVAL_IODA_TBL_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_ATS_INVAL_IODA_TBL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_INVAL_IODA_TBL_SEL]

//>> GET_[FIR_REG_1_ATS_INVAL_IODA_TBL_SEL]
static inline bool GET_FIR_REG_1_ATS_INVAL_IODA_TBL_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_ATS_INVAL_IODA_TBL_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_ATS_INVAL_IODA_TBL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_INVAL_IODA_TBL_SEL]

//>> SET_[FIR_REG_1_ATS_RSVD_19]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_RSVD_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_RSVD_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_ATS_RSVD_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_RSVD_19]

//>> SET_[FIR_REG_1_ATS_RSVD_19]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_RSVD_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_ATS_RSVD_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_ATS_RSVD_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_RSVD_19]

//>> SET_[FIR_REG_1_ATS_RSVD_19]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_ATS_RSVD_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_ATS_RSVD_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_ATS_RSVD_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_ATS_RSVD_19]

//>> CLEAR_[FIR_REG_1_ATS_RSVD_19]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_ATS_RSVD_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_ATS_RSVD_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_ATS_RSVD_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_ATS_RSVD_19]

//>> GET_[FIR_REG_1_ATS_RSVD_19]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_ATS_RSVD_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_ATS_RSVD_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_ATS_RSVD_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_RSVD_19]

//>> GET_[FIR_REG_1_ATS_RSVD_19]
static inline bool GET_FIR_REG_1_ATS_RSVD_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_ATS_RSVD_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_ATS_RSVD_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_ATS_RSVD_19]

//>> SET_[FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT]

//>> SET_[FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT]

//>> SET_[FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT]

//>> CLEAR_[FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT]

//>> GET_[FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT]

//>> GET_[FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT]
static inline bool GET_FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT]

//>> SET_[FIR_REG_1_XSL_RSVD_19]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_RSVD_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_XSL_RSVD_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_RSVD_19]

//>> SET_[FIR_REG_1_XSL_RSVD_19]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_RSVD_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_XSL_RSVD_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_RSVD_19]

//>> SET_[FIR_REG_1_XSL_RSVD_19]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_RSVD_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_XSL_RSVD_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_RSVD_19]

//>> CLEAR_[FIR_REG_1_XSL_RSVD_19]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_XSL_RSVD_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_XSL_RSVD_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_XSL_RSVD_19]

//>> GET_[FIR_REG_1_XSL_RSVD_19]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_XSL_RSVD_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_XSL_RSVD_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_XSL_RSVD_19]

//>> GET_[FIR_REG_1_XSL_RSVD_19]
static inline bool GET_FIR_REG_1_XSL_RSVD_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_XSL_RSVD_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_XSL_RSVD_19]

//>> SET_[FIR_REG_1_XSL_RSVD_20]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_RSVD_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_XSL_RSVD_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_RSVD_20]

//>> SET_[FIR_REG_1_XSL_RSVD_20]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_RSVD_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_XSL_RSVD_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_RSVD_20]

//>> SET_[FIR_REG_1_XSL_RSVD_20]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_RSVD_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_XSL_RSVD_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_RSVD_20]

//>> CLEAR_[FIR_REG_1_XSL_RSVD_20]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_XSL_RSVD_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_XSL_RSVD_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_XSL_RSVD_20]

//>> GET_[FIR_REG_1_XSL_RSVD_20]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_XSL_RSVD_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_XSL_RSVD_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_XSL_RSVD_20]

//>> GET_[FIR_REG_1_XSL_RSVD_20]
static inline bool GET_FIR_REG_1_XSL_RSVD_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_XSL_RSVD_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_XSL_RSVD_20]

//>> SET_[FIR_REG_1_XSL_RSVD_21]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_RSVD_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_XSL_RSVD_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_RSVD_21]

//>> SET_[FIR_REG_1_XSL_RSVD_21]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_RSVD_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_XSL_RSVD_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_RSVD_21]

//>> SET_[FIR_REG_1_XSL_RSVD_21]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_RSVD_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_XSL_RSVD_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_RSVD_21]

//>> CLEAR_[FIR_REG_1_XSL_RSVD_21]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_XSL_RSVD_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_XSL_RSVD_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_XSL_RSVD_21]

//>> GET_[FIR_REG_1_XSL_RSVD_21]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_XSL_RSVD_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_XSL_RSVD_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_XSL_RSVD_21]

//>> GET_[FIR_REG_1_XSL_RSVD_21]
static inline bool GET_FIR_REG_1_XSL_RSVD_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_XSL_RSVD_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_XSL_RSVD_21]

//>> SET_[FIR_REG_1_XSL_RSVD_22]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_RSVD_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_XSL_RSVD_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_RSVD_22]

//>> SET_[FIR_REG_1_XSL_RSVD_22]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_RSVD_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_XSL_RSVD_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_RSVD_22]

//>> SET_[FIR_REG_1_XSL_RSVD_22]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_RSVD_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_XSL_RSVD_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_RSVD_22]

//>> CLEAR_[FIR_REG_1_XSL_RSVD_22]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_XSL_RSVD_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_XSL_RSVD_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_XSL_RSVD_22]

//>> GET_[FIR_REG_1_XSL_RSVD_22]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_XSL_RSVD_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_XSL_RSVD_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_XSL_RSVD_22]

//>> GET_[FIR_REG_1_XSL_RSVD_22]
static inline bool GET_FIR_REG_1_XSL_RSVD_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_XSL_RSVD_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_XSL_RSVD_22]

//>> SET_[FIR_REG_1_XSL_RSVD_23]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_RSVD_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_XSL_RSVD_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_RSVD_23]

//>> SET_[FIR_REG_1_XSL_RSVD_23]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_RSVD_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_XSL_RSVD_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_RSVD_23]

//>> SET_[FIR_REG_1_XSL_RSVD_23]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_RSVD_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_XSL_RSVD_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_RSVD_23]

//>> CLEAR_[FIR_REG_1_XSL_RSVD_23]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_XSL_RSVD_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_XSL_RSVD_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_XSL_RSVD_23]

//>> GET_[FIR_REG_1_XSL_RSVD_23]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_XSL_RSVD_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_XSL_RSVD_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_XSL_RSVD_23]

//>> GET_[FIR_REG_1_XSL_RSVD_23]
static inline bool GET_FIR_REG_1_XSL_RSVD_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_XSL_RSVD_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_XSL_RSVD_23]

//>> SET_[FIR_REG_1_XSL_RSVD_24]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_RSVD_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_XSL_RSVD_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_RSVD_24]

//>> SET_[FIR_REG_1_XSL_RSVD_24]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_RSVD_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_XSL_RSVD_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_RSVD_24]

//>> SET_[FIR_REG_1_XSL_RSVD_24]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_RSVD_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_XSL_RSVD_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_RSVD_24]

//>> CLEAR_[FIR_REG_1_XSL_RSVD_24]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_XSL_RSVD_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_XSL_RSVD_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_XSL_RSVD_24]

//>> GET_[FIR_REG_1_XSL_RSVD_24]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_XSL_RSVD_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_XSL_RSVD_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_XSL_RSVD_24]

//>> GET_[FIR_REG_1_XSL_RSVD_24]
static inline bool GET_FIR_REG_1_XSL_RSVD_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_XSL_RSVD_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_XSL_RSVD_24]

//>> SET_[FIR_REG_1_XSL_RSVD_25]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_RSVD_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_XSL_RSVD_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_RSVD_25]

//>> SET_[FIR_REG_1_XSL_RSVD_25]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_RSVD_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_XSL_RSVD_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_RSVD_25]

//>> SET_[FIR_REG_1_XSL_RSVD_25]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_RSVD_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_XSL_RSVD_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_RSVD_25]

//>> CLEAR_[FIR_REG_1_XSL_RSVD_25]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_XSL_RSVD_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_XSL_RSVD_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_XSL_RSVD_25]

//>> GET_[FIR_REG_1_XSL_RSVD_25]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_XSL_RSVD_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_XSL_RSVD_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_XSL_RSVD_25]

//>> GET_[FIR_REG_1_XSL_RSVD_25]
static inline bool GET_FIR_REG_1_XSL_RSVD_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_XSL_RSVD_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_XSL_RSVD_25]

//>> SET_[FIR_REG_1_XSL_RSVD_26]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_RSVD_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_XSL_RSVD_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_RSVD_26]

//>> SET_[FIR_REG_1_XSL_RSVD_26]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_RSVD_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_XSL_RSVD_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_RSVD_26]

//>> SET_[FIR_REG_1_XSL_RSVD_26]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_RSVD_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_XSL_RSVD_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_RSVD_26]

//>> CLEAR_[FIR_REG_1_XSL_RSVD_26]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_XSL_RSVD_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_XSL_RSVD_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_XSL_RSVD_26]

//>> GET_[FIR_REG_1_XSL_RSVD_26]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_XSL_RSVD_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_XSL_RSVD_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_XSL_RSVD_26]

//>> GET_[FIR_REG_1_XSL_RSVD_26]
static inline bool GET_FIR_REG_1_XSL_RSVD_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_XSL_RSVD_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_XSL_RSVD_26]

//>> SET_[FIR_REG_1_XSL_RSVD_27]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_RSVD_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_XSL_RSVD_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_RSVD_27]

//>> SET_[FIR_REG_1_XSL_RSVD_27]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_RSVD_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_XSL_RSVD_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_RSVD_27]

//>> SET_[FIR_REG_1_XSL_RSVD_27]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_XSL_RSVD_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_XSL_RSVD_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_XSL_RSVD_27]

//>> CLEAR_[FIR_REG_1_XSL_RSVD_27]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_XSL_RSVD_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_XSL_RSVD_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_XSL_RSVD_27]

//>> GET_[FIR_REG_1_XSL_RSVD_27]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_XSL_RSVD_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_XSL_RSVD_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_XSL_RSVD_27]

//>> GET_[FIR_REG_1_XSL_RSVD_27]
static inline bool GET_FIR_REG_1_XSL_RSVD_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_XSL_RSVD_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_XSL_RSVD_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_XSL_RSVD_27]

//>> SET_[FIR_REG_1_NDL_BRK6_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK6_STALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK6_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_NDL_BRK6_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK6_STALL]

//>> SET_[FIR_REG_1_NDL_BRK6_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK6_STALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK6_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_NDL_BRK6_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK6_STALL]

//>> SET_[FIR_REG_1_NDL_BRK6_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK6_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_NDL_BRK6_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_NDL_BRK6_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK6_STALL]

//>> CLEAR_[FIR_REG_1_NDL_BRK6_STALL]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_NDL_BRK6_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_NDL_BRK6_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_NDL_BRK6_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_NDL_BRK6_STALL]

//>> GET_[FIR_REG_1_NDL_BRK6_STALL]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_NDL_BRK6_STALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_NDL_BRK6_STALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_NDL_BRK6_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK6_STALL]

//>> GET_[FIR_REG_1_NDL_BRK6_STALL]
static inline bool GET_FIR_REG_1_NDL_BRK6_STALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_NDL_BRK6_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_NDL_BRK6_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK6_STALL]

//>> SET_[FIR_REG_1_NDL_BRK6_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK6_NOSTALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK6_NOSTALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_NDL_BRK6_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK6_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK6_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK6_NOSTALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK6_NOSTALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_NDL_BRK6_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK6_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK6_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK6_NOSTALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_NDL_BRK6_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_NDL_BRK6_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK6_NOSTALL]

//>> CLEAR_[FIR_REG_1_NDL_BRK6_NOSTALL]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_NDL_BRK6_NOSTALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_NDL_BRK6_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_NDL_BRK6_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_NDL_BRK6_NOSTALL]

//>> GET_[FIR_REG_1_NDL_BRK6_NOSTALL]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_NDL_BRK6_NOSTALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_NDL_BRK6_NOSTALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_NDL_BRK6_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK6_NOSTALL]

//>> GET_[FIR_REG_1_NDL_BRK6_NOSTALL]
static inline bool GET_FIR_REG_1_NDL_BRK6_NOSTALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_NDL_BRK6_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_NDL_BRK6_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK6_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK7_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK7_STALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK7_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_NDL_BRK7_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK7_STALL]

//>> SET_[FIR_REG_1_NDL_BRK7_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK7_STALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK7_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_NDL_BRK7_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK7_STALL]

//>> SET_[FIR_REG_1_NDL_BRK7_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK7_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_NDL_BRK7_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_NDL_BRK7_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK7_STALL]

//>> CLEAR_[FIR_REG_1_NDL_BRK7_STALL]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_NDL_BRK7_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_NDL_BRK7_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_NDL_BRK7_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_NDL_BRK7_STALL]

//>> GET_[FIR_REG_1_NDL_BRK7_STALL]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_NDL_BRK7_STALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_NDL_BRK7_STALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_NDL_BRK7_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK7_STALL]

//>> GET_[FIR_REG_1_NDL_BRK7_STALL]
static inline bool GET_FIR_REG_1_NDL_BRK7_STALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_NDL_BRK7_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_NDL_BRK7_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK7_STALL]

//>> SET_[FIR_REG_1_NDL_BRK7_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK7_NOSTALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK7_NOSTALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_NDL_BRK7_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK7_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK7_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK7_NOSTALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK7_NOSTALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_NDL_BRK7_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK7_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK7_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK7_NOSTALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_NDL_BRK7_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_NDL_BRK7_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK7_NOSTALL]

//>> CLEAR_[FIR_REG_1_NDL_BRK7_NOSTALL]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_NDL_BRK7_NOSTALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_NDL_BRK7_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_NDL_BRK7_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_NDL_BRK7_NOSTALL]

//>> GET_[FIR_REG_1_NDL_BRK7_NOSTALL]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_NDL_BRK7_NOSTALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_NDL_BRK7_NOSTALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_NDL_BRK7_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK7_NOSTALL]

//>> GET_[FIR_REG_1_NDL_BRK7_NOSTALL]
static inline bool GET_FIR_REG_1_NDL_BRK7_NOSTALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_NDL_BRK7_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_NDL_BRK7_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK7_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK8_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK8_STALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK8_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_NDL_BRK8_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK8_STALL]

//>> SET_[FIR_REG_1_NDL_BRK8_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK8_STALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK8_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_NDL_BRK8_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK8_STALL]

//>> SET_[FIR_REG_1_NDL_BRK8_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK8_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_NDL_BRK8_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_NDL_BRK8_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK8_STALL]

//>> CLEAR_[FIR_REG_1_NDL_BRK8_STALL]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_NDL_BRK8_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_NDL_BRK8_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_NDL_BRK8_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_NDL_BRK8_STALL]

//>> GET_[FIR_REG_1_NDL_BRK8_STALL]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_NDL_BRK8_STALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_NDL_BRK8_STALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_NDL_BRK8_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK8_STALL]

//>> GET_[FIR_REG_1_NDL_BRK8_STALL]
static inline bool GET_FIR_REG_1_NDL_BRK8_STALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_NDL_BRK8_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_NDL_BRK8_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK8_STALL]

//>> SET_[FIR_REG_1_NDL_BRK8_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK8_NOSTALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK8_NOSTALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_NDL_BRK8_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK8_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK8_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK8_NOSTALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK8_NOSTALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_NDL_BRK8_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK8_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK8_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK8_NOSTALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_NDL_BRK8_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_NDL_BRK8_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK8_NOSTALL]

//>> CLEAR_[FIR_REG_1_NDL_BRK8_NOSTALL]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_NDL_BRK8_NOSTALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_NDL_BRK8_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_NDL_BRK8_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_NDL_BRK8_NOSTALL]

//>> GET_[FIR_REG_1_NDL_BRK8_NOSTALL]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_NDL_BRK8_NOSTALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_NDL_BRK8_NOSTALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_NDL_BRK8_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK8_NOSTALL]

//>> GET_[FIR_REG_1_NDL_BRK8_NOSTALL]
static inline bool GET_FIR_REG_1_NDL_BRK8_NOSTALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_NDL_BRK8_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_NDL_BRK8_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK8_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK9_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK9_STALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK9_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_NDL_BRK9_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK9_STALL]

//>> SET_[FIR_REG_1_NDL_BRK9_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK9_STALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK9_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_NDL_BRK9_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK9_STALL]

//>> SET_[FIR_REG_1_NDL_BRK9_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK9_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_NDL_BRK9_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_NDL_BRK9_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK9_STALL]

//>> CLEAR_[FIR_REG_1_NDL_BRK9_STALL]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_NDL_BRK9_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_NDL_BRK9_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_NDL_BRK9_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_NDL_BRK9_STALL]

//>> GET_[FIR_REG_1_NDL_BRK9_STALL]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_NDL_BRK9_STALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_NDL_BRK9_STALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_NDL_BRK9_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK9_STALL]

//>> GET_[FIR_REG_1_NDL_BRK9_STALL]
static inline bool GET_FIR_REG_1_NDL_BRK9_STALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_NDL_BRK9_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_NDL_BRK9_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK9_STALL]

//>> SET_[FIR_REG_1_NDL_BRK9_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK9_NOSTALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK9_NOSTALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_NDL_BRK9_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK9_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK9_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK9_NOSTALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK9_NOSTALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_NDL_BRK9_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK9_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK9_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK9_NOSTALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_NDL_BRK9_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_NDL_BRK9_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK9_NOSTALL]

//>> CLEAR_[FIR_REG_1_NDL_BRK9_NOSTALL]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_NDL_BRK9_NOSTALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_NDL_BRK9_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_NDL_BRK9_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_NDL_BRK9_NOSTALL]

//>> GET_[FIR_REG_1_NDL_BRK9_NOSTALL]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_NDL_BRK9_NOSTALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_NDL_BRK9_NOSTALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_NDL_BRK9_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK9_NOSTALL]

//>> GET_[FIR_REG_1_NDL_BRK9_NOSTALL]
static inline bool GET_FIR_REG_1_NDL_BRK9_NOSTALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_NDL_BRK9_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_NDL_BRK9_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK9_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK10_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK10_STALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK10_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_NDL_BRK10_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK10_STALL]

//>> SET_[FIR_REG_1_NDL_BRK10_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK10_STALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK10_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_NDL_BRK10_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK10_STALL]

//>> SET_[FIR_REG_1_NDL_BRK10_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK10_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_NDL_BRK10_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_NDL_BRK10_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK10_STALL]

//>> CLEAR_[FIR_REG_1_NDL_BRK10_STALL]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_NDL_BRK10_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_NDL_BRK10_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_NDL_BRK10_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_NDL_BRK10_STALL]

//>> GET_[FIR_REG_1_NDL_BRK10_STALL]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_NDL_BRK10_STALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_NDL_BRK10_STALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_NDL_BRK10_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK10_STALL]

//>> GET_[FIR_REG_1_NDL_BRK10_STALL]
static inline bool GET_FIR_REG_1_NDL_BRK10_STALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_NDL_BRK10_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_NDL_BRK10_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK10_STALL]

//>> SET_[FIR_REG_1_NDL_BRK10_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK10_NOSTALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK10_NOSTALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_NDL_BRK10_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK10_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK10_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK10_NOSTALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK10_NOSTALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_NDL_BRK10_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK10_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK10_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK10_NOSTALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_NDL_BRK10_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_NDL_BRK10_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK10_NOSTALL]

//>> CLEAR_[FIR_REG_1_NDL_BRK10_NOSTALL]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_NDL_BRK10_NOSTALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_NDL_BRK10_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_NDL_BRK10_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_NDL_BRK10_NOSTALL]

//>> GET_[FIR_REG_1_NDL_BRK10_NOSTALL]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_NDL_BRK10_NOSTALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_NDL_BRK10_NOSTALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_NDL_BRK10_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK10_NOSTALL]

//>> GET_[FIR_REG_1_NDL_BRK10_NOSTALL]
static inline bool GET_FIR_REG_1_NDL_BRK10_NOSTALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_NDL_BRK10_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_NDL_BRK10_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK10_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK11_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK11_STALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK11_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_NDL_BRK11_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK11_STALL]

//>> SET_[FIR_REG_1_NDL_BRK11_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK11_STALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK11_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_NDL_BRK11_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK11_STALL]

//>> SET_[FIR_REG_1_NDL_BRK11_STALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK11_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_NDL_BRK11_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_NDL_BRK11_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK11_STALL]

//>> CLEAR_[FIR_REG_1_NDL_BRK11_STALL]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_NDL_BRK11_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_NDL_BRK11_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_NDL_BRK11_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_NDL_BRK11_STALL]

//>> GET_[FIR_REG_1_NDL_BRK11_STALL]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_NDL_BRK11_STALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_NDL_BRK11_STALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_NDL_BRK11_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK11_STALL]

//>> GET_[FIR_REG_1_NDL_BRK11_STALL]
static inline bool GET_FIR_REG_1_NDL_BRK11_STALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_NDL_BRK11_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_NDL_BRK11_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK11_STALL]

//>> SET_[FIR_REG_1_NDL_BRK11_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK11_NOSTALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK11_NOSTALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_NDL_BRK11_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK11_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK11_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK11_NOSTALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_NDL_BRK11_NOSTALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_NDL_BRK11_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK11_NOSTALL]

//>> SET_[FIR_REG_1_NDL_BRK11_NOSTALL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_NDL_BRK11_NOSTALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_NDL_BRK11_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_NDL_BRK11_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_NDL_BRK11_NOSTALL]

//>> CLEAR_[FIR_REG_1_NDL_BRK11_NOSTALL]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_NDL_BRK11_NOSTALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_NDL_BRK11_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_NDL_BRK11_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_NDL_BRK11_NOSTALL]

//>> GET_[FIR_REG_1_NDL_BRK11_NOSTALL]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_NDL_BRK11_NOSTALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_NDL_BRK11_NOSTALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_NDL_BRK11_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK11_NOSTALL]

//>> GET_[FIR_REG_1_NDL_BRK11_NOSTALL]
static inline bool GET_FIR_REG_1_NDL_BRK11_NOSTALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_NDL_BRK11_NOSTALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_NDL_BRK11_NOSTALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_NDL_BRK11_NOSTALL]

//>> SET_[FIR_REG_1_AME_RSVD_2]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_AME_RSVD_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_AME_RSVD_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_AME_RSVD_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_AME_RSVD_2]

//>> SET_[FIR_REG_1_AME_RSVD_2]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_AME_RSVD_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_AME_RSVD_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_AME_RSVD_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_AME_RSVD_2]

//>> SET_[FIR_REG_1_AME_RSVD_2]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_AME_RSVD_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_AME_RSVD_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_AME_RSVD_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_AME_RSVD_2]

//>> CLEAR_[FIR_REG_1_AME_RSVD_2]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_AME_RSVD_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_AME_RSVD_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_AME_RSVD_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_AME_RSVD_2]

//>> GET_[FIR_REG_1_AME_RSVD_2]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_AME_RSVD_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_AME_RSVD_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_AME_RSVD_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_AME_RSVD_2]

//>> GET_[FIR_REG_1_AME_RSVD_2]
static inline bool GET_FIR_REG_1_AME_RSVD_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_AME_RSVD_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_AME_RSVD_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_AME_RSVD_2]

//>> SET_[FIR_REG_1_SCOMSAT00_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_SCOMSAT00_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_SCOMSAT00_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_SCOMSAT00_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_SCOMSAT00_ERR]

//>> SET_[FIR_REG_1_SCOMSAT00_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_SCOMSAT00_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_SCOMSAT00_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_SCOMSAT00_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_SCOMSAT00_ERR]

//>> SET_[FIR_REG_1_SCOMSAT00_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_SCOMSAT00_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_SCOMSAT00_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_SCOMSAT00_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_SCOMSAT00_ERR]

//>> CLEAR_[FIR_REG_1_SCOMSAT00_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_SCOMSAT00_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_SCOMSAT00_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_SCOMSAT00_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_SCOMSAT00_ERR]

//>> GET_[FIR_REG_1_SCOMSAT00_ERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_SCOMSAT00_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_SCOMSAT00_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_SCOMSAT00_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_SCOMSAT00_ERR]

//>> GET_[FIR_REG_1_SCOMSAT00_ERR]
static inline bool GET_FIR_REG_1_SCOMSAT00_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_SCOMSAT00_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_SCOMSAT00_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_SCOMSAT00_ERR]

//>> SET_[FIR_REG_1_SCOMSAT01_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_SCOMSAT01_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_SCOMSAT01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_SCOMSAT01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_SCOMSAT01_ERR]

//>> SET_[FIR_REG_1_SCOMSAT01_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_SCOMSAT01_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_SCOMSAT01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_SCOMSAT01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_SCOMSAT01_ERR]

//>> SET_[FIR_REG_1_SCOMSAT01_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_SCOMSAT01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_SCOMSAT01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_SCOMSAT01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_SCOMSAT01_ERR]

//>> CLEAR_[FIR_REG_1_SCOMSAT01_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_SCOMSAT01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_SCOMSAT01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_SCOMSAT01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_SCOMSAT01_ERR]

//>> GET_[FIR_REG_1_SCOMSAT01_ERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_SCOMSAT01_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_SCOMSAT01_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_SCOMSAT01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_SCOMSAT01_ERR]

//>> GET_[FIR_REG_1_SCOMSAT01_ERR]
static inline bool GET_FIR_REG_1_SCOMSAT01_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_SCOMSAT01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_SCOMSAT01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_SCOMSAT01_ERR]

//>> SET_[FIR_REG_1_FIR1_RSVD_62]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_FIR1_RSVD_62(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_FIR1_RSVD_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_FIR1_RSVD_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_FIR1_RSVD_62]

//>> SET_[FIR_REG_1_FIR1_RSVD_62]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_FIR1_RSVD_62(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_FIR1_RSVD_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_FIR1_RSVD_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_FIR1_RSVD_62]

//>> SET_[FIR_REG_1_FIR1_RSVD_62]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_FIR1_RSVD_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_FIR1_RSVD_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_FIR1_RSVD_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_FIR1_RSVD_62]

//>> CLEAR_[FIR_REG_1_FIR1_RSVD_62]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_FIR1_RSVD_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_FIR1_RSVD_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_FIR1_RSVD_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_FIR1_RSVD_62]

//>> GET_[FIR_REG_1_FIR1_RSVD_62]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_FIR1_RSVD_62(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_FIR1_RSVD_62,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_FIR1_RSVD_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_FIR1_RSVD_62]

//>> GET_[FIR_REG_1_FIR1_RSVD_62]
static inline bool GET_FIR_REG_1_FIR1_RSVD_62(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_FIR1_RSVD_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_FIR1_RSVD_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_FIR1_RSVD_62]

//>> SET_[FIR_REG_1_FIR1_RSVD_63]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_FIR1_RSVD_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_FIR1_RSVD_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_1_FIR1_RSVD_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_FIR1_RSVD_63]

//>> SET_[FIR_REG_1_FIR1_RSVD_63]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_FIR1_RSVD_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_1_FIR1_RSVD_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_1_FIR1_RSVD_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_FIR1_RSVD_63]

//>> SET_[FIR_REG_1_FIR1_RSVD_63]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_1_FIR1_RSVD_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.setBit<FIR_REG_1_FIR1_RSVD_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_1_FIR1_RSVD_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_1_FIR1_RSVD_63]

//>> CLEAR_[FIR_REG_1_FIR1_RSVD_63]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_1_FIR1_RSVD_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_1_FIR1_RSVD_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_1_FIR1_RSVD_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_1_FIR1_RSVD_63]

//>> GET_[FIR_REG_1_FIR1_RSVD_63]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_1_FIR1_RSVD_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_1_FIR1_RSVD_63,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_1_FIR1_RSVD_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_FIR1_RSVD_63]

//>> GET_[FIR_REG_1_FIR1_RSVD_63]
static inline bool GET_FIR_REG_1_FIR1_RSVD_63(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_1_RW, FIR_REG_1_WO_AND, FIR_REG_1_WO_OR));
#endif
    return i_data.getBit<FIR_REG_1_FIR1_RSVD_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_1_FIR1_RSVD_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_1_FIR1_RSVD_63]

//>> PREP_[XSL_MAIN_GPU0_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSL_MAIN_GPU0_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSL_MAIN_GPU0_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[XSL_MAIN_GPU0_BAR]

//>> GET_[XSL_MAIN_GPU0_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSL_MAIN_GPU0_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSL_MAIN_GPU0_BAR;
#endif
    return fapi2::getScom(i_target, XSL_MAIN_GPU0_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR]

//>> PUT_[XSL_MAIN_GPU0_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSL_MAIN_GPU0_BAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return fapi2::putScom(i_target, XSL_MAIN_GPU0_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[XSL_MAIN_GPU0_BAR]


//>> SET_[XSL_MAIN_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_ENABLE]

//>> SET_[XSL_MAIN_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_ENABLE]

//>> SET_[XSL_MAIN_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU0_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_ENABLE]

//>> CLEAR_[XSL_MAIN_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU0_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU0_BAR_ENABLE]

//>> GET_[XSL_MAIN_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_ENABLE]

//>> GET_[XSL_MAIN_GPU0_BAR_ENABLE]
static inline bool GET_XSL_MAIN_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU0_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_ENABLE]

//>> SET_[XSL_MAIN_GPU0_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_ADDR_MASK,
           XSL_MAIN_GPU0_BAR_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_ADDR_MASK]

//>> SET_[XSL_MAIN_GPU0_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_ADDR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_ADDR_MASK,
           XSL_MAIN_GPU0_BAR_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_ADDR_MASK]

//>> GET_[XSL_MAIN_GPU0_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_ADDR_MASK,
           XSL_MAIN_GPU0_BAR_ADDR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_ADDR_MASK]

//>> SET_[XSL_MAIN_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_SL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_SL_MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_SL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_SL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_SL_MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU0_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_SL_MODE]

//>> CLEAR_[XSL_MAIN_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU0_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU0_BAR_SL_MODE]

//>> GET_[XSL_MAIN_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_SL_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_SL_MODE]

//>> GET_[XSL_MAIN_GPU0_BAR_SL_MODE]
static inline bool GET_XSL_MAIN_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU0_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_SL_MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_4T_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_4T_LIMIT]

//>> SET_[XSL_MAIN_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_4T_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_4T_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_4T_LIMIT]

//>> SET_[XSL_MAIN_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU0_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_4T_LIMIT]

//>> CLEAR_[XSL_MAIN_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU0_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU0_BAR_4T_LIMIT]

//>> GET_[XSL_MAIN_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_4T_LIMIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_4T_LIMIT]

//>> GET_[XSL_MAIN_GPU0_BAR_4T_LIMIT]
static inline bool GET_XSL_MAIN_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU0_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_4T_LIMIT]

//>> SET_[XSL_MAIN_GPU0_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_4T_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_4T_SELECT,
           XSL_MAIN_GPU0_BAR_4T_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_4T_SELECT]

//>> SET_[XSL_MAIN_GPU0_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_4T_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_4T_SELECT,
           XSL_MAIN_GPU0_BAR_4T_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_4T_SELECT]

//>> GET_[XSL_MAIN_GPU0_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_4T_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_4T_SELECT,
           XSL_MAIN_GPU0_BAR_4T_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_4T_SELECT]

//>> SET_[XSL_MAIN_GPU0_BAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_MODE,
           XSL_MAIN_GPU0_BAR_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_MODE,
           XSL_MAIN_GPU0_BAR_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_MODE]

//>> GET_[XSL_MAIN_GPU0_BAR_MODE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_MODE,
           XSL_MAIN_GPU0_BAR_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_GRANULE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_GRANULE]

//>> SET_[XSL_MAIN_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_GRANULE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_GRANULE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_GRANULE]

//>> SET_[XSL_MAIN_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU0_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_GRANULE]

//>> CLEAR_[XSL_MAIN_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU0_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU0_BAR_GRANULE]

//>> GET_[XSL_MAIN_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_GRANULE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_GRANULE]

//>> GET_[XSL_MAIN_GPU0_BAR_GRANULE]
static inline bool GET_XSL_MAIN_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU0_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_GRANULE]

//>> SET_[XSL_MAIN_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_POISON]

//>> SET_[XSL_MAIN_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_POISON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_POISON]

//>> SET_[XSL_MAIN_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU0_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_POISON]

//>> CLEAR_[XSL_MAIN_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU0_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU0_BAR_POISON]

//>> GET_[XSL_MAIN_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_POISON,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_POISON]

//>> GET_[XSL_MAIN_GPU0_BAR_POISON]
static inline bool GET_XSL_MAIN_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU0_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_POISON]

//>> SET_[XSL_MAIN_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_M2MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_M2MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_M2MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_M2MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_M2MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU0_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_M2MODE]

//>> CLEAR_[XSL_MAIN_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU0_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU0_BAR_M2MODE]

//>> GET_[XSL_MAIN_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_M2MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_M2MODE]

//>> GET_[XSL_MAIN_GPU0_BAR_M2MODE]
static inline bool GET_XSL_MAIN_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU0_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_M2MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE]

//>> CLEAR_[XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE]

//>> GET_[XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE]

//>> GET_[XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE]
static inline bool GET_XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_SECURE_A12]

//>> SET_[XSL_MAIN_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_SECURE_A12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_SECURE_A12]

//>> SET_[XSL_MAIN_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU0_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_SECURE_A12]

//>> CLEAR_[XSL_MAIN_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU0_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU0_BAR_SECURE_A12]

//>> GET_[XSL_MAIN_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_SECURE_A12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_SECURE_A12]

//>> GET_[XSL_MAIN_GPU0_BAR_SECURE_A12]
static inline bool GET_XSL_MAIN_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU0_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_SECURE_A12]

//>> SET_[XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP]

//>> SET_[XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP]

//>> SET_[XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP]

//>> CLEAR_[XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP]

//>> GET_[XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP]

//>> GET_[XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP]
static inline bool GET_XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP]

//>> SET_[XSL_MAIN_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_EXTENDED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_EXTENDED_MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_EXTENDED_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_EXTENDED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_EXTENDED_MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU0_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_EXTENDED_MODE]

//>> CLEAR_[XSL_MAIN_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU0_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU0_BAR_EXTENDED_MODE]

//>> GET_[XSL_MAIN_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_EXTENDED_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_EXTENDED_MODE]

//>> GET_[XSL_MAIN_GPU0_BAR_EXTENDED_MODE]
static inline bool GET_XSL_MAIN_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU0_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_EXTENDED_MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_RESERVED]

//>> SET_[XSL_MAIN_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_RESERVED]

//>> SET_[XSL_MAIN_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU0_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_RESERVED]

//>> CLEAR_[XSL_MAIN_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU0_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU0_BAR_RESERVED]

//>> GET_[XSL_MAIN_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_RESERVED]

//>> GET_[XSL_MAIN_GPU0_BAR_RESERVED]
static inline bool GET_XSL_MAIN_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU0_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_RESERVED]

//>> PREP_[XSL_MAIN_GPU1_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSL_MAIN_GPU1_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSL_MAIN_GPU1_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[XSL_MAIN_GPU1_BAR]

//>> GET_[XSL_MAIN_GPU1_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSL_MAIN_GPU1_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSL_MAIN_GPU1_BAR;
#endif
    return fapi2::getScom(i_target, XSL_MAIN_GPU1_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR]

//>> PUT_[XSL_MAIN_GPU1_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSL_MAIN_GPU1_BAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return fapi2::putScom(i_target, XSL_MAIN_GPU1_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[XSL_MAIN_GPU1_BAR]


//>> SET_[XSL_MAIN_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_ENABLE]

//>> SET_[XSL_MAIN_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_ENABLE]

//>> SET_[XSL_MAIN_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU1_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_ENABLE]

//>> CLEAR_[XSL_MAIN_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU1_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU1_BAR_ENABLE]

//>> GET_[XSL_MAIN_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_ENABLE]

//>> GET_[XSL_MAIN_GPU1_BAR_ENABLE]
static inline bool GET_XSL_MAIN_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU1_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_ENABLE]

//>> SET_[XSL_MAIN_GPU1_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_ADDR_MASK,
           XSL_MAIN_GPU1_BAR_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_ADDR_MASK]

//>> SET_[XSL_MAIN_GPU1_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_ADDR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_ADDR_MASK,
           XSL_MAIN_GPU1_BAR_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_ADDR_MASK]

//>> GET_[XSL_MAIN_GPU1_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_ADDR_MASK,
           XSL_MAIN_GPU1_BAR_ADDR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_ADDR_MASK]

//>> SET_[XSL_MAIN_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_SL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_SL_MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_SL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_SL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_SL_MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU1_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_SL_MODE]

//>> CLEAR_[XSL_MAIN_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU1_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU1_BAR_SL_MODE]

//>> GET_[XSL_MAIN_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_SL_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_SL_MODE]

//>> GET_[XSL_MAIN_GPU1_BAR_SL_MODE]
static inline bool GET_XSL_MAIN_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU1_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_SL_MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_4T_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_4T_LIMIT]

//>> SET_[XSL_MAIN_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_4T_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_4T_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_4T_LIMIT]

//>> SET_[XSL_MAIN_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU1_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_4T_LIMIT]

//>> CLEAR_[XSL_MAIN_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU1_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU1_BAR_4T_LIMIT]

//>> GET_[XSL_MAIN_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_4T_LIMIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_4T_LIMIT]

//>> GET_[XSL_MAIN_GPU1_BAR_4T_LIMIT]
static inline bool GET_XSL_MAIN_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU1_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_4T_LIMIT]

//>> SET_[XSL_MAIN_GPU1_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_4T_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_4T_SELECT,
           XSL_MAIN_GPU1_BAR_4T_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_4T_SELECT]

//>> SET_[XSL_MAIN_GPU1_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_4T_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_4T_SELECT,
           XSL_MAIN_GPU1_BAR_4T_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_4T_SELECT]

//>> GET_[XSL_MAIN_GPU1_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_4T_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_4T_SELECT,
           XSL_MAIN_GPU1_BAR_4T_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_4T_SELECT]

//>> SET_[XSL_MAIN_GPU1_BAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_MODE,
           XSL_MAIN_GPU1_BAR_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_MODE,
           XSL_MAIN_GPU1_BAR_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_MODE]

//>> GET_[XSL_MAIN_GPU1_BAR_MODE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_MODE,
           XSL_MAIN_GPU1_BAR_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_GRANULE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_GRANULE]

//>> SET_[XSL_MAIN_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_GRANULE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_GRANULE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_GRANULE]

//>> SET_[XSL_MAIN_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU1_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_GRANULE]

//>> CLEAR_[XSL_MAIN_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU1_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU1_BAR_GRANULE]

//>> GET_[XSL_MAIN_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_GRANULE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_GRANULE]

//>> GET_[XSL_MAIN_GPU1_BAR_GRANULE]
static inline bool GET_XSL_MAIN_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU1_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_GRANULE]

//>> SET_[XSL_MAIN_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_POISON]

//>> SET_[XSL_MAIN_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_POISON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_POISON]

//>> SET_[XSL_MAIN_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU1_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_POISON]

//>> CLEAR_[XSL_MAIN_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU1_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU1_BAR_POISON]

//>> GET_[XSL_MAIN_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_POISON,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_POISON]

//>> GET_[XSL_MAIN_GPU1_BAR_POISON]
static inline bool GET_XSL_MAIN_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU1_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_POISON]

//>> SET_[XSL_MAIN_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_M2MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_M2MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_M2MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_M2MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_M2MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU1_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_M2MODE]

//>> CLEAR_[XSL_MAIN_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU1_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU1_BAR_M2MODE]

//>> GET_[XSL_MAIN_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_M2MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_M2MODE]

//>> GET_[XSL_MAIN_GPU1_BAR_M2MODE]
static inline bool GET_XSL_MAIN_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU1_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_M2MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE]

//>> CLEAR_[XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE]

//>> GET_[XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE]

//>> GET_[XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE]
static inline bool GET_XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_SECURE_A12]

//>> SET_[XSL_MAIN_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_SECURE_A12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_SECURE_A12]

//>> SET_[XSL_MAIN_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU1_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_SECURE_A12]

//>> CLEAR_[XSL_MAIN_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU1_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU1_BAR_SECURE_A12]

//>> GET_[XSL_MAIN_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_SECURE_A12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_SECURE_A12]

//>> GET_[XSL_MAIN_GPU1_BAR_SECURE_A12]
static inline bool GET_XSL_MAIN_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU1_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_SECURE_A12]

//>> SET_[XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP]

//>> SET_[XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP]

//>> SET_[XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP]

//>> CLEAR_[XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP]

//>> GET_[XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP]

//>> GET_[XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP]
static inline bool GET_XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP]

//>> SET_[XSL_MAIN_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_EXTENDED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_EXTENDED_MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_EXTENDED_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_EXTENDED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_EXTENDED_MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU1_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_EXTENDED_MODE]

//>> CLEAR_[XSL_MAIN_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU1_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU1_BAR_EXTENDED_MODE]

//>> GET_[XSL_MAIN_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_EXTENDED_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_EXTENDED_MODE]

//>> GET_[XSL_MAIN_GPU1_BAR_EXTENDED_MODE]
static inline bool GET_XSL_MAIN_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU1_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_EXTENDED_MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_RESERVED]

//>> SET_[XSL_MAIN_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_RESERVED]

//>> SET_[XSL_MAIN_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU1_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_RESERVED]

//>> CLEAR_[XSL_MAIN_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU1_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU1_BAR_RESERVED]

//>> GET_[XSL_MAIN_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_RESERVED]

//>> GET_[XSL_MAIN_GPU1_BAR_RESERVED]
static inline bool GET_XSL_MAIN_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU1_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_RESERVED]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
