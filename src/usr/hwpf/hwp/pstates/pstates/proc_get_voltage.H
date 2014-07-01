/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/pstates/pstates/proc_get_voltage.H $         */
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
// $Id: proc_get_voltage.H,v 1.4 2013/12/04 18:54:50 jimyac Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_get_voltage.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE       : proc_get_voltage.H
// *! DESCRIPTION : Get VDD & VCS Voltage for given Frequency (FAPI)
// *!
// *! OWNER NAME  : Jim Yacynych         Email: jimyac@us.ibm.com
// *! BACKUP NAME : 
// *!
// *! ADDITIONAL COMMENTS :
// *!
//------------------------------------------------------------------------------

#ifndef _proc_get_voltage_H_
#define _proc_get_voltage_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>
#include <p8_build_pstate_datablock.H>

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*proc_get_voltage_FP_t) (const fapi::Target&,
                                                   const uint32_t, 
                                                   uint8_t &, 
                                                   uint8_t &);

extern "C" {

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
/// \brief Build Pstate Tables
/// \param[in]     i_target            Chip Target
/// \param[in]     i_freq_mhz          frequency in Mhz 
/// \param[out]    o_vdd_vid           vdd value for given frequency  
/// \param[out]    o_vcs_vid           vcs value for given frequency 

fapi::ReturnCode proc_get_voltage(const fapi::Target& i_target, 
                                  const uint32_t i_freq_mhz, 
                                  uint8_t& o_vdd_vid, 
                                  uint8_t& o_vcs_vid);

} // extern "C"

#endif
