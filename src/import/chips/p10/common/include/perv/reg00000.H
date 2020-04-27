/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/perv/reg00000.H $         */
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

#ifndef __PERV_REG00000_H_
#define __PERV_REG00000_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> PREP_[CLK_REGION]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLK_REGION(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_REGION;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CLK_REGION]

//>> GET_[CLK_REGION]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLK_REGION(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_REGION;
#endif
    return fapi2::getScom(i_target, CLK_REGION, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CLK_REGION]

//>> PUT_[CLK_REGION]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLK_REGION(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return fapi2::putScom(i_target, CLK_REGION, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CLK_REGION]


//>> SET_[CLK_REGION_CLOCK_CMD]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_CMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_CMD,
           CLK_REGION_CLOCK_CMD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_REGION_CLOCK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_CMD]

//>> SET_[CLK_REGION_CLOCK_CMD]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_CMD,
           CLK_REGION_CLOCK_CMD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_REGION_CLOCK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_CMD]

//>> GET_[CLK_REGION_CLOCK_CMD]
static inline fapi2::buffer<uint64_t>& GET_CLK_REGION_CLOCK_CMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.extractToRight<CLK_REGION_CLOCK_CMD,
           CLK_REGION_CLOCK_CMD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_REGION_CLOCK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_CMD]

//>> SET_[CLK_REGION_SLAVE_MODE]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_SLAVE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_SLAVE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_REGION_SLAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_SLAVE_MODE]

//>> SET_[CLK_REGION_SLAVE_MODE]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_SLAVE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_SLAVE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_REGION_SLAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_SLAVE_MODE]

//>> SET_[CLK_REGION_SLAVE_MODE]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_SLAVE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.setBit<CLK_REGION_SLAVE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_REGION_SLAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_SLAVE_MODE]

//>> CLEAR_[CLK_REGION_SLAVE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_REGION_SLAVE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.clearBit<CLK_REGION_SLAVE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_REGION_SLAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_REGION_SLAVE_MODE]

//>> GET_[CLK_REGION_SLAVE_MODE]
static inline fapi2::buffer<uint64_t>& GET_CLK_REGION_SLAVE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.extractToRight<CLK_REGION_SLAVE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_REGION_SLAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_SLAVE_MODE]

//>> GET_[CLK_REGION_SLAVE_MODE]
static inline bool GET_CLK_REGION_SLAVE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.getBit<CLK_REGION_SLAVE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_REGION_SLAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_SLAVE_MODE]

//>> SET_[CLK_REGION_MASTER_MODE]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_MASTER_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_MASTER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_REGION_MASTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_MASTER_MODE]

//>> SET_[CLK_REGION_MASTER_MODE]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_MASTER_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_MASTER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_REGION_MASTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_MASTER_MODE]

//>> SET_[CLK_REGION_MASTER_MODE]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_MASTER_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.setBit<CLK_REGION_MASTER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_REGION_MASTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_MASTER_MODE]

//>> CLEAR_[CLK_REGION_MASTER_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_REGION_MASTER_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.clearBit<CLK_REGION_MASTER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_REGION_MASTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_REGION_MASTER_MODE]

//>> GET_[CLK_REGION_MASTER_MODE]
static inline fapi2::buffer<uint64_t>& GET_CLK_REGION_MASTER_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.extractToRight<CLK_REGION_MASTER_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_REGION_MASTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_MASTER_MODE]

//>> GET_[CLK_REGION_MASTER_MODE]
static inline bool GET_CLK_REGION_MASTER_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.getBit<CLK_REGION_MASTER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_REGION_MASTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_MASTER_MODE]

//>> SET_[CLK_REGION_CLOCK_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_PERV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_PERV]

//>> SET_[CLK_REGION_CLOCK_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_PERV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_PERV]

//>> SET_[CLK_REGION_CLOCK_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.setBit<CLK_REGION_CLOCK_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_PERV]

//>> CLEAR_[CLK_REGION_CLOCK_REGION_PERV]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_REGION_CLOCK_REGION_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.clearBit<CLK_REGION_CLOCK_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_REGION_CLOCK_REGION_PERV]

//>> GET_[CLK_REGION_CLOCK_REGION_PERV]
static inline fapi2::buffer<uint64_t>& GET_CLK_REGION_CLOCK_REGION_PERV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.extractToRight<CLK_REGION_CLOCK_REGION_PERV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_PERV]

//>> GET_[CLK_REGION_CLOCK_REGION_PERV]
static inline bool GET_CLK_REGION_CLOCK_REGION_PERV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.getBit<CLK_REGION_CLOCK_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_PERV]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT1]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT1]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.setBit<CLK_REGION_CLOCK_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT1]

//>> CLEAR_[CLK_REGION_CLOCK_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_REGION_CLOCK_REGION_UNIT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.clearBit<CLK_REGION_CLOCK_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_REGION_CLOCK_REGION_UNIT1]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& GET_CLK_REGION_CLOCK_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.extractToRight<CLK_REGION_CLOCK_REGION_UNIT1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT1]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT1]
static inline bool GET_CLK_REGION_CLOCK_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.getBit<CLK_REGION_CLOCK_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT1]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT2]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT2]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.setBit<CLK_REGION_CLOCK_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT2]

//>> CLEAR_[CLK_REGION_CLOCK_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_REGION_CLOCK_REGION_UNIT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.clearBit<CLK_REGION_CLOCK_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_REGION_CLOCK_REGION_UNIT2]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& GET_CLK_REGION_CLOCK_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.extractToRight<CLK_REGION_CLOCK_REGION_UNIT2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT2]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT2]
static inline bool GET_CLK_REGION_CLOCK_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.getBit<CLK_REGION_CLOCK_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT2]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT3]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT3]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.setBit<CLK_REGION_CLOCK_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT3]

//>> CLEAR_[CLK_REGION_CLOCK_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_REGION_CLOCK_REGION_UNIT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.clearBit<CLK_REGION_CLOCK_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_REGION_CLOCK_REGION_UNIT3]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& GET_CLK_REGION_CLOCK_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.extractToRight<CLK_REGION_CLOCK_REGION_UNIT3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT3]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT3]
static inline bool GET_CLK_REGION_CLOCK_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.getBit<CLK_REGION_CLOCK_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT3]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT4]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT4]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.setBit<CLK_REGION_CLOCK_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT4]

//>> CLEAR_[CLK_REGION_CLOCK_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_REGION_CLOCK_REGION_UNIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.clearBit<CLK_REGION_CLOCK_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_REGION_CLOCK_REGION_UNIT4]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& GET_CLK_REGION_CLOCK_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.extractToRight<CLK_REGION_CLOCK_REGION_UNIT4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT4]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT4]
static inline bool GET_CLK_REGION_CLOCK_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.getBit<CLK_REGION_CLOCK_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT4]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT5]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT5]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.setBit<CLK_REGION_CLOCK_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT5]

//>> CLEAR_[CLK_REGION_CLOCK_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_REGION_CLOCK_REGION_UNIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.clearBit<CLK_REGION_CLOCK_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_REGION_CLOCK_REGION_UNIT5]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& GET_CLK_REGION_CLOCK_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.extractToRight<CLK_REGION_CLOCK_REGION_UNIT5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT5]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT5]
static inline bool GET_CLK_REGION_CLOCK_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.getBit<CLK_REGION_CLOCK_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT5]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT6]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT6]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.setBit<CLK_REGION_CLOCK_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT6]

//>> CLEAR_[CLK_REGION_CLOCK_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_REGION_CLOCK_REGION_UNIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.clearBit<CLK_REGION_CLOCK_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_REGION_CLOCK_REGION_UNIT6]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& GET_CLK_REGION_CLOCK_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.extractToRight<CLK_REGION_CLOCK_REGION_UNIT6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT6]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT6]
static inline bool GET_CLK_REGION_CLOCK_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.getBit<CLK_REGION_CLOCK_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT6]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT7]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT7]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.setBit<CLK_REGION_CLOCK_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT7]

//>> CLEAR_[CLK_REGION_CLOCK_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_REGION_CLOCK_REGION_UNIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.clearBit<CLK_REGION_CLOCK_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_REGION_CLOCK_REGION_UNIT7]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& GET_CLK_REGION_CLOCK_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.extractToRight<CLK_REGION_CLOCK_REGION_UNIT7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT7]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT7]
static inline bool GET_CLK_REGION_CLOCK_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.getBit<CLK_REGION_CLOCK_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT7]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT8]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT8]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.setBit<CLK_REGION_CLOCK_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT8]

//>> CLEAR_[CLK_REGION_CLOCK_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_REGION_CLOCK_REGION_UNIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.clearBit<CLK_REGION_CLOCK_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_REGION_CLOCK_REGION_UNIT8]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& GET_CLK_REGION_CLOCK_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.extractToRight<CLK_REGION_CLOCK_REGION_UNIT8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT8]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT8]
static inline bool GET_CLK_REGION_CLOCK_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.getBit<CLK_REGION_CLOCK_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT8]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT9]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT9]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.setBit<CLK_REGION_CLOCK_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT9]

//>> CLEAR_[CLK_REGION_CLOCK_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_REGION_CLOCK_REGION_UNIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.clearBit<CLK_REGION_CLOCK_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_REGION_CLOCK_REGION_UNIT9]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& GET_CLK_REGION_CLOCK_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.extractToRight<CLK_REGION_CLOCK_REGION_UNIT9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT9]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT9]
static inline bool GET_CLK_REGION_CLOCK_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.getBit<CLK_REGION_CLOCK_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT9]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT10]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT10]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.setBit<CLK_REGION_CLOCK_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT10]

//>> CLEAR_[CLK_REGION_CLOCK_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_REGION_CLOCK_REGION_UNIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.clearBit<CLK_REGION_CLOCK_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_REGION_CLOCK_REGION_UNIT10]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& GET_CLK_REGION_CLOCK_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.extractToRight<CLK_REGION_CLOCK_REGION_UNIT10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT10]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT10]
static inline bool GET_CLK_REGION_CLOCK_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.getBit<CLK_REGION_CLOCK_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT10]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT11]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT11]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.setBit<CLK_REGION_CLOCK_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT11]

//>> CLEAR_[CLK_REGION_CLOCK_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_REGION_CLOCK_REGION_UNIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.clearBit<CLK_REGION_CLOCK_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_REGION_CLOCK_REGION_UNIT11]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& GET_CLK_REGION_CLOCK_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.extractToRight<CLK_REGION_CLOCK_REGION_UNIT11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT11]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT11]
static inline bool GET_CLK_REGION_CLOCK_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.getBit<CLK_REGION_CLOCK_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT11]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT12]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT12]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.setBit<CLK_REGION_CLOCK_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT12]

//>> CLEAR_[CLK_REGION_CLOCK_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_REGION_CLOCK_REGION_UNIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.clearBit<CLK_REGION_CLOCK_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_REGION_CLOCK_REGION_UNIT12]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& GET_CLK_REGION_CLOCK_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.extractToRight<CLK_REGION_CLOCK_REGION_UNIT12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT12]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT12]
static inline bool GET_CLK_REGION_CLOCK_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.getBit<CLK_REGION_CLOCK_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT12]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT13]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT13]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.setBit<CLK_REGION_CLOCK_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT13]

//>> CLEAR_[CLK_REGION_CLOCK_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_REGION_CLOCK_REGION_UNIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.clearBit<CLK_REGION_CLOCK_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_REGION_CLOCK_REGION_UNIT13]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& GET_CLK_REGION_CLOCK_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.extractToRight<CLK_REGION_CLOCK_REGION_UNIT13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT13]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT13]
static inline bool GET_CLK_REGION_CLOCK_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.getBit<CLK_REGION_CLOCK_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT13]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT14]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_REGION_UNIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT14]

//>> SET_[CLK_REGION_CLOCK_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_REGION_UNIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.setBit<CLK_REGION_CLOCK_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_REGION_UNIT14]

//>> CLEAR_[CLK_REGION_CLOCK_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_REGION_CLOCK_REGION_UNIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.clearBit<CLK_REGION_CLOCK_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_REGION_CLOCK_REGION_UNIT14]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& GET_CLK_REGION_CLOCK_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.extractToRight<CLK_REGION_CLOCK_REGION_UNIT14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT14]

//>> GET_[CLK_REGION_CLOCK_REGION_UNIT14]
static inline bool GET_CLK_REGION_CLOCK_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.getBit<CLK_REGION_CLOCK_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_REGION_CLOCK_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_REGION_UNIT14]

//>> SET_[CLK_REGION_SEL_THOLD_SL]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_SEL_THOLD_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_SEL_THOLD_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_REGION_SEL_THOLD_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_SEL_THOLD_SL]

//>> SET_[CLK_REGION_SEL_THOLD_SL]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_SEL_THOLD_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_SEL_THOLD_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_REGION_SEL_THOLD_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_SEL_THOLD_SL]

//>> SET_[CLK_REGION_SEL_THOLD_SL]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_SEL_THOLD_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.setBit<CLK_REGION_SEL_THOLD_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_REGION_SEL_THOLD_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_SEL_THOLD_SL]

//>> CLEAR_[CLK_REGION_SEL_THOLD_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_REGION_SEL_THOLD_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.clearBit<CLK_REGION_SEL_THOLD_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_REGION_SEL_THOLD_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_REGION_SEL_THOLD_SL]

//>> GET_[CLK_REGION_SEL_THOLD_SL]
static inline fapi2::buffer<uint64_t>& GET_CLK_REGION_SEL_THOLD_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.extractToRight<CLK_REGION_SEL_THOLD_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_REGION_SEL_THOLD_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_SEL_THOLD_SL]

//>> GET_[CLK_REGION_SEL_THOLD_SL]
static inline bool GET_CLK_REGION_SEL_THOLD_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.getBit<CLK_REGION_SEL_THOLD_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_REGION_SEL_THOLD_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_SEL_THOLD_SL]

//>> SET_[CLK_REGION_SEL_THOLD_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_SEL_THOLD_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_SEL_THOLD_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_REGION_SEL_THOLD_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_SEL_THOLD_NSL]

//>> SET_[CLK_REGION_SEL_THOLD_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_SEL_THOLD_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_SEL_THOLD_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_REGION_SEL_THOLD_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_SEL_THOLD_NSL]

//>> SET_[CLK_REGION_SEL_THOLD_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_SEL_THOLD_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.setBit<CLK_REGION_SEL_THOLD_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_REGION_SEL_THOLD_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_SEL_THOLD_NSL]

//>> CLEAR_[CLK_REGION_SEL_THOLD_NSL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_REGION_SEL_THOLD_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.clearBit<CLK_REGION_SEL_THOLD_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_REGION_SEL_THOLD_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_REGION_SEL_THOLD_NSL]

//>> GET_[CLK_REGION_SEL_THOLD_NSL]
static inline fapi2::buffer<uint64_t>& GET_CLK_REGION_SEL_THOLD_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.extractToRight<CLK_REGION_SEL_THOLD_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_REGION_SEL_THOLD_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_SEL_THOLD_NSL]

//>> GET_[CLK_REGION_SEL_THOLD_NSL]
static inline bool GET_CLK_REGION_SEL_THOLD_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.getBit<CLK_REGION_SEL_THOLD_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_REGION_SEL_THOLD_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_SEL_THOLD_NSL]

//>> SET_[CLK_REGION_SEL_THOLD_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_SEL_THOLD_ARY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_SEL_THOLD_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_REGION_SEL_THOLD_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_SEL_THOLD_ARY]

//>> SET_[CLK_REGION_SEL_THOLD_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_SEL_THOLD_ARY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_SEL_THOLD_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_REGION_SEL_THOLD_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_SEL_THOLD_ARY]

//>> SET_[CLK_REGION_SEL_THOLD_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_SEL_THOLD_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.setBit<CLK_REGION_SEL_THOLD_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_REGION_SEL_THOLD_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_SEL_THOLD_ARY]

//>> CLEAR_[CLK_REGION_SEL_THOLD_ARY]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_REGION_SEL_THOLD_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.clearBit<CLK_REGION_SEL_THOLD_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_REGION_SEL_THOLD_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_REGION_SEL_THOLD_ARY]

//>> GET_[CLK_REGION_SEL_THOLD_ARY]
static inline fapi2::buffer<uint64_t>& GET_CLK_REGION_SEL_THOLD_ARY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.extractToRight<CLK_REGION_SEL_THOLD_ARY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_REGION_SEL_THOLD_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_SEL_THOLD_ARY]

//>> GET_[CLK_REGION_SEL_THOLD_ARY]
static inline bool GET_CLK_REGION_SEL_THOLD_ARY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.getBit<CLK_REGION_SEL_THOLD_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_REGION_SEL_THOLD_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_SEL_THOLD_ARY]

