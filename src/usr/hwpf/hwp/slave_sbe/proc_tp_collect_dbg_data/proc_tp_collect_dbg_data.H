/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_tp_collect_dbg_data/proc_tp_collect_dbg_data.H $ */
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
// $Id: proc_tp_collect_dbg_data.H,v 1.3 2014/03/10 16:09:15 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_tp_collect_dbg_data.H,v $
///------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : proc_tp_collect_dbg_data.C
// *! DESCRIPTION : Header file for procedure to collect TP debug data
// *!
// *! OWNER NAME : Benedikt Geukes        Email: bgeukes@de.ibm.com
// *!
// *! ADDITIONAL COMMENTS :
// *!
//------------------------------------------------------------------------------

#ifndef PROC_TP_COLLECT_DBG_DATA_H_
#define PROC_TP_COLLECT_DBG_DATA_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>
#include <p8_scom_addresses.H>
#include <common_scom_addresses.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode
(*proc_tp_collect_dbg_data_FP_t)(const fapi::Target &, fapi::ReturnCode &);

extern "C" {

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

/**
 * @brief HWP to collect TP debug data for fails during various IPL steps 
 *        
 *
 * @param[in]  i_target Reference to processor chip target
 * @param[out] o_rc     Reference to return code (for appending of FFDC)
 *
 * @return ReturnCode
 */
fapi::ReturnCode proc_tp_collect_dbg_data(const fapi::Target & i_target, fapi::ReturnCode & o_rc);


} // extern "C"

#endif // PROC_TP_COLLECT_DBG_DATA_H_
