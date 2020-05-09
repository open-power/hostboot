/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omic/reg00005.H $         */
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

#ifndef __OMIC_REG00005_H_
#define __OMIC_REG00005_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


//>> PREP_[CTL_REGS_RX_MODE18_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_MODE18_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE18_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CTL_REGS_RX_MODE18_PG]

//>> GET_[CTL_REGS_RX_MODE18_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_MODE18_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE18_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_MODE18_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CTL_REGS_RX_MODE18_PG]

//>> PUT_[CTL_REGS_RX_MODE18_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_MODE18_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_MODE18_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CTL_REGS_RX_MODE18_PG]


//>> SET_[CTL_REGS_RX_MODE18_PG_GAIN_HIST_BIAS_THRESH]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE18_PG_GAIN_HIST_BIAS_THRESH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE18_PG_GAIN_HIST_BIAS_THRESH,
           CTL_REGS_RX_MODE18_PG_GAIN_HIST_BIAS_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_GAIN_HIST_BIAS_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE18_PG_GAIN_HIST_BIAS_THRESH]

//>> SET_[CTL_REGS_RX_MODE18_PG_GAIN_HIST_BIAS_THRESH]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE18_PG_GAIN_HIST_BIAS_THRESH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE18_PG_GAIN_HIST_BIAS_THRESH,
           CTL_REGS_RX_MODE18_PG_GAIN_HIST_BIAS_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_GAIN_HIST_BIAS_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE18_PG_GAIN_HIST_BIAS_THRESH]

//>> GET_[CTL_REGS_RX_MODE18_PG_GAIN_HIST_BIAS_THRESH]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE18_PG_GAIN_HIST_BIAS_THRESH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE18_PG_GAIN_HIST_BIAS_THRESH,
           CTL_REGS_RX_MODE18_PG_GAIN_HIST_BIAS_THRESH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_GAIN_HIST_BIAS_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE18_PG_GAIN_HIST_BIAS_THRESH]

//>> SET_[CTL_REGS_RX_MODE18_PG_GAIN_N1_SAMPLES]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE18_PG_GAIN_N1_SAMPLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE18_PG_GAIN_N1_SAMPLES,
           CTL_REGS_RX_MODE18_PG_GAIN_N1_SAMPLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_GAIN_N1_SAMPLES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE18_PG_GAIN_N1_SAMPLES]

//>> SET_[CTL_REGS_RX_MODE18_PG_GAIN_N1_SAMPLES]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE18_PG_GAIN_N1_SAMPLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE18_PG_GAIN_N1_SAMPLES,
           CTL_REGS_RX_MODE18_PG_GAIN_N1_SAMPLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_GAIN_N1_SAMPLES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE18_PG_GAIN_N1_SAMPLES]

//>> GET_[CTL_REGS_RX_MODE18_PG_GAIN_N1_SAMPLES]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE18_PG_GAIN_N1_SAMPLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE18_PG_GAIN_N1_SAMPLES,
           CTL_REGS_RX_MODE18_PG_GAIN_N1_SAMPLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_GAIN_N1_SAMPLES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE18_PG_GAIN_N1_SAMPLES]

//>> SET_[CTL_REGS_RX_MODE18_PG_GAIN_N1_BIAS_THRESH]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE18_PG_GAIN_N1_BIAS_THRESH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE18_PG_GAIN_N1_BIAS_THRESH,
           CTL_REGS_RX_MODE18_PG_GAIN_N1_BIAS_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_GAIN_N1_BIAS_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE18_PG_GAIN_N1_BIAS_THRESH]

//>> SET_[CTL_REGS_RX_MODE18_PG_GAIN_N1_BIAS_THRESH]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE18_PG_GAIN_N1_BIAS_THRESH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE18_PG_GAIN_N1_BIAS_THRESH,
           CTL_REGS_RX_MODE18_PG_GAIN_N1_BIAS_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_GAIN_N1_BIAS_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE18_PG_GAIN_N1_BIAS_THRESH]

