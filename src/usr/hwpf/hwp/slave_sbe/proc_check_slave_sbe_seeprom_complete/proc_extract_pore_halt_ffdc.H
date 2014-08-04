/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_extract_pore_halt_ffdc.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
// $Id: proc_extract_pore_halt_ffdc.H,v 1.1 2014/07/23 19:38:06 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_extract_pore_halt_ffdc.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_extract_pore_halt_ffdc.C
// *! DESCRIPTION : Extract SBE/SLW halt-fail related FFDC
// *!
// *! OWNER NAME  : Joe McGill              Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_EXTRACT_PORE_HALT_FFDC_H_
#define _PROC_EXTRACT_PORE_HALT_FFDC_H_


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>
#include <proc_extract_sbe_rc.H>


//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*proc_extract_pore_halt_ffdc_FP_t)(const por_base_state &,
                                                             const por_halt_type_t,
                                                             const por_ffdc_offset_t,
                                                             fapi::ReturnCode &);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------


extern "C"
{

/**
 * proc_extract_pore_halt_ffdc - HWP entry point, log PORE fail FFDC
 *
 * @param[in]   i_pore_state - struct holding PORE state
 * @param[in]   i_halt_type  - FFDC type to collect
 * @param[in]   i_offset     - offset to apply to FFDC registers for
 *                             i_halt_type (constant/value of PORE
 *                             pervasive base registers/none)
 * @param[out]  o_rc         - target return code for extra FFDC
 *
 * @retval      fapi::ReturnCode = SUCCESS
 */
fapi::ReturnCode proc_extract_pore_halt_ffdc(const por_base_state & i_pore_state,
                                             const por_halt_type_t i_halt_type,
                                             const por_ffdc_offset_t i_offset,
                                             fapi::ReturnCode & o_rc);

} // extern "C"

#endif // _PROC_EXTRACT_PORE_HALT_FFDC_H_
