/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00038.H $         */
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

#ifndef __PROC_REG00038_H_
#define __PROC_REG00038_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPBR_PBA_PBAF_PBAERRRPT0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAF_PBAERRRPT0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAF_PBAERRRPT0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAF_PBAERRRPT0]

//>> GET_[TP_TPBR_PBA_PBAF_PBAERRRPT0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAF_PBAERRRPT0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAF_PBAERRRPT0;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAF_PBAERRRPT0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAERRRPT0]

//>> PUT_[TP_TPBR_PBA_PBAF_PBAERRRPT0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAF_PBAERRRPT0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAERRRPT0));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAF_PBAERRRPT0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAF_PBAERRRPT0]


//>> SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_RDDATATO_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAERRRPT0_RDDATATO_FW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAERRRPT0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAERRRPT0_RDDATATO_FW,
           TP_TPBR_PBA_PBAF_PBAERRRPT0_RDDATATO_FW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAERRRPT0_RDDATATO_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_RDDATATO_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_RDDATATO_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAERRRPT0_RDDATATO_FW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAERRRPT0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAERRRPT0_RDDATATO_FW,
           TP_TPBR_PBA_PBAF_PBAERRRPT0_RDDATATO_FW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAERRRPT0_RDDATATO_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_RDDATATO_FW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_RDDATATO_FW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAERRRPT0_RDDATATO_FW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAERRRPT0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAERRRPT0_RDDATATO_FW,
           TP_TPBR_PBA_PBAF_PBAERRRPT0_RDDATATO_FW_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAERRRPT0_RDDATATO_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_RDDATATO_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_RDADRERR_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAERRRPT0_RDADRERR_FW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAERRRPT0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAERRRPT0_RDADRERR_FW,
           TP_TPBR_PBA_PBAF_PBAERRRPT0_RDADRERR_FW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAERRRPT0_RDADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_RDADRERR_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_RDADRERR_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAERRRPT0_RDADRERR_FW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAERRRPT0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAERRRPT0_RDADRERR_FW,
           TP_TPBR_PBA_PBAF_PBAERRRPT0_RDADRERR_FW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAERRRPT0_RDADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_RDADRERR_FW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_RDADRERR_FW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAERRRPT0_RDADRERR_FW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAERRRPT0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAERRRPT0_RDADRERR_FW,
           TP_TPBR_PBA_PBAF_PBAERRRPT0_RDADRERR_FW_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAERRRPT0_RDADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_RDADRERR_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_WRADRERR_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAERRRPT0_WRADRERR_FW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAERRRPT0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAERRRPT0_WRADRERR_FW,
           TP_TPBR_PBA_PBAF_PBAERRRPT0_WRADRERR_FW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAERRRPT0_WRADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_WRADRERR_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_WRADRERR_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAERRRPT0_WRADRERR_FW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAERRRPT0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAERRRPT0_WRADRERR_FW,
           TP_TPBR_PBA_PBAF_PBAERRRPT0_WRADRERR_FW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAERRRPT0_WRADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_WRADRERR_FW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_WRADRERR_FW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAERRRPT0_WRADRERR_FW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAERRRPT0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAERRRPT0_WRADRERR_FW,
           TP_TPBR_PBA_PBAF_PBAERRRPT0_WRADRERR_FW_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAERRRPT0_WRADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_WRADRERR_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_RD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_RD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAERRRPT0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_RD,
           TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_RD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_RD]

//>> SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_RD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAERRRPT0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_RD,
           TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_RD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_RD]

//>> GET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_RD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_RD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAERRRPT0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_RD,
           TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_RD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_RD]

//>> SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_WR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_WR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAERRRPT0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_WR,
           TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_WR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_WR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_WR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_WR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAERRRPT0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_WR,
           TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_WR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_WR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_WR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_WR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAERRRPT0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_WR,
           TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_WR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_ACKDEAD_FW_WR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPCRESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPCRESP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAERRRPT0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPCRESP,
           TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPCRESP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPCRESP]

