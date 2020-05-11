/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pau/reg00008.H $          */
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

#ifndef __PAU_REG00008_H_
#define __PAU_REG00008_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


//>> PREP_[CS_CTL_MISC_STATUS2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CS_CTL_MISC_STATUS2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_CTL_MISC_STATUS2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CS_CTL_MISC_STATUS2]

//>> GET_[CS_CTL_MISC_STATUS2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CS_CTL_MISC_STATUS2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_CTL_MISC_STATUS2;
#endif
    return fapi2::getScom(i_target, CS_CTL_MISC_STATUS2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2]

//>> PUT_[CS_CTL_MISC_STATUS2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CS_CTL_MISC_STATUS2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return fapi2::putScom(i_target, CS_CTL_MISC_STATUS2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CS_CTL_MISC_STATUS2]


//>> SET_[CS_CTL_MISC_STATUS2_FENCE1]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_FENCE1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_FENCE1,
           CS_CTL_MISC_STATUS2_FENCE1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_FENCE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_FENCE1]

//>> SET_[CS_CTL_MISC_STATUS2_FENCE1]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_FENCE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_FENCE1,
           CS_CTL_MISC_STATUS2_FENCE1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_FENCE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_FENCE1]

//>> GET_[CS_CTL_MISC_STATUS2_FENCE1]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_FENCE1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_FENCE1,
           CS_CTL_MISC_STATUS2_FENCE1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_FENCE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_FENCE1]

//>> SET_[CS_CTL_MISC_STATUS2_BRK1_RLX]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK1_RLX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK1_RLX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK1_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK1_RLX]

//>> SET_[CS_CTL_MISC_STATUS2_BRK1_RLX]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK1_RLX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK1_RLX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK1_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK1_RLX]

//>> SET_[CS_CTL_MISC_STATUS2_BRK1_RLX]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK1_RLX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS2_BRK1_RLX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK1_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK1_RLX]

//>> CLEAR_[CS_CTL_MISC_STATUS2_BRK1_RLX]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS2_BRK1_RLX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS2_BRK1_RLX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK1_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS2_BRK1_RLX]

//>> GET_[CS_CTL_MISC_STATUS2_BRK1_RLX]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_BRK1_RLX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_BRK1_RLX,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK1_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK1_RLX]

//>> GET_[CS_CTL_MISC_STATUS2_BRK1_RLX]
static inline bool GET_CS_CTL_MISC_STATUS2_BRK1_RLX(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS2_BRK1_RLX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK1_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK1_RLX]

//>> SET_[CS_CTL_MISC_STATUS2_NVREQ1]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVREQ1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_NVREQ1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVREQ1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVREQ1]

//>> SET_[CS_CTL_MISC_STATUS2_NVREQ1]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVREQ1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_NVREQ1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVREQ1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVREQ1]

//>> SET_[CS_CTL_MISC_STATUS2_NVREQ1]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVREQ1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS2_NVREQ1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVREQ1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVREQ1]

//>> CLEAR_[CS_CTL_MISC_STATUS2_NVREQ1]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS2_NVREQ1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS2_NVREQ1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVREQ1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS2_NVREQ1]

//>> GET_[CS_CTL_MISC_STATUS2_NVREQ1]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_NVREQ1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_NVREQ1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVREQ1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_NVREQ1]

//>> GET_[CS_CTL_MISC_STATUS2_NVREQ1]
static inline bool GET_CS_CTL_MISC_STATUS2_NVREQ1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS2_NVREQ1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVREQ1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_NVREQ1]

//>> SET_[CS_CTL_MISC_STATUS2_NVDGD1]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVDGD1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_NVDGD1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVDGD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVDGD1]

//>> SET_[CS_CTL_MISC_STATUS2_NVDGD1]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVDGD1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_NVDGD1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVDGD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVDGD1]

//>> SET_[CS_CTL_MISC_STATUS2_NVDGD1]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVDGD1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS2_NVDGD1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVDGD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVDGD1]

//>> CLEAR_[CS_CTL_MISC_STATUS2_NVDGD1]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS2_NVDGD1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS2_NVDGD1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVDGD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS2_NVDGD1]

//>> GET_[CS_CTL_MISC_STATUS2_NVDGD1]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_NVDGD1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_NVDGD1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVDGD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_NVDGD1]

//>> GET_[CS_CTL_MISC_STATUS2_NVDGD1]
static inline bool GET_CS_CTL_MISC_STATUS2_NVDGD1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS2_NVDGD1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVDGD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_NVDGD1]

//>> SET_[CS_CTL_MISC_STATUS2_NVRS1]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVRS1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_NVRS1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVRS1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVRS1]

//>> SET_[CS_CTL_MISC_STATUS2_NVRS1]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVRS1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_NVRS1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVRS1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVRS1]

//>> SET_[CS_CTL_MISC_STATUS2_NVRS1]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVRS1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS2_NVRS1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVRS1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVRS1]

//>> CLEAR_[CS_CTL_MISC_STATUS2_NVRS1]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS2_NVRS1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS2_NVRS1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVRS1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS2_NVRS1]

//>> GET_[CS_CTL_MISC_STATUS2_NVRS1]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_NVRS1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_NVRS1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVRS1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_NVRS1]

