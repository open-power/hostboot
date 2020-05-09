/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omic/reg00006.H $         */
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

#ifndef __OMIC_REG00006_H_
#define __OMIC_REG00006_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


//>> PREP_[CTL_REGS_RX_CNTL5_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_CNTL5_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_CNTL5_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CTL_REGS_RX_CNTL5_PG]

//>> GET_[CTL_REGS_RX_CNTL5_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_CNTL5_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_CNTL5_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_CNTL5_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CTL_REGS_RX_CNTL5_PG]

//>> PUT_[CTL_REGS_RX_CNTL5_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_CNTL5_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_CNTL5_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CTL_REGS_RX_CNTL5_PG]


//>> SET_[CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT]

//>> SET_[CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT]

//>> SET_[CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT]

//>> CLEAR_[CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT]

//>> GET_[CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT]

//>> GET_[CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT]
static inline bool GET_CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT]

//>> SET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD]

//>> SET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD]

//>> SET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD]

//>> CLEAR_[CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD]

//>> GET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD]

//>> GET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD]
static inline bool GET_CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD]

//>> SET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD]

//>> SET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD]

//>> SET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD]

//>> CLEAR_[CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD]

//>> GET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD]

//>> GET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD]
static inline bool GET_CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD]

//>> SET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO]

//>> SET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO]

//>> SET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO]

//>> CLEAR_[CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO]

//>> GET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO]

//>> GET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO]
static inline bool GET_CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO]

//>> SET_[CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL]

//>> SET_[CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL]

//>> SET_[CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL]

//>> CLEAR_[CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL]

//>> GET_[CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL]

//>> GET_[CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL]
static inline bool GET_CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL]

//>> PREP_[CTL_REGS_RX_MODE16_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_MODE16_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE16_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CTL_REGS_RX_MODE16_PG]

//>> GET_[CTL_REGS_RX_MODE16_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_MODE16_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE16_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_MODE16_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CTL_REGS_RX_MODE16_PG]

//>> PUT_[CTL_REGS_RX_MODE16_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_MODE16_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_MODE16_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CTL_REGS_RX_MODE16_PG]


//>> SET_[CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0,
           CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0]

//>> SET_[CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0,
           CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0]

//>> GET_[CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0,
           CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0]

//>> SET_[CTL_REGS_RX_MODE16_PG_THRESH1]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE16_PG_THRESH1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE16_PG_THRESH1,
           CTL_REGS_RX_MODE16_PG_THRESH1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE16_PG_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE16_PG_THRESH1]

//>> SET_[CTL_REGS_RX_MODE16_PG_THRESH1]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE16_PG_THRESH1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE16_PG_THRESH1,
           CTL_REGS_RX_MODE16_PG_THRESH1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE16_PG_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE16_PG_THRESH1]

//>> GET_[CTL_REGS_RX_MODE16_PG_THRESH1]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE16_PG_THRESH1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE16_PG_THRESH1,
           CTL_REGS_RX_MODE16_PG_THRESH1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE16_PG_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE16_PG_THRESH1]

//>> SET_[CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1,
           CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1]

//>> SET_[CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1,
           CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1]

//>> GET_[CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1,
           CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1]

//>> SET_[CTL_REGS_RX_MODE16_PG_THRESH2]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE16_PG_THRESH2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE16_PG_THRESH2,
           CTL_REGS_RX_MODE16_PG_THRESH2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE16_PG_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE16_PG_THRESH2]

//>> SET_[CTL_REGS_RX_MODE16_PG_THRESH2]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE16_PG_THRESH2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE16_PG_THRESH2,
           CTL_REGS_RX_MODE16_PG_THRESH2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE16_PG_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE16_PG_THRESH2]

//>> GET_[CTL_REGS_RX_MODE16_PG_THRESH2]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE16_PG_THRESH2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE16_PG_THRESH2,
           CTL_REGS_RX_MODE16_PG_THRESH2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE16_PG_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE16_PG_THRESH2]

