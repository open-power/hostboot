/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/tod_init/proc_tod_init/proc_tod_init.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
// $Id: proc_tod_init.H,v 1.5 2014/10/03 18:44:52 thi Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *!
// *! TITLE : proc_tod_init.H
// *!
// *! DESCRIPTION : Header for proc_tod_init.C
// *!
// *! OWNER NAME  : Nick Klazynski  Email: jklazyns@us.ibm.com
// *! BACKUP NAME :                 Email:
// *!
// *! ADDITIONAL COMMENTS :
// *!
//------------------------------------------------------------------------------

#ifndef PROC_TOD_INIT_H_
#define PROC_TOD_INIT_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi.H>
#include "proc_tod_utils.H"

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*proc_tod_init_FP_t) (const tod_topology_node*,
        fapi::Target* );

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

/**
 * @brief Initializes the TOD to 'running' state
 *
 * @param[in] i_tod_node  Reference to TOD topology (FAPI targets included within)
 *
 * @param[in] i_failingTodProc, Pointer to the fapi target, the memory location
 *         addressed by this parameter will be populated with processor target
 *         which is not able to recieve proper singals from OSC.
 *         Caller needs to look at this parameter only when proc_tod_init fails 
 *         and reason code indicates OSC failure. It is defaulted to NULL.
 *
 * @return FAPI_RC_SUCCESS if TOD topology is successfully initialized
 *         else FAPI or ECMD error is sent through
 */
fapi::ReturnCode proc_tod_init(const tod_topology_node* i_tod_node,
            fapi::Target* i_failingTodProc = NULL );

/**
 * @brief Clears TOD error register
 *
 * @param[in] i_tod_node  Reference to TOD topology (FAPI targets included within)
 *
 * @return FAPI_RC_SUCCESS if TOD topology is cleared of previous errors
 *         else FAPI or ECMD error is sent through
 */
fapi::ReturnCode proc_tod_clear_error_reg(const tod_topology_node* i_tod_node);

/**
 * @brief Helper function for proc_tod_init
 *
 * @param[in] i_tod_node  Reference to TOD topology (FAPI targets included within)
 *
 * @param[in] i_failingTodProc, Pointer to the fapi target, the memory location
 *         addressed by this parameter will be populated with processor target
 *         which is not able to recieve proper singals from OSC.
 *         Caller needs to look at this parameter only when proc_tod_init fails 
 *         and reason code indicates OSC failure. It is defaulted to NULL.
 *
 * @return FAPI_RC_SUCCESS if TOD topology is successfully initialized
 *         else FAPI or ECMD error is sent through
 */
fapi::ReturnCode init_tod_node(const tod_topology_node* i_tod_node,
        fapi::Target* i_failingTodProc = NULL);

} // extern "C"

#endif // PROC_TOD_INIT_H_