//>> GET_[CS_CTL_MISC_STATUS2_NVRS1]
static inline bool GET_CS_CTL_MISC_STATUS2_NVRS1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS2_NVRS1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVRS1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_NVRS1]

//>> SET_[CS_CTL_MISC_STATUS2_BRK1_AM_FENCED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK1_AM_FENCED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK1_AM_FENCED,
           CS_CTL_MISC_STATUS2_BRK1_AM_FENCED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK1_AM_FENCED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK1_AM_FENCED]

//>> SET_[CS_CTL_MISC_STATUS2_BRK1_AM_FENCED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK1_AM_FENCED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK1_AM_FENCED,
           CS_CTL_MISC_STATUS2_BRK1_AM_FENCED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK1_AM_FENCED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK1_AM_FENCED]

//>> GET_[CS_CTL_MISC_STATUS2_BRK1_AM_FENCED]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_BRK1_AM_FENCED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_BRK1_AM_FENCED,
           CS_CTL_MISC_STATUS2_BRK1_AM_FENCED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK1_AM_FENCED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK1_AM_FENCED]

//>> SET_[CS_CTL_MISC_STATUS2_BRK1_NTL_REQ_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK1_NTL_REQ_FENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK1_NTL_REQ_FENCE,
           CS_CTL_MISC_STATUS2_BRK1_NTL_REQ_FENCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK1_NTL_REQ_FENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK1_NTL_REQ_FENCE]

//>> SET_[CS_CTL_MISC_STATUS2_BRK1_NTL_REQ_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK1_NTL_REQ_FENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK1_NTL_REQ_FENCE,
           CS_CTL_MISC_STATUS2_BRK1_NTL_REQ_FENCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK1_NTL_REQ_FENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK1_NTL_REQ_FENCE]

//>> GET_[CS_CTL_MISC_STATUS2_BRK1_NTL_REQ_FENCE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_BRK1_NTL_REQ_FENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_BRK1_NTL_REQ_FENCE,
           CS_CTL_MISC_STATUS2_BRK1_NTL_REQ_FENCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK1_NTL_REQ_FENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK1_NTL_REQ_FENCE]

//>> SET_[CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE]

//>> SET_[CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE]

//>> SET_[CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE]

//>> CLEAR_[CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE]

//>> GET_[CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE]

//>> GET_[CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE]
static inline bool GET_CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE]

//>> SET_[CS_CTL_MISC_STATUS2_BRK1_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK1_RESERVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK1_RESERVED,
           CS_CTL_MISC_STATUS2_BRK1_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK1_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK1_RESERVED]

//>> SET_[CS_CTL_MISC_STATUS2_BRK1_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK1_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK1_RESERVED,
           CS_CTL_MISC_STATUS2_BRK1_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK1_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK1_RESERVED]

//>> GET_[CS_CTL_MISC_STATUS2_BRK1_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_BRK1_RESERVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_BRK1_RESERVED,
           CS_CTL_MISC_STATUS2_BRK1_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK1_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK1_RESERVED]

//>> SET_[CS_CTL_MISC_STATUS2_FENCE2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_FENCE2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_FENCE2,
           CS_CTL_MISC_STATUS2_FENCE2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_FENCE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_FENCE2]

//>> SET_[CS_CTL_MISC_STATUS2_FENCE2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_FENCE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_FENCE2,
           CS_CTL_MISC_STATUS2_FENCE2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_FENCE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_FENCE2]

//>> GET_[CS_CTL_MISC_STATUS2_FENCE2]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_FENCE2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_FENCE2,
           CS_CTL_MISC_STATUS2_FENCE2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_FENCE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_FENCE2]

//>> SET_[CS_CTL_MISC_STATUS2_BRK2_RLX]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK2_RLX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK2_RLX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK2_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK2_RLX]

//>> SET_[CS_CTL_MISC_STATUS2_BRK2_RLX]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK2_RLX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK2_RLX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK2_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK2_RLX]

//>> SET_[CS_CTL_MISC_STATUS2_BRK2_RLX]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK2_RLX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS2_BRK2_RLX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK2_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK2_RLX]

//>> CLEAR_[CS_CTL_MISC_STATUS2_BRK2_RLX]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS2_BRK2_RLX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS2_BRK2_RLX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK2_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS2_BRK2_RLX]

//>> GET_[CS_CTL_MISC_STATUS2_BRK2_RLX]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_BRK2_RLX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_BRK2_RLX,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK2_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK2_RLX]

//>> GET_[CS_CTL_MISC_STATUS2_BRK2_RLX]
static inline bool GET_CS_CTL_MISC_STATUS2_BRK2_RLX(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS2_BRK2_RLX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK2_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK2_RLX]

//>> SET_[CS_CTL_MISC_STATUS2_NVREQ2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVREQ2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_NVREQ2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVREQ2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVREQ2]

//>> SET_[CS_CTL_MISC_STATUS2_NVREQ2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVREQ2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_NVREQ2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVREQ2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVREQ2]

//>> SET_[CS_CTL_MISC_STATUS2_NVREQ2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVREQ2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS2_NVREQ2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVREQ2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVREQ2]

//>> CLEAR_[CS_CTL_MISC_STATUS2_NVREQ2]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS2_NVREQ2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS2_NVREQ2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVREQ2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS2_NVREQ2]

