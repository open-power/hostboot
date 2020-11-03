/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mc/reg00015.H $           */
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

#ifndef __MC_REG00015_H_
#define __MC_REG00015_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace mc
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
    FAPI_ERR("0:scom_mc Invalid dial access BIST_TC_BIST_START_TEST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access BIST_TC_BIST_START_TEST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access BIST_TC_BIST_START_TEST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access BIST_TC_BIST_START_TEST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access BIST_TC_BIST_START_TEST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access BIST_TC_BIST_START_TEST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access BIST_TC_SRAM_ABIST_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access BIST_TC_SRAM_ABIST_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access BIST_TC_SRAM_ABIST_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access BIST_TC_SRAM_ABIST_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access BIST_TC_SRAM_ABIST_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access BIST_TC_SRAM_ABIST_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access BIST_TC_IOBIST_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access BIST_TC_IOBIST_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access BIST_TC_IOBIST_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access BIST_TC_IOBIST_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access BIST_TC_IOBIST_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access BIST_TC_IOBIST_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access BIST_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access BIST_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access BIST_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access BIST_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access BIST_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access BIST_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access BIST_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access BIST_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access BIST_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access BIST_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access BIST_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access BIST_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access BIST_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access BIST_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access BIST_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access BIST_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access BIST_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access BIST_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access BIST_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access BIST_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access BIST_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access BIST_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access BIST_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access BIST_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access BIST_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access BIST_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access BIST_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access BIST_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access BIST_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access BIST_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access BIST_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access BIST_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access BIST_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access BIST_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access BIST_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access BIST_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access BIST_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access BIST_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access BIST_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access BIST_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access BIST_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access BIST_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access BIST_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access BIST_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access BIST_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access BIST_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access BIST_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access BIST_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access BIST_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access BIST_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access BIST_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access BIST_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access BIST_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access BIST_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access BIST_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access BIST_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access BIST_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access BIST_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access BIST_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access BIST_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access BIST_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access BIST_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access BIST_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access BIST_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access BIST_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access BIST_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access BIST_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access BIST_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access BIST_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access BIST_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access BIST_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access BIST_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access BIST_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access BIST_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access BIST_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access BIST_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access BIST_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access BIST_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access BIST_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access BIST_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access BIST_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access BIST_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access BIST_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access BIST_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access BIST_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access BIST_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access BIST_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access BIST_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access BIST_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access BIST_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access BIST_STROBE_WINDOW_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access BIST_STROBE_WINDOW_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access BIST_STROBE_WINDOW_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access BIST_STROBE_WINDOW_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access BIST_STROBE_WINDOW_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access BIST_STROBE_WINDOW_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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


//>> SET_[CPLT_CTRL5_0]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL5_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_0]

//>> SET_[CPLT_CTRL5_0]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL5_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_0]

//>> SET_[CPLT_CTRL5_0]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL5_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_0]

//>> CLEAR_[CPLT_CTRL5_0]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL5_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_0]

//>> GET_[CPLT_CTRL5_0]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL5_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_0]

//>> GET_[CPLT_CTRL5_0]
static inline bool GET_CPLT_CTRL5_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL5_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_0]

//>> SET_[CPLT_CTRL5_1]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL5_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_1]

//>> SET_[CPLT_CTRL5_1]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL5_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_1]

//>> SET_[CPLT_CTRL5_1]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL5_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_1]

//>> CLEAR_[CPLT_CTRL5_1]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL5_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_1]

//>> GET_[CPLT_CTRL5_1]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL5_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_1]

//>> GET_[CPLT_CTRL5_1]
static inline bool GET_CPLT_CTRL5_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL5_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_1]

//>> SET_[CPLT_CTRL5_2]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL5_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_2]

//>> SET_[CPLT_CTRL5_2]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL5_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_2]

//>> SET_[CPLT_CTRL5_2]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL5_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_2]

//>> CLEAR_[CPLT_CTRL5_2]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL5_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_2]

//>> GET_[CPLT_CTRL5_2]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL5_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_2]

//>> GET_[CPLT_CTRL5_2]
static inline bool GET_CPLT_CTRL5_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL5_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_2]

//>> SET_[CPLT_CTRL5_3]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL5_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_3]

//>> SET_[CPLT_CTRL5_3]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL5_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_3]

//>> SET_[CPLT_CTRL5_3]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL5_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_3]

//>> CLEAR_[CPLT_CTRL5_3]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL5_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_3]

//>> GET_[CPLT_CTRL5_3]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL5_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_3]

//>> GET_[CPLT_CTRL5_3]
static inline bool GET_CPLT_CTRL5_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL5_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_3]

