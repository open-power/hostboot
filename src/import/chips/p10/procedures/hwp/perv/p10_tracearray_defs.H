/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_tracearray_defs.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
/// @file  p10_tracearray_defs.H
///
/// @brief Constants to be used for p10 trayarray usage across platforms.
///
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Nicholas Landi <nlandi@ibm.com>
// *HWP FW Maintainer   : Raja Das <rajadas2@in.ibm.com>
// *HWP Consumed by     : Cronus, SBE
//------------------------------------------------------------------------------

#ifndef _P10_TRACEARRAY_DEFS_H
#define _P10_TRACEARRAY_DEFS_H
//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// maximum trace array entries supported by P10 chip design
static const uint8_t P10_TRACEARRAY_NUM_ROWS = 128;
// bits to store per trace array entry
static const uint8_t P10_TRACEARRAY_BITS_PER_ROW = 128;
// maximum trace array size in bytes
static const uint16_t PROC_TRACEARRAY_MAX_SIZE =
    (P10_TRACEARRAY_NUM_ROWS* P10_TRACEARRAY_BITS_PER_ROW) / 8;

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

/**
 * @brief Identifiers for supported trace arrays.
 *
 * There is an identifier for each available trace bus. Many arrays are shared
 * between multiple trace buses; in that case, several identifiers point to the
 * same trace array.
 */
enum p10_tracearray_bus_id
{
    NO_TB = 0,
    /* Pervasive chiplet - TARGET_TYPE_PROC_CHIP */
    PROC_TB_PIB     = 1,
    PROC_TB_OCC,
    PROC_TB_TOD,
    PROC_TB_SBE,
    PROC_TB_PIB_ALT,  /* alternate sink for PIB trace */

    /* Nest chiplets - TARGET_TYPE_PROC_CHIP */
    PROC_TB_PB0,
    PROC_TB_PB1,
    PROC_TB_PB2,
    PROC_TB_PB3,
    PROC_TB_PB4,
    PROC_TB_PB5,
    PROC_TB_PB6,
    PROC_TB_PB7,
    PROC_TB_PB8,
    PROC_TB_PB9,
    PROC_TB_PB10,
    PROC_TB_PB11,
    PROC_TB_MCD,
    PROC_TB_NX,
    PROC_TB_VAS,
    PROC_TB_PE0,
    PROC_TB_PE1,
    PROC_TB_NMMU0_0,
    PROC_TB_NMMU0_1,
    PROC_TB_NMMU1_0,
    PROC_TB_NMMU1_1,
    PROC_TB_INT,
    PROC_TB_PSI,
    PROC_TB_PBA,
    PROC_TB_ADU,
    PROC_TB_BR,

    _PROC_TB_LAST_PROC_TARGET = 0x40,

    /* PCI chiplets - TARGET_TYPE_PEC */
    PROC_TB_PE_0,
    PROC_TB_PE_1,
    PROC_TB_PE_2,
    PROC_TB_AIB,
    _PROC_TB_LAST_PEC_TARGET = 0x60,

    /* MemCtrl chiplets - TARGET_TYPE_MC */
    PROC_TB_MC0,
    PROC_TB_MC1,
    PROC_TB_DLM01_45,
    PROC_TB_DLM23_67,

    _PROC_TB_LAST_MC_TARGET = 0x80,

    /* PAUC chiplets - TARGET_TYPE_PAUC */
    PROC_TB_PAU0_0,
    PROC_TB_PAU0_1,
    PROC_TB_PAU1_0,
    PROC_TB_PAU1_1,
    PROC_TB_PTL0,
    PROC_TB_PTL1,

    _PROC_TB_LAST_PAUC_TARGET = 0xA0,

    /* AXON chiplets - TARGET_TYPE_IOHS */
    PROC_TB_IOHS,

    _PROC_TB_LAST_IOHS_TARGET  = 0xC0,
    /* Core regions - TARGET_TYPE_CORE */
    PROC_TB_L20,
    PROC_TB_L21,

    _PROC_TB_LAST_CORE_TARGET  = 0xE0,
    /* EQ chiplets passed by core - TARGET_TYPE_CORE */
    PROC_TB_L3_0,
    PROC_TB_L3_1,
    PROC_TB_NCU_0,
    PROC_TB_NCU_1,
    PROC_TB_CLKADJ,

    _PROC_TB_LAST_CORE_EQ_TARGET = 0xF0,
    /* EQ chiplets - TARGET_TYPE_EQ */
    PROC_TB_QME0,
    PROC_TB_QME1

};

#endif //_P10_TRACEARRAY_DEFS_H