//>> GET_[CTL_REGS_RX_MODE18_PG_GAIN_N1_BIAS_THRESH]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE18_PG_GAIN_N1_BIAS_THRESH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE18_PG_GAIN_N1_BIAS_THRESH,
           CTL_REGS_RX_MODE18_PG_GAIN_N1_BIAS_THRESH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_GAIN_N1_BIAS_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE18_PG_GAIN_N1_BIAS_THRESH]

//>> SET_[CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS]

//>> SET_[CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS]

//>> SET_[CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS]

//>> CLEAR_[CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS]

//>> GET_[CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS]

//>> GET_[CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS]
static inline bool GET_CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE18_PG_GAIN_HISTORY_BIAS_DIS]

//>> SET_[CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS]

//>> SET_[CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS]

//>> SET_[CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS]

//>> CLEAR_[CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS]

//>> GET_[CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS]

//>> GET_[CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS]
static inline bool GET_CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_DIS]

//>> SET_[CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE]

//>> SET_[CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE]

//>> SET_[CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE]

//>> CLEAR_[CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE]

//>> GET_[CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE]

//>> GET_[CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE]
static inline bool GET_CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE18_PG_GAIN_SAMPLE_BIAS_MODE]

//>> SET_[CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE]

//>> SET_[CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE]

//>> SET_[CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE]

//>> CLEAR_[CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE]

//>> GET_[CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE]

//>> GET_[CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE]
static inline bool GET_CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE18_PG_CONVERGE_UP_ENABLE]

//>> SET_[CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE]

//>> SET_[CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE]

//>> SET_[CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE]

//>> CLEAR_[CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE]

//>> GET_[CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE]

//>> GET_[CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE]
static inline bool GET_CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE18_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE18_PG_CONVERGE_DOWN_ENABLE]

//>> PREP_[CTL_REGS_TX_SPARE_MODE_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_TX_SPARE_MODE_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_SPARE_MODE_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CTL_REGS_TX_SPARE_MODE_PG]

//>> GET_[CTL_REGS_TX_SPARE_MODE_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_TX_SPARE_MODE_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_SPARE_MODE_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_TX_SPARE_MODE_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CTL_REGS_TX_SPARE_MODE_PG]

//>> PUT_[CTL_REGS_TX_SPARE_MODE_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_TX_SPARE_MODE_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_TX_SPARE_MODE_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CTL_REGS_TX_SPARE_MODE_PG]


//>> SET_[CTL_REGS_TX_SPARE_MODE_PG_0]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_SPARE_MODE_PG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_SPARE_MODE_PG_0]

//>> SET_[CTL_REGS_TX_SPARE_MODE_PG_0]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_SPARE_MODE_PG_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_SPARE_MODE_PG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_SPARE_MODE_PG_0]

//>> SET_[CTL_REGS_TX_SPARE_MODE_PG_0]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.setBit<CTL_REGS_TX_SPARE_MODE_PG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_SPARE_MODE_PG_0]

//>> CLEAR_[CTL_REGS_TX_SPARE_MODE_PG_0]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_TX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.clearBit<CTL_REGS_TX_SPARE_MODE_PG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_TX_SPARE_MODE_PG_0]

//>> GET_[CTL_REGS_TX_SPARE_MODE_PG_0]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_SPARE_MODE_PG_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_SPARE_MODE_PG_0]

//>> GET_[CTL_REGS_TX_SPARE_MODE_PG_0]
static inline bool GET_CTL_REGS_TX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return i_data.getBit<CTL_REGS_TX_SPARE_MODE_PG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_SPARE_MODE_PG_0]

//>> SET_[CTL_REGS_TX_SPARE_MODE_PG_1]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_SPARE_MODE_PG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_SPARE_MODE_PG_1]

//>> SET_[CTL_REGS_TX_SPARE_MODE_PG_1]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_SPARE_MODE_PG_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_SPARE_MODE_PG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_SPARE_MODE_PG_1]

//>> SET_[CTL_REGS_TX_SPARE_MODE_PG_1]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.setBit<CTL_REGS_TX_SPARE_MODE_PG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_SPARE_MODE_PG_1]

