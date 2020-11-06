/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/common/include/p9a_mc_scom_addresses_fixes.H $ */
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

///
/// @file p9a_mc_scom_addresses_fixed.H
/// @brief  Defines constants for scom addresses
///
// *HWP HWP Owner: Ben Gass <bgass@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: SOA
// *HWP Level: 1
// *HWP Consumed by: FSP:HB:HS:OCC:SBE:CME:SGPE:PGPE:FPPE:IPPE


#ifndef __P9A_MC_SCOM_ADDRESSES_FIXES_H
#define __P9A_MC_SCOM_ADDRESSES_FIXES_H

static const uint64_t P9A_MC_REG0_DL0_ERROR_ACTION                          = 0x0701335Dull;
static const uint64_t P9A_MC_REG0_DL1_ERROR_ACTION                          = 0x0701336Dull;
static const uint64_t P9A_MC_REG0_DL2_ERROR_ACTION                          = 0x0701337Dull;
static const uint64_t P9A_MC_REG1_DL0_ERROR_ACTION                          = 0x0701339Dull;
static const uint64_t P9A_MC_REG1_DL1_ERROR_ACTION                          = 0x070133ADull;
static const uint64_t P9A_MC_REG1_DL2_ERROR_ACTION                          = 0x070133BDull;
static const uint64_t P9A_MC_REG2_DL0_ERROR_ACTION                          = 0x070133DDull;
static const uint64_t P9A_MC_REG2_DL1_ERROR_ACTION                          = 0x070133EDull;
static const uint64_t P9A_MC_REG2_DL2_ERROR_ACTION                          = 0x070133FDull;

static const uint64_t P9A_MC_REG2_DL0_RMT_CONFIG                            = 0x070133D8ull;

static const uint64_t P9A_MC_REG0_CMN_CONFIG                                = 0x0701334Eull;

static const uint64_t P9A_MC_REG1_CMN_CONFIG                                = 0x0701338Eull;

static const uint64_t P9A_MC_REG2_CMN_CONFIG                                = 0x070133CEull;

static const uint64_t P9A_MCC_DSTLCFG2                                      = 0x0701090Eull;

static const uint64_t P9A_MCC_USTLFAILMASK                                  = 0x07010A13ull;

static const uint64_t P9A_MC_REG0_OMI_FIR                                   = 0x07013340ull;
static const uint64_t P9A_MC_REG0_OMI_FIR_MASK                              = 0x07013343ull;
static const uint64_t P9A_MC_REG0_OMI_FIR_ACTION0                           = 0x07013346ull;
static const uint64_t P9A_MC_REG0_OMI_FIR_ACTION1                           = 0x07013347ull;
static const uint64_t P9A_MC_REG0_OMI_FIR_MASK_AND                          = 0x07013344ull;
static const uint64_t P9A_MC_REG0_OMI_FIR_MASK_OR                           = 0x07013345ull;

static const uint64_t P9A_MC_REG1_OMI_FIR                                   = 0x07013380ull;
static const uint64_t P9A_MC_REG1_OMI_FIR_MASK                              = 0x07013383ull;
static const uint64_t P9A_MC_REG1_OMI_FIR_ACTION0                           = 0x07013386ull;
static const uint64_t P9A_MC_REG1_OMI_FIR_ACTION1                           = 0x07013387ull;
static const uint64_t P9A_MC_REG1_OMI_FIR_MASK_AND                          = 0x07013384ull;
static const uint64_t P9A_MC_REG1_OMI_FIR_MASK_OR                           = 0x07013385ull;

static const uint64_t P9A_MC_REG2_OMI_FIR                                   = 0x070133C0ull;
static const uint64_t P9A_MC_REG2_OMI_FIR_MASK                              = 0x070133C3ull;
static const uint64_t P9A_MC_REG2_OMI_FIR_ACTION0                           = 0x070133C6ull;
static const uint64_t P9A_MC_REG2_OMI_FIR_ACTION1                           = 0x070133C7ull;
static const uint64_t P9A_MC_REG2_OMI_FIR_MASK_AND                          = 0x070133C4ull;
static const uint64_t P9A_MC_REG2_OMI_FIR_MASK_OR                           = 0x070133C5ull;

static const uint64_t P9A_MCC_USTLLOLMASK                                   = 0x07010A12ull;

#endif
