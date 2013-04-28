/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/tod_init/proc_tod_init/proc_tod_init.H $     */
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
// $Id: proc_tod_init.H,v 1.4 2013/03/05 23:21:08 jklazyns Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
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
typedef fapi::ReturnCode
(*proc_tod_init_FP_t) (const tod_topology_node*);

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
 * @return FAPI_RC_SUCCESS if TOD topology is successfully initialized
 *         else FAPI or ECMD error is sent through
 */
fapi::ReturnCode proc_tod_init(const tod_topology_node* i_tod_node);

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
 * @return FAPI_RC_SUCCESS if TOD topology is successfully initialized
 *         else FAPI or ECMD error is sent through
 */
fapi::ReturnCode init_tod_node(const tod_topology_node* i_tod_node);

} // extern "C"

#endif // PROC_TOD_INIT_H_
