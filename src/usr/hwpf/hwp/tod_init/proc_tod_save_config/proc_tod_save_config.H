/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/tod_init/proc_tod_save_config/proc_tod_save_config.H $ */
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
// $Id: proc_tod_save_config.H,v 1.1 2012/10/31 21:34:27 jklazyns Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *!
// *! TITLE : proc_tod_save_config.H
// *!
// *! DESCRIPTION : Header for proc_tod_save_config.C
// *!
// *! OWNER NAME  : Nick Klazynski  Email: jklazyns@us.ibm.com
// *! BACKUP NAME :                 Email:
// *!
// *! ADDITIONAL COMMENTS :
// *!
//------------------------------------------------------------------------------

#ifndef PROC_TOD_SAVE_CONFIG_H_
#define PROC_TOD_SAVE_CONFIG_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi.H>
#include "proc_tod_utils.H"

extern "C"
{

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode
(*proc_tod_save_config_FP_t) (tod_topology_node*);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

/**
 * @brief Saves TOD configuration registers to i_tod_node->o_todRegs
 *
 * @param[in] i_tod_node  Reference to TOD topology (FAPI targets included within)
 *
 * @return FAPI_RC_SUCCESS if all registers were read and saved in node structure
 *         else FAPI or ECMD error is sent through
 */
fapi::ReturnCode proc_tod_save_config(tod_topology_node* i_tod_node);

/**
 * @brief Helper function which saves a single register to output buffer
 *
 * @param[in]  i_target FAPI target
 *             i_addr   SCOM address to read
 * @param[out] o_data   Buffer to save register read
 *
 * @return FAPI_RC_SUCCESS if the given register was read and saved into buffer
 *         else FAPI or ECMD error is sent through
 */
fapi::ReturnCode proc_tod_save_single_reg(const fapi::Target& i_target,
                                          const uint64_t      i_addr,
                                          ecmdDataBufferBase& o_data);

} // extern "C"

#endif // PROC_TOD_SAVE_CONFIG_H_
