/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/nmmu/reg00010.H $         */
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

#ifndef __NMMU_REG00010_H_
#define __NMMU_REG00010_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace nmmu
{
#endif


//>> PREP_[FIR1_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FIR1_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR1_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FIR1_REG_RW]

//>> GET_[FIR1_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FIR1_REG_RW(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR1_REG_RW;
#endif
    return fapi2::getScom(i_target, FIR1_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FIR1_REG_RW]

//>> PUT_[FIR1_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FIR1_REG_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, FIR1_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FIR1_REG_RW]

//>> PREP_[FIR1_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FIR1_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR1_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FIR1_REG_WO_AND]

//>> GET_[FIR1_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FIR1_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR1_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, FIR1_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FIR1_REG_WO_AND]

//>> PUT_[FIR1_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FIR1_REG_WO_AND(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, FIR1_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FIR1_REG_WO_AND]

//>> PREP_[FIR1_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FIR1_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR1_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FIR1_REG_WO_OR]

//>> GET_[FIR1_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FIR1_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR1_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, FIR1_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FIR1_REG_WO_OR]

//>> PUT_[FIR1_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FIR1_REG_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, FIR1_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FIR1_REG_WO_OR]


//>> SET_[FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET]

//>> SET_[FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET]

//>> SET_[FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET]

//>> CLEAR_[FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET]

//>> GET_[FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET]

//>> GET_[FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET]
static inline bool GET_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET]

//>> SET_[FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET]

//>> SET_[FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET]

//>> SET_[FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET]

//>> CLEAR_[FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET]

//>> GET_[FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET]

//>> GET_[FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET]
static inline bool GET_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET]

//>> SET_[FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET]

//>> SET_[FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET]

//>> SET_[FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET]

//>> CLEAR_[FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET]

//>> GET_[FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET]

//>> GET_[FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET]
static inline bool GET_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET]

//>> SET_[FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET]

//>> SET_[FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET]

//>> SET_[FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET]

//>> CLEAR_[FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET]

//>> GET_[FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET]

//>> GET_[FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET]
static inline bool GET_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET]

//>> SET_[FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET]

//>> SET_[FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET]

//>> SET_[FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET]

//>> CLEAR_[FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET]

//>> GET_[FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET]

//>> GET_[FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET]
static inline bool GET_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET]

//>> SET_[FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET]

//>> SET_[FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET]

//>> SET_[FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET]

//>> CLEAR_[FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET]

//>> GET_[FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET]

//>> GET_[FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET]
static inline bool GET_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET]

//>> SET_[FIR1_REG_FBC_XLAT_PROT_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_PROT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_XLAT_PROT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_PROT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_FBC_XLAT_PROT_ERR_DET]

//>> SET_[FIR1_REG_FBC_XLAT_PROT_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_PROT_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_XLAT_PROT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_PROT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_FBC_XLAT_PROT_ERR_DET]

//>> SET_[FIR1_REG_FBC_XLAT_PROT_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_PROT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_FBC_XLAT_PROT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_PROT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_FBC_XLAT_PROT_ERR_DET]

//>> CLEAR_[FIR1_REG_FBC_XLAT_PROT_ERR_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_FBC_XLAT_PROT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_FBC_XLAT_PROT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_PROT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_FBC_XLAT_PROT_ERR_DET]

//>> GET_[FIR1_REG_FBC_XLAT_PROT_ERR_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_FBC_XLAT_PROT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_FBC_XLAT_PROT_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_PROT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_FBC_XLAT_PROT_ERR_DET]

//>> GET_[FIR1_REG_FBC_XLAT_PROT_ERR_DET]
static inline bool GET_FIR1_REG_FBC_XLAT_PROT_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_FBC_XLAT_PROT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_PROT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_FBC_XLAT_PROT_ERR_DET]

//>> SET_[FIR1_REG_FBC_XLAT_TIMEOUT_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_TIMEOUT_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_XLAT_TIMEOUT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_TIMEOUT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_FBC_XLAT_TIMEOUT_DET]

//>> SET_[FIR1_REG_FBC_XLAT_TIMEOUT_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_TIMEOUT_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_XLAT_TIMEOUT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_TIMEOUT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_FBC_XLAT_TIMEOUT_DET]

//>> SET_[FIR1_REG_FBC_XLAT_TIMEOUT_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_TIMEOUT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_FBC_XLAT_TIMEOUT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_TIMEOUT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_FBC_XLAT_TIMEOUT_DET]

//>> CLEAR_[FIR1_REG_FBC_XLAT_TIMEOUT_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_FBC_XLAT_TIMEOUT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_FBC_XLAT_TIMEOUT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_TIMEOUT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_FBC_XLAT_TIMEOUT_DET]

//>> GET_[FIR1_REG_FBC_XLAT_TIMEOUT_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_FBC_XLAT_TIMEOUT_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_FBC_XLAT_TIMEOUT_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_TIMEOUT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_FBC_XLAT_TIMEOUT_DET]

//>> GET_[FIR1_REG_FBC_XLAT_TIMEOUT_DET]
static inline bool GET_FIR1_REG_FBC_XLAT_TIMEOUT_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_FBC_XLAT_TIMEOUT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_FBC_XLAT_TIMEOUT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_FBC_XLAT_TIMEOUT_DET]

//>> SET_[FIR1_REG_SLB_DIR_PERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_SLB_DIR_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_SLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_SLB_DIR_PERR_DET]

//>> SET_[FIR1_REG_SLB_DIR_PERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SLB_DIR_PERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_SLB_DIR_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_SLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_SLB_DIR_PERR_DET]

//>> SET_[FIR1_REG_SLB_DIR_PERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_SLB_DIR_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_SLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_SLB_DIR_PERR_DET]

//>> CLEAR_[FIR1_REG_SLB_DIR_PERR_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_SLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_SLB_DIR_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_SLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_SLB_DIR_PERR_DET]

//>> GET_[FIR1_REG_SLB_DIR_PERR_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_SLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_SLB_DIR_PERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_SLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_SLB_DIR_PERR_DET]

//>> GET_[FIR1_REG_SLB_DIR_PERR_DET]
static inline bool GET_FIR1_REG_SLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_SLB_DIR_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_SLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_SLB_DIR_PERR_DET]

//>> SET_[FIR1_REG_SLB_CAC_PERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_SLB_CAC_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_SLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_SLB_CAC_PERR_DET]

//>> SET_[FIR1_REG_SLB_CAC_PERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SLB_CAC_PERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_SLB_CAC_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_SLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_SLB_CAC_PERR_DET]

//>> SET_[FIR1_REG_SLB_CAC_PERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_SLB_CAC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_SLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_SLB_CAC_PERR_DET]

