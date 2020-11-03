/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/eq/reg00015.H $           */
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

#ifndef __EQ_REG00015_H_
#define __EQ_REG00015_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
{
#endif


//>> PREP_[BIST]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_BIST(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = BIST;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[BIST]

//>> GET_[BIST]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_BIST(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = BIST;
#endif
    return fapi2::getScom(i_target, BIST, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[BIST]

//>> PUT_[BIST]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_BIST(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return fapi2::putScom(i_target, BIST, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[BIST]


//>> SET_[BIST_TC_BIST_START_TEST_DC]
static inline fapi2::buffer<uint64_t>& SET_BIST_TC_BIST_START_TEST_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_TC_BIST_START_TEST_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access BIST_TC_BIST_START_TEST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_TC_BIST_START_TEST_DC]

//>> SET_[BIST_TC_BIST_START_TEST_DC]
static inline fapi2::buffer<uint64_t>& SET_BIST_TC_BIST_START_TEST_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_TC_BIST_START_TEST_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access BIST_TC_BIST_START_TEST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_TC_BIST_START_TEST_DC]

//>> SET_[BIST_TC_BIST_START_TEST_DC]
static inline fapi2::buffer<uint64_t>& SET_BIST_TC_BIST_START_TEST_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.setBit<BIST_TC_BIST_START_TEST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access BIST_TC_BIST_START_TEST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_TC_BIST_START_TEST_DC]

//>> CLEAR_[BIST_TC_BIST_START_TEST_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_BIST_TC_BIST_START_TEST_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.clearBit<BIST_TC_BIST_START_TEST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access BIST_TC_BIST_START_TEST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[BIST_TC_BIST_START_TEST_DC]

//>> GET_[BIST_TC_BIST_START_TEST_DC]
static inline fapi2::buffer<uint64_t>& GET_BIST_TC_BIST_START_TEST_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.extractToRight<BIST_TC_BIST_START_TEST_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access BIST_TC_BIST_START_TEST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_TC_BIST_START_TEST_DC]

//>> GET_[BIST_TC_BIST_START_TEST_DC]
static inline bool GET_BIST_TC_BIST_START_TEST_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.getBit<BIST_TC_BIST_START_TEST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access BIST_TC_BIST_START_TEST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_TC_BIST_START_TEST_DC]

//>> SET_[BIST_TC_SRAM_ABIST_MODE_DC]
static inline fapi2::buffer<uint64_t>& SET_BIST_TC_SRAM_ABIST_MODE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_TC_SRAM_ABIST_MODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access BIST_TC_SRAM_ABIST_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_TC_SRAM_ABIST_MODE_DC]

//>> SET_[BIST_TC_SRAM_ABIST_MODE_DC]
static inline fapi2::buffer<uint64_t>& SET_BIST_TC_SRAM_ABIST_MODE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_TC_SRAM_ABIST_MODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access BIST_TC_SRAM_ABIST_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_TC_SRAM_ABIST_MODE_DC]

//>> SET_[BIST_TC_SRAM_ABIST_MODE_DC]
static inline fapi2::buffer<uint64_t>& SET_BIST_TC_SRAM_ABIST_MODE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.setBit<BIST_TC_SRAM_ABIST_MODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access BIST_TC_SRAM_ABIST_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_TC_SRAM_ABIST_MODE_DC]

//>> CLEAR_[BIST_TC_SRAM_ABIST_MODE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_BIST_TC_SRAM_ABIST_MODE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.clearBit<BIST_TC_SRAM_ABIST_MODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access BIST_TC_SRAM_ABIST_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[BIST_TC_SRAM_ABIST_MODE_DC]

//>> GET_[BIST_TC_SRAM_ABIST_MODE_DC]
static inline fapi2::buffer<uint64_t>& GET_BIST_TC_SRAM_ABIST_MODE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.extractToRight<BIST_TC_SRAM_ABIST_MODE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access BIST_TC_SRAM_ABIST_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_TC_SRAM_ABIST_MODE_DC]

//>> GET_[BIST_TC_SRAM_ABIST_MODE_DC]
static inline bool GET_BIST_TC_SRAM_ABIST_MODE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.getBit<BIST_TC_SRAM_ABIST_MODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access BIST_TC_SRAM_ABIST_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_TC_SRAM_ABIST_MODE_DC]

//>> SET_[BIST_TC_IOBIST_MODE_DC]
static inline fapi2::buffer<uint64_t>& SET_BIST_TC_IOBIST_MODE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_TC_IOBIST_MODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access BIST_TC_IOBIST_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_TC_IOBIST_MODE_DC]

//>> SET_[BIST_TC_IOBIST_MODE_DC]
static inline fapi2::buffer<uint64_t>& SET_BIST_TC_IOBIST_MODE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_TC_IOBIST_MODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access BIST_TC_IOBIST_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_TC_IOBIST_MODE_DC]

//>> SET_[BIST_TC_IOBIST_MODE_DC]
static inline fapi2::buffer<uint64_t>& SET_BIST_TC_IOBIST_MODE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.setBit<BIST_TC_IOBIST_MODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access BIST_TC_IOBIST_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_TC_IOBIST_MODE_DC]

//>> CLEAR_[BIST_TC_IOBIST_MODE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_BIST_TC_IOBIST_MODE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.clearBit<BIST_TC_IOBIST_MODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access BIST_TC_IOBIST_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[BIST_TC_IOBIST_MODE_DC]

//>> GET_[BIST_TC_IOBIST_MODE_DC]
static inline fapi2::buffer<uint64_t>& GET_BIST_TC_IOBIST_MODE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.extractToRight<BIST_TC_IOBIST_MODE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access BIST_TC_IOBIST_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_TC_IOBIST_MODE_DC]

//>> GET_[BIST_TC_IOBIST_MODE_DC]
static inline bool GET_BIST_TC_IOBIST_MODE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.getBit<BIST_TC_IOBIST_MODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access BIST_TC_IOBIST_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_TC_IOBIST_MODE_DC]

//>> SET_[BIST_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_PERV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access BIST_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_PERV]

//>> SET_[BIST_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_PERV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access BIST_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_PERV]

//>> SET_[BIST_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.setBit<BIST_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access BIST_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_PERV]

//>> CLEAR_[BIST_REGION_PERV]
static inline fapi2::buffer<uint64_t>& CLEAR_BIST_REGION_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.clearBit<BIST_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access BIST_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[BIST_REGION_PERV]

//>> GET_[BIST_REGION_PERV]
static inline fapi2::buffer<uint64_t>& GET_BIST_REGION_PERV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.extractToRight<BIST_REGION_PERV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access BIST_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_PERV]

//>> GET_[BIST_REGION_PERV]
static inline bool GET_BIST_REGION_PERV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.getBit<BIST_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access BIST_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_PERV]

//>> SET_[BIST_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access BIST_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT1]

//>> SET_[BIST_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access BIST_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT1]

//>> SET_[BIST_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.setBit<BIST_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access BIST_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT1]

//>> CLEAR_[BIST_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& CLEAR_BIST_REGION_UNIT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.clearBit<BIST_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access BIST_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[BIST_REGION_UNIT1]

//>> GET_[BIST_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& GET_BIST_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.extractToRight<BIST_REGION_UNIT1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access BIST_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT1]

//>> GET_[BIST_REGION_UNIT1]
static inline bool GET_BIST_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.getBit<BIST_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access BIST_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT1]

//>> SET_[BIST_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access BIST_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT2]

//>> SET_[BIST_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access BIST_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT2]

//>> SET_[BIST_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.setBit<BIST_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access BIST_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT2]

//>> CLEAR_[BIST_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& CLEAR_BIST_REGION_UNIT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.clearBit<BIST_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access BIST_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[BIST_REGION_UNIT2]

//>> GET_[BIST_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& GET_BIST_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.extractToRight<BIST_REGION_UNIT2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access BIST_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT2]

//>> GET_[BIST_REGION_UNIT2]
static inline bool GET_BIST_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.getBit<BIST_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access BIST_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT2]

//>> SET_[BIST_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access BIST_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT3]