//>> SET_[CPLT_CTRL5_4]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL5_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_4]

//>> SET_[CPLT_CTRL5_4]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL5_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_4]

//>> SET_[CPLT_CTRL5_4]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL5_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_4]

//>> CLEAR_[CPLT_CTRL5_4]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL5_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_4]

//>> GET_[CPLT_CTRL5_4]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL5_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_4]

//>> GET_[CPLT_CTRL5_4]
static inline bool GET_CPLT_CTRL5_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL5_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_4]

//>> SET_[CPLT_CTRL5_5]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL5_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_5]

//>> SET_[CPLT_CTRL5_5]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL5_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_5]

//>> SET_[CPLT_CTRL5_5]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL5_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_5]

//>> CLEAR_[CPLT_CTRL5_5]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL5_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_5]

//>> GET_[CPLT_CTRL5_5]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL5_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_5]

//>> GET_[CPLT_CTRL5_5]
static inline bool GET_CPLT_CTRL5_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL5_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_5]

//>> SET_[CPLT_CTRL5_6]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL5_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_6]

//>> SET_[CPLT_CTRL5_6]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL5_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_6]

//>> SET_[CPLT_CTRL5_6]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL5_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_6]

//>> CLEAR_[CPLT_CTRL5_6]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL5_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_6]

//>> GET_[CPLT_CTRL5_6]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL5_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_6]

//>> GET_[CPLT_CTRL5_6]
static inline bool GET_CPLT_CTRL5_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL5_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_6]

//>> SET_[CPLT_CTRL5_7]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL5_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_7]

//>> SET_[CPLT_CTRL5_7]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL5_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_7]

//>> SET_[CPLT_CTRL5_7]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL5_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_7]

//>> CLEAR_[CPLT_CTRL5_7]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL5_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_7]

//>> GET_[CPLT_CTRL5_7]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL5_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_7]

//>> GET_[CPLT_CTRL5_7]
static inline bool GET_CPLT_CTRL5_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL5_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_7]

//>> SET_[CPLT_CTRL5_8]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL5_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_8]

//>> SET_[CPLT_CTRL5_8]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL5_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_8]

//>> SET_[CPLT_CTRL5_8]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL5_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_8]

//>> CLEAR_[CPLT_CTRL5_8]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL5_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_8]

//>> GET_[CPLT_CTRL5_8]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL5_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_8]

//>> GET_[CPLT_CTRL5_8]
static inline bool GET_CPLT_CTRL5_8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL5_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_8]

//>> SET_[CPLT_CTRL5_9]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL5_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_9]

//>> SET_[CPLT_CTRL5_9]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL5_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_9]

//>> SET_[CPLT_CTRL5_9]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL5_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_9]

//>> CLEAR_[CPLT_CTRL5_9]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL5_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_9]

//>> GET_[CPLT_CTRL5_9]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL5_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_9]

//>> GET_[CPLT_CTRL5_9]
static inline bool GET_CPLT_CTRL5_9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL5_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_9]

//>> SET_[CPLT_CTRL5_10]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL5_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_10]

//>> SET_[CPLT_CTRL5_10]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL5_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_10]

//>> SET_[CPLT_CTRL5_10]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL5_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_10]

//>> CLEAR_[CPLT_CTRL5_10]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL5_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_10]

//>> GET_[CPLT_CTRL5_10]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL5_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_10]

//>> GET_[CPLT_CTRL5_10]
static inline bool GET_CPLT_CTRL5_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL5_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_10]

//>> SET_[CPLT_CTRL5_11]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL5_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_11]

//>> SET_[CPLT_CTRL5_11]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL5_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_11]

//>> SET_[CPLT_CTRL5_11]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL5_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_11]

//>> CLEAR_[CPLT_CTRL5_11]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL5_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_11]

//>> GET_[CPLT_CTRL5_11]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL5_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_11]

//>> GET_[CPLT_CTRL5_11]
static inline bool GET_CPLT_CTRL5_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL5_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_11]

//>> SET_[CPLT_CTRL5_12]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL5_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_12]

//>> SET_[CPLT_CTRL5_12]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL5_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_12]

//>> SET_[CPLT_CTRL5_12]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL5_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_12]

//>> CLEAR_[CPLT_CTRL5_12]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL5_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_12]

//>> GET_[CPLT_CTRL5_12]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL5_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_12]

//>> GET_[CPLT_CTRL5_12]
static inline bool GET_CPLT_CTRL5_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL5_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_12]

//>> SET_[CPLT_CTRL5_13]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL5_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_13]

//>> SET_[CPLT_CTRL5_13]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL5_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_13]