//>> SET_[CLK_REGION_CLOCK_PULSE_USE_EVEN]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_PULSE_USE_EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_PULSE_USE_EVEN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_REGION_CLOCK_PULSE_USE_EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_PULSE_USE_EVEN]

//>> SET_[CLK_REGION_CLOCK_PULSE_USE_EVEN]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_PULSE_USE_EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_PULSE_USE_EVEN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_REGION_CLOCK_PULSE_USE_EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_PULSE_USE_EVEN]

//>> SET_[CLK_REGION_CLOCK_PULSE_USE_EVEN]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_PULSE_USE_EVEN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.setBit<CLK_REGION_CLOCK_PULSE_USE_EVEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_REGION_CLOCK_PULSE_USE_EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_PULSE_USE_EVEN]

//>> CLEAR_[CLK_REGION_CLOCK_PULSE_USE_EVEN]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_REGION_CLOCK_PULSE_USE_EVEN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.clearBit<CLK_REGION_CLOCK_PULSE_USE_EVEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_REGION_CLOCK_PULSE_USE_EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_REGION_CLOCK_PULSE_USE_EVEN]

//>> GET_[CLK_REGION_CLOCK_PULSE_USE_EVEN]
static inline fapi2::buffer<uint64_t>& GET_CLK_REGION_CLOCK_PULSE_USE_EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.extractToRight<CLK_REGION_CLOCK_PULSE_USE_EVEN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_REGION_CLOCK_PULSE_USE_EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_PULSE_USE_EVEN]

//>> GET_[CLK_REGION_CLOCK_PULSE_USE_EVEN]
static inline bool GET_CLK_REGION_CLOCK_PULSE_USE_EVEN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.getBit<CLK_REGION_CLOCK_PULSE_USE_EVEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_REGION_CLOCK_PULSE_USE_EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_PULSE_USE_EVEN]

//>> SET_[CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK]

//>> SET_[CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK]

//>> SET_[CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.setBit<CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK]

//>> CLEAR_[CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.clearBit<CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK]

//>> GET_[CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK]
static inline fapi2::buffer<uint64_t>& GET_CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.extractToRight<CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK]

//>> GET_[CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK]
static inline bool GET_CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.getBit<CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK]

//>> SET_[CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK]

//>> SET_[CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.insertFromRight<CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK]

//>> SET_[CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK]
static inline fapi2::buffer<uint64_t>& SET_CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.setBit<CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK]

//>> CLEAR_[CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return o_data.clearBit<CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK]

//>> GET_[CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK]
static inline fapi2::buffer<uint64_t>& GET_CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.extractToRight<CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK]

//>> GET_[CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK]
static inline bool GET_CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_REGION));
#endif
    return i_data.getBit<CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK]

//>> PREP_[CPLT_CONF0_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CONF0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CONF0_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CONF0_WO_CLEAR]

//>> GET_[CPLT_CONF0_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CONF0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CONF0_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPLT_CONF0_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CONF0_WO_CLEAR]

//>> PUT_[CPLT_CONF0_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CONF0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CONF0_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CONF0_WO_CLEAR]

//>> PREP_[CPLT_CONF0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CONF0_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CONF0_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CONF0_WO_OR]

//>> GET_[CPLT_CONF0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CONF0_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CONF0_WO_OR;
#endif
    return fapi2::getScom(i_target, CPLT_CONF0_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CONF0_WO_OR]

//>> PUT_[CPLT_CONF0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CONF0_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CONF0_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CONF0_WO_OR]


//>> SET_[CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC,
           CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC]

//>> SET_[CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC,
           CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC]

//>> GET_[CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC,
           CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC]

//>> SET_[CPLT_CONF0_RESERVED_6G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_6G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_6G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_RESERVED_6G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_6G]

//>> SET_[CPLT_CONF0_RESERVED_6G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_6G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_6G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_RESERVED_6G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_6G]

//>> SET_[CPLT_CONF0_RESERVED_6G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_6G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_RESERVED_6G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_RESERVED_6G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_6G]

//>> CLEAR_[CPLT_CONF0_RESERVED_6G]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_RESERVED_6G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_RESERVED_6G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_RESERVED_6G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_RESERVED_6G]

//>> GET_[CPLT_CONF0_RESERVED_6G]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_RESERVED_6G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_RESERVED_6G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_RESERVED_6G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_6G]

//>> GET_[CPLT_CONF0_RESERVED_6G]
static inline bool GET_CPLT_CONF0_RESERVED_6G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_RESERVED_6G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_RESERVED_6G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_6G]

//>> SET_[CPLT_CONF0_RESERVED_7G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_7G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_7G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_RESERVED_7G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_7G]

//>> SET_[CPLT_CONF0_RESERVED_7G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_7G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_7G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_RESERVED_7G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_7G]

//>> SET_[CPLT_CONF0_RESERVED_7G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_7G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_RESERVED_7G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_RESERVED_7G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_7G]

//>> CLEAR_[CPLT_CONF0_RESERVED_7G]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_RESERVED_7G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_RESERVED_7G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_RESERVED_7G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_RESERVED_7G]

//>> GET_[CPLT_CONF0_RESERVED_7G]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_RESERVED_7G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_RESERVED_7G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_RESERVED_7G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_7G]

//>> GET_[CPLT_CONF0_RESERVED_7G]
static inline bool GET_CPLT_CONF0_RESERVED_7G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_RESERVED_7G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_RESERVED_7G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_7G]

//>> SET_[CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC,
           CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC]

//>> SET_[CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC,
           CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC]

//>> GET_[CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC,
           CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC]

//>> SET_[CPLT_CONF0_RESERVED_14G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_14G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_14G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_RESERVED_14G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_14G]

//>> SET_[CPLT_CONF0_RESERVED_14G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_14G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_14G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_RESERVED_14G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_14G]

//>> SET_[CPLT_CONF0_RESERVED_14G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_14G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_RESERVED_14G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_RESERVED_14G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_14G]

//>> CLEAR_[CPLT_CONF0_RESERVED_14G]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_RESERVED_14G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_RESERVED_14G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_RESERVED_14G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_RESERVED_14G]

//>> GET_[CPLT_CONF0_RESERVED_14G]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_RESERVED_14G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_RESERVED_14G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_RESERVED_14G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_14G]

//>> GET_[CPLT_CONF0_RESERVED_14G]
static inline bool GET_CPLT_CONF0_RESERVED_14G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_RESERVED_14G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_RESERVED_14G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_14G]

//>> SET_[CPLT_CONF0_RESERVED_15G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_15G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_15G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_RESERVED_15G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_15G]

//>> SET_[CPLT_CONF0_RESERVED_15G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_15G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_15G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_RESERVED_15G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_15G]

//>> SET_[CPLT_CONF0_RESERVED_15G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_15G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_RESERVED_15G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_RESERVED_15G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_15G]

//>> CLEAR_[CPLT_CONF0_RESERVED_15G]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_RESERVED_15G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_RESERVED_15G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_RESERVED_15G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_RESERVED_15G]

//>> GET_[CPLT_CONF0_RESERVED_15G]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_RESERVED_15G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_RESERVED_15G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_RESERVED_15G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_15G]

//>> GET_[CPLT_CONF0_RESERVED_15G]
static inline bool GET_CPLT_CONF0_RESERVED_15G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_RESERVED_15G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_RESERVED_15G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_15G]

//>> SET_[CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC,
           CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC]

//>> SET_[CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC,
           CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC]

//>> GET_[CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC,
           CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC]

//>> SET_[CPLT_CONF0_RESERVED_22G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_22G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_22G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_RESERVED_22G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_22G]

//>> SET_[CPLT_CONF0_RESERVED_22G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_22G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_22G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_RESERVED_22G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_22G]

//>> SET_[CPLT_CONF0_RESERVED_22G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_22G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_RESERVED_22G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_RESERVED_22G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_22G]

//>> CLEAR_[CPLT_CONF0_RESERVED_22G]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_RESERVED_22G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_RESERVED_22G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_RESERVED_22G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_RESERVED_22G]

//>> GET_[CPLT_CONF0_RESERVED_22G]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_RESERVED_22G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_RESERVED_22G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_RESERVED_22G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_22G]

//>> GET_[CPLT_CONF0_RESERVED_22G]
static inline bool GET_CPLT_CONF0_RESERVED_22G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_RESERVED_22G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_RESERVED_22G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_22G]

//>> SET_[CPLT_CONF0_RESERVED_23G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_23G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_23G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_RESERVED_23G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_23G]

//>> SET_[CPLT_CONF0_RESERVED_23G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_23G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_23G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_RESERVED_23G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_23G]

//>> SET_[CPLT_CONF0_RESERVED_23G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_23G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_RESERVED_23G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_RESERVED_23G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_23G]

//>> CLEAR_[CPLT_CONF0_RESERVED_23G]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_RESERVED_23G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_RESERVED_23G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_RESERVED_23G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_RESERVED_23G]

//>> GET_[CPLT_CONF0_RESERVED_23G]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_RESERVED_23G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_RESERVED_23G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_RESERVED_23G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_23G]

//>> GET_[CPLT_CONF0_RESERVED_23G]
static inline bool GET_CPLT_CONF0_RESERVED_23G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_RESERVED_23G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_RESERVED_23G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_23G]

//>> SET_[CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC,
           CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC]

//>> SET_[CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC,
           CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC]

//>> GET_[CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC,
           CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC]

//>> SET_[CPLT_CONF0_TC_PHYX_REFA_REFB_CLK_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_PHYX_REFA_REFB_CLK_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_TC_PHYX_REFA_REFB_CLK_SEL_DC,
           CPLT_CONF0_TC_PHYX_REFA_REFB_CLK_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_TC_PHYX_REFA_REFB_CLK_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_PHYX_REFA_REFB_CLK_SEL_DC]

//>> SET_[CPLT_CONF0_TC_PHYX_REFA_REFB_CLK_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_PHYX_REFA_REFB_CLK_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_TC_PHYX_REFA_REFB_CLK_SEL_DC,
           CPLT_CONF0_TC_PHYX_REFA_REFB_CLK_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_TC_PHYX_REFA_REFB_CLK_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_PHYX_REFA_REFB_CLK_SEL_DC]

//>> GET_[CPLT_CONF0_TC_PHYX_REFA_REFB_CLK_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_TC_PHYX_REFA_REFB_CLK_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_TC_PHYX_REFA_REFB_CLK_SEL_DC,
           CPLT_CONF0_TC_PHYX_REFA_REFB_CLK_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_TC_PHYX_REFA_REFB_CLK_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_TC_PHYX_REFA_REFB_CLK_SEL_DC]

//>> SET_[CPLT_CONF0_RESERVED_30G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_30G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_30G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_RESERVED_30G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_30G]

//>> SET_[CPLT_CONF0_RESERVED_30G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_30G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_30G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_RESERVED_30G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_30G]

//>> SET_[CPLT_CONF0_RESERVED_30G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_30G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_RESERVED_30G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_RESERVED_30G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_30G]

//>> CLEAR_[CPLT_CONF0_RESERVED_30G]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_RESERVED_30G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_RESERVED_30G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_RESERVED_30G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_RESERVED_30G]

//>> GET_[CPLT_CONF0_RESERVED_30G]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_RESERVED_30G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_RESERVED_30G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_RESERVED_30G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_30G]

//>> GET_[CPLT_CONF0_RESERVED_30G]
static inline bool GET_CPLT_CONF0_RESERVED_30G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_RESERVED_30G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_RESERVED_30G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_30G]

//>> SET_[CPLT_CONF0_RESERVED_31G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_31G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_31G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_RESERVED_31G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_31G]

//>> SET_[CPLT_CONF0_RESERVED_31G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_31G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_31G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_RESERVED_31G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_31G]

//>> SET_[CPLT_CONF0_RESERVED_31G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_31G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_RESERVED_31G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_RESERVED_31G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_31G]

//>> CLEAR_[CPLT_CONF0_RESERVED_31G]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_RESERVED_31G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_RESERVED_31G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_RESERVED_31G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_RESERVED_31G]

//>> GET_[CPLT_CONF0_RESERVED_31G]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_RESERVED_31G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_RESERVED_31G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_RESERVED_31G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_31G]

//>> GET_[CPLT_CONF0_RESERVED_31G]
static inline bool GET_CPLT_CONF0_RESERVED_31G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_RESERVED_31G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_RESERVED_31G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_31G]

//>> SET_[CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC]

//>> SET_[CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC]

//>> SET_[CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC]

//>> CLEAR_[CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC]

//>> GET_[CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC]

//>> GET_[CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC]
static inline bool GET_CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC]

//>> SET_[CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC]

//>> SET_[CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC]

//>> SET_[CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC]

//>> CLEAR_[CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC]

//>> GET_[CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC]

//>> GET_[CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC]
static inline bool GET_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC]

//>> SET_[CPLT_CONF0_CTRL_CC_SDIS_DC_N]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_CC_SDIS_DC_N(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_CTRL_CC_SDIS_DC_N,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_SDIS_DC_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_CC_SDIS_DC_N]

//>> SET_[CPLT_CONF0_CTRL_CC_SDIS_DC_N]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_CC_SDIS_DC_N(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_CTRL_CC_SDIS_DC_N,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_SDIS_DC_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_CC_SDIS_DC_N]

//>> SET_[CPLT_CONF0_CTRL_CC_SDIS_DC_N]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_CC_SDIS_DC_N(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_CTRL_CC_SDIS_DC_N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_SDIS_DC_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_CC_SDIS_DC_N]

//>> CLEAR_[CPLT_CONF0_CTRL_CC_SDIS_DC_N]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_CTRL_CC_SDIS_DC_N(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_CTRL_CC_SDIS_DC_N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_SDIS_DC_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_CTRL_CC_SDIS_DC_N]

//>> GET_[CPLT_CONF0_CTRL_CC_SDIS_DC_N]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_CTRL_CC_SDIS_DC_N(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_CTRL_CC_SDIS_DC_N,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_SDIS_DC_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_CTRL_CC_SDIS_DC_N]

//>> GET_[CPLT_CONF0_CTRL_CC_SDIS_DC_N]
static inline bool GET_CPLT_CONF0_CTRL_CC_SDIS_DC_N(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_CTRL_CC_SDIS_DC_N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_SDIS_DC_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_CTRL_CC_SDIS_DC_N]

//>> SET_[CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC]

//>> SET_[CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC]

//>> SET_[CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC]

//>> CLEAR_[CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC]

//>> GET_[CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC]

//>> GET_[CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC]
static inline bool GET_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC]

//>> SET_[CPLT_CONF0_CTRL_CC_SCAN_DIAG]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_CC_SCAN_DIAG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_CTRL_CC_SCAN_DIAG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_SCAN_DIAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_CC_SCAN_DIAG]

//>> SET_[CPLT_CONF0_CTRL_CC_SCAN_DIAG]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_CC_SCAN_DIAG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_CTRL_CC_SCAN_DIAG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_SCAN_DIAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_CC_SCAN_DIAG]

//>> SET_[CPLT_CONF0_CTRL_CC_SCAN_DIAG]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_CC_SCAN_DIAG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_CTRL_CC_SCAN_DIAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_SCAN_DIAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_CC_SCAN_DIAG]

//>> CLEAR_[CPLT_CONF0_CTRL_CC_SCAN_DIAG]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_CTRL_CC_SCAN_DIAG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_CTRL_CC_SCAN_DIAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_SCAN_DIAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_CTRL_CC_SCAN_DIAG]

//>> GET_[CPLT_CONF0_CTRL_CC_SCAN_DIAG]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_CTRL_CC_SCAN_DIAG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_CTRL_CC_SCAN_DIAG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_SCAN_DIAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_CTRL_CC_SCAN_DIAG]

//>> GET_[CPLT_CONF0_CTRL_CC_SCAN_DIAG]
static inline bool GET_CPLT_CONF0_CTRL_CC_SCAN_DIAG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_CTRL_CC_SCAN_DIAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_SCAN_DIAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_CTRL_CC_SCAN_DIAG]

//>> SET_[CPLT_CONF0_RESERVED_TEST_CONTROL_36G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_TEST_CONTROL_36G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_TEST_CONTROL_36G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_RESERVED_TEST_CONTROL_36G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_TEST_CONTROL_36G]

//>> SET_[CPLT_CONF0_RESERVED_TEST_CONTROL_36G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_TEST_CONTROL_36G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_TEST_CONTROL_36G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_RESERVED_TEST_CONTROL_36G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_TEST_CONTROL_36G]

//>> SET_[CPLT_CONF0_RESERVED_TEST_CONTROL_36G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_TEST_CONTROL_36G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_RESERVED_TEST_CONTROL_36G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_RESERVED_TEST_CONTROL_36G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_TEST_CONTROL_36G]