//>> CLEAR_[CTL_REGS_TX_SPARE_MODE_PG_1]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_TX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.clearBit<CTL_REGS_TX_SPARE_MODE_PG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_TX_SPARE_MODE_PG_1]

//>> GET_[CTL_REGS_TX_SPARE_MODE_PG_1]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_SPARE_MODE_PG_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_SPARE_MODE_PG_1]

//>> GET_[CTL_REGS_TX_SPARE_MODE_PG_1]
static inline bool GET_CTL_REGS_TX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return i_data.getBit<CTL_REGS_TX_SPARE_MODE_PG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_SPARE_MODE_PG_1]

//>> SET_[CTL_REGS_TX_SPARE_MODE_PG_2]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_SPARE_MODE_PG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_SPARE_MODE_PG_2]

//>> SET_[CTL_REGS_TX_SPARE_MODE_PG_2]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_SPARE_MODE_PG_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_SPARE_MODE_PG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_SPARE_MODE_PG_2]

//>> SET_[CTL_REGS_TX_SPARE_MODE_PG_2]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.setBit<CTL_REGS_TX_SPARE_MODE_PG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_SPARE_MODE_PG_2]

//>> CLEAR_[CTL_REGS_TX_SPARE_MODE_PG_2]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_TX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.clearBit<CTL_REGS_TX_SPARE_MODE_PG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_TX_SPARE_MODE_PG_2]

//>> GET_[CTL_REGS_TX_SPARE_MODE_PG_2]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_SPARE_MODE_PG_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_SPARE_MODE_PG_2]

//>> GET_[CTL_REGS_TX_SPARE_MODE_PG_2]
static inline bool GET_CTL_REGS_TX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return i_data.getBit<CTL_REGS_TX_SPARE_MODE_PG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_SPARE_MODE_PG_2]

//>> SET_[CTL_REGS_TX_SPARE_MODE_PG_3]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_SPARE_MODE_PG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_SPARE_MODE_PG_3]

//>> SET_[CTL_REGS_TX_SPARE_MODE_PG_3]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_SPARE_MODE_PG_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_SPARE_MODE_PG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_SPARE_MODE_PG_3]

//>> SET_[CTL_REGS_TX_SPARE_MODE_PG_3]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.setBit<CTL_REGS_TX_SPARE_MODE_PG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_SPARE_MODE_PG_3]

//>> CLEAR_[CTL_REGS_TX_SPARE_MODE_PG_3]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_TX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.clearBit<CTL_REGS_TX_SPARE_MODE_PG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_TX_SPARE_MODE_PG_3]

//>> GET_[CTL_REGS_TX_SPARE_MODE_PG_3]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_SPARE_MODE_PG_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_SPARE_MODE_PG_3]

//>> GET_[CTL_REGS_TX_SPARE_MODE_PG_3]
static inline bool GET_CTL_REGS_TX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return i_data.getBit<CTL_REGS_TX_SPARE_MODE_PG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_SPARE_MODE_PG_3]

//>> SET_[CTL_REGS_TX_SPARE_MODE_PG_4]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_SPARE_MODE_PG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_SPARE_MODE_PG_4]

//>> SET_[CTL_REGS_TX_SPARE_MODE_PG_4]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_SPARE_MODE_PG_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_SPARE_MODE_PG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_SPARE_MODE_PG_4]

//>> SET_[CTL_REGS_TX_SPARE_MODE_PG_4]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.setBit<CTL_REGS_TX_SPARE_MODE_PG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_SPARE_MODE_PG_4]

//>> CLEAR_[CTL_REGS_TX_SPARE_MODE_PG_4]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_TX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.clearBit<CTL_REGS_TX_SPARE_MODE_PG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_TX_SPARE_MODE_PG_4]

//>> GET_[CTL_REGS_TX_SPARE_MODE_PG_4]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_SPARE_MODE_PG_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_SPARE_MODE_PG_4]

//>> GET_[CTL_REGS_TX_SPARE_MODE_PG_4]
static inline bool GET_CTL_REGS_TX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return i_data.getBit<CTL_REGS_TX_SPARE_MODE_PG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_SPARE_MODE_PG_4]

