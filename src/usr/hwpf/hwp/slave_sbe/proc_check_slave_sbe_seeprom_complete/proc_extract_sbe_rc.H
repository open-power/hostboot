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
// $Id: proc_extract_sbe_rc.H,v 1.7 2014/03/18 14:09:28 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_extract_sbe_rc.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_extract_sbe_rc.H
// *! DESCRIPTION : Create a return code for an SBE/SLW error.
// *!
// *! OWNER NAME  : Johannes Koesters       Email: koesters@de.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_EXTRACT_SBE_RC_H_
#define _PROC_EXTRACT_SBE_RC_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>
#include <p8_scom_addresses.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------
enum por_engine_t {
  SBE = PORE_SBE_0x000E0000,
  SLW = PORE_SLW_0x00068000
};

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*proc_extract_sbe_rc_FP_t)(const fapi::Target &,
                                                     const void *,
                                                     const por_engine_t);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------


extern "C"
{

/**
 * @brief Create a return code based off the current SBE/SLW RC.
 *
 * @param[in] i_target         Reference to processor target containing the SBE/SLW engine
 * @param[in] i_pSEEPROM       Pointer to a memory-mapped SEEPROM image (or NULL) 
 * @param[in] i_engine         The POR engine type (SBE/SLW)
 * @return ReturnCode          The error code the SBE hit, or the error hit
 *                             while trying to get the error code
 */
  fapi::ReturnCode proc_extract_sbe_rc(const fapi::Target & i_target,
                                       const void         * i_pSEEPROM,
                                       const por_engine_t   i_engine);

} // extern "C"

#endif // _PROC_EXTRACT_SBE_RC_H_