//>> CLEAR_[CPLT_CONF0_RESERVED_TEST_CONTROL_36G]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_RESERVED_TEST_CONTROL_36G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_RESERVED_TEST_CONTROL_36G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_RESERVED_TEST_CONTROL_36G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_RESERVED_TEST_CONTROL_36G]

//>> GET_[CPLT_CONF0_RESERVED_TEST_CONTROL_36G]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_RESERVED_TEST_CONTROL_36G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_RESERVED_TEST_CONTROL_36G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_RESERVED_TEST_CONTROL_36G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_TEST_CONTROL_36G]

//>> GET_[CPLT_CONF0_RESERVED_TEST_CONTROL_36G]
static inline bool GET_CPLT_CONF0_RESERVED_TEST_CONTROL_36G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_RESERVED_TEST_CONTROL_36G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_RESERVED_TEST_CONTROL_36G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_TEST_CONTROL_36G]

//>> SET_[CPLT_CONF0_RESERVED_TEST_CONTROL_37G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_TEST_CONTROL_37G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_TEST_CONTROL_37G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_RESERVED_TEST_CONTROL_37G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_TEST_CONTROL_37G]

//>> SET_[CPLT_CONF0_RESERVED_TEST_CONTROL_37G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_TEST_CONTROL_37G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_TEST_CONTROL_37G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_RESERVED_TEST_CONTROL_37G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_TEST_CONTROL_37G]

//>> SET_[CPLT_CONF0_RESERVED_TEST_CONTROL_37G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_TEST_CONTROL_37G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_RESERVED_TEST_CONTROL_37G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_RESERVED_TEST_CONTROL_37G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_TEST_CONTROL_37G]

//>> CLEAR_[CPLT_CONF0_RESERVED_TEST_CONTROL_37G]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_RESERVED_TEST_CONTROL_37G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_RESERVED_TEST_CONTROL_37G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_RESERVED_TEST_CONTROL_37G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_RESERVED_TEST_CONTROL_37G]

//>> GET_[CPLT_CONF0_RESERVED_TEST_CONTROL_37G]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_RESERVED_TEST_CONTROL_37G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_RESERVED_TEST_CONTROL_37G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_RESERVED_TEST_CONTROL_37G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_TEST_CONTROL_37G]

//>> GET_[CPLT_CONF0_RESERVED_TEST_CONTROL_37G]
static inline bool GET_CPLT_CONF0_RESERVED_TEST_CONTROL_37G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_RESERVED_TEST_CONTROL_37G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_RESERVED_TEST_CONTROL_37G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_TEST_CONTROL_37G]

//>> SET_[CPLT_CONF0_RESERVED_TEST_CONTROL_38G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_TEST_CONTROL_38G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_TEST_CONTROL_38G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_RESERVED_TEST_CONTROL_38G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_TEST_CONTROL_38G]

//>> SET_[CPLT_CONF0_RESERVED_TEST_CONTROL_38G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_TEST_CONTROL_38G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_TEST_CONTROL_38G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_RESERVED_TEST_CONTROL_38G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_TEST_CONTROL_38G]

//>> SET_[CPLT_CONF0_RESERVED_TEST_CONTROL_38G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_TEST_CONTROL_38G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_RESERVED_TEST_CONTROL_38G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_RESERVED_TEST_CONTROL_38G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_TEST_CONTROL_38G]

//>> CLEAR_[CPLT_CONF0_RESERVED_TEST_CONTROL_38G]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_RESERVED_TEST_CONTROL_38G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_RESERVED_TEST_CONTROL_38G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_RESERVED_TEST_CONTROL_38G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_RESERVED_TEST_CONTROL_38G]

//>> GET_[CPLT_CONF0_RESERVED_TEST_CONTROL_38G]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_RESERVED_TEST_CONTROL_38G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_RESERVED_TEST_CONTROL_38G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_RESERVED_TEST_CONTROL_38G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_TEST_CONTROL_38G]

//>> GET_[CPLT_CONF0_RESERVED_TEST_CONTROL_38G]
static inline bool GET_CPLT_CONF0_RESERVED_TEST_CONTROL_38G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_RESERVED_TEST_CONTROL_38G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_RESERVED_TEST_CONTROL_38G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_TEST_CONTROL_38G]

//>> SET_[CPLT_CONF0_RESERVED_TEST_CONTROL_39G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_TEST_CONTROL_39G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_TEST_CONTROL_39G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_RESERVED_TEST_CONTROL_39G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_TEST_CONTROL_39G]

//>> SET_[CPLT_CONF0_RESERVED_TEST_CONTROL_39G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_TEST_CONTROL_39G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_TEST_CONTROL_39G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_RESERVED_TEST_CONTROL_39G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_TEST_CONTROL_39G]

//>> SET_[CPLT_CONF0_RESERVED_TEST_CONTROL_39G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_TEST_CONTROL_39G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_RESERVED_TEST_CONTROL_39G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_RESERVED_TEST_CONTROL_39G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_TEST_CONTROL_39G]

//>> CLEAR_[CPLT_CONF0_RESERVED_TEST_CONTROL_39G]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_RESERVED_TEST_CONTROL_39G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_RESERVED_TEST_CONTROL_39G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_RESERVED_TEST_CONTROL_39G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_RESERVED_TEST_CONTROL_39G]

//>> GET_[CPLT_CONF0_RESERVED_TEST_CONTROL_39G]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_RESERVED_TEST_CONTROL_39G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_RESERVED_TEST_CONTROL_39G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_RESERVED_TEST_CONTROL_39G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_TEST_CONTROL_39G]

//>> GET_[CPLT_CONF0_RESERVED_TEST_CONTROL_39G]
static inline bool GET_CPLT_CONF0_RESERVED_TEST_CONTROL_39G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_RESERVED_TEST_CONTROL_39G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_RESERVED_TEST_CONTROL_39G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_TEST_CONTROL_39G]

//>> SET_[CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC]

//>> SET_[CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC]

//>> SET_[CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC]

//>> CLEAR_[CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC]

//>> GET_[CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC]

//>> GET_[CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC]
static inline bool GET_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC]

//>> SET_[CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC]

//>> SET_[CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC]

//>> SET_[CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC]

//>> CLEAR_[CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC]

//>> GET_[CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC]

//>> GET_[CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC]
static inline bool GET_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC]

//>> SET_[CPLT_CONF0_RESERVED_42G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_42G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_42G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_RESERVED_42G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_42G]

//>> SET_[CPLT_CONF0_RESERVED_42G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_42G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_42G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_RESERVED_42G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_42G]

//>> SET_[CPLT_CONF0_RESERVED_42G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_42G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_RESERVED_42G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_RESERVED_42G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_42G]

//>> CLEAR_[CPLT_CONF0_RESERVED_42G]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_RESERVED_42G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_RESERVED_42G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_RESERVED_42G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_RESERVED_42G]

//>> GET_[CPLT_CONF0_RESERVED_42G]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_RESERVED_42G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_RESERVED_42G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_RESERVED_42G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_42G]

//>> GET_[CPLT_CONF0_RESERVED_42G]
static inline bool GET_CPLT_CONF0_RESERVED_42G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_RESERVED_42G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_RESERVED_42G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_42G]

//>> SET_[CPLT_CONF0_RESERVED_43G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_43G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_43G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_RESERVED_43G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_43G]

//>> SET_[CPLT_CONF0_RESERVED_43G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_43G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_43G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_RESERVED_43G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_43G]

//>> SET_[CPLT_CONF0_RESERVED_43G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_43G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_RESERVED_43G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_RESERVED_43G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_43G]

//>> CLEAR_[CPLT_CONF0_RESERVED_43G]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_RESERVED_43G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_RESERVED_43G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_RESERVED_43G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_RESERVED_43G]

//>> GET_[CPLT_CONF0_RESERVED_43G]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_RESERVED_43G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_RESERVED_43G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_RESERVED_43G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_43G]

//>> GET_[CPLT_CONF0_RESERVED_43G]
static inline bool GET_CPLT_CONF0_RESERVED_43G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_RESERVED_43G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_RESERVED_43G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_43G]

//>> SET_[CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN]

//>> SET_[CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN]

//>> SET_[CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN]

//>> CLEAR_[CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN]

//>> GET_[CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN]

//>> GET_[CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN]
static inline bool GET_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN]

//>> SET_[CPLT_CONF0_RESERVED_45G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_45G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_45G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_RESERVED_45G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_45G]

//>> SET_[CPLT_CONF0_RESERVED_45G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_45G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_RESERVED_45G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_RESERVED_45G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_45G]

//>> SET_[CPLT_CONF0_RESERVED_45G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_RESERVED_45G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_RESERVED_45G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_RESERVED_45G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_RESERVED_45G]

//>> CLEAR_[CPLT_CONF0_RESERVED_45G]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_RESERVED_45G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_RESERVED_45G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_RESERVED_45G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_RESERVED_45G]

//>> GET_[CPLT_CONF0_RESERVED_45G]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_RESERVED_45G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_RESERVED_45G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_RESERVED_45G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_45G]

//>> GET_[CPLT_CONF0_RESERVED_45G]
static inline bool GET_CPLT_CONF0_RESERVED_45G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_RESERVED_45G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_RESERVED_45G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_RESERVED_45G]

//>> SET_[CPLT_CONF0_TC_IOO_EOL_TOGL_SRC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_IOO_EOL_TOGL_SRC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_TC_IOO_EOL_TOGL_SRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_TC_IOO_EOL_TOGL_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_IOO_EOL_TOGL_SRC]

//>> SET_[CPLT_CONF0_TC_IOO_EOL_TOGL_SRC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_IOO_EOL_TOGL_SRC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_TC_IOO_EOL_TOGL_SRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_TC_IOO_EOL_TOGL_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_IOO_EOL_TOGL_SRC]

//>> SET_[CPLT_CONF0_TC_IOO_EOL_TOGL_SRC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_IOO_EOL_TOGL_SRC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_TC_IOO_EOL_TOGL_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_TC_IOO_EOL_TOGL_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_IOO_EOL_TOGL_SRC]

//>> CLEAR_[CPLT_CONF0_TC_IOO_EOL_TOGL_SRC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_TC_IOO_EOL_TOGL_SRC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_TC_IOO_EOL_TOGL_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_TC_IOO_EOL_TOGL_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_TC_IOO_EOL_TOGL_SRC]

//>> GET_[CPLT_CONF0_TC_IOO_EOL_TOGL_SRC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_TC_IOO_EOL_TOGL_SRC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_TC_IOO_EOL_TOGL_SRC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_TC_IOO_EOL_TOGL_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_TC_IOO_EOL_TOGL_SRC]

//>> GET_[CPLT_CONF0_TC_IOO_EOL_TOGL_SRC]
static inline bool GET_CPLT_CONF0_TC_IOO_EOL_TOGL_SRC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_TC_IOO_EOL_TOGL_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_TC_IOO_EOL_TOGL_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_TC_IOO_EOL_TOGL_SRC]

//>> SET_[CPLT_CONF0_TC_SKIT_CANARY_MODE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_TC_SKIT_CANARY_MODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_TC_SKIT_CANARY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_SKIT_CANARY_MODE_DC]

//>> SET_[CPLT_CONF0_TC_SKIT_CANARY_MODE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_TC_SKIT_CANARY_MODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_TC_SKIT_CANARY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_SKIT_CANARY_MODE_DC]

//>> SET_[CPLT_CONF0_TC_SKIT_CANARY_MODE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_TC_SKIT_CANARY_MODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_TC_SKIT_CANARY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_SKIT_CANARY_MODE_DC]

//>> CLEAR_[CPLT_CONF0_TC_SKIT_CANARY_MODE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_TC_SKIT_CANARY_MODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_TC_SKIT_CANARY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_TC_SKIT_CANARY_MODE_DC]

//>> GET_[CPLT_CONF0_TC_SKIT_CANARY_MODE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_TC_SKIT_CANARY_MODE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_TC_SKIT_CANARY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_TC_SKIT_CANARY_MODE_DC]

//>> GET_[CPLT_CONF0_TC_SKIT_CANARY_MODE_DC]
static inline bool GET_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_TC_SKIT_CANARY_MODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_TC_SKIT_CANARY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_TC_SKIT_CANARY_MODE_DC]

//>> SET_[CPLT_CONF0_TC_TOPOLOGY_MODE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_TOPOLOGY_MODE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_TC_TOPOLOGY_MODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_TC_TOPOLOGY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_TOPOLOGY_MODE_DC]

//>> SET_[CPLT_CONF0_TC_TOPOLOGY_MODE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_TOPOLOGY_MODE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_TC_TOPOLOGY_MODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_TC_TOPOLOGY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_TOPOLOGY_MODE_DC]

//>> SET_[CPLT_CONF0_TC_TOPOLOGY_MODE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_TOPOLOGY_MODE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_TC_TOPOLOGY_MODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_TC_TOPOLOGY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_TOPOLOGY_MODE_DC]

//>> CLEAR_[CPLT_CONF0_TC_TOPOLOGY_MODE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_TC_TOPOLOGY_MODE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_TC_TOPOLOGY_MODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_TC_TOPOLOGY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_TC_TOPOLOGY_MODE_DC]

//>> GET_[CPLT_CONF0_TC_TOPOLOGY_MODE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_TC_TOPOLOGY_MODE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_TC_TOPOLOGY_MODE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_TC_TOPOLOGY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_TC_TOPOLOGY_MODE_DC]

//>> GET_[CPLT_CONF0_TC_TOPOLOGY_MODE_DC]
static inline bool GET_CPLT_CONF0_TC_TOPOLOGY_MODE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_TC_TOPOLOGY_MODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_TC_TOPOLOGY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_TC_TOPOLOGY_MODE_DC]

//>> SET_[CPLT_CONF0_TC_TOPOLOGY_ID_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_TOPOLOGY_ID_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_TC_TOPOLOGY_ID_DC,
           CPLT_CONF0_TC_TOPOLOGY_ID_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_TC_TOPOLOGY_ID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_TOPOLOGY_ID_DC]

//>> SET_[CPLT_CONF0_TC_TOPOLOGY_ID_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_TOPOLOGY_ID_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_TC_TOPOLOGY_ID_DC,
           CPLT_CONF0_TC_TOPOLOGY_ID_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_TC_TOPOLOGY_ID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_TOPOLOGY_ID_DC]

//>> GET_[CPLT_CONF0_TC_TOPOLOGY_ID_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_TC_TOPOLOGY_ID_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_TC_TOPOLOGY_ID_DC,
           CPLT_CONF0_TC_TOPOLOGY_ID_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_TC_TOPOLOGY_ID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_TC_TOPOLOGY_ID_DC]

//>> SET_[CPLT_CONF0_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_FREE_USAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE]

//>> SET_[CPLT_CONF0_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_FREE_USAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE]

//>> SET_[CPLT_CONF0_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE]

//>> CLEAR_[CPLT_CONF0_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_FREE_USAGE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_FREE_USAGE]

//>> GET_[CPLT_CONF0_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_FREE_USAGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_FREE_USAGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_FREE_USAGE]

//>> GET_[CPLT_CONF0_FREE_USAGE]
static inline bool GET_CPLT_CONF0_FREE_USAGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_FREE_USAGE]

//>> SET_[CPLT_CONF0_TP_AN_NEST_PROGDLY_SETTING_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TP_AN_NEST_PROGDLY_SETTING_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_TP_AN_NEST_PROGDLY_SETTING_DC,
           CPLT_CONF0_TP_AN_NEST_PROGDLY_SETTING_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_TP_AN_NEST_PROGDLY_SETTING_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TP_AN_NEST_PROGDLY_SETTING_DC]

//>> SET_[CPLT_CONF0_TP_AN_NEST_PROGDLY_SETTING_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TP_AN_NEST_PROGDLY_SETTING_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_TP_AN_NEST_PROGDLY_SETTING_DC,
           CPLT_CONF0_TP_AN_NEST_PROGDLY_SETTING_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_TP_AN_NEST_PROGDLY_SETTING_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TP_AN_NEST_PROGDLY_SETTING_DC]

//>> GET_[CPLT_CONF0_TP_AN_NEST_PROGDLY_SETTING_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_TP_AN_NEST_PROGDLY_SETTING_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_TP_AN_NEST_PROGDLY_SETTING_DC,
           CPLT_CONF0_TP_AN_NEST_PROGDLY_SETTING_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_TP_AN_NEST_PROGDLY_SETTING_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_TP_AN_NEST_PROGDLY_SETTING_DC]

//>> SET_[CPLT_CONF0_FREE_USAGE_52G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_52G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_FREE_USAGE_52G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_52G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_52G]

//>> SET_[CPLT_CONF0_FREE_USAGE_52G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_52G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_FREE_USAGE_52G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_52G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_52G]

//>> SET_[CPLT_CONF0_FREE_USAGE_52G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_52G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_FREE_USAGE_52G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_52G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_52G]

