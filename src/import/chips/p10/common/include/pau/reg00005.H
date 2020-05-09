/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pau/reg00005.H $          */
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

#ifndef __PAU_REG00005_H_
#define __PAU_REG00005_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


//>> PREP_[XTS_REG_ERR_HOLD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XTS_REG_ERR_HOLD(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XTS_REG_ERR_HOLD;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[XTS_REG_ERR_HOLD]

//>> GET_[XTS_REG_ERR_HOLD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XTS_REG_ERR_HOLD(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XTS_REG_ERR_HOLD;
#endif
    return fapi2::getScom(i_target, XTS_REG_ERR_HOLD, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD]

//>> PUT_[XTS_REG_ERR_HOLD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XTS_REG_ERR_HOLD(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return fapi2::putScom(i_target, XTS_REG_ERR_HOLD, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[XTS_REG_ERR_HOLD]


//>> SET_[XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR]

//>> SET_[XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR]

//>> SET_[XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR]

//>> CLEAR_[XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR]

//>> GET_[XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR]

//>> GET_[XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR]
static inline bool GET_XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_DEBUG0_CONFIG_P_ERR]

//>> SET_[XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR]

//>> SET_[XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR]

//>> SET_[XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR]

//>> CLEAR_[XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR]

//>> GET_[XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR]

//>> GET_[XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR]
static inline bool GET_XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_DEBUG1_CONFIG_P_ERR]

//>> SET_[XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR]

//>> SET_[XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR]

//>> SET_[XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR]

//>> CLEAR_[XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR]

//>> GET_[XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR]

//>> GET_[XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR]
static inline bool GET_XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_XTS_CONFIG_P_ERR]

//>> SET_[XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR]

//>> SET_[XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR]

//>> SET_[XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR]

//>> CLEAR_[XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR]

//>> GET_[XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR]

//>> GET_[XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR]
static inline bool GET_XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_XTS_CONFIG2_P_ERR]

//>> SET_[XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR]

//>> SET_[XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR]

//>> SET_[XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR]

//>> CLEAR_[XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR]

//>> GET_[XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR]

//>> GET_[XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR]
static inline bool GET_XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_XTS_CONFIG3_P_ERR]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR9]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_SNP_REG_ERR9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR9]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR9]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_SNP_REG_ERR9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR9]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR9]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_SNP_REG_ERR9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR9]

//>> CLEAR_[XTS_REG_ERR_HOLD_SNP_REG_ERR9]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_SNP_REG_ERR9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_SNP_REG_ERR9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_SNP_REG_ERR9]

//>> GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR9]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_SNP_REG_ERR9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_SNP_REG_ERR9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR9]

//>> GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR9]
static inline bool GET_XTS_REG_ERR_HOLD_SNP_REG_ERR9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_SNP_REG_ERR9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR9]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR7]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_SNP_REG_ERR7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR7]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR7]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_SNP_REG_ERR7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR7]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR7]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_SNP_REG_ERR7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR7]

//>> CLEAR_[XTS_REG_ERR_HOLD_SNP_REG_ERR7]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_SNP_REG_ERR7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_SNP_REG_ERR7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_SNP_REG_ERR7]

//>> GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR7]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_SNP_REG_ERR7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_SNP_REG_ERR7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR7]

//>> GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR7]
static inline bool GET_XTS_REG_ERR_HOLD_SNP_REG_ERR7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_SNP_REG_ERR7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR7]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR8]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_SNP_REG_ERR8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR8]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR8]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_SNP_REG_ERR8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR8]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR8]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_SNP_REG_ERR8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR8]

//>> CLEAR_[XTS_REG_ERR_HOLD_SNP_REG_ERR8]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_SNP_REG_ERR8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_SNP_REG_ERR8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_SNP_REG_ERR8]

//>> GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR8]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_SNP_REG_ERR8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_SNP_REG_ERR8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR8]

//>> GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR8]
static inline bool GET_XTS_REG_ERR_HOLD_SNP_REG_ERR8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_SNP_REG_ERR8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR8]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR0]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_SNP_REG_ERR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR0]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR0]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_SNP_REG_ERR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR0]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR0]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_SNP_REG_ERR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR0]

//>> CLEAR_[XTS_REG_ERR_HOLD_SNP_REG_ERR0]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_SNP_REG_ERR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_SNP_REG_ERR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_SNP_REG_ERR0]

//>> GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR0]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_SNP_REG_ERR0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_SNP_REG_ERR0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR0]

//>> GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR0]
static inline bool GET_XTS_REG_ERR_HOLD_SNP_REG_ERR0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_SNP_REG_ERR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR0]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR1]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_SNP_REG_ERR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR1]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR1]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_SNP_REG_ERR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR1]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR1]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_SNP_REG_ERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR1]

//>> CLEAR_[XTS_REG_ERR_HOLD_SNP_REG_ERR1]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_SNP_REG_ERR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_SNP_REG_ERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_SNP_REG_ERR1]

//>> GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR1]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_SNP_REG_ERR1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_SNP_REG_ERR1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR1]

//>> GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR1]
static inline bool GET_XTS_REG_ERR_HOLD_SNP_REG_ERR1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_SNP_REG_ERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR1]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR2]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_SNP_REG_ERR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR2]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR2]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_SNP_REG_ERR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR2]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR2]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_SNP_REG_ERR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR2]

//>> CLEAR_[XTS_REG_ERR_HOLD_SNP_REG_ERR2]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_SNP_REG_ERR2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_SNP_REG_ERR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_SNP_REG_ERR2]

//>> GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR2]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_SNP_REG_ERR2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_SNP_REG_ERR2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR2]

//>> GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR2]
static inline bool GET_XTS_REG_ERR_HOLD_SNP_REG_ERR2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_SNP_REG_ERR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR2]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR3]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_SNP_REG_ERR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR3]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR3]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_SNP_REG_ERR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR3]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR3]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_SNP_REG_ERR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR3]

//>> CLEAR_[XTS_REG_ERR_HOLD_SNP_REG_ERR3]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_SNP_REG_ERR3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_SNP_REG_ERR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_SNP_REG_ERR3]

//>> GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR3]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_SNP_REG_ERR3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_SNP_REG_ERR3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR3]

//>> GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR3]
static inline bool GET_XTS_REG_ERR_HOLD_SNP_REG_ERR3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_SNP_REG_ERR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR3]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR4]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_SNP_REG_ERR4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR4]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR4]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_SNP_REG_ERR4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR4]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR4]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_SNP_REG_ERR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR4]

//>> CLEAR_[XTS_REG_ERR_HOLD_SNP_REG_ERR4]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_SNP_REG_ERR4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_SNP_REG_ERR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_SNP_REG_ERR4]