//>> SET_[BIST_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access BIST_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT3]

//>> SET_[BIST_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.setBit<BIST_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access BIST_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT3]

//>> CLEAR_[BIST_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& CLEAR_BIST_REGION_UNIT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.clearBit<BIST_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access BIST_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[BIST_REGION_UNIT3]

//>> GET_[BIST_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& GET_BIST_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.extractToRight<BIST_REGION_UNIT3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access BIST_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT3]

//>> GET_[BIST_REGION_UNIT3]
static inline bool GET_BIST_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.getBit<BIST_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access BIST_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT3]

//>> SET_[BIST_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access BIST_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT4]

//>> SET_[BIST_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access BIST_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT4]

//>> SET_[BIST_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.setBit<BIST_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access BIST_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT4]

//>> CLEAR_[BIST_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& CLEAR_BIST_REGION_UNIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.clearBit<BIST_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access BIST_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[BIST_REGION_UNIT4]

//>> GET_[BIST_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& GET_BIST_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.extractToRight<BIST_REGION_UNIT4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access BIST_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT4]

//>> GET_[BIST_REGION_UNIT4]
static inline bool GET_BIST_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.getBit<BIST_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access BIST_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT4]

//>> SET_[BIST_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access BIST_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT5]

//>> SET_[BIST_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access BIST_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT5]

//>> SET_[BIST_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.setBit<BIST_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access BIST_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT5]

//>> CLEAR_[BIST_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& CLEAR_BIST_REGION_UNIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.clearBit<BIST_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access BIST_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[BIST_REGION_UNIT5]

//>> GET_[BIST_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& GET_BIST_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.extractToRight<BIST_REGION_UNIT5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access BIST_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT5]

//>> GET_[BIST_REGION_UNIT5]
static inline bool GET_BIST_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.getBit<BIST_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access BIST_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT5]

//>> SET_[BIST_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access BIST_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT6]

//>> SET_[BIST_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access BIST_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT6]

//>> SET_[BIST_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.setBit<BIST_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access BIST_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT6]

//>> CLEAR_[BIST_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& CLEAR_BIST_REGION_UNIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.clearBit<BIST_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access BIST_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[BIST_REGION_UNIT6]

//>> GET_[BIST_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& GET_BIST_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.extractToRight<BIST_REGION_UNIT6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access BIST_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT6]

//>> GET_[BIST_REGION_UNIT6]
static inline bool GET_BIST_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.getBit<BIST_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access BIST_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT6]

//>> SET_[BIST_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access BIST_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT7]

//>> SET_[BIST_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access BIST_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT7]

//>> SET_[BIST_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.setBit<BIST_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access BIST_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT7]

//>> CLEAR_[BIST_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& CLEAR_BIST_REGION_UNIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.clearBit<BIST_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access BIST_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[BIST_REGION_UNIT7]

//>> GET_[BIST_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& GET_BIST_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.extractToRight<BIST_REGION_UNIT7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access BIST_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT7]

//>> GET_[BIST_REGION_UNIT7]
static inline bool GET_BIST_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.getBit<BIST_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access BIST_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT7]

//>> SET_[BIST_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access BIST_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT8]

//>> SET_[BIST_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access BIST_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT8]

//>> SET_[BIST_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.setBit<BIST_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access BIST_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT8]

//>> CLEAR_[BIST_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& CLEAR_BIST_REGION_UNIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.clearBit<BIST_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access BIST_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[BIST_REGION_UNIT8]

//>> GET_[BIST_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& GET_BIST_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.extractToRight<BIST_REGION_UNIT8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access BIST_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT8]

//>> GET_[BIST_REGION_UNIT8]
static inline bool GET_BIST_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.getBit<BIST_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access BIST_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT8]

//>> SET_[BIST_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access BIST_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT9]

//>> SET_[BIST_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access BIST_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT9]

//>> SET_[BIST_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.setBit<BIST_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access BIST_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT9]

//>> CLEAR_[BIST_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& CLEAR_BIST_REGION_UNIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.clearBit<BIST_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access BIST_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[BIST_REGION_UNIT9]

//>> GET_[BIST_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& GET_BIST_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.extractToRight<BIST_REGION_UNIT9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access BIST_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT9]

//>> GET_[BIST_REGION_UNIT9]
static inline bool GET_BIST_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.getBit<BIST_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access BIST_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT9]

//>> SET_[BIST_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access BIST_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT10]

//>> SET_[BIST_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access BIST_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT10]

//>> SET_[BIST_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.setBit<BIST_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access BIST_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT10]

//>> CLEAR_[BIST_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& CLEAR_BIST_REGION_UNIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.clearBit<BIST_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access BIST_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[BIST_REGION_UNIT10]

//>> GET_[BIST_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& GET_BIST_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.extractToRight<BIST_REGION_UNIT10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access BIST_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT10]

//>> GET_[BIST_REGION_UNIT10]
static inline bool GET_BIST_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.getBit<BIST_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access BIST_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT10]

//>> SET_[BIST_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access BIST_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT11]

//>> SET_[BIST_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access BIST_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT11]

//>> SET_[BIST_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.setBit<BIST_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access BIST_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT11]

//>> CLEAR_[BIST_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& CLEAR_BIST_REGION_UNIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.clearBit<BIST_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access BIST_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[BIST_REGION_UNIT11]

//>> GET_[BIST_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& GET_BIST_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.extractToRight<BIST_REGION_UNIT11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access BIST_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT11]

//>> GET_[BIST_REGION_UNIT11]
static inline bool GET_BIST_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.getBit<BIST_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access BIST_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT11]

//>> SET_[BIST_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access BIST_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT12]

//>> SET_[BIST_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access BIST_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT12]

//>> SET_[BIST_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.setBit<BIST_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access BIST_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT12]

//>> CLEAR_[BIST_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& CLEAR_BIST_REGION_UNIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.clearBit<BIST_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access BIST_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[BIST_REGION_UNIT12]

//>> GET_[BIST_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& GET_BIST_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.extractToRight<BIST_REGION_UNIT12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access BIST_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT12]

//>> GET_[BIST_REGION_UNIT12]
static inline bool GET_BIST_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.getBit<BIST_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access BIST_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT12]

//>> SET_[BIST_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access BIST_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT13]

//>> SET_[BIST_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access BIST_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT13]

//>> SET_[BIST_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.setBit<BIST_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access BIST_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT13]

//>> CLEAR_[BIST_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& CLEAR_BIST_REGION_UNIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.clearBit<BIST_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access BIST_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[BIST_REGION_UNIT13]

//>> GET_[BIST_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& GET_BIST_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.extractToRight<BIST_REGION_UNIT13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access BIST_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT13]

//>> GET_[BIST_REGION_UNIT13]
static inline bool GET_BIST_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.getBit<BIST_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access BIST_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT13]

//>> SET_[BIST_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access BIST_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT14]

//>> SET_[BIST_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_REGION_UNIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access BIST_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT14]

//>> SET_[BIST_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_BIST_REGION_UNIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.setBit<BIST_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access BIST_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_REGION_UNIT14]

//>> CLEAR_[BIST_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& CLEAR_BIST_REGION_UNIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.clearBit<BIST_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access BIST_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[BIST_REGION_UNIT14]

//>> GET_[BIST_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& GET_BIST_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.extractToRight<BIST_REGION_UNIT14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access BIST_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT14]

//>> GET_[BIST_REGION_UNIT14]
static inline bool GET_BIST_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.getBit<BIST_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access BIST_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_REGION_UNIT14]

//>> SET_[BIST_STROBE_WINDOW_EN]
static inline fapi2::buffer<uint64_t>& SET_BIST_STROBE_WINDOW_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_STROBE_WINDOW_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access BIST_STROBE_WINDOW_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_STROBE_WINDOW_EN]

//>> SET_[BIST_STROBE_WINDOW_EN]
static inline fapi2::buffer<uint64_t>& SET_BIST_STROBE_WINDOW_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.insertFromRight<BIST_STROBE_WINDOW_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access BIST_STROBE_WINDOW_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_STROBE_WINDOW_EN]

