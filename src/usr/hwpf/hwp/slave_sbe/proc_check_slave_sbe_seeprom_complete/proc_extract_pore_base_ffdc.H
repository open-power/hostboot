/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_extract_pore_base_ffdc.H $ */
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
// $Id: proc_extract_pore_base_ffdc.H,v 1.1 2014/07/23 19:38:05 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_extract_pore_base_ffdc.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_extract_pore_base_ffdc.C
// *! DESCRIPTION : Log base FFDC for SBE/SLW errors
// *!
// *! OWNER NAME  : Joe McGill              Email: jmcgill@us.ibm.com
// *! BACKUP NAME : Johannes Koesters       Email: koesters@de.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_EXTRACT_PORE_BASE_FFDC_H_
#define _PROC_EXTRACT_PORE_BASE_FFDC_H_


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>
#include <proc_extract_sbe_rc.H>


//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*proc_extract_pore_base_ffdc_FP_t)(const por_base_state &,
                                                             const por_sbe_base_state &,
                                                             fapi::ReturnCode &);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------


extern "C"
{

/**
 * proc_extract_pore_engine_state - HWP entry point, log PORE engine state
 *
 * @param[in]   i_pore_state     - struct holding PORE state
 * @param[in]   i_pore_sbe_state - struct holding PORE SBE specific state
 * @param[out]  o_rc             - target return code for extra FFDC
 *
 * @retval      fapi::ReturnCode = SUCCESS
 */
fapi::ReturnCode proc_extract_pore_base_ffdc(const por_base_state & i_pore_state,
                                             const por_sbe_base_state & i_pore_sbe_state,
                                             fapi::ReturnCode & o_rc);



} // extern "C"

#endif // _PROC_EXTRACT_PORE_BASE_FFDC_H_