//>> GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR4]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_SNP_REG_ERR4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_SNP_REG_ERR4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR4]

//>> GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR4]
static inline bool GET_XTS_REG_ERR_HOLD_SNP_REG_ERR4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_SNP_REG_ERR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR4]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR5]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_SNP_REG_ERR5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR5]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR5]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_SNP_REG_ERR5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR5]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR5]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_SNP_REG_ERR5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR5]

//>> CLEAR_[XTS_REG_ERR_HOLD_SNP_REG_ERR5]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_SNP_REG_ERR5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_SNP_REG_ERR5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_SNP_REG_ERR5]

//>> GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR5]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_SNP_REG_ERR5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_SNP_REG_ERR5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR5]

//>> GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR5]
static inline bool GET_XTS_REG_ERR_HOLD_SNP_REG_ERR5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_SNP_REG_ERR5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR5]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR6]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_SNP_REG_ERR6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR6]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR6]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_SNP_REG_ERR6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR6]

//>> SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR6]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_SNP_REG_ERR6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_SNP_REG_ERR6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_SNP_REG_ERR6]

//>> CLEAR_[XTS_REG_ERR_HOLD_SNP_REG_ERR6]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_SNP_REG_ERR6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_SNP_REG_ERR6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_SNP_REG_ERR6]

//>> GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR6]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_SNP_REG_ERR6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_SNP_REG_ERR6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR6]

//>> GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR6]
static inline bool GET_XTS_REG_ERR_HOLD_SNP_REG_ERR6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_SNP_REG_ERR6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_SNP_REG_ERR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_SNP_REG_ERR6]

//>> SET_[XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE]

//>> SET_[XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE]

//>> SET_[XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE]

//>> CLEAR_[XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE]

//>> GET_[XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE]

//>> GET_[XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE]
static inline bool GET_XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_ATR_ERR_SM_STATE]

//>> SET_[XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE]

//>> SET_[XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE]

//>> SET_[XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE]

//>> CLEAR_[XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE]

//>> GET_[XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE]

//>> GET_[XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE]
static inline bool GET_XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_ATSD_ERR_SM_STATE]

//>> SET_[XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT]

//>> SET_[XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT]

//>> SET_[XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT]

//>> CLEAR_[XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT]

//>> GET_[XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT]

//>> GET_[XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT]
static inline bool GET_XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_ATR_ERR_TIMEOUT]

//>> SET_[XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT]

//>> SET_[XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT]

//>> SET_[XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT]

//>> CLEAR_[XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT]

//>> GET_[XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT]

//>> GET_[XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT]
static inline bool GET_XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_ATSD_ERR_TIMEOUT]

//>> SET_[XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG]

//>> SET_[XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG]

//>> SET_[XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG]

//>> CLEAR_[XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG]

//>> GET_[XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG]

//>> GET_[XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG]
static inline bool GET_XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_ATSD_ERR_BAD_TAG]

//>> SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR2]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_MAP_REG_ERR2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_MAP_REG_ERR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR2]

//>> SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR2]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_MAP_REG_ERR2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_MAP_REG_ERR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR2]

//>> SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR2]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_MAP_REG_ERR2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_MAP_REG_ERR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR2]

//>> CLEAR_[XTS_REG_ERR_HOLD_MAP_REG_ERR2]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_MAP_REG_ERR2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_MAP_REG_ERR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_MAP_REG_ERR2]

//>> GET_[XTS_REG_ERR_HOLD_MAP_REG_ERR2]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_MAP_REG_ERR2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_MAP_REG_ERR2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_MAP_REG_ERR2]

//>> GET_[XTS_REG_ERR_HOLD_MAP_REG_ERR2]
static inline bool GET_XTS_REG_ERR_HOLD_MAP_REG_ERR2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_MAP_REG_ERR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_MAP_REG_ERR2]

//>> SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR3]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_MAP_REG_ERR3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_MAP_REG_ERR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR3]

//>> SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR3]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_MAP_REG_ERR3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_MAP_REG_ERR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR3]

//>> SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR3]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_MAP_REG_ERR3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_MAP_REG_ERR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR3]

//>> CLEAR_[XTS_REG_ERR_HOLD_MAP_REG_ERR3]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_MAP_REG_ERR3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_MAP_REG_ERR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_MAP_REG_ERR3]

//>> GET_[XTS_REG_ERR_HOLD_MAP_REG_ERR3]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_MAP_REG_ERR3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_MAP_REG_ERR3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_MAP_REG_ERR3]

//>> GET_[XTS_REG_ERR_HOLD_MAP_REG_ERR3]
static inline bool GET_XTS_REG_ERR_HOLD_MAP_REG_ERR3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_MAP_REG_ERR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_MAP_REG_ERR3]

//>> SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR4]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_MAP_REG_ERR4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_MAP_REG_ERR4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR4]

//>> SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR4]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_MAP_REG_ERR4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_MAP_REG_ERR4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR4]

//>> SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR4]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_MAP_REG_ERR4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_MAP_REG_ERR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR4]

//>> CLEAR_[XTS_REG_ERR_HOLD_MAP_REG_ERR4]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_MAP_REG_ERR4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_MAP_REG_ERR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_MAP_REG_ERR4]

//>> GET_[XTS_REG_ERR_HOLD_MAP_REG_ERR4]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_MAP_REG_ERR4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_MAP_REG_ERR4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_MAP_REG_ERR4]

//>> GET_[XTS_REG_ERR_HOLD_MAP_REG_ERR4]
static inline bool GET_XTS_REG_ERR_HOLD_MAP_REG_ERR4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_MAP_REG_ERR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_MAP_REG_ERR4]

//>> SET_[XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE]

//>> SET_[XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE]

//>> SET_[XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE]

//>> CLEAR_[XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE]

//>> GET_[XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE]

//>> GET_[XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE]
static inline bool GET_XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_ATR_ERR_ARBSTATE]

//>> SET_[XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND]

//>> SET_[XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND]

//>> SET_[XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND]

//>> CLEAR_[XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND]

//>> GET_[XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND]

//>> GET_[XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND]
static inline bool GET_XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_ATR_ERR_RADDR_BND]

//>> SET_[XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR]

//>> SET_[XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR]

//>> SET_[XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR]

//>> CLEAR_[XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR]

//>> GET_[XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR]

//>> GET_[XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR]
static inline bool GET_XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_BDF_MAP_REG_PARITY_ERR]

//>> SET_[XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR]

//>> SET_[XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR]

//>> SET_[XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR]

//>> CLEAR_[XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR]

//>> GET_[XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR]