//>> PREP_[CTL_REGS_RX_MODE3_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_MODE3_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE3_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CTL_REGS_RX_MODE3_PG]

//>> GET_[CTL_REGS_RX_MODE3_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_MODE3_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE3_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_MODE3_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CTL_REGS_RX_MODE3_PG]

//>> PUT_[CTL_REGS_RX_MODE3_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_MODE3_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_MODE3_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CTL_REGS_RX_MODE3_PG]


//>> SET_[CTL_REGS_RX_MODE3_PG_FILTER_DEPTH]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_FILTER_DEPTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE3_PG_FILTER_DEPTH,
           CTL_REGS_RX_MODE3_PG_FILTER_DEPTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE3_PG_FILTER_DEPTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE3_PG_FILTER_DEPTH]

//>> SET_[CTL_REGS_RX_MODE3_PG_FILTER_DEPTH]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_FILTER_DEPTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE3_PG_FILTER_DEPTH,
           CTL_REGS_RX_MODE3_PG_FILTER_DEPTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE3_PG_FILTER_DEPTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE3_PG_FILTER_DEPTH]

//>> GET_[CTL_REGS_RX_MODE3_PG_FILTER_DEPTH]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE3_PG_FILTER_DEPTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE3_PG_FILTER_DEPTH,
           CTL_REGS_RX_MODE3_PG_FILTER_DEPTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE3_PG_FILTER_DEPTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE3_PG_FILTER_DEPTH]

//>> SET_[CTL_REGS_RX_MODE3_PG_THRESH4]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_THRESH4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE3_PG_THRESH4,
           CTL_REGS_RX_MODE3_PG_THRESH4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE3_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE3_PG_THRESH4]

//>> SET_[CTL_REGS_RX_MODE3_PG_THRESH4]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_THRESH4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE3_PG_THRESH4,
           CTL_REGS_RX_MODE3_PG_THRESH4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE3_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE3_PG_THRESH4]

//>> GET_[CTL_REGS_RX_MODE3_PG_THRESH4]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE3_PG_THRESH4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE3_PG_THRESH4,
           CTL_REGS_RX_MODE3_PG_THRESH4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE3_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE3_PG_THRESH4]

//>> SET_[CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG,
           CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG]

//>> SET_[CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG,
           CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG]

//>> GET_[CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG,
           CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG]

//>> SET_[CTL_REGS_RX_MODE3_PG_DATA_SRC]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_DATA_SRC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE3_PG_DATA_SRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE3_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE3_PG_DATA_SRC]

//>> SET_[CTL_REGS_RX_MODE3_PG_DATA_SRC]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_DATA_SRC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE3_PG_DATA_SRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE3_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE3_PG_DATA_SRC]

//>> SET_[CTL_REGS_RX_MODE3_PG_DATA_SRC]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_DATA_SRC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_MODE3_PG_DATA_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_RX_MODE3_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE3_PG_DATA_SRC]

//>> CLEAR_[CTL_REGS_RX_MODE3_PG_DATA_SRC]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_MODE3_PG_DATA_SRC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_MODE3_PG_DATA_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_RX_MODE3_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_RX_MODE3_PG_DATA_SRC]

//>> GET_[CTL_REGS_RX_MODE3_PG_DATA_SRC]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE3_PG_DATA_SRC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE3_PG_DATA_SRC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE3_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE3_PG_DATA_SRC]

//>> GET_[CTL_REGS_RX_MODE3_PG_DATA_SRC]
static inline bool GET_CTL_REGS_RX_MODE3_PG_DATA_SRC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_MODE3_PG_DATA_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_RX_MODE3_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE3_PG_DATA_SRC]

//>> SET_[CTL_REGS_RX_MODE3_PG_FORMAT]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_FORMAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE3_PG_FORMAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE3_PG_FORMAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE3_PG_FORMAT]

//>> SET_[CTL_REGS_RX_MODE3_PG_FORMAT]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_FORMAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE3_PG_FORMAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE3_PG_FORMAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE3_PG_FORMAT]