//>> SET_[CTL_REGS_TX_SPARE_MODE_PG_5]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_SPARE_MODE_PG_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_SPARE_MODE_PG_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_SPARE_MODE_PG_5]

//>> SET_[CTL_REGS_TX_SPARE_MODE_PG_5]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_SPARE_MODE_PG_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_SPARE_MODE_PG_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_SPARE_MODE_PG_5]

//>> SET_[CTL_REGS_TX_SPARE_MODE_PG_5]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_SPARE_MODE_PG_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.setBit<CTL_REGS_TX_SPARE_MODE_PG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_SPARE_MODE_PG_5]

//>> CLEAR_[CTL_REGS_TX_SPARE_MODE_PG_5]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_TX_SPARE_MODE_PG_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.clearBit<CTL_REGS_TX_SPARE_MODE_PG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_TX_SPARE_MODE_PG_5]

//>> GET_[CTL_REGS_TX_SPARE_MODE_PG_5]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_SPARE_MODE_PG_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_SPARE_MODE_PG_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_SPARE_MODE_PG_5]

//>> GET_[CTL_REGS_TX_SPARE_MODE_PG_5]
static inline bool GET_CTL_REGS_TX_SPARE_MODE_PG_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return i_data.getBit<CTL_REGS_TX_SPARE_MODE_PG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_SPARE_MODE_PG_5]

//>> SET_[CTL_REGS_TX_SPARE_MODE_PG_6]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_SPARE_MODE_PG_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_SPARE_MODE_PG_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_SPARE_MODE_PG_6]

//>> SET_[CTL_REGS_TX_SPARE_MODE_PG_6]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_SPARE_MODE_PG_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_SPARE_MODE_PG_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_SPARE_MODE_PG_6]

//>> SET_[CTL_REGS_TX_SPARE_MODE_PG_6]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_SPARE_MODE_PG_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.setBit<CTL_REGS_TX_SPARE_MODE_PG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_SPARE_MODE_PG_6]

//>> CLEAR_[CTL_REGS_TX_SPARE_MODE_PG_6]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_TX_SPARE_MODE_PG_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.clearBit<CTL_REGS_TX_SPARE_MODE_PG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_TX_SPARE_MODE_PG_6]

//>> GET_[CTL_REGS_TX_SPARE_MODE_PG_6]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_SPARE_MODE_PG_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_SPARE_MODE_PG_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_SPARE_MODE_PG_6]

//>> GET_[CTL_REGS_TX_SPARE_MODE_PG_6]
static inline bool GET_CTL_REGS_TX_SPARE_MODE_PG_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return i_data.getBit<CTL_REGS_TX_SPARE_MODE_PG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_SPARE_MODE_PG_6]

//>> SET_[CTL_REGS_TX_SPARE_MODE_PG_7]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_SPARE_MODE_PG_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_SPARE_MODE_PG_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_SPARE_MODE_PG_7]

//>> SET_[CTL_REGS_TX_SPARE_MODE_PG_7]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_SPARE_MODE_PG_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_SPARE_MODE_PG_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_SPARE_MODE_PG_7]

//>> SET_[CTL_REGS_TX_SPARE_MODE_PG_7]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_SPARE_MODE_PG_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.setBit<CTL_REGS_TX_SPARE_MODE_PG_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_SPARE_MODE_PG_7]

//>> CLEAR_[CTL_REGS_TX_SPARE_MODE_PG_7]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_TX_SPARE_MODE_PG_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.clearBit<CTL_REGS_TX_SPARE_MODE_PG_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_TX_SPARE_MODE_PG_7]

//>> GET_[CTL_REGS_TX_SPARE_MODE_PG_7]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_SPARE_MODE_PG_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_SPARE_MODE_PG_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_SPARE_MODE_PG_7]

//>> GET_[CTL_REGS_TX_SPARE_MODE_PG_7]
static inline bool GET_CTL_REGS_TX_SPARE_MODE_PG_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return i_data.getBit<CTL_REGS_TX_SPARE_MODE_PG_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_SPARE_MODE_PG_7]