//>> SET_[BIST_STROBE_WINDOW_EN]
static inline fapi2::buffer<uint64_t>& SET_BIST_STROBE_WINDOW_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.setBit<BIST_STROBE_WINDOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access BIST_STROBE_WINDOW_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[BIST_STROBE_WINDOW_EN]

//>> CLEAR_[BIST_STROBE_WINDOW_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_BIST_STROBE_WINDOW_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return o_data.clearBit<BIST_STROBE_WINDOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access BIST_STROBE_WINDOW_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[BIST_STROBE_WINDOW_EN]

//>> GET_[BIST_STROBE_WINDOW_EN]
static inline fapi2::buffer<uint64_t>& GET_BIST_STROBE_WINDOW_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.extractToRight<BIST_STROBE_WINDOW_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access BIST_STROBE_WINDOW_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_STROBE_WINDOW_EN]

//>> GET_[BIST_STROBE_WINDOW_EN]
static inline bool GET_BIST_STROBE_WINDOW_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(BIST));
#endif
    return i_data.getBit<BIST_STROBE_WINDOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access BIST_STROBE_WINDOW_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[BIST_STROBE_WINDOW_EN]

//>> PREP_[CPLT_CTRL5_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL5_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL5_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CTRL5_RW]

//>> GET_[CPLT_CTRL5_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL5_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL5_RW;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL5_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CTRL5_RW]

//>> PUT_[CPLT_CTRL5_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL5_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL5_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CTRL5_RW]

//>> PREP_[CPLT_CTRL5_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL5_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL5_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CTRL5_WO_CLEAR]

//>> GET_[CPLT_CTRL5_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL5_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL5_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL5_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CTRL5_WO_CLEAR]

//>> PUT_[CPLT_CTRL5_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL5_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL5_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CTRL5_WO_CLEAR]

//>> PREP_[CPLT_CTRL5_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL5_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL5_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CTRL5_WO_OR]

//>> GET_[CPLT_CTRL5_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL5_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL5_WO_OR;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL5_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CTRL5_WO_OR]

//>> PUT_[CPLT_CTRL5_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL5_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL5_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CTRL5_WO_OR]


//>> SET_[CPLT_CTRL5_VITL_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_VITL_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_VITL_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL5_VITL_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_VITL_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_VITL_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_VITL_DFT_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_VITL_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL5_VITL_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_VITL_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_VITL_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_VITL_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_VITL_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL5_VITL_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_VITL_DFT_FENCE_DC]

//>> CLEAR_[CPLT_CTRL5_VITL_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_VITL_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_VITL_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL5_VITL_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_VITL_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_VITL_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_VITL_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_VITL_DFT_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL5_VITL_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_VITL_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_VITL_DFT_FENCE_DC]
static inline bool GET_CPLT_CTRL5_VITL_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_VITL_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL5_VITL_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_VITL_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION0_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION0_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION0_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL5_REGION0_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION0_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION0_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION0_DFT_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION0_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL5_REGION0_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION0_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION0_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION0_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_REGION0_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL5_REGION0_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION0_DFT_FENCE_DC]

//>> CLEAR_[CPLT_CTRL5_REGION0_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_REGION0_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_REGION0_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL5_REGION0_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_REGION0_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION0_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_REGION0_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_REGION0_DFT_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL5_REGION0_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION0_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION0_DFT_FENCE_DC]
static inline bool GET_CPLT_CTRL5_REGION0_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_REGION0_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL5_REGION0_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION0_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION1_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION1_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION1_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL5_REGION1_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION1_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION1_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION1_DFT_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION1_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL5_REGION1_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION1_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION1_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION1_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_REGION1_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL5_REGION1_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION1_DFT_FENCE_DC]

//>> CLEAR_[CPLT_CTRL5_REGION1_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_REGION1_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_REGION1_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL5_REGION1_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_REGION1_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION1_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_REGION1_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_REGION1_DFT_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL5_REGION1_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION1_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION1_DFT_FENCE_DC]
static inline bool GET_CPLT_CTRL5_REGION1_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_REGION1_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL5_REGION1_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION1_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION2_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION2_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION2_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL5_REGION2_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION2_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION2_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION2_DFT_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION2_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL5_REGION2_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION2_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION2_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION2_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_REGION2_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL5_REGION2_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION2_DFT_FENCE_DC]

//>> CLEAR_[CPLT_CTRL5_REGION2_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_REGION2_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_REGION2_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL5_REGION2_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_REGION2_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION2_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_REGION2_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_REGION2_DFT_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL5_REGION2_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION2_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION2_DFT_FENCE_DC]
static inline bool GET_CPLT_CTRL5_REGION2_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_REGION2_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL5_REGION2_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION2_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION3_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION3_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION3_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL5_REGION3_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION3_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION3_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION3_DFT_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION3_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL5_REGION3_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION3_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION3_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION3_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_REGION3_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL5_REGION3_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION3_DFT_FENCE_DC]

//>> CLEAR_[CPLT_CTRL5_REGION3_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_REGION3_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_REGION3_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL5_REGION3_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_REGION3_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION3_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_REGION3_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_REGION3_DFT_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL5_REGION3_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION3_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION3_DFT_FENCE_DC]
static inline bool GET_CPLT_CTRL5_REGION3_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_REGION3_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL5_REGION3_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION3_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION4_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION4_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION4_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL5_REGION4_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION4_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION4_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION4_DFT_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION4_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL5_REGION4_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION4_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION4_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION4_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_REGION4_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL5_REGION4_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION4_DFT_FENCE_DC]

//>> CLEAR_[CPLT_CTRL5_REGION4_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_REGION4_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_REGION4_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL5_REGION4_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_REGION4_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION4_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_REGION4_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_REGION4_DFT_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL5_REGION4_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION4_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION4_DFT_FENCE_DC]
static inline bool GET_CPLT_CTRL5_REGION4_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_REGION4_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL5_REGION4_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION4_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION5_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION5_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION5_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL5_REGION5_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION5_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION5_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION5_DFT_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION5_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL5_REGION5_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION5_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION5_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION5_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_REGION5_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL5_REGION5_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION5_DFT_FENCE_DC]

//>> CLEAR_[CPLT_CTRL5_REGION5_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_REGION5_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_REGION5_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL5_REGION5_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_REGION5_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION5_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_REGION5_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_REGION5_DFT_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL5_REGION5_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION5_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION5_DFT_FENCE_DC]
static inline bool GET_CPLT_CTRL5_REGION5_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_REGION5_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL5_REGION5_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION5_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION6_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION6_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION6_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL5_REGION6_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION6_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION6_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION6_DFT_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION6_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL5_REGION6_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION6_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION6_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION6_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_REGION6_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL5_REGION6_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION6_DFT_FENCE_DC]

//>> CLEAR_[CPLT_CTRL5_REGION6_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_REGION6_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_REGION6_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL5_REGION6_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_REGION6_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION6_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_REGION6_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_REGION6_DFT_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL5_REGION6_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION6_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION6_DFT_FENCE_DC]
static inline bool GET_CPLT_CTRL5_REGION6_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_REGION6_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL5_REGION6_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION6_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION7_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION7_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION7_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL5_REGION7_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION7_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION7_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION7_DFT_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION7_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL5_REGION7_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION7_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION7_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION7_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_REGION7_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL5_REGION7_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION7_DFT_FENCE_DC]

//>> CLEAR_[CPLT_CTRL5_REGION7_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_REGION7_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_REGION7_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL5_REGION7_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_REGION7_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION7_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_REGION7_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_REGION7_DFT_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL5_REGION7_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION7_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION7_DFT_FENCE_DC]
static inline bool GET_CPLT_CTRL5_REGION7_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_REGION7_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL5_REGION7_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION7_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION8_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION8_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION8_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL5_REGION8_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION8_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION8_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION8_DFT_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION8_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL5_REGION8_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION8_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION8_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION8_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_REGION8_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL5_REGION8_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION8_DFT_FENCE_DC]