//>> GET_[XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR]
static inline bool GET_XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_PID_MAP_REG_PARITY_ERR]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_CERR0]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_CERR0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_IFC_REG_CERR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_CERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_CERR0]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_CERR0]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_CERR0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_IFC_REG_CERR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_CERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_CERR0]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_CERR0]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_CERR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_IFC_REG_CERR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_CERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_CERR0]

//>> CLEAR_[XTS_REG_ERR_HOLD_IFC_REG_CERR0]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_IFC_REG_CERR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_IFC_REG_CERR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_CERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_IFC_REG_CERR0]

//>> GET_[XTS_REG_ERR_HOLD_IFC_REG_CERR0]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_IFC_REG_CERR0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_IFC_REG_CERR0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_CERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_IFC_REG_CERR0]

//>> GET_[XTS_REG_ERR_HOLD_IFC_REG_CERR0]
static inline bool GET_XTS_REG_ERR_HOLD_IFC_REG_CERR0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_IFC_REG_CERR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_CERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_IFC_REG_CERR0]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_CERR1]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_CERR1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_IFC_REG_CERR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_CERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_CERR1]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_CERR1]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_CERR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_IFC_REG_CERR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_CERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_CERR1]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_CERR1]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_CERR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_IFC_REG_CERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_CERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_CERR1]

//>> CLEAR_[XTS_REG_ERR_HOLD_IFC_REG_CERR1]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_IFC_REG_CERR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_IFC_REG_CERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_CERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_IFC_REG_CERR1]

//>> GET_[XTS_REG_ERR_HOLD_IFC_REG_CERR1]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_IFC_REG_CERR1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_IFC_REG_CERR1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_CERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_IFC_REG_CERR1]

//>> GET_[XTS_REG_ERR_HOLD_IFC_REG_CERR1]
static inline bool GET_XTS_REG_ERR_HOLD_IFC_REG_CERR1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_IFC_REG_CERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_CERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_IFC_REG_CERR1]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_CERR2]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_CERR2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_IFC_REG_CERR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_CERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_CERR2]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_CERR2]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_CERR2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_IFC_REG_CERR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_CERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_CERR2]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_CERR2]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_CERR2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_IFC_REG_CERR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_CERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_CERR2]

//>> CLEAR_[XTS_REG_ERR_HOLD_IFC_REG_CERR2]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_IFC_REG_CERR2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_IFC_REG_CERR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_CERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_IFC_REG_CERR2]

//>> GET_[XTS_REG_ERR_HOLD_IFC_REG_CERR2]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_IFC_REG_CERR2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_IFC_REG_CERR2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_CERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_IFC_REG_CERR2]

//>> GET_[XTS_REG_ERR_HOLD_IFC_REG_CERR2]
static inline bool GET_XTS_REG_ERR_HOLD_IFC_REG_CERR2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_IFC_REG_CERR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_CERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_IFC_REG_CERR2]

//>> SET_[XTS_REG_ERR_HOLD_MAP_REG_CERR0]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_MAP_REG_CERR0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_MAP_REG_CERR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_CERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_MAP_REG_CERR0]

//>> SET_[XTS_REG_ERR_HOLD_MAP_REG_CERR0]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_MAP_REG_CERR0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_MAP_REG_CERR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_CERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_MAP_REG_CERR0]

//>> SET_[XTS_REG_ERR_HOLD_MAP_REG_CERR0]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_MAP_REG_CERR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_MAP_REG_CERR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_CERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_MAP_REG_CERR0]

//>> CLEAR_[XTS_REG_ERR_HOLD_MAP_REG_CERR0]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_MAP_REG_CERR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_MAP_REG_CERR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_CERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_MAP_REG_CERR0]

//>> GET_[XTS_REG_ERR_HOLD_MAP_REG_CERR0]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_MAP_REG_CERR0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_MAP_REG_CERR0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_CERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_MAP_REG_CERR0]

//>> GET_[XTS_REG_ERR_HOLD_MAP_REG_CERR0]
static inline bool GET_XTS_REG_ERR_HOLD_MAP_REG_CERR0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_MAP_REG_CERR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_CERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_MAP_REG_CERR0]

//>> SET_[XTS_REG_ERR_HOLD_MAP_REG_CERR1]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_MAP_REG_CERR1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_MAP_REG_CERR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_CERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_MAP_REG_CERR1]

//>> SET_[XTS_REG_ERR_HOLD_MAP_REG_CERR1]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_MAP_REG_CERR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_MAP_REG_CERR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_CERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_MAP_REG_CERR1]

//>> SET_[XTS_REG_ERR_HOLD_MAP_REG_CERR1]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_MAP_REG_CERR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_MAP_REG_CERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_CERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_MAP_REG_CERR1]

//>> CLEAR_[XTS_REG_ERR_HOLD_MAP_REG_CERR1]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_MAP_REG_CERR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_MAP_REG_CERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_CERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_MAP_REG_CERR1]

//>> GET_[XTS_REG_ERR_HOLD_MAP_REG_CERR1]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_MAP_REG_CERR1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_MAP_REG_CERR1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_CERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_MAP_REG_CERR1]

//>> GET_[XTS_REG_ERR_HOLD_MAP_REG_CERR1]
static inline bool GET_XTS_REG_ERR_HOLD_MAP_REG_CERR1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_MAP_REG_CERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_CERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_MAP_REG_CERR1]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR0]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_ERR0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_IFC_REG_ERR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR0]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR0]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_ERR0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_IFC_REG_ERR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR0]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR0]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_ERR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_IFC_REG_ERR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR0]

//>> CLEAR_[XTS_REG_ERR_HOLD_IFC_REG_ERR0]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_IFC_REG_ERR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_IFC_REG_ERR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_IFC_REG_ERR0]

//>> GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR0]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_IFC_REG_ERR0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_IFC_REG_ERR0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR0]

//>> GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR0]
static inline bool GET_XTS_REG_ERR_HOLD_IFC_REG_ERR0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_IFC_REG_ERR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR0]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR1]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_ERR1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_IFC_REG_ERR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR1]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR1]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_ERR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_IFC_REG_ERR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR1]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR1]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_ERR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_IFC_REG_ERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR1]

//>> CLEAR_[XTS_REG_ERR_HOLD_IFC_REG_ERR1]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_IFC_REG_ERR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_IFC_REG_ERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_IFC_REG_ERR1]

//>> GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR1]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_IFC_REG_ERR1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_IFC_REG_ERR1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR1]

