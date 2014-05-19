/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/utility_procedures/proc_cpu_special_wakeup.C $ */
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
// $Id: proc_cpu_special_wakeup.C,v 1.25 2012/10/09 11:04:29 pchatnah Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_cpu_special_wakeup.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Pradeep CN         Email: pradeepcn@in.ibm.com
// *!
/// \file p8_pm_init.C
/// \brief Calls each PM unit firinit procedrues to configure the FIRs to 
///         predefined types :
///             
///             
///             
///              
///             
// *!
// *! Procedure Prereq:
// *!   o System clocks are running
// *!
//------------------------------------------------------------------------------
///
/// \todo   Review
///
///
/// High-level procedure flow:
///
/// \verbatim
///     - call p8_pm_pmc_firinit.C *chiptarget 
///     - evaluate RC
///
///     - call p8_pm_pba_firinit.C *chiptarget 
///     - evaluate RC
///
///
///  \endverbatim
///
// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------


#include <fapi.H>
#include <p8_cpu_special_wakeup.H>



// #ifdef FAPIECMD
extern "C" {
  // #endif 


using namespace fapi;

// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------


// ---------------------------------------------------------------------- 
// Global variables
// ----------------------------------------------------------------------


// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------


// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------
/// \  input ex_target
// ----------------------------------------------------------------------
// p8_pm_init 
// ----------------------------------------------------------------------

fapi::ReturnCode
proc_cpu_special_wakeup(const fapi::Target &i_ex_target, PROC_SPCWKUP_OPS i_operation , PROC_SPCWKUP_ENTITY i_entity )
{

    fapi::ReturnCode l_fapi_rc;
 


    //  ******************************************************************
    //  PMC_FIRS 
    //  ******************************************************************  
   
    FAPI_DBG("");
    FAPI_EXEC_HWP(l_fapi_rc, p8_cpu_special_wakeup , i_ex_target, i_operation , i_entity );
    if (l_fapi_rc) 
    { 
        FAPI_ERR("ERROR: p8_cpu_special_wakeup detected failed result"); 
        return l_fapi_rc;
    }    
  


  
    return l_fapi_rc;
  
} 


  //#ifdef FAPIECMD
} //end extern C
//#endif 
