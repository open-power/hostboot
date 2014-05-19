/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_oha_firinit.C $     */
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
// $Id: p8_pm_oha_firinit.C,v 1.13 2013/09/25 22:35:00 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_oha_firinit.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Pradeep CN         Email: pradeepcn@in.ibm.com
// *!
// *! General Description: Configures the FIR errors
// *!        
// *!   The purpose of this procedure is to ......
// *!   
// *!   High-level procedure flow:
// *!     o Set the particluar bits of databuffers action0 , action 1 and mask for the correspoding actions via MACROS
// *!     o Write the action1 , actionn0 and mask registers of FIRs
// *!     o 
// *!     o 
// *!     o 
// *!     o 
// *!
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
fapi::ReturnCode
p8_pm_oha_firinit(const fapi::Target &i_target , uint32_t mode )
{
    fapi::ReturnCode                rc;
    //    fapi::TargetState               l_state = TARGET_STATE_FUNCTIONAL; 
    ecmdDataBufferBase              mask(64);
    uint32_t                        e_rc = 0;
        
    std::vector<fapi::Target>       l_chiplets;
    std::vector<Target>::iterator   itr;    


    

    FAPI_INF("Executing proc_pm_oha_firinit  ...");
    
    do
    {

       //#--  OHA_ERROR_AND_ERROR_MASK_REG:     0..1     WREG=0x0E OHA error and error mask register 
       //#--  tpc_oha1_mac_inst.error_mask      0..5     SCOM    
       //#--  0..5    RW      oha_error_mask  Error mask for OHA/DPLL error reporting registers

       if (mode == PM_RESET)
       {                                
            rc = fapiGetChildChiplets ( i_target, 
                                        TARGET_TYPE_EX_CHIPLET, 
                                        l_chiplets, 
                                        TARGET_STATE_FUNCTIONAL); 
            if (rc) 
            {
                FAPI_ERR("fapiGetChildChiplets failed."); 
                break;
            }
            
            FAPI_DBG("  chiplet vector size          => %u", l_chiplets.size());
            
            e_rc  = mask.flushTo0();
            e_rc |= mask.setBit(0,OHA_FIR_REGISTER_LENGTH);
            if (e_rc)
            {
                rc.setEcmdError(e_rc);
                break;
            }          

            for (itr = l_chiplets.begin(); itr != l_chiplets.end(); itr++)
            {
                rc = fapiPutScom((*itr), EX_OHA_ERROR_ERROR_MASK_REG_RWx1002000E, mask );
                if (rc) 
                {
                    FAPI_ERR("fapiPutScom(EX_OHA_ERROR_ERROR_MASK_REG_RWx1002000E) failed."); 
                    break;
                }
            }
            // Exit if error detected
            if (!rc.ok())
            {
                break;
            }
       }
       else 
       {
            e_rc = mask.flushTo0(); 

            SET_FIR_MASKED(OHA21_PPT_TIMEOUT_ERR); //  OHA21_PPT_TIMEOUT_ERR            
            SET_FIR_MASKED(NOT_CPM_BIT_SYNCED   ); //  NOT_CPM_BIT_SYNCED               
            SET_FIR_MASKED(AISS_HANG_CONDITION  ); //  AISS_HANG_CONDITION              
            SET_FIR_MASKED(TC_TC_THERM_TRIP0    ); //  TC_TC_THERM_TRIP0                
            SET_FIR_MASKED(TC_TC_THERM_TRIP1    ); //  TC_TC_THERM_TRIP1                
            SET_FIR_MASKED(PCB_ERR_TO_FIR       ); //  PCB_ERR_TO_FIR                   
    
            if (e_rc)
            {
                rc.setEcmdError(e_rc);
                break;
            }

            //    #--***********************************************************
            //    #-- Mask  EX_OHA_ERROR_ERROR_MASK_REG_RWx1002000E
            //    #--***********************************************************
            
            rc = fapiGetChildChiplets(   i_target,
                                         fapi::TARGET_TYPE_EX_CHIPLET,
                                         l_chiplets,
                                         TARGET_STATE_FUNCTIONAL);
            if (rc) 
            {
	            FAPI_ERR("fapiGetChildChiplets failed."); 
                break;
	        }
           
            FAPI_DBG("  chiplet vector size          => %u", l_chiplets.size());

            for (itr = l_chiplets.begin(); itr != l_chiplets.end(); itr++)
            {                

                rc = fapiPutScom( (*itr), 
                                  EX_OHA_ERROR_ERROR_MASK_REG_RWx1002000E, 
                                  mask );
                if (rc)
                {
                     FAPI_ERR("fapiPutScom(EX_OHA_ERROR_ERROR_MASK_REG_RWx1002000E) failed.");
                     break;
                }              
            } // Chiplet loop
            
            // Exit if error detected
            if (!rc.ok())
            {
                break;
            }
        } // Mode
        
    } while(0);

    return rc;

} // Procedure

} //end extern C
