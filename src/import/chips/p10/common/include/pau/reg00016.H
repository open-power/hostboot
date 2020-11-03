/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pau/reg00016.H $          */
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

#ifndef __PAU_REG00016_H_
#define __PAU_REG00016_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


//>> PREP_[CS_CTL_MISC_STATUS1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CS_CTL_MISC_STATUS1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_CTL_MISC_STATUS1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CS_CTL_MISC_STATUS1]

//>> GET_[CS_CTL_MISC_STATUS1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CS_CTL_MISC_STATUS1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_CTL_MISC_STATUS1;
#endif
    return fapi2::getScom(i_target, CS_CTL_MISC_STATUS1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1]

//>> PUT_[CS_CTL_MISC_STATUS1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CS_CTL_MISC_STATUS1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return fapi2::putScom(i_target, CS_CTL_MISC_STATUS1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CS_CTL_MISC_STATUS1]


//>> SET_[CS_CTL_MISC_STATUS1_SM_MMIO0]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_SM_MMIO0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_SM_MMIO0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_SM_MMIO0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_SM_MMIO0]

//>> SET_[CS_CTL_MISC_STATUS1_SM_MMIO0]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_SM_MMIO0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_SM_MMIO0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_SM_MMIO0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_SM_MMIO0]

//>> SET_[CS_CTL_MISC_STATUS1_SM_MMIO0]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_SM_MMIO0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS1_SM_MMIO0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_SM_MMIO0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_SM_MMIO0]

//>> CLEAR_[CS_CTL_MISC_STATUS1_SM_MMIO0]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS1_SM_MMIO0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS1_SM_MMIO0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_SM_MMIO0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS1_SM_MMIO0]

//>> GET_[CS_CTL_MISC_STATUS1_SM_MMIO0]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_SM_MMIO0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_SM_MMIO0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_SM_MMIO0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_SM_MMIO0]

//>> GET_[CS_CTL_MISC_STATUS1_SM_MMIO0]
static inline bool GET_CS_CTL_MISC_STATUS1_SM_MMIO0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS1_SM_MMIO0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_SM_MMIO0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_SM_MMIO0]

//>> SET_[CS_CTL_MISC_STATUS1_SM_MMIO1]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_SM_MMIO1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_SM_MMIO1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_SM_MMIO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_SM_MMIO1]

//>> SET_[CS_CTL_MISC_STATUS1_SM_MMIO1]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_SM_MMIO1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_SM_MMIO1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_SM_MMIO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_SM_MMIO1]

//>> SET_[CS_CTL_MISC_STATUS1_SM_MMIO1]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_SM_MMIO1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS1_SM_MMIO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_SM_MMIO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_SM_MMIO1]

//>> CLEAR_[CS_CTL_MISC_STATUS1_SM_MMIO1]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS1_SM_MMIO1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS1_SM_MMIO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_SM_MMIO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS1_SM_MMIO1]

//>> GET_[CS_CTL_MISC_STATUS1_SM_MMIO1]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_SM_MMIO1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_SM_MMIO1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_SM_MMIO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_SM_MMIO1]

//>> GET_[CS_CTL_MISC_STATUS1_SM_MMIO1]
static inline bool GET_CS_CTL_MISC_STATUS1_SM_MMIO1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS1_SM_MMIO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_SM_MMIO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_SM_MMIO1]

//>> SET_[CS_CTL_MISC_STATUS1_SM_MMIO2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_SM_MMIO2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_SM_MMIO2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_SM_MMIO2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_SM_MMIO2]

//>> SET_[CS_CTL_MISC_STATUS1_SM_MMIO2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_SM_MMIO2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_SM_MMIO2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_SM_MMIO2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_SM_MMIO2]

//>> SET_[CS_CTL_MISC_STATUS1_SM_MMIO2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_SM_MMIO2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS1_SM_MMIO2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_SM_MMIO2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_SM_MMIO2]

//>> CLEAR_[CS_CTL_MISC_STATUS1_SM_MMIO2]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS1_SM_MMIO2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS1_SM_MMIO2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_SM_MMIO2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS1_SM_MMIO2]

//>> GET_[CS_CTL_MISC_STATUS1_SM_MMIO2]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_SM_MMIO2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_SM_MMIO2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_SM_MMIO2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_SM_MMIO2]

//>> GET_[CS_CTL_MISC_STATUS1_SM_MMIO2]
static inline bool GET_CS_CTL_MISC_STATUS1_SM_MMIO2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS1_SM_MMIO2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_SM_MMIO2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_SM_MMIO2]