//>> CLEAR_[FIR1_REG_SLB_CAC_PERR_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_SLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_SLB_CAC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_SLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_SLB_CAC_PERR_DET]

//>> GET_[FIR1_REG_SLB_CAC_PERR_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_SLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_SLB_CAC_PERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_SLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_SLB_CAC_PERR_DET]

//>> GET_[FIR1_REG_SLB_CAC_PERR_DET]
static inline bool GET_FIR1_REG_SLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_SLB_CAC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_SLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_SLB_CAC_PERR_DET]

//>> SET_[FIR1_REG_SLB_LRU_PERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_SLB_LRU_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_SLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_SLB_LRU_PERR_DET]

//>> SET_[FIR1_REG_SLB_LRU_PERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SLB_LRU_PERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_SLB_LRU_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_SLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_SLB_LRU_PERR_DET]

//>> SET_[FIR1_REG_SLB_LRU_PERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_SLB_LRU_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_SLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_SLB_LRU_PERR_DET]

//>> CLEAR_[FIR1_REG_SLB_LRU_PERR_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_SLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_SLB_LRU_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_SLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_SLB_LRU_PERR_DET]

//>> GET_[FIR1_REG_SLB_LRU_PERR_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_SLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_SLB_LRU_PERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_SLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_SLB_LRU_PERR_DET]

//>> GET_[FIR1_REG_SLB_LRU_PERR_DET]
static inline bool GET_FIR1_REG_SLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_SLB_LRU_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_SLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_SLB_LRU_PERR_DET]

//>> SET_[FIR1_REG_SLB_MULTIHIT_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_SLB_MULTIHIT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_SLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_SLB_MULTIHIT_DET]

//>> SET_[FIR1_REG_SLB_MULTIHIT_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SLB_MULTIHIT_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_SLB_MULTIHIT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_SLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_SLB_MULTIHIT_DET]

//>> SET_[FIR1_REG_SLB_MULTIHIT_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_SLB_MULTIHIT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_SLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_SLB_MULTIHIT_DET]

//>> CLEAR_[FIR1_REG_SLB_MULTIHIT_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_SLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_SLB_MULTIHIT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_SLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_SLB_MULTIHIT_DET]

//>> GET_[FIR1_REG_SLB_MULTIHIT_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_SLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_SLB_MULTIHIT_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_SLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_SLB_MULTIHIT_DET]

//>> GET_[FIR1_REG_SLB_MULTIHIT_DET]
static inline bool GET_FIR1_REG_SLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_SLB_MULTIHIT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_SLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_SLB_MULTIHIT_DET]

//>> SET_[FIR1_REG_TLB_DIR_PERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TLB_DIR_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_TLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TLB_DIR_PERR_DET]

//>> SET_[FIR1_REG_TLB_DIR_PERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TLB_DIR_PERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TLB_DIR_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_TLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TLB_DIR_PERR_DET]

//>> SET_[FIR1_REG_TLB_DIR_PERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_TLB_DIR_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_TLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TLB_DIR_PERR_DET]

//>> CLEAR_[FIR1_REG_TLB_DIR_PERR_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_TLB_DIR_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_TLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_TLB_DIR_PERR_DET]

//>> GET_[FIR1_REG_TLB_DIR_PERR_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TLB_DIR_PERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_TLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TLB_DIR_PERR_DET]

//>> GET_[FIR1_REG_TLB_DIR_PERR_DET]
static inline bool GET_FIR1_REG_TLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_TLB_DIR_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_TLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TLB_DIR_PERR_DET]

//>> SET_[FIR1_REG_TLB_CAC_PERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TLB_CAC_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_TLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TLB_CAC_PERR_DET]

//>> SET_[FIR1_REG_TLB_CAC_PERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TLB_CAC_PERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TLB_CAC_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_TLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TLB_CAC_PERR_DET]

//>> SET_[FIR1_REG_TLB_CAC_PERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_TLB_CAC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_TLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TLB_CAC_PERR_DET]

//>> CLEAR_[FIR1_REG_TLB_CAC_PERR_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_TLB_CAC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_TLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_TLB_CAC_PERR_DET]

//>> GET_[FIR1_REG_TLB_CAC_PERR_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TLB_CAC_PERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_TLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TLB_CAC_PERR_DET]

//>> GET_[FIR1_REG_TLB_CAC_PERR_DET]
static inline bool GET_FIR1_REG_TLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_TLB_CAC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_TLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TLB_CAC_PERR_DET]

//>> SET_[FIR1_REG_TLB_LRU_PERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TLB_LRU_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_TLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TLB_LRU_PERR_DET]

//>> SET_[FIR1_REG_TLB_LRU_PERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TLB_LRU_PERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TLB_LRU_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_TLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TLB_LRU_PERR_DET]

//>> SET_[FIR1_REG_TLB_LRU_PERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_TLB_LRU_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_TLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TLB_LRU_PERR_DET]

//>> CLEAR_[FIR1_REG_TLB_LRU_PERR_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_TLB_LRU_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_TLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_TLB_LRU_PERR_DET]

//>> GET_[FIR1_REG_TLB_LRU_PERR_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TLB_LRU_PERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_TLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TLB_LRU_PERR_DET]

//>> GET_[FIR1_REG_TLB_LRU_PERR_DET]
static inline bool GET_FIR1_REG_TLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_TLB_LRU_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_TLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TLB_LRU_PERR_DET]

//>> SET_[FIR1_REG_TLB_MULTIHIT_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TLB_MULTIHIT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_TLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TLB_MULTIHIT_DET]

//>> SET_[FIR1_REG_TLB_MULTIHIT_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TLB_MULTIHIT_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TLB_MULTIHIT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_TLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TLB_MULTIHIT_DET]

//>> SET_[FIR1_REG_TLB_MULTIHIT_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_TLB_MULTIHIT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_TLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TLB_MULTIHIT_DET]

//>> CLEAR_[FIR1_REG_TLB_MULTIHIT_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_TLB_MULTIHIT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_TLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_TLB_MULTIHIT_DET]

//>> GET_[FIR1_REG_TLB_MULTIHIT_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TLB_MULTIHIT_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_TLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TLB_MULTIHIT_DET]

//>> GET_[FIR1_REG_TLB_MULTIHIT_DET]
static inline bool GET_FIR1_REG_TLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_TLB_MULTIHIT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_TLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TLB_MULTIHIT_DET]

//>> SET_[FIR1_REG_TW_SEG_FAULT_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_SEG_FAULT_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_SEG_FAULT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_TW_SEG_FAULT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_SEG_FAULT_DET]

//>> SET_[FIR1_REG_TW_SEG_FAULT_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_SEG_FAULT_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_SEG_FAULT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_TW_SEG_FAULT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_SEG_FAULT_DET]

//>> SET_[FIR1_REG_TW_SEG_FAULT_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_SEG_FAULT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_SEG_FAULT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_TW_SEG_FAULT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_SEG_FAULT_DET]

