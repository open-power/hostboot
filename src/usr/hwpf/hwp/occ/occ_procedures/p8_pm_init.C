/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_init.C $            */
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
// $Id: p8_pm_init.C,v 1.8 2012/10/10 14:33:49 pchatnah Exp $
// $Source: /afs/awd.austin.ibm.com/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_init.C,v $  
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Ralf Maier         Email: ralf.maier@de.ibm.com
// *!
/// \file p8_pm_init.C
/// \brief Calls each PM unit initialization procedures with the control 
///         parameter to process the respective phase:
///             config: use Platform Attributes to create an effective 
///                     configuration using relevant Feature Attributes
///             init:   use the Feature attributes to initialize the hardware
///             reset:  call the "p8_pm_prep_reset" procedure to invoke a 
///                     reset of the hardware to allow for reinitialization
// *!
// *! Procedure Prereq:
// *!   o System clocks are running
// *!
//------------------------------------------------------------------------------
///
/// \version -------------------------------------------------------------------
/// \version 1.0 stillgs 2012/03/06 Initial Version 
/// \version -------------------------------------------------------------------
///
///
/// \todo   Review
///
///
/// High-level procedure flow:
///
/// \verbatim
///     - call p8_pcbs_init.C *chiptarget, mode (PM_CONFIG, PM_INIT, PM_RESET)
///     - evaluate RC
///
///     - call p8_pmc_init.C *chiptarget, mode (PM_CONFIG, PM_INIT, PM_RESET)
///     - evaluate RC
///
///     - call p8_poreslw_init.C *chiptarget, mode (PM_CONFIG, PM_INIT, PM_RESET)
///     - evaluate RC
///
///     - call p8_poregpe_init.C *chiptarget, mode (PM_CONFIG, PM_INIT, PM_RESET)
///     - evaluate RC
///
///     - call p8_oha_init.C *chiptarget, mode (PM_CONFIG, PM_INIT, PM_RESET)
///     - evaluate RC
///
///     - call p8_pba_init.C *chiptarget, mode (PM_CONFIG, PM_INIT, PM_RESET)
///     - evaluate RC
///
///     - call p8_occ_sram_init.C *chiptarget,mode (PM_CONFIG, PM_INIT, PM_RESET)   
///     - evaluate RC
///
///     - call p8_ocb_init .C *chiptarget, mode (PM_CONFIG, PM_INIT, PM_RESET)
///     - evaluate RC
///
///     - call p8_pss_init .C *chiptarget, mode (PM_CONFIG, PM_INIT, PM_RESET)
///     - evaluate RC
///
///  \endverbatim
///
// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------

#include "p8_pm.H"
#include "p8_pm_init.H"