//>> SET_[CS_CTL_MISC_STATUS1_SM_MMIO3]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_SM_MMIO3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_SM_MMIO3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_SM_MMIO3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_SM_MMIO3]

//>> SET_[CS_CTL_MISC_STATUS1_SM_MMIO3]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_SM_MMIO3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_SM_MMIO3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_SM_MMIO3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_SM_MMIO3]

//>> SET_[CS_CTL_MISC_STATUS1_SM_MMIO3]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_SM_MMIO3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS1_SM_MMIO3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_SM_MMIO3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_SM_MMIO3]

//>> CLEAR_[CS_CTL_MISC_STATUS1_SM_MMIO3]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS1_SM_MMIO3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS1_SM_MMIO3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_SM_MMIO3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS1_SM_MMIO3]

//>> GET_[CS_CTL_MISC_STATUS1_SM_MMIO3]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_SM_MMIO3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_SM_MMIO3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_SM_MMIO3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_SM_MMIO3]

//>> GET_[CS_CTL_MISC_STATUS1_SM_MMIO3]
static inline bool GET_CS_CTL_MISC_STATUS1_SM_MMIO3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS1_SM_MMIO3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_SM_MMIO3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_SM_MMIO3]

//>> SET_[CS_CTL_MISC_STATUS1_MRBGP]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_MRBGP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_MRBGP,
           CS_CTL_MISC_STATUS1_MRBGP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_MRBGP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_MRBGP]

//>> SET_[CS_CTL_MISC_STATUS1_MRBGP]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_MRBGP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_MRBGP,
           CS_CTL_MISC_STATUS1_MRBGP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_MRBGP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_MRBGP]

//>> GET_[CS_CTL_MISC_STATUS1_MRBGP]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_MRBGP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_MRBGP,
           CS_CTL_MISC_STATUS1_MRBGP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_MRBGP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_MRBGP]

//>> SET_[CS_CTL_MISC_STATUS1_MRBSP]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_MRBSP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_MRBSP,
           CS_CTL_MISC_STATUS1_MRBSP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_MRBSP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_MRBSP]

//>> SET_[CS_CTL_MISC_STATUS1_MRBSP]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_MRBSP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_MRBSP,
           CS_CTL_MISC_STATUS1_MRBSP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_MRBSP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_MRBSP]

//>> GET_[CS_CTL_MISC_STATUS1_MRBSP]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_MRBSP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_MRBSP,
           CS_CTL_MISC_STATUS1_MRBSP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_MRBSP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_MRBSP]

//>> SET_[CS_CTL_MISC_STATUS1_MRBCP]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_MRBCP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_MRBCP,
           CS_CTL_MISC_STATUS1_MRBCP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_MRBCP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_MRBCP]

//>> SET_[CS_CTL_MISC_STATUS1_MRBCP]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_MRBCP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_MRBCP,
           CS_CTL_MISC_STATUS1_MRBCP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_MRBCP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_MRBCP]

//>> GET_[CS_CTL_MISC_STATUS1_MRBCP]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_MRBCP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_MRBCP,
           CS_CTL_MISC_STATUS1_MRBCP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_MRBCP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_MRBCP]

//>> SET_[CS_CTL_MISC_STATUS1_LPCTH]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_LPCTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_LPCTH,
           CS_CTL_MISC_STATUS1_LPCTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_LPCTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_LPCTH]

//>> SET_[CS_CTL_MISC_STATUS1_LPCTH]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_LPCTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_LPCTH,
           CS_CTL_MISC_STATUS1_LPCTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_LPCTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_LPCTH]

//>> GET_[CS_CTL_MISC_STATUS1_LPCTH]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_LPCTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_LPCTH,
           CS_CTL_MISC_STATUS1_LPCTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_LPCTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_LPCTH]

//>> SET_[CS_CTL_MISC_STATUS1_ATS_SYNC]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_ATS_SYNC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_ATS_SYNC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_ATS_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_ATS_SYNC]

//>> SET_[CS_CTL_MISC_STATUS1_ATS_SYNC]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_ATS_SYNC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_ATS_SYNC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_ATS_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_ATS_SYNC]

//>> SET_[CS_CTL_MISC_STATUS1_ATS_SYNC]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_ATS_SYNC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS1_ATS_SYNC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_ATS_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_ATS_SYNC]

//>> CLEAR_[CS_CTL_MISC_STATUS1_ATS_SYNC]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS1_ATS_SYNC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS1_ATS_SYNC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_ATS_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS1_ATS_SYNC]