//>> GET_[CS_CTL_MISC_STATUS2_NVREQ2]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_NVREQ2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_NVREQ2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVREQ2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_NVREQ2]

//>> GET_[CS_CTL_MISC_STATUS2_NVREQ2]
static inline bool GET_CS_CTL_MISC_STATUS2_NVREQ2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS2_NVREQ2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVREQ2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_NVREQ2]

//>> SET_[CS_CTL_MISC_STATUS2_NVDGD2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVDGD2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_NVDGD2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVDGD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVDGD2]

//>> SET_[CS_CTL_MISC_STATUS2_NVDGD2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVDGD2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_NVDGD2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVDGD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVDGD2]

//>> SET_[CS_CTL_MISC_STATUS2_NVDGD2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVDGD2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS2_NVDGD2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVDGD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVDGD2]

//>> CLEAR_[CS_CTL_MISC_STATUS2_NVDGD2]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS2_NVDGD2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS2_NVDGD2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVDGD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS2_NVDGD2]

//>> GET_[CS_CTL_MISC_STATUS2_NVDGD2]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_NVDGD2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_NVDGD2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVDGD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_NVDGD2]

//>> GET_[CS_CTL_MISC_STATUS2_NVDGD2]
static inline bool GET_CS_CTL_MISC_STATUS2_NVDGD2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS2_NVDGD2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVDGD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_NVDGD2]

//>> SET_[CS_CTL_MISC_STATUS2_NVRS2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVRS2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_NVRS2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVRS2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVRS2]

//>> SET_[CS_CTL_MISC_STATUS2_NVRS2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVRS2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_NVRS2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVRS2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVRS2]

//>> SET_[CS_CTL_MISC_STATUS2_NVRS2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVRS2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS2_NVRS2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVRS2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVRS2]

//>> CLEAR_[CS_CTL_MISC_STATUS2_NVRS2]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS2_NVRS2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS2_NVRS2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVRS2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS2_NVRS2]

//>> GET_[CS_CTL_MISC_STATUS2_NVRS2]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_NVRS2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_NVRS2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVRS2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_NVRS2]

//>> GET_[CS_CTL_MISC_STATUS2_NVRS2]
static inline bool GET_CS_CTL_MISC_STATUS2_NVRS2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS2_NVRS2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVRS2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_NVRS2]

//>> SET_[CS_CTL_MISC_STATUS2_BRK2_AM_FENCED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK2_AM_FENCED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK2_AM_FENCED,
           CS_CTL_MISC_STATUS2_BRK2_AM_FENCED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK2_AM_FENCED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK2_AM_FENCED]

//>> SET_[CS_CTL_MISC_STATUS2_BRK2_AM_FENCED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK2_AM_FENCED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK2_AM_FENCED,
           CS_CTL_MISC_STATUS2_BRK2_AM_FENCED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK2_AM_FENCED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK2_AM_FENCED]

//>> GET_[CS_CTL_MISC_STATUS2_BRK2_AM_FENCED]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_BRK2_AM_FENCED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_BRK2_AM_FENCED,
           CS_CTL_MISC_STATUS2_BRK2_AM_FENCED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK2_AM_FENCED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK2_AM_FENCED]

//>> SET_[CS_CTL_MISC_STATUS2_BRK2_NTL_REQ_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK2_NTL_REQ_FENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK2_NTL_REQ_FENCE,
           CS_CTL_MISC_STATUS2_BRK2_NTL_REQ_FENCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK2_NTL_REQ_FENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK2_NTL_REQ_FENCE]

//>> SET_[CS_CTL_MISC_STATUS2_BRK2_NTL_REQ_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK2_NTL_REQ_FENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK2_NTL_REQ_FENCE,
           CS_CTL_MISC_STATUS2_BRK2_NTL_REQ_FENCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK2_NTL_REQ_FENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK2_NTL_REQ_FENCE]

//>> GET_[CS_CTL_MISC_STATUS2_BRK2_NTL_REQ_FENCE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_BRK2_NTL_REQ_FENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_BRK2_NTL_REQ_FENCE,
           CS_CTL_MISC_STATUS2_BRK2_NTL_REQ_FENCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK2_NTL_REQ_FENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK2_NTL_REQ_FENCE]

//>> SET_[CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE]

//>> SET_[CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE]

//>> SET_[CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE]

//>> CLEAR_[CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE]

//>> GET_[CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE]

//>> GET_[CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE]
static inline bool GET_CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE]

//>> SET_[CS_CTL_MISC_STATUS2_BRK2_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK2_RESERVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK2_RESERVED,
           CS_CTL_MISC_STATUS2_BRK2_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK2_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK2_RESERVED]

//>> SET_[CS_CTL_MISC_STATUS2_BRK2_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK2_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK2_RESERVED,
           CS_CTL_MISC_STATUS2_BRK2_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK2_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK2_RESERVED]

//>> GET_[CS_CTL_MISC_STATUS2_BRK2_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_BRK2_RESERVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_BRK2_RESERVED,
           CS_CTL_MISC_STATUS2_BRK2_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK2_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK2_RESERVED]

//>> SET_[CS_CTL_MISC_STATUS2_FENCE3]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_FENCE3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_FENCE3,
           CS_CTL_MISC_STATUS2_FENCE3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_FENCE3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_FENCE3]