//>> CLEAR_[CPLT_CTRL5_REGION8_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_REGION8_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_REGION8_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL5_REGION8_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_REGION8_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION8_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_REGION8_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_REGION8_DFT_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL5_REGION8_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION8_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION8_DFT_FENCE_DC]
static inline bool GET_CPLT_CTRL5_REGION8_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_REGION8_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL5_REGION8_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION8_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION9_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION9_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION9_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL5_REGION9_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION9_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION9_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION9_DFT_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION9_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL5_REGION9_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION9_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION9_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION9_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_REGION9_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL5_REGION9_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION9_DFT_FENCE_DC]

//>> CLEAR_[CPLT_CTRL5_REGION9_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_REGION9_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_REGION9_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL5_REGION9_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_REGION9_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION9_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_REGION9_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_REGION9_DFT_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL5_REGION9_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION9_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION9_DFT_FENCE_DC]
static inline bool GET_CPLT_CTRL5_REGION9_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_REGION9_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL5_REGION9_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION9_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION10_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION10_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION10_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL5_REGION10_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION10_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION10_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION10_DFT_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION10_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL5_REGION10_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION10_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION10_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION10_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_REGION10_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL5_REGION10_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION10_DFT_FENCE_DC]

//>> CLEAR_[CPLT_CTRL5_REGION10_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_REGION10_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_REGION10_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL5_REGION10_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_REGION10_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION10_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_REGION10_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_REGION10_DFT_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL5_REGION10_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION10_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION10_DFT_FENCE_DC]
static inline bool GET_CPLT_CTRL5_REGION10_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_REGION10_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL5_REGION10_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION10_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION11_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION11_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION11_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL5_REGION11_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION11_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION11_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION11_DFT_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION11_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL5_REGION11_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION11_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION11_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION11_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_REGION11_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL5_REGION11_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION11_DFT_FENCE_DC]

//>> CLEAR_[CPLT_CTRL5_REGION11_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_REGION11_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_REGION11_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL5_REGION11_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_REGION11_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION11_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_REGION11_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_REGION11_DFT_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL5_REGION11_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION11_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION11_DFT_FENCE_DC]
static inline bool GET_CPLT_CTRL5_REGION11_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_REGION11_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL5_REGION11_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION11_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION12_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION12_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION12_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL5_REGION12_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION12_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION12_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION12_DFT_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION12_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL5_REGION12_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION12_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION12_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION12_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_REGION12_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL5_REGION12_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION12_DFT_FENCE_DC]

//>> CLEAR_[CPLT_CTRL5_REGION12_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_REGION12_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_REGION12_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL5_REGION12_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_REGION12_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION12_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_REGION12_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_REGION12_DFT_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL5_REGION12_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION12_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION12_DFT_FENCE_DC]
static inline bool GET_CPLT_CTRL5_REGION12_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_REGION12_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL5_REGION12_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION12_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION13_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION13_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION13_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL5_REGION13_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION13_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION13_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION13_DFT_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION13_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL5_REGION13_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION13_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION13_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION13_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_REGION13_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL5_REGION13_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION13_DFT_FENCE_DC]

//>> CLEAR_[CPLT_CTRL5_REGION13_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_REGION13_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_REGION13_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL5_REGION13_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_REGION13_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION13_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_REGION13_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_REGION13_DFT_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL5_REGION13_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION13_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION13_DFT_FENCE_DC]
static inline bool GET_CPLT_CTRL5_REGION13_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_REGION13_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL5_REGION13_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION13_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION14_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION14_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION14_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL5_REGION14_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION14_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION14_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION14_DFT_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_REGION14_DFT_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL5_REGION14_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION14_DFT_FENCE_DC]

//>> SET_[CPLT_CTRL5_REGION14_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_REGION14_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_REGION14_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL5_REGION14_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_REGION14_DFT_FENCE_DC]

//>> CLEAR_[CPLT_CTRL5_REGION14_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_REGION14_DFT_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_REGION14_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL5_REGION14_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_REGION14_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION14_DFT_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_REGION14_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_REGION14_DFT_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL5_REGION14_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION14_DFT_FENCE_DC]

//>> GET_[CPLT_CTRL5_REGION14_DFT_FENCE_DC]
static inline bool GET_CPLT_CTRL5_REGION14_DFT_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_REGION14_DFT_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL5_REGION14_DFT_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_REGION14_DFT_FENCE_DC]

//>> PREP_[EPS_THERM_WSUB_DTS_RESULT0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_THERM_WSUB_DTS_RESULT0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB_DTS_RESULT0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EPS_THERM_WSUB_DTS_RESULT0]

//>> GET_[EPS_THERM_WSUB_DTS_RESULT0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_THERM_WSUB_DTS_RESULT0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB_DTS_RESULT0;
#endif
    return fapi2::getScom(i_target, EPS_THERM_WSUB_DTS_RESULT0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EPS_THERM_WSUB_DTS_RESULT0]

//>> PUT_[EPS_THERM_WSUB_DTS_RESULT0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_THERM_WSUB_DTS_RESULT0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT0));
#endif
    return fapi2::putScom(i_target, EPS_THERM_WSUB_DTS_RESULT0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_THERM_WSUB_DTS_RESULT0]


//>> SET_[EPS_THERM_WSUB_DTS_RESULT0_0_RESULT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_DTS_RESULT0_0_RESULT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT0));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_DTS_RESULT0_0_RESULT,
           EPS_THERM_WSUB_DTS_RESULT0_0_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB_DTS_RESULT0_0_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_DTS_RESULT0_0_RESULT]

//>> SET_[EPS_THERM_WSUB_DTS_RESULT0_0_RESULT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_DTS_RESULT0_0_RESULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT0));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_DTS_RESULT0_0_RESULT,
           EPS_THERM_WSUB_DTS_RESULT0_0_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB_DTS_RESULT0_0_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_DTS_RESULT0_0_RESULT]

//>> GET_[EPS_THERM_WSUB_DTS_RESULT0_0_RESULT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_DTS_RESULT0_0_RESULT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT0));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_DTS_RESULT0_0_RESULT,
           EPS_THERM_WSUB_DTS_RESULT0_0_RESULT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB_DTS_RESULT0_0_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_DTS_RESULT0_0_RESULT]

//>> SET_[EPS_THERM_WSUB_DTS_RESULT0_1_RESULT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_DTS_RESULT0_1_RESULT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT0));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_DTS_RESULT0_1_RESULT,
           EPS_THERM_WSUB_DTS_RESULT0_1_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB_DTS_RESULT0_1_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_DTS_RESULT0_1_RESULT]

//>> SET_[EPS_THERM_WSUB_DTS_RESULT0_1_RESULT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_DTS_RESULT0_1_RESULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT0));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_DTS_RESULT0_1_RESULT,
           EPS_THERM_WSUB_DTS_RESULT0_1_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB_DTS_RESULT0_1_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_DTS_RESULT0_1_RESULT]

//>> GET_[EPS_THERM_WSUB_DTS_RESULT0_1_RESULT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_DTS_RESULT0_1_RESULT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT0));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_DTS_RESULT0_1_RESULT,
           EPS_THERM_WSUB_DTS_RESULT0_1_RESULT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB_DTS_RESULT0_1_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_DTS_RESULT0_1_RESULT]

//>> SET_[EPS_THERM_WSUB_DTS_RESULT0_2_RESULT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_DTS_RESULT0_2_RESULT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT0));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_DTS_RESULT0_2_RESULT,
           EPS_THERM_WSUB_DTS_RESULT0_2_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB_DTS_RESULT0_2_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_DTS_RESULT0_2_RESULT]

