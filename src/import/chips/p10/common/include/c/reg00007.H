/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/c/reg00007.H $            */
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

#ifndef __C_REG00007_H_
#define __C_REG00007_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> PREP_[CPMS_CERRMSK]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_CERRMSK(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CERRMSK;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_CERRMSK]

//>> GET_[CPMS_CERRMSK]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_CERRMSK(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CERRMSK;
#endif
    return fapi2::getScom(i_target, CPMS_CERRMSK, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_CERRMSK]

//>> PUT_[CPMS_CERRMSK]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_CERRMSK(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return fapi2::putScom(i_target, CPMS_CERRMSK, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_CERRMSK]


//>> SET_[CPMS_CERRMSK_PFET_SEQ_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_PFET_SEQ_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_PFET_SEQ_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CERRMSK_PFET_SEQ_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_PFET_SEQ_ERR_MASK]

//>> SET_[CPMS_CERRMSK_PFET_SEQ_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_PFET_SEQ_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_PFET_SEQ_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CERRMSK_PFET_SEQ_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_PFET_SEQ_ERR_MASK]

//>> SET_[CPMS_CERRMSK_PFET_SEQ_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_PFET_SEQ_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.setBit<CPMS_CERRMSK_PFET_SEQ_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CERRMSK_PFET_SEQ_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_PFET_SEQ_ERR_MASK]

//>> CLEAR_[CPMS_CERRMSK_PFET_SEQ_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERRMSK_PFET_SEQ_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.clearBit<CPMS_CERRMSK_PFET_SEQ_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CERRMSK_PFET_SEQ_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CERRMSK_PFET_SEQ_ERR_MASK]

//>> GET_[CPMS_CERRMSK_PFET_SEQ_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CERRMSK_PFET_SEQ_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.extractToRight<CPMS_CERRMSK_PFET_SEQ_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CERRMSK_PFET_SEQ_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERRMSK_PFET_SEQ_ERR_MASK]

//>> GET_[CPMS_CERRMSK_PFET_SEQ_ERR_MASK]
static inline bool GET_CPMS_CERRMSK_PFET_SEQ_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.getBit<CPMS_CERRMSK_PFET_SEQ_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CERRMSK_PFET_SEQ_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERRMSK_PFET_SEQ_ERR_MASK]

//>> SET_[CPMS_CERRMSK_DDS_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_DDS_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_DDS_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CERRMSK_DDS_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_DDS_ERR_MASK]

//>> SET_[CPMS_CERRMSK_DDS_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_DDS_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_DDS_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CERRMSK_DDS_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_DDS_ERR_MASK]

//>> SET_[CPMS_CERRMSK_DDS_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_DDS_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.setBit<CPMS_CERRMSK_DDS_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CERRMSK_DDS_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_DDS_ERR_MASK]

//>> CLEAR_[CPMS_CERRMSK_DDS_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERRMSK_DDS_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.clearBit<CPMS_CERRMSK_DDS_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CERRMSK_DDS_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CERRMSK_DDS_ERR_MASK]

//>> GET_[CPMS_CERRMSK_DDS_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CERRMSK_DDS_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.extractToRight<CPMS_CERRMSK_DDS_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CERRMSK_DDS_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERRMSK_DDS_ERR_MASK]

//>> GET_[CPMS_CERRMSK_DDS_ERR_MASK]
static inline bool GET_CPMS_CERRMSK_DDS_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.getBit<CPMS_CERRMSK_DDS_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CERRMSK_DDS_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERRMSK_DDS_ERR_MASK]

//>> SET_[CPMS_CERRMSK_CLK_SYNC_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_CLK_SYNC_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_CLK_SYNC_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CERRMSK_CLK_SYNC_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_CLK_SYNC_ERR_MASK]

//>> SET_[CPMS_CERRMSK_CLK_SYNC_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_CLK_SYNC_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_CLK_SYNC_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CERRMSK_CLK_SYNC_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_CLK_SYNC_ERR_MASK]

//>> SET_[CPMS_CERRMSK_CLK_SYNC_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_CLK_SYNC_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.setBit<CPMS_CERRMSK_CLK_SYNC_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CERRMSK_CLK_SYNC_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_CLK_SYNC_ERR_MASK]

//>> CLEAR_[CPMS_CERRMSK_CLK_SYNC_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERRMSK_CLK_SYNC_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.clearBit<CPMS_CERRMSK_CLK_SYNC_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CERRMSK_CLK_SYNC_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CERRMSK_CLK_SYNC_ERR_MASK]

//>> GET_[CPMS_CERRMSK_CLK_SYNC_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CERRMSK_CLK_SYNC_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.extractToRight<CPMS_CERRMSK_CLK_SYNC_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CERRMSK_CLK_SYNC_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERRMSK_CLK_SYNC_ERR_MASK]

//>> GET_[CPMS_CERRMSK_CLK_SYNC_ERR_MASK]
static inline bool GET_CPMS_CERRMSK_CLK_SYNC_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.getBit<CPMS_CERRMSK_CLK_SYNC_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CERRMSK_CLK_SYNC_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERRMSK_CLK_SYNC_ERR_MASK]

//>> SET_[CPMS_CERRMSK_DPT_ACCESS_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_DPT_ACCESS_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_DPT_ACCESS_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CERRMSK_DPT_ACCESS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_DPT_ACCESS_MASK]

//>> SET_[CPMS_CERRMSK_DPT_ACCESS_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_DPT_ACCESS_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_DPT_ACCESS_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CERRMSK_DPT_ACCESS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_DPT_ACCESS_MASK]

//>> SET_[CPMS_CERRMSK_DPT_ACCESS_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_DPT_ACCESS_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.setBit<CPMS_CERRMSK_DPT_ACCESS_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CERRMSK_DPT_ACCESS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_DPT_ACCESS_MASK]

//>> CLEAR_[CPMS_CERRMSK_DPT_ACCESS_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERRMSK_DPT_ACCESS_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.clearBit<CPMS_CERRMSK_DPT_ACCESS_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CERRMSK_DPT_ACCESS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CERRMSK_DPT_ACCESS_MASK]

//>> GET_[CPMS_CERRMSK_DPT_ACCESS_MASK]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CERRMSK_DPT_ACCESS_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.extractToRight<CPMS_CERRMSK_DPT_ACCESS_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CERRMSK_DPT_ACCESS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERRMSK_DPT_ACCESS_MASK]

//>> GET_[CPMS_CERRMSK_DPT_ACCESS_MASK]
static inline bool GET_CPMS_CERRMSK_DPT_ACCESS_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.getBit<CPMS_CERRMSK_DPT_ACCESS_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CERRMSK_DPT_ACCESS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERRMSK_DPT_ACCESS_MASK]

//>> SET_[CPMS_CERRMSK_PROXY_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_PROXY_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_PROXY_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CERRMSK_PROXY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_PROXY_MASK]

//>> SET_[CPMS_CERRMSK_PROXY_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_PROXY_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_PROXY_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CERRMSK_PROXY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_PROXY_MASK]

//>> SET_[CPMS_CERRMSK_PROXY_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_PROXY_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.setBit<CPMS_CERRMSK_PROXY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CERRMSK_PROXY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_PROXY_MASK]

//>> CLEAR_[CPMS_CERRMSK_PROXY_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERRMSK_PROXY_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.clearBit<CPMS_CERRMSK_PROXY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CERRMSK_PROXY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CERRMSK_PROXY_MASK]

//>> GET_[CPMS_CERRMSK_PROXY_MASK]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CERRMSK_PROXY_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.extractToRight<CPMS_CERRMSK_PROXY_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CERRMSK_PROXY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERRMSK_PROXY_MASK]

//>> GET_[CPMS_CERRMSK_PROXY_MASK]
static inline bool GET_CPMS_CERRMSK_PROXY_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.getBit<CPMS_CERRMSK_PROXY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CERRMSK_PROXY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERRMSK_PROXY_MASK]

//>> SET_[CPMS_CERRMSK_FTC_EVENT_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_FTC_EVENT_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_FTC_EVENT_MASK,
           CPMS_CERRMSK_FTC_EVENT_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CERRMSK_FTC_EVENT_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_FTC_EVENT_MASK]

//>> SET_[CPMS_CERRMSK_FTC_EVENT_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_FTC_EVENT_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_FTC_EVENT_MASK,
           CPMS_CERRMSK_FTC_EVENT_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CERRMSK_FTC_EVENT_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_FTC_EVENT_MASK]

//>> GET_[CPMS_CERRMSK_FTC_EVENT_MASK]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CERRMSK_FTC_EVENT_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.extractToRight<CPMS_CERRMSK_FTC_EVENT_MASK,
           CPMS_CERRMSK_FTC_EVENT_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CERRMSK_FTC_EVENT_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERRMSK_FTC_EVENT_MASK]

//>> SET_[CPMS_CERRMSK_PITCH_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_PITCH_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_PITCH_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CERRMSK_PITCH_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_PITCH_MASK]

//>> SET_[CPMS_CERRMSK_PITCH_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_PITCH_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_PITCH_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CERRMSK_PITCH_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_PITCH_MASK]

//>> SET_[CPMS_CERRMSK_PITCH_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_PITCH_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.setBit<CPMS_CERRMSK_PITCH_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CERRMSK_PITCH_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_PITCH_MASK]

//>> CLEAR_[CPMS_CERRMSK_PITCH_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERRMSK_PITCH_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.clearBit<CPMS_CERRMSK_PITCH_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CERRMSK_PITCH_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CERRMSK_PITCH_MASK]

//>> GET_[CPMS_CERRMSK_PITCH_MASK]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CERRMSK_PITCH_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.extractToRight<CPMS_CERRMSK_PITCH_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CERRMSK_PITCH_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERRMSK_PITCH_MASK]

//>> GET_[CPMS_CERRMSK_PITCH_MASK]
static inline bool GET_CPMS_CERRMSK_PITCH_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.getBit<CPMS_CERRMSK_PITCH_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CERRMSK_PITCH_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERRMSK_PITCH_MASK]

//>> SET_[CPMS_CERRMSK_CCFG_PARITY_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_CCFG_PARITY_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_CCFG_PARITY_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CERRMSK_CCFG_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_CCFG_PARITY_MASK]

//>> SET_[CPMS_CERRMSK_CCFG_PARITY_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_CCFG_PARITY_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_CCFG_PARITY_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CERRMSK_CCFG_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_CCFG_PARITY_MASK]

//>> SET_[CPMS_CERRMSK_CCFG_PARITY_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_CCFG_PARITY_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.setBit<CPMS_CERRMSK_CCFG_PARITY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CERRMSK_CCFG_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_CCFG_PARITY_MASK]

//>> CLEAR_[CPMS_CERRMSK_CCFG_PARITY_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERRMSK_CCFG_PARITY_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.clearBit<CPMS_CERRMSK_CCFG_PARITY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CERRMSK_CCFG_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CERRMSK_CCFG_PARITY_MASK]

//>> GET_[CPMS_CERRMSK_CCFG_PARITY_MASK]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CERRMSK_CCFG_PARITY_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.extractToRight<CPMS_CERRMSK_CCFG_PARITY_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CERRMSK_CCFG_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERRMSK_CCFG_PARITY_MASK]

//>> GET_[CPMS_CERRMSK_CCFG_PARITY_MASK]
static inline bool GET_CPMS_CERRMSK_CCFG_PARITY_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.getBit<CPMS_CERRMSK_CCFG_PARITY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CERRMSK_CCFG_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERRMSK_CCFG_PARITY_MASK]

//>> SET_[CPMS_CERRMSK_RVRM_DROPOUT_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_RVRM_DROPOUT_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_RVRM_DROPOUT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CERRMSK_RVRM_DROPOUT_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_RVRM_DROPOUT_MASK]

//>> SET_[CPMS_CERRMSK_RVRM_DROPOUT_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_RVRM_DROPOUT_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_RVRM_DROPOUT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CERRMSK_RVRM_DROPOUT_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_RVRM_DROPOUT_MASK]

//>> SET_[CPMS_CERRMSK_RVRM_DROPOUT_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_RVRM_DROPOUT_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.setBit<CPMS_CERRMSK_RVRM_DROPOUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CERRMSK_RVRM_DROPOUT_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_RVRM_DROPOUT_MASK]

//>> CLEAR_[CPMS_CERRMSK_RVRM_DROPOUT_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERRMSK_RVRM_DROPOUT_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.clearBit<CPMS_CERRMSK_RVRM_DROPOUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CERRMSK_RVRM_DROPOUT_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CERRMSK_RVRM_DROPOUT_MASK]

//>> GET_[CPMS_CERRMSK_RVRM_DROPOUT_MASK]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CERRMSK_RVRM_DROPOUT_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.extractToRight<CPMS_CERRMSK_RVRM_DROPOUT_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CERRMSK_RVRM_DROPOUT_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERRMSK_RVRM_DROPOUT_MASK]

//>> GET_[CPMS_CERRMSK_RVRM_DROPOUT_MASK]
static inline bool GET_CPMS_CERRMSK_RVRM_DROPOUT_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.getBit<CPMS_CERRMSK_RVRM_DROPOUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CERRMSK_RVRM_DROPOUT_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERRMSK_RVRM_DROPOUT_MASK]

//>> SET_[CPMS_CERRMSK_PITCH_UPDATE_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_PITCH_UPDATE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_PITCH_UPDATE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CERRMSK_PITCH_UPDATE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_PITCH_UPDATE_MASK]

//>> SET_[CPMS_CERRMSK_PITCH_UPDATE_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_PITCH_UPDATE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_PITCH_UPDATE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CERRMSK_PITCH_UPDATE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_PITCH_UPDATE_MASK]