//>> GET_[CS_CTL_MISC_STATUS1_ATS_SYNC]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_ATS_SYNC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_ATS_SYNC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_ATS_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_ATS_SYNC]

//>> GET_[CS_CTL_MISC_STATUS1_ATS_SYNC]
static inline bool GET_CS_CTL_MISC_STATUS1_ATS_SYNC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS1_ATS_SYNC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_ATS_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_ATS_SYNC]

//>> SET_[CS_CTL_MISC_STATUS1_NMMU]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_NMMU(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_NMMU,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_NMMU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_NMMU]

//>> SET_[CS_CTL_MISC_STATUS1_NMMU]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_NMMU(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_NMMU,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_NMMU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_NMMU]

//>> SET_[CS_CTL_MISC_STATUS1_NMMU]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_NMMU(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS1_NMMU>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_NMMU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_NMMU]

//>> CLEAR_[CS_CTL_MISC_STATUS1_NMMU]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS1_NMMU(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS1_NMMU>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_NMMU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS1_NMMU]

//>> GET_[CS_CTL_MISC_STATUS1_NMMU]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_NMMU(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_NMMU,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_NMMU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_NMMU]

//>> GET_[CS_CTL_MISC_STATUS1_NMMU]
static inline bool GET_CS_CTL_MISC_STATUS1_NMMU(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS1_NMMU>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_NMMU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_NMMU]

//>> SET_[CS_CTL_MISC_STATUS1_PBLN]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_PBLN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_PBLN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_PBLN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_PBLN]

//>> SET_[CS_CTL_MISC_STATUS1_PBLN]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_PBLN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_PBLN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_PBLN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_PBLN]

//>> SET_[CS_CTL_MISC_STATUS1_PBLN]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_PBLN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS1_PBLN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_PBLN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_PBLN]

//>> CLEAR_[CS_CTL_MISC_STATUS1_PBLN]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS1_PBLN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS1_PBLN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_PBLN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS1_PBLN]

//>> GET_[CS_CTL_MISC_STATUS1_PBLN]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_PBLN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_PBLN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_PBLN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_PBLN]

//>> GET_[CS_CTL_MISC_STATUS1_PBLN]
static inline bool GET_CS_CTL_MISC_STATUS1_PBLN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS1_PBLN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_PBLN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_PBLN]

//>> SET_[CS_CTL_MISC_STATUS1_PBNNG]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_PBNNG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_PBNNG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_PBNNG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_PBNNG]

//>> SET_[CS_CTL_MISC_STATUS1_PBNNG]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_PBNNG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_PBNNG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_PBNNG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_PBNNG]

//>> SET_[CS_CTL_MISC_STATUS1_PBNNG]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_PBNNG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS1_PBNNG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_PBNNG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_PBNNG]

//>> CLEAR_[CS_CTL_MISC_STATUS1_PBNNG]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS1_PBNNG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS1_PBNNG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_PBNNG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS1_PBNNG]

//>> GET_[CS_CTL_MISC_STATUS1_PBNNG]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_PBNNG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_PBNNG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_PBNNG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_PBNNG]

//>> GET_[CS_CTL_MISC_STATUS1_PBNNG]
static inline bool GET_CS_CTL_MISC_STATUS1_PBNNG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS1_PBNNG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_PBNNG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_PBNNG]

//>> SET_[CS_CTL_MISC_STATUS1_PBRNVG]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_PBRNVG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_PBRNVG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_PBRNVG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_PBRNVG]

//>> SET_[CS_CTL_MISC_STATUS1_PBRNVG]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_PBRNVG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_PBRNVG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_PBRNVG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_PBRNVG]

//>> SET_[CS_CTL_MISC_STATUS1_PBRNVG]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_PBRNVG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS1_PBRNVG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_PBRNVG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_PBRNVG]

//>> CLEAR_[CS_CTL_MISC_STATUS1_PBRNVG]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS1_PBRNVG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS1_PBRNVG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_PBRNVG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS1_PBRNVG]

//>> GET_[CS_CTL_MISC_STATUS1_PBRNVG]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_PBRNVG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_PBRNVG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_PBRNVG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_PBRNVG]

//>> GET_[CS_CTL_MISC_STATUS1_PBRNVG]
static inline bool GET_CS_CTL_MISC_STATUS1_PBRNVG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS1_PBRNVG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_PBRNVG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_PBRNVG]