//>> SET_[EPS_THERM_WSUB_DTS_RESULT0_2_RESULT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_DTS_RESULT0_2_RESULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT0));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_DTS_RESULT0_2_RESULT,
           EPS_THERM_WSUB_DTS_RESULT0_2_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB_DTS_RESULT0_2_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_DTS_RESULT0_2_RESULT]

//>> GET_[EPS_THERM_WSUB_DTS_RESULT0_2_RESULT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_DTS_RESULT0_2_RESULT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT0));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_DTS_RESULT0_2_RESULT,
           EPS_THERM_WSUB_DTS_RESULT0_2_RESULT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB_DTS_RESULT0_2_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_DTS_RESULT0_2_RESULT]

//>> PREP_[QME_PBCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_PBCR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PBCR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_PBCR]

//>> GET_[QME_PBCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_PBCR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PBCR;
#endif
    return fapi2::getScom(i_target, QME_PBCR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_PBCR]

//>> PUT_[QME_PBCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_PBCR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, QME_PBCR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_PBCR]

//>> PREP_[QME_PBCR_SCOM2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_PBCR_SCOM2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PBCR_SCOM2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_PBCR_SCOM2]

//>> GET_[QME_PBCR_SCOM2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_PBCR_SCOM2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PBCR_SCOM2;
#endif
    return fapi2::getScom(i_target, QME_PBCR_SCOM2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_PBCR_SCOM2]

//>> PUT_[QME_PBCR_SCOM2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_PBCR_SCOM2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, QME_PBCR_SCOM2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_PBCR_SCOM2]

//>> PREP_[QME_PBCR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_PBCR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PBCR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_PBCR_WO_CLEAR]

//>> GET_[QME_PBCR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_PBCR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PBCR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, QME_PBCR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_PBCR_WO_CLEAR]

//>> PUT_[QME_PBCR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_PBCR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, QME_PBCR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_PBCR_WO_CLEAR]


//>> SET_[QME_PBCR_DISABLE_LN_RD]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_DISABLE_LN_RD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_DISABLE_LN_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PBCR_DISABLE_LN_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_DISABLE_LN_RD]

//>> SET_[QME_PBCR_DISABLE_LN_RD]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_DISABLE_LN_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_DISABLE_LN_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PBCR_DISABLE_LN_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_DISABLE_LN_RD]

//>> SET_[QME_PBCR_DISABLE_LN_RD]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_DISABLE_LN_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.setBit<QME_PBCR_DISABLE_LN_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PBCR_DISABLE_LN_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_DISABLE_LN_RD]

//>> CLEAR_[QME_PBCR_DISABLE_LN_RD]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PBCR_DISABLE_LN_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_PBCR_DISABLE_LN_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PBCR_DISABLE_LN_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PBCR_DISABLE_LN_RD]

//>> GET_[QME_PBCR_DISABLE_LN_RD]
static inline fapi2::buffer<uint64_t>& GET_QME_PBCR_DISABLE_LN_RD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_PBCR_DISABLE_LN_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PBCR_DISABLE_LN_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_DISABLE_LN_RD]

//>> GET_[QME_PBCR_DISABLE_LN_RD]
static inline bool GET_QME_PBCR_DISABLE_LN_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.getBit<QME_PBCR_DISABLE_LN_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PBCR_DISABLE_LN_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_DISABLE_LN_RD]

//>> SET_[QME_PBCR_DISABLE_NN_RN_RD]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_DISABLE_NN_RN_RD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_DISABLE_NN_RN_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PBCR_DISABLE_NN_RN_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_DISABLE_NN_RN_RD]

//>> SET_[QME_PBCR_DISABLE_NN_RN_RD]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_DISABLE_NN_RN_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_DISABLE_NN_RN_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PBCR_DISABLE_NN_RN_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_DISABLE_NN_RN_RD]

//>> SET_[QME_PBCR_DISABLE_NN_RN_RD]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_DISABLE_NN_RN_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.setBit<QME_PBCR_DISABLE_NN_RN_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PBCR_DISABLE_NN_RN_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_DISABLE_NN_RN_RD]

//>> CLEAR_[QME_PBCR_DISABLE_NN_RN_RD]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PBCR_DISABLE_NN_RN_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_PBCR_DISABLE_NN_RN_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PBCR_DISABLE_NN_RN_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PBCR_DISABLE_NN_RN_RD]

//>> GET_[QME_PBCR_DISABLE_NN_RN_RD]
static inline fapi2::buffer<uint64_t>& GET_QME_PBCR_DISABLE_NN_RN_RD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_PBCR_DISABLE_NN_RN_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PBCR_DISABLE_NN_RN_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_DISABLE_NN_RN_RD]

//>> GET_[QME_PBCR_DISABLE_NN_RN_RD]
static inline bool GET_QME_PBCR_DISABLE_NN_RN_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.getBit<QME_PBCR_DISABLE_NN_RN_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PBCR_DISABLE_NN_RN_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_DISABLE_NN_RN_RD]

//>> SET_[QME_PBCR_DISABLE_GROUP_RD]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_DISABLE_GROUP_RD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_DISABLE_GROUP_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PBCR_DISABLE_GROUP_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_DISABLE_GROUP_RD]

//>> SET_[QME_PBCR_DISABLE_GROUP_RD]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_DISABLE_GROUP_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_DISABLE_GROUP_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PBCR_DISABLE_GROUP_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_DISABLE_GROUP_RD]

//>> SET_[QME_PBCR_DISABLE_GROUP_RD]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_DISABLE_GROUP_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.setBit<QME_PBCR_DISABLE_GROUP_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PBCR_DISABLE_GROUP_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_DISABLE_GROUP_RD]

//>> CLEAR_[QME_PBCR_DISABLE_GROUP_RD]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PBCR_DISABLE_GROUP_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_PBCR_DISABLE_GROUP_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PBCR_DISABLE_GROUP_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PBCR_DISABLE_GROUP_RD]

//>> GET_[QME_PBCR_DISABLE_GROUP_RD]
static inline fapi2::buffer<uint64_t>& GET_QME_PBCR_DISABLE_GROUP_RD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_PBCR_DISABLE_GROUP_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PBCR_DISABLE_GROUP_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_DISABLE_GROUP_RD]

//>> GET_[QME_PBCR_DISABLE_GROUP_RD]
static inline bool GET_QME_PBCR_DISABLE_GROUP_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.getBit<QME_PBCR_DISABLE_GROUP_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PBCR_DISABLE_GROUP_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_DISABLE_GROUP_RD]

//>> SET_[QME_PBCR_DISABLE_VG_RD]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_DISABLE_VG_RD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_DISABLE_VG_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PBCR_DISABLE_VG_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_DISABLE_VG_RD]

//>> SET_[QME_PBCR_DISABLE_VG_RD]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_DISABLE_VG_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_DISABLE_VG_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PBCR_DISABLE_VG_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_DISABLE_VG_RD]

//>> SET_[QME_PBCR_DISABLE_VG_RD]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_DISABLE_VG_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.setBit<QME_PBCR_DISABLE_VG_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PBCR_DISABLE_VG_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_DISABLE_VG_RD]

//>> CLEAR_[QME_PBCR_DISABLE_VG_RD]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PBCR_DISABLE_VG_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_PBCR_DISABLE_VG_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PBCR_DISABLE_VG_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PBCR_DISABLE_VG_RD]

//>> GET_[QME_PBCR_DISABLE_VG_RD]
static inline fapi2::buffer<uint64_t>& GET_QME_PBCR_DISABLE_VG_RD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_PBCR_DISABLE_VG_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PBCR_DISABLE_VG_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_DISABLE_VG_RD]

//>> GET_[QME_PBCR_DISABLE_VG_RD]
static inline bool GET_QME_PBCR_DISABLE_VG_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.getBit<QME_PBCR_DISABLE_VG_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PBCR_DISABLE_VG_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_DISABLE_VG_RD]

//>> SET_[QME_PBCR_DISABLE_LN_WR]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_DISABLE_LN_WR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_DISABLE_LN_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PBCR_DISABLE_LN_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_DISABLE_LN_WR]

