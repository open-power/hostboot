/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_read_seeprom.H $ */
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
// $Id: proc_read_seeprom.H,v 1.4 2013/06/06 20:45:13 cswenson Exp $
/* File proc_read_seeprom.H created by KUHFAL, CHRISTINA L. (CHRISTY) on Thu Jun 21 2012. */

/* Change Activity: */
/* End Change Activity */

#ifndef _PROC_READ_SEEPROM_H
#define _PROC_READ_SEEPROM_H

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi.H>
#include "p8_scom_addresses.H"

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*proc_read_seeprom_FP_t)(const fapi::Target &,
						   uint32_t &, uint32_t &, bool &, uint64_t *, bool &);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------


extern "C"
{

/**
 * @Read seeprom_0 or seeprom_1
 *
 * @param[in] i_target      Reference to processor chip target
 * @param[in] i_start_addr  The starting address to begin reading the seeprom
 * @param[in] i_length The  Length that is to be read from seeprom
 * @param[in] i_ecc_disable True if ecc is to be disabled false otherwise
 * @param[in] return_data   Data returned to the wrapper
 * @param[in] use_secondary True if secondary seeprom is to used, false otherwise
 * @return ReturnCode
 */
   fapi::ReturnCode proc_read_seeprom(const fapi::Target & i_target,
				      uint32_t & i_start_addr, uint32_t & i_length, bool & i_ecc_disable, uint64_t * return_data, bool & use_secondary);  

} // extern "C"

#endif /* _PROC_READ_SEEPROM_H */

/* Change Log
<@log@>

Fri Jul 27 2012  08:29:15  by KUHFAL, CHRISTINA L. (CHRISTY)
<reason><version><Brief description and why change was made.>

Fri Jun 22 2012  14:22:35  by KUHFAL, CHRISTINA L. (CHRISTY)
<reason><version><Brief description and why change was made.>

Thu Jun 21 2012  10:02:20  by KUHFAL, CHRISTINA L. (CHRISTY)
<reason><version><Brief description and why change was made.>
*/
