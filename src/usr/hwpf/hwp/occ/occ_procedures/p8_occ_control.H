/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_occ_control.H $        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/* begin_generated_IBM_copyright_prolog                            */
/*                                                                 */
/* This is an automatically generated copyright prolog.            */
/* After initializing,  DO NOT MODIFY OR MOVE                      */ 
/* --------------------------------------------------------------- */
/* IBM Confidential                                                */
/*                                                                 */
/* Licensed Internal Code Source Materials                         */
/*                                                                 */
/* (C)Copyright IBM Corp.  2014, 2014                              */
/*                                                                 */
/* The Source code for this program is not published  or otherwise */
/* divested of its trade secrets,  irrespective of what has been   */
/* deposited with the U.S. Copyright Office.                       */
/*  -------------------------------------------------------------- */
/*                                                                 */
/* end_generated_IBM_copyright_prolog                              */
#ifndef _P8_OCC_CONTROL_H_
#define _P8_OCC_CONTROL_H_

#include <fapi.H>

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_occ_control_FP_t) (const fapi::Target&, 
                                                    const uint8_t, 
                                                    const uint8_t);

extern "C" {

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

fapi::ReturnCode p8_occ_control(const fapi::Target& i_target, 
                                         const uint8_t i_ppc405_reset_ctrl,
                                         const uint8_t i_ppc405_boot_ctrl);
// ---------
// Constants
// ---------
const uint8_t PPC405_RESET_NULL         = 0x00; 
const uint8_t PPC405_RESET_OFF          = 0x01;
const uint8_t PPC405_RESET_ON           = 0x02;

const uint8_t PPC405_BOOT_NULL          = 0x00;
const uint8_t PPC405_BOOT_SRAM          = 0x01;
const uint8_t PPC405_BOOT_MEM           = 0x02;
const uint8_t PPC405_BOOT_OLD           = 0x03;

const uint32_t PPC405_BRANCH_SRAM_INSTR = 0x4BF80012;  // Branch Absolute 0xFFF80010  => ba 0xfff80010 (boot from sram)
const uint32_t PPC405_BRANCH_MEM_INSTR  = 0x48000012;  // Branch Absolute 0x00000010  => ba 0x00000010 (boot from memory)
const uint32_t PPC405_BRANCH_OLD_INSTR  = 0x4BFFFFF0;  // Branch Relative -16                          (boot from sram)

} // extern "C"

#endif 
