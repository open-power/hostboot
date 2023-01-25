/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/perv/poz_perv_mod_misc_regs.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
//------------------------------------------------------------------------------
/// @file  poz_perv_mod_misc_regs.H
/// @brief Registers referenced by poz_perv_mod_misc module
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Sreekanth Reddy (skadapal@in.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
//------------------------------------------------------------------------------

#pragma once

#include <poz_scom_perv.H>

using namespace scomt::poz;

SCOMT_PERV_USE_FSXCOMP_FSXLOG_ROOT_CTRL0;
SCOMT_PERV_USE_FSXCOMP_FSXLOG_ROOT_CTRL1;
SCOMT_PERV_USE_FSXCOMP_FSXLOG_CBS_ENVSTAT;
SCOMT_PERV_USE_FSXCOMP_FSXLOG_ROOT_CTRL0_COPY;
SCOMT_PERV_USE_FSXCOMP_FSXLOG_ROOT_CTRL1_COPY;
SCOMT_PERV_USE_FSXCOMP_FSXLOG_CBS_CS;
SCOMT_PERV_USE_FSXCOMP_FSXLOG_SB_CS;
SCOMT_PERV_USE_TP_CFAM_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET;
SCOMT_PERV_USE_TP_CFAM_FSI_W_FSI2PIB_STATUS;
SCOMT_PERV_USE_FSXCOMP_FSXLOG_SB_MSG;
SCOMT_PERV_USE_HANG_PULSE_0_REG;
SCOMT_PERV_USE_PRE_COUNTER_REG;
SCOMT_PERV_USE_PCBCTL_COMP_INTR_HOST_MASK_REG;
SCOMT_PERV_USE_FSXCOMP_FSXLOG_PERV_CTRL0;
SCOMT_PERV_USE_CPLT_CTRL0;
SCOMT_PERV_USE_CPLT_CTRL2;
SCOMT_PERV_USE_XSTOP1;
SCOMT_PERV_USE_EPS_CLKSTOP_ON_XSTOP_MASK1;

typedef FSXCOMP_FSXLOG_ROOT_CTRL0_t ROOT_CTRL0_t;
typedef FSXCOMP_FSXLOG_ROOT_CTRL1_t ROOT_CTRL1_t;
typedef FSXCOMP_FSXLOG_CBS_ENVSTAT_t CBS_ENVSTAT_t;
typedef FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_t ROOT_CTRL0_COPY_t;
typedef FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_t ROOT_CTRL1_COPY_t;
typedef FSXCOMP_FSXLOG_CBS_CS_t CBS_CS_t;
typedef FSXCOMP_FSXLOG_SB_CS_t SB_CS_t;
typedef TP_CFAM_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_t SBE_FIFO_FSB_DOWNFIFO_RESET_t;
typedef TP_CFAM_FSI_W_FSI2PIB_STATUS_t FSI2PIB_STATUS_t;
typedef FSXCOMP_FSXLOG_SB_MSG_t SB_MSG_t;
typedef HANG_PULSE_0_REG_t HANG_PULSE_0_t;
typedef PRE_COUNTER_REG_t PRE_COUNTER_t;
typedef PCBCTL_COMP_INTR_HOST_MASK_REG_t INTR_HOST_MASK_t;
typedef FSXCOMP_FSXLOG_PERV_CTRL0_t PERV_CTRL0_t;
typedef EPS_CLKSTOP_ON_XSTOP_MASK1_t CLKSTOP_ON_XSTOP_MASK1_t;