//>> SET_[CS_CTL_MISC_STATUS1_ATSREQ]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_ATSREQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_ATSREQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_ATSREQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_ATSREQ]

//>> SET_[CS_CTL_MISC_STATUS1_ATSREQ]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_ATSREQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_ATSREQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_ATSREQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_ATSREQ]

//>> SET_[CS_CTL_MISC_STATUS1_ATSREQ]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_ATSREQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS1_ATSREQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_ATSREQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_ATSREQ]

//>> CLEAR_[CS_CTL_MISC_STATUS1_ATSREQ]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS1_ATSREQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS1_ATSREQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_ATSREQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS1_ATSREQ]

//>> GET_[CS_CTL_MISC_STATUS1_ATSREQ]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_ATSREQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_ATSREQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_ATSREQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_ATSREQ]

//>> GET_[CS_CTL_MISC_STATUS1_ATSREQ]
static inline bool GET_CS_CTL_MISC_STATUS1_ATSREQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS1_ATSREQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_ATSREQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_ATSREQ]

//>> SET_[CS_CTL_MISC_STATUS1_MMIO]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_MMIO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_MMIO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_MMIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_MMIO]

//>> SET_[CS_CTL_MISC_STATUS1_MMIO]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_MMIO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_MMIO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_MMIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_MMIO]

//>> SET_[CS_CTL_MISC_STATUS1_MMIO]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_MMIO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS1_MMIO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_MMIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_MMIO]

//>> CLEAR_[CS_CTL_MISC_STATUS1_MMIO]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS1_MMIO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS1_MMIO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_MMIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS1_MMIO]

//>> GET_[CS_CTL_MISC_STATUS1_MMIO]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_MMIO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_MMIO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_MMIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_MMIO]

//>> GET_[CS_CTL_MISC_STATUS1_MMIO]
static inline bool GET_CS_CTL_MISC_STATUS1_MMIO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS1_MMIO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_MMIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_MMIO]

//>> SET_[CS_CTL_MISC_STATUS1_MMIOSUE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_MMIOSUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_MMIOSUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_MMIOSUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_MMIOSUE]

//>> SET_[CS_CTL_MISC_STATUS1_MMIOSUE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_MMIOSUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_MMIOSUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_MMIOSUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_MMIOSUE]

//>> SET_[CS_CTL_MISC_STATUS1_MMIOSUE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_MMIOSUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS1_MMIOSUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_MMIOSUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_MMIOSUE]

//>> CLEAR_[CS_CTL_MISC_STATUS1_MMIOSUE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS1_MMIOSUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS1_MMIOSUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_MMIOSUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS1_MMIOSUE]

//>> GET_[CS_CTL_MISC_STATUS1_MMIOSUE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_MMIOSUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_MMIOSUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_MMIOSUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_MMIOSUE]

//>> GET_[CS_CTL_MISC_STATUS1_MMIOSUE]
static inline bool GET_CS_CTL_MISC_STATUS1_MMIOSUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS1_MMIOSUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_MMIOSUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_MMIOSUE]

//>> SET_[CS_CTL_MISC_STATUS1_PBRS]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_PBRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_PBRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_PBRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_PBRS]

//>> SET_[CS_CTL_MISC_STATUS1_PBRS]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_PBRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_PBRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_PBRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_PBRS]

//>> SET_[CS_CTL_MISC_STATUS1_PBRS]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_PBRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS1_PBRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_PBRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_PBRS]

//>> CLEAR_[CS_CTL_MISC_STATUS1_PBRS]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS1_PBRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS1_PBRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_PBRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS1_PBRS]

//>> GET_[CS_CTL_MISC_STATUS1_PBRS]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_PBRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_PBRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_PBRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_PBRS]

//>> GET_[CS_CTL_MISC_STATUS1_PBRS]
static inline bool GET_CS_CTL_MISC_STATUS1_PBRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS1_PBRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_PBRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_PBRS]

//>> SET_[CS_CTL_MISC_STATUS1_XARS]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_XARS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_XARS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_XARS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_XARS]

//>> SET_[CS_CTL_MISC_STATUS1_XARS]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_XARS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_XARS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_XARS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_XARS]

//>> SET_[CS_CTL_MISC_STATUS1_XARS]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_XARS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS1_XARS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_XARS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_XARS]

//>> CLEAR_[CS_CTL_MISC_STATUS1_XARS]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS1_XARS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS1_XARS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_XARS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS1_XARS]

