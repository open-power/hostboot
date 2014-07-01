/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_check_slave_sbe_seeprom_complete.H $ */
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
// $Id: proc_check_slave_sbe_seeprom_complete.H,v 1.5 2014/06/10 12:41:42 dsanner Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_check_slave_sbe_seeprom_complete.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_check_slave_sbe_seeprom_complete.H
// *! DESCRIPTION : Check if a slave has completed the seeprom code
// *!
// *! OWNER NAME  : Joe McGill              Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_CHECK_SLAVE_SBE_SEEPROM_COMPLETE_H_
#define _PROC_CHECK_SLAVE_SBE_SEEPROM_COMPLETE_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*proc_check_slave_sbe_seeprom_complete_FP_t)(const fapi::Target &,
                                                                       const void *,
                                                                       const size_t);

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------


extern "C"
{

/**
 * @brief Check if the slave chip stopped successfully at the end of
 *        proc_sbe_check_master / proc_sbe_enable_pnor
 *
 * @param[in] i_target           Reference to processor slave chip target
 * @param[in] i_pSEEPROM         Pointer to the seeprom image (for errors)
 * @param[in] i_wait_in_ms       Amount of time to wait in ms for SBE to complete
 *
 * @return ReturnCode            Success if slave chip stopped at correct place,
 *                               else error
 */
  fapi::ReturnCode proc_check_slave_sbe_seeprom_complete(
                                               const fapi::Target & i_target,
                                               const void         * i_pSEEPROM,
                                               const size_t       i_wait_in_ms = 1000);

} // extern "C"

#endif // _PROC_CHECK_SLAVE_SBE_SEEPROM_COMPLETE_H_