//>> SET_[CTL_REGS_RX_MODE3_PG_FORMAT]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_FORMAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_MODE3_PG_FORMAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_RX_MODE3_PG_FORMAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE3_PG_FORMAT]

//>> CLEAR_[CTL_REGS_RX_MODE3_PG_FORMAT]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_MODE3_PG_FORMAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_MODE3_PG_FORMAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_RX_MODE3_PG_FORMAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_RX_MODE3_PG_FORMAT]

//>> GET_[CTL_REGS_RX_MODE3_PG_FORMAT]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE3_PG_FORMAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE3_PG_FORMAT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE3_PG_FORMAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE3_PG_FORMAT]

//>> GET_[CTL_REGS_RX_MODE3_PG_FORMAT]
static inline bool GET_CTL_REGS_RX_MODE3_PG_FORMAT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_MODE3_PG_FORMAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_RX_MODE3_PG_FORMAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE3_PG_FORMAT]

//>> SET_[CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH]

//>> SET_[CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH]

//>> SET_[CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH]

//>> CLEAR_[CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH]

//>> GET_[CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH]

//>> GET_[CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH]
static inline bool GET_CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH]

//>> PREP_[CTL_REGS_RX_FIR1_ERROR_INJECT_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_FIR1_ERROR_INJECT_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_FIR1_ERROR_INJECT_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CTL_REGS_RX_FIR1_ERROR_INJECT_PG]

//>> GET_[CTL_REGS_RX_FIR1_ERROR_INJECT_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_FIR1_ERROR_INJECT_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_FIR1_ERROR_INJECT_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_FIR1_ERROR_INJECT_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CTL_REGS_RX_FIR1_ERROR_INJECT_PG]

//>> PUT_[CTL_REGS_RX_FIR1_ERROR_INJECT_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_FIR1_ERROR_INJECT_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_FIR1_ERROR_INJECT_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_FIR1_ERROR_INJECT_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CTL_REGS_RX_FIR1_ERROR_INJECT_PG]


//>> SET_[CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_FIR1_ERROR_INJECT_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ,
           CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ]

//>> SET_[CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_FIR1_ERROR_INJECT_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ,
           CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ]

//>> GET_[CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_FIR1_ERROR_INJECT_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ,
           CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ]

//>> PREP_[CTL_REGS_TX_CNTL4_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_TX_CNTL4_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_CNTL4_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CTL_REGS_TX_CNTL4_PG]

//>> GET_[CTL_REGS_TX_CNTL4_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_TX_CNTL4_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_CNTL4_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_TX_CNTL4_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CTL_REGS_TX_CNTL4_PG]

//>> PUT_[CTL_REGS_TX_CNTL4_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_TX_CNTL4_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_TX_CNTL4_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CTL_REGS_TX_CNTL4_PG]


//>> SET_[CTL_REGS_TX_CNTL4_PG_DAC_CNTL]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL4_PG_DAC_CNTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL4_PG_DAC_CNTL,
           CTL_REGS_TX_CNTL4_PG_DAC_CNTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_DAC_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_CNTL4_PG_DAC_CNTL]

//>> SET_[CTL_REGS_TX_CNTL4_PG_DAC_CNTL]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL4_PG_DAC_CNTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL4_PG_DAC_CNTL,
           CTL_REGS_TX_CNTL4_PG_DAC_CNTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_DAC_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_CNTL4_PG_DAC_CNTL]

//>> GET_[CTL_REGS_TX_CNTL4_PG_DAC_CNTL]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_CNTL4_PG_DAC_CNTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_CNTL4_PG_DAC_CNTL,
           CTL_REGS_TX_CNTL4_PG_DAC_CNTL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_DAC_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_CNTL4_PG_DAC_CNTL]

//>> SET_[CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE]

//>> SET_[CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE]

//>> SET_[CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.setBit<CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE]

//>> CLEAR_[CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.clearBit<CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE]

//>> GET_[CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE]

//>> GET_[CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE]
static inline bool GET_CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return i_data.getBit<CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE]