//>> GET_[CS_CTL_MISC_STATUS1_XARS]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_XARS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_XARS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_XARS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_XARS]

//>> GET_[CS_CTL_MISC_STATUS1_XARS]
static inline bool GET_CS_CTL_MISC_STATUS1_XARS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS1_XARS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_XARS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_XARS]

//>> SET_[CS_CTL_MISC_STATUS1_ATRR]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_ATRR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_ATRR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_ATRR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_ATRR]

//>> SET_[CS_CTL_MISC_STATUS1_ATRR]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_ATRR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_ATRR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_ATRR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_ATRR]

//>> SET_[CS_CTL_MISC_STATUS1_ATRR]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_ATRR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS1_ATRR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_ATRR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_ATRR]

//>> CLEAR_[CS_CTL_MISC_STATUS1_ATRR]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS1_ATRR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS1_ATRR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_ATRR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS1_ATRR]

//>> GET_[CS_CTL_MISC_STATUS1_ATRR]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_ATRR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_ATRR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_ATRR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_ATRR]

//>> GET_[CS_CTL_MISC_STATUS1_ATRR]
static inline bool GET_CS_CTL_MISC_STATUS1_ATRR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS1_ATRR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_ATRR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_ATRR]

//>> SET_[CS_CTL_MISC_STATUS1_REPLAY]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_REPLAY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_REPLAY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_REPLAY]

//>> SET_[CS_CTL_MISC_STATUS1_REPLAY]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_REPLAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_REPLAY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_REPLAY]

//>> SET_[CS_CTL_MISC_STATUS1_REPLAY]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_REPLAY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS1_REPLAY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_REPLAY]

//>> CLEAR_[CS_CTL_MISC_STATUS1_REPLAY]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS1_REPLAY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS1_REPLAY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS1_REPLAY]

//>> GET_[CS_CTL_MISC_STATUS1_REPLAY]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_REPLAY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_REPLAY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_REPLAY]

//>> GET_[CS_CTL_MISC_STATUS1_REPLAY]
static inline bool GET_CS_CTL_MISC_STATUS1_REPLAY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS1_REPLAY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_REPLAY]

//>> SET_[CS_CTL_MISC_STATUS1_XSL_FAST_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_XSL_FAST_FENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_XSL_FAST_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_XSL_FAST_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_XSL_FAST_FENCE]

//>> SET_[CS_CTL_MISC_STATUS1_XSL_FAST_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_XSL_FAST_FENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_XSL_FAST_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_XSL_FAST_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_XSL_FAST_FENCE]

//>> SET_[CS_CTL_MISC_STATUS1_XSL_FAST_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_XSL_FAST_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS1_XSL_FAST_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_XSL_FAST_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_XSL_FAST_FENCE]

//>> CLEAR_[CS_CTL_MISC_STATUS1_XSL_FAST_FENCE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS1_XSL_FAST_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS1_XSL_FAST_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_XSL_FAST_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS1_XSL_FAST_FENCE]

//>> GET_[CS_CTL_MISC_STATUS1_XSL_FAST_FENCE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_XSL_FAST_FENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_XSL_FAST_FENCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_XSL_FAST_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_XSL_FAST_FENCE]

//>> GET_[CS_CTL_MISC_STATUS1_XSL_FAST_FENCE]
static inline bool GET_CS_CTL_MISC_STATUS1_XSL_FAST_FENCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS1_XSL_FAST_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_XSL_FAST_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_XSL_FAST_FENCE]

//>> SET_[CS_CTL_MISC_STATUS1_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_RESERVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_RESERVED]

//>> SET_[CS_CTL_MISC_STATUS1_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_RESERVED]

//>> SET_[CS_CTL_MISC_STATUS1_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_RESERVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS1_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_RESERVED]

//>> CLEAR_[CS_CTL_MISC_STATUS1_RESERVED]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS1_RESERVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS1_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS1_RESERVED]

//>> GET_[CS_CTL_MISC_STATUS1_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_RESERVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_RESERVED]

//>> GET_[CS_CTL_MISC_STATUS1_RESERVED]
static inline bool GET_CS_CTL_MISC_STATUS1_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS1_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_RESERVED]

//>> SET_[CS_CTL_MISC_STATUS1_FENCE0]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_FENCE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_FENCE0,
           CS_CTL_MISC_STATUS1_FENCE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_FENCE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_FENCE0]

//>> SET_[CS_CTL_MISC_STATUS1_FENCE0]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_FENCE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_FENCE0,
           CS_CTL_MISC_STATUS1_FENCE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_FENCE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_FENCE0]

