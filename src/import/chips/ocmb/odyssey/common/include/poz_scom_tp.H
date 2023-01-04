/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/common/include/poz_scom_tp.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
#pragma once
#include <stdint.h>

#ifndef __PPE_HCODE__
namespace scomt
{
namespace poz
{
#endif

static const uint64_t TP_CFAM_FSI_W_FSI2PIB_STATUS_RO = 0x101Cull;

static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_ANY_ERROR = 0;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP = 1;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION = 2;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR = 3;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST = 4;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_PARITY_CHECK = 5;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_LOCAL_CHECKSTOP = 6;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK = 7;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT = 8;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_RESERVED_9 = 9;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION = 10;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_PIB_ABORT = 11;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_TP_TPFSI_RCS_ERROR_STATUS_DC = 12;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_TP_TPFSI_RCS_ERROR_STATUS_DC_LEN = 4;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE = 16;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_PIB_ERROR_CODE = 17;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_PIB_ERROR_CODE_LEN = 3;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC = 20;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC = 21;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC = 22;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC = 23;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC = 24;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC = 25;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC = 26;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC = 27;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING = 28;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED = 29;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION = 30;
static const uint32_t TP_CFAM_FSI_W_FSI2PIB_STATUS_RESERVED_31 = 31;


static const uint64_t TP_CFAM_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_WO = 0x2450ull;

static const uint32_t TP_CFAM_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET = 0;

#ifndef __PPE_HCODE__
}
}
#endif

#ifndef SCOMT_OMIT_FIELD_ACCESSORS
    #include "poz_scom_tp_fields.H"
#endif