//>> SET_[CS_CTL_MISC_STATUS2_FENCE3]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_FENCE3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_FENCE3,
           CS_CTL_MISC_STATUS2_FENCE3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_FENCE3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_FENCE3]

//>> GET_[CS_CTL_MISC_STATUS2_FENCE3]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_FENCE3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_FENCE3,
           CS_CTL_MISC_STATUS2_FENCE3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_FENCE3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_FENCE3]

//>> SET_[CS_CTL_MISC_STATUS2_BRK3_RLX]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK3_RLX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK3_RLX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK3_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK3_RLX]

//>> SET_[CS_CTL_MISC_STATUS2_BRK3_RLX]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK3_RLX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK3_RLX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK3_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK3_RLX]

//>> SET_[CS_CTL_MISC_STATUS2_BRK3_RLX]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK3_RLX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS2_BRK3_RLX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK3_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK3_RLX]

//>> CLEAR_[CS_CTL_MISC_STATUS2_BRK3_RLX]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS2_BRK3_RLX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS2_BRK3_RLX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK3_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS2_BRK3_RLX]

//>> GET_[CS_CTL_MISC_STATUS2_BRK3_RLX]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_BRK3_RLX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_BRK3_RLX,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK3_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK3_RLX]

//>> GET_[CS_CTL_MISC_STATUS2_BRK3_RLX]
static inline bool GET_CS_CTL_MISC_STATUS2_BRK3_RLX(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS2_BRK3_RLX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK3_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK3_RLX]

//>> SET_[CS_CTL_MISC_STATUS2_NVREQ3]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVREQ3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_NVREQ3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVREQ3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVREQ3]

//>> SET_[CS_CTL_MISC_STATUS2_NVREQ3]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVREQ3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_NVREQ3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVREQ3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVREQ3]

//>> SET_[CS_CTL_MISC_STATUS2_NVREQ3]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVREQ3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS2_NVREQ3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVREQ3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVREQ3]

//>> CLEAR_[CS_CTL_MISC_STATUS2_NVREQ3]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS2_NVREQ3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS2_NVREQ3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVREQ3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS2_NVREQ3]

//>> GET_[CS_CTL_MISC_STATUS2_NVREQ3]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_NVREQ3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_NVREQ3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVREQ3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_NVREQ3]

//>> GET_[CS_CTL_MISC_STATUS2_NVREQ3]
static inline bool GET_CS_CTL_MISC_STATUS2_NVREQ3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS2_NVREQ3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVREQ3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_NVREQ3]

//>> SET_[CS_CTL_MISC_STATUS2_NVDGD3]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVDGD3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_NVDGD3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVDGD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVDGD3]

//>> SET_[CS_CTL_MISC_STATUS2_NVDGD3]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVDGD3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_NVDGD3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVDGD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVDGD3]

//>> SET_[CS_CTL_MISC_STATUS2_NVDGD3]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVDGD3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS2_NVDGD3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVDGD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVDGD3]

//>> CLEAR_[CS_CTL_MISC_STATUS2_NVDGD3]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS2_NVDGD3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS2_NVDGD3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVDGD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS2_NVDGD3]

//>> GET_[CS_CTL_MISC_STATUS2_NVDGD3]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_NVDGD3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_NVDGD3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVDGD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_NVDGD3]

//>> GET_[CS_CTL_MISC_STATUS2_NVDGD3]
static inline bool GET_CS_CTL_MISC_STATUS2_NVDGD3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS2_NVDGD3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVDGD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_NVDGD3]

//>> SET_[CS_CTL_MISC_STATUS2_NVRS3]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVRS3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_NVRS3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVRS3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVRS3]

//>> SET_[CS_CTL_MISC_STATUS2_NVRS3]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVRS3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_NVRS3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVRS3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVRS3]

//>> SET_[CS_CTL_MISC_STATUS2_NVRS3]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVRS3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS2_NVRS3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVRS3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVRS3]

//>> CLEAR_[CS_CTL_MISC_STATUS2_NVRS3]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS2_NVRS3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS2_NVRS3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVRS3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS2_NVRS3]

//>> GET_[CS_CTL_MISC_STATUS2_NVRS3]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_NVRS3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_NVRS3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVRS3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_NVRS3]

//>> GET_[CS_CTL_MISC_STATUS2_NVRS3]
static inline bool GET_CS_CTL_MISC_STATUS2_NVRS3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS2_NVRS3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVRS3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_NVRS3]

//>> SET_[CS_CTL_MISC_STATUS2_BRK3_AM_FENCED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK3_AM_FENCED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK3_AM_FENCED,
           CS_CTL_MISC_STATUS2_BRK3_AM_FENCED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK3_AM_FENCED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK3_AM_FENCED]

//>> SET_[CS_CTL_MISC_STATUS2_BRK3_AM_FENCED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK3_AM_FENCED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK3_AM_FENCED,
           CS_CTL_MISC_STATUS2_BRK3_AM_FENCED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK3_AM_FENCED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK3_AM_FENCED]

//>> GET_[CS_CTL_MISC_STATUS2_BRK3_AM_FENCED]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_BRK3_AM_FENCED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_BRK3_AM_FENCED,
           CS_CTL_MISC_STATUS2_BRK3_AM_FENCED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK3_AM_FENCED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK3_AM_FENCED]