//>> SET_[QME_PBCR_DISABLE_LN_WR]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_DISABLE_LN_WR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_DISABLE_LN_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PBCR_DISABLE_LN_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_DISABLE_LN_WR]

//>> SET_[QME_PBCR_DISABLE_LN_WR]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_DISABLE_LN_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.setBit<QME_PBCR_DISABLE_LN_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PBCR_DISABLE_LN_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_DISABLE_LN_WR]

//>> CLEAR_[QME_PBCR_DISABLE_LN_WR]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PBCR_DISABLE_LN_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_PBCR_DISABLE_LN_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PBCR_DISABLE_LN_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PBCR_DISABLE_LN_WR]

//>> GET_[QME_PBCR_DISABLE_LN_WR]
static inline fapi2::buffer<uint64_t>& GET_QME_PBCR_DISABLE_LN_WR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_PBCR_DISABLE_LN_WR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PBCR_DISABLE_LN_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_DISABLE_LN_WR]

//>> GET_[QME_PBCR_DISABLE_LN_WR]
static inline bool GET_QME_PBCR_DISABLE_LN_WR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.getBit<QME_PBCR_DISABLE_LN_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PBCR_DISABLE_LN_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_DISABLE_LN_WR]

//>> SET_[QME_PBCR_DISABLE_NN_RN_WR]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_DISABLE_NN_RN_WR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_DISABLE_NN_RN_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PBCR_DISABLE_NN_RN_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_DISABLE_NN_RN_WR]

//>> SET_[QME_PBCR_DISABLE_NN_RN_WR]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_DISABLE_NN_RN_WR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_DISABLE_NN_RN_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PBCR_DISABLE_NN_RN_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_DISABLE_NN_RN_WR]

//>> SET_[QME_PBCR_DISABLE_NN_RN_WR]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_DISABLE_NN_RN_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.setBit<QME_PBCR_DISABLE_NN_RN_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PBCR_DISABLE_NN_RN_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_DISABLE_NN_RN_WR]

//>> CLEAR_[QME_PBCR_DISABLE_NN_RN_WR]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PBCR_DISABLE_NN_RN_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_PBCR_DISABLE_NN_RN_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PBCR_DISABLE_NN_RN_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PBCR_DISABLE_NN_RN_WR]

//>> GET_[QME_PBCR_DISABLE_NN_RN_WR]
static inline fapi2::buffer<uint64_t>& GET_QME_PBCR_DISABLE_NN_RN_WR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_PBCR_DISABLE_NN_RN_WR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PBCR_DISABLE_NN_RN_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_DISABLE_NN_RN_WR]

//>> GET_[QME_PBCR_DISABLE_NN_RN_WR]
static inline bool GET_QME_PBCR_DISABLE_NN_RN_WR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.getBit<QME_PBCR_DISABLE_NN_RN_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PBCR_DISABLE_NN_RN_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_DISABLE_NN_RN_WR]

//>> SET_[QME_PBCR_DISABLE_GROUP_WR]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_DISABLE_GROUP_WR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_DISABLE_GROUP_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PBCR_DISABLE_GROUP_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_DISABLE_GROUP_WR]

//>> SET_[QME_PBCR_DISABLE_GROUP_WR]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_DISABLE_GROUP_WR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_DISABLE_GROUP_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PBCR_DISABLE_GROUP_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_DISABLE_GROUP_WR]

//>> SET_[QME_PBCR_DISABLE_GROUP_WR]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_DISABLE_GROUP_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.setBit<QME_PBCR_DISABLE_GROUP_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PBCR_DISABLE_GROUP_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_DISABLE_GROUP_WR]

//>> CLEAR_[QME_PBCR_DISABLE_GROUP_WR]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PBCR_DISABLE_GROUP_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_PBCR_DISABLE_GROUP_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PBCR_DISABLE_GROUP_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PBCR_DISABLE_GROUP_WR]

//>> GET_[QME_PBCR_DISABLE_GROUP_WR]
static inline fapi2::buffer<uint64_t>& GET_QME_PBCR_DISABLE_GROUP_WR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_PBCR_DISABLE_GROUP_WR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PBCR_DISABLE_GROUP_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_DISABLE_GROUP_WR]

//>> GET_[QME_PBCR_DISABLE_GROUP_WR]
static inline bool GET_QME_PBCR_DISABLE_GROUP_WR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.getBit<QME_PBCR_DISABLE_GROUP_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PBCR_DISABLE_GROUP_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_DISABLE_GROUP_WR]

//>> SET_[QME_PBCR_DISABLE_VG_WR]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_DISABLE_VG_WR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_DISABLE_VG_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PBCR_DISABLE_VG_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_DISABLE_VG_WR]

//>> SET_[QME_PBCR_DISABLE_VG_WR]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_DISABLE_VG_WR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_DISABLE_VG_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PBCR_DISABLE_VG_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_DISABLE_VG_WR]

//>> SET_[QME_PBCR_DISABLE_VG_WR]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_DISABLE_VG_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.setBit<QME_PBCR_DISABLE_VG_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PBCR_DISABLE_VG_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_DISABLE_VG_WR]

//>> CLEAR_[QME_PBCR_DISABLE_VG_WR]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PBCR_DISABLE_VG_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_PBCR_DISABLE_VG_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PBCR_DISABLE_VG_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PBCR_DISABLE_VG_WR]

//>> GET_[QME_PBCR_DISABLE_VG_WR]
static inline fapi2::buffer<uint64_t>& GET_QME_PBCR_DISABLE_VG_WR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_PBCR_DISABLE_VG_WR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PBCR_DISABLE_VG_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_DISABLE_VG_WR]

//>> GET_[QME_PBCR_DISABLE_VG_WR]
static inline bool GET_QME_PBCR_DISABLE_VG_WR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.getBit<QME_PBCR_DISABLE_VG_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PBCR_DISABLE_VG_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_DISABLE_VG_WR]

//>> SET_[QME_PBCR_SKIP_GROUP_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_SKIP_GROUP_SCOPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_SKIP_GROUP_SCOPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PBCR_SKIP_GROUP_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_SKIP_GROUP_SCOPE]

//>> SET_[QME_PBCR_SKIP_GROUP_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_SKIP_GROUP_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_SKIP_GROUP_SCOPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PBCR_SKIP_GROUP_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_SKIP_GROUP_SCOPE]

//>> SET_[QME_PBCR_SKIP_GROUP_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_SKIP_GROUP_SCOPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.setBit<QME_PBCR_SKIP_GROUP_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PBCR_SKIP_GROUP_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_SKIP_GROUP_SCOPE]

//>> CLEAR_[QME_PBCR_SKIP_GROUP_SCOPE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PBCR_SKIP_GROUP_SCOPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_PBCR_SKIP_GROUP_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PBCR_SKIP_GROUP_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PBCR_SKIP_GROUP_SCOPE]

//>> GET_[QME_PBCR_SKIP_GROUP_SCOPE]
static inline fapi2::buffer<uint64_t>& GET_QME_PBCR_SKIP_GROUP_SCOPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_PBCR_SKIP_GROUP_SCOPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PBCR_SKIP_GROUP_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_SKIP_GROUP_SCOPE]

//>> GET_[QME_PBCR_SKIP_GROUP_SCOPE]
static inline bool GET_QME_PBCR_SKIP_GROUP_SCOPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.getBit<QME_PBCR_SKIP_GROUP_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PBCR_SKIP_GROUP_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_SKIP_GROUP_SCOPE]

//>> SET_[QME_PBCR_USE_DMA_PR_W]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_USE_DMA_PR_W(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_USE_DMA_PR_W,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PBCR_USE_DMA_PR_W chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_USE_DMA_PR_W]

//>> SET_[QME_PBCR_USE_DMA_PR_W]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_USE_DMA_PR_W(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_USE_DMA_PR_W,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PBCR_USE_DMA_PR_W chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_USE_DMA_PR_W]

//>> SET_[QME_PBCR_USE_DMA_PR_W]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_USE_DMA_PR_W(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.setBit<QME_PBCR_USE_DMA_PR_W>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PBCR_USE_DMA_PR_W chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_USE_DMA_PR_W]