//>> SET_[CTL_REGS_TX_CNTL4_PG_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL4_PG_PHASE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_CNTL4_PG_PHASE_SEL]

//>> SET_[CTL_REGS_TX_CNTL4_PG_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL4_PG_PHASE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_CNTL4_PG_PHASE_SEL]

//>> SET_[CTL_REGS_TX_CNTL4_PG_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.setBit<CTL_REGS_TX_CNTL4_PG_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_CNTL4_PG_PHASE_SEL]

//>> CLEAR_[CTL_REGS_TX_CNTL4_PG_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.clearBit<CTL_REGS_TX_CNTL4_PG_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_TX_CNTL4_PG_PHASE_SEL]

//>> GET_[CTL_REGS_TX_CNTL4_PG_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_CNTL4_PG_PHASE_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_CNTL4_PG_PHASE_SEL]

//>> GET_[CTL_REGS_TX_CNTL4_PG_PHASE_SEL]
static inline bool GET_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return i_data.getBit<CTL_REGS_TX_CNTL4_PG_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_CNTL4_PG_PHASE_SEL]

//>> PREP_[DATASM_REGS_RX_CNT14_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNT14_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT14_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DATASM_REGS_RX_CNT14_PG]

//>> GET_[DATASM_REGS_RX_CNT14_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNT14_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT14_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNT14_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DATASM_REGS_RX_CNT14_PG]

//>> PUT_[DATASM_REGS_RX_CNT14_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNT14_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT14_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNT14_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DATASM_REGS_RX_CNT14_PG]


//>> SET_[DATASM_REGS_RX_CNT14_PG_0_SEL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT14_PG_0_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT14_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT14_PG_0_SEL,
           DATASM_REGS_RX_CNT14_PG_0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_CNT14_PG_0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNT14_PG_0_SEL]

//>> SET_[DATASM_REGS_RX_CNT14_PG_0_SEL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT14_PG_0_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT14_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT14_PG_0_SEL,
           DATASM_REGS_RX_CNT14_PG_0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_CNT14_PG_0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNT14_PG_0_SEL]

//>> GET_[DATASM_REGS_RX_CNT14_PG_0_SEL]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT14_PG_0_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT14_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT14_PG_0_SEL,
           DATASM_REGS_RX_CNT14_PG_0_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_CNT14_PG_0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_CNT14_PG_0_SEL]

//>> SET_[DATASM_REGS_RX_CNT14_PG_1_SEL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT14_PG_1_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT14_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT14_PG_1_SEL,
           DATASM_REGS_RX_CNT14_PG_1_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_CNT14_PG_1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNT14_PG_1_SEL]

//>> SET_[DATASM_REGS_RX_CNT14_PG_1_SEL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT14_PG_1_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT14_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT14_PG_1_SEL,
           DATASM_REGS_RX_CNT14_PG_1_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_CNT14_PG_1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNT14_PG_1_SEL]

//>> GET_[DATASM_REGS_RX_CNT14_PG_1_SEL]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT14_PG_1_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT14_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT14_PG_1_SEL,
           DATASM_REGS_RX_CNT14_PG_1_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_CNT14_PG_1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_CNT14_PG_1_SEL]

//>> SET_[DATASM_REGS_RX_CNT14_PG_2_SEL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT14_PG_2_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT14_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT14_PG_2_SEL,
           DATASM_REGS_RX_CNT14_PG_2_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_CNT14_PG_2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNT14_PG_2_SEL]

//>> SET_[DATASM_REGS_RX_CNT14_PG_2_SEL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT14_PG_2_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT14_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT14_PG_2_SEL,
           DATASM_REGS_RX_CNT14_PG_2_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_CNT14_PG_2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNT14_PG_2_SEL]

//>> GET_[DATASM_REGS_RX_CNT14_PG_2_SEL]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT14_PG_2_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT14_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT14_PG_2_SEL,
           DATASM_REGS_RX_CNT14_PG_2_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_CNT14_PG_2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_CNT14_PG_2_SEL]