//>> GET_[CS_CTL_MISC_STATUS1_FENCE0]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_FENCE0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_FENCE0,
           CS_CTL_MISC_STATUS1_FENCE0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_FENCE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_FENCE0]

//>> SET_[CS_CTL_MISC_STATUS1_BRK0_RLX]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_BRK0_RLX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_BRK0_RLX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_BRK0_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_BRK0_RLX]

//>> SET_[CS_CTL_MISC_STATUS1_BRK0_RLX]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_BRK0_RLX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_BRK0_RLX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_BRK0_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_BRK0_RLX]

//>> SET_[CS_CTL_MISC_STATUS1_BRK0_RLX]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_BRK0_RLX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS1_BRK0_RLX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_BRK0_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_BRK0_RLX]

//>> CLEAR_[CS_CTL_MISC_STATUS1_BRK0_RLX]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS1_BRK0_RLX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS1_BRK0_RLX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_BRK0_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS1_BRK0_RLX]

//>> GET_[CS_CTL_MISC_STATUS1_BRK0_RLX]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_BRK0_RLX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_BRK0_RLX,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_BRK0_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_BRK0_RLX]

//>> GET_[CS_CTL_MISC_STATUS1_BRK0_RLX]
static inline bool GET_CS_CTL_MISC_STATUS1_BRK0_RLX(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS1_BRK0_RLX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_BRK0_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_BRK0_RLX]

//>> SET_[CS_CTL_MISC_STATUS1_NVREQ0]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_NVREQ0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_NVREQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_NVREQ0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_NVREQ0]

//>> SET_[CS_CTL_MISC_STATUS1_NVREQ0]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_NVREQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_NVREQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_NVREQ0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_NVREQ0]

//>> SET_[CS_CTL_MISC_STATUS1_NVREQ0]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_NVREQ0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS1_NVREQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_NVREQ0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_NVREQ0]

//>> CLEAR_[CS_CTL_MISC_STATUS1_NVREQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS1_NVREQ0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS1_NVREQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_NVREQ0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS1_NVREQ0]

//>> GET_[CS_CTL_MISC_STATUS1_NVREQ0]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_NVREQ0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_NVREQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_NVREQ0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_NVREQ0]

//>> GET_[CS_CTL_MISC_STATUS1_NVREQ0]
static inline bool GET_CS_CTL_MISC_STATUS1_NVREQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS1_NVREQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_NVREQ0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_NVREQ0]

//>> SET_[CS_CTL_MISC_STATUS1_NVDGD0]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_NVDGD0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_NVDGD0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_NVDGD0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_NVDGD0]

//>> SET_[CS_CTL_MISC_STATUS1_NVDGD0]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_NVDGD0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_NVDGD0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_NVDGD0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_NVDGD0]

//>> SET_[CS_CTL_MISC_STATUS1_NVDGD0]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_NVDGD0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS1_NVDGD0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_NVDGD0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_NVDGD0]

//>> CLEAR_[CS_CTL_MISC_STATUS1_NVDGD0]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS1_NVDGD0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS1_NVDGD0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_NVDGD0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS1_NVDGD0]

//>> GET_[CS_CTL_MISC_STATUS1_NVDGD0]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_NVDGD0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_NVDGD0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_NVDGD0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_NVDGD0]

//>> GET_[CS_CTL_MISC_STATUS1_NVDGD0]
static inline bool GET_CS_CTL_MISC_STATUS1_NVDGD0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS1_NVDGD0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_NVDGD0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_NVDGD0]

//>> SET_[CS_CTL_MISC_STATUS1_NVRS0]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_NVRS0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_NVRS0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_NVRS0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_NVRS0]

//>> SET_[CS_CTL_MISC_STATUS1_NVRS0]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_NVRS0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_NVRS0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_NVRS0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_NVRS0]

//>> SET_[CS_CTL_MISC_STATUS1_NVRS0]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_NVRS0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS1_NVRS0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_NVRS0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_NVRS0]

//>> CLEAR_[CS_CTL_MISC_STATUS1_NVRS0]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS1_NVRS0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS1_NVRS0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_NVRS0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS1_NVRS0]

//>> GET_[CS_CTL_MISC_STATUS1_NVRS0]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_NVRS0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_NVRS0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_NVRS0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_NVRS0]

//>> GET_[CS_CTL_MISC_STATUS1_NVRS0]
static inline bool GET_CS_CTL_MISC_STATUS1_NVRS0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS1_NVRS0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_NVRS0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_NVRS0]

