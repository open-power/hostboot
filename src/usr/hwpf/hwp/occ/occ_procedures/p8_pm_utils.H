/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_utils.H $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
// $Id: p8_pm_utils.H,v 1.1 2014/02/06 20:05:37 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_utils.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : p8_pm_utils.H
// *! DESCRIPTION : Utility functions for PM FAPIs
// *!
// *! OWNER NAME  : Greg Still    Email: stillgs@us.ibm.com
// *! BACKUP NAME : Michael Olsen Email: cmolsen@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _P8_PM_UTILS_H_
#define _P8_PM_UTILS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

extern "C" {


//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/**
 * Trace Global FIRs
 *
 * @param[in] i_target Chip target
 * @param[in] i_msg    String to put out in the trace
 *
 * @retval SCOM FAPI RCs
 */
fapi::ReturnCode
p8_pm_glob_fir_trace  (const fapi::Target& i_target,
                      const char * i_msg);
                 
//------------------------------------------------------------------------------
/**
 * Trace PCBS FSMs
 *
 * @param[in] i_target Chip target
 * @param[in] i_msg    String to put out in the trace
 *
 * @retval SCOM FAPI RCs
 */
fapi::ReturnCode
p8_pm_pcbs_fsm_trace_chip(const fapi::Target& i_target,           
                            const char *      i_msg);
                            
                            
//------------------------------------------------------------------------------
/**
 * Trace PCBS FSMs for a given EX
 *
 * @param[in] i_target Chip target
 * @param[in] i_msg    String to put out in the trace
 *
 * @retval ECMD_SUCCESS
 */
fapi::ReturnCode
p8_pm_pcbs_fsm_trace  ( const fapi::Target& i_target,
                        uint32_t            i_ex_number,           
                        const char *        i_msg);
                                                                                                            

} // extern "C"

#endif // _P8_PM_UTILS_H_