//>> SET_[CPMS_CERRMSK_PITCH_UPDATE_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_PITCH_UPDATE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.setBit<CPMS_CERRMSK_PITCH_UPDATE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CERRMSK_PITCH_UPDATE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_PITCH_UPDATE_MASK]

//>> CLEAR_[CPMS_CERRMSK_PITCH_UPDATE_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERRMSK_PITCH_UPDATE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.clearBit<CPMS_CERRMSK_PITCH_UPDATE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CERRMSK_PITCH_UPDATE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CERRMSK_PITCH_UPDATE_MASK]

//>> GET_[CPMS_CERRMSK_PITCH_UPDATE_MASK]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CERRMSK_PITCH_UPDATE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.extractToRight<CPMS_CERRMSK_PITCH_UPDATE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CERRMSK_PITCH_UPDATE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERRMSK_PITCH_UPDATE_MASK]

//>> GET_[CPMS_CERRMSK_PITCH_UPDATE_MASK]
static inline bool GET_CPMS_CERRMSK_PITCH_UPDATE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.getBit<CPMS_CERRMSK_PITCH_UPDATE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CERRMSK_PITCH_UPDATE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERRMSK_PITCH_UPDATE_MASK]

//>> SET_[CPMS_CERRMSK_SPARE_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_SPARE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_SPARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CERRMSK_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_SPARE_MASK]

//>> SET_[CPMS_CERRMSK_SPARE_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_SPARE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_SPARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CERRMSK_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_SPARE_MASK]

//>> SET_[CPMS_CERRMSK_SPARE_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_SPARE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.setBit<CPMS_CERRMSK_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CERRMSK_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERRMSK_SPARE_MASK]

//>> CLEAR_[CPMS_CERRMSK_SPARE_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERRMSK_SPARE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.clearBit<CPMS_CERRMSK_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CERRMSK_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CERRMSK_SPARE_MASK]

//>> GET_[CPMS_CERRMSK_SPARE_MASK]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CERRMSK_SPARE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.extractToRight<CPMS_CERRMSK_SPARE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CERRMSK_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERRMSK_SPARE_MASK]

//>> GET_[CPMS_CERRMSK_SPARE_MASK]
static inline bool GET_CPMS_CERRMSK_SPARE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.getBit<CPMS_CERRMSK_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CERRMSK_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERRMSK_SPARE_MASK]

//>> PREP_[EC_PC_FIR_HOLD_OUT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_FIR_HOLD_OUT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_HOLD_OUT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_FIR_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_FIR_HOLD_OUT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_HOLD_OUT;
#endif
    return fapi2::getScom(i_target, EC_PC_FIR_HOLD_OUT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT]

//>> PUT_[EC_PC_FIR_HOLD_OUT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_FIR_HOLD_OUT(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return fapi2::putScom(i_target, EC_PC_FIR_HOLD_OUT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_FIR_HOLD_OUT]


//>> SET_[EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT]

//>> CLEAR_[EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT]
static inline bool GET_EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT]

//>> CLEAR_[EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT]
static inline bool GET_EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT]

//>> CLEAR_[EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT]
static inline bool GET_EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT]

//>> CLEAR_[EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT]
static inline bool GET_EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT]

//>> CLEAR_[EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT]
static inline bool GET_EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT]

//>> CLEAR_[EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT]
static inline bool GET_EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT]

//>> CLEAR_[EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT]
static inline bool GET_EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT]

//>> CLEAR_[EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT]
static inline bool GET_EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT]

//>> CLEAR_[EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT]
static inline bool GET_EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT]

//>> CLEAR_[EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT]
static inline bool GET_EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT]

//>> CLEAR_[EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT]
static inline bool GET_EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT]

//>> CLEAR_[EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT]
static inline bool GET_EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT]

//>> CLEAR_[EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT]
static inline bool GET_EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT]

//>> CLEAR_[EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT]
static inline bool GET_EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT]

//>> CLEAR_[EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT]
static inline bool GET_EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT]

//>> CLEAR_[EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT]
static inline bool GET_EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT]

//>> CLEAR_[EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT]
static inline bool GET_EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT]

//>> CLEAR_[EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT]
static inline bool GET_EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT]

//>> CLEAR_[EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT]
static inline bool GET_EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT]

//>> CLEAR_[EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT]
static inline bool GET_EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT]

//>> CLEAR_[EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT]
static inline bool GET_EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT]

//>> CLEAR_[EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT]
static inline bool GET_EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT]

//>> CLEAR_[EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT]
static inline bool GET_EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT]

//>> CLEAR_[EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT]
static inline bool GET_EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT]

//>> CLEAR_[EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT]
static inline bool GET_EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT]

//>> SET_[EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT]

//>> CLEAR_[EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT]

//>> GET_[EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT]
static inline bool GET_EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT]

//>> PREP_[EC_PC_FIR_RAM_MODEREG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_FIR_RAM_MODEREG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_RAM_MODEREG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_FIR_RAM_MODEREG]

//>> GET_[EC_PC_FIR_RAM_MODEREG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_FIR_RAM_MODEREG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_RAM_MODEREG;
#endif
    return fapi2::getScom(i_target, EC_PC_FIR_RAM_MODEREG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_FIR_RAM_MODEREG]

//>> PUT_[EC_PC_FIR_RAM_MODEREG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_FIR_RAM_MODEREG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_MODEREG));
#endif
    return fapi2::putScom(i_target, EC_PC_FIR_RAM_MODEREG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_FIR_RAM_MODEREG]


//>> SET_[EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_MODEREG));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE]

//>> SET_[EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_MODEREG));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE]

//>> SET_[EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_MODEREG));
#endif
    return o_data.setBit<EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE]

//>> CLEAR_[EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_MODEREG));
#endif
    return o_data.clearBit<EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE]

//>> GET_[EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_MODEREG));
#endif
    return i_data.extractToRight<EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE]

//>> GET_[EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE]
static inline bool GET_EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_MODEREG));
#endif
    return i_data.getBit<EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE]

//>> PREP_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_THRCTL_TCTLCOM_RAS_MODEREG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_THRCTL_TCTLCOM_RAS_MODEREG;
#endif
    return fapi2::getScom(i_target, EC_PC_THRCTL_TCTLCOM_RAS_MODEREG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG]

//>> PUT_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_MODEREG));
#endif
    return fapi2::putScom(i_target, EC_PC_THRCTL_TCTLCOM_RAS_MODEREG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG]


//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_MODEREG));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_MODEREG));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_MODEREG));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_MODEREG));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_MODEREG));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_MODEREG));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_MODEREG));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_MODEREG));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_MODEREG));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_MODEREG));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_MODEREG));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_MODEREG));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_MODEREG));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_MODEREG));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_MODEREG));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_MODEREG));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_MODEREG));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_MODEREG));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_MODEREG));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_MODEREG));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP]

//>> SET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_MODEREG));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_MODEREG));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_MODEREG));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP]

//>> GET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_MODEREG));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP]

//>> PREP_[L3_MISC_L3CERRS_PRD_PURGE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_PRD_PURGE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_PRD_PURGE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3_MISC_L3CERRS_PRD_PURGE_REG]

//>> GET_[L3_MISC_L3CERRS_PRD_PURGE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_PRD_PURGE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_PRD_PURGE_REG;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_PRD_PURGE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3_MISC_L3CERRS_PRD_PURGE_REG]

//>> PUT_[L3_MISC_L3CERRS_PRD_PURGE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_PRD_PURGE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_PRD_PURGE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3_MISC_L3CERRS_PRD_PURGE_REG]


//>> SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ]

//>> SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ]

//>> SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ]

//>> CLEAR_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ]

//>> GET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ]

//>> GET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ]
static inline bool GET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ]

//>> SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_TTYPE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_TTYPE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_TTYPE,
           L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_TTYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_TTYPE]

//>> SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_TTYPE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_TTYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_TTYPE,
           L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_TTYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_TTYPE]

//>> GET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_TTYPE]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_TTYPE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_TTYPE,
           L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_TTYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_TTYPE]

//>> SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE]

//>> SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE]

//>> SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE]

//>> CLEAR_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE]

//>> GET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE]

//>> GET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE]
static inline bool GET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE]

//>> SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE]

//>> SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE]

//>> SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE]

//>> CLEAR_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE]

//>> GET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE]

//>> GET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE]
static inline bool GET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE]

//>> SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_1]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_1,
           L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_1]

//>> SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_1]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_1,
           L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_1]

//>> GET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_1]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_1,
           L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_1]

//>> SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR]

//>> SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR]

//>> SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR]

//>> CLEAR_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR]

//>> GET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR]

//>> GET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR]
static inline bool GET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR]

//>> SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_2]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_2,
           L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_2]

//>> SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_2]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_2,
           L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_2]

//>> GET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_2]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_2,
           L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_2]

//>> SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_MEMBER]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_MEMBER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_MEMBER,
           L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_MEMBER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_MEMBER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_MEMBER]

//>> SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_MEMBER]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_MEMBER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_MEMBER,
           L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_MEMBER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_MEMBER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_MEMBER]

//>> GET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_MEMBER]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_MEMBER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_MEMBER,
           L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_MEMBER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_MEMBER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_MEMBER]

//>> SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_DIR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_DIR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_DIR_ADDR,
           L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_DIR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_DIR_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_DIR_ADDR]

//>> SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_DIR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_DIR_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_DIR_ADDR,
           L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_DIR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_DIR_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_DIR_ADDR]

//>> GET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_DIR_ADDR]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_DIR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_DIR_ADDR,
           L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_DIR_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_DIR_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_DIR_ADDR]

//>> PREP_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD]

//>> PUT_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD]


//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31]

//>> PREP_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3;
#endif
    return fapi2::getScom(i_target, NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3]

//>> PUT_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return fapi2::putScom(i_target, NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3]


//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31]

//>> PREP_[QME_PSCRS3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_PSCRS3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PSCRS3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_PSCRS3]

//>> GET_[QME_PSCRS3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_PSCRS3(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PSCRS3;
#endif
    return fapi2::getScom(i_target, QME_PSCRS3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_PSCRS3]

//>> PUT_[QME_PSCRS3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_PSCRS3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return fapi2::putScom(i_target, QME_PSCRS3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_PSCRS3]


//>> SET_[QME_PSCRS3_DPDES_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_DPDES_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_DPDES_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS3_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_DPDES_EXIT_ENABLE]

//>> SET_[QME_PSCRS3_DPDES_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_DPDES_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_DPDES_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS3_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_DPDES_EXIT_ENABLE]

//>> SET_[QME_PSCRS3_DPDES_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_DPDES_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.setBit<QME_PSCRS3_DPDES_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS3_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_DPDES_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS3_DPDES_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS3_DPDES_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.clearBit<QME_PSCRS3_DPDES_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS3_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS3_DPDES_EXIT_ENABLE]

//>> GET_[QME_PSCRS3_DPDES_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_DPDES_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_DPDES_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS3_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS3_DPDES_EXIT_ENABLE]

//>> GET_[QME_PSCRS3_DPDES_EXIT_ENABLE]
static inline bool GET_QME_PSCRS3_DPDES_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.getBit<QME_PSCRS3_DPDES_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS3_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS3_DPDES_EXIT_ENABLE]

//>> SET_[QME_PSCRS3_SD]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_SD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_SD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS3_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_SD]

//>> SET_[QME_PSCRS3_SD]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_SD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_SD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS3_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_SD]

//>> SET_[QME_PSCRS3_SD]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_SD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.setBit<QME_PSCRS3_SD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS3_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_SD]

//>> CLEAR_[QME_PSCRS3_SD]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS3_SD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.clearBit<QME_PSCRS3_SD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS3_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS3_SD]

//>> GET_[QME_PSCRS3_SD]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_SD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_SD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS3_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS3_SD]

//>> GET_[QME_PSCRS3_SD]
static inline bool GET_QME_PSCRS3_SD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.getBit<QME_PSCRS3_SD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS3_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS3_SD]

//>> SET_[QME_PSCRS3_ESL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_ESL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_ESL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS3_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_ESL]

//>> SET_[QME_PSCRS3_ESL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_ESL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_ESL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS3_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_ESL]

//>> SET_[QME_PSCRS3_ESL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_ESL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.setBit<QME_PSCRS3_ESL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS3_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_ESL]

//>> CLEAR_[QME_PSCRS3_ESL]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS3_ESL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.clearBit<QME_PSCRS3_ESL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS3_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS3_ESL]

//>> GET_[QME_PSCRS3_ESL]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_ESL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_ESL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS3_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS3_ESL]

//>> GET_[QME_PSCRS3_ESL]
static inline bool GET_QME_PSCRS3_ESL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.getBit<QME_PSCRS3_ESL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS3_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS3_ESL]

//>> SET_[QME_PSCRS3_EC]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_EC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_EC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS3_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_EC]

//>> SET_[QME_PSCRS3_EC]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_EC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_EC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS3_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_EC]

//>> SET_[QME_PSCRS3_EC]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_EC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.setBit<QME_PSCRS3_EC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS3_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_EC]

//>> CLEAR_[QME_PSCRS3_EC]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS3_EC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.clearBit<QME_PSCRS3_EC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS3_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS3_EC]

//>> GET_[QME_PSCRS3_EC]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_EC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_EC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS3_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS3_EC]

//>> GET_[QME_PSCRS3_EC]
static inline bool GET_QME_PSCRS3_EC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.getBit<QME_PSCRS3_EC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS3_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS3_EC]

//>> SET_[QME_PSCRS3_PSLL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_PSLL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_PSLL,
           QME_PSCRS3_PSLL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS3_PSLL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_PSLL]