//>> SET_[CPLT_CTRL5_13]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL5_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_13]

//>> CLEAR_[CPLT_CTRL5_13]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL5_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_13]

//>> GET_[CPLT_CTRL5_13]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL5_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_13]

//>> GET_[CPLT_CTRL5_13]
static inline bool GET_CPLT_CTRL5_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL5_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_13]

//>> SET_[CPLT_CTRL5_14]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL5_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_14]

//>> SET_[CPLT_CTRL5_14]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL5_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_14]

//>> SET_[CPLT_CTRL5_14]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL5_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_14]

//>> CLEAR_[CPLT_CTRL5_14]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL5_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_14]

//>> GET_[CPLT_CTRL5_14]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL5_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_14]

//>> GET_[CPLT_CTRL5_14]
static inline bool GET_CPLT_CTRL5_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL5_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_14]

//>> SET_[CPLT_CTRL5_15]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL5_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_15]

//>> SET_[CPLT_CTRL5_15]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL5_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_15]

//>> SET_[CPLT_CTRL5_15]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL5_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_15]

//>> CLEAR_[CPLT_CTRL5_15]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL5_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_15]

//>> GET_[CPLT_CTRL5_15]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL5_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_15]

//>> GET_[CPLT_CTRL5_15]
static inline bool GET_CPLT_CTRL5_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL5_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_15]

//>> SET_[CPLT_CTRL5_16]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL5_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_16]

//>> SET_[CPLT_CTRL5_16]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL5_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_16]

//>> SET_[CPLT_CTRL5_16]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL5_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_16]

//>> CLEAR_[CPLT_CTRL5_16]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL5_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_16]

//>> GET_[CPLT_CTRL5_16]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL5_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_16]

//>> GET_[CPLT_CTRL5_16]
static inline bool GET_CPLT_CTRL5_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL5_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_16]

//>> SET_[CPLT_CTRL5_17]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL5_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_17]

//>> SET_[CPLT_CTRL5_17]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL5_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_17]

//>> SET_[CPLT_CTRL5_17]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL5_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_17]

//>> CLEAR_[CPLT_CTRL5_17]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL5_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_17]

//>> GET_[CPLT_CTRL5_17]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL5_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_17]

//>> GET_[CPLT_CTRL5_17]
static inline bool GET_CPLT_CTRL5_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL5_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_17]

//>> SET_[CPLT_CTRL5_18]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL5_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_18]

//>> SET_[CPLT_CTRL5_18]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL5_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_18]

//>> SET_[CPLT_CTRL5_18]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL5_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_18]

//>> CLEAR_[CPLT_CTRL5_18]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL5_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_18]

//>> GET_[CPLT_CTRL5_18]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL5_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_18]

//>> GET_[CPLT_CTRL5_18]
static inline bool GET_CPLT_CTRL5_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL5_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_18]

//>> SET_[CPLT_CTRL5_19]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL5_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_19]

//>> SET_[CPLT_CTRL5_19]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL5_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL5_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_19]

//>> SET_[CPLT_CTRL5_19]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL5_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL5_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL5_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL5_19]

//>> CLEAR_[CPLT_CTRL5_19]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL5_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL5_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL5_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL5_19]

//>> GET_[CPLT_CTRL5_19]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL5_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL5_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL5_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_19]

//>> GET_[CPLT_CTRL5_19]
static inline bool GET_CPLT_CTRL5_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL5_RW, CPLT_CTRL5_WO_CLEAR, CPLT_CTRL5_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL5_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL5_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL5_19]

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
    FAPI_ERR("0:scom_mc Invalid dial access EPS_THERM_WSUB_DTS_RESULT0_0_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access EPS_THERM_WSUB_DTS_RESULT0_0_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access EPS_THERM_WSUB_DTS_RESULT0_0_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access EPS_THERM_WSUB_DTS_RESULT0_1_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access EPS_THERM_WSUB_DTS_RESULT0_1_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access EPS_THERM_WSUB_DTS_RESULT0_1_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access EPS_THERM_WSUB_DTS_RESULT0_2_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access EPS_THERM_WSUB_DTS_RESULT0_2_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access EPS_THERM_WSUB_DTS_RESULT0_2_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_DTS_RESULT0_2_RESULT]

//>> PREP_[SCOMFIR_MCFGP1E]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCOMFIR_MCFGP1E(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCFGP1E;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SCOMFIR_MCFGP1E]

//>> GET_[SCOMFIR_MCFGP1E]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCOMFIR_MCFGP1E(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCFGP1E;
#endif
    return fapi2::getScom(i_target, SCOMFIR_MCFGP1E, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SCOMFIR_MCFGP1E]

//>> PUT_[SCOMFIR_MCFGP1E]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCOMFIR_MCFGP1E(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP1E));
#endif
    return fapi2::putScom(i_target, SCOMFIR_MCFGP1E, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SCOMFIR_MCFGP1E]


//>> SET_[SCOMFIR_MCFGP1E_VALID]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGP1E_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP1E));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGP1E_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFGP1E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGP1E_VALID]

//>> SET_[SCOMFIR_MCFGP1E_VALID]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGP1E_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP1E));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGP1E_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFGP1E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGP1E_VALID]

//>> SET_[SCOMFIR_MCFGP1E_VALID]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGP1E_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP1E));
#endif
    return o_data.setBit<SCOMFIR_MCFGP1E_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFGP1E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGP1E_VALID]