//>> SET_[CTL_REGS_TX_SPARE_MODE_PG_8_9]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_SPARE_MODE_PG_8_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_SPARE_MODE_PG_8_9,
           CTL_REGS_TX_SPARE_MODE_PG_8_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_8_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_SPARE_MODE_PG_8_9]

//>> SET_[CTL_REGS_TX_SPARE_MODE_PG_8_9]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_SPARE_MODE_PG_8_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_SPARE_MODE_PG_8_9,
           CTL_REGS_TX_SPARE_MODE_PG_8_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_8_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_SPARE_MODE_PG_8_9]

//>> GET_[CTL_REGS_TX_SPARE_MODE_PG_8_9]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_SPARE_MODE_PG_8_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_SPARE_MODE_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_SPARE_MODE_PG_8_9,
           CTL_REGS_TX_SPARE_MODE_PG_8_9_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_SPARE_MODE_PG_8_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_SPARE_MODE_PG_8_9]

//>> PREP_[DATASM_REGS_RX_CNTL9_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNTL9_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNTL9_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DATASM_REGS_RX_CNTL9_PG]

//>> GET_[DATASM_REGS_RX_CNTL9_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNTL9_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNTL9_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNTL9_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DATASM_REGS_RX_CNTL9_PG]

//>> PUT_[DATASM_REGS_RX_CNTL9_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNTL9_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL9_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNTL9_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DATASM_REGS_RX_CNTL9_PG]


//>> SET_[DATASM_REGS_RX_CNTL9_PG_RX_PSAVE_FORCE_REQ_0_15]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNTL9_PG_RX_PSAVE_FORCE_REQ_0_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL9_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNTL9_PG_RX_PSAVE_FORCE_REQ_0_15,
           DATASM_REGS_RX_CNTL9_PG_RX_PSAVE_FORCE_REQ_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_CNTL9_PG_RX_PSAVE_FORCE_REQ_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNTL9_PG_RX_PSAVE_FORCE_REQ_0_15]

//>> SET_[DATASM_REGS_RX_CNTL9_PG_RX_PSAVE_FORCE_REQ_0_15]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNTL9_PG_RX_PSAVE_FORCE_REQ_0_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL9_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNTL9_PG_RX_PSAVE_FORCE_REQ_0_15,
           DATASM_REGS_RX_CNTL9_PG_RX_PSAVE_FORCE_REQ_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_CNTL9_PG_RX_PSAVE_FORCE_REQ_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNTL9_PG_RX_PSAVE_FORCE_REQ_0_15]

//>> GET_[DATASM_REGS_RX_CNTL9_PG_RX_PSAVE_FORCE_REQ_0_15]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNTL9_PG_RX_PSAVE_FORCE_REQ_0_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL9_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNTL9_PG_RX_PSAVE_FORCE_REQ_0_15,
           DATASM_REGS_RX_CNTL9_PG_RX_PSAVE_FORCE_REQ_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_CNTL9_PG_RX_PSAVE_FORCE_REQ_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_CNTL9_PG_RX_PSAVE_FORCE_REQ_0_15]

//>> PREP_[DATASM_REGS_RX_STAT17_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_STAT17_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT17_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DATASM_REGS_RX_STAT17_PG]

//>> GET_[DATASM_REGS_RX_STAT17_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_STAT17_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT17_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_STAT17_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT17_PG]

//>> PUT_[DATASM_REGS_RX_STAT17_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_STAT17_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT17_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_STAT17_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DATASM_REGS_RX_STAT17_PG]


//>> SET_[DATASM_REGS_RX_STAT17_PG_RX_LOFF_HYST_MAX_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT17_PG_RX_LOFF_HYST_MAX_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT17_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT17_PG_RX_LOFF_HYST_MAX_RO_SIGNAL,
           DATASM_REGS_RX_STAT17_PG_RX_LOFF_HYST_MAX_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_STAT17_PG_RX_LOFF_HYST_MAX_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT17_PG_RX_LOFF_HYST_MAX_RO_SIGNAL]