//>> SET_[QME_PSCRS3_PSLL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_PSLL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_PSLL,
           QME_PSCRS3_PSLL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS3_PSLL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_PSLL]

//>> GET_[QME_PSCRS3_PSLL]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_PSLL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_PSLL,
           QME_PSCRS3_PSLL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS3_PSLL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS3_PSLL]

//>> SET_[QME_PSCRS3_HYP_VIRT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_HYP_VIRT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_HYP_VIRT_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS3_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_HYP_VIRT_EXIT_ENABLE]

//>> SET_[QME_PSCRS3_HYP_VIRT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_HYP_VIRT_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_HYP_VIRT_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS3_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_HYP_VIRT_EXIT_ENABLE]

//>> SET_[QME_PSCRS3_HYP_VIRT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_HYP_VIRT_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.setBit<QME_PSCRS3_HYP_VIRT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS3_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_HYP_VIRT_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS3_HYP_VIRT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS3_HYP_VIRT_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.clearBit<QME_PSCRS3_HYP_VIRT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS3_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS3_HYP_VIRT_EXIT_ENABLE]

//>> GET_[QME_PSCRS3_HYP_VIRT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_HYP_VIRT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_HYP_VIRT_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS3_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS3_HYP_VIRT_EXIT_ENABLE]

//>> GET_[QME_PSCRS3_HYP_VIRT_EXIT_ENABLE]
static inline bool GET_QME_PSCRS3_HYP_VIRT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.getBit<QME_PSCRS3_HYP_VIRT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS3_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS3_HYP_VIRT_EXIT_ENABLE]

//>> SET_[QME_PSCRS3_UV_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_UV_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_UV_DB_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS3_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_UV_DB_EXIT_ENABLE]

//>> SET_[QME_PSCRS3_UV_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_UV_DB_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_UV_DB_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS3_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_UV_DB_EXIT_ENABLE]

//>> SET_[QME_PSCRS3_UV_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_UV_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.setBit<QME_PSCRS3_UV_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS3_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_UV_DB_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS3_UV_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS3_UV_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.clearBit<QME_PSCRS3_UV_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS3_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS3_UV_DB_EXIT_ENABLE]

//>> GET_[QME_PSCRS3_UV_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_UV_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_UV_DB_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS3_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS3_UV_DB_EXIT_ENABLE]

//>> GET_[QME_PSCRS3_UV_DB_EXIT_ENABLE]
static inline bool GET_QME_PSCRS3_UV_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.getBit<QME_PSCRS3_UV_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS3_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS3_UV_DB_EXIT_ENABLE]

//>> SET_[QME_PSCRS3_HYP_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_HYP_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_HYP_DB_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS3_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_HYP_DB_EXIT_ENABLE]

//>> SET_[QME_PSCRS3_HYP_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_HYP_DB_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_HYP_DB_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS3_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_HYP_DB_EXIT_ENABLE]

//>> SET_[QME_PSCRS3_HYP_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_HYP_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.setBit<QME_PSCRS3_HYP_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS3_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_HYP_DB_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS3_HYP_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS3_HYP_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.clearBit<QME_PSCRS3_HYP_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS3_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS3_HYP_DB_EXIT_ENABLE]

//>> GET_[QME_PSCRS3_HYP_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_HYP_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_HYP_DB_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS3_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS3_HYP_DB_EXIT_ENABLE]

//>> GET_[QME_PSCRS3_HYP_DB_EXIT_ENABLE]
static inline bool GET_QME_PSCRS3_HYP_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.getBit<QME_PSCRS3_HYP_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS3_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS3_HYP_DB_EXIT_ENABLE]

//>> SET_[QME_PSCRS3_EXT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_EXT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_EXT_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS3_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_EXT_EXIT_ENABLE]

//>> SET_[QME_PSCRS3_EXT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_EXT_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_EXT_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS3_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_EXT_EXIT_ENABLE]

//>> SET_[QME_PSCRS3_EXT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_EXT_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.setBit<QME_PSCRS3_EXT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS3_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_EXT_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS3_EXT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS3_EXT_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.clearBit<QME_PSCRS3_EXT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS3_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS3_EXT_EXIT_ENABLE]

//>> GET_[QME_PSCRS3_EXT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_EXT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_EXT_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS3_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS3_EXT_EXIT_ENABLE]

//>> GET_[QME_PSCRS3_EXT_EXIT_ENABLE]
static inline bool GET_QME_PSCRS3_EXT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.getBit<QME_PSCRS3_EXT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS3_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS3_EXT_EXIT_ENABLE]

//>> SET_[QME_PSCRS3_DEC_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_DEC_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_DEC_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS3_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_DEC_EXIT_ENABLE]

//>> SET_[QME_PSCRS3_DEC_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_DEC_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_DEC_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS3_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_DEC_EXIT_ENABLE]

//>> SET_[QME_PSCRS3_DEC_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_DEC_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.setBit<QME_PSCRS3_DEC_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS3_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_DEC_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS3_DEC_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS3_DEC_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.clearBit<QME_PSCRS3_DEC_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS3_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS3_DEC_EXIT_ENABLE]

//>> GET_[QME_PSCRS3_DEC_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_DEC_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_DEC_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS3_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS3_DEC_EXIT_ENABLE]

//>> GET_[QME_PSCRS3_DEC_EXIT_ENABLE]
static inline bool GET_QME_PSCRS3_DEC_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.getBit<QME_PSCRS3_DEC_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS3_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS3_DEC_EXIT_ENABLE]

//>> SET_[QME_PSCRS3_HMI_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_HMI_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_HMI_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS3_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_HMI_EXIT_ENABLE]

//>> SET_[QME_PSCRS3_HMI_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_HMI_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_HMI_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS3_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_HMI_EXIT_ENABLE]

//>> SET_[QME_PSCRS3_HMI_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_HMI_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.setBit<QME_PSCRS3_HMI_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS3_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_HMI_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS3_HMI_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS3_HMI_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.clearBit<QME_PSCRS3_HMI_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS3_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS3_HMI_EXIT_ENABLE]

//>> GET_[QME_PSCRS3_HMI_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_HMI_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_HMI_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS3_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS3_HMI_EXIT_ENABLE]

//>> GET_[QME_PSCRS3_HMI_EXIT_ENABLE]
static inline bool GET_QME_PSCRS3_HMI_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.getBit<QME_PSCRS3_HMI_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS3_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS3_HMI_EXIT_ENABLE]

//>> SET_[QME_PSCRS3_TR]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_TR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_TR,
           QME_PSCRS3_TR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS3_TR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_TR]

//>> SET_[QME_PSCRS3_TR]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_TR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_TR,
           QME_PSCRS3_TR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS3_TR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_TR]

//>> GET_[QME_PSCRS3_TR]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_TR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_TR,
           QME_PSCRS3_TR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS3_TR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS3_TR]

//>> SET_[QME_PSCRS3_MTL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_MTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_MTL,
           QME_PSCRS3_MTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS3_MTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_MTL]

//>> SET_[QME_PSCRS3_MTL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_MTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_MTL,
           QME_PSCRS3_MTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS3_MTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_MTL]

//>> GET_[QME_PSCRS3_MTL]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_MTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_MTL,
           QME_PSCRS3_MTL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS3_MTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS3_MTL]

//>> SET_[QME_PSCRS3_RL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_RL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_RL,
           QME_PSCRS3_RL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS3_RL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_RL]

//>> SET_[QME_PSCRS3_RL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_RL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_RL,
           QME_PSCRS3_RL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS3_RL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_RL]

//>> GET_[QME_PSCRS3_RL]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_RL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_RL,
           QME_PSCRS3_RL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS3_RL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS3_RL]

//>> SET_[QME_PSCRS3_PLS]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_PLS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_PLS,
           QME_PSCRS3_PLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS3_PLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_PLS]

//>> SET_[QME_PSCRS3_PLS]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_PLS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_PLS,
           QME_PSCRS3_PLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS3_PLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS3_PLS]

//>> GET_[QME_PSCRS3_PLS]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_PLS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_PLS,
           QME_PSCRS3_PLS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS3_PLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS3_PLS]

//>> PREP_[QME_SCSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCSR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCSR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SCSR]

//>> GET_[QME_SCSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCSR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCSR;
#endif
    return fapi2::getScom(i_target, QME_SCSR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SCSR]

//>> PUT_[QME_SCSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCSR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, QME_SCSR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SCSR]

//>> PREP_[QME_SCSR_SCOM2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCSR_SCOM2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCSR_SCOM2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SCSR_SCOM2]

//>> GET_[QME_SCSR_SCOM2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCSR_SCOM2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCSR_SCOM2;
#endif
    return fapi2::getScom(i_target, QME_SCSR_SCOM2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SCSR_SCOM2]

//>> PUT_[QME_SCSR_SCOM2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCSR_SCOM2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, QME_SCSR_SCOM2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SCSR_SCOM2]

//>> PREP_[QME_SCSR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCSR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCSR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SCSR_WO_CLEAR]

//>> GET_[QME_SCSR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCSR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCSR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, QME_SCSR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SCSR_WO_CLEAR]

//>> PUT_[QME_SCSR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCSR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, QME_SCSR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SCSR_WO_CLEAR]


//>> SET_[QME_SCSR_ASSERT_PM_BLOCK_INTR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ASSERT_PM_BLOCK_INTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_ASSERT_PM_BLOCK_INTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_ASSERT_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_ASSERT_PM_BLOCK_INTR]

//>> SET_[QME_SCSR_ASSERT_PM_BLOCK_INTR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ASSERT_PM_BLOCK_INTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_ASSERT_PM_BLOCK_INTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_ASSERT_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_ASSERT_PM_BLOCK_INTR]

//>> SET_[QME_SCSR_ASSERT_PM_BLOCK_INTR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ASSERT_PM_BLOCK_INTR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_ASSERT_PM_BLOCK_INTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_ASSERT_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_ASSERT_PM_BLOCK_INTR]

//>> CLEAR_[QME_SCSR_ASSERT_PM_BLOCK_INTR]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_ASSERT_PM_BLOCK_INTR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_ASSERT_PM_BLOCK_INTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_ASSERT_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_ASSERT_PM_BLOCK_INTR]

//>> GET_[QME_SCSR_ASSERT_PM_BLOCK_INTR]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_ASSERT_PM_BLOCK_INTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_ASSERT_PM_BLOCK_INTR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_ASSERT_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_ASSERT_PM_BLOCK_INTR]

//>> GET_[QME_SCSR_ASSERT_PM_BLOCK_INTR]
static inline bool GET_QME_SCSR_ASSERT_PM_BLOCK_INTR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_ASSERT_PM_BLOCK_INTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_ASSERT_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_ASSERT_PM_BLOCK_INTR]

//>> SET_[QME_SCSR_ASSERT_PM_EXIT]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ASSERT_PM_EXIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_ASSERT_PM_EXIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_ASSERT_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_ASSERT_PM_EXIT]

//>> SET_[QME_SCSR_ASSERT_PM_EXIT]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ASSERT_PM_EXIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_ASSERT_PM_EXIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_ASSERT_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_ASSERT_PM_EXIT]

//>> SET_[QME_SCSR_ASSERT_PM_EXIT]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ASSERT_PM_EXIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_ASSERT_PM_EXIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_ASSERT_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_ASSERT_PM_EXIT]

//>> CLEAR_[QME_SCSR_ASSERT_PM_EXIT]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_ASSERT_PM_EXIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_ASSERT_PM_EXIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_ASSERT_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_ASSERT_PM_EXIT]

//>> GET_[QME_SCSR_ASSERT_PM_EXIT]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_ASSERT_PM_EXIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_ASSERT_PM_EXIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_ASSERT_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_ASSERT_PM_EXIT]

//>> GET_[QME_SCSR_ASSERT_PM_EXIT]
static inline bool GET_QME_SCSR_ASSERT_PM_EXIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_ASSERT_PM_EXIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_ASSERT_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_ASSERT_PM_EXIT]

//>> SET_[QME_SCSR_ASSERT_PM_ENTRY_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ASSERT_PM_ENTRY_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_ASSERT_PM_ENTRY_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_ASSERT_PM_ENTRY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_ASSERT_PM_ENTRY_LIMIT]

//>> SET_[QME_SCSR_ASSERT_PM_ENTRY_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ASSERT_PM_ENTRY_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_ASSERT_PM_ENTRY_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_ASSERT_PM_ENTRY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_ASSERT_PM_ENTRY_LIMIT]

//>> SET_[QME_SCSR_ASSERT_PM_ENTRY_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ASSERT_PM_ENTRY_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_ASSERT_PM_ENTRY_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_ASSERT_PM_ENTRY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_ASSERT_PM_ENTRY_LIMIT]

//>> CLEAR_[QME_SCSR_ASSERT_PM_ENTRY_LIMIT]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_ASSERT_PM_ENTRY_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_ASSERT_PM_ENTRY_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_ASSERT_PM_ENTRY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_ASSERT_PM_ENTRY_LIMIT]

//>> GET_[QME_SCSR_ASSERT_PM_ENTRY_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_ASSERT_PM_ENTRY_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_ASSERT_PM_ENTRY_LIMIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_ASSERT_PM_ENTRY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_ASSERT_PM_ENTRY_LIMIT]

//>> GET_[QME_SCSR_ASSERT_PM_ENTRY_LIMIT]
static inline bool GET_QME_SCSR_ASSERT_PM_ENTRY_LIMIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_ASSERT_PM_ENTRY_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_ASSERT_PM_ENTRY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_ASSERT_PM_ENTRY_LIMIT]