//>> GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR1]
static inline bool GET_XTS_REG_ERR_HOLD_IFC_REG_ERR1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_IFC_REG_ERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR1]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR2]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_ERR2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_IFC_REG_ERR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR2]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR2]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_ERR2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_IFC_REG_ERR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR2]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR2]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_ERR2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_IFC_REG_ERR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR2]

//>> CLEAR_[XTS_REG_ERR_HOLD_IFC_REG_ERR2]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_IFC_REG_ERR2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_IFC_REG_ERR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_IFC_REG_ERR2]

//>> GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR2]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_IFC_REG_ERR2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_IFC_REG_ERR2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR2]

//>> GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR2]
static inline bool GET_XTS_REG_ERR_HOLD_IFC_REG_ERR2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_IFC_REG_ERR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR2]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR3]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_ERR3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_IFC_REG_ERR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR3]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR3]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_ERR3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_IFC_REG_ERR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR3]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR3]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_ERR3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_IFC_REG_ERR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR3]

//>> CLEAR_[XTS_REG_ERR_HOLD_IFC_REG_ERR3]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_IFC_REG_ERR3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_IFC_REG_ERR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_IFC_REG_ERR3]

//>> GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR3]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_IFC_REG_ERR3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_IFC_REG_ERR3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR3]

//>> GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR3]
static inline bool GET_XTS_REG_ERR_HOLD_IFC_REG_ERR3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_IFC_REG_ERR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR3]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR4]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_ERR4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_IFC_REG_ERR4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR4]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR4]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_ERR4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_IFC_REG_ERR4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR4]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR4]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_ERR4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_IFC_REG_ERR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR4]

//>> CLEAR_[XTS_REG_ERR_HOLD_IFC_REG_ERR4]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_IFC_REG_ERR4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_IFC_REG_ERR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_IFC_REG_ERR4]

//>> GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR4]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_IFC_REG_ERR4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_IFC_REG_ERR4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR4]

//>> GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR4]
static inline bool GET_XTS_REG_ERR_HOLD_IFC_REG_ERR4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_IFC_REG_ERR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR4]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR5]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_ERR5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_IFC_REG_ERR5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR5]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR5]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_ERR5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_IFC_REG_ERR5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR5]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR5]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_ERR5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_IFC_REG_ERR5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR5]

//>> CLEAR_[XTS_REG_ERR_HOLD_IFC_REG_ERR5]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_IFC_REG_ERR5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_IFC_REG_ERR5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_IFC_REG_ERR5]

//>> GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR5]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_IFC_REG_ERR5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_IFC_REG_ERR5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR5]

//>> GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR5]
static inline bool GET_XTS_REG_ERR_HOLD_IFC_REG_ERR5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_IFC_REG_ERR5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR5]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR6]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_ERR6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_IFC_REG_ERR6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR6]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR6]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_ERR6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_IFC_REG_ERR6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR6]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR6]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_ERR6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_IFC_REG_ERR6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR6]

//>> CLEAR_[XTS_REG_ERR_HOLD_IFC_REG_ERR6]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_IFC_REG_ERR6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_IFC_REG_ERR6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_IFC_REG_ERR6]

//>> GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR6]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_IFC_REG_ERR6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_IFC_REG_ERR6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR6]

//>> GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR6]
static inline bool GET_XTS_REG_ERR_HOLD_IFC_REG_ERR6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_IFC_REG_ERR6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR6]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR7]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_ERR7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_IFC_REG_ERR7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR7]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR7]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_ERR7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_IFC_REG_ERR7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR7]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR7]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_ERR7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_IFC_REG_ERR7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR7]

//>> CLEAR_[XTS_REG_ERR_HOLD_IFC_REG_ERR7]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_IFC_REG_ERR7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_IFC_REG_ERR7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_IFC_REG_ERR7]

//>> GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR7]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_IFC_REG_ERR7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_IFC_REG_ERR7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR7]

//>> GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR7]
static inline bool GET_XTS_REG_ERR_HOLD_IFC_REG_ERR7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_IFC_REG_ERR7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR7]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR8]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_ERR8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_IFC_REG_ERR8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR8]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR8]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_ERR8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_IFC_REG_ERR8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR8]

//>> SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR8]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_IFC_REG_ERR8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_IFC_REG_ERR8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_IFC_REG_ERR8]

//>> CLEAR_[XTS_REG_ERR_HOLD_IFC_REG_ERR8]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_IFC_REG_ERR8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_IFC_REG_ERR8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_IFC_REG_ERR8]

//>> GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR8]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_IFC_REG_ERR8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_IFC_REG_ERR8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR8]

//>> GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR8]
static inline bool GET_XTS_REG_ERR_HOLD_IFC_REG_ERR8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_IFC_REG_ERR8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_IFC_REG_ERR8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_IFC_REG_ERR8]

//>> SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR0]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_MAP_REG_ERR0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_MAP_REG_ERR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR0]

//>> SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR0]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_MAP_REG_ERR0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_MAP_REG_ERR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR0]

//>> SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR0]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_MAP_REG_ERR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_MAP_REG_ERR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR0]

//>> CLEAR_[XTS_REG_ERR_HOLD_MAP_REG_ERR0]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_MAP_REG_ERR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_MAP_REG_ERR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_MAP_REG_ERR0]

//>> GET_[XTS_REG_ERR_HOLD_MAP_REG_ERR0]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_MAP_REG_ERR0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_MAP_REG_ERR0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_MAP_REG_ERR0]

//>> GET_[XTS_REG_ERR_HOLD_MAP_REG_ERR0]
static inline bool GET_XTS_REG_ERR_HOLD_MAP_REG_ERR0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_MAP_REG_ERR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_MAP_REG_ERR0]

//>> SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR1]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_MAP_REG_ERR1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_MAP_REG_ERR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR1]

//>> SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR1]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_MAP_REG_ERR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_MAP_REG_ERR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR1]

//>> SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR1]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_MAP_REG_ERR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_MAP_REG_ERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_MAP_REG_ERR1]

//>> CLEAR_[XTS_REG_ERR_HOLD_MAP_REG_ERR1]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_MAP_REG_ERR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_MAP_REG_ERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_MAP_REG_ERR1]

//>> GET_[XTS_REG_ERR_HOLD_MAP_REG_ERR1]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_MAP_REG_ERR1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_MAP_REG_ERR1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_MAP_REG_ERR1]

//>> GET_[XTS_REG_ERR_HOLD_MAP_REG_ERR1]
static inline bool GET_XTS_REG_ERR_HOLD_MAP_REG_ERR1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_MAP_REG_ERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_MAP_REG_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_MAP_REG_ERR1]

//>> SET_[XTS_REG_ERR_HOLD_ATR_MISS_IRQ]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_ATR_MISS_IRQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_ATR_MISS_IRQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_MISS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_ATR_MISS_IRQ]

