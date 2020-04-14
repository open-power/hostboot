/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pau/reg00000.H $          */
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

#ifndef __PAU_REG00000_H_
#define __PAU_REG00000_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


//>> PREP_[MISC_REGS_OPTICAL_IO_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MISC_REGS_OPTICAL_IO_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MISC_REGS_OPTICAL_IO_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MISC_REGS_OPTICAL_IO_CONFIG]

//>> GET_[MISC_REGS_OPTICAL_IO_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MISC_REGS_OPTICAL_IO_CONFIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MISC_REGS_OPTICAL_IO_CONFIG;
#endif
    return fapi2::getScom(i_target, MISC_REGS_OPTICAL_IO_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MISC_REGS_OPTICAL_IO_CONFIG]

//>> PUT_[MISC_REGS_OPTICAL_IO_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MISC_REGS_OPTICAL_IO_CONFIG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MISC_REGS_OPTICAL_IO_CONFIG));
#endif
    return fapi2::putScom(i_target, MISC_REGS_OPTICAL_IO_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MISC_REGS_OPTICAL_IO_CONFIG]


//>> SET_[MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_OPTICAL_IO_CONFIG));
#endif
    return o_data.insertFromRight<MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH]

//>> SET_[MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_OPTICAL_IO_CONFIG));
#endif
    return o_data.insertFromRight<MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH]

//>> SET_[MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_OPTICAL_IO_CONFIG));
#endif
    return o_data.setBit<MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH]

//>> CLEAR_[MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH]
static inline fapi2::buffer<uint64_t>& CLEAR_MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_OPTICAL_IO_CONFIG));
#endif
    return o_data.clearBit<MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH]

//>> GET_[MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH]
static inline fapi2::buffer<uint64_t>& GET_MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_OPTICAL_IO_CONFIG));
#endif
    return i_data.extractToRight<MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH]

//>> GET_[MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH]
static inline bool GET_MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_OPTICAL_IO_CONFIG));
#endif
    return i_data.getBit<MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH]

//>> SET_[MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_OPTICAL_IO_CONFIG));
#endif
    return o_data.insertFromRight<MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH]

//>> SET_[MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_OPTICAL_IO_CONFIG));
#endif
    return o_data.insertFromRight<MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH]

//>> SET_[MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_OPTICAL_IO_CONFIG));
#endif
    return o_data.setBit<MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH]

//>> CLEAR_[MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH]
static inline fapi2::buffer<uint64_t>& CLEAR_MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_OPTICAL_IO_CONFIG));
#endif
    return o_data.clearBit<MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH]

//>> GET_[MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH]
static inline fapi2::buffer<uint64_t>& GET_MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_OPTICAL_IO_CONFIG));
#endif
    return i_data.extractToRight<MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH]

//>> GET_[MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH]
static inline bool GET_MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_OPTICAL_IO_CONFIG));
#endif
    return i_data.getBit<MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH]

//>> SET_[MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_OPTICAL_IO_CONFIG));
#endif
    return o_data.insertFromRight<MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH]

//>> SET_[MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_OPTICAL_IO_CONFIG));
#endif
    return o_data.insertFromRight<MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH]

//>> SET_[MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_OPTICAL_IO_CONFIG));
#endif
    return o_data.setBit<MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH]

//>> CLEAR_[MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH]
static inline fapi2::buffer<uint64_t>& CLEAR_MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_OPTICAL_IO_CONFIG));
#endif
    return o_data.clearBit<MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH]

//>> GET_[MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH]
static inline fapi2::buffer<uint64_t>& GET_MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_OPTICAL_IO_CONFIG));
#endif
    return i_data.extractToRight<MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH]

//>> GET_[MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH]
static inline bool GET_MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_OPTICAL_IO_CONFIG));
#endif
    return i_data.getBit<MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH]

//>> SET_[MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_OPTICAL_IO_CONFIG));
#endif
    return o_data.insertFromRight<MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH]

//>> SET_[MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_OPTICAL_IO_CONFIG));
#endif
    return o_data.insertFromRight<MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH]

//>> SET_[MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_OPTICAL_IO_CONFIG));
#endif
    return o_data.setBit<MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH]

//>> CLEAR_[MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH]
static inline fapi2::buffer<uint64_t>& CLEAR_MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_OPTICAL_IO_CONFIG));
#endif
    return o_data.clearBit<MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH]

//>> GET_[MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH]
static inline fapi2::buffer<uint64_t>& GET_MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_OPTICAL_IO_CONFIG));
#endif
    return i_data.extractToRight<MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH]

//>> GET_[MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH]
static inline bool GET_MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_OPTICAL_IO_CONFIG));
#endif
    return i_data.getBit<MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