//>> CLEAR_[CPLT_CONF0_FREE_USAGE_52G]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_FREE_USAGE_52G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_FREE_USAGE_52G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_52G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_FREE_USAGE_52G]

//>> GET_[CPLT_CONF0_FREE_USAGE_52G]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_FREE_USAGE_52G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_FREE_USAGE_52G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_52G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_FREE_USAGE_52G]

//>> GET_[CPLT_CONF0_FREE_USAGE_52G]
static inline bool GET_CPLT_CONF0_FREE_USAGE_52G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_FREE_USAGE_52G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_52G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_FREE_USAGE_52G]

//>> SET_[CPLT_CONF0_TC_PIPE_LANEX_LANEPLL_BYPASS_MODE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_PIPE_LANEX_LANEPLL_BYPASS_MODE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_TC_PIPE_LANEX_LANEPLL_BYPASS_MODE_DC,
           CPLT_CONF0_TC_PIPE_LANEX_LANEPLL_BYPASS_MODE_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_TC_PIPE_LANEX_LANEPLL_BYPASS_MODE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_PIPE_LANEX_LANEPLL_BYPASS_MODE_DC]

//>> SET_[CPLT_CONF0_TC_PIPE_LANEX_LANEPLL_BYPASS_MODE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_PIPE_LANEX_LANEPLL_BYPASS_MODE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_TC_PIPE_LANEX_LANEPLL_BYPASS_MODE_DC,
           CPLT_CONF0_TC_PIPE_LANEX_LANEPLL_BYPASS_MODE_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_TC_PIPE_LANEX_LANEPLL_BYPASS_MODE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_PIPE_LANEX_LANEPLL_BYPASS_MODE_DC]

//>> GET_[CPLT_CONF0_TC_PIPE_LANEX_LANEPLL_BYPASS_MODE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_TC_PIPE_LANEX_LANEPLL_BYPASS_MODE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_TC_PIPE_LANEX_LANEPLL_BYPASS_MODE_DC,
           CPLT_CONF0_TC_PIPE_LANEX_LANEPLL_BYPASS_MODE_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_TC_PIPE_LANEX_LANEPLL_BYPASS_MODE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_TC_PIPE_LANEX_LANEPLL_BYPASS_MODE_DC]

//>> SET_[CPLT_CONF0_FREE_USAGE_53G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_53G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_FREE_USAGE_53G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_53G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_53G]

//>> SET_[CPLT_CONF0_FREE_USAGE_53G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_53G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_FREE_USAGE_53G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_53G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_53G]

//>> SET_[CPLT_CONF0_FREE_USAGE_53G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_53G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_FREE_USAGE_53G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_53G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_53G]

//>> CLEAR_[CPLT_CONF0_FREE_USAGE_53G]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_FREE_USAGE_53G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_FREE_USAGE_53G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_53G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_FREE_USAGE_53G]

//>> GET_[CPLT_CONF0_FREE_USAGE_53G]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_FREE_USAGE_53G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_FREE_USAGE_53G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_53G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_FREE_USAGE_53G]

//>> GET_[CPLT_CONF0_FREE_USAGE_53G]
static inline bool GET_CPLT_CONF0_FREE_USAGE_53G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_FREE_USAGE_53G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_53G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_FREE_USAGE_53G]

//>> SET_[CPLT_CONF0_FREE_USAGE_54G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_54G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_FREE_USAGE_54G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_54G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_54G]

//>> SET_[CPLT_CONF0_FREE_USAGE_54G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_54G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_FREE_USAGE_54G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_54G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_54G]

//>> SET_[CPLT_CONF0_FREE_USAGE_54G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_54G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_FREE_USAGE_54G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_54G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_54G]

//>> CLEAR_[CPLT_CONF0_FREE_USAGE_54G]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_FREE_USAGE_54G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_FREE_USAGE_54G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_54G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_FREE_USAGE_54G]

//>> GET_[CPLT_CONF0_FREE_USAGE_54G]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_FREE_USAGE_54G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_FREE_USAGE_54G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_54G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_FREE_USAGE_54G]

//>> GET_[CPLT_CONF0_FREE_USAGE_54G]
static inline bool GET_CPLT_CONF0_FREE_USAGE_54G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_FREE_USAGE_54G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_54G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_FREE_USAGE_54G]

//>> SET_[CPLT_CONF0_FREE_USAGE_55G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_55G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_FREE_USAGE_55G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_55G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_55G]

//>> SET_[CPLT_CONF0_FREE_USAGE_55G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_55G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_FREE_USAGE_55G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_55G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_55G]

//>> SET_[CPLT_CONF0_FREE_USAGE_55G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_55G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_FREE_USAGE_55G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_55G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_55G]

//>> CLEAR_[CPLT_CONF0_FREE_USAGE_55G]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_FREE_USAGE_55G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_FREE_USAGE_55G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_55G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_FREE_USAGE_55G]

//>> GET_[CPLT_CONF0_FREE_USAGE_55G]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_FREE_USAGE_55G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_FREE_USAGE_55G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_55G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_FREE_USAGE_55G]

//>> GET_[CPLT_CONF0_FREE_USAGE_55G]
static inline bool GET_CPLT_CONF0_FREE_USAGE_55G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_FREE_USAGE_55G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_55G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_FREE_USAGE_55G]

//>> SET_[CPLT_CONF0_TP_AN_NEST_DCC_SETTING_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TP_AN_NEST_DCC_SETTING_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_TP_AN_NEST_DCC_SETTING_DC,
           CPLT_CONF0_TP_AN_NEST_DCC_SETTING_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_TP_AN_NEST_DCC_SETTING_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TP_AN_NEST_DCC_SETTING_DC]

//>> SET_[CPLT_CONF0_TP_AN_NEST_DCC_SETTING_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TP_AN_NEST_DCC_SETTING_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_TP_AN_NEST_DCC_SETTING_DC,
           CPLT_CONF0_TP_AN_NEST_DCC_SETTING_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_TP_AN_NEST_DCC_SETTING_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TP_AN_NEST_DCC_SETTING_DC]

//>> GET_[CPLT_CONF0_TP_AN_NEST_DCC_SETTING_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_TP_AN_NEST_DCC_SETTING_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_TP_AN_NEST_DCC_SETTING_DC,
           CPLT_CONF0_TP_AN_NEST_DCC_SETTING_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_TP_AN_NEST_DCC_SETTING_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_TP_AN_NEST_DCC_SETTING_DC]

//>> SET_[CPLT_CONF0_FREE_USAGE_56G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_56G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_FREE_USAGE_56G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_56G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_56G]

//>> SET_[CPLT_CONF0_FREE_USAGE_56G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_56G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_FREE_USAGE_56G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_56G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_56G]

//>> SET_[CPLT_CONF0_FREE_USAGE_56G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_56G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_FREE_USAGE_56G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_56G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_56G]

//>> CLEAR_[CPLT_CONF0_FREE_USAGE_56G]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_FREE_USAGE_56G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_FREE_USAGE_56G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_56G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_FREE_USAGE_56G]

//>> GET_[CPLT_CONF0_FREE_USAGE_56G]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_FREE_USAGE_56G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_FREE_USAGE_56G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_56G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_FREE_USAGE_56G]

//>> GET_[CPLT_CONF0_FREE_USAGE_56G]
static inline bool GET_CPLT_CONF0_FREE_USAGE_56G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_FREE_USAGE_56G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_56G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_FREE_USAGE_56G]

//>> SET_[CPLT_CONF0_FREE_USAGE_57G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_57G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_FREE_USAGE_57G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_57G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_57G]

//>> SET_[CPLT_CONF0_FREE_USAGE_57G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_57G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_FREE_USAGE_57G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_57G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_57G]

//>> SET_[CPLT_CONF0_FREE_USAGE_57G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_57G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_FREE_USAGE_57G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_57G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_57G]

//>> CLEAR_[CPLT_CONF0_FREE_USAGE_57G]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_FREE_USAGE_57G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_FREE_USAGE_57G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_57G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_FREE_USAGE_57G]

//>> GET_[CPLT_CONF0_FREE_USAGE_57G]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_FREE_USAGE_57G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_FREE_USAGE_57G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_57G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_FREE_USAGE_57G]

//>> GET_[CPLT_CONF0_FREE_USAGE_57G]
static inline bool GET_CPLT_CONF0_FREE_USAGE_57G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_FREE_USAGE_57G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_57G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_FREE_USAGE_57G]

//>> SET_[CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC]

//>> SET_[CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC]

//>> SET_[CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC]

//>> CLEAR_[CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC]

//>> GET_[CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC]

//>> GET_[CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC]
static inline bool GET_CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC]

//>> SET_[CPLT_CONF0_FREE_USAGE_58G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_58G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_FREE_USAGE_58G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_58G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_58G]

//>> SET_[CPLT_CONF0_FREE_USAGE_58G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_58G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_FREE_USAGE_58G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_58G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_58G]

//>> SET_[CPLT_CONF0_FREE_USAGE_58G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_58G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_FREE_USAGE_58G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_58G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_58G]

//>> CLEAR_[CPLT_CONF0_FREE_USAGE_58G]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_FREE_USAGE_58G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_FREE_USAGE_58G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_58G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_FREE_USAGE_58G]

//>> GET_[CPLT_CONF0_FREE_USAGE_58G]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_FREE_USAGE_58G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_FREE_USAGE_58G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_58G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_FREE_USAGE_58G]

//>> GET_[CPLT_CONF0_FREE_USAGE_58G]
static inline bool GET_CPLT_CONF0_FREE_USAGE_58G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_FREE_USAGE_58G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_58G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_FREE_USAGE_58G]

//>> SET_[CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC]

//>> SET_[CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC]

//>> SET_[CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC]

//>> CLEAR_[CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC]

//>> GET_[CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC]

//>> GET_[CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC]
static inline bool GET_CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC]

//>> SET_[CPLT_CONF0_FREE_USAGE_59G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_59G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_FREE_USAGE_59G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_59G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_59G]

//>> SET_[CPLT_CONF0_FREE_USAGE_59G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_59G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_FREE_USAGE_59G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_59G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_59G]

//>> SET_[CPLT_CONF0_FREE_USAGE_59G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_59G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_FREE_USAGE_59G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_59G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_59G]

//>> CLEAR_[CPLT_CONF0_FREE_USAGE_59G]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_FREE_USAGE_59G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_FREE_USAGE_59G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_59G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_FREE_USAGE_59G]

//>> GET_[CPLT_CONF0_FREE_USAGE_59G]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_FREE_USAGE_59G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_FREE_USAGE_59G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_59G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_FREE_USAGE_59G]

//>> GET_[CPLT_CONF0_FREE_USAGE_59G]
static inline bool GET_CPLT_CONF0_FREE_USAGE_59G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_FREE_USAGE_59G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_59G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_FREE_USAGE_59G]

//>> SET_[CPLT_CONF0_TC_PHYX_NOMINAL_VP_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_PHYX_NOMINAL_VP_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_TC_PHYX_NOMINAL_VP_SEL_DC,
           CPLT_CONF0_TC_PHYX_NOMINAL_VP_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_TC_PHYX_NOMINAL_VP_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_PHYX_NOMINAL_VP_SEL_DC]

//>> SET_[CPLT_CONF0_TC_PHYX_NOMINAL_VP_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_PHYX_NOMINAL_VP_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_TC_PHYX_NOMINAL_VP_SEL_DC,
           CPLT_CONF0_TC_PHYX_NOMINAL_VP_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_TC_PHYX_NOMINAL_VP_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_PHYX_NOMINAL_VP_SEL_DC]

//>> GET_[CPLT_CONF0_TC_PHYX_NOMINAL_VP_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_TC_PHYX_NOMINAL_VP_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_TC_PHYX_NOMINAL_VP_SEL_DC,
           CPLT_CONF0_TC_PHYX_NOMINAL_VP_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_TC_PHYX_NOMINAL_VP_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_TC_PHYX_NOMINAL_VP_SEL_DC]

//>> SET_[CPLT_CONF0_FREE_USAGE_60G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_60G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_FREE_USAGE_60G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_60G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_60G]

//>> SET_[CPLT_CONF0_FREE_USAGE_60G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_60G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_FREE_USAGE_60G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_60G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_60G]

//>> SET_[CPLT_CONF0_FREE_USAGE_60G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_60G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_FREE_USAGE_60G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_60G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_60G]

//>> CLEAR_[CPLT_CONF0_FREE_USAGE_60G]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_FREE_USAGE_60G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_FREE_USAGE_60G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_60G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_FREE_USAGE_60G]

//>> GET_[CPLT_CONF0_FREE_USAGE_60G]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_FREE_USAGE_60G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_FREE_USAGE_60G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_60G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_FREE_USAGE_60G]

//>> GET_[CPLT_CONF0_FREE_USAGE_60G]
static inline bool GET_CPLT_CONF0_FREE_USAGE_60G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_FREE_USAGE_60G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_60G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_FREE_USAGE_60G]

//>> SET_[CPLT_CONF0_FREE_USAGE_61G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_61G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_FREE_USAGE_61G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_61G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_61G]

//>> SET_[CPLT_CONF0_FREE_USAGE_61G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_61G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_FREE_USAGE_61G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_61G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_61G]

//>> SET_[CPLT_CONF0_FREE_USAGE_61G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_61G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_FREE_USAGE_61G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_61G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_61G]

//>> CLEAR_[CPLT_CONF0_FREE_USAGE_61G]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_FREE_USAGE_61G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_FREE_USAGE_61G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_61G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_FREE_USAGE_61G]

//>> GET_[CPLT_CONF0_FREE_USAGE_61G]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_FREE_USAGE_61G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_FREE_USAGE_61G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_61G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_FREE_USAGE_61G]

//>> GET_[CPLT_CONF0_FREE_USAGE_61G]
static inline bool GET_CPLT_CONF0_FREE_USAGE_61G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_FREE_USAGE_61G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_61G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_FREE_USAGE_61G]

//>> SET_[CPLT_CONF0_TC_PHYX_NOMINAL_VPH_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_PHYX_NOMINAL_VPH_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_TC_PHYX_NOMINAL_VPH_SEL_DC,
           CPLT_CONF0_TC_PHYX_NOMINAL_VPH_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_TC_PHYX_NOMINAL_VPH_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_PHYX_NOMINAL_VPH_SEL_DC]

//>> SET_[CPLT_CONF0_TC_PHYX_NOMINAL_VPH_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_TC_PHYX_NOMINAL_VPH_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_TC_PHYX_NOMINAL_VPH_SEL_DC,
           CPLT_CONF0_TC_PHYX_NOMINAL_VPH_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_TC_PHYX_NOMINAL_VPH_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_TC_PHYX_NOMINAL_VPH_SEL_DC]

//>> GET_[CPLT_CONF0_TC_PHYX_NOMINAL_VPH_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_TC_PHYX_NOMINAL_VPH_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_TC_PHYX_NOMINAL_VPH_SEL_DC,
           CPLT_CONF0_TC_PHYX_NOMINAL_VPH_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_TC_PHYX_NOMINAL_VPH_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_TC_PHYX_NOMINAL_VPH_SEL_DC]

//>> SET_[CPLT_CONF0_FREE_USAGE_62G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_62G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_FREE_USAGE_62G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_62G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_62G]

//>> SET_[CPLT_CONF0_FREE_USAGE_62G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_62G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_FREE_USAGE_62G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_62G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_62G]

//>> SET_[CPLT_CONF0_FREE_USAGE_62G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_62G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_FREE_USAGE_62G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_62G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_62G]

//>> CLEAR_[CPLT_CONF0_FREE_USAGE_62G]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_FREE_USAGE_62G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_FREE_USAGE_62G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_62G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_FREE_USAGE_62G]

//>> GET_[CPLT_CONF0_FREE_USAGE_62G]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_FREE_USAGE_62G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_FREE_USAGE_62G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_62G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_FREE_USAGE_62G]

//>> GET_[CPLT_CONF0_FREE_USAGE_62G]
static inline bool GET_CPLT_CONF0_FREE_USAGE_62G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_FREE_USAGE_62G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_62G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_FREE_USAGE_62G]

//>> SET_[CPLT_CONF0_FREE_USAGE_63G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_63G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_FREE_USAGE_63G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_63G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_63G]

//>> SET_[CPLT_CONF0_FREE_USAGE_63G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_63G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF0_FREE_USAGE_63G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_63G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_63G]

//>> SET_[CPLT_CONF0_FREE_USAGE_63G]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF0_FREE_USAGE_63G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF0_FREE_USAGE_63G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_63G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF0_FREE_USAGE_63G]

//>> CLEAR_[CPLT_CONF0_FREE_USAGE_63G]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF0_FREE_USAGE_63G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF0_FREE_USAGE_63G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_63G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF0_FREE_USAGE_63G]

