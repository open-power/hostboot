/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_utils.H $           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
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
// $Id: p8_pm_utils.H,v 1.1 2014/02/06 20:05:37 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_utils.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
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