//>> SET_[DATASM_REGS_RX_STAT17_PG_RX_LOFF_HYST_MAX_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT17_PG_RX_LOFF_HYST_MAX_RO_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT17_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT17_PG_RX_LOFF_HYST_MAX_RO_SIGNAL,
           DATASM_REGS_RX_STAT17_PG_RX_LOFF_HYST_MAX_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_STAT17_PG_RX_LOFF_HYST_MAX_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT17_PG_RX_LOFF_HYST_MAX_RO_SIGNAL]

//>> GET_[DATASM_REGS_RX_STAT17_PG_RX_LOFF_HYST_MAX_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_STAT17_PG_RX_LOFF_HYST_MAX_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT17_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_STAT17_PG_RX_LOFF_HYST_MAX_RO_SIGNAL,
           DATASM_REGS_RX_STAT17_PG_RX_LOFF_HYST_MAX_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_STAT17_PG_RX_LOFF_HYST_MAX_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT17_PG_RX_LOFF_HYST_MAX_RO_SIGNAL]

//>> PREP_[DATASM_REGS_RX_STAT27_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_STAT27_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT27_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DATASM_REGS_RX_STAT27_PG]

//>> GET_[DATASM_REGS_RX_STAT27_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_STAT27_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT27_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_STAT27_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT27_PG]

//>> PUT_[DATASM_REGS_RX_STAT27_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_STAT27_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT27_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_STAT27_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DATASM_REGS_RX_STAT27_PG]


//>> SET_[DATASM_REGS_RX_STAT27_PG_RX_PSAVE_STS_PHY_16_23_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT27_PG_RX_PSAVE_STS_PHY_16_23_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT27_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT27_PG_RX_PSAVE_STS_PHY_16_23_RO_SIGNAL,
           DATASM_REGS_RX_STAT27_PG_RX_PSAVE_STS_PHY_16_23_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_STAT27_PG_RX_PSAVE_STS_PHY_16_23_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT27_PG_RX_PSAVE_STS_PHY_16_23_RO_SIGNAL]

//>> SET_[DATASM_REGS_RX_STAT27_PG_RX_PSAVE_STS_PHY_16_23_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT27_PG_RX_PSAVE_STS_PHY_16_23_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT27_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT27_PG_RX_PSAVE_STS_PHY_16_23_RO_SIGNAL,
           DATASM_REGS_RX_STAT27_PG_RX_PSAVE_STS_PHY_16_23_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_STAT27_PG_RX_PSAVE_STS_PHY_16_23_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT27_PG_RX_PSAVE_STS_PHY_16_23_RO_SIGNAL]

//>> GET_[DATASM_REGS_RX_STAT27_PG_RX_PSAVE_STS_PHY_16_23_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_STAT27_PG_RX_PSAVE_STS_PHY_16_23_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT27_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_STAT27_PG_RX_PSAVE_STS_PHY_16_23_RO_SIGNAL,
           DATASM_REGS_RX_STAT27_PG_RX_PSAVE_STS_PHY_16_23_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_STAT27_PG_RX_PSAVE_STS_PHY_16_23_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT27_PG_RX_PSAVE_STS_PHY_16_23_RO_SIGNAL]

//>> PREP_[DATASM_REGS_RX_STAT9_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_STAT9_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT9_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DATASM_REGS_RX_STAT9_PG]

//>> GET_[DATASM_REGS_RX_STAT9_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_STAT9_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT9_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_STAT9_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT9_PG]

//>> PUT_[DATASM_REGS_RX_STAT9_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_STAT9_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT9_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_STAT9_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DATASM_REGS_RX_STAT9_PG]


//>> SET_[DATASM_REGS_RX_STAT9_PG_P_16_23_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT9_PG_P_16_23_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT9_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT9_PG_P_16_23_RO_SIGNAL,
           DATASM_REGS_RX_STAT9_PG_P_16_23_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_STAT9_PG_P_16_23_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT9_PG_P_16_23_RO_SIGNAL]