//>> SET_[XTS_REG_ERR_HOLD_ATR_MISS_IRQ]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_ATR_MISS_IRQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_HOLD_ATR_MISS_IRQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_MISS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_ATR_MISS_IRQ]

//>> SET_[XTS_REG_ERR_HOLD_ATR_MISS_IRQ]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_HOLD_ATR_MISS_IRQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.setBit<XTS_REG_ERR_HOLD_ATR_MISS_IRQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_MISS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_ERR_HOLD_ATR_MISS_IRQ]

//>> CLEAR_[XTS_REG_ERR_HOLD_ATR_MISS_IRQ]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ERR_HOLD_ATR_MISS_IRQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return o_data.clearBit<XTS_REG_ERR_HOLD_ATR_MISS_IRQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_MISS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_ERR_HOLD_ATR_MISS_IRQ]

//>> GET_[XTS_REG_ERR_HOLD_ATR_MISS_IRQ]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_HOLD_ATR_MISS_IRQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.extractToRight<XTS_REG_ERR_HOLD_ATR_MISS_IRQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_MISS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_ATR_MISS_IRQ]

//>> GET_[XTS_REG_ERR_HOLD_ATR_MISS_IRQ]
static inline bool GET_XTS_REG_ERR_HOLD_ATR_MISS_IRQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_HOLD));
#endif
    return i_data.getBit<XTS_REG_ERR_HOLD_ATR_MISS_IRQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_ERR_HOLD_ATR_MISS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_ERR_HOLD_ATR_MISS_IRQ]

//>> PREP_[XTS_REG_CONFIG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XTS_REG_CONFIG2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XTS_REG_CONFIG2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[XTS_REG_CONFIG2]

//>> GET_[XTS_REG_CONFIG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XTS_REG_CONFIG2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XTS_REG_CONFIG2;
#endif
    return fapi2::getScom(i_target, XTS_REG_CONFIG2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[XTS_REG_CONFIG2]

//>> PUT_[XTS_REG_CONFIG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XTS_REG_CONFIG2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return fapi2::putScom(i_target, XTS_REG_CONFIG2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[XTS_REG_CONFIG2]


//>> SET_[XTS_REG_CONFIG2_PERF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_ENABLE]

//>> SET_[XTS_REG_CONFIG2_PERF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_ENABLE]

//>> SET_[XTS_REG_CONFIG2_PERF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.setBit<XTS_REG_CONFIG2_PERF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_ENABLE]

//>> CLEAR_[XTS_REG_CONFIG2_PERF_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_CONFIG2_PERF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.clearBit<XTS_REG_CONFIG2_PERF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_CONFIG2_PERF_ENABLE]

//>> GET_[XTS_REG_CONFIG2_PERF_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG2_PERF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG2_PERF_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_PERF_ENABLE]

//>> GET_[XTS_REG_CONFIG2_PERF_ENABLE]
static inline bool GET_XTS_REG_CONFIG2_PERF_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.getBit<XTS_REG_CONFIG2_PERF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_PERF_ENABLE]

//>> SET_[XTS_REG_CONFIG2_PERF_RESETMODE]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_RESETMODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_RESETMODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_RESETMODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_RESETMODE]

//>> SET_[XTS_REG_CONFIG2_PERF_RESETMODE]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_RESETMODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_RESETMODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_RESETMODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_RESETMODE]

//>> SET_[XTS_REG_CONFIG2_PERF_RESETMODE]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_RESETMODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.setBit<XTS_REG_CONFIG2_PERF_RESETMODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_RESETMODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_RESETMODE]

//>> CLEAR_[XTS_REG_CONFIG2_PERF_RESETMODE]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_CONFIG2_PERF_RESETMODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.clearBit<XTS_REG_CONFIG2_PERF_RESETMODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_RESETMODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_CONFIG2_PERF_RESETMODE]

//>> GET_[XTS_REG_CONFIG2_PERF_RESETMODE]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG2_PERF_RESETMODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG2_PERF_RESETMODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_RESETMODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_PERF_RESETMODE]

//>> GET_[XTS_REG_CONFIG2_PERF_RESETMODE]
static inline bool GET_XTS_REG_CONFIG2_PERF_RESETMODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.getBit<XTS_REG_CONFIG2_PERF_RESETMODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_RESETMODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_PERF_RESETMODE]

//>> SET_[XTS_REG_CONFIG2_PERF_FREEZEMODE]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_FREEZEMODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_FREEZEMODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_FREEZEMODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_FREEZEMODE]

//>> SET_[XTS_REG_CONFIG2_PERF_FREEZEMODE]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_FREEZEMODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_FREEZEMODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_FREEZEMODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_FREEZEMODE]

//>> SET_[XTS_REG_CONFIG2_PERF_FREEZEMODE]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_FREEZEMODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.setBit<XTS_REG_CONFIG2_PERF_FREEZEMODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_FREEZEMODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_FREEZEMODE]

//>> CLEAR_[XTS_REG_CONFIG2_PERF_FREEZEMODE]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_CONFIG2_PERF_FREEZEMODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.clearBit<XTS_REG_CONFIG2_PERF_FREEZEMODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_FREEZEMODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_CONFIG2_PERF_FREEZEMODE]

//>> GET_[XTS_REG_CONFIG2_PERF_FREEZEMODE]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG2_PERF_FREEZEMODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG2_PERF_FREEZEMODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_FREEZEMODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_PERF_FREEZEMODE]

//>> GET_[XTS_REG_CONFIG2_PERF_FREEZEMODE]
static inline bool GET_XTS_REG_CONFIG2_PERF_FREEZEMODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.getBit<XTS_REG_CONFIG2_PERF_FREEZEMODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_FREEZEMODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_PERF_FREEZEMODE]

//>> SET_[XTS_REG_CONFIG2_PERF_DISABLE_PMISC]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_DISABLE_PMISC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_DISABLE_PMISC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_DISABLE_PMISC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_DISABLE_PMISC]

//>> SET_[XTS_REG_CONFIG2_PERF_DISABLE_PMISC]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_DISABLE_PMISC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_DISABLE_PMISC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_DISABLE_PMISC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_DISABLE_PMISC]

//>> SET_[XTS_REG_CONFIG2_PERF_DISABLE_PMISC]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_DISABLE_PMISC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.setBit<XTS_REG_CONFIG2_PERF_DISABLE_PMISC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_DISABLE_PMISC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_DISABLE_PMISC]

