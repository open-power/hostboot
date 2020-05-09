/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_3.H $        */
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

#ifndef __p10_scom_mcc_3_H_
#define __p10_scom_mcc_3_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> [USTL_USTLMCHWFM]
static const uint64_t USTL_USTLMCHWFM = 0x0c010e0full;

static const uint32_t USTL_USTLMCHWFM_ENABLE = 0;
static const uint32_t USTL_USTLMCHWFM_FAIL_THRESH = 1;
static const uint32_t USTL_USTLMCHWFM_FAIL_THRESH_LEN = 6;
static const uint32_t USTL_USTLMCHWFM_WINDOW_SIZE = 7;
static const uint32_t USTL_USTLMCHWFM_WINDOW_SIZE_LEN = 7;
static const uint32_t USTL_USTLMCHWFM_TSCALE = 14;
static const uint32_t USTL_USTLMCHWFM_TSCALE_LEN = 2;
static const uint32_t USTL_USTLMCHWFM_SCOM_COMMAND_VALID = 16;
static const uint32_t USTL_USTLMCHWFM_SCOM_COMMAND = 17;
static const uint32_t USTL_USTLMCHWFM_SUB_CHANNEL_SELECT = 18;
static const uint32_t USTL_USTLMCHWFM_HWFM_STATUS = 19;
static const uint32_t USTL_USTLMCHWFM_HWFM_STATUS_LEN = 4;
//<< [USTL_USTLMCHWFM]
// mcc/reg00003.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "mcc/reg00003.H"
#endif
#endif