//>> SET_[QME_SCSR_PC_SPARE_OUT]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_SPARE_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PC_SPARE_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_PC_SPARE_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PC_SPARE_OUT]

//>> SET_[QME_SCSR_PC_SPARE_OUT]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_SPARE_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PC_SPARE_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_PC_SPARE_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PC_SPARE_OUT]

//>> SET_[QME_SCSR_PC_SPARE_OUT]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_SPARE_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_PC_SPARE_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_PC_SPARE_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PC_SPARE_OUT]

//>> CLEAR_[QME_SCSR_PC_SPARE_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_PC_SPARE_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_PC_SPARE_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_PC_SPARE_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_PC_SPARE_OUT]

//>> GET_[QME_SCSR_PC_SPARE_OUT]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PC_SPARE_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_PC_SPARE_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_PC_SPARE_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PC_SPARE_OUT]

//>> GET_[QME_SCSR_PC_SPARE_OUT]
static inline bool GET_QME_SCSR_PC_SPARE_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_PC_SPARE_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_PC_SPARE_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PC_SPARE_OUT]

//>> SET_[QME_SCSR_HBUS_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_HBUS_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_HBUS_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_HBUS_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_HBUS_DISABLE]

//>> SET_[QME_SCSR_HBUS_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_HBUS_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_HBUS_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_HBUS_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_HBUS_DISABLE]

//>> SET_[QME_SCSR_HBUS_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_HBUS_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_HBUS_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_HBUS_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_HBUS_DISABLE]

//>> CLEAR_[QME_SCSR_HBUS_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_HBUS_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_HBUS_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_HBUS_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_HBUS_DISABLE]

//>> GET_[QME_SCSR_HBUS_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_HBUS_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_HBUS_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_HBUS_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_HBUS_DISABLE]

//>> GET_[QME_SCSR_HBUS_DISABLE]
static inline bool GET_QME_SCSR_HBUS_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_HBUS_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_HBUS_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_HBUS_DISABLE]

//>> SET_[QME_SCSR_L2_PURGE_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_L2_PURGE_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_L2_PURGE_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_L2_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_L2_PURGE_REQ]

//>> SET_[QME_SCSR_L2_PURGE_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_L2_PURGE_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_L2_PURGE_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_L2_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_L2_PURGE_REQ]

//>> SET_[QME_SCSR_L2_PURGE_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_L2_PURGE_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_L2_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_L2_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_L2_PURGE_REQ]

//>> CLEAR_[QME_SCSR_L2_PURGE_REQ]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_L2_PURGE_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_L2_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_L2_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_L2_PURGE_REQ]

//>> GET_[QME_SCSR_L2_PURGE_REQ]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_L2_PURGE_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_L2_PURGE_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_L2_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_L2_PURGE_REQ]

//>> GET_[QME_SCSR_L2_PURGE_REQ]
static inline bool GET_QME_SCSR_L2_PURGE_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_L2_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_L2_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_L2_PURGE_REQ]

//>> SET_[QME_SCSR_L2_PURGE_ABORT]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_L2_PURGE_ABORT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_L2_PURGE_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_L2_PURGE_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_L2_PURGE_ABORT]

//>> SET_[QME_SCSR_L2_PURGE_ABORT]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_L2_PURGE_ABORT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_L2_PURGE_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_L2_PURGE_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_L2_PURGE_ABORT]

//>> SET_[QME_SCSR_L2_PURGE_ABORT]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_L2_PURGE_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_L2_PURGE_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_L2_PURGE_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_L2_PURGE_ABORT]

//>> CLEAR_[QME_SCSR_L2_PURGE_ABORT]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_L2_PURGE_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_L2_PURGE_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_L2_PURGE_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_L2_PURGE_ABORT]

//>> GET_[QME_SCSR_L2_PURGE_ABORT]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_L2_PURGE_ABORT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_L2_PURGE_ABORT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_L2_PURGE_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_L2_PURGE_ABORT]

//>> GET_[QME_SCSR_L2_PURGE_ABORT]
static inline bool GET_QME_SCSR_L2_PURGE_ABORT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_L2_PURGE_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_L2_PURGE_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_L2_PURGE_ABORT]

//>> SET_[QME_SCSR_L2RCMD_INTF_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_L2RCMD_INTF_QUIESCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_L2RCMD_INTF_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_L2RCMD_INTF_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_L2RCMD_INTF_QUIESCE]

//>> SET_[QME_SCSR_L2RCMD_INTF_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_L2RCMD_INTF_QUIESCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_L2RCMD_INTF_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_L2RCMD_INTF_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_L2RCMD_INTF_QUIESCE]

//>> SET_[QME_SCSR_L2RCMD_INTF_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_L2RCMD_INTF_QUIESCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_L2RCMD_INTF_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_L2RCMD_INTF_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_L2RCMD_INTF_QUIESCE]

//>> CLEAR_[QME_SCSR_L2RCMD_INTF_QUIESCE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_L2RCMD_INTF_QUIESCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_L2RCMD_INTF_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_L2RCMD_INTF_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_L2RCMD_INTF_QUIESCE]

//>> GET_[QME_SCSR_L2RCMD_INTF_QUIESCE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_L2RCMD_INTF_QUIESCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_L2RCMD_INTF_QUIESCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_L2RCMD_INTF_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_L2RCMD_INTF_QUIESCE]

//>> GET_[QME_SCSR_L2RCMD_INTF_QUIESCE]
static inline bool GET_QME_SCSR_L2RCMD_INTF_QUIESCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_L2RCMD_INTF_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_L2RCMD_INTF_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_L2RCMD_INTF_QUIESCE]

//>> SET_[QME_SCSR_NCU_TLBIE_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_NCU_TLBIE_QUIESCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_NCU_TLBIE_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_NCU_TLBIE_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_NCU_TLBIE_QUIESCE]

//>> SET_[QME_SCSR_NCU_TLBIE_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_NCU_TLBIE_QUIESCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_NCU_TLBIE_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_NCU_TLBIE_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_NCU_TLBIE_QUIESCE]

//>> SET_[QME_SCSR_NCU_TLBIE_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_NCU_TLBIE_QUIESCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_NCU_TLBIE_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_NCU_TLBIE_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_NCU_TLBIE_QUIESCE]

//>> CLEAR_[QME_SCSR_NCU_TLBIE_QUIESCE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_NCU_TLBIE_QUIESCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_NCU_TLBIE_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_NCU_TLBIE_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_NCU_TLBIE_QUIESCE]

//>> GET_[QME_SCSR_NCU_TLBIE_QUIESCE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_NCU_TLBIE_QUIESCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_NCU_TLBIE_QUIESCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_NCU_TLBIE_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_NCU_TLBIE_QUIESCE]

//>> GET_[QME_SCSR_NCU_TLBIE_QUIESCE]
static inline bool GET_QME_SCSR_NCU_TLBIE_QUIESCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_NCU_TLBIE_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_NCU_TLBIE_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_NCU_TLBIE_QUIESCE]

//>> SET_[QME_SCSR_NCU_PURGE_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_NCU_PURGE_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_NCU_PURGE_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_NCU_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_NCU_PURGE_REQ]

//>> SET_[QME_SCSR_NCU_PURGE_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_NCU_PURGE_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_NCU_PURGE_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_NCU_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_NCU_PURGE_REQ]

//>> SET_[QME_SCSR_NCU_PURGE_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_NCU_PURGE_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_NCU_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_NCU_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_NCU_PURGE_REQ]

//>> CLEAR_[QME_SCSR_NCU_PURGE_REQ]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_NCU_PURGE_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_NCU_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_NCU_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_NCU_PURGE_REQ]

//>> GET_[QME_SCSR_NCU_PURGE_REQ]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_NCU_PURGE_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_NCU_PURGE_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_NCU_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_NCU_PURGE_REQ]

//>> GET_[QME_SCSR_NCU_PURGE_REQ]
static inline bool GET_QME_SCSR_NCU_PURGE_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_NCU_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_NCU_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_NCU_PURGE_REQ]

//>> SET_[QME_SCSR_NCU_PURGE_ABORT]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_NCU_PURGE_ABORT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_NCU_PURGE_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_NCU_PURGE_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_NCU_PURGE_ABORT]

//>> SET_[QME_SCSR_NCU_PURGE_ABORT]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_NCU_PURGE_ABORT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_NCU_PURGE_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_NCU_PURGE_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_NCU_PURGE_ABORT]

//>> SET_[QME_SCSR_NCU_PURGE_ABORT]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_NCU_PURGE_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_NCU_PURGE_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_NCU_PURGE_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_NCU_PURGE_ABORT]

//>> CLEAR_[QME_SCSR_NCU_PURGE_ABORT]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_NCU_PURGE_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_NCU_PURGE_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_NCU_PURGE_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_NCU_PURGE_ABORT]

//>> GET_[QME_SCSR_NCU_PURGE_ABORT]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_NCU_PURGE_ABORT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_NCU_PURGE_ABORT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_NCU_PURGE_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_NCU_PURGE_ABORT]

//>> GET_[QME_SCSR_NCU_PURGE_ABORT]
static inline bool GET_QME_SCSR_NCU_PURGE_ABORT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_NCU_PURGE_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_NCU_PURGE_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_NCU_PURGE_ABORT]

//>> SET_[QME_SCSR_CHTM_PURGE_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CHTM_PURGE_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_CHTM_PURGE_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_CHTM_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_CHTM_PURGE_REQ]

//>> SET_[QME_SCSR_CHTM_PURGE_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CHTM_PURGE_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_CHTM_PURGE_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_CHTM_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_CHTM_PURGE_REQ]

//>> SET_[QME_SCSR_CHTM_PURGE_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CHTM_PURGE_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_CHTM_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_CHTM_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_CHTM_PURGE_REQ]

//>> CLEAR_[QME_SCSR_CHTM_PURGE_REQ]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_CHTM_PURGE_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_CHTM_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_CHTM_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_CHTM_PURGE_REQ]

//>> GET_[QME_SCSR_CHTM_PURGE_REQ]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_CHTM_PURGE_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_CHTM_PURGE_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_CHTM_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_CHTM_PURGE_REQ]

//>> GET_[QME_SCSR_CHTM_PURGE_REQ]
static inline bool GET_QME_SCSR_CHTM_PURGE_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_CHTM_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_CHTM_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_CHTM_PURGE_REQ]

//>> SET_[QME_SCSR_PB_PURGE_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PB_PURGE_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PB_PURGE_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_PB_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PB_PURGE_REQ]

//>> SET_[QME_SCSR_PB_PURGE_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PB_PURGE_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PB_PURGE_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_PB_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PB_PURGE_REQ]

//>> SET_[QME_SCSR_PB_PURGE_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PB_PURGE_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_PB_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_PB_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PB_PURGE_REQ]

//>> CLEAR_[QME_SCSR_PB_PURGE_REQ]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_PB_PURGE_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_PB_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_PB_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_PB_PURGE_REQ]

//>> GET_[QME_SCSR_PB_PURGE_REQ]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PB_PURGE_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_PB_PURGE_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_PB_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PB_PURGE_REQ]

//>> GET_[QME_SCSR_PB_PURGE_REQ]
static inline bool GET_QME_SCSR_PB_PURGE_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_PB_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_PB_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PB_PURGE_REQ]

//>> SET_[QME_SCSR_CORE_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CORE_QUIESCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_CORE_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_CORE_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_CORE_QUIESCE]

//>> SET_[QME_SCSR_CORE_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CORE_QUIESCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_CORE_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_CORE_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_CORE_QUIESCE]

//>> SET_[QME_SCSR_CORE_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CORE_QUIESCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_CORE_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_CORE_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_CORE_QUIESCE]

//>> CLEAR_[QME_SCSR_CORE_QUIESCE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_CORE_QUIESCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_CORE_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_CORE_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_CORE_QUIESCE]

//>> GET_[QME_SCSR_CORE_QUIESCE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_CORE_QUIESCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_CORE_QUIESCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_CORE_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_CORE_QUIESCE]

//>> GET_[QME_SCSR_CORE_QUIESCE]
static inline bool GET_QME_SCSR_CORE_QUIESCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_CORE_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_CORE_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_CORE_QUIESCE]

//>> SET_[QME_SCSR_SPARE_MODE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SPARE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_SPARE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_SPARE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_SPARE_MODE]

//>> SET_[QME_SCSR_SPARE_MODE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SPARE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_SPARE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_SPARE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_SPARE_MODE]

//>> SET_[QME_SCSR_SPARE_MODE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SPARE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_SPARE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_SPARE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_SPARE_MODE]

//>> CLEAR_[QME_SCSR_SPARE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_SPARE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_SPARE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_SPARE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_SPARE_MODE]

//>> GET_[QME_SCSR_SPARE_MODE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_SPARE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_SPARE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_SPARE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_SPARE_MODE]

//>> GET_[QME_SCSR_SPARE_MODE]
static inline bool GET_QME_SCSR_SPARE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_SPARE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_SPARE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_SPARE_MODE]

//>> SET_[QME_SCSR_REG_WKUP_FILTER_DIS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_REG_WKUP_FILTER_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_REG_WKUP_FILTER_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_REG_WKUP_FILTER_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_REG_WKUP_FILTER_DIS]

//>> SET_[QME_SCSR_REG_WKUP_FILTER_DIS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_REG_WKUP_FILTER_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_REG_WKUP_FILTER_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_REG_WKUP_FILTER_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_REG_WKUP_FILTER_DIS]

//>> SET_[QME_SCSR_REG_WKUP_FILTER_DIS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_REG_WKUP_FILTER_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_REG_WKUP_FILTER_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_REG_WKUP_FILTER_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_REG_WKUP_FILTER_DIS]

