/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_4.H $        */
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

#ifndef __PPE_HCODE__
    #include "proc_scomt.H"
#endif

#ifndef __p10_scom_mcc_4_H_
#define __p10_scom_mcc_4_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> [DSTL_DSTLCFG]
static const uint64_t DSTL_DSTLCFG = 0x0c010d0bull;

static const uint32_t DSTL_DSTLCFG_TMPL0_ONLY = 0;
static const uint32_t DSTL_DSTLCFG_RESERVED_1 = 1;
static const uint32_t DSTL_DSTLCFG_TMPL7_ENABLE = 2;
static const uint32_t DSTL_DSTLCFG_TMPL1_DIS = 3;
static const uint32_t DSTL_DSTLCFG_FAST_RD_DISABLE = 4;
static const uint32_t DSTL_DSTLCFG_RESERVED_5 = 5;
static const uint32_t DSTL_DSTLCFG_TMPL4_DISABLE = 6;
static const uint32_t DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS = 7;
static const uint32_t DSTL_DSTLCFG_READ_THRESHOLD = 8;
static const uint32_t DSTL_DSTLCFG_READ_THRESHOLD_LEN = 4;
static const uint32_t DSTL_DSTLCFG_RESERVED_12_15 = 12;
static const uint32_t DSTL_DSTLCFG_RESERVED_12_15_LEN = 4;
static const uint32_t DSTL_DSTLCFG_WR_TMP4_THRESHOLD = 16;
static const uint32_t DSTL_DSTLCFG_WR_TMP4_THRESHOLD_LEN = 4;
static const uint32_t DSTL_DSTLCFG_RESERVED_20_23 = 20;
static const uint32_t DSTL_DSTLCFG_RESERVED_20_23_LEN = 4;
static const uint32_t DSTL_DSTLCFG_WR_DBL_THRESHOLD = 24;
static const uint32_t DSTL_DSTLCFG_WR_DBL_THRESHOLD_LEN = 4;
static const uint32_t DSTL_DSTLCFG_CRITICAL_OW_DIS = 28;
static const uint32_t DSTL_DSTLCFG_RESERVED_29 = 29;
static const uint32_t DSTL_DSTLCFG_RESERVED_30 = 30;
static const uint32_t DSTL_DSTLCFG_RESERVED_31 = 31;
static const uint32_t DSTL_DSTLCFG_RESERVED_32 = 32;
static const uint32_t DSTL_DSTLCFG_RESERVED_33_43 = 33;
static const uint32_t DSTL_DSTLCFG_RESERVED_33_43_LEN = 11;
static const uint32_t DSTL_DSTLCFG_WRAP_MODE_EN = 44;
static const uint32_t DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH = 45;
static const uint32_t DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH_LEN = 4;
static const uint32_t DSTL_DSTLCFG_TIMEOUT_MODE = 49;
static const uint32_t DSTL_DSTLCFG_TIMEOUT_MODE_LEN = 3;
static const uint32_t DSTL_DSTLCFG_MMIO_ADDRBIT_POS = 52;
static const uint32_t DSTL_DSTLCFG_MMIO_ADDRBIT_POS_LEN = 5;
static const uint32_t DSTL_DSTLCFG_RESET_CREDITS = 57;
static const uint32_t DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET = 58;
static const uint32_t DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET = 59;
static const uint32_t DSTL_DSTLCFG_RESERVED_62_63 = 62;
static const uint32_t DSTL_DSTLCFG_RESERVED_62_63_LEN = 2;
//<< [DSTL_DSTLCFG]
// mcc/reg00004.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "mcc/reg00004.H"
#endif
#endif