//>> CLEAR_[SCOMFIR_MCFGP1E_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFGP1E_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP1E));
#endif
    return o_data.clearBit<SCOMFIR_MCFGP1E_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFGP1E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFGP1E_VALID]

//>> GET_[SCOMFIR_MCFGP1E_VALID]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFGP1E_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP1E));
#endif
    return i_data.extractToRight<SCOMFIR_MCFGP1E_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFGP1E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFGP1E_VALID]

//>> GET_[SCOMFIR_MCFGP1E_VALID]
static inline bool GET_SCOMFIR_MCFGP1E_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP1E));
#endif
    return i_data.getBit<SCOMFIR_MCFGP1E_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFGP1E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFGP1E_VALID]

//>> SET_[SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP1E));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE]

//>> SET_[SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP1E));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE]

//>> SET_[SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP1E));
#endif
    return o_data.setBit<SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE]

//>> CLEAR_[SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP1E));
#endif
    return o_data.clearBit<SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE]

//>> GET_[SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP1E));
#endif
    return i_data.extractToRight<SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE]

//>> GET_[SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE]
static inline bool GET_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP1E));
#endif
    return i_data.getBit<SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE]

//>> SET_[SCOMFIR_MCFGP1E_LOWER_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGP1E_LOWER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP1E));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGP1E_LOWER_ADDRESS,
           SCOMFIR_MCFGP1E_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFGP1E_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGP1E_LOWER_ADDRESS]

//>> SET_[SCOMFIR_MCFGP1E_LOWER_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGP1E_LOWER_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP1E));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGP1E_LOWER_ADDRESS,
           SCOMFIR_MCFGP1E_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFGP1E_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGP1E_LOWER_ADDRESS]

//>> GET_[SCOMFIR_MCFGP1E_LOWER_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFGP1E_LOWER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP1E));
#endif
    return i_data.extractToRight<SCOMFIR_MCFGP1E_LOWER_ADDRESS,
           SCOMFIR_MCFGP1E_LOWER_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFGP1E_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFGP1E_LOWER_ADDRESS]

//>> SET_[SCOMFIR_MCFGP1E_UPPER_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGP1E_UPPER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP1E));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGP1E_UPPER_ADDRESS,
           SCOMFIR_MCFGP1E_UPPER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFGP1E_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGP1E_UPPER_ADDRESS]

//>> SET_[SCOMFIR_MCFGP1E_UPPER_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGP1E_UPPER_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP1E));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGP1E_UPPER_ADDRESS,
           SCOMFIR_MCFGP1E_UPPER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFGP1E_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGP1E_UPPER_ADDRESS]

//>> GET_[SCOMFIR_MCFGP1E_UPPER_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFGP1E_UPPER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP1E));
#endif
    return i_data.extractToRight<SCOMFIR_MCFGP1E_UPPER_ADDRESS,
           SCOMFIR_MCFGP1E_UPPER_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFGP1E_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFGP1E_UPPER_ADDRESS]

//>> PREP_[SCOMFIR_MCFGPM0A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCOMFIR_MCFGPM0A(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCFGPM0A;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SCOMFIR_MCFGPM0A]

//>> GET_[SCOMFIR_MCFGPM0A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCOMFIR_MCFGPM0A(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCFGPM0A;
#endif
    return fapi2::getScom(i_target, SCOMFIR_MCFGPM0A, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SCOMFIR_MCFGPM0A]

//>> PUT_[SCOMFIR_MCFGPM0A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCOMFIR_MCFGPM0A(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return fapi2::putScom(i_target, SCOMFIR_MCFGPM0A, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SCOMFIR_MCFGPM0A]


//>> SET_[SCOMFIR_MCFGPM0A_HOLE_VALID]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGPM0A_HOLE_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGPM0A_HOLE_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGPM0A_HOLE_VALID]