//>> GET_[CPLT_CONF0_FREE_USAGE_63G]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF0_FREE_USAGE_63G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF0_FREE_USAGE_63G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_63G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_FREE_USAGE_63G]

//>> GET_[CPLT_CONF0_FREE_USAGE_63G]
static inline bool GET_CPLT_CONF0_FREE_USAGE_63G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF0_FREE_USAGE_63G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF0_FREE_USAGE_63G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF0_FREE_USAGE_63G]

//>> PREP_[CPLT_CTRL0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL0_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL0_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CTRL0_RW]

//>> GET_[CPLT_CTRL0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL0_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL0_RW;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL0_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CTRL0_RW]

//>> PUT_[CPLT_CTRL0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL0_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL0_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CTRL0_RW]

//>> PREP_[CPLT_CTRL0_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL0_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CTRL0_WO_CLEAR]

//>> GET_[CPLT_CTRL0_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL0_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL0_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CTRL0_WO_CLEAR]

//>> PUT_[CPLT_CTRL0_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL0_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CTRL0_WO_CLEAR]

//>> PREP_[CPLT_CTRL0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL0_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL0_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CTRL0_WO_OR]

//>> GET_[CPLT_CTRL0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL0_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL0_WO_OR;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL0_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CTRL0_WO_OR]

//>> PUT_[CPLT_CTRL0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL0_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL0_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CTRL0_WO_OR]


//>> SET_[CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]

//>> SET_[CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]

//>> SET_[CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]

//>> CLEAR_[CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]

//>> GET_[CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]

//>> GET_[CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]
static inline bool GET_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]

//>> SET_[CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]

//>> SET_[CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]

//>> SET_[CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]

//>> CLEAR_[CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]

//>> GET_[CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]

//>> GET_[CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]
static inline bool GET_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]

//>> SET_[CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]

//>> CLEAR_[CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]
static inline bool GET_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_CTRL_CC_FORCE_ALIGN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]

//>> SET_[CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_CTRL_CC_FORCE_ALIGN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]

//>> SET_[CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_CTRL_CC_FORCE_ALIGN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]

//>> CLEAR_[CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_CTRL_CC_FORCE_ALIGN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]

//>> GET_[CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_CTRL_CC_FORCE_ALIGN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]

//>> GET_[CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]
static inline bool GET_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_CTRL_CC_FORCE_ALIGN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]

//>> SET_[CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]

//>> SET_[CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]

//>> SET_[CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]

//>> CLEAR_[CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]

//>> GET_[CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]

//>> GET_[CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]
static inline bool GET_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]

//>> SET_[CPLT_CTRL0_TC_UNIT_AVP_MODE]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_UNIT_AVP_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_UNIT_AVP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_AVP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_UNIT_AVP_MODE]

//>> SET_[CPLT_CTRL0_TC_UNIT_AVP_MODE]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_UNIT_AVP_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_UNIT_AVP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_AVP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_UNIT_AVP_MODE]

//>> SET_[CPLT_CTRL0_TC_UNIT_AVP_MODE]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_UNIT_AVP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_TC_UNIT_AVP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_AVP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_UNIT_AVP_MODE]

//>> CLEAR_[CPLT_CTRL0_TC_UNIT_AVP_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_TC_UNIT_AVP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_TC_UNIT_AVP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_AVP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_TC_UNIT_AVP_MODE]

//>> GET_[CPLT_CTRL0_TC_UNIT_AVP_MODE]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_TC_UNIT_AVP_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_TC_UNIT_AVP_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_AVP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_UNIT_AVP_MODE]

//>> GET_[CPLT_CTRL0_TC_UNIT_AVP_MODE]
static inline bool GET_CPLT_CTRL0_TC_UNIT_AVP_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_TC_UNIT_AVP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_AVP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_UNIT_AVP_MODE]

//>> SET_[CPLT_CTRL0_TC_VITL_PROTECTION]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_VITL_PROTECTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_VITL_PROTECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_TC_VITL_PROTECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_VITL_PROTECTION]

//>> SET_[CPLT_CTRL0_TC_VITL_PROTECTION]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_VITL_PROTECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_VITL_PROTECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_TC_VITL_PROTECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_VITL_PROTECTION]

//>> SET_[CPLT_CTRL0_TC_VITL_PROTECTION]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_VITL_PROTECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_TC_VITL_PROTECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_TC_VITL_PROTECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_VITL_PROTECTION]

//>> CLEAR_[CPLT_CTRL0_TC_VITL_PROTECTION]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_TC_VITL_PROTECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_TC_VITL_PROTECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_TC_VITL_PROTECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_TC_VITL_PROTECTION]

//>> GET_[CPLT_CTRL0_TC_VITL_PROTECTION]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_TC_VITL_PROTECTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_TC_VITL_PROTECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_TC_VITL_PROTECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_VITL_PROTECTION]

//>> GET_[CPLT_CTRL0_TC_VITL_PROTECTION]
static inline bool GET_CPLT_CTRL0_TC_VITL_PROTECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_TC_VITL_PROTECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_TC_VITL_PROTECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_VITL_PROTECTION]

//>> SET_[CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]

//>> SET_[CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]

//>> SET_[CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]

//>> CLEAR_[CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]

//>> GET_[CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]

//>> GET_[CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]
static inline bool GET_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]

//>> SET_[CPLT_CTRL0_RESERVED_11A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_11A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_11A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_11A]

//>> SET_[CPLT_CTRL0_RESERVED_11A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_11A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_11A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_11A]

//>> SET_[CPLT_CTRL0_RESERVED_11A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_11A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_RESERVED_11A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_11A]

//>> CLEAR_[CPLT_CTRL0_RESERVED_11A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_RESERVED_11A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_RESERVED_11A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_RESERVED_11A]

//>> GET_[CPLT_CTRL0_RESERVED_11A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_RESERVED_11A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_RESERVED_11A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_11A]

//>> GET_[CPLT_CTRL0_RESERVED_11A]
static inline bool GET_CPLT_CTRL0_RESERVED_11A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_RESERVED_11A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_11A]

//>> SET_[CPLT_CTRL0_TC_SKIT_MODE_BIST_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_SKIT_MODE_BIST_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_TC_SKIT_MODE_BIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_SKIT_MODE_BIST_DC]

//>> SET_[CPLT_CTRL0_TC_SKIT_MODE_BIST_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_SKIT_MODE_BIST_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_TC_SKIT_MODE_BIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_SKIT_MODE_BIST_DC]

//>> SET_[CPLT_CTRL0_TC_SKIT_MODE_BIST_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_TC_SKIT_MODE_BIST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_TC_SKIT_MODE_BIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_SKIT_MODE_BIST_DC]

//>> CLEAR_[CPLT_CTRL0_TC_SKIT_MODE_BIST_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_TC_SKIT_MODE_BIST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_TC_SKIT_MODE_BIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_TC_SKIT_MODE_BIST_DC]

//>> GET_[CPLT_CTRL0_TC_SKIT_MODE_BIST_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_TC_SKIT_MODE_BIST_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_TC_SKIT_MODE_BIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_SKIT_MODE_BIST_DC]

//>> GET_[CPLT_CTRL0_TC_SKIT_MODE_BIST_DC]
static inline bool GET_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_TC_SKIT_MODE_BIST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_TC_SKIT_MODE_BIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_SKIT_MODE_BIST_DC]

//>> SET_[CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]

//>> SET_[CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]

//>> SET_[CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]

//>> CLEAR_[CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]

//>> GET_[CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]

//>> GET_[CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]
static inline bool GET_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]

//>> SET_[CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]

//>> SET_[CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]

//>> SET_[CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]

//>> CLEAR_[CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]

//>> GET_[CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]

//>> GET_[CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]
static inline bool GET_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]

//>> SET_[CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]

//>> SET_[CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]

//>> SET_[CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]

//>> CLEAR_[CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]

//>> GET_[CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]

//>> GET_[CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]
static inline bool GET_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]

//>> SET_[CPLT_CTRL0_RESERVED_18A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_18A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_18A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_18A]

//>> SET_[CPLT_CTRL0_RESERVED_18A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_18A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_18A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_18A]

//>> SET_[CPLT_CTRL0_RESERVED_18A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_18A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_RESERVED_18A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_18A]

//>> CLEAR_[CPLT_CTRL0_RESERVED_18A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_RESERVED_18A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_RESERVED_18A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_RESERVED_18A]

//>> GET_[CPLT_CTRL0_RESERVED_18A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_RESERVED_18A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_RESERVED_18A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_18A]

//>> GET_[CPLT_CTRL0_RESERVED_18A]
static inline bool GET_CPLT_CTRL0_RESERVED_18A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_RESERVED_18A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_18A]

//>> SET_[CPLT_CTRL0_RESERVED_19A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_19A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_19A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_19A]

//>> SET_[CPLT_CTRL0_RESERVED_19A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_19A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_19A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_19A]

//>> SET_[CPLT_CTRL0_RESERVED_19A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_19A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_RESERVED_19A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_19A]

//>> CLEAR_[CPLT_CTRL0_RESERVED_19A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_RESERVED_19A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_RESERVED_19A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_RESERVED_19A]

//>> GET_[CPLT_CTRL0_RESERVED_19A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_RESERVED_19A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_RESERVED_19A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_19A]

//>> GET_[CPLT_CTRL0_RESERVED_19A]
static inline bool GET_CPLT_CTRL0_RESERVED_19A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_RESERVED_19A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_19A]

//>> SET_[CPLT_CTRL0_TC_PSRO_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_PSRO_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_PSRO_SEL_DC,
           CPLT_CTRL0_TC_PSRO_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_TC_PSRO_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_PSRO_SEL_DC]

//>> SET_[CPLT_CTRL0_TC_PSRO_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_PSRO_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_PSRO_SEL_DC,
           CPLT_CTRL0_TC_PSRO_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_TC_PSRO_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_PSRO_SEL_DC]

//>> GET_[CPLT_CTRL0_TC_PSRO_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_TC_PSRO_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_TC_PSRO_SEL_DC,
           CPLT_CTRL0_TC_PSRO_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_TC_PSRO_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_PSRO_SEL_DC]

//>> SET_[CPLT_CTRL0_TC_BSC_WRAPSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_BSC_WRAPSEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_BSC_WRAPSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_TC_BSC_WRAPSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_BSC_WRAPSEL_DC]

//>> SET_[CPLT_CTRL0_TC_BSC_WRAPSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_BSC_WRAPSEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_BSC_WRAPSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_TC_BSC_WRAPSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_BSC_WRAPSEL_DC]

//>> SET_[CPLT_CTRL0_TC_BSC_WRAPSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_BSC_WRAPSEL_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_TC_BSC_WRAPSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_TC_BSC_WRAPSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_BSC_WRAPSEL_DC]

//>> CLEAR_[CPLT_CTRL0_TC_BSC_WRAPSEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_TC_BSC_WRAPSEL_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_TC_BSC_WRAPSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_TC_BSC_WRAPSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_TC_BSC_WRAPSEL_DC]

//>> GET_[CPLT_CTRL0_TC_BSC_WRAPSEL_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_TC_BSC_WRAPSEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_TC_BSC_WRAPSEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_TC_BSC_WRAPSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_BSC_WRAPSEL_DC]

//>> GET_[CPLT_CTRL0_TC_BSC_WRAPSEL_DC]
static inline bool GET_CPLT_CTRL0_TC_BSC_WRAPSEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_TC_BSC_WRAPSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_TC_BSC_WRAPSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_BSC_WRAPSEL_DC]

//>> SET_[CPLT_CTRL0_TC_BSC_INTMODE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_BSC_INTMODE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_BSC_INTMODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_TC_BSC_INTMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_BSC_INTMODE_DC]

//>> SET_[CPLT_CTRL0_TC_BSC_INTMODE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_BSC_INTMODE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_BSC_INTMODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_TC_BSC_INTMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_BSC_INTMODE_DC]

//>> SET_[CPLT_CTRL0_TC_BSC_INTMODE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_BSC_INTMODE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_TC_BSC_INTMODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_TC_BSC_INTMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_BSC_INTMODE_DC]

//>> CLEAR_[CPLT_CTRL0_TC_BSC_INTMODE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_TC_BSC_INTMODE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_TC_BSC_INTMODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_TC_BSC_INTMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_TC_BSC_INTMODE_DC]

//>> GET_[CPLT_CTRL0_TC_BSC_INTMODE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_TC_BSC_INTMODE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_TC_BSC_INTMODE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_TC_BSC_INTMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_BSC_INTMODE_DC]

//>> GET_[CPLT_CTRL0_TC_BSC_INTMODE_DC]
static inline bool GET_CPLT_CTRL0_TC_BSC_INTMODE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_TC_BSC_INTMODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_TC_BSC_INTMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_BSC_INTMODE_DC]

//>> SET_[CPLT_CTRL0_TC_BSC_INV_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_BSC_INV_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_BSC_INV_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_TC_BSC_INV_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_BSC_INV_DC]

//>> SET_[CPLT_CTRL0_TC_BSC_INV_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_BSC_INV_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_BSC_INV_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_TC_BSC_INV_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_BSC_INV_DC]

//>> SET_[CPLT_CTRL0_TC_BSC_INV_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_BSC_INV_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_TC_BSC_INV_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_TC_BSC_INV_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_BSC_INV_DC]

//>> CLEAR_[CPLT_CTRL0_TC_BSC_INV_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_TC_BSC_INV_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_TC_BSC_INV_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_TC_BSC_INV_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_TC_BSC_INV_DC]

//>> GET_[CPLT_CTRL0_TC_BSC_INV_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_TC_BSC_INV_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_TC_BSC_INV_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_TC_BSC_INV_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_BSC_INV_DC]

//>> GET_[CPLT_CTRL0_TC_BSC_INV_DC]
static inline bool GET_CPLT_CTRL0_TC_BSC_INV_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_TC_BSC_INV_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_TC_BSC_INV_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_BSC_INV_DC]

//>> SET_[CPLT_CTRL0_TC_BSC_EXTMODE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_BSC_EXTMODE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_BSC_EXTMODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_TC_BSC_EXTMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_BSC_EXTMODE_DC]

//>> SET_[CPLT_CTRL0_TC_BSC_EXTMODE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_BSC_EXTMODE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_BSC_EXTMODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_TC_BSC_EXTMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_BSC_EXTMODE_DC]

//>> SET_[CPLT_CTRL0_TC_BSC_EXTMODE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_BSC_EXTMODE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_TC_BSC_EXTMODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_TC_BSC_EXTMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_BSC_EXTMODE_DC]

//>> CLEAR_[CPLT_CTRL0_TC_BSC_EXTMODE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_TC_BSC_EXTMODE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_TC_BSC_EXTMODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_TC_BSC_EXTMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_TC_BSC_EXTMODE_DC]

//>> GET_[CPLT_CTRL0_TC_BSC_EXTMODE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_TC_BSC_EXTMODE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_TC_BSC_EXTMODE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_TC_BSC_EXTMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_BSC_EXTMODE_DC]

//>> GET_[CPLT_CTRL0_TC_BSC_EXTMODE_DC]
static inline bool GET_CPLT_CTRL0_TC_BSC_EXTMODE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_TC_BSC_EXTMODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_TC_BSC_EXTMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_BSC_EXTMODE_DC]

//>> SET_[CPLT_CTRL0_RESERVED_32A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_32A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_32A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_32A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_32A]

//>> SET_[CPLT_CTRL0_RESERVED_32A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_32A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_32A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_32A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_32A]

//>> SET_[CPLT_CTRL0_RESERVED_32A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_32A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_RESERVED_32A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_32A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_32A]

//>> CLEAR_[CPLT_CTRL0_RESERVED_32A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_RESERVED_32A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_RESERVED_32A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_32A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_RESERVED_32A]

//>> GET_[CPLT_CTRL0_RESERVED_32A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_RESERVED_32A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_RESERVED_32A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_32A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_32A]

//>> GET_[CPLT_CTRL0_RESERVED_32A]
static inline bool GET_CPLT_CTRL0_RESERVED_32A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_RESERVED_32A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_32A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_32A]

//>> SET_[CPLT_CTRL0_RESERVED_33A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_33A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_33A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_33A]

//>> SET_[CPLT_CTRL0_RESERVED_33A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_33A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_33A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_33A]

//>> SET_[CPLT_CTRL0_RESERVED_33A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_33A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_RESERVED_33A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_33A]

//>> CLEAR_[CPLT_CTRL0_RESERVED_33A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_RESERVED_33A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_RESERVED_33A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_RESERVED_33A]

//>> GET_[CPLT_CTRL0_RESERVED_33A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_RESERVED_33A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_RESERVED_33A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_33A]