//>> PREP_[DATASM_REGS_RX_CNT24_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNT24_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT24_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DATASM_REGS_RX_CNT24_PG]

//>> GET_[DATASM_REGS_RX_CNT24_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNT24_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT24_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNT24_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DATASM_REGS_RX_CNT24_PG]

//>> PUT_[DATASM_REGS_RX_CNT24_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNT24_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT24_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNT24_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DATASM_REGS_RX_CNT24_PG]


//>> SET_[DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT24_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23,
           DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23]

//>> SET_[DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT24_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23,
           DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23]

//>> GET_[DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT24_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23,
           DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23]

//>> PREP_[DATASM_REGS_RX_CNTL7_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNTL7_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNTL7_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DATASM_REGS_RX_CNTL7_PG]

//>> GET_[DATASM_REGS_RX_CNTL7_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNTL7_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNTL7_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNTL7_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DATASM_REGS_RX_CNTL7_PG]

//>> PUT_[DATASM_REGS_RX_CNTL7_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNTL7_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL7_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNTL7_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DATASM_REGS_RX_CNTL7_PG]


//>> SET_[DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL7_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15,
           DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15]

//>> SET_[DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL7_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15,
           DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15]

//>> GET_[DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL7_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15,
           DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15]

//>> PREP_[DATASM_REGS_RX_STAT19_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_STAT19_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT19_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DATASM_REGS_RX_STAT19_PG]

//>> GET_[DATASM_REGS_RX_STAT19_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_STAT19_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT19_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_STAT19_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT19_PG]

//>> PUT_[DATASM_REGS_RX_STAT19_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_STAT19_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT19_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_STAT19_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DATASM_REGS_RX_STAT19_PG]


//>> SET_[DATASM_REGS_RX_STAT19_PG_RX_DL_PHY_RUN_LANE_0_15_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT19_PG_RX_DL_PHY_RUN_LANE_0_15_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT19_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT19_PG_RX_DL_PHY_RUN_LANE_0_15_RO_SIGNAL,
           DATASM_REGS_RX_STAT19_PG_RX_DL_PHY_RUN_LANE_0_15_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_STAT19_PG_RX_DL_PHY_RUN_LANE_0_15_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT19_PG_RX_DL_PHY_RUN_LANE_0_15_RO_SIGNAL]

//>> SET_[DATASM_REGS_RX_STAT19_PG_RX_DL_PHY_RUN_LANE_0_15_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT19_PG_RX_DL_PHY_RUN_LANE_0_15_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT19_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT19_PG_RX_DL_PHY_RUN_LANE_0_15_RO_SIGNAL,
           DATASM_REGS_RX_STAT19_PG_RX_DL_PHY_RUN_LANE_0_15_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_STAT19_PG_RX_DL_PHY_RUN_LANE_0_15_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT19_PG_RX_DL_PHY_RUN_LANE_0_15_RO_SIGNAL]

//>> GET_[DATASM_REGS_RX_STAT19_PG_RX_DL_PHY_RUN_LANE_0_15_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_STAT19_PG_RX_DL_PHY_RUN_LANE_0_15_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT19_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_STAT19_PG_RX_DL_PHY_RUN_LANE_0_15_RO_SIGNAL,
           DATASM_REGS_RX_STAT19_PG_RX_DL_PHY_RUN_LANE_0_15_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_STAT19_PG_RX_DL_PHY_RUN_LANE_0_15_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT19_PG_RX_DL_PHY_RUN_LANE_0_15_RO_SIGNAL]

//>> PREP_[DATASM_REGS_RX_STAT29_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_STAT29_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT29_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DATASM_REGS_RX_STAT29_PG]

//>> GET_[DATASM_REGS_RX_STAT29_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_STAT29_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT29_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_STAT29_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT29_PG]

//>> PUT_[DATASM_REGS_RX_STAT29_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_STAT29_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT29_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_STAT29_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DATASM_REGS_RX_STAT29_PG]