//>> CLEAR_[QME_PBCR_USE_DMA_PR_W]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PBCR_USE_DMA_PR_W(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_PBCR_USE_DMA_PR_W>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PBCR_USE_DMA_PR_W chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PBCR_USE_DMA_PR_W]

//>> GET_[QME_PBCR_USE_DMA_PR_W]
static inline fapi2::buffer<uint64_t>& GET_QME_PBCR_USE_DMA_PR_W(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_PBCR_USE_DMA_PR_W,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PBCR_USE_DMA_PR_W chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_USE_DMA_PR_W]

//>> GET_[QME_PBCR_USE_DMA_PR_W]
static inline bool GET_QME_PBCR_USE_DMA_PR_W(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.getBit<QME_PBCR_USE_DMA_PR_W>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PBCR_USE_DMA_PR_W chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_USE_DMA_PR_W]

//>> SET_[QME_PBCR_FREEZE_ON_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_FREEZE_ON_CRESP_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_FREEZE_ON_CRESP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PBCR_FREEZE_ON_CRESP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_FREEZE_ON_CRESP_ERR]

//>> SET_[QME_PBCR_FREEZE_ON_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_FREEZE_ON_CRESP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_FREEZE_ON_CRESP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PBCR_FREEZE_ON_CRESP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_FREEZE_ON_CRESP_ERR]

//>> SET_[QME_PBCR_FREEZE_ON_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_FREEZE_ON_CRESP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.setBit<QME_PBCR_FREEZE_ON_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PBCR_FREEZE_ON_CRESP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_FREEZE_ON_CRESP_ERR]

//>> CLEAR_[QME_PBCR_FREEZE_ON_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PBCR_FREEZE_ON_CRESP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_PBCR_FREEZE_ON_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PBCR_FREEZE_ON_CRESP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PBCR_FREEZE_ON_CRESP_ERR]

//>> GET_[QME_PBCR_FREEZE_ON_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& GET_QME_PBCR_FREEZE_ON_CRESP_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_PBCR_FREEZE_ON_CRESP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PBCR_FREEZE_ON_CRESP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_FREEZE_ON_CRESP_ERR]

//>> GET_[QME_PBCR_FREEZE_ON_CRESP_ERR]
static inline bool GET_QME_PBCR_FREEZE_ON_CRESP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.getBit<QME_PBCR_FREEZE_ON_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PBCR_FREEZE_ON_CRESP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_FREEZE_ON_CRESP_ERR]

//>> SET_[QME_PBCR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_SPARE,
           QME_PBCR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PBCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_SPARE]

//>> SET_[QME_PBCR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_SPARE,
           QME_PBCR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PBCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_SPARE]

//>> GET_[QME_PBCR_SPARE]
static inline fapi2::buffer<uint64_t>& GET_QME_PBCR_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_PBCR_SPARE,
           QME_PBCR_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PBCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_SPARE]

//>> SET_[QME_PBCR_TYPE]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_TYPE,
           QME_PBCR_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PBCR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_TYPE]

//>> SET_[QME_PBCR_TYPE]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_TYPE,
           QME_PBCR_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PBCR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_TYPE]

//>> GET_[QME_PBCR_TYPE]
static inline fapi2::buffer<uint64_t>& GET_QME_PBCR_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_PBCR_TYPE,
           QME_PBCR_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PBCR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_TYPE]

//>> SET_[QME_PBCR_HANG_POLL_MAX_CNT]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_HANG_POLL_MAX_CNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_HANG_POLL_MAX_CNT,
           QME_PBCR_HANG_POLL_MAX_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PBCR_HANG_POLL_MAX_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_HANG_POLL_MAX_CNT]

//>> SET_[QME_PBCR_HANG_POLL_MAX_CNT]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_HANG_POLL_MAX_CNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_HANG_POLL_MAX_CNT,
           QME_PBCR_HANG_POLL_MAX_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PBCR_HANG_POLL_MAX_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_HANG_POLL_MAX_CNT]

//>> GET_[QME_PBCR_HANG_POLL_MAX_CNT]
static inline fapi2::buffer<uint64_t>& GET_QME_PBCR_HANG_POLL_MAX_CNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_PBCR_HANG_POLL_MAX_CNT,
           QME_PBCR_HANG_POLL_MAX_CNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PBCR_HANG_POLL_MAX_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_HANG_POLL_MAX_CNT]

//>> SET_[QME_PBCR_HANG_DATA_MAX_CNT]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_HANG_DATA_MAX_CNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_HANG_DATA_MAX_CNT,
           QME_PBCR_HANG_DATA_MAX_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PBCR_HANG_DATA_MAX_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_HANG_DATA_MAX_CNT]

//>> SET_[QME_PBCR_HANG_DATA_MAX_CNT]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_HANG_DATA_MAX_CNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_HANG_DATA_MAX_CNT,
           QME_PBCR_HANG_DATA_MAX_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PBCR_HANG_DATA_MAX_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_HANG_DATA_MAX_CNT]

//>> GET_[QME_PBCR_HANG_DATA_MAX_CNT]
static inline fapi2::buffer<uint64_t>& GET_QME_PBCR_HANG_DATA_MAX_CNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_PBCR_HANG_DATA_MAX_CNT,
           QME_PBCR_HANG_DATA_MAX_CNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PBCR_HANG_DATA_MAX_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_HANG_DATA_MAX_CNT]

//>> SET_[QME_PBCR_DISABLE_PB_CACHE]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_DISABLE_PB_CACHE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_DISABLE_PB_CACHE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PBCR_DISABLE_PB_CACHE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_DISABLE_PB_CACHE]

//>> SET_[QME_PBCR_DISABLE_PB_CACHE]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_DISABLE_PB_CACHE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_DISABLE_PB_CACHE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PBCR_DISABLE_PB_CACHE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_DISABLE_PB_CACHE]

//>> SET_[QME_PBCR_DISABLE_PB_CACHE]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_DISABLE_PB_CACHE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.setBit<QME_PBCR_DISABLE_PB_CACHE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PBCR_DISABLE_PB_CACHE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_DISABLE_PB_CACHE]

//>> CLEAR_[QME_PBCR_DISABLE_PB_CACHE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PBCR_DISABLE_PB_CACHE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_PBCR_DISABLE_PB_CACHE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PBCR_DISABLE_PB_CACHE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PBCR_DISABLE_PB_CACHE]

//>> GET_[QME_PBCR_DISABLE_PB_CACHE]
static inline fapi2::buffer<uint64_t>& GET_QME_PBCR_DISABLE_PB_CACHE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_PBCR_DISABLE_PB_CACHE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PBCR_DISABLE_PB_CACHE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_DISABLE_PB_CACHE]

//>> GET_[QME_PBCR_DISABLE_PB_CACHE]
static inline bool GET_QME_PBCR_DISABLE_PB_CACHE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.getBit<QME_PBCR_DISABLE_PB_CACHE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PBCR_DISABLE_PB_CACHE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_DISABLE_PB_CACHE]

//>> SET_[QME_PBCR_INVALIDATE_PB_CACHE]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_INVALIDATE_PB_CACHE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_INVALIDATE_PB_CACHE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PBCR_INVALIDATE_PB_CACHE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_INVALIDATE_PB_CACHE]

//>> SET_[QME_PBCR_INVALIDATE_PB_CACHE]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_INVALIDATE_PB_CACHE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_PBCR_INVALIDATE_PB_CACHE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PBCR_INVALIDATE_PB_CACHE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_INVALIDATE_PB_CACHE]

//>> SET_[QME_PBCR_INVALIDATE_PB_CACHE]
static inline fapi2::buffer<uint64_t>& SET_QME_PBCR_INVALIDATE_PB_CACHE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.setBit<QME_PBCR_INVALIDATE_PB_CACHE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PBCR_INVALIDATE_PB_CACHE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PBCR_INVALIDATE_PB_CACHE]