//>> GET_[CPLT_CTRL0_RESERVED_33A]
static inline bool GET_CPLT_CTRL0_RESERVED_33A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_RESERVED_33A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_33A]

//>> SET_[CPLT_CTRL0_RESERVED_34A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_34A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_34A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_34A]

//>> SET_[CPLT_CTRL0_RESERVED_34A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_34A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_34A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_34A]

//>> SET_[CPLT_CTRL0_RESERVED_34A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_34A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_RESERVED_34A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_34A]

//>> CLEAR_[CPLT_CTRL0_RESERVED_34A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_RESERVED_34A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_RESERVED_34A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_RESERVED_34A]

//>> GET_[CPLT_CTRL0_RESERVED_34A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_RESERVED_34A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_RESERVED_34A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_34A]

//>> GET_[CPLT_CTRL0_RESERVED_34A]
static inline bool GET_CPLT_CTRL0_RESERVED_34A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_RESERVED_34A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_34A]

//>> SET_[CPLT_CTRL0_RESERVED_35A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_35A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_35A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_35A]

//>> SET_[CPLT_CTRL0_RESERVED_35A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_35A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_35A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_35A]

//>> SET_[CPLT_CTRL0_RESERVED_35A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_35A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_RESERVED_35A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_35A]

//>> CLEAR_[CPLT_CTRL0_RESERVED_35A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_RESERVED_35A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_RESERVED_35A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_RESERVED_35A]

//>> GET_[CPLT_CTRL0_RESERVED_35A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_RESERVED_35A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_RESERVED_35A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_35A]

//>> GET_[CPLT_CTRL0_RESERVED_35A]
static inline bool GET_CPLT_CTRL0_RESERVED_35A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_RESERVED_35A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_35A]

//>> SET_[CPLT_CTRL0_RESERVED_36A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_36A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_36A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_36A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_36A]

//>> SET_[CPLT_CTRL0_RESERVED_36A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_36A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_36A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_36A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_36A]

//>> SET_[CPLT_CTRL0_RESERVED_36A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_36A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_RESERVED_36A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_36A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_36A]

//>> CLEAR_[CPLT_CTRL0_RESERVED_36A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_RESERVED_36A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_RESERVED_36A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_36A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_RESERVED_36A]

//>> GET_[CPLT_CTRL0_RESERVED_36A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_RESERVED_36A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_RESERVED_36A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_36A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_36A]

//>> GET_[CPLT_CTRL0_RESERVED_36A]
static inline bool GET_CPLT_CTRL0_RESERVED_36A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_RESERVED_36A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_36A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_36A]

//>> SET_[CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC]

//>> SET_[CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC]

//>> SET_[CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC]

//>> CLEAR_[CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC]

//>> GET_[CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC]

//>> GET_[CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC]
static inline bool GET_CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC]

//>> SET_[CPLT_CTRL0_RESERVED_37A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_37A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_37A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_37A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_37A]

//>> SET_[CPLT_CTRL0_RESERVED_37A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_37A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_37A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_37A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_37A]

//>> SET_[CPLT_CTRL0_RESERVED_37A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_37A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_RESERVED_37A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_37A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_37A]

//>> CLEAR_[CPLT_CTRL0_RESERVED_37A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_RESERVED_37A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_RESERVED_37A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_37A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_RESERVED_37A]

//>> GET_[CPLT_CTRL0_RESERVED_37A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_RESERVED_37A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_RESERVED_37A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_37A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_37A]

//>> GET_[CPLT_CTRL0_RESERVED_37A]
static inline bool GET_CPLT_CTRL0_RESERVED_37A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_RESERVED_37A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_37A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_37A]

//>> SET_[CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC]

//>> SET_[CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC]

//>> SET_[CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC]

//>> CLEAR_[CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC]

//>> GET_[CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC]

//>> GET_[CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC]
static inline bool GET_CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC]

//>> SET_[CPLT_CTRL0_RESERVED_38A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_38A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_38A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_38A]

//>> SET_[CPLT_CTRL0_RESERVED_38A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_38A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_38A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_38A]

//>> SET_[CPLT_CTRL0_RESERVED_38A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_38A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_RESERVED_38A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_38A]

//>> CLEAR_[CPLT_CTRL0_RESERVED_38A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_RESERVED_38A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_RESERVED_38A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_RESERVED_38A]

//>> GET_[CPLT_CTRL0_RESERVED_38A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_RESERVED_38A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_RESERVED_38A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_38A]

//>> GET_[CPLT_CTRL0_RESERVED_38A]
static inline bool GET_CPLT_CTRL0_RESERVED_38A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_RESERVED_38A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_38A]

//>> SET_[CPLT_CTRL0_RESERVED_39A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_39A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_39A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_39A]

//>> SET_[CPLT_CTRL0_RESERVED_39A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_39A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_39A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_39A]

//>> SET_[CPLT_CTRL0_RESERVED_39A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_39A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_RESERVED_39A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_39A]

//>> CLEAR_[CPLT_CTRL0_RESERVED_39A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_RESERVED_39A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_RESERVED_39A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_RESERVED_39A]

//>> GET_[CPLT_CTRL0_RESERVED_39A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_RESERVED_39A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_RESERVED_39A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_39A]

//>> GET_[CPLT_CTRL0_RESERVED_39A]
static inline bool GET_CPLT_CTRL0_RESERVED_39A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_RESERVED_39A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_39A]

//>> SET_[CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC,
           CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC]

//>> SET_[CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC,
           CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC]

//>> GET_[CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC,
           CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC]

//>> SET_[CPLT_CTRL0_RESERVED_42A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_42A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_42A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_42A]

//>> SET_[CPLT_CTRL0_RESERVED_42A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_42A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_42A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_42A]

//>> SET_[CPLT_CTRL0_RESERVED_42A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_42A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_RESERVED_42A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_42A]

//>> CLEAR_[CPLT_CTRL0_RESERVED_42A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_RESERVED_42A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_RESERVED_42A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_RESERVED_42A]

//>> GET_[CPLT_CTRL0_RESERVED_42A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_RESERVED_42A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_RESERVED_42A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_42A]

//>> GET_[CPLT_CTRL0_RESERVED_42A]
static inline bool GET_CPLT_CTRL0_RESERVED_42A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_RESERVED_42A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_42A]

//>> SET_[CPLT_CTRL0_RESERVED_43A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_43A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_43A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_43A]

//>> SET_[CPLT_CTRL0_RESERVED_43A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_43A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_43A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_43A]

//>> SET_[CPLT_CTRL0_RESERVED_43A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_43A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_RESERVED_43A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_43A]

//>> CLEAR_[CPLT_CTRL0_RESERVED_43A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_RESERVED_43A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_RESERVED_43A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_RESERVED_43A]

//>> GET_[CPLT_CTRL0_RESERVED_43A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_RESERVED_43A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_RESERVED_43A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_43A]

//>> GET_[CPLT_CTRL0_RESERVED_43A]
static inline bool GET_CPLT_CTRL0_RESERVED_43A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_RESERVED_43A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_43A]

//>> SET_[CPLT_CTRL0_CTRL_CC_DCTEST_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_CTRL_CC_DCTEST_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_CTRL_CC_DCTEST_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_DCTEST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_CTRL_CC_DCTEST_DC]

//>> SET_[CPLT_CTRL0_CTRL_CC_DCTEST_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_CTRL_CC_DCTEST_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_CTRL_CC_DCTEST_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_DCTEST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_CTRL_CC_DCTEST_DC]

//>> SET_[CPLT_CTRL0_CTRL_CC_DCTEST_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_CTRL_CC_DCTEST_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_CTRL_CC_DCTEST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_DCTEST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_CTRL_CC_DCTEST_DC]

//>> CLEAR_[CPLT_CTRL0_CTRL_CC_DCTEST_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_CTRL_CC_DCTEST_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_CTRL_CC_DCTEST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_DCTEST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_CTRL_CC_DCTEST_DC]

//>> GET_[CPLT_CTRL0_CTRL_CC_DCTEST_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_CTRL_CC_DCTEST_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_CTRL_CC_DCTEST_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_DCTEST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_CTRL_CC_DCTEST_DC]

//>> GET_[CPLT_CTRL0_CTRL_CC_DCTEST_DC]
static inline bool GET_CPLT_CTRL0_CTRL_CC_DCTEST_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_CTRL_CC_DCTEST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_DCTEST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_CTRL_CC_DCTEST_DC]

//>> SET_[CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC]

//>> SET_[CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC]

//>> SET_[CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC]

//>> CLEAR_[CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC]

//>> GET_[CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC]

//>> GET_[CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC]
static inline bool GET_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC]

//>> SET_[CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]

//>> SET_[CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]

//>> SET_[CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]

//>> CLEAR_[CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]

//>> GET_[CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]

//>> GET_[CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]
static inline bool GET_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]

//>> SET_[CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]

//>> SET_[CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]

//>> SET_[CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]

//>> CLEAR_[CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]

//>> GET_[CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]

//>> GET_[CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]
static inline bool GET_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]

//>> SET_[CPLT_CTRL0_FREE_USAGE_48A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_48A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_48A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_48A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_48A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_48A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_48A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_48A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_48A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_48A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_FREE_USAGE_48A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_48A]

//>> CLEAR_[CPLT_CTRL0_FREE_USAGE_48A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_FREE_USAGE_48A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_FREE_USAGE_48A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_FREE_USAGE_48A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_48A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_FREE_USAGE_48A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_FREE_USAGE_48A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_48A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_48A]
static inline bool GET_CPLT_CTRL0_FREE_USAGE_48A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_FREE_USAGE_48A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_48A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_49A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_49A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_49A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_49A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_49A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_49A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_49A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_49A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_49A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_49A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_FREE_USAGE_49A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_49A]

//>> CLEAR_[CPLT_CTRL0_FREE_USAGE_49A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_FREE_USAGE_49A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_FREE_USAGE_49A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_FREE_USAGE_49A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_49A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_FREE_USAGE_49A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_FREE_USAGE_49A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_49A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_49A]
static inline bool GET_CPLT_CTRL0_FREE_USAGE_49A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_FREE_USAGE_49A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_49A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_50A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_50A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_50A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_50A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_50A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_50A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_50A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_50A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_50A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_50A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_FREE_USAGE_50A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_50A]

//>> CLEAR_[CPLT_CTRL0_FREE_USAGE_50A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_FREE_USAGE_50A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_FREE_USAGE_50A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_FREE_USAGE_50A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_50A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_FREE_USAGE_50A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_FREE_USAGE_50A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_50A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_50A]
static inline bool GET_CPLT_CTRL0_FREE_USAGE_50A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_FREE_USAGE_50A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_50A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_51A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_51A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_51A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_51A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_51A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_51A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_51A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_51A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_51A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_51A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_FREE_USAGE_51A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_51A]

//>> CLEAR_[CPLT_CTRL0_FREE_USAGE_51A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_FREE_USAGE_51A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_FREE_USAGE_51A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_FREE_USAGE_51A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_51A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_FREE_USAGE_51A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_FREE_USAGE_51A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_51A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_51A]
static inline bool GET_CPLT_CTRL0_FREE_USAGE_51A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_FREE_USAGE_51A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_51A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_52A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_52A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_52A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_52A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_52A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_52A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_52A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_52A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_52A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_52A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_FREE_USAGE_52A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_52A]

//>> CLEAR_[CPLT_CTRL0_FREE_USAGE_52A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_FREE_USAGE_52A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_FREE_USAGE_52A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_FREE_USAGE_52A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_52A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_FREE_USAGE_52A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_FREE_USAGE_52A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_52A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_52A]
static inline bool GET_CPLT_CTRL0_FREE_USAGE_52A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_FREE_USAGE_52A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_52A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_53A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_53A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_53A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_53A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_53A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_53A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_53A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_53A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_53A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_53A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_FREE_USAGE_53A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_53A]

//>> CLEAR_[CPLT_CTRL0_FREE_USAGE_53A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_FREE_USAGE_53A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_FREE_USAGE_53A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_FREE_USAGE_53A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_53A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_FREE_USAGE_53A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_FREE_USAGE_53A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_53A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_53A]
static inline bool GET_CPLT_CTRL0_FREE_USAGE_53A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_FREE_USAGE_53A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_53A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_54A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_54A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_54A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_54A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_54A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_54A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_54A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_54A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_54A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_54A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_FREE_USAGE_54A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_54A]

//>> CLEAR_[CPLT_CTRL0_FREE_USAGE_54A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_FREE_USAGE_54A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_FREE_USAGE_54A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_FREE_USAGE_54A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_54A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_FREE_USAGE_54A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_FREE_USAGE_54A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_54A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_54A]
static inline bool GET_CPLT_CTRL0_FREE_USAGE_54A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_FREE_USAGE_54A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_54A]

//>> SET_[CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC]

//>> SET_[CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC]

//>> SET_[CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC]

//>> CLEAR_[CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC]

//>> GET_[CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC]

//>> GET_[CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC]
static inline bool GET_CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC]

//>> SET_[CPLT_CTRL0_RESERVED_55A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_55A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_55A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_55A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_55A]

//>> SET_[CPLT_CTRL0_RESERVED_55A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_55A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_RESERVED_55A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_55A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_55A]

//>> SET_[CPLT_CTRL0_RESERVED_55A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_RESERVED_55A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_RESERVED_55A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_55A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_RESERVED_55A]

//>> CLEAR_[CPLT_CTRL0_RESERVED_55A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_RESERVED_55A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_RESERVED_55A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_55A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_RESERVED_55A]

//>> GET_[CPLT_CTRL0_RESERVED_55A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_RESERVED_55A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_RESERVED_55A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_55A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_55A]

//>> GET_[CPLT_CTRL0_RESERVED_55A]
static inline bool GET_CPLT_CTRL0_RESERVED_55A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_RESERVED_55A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_RESERVED_55A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_RESERVED_55A]

//>> SET_[CPLT_CTRL0_TC_JTAG_TRST0_N_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_JTAG_TRST0_N_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_JTAG_TRST0_N_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_TRST0_N_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_JTAG_TRST0_N_DC]

//>> SET_[CPLT_CTRL0_TC_JTAG_TRST0_N_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_JTAG_TRST0_N_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_JTAG_TRST0_N_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_TRST0_N_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_JTAG_TRST0_N_DC]

//>> SET_[CPLT_CTRL0_TC_JTAG_TRST0_N_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_JTAG_TRST0_N_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_TC_JTAG_TRST0_N_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_TRST0_N_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_JTAG_TRST0_N_DC]

//>> CLEAR_[CPLT_CTRL0_TC_JTAG_TRST0_N_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_TC_JTAG_TRST0_N_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_TC_JTAG_TRST0_N_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_TRST0_N_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_TC_JTAG_TRST0_N_DC]

//>> GET_[CPLT_CTRL0_TC_JTAG_TRST0_N_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_TC_JTAG_TRST0_N_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_TC_JTAG_TRST0_N_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_TRST0_N_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_JTAG_TRST0_N_DC]

//>> GET_[CPLT_CTRL0_TC_JTAG_TRST0_N_DC]
static inline bool GET_CPLT_CTRL0_TC_JTAG_TRST0_N_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_TC_JTAG_TRST0_N_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_TRST0_N_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_JTAG_TRST0_N_DC]

//>> SET_[CPLT_CTRL0_FREE_USAGE_56A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_56A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_56A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_56A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_56A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_56A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_56A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_56A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_56A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_56A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_FREE_USAGE_56A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_56A]

//>> CLEAR_[CPLT_CTRL0_FREE_USAGE_56A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_FREE_USAGE_56A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_FREE_USAGE_56A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_FREE_USAGE_56A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_56A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_FREE_USAGE_56A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_FREE_USAGE_56A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_56A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_56A]
static inline bool GET_CPLT_CTRL0_FREE_USAGE_56A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_FREE_USAGE_56A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_56A]

//>> SET_[CPLT_CTRL0_TC_JTAG_TRST1_N_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_JTAG_TRST1_N_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_JTAG_TRST1_N_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_TRST1_N_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_JTAG_TRST1_N_DC]

//>> SET_[CPLT_CTRL0_TC_JTAG_TRST1_N_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_JTAG_TRST1_N_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_JTAG_TRST1_N_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_TRST1_N_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_JTAG_TRST1_N_DC]

//>> SET_[CPLT_CTRL0_TC_JTAG_TRST1_N_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_JTAG_TRST1_N_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_TC_JTAG_TRST1_N_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_TRST1_N_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_JTAG_TRST1_N_DC]

//>> CLEAR_[CPLT_CTRL0_TC_JTAG_TRST1_N_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_TC_JTAG_TRST1_N_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_TC_JTAG_TRST1_N_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_TRST1_N_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_TC_JTAG_TRST1_N_DC]

