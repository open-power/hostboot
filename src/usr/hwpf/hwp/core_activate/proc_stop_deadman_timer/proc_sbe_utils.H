/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/core_activate/proc_stop_deadman_timer/proc_sbe_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
// $Id: proc_sbe_utils.H,v 1.1 2015/07/27 00:39:15 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_sbe_utils.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2015
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_sbe_utils.H
// *! DESCRIPTION : SBE utility functions
// *!
// *! OWNER NAME  : Joe McGill              Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_SBE_UTILS_H_
#define _PROC_SBE_UTILS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{


/**
 * @brief Reset SBE engine
 *
 * @param[in] i_target Reference to chip target
 * @return ReturnCode
 */
fapi::ReturnCode proc_sbe_utils_reset_sbe(
    const fapi::Target & i_target);

/**
 * @brief Update SBE Vital register with substep progress code
 *
 * @param[in] i_target Reference to chip target
 * @param[in] i_substep_num Substep progress code to write
 * @return ReturnCode
 */
fapi::ReturnCode proc_sbe_utils_update_substep(
    const fapi::Target & i_target,
    uint8_t i_substep_num);

/**
 * @brief Determine SBE run state and istep progress
 *
 * @param[in] i_target Reference to chip target
 * @param[out] o_running Is SBE running or stopped?
 * @param[out] o_halt_code SBE halt code (only valid if SBE stopped)
 * @param[out] o_istep_num Current istep number (0xMmm)
 * @param[out] o_substep_num Current substep within istep
 * @return ReturnCode
 */
fapi::ReturnCode proc_sbe_utils_check_status(
    const fapi::Target & i_target,
    bool & o_running,
    uint8_t & o_halt_code,
    uint16_t & o_istep_num,
    uint8_t & o_substep_num);


} // extern "C"

#endif // _PROC_SBE_UTILS_H_