//>> CLEAR_[QME_PBCR_INVALIDATE_PB_CACHE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PBCR_INVALIDATE_PB_CACHE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_PBCR_INVALIDATE_PB_CACHE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PBCR_INVALIDATE_PB_CACHE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PBCR_INVALIDATE_PB_CACHE]

//>> GET_[QME_PBCR_INVALIDATE_PB_CACHE]
static inline fapi2::buffer<uint64_t>& GET_QME_PBCR_INVALIDATE_PB_CACHE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_PBCR_INVALIDATE_PB_CACHE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PBCR_INVALIDATE_PB_CACHE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_INVALIDATE_PB_CACHE]

//>> GET_[QME_PBCR_INVALIDATE_PB_CACHE]
static inline bool GET_QME_PBCR_INVALIDATE_PB_CACHE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PBCR, QME_PBCR_SCOM2, QME_PBCR_WO_CLEAR));
#endif
    return i_data.getBit<QME_PBCR_INVALIDATE_PB_CACHE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PBCR_INVALIDATE_PB_CACHE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PBCR_INVALIDATE_PB_CACHE]

//>> PREP_[QME_QSAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_QSAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_QSAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_QSAR]

//>> GET_[QME_QSAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_QSAR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_QSAR;
#endif
    return fapi2::getScom(i_target, QME_QSAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_QSAR]

//>> PUT_[QME_QSAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_QSAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_QSAR));
#endif
    return fapi2::putScom(i_target, QME_QSAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_QSAR]


//>> SET_[QME_QSAR_SRAM_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_QME_QSAR_SRAM_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QSAR));
#endif
    return o_data.insertFromRight<QME_QSAR_SRAM_ADDRESS,
           QME_QSAR_SRAM_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_QSAR_SRAM_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSAR_SRAM_ADDRESS]

//>> SET_[QME_QSAR_SRAM_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_QME_QSAR_SRAM_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QSAR));
#endif
    return o_data.insertFromRight<QME_QSAR_SRAM_ADDRESS,
           QME_QSAR_SRAM_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_QSAR_SRAM_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSAR_SRAM_ADDRESS]

//>> GET_[QME_QSAR_SRAM_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_QME_QSAR_SRAM_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QSAR));
#endif
    return i_data.extractToRight<QME_QSAR_SRAM_ADDRESS,
           QME_QSAR_SRAM_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_QSAR_SRAM_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QSAR_SRAM_ADDRESS]

//>> SET_[QME_QSAR_AUTO_INCR_MODE]
static inline fapi2::buffer<uint64_t>& SET_QME_QSAR_AUTO_INCR_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QSAR));
#endif
    return o_data.insertFromRight<QME_QSAR_AUTO_INCR_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_QSAR_AUTO_INCR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSAR_AUTO_INCR_MODE]

//>> SET_[QME_QSAR_AUTO_INCR_MODE]
static inline fapi2::buffer<uint64_t>& SET_QME_QSAR_AUTO_INCR_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QSAR));
#endif
    return o_data.insertFromRight<QME_QSAR_AUTO_INCR_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_QSAR_AUTO_INCR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSAR_AUTO_INCR_MODE]

//>> SET_[QME_QSAR_AUTO_INCR_MODE]
static inline fapi2::buffer<uint64_t>& SET_QME_QSAR_AUTO_INCR_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QSAR));
#endif
    return o_data.setBit<QME_QSAR_AUTO_INCR_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_QSAR_AUTO_INCR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSAR_AUTO_INCR_MODE]

//>> CLEAR_[QME_QSAR_AUTO_INCR_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_QSAR_AUTO_INCR_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QSAR));
#endif
    return o_data.clearBit<QME_QSAR_AUTO_INCR_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_QSAR_AUTO_INCR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_QSAR_AUTO_INCR_MODE]

//>> GET_[QME_QSAR_AUTO_INCR_MODE]
static inline fapi2::buffer<uint64_t>& GET_QME_QSAR_AUTO_INCR_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QSAR));
#endif
    return i_data.extractToRight<QME_QSAR_AUTO_INCR_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_QSAR_AUTO_INCR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QSAR_AUTO_INCR_MODE]

//>> GET_[QME_QSAR_AUTO_INCR_MODE]
static inline bool GET_QME_QSAR_AUTO_INCR_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QSAR));
#endif
    return i_data.getBit<QME_QSAR_AUTO_INCR_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_QSAR_AUTO_INCR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QSAR_AUTO_INCR_MODE]

//>> PREP_[QME_SCOM_XIVDR6]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCOM_XIVDR6(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCOM_XIVDR6;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SCOM_XIVDR6]

//>> GET_[QME_SCOM_XIVDR6]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCOM_XIVDR6(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCOM_XIVDR6;
#endif
    return fapi2::getScom(i_target, QME_SCOM_XIVDR6, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SCOM_XIVDR6]

//>> PUT_[QME_SCOM_XIVDR6]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCOM_XIVDR6(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR6));
#endif
    return fapi2::putScom(i_target, QME_SCOM_XIVDR6, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SCOM_XIVDR6]


//>> SET_[QME_SCOM_XIVDR6_6]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIVDR6_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR6));
#endif
    return o_data.insertFromRight<QME_SCOM_XIVDR6_6,
           QME_SCOM_XIVDR6_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIVDR6_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIVDR6_6]

//>> SET_[QME_SCOM_XIVDR6_6]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIVDR6_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR6));
#endif
    return o_data.insertFromRight<QME_SCOM_XIVDR6_6,
           QME_SCOM_XIVDR6_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIVDR6_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIVDR6_6]

//>> GET_[QME_SCOM_XIVDR6_6]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIVDR6_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR6));
#endif
    return i_data.extractToRight<QME_SCOM_XIVDR6_6,
           QME_SCOM_XIVDR6_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIVDR6_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIVDR6_6]

//>> SET_[QME_SCOM_XIVDR6_7]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIVDR6_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR6));
#endif
    return o_data.insertFromRight<QME_SCOM_XIVDR6_7,
           QME_SCOM_XIVDR6_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIVDR6_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIVDR6_7]

//>> SET_[QME_SCOM_XIVDR6_7]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIVDR6_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR6));
#endif
    return o_data.insertFromRight<QME_SCOM_XIVDR6_7,
           QME_SCOM_XIVDR6_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIVDR6_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIVDR6_7]

//>> GET_[QME_SCOM_XIVDR6_7]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIVDR6_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR6));
#endif
    return i_data.extractToRight<QME_SCOM_XIVDR6_7,
           QME_SCOM_XIVDR6_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIVDR6_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIVDR6_7]

//>> PREP_[TIMEOUT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TIMEOUT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TIMEOUT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TIMEOUT_REG]

//>> GET_[TIMEOUT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TIMEOUT_REG(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TIMEOUT_REG;
#endif
    return fapi2::getScom(i_target, TIMEOUT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TIMEOUT_REG]

//>> PUT_[TIMEOUT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TIMEOUT_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TIMEOUT_REG));
#endif
    return fapi2::putScom(i_target, TIMEOUT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TIMEOUT_REG]


//>> SET_[TIMEOUT_REG_INT_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TIMEOUT_REG_INT_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TIMEOUT_REG));
#endif
    return o_data.insertFromRight<TIMEOUT_REG_INT_TIMEOUT,
           TIMEOUT_REG_INT_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access TIMEOUT_REG_INT_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TIMEOUT_REG_INT_TIMEOUT]

//>> SET_[TIMEOUT_REG_INT_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TIMEOUT_REG_INT_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TIMEOUT_REG));
#endif
    return o_data.insertFromRight<TIMEOUT_REG_INT_TIMEOUT,
           TIMEOUT_REG_INT_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access TIMEOUT_REG_INT_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TIMEOUT_REG_INT_TIMEOUT]

//>> GET_[TIMEOUT_REG_INT_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_TIMEOUT_REG_INT_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TIMEOUT_REG));
#endif
    return i_data.extractToRight<TIMEOUT_REG_INT_TIMEOUT,
           TIMEOUT_REG_INT_TIMEOUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access TIMEOUT_REG_INT_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TIMEOUT_REG_INT_TIMEOUT]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
