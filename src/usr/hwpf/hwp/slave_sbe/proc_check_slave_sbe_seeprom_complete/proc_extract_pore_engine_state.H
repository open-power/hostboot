/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_extract_pore_engine_state.H $ */
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
// $Id: proc_extract_pore_engine_state.H,v 1.2 2014/07/24 03:16:22 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_extract_pore_engine_state.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_extract_pore_engine_state.H
// *! DESCRIPTION : Extract PORE (SBE/SLW) engine state
// *!
// *! OWNER NAME  : Joe McGill              Email: jmcgill@us.ibm.com
// *! BACKUP NAME : Johannes Koesters       Email: koesters@de.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_EXTRACT_PORE_ENGINE_STATE_H_
#define _PROC_EXTRACT_PORE_ENGINE_STATE_H_


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>
#include <proc_extract_sbe_rc.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*proc_extract_pore_engine_state_FP_t)(const fapi::Target &,
                                                                void *,
                                                                const por_engine_t,
                                                                por_base_state &,
                                                                por_sbe_base_state &);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------


extern "C"
{


/**
 * proc_extract_pore_engine_state - HWP entry point, extract PORE engine state
 *
 * @param[in]   i_target         - chip target, used to collect engine state if
 *                                 i_poreve is NULL
 * @param[in]   i_poreve         - pointer to PoreVe object, used to collect engine
 *                                 state if non NULL
 * @param[in]   i_engine         - engine type to analyze (SBE/SLW)
 * @param[out]  o_pore_state     - PORE state/FFDC content
 * @param[out]  o_pore_sbe_state - PORE SBE-specific state/FFDC content (filled
 *                                 only if i_engine=SBE)
 *
 * @retval      fapi::ReturnCode = SUCCESS
 * @retval      fapi::ReturnCode = RC_PROC_EXTRACT_PORE_ENGINE_STATE_VSBE_MODEL_ERROR
 * @retval      fapi::ReturnCode = RC_PROC_EXTRACT_PORE_ENGINE_STATE_VSBE_PIB_ERROR
 * @retval      fapi::ReturnCode = RC_PROC_EXTRACT_PORE_ENGINE_STATE_UNSUPPORTED_INVOCATION
 */
fapi::ReturnCode proc_extract_pore_engine_state(const fapi::Target & i_target,
                                                void *,
                                                const por_engine_t i_engine,
                                                por_base_state & o_pore_state,
                                                por_sbe_base_state & o_pore_sbe_state);


} // extern "C"

#endif // _PROC_EXTRACT_PORE_ENGINE_STATE_H_
