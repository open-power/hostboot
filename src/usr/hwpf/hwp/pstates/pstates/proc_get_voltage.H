/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/pstates/pstates/proc_get_voltage.H $         */
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
// $Id: proc_get_voltage.H,v 1.4 2013/12/04 18:54:50 jimyac Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_get_voltage.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
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
