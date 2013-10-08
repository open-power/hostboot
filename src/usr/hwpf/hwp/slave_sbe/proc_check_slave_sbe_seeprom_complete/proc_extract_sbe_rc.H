/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_extract_sbe_rc.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
// $Id: proc_extract_sbe_rc.H,v 1.4 2013/09/20 15:26:50 jeshua Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_extract_sbe_rc.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_extract_sbe_rc.H
// *! DESCRIPTION : Create a return code for an SBE error. Will NEVER return
// *!               with SUCCESS.
// *!
// *! OWNER NAME  : Jeshua Smith            Email: jeshua@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_EXTRACT_SBE_RC_H_
#define _PROC_EXTRACT_SBE_RC_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi.H>
#include "p8_scom_addresses.H"

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Enum definitions
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
 * @brief Create a return code based off the current SBE RC.
 *
 * @param[in] i_target         Reference to processor target containing the SBE
 *
 * @param[in] i_pSEEPROM       Pointer to a memory-mapped SEEPROM image (or NULL) 
 *
 * @param[in] i_engine         The POR engine type (SBE/SLW)
 *
 * @return ReturnCode          The error code the SBE hit, or the error hit
 *                             while trying to get the error code
 */
  fapi::ReturnCode proc_extract_sbe_rc(const fapi::Target & i_target,
                                       const void         * i_pSEEPROM,
                                       const por_engine_t   i_engine);

} // extern "C"

#endif // _PROC_EXTRACT_SBE_RC_H_
