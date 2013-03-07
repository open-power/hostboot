/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_firinit.C $         */
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
/* begin_generated_IBM_copyright_prolog                            */
/*                                                                 */
/* This is an automatically generated copyright prolog.            */
/* After initializing,  DO NOT MODIFY OR MOVE                      */ 
/* --------------------------------------------------------------- */
/* IBM Confidential                                                */
/*                                                                 */
/* Licensed Internal Code Source Materials                         */
/*                                                                 */
/* (C)Copyright IBM Corp.  2014, 2014                              */
/*                                                                 */
/* The Source code for this program is not published  or otherwise */
/* divested of its trade secrets,  irrespective of what has been   */
/* deposited with the U.S. Copyright Office.                       */
/*  -------------------------------------------------------------- */
/*                                                                 */
/* end_generated_IBM_copyright_prolog                              */
// $Id: p8_pm_firinit.C,v 1.3 2012/09/11 10:31:30 pchatnah Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_firinit.C,v $
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
#include "p8_scom_addresses.H"
#include "p8_pm_firinit.H"
#include "p8_pm_pmc_firinit.H"
#include "p8_pm_pba_firinit.H"
#include "p8_pm_pcbs_firinit.H"
#include "p8_pm_oha_firinit.H"
#include "p8_pm_occ_firinit.H"




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
fapi::ReturnCode p8_pm_firinitlist(Target &i_target);

// ----------------------------------------------------------------------
// p8_pm_init 
// ----------------------------------------------------------------------

fapi::ReturnCode
p8_pm_firinit(const fapi::Target &i_target )
{

    fapi::ReturnCode l_rc;
 


    //  ******************************************************************
    //  PMC_FIRS 
    //  ******************************************************************  
   
    FAPI_DBG("");
    FAPI_EXEC_HWP(l_rc, p8_pm_pmc_firinit , i_target );
    if (l_rc) 
    { 
        FAPI_ERR("ERROR: p8_pm_pmc_firinit detected failed result"); 
        return l_rc;
    }    
  


    //  ******************************************************************
    //  PBA 
    //  ******************************************************************  
   
   
    FAPI_DBG("");
    FAPI_EXEC_HWP(l_rc, p8_pm_pba_firinit , i_target );
    if (l_rc) 
    { 
        FAPI_ERR("ERROR: p8_pm_pba_firinit detected failed result"); 
        return l_rc;
    }    
  

    //  ******************************************************************
    //  OHA 
    //  ******************************************************************  
   
   
    FAPI_DBG("");
    FAPI_EXEC_HWP(l_rc, p8_pm_oha_firinit , i_target );
    if (l_rc) 
    { 
        FAPI_ERR("ERROR: p8_pm_oha_firinit detected failed result"); 
        return l_rc;
    }    
  
    //  ******************************************************************
    //  PCBS
    //  ******************************************************************  
   
   
    FAPI_DBG("");
    FAPI_EXEC_HWP(l_rc, p8_pm_pcbs_firinit , i_target );
    if (l_rc) 
    { 
        FAPI_ERR("ERROR: p8_pm_pcbs_firinit detected failed result"); 
        return l_rc;
    }    


    //  ******************************************************************
    //  OCC
    //  ******************************************************************  
   
   
    FAPI_DBG("");
    FAPI_EXEC_HWP(l_rc,  p8_pm_occ_firinit , i_target );
    if (l_rc) 
    { 
        FAPI_ERR("ERROR: p8_pm_occ_firinit detected failed result"); 
        return l_rc;
    }    
  

  
    return l_rc;
  
} 


  //#ifdef FAPIECMD
} //end extern C
//#endif 
