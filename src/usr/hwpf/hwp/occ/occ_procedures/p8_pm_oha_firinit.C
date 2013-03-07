/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_oha_firinit.C $     */
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
// $Id: p8_pm_oha_firinit.C,v 1.4 2012/09/16 05:10:14 pchatnah Exp $
// $Source: /afs/awd.austin.ibm.com/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_oha_firinit.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Joe Procwriter         Email: asmartpersion@xx.ibm.com
// *!
// *! General Description: Configures the FIR errors
// *!        
// *!   The purpose of this procedure is to ......
// *!   
// *!   High-level procedure flow:
// *!     o Do thing 1
// *!     o Do thing 2
// *!     o Do thing 3
// *!     o Check if all went well
// *!     o   If so celebrate 
// *!     o   Else write logs, set bad return code
// *!
// *! Procedure Prereq:
// *!   o System clocks are running
// *!
//------------------------------------------------------------------------------



// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <fapi.H>
#include "p8_scom_addresses.H"
#include "p8_pm_oha_firinit.H"
#include "p8_pm_firinit.H"


extern "C" {

using namespace fapi;

// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------
// #define SET_CHECK_STOP(b){SET_FIR_ACTION(b, 0, 0);}
// #define SET_RECOV_ATTN(b){SET_FIR_ACTION(b, 0, 1);}
// #define SET_RECOV_INTR(b){SET_FIR_ACTION(b, 1, 0);}
// #define SET_MALF_ALERT(b){SET_FIR_ACTION(b, 1, 1);}
// #define SET_FIR_MASKED(b){SET_FIR_MASK(b,1);}


// ----------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------





// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------




// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------


// function: xxx
// parameters: none
// returns: ECMD_SUCCESS if something good happens,
//          BAD_RETURN_CODE otherwise
ReturnCode
p8_pm_oha_firinit(const fapi::Target &i_target  )
{
    ReturnCode rc;
 //    ecmdDataBufferBase  action_0(64);
//     ecmdDataBufferBase  action_1(64);
    ecmdDataBufferBase  mask(64);
    uint32_t            e_rc = 0;
    
    std::vector<fapi::Target>      l_chiplets;
    std::vector<Target>::iterator  itr;
    
    
    //    FAPI_INF("");
    FAPI_INF("Executing proc_pm_oha_firinit  ....\n");



//#--OHA_ERROR_AND_ERROR_MASK_REG:0..1               WREG=0x0E       OHA error and error mask register 
//#--        tpc_oha1_mac_inst.error_mask    0..5    SCOM    
//#--        0..5    RW      oha_error_mask  Error mask for OHA/DPLL error reporting registers


    


 
    e_rc |= mask.flushTo0(); 


    SET_FIR_MASKED(0);    //        oha21_ppt_timeout_err            
    SET_FIR_MASKED(1);	  //        NOT CPM_bit_synced               
    SET_FIR_MASKED(2);	  //        aiss_hang_condition              
    SET_FIR_MASKED(3);	  //        tc_tc_therm_trip0                
    SET_FIR_MASKED(4);	  //        tc_tc_therm_trip1                
    SET_FIR_MASKED(5);	  //        pcb_err_to_fir                   
 
    if (e_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)e_rc);  rc.setEcmdError(e_rc); return rc;    }
    

    
//    #--******************************************************************************
//    #-- Mask  EX_OHA_ERROR_ERROR_MASK_REG_RWx1002000E
//    #--******************************************************************************

 rc = fapiGetChildChiplets (i_target, TARGET_TYPE_EX_CHIPLET, l_chiplets, TARGET_STATE_FUNCTIONAL); if (rc) return rc;
 FAPI_DBG("  chiplet vector size          => %u", l_chiplets.size());

  for (itr = l_chiplets.begin(); itr != l_chiplets.end(); itr++){
  


    rc = fapiPutScom((*itr), EX_OHA_ERROR_ERROR_MASK_REG_RWx1002000E, mask );
    if (rc) {
      FAPI_ERR("fapiPutScom(EX_OHA_ERROR_ERROR_MASK_REG_RWx1002000E) failed."); return rc;
    }
    
    FAPI_INF("Done in current chiplet  ....\n");
    
  }





    return rc ;
    
 
} // Procedure


} //end extern C
 

