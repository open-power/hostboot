/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_check_slave_sbe_seeprom_complete.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: proc_check_slave_sbe_seeprom_complete.H,v 1.4 2014/02/10 02:32:02 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_check_slave_sbe_seeprom_complete.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
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
                                                                       const void *);

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
 *
 * @return ReturnCode            Success if slave chip stopped at correct place,
 *                               else error
 */
  fapi::ReturnCode proc_check_slave_sbe_seeprom_complete(
                                               const fapi::Target & i_target,
                                               const void         * i_pSEEPROM);

} // extern "C"

#endif // _PROC_CHECK_SLAVE_SBE_SEEPROM_COMPLETE_H_