//>> SET_[DATASM_REGS_RX_STAT29_PG_RX_VTAL_EARLY_RESULT_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT29_PG_RX_VTAL_EARLY_RESULT_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT29_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT29_PG_RX_VTAL_EARLY_RESULT_RO_SIGNAL,
           DATASM_REGS_RX_STAT29_PG_RX_VTAL_EARLY_RESULT_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_STAT29_PG_RX_VTAL_EARLY_RESULT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT29_PG_RX_VTAL_EARLY_RESULT_RO_SIGNAL]

//>> SET_[DATASM_REGS_RX_STAT29_PG_RX_VTAL_EARLY_RESULT_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT29_PG_RX_VTAL_EARLY_RESULT_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT29_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT29_PG_RX_VTAL_EARLY_RESULT_RO_SIGNAL,
           DATASM_REGS_RX_STAT29_PG_RX_VTAL_EARLY_RESULT_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_STAT29_PG_RX_VTAL_EARLY_RESULT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT29_PG_RX_VTAL_EARLY_RESULT_RO_SIGNAL]

//>> GET_[DATASM_REGS_RX_STAT29_PG_RX_VTAL_EARLY_RESULT_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_STAT29_PG_RX_VTAL_EARLY_RESULT_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT29_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_STAT29_PG_RX_VTAL_EARLY_RESULT_RO_SIGNAL,
           DATASM_REGS_RX_STAT29_PG_RX_VTAL_EARLY_RESULT_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_STAT29_PG_RX_VTAL_EARLY_RESULT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT29_PG_RX_VTAL_EARLY_RESULT_RO_SIGNAL]

//>> PREP_[DATASM_REGS_RX_STAT7_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_STAT7_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT7_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DATASM_REGS_RX_STAT7_PG]

//>> GET_[DATASM_REGS_RX_STAT7_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_STAT7_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT7_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_STAT7_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT7_PG]

//>> PUT_[DATASM_REGS_RX_STAT7_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_STAT7_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT7_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_STAT7_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DATASM_REGS_RX_STAT7_PG]


//>> SET_[DATASM_REGS_RX_STAT7_PG_RX_SERVO_STATUS1_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT7_PG_RX_SERVO_STATUS1_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT7_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT7_PG_RX_SERVO_STATUS1_RO_SIGNAL,
           DATASM_REGS_RX_STAT7_PG_RX_SERVO_STATUS1_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_STAT7_PG_RX_SERVO_STATUS1_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT7_PG_RX_SERVO_STATUS1_RO_SIGNAL]

//>> SET_[DATASM_REGS_RX_STAT7_PG_RX_SERVO_STATUS1_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT7_PG_RX_SERVO_STATUS1_RO_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT7_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT7_PG_RX_SERVO_STATUS1_RO_SIGNAL,
           DATASM_REGS_RX_STAT7_PG_RX_SERVO_STATUS1_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_STAT7_PG_RX_SERVO_STATUS1_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT7_PG_RX_SERVO_STATUS1_RO_SIGNAL]

//>> GET_[DATASM_REGS_RX_STAT7_PG_RX_SERVO_STATUS1_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_STAT7_PG_RX_SERVO_STATUS1_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT7_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_STAT7_PG_RX_SERVO_STATUS1_RO_SIGNAL,
           DATASM_REGS_RX_STAT7_PG_RX_SERVO_STATUS1_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_STAT7_PG_RX_SERVO_STATUS1_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT7_PG_RX_SERVO_STATUS1_RO_SIGNAL]

//>> PREP_[TX_CTL_SM_REGS_CTLSM_CNTL5_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX_CTL_SM_REGS_CTLSM_CNTL5_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_CNTL5_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TX_CTL_SM_REGS_CTLSM_CNTL5_PG]

//>> GET_[TX_CTL_SM_REGS_CTLSM_CNTL5_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX_CTL_SM_REGS_CTLSM_CNTL5_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_CNTL5_PG;
#endif
    return fapi2::getScom(i_target, TX_CTL_SM_REGS_CTLSM_CNTL5_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TX_CTL_SM_REGS_CTLSM_CNTL5_PG]