//>> SET_[CS_CTL_MISC_STATUS2_BRK3_NTL_REQ_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK3_NTL_REQ_FENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK3_NTL_REQ_FENCE,
           CS_CTL_MISC_STATUS2_BRK3_NTL_REQ_FENCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK3_NTL_REQ_FENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK3_NTL_REQ_FENCE]

//>> SET_[CS_CTL_MISC_STATUS2_BRK3_NTL_REQ_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK3_NTL_REQ_FENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK3_NTL_REQ_FENCE,
           CS_CTL_MISC_STATUS2_BRK3_NTL_REQ_FENCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK3_NTL_REQ_FENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK3_NTL_REQ_FENCE]

//>> GET_[CS_CTL_MISC_STATUS2_BRK3_NTL_REQ_FENCE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_BRK3_NTL_REQ_FENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_BRK3_NTL_REQ_FENCE,
           CS_CTL_MISC_STATUS2_BRK3_NTL_REQ_FENCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK3_NTL_REQ_FENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK3_NTL_REQ_FENCE]

//>> SET_[CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE]

//>> SET_[CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE]

//>> SET_[CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE]

//>> CLEAR_[CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE]

//>> GET_[CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE]

//>> GET_[CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE]
static inline bool GET_CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE]

//>> SET_[CS_CTL_MISC_STATUS2_BRK3_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK3_RESERVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK3_RESERVED,
           CS_CTL_MISC_STATUS2_BRK3_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK3_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK3_RESERVED]

//>> SET_[CS_CTL_MISC_STATUS2_BRK3_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK3_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK3_RESERVED,
           CS_CTL_MISC_STATUS2_BRK3_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK3_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK3_RESERVED]

//>> GET_[CS_CTL_MISC_STATUS2_BRK3_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_BRK3_RESERVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_BRK3_RESERVED,
           CS_CTL_MISC_STATUS2_BRK3_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK3_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK3_RESERVED]

//>> SET_[CS_CTL_MISC_STATUS2_FENCE4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_FENCE4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_FENCE4,
           CS_CTL_MISC_STATUS2_FENCE4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_FENCE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_FENCE4]

//>> SET_[CS_CTL_MISC_STATUS2_FENCE4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_FENCE4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_FENCE4,
           CS_CTL_MISC_STATUS2_FENCE4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_FENCE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_FENCE4]

//>> GET_[CS_CTL_MISC_STATUS2_FENCE4]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_FENCE4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_FENCE4,
           CS_CTL_MISC_STATUS2_FENCE4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_FENCE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_FENCE4]

//>> SET_[CS_CTL_MISC_STATUS2_BRK4_RLX]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK4_RLX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK4_RLX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK4_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK4_RLX]

//>> SET_[CS_CTL_MISC_STATUS2_BRK4_RLX]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK4_RLX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK4_RLX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK4_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK4_RLX]

//>> SET_[CS_CTL_MISC_STATUS2_BRK4_RLX]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK4_RLX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS2_BRK4_RLX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK4_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK4_RLX]

//>> CLEAR_[CS_CTL_MISC_STATUS2_BRK4_RLX]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS2_BRK4_RLX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS2_BRK4_RLX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK4_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS2_BRK4_RLX]

//>> GET_[CS_CTL_MISC_STATUS2_BRK4_RLX]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_BRK4_RLX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_BRK4_RLX,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK4_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK4_RLX]

//>> GET_[CS_CTL_MISC_STATUS2_BRK4_RLX]
static inline bool GET_CS_CTL_MISC_STATUS2_BRK4_RLX(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS2_BRK4_RLX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK4_RLX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK4_RLX]

//>> SET_[CS_CTL_MISC_STATUS2_NVREQ4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVREQ4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_NVREQ4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVREQ4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVREQ4]

//>> SET_[CS_CTL_MISC_STATUS2_NVREQ4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVREQ4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_NVREQ4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVREQ4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVREQ4]

//>> SET_[CS_CTL_MISC_STATUS2_NVREQ4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVREQ4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS2_NVREQ4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVREQ4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVREQ4]

//>> CLEAR_[CS_CTL_MISC_STATUS2_NVREQ4]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS2_NVREQ4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS2_NVREQ4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVREQ4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS2_NVREQ4]

//>> GET_[CS_CTL_MISC_STATUS2_NVREQ4]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_NVREQ4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_NVREQ4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVREQ4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_NVREQ4]

//>> GET_[CS_CTL_MISC_STATUS2_NVREQ4]
static inline bool GET_CS_CTL_MISC_STATUS2_NVREQ4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS2_NVREQ4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVREQ4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_NVREQ4]

//>> SET_[CS_CTL_MISC_STATUS2_NVDGD4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVDGD4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_NVDGD4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVDGD4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVDGD4]

//>> SET_[CS_CTL_MISC_STATUS2_NVDGD4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVDGD4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_NVDGD4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVDGD4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVDGD4]

//>> SET_[CS_CTL_MISC_STATUS2_NVDGD4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVDGD4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS2_NVDGD4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVDGD4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVDGD4]

//>> CLEAR_[CS_CTL_MISC_STATUS2_NVDGD4]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS2_NVDGD4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS2_NVDGD4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVDGD4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS2_NVDGD4]