//>> CLEAR_[XTS_REG_CONFIG2_PERF_DISABLE_PMISC]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_CONFIG2_PERF_DISABLE_PMISC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.clearBit<XTS_REG_CONFIG2_PERF_DISABLE_PMISC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_DISABLE_PMISC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_CONFIG2_PERF_DISABLE_PMISC]

//>> GET_[XTS_REG_CONFIG2_PERF_DISABLE_PMISC]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG2_PERF_DISABLE_PMISC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG2_PERF_DISABLE_PMISC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_DISABLE_PMISC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_PERF_DISABLE_PMISC]

//>> GET_[XTS_REG_CONFIG2_PERF_DISABLE_PMISC]
static inline bool GET_XTS_REG_CONFIG2_PERF_DISABLE_PMISC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.getBit<XTS_REG_CONFIG2_PERF_DISABLE_PMISC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_DISABLE_PMISC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_PERF_DISABLE_PMISC]

//>> SET_[XTS_REG_CONFIG2_PERF_PMISC_MODE]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_PMISC_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_PMISC_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_PMISC_MODE]

//>> SET_[XTS_REG_CONFIG2_PERF_PMISC_MODE]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_PMISC_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_PMISC_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_PMISC_MODE]

//>> SET_[XTS_REG_CONFIG2_PERF_PMISC_MODE]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_PMISC_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.setBit<XTS_REG_CONFIG2_PERF_PMISC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_PMISC_MODE]

//>> CLEAR_[XTS_REG_CONFIG2_PERF_PMISC_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_CONFIG2_PERF_PMISC_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.clearBit<XTS_REG_CONFIG2_PERF_PMISC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_CONFIG2_PERF_PMISC_MODE]

//>> GET_[XTS_REG_CONFIG2_PERF_PMISC_MODE]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG2_PERF_PMISC_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG2_PERF_PMISC_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_PERF_PMISC_MODE]

//>> GET_[XTS_REG_CONFIG2_PERF_PMISC_MODE]
static inline bool GET_XTS_REG_CONFIG2_PERF_PMISC_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.getBit<XTS_REG_CONFIG2_PERF_PMISC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_PERF_PMISC_MODE]

//>> SET_[XTS_REG_CONFIG2_PERF_CASCADE]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_CASCADE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_CASCADE,
           XTS_REG_CONFIG2_PERF_CASCADE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_CASCADE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_CASCADE]

//>> SET_[XTS_REG_CONFIG2_PERF_CASCADE]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_CASCADE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_CASCADE,
           XTS_REG_CONFIG2_PERF_CASCADE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_CASCADE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_CASCADE]

//>> GET_[XTS_REG_CONFIG2_PERF_CASCADE]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG2_PERF_CASCADE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG2_PERF_CASCADE,
           XTS_REG_CONFIG2_PERF_CASCADE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_CASCADE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_PERF_CASCADE]

//>> SET_[XTS_REG_CONFIG2_PERF_PRESCALE_C0]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_PRESCALE_C0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_PRESCALE_C0,
           XTS_REG_CONFIG2_PERF_PRESCALE_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_PRESCALE_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_PRESCALE_C0]

//>> SET_[XTS_REG_CONFIG2_PERF_PRESCALE_C0]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_PRESCALE_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_PRESCALE_C0,
           XTS_REG_CONFIG2_PERF_PRESCALE_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_PRESCALE_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_PRESCALE_C0]

//>> GET_[XTS_REG_CONFIG2_PERF_PRESCALE_C0]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG2_PERF_PRESCALE_C0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG2_PERF_PRESCALE_C0,
           XTS_REG_CONFIG2_PERF_PRESCALE_C0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_PRESCALE_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_PERF_PRESCALE_C0]

//>> SET_[XTS_REG_CONFIG2_PERF_PRESCALE_C1]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_PRESCALE_C1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_PRESCALE_C1,
           XTS_REG_CONFIG2_PERF_PRESCALE_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_PRESCALE_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_PRESCALE_C1]

//>> SET_[XTS_REG_CONFIG2_PERF_PRESCALE_C1]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_PRESCALE_C1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_PRESCALE_C1,
           XTS_REG_CONFIG2_PERF_PRESCALE_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_PRESCALE_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_PRESCALE_C1]

//>> GET_[XTS_REG_CONFIG2_PERF_PRESCALE_C1]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG2_PERF_PRESCALE_C1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG2_PERF_PRESCALE_C1,
           XTS_REG_CONFIG2_PERF_PRESCALE_C1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_PRESCALE_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_PERF_PRESCALE_C1]

//>> SET_[XTS_REG_CONFIG2_PERF_PRESCALE_C2]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_PRESCALE_C2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_PRESCALE_C2,
           XTS_REG_CONFIG2_PERF_PRESCALE_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_PRESCALE_C2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_PRESCALE_C2]

//>> SET_[XTS_REG_CONFIG2_PERF_PRESCALE_C2]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_PRESCALE_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_PRESCALE_C2,
           XTS_REG_CONFIG2_PERF_PRESCALE_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_PRESCALE_C2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_PRESCALE_C2]

//>> GET_[XTS_REG_CONFIG2_PERF_PRESCALE_C2]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG2_PERF_PRESCALE_C2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG2_PERF_PRESCALE_C2,
           XTS_REG_CONFIG2_PERF_PRESCALE_C2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_PRESCALE_C2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_PERF_PRESCALE_C2]

//>> SET_[XTS_REG_CONFIG2_PERF_PRESCALE_C3]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_PRESCALE_C3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_PRESCALE_C3,
           XTS_REG_CONFIG2_PERF_PRESCALE_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_PRESCALE_C3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_PRESCALE_C3]

//>> SET_[XTS_REG_CONFIG2_PERF_PRESCALE_C3]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_PRESCALE_C3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_PRESCALE_C3,
           XTS_REG_CONFIG2_PERF_PRESCALE_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_PRESCALE_C3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_PRESCALE_C3]

//>> GET_[XTS_REG_CONFIG2_PERF_PRESCALE_C3]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG2_PERF_PRESCALE_C3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG2_PERF_PRESCALE_C3,
           XTS_REG_CONFIG2_PERF_PRESCALE_C3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_PRESCALE_C3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_PERF_PRESCALE_C3]

//>> SET_[XTS_REG_CONFIG2_PERF_EVENT0]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_EVENT0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_EVENT0,
           XTS_REG_CONFIG2_PERF_EVENT0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_EVENT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_EVENT0]

//>> SET_[XTS_REG_CONFIG2_PERF_EVENT0]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_EVENT0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_EVENT0,
           XTS_REG_CONFIG2_PERF_EVENT0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_EVENT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_EVENT0]