//>> PUT_[TX_CTL_SM_REGS_CTLSM_CNTL5_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX_CTL_SM_REGS_CTLSM_CNTL5_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL5_PG));
#endif
    return fapi2::putScom(i_target, TX_CTL_SM_REGS_CTLSM_CNTL5_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TX_CTL_SM_REGS_CTLSM_CNTL5_PG]


//>> SET_[TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL5_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15,
           TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15]

//>> SET_[TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL5_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15,
           TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15]

//>> GET_[TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15]
static inline fapi2::buffer<uint64_t>& GET_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL5_PG));
#endif
    return i_data.extractToRight<TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15,
           TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15]

//>> PREP_[TX_CTL_SM_REGS_CTLSM_STAT5_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX_CTL_SM_REGS_CTLSM_STAT5_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_STAT5_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TX_CTL_SM_REGS_CTLSM_STAT5_PG]

//>> GET_[TX_CTL_SM_REGS_CTLSM_STAT5_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX_CTL_SM_REGS_CTLSM_STAT5_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_STAT5_PG;
#endif
    return fapi2::getScom(i_target, TX_CTL_SM_REGS_CTLSM_STAT5_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TX_CTL_SM_REGS_CTLSM_STAT5_PG]

//>> PUT_[TX_CTL_SM_REGS_CTLSM_STAT5_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX_CTL_SM_REGS_CTLSM_STAT5_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_STAT5_PG));
#endif
    return fapi2::putScom(i_target, TX_CTL_SM_REGS_CTLSM_STAT5_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TX_CTL_SM_REGS_CTLSM_STAT5_PG]


//>> SET_[TX_CTL_SM_REGS_CTLSM_STAT5_PG_TX_PSAVE_STS_PHY_16_23_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_STAT5_PG_TX_PSAVE_STS_PHY_16_23_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_STAT5_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_STAT5_PG_TX_PSAVE_STS_PHY_16_23_RO_SIGNAL,
           TX_CTL_SM_REGS_CTLSM_STAT5_PG_TX_PSAVE_STS_PHY_16_23_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access TX_CTL_SM_REGS_CTLSM_STAT5_PG_TX_PSAVE_STS_PHY_16_23_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_CTLSM_STAT5_PG_TX_PSAVE_STS_PHY_16_23_RO_SIGNAL]

//>> SET_[TX_CTL_SM_REGS_CTLSM_STAT5_PG_TX_PSAVE_STS_PHY_16_23_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_STAT5_PG_TX_PSAVE_STS_PHY_16_23_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_STAT5_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_STAT5_PG_TX_PSAVE_STS_PHY_16_23_RO_SIGNAL,
           TX_CTL_SM_REGS_CTLSM_STAT5_PG_TX_PSAVE_STS_PHY_16_23_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access TX_CTL_SM_REGS_CTLSM_STAT5_PG_TX_PSAVE_STS_PHY_16_23_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_CTLSM_STAT5_PG_TX_PSAVE_STS_PHY_16_23_RO_SIGNAL]

//>> GET_[TX_CTL_SM_REGS_CTLSM_STAT5_PG_TX_PSAVE_STS_PHY_16_23_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_TX_CTL_SM_REGS_CTLSM_STAT5_PG_TX_PSAVE_STS_PHY_16_23_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_STAT5_PG));
#endif
    return i_data.extractToRight<TX_CTL_SM_REGS_CTLSM_STAT5_PG_TX_PSAVE_STS_PHY_16_23_RO_SIGNAL,
           TX_CTL_SM_REGS_CTLSM_STAT5_PG_TX_PSAVE_STS_PHY_16_23_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access TX_CTL_SM_REGS_CTLSM_STAT5_PG_TX_PSAVE_STS_PHY_16_23_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TX_CTL_SM_REGS_CTLSM_STAT5_PG_TX_PSAVE_STS_PHY_16_23_RO_SIGNAL]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