//>> SET_[SCOMFIR_MCFGPM0A_HOLE_VALID]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGPM0A_HOLE_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGPM0A_HOLE_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGPM0A_HOLE_VALID]

//>> SET_[SCOMFIR_MCFGPM0A_HOLE_VALID]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGPM0A_HOLE_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return o_data.setBit<SCOMFIR_MCFGPM0A_HOLE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGPM0A_HOLE_VALID]

//>> CLEAR_[SCOMFIR_MCFGPM0A_HOLE_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFGPM0A_HOLE_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return o_data.clearBit<SCOMFIR_MCFGPM0A_HOLE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFGPM0A_HOLE_VALID]

//>> GET_[SCOMFIR_MCFGPM0A_HOLE_VALID]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFGPM0A_HOLE_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return i_data.extractToRight<SCOMFIR_MCFGPM0A_HOLE_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFGPM0A_HOLE_VALID]

//>> GET_[SCOMFIR_MCFGPM0A_HOLE_VALID]
static inline bool GET_SCOMFIR_MCFGPM0A_HOLE_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return i_data.getBit<SCOMFIR_MCFGPM0A_HOLE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFGPM0A_HOLE_VALID]

//>> SET_[SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS,
           SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS]

//>> SET_[SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS,
           SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS]

//>> GET_[SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return i_data.extractToRight<SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS,
           SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS]

//>> SET_[SCOMFIR_MCFGPM0A_RESERVED_16_21]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGPM0A_RESERVED_16_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGPM0A_RESERVED_16_21,
           SCOMFIR_MCFGPM0A_RESERVED_16_21_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_RESERVED_16_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGPM0A_RESERVED_16_21]

//>> SET_[SCOMFIR_MCFGPM0A_RESERVED_16_21]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGPM0A_RESERVED_16_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGPM0A_RESERVED_16_21,
           SCOMFIR_MCFGPM0A_RESERVED_16_21_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_RESERVED_16_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGPM0A_RESERVED_16_21]

//>> GET_[SCOMFIR_MCFGPM0A_RESERVED_16_21]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFGPM0A_RESERVED_16_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return i_data.extractToRight<SCOMFIR_MCFGPM0A_RESERVED_16_21,
           SCOMFIR_MCFGPM0A_RESERVED_16_21_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_RESERVED_16_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFGPM0A_RESERVED_16_21]

//>> SET_[SCOMFIR_MCFGPM0A_SMF_VALID]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGPM0A_SMF_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGPM0A_SMF_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGPM0A_SMF_VALID]

//>> SET_[SCOMFIR_MCFGPM0A_SMF_VALID]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGPM0A_SMF_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGPM0A_SMF_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGPM0A_SMF_VALID]

//>> SET_[SCOMFIR_MCFGPM0A_SMF_VALID]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGPM0A_SMF_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return o_data.setBit<SCOMFIR_MCFGPM0A_SMF_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGPM0A_SMF_VALID]

//>> CLEAR_[SCOMFIR_MCFGPM0A_SMF_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFGPM0A_SMF_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return o_data.clearBit<SCOMFIR_MCFGPM0A_SMF_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFGPM0A_SMF_VALID]

//>> GET_[SCOMFIR_MCFGPM0A_SMF_VALID]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFGPM0A_SMF_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return i_data.extractToRight<SCOMFIR_MCFGPM0A_SMF_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFGPM0A_SMF_VALID]

//>> GET_[SCOMFIR_MCFGPM0A_SMF_VALID]
static inline bool GET_SCOMFIR_MCFGPM0A_SMF_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return i_data.getBit<SCOMFIR_MCFGPM0A_SMF_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFGPM0A_SMF_VALID]

//>> SET_[SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE]

//>> SET_[SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE]

//>> SET_[SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return o_data.setBit<SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE]

//>> CLEAR_[SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return o_data.clearBit<SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE]

//>> GET_[SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return i_data.extractToRight<SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE]

//>> GET_[SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE]
static inline bool GET_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return i_data.getBit<SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE]

//>> SET_[SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS,
           SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS]

//>> SET_[SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS,
           SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS]

//>> GET_[SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return i_data.extractToRight<SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS,
           SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS]

//>> SET_[SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS,
           SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS]

//>> SET_[SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS,
           SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS]

//>> GET_[SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGPM0A));
#endif
    return i_data.extractToRight<SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS,
           SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS]

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
    FAPI_ERR("0:scom_mc Invalid dial access TIMEOUT_REG_INT_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access TIMEOUT_REG_INT_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access TIMEOUT_REG_INT_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
