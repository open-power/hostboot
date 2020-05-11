/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_f.H $       */
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

#ifndef __p10_scom_iohs_f_H_
#define __p10_scom_iohs_f_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> [DLP_DLL_STATUS]
static const uint64_t DLP_DLL_STATUS = 0x18011028ull;

static const uint32_t DLP_DLL_STATUS_0_PHY_TRAINING_STATE = 0;
static const uint32_t DLP_DLL_STATUS_0_PHY_TRAINING_STATE_LEN = 4;
static const uint32_t DLP_DLL_STATUS_0_CURRENT_STATE = 4;
static const uint32_t DLP_DLL_STATUS_0_CURRENT_STATE_LEN = 4;
static const uint32_t DLP_DLL_STATUS_0_TIMEOUT_STATE = 8;
static const uint32_t DLP_DLL_STATUS_0_TIMEOUT_STATE_LEN = 4;
static const uint32_t DLP_DLL_STATUS_0_PRIOR_STATE = 12;
static const uint32_t DLP_DLL_STATUS_0_PRIOR_STATE_LEN = 4;
static const uint32_t DLP_DLL_STATUS_0_OPTICS_RST_B = 16;
static const uint32_t DLP_DLL_STATUS_0_OPTICS_IRQ = 17;
static const uint32_t DLP_DLL_STATUS_0_TRAINING = 18;
static const uint32_t DLP_DLL_STATUS_0_MAX_PKT_TIMER = 19;
static const uint32_t DLP_DLL_STATUS_0_MAX_PKT_TIMER_LEN = 5;
static const uint32_t DLP_DLL_STATUS_1_PHY_TRAINING_STATE = 24;
static const uint32_t DLP_DLL_STATUS_1_PHY_TRAINING_STATE_LEN = 4;
static const uint32_t DLP_DLL_STATUS_1_CURRENT_STATE = 28;
static const uint32_t DLP_DLL_STATUS_1_CURRENT_STATE_LEN = 4;
static const uint32_t DLP_DLL_STATUS_1_TIMEOUT_STATE = 32;
static const uint32_t DLP_DLL_STATUS_1_TIMEOUT_STATE_LEN = 4;
static const uint32_t DLP_DLL_STATUS_1_PRIOR_STATE = 36;
static const uint32_t DLP_DLL_STATUS_1_PRIOR_STATE_LEN = 4;
static const uint32_t DLP_DLL_STATUS_1_OPTICS_RST_B = 40;
static const uint32_t DLP_DLL_STATUS_1_OPTICS_IRQ = 41;
static const uint32_t DLP_DLL_STATUS_1_TRAINING = 42;
static const uint32_t DLP_DLL_STATUS_1_MAX_PKT_TIMER = 43;
static const uint32_t DLP_DLL_STATUS_1_MAX_PKT_TIMER_LEN = 5;
static const uint32_t DLP_DLL_STATUS_0_LINK_UP = 48;
static const uint32_t DLP_DLL_STATUS_1_LINK_UP = 49;
static const uint32_t DLP_DLL_STATUS_0_RESET_ACTIVE = 50;
static const uint32_t DLP_DLL_STATUS_1_RESET_ACTIVE = 51;
static const uint32_t DLP_DLL_STATUS_0_TDM_STATUS = 52;
static const uint32_t DLP_DLL_STATUS_0_TDM_STATUS_LEN = 2;
static const uint32_t DLP_DLL_STATUS_1_TDM_STATUS = 54;
static const uint32_t DLP_DLL_STATUS_1_TDM_STATUS_LEN = 2;
static const uint32_t DLP_DLL_STATUS_0_PSAVE_STATE = 56;
static const uint32_t DLP_DLL_STATUS_0_PSAVE_STATE_LEN = 4;
static const uint32_t DLP_DLL_STATUS_1_PSAVE_STATE = 60;
static const uint32_t DLP_DLL_STATUS_1_PSAVE_STATE_LEN = 4;
//<< [DLP_DLL_STATUS]
// iohs/reg00065.H

//>> [DLP_LINK0_ERROR_STATUS]
static const uint64_t DLP_LINK0_ERROR_STATUS = 0x18011016ull;

static const uint32_t DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER = 0;
static const uint32_t DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE = 1;
static const uint32_t DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE_LEN = 7;
static const uint32_t DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE = 8;
static const uint32_t DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE_LEN = 4;
static const uint32_t DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC = 12;
static const uint32_t DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC_LEN = 2;
static const uint32_t DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN = 16;
static const uint32_t DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN_LEN = 5;
static const uint32_t DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV = 24;
static const uint32_t DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV_LEN = 14;
static const uint32_t DLP_LINK0_ERROR_STATUS_INTERNAL = 38;
static const uint32_t DLP_LINK0_ERROR_STATUS_INTERNAL_LEN = 26;
//<< [DLP_LINK0_ERROR_STATUS]
// iohs/reg00065.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "iohs/reg00065.H"
#include "iohs/reg00066.H"
#include "iohs/reg00067.H"
#include "iohs/reg00068.H"
#endif
#endif
