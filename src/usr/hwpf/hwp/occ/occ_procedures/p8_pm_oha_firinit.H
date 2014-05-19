/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_oha_firinit.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: p8_pm_oha_firinit.H,v 1.6 2013/08/26 12:44:33 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_oha_firinit.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_pm_oha_firinit.H
// *! DESCRIPTION : SETS OHA firs to proper error settings
// *!
// *! OWNER NAME  : Greg Still    Email: stillgs@us.ibm.com
// *! BACKUP NAME : Pradeep CN    Email: padeepcn@in.ibm.com
// *!
//------------------------------------------------------------------------------
#include "p8_pm_firinit.H"


// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_pm_oha_firinit_FP_t) (const fapi::Target& , uint32_t mode );

const uint32_t        OHA_FIR_REGISTER_LENGTH = 6;
enum OHA_FIRS 
{    
    OHA21_PPT_TIMEOUT_ERR       = 0,
    NOT_CPM_BIT_SYNCED          = 1,
    AISS_HANG_CONDITION         = 2,
    TC_TC_THERM_TRIP0           = 3,
    TC_TC_THERM_TRIP1           = 4,
    PCB_ERR_TO_FIR              = 5    
};

extern "C" {


fapi::ReturnCode 
p8_pm_oha_firinit(const fapi::Target& i_target, uint32_t mode );

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// function: FAPI p8_pm_oha_firinit  HWP entry point
//           operates on chips passed in i_target argument to perform
//           desired settings of FIRS of OHA macro 
// parameters: i_target        => chip target

// returns: FAPI_RC_SUCCESS if all specified operations complete successfully,
//          else return code for failing operation
//------------------------------------------------------------------------------




} // extern "C"