//>> GET_[XTS_REG_CONFIG2_PERF_EVENT0]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG2_PERF_EVENT0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG2_PERF_EVENT0,
           XTS_REG_CONFIG2_PERF_EVENT0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_EVENT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_PERF_EVENT0]

//>> SET_[XTS_REG_CONFIG2_PERF_EVENT1]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_EVENT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_EVENT1,
           XTS_REG_CONFIG2_PERF_EVENT1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_EVENT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_EVENT1]

//>> SET_[XTS_REG_CONFIG2_PERF_EVENT1]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_EVENT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_EVENT1,
           XTS_REG_CONFIG2_PERF_EVENT1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_EVENT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_EVENT1]

//>> GET_[XTS_REG_CONFIG2_PERF_EVENT1]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG2_PERF_EVENT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG2_PERF_EVENT1,
           XTS_REG_CONFIG2_PERF_EVENT1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_EVENT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_PERF_EVENT1]

//>> SET_[XTS_REG_CONFIG2_PERF_EVENT2]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_EVENT2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_EVENT2,
           XTS_REG_CONFIG2_PERF_EVENT2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_EVENT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_EVENT2]

//>> SET_[XTS_REG_CONFIG2_PERF_EVENT2]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_EVENT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_EVENT2,
           XTS_REG_CONFIG2_PERF_EVENT2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_EVENT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_EVENT2]

//>> GET_[XTS_REG_CONFIG2_PERF_EVENT2]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG2_PERF_EVENT2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG2_PERF_EVENT2,
           XTS_REG_CONFIG2_PERF_EVENT2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_EVENT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_PERF_EVENT2]

//>> SET_[XTS_REG_CONFIG2_PERF_EVENT3]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_EVENT3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_EVENT3,
           XTS_REG_CONFIG2_PERF_EVENT3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_EVENT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_EVENT3]

//>> SET_[XTS_REG_CONFIG2_PERF_EVENT3]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_PERF_EVENT3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_PERF_EVENT3,
           XTS_REG_CONFIG2_PERF_EVENT3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_EVENT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_PERF_EVENT3]

//>> GET_[XTS_REG_CONFIG2_PERF_EVENT3]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG2_PERF_EVENT3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG2_PERF_EVENT3,
           XTS_REG_CONFIG2_PERF_EVENT3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_CONFIG2_PERF_EVENT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_PERF_EVENT3]

//>> SET_[XTS_REG_CONFIG2_RADDR_BND]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_RADDR_BND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_RADDR_BND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_CONFIG2_RADDR_BND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_RADDR_BND]

//>> SET_[XTS_REG_CONFIG2_RADDR_BND]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_RADDR_BND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_RADDR_BND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_CONFIG2_RADDR_BND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_RADDR_BND]

//>> SET_[XTS_REG_CONFIG2_RADDR_BND]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_RADDR_BND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.setBit<XTS_REG_CONFIG2_RADDR_BND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_CONFIG2_RADDR_BND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_RADDR_BND]

//>> CLEAR_[XTS_REG_CONFIG2_RADDR_BND]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_CONFIG2_RADDR_BND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.clearBit<XTS_REG_CONFIG2_RADDR_BND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_CONFIG2_RADDR_BND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_CONFIG2_RADDR_BND]

//>> GET_[XTS_REG_CONFIG2_RADDR_BND]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG2_RADDR_BND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG2_RADDR_BND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_CONFIG2_RADDR_BND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_RADDR_BND]

//>> GET_[XTS_REG_CONFIG2_RADDR_BND]
static inline bool GET_XTS_REG_CONFIG2_RADDR_BND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.getBit<XTS_REG_CONFIG2_RADDR_BND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_CONFIG2_RADDR_BND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_RADDR_BND]

//>> SET_[XTS_REG_CONFIG2_NO_FLUSH_ENA]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_NO_FLUSH_ENA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_NO_FLUSH_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_CONFIG2_NO_FLUSH_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_NO_FLUSH_ENA]

//>> SET_[XTS_REG_CONFIG2_NO_FLUSH_ENA]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_NO_FLUSH_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_NO_FLUSH_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_CONFIG2_NO_FLUSH_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_NO_FLUSH_ENA]

//>> SET_[XTS_REG_CONFIG2_NO_FLUSH_ENA]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_NO_FLUSH_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.setBit<XTS_REG_CONFIG2_NO_FLUSH_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_CONFIG2_NO_FLUSH_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_NO_FLUSH_ENA]

//>> CLEAR_[XTS_REG_CONFIG2_NO_FLUSH_ENA]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_CONFIG2_NO_FLUSH_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.clearBit<XTS_REG_CONFIG2_NO_FLUSH_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_CONFIG2_NO_FLUSH_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_CONFIG2_NO_FLUSH_ENA]

//>> GET_[XTS_REG_CONFIG2_NO_FLUSH_ENA]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG2_NO_FLUSH_ENA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG2_NO_FLUSH_ENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_CONFIG2_NO_FLUSH_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_NO_FLUSH_ENA]

//>> GET_[XTS_REG_CONFIG2_NO_FLUSH_ENA]
static inline bool GET_XTS_REG_CONFIG2_NO_FLUSH_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.getBit<XTS_REG_CONFIG2_NO_FLUSH_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_CONFIG2_NO_FLUSH_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_NO_FLUSH_ENA]

//>> SET_[XTS_REG_CONFIG2_MAP_ILOCK]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_MAP_ILOCK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_MAP_ILOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_CONFIG2_MAP_ILOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_MAP_ILOCK]

//>> SET_[XTS_REG_CONFIG2_MAP_ILOCK]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_MAP_ILOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_MAP_ILOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_CONFIG2_MAP_ILOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_MAP_ILOCK]

//>> SET_[XTS_REG_CONFIG2_MAP_ILOCK]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_MAP_ILOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.setBit<XTS_REG_CONFIG2_MAP_ILOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_CONFIG2_MAP_ILOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_MAP_ILOCK]

//>> CLEAR_[XTS_REG_CONFIG2_MAP_ILOCK]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_CONFIG2_MAP_ILOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.clearBit<XTS_REG_CONFIG2_MAP_ILOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_CONFIG2_MAP_ILOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_CONFIG2_MAP_ILOCK]

//>> GET_[XTS_REG_CONFIG2_MAP_ILOCK]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG2_MAP_ILOCK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG2_MAP_ILOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_CONFIG2_MAP_ILOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_MAP_ILOCK]

//>> GET_[XTS_REG_CONFIG2_MAP_ILOCK]
static inline bool GET_XTS_REG_CONFIG2_MAP_ILOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.getBit<XTS_REG_CONFIG2_MAP_ILOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_CONFIG2_MAP_ILOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_MAP_ILOCK]