//>> SET_[DATASM_REGS_RX_STAT9_PG_P_16_23_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT9_PG_P_16_23_RO_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT9_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT9_PG_P_16_23_RO_SIGNAL,
           DATASM_REGS_RX_STAT9_PG_P_16_23_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_STAT9_PG_P_16_23_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT9_PG_P_16_23_RO_SIGNAL]

//>> GET_[DATASM_REGS_RX_STAT9_PG_P_16_23_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_STAT9_PG_P_16_23_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT9_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_STAT9_PG_P_16_23_RO_SIGNAL,
           DATASM_REGS_RX_STAT9_PG_P_16_23_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_STAT9_PG_P_16_23_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT9_PG_P_16_23_RO_SIGNAL]

//>> SET_[DATASM_REGS_RX_STAT9_PG_N_16_23_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT9_PG_N_16_23_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT9_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT9_PG_N_16_23_RO_SIGNAL,
           DATASM_REGS_RX_STAT9_PG_N_16_23_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_STAT9_PG_N_16_23_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT9_PG_N_16_23_RO_SIGNAL]

//>> SET_[DATASM_REGS_RX_STAT9_PG_N_16_23_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT9_PG_N_16_23_RO_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT9_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT9_PG_N_16_23_RO_SIGNAL,
           DATASM_REGS_RX_STAT9_PG_N_16_23_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_STAT9_PG_N_16_23_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT9_PG_N_16_23_RO_SIGNAL]

//>> GET_[DATASM_REGS_RX_STAT9_PG_N_16_23_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_STAT9_PG_N_16_23_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT9_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_STAT9_PG_N_16_23_RO_SIGNAL,
           DATASM_REGS_RX_STAT9_PG_N_16_23_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_STAT9_PG_N_16_23_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT9_PG_N_16_23_RO_SIGNAL]

//>> PREP_[TX_CTL_SM_REGS_FIR_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX_CTL_SM_REGS_FIR_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_FIR_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TX_CTL_SM_REGS_FIR_PG]

//>> GET_[TX_CTL_SM_REGS_FIR_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX_CTL_SM_REGS_FIR_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_FIR_PG;
#endif
    return fapi2::getScom(i_target, TX_CTL_SM_REGS_FIR_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TX_CTL_SM_REGS_FIR_PG]

//>> PUT_[TX_CTL_SM_REGS_FIR_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX_CTL_SM_REGS_FIR_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return fapi2::putScom(i_target, TX_CTL_SM_REGS_FIR_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TX_CTL_SM_REGS_FIR_PG]


//>> SET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL]

//>> SET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL]

//>> SET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return o_data.setBit<TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL]

//>> CLEAR_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return o_data.clearBit<TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL]

//>> GET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return i_data.extractToRight<TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL]

//>> GET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL]
static inline bool GET_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return i_data.getBit<TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL]

//>> SET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL]

//>> SET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL]

//>> SET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return o_data.setBit<TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL]

//>> CLEAR_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return o_data.clearBit<TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL]

//>> GET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return i_data.extractToRight<TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL]

//>> GET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL]
static inline bool GET_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return i_data.getBit<TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL]

//>> SET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL]

//>> SET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL]

//>> SET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return o_data.setBit<TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL]

//>> CLEAR_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return o_data.clearBit<TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL]

//>> GET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return i_data.extractToRight<TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL]

//>> GET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL]
static inline bool GET_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return i_data.getBit<TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL]

//>> SET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL]

//>> SET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL]

//>> SET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return o_data.setBit<TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL]

//>> CLEAR_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return o_data.clearBit<TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL]

//>> GET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return i_data.extractToRight<TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL]

//>> GET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL]
static inline bool GET_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return i_data.getBit<TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL]

//>> SET_[TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL]

//>> SET_[TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL]

//>> SET_[TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return o_data.setBit<TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL]

//>> CLEAR_[TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return o_data.clearBit<TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL]

//>> GET_[TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return i_data.extractToRight<TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL]

//>> GET_[TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL]
static inline bool GET_TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_PG));
#endif
    return i_data.getBit<TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