//>> CLEAR_[FIR1_REG_TW_SEG_FAULT_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_SEG_FAULT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_SEG_FAULT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_TW_SEG_FAULT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_TW_SEG_FAULT_DET]

//>> GET_[FIR1_REG_TW_SEG_FAULT_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_SEG_FAULT_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_SEG_FAULT_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_TW_SEG_FAULT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_SEG_FAULT_DET]

//>> GET_[FIR1_REG_TW_SEG_FAULT_DET]
static inline bool GET_FIR1_REG_TW_SEG_FAULT_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_SEG_FAULT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_TW_SEG_FAULT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_SEG_FAULT_DET]

//>> SET_[FIR1_REG_TW_PG_FAULT_NOPTE_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PG_FAULT_NOPTE_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_PG_FAULT_NOPTE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_TW_PG_FAULT_NOPTE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_PG_FAULT_NOPTE_DET]

//>> SET_[FIR1_REG_TW_PG_FAULT_NOPTE_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PG_FAULT_NOPTE_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_PG_FAULT_NOPTE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_TW_PG_FAULT_NOPTE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_PG_FAULT_NOPTE_DET]

//>> SET_[FIR1_REG_TW_PG_FAULT_NOPTE_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PG_FAULT_NOPTE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_PG_FAULT_NOPTE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_TW_PG_FAULT_NOPTE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_PG_FAULT_NOPTE_DET]

//>> CLEAR_[FIR1_REG_TW_PG_FAULT_NOPTE_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_PG_FAULT_NOPTE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_PG_FAULT_NOPTE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_TW_PG_FAULT_NOPTE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_TW_PG_FAULT_NOPTE_DET]

//>> GET_[FIR1_REG_TW_PG_FAULT_NOPTE_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_PG_FAULT_NOPTE_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_PG_FAULT_NOPTE_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_TW_PG_FAULT_NOPTE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_PG_FAULT_NOPTE_DET]

//>> GET_[FIR1_REG_TW_PG_FAULT_NOPTE_DET]
static inline bool GET_FIR1_REG_TW_PG_FAULT_NOPTE_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_PG_FAULT_NOPTE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_TW_PG_FAULT_NOPTE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_PG_FAULT_NOPTE_DET]

//>> SET_[FIR1_REG_TW_PG_FAULT_BPCHK_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PG_FAULT_BPCHK_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_PG_FAULT_BPCHK_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_TW_PG_FAULT_BPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_PG_FAULT_BPCHK_DET]

//>> SET_[FIR1_REG_TW_PG_FAULT_BPCHK_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PG_FAULT_BPCHK_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_PG_FAULT_BPCHK_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_TW_PG_FAULT_BPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_PG_FAULT_BPCHK_DET]

//>> SET_[FIR1_REG_TW_PG_FAULT_BPCHK_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PG_FAULT_BPCHK_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_PG_FAULT_BPCHK_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_TW_PG_FAULT_BPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_PG_FAULT_BPCHK_DET]

//>> CLEAR_[FIR1_REG_TW_PG_FAULT_BPCHK_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_PG_FAULT_BPCHK_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_PG_FAULT_BPCHK_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_TW_PG_FAULT_BPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_TW_PG_FAULT_BPCHK_DET]

//>> GET_[FIR1_REG_TW_PG_FAULT_BPCHK_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_PG_FAULT_BPCHK_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_PG_FAULT_BPCHK_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_TW_PG_FAULT_BPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_PG_FAULT_BPCHK_DET]

//>> GET_[FIR1_REG_TW_PG_FAULT_BPCHK_DET]
static inline bool GET_FIR1_REG_TW_PG_FAULT_BPCHK_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_PG_FAULT_BPCHK_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_TW_PG_FAULT_BPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_PG_FAULT_BPCHK_DET]

//>> SET_[FIR1_REG_TW_PG_FAULT_VPCHK_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PG_FAULT_VPCHK_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_PG_FAULT_VPCHK_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_TW_PG_FAULT_VPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_PG_FAULT_VPCHK_DET]

//>> SET_[FIR1_REG_TW_PG_FAULT_VPCHK_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PG_FAULT_VPCHK_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_PG_FAULT_VPCHK_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_TW_PG_FAULT_VPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_PG_FAULT_VPCHK_DET]

//>> SET_[FIR1_REG_TW_PG_FAULT_VPCHK_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PG_FAULT_VPCHK_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_PG_FAULT_VPCHK_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_TW_PG_FAULT_VPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_PG_FAULT_VPCHK_DET]

//>> CLEAR_[FIR1_REG_TW_PG_FAULT_VPCHK_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_PG_FAULT_VPCHK_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_PG_FAULT_VPCHK_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_TW_PG_FAULT_VPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_TW_PG_FAULT_VPCHK_DET]

//>> GET_[FIR1_REG_TW_PG_FAULT_VPCHK_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_PG_FAULT_VPCHK_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_PG_FAULT_VPCHK_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_TW_PG_FAULT_VPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_PG_FAULT_VPCHK_DET]

//>> GET_[FIR1_REG_TW_PG_FAULT_VPCHK_DET]
static inline bool GET_FIR1_REG_TW_PG_FAULT_VPCHK_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_PG_FAULT_VPCHK_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_TW_PG_FAULT_VPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_PG_FAULT_VPCHK_DET]

//>> SET_[FIR1_REG_TW_PG_FAULT_SEID_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PG_FAULT_SEID_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_PG_FAULT_SEID_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_TW_PG_FAULT_SEID_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_PG_FAULT_SEID_DET]

//>> SET_[FIR1_REG_TW_PG_FAULT_SEID_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PG_FAULT_SEID_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_PG_FAULT_SEID_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_TW_PG_FAULT_SEID_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_PG_FAULT_SEID_DET]

//>> SET_[FIR1_REG_TW_PG_FAULT_SEID_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PG_FAULT_SEID_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_PG_FAULT_SEID_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_TW_PG_FAULT_SEID_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_PG_FAULT_SEID_DET]

//>> CLEAR_[FIR1_REG_TW_PG_FAULT_SEID_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_PG_FAULT_SEID_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_PG_FAULT_SEID_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_TW_PG_FAULT_SEID_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_TW_PG_FAULT_SEID_DET]

//>> GET_[FIR1_REG_TW_PG_FAULT_SEID_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_PG_FAULT_SEID_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_PG_FAULT_SEID_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_TW_PG_FAULT_SEID_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_PG_FAULT_SEID_DET]

//>> GET_[FIR1_REG_TW_PG_FAULT_SEID_DET]
static inline bool GET_FIR1_REG_TW_PG_FAULT_SEID_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_PG_FAULT_SEID_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_TW_PG_FAULT_SEID_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_PG_FAULT_SEID_DET]

//>> SET_[FIR1_REG_TW_ADD_ERR_CR_RD_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_ADD_ERR_CR_RD_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_ADD_ERR_CR_RD_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_TW_ADD_ERR_CR_RD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_ADD_ERR_CR_RD_DET]