//>> GET_[CPLT_CTRL0_TC_JTAG_TRST1_N_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_TC_JTAG_TRST1_N_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_TC_JTAG_TRST1_N_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_TRST1_N_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_JTAG_TRST1_N_DC]

//>> GET_[CPLT_CTRL0_TC_JTAG_TRST1_N_DC]
static inline bool GET_CPLT_CTRL0_TC_JTAG_TRST1_N_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_TC_JTAG_TRST1_N_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_TRST1_N_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_JTAG_TRST1_N_DC]

//>> SET_[CPLT_CTRL0_FREE_USAGE_57A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_57A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_57A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_57A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_57A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_57A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_57A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_57A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_57A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_57A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_FREE_USAGE_57A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_57A]

//>> CLEAR_[CPLT_CTRL0_FREE_USAGE_57A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_FREE_USAGE_57A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_FREE_USAGE_57A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_FREE_USAGE_57A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_57A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_FREE_USAGE_57A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_FREE_USAGE_57A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_57A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_57A]
static inline bool GET_CPLT_CTRL0_FREE_USAGE_57A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_FREE_USAGE_57A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_57A]

//>> SET_[CPLT_CTRL0_TC_JTAG_TRST2_N_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_JTAG_TRST2_N_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_JTAG_TRST2_N_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_TRST2_N_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_JTAG_TRST2_N_DC]

//>> SET_[CPLT_CTRL0_TC_JTAG_TRST2_N_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_JTAG_TRST2_N_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_JTAG_TRST2_N_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_TRST2_N_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_JTAG_TRST2_N_DC]

//>> SET_[CPLT_CTRL0_TC_JTAG_TRST2_N_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_JTAG_TRST2_N_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_TC_JTAG_TRST2_N_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_TRST2_N_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_JTAG_TRST2_N_DC]

//>> CLEAR_[CPLT_CTRL0_TC_JTAG_TRST2_N_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_TC_JTAG_TRST2_N_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_TC_JTAG_TRST2_N_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_TRST2_N_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_TC_JTAG_TRST2_N_DC]

//>> GET_[CPLT_CTRL0_TC_JTAG_TRST2_N_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_TC_JTAG_TRST2_N_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_TC_JTAG_TRST2_N_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_TRST2_N_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_JTAG_TRST2_N_DC]

//>> GET_[CPLT_CTRL0_TC_JTAG_TRST2_N_DC]
static inline bool GET_CPLT_CTRL0_TC_JTAG_TRST2_N_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_TC_JTAG_TRST2_N_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_TRST2_N_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_JTAG_TRST2_N_DC]

//>> SET_[CPLT_CTRL0_FREE_USAGE_58A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_58A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_58A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_58A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_58A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_58A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_58A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_58A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_58A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_58A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_FREE_USAGE_58A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_58A]

//>> CLEAR_[CPLT_CTRL0_FREE_USAGE_58A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_FREE_USAGE_58A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_FREE_USAGE_58A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_FREE_USAGE_58A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_58A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_FREE_USAGE_58A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_FREE_USAGE_58A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_58A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_58A]
static inline bool GET_CPLT_CTRL0_FREE_USAGE_58A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_FREE_USAGE_58A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_58A]

//>> SET_[CPLT_CTRL0_TC_JTAG_TRST3_N_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_JTAG_TRST3_N_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_JTAG_TRST3_N_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_TRST3_N_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_JTAG_TRST3_N_DC]

//>> SET_[CPLT_CTRL0_TC_JTAG_TRST3_N_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_JTAG_TRST3_N_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_JTAG_TRST3_N_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_TRST3_N_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_JTAG_TRST3_N_DC]

//>> SET_[CPLT_CTRL0_TC_JTAG_TRST3_N_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_JTAG_TRST3_N_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_TC_JTAG_TRST3_N_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_TRST3_N_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_JTAG_TRST3_N_DC]

//>> CLEAR_[CPLT_CTRL0_TC_JTAG_TRST3_N_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_TC_JTAG_TRST3_N_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_TC_JTAG_TRST3_N_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_TRST3_N_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_TC_JTAG_TRST3_N_DC]

//>> GET_[CPLT_CTRL0_TC_JTAG_TRST3_N_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_TC_JTAG_TRST3_N_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_TC_JTAG_TRST3_N_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_TRST3_N_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_JTAG_TRST3_N_DC]

//>> GET_[CPLT_CTRL0_TC_JTAG_TRST3_N_DC]
static inline bool GET_CPLT_CTRL0_TC_JTAG_TRST3_N_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_TC_JTAG_TRST3_N_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_TRST3_N_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_JTAG_TRST3_N_DC]

//>> SET_[CPLT_CTRL0_FREE_USAGE_59A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_59A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_59A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_59A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_59A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_59A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_59A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_59A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_59A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_59A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_FREE_USAGE_59A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_59A]

//>> CLEAR_[CPLT_CTRL0_FREE_USAGE_59A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_FREE_USAGE_59A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_FREE_USAGE_59A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_FREE_USAGE_59A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_59A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_FREE_USAGE_59A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_FREE_USAGE_59A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_59A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_59A]
static inline bool GET_CPLT_CTRL0_FREE_USAGE_59A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_FREE_USAGE_59A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_59A]

//>> SET_[CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC]

//>> SET_[CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC]

//>> SET_[CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC]

//>> CLEAR_[CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC]

//>> GET_[CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC]

//>> GET_[CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC]
static inline bool GET_CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC]

//>> SET_[CPLT_CTRL0_FREE_USAGE_60A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_60A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_60A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_60A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_60A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_60A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_60A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_60A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_60A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_60A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_FREE_USAGE_60A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_60A]

//>> CLEAR_[CPLT_CTRL0_FREE_USAGE_60A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_FREE_USAGE_60A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_FREE_USAGE_60A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_FREE_USAGE_60A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_60A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_FREE_USAGE_60A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_FREE_USAGE_60A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_60A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_60A]
static inline bool GET_CPLT_CTRL0_FREE_USAGE_60A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_FREE_USAGE_60A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_60A]

//>> SET_[CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC]

//>> SET_[CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC]

//>> SET_[CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC]

//>> CLEAR_[CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC]

//>> GET_[CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC]

//>> GET_[CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC]
static inline bool GET_CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC]

//>> SET_[CPLT_CTRL0_FREE_USAGE_61A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_61A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_61A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_61A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_61A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_61A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_61A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_61A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_61A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_61A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_FREE_USAGE_61A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_61A]

//>> CLEAR_[CPLT_CTRL0_FREE_USAGE_61A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_FREE_USAGE_61A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_FREE_USAGE_61A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_FREE_USAGE_61A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_61A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_FREE_USAGE_61A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_FREE_USAGE_61A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_61A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_61A]
static inline bool GET_CPLT_CTRL0_FREE_USAGE_61A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_FREE_USAGE_61A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_61A]

//>> SET_[CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC]

//>> SET_[CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC]

//>> SET_[CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC]

//>> CLEAR_[CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC]

//>> GET_[CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC]

//>> GET_[CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC]
static inline bool GET_CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC]

//>> SET_[CPLT_CTRL0_FREE_USAGE_62A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_62A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_62A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_62A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_62A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_62A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_62A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_62A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_62A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_62A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_FREE_USAGE_62A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_62A]

//>> CLEAR_[CPLT_CTRL0_FREE_USAGE_62A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_FREE_USAGE_62A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_FREE_USAGE_62A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_FREE_USAGE_62A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_62A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_FREE_USAGE_62A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_FREE_USAGE_62A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_62A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_62A]
static inline bool GET_CPLT_CTRL0_FREE_USAGE_62A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_FREE_USAGE_62A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_62A]

//>> SET_[CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC]

//>> SET_[CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC]

//>> SET_[CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC]

//>> CLEAR_[CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC]

//>> GET_[CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC]

//>> GET_[CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC]
static inline bool GET_CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC]

//>> SET_[CPLT_CTRL0_FREE_USAGE_63A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_63A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_63A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_63A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_63A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_63A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL0_FREE_USAGE_63A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_63A]

//>> SET_[CPLT_CTRL0_FREE_USAGE_63A]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL0_FREE_USAGE_63A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL0_FREE_USAGE_63A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL0_FREE_USAGE_63A]

//>> CLEAR_[CPLT_CTRL0_FREE_USAGE_63A]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL0_FREE_USAGE_63A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL0_FREE_USAGE_63A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL0_FREE_USAGE_63A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_63A]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL0_FREE_USAGE_63A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL0_FREE_USAGE_63A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_63A]

//>> GET_[CPLT_CTRL0_FREE_USAGE_63A]
static inline bool GET_CPLT_CTRL0_FREE_USAGE_63A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL0_RW, CPLT_CTRL0_WO_CLEAR, CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL0_FREE_USAGE_63A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL0_FREE_USAGE_63A]

//>> PREP_[EPS_THERM_WSUB_ERR_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_THERM_WSUB_ERR_STATUS_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB_ERR_STATUS_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EPS_THERM_WSUB_ERR_STATUS_REG]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_THERM_WSUB_ERR_STATUS_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB_ERR_STATUS_REG;
#endif
    return fapi2::getScom(i_target, EPS_THERM_WSUB_ERR_STATUS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG]

//>> PUT_[EPS_THERM_WSUB_ERR_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_THERM_WSUB_ERR_STATUS_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return fapi2::putScom(i_target, EPS_THERM_WSUB_ERR_STATUS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_THERM_WSUB_ERR_STATUS_REG]


//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]

//>> CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]
static inline bool GET_EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_LT,
           EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_LT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_LT,
           EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_LT]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_LT,
           EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_LT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_LT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_LT,
           EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_LT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_LT,
           EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_LT]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_LT,
           EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_LT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_LT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT]

//>> CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT]
static inline bool GET_EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT]

//>> CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT]
static inline bool GET_EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_READ_STATE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_READ_STATE_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_READ_STATE_LT,
           EPS_THERM_WSUB_ERR_STATUS_REG_READ_STATE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_READ_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_READ_STATE_LT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_READ_STATE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_READ_STATE_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_READ_STATE_LT,
           EPS_THERM_WSUB_ERR_STATUS_REG_READ_STATE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_READ_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_READ_STATE_LT]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_READ_STATE_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_ERR_STATUS_REG_READ_STATE_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_ERR_STATUS_REG_READ_STATE_LT,
           EPS_THERM_WSUB_ERR_STATUS_REG_READ_STATE_LT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_READ_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_READ_STATE_LT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_STATE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_STATE_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_STATE_LT,
           EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_STATE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_STATE_LT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_STATE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_STATE_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_STATE_LT,
           EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_STATE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_STATE_LT]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_STATE_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_STATE_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_STATE_LT,
           EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_STATE_LT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_STATE_LT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT]

//>> CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT]
static inline bool GET_EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT]

//>> CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT]
static inline bool GET_EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT]

//>> CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT]
static inline bool GET_EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT]

//>> CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT]
static inline bool GET_EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED]

//>> SET_[EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED]

//>> CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED]

//>> GET_[EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED]
static inline bool GET_EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR]


//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_DESKEW]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_DESKEW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_DESKEW,
           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_DESKEW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_DESKEW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_DESKEW]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_DESKEW]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_DESKEW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_DESKEW,
           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_DESKEW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_DESKEW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_DESKEW]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_DESKEW]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_DESKEW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_DESKEW,
           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_DESKEW_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_DESKEW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_DESKEW]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FILT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FILT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FILT,
           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FILT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FILT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FILT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FILT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FILT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FILT,
           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FILT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FILT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FILT]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FILT]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FILT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FILT,
           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FILT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FILT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FILT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_SEL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_SEL,
           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_SEL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_SEL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_SEL,
           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_SEL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_SEL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_SEL,
           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_SEL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_OVRBIT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_OVRBIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_OVRBIT,
           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_OVRBIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_OVRBIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_OVRBIT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_OVRBIT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_OVRBIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_OVRBIT,
           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_OVRBIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_OVRBIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_OVRBIT]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_OVRBIT]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_OVRBIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_OVRBIT,
           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_OVRBIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_OVRBIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_OVRBIT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_ROOT_CTRL6_COPY_REG]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_ROOT_CTRL6_COPY_REG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_ROOT_CTRL6_COPY_REG,
           FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_ROOT_CTRL6_COPY_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_ROOT_CTRL6_COPY_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_ROOT_CTRL6_COPY_REG]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_ROOT_CTRL6_COPY_REG]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_ROOT_CTRL6_COPY_REG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_ROOT_CTRL6_COPY_REG,
           FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_ROOT_CTRL6_COPY_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_ROOT_CTRL6_COPY_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_ROOT_CTRL6_COPY_REG]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_ROOT_CTRL6_COPY_REG]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_ROOT_CTRL6_COPY_REG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_ROOT_CTRL6_COPY_REG,
           FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_ROOT_CTRL6_COPY_REG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_ROOT_CTRL6_COPY_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_ROOT_CTRL6_COPY_REG]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL8_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL8_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL8_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL8_RW]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL8_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL8_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL8_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_RW]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL8_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL8_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL8_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL8_RW]


//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_4_15]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_4_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_4_15,
           FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_4_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_4_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_4_15]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_4_15]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_4_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_4_15,
           FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_4_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_4_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_4_15]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_4_15]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_4_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_4_15,
           FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_4_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_4_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_4_15]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_24_31]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_24_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_24_31,
           FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_24_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_24_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_24_31]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_24_31]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_24_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_24_31,
           FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_24_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_24_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_24_31]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_24_31]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_24_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_24_31,
           FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_24_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_24_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_24_31]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_ROOT_CTRL8_COPY_REG]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_ROOT_CTRL8_COPY_REG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_ROOT_CTRL8_COPY_REG,
           FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_ROOT_CTRL8_COPY_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_ROOT_CTRL8_COPY_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_ROOT_CTRL8_COPY_REG]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_ROOT_CTRL8_COPY_REG]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_ROOT_CTRL8_COPY_REG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_ROOT_CTRL8_COPY_REG,
           FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_ROOT_CTRL8_COPY_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_ROOT_CTRL8_COPY_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_ROOT_CTRL8_COPY_REG]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_ROOT_CTRL8_COPY_REG]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_ROOT_CTRL8_COPY_REG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_ROOT_CTRL8_COPY_REG,
           FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_ROOT_CTRL8_COPY_REG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_ROOT_CTRL8_COPY_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_ROOT_CTRL8_COPY_REG]

//>> PREP_[OPCG_ALIGN]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_OPCG_ALIGN(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OPCG_ALIGN;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[OPCG_ALIGN]

//>> GET_[OPCG_ALIGN]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_OPCG_ALIGN(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OPCG_ALIGN;
#endif
    return fapi2::getScom(i_target, OPCG_ALIGN, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[OPCG_ALIGN]

//>> PUT_[OPCG_ALIGN]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_OPCG_ALIGN(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return fapi2::putScom(i_target, OPCG_ALIGN, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[OPCG_ALIGN]


//>> SET_[OPCG_ALIGN_INOP_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_INOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.insertFromRight<OPCG_ALIGN_INOP_ALIGN,
           OPCG_ALIGN_INOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_ALIGN_INOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_INOP_ALIGN]

//>> SET_[OPCG_ALIGN_INOP_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_INOP_ALIGN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.insertFromRight<OPCG_ALIGN_INOP_ALIGN,
           OPCG_ALIGN_INOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_ALIGN_INOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_INOP_ALIGN]

//>> GET_[OPCG_ALIGN_INOP_ALIGN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_ALIGN_INOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return i_data.extractToRight<OPCG_ALIGN_INOP_ALIGN,
           OPCG_ALIGN_INOP_ALIGN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_ALIGN_INOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_ALIGN_INOP_ALIGN]

//>> SET_[OPCG_ALIGN_SNOP_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_SNOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.insertFromRight<OPCG_ALIGN_SNOP_ALIGN,
           OPCG_ALIGN_SNOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_ALIGN_SNOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_SNOP_ALIGN]

//>> SET_[OPCG_ALIGN_SNOP_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_SNOP_ALIGN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.insertFromRight<OPCG_ALIGN_SNOP_ALIGN,
           OPCG_ALIGN_SNOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_ALIGN_SNOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_SNOP_ALIGN]

//>> GET_[OPCG_ALIGN_SNOP_ALIGN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_ALIGN_SNOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return i_data.extractToRight<OPCG_ALIGN_SNOP_ALIGN,
           OPCG_ALIGN_SNOP_ALIGN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_ALIGN_SNOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_ALIGN_SNOP_ALIGN]

//>> SET_[OPCG_ALIGN_ENOP_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_ENOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.insertFromRight<OPCG_ALIGN_ENOP_ALIGN,
           OPCG_ALIGN_ENOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_ALIGN_ENOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_ENOP_ALIGN]