//>> CLEAR_[QME_SCSR_REG_WKUP_FILTER_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_REG_WKUP_FILTER_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_REG_WKUP_FILTER_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_REG_WKUP_FILTER_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_REG_WKUP_FILTER_DIS]

//>> GET_[QME_SCSR_REG_WKUP_FILTER_DIS]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_REG_WKUP_FILTER_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_REG_WKUP_FILTER_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_REG_WKUP_FILTER_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_REG_WKUP_FILTER_DIS]

//>> GET_[QME_SCSR_REG_WKUP_FILTER_DIS]
static inline bool GET_QME_SCSR_REG_WKUP_FILTER_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_REG_WKUP_FILTER_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_REG_WKUP_FILTER_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_REG_WKUP_FILTER_DIS]

//>> SET_[QME_SCSR_SRESET_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SRESET_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_SRESET_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_SRESET_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_SRESET_REQ]

//>> SET_[QME_SCSR_SRESET_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SRESET_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_SRESET_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_SRESET_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_SRESET_REQ]

//>> SET_[QME_SCSR_SRESET_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SRESET_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_SRESET_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_SRESET_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_SRESET_REQ]

//>> CLEAR_[QME_SCSR_SRESET_REQ]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_SRESET_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_SRESET_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_SRESET_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_SRESET_REQ]

//>> GET_[QME_SCSR_SRESET_REQ]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_SRESET_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_SRESET_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_SRESET_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_SRESET_REQ]

//>> GET_[QME_SCSR_SRESET_REQ]
static inline bool GET_QME_SCSR_SRESET_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_SRESET_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_SRESET_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_SRESET_REQ]

//>> SET_[QME_SCSR_ASSERT_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ASSERT_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_ASSERT_SPECIAL_WKUP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_ASSERT_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_ASSERT_SPECIAL_WKUP_DONE]

//>> SET_[QME_SCSR_ASSERT_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ASSERT_SPECIAL_WKUP_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_ASSERT_SPECIAL_WKUP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_ASSERT_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_ASSERT_SPECIAL_WKUP_DONE]

//>> SET_[QME_SCSR_ASSERT_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ASSERT_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_ASSERT_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_ASSERT_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_ASSERT_SPECIAL_WKUP_DONE]

//>> CLEAR_[QME_SCSR_ASSERT_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_ASSERT_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_ASSERT_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_ASSERT_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_ASSERT_SPECIAL_WKUP_DONE]

//>> GET_[QME_SCSR_ASSERT_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_ASSERT_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_ASSERT_SPECIAL_WKUP_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_ASSERT_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_ASSERT_SPECIAL_WKUP_DONE]

//>> GET_[QME_SCSR_ASSERT_SPECIAL_WKUP_DONE]
static inline bool GET_QME_SCSR_ASSERT_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_ASSERT_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_ASSERT_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_ASSERT_SPECIAL_WKUP_DONE]

//>> SET_[QME_SCSR_SPARE_OUT]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SPARE_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_SPARE_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_SPARE_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_SPARE_OUT]

//>> SET_[QME_SCSR_SPARE_OUT]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SPARE_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_SPARE_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_SPARE_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_SPARE_OUT]

//>> SET_[QME_SCSR_SPARE_OUT]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SPARE_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_SPARE_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_SPARE_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_SPARE_OUT]

//>> CLEAR_[QME_SCSR_SPARE_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_SPARE_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_SPARE_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_SPARE_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_SPARE_OUT]

//>> GET_[QME_SCSR_SPARE_OUT]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_SPARE_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_SPARE_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_SPARE_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_SPARE_OUT]

//>> GET_[QME_SCSR_SPARE_OUT]
static inline bool GET_QME_SCSR_SPARE_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_SPARE_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_SPARE_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_SPARE_OUT]

//>> SET_[QME_SCSR_CORE_INTR_SAMPLE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CORE_INTR_SAMPLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_CORE_INTR_SAMPLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_CORE_INTR_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_CORE_INTR_SAMPLE]

//>> SET_[QME_SCSR_CORE_INTR_SAMPLE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CORE_INTR_SAMPLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_CORE_INTR_SAMPLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_CORE_INTR_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_CORE_INTR_SAMPLE]

//>> SET_[QME_SCSR_CORE_INTR_SAMPLE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CORE_INTR_SAMPLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_CORE_INTR_SAMPLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_CORE_INTR_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_CORE_INTR_SAMPLE]

//>> CLEAR_[QME_SCSR_CORE_INTR_SAMPLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_CORE_INTR_SAMPLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_CORE_INTR_SAMPLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_CORE_INTR_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_CORE_INTR_SAMPLE]

//>> GET_[QME_SCSR_CORE_INTR_SAMPLE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_CORE_INTR_SAMPLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_CORE_INTR_SAMPLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_CORE_INTR_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_CORE_INTR_SAMPLE]

//>> GET_[QME_SCSR_CORE_INTR_SAMPLE]
static inline bool GET_QME_SCSR_CORE_INTR_SAMPLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_CORE_INTR_SAMPLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_CORE_INTR_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_CORE_INTR_SAMPLE]

//>> SET_[QME_SCSR_IGNORE_PMCR_RECENT]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_IGNORE_PMCR_RECENT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_IGNORE_PMCR_RECENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_IGNORE_PMCR_RECENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_IGNORE_PMCR_RECENT]

//>> SET_[QME_SCSR_IGNORE_PMCR_RECENT]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_IGNORE_PMCR_RECENT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_IGNORE_PMCR_RECENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_IGNORE_PMCR_RECENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_IGNORE_PMCR_RECENT]

//>> SET_[QME_SCSR_IGNORE_PMCR_RECENT]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_IGNORE_PMCR_RECENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_IGNORE_PMCR_RECENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_IGNORE_PMCR_RECENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_IGNORE_PMCR_RECENT]

//>> CLEAR_[QME_SCSR_IGNORE_PMCR_RECENT]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_IGNORE_PMCR_RECENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_IGNORE_PMCR_RECENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_IGNORE_PMCR_RECENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_IGNORE_PMCR_RECENT]

//>> GET_[QME_SCSR_IGNORE_PMCR_RECENT]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_IGNORE_PMCR_RECENT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_IGNORE_PMCR_RECENT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_IGNORE_PMCR_RECENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_IGNORE_PMCR_RECENT]

//>> GET_[QME_SCSR_IGNORE_PMCR_RECENT]
static inline bool GET_QME_SCSR_IGNORE_PMCR_RECENT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_IGNORE_PMCR_RECENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_IGNORE_PMCR_RECENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_IGNORE_PMCR_RECENT]

//>> SET_[QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE]

//>> SET_[QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE]

//>> SET_[QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE]

//>> CLEAR_[QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE]

//>> GET_[QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE]

//>> GET_[QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE]
static inline bool GET_QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE]

//>> SET_[QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE]

//>> SET_[QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE]

//>> SET_[QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE]

//>> CLEAR_[QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE]

//>> GET_[QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE]

//>> GET_[QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE]
static inline bool GET_QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE]

//>> SET_[QME_SCSR_AUTO_PMSR_SHIFT_DIS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_AUTO_PMSR_SHIFT_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_AUTO_PMSR_SHIFT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_AUTO_PMSR_SHIFT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_AUTO_PMSR_SHIFT_DIS]

//>> SET_[QME_SCSR_AUTO_PMSR_SHIFT_DIS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_AUTO_PMSR_SHIFT_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_AUTO_PMSR_SHIFT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_AUTO_PMSR_SHIFT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_AUTO_PMSR_SHIFT_DIS]

//>> SET_[QME_SCSR_AUTO_PMSR_SHIFT_DIS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_AUTO_PMSR_SHIFT_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_AUTO_PMSR_SHIFT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_AUTO_PMSR_SHIFT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_AUTO_PMSR_SHIFT_DIS]

//>> CLEAR_[QME_SCSR_AUTO_PMSR_SHIFT_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_AUTO_PMSR_SHIFT_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_AUTO_PMSR_SHIFT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_AUTO_PMSR_SHIFT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_AUTO_PMSR_SHIFT_DIS]

//>> GET_[QME_SCSR_AUTO_PMSR_SHIFT_DIS]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_AUTO_PMSR_SHIFT_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_AUTO_PMSR_SHIFT_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_AUTO_PMSR_SHIFT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_AUTO_PMSR_SHIFT_DIS]

//>> GET_[QME_SCSR_AUTO_PMSR_SHIFT_DIS]
static inline bool GET_QME_SCSR_AUTO_PMSR_SHIFT_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_AUTO_PMSR_SHIFT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_AUTO_PMSR_SHIFT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_AUTO_PMSR_SHIFT_DIS]

//>> SET_[QME_SCSR_REFRESH_PMSR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_REFRESH_PMSR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_REFRESH_PMSR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_REFRESH_PMSR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_REFRESH_PMSR]

//>> SET_[QME_SCSR_REFRESH_PMSR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_REFRESH_PMSR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_REFRESH_PMSR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_REFRESH_PMSR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_REFRESH_PMSR]

//>> SET_[QME_SCSR_REFRESH_PMSR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_REFRESH_PMSR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_REFRESH_PMSR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_REFRESH_PMSR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_REFRESH_PMSR]

//>> CLEAR_[QME_SCSR_REFRESH_PMSR]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_REFRESH_PMSR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_REFRESH_PMSR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_REFRESH_PMSR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_REFRESH_PMSR]

//>> GET_[QME_SCSR_REFRESH_PMSR]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_REFRESH_PMSR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_REFRESH_PMSR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_REFRESH_PMSR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_REFRESH_PMSR]

//>> GET_[QME_SCSR_REFRESH_PMSR]
static inline bool GET_QME_SCSR_REFRESH_PMSR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_REFRESH_PMSR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_REFRESH_PMSR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_REFRESH_PMSR]

//>> SET_[QME_SCSR_BLOCK_INTR_OUTPUTS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_BLOCK_INTR_OUTPUTS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_BLOCK_INTR_OUTPUTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_BLOCK_INTR_OUTPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_BLOCK_INTR_OUTPUTS]

//>> SET_[QME_SCSR_BLOCK_INTR_OUTPUTS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_BLOCK_INTR_OUTPUTS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_BLOCK_INTR_OUTPUTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_BLOCK_INTR_OUTPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_BLOCK_INTR_OUTPUTS]

//>> SET_[QME_SCSR_BLOCK_INTR_OUTPUTS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_BLOCK_INTR_OUTPUTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_BLOCK_INTR_OUTPUTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_BLOCK_INTR_OUTPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_BLOCK_INTR_OUTPUTS]

//>> CLEAR_[QME_SCSR_BLOCK_INTR_OUTPUTS]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_BLOCK_INTR_OUTPUTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_BLOCK_INTR_OUTPUTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_BLOCK_INTR_OUTPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_BLOCK_INTR_OUTPUTS]

//>> GET_[QME_SCSR_BLOCK_INTR_OUTPUTS]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_BLOCK_INTR_OUTPUTS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_BLOCK_INTR_OUTPUTS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_BLOCK_INTR_OUTPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_BLOCK_INTR_OUTPUTS]

//>> GET_[QME_SCSR_BLOCK_INTR_OUTPUTS]
static inline bool GET_QME_SCSR_BLOCK_INTR_OUTPUTS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_BLOCK_INTR_OUTPUTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_BLOCK_INTR_OUTPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_BLOCK_INTR_OUTPUTS]

//>> SET_[QME_SCSR_BLOCK_INTR_INPUTS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_BLOCK_INTR_INPUTS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_BLOCK_INTR_INPUTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_BLOCK_INTR_INPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_BLOCK_INTR_INPUTS]

//>> SET_[QME_SCSR_BLOCK_INTR_INPUTS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_BLOCK_INTR_INPUTS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_BLOCK_INTR_INPUTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_BLOCK_INTR_INPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_BLOCK_INTR_INPUTS]

//>> SET_[QME_SCSR_BLOCK_INTR_INPUTS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_BLOCK_INTR_INPUTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_BLOCK_INTR_INPUTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_BLOCK_INTR_INPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_BLOCK_INTR_INPUTS]

//>> CLEAR_[QME_SCSR_BLOCK_INTR_INPUTS]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_BLOCK_INTR_INPUTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_BLOCK_INTR_INPUTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_BLOCK_INTR_INPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_BLOCK_INTR_INPUTS]

//>> GET_[QME_SCSR_BLOCK_INTR_INPUTS]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_BLOCK_INTR_INPUTS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_BLOCK_INTR_INPUTS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_BLOCK_INTR_INPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_BLOCK_INTR_INPUTS]

//>> GET_[QME_SCSR_BLOCK_INTR_INPUTS]
static inline bool GET_QME_SCSR_BLOCK_INTR_INPUTS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_BLOCK_INTR_INPUTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_BLOCK_INTR_INPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_BLOCK_INTR_INPUTS]

//>> SET_[QME_SCSR_ENABLE_PECE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ENABLE_PECE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_ENABLE_PECE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_ENABLE_PECE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_ENABLE_PECE]

//>> SET_[QME_SCSR_ENABLE_PECE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ENABLE_PECE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_ENABLE_PECE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_ENABLE_PECE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_ENABLE_PECE]

//>> SET_[QME_SCSR_ENABLE_PECE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ENABLE_PECE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_ENABLE_PECE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_ENABLE_PECE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_ENABLE_PECE]

//>> CLEAR_[QME_SCSR_ENABLE_PECE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_ENABLE_PECE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_ENABLE_PECE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_ENABLE_PECE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_ENABLE_PECE]