//>> GET_[CS_CTL_MISC_STATUS2_NVDGD4]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_NVDGD4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_NVDGD4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVDGD4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_NVDGD4]

//>> GET_[CS_CTL_MISC_STATUS2_NVDGD4]
static inline bool GET_CS_CTL_MISC_STATUS2_NVDGD4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS2_NVDGD4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVDGD4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_NVDGD4]

//>> SET_[CS_CTL_MISC_STATUS2_NVRS4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVRS4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_NVRS4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVRS4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVRS4]

//>> SET_[CS_CTL_MISC_STATUS2_NVRS4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVRS4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_NVRS4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVRS4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVRS4]

//>> SET_[CS_CTL_MISC_STATUS2_NVRS4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_NVRS4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS2_NVRS4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVRS4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_NVRS4]

//>> CLEAR_[CS_CTL_MISC_STATUS2_NVRS4]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS2_NVRS4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS2_NVRS4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVRS4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS2_NVRS4]

//>> GET_[CS_CTL_MISC_STATUS2_NVRS4]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_NVRS4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_NVRS4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVRS4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_NVRS4]

//>> GET_[CS_CTL_MISC_STATUS2_NVRS4]
static inline bool GET_CS_CTL_MISC_STATUS2_NVRS4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS2_NVRS4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_NVRS4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_NVRS4]

//>> SET_[CS_CTL_MISC_STATUS2_BRK4_AM_FENCED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK4_AM_FENCED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK4_AM_FENCED,
           CS_CTL_MISC_STATUS2_BRK4_AM_FENCED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK4_AM_FENCED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK4_AM_FENCED]

//>> SET_[CS_CTL_MISC_STATUS2_BRK4_AM_FENCED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK4_AM_FENCED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK4_AM_FENCED,
           CS_CTL_MISC_STATUS2_BRK4_AM_FENCED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK4_AM_FENCED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK4_AM_FENCED]

//>> GET_[CS_CTL_MISC_STATUS2_BRK4_AM_FENCED]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_BRK4_AM_FENCED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_BRK4_AM_FENCED,
           CS_CTL_MISC_STATUS2_BRK4_AM_FENCED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK4_AM_FENCED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK4_AM_FENCED]

//>> SET_[CS_CTL_MISC_STATUS2_BRK4_NTL_REQ_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK4_NTL_REQ_FENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK4_NTL_REQ_FENCE,
           CS_CTL_MISC_STATUS2_BRK4_NTL_REQ_FENCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK4_NTL_REQ_FENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK4_NTL_REQ_FENCE]

//>> SET_[CS_CTL_MISC_STATUS2_BRK4_NTL_REQ_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK4_NTL_REQ_FENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK4_NTL_REQ_FENCE,
           CS_CTL_MISC_STATUS2_BRK4_NTL_REQ_FENCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK4_NTL_REQ_FENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK4_NTL_REQ_FENCE]

//>> GET_[CS_CTL_MISC_STATUS2_BRK4_NTL_REQ_FENCE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_BRK4_NTL_REQ_FENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_BRK4_NTL_REQ_FENCE,
           CS_CTL_MISC_STATUS2_BRK4_NTL_REQ_FENCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK4_NTL_REQ_FENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK4_NTL_REQ_FENCE]

//>> SET_[CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE]

//>> SET_[CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE]

//>> SET_[CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.setBit<CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE]

//>> CLEAR_[CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.clearBit<CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE]

//>> GET_[CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE]

//>> GET_[CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE]
static inline bool GET_CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.getBit<CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE]

//>> SET_[CS_CTL_MISC_STATUS2_BRK4_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK4_RESERVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK4_RESERVED,
           CS_CTL_MISC_STATUS2_BRK4_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK4_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK4_RESERVED]

//>> SET_[CS_CTL_MISC_STATUS2_BRK4_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_STATUS2_BRK4_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_STATUS2_BRK4_RESERVED,
           CS_CTL_MISC_STATUS2_BRK4_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK4_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_STATUS2_BRK4_RESERVED]

//>> GET_[CS_CTL_MISC_STATUS2_BRK4_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_STATUS2_BRK4_RESERVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_STATUS2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_STATUS2_BRK4_RESERVED,
           CS_CTL_MISC_STATUS2_BRK4_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_STATUS2_BRK4_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_STATUS2_BRK4_RESERVED]

//>> PREP_[CS_SM1_SNP_MISC_GPU0_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CS_SM1_SNP_MISC_GPU0_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM1_SNP_MISC_GPU0_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CS_SM1_SNP_MISC_GPU0_BAR]

//>> GET_[CS_SM1_SNP_MISC_GPU0_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CS_SM1_SNP_MISC_GPU0_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM1_SNP_MISC_GPU0_BAR;
#endif
    return fapi2::getScom(i_target, CS_SM1_SNP_MISC_GPU0_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU0_BAR]

//>> PUT_[CS_SM1_SNP_MISC_GPU0_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CS_SM1_SNP_MISC_GPU0_BAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return fapi2::putScom(i_target, CS_SM1_SNP_MISC_GPU0_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CS_SM1_SNP_MISC_GPU0_BAR]


//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_ENABLE]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_ENABLE]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_GPU0_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_ENABLE]

//>> CLEAR_[CS_SM1_SNP_MISC_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_GPU0_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_GPU0_BAR_ENABLE]