//>> SET_[XTS_REG_CONFIG2_ADJUST_PLS_RATE]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_ADJUST_PLS_RATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_ADJUST_PLS_RATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_CONFIG2_ADJUST_PLS_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_ADJUST_PLS_RATE]

//>> SET_[XTS_REG_CONFIG2_ADJUST_PLS_RATE]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_ADJUST_PLS_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_ADJUST_PLS_RATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_CONFIG2_ADJUST_PLS_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_ADJUST_PLS_RATE]

//>> SET_[XTS_REG_CONFIG2_ADJUST_PLS_RATE]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_ADJUST_PLS_RATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.setBit<XTS_REG_CONFIG2_ADJUST_PLS_RATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_CONFIG2_ADJUST_PLS_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_ADJUST_PLS_RATE]

//>> CLEAR_[XTS_REG_CONFIG2_ADJUST_PLS_RATE]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_CONFIG2_ADJUST_PLS_RATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.clearBit<XTS_REG_CONFIG2_ADJUST_PLS_RATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_CONFIG2_ADJUST_PLS_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_CONFIG2_ADJUST_PLS_RATE]

//>> GET_[XTS_REG_CONFIG2_ADJUST_PLS_RATE]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG2_ADJUST_PLS_RATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG2_ADJUST_PLS_RATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_CONFIG2_ADJUST_PLS_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_ADJUST_PLS_RATE]

//>> GET_[XTS_REG_CONFIG2_ADJUST_PLS_RATE]
static inline bool GET_XTS_REG_CONFIG2_ADJUST_PLS_RATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.getBit<XTS_REG_CONFIG2_ADJUST_PLS_RATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_CONFIG2_ADJUST_PLS_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_ADJUST_PLS_RATE]

//>> SET_[XTS_REG_CONFIG2_TLBIE_HV_EN]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_TLBIE_HV_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_TLBIE_HV_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_CONFIG2_TLBIE_HV_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_TLBIE_HV_EN]

//>> SET_[XTS_REG_CONFIG2_TLBIE_HV_EN]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_TLBIE_HV_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_TLBIE_HV_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_CONFIG2_TLBIE_HV_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_TLBIE_HV_EN]

//>> SET_[XTS_REG_CONFIG2_TLBIE_HV_EN]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_TLBIE_HV_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.setBit<XTS_REG_CONFIG2_TLBIE_HV_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_CONFIG2_TLBIE_HV_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_TLBIE_HV_EN]

//>> CLEAR_[XTS_REG_CONFIG2_TLBIE_HV_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_CONFIG2_TLBIE_HV_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.clearBit<XTS_REG_CONFIG2_TLBIE_HV_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_CONFIG2_TLBIE_HV_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_CONFIG2_TLBIE_HV_EN]

//>> GET_[XTS_REG_CONFIG2_TLBIE_HV_EN]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG2_TLBIE_HV_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG2_TLBIE_HV_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_CONFIG2_TLBIE_HV_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_TLBIE_HV_EN]

//>> GET_[XTS_REG_CONFIG2_TLBIE_HV_EN]
static inline bool GET_XTS_REG_CONFIG2_TLBIE_HV_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.getBit<XTS_REG_CONFIG2_TLBIE_HV_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_CONFIG2_TLBIE_HV_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_TLBIE_HV_EN]

//>> SET_[XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN]

//>> SET_[XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN]

//>> SET_[XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.setBit<XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN]

//>> CLEAR_[XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.clearBit<XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN]

//>> GET_[XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN]

//>> GET_[XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN]
static inline bool GET_XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.getBit<XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_TLBIE_PACING_CNT_EN]

//>> SET_[XTS_REG_CONFIG2_XSL2_ENA]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_XSL2_ENA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_XSL2_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_CONFIG2_XSL2_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_XSL2_ENA]

//>> SET_[XTS_REG_CONFIG2_XSL2_ENA]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_XSL2_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_XSL2_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_CONFIG2_XSL2_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_XSL2_ENA]

//>> SET_[XTS_REG_CONFIG2_XSL2_ENA]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_XSL2_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.setBit<XTS_REG_CONFIG2_XSL2_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XTS_REG_CONFIG2_XSL2_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_XSL2_ENA]

//>> CLEAR_[XTS_REG_CONFIG2_XSL2_ENA]
static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_CONFIG2_XSL2_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.clearBit<XTS_REG_CONFIG2_XSL2_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XTS_REG_CONFIG2_XSL2_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XTS_REG_CONFIG2_XSL2_ENA]

//>> GET_[XTS_REG_CONFIG2_XSL2_ENA]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG2_XSL2_ENA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG2_XSL2_ENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_CONFIG2_XSL2_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_XSL2_ENA]

//>> GET_[XTS_REG_CONFIG2_XSL2_ENA]
static inline bool GET_XTS_REG_CONFIG2_XSL2_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.getBit<XTS_REG_CONFIG2_XSL2_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XTS_REG_CONFIG2_XSL2_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_XSL2_ENA]

//>> SET_[XTS_REG_CONFIG2_ATSD_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_ATSD_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_ATSD_TIMEOUT,
           XTS_REG_CONFIG2_ATSD_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_CONFIG2_ATSD_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_ATSD_TIMEOUT]

//>> SET_[XTS_REG_CONFIG2_ATSD_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_ATSD_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_ATSD_TIMEOUT,
           XTS_REG_CONFIG2_ATSD_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_CONFIG2_ATSD_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_ATSD_TIMEOUT]

//>> GET_[XTS_REG_CONFIG2_ATSD_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG2_ATSD_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG2_ATSD_TIMEOUT,
           XTS_REG_CONFIG2_ATSD_TIMEOUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_CONFIG2_ATSD_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_ATSD_TIMEOUT]

//>> SET_[XTS_REG_CONFIG2_ATR_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_ATR_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_ATR_TIMEOUT,
           XTS_REG_CONFIG2_ATR_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_CONFIG2_ATR_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_ATR_TIMEOUT]

//>> SET_[XTS_REG_CONFIG2_ATR_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG2_ATR_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG2_ATR_TIMEOUT,
           XTS_REG_CONFIG2_ATR_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_CONFIG2_ATR_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_CONFIG2_ATR_TIMEOUT]

//>> GET_[XTS_REG_CONFIG2_ATR_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG2_ATR_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG2));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG2_ATR_TIMEOUT,
           XTS_REG_CONFIG2_ATR_TIMEOUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_CONFIG2_ATR_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_CONFIG2_ATR_TIMEOUT]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