//>> GET_[QME_SCSR_ENABLE_PECE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_ENABLE_PECE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_ENABLE_PECE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_ENABLE_PECE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_ENABLE_PECE]

//>> GET_[QME_SCSR_ENABLE_PECE]
static inline bool GET_QME_SCSR_ENABLE_PECE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_ENABLE_PECE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_ENABLE_PECE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_ENABLE_PECE]

//>> SET_[QME_SCSR_CTFS_WKUP_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CTFS_WKUP_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_CTFS_WKUP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_CTFS_WKUP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_CTFS_WKUP_ENABLE]

//>> SET_[QME_SCSR_CTFS_WKUP_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CTFS_WKUP_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_CTFS_WKUP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_CTFS_WKUP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_CTFS_WKUP_ENABLE]

//>> SET_[QME_SCSR_CTFS_WKUP_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CTFS_WKUP_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_CTFS_WKUP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_CTFS_WKUP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_CTFS_WKUP_ENABLE]

//>> CLEAR_[QME_SCSR_CTFS_WKUP_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_CTFS_WKUP_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_CTFS_WKUP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_CTFS_WKUP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_CTFS_WKUP_ENABLE]

//>> GET_[QME_SCSR_CTFS_WKUP_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_CTFS_WKUP_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_CTFS_WKUP_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_CTFS_WKUP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_CTFS_WKUP_ENABLE]

//>> GET_[QME_SCSR_CTFS_WKUP_ENABLE]
static inline bool GET_QME_SCSR_CTFS_WKUP_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_CTFS_WKUP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_CTFS_WKUP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_CTFS_WKUP_ENABLE]

//>> SET_[QME_SCSR_PC_COPY_FUSED_SPRS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_COPY_FUSED_SPRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PC_COPY_FUSED_SPRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_PC_COPY_FUSED_SPRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PC_COPY_FUSED_SPRS]

//>> SET_[QME_SCSR_PC_COPY_FUSED_SPRS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_COPY_FUSED_SPRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PC_COPY_FUSED_SPRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_PC_COPY_FUSED_SPRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PC_COPY_FUSED_SPRS]

//>> SET_[QME_SCSR_PC_COPY_FUSED_SPRS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_COPY_FUSED_SPRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_PC_COPY_FUSED_SPRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_PC_COPY_FUSED_SPRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PC_COPY_FUSED_SPRS]

//>> CLEAR_[QME_SCSR_PC_COPY_FUSED_SPRS]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_PC_COPY_FUSED_SPRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_PC_COPY_FUSED_SPRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_PC_COPY_FUSED_SPRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_PC_COPY_FUSED_SPRS]

//>> GET_[QME_SCSR_PC_COPY_FUSED_SPRS]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PC_COPY_FUSED_SPRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_PC_COPY_FUSED_SPRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_PC_COPY_FUSED_SPRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PC_COPY_FUSED_SPRS]

//>> GET_[QME_SCSR_PC_COPY_FUSED_SPRS]
static inline bool GET_QME_SCSR_PC_COPY_FUSED_SPRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_PC_COPY_FUSED_SPRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_PC_COPY_FUSED_SPRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PC_COPY_FUSED_SPRS]

//>> SET_[QME_SCSR_SINGLE_LPAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SINGLE_LPAR_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_SINGLE_LPAR_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_SINGLE_LPAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_SINGLE_LPAR_MODE]

//>> SET_[QME_SCSR_SINGLE_LPAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SINGLE_LPAR_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_SINGLE_LPAR_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_SINGLE_LPAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_SINGLE_LPAR_MODE]

//>> SET_[QME_SCSR_SINGLE_LPAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SINGLE_LPAR_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_SINGLE_LPAR_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_SINGLE_LPAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_SINGLE_LPAR_MODE]

//>> CLEAR_[QME_SCSR_SINGLE_LPAR_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_SINGLE_LPAR_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_SINGLE_LPAR_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_SINGLE_LPAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_SINGLE_LPAR_MODE]

//>> GET_[QME_SCSR_SINGLE_LPAR_MODE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_SINGLE_LPAR_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_SINGLE_LPAR_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_SINGLE_LPAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_SINGLE_LPAR_MODE]

//>> GET_[QME_SCSR_SINGLE_LPAR_MODE]
static inline bool GET_QME_SCSR_SINGLE_LPAR_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_SINGLE_LPAR_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_SINGLE_LPAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_SINGLE_LPAR_MODE]

//>> SET_[QME_SCSR_PM_BLOCK_INTR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_BLOCK_INTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PM_BLOCK_INTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PM_BLOCK_INTR]

//>> SET_[QME_SCSR_PM_BLOCK_INTR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_BLOCK_INTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PM_BLOCK_INTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PM_BLOCK_INTR]

//>> SET_[QME_SCSR_PM_BLOCK_INTR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_BLOCK_INTR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_PM_BLOCK_INTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PM_BLOCK_INTR]

//>> CLEAR_[QME_SCSR_PM_BLOCK_INTR]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_PM_BLOCK_INTR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_PM_BLOCK_INTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_PM_BLOCK_INTR]

//>> GET_[QME_SCSR_PM_BLOCK_INTR]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PM_BLOCK_INTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_PM_BLOCK_INTR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PM_BLOCK_INTR]

//>> GET_[QME_SCSR_PM_BLOCK_INTR]
static inline bool GET_QME_SCSR_PM_BLOCK_INTR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_PM_BLOCK_INTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PM_BLOCK_INTR]

//>> SET_[QME_SCSR_PM_EXIT]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_EXIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PM_EXIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PM_EXIT]

//>> SET_[QME_SCSR_PM_EXIT]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_EXIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PM_EXIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PM_EXIT]

//>> SET_[QME_SCSR_PM_EXIT]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_EXIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_PM_EXIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PM_EXIT]

//>> CLEAR_[QME_SCSR_PM_EXIT]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_PM_EXIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_PM_EXIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_PM_EXIT]

//>> GET_[QME_SCSR_PM_EXIT]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PM_EXIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_PM_EXIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PM_EXIT]

//>> GET_[QME_SCSR_PM_EXIT]
static inline bool GET_QME_SCSR_PM_EXIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_PM_EXIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PM_EXIT]

//>> SET_[QME_SCSR_PM_ENTRY_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_ENTRY_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PM_ENTRY_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_PM_ENTRY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PM_ENTRY_LIMIT]

//>> SET_[QME_SCSR_PM_ENTRY_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_ENTRY_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PM_ENTRY_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_PM_ENTRY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PM_ENTRY_LIMIT]

//>> SET_[QME_SCSR_PM_ENTRY_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_ENTRY_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_PM_ENTRY_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_PM_ENTRY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PM_ENTRY_LIMIT]

//>> CLEAR_[QME_SCSR_PM_ENTRY_LIMIT]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_PM_ENTRY_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_PM_ENTRY_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_PM_ENTRY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_PM_ENTRY_LIMIT]

//>> GET_[QME_SCSR_PM_ENTRY_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PM_ENTRY_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_PM_ENTRY_LIMIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_PM_ENTRY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PM_ENTRY_LIMIT]

//>> GET_[QME_SCSR_PM_ENTRY_LIMIT]
static inline bool GET_QME_SCSR_PM_ENTRY_LIMIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_PM_ENTRY_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_PM_ENTRY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PM_ENTRY_LIMIT]

//>> SET_[QME_SCSR_PC_SPARE_IN]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_SPARE_IN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PC_SPARE_IN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_PC_SPARE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PC_SPARE_IN]

//>> SET_[QME_SCSR_PC_SPARE_IN]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_SPARE_IN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PC_SPARE_IN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_PC_SPARE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PC_SPARE_IN]

//>> SET_[QME_SCSR_PC_SPARE_IN]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_SPARE_IN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_PC_SPARE_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_PC_SPARE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PC_SPARE_IN]

//>> CLEAR_[QME_SCSR_PC_SPARE_IN]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_PC_SPARE_IN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_PC_SPARE_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_PC_SPARE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_PC_SPARE_IN]

//>> GET_[QME_SCSR_PC_SPARE_IN]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PC_SPARE_IN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_PC_SPARE_IN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_PC_SPARE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PC_SPARE_IN]

//>> GET_[QME_SCSR_PC_SPARE_IN]
static inline bool GET_QME_SCSR_PC_SPARE_IN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_PC_SPARE_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_PC_SPARE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PC_SPARE_IN]

//>> SET_[QME_SCSR_HBUS_INACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_HBUS_INACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_HBUS_INACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_HBUS_INACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_HBUS_INACTIVE]

//>> SET_[QME_SCSR_HBUS_INACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_HBUS_INACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_HBUS_INACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_HBUS_INACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_HBUS_INACTIVE]

//>> SET_[QME_SCSR_HBUS_INACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_HBUS_INACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_HBUS_INACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_HBUS_INACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_HBUS_INACTIVE]

//>> CLEAR_[QME_SCSR_HBUS_INACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_HBUS_INACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_HBUS_INACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_HBUS_INACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_HBUS_INACTIVE]

//>> GET_[QME_SCSR_HBUS_INACTIVE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_HBUS_INACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_HBUS_INACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_HBUS_INACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_HBUS_INACTIVE]

//>> GET_[QME_SCSR_HBUS_INACTIVE]
static inline bool GET_QME_SCSR_HBUS_INACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_HBUS_INACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_HBUS_INACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_HBUS_INACTIVE]

//>> SET_[QME_SCSR_L2_PURGE_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_L2_PURGE_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_L2_PURGE_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_L2_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_L2_PURGE_DONE]

//>> SET_[QME_SCSR_L2_PURGE_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_L2_PURGE_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_L2_PURGE_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_L2_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_L2_PURGE_DONE]

//>> SET_[QME_SCSR_L2_PURGE_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_L2_PURGE_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_L2_PURGE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_L2_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_L2_PURGE_DONE]

//>> CLEAR_[QME_SCSR_L2_PURGE_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_L2_PURGE_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_L2_PURGE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_L2_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_L2_PURGE_DONE]

//>> GET_[QME_SCSR_L2_PURGE_DONE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_L2_PURGE_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_L2_PURGE_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_L2_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_L2_PURGE_DONE]

//>> GET_[QME_SCSR_L2_PURGE_DONE]
static inline bool GET_QME_SCSR_L2_PURGE_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_L2_PURGE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_L2_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_L2_PURGE_DONE]

//>> SET_[QME_SCSR_NCU_PURGE_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_NCU_PURGE_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_NCU_PURGE_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_NCU_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_NCU_PURGE_DONE]

//>> SET_[QME_SCSR_NCU_PURGE_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_NCU_PURGE_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_NCU_PURGE_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_NCU_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_NCU_PURGE_DONE]

//>> SET_[QME_SCSR_NCU_PURGE_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_NCU_PURGE_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_NCU_PURGE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_NCU_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_NCU_PURGE_DONE]

//>> CLEAR_[QME_SCSR_NCU_PURGE_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_NCU_PURGE_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_NCU_PURGE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_NCU_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_NCU_PURGE_DONE]

//>> GET_[QME_SCSR_NCU_PURGE_DONE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_NCU_PURGE_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_NCU_PURGE_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_NCU_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_NCU_PURGE_DONE]

//>> GET_[QME_SCSR_NCU_PURGE_DONE]
static inline bool GET_QME_SCSR_NCU_PURGE_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_NCU_PURGE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_NCU_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_NCU_PURGE_DONE]

//>> SET_[QME_SCSR_PC_FUSED_COPY_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_FUSED_COPY_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PC_FUSED_COPY_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_PC_FUSED_COPY_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PC_FUSED_COPY_DONE]

//>> SET_[QME_SCSR_PC_FUSED_COPY_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_FUSED_COPY_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PC_FUSED_COPY_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_PC_FUSED_COPY_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PC_FUSED_COPY_DONE]

//>> SET_[QME_SCSR_PC_FUSED_COPY_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_FUSED_COPY_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_PC_FUSED_COPY_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_PC_FUSED_COPY_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PC_FUSED_COPY_DONE]

//>> CLEAR_[QME_SCSR_PC_FUSED_COPY_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_PC_FUSED_COPY_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_PC_FUSED_COPY_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_PC_FUSED_COPY_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_PC_FUSED_COPY_DONE]

//>> GET_[QME_SCSR_PC_FUSED_COPY_DONE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PC_FUSED_COPY_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_PC_FUSED_COPY_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_PC_FUSED_COPY_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PC_FUSED_COPY_DONE]

//>> GET_[QME_SCSR_PC_FUSED_COPY_DONE]
static inline bool GET_QME_SCSR_PC_FUSED_COPY_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_PC_FUSED_COPY_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_PC_FUSED_COPY_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PC_FUSED_COPY_DONE]

//>> SET_[QME_SCSR_CHTM_PURGE_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CHTM_PURGE_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_CHTM_PURGE_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_CHTM_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_CHTM_PURGE_DONE]

//>> SET_[QME_SCSR_CHTM_PURGE_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CHTM_PURGE_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_CHTM_PURGE_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_CHTM_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_CHTM_PURGE_DONE]

//>> SET_[QME_SCSR_CHTM_PURGE_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CHTM_PURGE_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_CHTM_PURGE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_CHTM_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_CHTM_PURGE_DONE]

//>> CLEAR_[QME_SCSR_CHTM_PURGE_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_CHTM_PURGE_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_CHTM_PURGE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_CHTM_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_CHTM_PURGE_DONE]

//>> GET_[QME_SCSR_CHTM_PURGE_DONE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_CHTM_PURGE_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_CHTM_PURGE_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_CHTM_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_CHTM_PURGE_DONE]