//>> GET_[CS_SM1_SNP_MISC_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU0_BAR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU0_BAR_ENABLE]

//>> GET_[CS_SM1_SNP_MISC_GPU0_BAR_ENABLE]
static inline bool GET_CS_SM1_SNP_MISC_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_GPU0_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU0_BAR_ENABLE]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_ADDR_MASK,
           CS_SM1_SNP_MISC_GPU0_BAR_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_ADDR_MASK]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_ADDR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_ADDR_MASK,
           CS_SM1_SNP_MISC_GPU0_BAR_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_ADDR_MASK]

//>> GET_[CS_SM1_SNP_MISC_GPU0_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU0_BAR_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU0_BAR_ADDR_MASK,
           CS_SM1_SNP_MISC_GPU0_BAR_ADDR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU0_BAR_ADDR_MASK]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE]

//>> CLEAR_[CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE]

//>> GET_[CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE]

//>> GET_[CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE]
static inline bool GET_CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT]

//>> CLEAR_[CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT]

//>> GET_[CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT]

//>> GET_[CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT]
static inline bool GET_CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_4T_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_4T_SELECT,
           CS_SM1_SNP_MISC_GPU0_BAR_4T_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_4T_SELECT]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_4T_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_4T_SELECT,
           CS_SM1_SNP_MISC_GPU0_BAR_4T_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_4T_SELECT]

//>> GET_[CS_SM1_SNP_MISC_GPU0_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU0_BAR_4T_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU0_BAR_4T_SELECT,
           CS_SM1_SNP_MISC_GPU0_BAR_4T_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU0_BAR_4T_SELECT]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_MODE,
           CS_SM1_SNP_MISC_GPU0_BAR_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_MODE,
           CS_SM1_SNP_MISC_GPU0_BAR_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_MODE]

//>> GET_[CS_SM1_SNP_MISC_GPU0_BAR_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU0_BAR_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU0_BAR_MODE,
           CS_SM1_SNP_MISC_GPU0_BAR_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU0_BAR_MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_GRANULE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_GRANULE]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_GRANULE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_GRANULE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_GRANULE]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_GPU0_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_GRANULE]

//>> CLEAR_[CS_SM1_SNP_MISC_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_GPU0_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_GPU0_BAR_GRANULE]

//>> GET_[CS_SM1_SNP_MISC_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU0_BAR_GRANULE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU0_BAR_GRANULE]

//>> GET_[CS_SM1_SNP_MISC_GPU0_BAR_GRANULE]
static inline bool GET_CS_SM1_SNP_MISC_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_GPU0_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU0_BAR_GRANULE]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_POISON]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_POISON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_POISON]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_GPU0_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_POISON]

//>> CLEAR_[CS_SM1_SNP_MISC_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_GPU0_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_GPU0_BAR_POISON]

//>> GET_[CS_SM1_SNP_MISC_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU0_BAR_POISON,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU0_BAR_POISON]

//>> GET_[CS_SM1_SNP_MISC_GPU0_BAR_POISON]
static inline bool GET_CS_SM1_SNP_MISC_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_GPU0_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU0_BAR_POISON]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_M2MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_M2MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_M2MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_M2MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_M2MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_GPU0_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_M2MODE]

//>> CLEAR_[CS_SM1_SNP_MISC_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_GPU0_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_GPU0_BAR_M2MODE]

//>> GET_[CS_SM1_SNP_MISC_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU0_BAR_M2MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU0_BAR_M2MODE]

//>> GET_[CS_SM1_SNP_MISC_GPU0_BAR_M2MODE]
static inline bool GET_CS_SM1_SNP_MISC_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_GPU0_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU0_BAR_M2MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]

//>> CLEAR_[CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]

//>> GET_[CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]

//>> GET_[CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]
static inline bool GET_CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12]

//>> CLEAR_[CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12]

//>> GET_[CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12]

//>> GET_[CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12]
static inline bool GET_CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]

//>> CLEAR_[CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]

//>> GET_[CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]

//>> GET_[CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]
static inline bool GET_CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE]

//>> CLEAR_[CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE]

//>> GET_[CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE]

//>> GET_[CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE]
static inline bool GET_CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_RESERVED]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU0_BAR_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_RESERVED]

//>> SET_[CS_SM1_SNP_MISC_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_GPU0_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU0_BAR_RESERVED]

//>> CLEAR_[CS_SM1_SNP_MISC_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_GPU0_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_GPU0_BAR_RESERVED]

//>> GET_[CS_SM1_SNP_MISC_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU0_BAR_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU0_BAR_RESERVED]

//>> GET_[CS_SM1_SNP_MISC_GPU0_BAR_RESERVED]
static inline bool GET_CS_SM1_SNP_MISC_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_GPU0_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU0_BAR_RESERVED]

//>> PREP_[CS_SM1_SNP_MISC_GPU1_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CS_SM1_SNP_MISC_GPU1_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM1_SNP_MISC_GPU1_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CS_SM1_SNP_MISC_GPU1_BAR]

//>> GET_[CS_SM1_SNP_MISC_GPU1_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CS_SM1_SNP_MISC_GPU1_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM1_SNP_MISC_GPU1_BAR;
#endif
    return fapi2::getScom(i_target, CS_SM1_SNP_MISC_GPU1_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU1_BAR]