//>> SET_[FIR1_REG_TW_ADD_ERR_CR_RD_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_ADD_ERR_CR_RD_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_ADD_ERR_CR_RD_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_TW_ADD_ERR_CR_RD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_ADD_ERR_CR_RD_DET]

//>> SET_[FIR1_REG_TW_ADD_ERR_CR_RD_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_ADD_ERR_CR_RD_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_ADD_ERR_CR_RD_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_TW_ADD_ERR_CR_RD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_ADD_ERR_CR_RD_DET]

//>> CLEAR_[FIR1_REG_TW_ADD_ERR_CR_RD_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_ADD_ERR_CR_RD_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_ADD_ERR_CR_RD_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_TW_ADD_ERR_CR_RD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_TW_ADD_ERR_CR_RD_DET]

//>> GET_[FIR1_REG_TW_ADD_ERR_CR_RD_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_ADD_ERR_CR_RD_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_ADD_ERR_CR_RD_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_TW_ADD_ERR_CR_RD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_ADD_ERR_CR_RD_DET]

//>> GET_[FIR1_REG_TW_ADD_ERR_CR_RD_DET]
static inline bool GET_FIR1_REG_TW_ADD_ERR_CR_RD_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_ADD_ERR_CR_RD_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_TW_ADD_ERR_CR_RD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_ADD_ERR_CR_RD_DET]

//>> SET_[FIR1_REG_TW_PTE_UPD_FAIL_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PTE_UPD_FAIL_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_PTE_UPD_FAIL_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_TW_PTE_UPD_FAIL_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_PTE_UPD_FAIL_DET]

//>> SET_[FIR1_REG_TW_PTE_UPD_FAIL_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PTE_UPD_FAIL_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_PTE_UPD_FAIL_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_TW_PTE_UPD_FAIL_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_PTE_UPD_FAIL_DET]

//>> SET_[FIR1_REG_TW_PTE_UPD_FAIL_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PTE_UPD_FAIL_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_PTE_UPD_FAIL_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_TW_PTE_UPD_FAIL_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_PTE_UPD_FAIL_DET]

//>> CLEAR_[FIR1_REG_TW_PTE_UPD_FAIL_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_PTE_UPD_FAIL_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_PTE_UPD_FAIL_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_TW_PTE_UPD_FAIL_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_TW_PTE_UPD_FAIL_DET]

//>> GET_[FIR1_REG_TW_PTE_UPD_FAIL_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_PTE_UPD_FAIL_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_PTE_UPD_FAIL_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_TW_PTE_UPD_FAIL_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_PTE_UPD_FAIL_DET]

//>> GET_[FIR1_REG_TW_PTE_UPD_FAIL_DET]
static inline bool GET_FIR1_REG_TW_PTE_UPD_FAIL_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_PTE_UPD_FAIL_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_TW_PTE_UPD_FAIL_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_PTE_UPD_FAIL_DET]

//>> SET_[FIR1_REG_TW_ADD_ERR_CR_WR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_ADD_ERR_CR_WR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_ADD_ERR_CR_WR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_TW_ADD_ERR_CR_WR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_ADD_ERR_CR_WR_DET]

//>> SET_[FIR1_REG_TW_ADD_ERR_CR_WR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_ADD_ERR_CR_WR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_ADD_ERR_CR_WR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_TW_ADD_ERR_CR_WR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_ADD_ERR_CR_WR_DET]

//>> SET_[FIR1_REG_TW_ADD_ERR_CR_WR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_ADD_ERR_CR_WR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_ADD_ERR_CR_WR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_TW_ADD_ERR_CR_WR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_ADD_ERR_CR_WR_DET]

//>> CLEAR_[FIR1_REG_TW_ADD_ERR_CR_WR_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_ADD_ERR_CR_WR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_ADD_ERR_CR_WR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_TW_ADD_ERR_CR_WR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_TW_ADD_ERR_CR_WR_DET]

//>> GET_[FIR1_REG_TW_ADD_ERR_CR_WR_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_ADD_ERR_CR_WR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_ADD_ERR_CR_WR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_TW_ADD_ERR_CR_WR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_ADD_ERR_CR_WR_DET]

//>> GET_[FIR1_REG_TW_ADD_ERR_CR_WR_DET]
static inline bool GET_FIR1_REG_TW_ADD_ERR_CR_WR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_ADD_ERR_CR_WR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_TW_ADD_ERR_CR_WR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_ADD_ERR_CR_WR_DET]

//>> SET_[FIR1_REG_TW_RDX_CFG_GUEST_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_RDX_CFG_GUEST_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_RDX_CFG_GUEST_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_TW_RDX_CFG_GUEST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_RDX_CFG_GUEST_DET]

//>> SET_[FIR1_REG_TW_RDX_CFG_GUEST_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_RDX_CFG_GUEST_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_RDX_CFG_GUEST_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_TW_RDX_CFG_GUEST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_RDX_CFG_GUEST_DET]

//>> SET_[FIR1_REG_TW_RDX_CFG_GUEST_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_RDX_CFG_GUEST_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_RDX_CFG_GUEST_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_TW_RDX_CFG_GUEST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_RDX_CFG_GUEST_DET]

//>> CLEAR_[FIR1_REG_TW_RDX_CFG_GUEST_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_RDX_CFG_GUEST_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_RDX_CFG_GUEST_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_TW_RDX_CFG_GUEST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_TW_RDX_CFG_GUEST_DET]

//>> GET_[FIR1_REG_TW_RDX_CFG_GUEST_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_RDX_CFG_GUEST_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_RDX_CFG_GUEST_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_TW_RDX_CFG_GUEST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_RDX_CFG_GUEST_DET]

//>> GET_[FIR1_REG_TW_RDX_CFG_GUEST_DET]
static inline bool GET_FIR1_REG_TW_RDX_CFG_GUEST_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_RDX_CFG_GUEST_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_TW_RDX_CFG_GUEST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_RDX_CFG_GUEST_DET]

//>> SET_[FIR1_REG_TW_RDX_CFG_HOST_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_RDX_CFG_HOST_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_RDX_CFG_HOST_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_TW_RDX_CFG_HOST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_RDX_CFG_HOST_DET]

//>> SET_[FIR1_REG_TW_RDX_CFG_HOST_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_RDX_CFG_HOST_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_RDX_CFG_HOST_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_TW_RDX_CFG_HOST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_RDX_CFG_HOST_DET]

//>> SET_[FIR1_REG_TW_RDX_CFG_HOST_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_RDX_CFG_HOST_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_RDX_CFG_HOST_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_TW_RDX_CFG_HOST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_RDX_CFG_HOST_DET]

//>> CLEAR_[FIR1_REG_TW_RDX_CFG_HOST_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_RDX_CFG_HOST_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_RDX_CFG_HOST_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_TW_RDX_CFG_HOST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_TW_RDX_CFG_HOST_DET]

