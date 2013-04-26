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
// $Id: p8_pm_init.C,v 1.18 2013/04/16 12:00:34 pchatnah Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_init.C,v $  
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

extern "C" {

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
  fapi::ReturnCode p8_pm_list(const Target& i_target, const Target& i_target2, uint32_t mode);

// ----------------------------------------------------------------------
// p8_pm_init 
// ----------------------------------------------------------------------

fapi::ReturnCode
p8_pm_init(const fapi::Target &i_target1 ,const fapi::Target &i_target2 , uint32_t mode)
{

    fapi::ReturnCode l_fapi_rc;
    
    FAPI_INF("Executing p8_pm_init in mode %x ....\n", mode);

    /// -------------------------------
    /// Configuration/Initialation
    if (mode == PM_CONFIG || mode == PM_INIT || mode == PM_RESET) 
    {       
        l_fapi_rc = p8_pm_list(i_target1, i_target2, mode);
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
p8_pm_list(const Target& i_target, const Target& i_target2, uint32_t mode)
{

    fapi::ReturnCode l_fapi_rc;
        uint64_t            SP_WKUP_REG_ADDRS;
    uint8_t                        l_functional = 0;
    uint8_t                        l_ex_number = 0;
    ecmdDataBufferBase  data(64);

    std::vector<fapi::Target>      l_exChiplets;   


    //  ******************************************************************
    //  PCBS_PM 
    //  ******************************************************************  
  
    FAPI_INF("Executing: p8_pcbs_init.C in mode %x", mode);  

    if ( i_target.getType() != TARGET_TYPE_NONE )
      {  
	FAPI_EXEC_HWP(l_fapi_rc, p8_pcbs_init, i_target, mode);
	if (l_fapi_rc) 
	  { 
        FAPI_ERR("ERROR: p8_pm_init detected failed PCBS_PM result"); 
        return l_fapi_rc;
	  }    
      }


    if ( i_target2.getType() != TARGET_TYPE_NONE )
      {
	FAPI_EXEC_HWP(l_fapi_rc, p8_pcbs_init, i_target2, mode);
	if (l_fapi_rc) 
	  { 
	    FAPI_ERR("ERROR: p8_pm_init detected failed PCBS_PM result"); 
	    return l_fapi_rc;
	  }    
      }
    //  ******************************************************************
    //  PMC 
    //  ******************************************************************  
   
    FAPI_INF("Executing: p8_pmc_init in mode %x", mode);   

    FAPI_EXEC_HWP(l_fapi_rc, p8_pmc_init, i_target, i_target2, mode);
    if (l_fapi_rc) 
    { 
        FAPI_ERR("ERROR: p8_pm_init detected failed PMC result");
        return l_fapi_rc;
    }
    
    //  ******************************************************************
    //  PORE Sleep/Winkle engine 
    //  ******************************************************************  

    FAPI_INF("Executing: p8_poreslw_init in mode %x", mode); 
    if ( i_target.getType() != TARGET_TYPE_NONE )
      {    
	FAPI_EXEC_HWP(l_fapi_rc, p8_poreslw_init, i_target, mode);
	if (l_fapi_rc) 
	  { 
	    FAPI_ERR("ERROR: p8_pm_init detected failed PORE SLW result");
	    return l_fapi_rc;
	  }
      }

    if ( i_target2.getType() != TARGET_TYPE_NONE )
      {
	FAPI_EXEC_HWP(l_fapi_rc, p8_poreslw_init, i_target2, mode);
	if (l_fapi_rc) 
	  { 
	    FAPI_ERR("ERROR: p8_pm_init detected failed PORE SLW result");
	    return l_fapi_rc;
	  }
      }
    //  ******************************************************************
    //  PORE General Purpose Engines
    //  ******************************************************************  

    FAPI_INF("Executing: p8_poregpe_init in mode %x", mode);
       
    if ( i_target.getType() != TARGET_TYPE_NONE )
      {
	FAPI_EXEC_HWP(l_fapi_rc, p8_poregpe_init, i_target, mode , GPEALL);
	if (l_fapi_rc) 
	  { 
	    FAPI_ERR("ERROR: p8_pm_init detected failed PORE GPE result");
	    return l_fapi_rc;
	  }
	
      }

    if ( i_target2.getType() != TARGET_TYPE_NONE )
      {
	FAPI_EXEC_HWP(l_fapi_rc, p8_poregpe_init, i_target2, mode , GPEALL);
	if (l_fapi_rc) 
	  { 
	    FAPI_ERR("ERROR: p8_pm_init detected failed PORE GPE result");
	    return l_fapi_rc;
	  }
    
      }
    //  ******************************************************************
    //  OHA
    //  ******************************************************************  

    FAPI_INF("Executing: p8_oha_init in mode %x", mode);

    if ( i_target.getType() != TARGET_TYPE_NONE )
      {     
	FAPI_EXEC_HWP(l_fapi_rc, p8_oha_init, i_target, mode);
	if (l_fapi_rc) 
	  { 
	    FAPI_ERR("ERROR: p8_pm_init detected failed OHA result");
	    return l_fapi_rc;
	  }
      }

    if ( i_target2.getType() != TARGET_TYPE_NONE )
      {
	FAPI_EXEC_HWP(l_fapi_rc, p8_oha_init, i_target2, mode);
	if (l_fapi_rc) 
	  { 
	    FAPI_ERR("ERROR: p8_pm_init detected failed OHA result");
	    return l_fapi_rc;
	  }
      }
    
    //  ******************************************************************
    //  OCC-SRAM 
    //  ******************************************************************  
  

    FAPI_INF("Executing: p8_occ_sram_init in mode %x", mode);
    
    if ( i_target.getType() != TARGET_TYPE_NONE )
      {
	FAPI_EXEC_HWP(l_fapi_rc, p8_occ_sram_init, i_target, mode );
	if (l_fapi_rc) 
	  { 
	    FAPI_ERR("ERROR: p8_pm_init detected failed OCC-SRAM result");
	    return l_fapi_rc;
	  }
      }

    if ( i_target2.getType() != TARGET_TYPE_NONE )
      {
	FAPI_EXEC_HWP(l_fapi_rc, p8_occ_sram_init, i_target2, mode );
	if (l_fapi_rc) 
	  { 
	    FAPI_ERR("ERROR: p8_pm_init detected failed OCC-SRAM result");
	    return l_fapi_rc;
	  }
      }
    
    //  ******************************************************************
    //  OCB 
    //  ******************************************************************  

    FAPI_INF("Executing: p8_ocb_init in mode %x", mode);   
    if ( i_target.getType() != TARGET_TYPE_NONE )
      {
   
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

      }

    if ( i_target2.getType() != TARGET_TYPE_NONE )
      {


	FAPI_EXEC_HWP(l_fapi_rc, p8_ocb_init, i_target2, mode,OCB_CHAN0,OCB_TYPE_NULL, 0x10000000, 1 , OCB_Q_OUFLOW_EN , OCB_Q_ITPTYPE_NOTFULL   );
	if (l_fapi_rc) 
	  { 
	    FAPI_ERR("ERROR: p8_pm_init detected failed OCB result on channel 0");
	    return l_fapi_rc;
	  }
       
	FAPI_EXEC_HWP(l_fapi_rc, p8_ocb_init, i_target2, mode,OCB_CHAN1,OCB_TYPE_NULL, 0x10000000, 1 , OCB_Q_OUFLOW_EN , OCB_Q_ITPTYPE_NOTFULL   );
	if (l_fapi_rc) 
	  { 
	    FAPI_ERR("ERROR: p8_pm_init detected failed OCB result on channel 1");
	    return l_fapi_rc;
	  }
    
	FAPI_EXEC_HWP(l_fapi_rc, p8_ocb_init, i_target2, mode,OCB_CHAN2,OCB_TYPE_NULL, 0x10000000, 1 , OCB_Q_OUFLOW_EN , OCB_Q_ITPTYPE_NOTFULL   );
	if (l_fapi_rc) 
	  { 
	    FAPI_ERR("ERROR: p8_pm_init detected failed OCB result on channel 2");
	    return l_fapi_rc;
	  }
    
	FAPI_EXEC_HWP(l_fapi_rc, p8_ocb_init, i_target2, mode,OCB_CHAN3,OCB_TYPE_NULL, 0x10000000, 1 , OCB_Q_OUFLOW_EN , OCB_Q_ITPTYPE_NOTFULL   );
	if (l_fapi_rc) 
	  { 
	    FAPI_ERR("ERROR: p8_pm_init detected failed OCB result on channel 0");
	    return l_fapi_rc;
	  }

      }

 
    //  ******************************************************************
    //  PSS 
    //  ******************************************************************  
   
    FAPI_INF("Executing:p8_pss_init in mode %x", mode);

    if ( i_target.getType() != TARGET_TYPE_NONE )
      {
    
	FAPI_EXEC_HWP(l_fapi_rc, p8_pss_init, i_target, mode );
	if (l_fapi_rc) 
	  { 
	    FAPI_ERR("ERROR: p8_pm_init detected failed PSS result");
	    return l_fapi_rc;
	  }
      }

    if ( i_target2.getType() != TARGET_TYPE_NONE )
      {
	FAPI_EXEC_HWP(l_fapi_rc, p8_pss_init, i_target2, mode );
	if (l_fapi_rc) 
	  { 
	    FAPI_ERR("ERROR: p8_pm_init detected failed PSS result");
	    return l_fapi_rc;
	  }
      }

    //  ******************************************************************
    //  PBA 
    //  ******************************************************************  
    
    FAPI_INF("Executing: p8_pba_init  in mode %x", mode);
    if ( i_target.getType() != TARGET_TYPE_NONE )
      {         
	FAPI_EXEC_HWP(l_fapi_rc, p8_pba_init, i_target, mode );
	if (l_fapi_rc) 
	  { 
	    FAPI_ERR("ERROR: p8_pm_init detected failed PBA result");
	    return l_fapi_rc;
	  }
      }
    
    if ( i_target2.getType() != TARGET_TYPE_NONE )
      {
	FAPI_EXEC_HWP(l_fapi_rc, p8_pba_init, i_target2, mode );
	if (l_fapi_rc) 
	  { 
	    FAPI_ERR("ERROR: p8_pm_init detected failed PBA result");
	    return l_fapi_rc;
	  }
      }




 

    // loop over all the core chiplets

    if (mode == PM_INIT)
      {
	


    //  ******************************************************************
    //  FIRINIT
    //  ******************************************************************  
    

    FAPI_INF("Executing:p8_pm_firinit in mode %x", mode);

    if ( i_target.getType() != TARGET_TYPE_NONE )
      {
    
	FAPI_EXEC_HWP(l_fapi_rc, p8_pm_firinit, i_target , mode );
	if (l_fapi_rc) 
	  { 
	    FAPI_ERR("ERROR: p8_pm_firinit detected failed  result");
	    return l_fapi_rc;
	  }
      }

    if ( i_target2.getType() != TARGET_TYPE_NONE )
      {

	FAPI_EXEC_HWP(l_fapi_rc, p8_pm_firinit, i_target2 , mode );
	if (l_fapi_rc) 
	  { 
	    FAPI_ERR("ERROR: p8_pm_firinit detected failed  result");
	    return l_fapi_rc;
	  }
      }


    //  ******************************************************************
    //  CPU_SPECIAL_WAKEUP switch off
    //  ******************************************************************  


    if ( i_target.getType() != TARGET_TYPE_NONE )
      {
	l_fapi_rc = fapiGetChildChiplets (  i_target, 
					    TARGET_TYPE_EX_CHIPLET, 
					    l_exChiplets, 
					    TARGET_STATE_PRESENT);
	if (l_fapi_rc)
	  { 
	    FAPI_ERR("Error from fapiGetChildChiplets!");       
	    return l_fapi_rc;     
	  }
	
	FAPI_DBG("\tChiplet vector size  => %u ", l_exChiplets.size());
	
	// Iterate through the returned chiplets
	for (uint8_t j=0; j < l_exChiplets.size(); j++)
	  {
	    
	    // Determine if it's functional
	    l_fapi_rc = FAPI_ATTR_GET(  ATTR_FUNCTIONAL, 
					&l_exChiplets[j], 
					l_functional);
	    if (l_fapi_rc)
	      {
		FAPI_ERR("fapiGetAttribute of ATTR_FUNCTIONAL error"); 
		break;
	      }
	    
	    if ( l_functional )
	      {
	        // The ex is functional let's build the SCOM address 
	        l_fapi_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_exChiplets[j], l_ex_number);
	        FAPI_DBG("Running special wakeup on ex chiplet %d ", l_ex_number);
		
	        // Set special wakeup for EX
	        // Commented due to attribute errors 
		SP_WKUP_REG_ADDRS = PM_SPECIAL_WKUP_OCC_0x100F010C + (l_ex_number  * 0x01000000) ;
		l_fapi_rc=fapiGetScom(i_target, SP_WKUP_REG_ADDRS , data); if(l_fapi_rc) return l_fapi_rc;                                  
		FAPI_DBG("  Before clear of SPWKUP_REG PM_SPECIAL_WKUP_OCC_(0x%08llx) => =>0x%16llx",  SP_WKUP_REG_ADDRS, data.getDoubleWord(0));
		
		if (data.isBitSet(0))
		  {
		    //		    FAPI_EXEC_HWP(l_fapi_rc, p8_cpu_special_wakeup, l_exChiplets[j], SPCWKUP_DISABLE , HOST);
		      l_fapi_rc = fapiSpecialWakeup(l_exChiplets[j], false);
		    if (l_fapi_rc) { FAPI_ERR("p8_cpu_special_wakeup: Failed to put CORE into special wakeup. With rc = 0x%x", (uint32_t)l_fapi_rc);  return l_fapi_rc;    }    


		  }
	      }
	  }  // chiplet loop 

      }
    ///////////////////////////////////////////// SLAVE TARGET /////////////////////////////////////////////////


      if ( i_target2.getType() != TARGET_TYPE_NONE )
	{
	  l_fapi_rc = fapiGetChildChiplets (  i_target2, 
					      TARGET_TYPE_EX_CHIPLET, 
					      l_exChiplets, 
					      TARGET_STATE_PRESENT);
	  if (l_fapi_rc)
	    { 
	      FAPI_ERR("Error from fapiGetChildChiplets!");       
	      return l_fapi_rc;     
	    }
	
	  FAPI_DBG("\tChiplet vector size  => %u ", l_exChiplets.size());
	
	  // Iterate through the returned chiplets
	  for (uint8_t j=0; j < l_exChiplets.size(); j++)
	    {
	    
	      // Determine if it's functional
	      l_fapi_rc = FAPI_ATTR_GET(  ATTR_FUNCTIONAL, 
					  &l_exChiplets[j], 
					  l_functional);
	      if (l_fapi_rc)
		{
		  FAPI_ERR("fapiGetAttribute of ATTR_FUNCTIONAL error"); 
		  break;
		}
	    
	      if ( l_functional )
		{
		  // The ex is functional let's build the SCOM address 
		  l_fapi_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_exChiplets[j], l_ex_number);
		  FAPI_DBG("Running special wakeup on ex chiplet %d ", l_ex_number);
		
		  // Set special wakeup for EX
		  // Commented due to attribute errors 
		  SP_WKUP_REG_ADDRS = PM_SPECIAL_WKUP_OCC_0x100F010C + (l_ex_number  * 0x01000000) ;
		  l_fapi_rc=fapiGetScom(i_target2, SP_WKUP_REG_ADDRS , data); if(l_fapi_rc) return l_fapi_rc;                                  
		  FAPI_DBG("  Before clear of SPWKUP_REG PM_SPECIAL_WKUP_OCC_(0x%08llx) => =>0x%16llx",  SP_WKUP_REG_ADDRS, data.getDoubleWord(0));
		
		  if (data.isBitSet(0))
		    {
		      //		      FAPI_EXEC_HWP(l_fapi_rc, p8_cpu_special_wakeup, l_exChiplets[j], SPCWKUP_DISABLE , HOST);
		      l_fapi_rc = fapiSpecialWakeup(l_exChiplets[j], false);
		      if (l_fapi_rc) { FAPI_ERR("p8_cpu_special_wakeup: Failed to put CORE into special wakeup. With rc = 0x%x", (uint32_t)l_fapi_rc);  return l_fapi_rc;    }    


		    }
		}
	    }  // chiplet loop  
	}



       
	
      }
	return l_fapi_rc;
  
}


  //#ifdef FAPIECMD
} //end extern C
//#endif 
