/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_cen_ref_clk_enable/proc_check_master_sbe_seeprom.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
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
// $Id: proc_check_master_sbe_seeprom.H,v 1.1 2013/09/23 22:04:00 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_check_master_sbe_seeprom.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : proc_check_master_sbe_seeprom.H
// *! DESCRIPTION : Determine if given chip is the drawer master (FAPI)
// *!
// *! OWNER NAME  : Joe McGill        Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef PROC_CHECK_MASTER_SBE_SEEPROM_H_
#define PROC_CHECK_MASTER_SBE_SEEPROM_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// SBE Vital register bit/field definitions
const uint32_t MBOX_SBEVITAL_SBE_SELECT_MODE_MASTER_BIT = 10;

// Device ID register bit/field definitions
const uint32_t PCBMS_DEVICE_ID_CHIP_ID_START_BIT = 36;
const uint32_t PCBMS_DEVICE_ID_CHIP_ID_END_BIT = 39;

const uint32_t PCBMS_DEVICE_ID_PRIMARY_MASTER = 0x00;
const uint32_t PCBMS_DEVICE_ID_ALTERNATE_MASTER = 0x02;


//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode
(*proc_check_master_sbe_seeprom_FP_t)(const fapi::Target &,
                                      bool &);


extern "C" {

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

/**
 * @brief HWP which determines if a given chip is the drawer master
 *
 * @param[in]  i_target    Processor target
 * @param[out] o_is_master Master state
 *
 * @return ReturnCode
 */
fapi::ReturnCode proc_check_master_sbe_seeprom(
    const fapi::Target & i_target,
    bool & o_is_master);


} // extern "C"

#endif // PROC_CHECK_MASTER_SBE_SEEPROM_H_
