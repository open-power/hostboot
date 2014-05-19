/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_occ_control.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: p8_occ_control.H,v 1.4 2014/04/21 14:27:53 bcbrock Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_occ_control.H,v $
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
const uint8_t PPC405_HALT_OFF           = 0x03;
const uint8_t PPC405_HALT_ON            = 0x04;
const uint8_t PPC405_RESET_SEQUENCE     = 0x05;

const uint8_t PPC405_BOOT_NULL          = 0x00;
const uint8_t PPC405_BOOT_SRAM          = 0x01;
const uint8_t PPC405_BOOT_MEM           = 0x02;
const uint8_t PPC405_BOOT_OLD           = 0x03;

const uint32_t PPC405_BRANCH_SRAM_INSTR = 0x4BF80042;  // Branch Absolute 0xFFF80040  (boot from sram)
const uint32_t PPC405_BRANCH_MEM_INSTR  = 0x48000042;  // Branch Absolute 0x00000040  (boot from memory)
const uint32_t PPC405_BRANCH_OLD_INSTR  = 0x4BFFFFF0;  // Branch Relative -16         (boot from sram)

} // extern "C"

#endif 