//>> SET_[CS_CTL_MISC_STATUS1_BRK0_AM_FENCED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_BRK0_AM_FENCED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_BRK0_AM_FENCED,
           CS_CTL_MISC_STATUS1_BRK0_AM_FENCED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_BRK0_AM_FENCED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_BRK0_AM_FENCED]

//>> SET_[CS_CTL_MISC_STATUS1_BRK0_AM_FENCED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_BRK0_AM_FENCED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_BRK0_AM_FENCED,
           CS_CTL_MISC_STATUS1_BRK0_AM_FENCED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_BRK0_AM_FENCED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_BRK0_AM_FENCED]

//>> GET_[CS_CTL_MISC_STATUS1_BRK0_AM_FENCED]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_BRK0_AM_FENCED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_BRK0_AM_FENCED,
           CS_CTL_MISC_STATUS1_BRK0_AM_FENCED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_BRK0_AM_FENCED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_BRK0_AM_FENCED]

//>> SET_[CS_CTL_MISC_STATUS1_BRK0_NTL_REQ_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_BRK0_NTL_REQ_FENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_BRK0_NTL_REQ_FENCE,
           CS_CTL_MISC_STATUS1_BRK0_NTL_REQ_FENCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_BRK0_NTL_REQ_FENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_BRK0_NTL_REQ_FENCE]

//>> SET_[CS_CTL_MISC_STATUS1_BRK0_NTL_REQ_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_BRK0_NTL_REQ_FENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_BRK0_NTL_REQ_FENCE,
           CS_CTL_MISC_STATUS1_BRK0_NTL_REQ_FENCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_BRK0_NTL_REQ_FENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_BRK0_NTL_REQ_FENCE]

//>> GET_[CS_CTL_MISC_STATUS1_BRK0_NTL_REQ_FENCE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_BRK0_NTL_REQ_FENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_BRK0_NTL_REQ_FENCE,
           CS_CTL_MISC_STATUS1_BRK0_NTL_REQ_FENCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_BRK0_NTL_REQ_FENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_BRK0_NTL_REQ_FENCE]

//>> SET_[CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE]

//>> SET_[CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE]

//>> SET_[CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE]

//>> CLEAR_[CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE]

//>> GET_[CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE]

//>> GET_[CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE]
static inline bool GET_CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE]

//>> SET_[CS_CTL_MISC_STATUS1_BRK0_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_BRK0_RESERVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_BRK0_RESERVED,
           CS_CTL_MISC_STATUS1_BRK0_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_BRK0_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_BRK0_RESERVED]

//>> SET_[CS_CTL_MISC_STATUS1_BRK0_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS1_BRK0_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS1_BRK0_RESERVED,
           CS_CTL_MISC_STATUS1_BRK0_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_BRK0_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS1_BRK0_RESERVED]

//>> GET_[CS_CTL_MISC_STATUS1_BRK0_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS1_BRK0_RESERVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS1_BRK0_RESERVED,
           CS_CTL_MISC_STATUS1_BRK0_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS1_BRK0_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS1_BRK0_RESERVED]

//>> PREP_[CS_SM2_SNP_MISC_NDT0_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CS_SM2_SNP_MISC_NDT0_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM2_SNP_MISC_NDT0_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CS_SM2_SNP_MISC_NDT0_BAR]

//>> GET_[CS_SM2_SNP_MISC_NDT0_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CS_SM2_SNP_MISC_NDT0_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM2_SNP_MISC_NDT0_BAR;
#endif
    return fapi2::getScom(i_target, CS_SM2_SNP_MISC_NDT0_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_NDT0_BAR]

//>> PUT_[CS_SM2_SNP_MISC_NDT0_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CS_SM2_SNP_MISC_NDT0_BAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return fapi2::putScom(i_target, CS_SM2_SNP_MISC_NDT0_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CS_SM2_SNP_MISC_NDT0_BAR]


//>> SET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]

//>> SET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]

//>> SET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]

//>> CLEAR_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]

//>> GET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]

//>> GET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]
static inline bool GET_CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]

//>> SET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]

//>> SET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]

//>> SET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]

//>> CLEAR_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]

//>> GET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]

//>> GET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]
static inline bool GET_CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]

//>> SET_[CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]

//>> SET_[CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]

//>> SET_[CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]

//>> CLEAR_[CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]

//>> GET_[CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]

//>> GET_[CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]
static inline bool GET_CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]