//>> GET_[FIR1_REG_TW_RDX_CFG_HOST_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_RDX_CFG_HOST_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_RDX_CFG_HOST_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_TW_RDX_CFG_HOST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_RDX_CFG_HOST_DET]

//>> GET_[FIR1_REG_TW_RDX_CFG_HOST_DET]
static inline bool GET_FIR1_REG_TW_RDX_CFG_HOST_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_RDX_CFG_HOST_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_TW_RDX_CFG_HOST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_RDX_CFG_HOST_DET]

//>> SET_[FIR1_REG_TW_INVALID_WIMG_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_INVALID_WIMG_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_INVALID_WIMG_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_TW_INVALID_WIMG_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_INVALID_WIMG_DET]

//>> SET_[FIR1_REG_TW_INVALID_WIMG_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_INVALID_WIMG_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_INVALID_WIMG_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_TW_INVALID_WIMG_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_INVALID_WIMG_DET]

//>> SET_[FIR1_REG_TW_INVALID_WIMG_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_INVALID_WIMG_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_INVALID_WIMG_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_TW_INVALID_WIMG_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_INVALID_WIMG_DET]

//>> CLEAR_[FIR1_REG_TW_INVALID_WIMG_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_INVALID_WIMG_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_INVALID_WIMG_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_TW_INVALID_WIMG_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_TW_INVALID_WIMG_DET]

//>> GET_[FIR1_REG_TW_INVALID_WIMG_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_INVALID_WIMG_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_INVALID_WIMG_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_TW_INVALID_WIMG_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_INVALID_WIMG_DET]

//>> GET_[FIR1_REG_TW_INVALID_WIMG_DET]
static inline bool GET_FIR1_REG_TW_INVALID_WIMG_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_INVALID_WIMG_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_TW_INVALID_WIMG_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_INVALID_WIMG_DET]

//>> SET_[FIR1_REG_TW_INV_RDX_QUAD_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_INV_RDX_QUAD_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_INV_RDX_QUAD_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_TW_INV_RDX_QUAD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_INV_RDX_QUAD_DET]

//>> SET_[FIR1_REG_TW_INV_RDX_QUAD_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_INV_RDX_QUAD_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_INV_RDX_QUAD_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_TW_INV_RDX_QUAD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_INV_RDX_QUAD_DET]

//>> SET_[FIR1_REG_TW_INV_RDX_QUAD_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_INV_RDX_QUAD_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_INV_RDX_QUAD_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_TW_INV_RDX_QUAD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_INV_RDX_QUAD_DET]

//>> CLEAR_[FIR1_REG_TW_INV_RDX_QUAD_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_INV_RDX_QUAD_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_INV_RDX_QUAD_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_TW_INV_RDX_QUAD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_TW_INV_RDX_QUAD_DET]

//>> GET_[FIR1_REG_TW_INV_RDX_QUAD_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_INV_RDX_QUAD_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_INV_RDX_QUAD_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_TW_INV_RDX_QUAD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_INV_RDX_QUAD_DET]

//>> GET_[FIR1_REG_TW_INV_RDX_QUAD_DET]
static inline bool GET_FIR1_REG_TW_INV_RDX_QUAD_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_INV_RDX_QUAD_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_TW_INV_RDX_QUAD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_INV_RDX_QUAD_DET]

//>> SET_[FIR1_REG_TW_FOREIGN_ADDR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_FOREIGN_ADDR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_FOREIGN_ADDR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_TW_FOREIGN_ADDR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_FOREIGN_ADDR_DET]

//>> SET_[FIR1_REG_TW_FOREIGN_ADDR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_FOREIGN_ADDR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_FOREIGN_ADDR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_TW_FOREIGN_ADDR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_FOREIGN_ADDR_DET]

//>> SET_[FIR1_REG_TW_FOREIGN_ADDR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_FOREIGN_ADDR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_FOREIGN_ADDR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_TW_FOREIGN_ADDR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_FOREIGN_ADDR_DET]

//>> CLEAR_[FIR1_REG_TW_FOREIGN_ADDR_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_FOREIGN_ADDR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_FOREIGN_ADDR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_TW_FOREIGN_ADDR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_TW_FOREIGN_ADDR_DET]

//>> GET_[FIR1_REG_TW_FOREIGN_ADDR_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_FOREIGN_ADDR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_FOREIGN_ADDR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_TW_FOREIGN_ADDR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_FOREIGN_ADDR_DET]

//>> GET_[FIR1_REG_TW_FOREIGN_ADDR_DET]
static inline bool GET_FIR1_REG_TW_FOREIGN_ADDR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_FOREIGN_ADDR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_TW_FOREIGN_ADDR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_FOREIGN_ADDR_DET]

//>> SET_[FIR1_REG_TW_PREFETCH_ABT_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PREFETCH_ABT_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_PREFETCH_ABT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_TW_PREFETCH_ABT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_PREFETCH_ABT_DET]

//>> SET_[FIR1_REG_TW_PREFETCH_ABT_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PREFETCH_ABT_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_PREFETCH_ABT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_TW_PREFETCH_ABT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_PREFETCH_ABT_DET]

//>> SET_[FIR1_REG_TW_PREFETCH_ABT_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PREFETCH_ABT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_PREFETCH_ABT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_TW_PREFETCH_ABT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_PREFETCH_ABT_DET]

//>> CLEAR_[FIR1_REG_TW_PREFETCH_ABT_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_PREFETCH_ABT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_PREFETCH_ABT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_TW_PREFETCH_ABT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_TW_PREFETCH_ABT_DET]

//>> GET_[FIR1_REG_TW_PREFETCH_ABT_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_PREFETCH_ABT_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_PREFETCH_ABT_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_TW_PREFETCH_ABT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_PREFETCH_ABT_DET]

//>> GET_[FIR1_REG_TW_PREFETCH_ABT_DET]
static inline bool GET_FIR1_REG_TW_PREFETCH_ABT_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_PREFETCH_ABT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_TW_PREFETCH_ABT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_PREFETCH_ABT_DET]

//>> SET_[FIR1_REG_TW_CXT_CAC_PERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_CXT_CAC_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_CXT_CAC_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_TW_CXT_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_CXT_CAC_PERR_DET]

//>> SET_[FIR1_REG_TW_CXT_CAC_PERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_CXT_CAC_PERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_CXT_CAC_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_TW_CXT_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_CXT_CAC_PERR_DET]

//>> SET_[FIR1_REG_TW_CXT_CAC_PERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_CXT_CAC_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_CXT_CAC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_TW_CXT_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_CXT_CAC_PERR_DET]

//>> CLEAR_[FIR1_REG_TW_CXT_CAC_PERR_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_CXT_CAC_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_CXT_CAC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_TW_CXT_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_TW_CXT_CAC_PERR_DET]

