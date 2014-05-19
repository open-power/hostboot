/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_sbe_check_master.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: proc_sbe_check_master.H,v 1.3 2013/10/03 20:53:15 jeshua Exp $

/// Substep numbers for proc_sbe_check_master

#ifndef __PROC_SBE_CHECK_MASTER_H
#define __PROC_SBE_CHECK_MASTER_H

#include "fapi_sbe_common.H"
#include "sbe_vital.H"

CONST_UINT8_T(SUBSTEP_CHECK_MASTER_PROC_ENTRY,           ULL(0x0));
//NOTE: The slave chip substep value can never change, because HB checks for it
CONST_UINT8_T(SUBSTEP_CHECK_MASTER_SLAVE_CHIP,           ULL(0x1));
CONST_UINT8_T(SUBSTEP_CHECK_MASTER_MASTER_CHIP,          ULL(0x2));


#endif  // __PROC_SBE_CHECK_MASTER_H
