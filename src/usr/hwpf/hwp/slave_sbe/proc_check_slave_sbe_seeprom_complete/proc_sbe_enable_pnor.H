/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_sbe_enable_pnor.H $ */
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
// $Id: proc_sbe_enable_pnor.H,v 1.1 2012/10/16 02:44:44 jmcgill Exp $

/// Substep numbers for proc_sbe_enable_pnor

#ifndef __PROC_SBE_ENABLE_PNOR_H
#define __PROC_SBE_ENABLE_PNOR_H

#include "fapi_sbe_common.H"
#include "sbe_vital.H"

CONST_UINT8_T(SUBSTEP_ENABLE_PNOR_PROC_ENTRY,    ULL(0x0));
CONST_UINT8_T(SUBSTEP_ENABLE_PNOR_SLAVE_CHIP,    ULL(0x1));
CONST_UINT8_T(SUBSTEP_ENABLE_PNOR_MASTER_CHIP,   ULL(0x2));
CONST_UINT8_T(SUBSTEP_ENABLE_PNOR_CONFIG_I2C_E1, ULL(0x3));
CONST_UINT8_T(SUBSTEP_ENABLE_PNOR_INIT_PROC,     ULL(0x4));


#endif  // __PROC_SBE_ENABLE_PNOR_H