//#ifdef FAPIECMD
extern "C" {
  //#endif 


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
  fapi::ReturnCode p8_pm_list(const Target& i_target, uint32_t mode);

// ----------------------------------------------------------------------
// p8_pm_init 
// ----------------------------------------------------------------------

fapi::ReturnCode
p8_pm_init(const fapi::Target &i_target, uint32_t mode)
{

    fapi::ReturnCode l_fapi_rc;
 

    //  ******************************************************************

    FAPI_INF("Executing p8_pm_init in mode %x ....\n", mode);

    /// -------------------------------
    /// Configuration/Initialation
    if (mode == PM_CONFIG || mode == PM_INIT || mode == PM_RESET) 
    {
        
      l_fapi_rc = p8_pm_list(i_target, mode);
	if (l_fapi_rc) 
	  { 
	    FAPI_ERR("ERROR: p8_pm_list detected failed "); 
	    return l_fapi_rc;
	  }    



    }
    /// -------------------------------
    /// Unsupported Mode
    else 
    {

      FAPI_ERR("Unknown mode passed to p8_pm_init. Mode %x ....\n", mode);
      uint32_t & MODE = mode;
      FAPI_SET_HWP_ERROR(l_fapi_rc, RC_PROCPM_PMC_CODE_BAD_MODE); // proc_pmc_errors.xml

    }


    return l_fapi_rc;
}


// ----------------------------------------------------------------------
// p8_pm_list - process the underlying routines in the prescribed order 
// ----------------------------------------------------------------------

fapi::ReturnCode
p8_pm_list(const Target& i_target, uint32_t mode)
{

    fapi::ReturnCode l_fapi_rc;

    //  ******************************************************************
    //  PCBS_PM 
    //  ******************************************************************  
   

    FAPI_INF("Executing: p8_pcbs_init.C in mode %x", mode);    
    FAPI_EXEC_HWP(l_fapi_rc, p8_pcbs_init, i_target, mode);
    if (l_fapi_rc) 
    { 
        FAPI_ERR("ERROR: p8_pm_init detected failed PCBS_PM result"); 
        return l_fapi_rc;
    }    
  


    //  ******************************************************************
    //  PMC 
    //  ******************************************************************  
   

    FAPI_INF("Executing: p8_pmc_init in mode %x", mode);   

    FAPI_EXEC_HWP(l_fapi_rc, p8_pmc_init, i_target, mode);
    if (l_fapi_rc) 
    { 
        FAPI_ERR("ERROR: p8_pm_init detected failed PMC result");
        return l_fapi_rc;
    }
    
    //  ******************************************************************
    //  PORE Sleep/Winkle engine 
    //  ******************************************************************  

    FAPI_INF("Executing: p8_poreslw_init in mode %x", mode); 
    
    FAPI_EXEC_HWP(l_fapi_rc, p8_poreslw_init, i_target, mode);
    if (l_fapi_rc) 
    { 
        FAPI_ERR("ERROR: p8_pm_init detected failed PORE SLW result");
        return l_fapi_rc;
    }
    
    //  ******************************************************************
    //  PORE General Purpose Engines
    //  ******************************************************************  

    FAPI_INF("Executing: p8_poregpe_init in mode %x", mode);
       
    FAPI_EXEC_HWP(l_fapi_rc, p8_poregpe_init, i_target, mode , GPEALL);
    if (l_fapi_rc) 
    { 
        FAPI_ERR("ERROR: p8_pm_init detected failed PORE GPE result");
        return l_fapi_rc;
    }
    
    //  ******************************************************************
    //  OHA
    //  ******************************************************************  

    FAPI_INF("Executing: p8_oha_init in mode %x", mode);
     
    FAPI_EXEC_HWP(l_fapi_rc, p8_oha_init, i_target, PM_CONFIG );
    if (l_fapi_rc) 
    { 
        FAPI_ERR("ERROR: p8_pm_init detected failed OHA result");
        return l_fapi_rc;
    }
    

    //  ******************************************************************
    //  OCC-SRAM 
    //  ******************************************************************  
  

    FAPI_INF("Executing: p8_occ_sram_init in mode %x", mode);
    
    FAPI_EXEC_HWP(l_fapi_rc, p8_occ_sram_init, i_target, mode );
    if (l_fapi_rc) 
    { 
        FAPI_ERR("ERROR: p8_pm_init detected failed OCC-SRAM result");
        return l_fapi_rc;
    }
    
    //  ******************************************************************
    //  OCB 
    //  ******************************************************************  

    FAPI_INF("Executing: p8_ocb_init in mode %x", mode);   
   
    FAPI_EXEC_HWP(l_fapi_rc, p8_ocb_init, i_target, mode,OCB_CHAN0,OCB_TYPE_NULL, 0x10000000, 1 , OCB_Q_OUFLOW_EN , OCB_Q_ITPTYPE_NOTFULL   );
    if (l_fapi_rc) 
    { 
        FAPI_ERR("ERROR: p8_pm_init detected failed OCB result on channel 0");
        return l_fapi_rc;
    }
       
    FAPI_EXEC_HWP(l_fapi_rc, p8_ocb_init, i_target, mode,OCB_CHAN1,OCB_TYPE_NULL, 0x10000000, 1 , OCB_Q_OUFLOW_EN , OCB_Q_ITPTYPE_NOTFULL   );
    if (l_fapi_rc) 
    { 
        FAPI_ERR("ERROR: p8_pm_init detected failed OCB result on channel 1");
        return l_fapi_rc;
    }
    
    FAPI_EXEC_HWP(l_fapi_rc, p8_ocb_init, i_target, mode,OCB_CHAN2,OCB_TYPE_NULL, 0x10000000, 1 , OCB_Q_OUFLOW_EN , OCB_Q_ITPTYPE_NOTFULL   );
    if (l_fapi_rc) 
    { 
        FAPI_ERR("ERROR: p8_pm_init detected failed OCB result on channel 2");
        return l_fapi_rc;
    }
    
    FAPI_EXEC_HWP(l_fapi_rc, p8_ocb_init, i_target, mode,OCB_CHAN3,OCB_TYPE_NULL, 0x10000000, 1 , OCB_Q_OUFLOW_EN , OCB_Q_ITPTYPE_NOTFULL   );
    if (l_fapi_rc) 
    { 
        FAPI_ERR("ERROR: p8_pm_init detected failed OCB result on channel 0");
        return l_fapi_rc;
    }
 
    //  ******************************************************************
    //  PSS 
    //  ******************************************************************  
    

    FAPI_INF("Executing:p8_pss_init in mode %x", mode);
    
    FAPI_EXEC_HWP(l_fapi_rc, p8_pss_init, i_target, mode );
    if (l_fapi_rc) 
    { 
        FAPI_ERR("ERROR: p8_pm_init detected failed PSS result");
        return l_fapi_rc;
    }




    //  ******************************************************************
    //  PBA 
    //  ******************************************************************  
    

    FAPI_INF("Executing: p8_pba_init  in mode %x", mode);
         
    FAPI_EXEC_HWP(l_fapi_rc, p8_pba_init, i_target, mode );
    if (l_fapi_rc) 
    { 
        FAPI_ERR("ERROR: p8_pm_init detected failed PBA result");
        return l_fapi_rc;
    }
    
    return l_fapi_rc;
  
} 


  //#ifdef FAPIECMD
} //end extern C
//#endif 