//>> SET_[OPCG_ALIGN_ENOP_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_ENOP_ALIGN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.insertFromRight<OPCG_ALIGN_ENOP_ALIGN,
           OPCG_ALIGN_ENOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_ALIGN_ENOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_ENOP_ALIGN]

//>> GET_[OPCG_ALIGN_ENOP_ALIGN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_ALIGN_ENOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return i_data.extractToRight<OPCG_ALIGN_ENOP_ALIGN,
           OPCG_ALIGN_ENOP_ALIGN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_ALIGN_ENOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_ALIGN_ENOP_ALIGN]

//>> SET_[OPCG_ALIGN_INOP_WAIT]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_INOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.insertFromRight<OPCG_ALIGN_INOP_WAIT,
           OPCG_ALIGN_INOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_ALIGN_INOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_INOP_WAIT]

//>> SET_[OPCG_ALIGN_INOP_WAIT]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_INOP_WAIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.insertFromRight<OPCG_ALIGN_INOP_WAIT,
           OPCG_ALIGN_INOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_ALIGN_INOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_INOP_WAIT]

//>> GET_[OPCG_ALIGN_INOP_WAIT]
static inline fapi2::buffer<uint64_t>& GET_OPCG_ALIGN_INOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return i_data.extractToRight<OPCG_ALIGN_INOP_WAIT,
           OPCG_ALIGN_INOP_WAIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_ALIGN_INOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_ALIGN_INOP_WAIT]

//>> SET_[OPCG_ALIGN_SNOP_WAIT]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_SNOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.insertFromRight<OPCG_ALIGN_SNOP_WAIT,
           OPCG_ALIGN_SNOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_ALIGN_SNOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_SNOP_WAIT]

//>> SET_[OPCG_ALIGN_SNOP_WAIT]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_SNOP_WAIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.insertFromRight<OPCG_ALIGN_SNOP_WAIT,
           OPCG_ALIGN_SNOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_ALIGN_SNOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_SNOP_WAIT]

//>> GET_[OPCG_ALIGN_SNOP_WAIT]
static inline fapi2::buffer<uint64_t>& GET_OPCG_ALIGN_SNOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return i_data.extractToRight<OPCG_ALIGN_SNOP_WAIT,
           OPCG_ALIGN_SNOP_WAIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_ALIGN_SNOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_ALIGN_SNOP_WAIT]

//>> SET_[OPCG_ALIGN_ENOP_WAIT]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_ENOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.insertFromRight<OPCG_ALIGN_ENOP_WAIT,
           OPCG_ALIGN_ENOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_ALIGN_ENOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_ENOP_WAIT]

//>> SET_[OPCG_ALIGN_ENOP_WAIT]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_ENOP_WAIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.insertFromRight<OPCG_ALIGN_ENOP_WAIT,
           OPCG_ALIGN_ENOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_ALIGN_ENOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_ENOP_WAIT]

//>> GET_[OPCG_ALIGN_ENOP_WAIT]
static inline fapi2::buffer<uint64_t>& GET_OPCG_ALIGN_ENOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return i_data.extractToRight<OPCG_ALIGN_ENOP_WAIT,
           OPCG_ALIGN_ENOP_WAIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_ALIGN_ENOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_ALIGN_ENOP_WAIT]

//>> SET_[OPCG_ALIGN_INOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_INOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.insertFromRight<OPCG_ALIGN_INOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_INOP_FORCE_SG]

//>> SET_[OPCG_ALIGN_INOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_INOP_FORCE_SG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.insertFromRight<OPCG_ALIGN_INOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_INOP_FORCE_SG]

//>> SET_[OPCG_ALIGN_INOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_INOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.setBit<OPCG_ALIGN_INOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_INOP_FORCE_SG]

//>> CLEAR_[OPCG_ALIGN_INOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_ALIGN_INOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.clearBit<OPCG_ALIGN_INOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_ALIGN_INOP_FORCE_SG]

//>> GET_[OPCG_ALIGN_INOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& GET_OPCG_ALIGN_INOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return i_data.extractToRight<OPCG_ALIGN_INOP_FORCE_SG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_ALIGN_INOP_FORCE_SG]

//>> GET_[OPCG_ALIGN_INOP_FORCE_SG]
static inline bool GET_OPCG_ALIGN_INOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return i_data.getBit<OPCG_ALIGN_INOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_ALIGN_INOP_FORCE_SG]

//>> SET_[OPCG_ALIGN_SNOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_SNOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.insertFromRight<OPCG_ALIGN_SNOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_SNOP_FORCE_SG]

//>> SET_[OPCG_ALIGN_SNOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_SNOP_FORCE_SG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.insertFromRight<OPCG_ALIGN_SNOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_SNOP_FORCE_SG]

//>> SET_[OPCG_ALIGN_SNOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_SNOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.setBit<OPCG_ALIGN_SNOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_SNOP_FORCE_SG]

//>> CLEAR_[OPCG_ALIGN_SNOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_ALIGN_SNOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.clearBit<OPCG_ALIGN_SNOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_ALIGN_SNOP_FORCE_SG]

//>> GET_[OPCG_ALIGN_SNOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& GET_OPCG_ALIGN_SNOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return i_data.extractToRight<OPCG_ALIGN_SNOP_FORCE_SG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_ALIGN_SNOP_FORCE_SG]

//>> GET_[OPCG_ALIGN_SNOP_FORCE_SG]
static inline bool GET_OPCG_ALIGN_SNOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return i_data.getBit<OPCG_ALIGN_SNOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_ALIGN_SNOP_FORCE_SG]

//>> SET_[OPCG_ALIGN_ENOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_ENOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.insertFromRight<OPCG_ALIGN_ENOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_ENOP_FORCE_SG]

//>> SET_[OPCG_ALIGN_ENOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_ENOP_FORCE_SG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.insertFromRight<OPCG_ALIGN_ENOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_ENOP_FORCE_SG]

//>> SET_[OPCG_ALIGN_ENOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_ENOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.setBit<OPCG_ALIGN_ENOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_ENOP_FORCE_SG]

//>> CLEAR_[OPCG_ALIGN_ENOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_ALIGN_ENOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.clearBit<OPCG_ALIGN_ENOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_ALIGN_ENOP_FORCE_SG]

//>> GET_[OPCG_ALIGN_ENOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& GET_OPCG_ALIGN_ENOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return i_data.extractToRight<OPCG_ALIGN_ENOP_FORCE_SG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_ALIGN_ENOP_FORCE_SG]

//>> GET_[OPCG_ALIGN_ENOP_FORCE_SG]
static inline bool GET_OPCG_ALIGN_ENOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return i_data.getBit<OPCG_ALIGN_ENOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_ALIGN_ENOP_FORCE_SG]

//>> SET_[OPCG_ALIGN_NO_WAIT_ON_CLK_CMD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.insertFromRight<OPCG_ALIGN_NO_WAIT_ON_CLK_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_NO_WAIT_ON_CLK_CMD]

//>> SET_[OPCG_ALIGN_NO_WAIT_ON_CLK_CMD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.insertFromRight<OPCG_ALIGN_NO_WAIT_ON_CLK_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_NO_WAIT_ON_CLK_CMD]

//>> SET_[OPCG_ALIGN_NO_WAIT_ON_CLK_CMD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.setBit<OPCG_ALIGN_NO_WAIT_ON_CLK_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_NO_WAIT_ON_CLK_CMD]

//>> CLEAR_[OPCG_ALIGN_NO_WAIT_ON_CLK_CMD]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.clearBit<OPCG_ALIGN_NO_WAIT_ON_CLK_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_ALIGN_NO_WAIT_ON_CLK_CMD]

//>> GET_[OPCG_ALIGN_NO_WAIT_ON_CLK_CMD]
static inline fapi2::buffer<uint64_t>& GET_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return i_data.extractToRight<OPCG_ALIGN_NO_WAIT_ON_CLK_CMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_ALIGN_NO_WAIT_ON_CLK_CMD]

//>> GET_[OPCG_ALIGN_NO_WAIT_ON_CLK_CMD]
static inline bool GET_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return i_data.getBit<OPCG_ALIGN_NO_WAIT_ON_CLK_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_ALIGN_NO_WAIT_ON_CLK_CMD]

//>> SET_[OPCG_ALIGN_ALIGN_SOURCE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_ALIGN_SOURCE_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.insertFromRight<OPCG_ALIGN_ALIGN_SOURCE_SELECT,
           OPCG_ALIGN_ALIGN_SOURCE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_ALIGN_ALIGN_SOURCE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_ALIGN_SOURCE_SELECT]

//>> SET_[OPCG_ALIGN_ALIGN_SOURCE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_ALIGN_SOURCE_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.insertFromRight<OPCG_ALIGN_ALIGN_SOURCE_SELECT,
           OPCG_ALIGN_ALIGN_SOURCE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_ALIGN_ALIGN_SOURCE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_ALIGN_SOURCE_SELECT]

//>> GET_[OPCG_ALIGN_ALIGN_SOURCE_SELECT]
static inline fapi2::buffer<uint64_t>& GET_OPCG_ALIGN_ALIGN_SOURCE_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return i_data.extractToRight<OPCG_ALIGN_ALIGN_SOURCE_SELECT,
           OPCG_ALIGN_ALIGN_SOURCE_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_ALIGN_ALIGN_SOURCE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_ALIGN_ALIGN_SOURCE_SELECT]

//>> SET_[OPCG_ALIGN_SCAN_RATIO]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_SCAN_RATIO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.insertFromRight<OPCG_ALIGN_SCAN_RATIO,
           OPCG_ALIGN_SCAN_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_ALIGN_SCAN_RATIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_SCAN_RATIO]

//>> SET_[OPCG_ALIGN_SCAN_RATIO]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_SCAN_RATIO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.insertFromRight<OPCG_ALIGN_SCAN_RATIO,
           OPCG_ALIGN_SCAN_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_ALIGN_SCAN_RATIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_SCAN_RATIO]

//>> GET_[OPCG_ALIGN_SCAN_RATIO]
static inline fapi2::buffer<uint64_t>& GET_OPCG_ALIGN_SCAN_RATIO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return i_data.extractToRight<OPCG_ALIGN_SCAN_RATIO,
           OPCG_ALIGN_SCAN_RATIO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_ALIGN_SCAN_RATIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_ALIGN_SCAN_RATIO]

//>> SET_[OPCG_ALIGN_OPCG_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_OPCG_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.insertFromRight<OPCG_ALIGN_OPCG_WAIT_CYCLES,
           OPCG_ALIGN_OPCG_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_ALIGN_OPCG_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_OPCG_WAIT_CYCLES]

//>> SET_[OPCG_ALIGN_OPCG_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_OPCG_ALIGN_OPCG_WAIT_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return o_data.insertFromRight<OPCG_ALIGN_OPCG_WAIT_CYCLES,
           OPCG_ALIGN_OPCG_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_ALIGN_OPCG_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_ALIGN_OPCG_WAIT_CYCLES]

//>> GET_[OPCG_ALIGN_OPCG_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& GET_OPCG_ALIGN_OPCG_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_ALIGN));
#endif
    return i_data.extractToRight<OPCG_ALIGN_OPCG_WAIT_CYCLES,
           OPCG_ALIGN_OPCG_WAIT_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_ALIGN_OPCG_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_ALIGN_OPCG_WAIT_CYCLES]

//>> PREP_[CPLT_CONF0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CONF0_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CONF0_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CONF0_RW]

//>> GET_[CPLT_CONF0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CONF0_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CONF0_RW;
#endif
    return fapi2::getScom(i_target, CPLT_CONF0_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CONF0_RW]

//>> PUT_[CPLT_CONF0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CONF0_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CONF0_RW, CPLT_CONF0_WO_CLEAR, CPLT_CONF0_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CONF0_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CONF0_RW]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_RW]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_RW]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_RW]


//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL8_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL8_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL8_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL8_FSI]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL8_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL8_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_FSI]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL8_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL8_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL8_FSI]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_RW]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_RW]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_RW]


//>> PREP_[REC_ERR_MST14_REG3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REC_ERR_MST14_REG3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REC_ERR_MST14_REG3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REC_ERR_MST14_REG3]

//>> GET_[REC_ERR_MST14_REG3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REC_ERR_MST14_REG3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REC_ERR_MST14_REG3;
#endif
    return fapi2::getScom(i_target, REC_ERR_MST14_REG3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REC_ERR_MST14_REG3]

//>> PUT_[REC_ERR_MST14_REG3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REC_ERR_MST14_REG3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return fapi2::putScom(i_target, REC_ERR_MST14_REG3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REC_ERR_MST14_REG3]


//>> SET_[REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.setBit<REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.getBit<REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_48_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_48_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_48_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_48_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_48_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_48_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_48_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_48_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_48_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_48_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_48_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_48_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG3_48_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_48_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_48_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_48_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_48_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_48_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.setBit<REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.getBit<REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_49_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_49_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_49_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_49_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_49_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_49_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_49_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_49_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_49_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_49_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_49_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_49_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG3_49_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_49_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_49_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_49_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_49_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_49_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.setBit<REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.getBit<REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_50_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_50_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_50_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_50_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_50_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_50_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_50_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_50_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_50_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_50_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_50_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_50_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG3_50_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_50_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_50_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_50_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_50_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_50_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.setBit<REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.getBit<REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_51_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_51_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_51_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_51_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_51_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_51_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_51_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_51_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_51_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_51_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_51_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_51_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG3_51_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_51_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_51_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_51_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_51_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_51_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.setBit<REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.getBit<REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_52_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_52_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_52_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_52_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_52_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_52_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_52_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_52_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_52_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_52_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_52_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_52_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG3_52_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_52_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_52_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_52_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_52_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_52_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.setBit<REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.getBit<REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_53_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_53_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_53_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_53_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_53_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_53_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_53_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_53_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_53_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_53_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_53_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_53_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG3_53_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_53_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_53_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_53_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_53_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_53_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.setBit<REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.getBit<REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_54_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_54_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_54_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_54_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_54_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_54_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_54_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_54_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_54_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_54_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_54_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_54_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG3_54_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_54_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_54_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_54_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_54_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_54_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.setBit<REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.getBit<REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_55_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_55_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_55_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_55_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_55_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_55_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_55_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_55_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_55_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_55_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_55_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_55_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG3_55_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_55_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_55_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_55_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_55_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_55_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.setBit<REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.getBit<REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_56_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_56_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_56_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_56_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_56_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_56_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_56_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_56_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_56_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_56_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_56_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_56_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG3_56_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_56_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_56_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_56_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_56_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_56_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.setBit<REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.getBit<REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_57_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_57_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_57_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_57_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_57_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_57_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_57_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_57_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_57_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_57_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_57_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_57_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG3_57_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_57_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_57_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_57_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_57_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_57_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.setBit<REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.getBit<REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_58_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_58_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_58_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_58_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_58_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_58_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_58_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_58_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_58_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_58_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_58_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_58_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG3_58_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_58_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_58_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_58_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_58_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_58_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.setBit<REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.getBit<REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_59_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_59_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_59_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_59_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_59_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_59_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_59_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_59_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_59_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_59_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_59_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_59_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG3_59_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_59_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_59_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_59_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_59_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_59_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.setBit<REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.getBit<REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_60_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_60_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_60_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_60_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_60_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_60_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_60_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_60_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_60_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_60_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_60_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_60_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG3_60_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_60_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_60_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_60_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_60_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_60_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.setBit<REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.getBit<REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_61_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_61_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_61_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_61_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_61_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_61_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_61_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_61_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_61_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_61_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_61_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_61_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG3_61_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_61_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_61_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_61_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_61_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_61_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.setBit<REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.getBit<REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_62_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_62_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_62_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_62_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_62_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_62_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_62_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_62_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_62_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_62_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_62_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_62_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG3_62_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_62_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_62_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_62_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_62_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_62_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.setBit<REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.getBit<REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG3_63_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_63_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_63_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_63_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG3_63_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_63_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG3_63_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG3_63_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG3_63_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_63_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG3_63_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG3_63_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG3_63_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG3_63_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG3));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG3_63_MST14_ERROR_CODE,
           REC_ERR_MST14_REG3_63_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG3_63_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG3_63_MST14_ERROR_CODE]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR]


//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_4_15]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_4_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_4_15,
           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_4_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_4_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_4_15]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_4_15]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_4_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_4_15,
           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_4_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_4_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_4_15]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_4_15]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_4_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_4_15,
           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_4_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_4_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_4_15]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_24_31]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_24_31(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_24_31,
           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_24_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_24_31 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_24_31]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_24_31]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_24_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_24_31,
           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_24_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_24_31 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_24_31]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_24_31]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_24_31(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_24_31,
           FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_24_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_24_31 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_24_31]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