//>> GET_[FIR1_REG_TW_CXT_CAC_PERR_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_CXT_CAC_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_CXT_CAC_PERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_TW_CXT_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_CXT_CAC_PERR_DET]

//>> GET_[FIR1_REG_TW_CXT_CAC_PERR_DET]
static inline bool GET_FIR1_REG_TW_CXT_CAC_PERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_CXT_CAC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_TW_CXT_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_CXT_CAC_PERR_DET]

//>> SET_[FIR1_REG_TW_RDX_PWC_PERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_RDX_PWC_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_RDX_PWC_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_TW_RDX_PWC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_RDX_PWC_PERR_DET]

//>> SET_[FIR1_REG_TW_RDX_PWC_PERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_RDX_PWC_PERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_RDX_PWC_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_TW_RDX_PWC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_RDX_PWC_PERR_DET]

//>> SET_[FIR1_REG_TW_RDX_PWC_PERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_RDX_PWC_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_RDX_PWC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_TW_RDX_PWC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_RDX_PWC_PERR_DET]

//>> CLEAR_[FIR1_REG_TW_RDX_PWC_PERR_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_RDX_PWC_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_RDX_PWC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_TW_RDX_PWC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_TW_RDX_PWC_PERR_DET]

//>> GET_[FIR1_REG_TW_RDX_PWC_PERR_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_RDX_PWC_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_RDX_PWC_PERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_TW_RDX_PWC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_RDX_PWC_PERR_DET]

//>> GET_[FIR1_REG_TW_RDX_PWC_PERR_DET]
static inline bool GET_FIR1_REG_TW_RDX_PWC_PERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_RDX_PWC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_TW_RDX_PWC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_RDX_PWC_PERR_DET]

//>> SET_[FIR1_REG_TW_SM_CTL_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_SM_CTL_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_TW_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_SM_CTL_ERR_DET]

//>> SET_[FIR1_REG_TW_SM_CTL_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_SM_CTL_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_SM_CTL_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_TW_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_SM_CTL_ERR_DET]

//>> SET_[FIR1_REG_TW_SM_CTL_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_TW_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_SM_CTL_ERR_DET]

//>> CLEAR_[FIR1_REG_TW_SM_CTL_ERR_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_TW_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_TW_SM_CTL_ERR_DET]

//>> GET_[FIR1_REG_TW_SM_CTL_ERR_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_SM_CTL_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_TW_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_SM_CTL_ERR_DET]

//>> GET_[FIR1_REG_TW_SM_CTL_ERR_DET]
static inline bool GET_FIR1_REG_TW_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_TW_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_SM_CTL_ERR_DET]

//>> SET_[FIR1_REG_CO_SM_CTL_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CO_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_CO_SM_CTL_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_CO_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_CO_SM_CTL_ERR_DET]

//>> SET_[FIR1_REG_CO_SM_CTL_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CO_SM_CTL_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_CO_SM_CTL_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_CO_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_CO_SM_CTL_ERR_DET]

//>> SET_[FIR1_REG_CO_SM_CTL_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CO_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_CO_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_CO_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_CO_SM_CTL_ERR_DET]

//>> CLEAR_[FIR1_REG_CO_SM_CTL_ERR_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_CO_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_CO_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_CO_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_CO_SM_CTL_ERR_DET]

//>> GET_[FIR1_REG_CO_SM_CTL_ERR_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_CO_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_CO_SM_CTL_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_CO_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_CO_SM_CTL_ERR_DET]

//>> GET_[FIR1_REG_CO_SM_CTL_ERR_DET]
static inline bool GET_FIR1_REG_CO_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_CO_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_CO_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_CO_SM_CTL_ERR_DET]

//>> SET_[FIR1_REG_CI_SM_CTL_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CI_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_CI_SM_CTL_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_CI_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_CI_SM_CTL_ERR_DET]

//>> SET_[FIR1_REG_CI_SM_CTL_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CI_SM_CTL_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_CI_SM_CTL_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_CI_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_CI_SM_CTL_ERR_DET]

//>> SET_[FIR1_REG_CI_SM_CTL_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CI_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_CI_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_CI_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_CI_SM_CTL_ERR_DET]

//>> CLEAR_[FIR1_REG_CI_SM_CTL_ERR_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_CI_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_CI_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_CI_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_CI_SM_CTL_ERR_DET]

//>> GET_[FIR1_REG_CI_SM_CTL_ERR_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_CI_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_CI_SM_CTL_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_CI_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_CI_SM_CTL_ERR_DET]

//>> GET_[FIR1_REG_CI_SM_CTL_ERR_DET]
static inline bool GET_FIR1_REG_CI_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_CI_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_CI_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_CI_SM_CTL_ERR_DET]

//>> SET_[FIR1_REG_INV_SM_CTL_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_INV_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_INV_SM_CTL_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_INV_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_INV_SM_CTL_ERR_DET]

//>> SET_[FIR1_REG_INV_SM_CTL_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_INV_SM_CTL_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_INV_SM_CTL_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_INV_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_INV_SM_CTL_ERR_DET]

//>> SET_[FIR1_REG_INV_SM_CTL_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_INV_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_INV_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_INV_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_INV_SM_CTL_ERR_DET]

//>> CLEAR_[FIR1_REG_INV_SM_CTL_ERR_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_INV_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_INV_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_INV_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_INV_SM_CTL_ERR_DET]

//>> GET_[FIR1_REG_INV_SM_CTL_ERR_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_INV_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_INV_SM_CTL_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_INV_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_INV_SM_CTL_ERR_DET]

//>> GET_[FIR1_REG_INV_SM_CTL_ERR_DET]
static inline bool GET_FIR1_REG_INV_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_INV_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_INV_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_INV_SM_CTL_ERR_DET]

//>> SET_[FIR1_REG_TW_TIMEOUT_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_TIMEOUT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_TW_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_TIMEOUT_ERR_DET]

//>> SET_[FIR1_REG_TW_TIMEOUT_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_TIMEOUT_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_TIMEOUT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_TW_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_TIMEOUT_ERR_DET]

//>> SET_[FIR1_REG_TW_TIMEOUT_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_TW_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_TW_TIMEOUT_ERR_DET]

//>> CLEAR_[FIR1_REG_TW_TIMEOUT_ERR_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_TW_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_TW_TIMEOUT_ERR_DET]

//>> GET_[FIR1_REG_TW_TIMEOUT_ERR_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_TIMEOUT_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_TW_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_TIMEOUT_ERR_DET]

//>> GET_[FIR1_REG_TW_TIMEOUT_ERR_DET]
static inline bool GET_FIR1_REG_TW_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_TW_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_TW_TIMEOUT_ERR_DET]

//>> SET_[FIR1_REG_CO_TIMEOUT_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CO_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_CO_TIMEOUT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_CO_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_CO_TIMEOUT_ERR_DET]