//>> GET_[QME_SCSR_CHTM_PURGE_DONE]
static inline bool GET_QME_SCSR_CHTM_PURGE_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_CHTM_PURGE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_CHTM_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_CHTM_PURGE_DONE]

//>> SET_[QME_SCSR_PB_PURGE_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PB_PURGE_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PB_PURGE_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_PB_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PB_PURGE_DONE]

//>> SET_[QME_SCSR_PB_PURGE_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PB_PURGE_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PB_PURGE_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_PB_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PB_PURGE_DONE]

//>> SET_[QME_SCSR_PB_PURGE_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PB_PURGE_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_PB_PURGE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_PB_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PB_PURGE_DONE]

//>> CLEAR_[QME_SCSR_PB_PURGE_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_PB_PURGE_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_PB_PURGE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_PB_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_PB_PURGE_DONE]

//>> GET_[QME_SCSR_PB_PURGE_DONE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PB_PURGE_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_PB_PURGE_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_PB_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PB_PURGE_DONE]

//>> GET_[QME_SCSR_PB_PURGE_DONE]
static inline bool GET_QME_SCSR_PB_PURGE_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_PB_PURGE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_PB_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PB_PURGE_DONE]

//>> SET_[QME_SCSR_CORE_QUIESCED]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CORE_QUIESCED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_CORE_QUIESCED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_CORE_QUIESCED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_CORE_QUIESCED]

//>> SET_[QME_SCSR_CORE_QUIESCED]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CORE_QUIESCED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_CORE_QUIESCED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_CORE_QUIESCED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_CORE_QUIESCED]

//>> SET_[QME_SCSR_CORE_QUIESCED]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CORE_QUIESCED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_CORE_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_CORE_QUIESCED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_CORE_QUIESCED]

//>> CLEAR_[QME_SCSR_CORE_QUIESCED]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_CORE_QUIESCED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_CORE_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_CORE_QUIESCED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_CORE_QUIESCED]

//>> GET_[QME_SCSR_CORE_QUIESCED]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_CORE_QUIESCED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_CORE_QUIESCED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_CORE_QUIESCED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_CORE_QUIESCED]

//>> GET_[QME_SCSR_CORE_QUIESCED]
static inline bool GET_QME_SCSR_CORE_QUIESCED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_CORE_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_CORE_QUIESCED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_CORE_QUIESCED]

//>> SET_[QME_SCSR_PC_INTR_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_INTR_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PC_INTR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_PC_INTR_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PC_INTR_PENDING]

//>> SET_[QME_SCSR_PC_INTR_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_INTR_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PC_INTR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_PC_INTR_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PC_INTR_PENDING]

//>> SET_[QME_SCSR_PC_INTR_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_INTR_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_PC_INTR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_PC_INTR_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PC_INTR_PENDING]

//>> CLEAR_[QME_SCSR_PC_INTR_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_PC_INTR_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_PC_INTR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_PC_INTR_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_PC_INTR_PENDING]

//>> GET_[QME_SCSR_PC_INTR_PENDING]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PC_INTR_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_PC_INTR_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_PC_INTR_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PC_INTR_PENDING]

//>> GET_[QME_SCSR_PC_INTR_PENDING]
static inline bool GET_QME_SCSR_PC_INTR_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_PC_INTR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_PC_INTR_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PC_INTR_PENDING]

//>> SET_[QME_SCSR_STOP_SHIFT_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_STOP_SHIFT_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_STOP_SHIFT_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_STOP_SHIFT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_STOP_SHIFT_ACTIVE]

//>> SET_[QME_SCSR_STOP_SHIFT_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_STOP_SHIFT_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_STOP_SHIFT_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_STOP_SHIFT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_STOP_SHIFT_ACTIVE]

//>> SET_[QME_SCSR_STOP_SHIFT_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_STOP_SHIFT_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_STOP_SHIFT_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_STOP_SHIFT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_STOP_SHIFT_ACTIVE]

//>> CLEAR_[QME_SCSR_STOP_SHIFT_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_STOP_SHIFT_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_STOP_SHIFT_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_STOP_SHIFT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_STOP_SHIFT_ACTIVE]

//>> GET_[QME_SCSR_STOP_SHIFT_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_STOP_SHIFT_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_STOP_SHIFT_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_STOP_SHIFT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_STOP_SHIFT_ACTIVE]

//>> GET_[QME_SCSR_STOP_SHIFT_ACTIVE]
static inline bool GET_QME_SCSR_STOP_SHIFT_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_STOP_SHIFT_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_STOP_SHIFT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_STOP_SHIFT_ACTIVE]

//>> SET_[QME_SCSR_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_SPECIAL_WKUP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_SPECIAL_WKUP_DONE]

//>> SET_[QME_SCSR_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SPECIAL_WKUP_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_SPECIAL_WKUP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_SPECIAL_WKUP_DONE]

//>> SET_[QME_SCSR_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_SPECIAL_WKUP_DONE]

//>> CLEAR_[QME_SCSR_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_SPECIAL_WKUP_DONE]

//>> GET_[QME_SCSR_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_SPECIAL_WKUP_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_SPECIAL_WKUP_DONE]

//>> GET_[QME_SCSR_SPECIAL_WKUP_DONE]
static inline bool GET_QME_SCSR_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_SPECIAL_WKUP_DONE]

//>> SET_[QME_SCSR_SPARE_IN]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SPARE_IN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_SPARE_IN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_SPARE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_SPARE_IN]

//>> SET_[QME_SCSR_SPARE_IN]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SPARE_IN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_SPARE_IN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_SPARE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_SPARE_IN]

//>> SET_[QME_SCSR_SPARE_IN]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SPARE_IN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_SPARE_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_SPARE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_SPARE_IN]

//>> CLEAR_[QME_SCSR_SPARE_IN]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_SPARE_IN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_SPARE_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_SPARE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_SPARE_IN]

//>> GET_[QME_SCSR_SPARE_IN]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_SPARE_IN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_SPARE_IN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_SPARE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_SPARE_IN]

//>> GET_[QME_SCSR_SPARE_IN]
static inline bool GET_QME_SCSR_SPARE_IN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_SPARE_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_SPARE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_SPARE_IN]

//>> SET_[QME_SCSR_PSSCR_POWEROFF_ALLOWED]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PSSCR_POWEROFF_ALLOWED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PSSCR_POWEROFF_ALLOWED,
           QME_SCSR_PSSCR_POWEROFF_ALLOWED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_PSSCR_POWEROFF_ALLOWED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PSSCR_POWEROFF_ALLOWED]

//>> SET_[QME_SCSR_PSSCR_POWEROFF_ALLOWED]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PSSCR_POWEROFF_ALLOWED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PSSCR_POWEROFF_ALLOWED,
           QME_SCSR_PSSCR_POWEROFF_ALLOWED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_PSSCR_POWEROFF_ALLOWED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PSSCR_POWEROFF_ALLOWED]

//>> GET_[QME_SCSR_PSSCR_POWEROFF_ALLOWED]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PSSCR_POWEROFF_ALLOWED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_PSSCR_POWEROFF_ALLOWED,
           QME_SCSR_PSSCR_POWEROFF_ALLOWED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_PSSCR_POWEROFF_ALLOWED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PSSCR_POWEROFF_ALLOWED]

//>> SET_[QME_SCSR_PC_THREAD_INSTR_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_THREAD_INSTR_RUNNING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PC_THREAD_INSTR_RUNNING,
           QME_SCSR_PC_THREAD_INSTR_RUNNING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_PC_THREAD_INSTR_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PC_THREAD_INSTR_RUNNING]

//>> SET_[QME_SCSR_PC_THREAD_INSTR_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_THREAD_INSTR_RUNNING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PC_THREAD_INSTR_RUNNING,
           QME_SCSR_PC_THREAD_INSTR_RUNNING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_PC_THREAD_INSTR_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PC_THREAD_INSTR_RUNNING]

//>> GET_[QME_SCSR_PC_THREAD_INSTR_RUNNING]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PC_THREAD_INSTR_RUNNING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_PC_THREAD_INSTR_RUNNING,
           QME_SCSR_PC_THREAD_INSTR_RUNNING_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_PC_THREAD_INSTR_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PC_THREAD_INSTR_RUNNING]

//>> SET_[QME_SCSR_PMSR_SHIFT_INACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PMSR_SHIFT_INACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PMSR_SHIFT_INACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_PMSR_SHIFT_INACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PMSR_SHIFT_INACTIVE]

//>> SET_[QME_SCSR_PMSR_SHIFT_INACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PMSR_SHIFT_INACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PMSR_SHIFT_INACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_PMSR_SHIFT_INACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PMSR_SHIFT_INACTIVE]

//>> SET_[QME_SCSR_PMSR_SHIFT_INACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PMSR_SHIFT_INACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_PMSR_SHIFT_INACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_PMSR_SHIFT_INACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PMSR_SHIFT_INACTIVE]

//>> CLEAR_[QME_SCSR_PMSR_SHIFT_INACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_PMSR_SHIFT_INACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_PMSR_SHIFT_INACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_PMSR_SHIFT_INACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_PMSR_SHIFT_INACTIVE]

//>> GET_[QME_SCSR_PMSR_SHIFT_INACTIVE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PMSR_SHIFT_INACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_PMSR_SHIFT_INACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_PMSR_SHIFT_INACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PMSR_SHIFT_INACTIVE]

//>> GET_[QME_SCSR_PMSR_SHIFT_INACTIVE]
static inline bool GET_QME_SCSR_PMSR_SHIFT_INACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_PMSR_SHIFT_INACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_PMSR_SHIFT_INACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PMSR_SHIFT_INACTIVE]

//>> SET_[QME_SCSR_OTHER_DPDES_INTR_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_OTHER_DPDES_INTR_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_OTHER_DPDES_INTR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_OTHER_DPDES_INTR_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_OTHER_DPDES_INTR_PENDING]

//>> SET_[QME_SCSR_OTHER_DPDES_INTR_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_OTHER_DPDES_INTR_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_OTHER_DPDES_INTR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_OTHER_DPDES_INTR_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_OTHER_DPDES_INTR_PENDING]

//>> SET_[QME_SCSR_OTHER_DPDES_INTR_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_OTHER_DPDES_INTR_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_OTHER_DPDES_INTR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_OTHER_DPDES_INTR_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_OTHER_DPDES_INTR_PENDING]

//>> CLEAR_[QME_SCSR_OTHER_DPDES_INTR_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_OTHER_DPDES_INTR_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_OTHER_DPDES_INTR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_OTHER_DPDES_INTR_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_OTHER_DPDES_INTR_PENDING]

//>> GET_[QME_SCSR_OTHER_DPDES_INTR_PENDING]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_OTHER_DPDES_INTR_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_OTHER_DPDES_INTR_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_OTHER_DPDES_INTR_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_OTHER_DPDES_INTR_PENDING]

//>> GET_[QME_SCSR_OTHER_DPDES_INTR_PENDING]
static inline bool GET_QME_SCSR_OTHER_DPDES_INTR_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_OTHER_DPDES_INTR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_OTHER_DPDES_INTR_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_OTHER_DPDES_INTR_PENDING]

//>> SET_[QME_SCSR_PC_UNMASKED_ATTN]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_UNMASKED_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PC_UNMASKED_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_PC_UNMASKED_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PC_UNMASKED_ATTN]

//>> SET_[QME_SCSR_PC_UNMASKED_ATTN]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_UNMASKED_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PC_UNMASKED_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_PC_UNMASKED_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PC_UNMASKED_ATTN]

//>> SET_[QME_SCSR_PC_UNMASKED_ATTN]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_UNMASKED_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_PC_UNMASKED_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_PC_UNMASKED_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PC_UNMASKED_ATTN]

//>> CLEAR_[QME_SCSR_PC_UNMASKED_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_PC_UNMASKED_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_PC_UNMASKED_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_PC_UNMASKED_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_PC_UNMASKED_ATTN]

//>> GET_[QME_SCSR_PC_UNMASKED_ATTN]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PC_UNMASKED_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_PC_UNMASKED_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_PC_UNMASKED_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PC_UNMASKED_ATTN]

//>> GET_[QME_SCSR_PC_UNMASKED_ATTN]
static inline bool GET_QME_SCSR_PC_UNMASKED_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_PC_UNMASKED_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_PC_UNMASKED_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PC_UNMASKED_ATTN]

//>> SET_[QME_SCSR_PM_STATE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_STATE_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PM_STATE_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_PM_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PM_STATE_ACTIVE]

//>> SET_[QME_SCSR_PM_STATE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_STATE_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PM_STATE_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_PM_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PM_STATE_ACTIVE]

//>> SET_[QME_SCSR_PM_STATE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_STATE_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_SCSR_PM_STATE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SCSR_PM_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PM_STATE_ACTIVE]

//>> CLEAR_[QME_SCSR_PM_STATE_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_PM_STATE_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_SCSR_PM_STATE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SCSR_PM_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCSR_PM_STATE_ACTIVE]

//>> GET_[QME_SCSR_PM_STATE_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PM_STATE_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_PM_STATE_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_PM_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PM_STATE_ACTIVE]

//>> GET_[QME_SCSR_PM_STATE_ACTIVE]
static inline bool GET_QME_SCSR_PM_STATE_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_SCSR_PM_STATE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SCSR_PM_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PM_STATE_ACTIVE]

//>> SET_[QME_SCSR_PM_STATE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PM_STATE,
           QME_SCSR_PM_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCSR_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PM_STATE]

//>> SET_[QME_SCSR_PM_STATE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_SCSR_PM_STATE,
           QME_SCSR_PM_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCSR_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCSR_PM_STATE]