//>> SET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR,
           CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR]

//>> SET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR,
           CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR]

//>> GET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR,
           CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR]

//>> SET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]

//>> SET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]

//>> SET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]

//>> CLEAR_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]

//>> GET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]

//>> GET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]
static inline bool GET_CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]

//>> SET_[CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED2]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED2,
           CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED2]

//>> SET_[CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED2]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED2,
           CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED2]

//>> GET_[CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED2]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED2,
           CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED2]

//>> SET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE,
           CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE]

//>> SET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE,
           CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE]

//>> GET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT0_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE,
           CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE]

//>> PREP_[CS_SM2_SNP_MISC_NDT1_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CS_SM2_SNP_MISC_NDT1_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM2_SNP_MISC_NDT1_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CS_SM2_SNP_MISC_NDT1_BAR]

//>> GET_[CS_SM2_SNP_MISC_NDT1_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CS_SM2_SNP_MISC_NDT1_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM2_SNP_MISC_NDT1_BAR;
#endif
    return fapi2::getScom(i_target, CS_SM2_SNP_MISC_NDT1_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_NDT1_BAR]

//>> PUT_[CS_SM2_SNP_MISC_NDT1_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CS_SM2_SNP_MISC_NDT1_BAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return fapi2::putScom(i_target, CS_SM2_SNP_MISC_NDT1_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CS_SM2_SNP_MISC_NDT1_BAR]


//>> SET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]

//>> SET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]

//>> SET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]

//>> CLEAR_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]

//>> GET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]

//>> GET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]
static inline bool GET_CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]

//>> SET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]

//>> SET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]

//>> SET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]

//>> CLEAR_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]

//>> GET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]

//>> GET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]
static inline bool GET_CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]

//>> SET_[CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]

//>> SET_[CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]

//>> SET_[CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]

//>> CLEAR_[CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]

//>> GET_[CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]

//>> GET_[CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]
static inline bool GET_CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]

//>> SET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR,
           CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR]

//>> SET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR,
           CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR]

//>> GET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR,
           CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR]

//>> SET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]

//>> SET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]

//>> SET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]

//>> CLEAR_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]

//>> GET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]

//>> GET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]
static inline bool GET_CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]

//>> SET_[CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED2]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED2,
           CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED2]

//>> SET_[CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED2]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED2,
           CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED2]

//>> GET_[CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED2]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED2,
           CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED2]

//>> SET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE,
           CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE]

//>> SET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE,
           CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE]

//>> GET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_NDT1_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE,
           CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE]

//>> PREP_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM2_SNP_MISC_TOPOLOGY_TABLE0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0]

//>> GET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM2_SNP_MISC_TOPOLOGY_TABLE0;
#endif
    return fapi2::getScom(i_target, CS_SM2_SNP_MISC_TOPOLOGY_TABLE0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0]

//>> PUT_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return fapi2::putScom(i_target, CS_SM2_SNP_MISC_TOPOLOGY_TABLE0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0]


//>> SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7,
           CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7]

//>> SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7,
           CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7]

//>> GET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7,
           CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7]

//>> SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY0]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY0,
           CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY0]

//>> SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY0]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY0,
           CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY0]

//>> GET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY0]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY0,
           CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY0]

//>> SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY1,
           CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY1]

//>> SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY1,
           CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY1]

//>> GET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY1]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY1,
           CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY1]

//>> SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY2]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY2,
           CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY2]

//>> SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY2]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY2,
           CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY2]

//>> GET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY2]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY2,
           CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY2]

//>> SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY3]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY3,
           CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY3]

//>> SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY3]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY3,
           CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY3]

//>> GET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY3]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY3,
           CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY3]

//>> SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY4]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY4,
           CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY4]

//>> SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY4]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY4,
           CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY4]

//>> GET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY4]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY4,
           CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY4]

//>> SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY5]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY5,
           CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY5]

//>> SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY5]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY5,
           CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY5]

//>> GET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY5]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY5,
           CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY5]

//>> SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY6]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY6,
           CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY6]

//>> SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY6]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY6,
           CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY6]

//>> GET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY6]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY6,
           CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY6]

//>> SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY7]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY7,
           CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY7]

//>> SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY7]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY7,
           CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY7]

//>> GET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY7]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY7,
           CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY7]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