//>> SET_[FIR1_REG_CO_TIMEOUT_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CO_TIMEOUT_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_CO_TIMEOUT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_CO_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_CO_TIMEOUT_ERR_DET]

//>> SET_[FIR1_REG_CO_TIMEOUT_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CO_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_CO_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_CO_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_CO_TIMEOUT_ERR_DET]

//>> CLEAR_[FIR1_REG_CO_TIMEOUT_ERR_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_CO_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_CO_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_CO_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_CO_TIMEOUT_ERR_DET]

//>> GET_[FIR1_REG_CO_TIMEOUT_ERR_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_CO_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_CO_TIMEOUT_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_CO_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_CO_TIMEOUT_ERR_DET]

//>> GET_[FIR1_REG_CO_TIMEOUT_ERR_DET]
static inline bool GET_FIR1_REG_CO_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_CO_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_CO_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_CO_TIMEOUT_ERR_DET]

//>> SET_[FIR1_REG_CI_TIMEOUT_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CI_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_CI_TIMEOUT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_CI_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_CI_TIMEOUT_ERR_DET]

//>> SET_[FIR1_REG_CI_TIMEOUT_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CI_TIMEOUT_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_CI_TIMEOUT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_CI_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_CI_TIMEOUT_ERR_DET]

//>> SET_[FIR1_REG_CI_TIMEOUT_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CI_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_CI_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_CI_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_CI_TIMEOUT_ERR_DET]

//>> CLEAR_[FIR1_REG_CI_TIMEOUT_ERR_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_CI_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_CI_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_CI_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_CI_TIMEOUT_ERR_DET]

//>> GET_[FIR1_REG_CI_TIMEOUT_ERR_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_CI_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_CI_TIMEOUT_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_CI_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_CI_TIMEOUT_ERR_DET]

//>> GET_[FIR1_REG_CI_TIMEOUT_ERR_DET]
static inline bool GET_FIR1_REG_CI_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_CI_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_CI_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_CI_TIMEOUT_ERR_DET]

//>> SET_[FIR1_REG_INV_TIMEOUT_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_INV_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_INV_TIMEOUT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_INV_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_INV_TIMEOUT_ERR_DET]

//>> SET_[FIR1_REG_INV_TIMEOUT_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_INV_TIMEOUT_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_INV_TIMEOUT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_INV_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_INV_TIMEOUT_ERR_DET]

//>> SET_[FIR1_REG_INV_TIMEOUT_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_INV_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_INV_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_INV_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_INV_TIMEOUT_ERR_DET]

//>> CLEAR_[FIR1_REG_INV_TIMEOUT_ERR_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_INV_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_INV_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_INV_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_INV_TIMEOUT_ERR_DET]

//>> GET_[FIR1_REG_INV_TIMEOUT_ERR_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_INV_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_INV_TIMEOUT_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_INV_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_INV_TIMEOUT_ERR_DET]

//>> GET_[FIR1_REG_INV_TIMEOUT_ERR_DET]
static inline bool GET_FIR1_REG_INV_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_INV_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_INV_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_INV_TIMEOUT_ERR_DET]

//>> SET_[FIR1_REG_NX0_LXSTOP_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_NX0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_NX0_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_NX0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_NX0_LXSTOP_ERR_DET]

//>> SET_[FIR1_REG_NX0_LXSTOP_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_NX0_LXSTOP_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_NX0_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_NX0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_NX0_LXSTOP_ERR_DET]

//>> SET_[FIR1_REG_NX0_LXSTOP_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_NX0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_NX0_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_NX0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_NX0_LXSTOP_ERR_DET]

//>> CLEAR_[FIR1_REG_NX0_LXSTOP_ERR_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_NX0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_NX0_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_NX0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_NX0_LXSTOP_ERR_DET]

//>> GET_[FIR1_REG_NX0_LXSTOP_ERR_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_NX0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_NX0_LXSTOP_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_NX0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_NX0_LXSTOP_ERR_DET]

//>> GET_[FIR1_REG_NX0_LXSTOP_ERR_DET]
static inline bool GET_FIR1_REG_NX0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_NX0_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_NX0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_NX0_LXSTOP_ERR_DET]

//>> SET_[FIR1_REG_CP0_LXSTOP_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CP0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_CP0_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_CP0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_CP0_LXSTOP_ERR_DET]

//>> SET_[FIR1_REG_CP0_LXSTOP_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CP0_LXSTOP_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_CP0_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_CP0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_CP0_LXSTOP_ERR_DET]

//>> SET_[FIR1_REG_CP0_LXSTOP_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CP0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_CP0_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_CP0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_CP0_LXSTOP_ERR_DET]

//>> CLEAR_[FIR1_REG_CP0_LXSTOP_ERR_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_CP0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_CP0_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_CP0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_CP0_LXSTOP_ERR_DET]

//>> GET_[FIR1_REG_CP0_LXSTOP_ERR_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_CP0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_CP0_LXSTOP_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_CP0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_CP0_LXSTOP_ERR_DET]

//>> GET_[FIR1_REG_CP0_LXSTOP_ERR_DET]
static inline bool GET_FIR1_REG_CP0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_CP0_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_CP0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_CP0_LXSTOP_ERR_DET]

//>> SET_[FIR1_REG_CP1_LXSTOP_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CP1_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_CP1_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_CP1_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_CP1_LXSTOP_ERR_DET]

//>> SET_[FIR1_REG_CP1_LXSTOP_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CP1_LXSTOP_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_CP1_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_CP1_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_CP1_LXSTOP_ERR_DET]

//>> SET_[FIR1_REG_CP1_LXSTOP_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CP1_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_CP1_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_CP1_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_CP1_LXSTOP_ERR_DET]

//>> CLEAR_[FIR1_REG_CP1_LXSTOP_ERR_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_CP1_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_CP1_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_CP1_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_CP1_LXSTOP_ERR_DET]

//>> GET_[FIR1_REG_CP1_LXSTOP_ERR_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_CP1_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_CP1_LXSTOP_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_CP1_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_CP1_LXSTOP_ERR_DET]

//>> GET_[FIR1_REG_CP1_LXSTOP_ERR_DET]
static inline bool GET_FIR1_REG_CP1_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_CP1_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_CP1_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_CP1_LXSTOP_ERR_DET]

//>> SET_[FIR1_REG_NPU_LXSTOP_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_NPU_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_NPU_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_NPU_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_NPU_LXSTOP_ERR_DET]

//>> SET_[FIR1_REG_NPU_LXSTOP_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_NPU_LXSTOP_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_NPU_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_NPU_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_NPU_LXSTOP_ERR_DET]

//>> SET_[FIR1_REG_NPU_LXSTOP_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_NPU_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_NPU_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_NPU_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_NPU_LXSTOP_ERR_DET]

//>> CLEAR_[FIR1_REG_NPU_LXSTOP_ERR_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_NPU_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_NPU_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_NPU_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_NPU_LXSTOP_ERR_DET]