//>> SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPCRESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPCRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAERRRPT0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPCRESP,
           TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPCRESP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPCRESP]

//>> GET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPCRESP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPCRESP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAERRRPT0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPCRESP,
           TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPCRESP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPCRESP]

//>> SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPDATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPDATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAERRRPT0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPDATA,
           TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPDATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPDATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPDATA]

//>> SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPDATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPDATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAERRRPT0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPDATA,
           TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPDATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPDATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPDATA]

//>> GET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPDATA]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPDATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAERRRPT0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPDATA,
           TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPDATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPDATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAERRRPT0_UNEXPDATA]

//>> PREP_[TP_TPBR_PBA_PBAO_BCDE_PBADR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_BCDE_PBADR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_BCDE_PBADR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_BCDE_PBADR]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_PBADR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_BCDE_PBADR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_BCDE_PBADR;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_BCDE_PBADR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_PBADR]

//>> PUT_[TP_TPBR_PBA_PBAO_BCDE_PBADR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_BCDE_PBADR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_PBADR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_BCDE_PBADR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_BCDE_PBADR]


//>> SET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_0_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_PBADR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_0_1,
           TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_0_1]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_PBADR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_0_1,
           TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_0_1]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_0_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_0_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_PBADR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_0_1,
           TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_0_1]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_PB_OFFSET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_PBADR_PB_OFFSET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_PBADR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_PBADR_PB_OFFSET,
           TP_TPBR_PBA_PBAO_BCDE_PBADR_PB_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_PBADR_PB_OFFSET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_PB_OFFSET]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_PB_OFFSET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_PBADR_PB_OFFSET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_PBADR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_PBADR_PB_OFFSET,
           TP_TPBR_PBA_PBAO_BCDE_PBADR_PB_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_PBADR_PB_OFFSET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_PB_OFFSET]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_PB_OFFSET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCDE_PBADR_PB_OFFSET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_PBADR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCDE_PBADR_PB_OFFSET,
           TP_TPBR_PBA_PBAO_BCDE_PBADR_PB_OFFSET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_PBADR_PB_OFFSET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_PB_OFFSET]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_25_26]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_25_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_PBADR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_25_26,
           TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_25_26_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_25_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_25_26]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_25_26]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_25_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_PBADR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_25_26,
           TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_25_26_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_25_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_25_26]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_25_26]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_25_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_PBADR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_25_26,
           TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_25_26_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_25_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_25_26]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_EXTADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_PBADR_EXTADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_PBADR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_PBADR_EXTADDR,
           TP_TPBR_PBA_PBAO_BCDE_PBADR_EXTADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_PBADR_EXTADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_EXTADDR]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_EXTADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_PBADR_EXTADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_PBADR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_PBADR_EXTADDR,
           TP_TPBR_PBA_PBAO_BCDE_PBADR_EXTADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_PBADR_EXTADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_EXTADDR]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_EXTADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCDE_PBADR_EXTADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_PBADR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCDE_PBADR_EXTADDR,
           TP_TPBR_PBA_PBAO_BCDE_PBADR_EXTADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_PBADR_EXTADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_EXTADDR]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_41_42]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_41_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_PBADR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_41_42,
           TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_41_42_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_41_42 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_41_42]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_41_42]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_41_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_PBADR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_41_42,
           TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_41_42_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_41_42 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_41_42]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_41_42]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_41_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_PBADR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_41_42,
           TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_41_42_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_41_42 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_PBADR_RESERVED_41_42]

//>> PREP_[TP_TPBR_PBA_PBAO_PBAPBTXT2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAPBTXT2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAPBTXT2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBAPBTXT2]

//>> GET_[TP_TPBR_PBA_PBAO_PBAPBTXT2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAPBTXT2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAPBTXT2;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAPBTXT2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAPBTXT2]

//>> PUT_[TP_TPBR_PBA_PBAO_PBAPBTXT2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAPBTXT2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAPBTXT2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBAPBTXT2]