//>> GET_[QME_SCSR_PM_STATE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PM_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM2, QME_SCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_SCSR_PM_STATE,
           QME_SCSR_PM_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCSR_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCSR_PM_STATE]

//>> PREP_[QME_TFCSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_TFCSR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_TFCSR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_TFCSR]

//>> GET_[QME_TFCSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_TFCSR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_TFCSR;
#endif
    return fapi2::getScom(i_target, QME_TFCSR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_TFCSR]

//>> PUT_[QME_TFCSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_TFCSR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, QME_TFCSR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_TFCSR]

//>> PREP_[QME_TFCSR_SCOM2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_TFCSR_SCOM2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_TFCSR_SCOM2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_TFCSR_SCOM2]

//>> GET_[QME_TFCSR_SCOM2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_TFCSR_SCOM2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_TFCSR_SCOM2;
#endif
    return fapi2::getScom(i_target, QME_TFCSR_SCOM2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_TFCSR_SCOM2]

//>> PUT_[QME_TFCSR_SCOM2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_TFCSR_SCOM2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, QME_TFCSR_SCOM2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_TFCSR_SCOM2]

//>> PREP_[QME_TFCSR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_TFCSR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_TFCSR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_TFCSR_WO_CLEAR]

//>> GET_[QME_TFCSR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_TFCSR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_TFCSR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, QME_TFCSR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_TFCSR_WO_CLEAR]

//>> PUT_[QME_TFCSR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_TFCSR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, QME_TFCSR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_TFCSR_WO_CLEAR]


//>> SET_[QME_TFCSR_XFER_START]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_XFER_START(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_TFCSR_XFER_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_TFCSR_XFER_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_XFER_START]

//>> SET_[QME_TFCSR_XFER_START]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_XFER_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_TFCSR_XFER_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_TFCSR_XFER_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_XFER_START]

//>> SET_[QME_TFCSR_XFER_START]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_XFER_START(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_TFCSR_XFER_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_TFCSR_XFER_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_XFER_START]

//>> CLEAR_[QME_TFCSR_XFER_START]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_TFCSR_XFER_START(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_TFCSR_XFER_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_TFCSR_XFER_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_TFCSR_XFER_START]

//>> GET_[QME_TFCSR_XFER_START]
static inline fapi2::buffer<uint64_t>& GET_QME_TFCSR_XFER_START(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_TFCSR_XFER_START,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_TFCSR_XFER_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_TFCSR_XFER_START]

//>> GET_[QME_TFCSR_XFER_START]
static inline bool GET_QME_TFCSR_XFER_START(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_TFCSR_XFER_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_TFCSR_XFER_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_TFCSR_XFER_START]

//>> SET_[QME_TFCSR_TFAC_RESET]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_TFAC_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_TFCSR_TFAC_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_TFCSR_TFAC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_TFAC_RESET]

//>> SET_[QME_TFCSR_TFAC_RESET]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_TFAC_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_TFCSR_TFAC_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_TFCSR_TFAC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_TFAC_RESET]

//>> SET_[QME_TFCSR_TFAC_RESET]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_TFAC_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_TFCSR_TFAC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_TFCSR_TFAC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_TFAC_RESET]

//>> CLEAR_[QME_TFCSR_TFAC_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_TFCSR_TFAC_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_TFCSR_TFAC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_TFCSR_TFAC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_TFCSR_TFAC_RESET]

//>> GET_[QME_TFCSR_TFAC_RESET]
static inline fapi2::buffer<uint64_t>& GET_QME_TFCSR_TFAC_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_TFCSR_TFAC_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_TFCSR_TFAC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_TFCSR_TFAC_RESET]

//>> GET_[QME_TFCSR_TFAC_RESET]
static inline bool GET_QME_TFCSR_TFAC_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_TFCSR_TFAC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_TFCSR_TFAC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_TFCSR_TFAC_RESET]

//>> SET_[QME_TFCSR_CORE_NUM]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_CORE_NUM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_TFCSR_CORE_NUM,
           QME_TFCSR_CORE_NUM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_TFCSR_CORE_NUM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_CORE_NUM]

//>> SET_[QME_TFCSR_CORE_NUM]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_CORE_NUM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_TFCSR_CORE_NUM,
           QME_TFCSR_CORE_NUM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_TFCSR_CORE_NUM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_CORE_NUM]

//>> GET_[QME_TFCSR_CORE_NUM]
static inline fapi2::buffer<uint64_t>& GET_QME_TFCSR_CORE_NUM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_TFCSR_CORE_NUM,
           QME_TFCSR_CORE_NUM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_TFCSR_CORE_NUM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_TFCSR_CORE_NUM]

//>> SET_[QME_TFCSR_XFER_RECEIVE_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_XFER_RECEIVE_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_TFCSR_XFER_RECEIVE_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_TFCSR_XFER_RECEIVE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_XFER_RECEIVE_DONE]

//>> SET_[QME_TFCSR_XFER_RECEIVE_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_XFER_RECEIVE_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_TFCSR_XFER_RECEIVE_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_TFCSR_XFER_RECEIVE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_XFER_RECEIVE_DONE]

//>> SET_[QME_TFCSR_XFER_RECEIVE_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_XFER_RECEIVE_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_TFCSR_XFER_RECEIVE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_TFCSR_XFER_RECEIVE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_XFER_RECEIVE_DONE]

//>> CLEAR_[QME_TFCSR_XFER_RECEIVE_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_TFCSR_XFER_RECEIVE_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_TFCSR_XFER_RECEIVE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_TFCSR_XFER_RECEIVE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_TFCSR_XFER_RECEIVE_DONE]

//>> GET_[QME_TFCSR_XFER_RECEIVE_DONE]
static inline fapi2::buffer<uint64_t>& GET_QME_TFCSR_XFER_RECEIVE_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_TFCSR_XFER_RECEIVE_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_TFCSR_XFER_RECEIVE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_TFCSR_XFER_RECEIVE_DONE]

//>> GET_[QME_TFCSR_XFER_RECEIVE_DONE]
static inline bool GET_QME_TFCSR_XFER_RECEIVE_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_TFCSR_XFER_RECEIVE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_TFCSR_XFER_RECEIVE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_TFCSR_XFER_RECEIVE_DONE]

//>> SET_[QME_TFCSR_XFER_SENT_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_XFER_SENT_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_TFCSR_XFER_SENT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_TFCSR_XFER_SENT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_XFER_SENT_DONE]

//>> SET_[QME_TFCSR_XFER_SENT_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_XFER_SENT_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_TFCSR_XFER_SENT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_TFCSR_XFER_SENT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_XFER_SENT_DONE]

//>> SET_[QME_TFCSR_XFER_SENT_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_XFER_SENT_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_TFCSR_XFER_SENT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_TFCSR_XFER_SENT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_XFER_SENT_DONE]

//>> CLEAR_[QME_TFCSR_XFER_SENT_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_TFCSR_XFER_SENT_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_TFCSR_XFER_SENT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_TFCSR_XFER_SENT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_TFCSR_XFER_SENT_DONE]

//>> GET_[QME_TFCSR_XFER_SENT_DONE]
static inline fapi2::buffer<uint64_t>& GET_QME_TFCSR_XFER_SENT_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_TFCSR_XFER_SENT_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_TFCSR_XFER_SENT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_TFCSR_XFER_SENT_DONE]

//>> GET_[QME_TFCSR_XFER_SENT_DONE]
static inline bool GET_QME_TFCSR_XFER_SENT_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_TFCSR_XFER_SENT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_TFCSR_XFER_SENT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_TFCSR_XFER_SENT_DONE]

//>> SET_[QME_TFCSR_INCOMING_ERR]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_INCOMING_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_TFCSR_INCOMING_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_TFCSR_INCOMING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_INCOMING_ERR]

//>> SET_[QME_TFCSR_INCOMING_ERR]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_INCOMING_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_TFCSR_INCOMING_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_TFCSR_INCOMING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_INCOMING_ERR]

//>> SET_[QME_TFCSR_INCOMING_ERR]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_INCOMING_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_TFCSR_INCOMING_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_TFCSR_INCOMING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_INCOMING_ERR]

//>> CLEAR_[QME_TFCSR_INCOMING_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_TFCSR_INCOMING_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_TFCSR_INCOMING_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_TFCSR_INCOMING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_TFCSR_INCOMING_ERR]

//>> GET_[QME_TFCSR_INCOMING_ERR]
static inline fapi2::buffer<uint64_t>& GET_QME_TFCSR_INCOMING_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_TFCSR_INCOMING_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_TFCSR_INCOMING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_TFCSR_INCOMING_ERR]

//>> GET_[QME_TFCSR_INCOMING_ERR]
static inline bool GET_QME_TFCSR_INCOMING_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_TFCSR_INCOMING_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_TFCSR_INCOMING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_TFCSR_INCOMING_ERR]

//>> SET_[QME_TFCSR_RUNTIME_ERR]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_RUNTIME_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_TFCSR_RUNTIME_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_TFCSR_RUNTIME_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_RUNTIME_ERR]

//>> SET_[QME_TFCSR_RUNTIME_ERR]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_RUNTIME_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_TFCSR_RUNTIME_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_TFCSR_RUNTIME_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_RUNTIME_ERR]

//>> SET_[QME_TFCSR_RUNTIME_ERR]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_RUNTIME_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_TFCSR_RUNTIME_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_TFCSR_RUNTIME_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_RUNTIME_ERR]

//>> CLEAR_[QME_TFCSR_RUNTIME_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_TFCSR_RUNTIME_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_TFCSR_RUNTIME_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_TFCSR_RUNTIME_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_TFCSR_RUNTIME_ERR]

//>> GET_[QME_TFCSR_RUNTIME_ERR]
static inline fapi2::buffer<uint64_t>& GET_QME_TFCSR_RUNTIME_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_TFCSR_RUNTIME_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_TFCSR_RUNTIME_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_TFCSR_RUNTIME_ERR]

//>> GET_[QME_TFCSR_RUNTIME_ERR]
static inline bool GET_QME_TFCSR_RUNTIME_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_TFCSR_RUNTIME_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_TFCSR_RUNTIME_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_TFCSR_RUNTIME_ERR]

//>> SET_[QME_TFCSR_STATE_ERR]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_STATE_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_TFCSR_STATE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_TFCSR_STATE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_STATE_ERR]

//>> SET_[QME_TFCSR_STATE_ERR]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_STATE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_TFCSR_STATE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_TFCSR_STATE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_STATE_ERR]

//>> SET_[QME_TFCSR_STATE_ERR]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_STATE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_TFCSR_STATE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_TFCSR_STATE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_STATE_ERR]

//>> CLEAR_[QME_TFCSR_STATE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_TFCSR_STATE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_TFCSR_STATE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_TFCSR_STATE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_TFCSR_STATE_ERR]

//>> GET_[QME_TFCSR_STATE_ERR]
static inline fapi2::buffer<uint64_t>& GET_QME_TFCSR_STATE_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_TFCSR_STATE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_TFCSR_STATE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_TFCSR_STATE_ERR]

//>> GET_[QME_TFCSR_STATE_ERR]
static inline bool GET_QME_TFCSR_STATE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_TFCSR_STATE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_TFCSR_STATE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_TFCSR_STATE_ERR]

//>> SET_[QME_TFCSR_HDEC_MSB]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_HDEC_MSB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_TFCSR_HDEC_MSB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_TFCSR_HDEC_MSB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_HDEC_MSB]

//>> SET_[QME_TFCSR_HDEC_MSB]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_HDEC_MSB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_TFCSR_HDEC_MSB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_TFCSR_HDEC_MSB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_HDEC_MSB]

//>> SET_[QME_TFCSR_HDEC_MSB]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_HDEC_MSB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.setBit<QME_TFCSR_HDEC_MSB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_TFCSR_HDEC_MSB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_HDEC_MSB]

//>> CLEAR_[QME_TFCSR_HDEC_MSB]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_TFCSR_HDEC_MSB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.clearBit<QME_TFCSR_HDEC_MSB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_TFCSR_HDEC_MSB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_TFCSR_HDEC_MSB]

//>> GET_[QME_TFCSR_HDEC_MSB]
static inline fapi2::buffer<uint64_t>& GET_QME_TFCSR_HDEC_MSB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_TFCSR_HDEC_MSB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_TFCSR_HDEC_MSB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_TFCSR_HDEC_MSB]

//>> GET_[QME_TFCSR_HDEC_MSB]
static inline bool GET_QME_TFCSR_HDEC_MSB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return i_data.getBit<QME_TFCSR_HDEC_MSB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_TFCSR_HDEC_MSB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_TFCSR_HDEC_MSB]

//>> SET_[QME_TFCSR_DEC_MSB]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_DEC_MSB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_TFCSR_DEC_MSB,
           QME_TFCSR_DEC_MSB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_TFCSR_DEC_MSB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_DEC_MSB]

//>> SET_[QME_TFCSR_DEC_MSB]
static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_DEC_MSB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return o_data.insertFromRight<QME_TFCSR_DEC_MSB,
           QME_TFCSR_DEC_MSB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_TFCSR_DEC_MSB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TFCSR_DEC_MSB]

//>> GET_[QME_TFCSR_DEC_MSB]
static inline fapi2::buffer<uint64_t>& GET_QME_TFCSR_DEC_MSB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM2, QME_TFCSR_WO_CLEAR));
#endif
    return i_data.extractToRight<QME_TFCSR_DEC_MSB,
           QME_TFCSR_DEC_MSB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_TFCSR_DEC_MSB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_TFCSR_DEC_MSB]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
