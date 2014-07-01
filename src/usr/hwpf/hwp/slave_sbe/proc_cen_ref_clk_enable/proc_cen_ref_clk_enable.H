/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_cen_ref_clk_enable/proc_cen_ref_clk_enable.H $ */
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
// $Id: proc_cen_ref_clk_enable.H,v 1.1 2013/08/12 18:19:30 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_cen_ref_clk_enable.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_cen_ref_clk_enable.H
// *! DESCRIPTION : Enable Centaur reference clocks (FAPI)
// *!
// *! OWNER NAME  : Benedikt Geukes            Email: benedikt.geukes@de.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_CEN_REF_CLK_ENABLE_H_
#define _PROC_CEN_REF_CLK_ENABLE_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi.H>
#include "p8_scom_addresses.H"

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*proc_cen_ref_clk_enable_FP_t)(const fapi::Target &,
                                                         const uint8_t);


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

const uint8_t NUM_CENTAUR_POS = 8;
const uint8_t FSI_GP8_CENTAUR_REFCLOCK_START_BIT = 16;
const uint8_t FSI_GP8_CENTAUR_REFCLOCK_END_BIT = (FSI_GP8_CENTAUR_REFCLOCK_START_BIT + NUM_CENTAUR_POS - 1);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------


extern "C"
{

/**
 * @brief Enble Centaur reference clocks
 *
 * @param[in] i_target            chip target
 * @param[in] i_attached_centaurs Bitmask representing attached Centaur positions
 *
 * @return ReturnCode
 */
  fapi::ReturnCode proc_cen_ref_clk_enable(const fapi::Target & i_target,
                                           const uint8_t i_attached_centaurs);

} // extern "C"

#endif // _PROC_CEN_REF_CLK_ENABLE_H