//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT2_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT2_VALID,
           TP_TPBR_PBA_PBAO_PBAPBTXT2_VALID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT2_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_VALID]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT2_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT2_VALID,
           TP_TPBR_PBA_PBAO_PBAPBTXT2_VALID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT2_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_VALID]

//>> GET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_VALID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAPBTXT2_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAPBTXT2_VALID,
           TP_TPBR_PBA_PBAO_PBAPBTXT2_VALID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT2_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_VALID]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT2_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT2_0,
           TP_TPBR_PBA_PBAO_PBAPBTXT2_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT2_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_0]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT2_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT2_0,
           TP_TPBR_PBA_PBAO_PBAPBTXT2_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT2_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_0]

//>> GET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAPBTXT2_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAPBTXT2_0,
           TP_TPBR_PBA_PBAO_PBAPBTXT2_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT2_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_0]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT2_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT2_1,
           TP_TPBR_PBA_PBAO_PBAPBTXT2_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT2_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_1]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT2_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT2_1,
           TP_TPBR_PBA_PBAO_PBAPBTXT2_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT2_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_1]

//>> GET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAPBTXT2_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAPBTXT2_1,
           TP_TPBR_PBA_PBAO_PBAPBTXT2_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT2_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_1]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT2_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT2_2,
           TP_TPBR_PBA_PBAO_PBAPBTXT2_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT2_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_2]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT2_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT2_2,
           TP_TPBR_PBA_PBAO_PBAPBTXT2_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT2_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_2]

//>> GET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAPBTXT2_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAPBTXT2_2,
           TP_TPBR_PBA_PBAO_PBAPBTXT2_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT2_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_2]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT2_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT2_3,
           TP_TPBR_PBA_PBAO_PBAPBTXT2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT2_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT2_3,
           TP_TPBR_PBA_PBAO_PBAPBTXT2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_3]

//>> GET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAPBTXT2_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAPBTXT2_3,
           TP_TPBR_PBA_PBAO_PBAPBTXT2_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT2_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT2_4,
           TP_TPBR_PBA_PBAO_PBAPBTXT2_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT2_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_4]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT2_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT2_4,
           TP_TPBR_PBA_PBAO_PBAPBTXT2_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT2_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_4]

//>> GET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_4]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAPBTXT2_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAPBTXT2_4,
           TP_TPBR_PBA_PBAO_PBAPBTXT2_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT2_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_4]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT2_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT2_5,
           TP_TPBR_PBA_PBAO_PBAPBTXT2_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT2_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_5]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT2_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT2_5,
           TP_TPBR_PBA_PBAO_PBAPBTXT2_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT2_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_5]

//>> GET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_5]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAPBTXT2_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAPBTXT2_5,
           TP_TPBR_PBA_PBAO_PBAPBTXT2_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT2_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_5]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT2_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT2_6,
           TP_TPBR_PBA_PBAO_PBAPBTXT2_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT2_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_6]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT2_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT2_6,
           TP_TPBR_PBA_PBAO_PBAPBTXT2_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT2_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_6]

//>> GET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_6]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAPBTXT2_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAPBTXT2_6,
           TP_TPBR_PBA_PBAO_PBAPBTXT2_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT2_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_6]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT2_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT2_7,
           TP_TPBR_PBA_PBAO_PBAPBTXT2_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT2_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_7]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT2_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT2_7,
           TP_TPBR_PBA_PBAO_PBAPBTXT2_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT2_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_7]

//>> GET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_7]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAPBTXT2_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAPBTXT2_7,
           TP_TPBR_PBA_PBAO_PBAPBTXT2_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT2_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAPBTXT2_7]

//>> PREP_[TP_TPBR_PSIHB_ERROR_MASK_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSIHB_ERROR_MASK_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_ERROR_MASK_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PSIHB_ERROR_MASK_REG]

//>> GET_[TP_TPBR_PSIHB_ERROR_MASK_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSIHB_ERROR_MASK_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_ERROR_MASK_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSIHB_ERROR_MASK_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PSIHB_ERROR_MASK_REG]

//>> PUT_[TP_TPBR_PSIHB_ERROR_MASK_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSIHB_ERROR_MASK_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_ERROR_MASK_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSIHB_ERROR_MASK_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PSIHB_ERROR_MASK_REG]


