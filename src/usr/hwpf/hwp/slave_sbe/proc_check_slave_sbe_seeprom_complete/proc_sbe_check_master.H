/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_sbe_check_master.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
// $Id: proc_sbe_check_master.H,v 1.2 2012/10/16 02:43:51 jmcgill Exp $

/// Substep numbers for proc_sbe_check_master

#ifndef __PROC_SBE_CHECK_MASTER_H
#define __PROC_SBE_CHECK_MASTER_H

#include "fapi_sbe_common.H"
#include "sbe_vital.H"

CONST_UINT8_T(SUBSTEP_CHECK_MASTER_PROC_ENTRY,           ULL(0x0));
CONST_UINT8_T(SUBSTEP_CHECK_MASTER_SLAVE_CHIP,           ULL(0x1));
CONST_UINT8_T(SUBSTEP_CHECK_MASTER_MASTER_CHIP,          ULL(0x2));


#endif  // __PROC_SBE_CHECK_MASTER_H
