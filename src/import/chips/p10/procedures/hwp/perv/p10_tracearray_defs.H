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
//TODO: RTC:202264
//TODO: Replace all comments with p10 specific code

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
    PROC_TB_PB12,
    PROC_TB_PB13,
    PROC_TB_MCS0,
    PROC_TB_MCS1,
    PROC_TB_MCS2,
    PROC_TB_MCS3,
    PROC_TB_MCD0,
    PROC_TB_MCD1,
    PROC_TB_VAS,
    PROC_TB_PBIO0,
    PROC_TB_PBIO1,
    PROC_TB_PBIOE0,
    PROC_TB_PBIOE1,
    PROC_TB_CXA0,
    PROC_TB_CXA1,
    PROC_TB_NX,
    PROC_TB_IOPSI,
    PROC_TB_PCIS0,
    PROC_TB_PCIS1,
    PROC_TB_PCIS2,
    PROC_TB_NPU0,
    PROC_TB_NPU1,
    PROC_TB_NMMU0,
    PROC_TB_NMMU1,
    PROC_TB_INT,
    PROC_TB_BRIDGE,

    /* XBUS chiplet - TARGET_TYPE_PROC_CHIP */
    PROC_TB_IOX0,
    PROC_TB_IOX1,
    PROC_TB_IOX2,
    PROC_TB_PBIOX0,
    PROC_TB_PBIOX1,
    PROC_TB_PBIOX2,

    /* PCI chiplets - TARGET_TYPE_PROC_CHIP */
    PROC_TB_PCI0X,
    PROC_TB_PCI00,
    PROC_TB_PCI1X,
    PROC_TB_PCI11,
    PROC_TB_PCI12,
    PROC_TB_PCI2X,
    PROC_TB_PCI23,
    PROC_TB_PCI24,
    PROC_TB_PCI25,

    _PROC_TB_LAST_PROC_TARGET = PROC_TB_PCI25,

    /* OBus chiplets - TARGET_TYPE_OBUS */
    PROC_TB_PBIOOA,
    PROC_TB_IOO,

    _PROC_TB_LAST_OBUS_TARGET = PROC_TB_IOO,

    /* MemCtrl chiplets - TARGET_TYPE_MCS */
    PROC_TB_MCA0,
    PROC_TB_MCA1,
    PROC_TB_IOMC0,
    PROC_TB_IOMC1,
    PROC_TB_IOMC2,
    PROC_TB_IOMC3,

    _PROC_TB_LAST_MC_TARGET = PROC_TB_IOMC3,

    /* Cache chiplets - TARGET_TYPE_EX */
    PROC_TB_L30,
    PROC_TB_L31,
    PROC_TB_NCU0,
    PROC_TB_NCU1,
    PROC_TB_CME,
    PROC_TB_EQPB,    // note: only for odd EX instances
    PROC_TB_IVRM,
    PROC_TB_SKEWADJ, // note: only for even EX instances
    PROC_TB_L20,
    PROC_TB_L21,
    PROC_TB_SKIT10,
    PROC_TB_SKIT11,

    _PROC_TB_LAST_EX_TARGET = PROC_TB_SKIT11,

    /* Core chiplets - TARGET_TYPE_CORE */
    PROC_TB_CORE0,
    PROC_TB_CORE1,
};

#endif //_P10_TRACEARRAY_DEFS_H