//>> SET_[TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_1,
           TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_1]

//>> SET_[TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_1,
           TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_1]

//>> GET_[TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_1,
           TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_1]

//>> SET_[TP_TPBR_PSIHB_ERROR_MASK_REG_INTERRUPT_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_ERROR_MASK_REG_INTERRUPT_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_ERROR_MASK_REG_INTERRUPT_DISABLE,
           TP_TPBR_PSIHB_ERROR_MASK_REG_INTERRUPT_DISABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_ERROR_MASK_REG_INTERRUPT_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_ERROR_MASK_REG_INTERRUPT_DISABLE]

//>> SET_[TP_TPBR_PSIHB_ERROR_MASK_REG_INTERRUPT_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_ERROR_MASK_REG_INTERRUPT_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_ERROR_MASK_REG_INTERRUPT_DISABLE,
           TP_TPBR_PSIHB_ERROR_MASK_REG_INTERRUPT_DISABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_ERROR_MASK_REG_INTERRUPT_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_ERROR_MASK_REG_INTERRUPT_DISABLE]

//>> GET_[TP_TPBR_PSIHB_ERROR_MASK_REG_INTERRUPT_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_ERROR_MASK_REG_INTERRUPT_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_ERROR_MASK_REG_INTERRUPT_DISABLE,
           TP_TPBR_PSIHB_ERROR_MASK_REG_INTERRUPT_DISABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_ERROR_MASK_REG_INTERRUPT_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_ERROR_MASK_REG_INTERRUPT_DISABLE]

//>> SET_[TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_2,
           TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_2]

//>> SET_[TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_2,
           TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_2]

//>> GET_[TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_2,
           TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_ERROR_MASK_REG_ERROR_DISABLE_2]

//>> PREP_[TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1]

//>> PUT_[TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1]


//>> SET_[TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1_MULTICAST1_GROUP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1_MULTICAST1_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1_MULTICAST1_GROUP,
           TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1_MULTICAST1_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1_MULTICAST1_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1_MULTICAST1_GROUP]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1_MULTICAST1_GROUP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1_MULTICAST1_GROUP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1_MULTICAST1_GROUP,
           TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1_MULTICAST1_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1_MULTICAST1_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1_MULTICAST1_GROUP]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1_MULTICAST1_GROUP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1_MULTICAST1_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1_MULTICAST1_GROUP,
           TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1_MULTICAST1_GROUP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1_MULTICAST1_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_1_MULTICAST1_GROUP]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_WATCHDOG_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_WATCHDOG_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_WATCHDOG_SEL,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_WATCHDOG_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_WATCHDOG_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_WATCHDOG_SEL]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_WATCHDOG_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_WATCHDOG_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_WATCHDOG_SEL,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_WATCHDOG_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_WATCHDOG_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_WATCHDOG_SEL]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_WATCHDOG_SEL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_WATCHDOG_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_WATCHDOG_SEL,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_WATCHDOG_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_WATCHDOG_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_WATCHDOG_SEL]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_FIT_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_FIT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_FIT_SEL,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_FIT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_FIT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_FIT_SEL]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_FIT_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_FIT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_FIT_SEL,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_FIT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_FIT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_FIT_SEL]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_FIT_SEL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_FIT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_FIT_SEL,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_FIT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_FIT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPETSEL_FIT_SEL]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>&
GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU_SGB_INFO_UPPER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU_SGB_INFO_UPPER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU_SGB_INFO_UPPER,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU_SGB_INFO_UPPER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU_SGB_INFO_UPPER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU_SGB_INFO_UPPER]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU_SGB_INFO_UPPER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU_SGB_INFO_UPPER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU_SGB_INFO_UPPER,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU_SGB_INFO_UPPER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU_SGB_INFO_UPPER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU_SGB_INFO_UPPER]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU_SGB_INFO_UPPER]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU_SGB_INFO_UPPER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU_SGB_INFO_UPPER,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU_SGB_INFO_UPPER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU_SGB_INFO_UPPER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISGBU_SGB_INFO_UPPER]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU_ICACHE_INFO_UPPER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU_ICACHE_INFO_UPPER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU_ICACHE_INFO_UPPER,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU_ICACHE_INFO_UPPER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU_ICACHE_INFO_UPPER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU_ICACHE_INFO_UPPER]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU_ICACHE_INFO_UPPER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU_ICACHE_INFO_UPPER(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU_ICACHE_INFO_UPPER,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU_ICACHE_INFO_UPPER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU_ICACHE_INFO_UPPER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU_ICACHE_INFO_UPPER]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU_ICACHE_INFO_UPPER]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU_ICACHE_INFO_UPPER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU_ICACHE_INFO_UPPER,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU_ICACHE_INFO_UPPER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU_ICACHE_INFO_UPPER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICACU_ICACHE_INFO_UPPER]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_8]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_8,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_8]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_8]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_8,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_8]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_8]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_8,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_8_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_8]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_9]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_9,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_9]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_9]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_9,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_9]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_9]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_9,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_9_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_9]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_10]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_10,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_10]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_10]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_10,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_10]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_10]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_10,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_10_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_10]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_11]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_11,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_11]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_11]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_11,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_11]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_11]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_11,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_11_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA2_11]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_BRIDGE_ENABLE_0_B]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_2_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_2_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_2_3,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_2_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_2_3]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_2_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_2_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_2_3,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_2_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_2_3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_2_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_2_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_2_3,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_2_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_2_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_2_3]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_CLOCK_DIVIDER_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_CLOCK_DIVIDER_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_CLOCK_DIVIDER_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_CLOCK_DIVIDER_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_CLOCK_DIVIDER_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_CLOCK_DIVIDER_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_CLOCK_DIVIDER_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_CLOCK_DIVIDER_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_CLOCK_DIVIDER_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_CLOCK_DIVIDER_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_CLOCK_DIVIDER_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_CLOCK_DIVIDER_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_CLOCK_DIVIDER_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_CLOCK_DIVIDER_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_CLOCK_DIVIDER_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_CLOCK_DIVIDER_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_CLOCK_DIVIDER_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_CLOCK_DIVIDER_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2SCTRL10_RESERVED_14_16]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2SCTRL10_RESERVED_14_16(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2SCTRL10_RESERVED_14_16,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2SCTRL10_RESERVED_14_16_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2SCTRL10_RESERVED_14_16 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2SCTRL10_RESERVED_14_16]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2SCTRL10_RESERVED_14_16]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2SCTRL10_RESERVED_14_16(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2SCTRL10_RESERVED_14_16,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2SCTRL10_RESERVED_14_16_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2SCTRL10_RESERVED_14_16 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2SCTRL10_RESERVED_14_16]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2SCTRL10_RESERVED_14_16]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2SCTRL10_RESERVED_14_16(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2SCTRL10_RESERVED_14_16,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2SCTRL10_RESERVED_14_16_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2SCTRL10_RESERVED_14_16 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2SCTRL10_RESERVED_14_16]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_O2S_NR_OF_FRAMES_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_18_19]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_18_19(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_18_19,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_18_19_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_18_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_18_19]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_18_19]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_18_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_18_19,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_18_19_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_18_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_18_19]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_18_19]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_18_19(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_18_19,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_18_19_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_18_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_RESERVED_18_19]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_SLAVE_DATA_SAMPLE_DELAY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_SLAVE_DATA_SAMPLE_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_SLAVE_DATA_SAMPLE_DELAY,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_SLAVE_DATA_SAMPLE_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_SLAVE_DATA_SAMPLE_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_SLAVE_DATA_SAMPLE_DELAY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_SLAVE_DATA_SAMPLE_DELAY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_SLAVE_DATA_SAMPLE_DELAY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_SLAVE_DATA_SAMPLE_DELAY,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_SLAVE_DATA_SAMPLE_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_SLAVE_DATA_SAMPLE_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_SLAVE_DATA_SAMPLE_DELAY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_SLAVE_DATA_SAMPLE_DELAY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_SLAVE_DATA_SAMPLE_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_SLAVE_DATA_SAMPLE_DELAY,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_SLAVE_DATA_SAMPLE_DELAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_SLAVE_DATA_SAMPLE_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10_SLAVE_DATA_SAMPLE_DELAY]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SRD1A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SRD1A(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SRD1A;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SRD1A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD1A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SRD1A(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SRD1A;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SRD1A, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD1A]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SRD1A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SRD1A(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SRD1A));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SRD1A, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SRD1A]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD1A_OCB_OCI_O2SRD1A_O2S_RDATA_1A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SRD1A_OCB_OCI_O2SRD1A_O2S_RDATA_1A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SRD1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SRD1A_OCB_OCI_O2SRD1A_O2S_RDATA_1A,
           TP_TPCHIP_OCC_OCI_OCB_O2SRD1A_OCB_OCI_O2SRD1A_O2S_RDATA_1A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SRD1A_OCB_OCI_O2SRD1A_O2S_RDATA_1A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD1A_OCB_OCI_O2SRD1A_O2S_RDATA_1A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD1A_OCB_OCI_O2SRD1A_O2S_RDATA_1A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SRD1A_OCB_OCI_O2SRD1A_O2S_RDATA_1A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SRD1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SRD1A_OCB_OCI_O2SRD1A_O2S_RDATA_1A,
           TP_TPCHIP_OCC_OCI_OCB_O2SRD1A_OCB_OCI_O2SRD1A_O2S_RDATA_1A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SRD1A_OCB_OCI_O2SRD1A_O2S_RDATA_1A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD1A_OCB_OCI_O2SRD1A_O2S_RDATA_1A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD1A_OCB_OCI_O2SRD1A_O2S_RDATA_1A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SRD1A_OCB_OCI_O2SRD1A_O2S_RDATA_1A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SRD1A));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SRD1A_OCB_OCI_O2SRD1A_O2S_RDATA_1A,
           TP_TPCHIP_OCC_OCI_OCB_O2SRD1A_OCB_OCI_O2SRD1A_O2S_RDATA_1A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SRD1A_OCB_OCI_O2SRD1A_O2S_RDATA_1A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD1A_OCB_OCI_O2SRD1A_O2S_RDATA_1A]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_REGION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_REGION]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_REGION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_REGION]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_REGION]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_REGION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_REGION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_REGION]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_BASE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_BASE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_BASE,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_BASE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_BASE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_BASE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_BASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_BASE,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_BASE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_BASE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_BASE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_BASE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_BASE,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_BASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_BASE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3_BASE]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_RW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_RW]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_RW, TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_RW]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_CLEAR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_CLEAR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_RW, TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_CLEAR]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_OR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_OR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_RW, TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_OR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_OCB_OCI_OCCFLG2_OCC_FLAGS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_OCB_OCI_OCCFLG2_OCC_FLAGS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_RW, TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_OCB_OCI_OCCFLG2_OCC_FLAGS,
           TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_OCB_OCI_OCCFLG2_OCC_FLAGS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_OCB_OCI_OCCFLG2_OCC_FLAGS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_OCB_OCI_OCCFLG2_OCC_FLAGS]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_OCB_OCI_OCCFLG2_OCC_FLAGS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_OCB_OCI_OCCFLG2_OCC_FLAGS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_RW, TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_OCB_OCI_OCCFLG2_OCC_FLAGS,
           TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_OCB_OCI_OCCFLG2_OCC_FLAGS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_OCB_OCI_OCCFLG2_OCC_FLAGS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_OCB_OCI_OCCFLG2_OCC_FLAGS]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_OCB_OCI_OCCFLG2_OCC_FLAGS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_OCB_OCI_OCCFLG2_OCC_FLAGS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_RW, TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_OCB_OCI_OCCFLG2_OCC_FLAGS,
           TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_OCB_OCI_OCCFLG2_OCC_FLAGS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_OCB_OCI_OCCFLG2_OCC_FLAGS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_OCB_OCI_OCCFLG2_OCC_FLAGS]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