//>> PUT_[CS_SM1_SNP_MISC_GPU1_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CS_SM1_SNP_MISC_GPU1_BAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return fapi2::putScom(i_target, CS_SM1_SNP_MISC_GPU1_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CS_SM1_SNP_MISC_GPU1_BAR]


//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_ENABLE]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_ENABLE]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_GPU1_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_ENABLE]

//>> CLEAR_[CS_SM1_SNP_MISC_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_GPU1_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_GPU1_BAR_ENABLE]

//>> GET_[CS_SM1_SNP_MISC_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU1_BAR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU1_BAR_ENABLE]

//>> GET_[CS_SM1_SNP_MISC_GPU1_BAR_ENABLE]
static inline bool GET_CS_SM1_SNP_MISC_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_GPU1_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU1_BAR_ENABLE]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_ADDR_MASK,
           CS_SM1_SNP_MISC_GPU1_BAR_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_ADDR_MASK]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_ADDR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_ADDR_MASK,
           CS_SM1_SNP_MISC_GPU1_BAR_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_ADDR_MASK]

//>> GET_[CS_SM1_SNP_MISC_GPU1_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU1_BAR_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU1_BAR_ADDR_MASK,
           CS_SM1_SNP_MISC_GPU1_BAR_ADDR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU1_BAR_ADDR_MASK]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE]

//>> CLEAR_[CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE]

//>> GET_[CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE]

//>> GET_[CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE]
static inline bool GET_CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT]

//>> CLEAR_[CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT]

//>> GET_[CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT]

//>> GET_[CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT]
static inline bool GET_CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_4T_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_4T_SELECT,
           CS_SM1_SNP_MISC_GPU1_BAR_4T_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_4T_SELECT]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_4T_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_4T_SELECT,
           CS_SM1_SNP_MISC_GPU1_BAR_4T_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_4T_SELECT]

//>> GET_[CS_SM1_SNP_MISC_GPU1_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU1_BAR_4T_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU1_BAR_4T_SELECT,
           CS_SM1_SNP_MISC_GPU1_BAR_4T_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU1_BAR_4T_SELECT]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_MODE,
           CS_SM1_SNP_MISC_GPU1_BAR_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_MODE,
           CS_SM1_SNP_MISC_GPU1_BAR_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_MODE]

//>> GET_[CS_SM1_SNP_MISC_GPU1_BAR_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU1_BAR_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU1_BAR_MODE,
           CS_SM1_SNP_MISC_GPU1_BAR_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU1_BAR_MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_GRANULE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_GRANULE]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_GRANULE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_GRANULE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_GRANULE]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_GPU1_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_GRANULE]

//>> CLEAR_[CS_SM1_SNP_MISC_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_GPU1_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_GPU1_BAR_GRANULE]

//>> GET_[CS_SM1_SNP_MISC_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU1_BAR_GRANULE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU1_BAR_GRANULE]

//>> GET_[CS_SM1_SNP_MISC_GPU1_BAR_GRANULE]
static inline bool GET_CS_SM1_SNP_MISC_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_GPU1_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU1_BAR_GRANULE]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_POISON]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_POISON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_POISON]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_GPU1_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_POISON]

//>> CLEAR_[CS_SM1_SNP_MISC_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_GPU1_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_GPU1_BAR_POISON]

//>> GET_[CS_SM1_SNP_MISC_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU1_BAR_POISON,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU1_BAR_POISON]

//>> GET_[CS_SM1_SNP_MISC_GPU1_BAR_POISON]
static inline bool GET_CS_SM1_SNP_MISC_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_GPU1_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU1_BAR_POISON]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_M2MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_M2MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_M2MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_M2MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_M2MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_GPU1_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_M2MODE]

//>> CLEAR_[CS_SM1_SNP_MISC_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_GPU1_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_GPU1_BAR_M2MODE]

//>> GET_[CS_SM1_SNP_MISC_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU1_BAR_M2MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU1_BAR_M2MODE]

//>> GET_[CS_SM1_SNP_MISC_GPU1_BAR_M2MODE]
static inline bool GET_CS_SM1_SNP_MISC_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_GPU1_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU1_BAR_M2MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]

//>> CLEAR_[CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]

//>> GET_[CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]

//>> GET_[CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]
static inline bool GET_CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12]

//>> CLEAR_[CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12]

//>> GET_[CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12]

//>> GET_[CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12]
static inline bool GET_CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]

//>> CLEAR_[CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]

//>> GET_[CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]

//>> GET_[CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]
static inline bool GET_CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE]

//>> CLEAR_[CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE]

//>> GET_[CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE]

//>> GET_[CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE]
static inline bool GET_CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_RESERVED]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GPU1_BAR_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_RESERVED]

//>> SET_[CS_SM1_SNP_MISC_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_GPU1_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GPU1_BAR_RESERVED]

//>> CLEAR_[CS_SM1_SNP_MISC_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_GPU1_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_GPU1_BAR_RESERVED]

//>> GET_[CS_SM1_SNP_MISC_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GPU1_BAR_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU1_BAR_RESERVED]

//>> GET_[CS_SM1_SNP_MISC_GPU1_BAR_RESERVED]
static inline bool GET_CS_SM1_SNP_MISC_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_GPU1_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GPU1_BAR_RESERVED]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