//>> GET_[FIR1_REG_NPU_LXSTOP_ERR_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_NPU_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_NPU_LXSTOP_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_NPU_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_NPU_LXSTOP_ERR_DET]

//>> GET_[FIR1_REG_NPU_LXSTOP_ERR_DET]
static inline bool GET_FIR1_REG_NPU_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_NPU_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_NPU_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_NPU_LXSTOP_ERR_DET]

//>> SET_[FIR1_REG_FBC_LXSTOP_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_FBC_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_FBC_LXSTOP_ERR_DET]

//>> SET_[FIR1_REG_FBC_LXSTOP_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_LXSTOP_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_FBC_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_FBC_LXSTOP_ERR_DET]

//>> SET_[FIR1_REG_FBC_LXSTOP_ERR_DET]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_FBC_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_FBC_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_FBC_LXSTOP_ERR_DET]

//>> CLEAR_[FIR1_REG_FBC_LXSTOP_ERR_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_FBC_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_FBC_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_FBC_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_FBC_LXSTOP_ERR_DET]

//>> GET_[FIR1_REG_FBC_LXSTOP_ERR_DET]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_FBC_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_FBC_LXSTOP_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_FBC_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_FBC_LXSTOP_ERR_DET]

//>> GET_[FIR1_REG_FBC_LXSTOP_ERR_DET]
static inline bool GET_FIR1_REG_FBC_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_FBC_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_FBC_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_FBC_LXSTOP_ERR_DET]

//>> SET_[FIR1_REG_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FIR1_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_SPARE]

//>> SET_[FIR1_REG_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FIR1_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_SPARE]

//>> SET_[FIR1_REG_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.setBit<FIR1_REG_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FIR1_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR1_REG_SPARE]

//>> CLEAR_[FIR1_REG_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return o_data.clearBit<FIR1_REG_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FIR1_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR1_REG_SPARE]

//>> GET_[FIR1_REG_SPARE]
static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.extractToRight<FIR1_REG_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FIR1_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_SPARE]

//>> GET_[FIR1_REG_SPARE]
static inline bool GET_FIR1_REG_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RW, FIR1_REG_WO_AND, FIR1_REG_WO_OR));
#endif
    return i_data.getBit<FIR1_REG_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FIR1_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR1_REG_SPARE]

//>> PREP_[NMMU_ERR_LOG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NMMU_ERR_LOG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NMMU_ERR_LOG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NMMU_ERR_LOG]

//>> GET_[NMMU_ERR_LOG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NMMU_ERR_LOG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NMMU_ERR_LOG;
#endif
    return fapi2::getScom(i_target, NMMU_ERR_LOG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NMMU_ERR_LOG]

//>> PUT_[NMMU_ERR_LOG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NMMU_ERR_LOG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return fapi2::putScom(i_target, NMMU_ERR_LOG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NMMU_ERR_LOG]


//>> SET_[NMMU_ERR_LOG_RESERVED_0_1]
static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_LOG_RESERVED_0_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.insertFromRight<NMMU_ERR_LOG_RESERVED_0_1,
           NMMU_ERR_LOG_RESERVED_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access NMMU_ERR_LOG_RESERVED_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NMMU_ERR_LOG_RESERVED_0_1]

//>> SET_[NMMU_ERR_LOG_RESERVED_0_1]
static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_LOG_RESERVED_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.insertFromRight<NMMU_ERR_LOG_RESERVED_0_1,
           NMMU_ERR_LOG_RESERVED_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access NMMU_ERR_LOG_RESERVED_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NMMU_ERR_LOG_RESERVED_0_1]

//>> GET_[NMMU_ERR_LOG_RESERVED_0_1]
static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_LOG_RESERVED_0_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return i_data.extractToRight<NMMU_ERR_LOG_RESERVED_0_1,
           NMMU_ERR_LOG_RESERVED_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access NMMU_ERR_LOG_RESERVED_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NMMU_ERR_LOG_RESERVED_0_1]

//>> SET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN]
static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.insertFromRight<NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN]

//>> SET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN]
static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.insertFromRight<NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN]

//>> SET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN]
static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.setBit<NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN]

//>> CLEAR_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.clearBit<NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN]

//>> GET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN]
static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return i_data.extractToRight<NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN]

//>> GET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN]
static inline bool GET_NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return i_data.getBit<NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_EN]

//>> SET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN]
static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.insertFromRight<NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN]

//>> SET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN]
static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.insertFromRight<NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN]

//>> SET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN]
static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.setBit<NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN]

//>> CLEAR_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.clearBit<NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN]

//>> GET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN]
static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return i_data.extractToRight<NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN]

//>> GET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN]
static inline bool GET_NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return i_data.getBit<NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_SNGL_SHOT_EN]

//>> SET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN]
static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.insertFromRight<NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN]

//>> SET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN]
static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.insertFromRight<NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN]

//>> SET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN]
static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.setBit<NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN]

//>> CLEAR_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.clearBit<NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN]

//>> GET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN]
static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return i_data.extractToRight<NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN]

//>> GET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN]
static inline bool GET_NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return i_data.getBit<NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_OVERLAP_EN]

//>> SET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_MULT_SEL]
static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_MULT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.insertFromRight<NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_MULT_SEL,
           NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_MULT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_MULT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_MULT_SEL]

//>> SET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_MULT_SEL]
static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_MULT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.insertFromRight<NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_MULT_SEL,
           NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_MULT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_MULT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_MULT_SEL]

//>> GET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_MULT_SEL]
static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_MULT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return i_data.extractToRight<NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_MULT_SEL,
           NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_MULT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_MULT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NMMU_ERR_LOG_MM_ERR_INJ_SNP_FLT_MULT_SEL]

//>> SET_[NMMU_ERR_LOG_RESERVED_08_63]
static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_LOG_RESERVED_08_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.insertFromRight<NMMU_ERR_LOG_RESERVED_08_63,
           NMMU_ERR_LOG_RESERVED_08_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access NMMU_ERR_LOG_RESERVED_08_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NMMU_ERR_LOG_RESERVED_08_63]

//>> SET_[NMMU_ERR_LOG_RESERVED_08_63]
static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_LOG_RESERVED_08_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.insertFromRight<NMMU_ERR_LOG_RESERVED_08_63,
           NMMU_ERR_LOG_RESERVED_08_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access NMMU_ERR_LOG_RESERVED_08_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NMMU_ERR_LOG_RESERVED_08_63]

//>> GET_[NMMU_ERR_LOG_RESERVED_08_63]
static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_LOG_RESERVED_08_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return i_data.extractToRight<NMMU_ERR_LOG_RESERVED_08_63,
           NMMU_ERR_LOG_RESERVED_08_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access NMMU_ERR_LOG_RESERVED_08_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NMMU_ERR_LOG_RESERVED_08_63]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
