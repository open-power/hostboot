/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_extract_sbe_rc.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
// $Id: proc_extract_sbe_rc.H,v 1.9 2014/07/24 03:13:59 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_extract_sbe_rc.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_extract_sbe_rc.H
// *! DESCRIPTION : Create return code for PORE (SBE/SLW) error
// *!
// *! OWNER NAME  : Joe McGill              Email: jmcgill@us.ibm.com
// *! BACKUP NAME : Johannes Koesters       Email: koesters@de.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_EXTRACT_SBE_RC_H_
#define _PROC_EXTRACT_SBE_RC_H_


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>
#include <p8_scom_addresses.H>
#include <cen_scom_addresses.H>


//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// engine types
enum por_engine_t {
    SBE = PORE_SBE_0x000E0000,
    SLW = PORE_SLW_0x00068000
};

// common SCOM register offsets for SBE/SLW engines
enum por_reg_offset_t {
    PORE_STATUS_OFFSET      = 0x00,
    PORE_CONTROL_OFFSET     = 0x01,
    PORE_RESET_OFFSET       = 0x02,
    PORE_ERR_MASK_OFFSET    = 0x03,
    PORE_P0_OFFSET          = 0x04,
    PORE_P1_OFFSET          = 0x05,
    PORE_A0_OFFSET          = 0x06,
    PORE_A1_OFFSET          = 0x07,
    PORE_TBL_BASE_OFFSET    = 0x08,
    PORE_EXE_TRIGGER_OFFSET = 0x09,
    PORE_CTR_OFFSET         = 0x0A,
    PORE_D0_OFFSET          = 0x0B,
    PORE_D1_OFFSET          = 0x0C,
    PORE_IBUF0_OFFSET       = 0x0D,
    PORE_IBUF1_OFFSET       = 0x0E,
    PORE_DEBUG0_OFFSET      = 0x0F,
    PORE_DEBUG1_OFFSET      = 0x10,
    PORE_STACK0_OFFSET      = 0x11,
    PORE_STACK1_OFFSET      = 0x12,
    PORE_STACK2_OFFSET      = 0x13,
    PORE_IDFLAGS_OFFSET     = 0x14,
    PORE_SPRG0_OFFSET       = 0x15,
    PORE_MRR_OFFSET         = 0x16,
    PORE_I2CE0_OFFSET       = 0x17,
    PORE_I2CE1_OFFSET       = 0x18,
    PORE_I2CE2_OFFSET       = 0x19,
    PORE_NUM_REGS           = 0x1A
};

// SBE soft error types
enum por_sbe_soft_error_t
{
    eNO_ERROR = 0,
    eSOFT_ERR_I2CM=1, 
    eSOFT_ERR_PNOR=2,
    eSOFT_ERR_BOTH=3
};

enum por_halt_type_t
{
    PORE_HALT_SCAN_FAIL = 0,
    PORE_HALT_SCAN_FLUSH_FAIL = 1,
    PORE_HALT_ARRAYINIT_FAIL = 2,
    PORE_HALT_SKEW_ADJUST_FAIL = 3,
    PORE_HALT_FIR_FAIL = 4,
    PORE_HALT_INSTRUCT_FAIL = 5,
    PORE_HALT_DPLL_LOCK_FAIL = 6
};

enum por_ffdc_offset_t
{
    POR_FFDC_OFFSET_NONE = 0x0,
    POR_FFDC_OFFSET_TP_CHIPLET = TP_CHIPLET_0x01000000,
    POR_FFDC_OFFSET_NEST_CHIPLET = NEST_CHIPLET_0x02000000,
    POR_FFDC_OFFSET_MEM_CHIPLET = MEM_CHIPLET_0x03000000,
    POR_FFDC_OFFSET_XBUS_CHIPLET = X_BUS_CHIPLET_0x04000000,
    POR_FFDC_OFFSET_ABUS_CHIPLET = A_BUS_CHIPLET_0x08000000,
    POR_FFDC_OFFSET_PCIE_CHIPLET = PCIE_CHIPLET_0x09000000,
    POR_FFDC_OFFSET_EX_CHIPLET = EX00_CHIPLET_0x10000000,
    POR_FFDC_OFFSET_USE_P0 = PORE_P0_OFFSET,
    POR_FFDC_OFFSET_USE_P1 = PORE_P1_OFFSET
};


// structure to encapsulate PORE state/FFDC content
struct por_base_state
{
    fapi::Target target;               // chip target associated with failed engine
    por_engine_t engine;               // engine type (SBE/SLW)
    bool is_virtual;                   // virtual engine?
    ecmdDataBufferBase vital_state;    // SBE/SLW vital state
    ecmdDataBufferBase engine_state;   // SBE/SLW engine state
    uint64_t pc;                       // SBE/SLW engine PC
    uint32_t rc;                       // RC associated with SBE/SLW halt point

    por_base_state()
    {
        vital_state.setDoubleWordLength(1);
        vital_state.flushTo1();
        engine_state.setDoubleWordLength(PORE_NUM_REGS);
        engine_state.flushTo1();
        pc = 0xFFFFFFFFFFFFFFFFULL;
        rc = 0x0;
    }
};

// structure to encapsulate PORE SBE-specific base FFDC content
struct por_sbe_base_state
{
    ecmdDataBufferBase pnor_eccb_status;  // PNOR ECCB status register state
    ecmdDataBufferBase i2cm_eccb_status;  // SEEPROM ECCB status register state
    por_sbe_soft_error_t soft_err;        // PNOR/SEEPROM soft error state
    bool reported_attn;                   // SBE generated attention?

    por_sbe_base_state()
    {
        pnor_eccb_status.setDoubleWordLength(1);
        pnor_eccb_status.flushTo1();
        i2cm_eccb_status.setDoubleWordLength(1);
        i2cm_eccb_status.flushTo1();
        soft_err = eNO_ERROR;
        reported_attn = false;
    }
};

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*proc_extract_sbe_rc_FP_t)(const fapi::Target &,
                                                     void *,
                                                     const void *,
                                                     const por_engine_t);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------


extern "C"
{

/**
 * proc_extract_sbe_rc - HWP entry point, return RC indicating SBE/SLW error
 *
 * @param[in]   i_target - target of chip with failed SBE/SLW engine
 * @param[in]   i_poreve - pointer to PoreVe object, used to collect engine
 *                         state if non NULL
 * @param[in]   i_image  - pointer to memory-mapped PORE image
 * @param[in]   i_engine - type of engine that failed (SBE/SLW)
 *
 * @retval      fapi::ReturnCode  - The error code the SBE hit, or the error hit
 *                                  while trying to get the error code
 */
fapi::ReturnCode proc_extract_sbe_rc(const fapi::Target & i_target,
                                     void * i_poreve,
                                     const void * i_image,
                                     const por_engine_t i_engine);

} // extern "C"

#endif // _PROC_EXTRACT_SBE_RC_H_
