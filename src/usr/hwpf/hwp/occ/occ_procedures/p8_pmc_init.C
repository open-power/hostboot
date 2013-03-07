/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pmc_init.C $           */
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
// $Id: p8_pmc_init.C,v 1.6 2012/10/04 10:24:27 pchatnah Exp $
// $Source: /afs/awd.austin.ibm.com/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pmc_init.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Joe Procwriter         Email: asmartpersion@xx.ibm.com
// *!
// *! General Description:
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

#include "p8_pm.H"
#include "p8_pmc_init.H"

//----------------------------------------------------------------------    
//  eCMD Includes
//----------------------------------------------------------------------
// #include <ecmdClientCapi.H>
// #include <ecmdUtils.H>
// #include <ecmdSharedUtils.H>
// #include <iostream>
// #include <fapiUtil.H>
//#include <sim_utils.inc>
//#include "myscoms.H"          // Remove eventually


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <fapi.H>
#include <ecmdDataBufferBase.H>

//#ifdef FAPIECMD
extern "C" {
  //  #endif 
  


using namespace fapi;

//TODO RTC: 68461 - Refresh procedures to remove multiple definitions
//RTC 68461 CONST_UINT64_T( OCB_OCI_OIMR1_0x0006a014                    , ULL(0x0006a014) );
//RTC 68461 CONST_UINT64_T( OCB_OCI_OIMR0_0x0006a004                    , ULL(0x0006a004) );
  //NST_UINT64_T(  PMC_MODE_REG_0x00062000                    , ULL(0x00062000) );
//RTC 68461 CONST_UINT64_T( PMC_INTCHP_COMMAND_REG_0x00062014           , ULL(0x00062014) );
//RTC 68461 CONST_UINT64_T( PMC_INTCHP_STATUS_REG_0x00062013                    , ULL(0x00062013) );
  //CONST_UINT64_T( PMC_INTCHP_COMMAND_REG_0x00062014                   , ULL(0x00062014) );


// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------


// fapi::ReturnCode
// pmc_create_spivid_settings(const Target& l_pTarget) 
// {
//     fapi::ReturnCode rc;
    




//       return rc ;
// }   

//-------------------------------------------------------------------------
    /// Locally computed variables to put into the feature attributes   
//-------------------------------------------------------------------------       

fapi::ReturnCode
pmc_config_spivid_settings(const Target& l_pTarget) 
{
    fapi::ReturnCode rc;
    
    uint32_t attr_pm_spivid_clock_divider;
    uint32_t attr_pm_spivid_frequency = 10;
    uint32_t attr_proc_nest_frequency = 2400;

    FAPI_INF("entering the config function");
    
        rc = FAPI_ATTR_GET(ATTR_FREQ_PB, NULL, attr_proc_nest_frequency); if (rc) return rc;
        //TODO RTC: 68461 - refresh procedures - hacked target in the line below.
        rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_FREQUENCY, &l_pTarget, attr_pm_spivid_frequency); if (rc) return rc; 
    
    


    // calculation of clock divider
       attr_pm_spivid_clock_divider =  (attr_proc_nest_frequency/(attr_pm_spivid_frequency*8)-1 );   


         rc = FAPI_ATTR_SET(ATTR_PM_SPIVID_CLOCK_DIVIDER, &l_pTarget, attr_pm_spivid_clock_divider); if (rc) return rc;
    
        FAPI_INF("exiting the config function");
    return rc ;
}



fapi::ReturnCode
pmc_reset_function(const Target& i_target) 
{
    fapi::ReturnCode rc;
  ecmdDataBufferBase data(64);
  //  ecmdDataBufferBase mask(64);
  uint32_t e_rc = 0;
  uint32_t count = 0 ;	  
  bool is_stopped ;
  bool is_spivid_stopped ;
  bool is_not_ongoing ;
  bool enable_pstate_voltage_changes ;
  bool fw_pstate_mode = false;  ////TODO RTC: 68461 - refresh procedures, and to init variable.
  bool is_pstate_error_stopped ;
  bool is_intchp_error_stopped;
  bool is_MasterPMC;
  bool enable_fw_pstate_mode;


////////////////////////////////////////////////////////////////////////////
// 1. cRQ_TD_IntMaskRQ: Mask OCC interrupts in OIMR1
//    PMC_PSTATE_REQUEST, PMC_PROTOCOL_ONGOING, PMC_VOLTAGE_CHANGE_ONGOING,
//    PMC_INTERCHIP_MSG_SEND_ONGOING, PMC_IDLE_ENTER, PMC_IDLE_EXIT, PMC_SYNC
////////////////////////////////////////////////////////////////////////////

  FAPI_INF("Performing STEP 1");

    e_rc = data.flushTo0(); if(e_rc){rc.setEcmdError(e_rc); return rc;}

    rc = fapiGetScom(i_target, OCB_OCI_OIMR1_0x0006a014 , data );
    if (rc) {
         FAPI_ERR("fapiGetScom(OCB_OCI_OIMR1_0x0006a014) failed."); return rc;
    }


    e_rc = data.setBit(12);  if(e_rc){rc.setEcmdError(e_rc); return rc; }
    e_rc = data.setBit(13);  if(e_rc){rc.setEcmdError(e_rc); return rc; }
    e_rc = data.setBit(14);  if(e_rc){rc.setEcmdError(e_rc); return rc; }
    e_rc = data.setBit(15);  if(e_rc){rc.setEcmdError(e_rc); return rc; }
    e_rc = data.setBit(18);  if(e_rc){rc.setEcmdError(e_rc); return rc; }
    e_rc = data.setBit(20);  if(e_rc){rc.setEcmdError(e_rc); return rc; }
    e_rc = data.setBit(22);  if(e_rc){rc.setEcmdError(e_rc); return rc; }



    rc = fapiPutScom(i_target, OCB_OCI_OIMR1_0x0006a014 , data );
    if (rc) {
         FAPI_ERR("fapiPutScom(OCB_OCI_OIMR1_0x0006a014) failed."); return rc;
    }

////////////////////////////////////////////////////////////////////////////
// 2. cRQ_TD_IntMaskER: Mask OCC interrupts in OIMR0
//    PMC_ERROR, PMC_MALF_ALERT, PMC_INTERCHIP_MSG_RECVD
////////////////////////////////////////////////////////////////////////////



  FAPI_INF("Performing STEP 2");
    rc = fapiGetScom(i_target, OCB_OCI_OIMR0_0x0006a004 , data );
    if (rc) {
         FAPI_ERR("fapiGetScom(OCB_OCI_OIMR0_0x0006a004) failed."); return rc;
    }


    e_rc = data.setBit(9);  if(e_rc){rc.setEcmdError(e_rc); return rc; }
    e_rc = data.setBit(13);  if(e_rc){rc.setEcmdError(e_rc); return rc; }
    e_rc = data.setBit(21);  if(e_rc){rc.setEcmdError(e_rc); return rc; }



    rc = fapiPutScom(i_target, OCB_OCI_OIMR0_0x0006a004 , data );
    if (rc) {
         FAPI_ERR("fapiPutScom(OCB_OCI_OIMR0_0x0006a004) failed."); return rc;
    }


////////////////////////////////////////////////////////////////////////////
// 3. cRQ_TD_DisableMPS: Write PMC_MODE_REG to halt things  Which register bits should be written with what to make this below halts ? 
//    halt_pstate_master_fsm<-1          <-1 indicates to write the bit with the value 1
//    halt_idle_state_master_fsm<-1      <-1 indicates to write the bit with the value 1
//    Note: Other bits are left as setup so the configuration remains as things halt, and new
//          requests are queued (just now processed now).
////////////////////////////////////////////////////////////////////////////

  FAPI_INF("Performing STEP 3");
    rc = fapiGetScom(i_target, PMC_MODE_REG_0x00062000 , data );
    if (rc) {
         FAPI_ERR("fapiGetScom(PMC_MODE_REG_0x00062000) failed."); return rc;
    }


    e_rc = data.setBit(05);  if(e_rc){rc.setEcmdError(e_rc); return rc; }
    e_rc = data.setBit(14);  if(e_rc){rc.setEcmdError(e_rc); return rc; }



    rc = fapiPutScom(i_target, PMC_MODE_REG_0x00062000 , data );
    if (rc) {
         FAPI_ERR("fapiPutScom(PMC_MODE_REG_0x00062000) failed."); return rc;
    }

    is_MasterPMC = data.isBitSet(6) & data.isBitSet(7) ;
    enable_pstate_voltage_changes = data.isBitSet(6) ;
    enable_fw_pstate_mode = data.isBitSet(2) ;






////////////////////////////////////////////////////////////////////////////
// 4. if enable_interchip_interface==1
//       cRQ_TD_HaltInterchip_On: Write PMC_INTCHP_COMMAND_REG.interchip_halt_msg_fsm<-1 Should we write the command register here ? That's why I specified the command register, PMC_INTCHP_COMMAND_REG.
//    cRQ_TD_HaltInterchip_Wait1: Read PMC_STATUS_REG 
//    cRQ_TD_HaltInterchip_Wait2: Read PMC_INTCHP_STATUS_REG 
//       is_pstate_error_stopped = pstate_processing_is_suspended || gpsa_bdcst_error || gpsa_vchg_error || gpsa_timeout_error || pstate_interchip_error
//       is_intchp_error_stopped = interchip_ecc_ue_err || interchip_fsm_err || (is_MasterPMC && interchip_slave_error_code != 0) is_MasterPMC where is this bit ?
//       is_stopped = (interchip_ga_ongoing == 0) || is_pstate_error_stopped || is_intchp_error_stopped
//       If !is_stopped Then -->cRQ_TD_HaltInterchip_Wait1  (Wait limit is parm TD_Interchip_HaltWait_max=260)
//    cRQ_TD_HaltInterchipIf: PMC_MODE_REG.interchip_halt_if<-1 interchip_halt_if where is this bit ? PMC_MODE_REG bit 15 as documented.


////////////////////////////////////////////////////////////////////////////


  FAPI_INF("Performing STEP 4");
    if (data.isBitSet(6))

      {

	rc = fapiGetScom(i_target, PMC_INTCHP_COMMAND_REG_0x00062014 , data );
	if (rc) {
	  FAPI_ERR("fapiGetScom(PMC_INTCHP_COMMAND_REG_0x00062014) failed."); return rc;
	}
	
	e_rc = data.setBit(01);  if(e_rc){rc.setEcmdError(e_rc); return rc; }
	
	
	rc = fapiPutScom(i_target, PMC_INTCHP_COMMAND_REG_0x00062014 , data );
	if (rc) {
	  FAPI_ERR("fapiPutScom(PMC_INTCHP_COMMAND_REG_0x00062014) failed."); return rc;
	}






	for (count = 0 , is_stopped = 0 ; count <= 256 && is_stopped == 0;  count++)
	  {
//    cRQ_TD_HaltInterchip_Wait1: Read PMC_STATUS_REG 
//       is_pstate_error_stopped = pstate_processing_is_suspended || gpsa_bdcst_error || gpsa_vchg_error || gpsa_timeout_error || pstate_interchip_error

	    rc = fapiGetScom(i_target, PMC_STATUS_REG_0x00062009 , data );
	    if (rc) {
	      FAPI_ERR("fapiGetScom(PMC_STATUS_REG_0x00062009) failed."); return rc;
	    }
	

	    is_pstate_error_stopped = data.isBitSet(0) | data.isBitSet(1) | data.isBitSet(5)| data.isBitSet(6) | data.isBitSet(11) ;
	    

//    cRQ_TD_HaltInterchip_Wait2: Read PMC_INTCHP_STATUS_REG 
//       is_intchp_error_stopped = interchip_ecc_ue_err || interchip_fsm_err || (is_MasterPMC && interchip_slave_error_code != 0) is_MasterPMC where is this bit ?

	    rc = fapiGetScom(i_target, PMC_INTCHP_STATUS_REG_0x00062013 , data );
	    if (rc) {
	      FAPI_ERR("fapiGetScom(PMC_INTCHP_STATUS_REG_0x00062013) failed."); return rc;
	    }
	    is_intchp_error_stopped = data.isBitSet(1) | data.isBitSet(7) | (~( data.isBitClear(16,4) &&  is_MasterPMC))  ;

//	is_stopped = (interchip_ga_ongoing == 0) || is_pstate_error_stopped || is_intchp_error_stopped ;
	    is_stopped = data.isBitClear(0)  || is_pstate_error_stopped || is_intchp_error_stopped;


//       If !is_stopped Then -->cRQ_TD_HaltInterchip_Wait1  (Wait limit is parm TD_Interchip_HaltWait_max=260)


	  } // end_for
	if (count > 256)
	  {
	   FAPI_ERR("Timed out in polling interchip ongoing    ... ");
	   FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PMCINIT_TIMEOUT);
	   return rc;
	  
	  }


//    cRQ_TD_HaltInterchipIf: PMC_MODE_REG.interchip_halt_if<-1 interchip_halt_if where is this bit ? PMC_MODE_REG bit 15 as documented.

    rc = fapiGetScom(i_target, PMC_MODE_REG_0x00062000 , data );
    if (rc) {
         FAPI_ERR("fapiGetScom(PMC_MODE_REG_0x00062000) failed."); return rc;
    }

    e_rc = data.setBit(15);  if(e_rc){rc.setEcmdError(e_rc); return rc; }

    rc = fapiPutScom(i_target, PMC_MODE_REG_0x00062000 , data );
    if (rc) {
         FAPI_ERR("fapiPutScom(PMC_MODE_REG_0x00062000) failed."); return rc;
    }




      } // end if

	    


////////////////////////////////////////////////////////////////////////////
// 5. if enable_pstate_voltage_changes==1
//         cRQ_TD_HaltSpivid: PMC_SPIV_COMMAND_REG.spivid_halt_fsm<-1
//    cRQ_TD_Spivid_HaltWait: Read PMC_SPIV_STATUS_REG
//       is_spivid_error = spivid_retry_timeout || spivid_fsm_err
//       if spivid_ongoing && !is_spivid_error Then -->cRQ_TD_Spivid_HaltWait   (Wait limit is parm TD_Spivid_HaltWait_max=100)
//       else -->cRQ_TD_MPS_HaltWait
////////////////////////////////////////////////////////////////////////////

  FAPI_INF("Performing STEP 5");

    if (enable_pstate_voltage_changes==1)
      {
//         cRQ_TD_HaltSpivid: PMC_SPIV_COMMAND_REG.spivid_halt_fsm<-1
	rc = fapiGetScom(i_target, PMC_SPIV_COMMAND_REG_0x00062047 , data );
	if (rc) {
	  FAPI_ERR("fapiGetScom(PMC_SPIV_COMMAND_REG_0x00062047) failed."); return rc;
	}
	
	e_rc = data.setBit(15);  if(e_rc){rc.setEcmdError(e_rc); return rc; }
	
	rc = fapiPutScom(i_target, PMC_SPIV_COMMAND_REG_0x00062047 , data );
	if (rc) {
	  FAPI_ERR("fapiPutScom(PMC_SPIV_COMMAND_REG_0x00062047) failed."); return rc;
	}
	
      

//    cRQ_TD_Spivid_HaltWait: Read PMC_SPIV_STATUS_REG

//       if spivid_ongoing && !is_spivid_error Then -->cRQ_TD_Spivid_HaltWait   (Wait limit is parm TD_Spivid_HaltWait_max=100)

	for (count = 0 , is_spivid_stopped=0; count <= 100 && is_spivid_stopped==0  ; count++)
	  { 

	    rc = fapiGetScom(i_target, PMC_SPIV_STATUS_REG_0x00062046 , data );
	    if (rc) {
	      FAPI_ERR("fapiGetScom(PMC_SPIV_STATUS_REG_0x00062046) failed."); return rc;
	    }
	    is_spivid_stopped = data.isBitClear(0) | data.isBitSet(1) | data.isBitSet(2) | data.isBitSet(3) | data.isBitSet(4) ; 
	    
	  } // end for 



	if (count > 100)
	  {
	   FAPI_ERR("Timed out in polling spiv ongoing    ... ");
	   FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PMCINIT_TIMEOUT);
	   return rc;
	  
	  }

      } // end if


////////////////////////////////////////////////////////////////////////////
// 6. cRQ_TD_MPS_HaltWait: Read PMC_STATUS_REG
// 
//       if (fw_pstate_mode)
//          is_not_ongoing = (enable_pstate_voltage_changes==0 || volt_chg_ongoing==0) && (brd_cst_ongoing == 0)
//       else
//          is_not_ongoing = (enable_pstate_voltage_changes==0 || gpsa_chg_ongoing==0)

//       is_pstate_error = (pstate_interchip_error || pstate_processing_is_suspended || gpsa_bdcst_error || gpsa_vchg_error || gpsa_timeout_error)
//            is_stopped = is_not_ongoing || is_pstate_error

//       if (!is_stopped) then -->cRQ_TD_MPS_HaltWait   (Wait limit)

////////////////////////////////////////////////////////////////////////////

  FAPI_INF("Performing STEP ");


    for (count = 0 , is_stopped = 0 ; count <= 256 && is_stopped == 0 ; count++)
      {

	rc = fapiGetScom(i_target, PMC_STATUS_REG_0x00062009 , data );
	if (rc) {
	  FAPI_ERR("fapiGetScom(PMC_STATUS_REG_0x00062009) failed."); return rc;
	}

	
	if (fw_pstate_mode)
	  {
	    
	    is_not_ongoing = (enable_pstate_voltage_changes==0 ||  data.isBitClear(8)) && data.isBitClear(9);
	    
	  }
	else
	  {
	    is_not_ongoing = (enable_pstate_voltage_changes==0 ||  data.isBitClear(7));
	  }

	is_stopped = (data.isBitSet(11) | data.isBitSet(12) | data.isBitSet(1) | data.isBitSet(5) | data.isBitSet(6)) | is_not_ongoing ;

      } // end for

	if (count > 100)
	  {
	   FAPI_ERR("Timed out in polling voltage change ongoing    ... ");
	   FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PMCINIT_TIMEOUT);
	   return rc;

	  }
	return rc;
}
// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------


// function: p8_pmc_init
// parameters: target , mode = (PM_INIT , PM_CONFIG, PM_RESET)
// returns: ECMD_SUCCESS if something good happens,
//          BAD_RETURN_CODE otherwise
fapi::ReturnCode
p8_pmc_init(const Target& i_target, uint32_t mode)
{
  fapi::ReturnCode rc;
  ecmdDataBufferBase data(64);
  ecmdDataBufferBase mask(64);
  uint32_t            e_rc = 0;

  FAPI_INF("");
  FAPI_INF("Executing p8_pmc_init  ....");
  

  // ------------------------------------------------
  // CONFIG mode
  // ------------------------------------------------
  if (mode == PM_CONFIG) 
  {
  
    FAPI_INF("PMC configuration...");    rc=pmc_config_spivid_settings(i_target);
    
  } 
  
  // ------------------------------------------------
  // INIT mode
  // ------------------------------------------------

  else if (mode == PM_INIT) {
  
    uint8_t attr_pm_spivid_frame_size;
    uint8_t attr_pm_spivid_in_delay_frame1;
    uint8_t attr_pm_spivid_in_delay_frame2;
    uint8_t attr_pm_spivid_clock_polarity;
    uint8_t attr_pm_spivid_clock_phase;
    uint32_t attr_pm_spivid_clock_divider;
    uint8_t attr_pm_spivid_port_enable = 7;
    // uint32_t attr_pm_spivid_interframe_delay_write_status;
    uint32_t attr_pm_spivid_interframe_delay_write_status_value;
//     uint32_t attr_pm_spivid_inter_retry_delay_value;
//     uint32_t attr_pm_spivid_inter_retry_delay;
    uint8_t attr_pm_spivid_crc_gen_enable;
    uint8_t attr_pm_spivid_crc_check_enable;
    uint8_t attr_pm_spivid_majority_vote_enable;
    uint8_t attr_pm_spivid_max_retries;
    uint8_t attr_pm_spivid_crc_polynomial_enables;                



     	//---------------------------------------------------------- 
     rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_FRAME_SIZE, &i_target, attr_pm_spivid_frame_size); 
     if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_FRAME_SIZE with rc = 0x%x", (uint32_t)rc);  return rc; }
     else { FAPI_INF (" value read from the attribute attr_pm_spivid_frame_size = 0x%x", attr_pm_spivid_frame_size );}

     	//---------------------------------------------------------- 
     rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_IN_DELAY_FRAME1, &i_target, attr_pm_spivid_in_delay_frame1); 

     if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_IN_DELAY_FRAME1 with rc = 0x%x", (uint32_t)rc);  return rc; }
     else { FAPI_INF (" value read from the attribute attr_pm_spivid_in_delay_frame1 = 0x%x", attr_pm_spivid_in_delay_frame1);}

     	//---------------------------------------------------------- 
     rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_IN_DELAY_FRAME2, &i_target, attr_pm_spivid_in_delay_frame2); 

     if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_IN_DELAY_FRAME2 with rc = 0x%x", (uint32_t)rc);  return rc; }
     else { FAPI_INF (" value read from the attribute attr_pm_spivid_in_delay_frame2 = 0x%x", attr_pm_spivid_in_delay_frame2);}

     	//---------------------------------------------------------- 
     rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_CLOCK_POLARITY, &i_target, attr_pm_spivid_clock_polarity); 

     if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_CLOCK_POLARITY with rc = 0x%x", (uint32_t)rc);  return rc; }
     else { FAPI_INF (" value read from the attribute attr_pm_spivid_clock_polarity = 0x%x", attr_pm_spivid_clock_polarity);}

     	//---------------------------------------------------------- 
     rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_CLOCK_PHASE, &i_target, attr_pm_spivid_clock_phase); 

     if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_CLOCK_PHASE with rc = 0x%x", (uint32_t)rc);  return rc; }
     else { FAPI_INF (" value read from the attribute attr_pm_spivid_clock_phase = 0x%x", attr_pm_spivid_clock_phase);}

     	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS, &i_target, attr_pm_spivid_interframe_delay_write_status); 

//      if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS with rc = 0x%x", (uint32_t)rc);  return rc; }
//      else { FAPI_INF (" value read from the attribute attr_pm_spivid_interframe_delay_write_status = 0x%x", attr_pm_spivid_interframe_delay_write_status);}

     	//---------------------------------------------------------- 
     rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS_VALUE, &i_target, attr_pm_spivid_interframe_delay_write_status_value); 

     if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS_VALUE with rc = 0x%x", (uint32_t)rc);  return rc; }
     else { FAPI_INF (" value read from the attribute attr_pm_spivid_interframe_delay_write_status_value = 0x%x", attr_pm_spivid_interframe_delay_write_status_value);}

     	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_INTER_RETRY_DELAY_VALUE, &i_target, attr_pm_spivid_inter_retry_delay_value); 

//      if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_INTER_RETRY_DELAY_VALUE with rc = 0x%x", (uint32_t)rc);  return rc; }
//      else { FAPI_INF (" value read from the attribute attr_pm_spivid_inter_retry_delay_value = 0x%x", attr_pm_spivid_inter_retry_delay_value);}

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_INTER_RETRY_DELAY, &i_target, attr_pm_spivid_inter_retry_delay); 

//      if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_INTER_RETRY_DELAY with rc = 0x%x", (uint32_t)rc);  return rc; }
//      else { FAPI_INF (" value read from the attribute attr_pm_spivid_inter_retry_delay = 0x%x", attr_pm_spivid_inter_retry_delay);}

     	//---------------------------------------------------------- 
     rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_CRC_GEN_ENABLE, &i_target, attr_pm_spivid_crc_gen_enable); 

     if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_CRC_GEN_ENABLE with rc = 0x%x", (uint32_t)rc);  return rc; }
     else { FAPI_INF (" value read from the attribute attr_pm_spivid_crc_gen_enable = 0x%x", attr_pm_spivid_crc_gen_enable);}

     	//---------------------------------------------------------- 
     rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_CRC_CHECK_ENABLE, &i_target, attr_pm_spivid_crc_check_enable); 

     if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_CRC_CHECK_ENABLE with rc = 0x%x", (uint32_t)rc);  return rc; }
     else { FAPI_INF (" value read from the attribute attr_pm_spivid_crc_check_enable = 0x%x", attr_pm_spivid_crc_check_enable);}

     	//---------------------------------------------------------- 
     rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_MAJORITY_VOTE_ENABLE, &i_target, attr_pm_spivid_majority_vote_enable); 

     if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_MAJORITY_VOTE_ENABLE with rc = 0x%x", (uint32_t)rc);  return rc; }
     else { FAPI_INF (" value read from the attribute attr_pm_spivid_majority_vote_enable = 0x%x", attr_pm_spivid_majority_vote_enable);}

     	//---------------------------------------------------------- 
     rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_MAX_RETRIES, &i_target, attr_pm_spivid_max_retries); 

     if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_MAX_RETRIES with rc = 0x%x", (uint32_t)rc);  return rc; }
     else { FAPI_INF (" value read from the attribute attr_pm_spivid_max_retries = 0x%x", attr_pm_spivid_max_retries);}

     	//---------------------------------------------------------- 
     rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_CRC_POLYNOMIAL_ENABLES, &i_target, attr_pm_spivid_crc_polynomial_enables); 

     if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_CRC_POLYNOMIAL_ENABLES with rc = 0x%x", (uint32_t)rc);  return rc; }
     else { FAPI_INF (" value read from the attribute attr_pm_spivid_crc_polynomial_enables = 0x%x", attr_pm_spivid_crc_polynomial_enables);}


     	//---------------------------------------------------------- 
      rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_CLOCK_DIVIDER, &i_target, attr_pm_spivid_clock_divider); 

      if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_CLOCK_DIVIDER with rc = 0x%x", (uint32_t)rc);  return rc; }
      else { FAPI_INF (" value read from the attribute attr_pm_spivid_clock_divider = 0x%x", attr_pm_spivid_clock_divider);}


     	//---------------------------------------------------------- 
      rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_PORT_ENABLE, &i_target, attr_pm_spivid_port_enable); 

      if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_PORT_ENABLE with rc = 0x%x", (uint32_t)rc);  return rc; }
     else { FAPI_INF (" value read from the attribute attr_pm_spivid_port_enable = 0x%x", attr_pm_spivid_port_enable);}


     	//---------------------------------------------------------- 











      //      rc=pmc_create_spivid_settings(i_target);  above lines replaced this functions
  
    FAPI_INF("PMC initialization...");

     uint8_t o2s_frame_size = attr_pm_spivid_frame_size;                            
     uint8_t o2s_in_delay1  = attr_pm_spivid_in_delay_frame1;                       
     uint8_t o2s_in_delay2  = attr_pm_spivid_in_delay_frame2;                       
     uint8_t o2s_clk_pol    = attr_pm_spivid_clock_polarity;                        
     uint8_t o2s_clk_pha    = attr_pm_spivid_clock_phase;                           
     uint8_t o2s_port_enable = attr_pm_spivid_port_enable;                           
     uint32_t o2s_inter_frame_delay = attr_pm_spivid_interframe_delay_write_status_value; 
     uint8_t o2s_crc_gen_en = attr_pm_spivid_crc_gen_enable;                        
     uint8_t o2s_crc_check_en = attr_pm_spivid_crc_check_enable;                      
     uint8_t o2s_majority_vote_en = attr_pm_spivid_majority_vote_enable;                  
     uint8_t o2s_max_retries = attr_pm_spivid_max_retries;                           
     uint8_t o2s_crc_polynomial_enables = attr_pm_spivid_crc_polynomial_enables;                
     uint16_t o2s_clk_divider = attr_pm_spivid_clock_divider;                        
     //spivid_freq =  attr_pm_spivid_frequency;                            
     uint8_t   o2s_in_count2 	   = 0 ; 
     uint8_t   o2s_out_count2          = 0 ; 
     uint8_t   o2s_bridge_enable = 0x1 ;  
     uint8_t   o2s_nr_of_frames        = 1 ; //(uint8_t) args.front(); args.pop_front(); // for pmc o2s operations it is usually 1    
     uint8_t   o2s_in_count1 	   = 0 ; 
     uint8_t   o2s_out_count1 	   = 32 ; 
     uint32_t  dummy = 0 ;


     uint8_t   one=1;



    
    
    // Here to bypass feature attribute passing until these as moved into proc.pm.pmc.scom.initfile
    
//     o2s_frame_size = 0x10 ;  
//     o2s_clk_pol    = 0;  
//     o2s_clk_pha    = 0;  
//     o2s_clk_divider= 0x1D;  
//     o2s_inter_frame_delay = 0x0;
//     nest_freq = 600;
//     spivid_freq = 10;
//     o2s_in_count1=0;  
//     o2s_out_count1=0; 
//     o2s_in_delay1=0;  
//     o2s_in_count2=0;  
//     o2s_out_count2=0; 
//     o2s_in_delay2=0;  
//    o2s_wdata = 0x11223344;

    
    
    //  ******************************************************************
    // 	- set PMC_o2s_CTRL_REG0A (24b) 
    //  ******************************************************************

    rc = fapiGetScom(i_target, PMC_O2S_CTRL_REG0A_0x00062050, data );
    if (rc) {
         FAPI_ERR("fapiGetScom(PMC_O2S_CTRL_REG0A) failed."); return rc;
    }
    
    e_rc = data.insertFromRight(   o2s_frame_size ,0,6); if(e_rc){rc.setEcmdError(e_rc); return rc;}
    e_rc = data.insertFromRight(   o2s_in_count1  ,6,6); if(e_rc){rc.setEcmdError(e_rc); return rc;}
    e_rc = data.insertFromRight(   o2s_out_count1 ,12,6); if(e_rc){rc.setEcmdError(e_rc); return rc;}
    e_rc = data.insertFromRight(   o2s_in_delay1  ,18,6); if(e_rc){rc.setEcmdError(e_rc); return rc;}



    // FAPI_INF("  -----------------------------------------------------");
    FAPI_INF("  PMC O2S CTRL_REG_0A Configuration                  ");
    // FAPI_INF("  -----------------------------------------------------");  
    e_rc = data.extractToRight(&dummy,0,6);
    FAPI_INF("    frame size                 => %x ",  dummy);
    e_rc |= data.extractToRight(&dummy,6,6);
    FAPI_INF("    o2s_out_count1             => %x ",  dummy);
    e_rc |= data.extractToRight(&dummy,12,6);
    FAPI_INF("    o2s_in_delay1              => %x ",  dummy);
    e_rc |= data.extractToRight(&dummy,18,6);
    FAPI_INF("    o2s_in_count1              => %x ",  dummy);
    FAPI_INF("                                     "                 );
    FAPI_INF("                                     "                 );
    // FAPI_INF("  -----------------------------------------------------");

    if(e_rc){rc.setEcmdError(e_rc); return rc;}
    rc = fapiPutScom(i_target, PMC_O2S_CTRL_REG0A_0x00062050, data );
    if (rc) {
      FAPI_ERR("fapiPutScom(PMC_O2S_CTRL_REG0A_0x00062050) failed."); return rc;
    }
    

    //  ******************************************************************
    // 	- set PMC_O2S_CTRL_REG0B (24b) 
    //  ******************************************************************

    rc = fapiGetScom(i_target, PMC_O2S_CTRL_REG0B_0x00062051, data );
    if (rc) {
      FAPI_ERR("fapiGetScom(PMC_O2S_CTRL_REG0B) failed."); return rc;
    }
    
    e_rc = data.insertFromRight(o2s_out_count2,00,6); if(e_rc){rc.setEcmdError(e_rc); return rc;}
    e_rc = data.insertFromRight(o2s_in_delay2 ,06,6); if(e_rc){rc.setEcmdError(e_rc); return rc;}
    e_rc = data.insertFromRight(o2s_in_count2 ,12,6); if(e_rc){rc.setEcmdError(e_rc); return rc;}

    // FAPI_INF("  -----------------------------------------------------");
    FAPI_INF("  PMC O2S CTRL_REG_0B Configuration                  ");
    // FAPI_INF("  -----------------------------------------------------");  
    FAPI_INF("    o2s_out_count2             => %d ",  o2s_out_count2);
    FAPI_INF("    o2s_in_delay2              => %d ",  o2s_in_delay2 );
    FAPI_INF("    o2s_in_count2              => %d ",  o2s_in_count2 );
    FAPI_INF("                                     "                 );
    FAPI_INF("                                     "                 );
    // FAPI_INF("  -----------------------------------------------------");

    rc = fapiPutScom(i_target, PMC_O2S_CTRL_REG0B_0x00062051, data );
    if (rc) {
      FAPI_ERR("fapiPutScom(PMC_O2S_CTRL_REG0B_0x00062051) failed."); return rc;
    }

    //  ******************************************************************
    // 	- set PMC_O2S_CTRL_REG1
    //  ******************************************************************

    rc = fapiGetScom(i_target, PMC_O2S_CTRL_REG1_0x00062052, data );
    if (rc) {
      FAPI_ERR("fapiGetScom(PMC_O2S_CTRL_REG1) failed."); return rc;
    }
    
    o2s_nr_of_frames--;
    e_rc = data.insertFromRight(   o2s_bridge_enable ,0,1); if(e_rc){rc.setEcmdError(e_rc); return rc;}
    e_rc = data.insertFromRight(   o2s_clk_pol    ,2,1); if(e_rc){rc.setEcmdError(e_rc); return rc;}
    e_rc = data.insertFromRight(   o2s_clk_pha    ,3,1); if(e_rc){rc.setEcmdError(e_rc); return rc;}
    e_rc = data.insertFromRight(   o2s_clk_divider,4,10); if(e_rc){rc.setEcmdError(e_rc); return rc;}
    e_rc = data.insertFromRight(   o2s_nr_of_frames ,17,1); if(e_rc){rc.setEcmdError(e_rc); return rc;}
    e_rc = data.insertFromRight(   o2s_port_enable    ,18,3); if(e_rc){rc.setEcmdError(e_rc); return rc;}
    o2s_nr_of_frames++;
  

    // FAPI_INF("  -----------------------------------------------------");
    FAPI_INF("  PMC O2S CTRL_REG_1 Configuration                  ");
    // FAPI_INF("  -----------------------------------------------------");  
    FAPI_INF("    o2s_bridge_enable           => %d ",  o2s_bridge_enable );
    FAPI_INF("    o2s_clk_pol                 => %d ",  o2s_clk_pol    );
    FAPI_INF("    o2s_clk_pha                 => %d ",  o2s_clk_pha    );
    FAPI_INF("    o2s_clk_divider             => %d ",  o2s_clk_divider);
    FAPI_INF("    o2s_nr_of_frames            => %d ",  o2s_nr_of_frames);
    FAPI_INF("    o2s_port_enable             => %d ",  o2s_port_enable);
    FAPI_INF("                                     "                 );
    FAPI_INF("                                     "                 );
    // FAPI_INF("  -----------------------------------------------------");

    rc = fapiPutScom(i_target, PMC_O2S_CTRL_REG1_0x00062052, data );
    if (rc) {
      FAPI_ERR("fapiPutScom(PMC_O2S_CTRL_REG1_0x00062052) failed."); return rc;
    }
    

    //  ******************************************************************
    // 	- set PMC_O2S_CTRL_REG2
    //  ******************************************************************


    rc = fapiGetScom(i_target, PMC_O2S_CTRL_REG2_0x00062053, data );
    if (rc) {
      FAPI_ERR("fapiGetScom(PMC_O2S_CTRL_REG2) failed."); return rc;
    }

    e_rc = data.insertFromRight(  o2s_inter_frame_delay   ,0,17); if(e_rc){rc.setEcmdError(e_rc); return rc;}

    // FAPI_INF("  -----------------------------------------------------");
    FAPI_INF("  PMC O2S CTRL_REG_2 Configuration                  ");
    // FAPI_INF("  -----------------------------------------------------");  
    FAPI_INF("    o2s_inter_frame_delay       => %d ",  o2s_inter_frame_delay );
    FAPI_INF("                                     "                 );
    FAPI_INF("                                     "                 );
    // FAPI_INF("  -----------------------------------------------------");



    rc = fapiPutScom(i_target, PMC_O2S_CTRL_REG2_0x00062053, data );
    if (rc) {
      FAPI_ERR("fapiPutScom(PMC_O2S_CTRL_REG2_0x00062053) failed."); return rc;
    }
    
    //  ******************************************************************
    // 	- set PMC_O2S_CTRL_REG4
    //  ******************************************************************

    rc = fapiGetScom(i_target, PMC_O2S_CTRL_REG4_0x00062055, data );
    if (rc) {
      FAPI_ERR("fapiGetScom(PMC_O2S_CTRL_REG4) failed."); return rc;
    }

    e_rc = data.insertFromRight(  o2s_crc_gen_en         ,0,1); if(e_rc){rc.setEcmdError(e_rc); return rc;}
    e_rc = data.insertFromRight(  o2s_crc_check_en       ,1,1); if(e_rc){rc.setEcmdError(e_rc); return rc;}
    e_rc = data.insertFromRight(  o2s_majority_vote_en   ,2,1); if(e_rc){rc.setEcmdError(e_rc); return rc;}
    e_rc = data.insertFromRight(  o2s_max_retries        ,3,5); if(e_rc){rc.setEcmdError(e_rc); return rc;}
    e_rc = data.insertFromRight(  o2s_crc_polynomial_enables,8,8); if(e_rc){rc.setEcmdError(e_rc); return rc;}

    // FAPI_INF("  -----------------------------------------------------");
    FAPI_INF("  PMC O2S CTRL_REG_4 Configuration                  ");
    // FAPI_INF("  -----------------------------------------------------");  
    FAPI_INF("    o2s_crc_gen_en           => %d ",  o2s_crc_gen_en          );
    FAPI_INF("    o2s_crc_check_en         => %d ",  o2s_crc_check_en        );
    FAPI_INF("    o2s_majority_vote_en     => %d ",  o2s_majority_vote_en    );
    FAPI_INF("    o2s_max_retries          => %d ",  o2s_max_retries         );
    FAPI_INF("    o2s_crc_polynomial_enab  => %d ",  o2s_crc_polynomial_enables );
    FAPI_INF("                                     "                 );
    FAPI_INF("                                     "                 );
    // FAPI_INF("  -----------------------------------------------------");


    rc = fapiPutScom(i_target, PMC_O2S_CTRL_REG4_0x00062055, data );
    if (rc) {
      FAPI_ERR("fapiPutScom(PMC_O2S_CTRL_REG4_0x00062055) failed."); return rc;
    }

//  ******************************************************************
//   Program crc polynomials
//  ******************************************************************

   rc = fapiGetScom(i_target, PMC_SPIV_CTRL_REG4_0x00062045, data );
   if (rc) {
     FAPI_ERR("fapiGetScom(PMC_SPIV_CTRL_REG4) failed."); return rc;
   }


   e_rc = data.insertFromRight(  o2s_crc_gen_en         ,0,1); if(e_rc){rc.setEcmdError(e_rc); return rc;}
   e_rc = data.insertFromRight(  o2s_crc_check_en       ,1,1); if(e_rc){rc.setEcmdError(e_rc); return rc;}
   e_rc = data.insertFromRight(  o2s_majority_vote_en   ,2,1); if(e_rc){rc.setEcmdError(e_rc); return rc;}
   e_rc = data.insertFromRight(  o2s_max_retries        ,3,5); if(e_rc){rc.setEcmdError(e_rc); return rc;}
   e_rc = data.insertFromRight(  o2s_crc_polynomial_enables,8,8); if(e_rc){rc.setEcmdError(e_rc); return rc;}

      //   FAPI_INF("  -----------------------------------------------------");
   FAPI_INF("  PMC O2S CTRL_REG_3Configuration                  ");
   //   FAPI_INF("  -----------------------------------------------------");  
   FAPI_INF("    spiv_crc_gen_en           => %d ",  o2s_crc_gen_en          );
   FAPI_INF("    spiv_crc_check_en         => %d ",  o2s_crc_check_en        );
   FAPI_INF("    spiv_majority_vote_en     => %d ",  o2s_majority_vote_en    );
   FAPI_INF("    spiv_max_retries          => %d ",  o2s_max_retries         );
   FAPI_INF("    spiv_crc_polynomial_enab  => %d ",  o2s_crc_polynomial_enables );
   FAPI_INF("                                     "                 );
   FAPI_INF("                                     "                 );
   //   FAPI_INF("  -----------------------------------------------------");


   rc = fapiPutScom(i_target, PMC_SPIV_CTRL_REG4_0x00062045, data );
   if (rc) {
     FAPI_ERR("fapiPutScom(PMC_SPIV_CTRL_REG4_0x00062045) failed."); return rc;
   }
 
    
    //  ******************************************************************
    // 	- write PMC_O2S_command_reg to clear any latent errors
    //  ******************************************************************
   e_rc = data.flushTo0(); if(e_rc){rc.setEcmdError(e_rc); return rc;}
    e_rc = data.insertFromRight(one ,0,1); if(e_rc){rc.setEcmdError(e_rc); return rc;} // halt retries 
    e_rc = data.insertFromRight(one ,1,1); if(e_rc){rc.setEcmdError(e_rc); return rc;} // reset sticky errors 
    // FAPI_INF("  -----------------------------------------------------");
    FAPI_INF("   clearing errors                                 ");
    // FAPI_INF("  -----------------------------------------------------");  

    rc = fapiPutScom(i_target, PMC_O2S_COMMAND_REG_0x00062057, data );
    if (rc) {
      FAPI_ERR("fapiPutScom(PMC_O2S_COMMAND_REG_0x00062057) failed."); return rc;
    }
  
    e_rc = data.flushTo0(); if(e_rc){rc.setEcmdError(e_rc); return rc;}
  
    rc = fapiPutScom(i_target, PMC_O2S_COMMAND_REG_0x00062057, data );
    if (rc) {
      FAPI_ERR("fapiPutScom(PMC_O2S_COMMAND_REG_0x00062057) failed."); return rc;
    }
    FAPI_INF ("I m done with the init " );
  
  }
  
  /// -------------------------------
  /// Reset:  perform reset of PMC
  else if (mode == PM_RESET) 
  {

    FAPI_INF("PMC reset...");
    
    //  Reset PMC.  However, the bit used means the entire PMC must be reconfigured!
     
    e_rc = data.flushTo0(); if(e_rc){rc.setEcmdError(e_rc); return rc;}
    e_rc = data.setBit(12);  if(e_rc){rc.setEcmdError(e_rc); return rc; } // RESET_ALL_PMC_REGISTERS    
           
    rc=fapiPutScom(i_target, PMC_MODE_REG_0x00062000 , data); if(rc) return rc; 
    // This function is not yet verified
    rc=pmc_reset_function(i_target);

    
  } 

  
  /// -------------------------------
  /// Unsupported Mode
  
  else {
    FAPI_ERR("Unknown mode passed to p8_pmc_init. Mode %x ", mode);
    uint32_t & MODE = mode;
    FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PMC_CODE_BAD_MODE); 
  }
  
  return rc;

}



  //#ifdef FAPIECMD
}   //end extern C
// #endif 











// BackUPS

// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------



// PIB Space Addresses


/*
    CONST_UINT64_T( PMC_SPIV_CTRL_REG0B_0x00072041        , ULL(0x00072041) );
    CONST_UINT64_T( PMC_SPIV_CTRL_REG1_0x00072042        , ULL(0x00072042) );
    CONST_UINT64_T( PMC_SPIV_CTRL_REG2_0x00072043        , ULL(0x00072043) );
    CONST_UINT64_T( PMC_SPIV_CTRL_REG3_0x00072044        , ULL(0x00072044) );
    CONST_UINT64_T( PMC_SPIV_CTRL_REG4_0x00072045        , ULL(0x00072045) );
    CONST_UINT64_T( PMC_SPIV_STATUS_REG_0x00072046        , ULL(0x00072046) );
    CONST_UINT64_T( PMC_SPIV_COMMAND_REG_0x00072047        , ULL(0x00072047) );


    CONST_UINT64_T( PMC_O2S_CTRL_REG0A_0x00062050 , ULL(0x00062050) );               
    CONST_UINT64_T( PMC_O2S_CTRL_REG0B_0x00062051 ,ULL(0x00062051) ); 		 
    CONST_UINT64_T( PMC_O2S_CTRL_REG1_0x00062052 ,ULL(0x00062052) ); 		 
    CONST_UINT64_T( PMC_O2S_CTRL_REG2_0x00062053 ,ULL(0x00062053) ); 		 
    CONST_UINT64_T( PMC_O2S_CTRL_REG4_0x00062055 ,ULL(0x00062055) ); 		 
    CONST_UINT64_T( PMC_O2S_STATUS_REG_0x00062056 ,ULL(0x00062056) ); 		 
    CONST_UINT64_T( PMC_O2S_COMMAND_REG_0x00062057 ,ULL(0x00062057) ); 		 
    CONST_UINT64_T( PMC_O2S_WDATA_REG_0x00062058 ,ULL(0x00062058) ); 		 
    CONST_UINT64_T( PMC_O2S_RDATA_REG_0x00062059 ,ULL(0x00062059) ); 		 

// OCI Space Addresses
CONST_UINT32_T( OCI_PMC_MODE_REG_0x40010000  , ULL(0x40010000) );
*/

// ----------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------

// std::string PROCEDURE = "p8_pmc_init";        // procedure name
  //std::string REVISION  = "$Revision: 1.6 $";        // procedure CVS revision

//ReturnCode BAD_RETURN_CODE      = 0x12000001;      // procedure return code on fail, not used by ECMD
//uint32_t   SIM_CYCLE_POLL_DELAY = 200000;          // simulation cycle delay between status register polls
//bool       VERBOSE              = true;            // enable verbose mode debug comments
//uint32_t   MAX_POLL_ATTEMPTS    = 5;               // maximum number of status poll attempts to make before giving up



  // Global Variables
    /// From generated pm_attributes_plat.H

/*
      uint8_t attr_pm_pstate_stepsize;
      uint8_t attr_pm_external_vrm_stepdelay_range;
      uint8_t attr_pm_external_vrm_stepdelay_value;
      uint8_t attr_pm_pmc_hangpulse_divider;
      uint8_t attr_pm_pvsafe_pstate;
      uint8_t attr_pm_pstate_undervolting_minimum;
      uint8_t attr_pm_pstate_undervolting_maximum;
*/


    /// From generated pm_attributes_plat.H









/*
    rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_FRAME_SIZE, l_pTarget, attr_pm_spivid_frame_size); if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_IN_DELAY_FRAME1, l_pTarget, attr_pm_spivid_in_delay_frame1); if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_IN_DELAY_FRAME2, l_pTarget, attr_pm_spivid_in_delay_frame2); if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_INTER_FRAME_DELAY, l_pTarget, attr_pm_spivid_inter_frame_delay); if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_INTER_FRAME_DELAY_WRITE_STATUS, l_pTarget, attr_pm_spivid_inter_frame_delay_write_status); if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_INTER_RETRY_DELAY, l_pTarget, attr_pm_spivid_inter_retry_delay); if (rc) return rc;
*/


    // Here to test feature attribute passing util these as moved into proc.pm.pmc.scom.initfile
    /*
    rc = FAPI_ATTR_GET(ATTR_SPIVID_CLOCK_POLARITY, NULL, o2s_clk_pol); if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_SPIVID_CLOCK_PHASE, NULL, o2s_clk_pha); if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_SPIVID_PORT_ENABLE, NULL, o2s_port_enable); if (rc) return rc;
    rc = FAPI_ATTR_GET(SPIVID_INTER_FRAME_DELAY_WRITE_STATUS, NULL, o2s_inter_frame_delay); if (rc) return rc;


    //   rc = FAPI_ATTR_GET(SPIVID_INTER_RETRY_DELAY, NULL, l_uint64_1); if (rc) return rc;

    rc = FAPI_ATTR_GET(ATTR_SPIVID_CRC_GEN_ENABLE, NULL, o2s_crc_gen_en); if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_SPIVID_CRC_CHECK_ENABLE, NULL, o2s_crc_check_en); if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_SPIVID_MAJORITY_VOTE_ENABLE, NULL, o2s_majority_vote_en); if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_SPIVID_MAX_RETRIES, NULL, o2s_max_retries); if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_SPIVID_CRC_POLYNOMIAL_ENABLES, NULL, o2s_crc_polynomial_enables); if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_SPIVID_IN_DELAY_FRAME1, NULL, o2s_in_delay1); if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_SPIVID_IN_DELAY_FRAME2, NULL, o2s_in_delay2); if (rc) return rc;
    */




//     uint8_t attr_pm_spivid_frame_size_set = 32;
//     uint8_t attr_pm_spivid_in_delay_frame1_set = 0;
//     uint8_t attr_pm_spivid_in_delay_frame2_set = 0 ;
//     uint8_t attr_pm_spivid_clock_polarity_set = 0;
//     uint8_t attr_pm_spivid_clock_phase_set = 0 ;
//     //    uint32_t attr_pm_spivid_clock_divider_set = 0x1D ;
//     //    uint8_t attr_pm_spivid_port_enable_set = 3 ;
//     uint32_t attr_pm_spivid_interframe_delay_write_status_set = 0 ;
//     uint32_t attr_pm_spivid_interframe_delay_write_status_value_set = 12;
//     uint32_t attr_pm_spivid_inter_retry_delay_value_set = 20 ;
//     uint32_t attr_pm_spivid_inter_retry_delay_set = 1;
//     uint8_t attr_pm_spivid_crc_gen_enable_set = 1 ;
//     uint8_t attr_pm_spivid_crc_check_enable_set = 1 ;
//     uint8_t attr_pm_spivid_majority_vote_enable_set = 1;
//     uint8_t attr_pm_spivid_max_retries_set = 5 ;
//     uint8_t attr_pm_spivid_crc_polynomial_enables_set = 0xD5;              
// //     uint32_t attr_pm_spivid_frequency_set = 20;
// //     uint32_t attr_p8_nest_frequency_set = 3000;





//     rc = FAPI_ATTR_SET(ATTR_PM_SPIVID_FRAME_SIZE, &l_pTarget, attr_pm_spivid_frame_size_set); 
//      if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_FRAME_SIZE with rc = 0x%x", (uint32_t)rc);  return rc; }
    
   
//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_SET(ATTR_PM_SPIVID_IN_DELAY_FRAME1, &l_pTarget, attr_pm_spivid_in_delay_frame1_set); 
//      if (rc) { FAPI_ERR("fapiSetAttribute of ATTR_PM_SPIVID_IN_DELAY_FRAME1 with rc = 0x%x", (uint32_t)rc);  return rc; }

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_SET(ATTR_PM_SPIVID_IN_DELAY_FRAME2, &l_pTarget, attr_pm_spivid_in_delay_frame2_set); 
//      if (rc) { FAPI_ERR("fapiSetAttribute of ATTR_PM_SPIVID_IN_DELAY_FRAME2 with rc = 0x%x", (uint32_t)rc);  return rc; }

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_SET(ATTR_PM_SPIVID_CLOCK_POLARITY, &l_pTarget, attr_pm_spivid_clock_polarity_set); 
//      if (rc) { FAPI_ERR("fapiSetAttribute of ATTR_PM_SPIVID_CLOCK_POLARITY with rc = 0x%x", (uint32_t)rc);  return rc; }

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_SET(ATTR_PM_SPIVID_CLOCK_PHASE, &l_pTarget, attr_pm_spivid_clock_phase_set); 
//      if (rc) { FAPI_ERR("fapiSetAttribute of ATTR_PM_SPIVID_CLOCK_PHASE with rc = 0x%x", (uint32_t)rc);  return rc; }



//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_SET(ATTR_PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS, &l_pTarget, attr_pm_spivid_interframe_delay_write_status_set); 
//      if (rc) { FAPI_ERR("fapiSetAttribute of ATTR_PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS with rc = 0x%x", (uint32_t)rc);  return rc; }

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_SET(ATTR_PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS_VALUE, &l_pTarget, attr_pm_spivid_interframe_delay_write_status_value_set); 
//      if (rc) { FAPI_ERR("fapiSetAttribute of ATTR_PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS_VALUE with rc = 0x%x", (uint32_t)rc);  return rc; }

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_SET(ATTR_PM_SPIVID_INTER_RETRY_DELAY_VALUE, &l_pTarget, attr_pm_spivid_inter_retry_delay_value_set); 
//      if (rc) { FAPI_ERR("fapiSetAttribute of ATTR_PM_SPIVID_INTER_RETRY_DELAY_VALUE with rc = 0x%x", (uint32_t)rc);  return rc; }

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_SET(ATTR_PM_SPIVID_INTER_RETRY_DELAY, &l_pTarget, attr_pm_spivid_inter_retry_delay_set); 
//      if (rc) { FAPI_ERR("fapiSetAttribute of ATTR_PM_SPIVID_INTER_RETRY_DELAY with rc = 0x%x", (uint32_t)rc);  return rc; }

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_SET(ATTR_PM_SPIVID_CRC_GEN_ENABLE, &l_pTarget, attr_pm_spivid_crc_gen_enable_set); 
//      if (rc) { FAPI_ERR("fapiSetAttribute of ATTR_PM_SPIVID_CRC_GEN_ENABLE with rc = 0x%x", (uint32_t)rc);  return rc; }

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_SET(ATTR_PM_SPIVID_CRC_CHECK_ENABLE, &l_pTarget, attr_pm_spivid_crc_check_enable_set); 
//      if (rc) { FAPI_ERR("fapiSetAttribute of ATTR_PM_SPIVID_CRC_CHECK_ENABLE with rc = 0x%x", (uint32_t)rc);  return rc; }

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_SET(ATTR_PM_SPIVID_MAJORITY_VOTE_ENABLE, &l_pTarget, attr_pm_spivid_majority_vote_enable_set); 
//      if (rc) { FAPI_ERR("fapiSetAttribute of ATTR_PM_SPIVID_MAJORITY_VOTE_ENABLE with rc = 0x%x", (uint32_t)rc);  return rc; }

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_SET(ATTR_PM_SPIVID_MAX_RETRIES, &l_pTarget, attr_pm_spivid_max_retries_set); 
//      if (rc) { FAPI_ERR("fapiSetAttribute of ATTR_PM_SPIVID_MAX_RETRIES with rc = 0x%x", (uint32_t)rc);  return rc; }

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_SET(ATTR_PM_SPIVID_CRC_POLYNOMIAL_ENABLES, &l_pTarget, attr_pm_spivid_crc_polynomial_enables_set); 
//      if (rc) { FAPI_ERR("fapiSetAttribute of ATTR_PM_SPIVID_CRC_POLYNOMIAL_ENABLES with rc = 0x%x", (uint32_t)rc);  return rc; }


// //         rc = FAPI_ATTR_SET(ATTR_FREQ_PB, &l_pTarget, attr_p8_nest_frequency_set); if (rc) return rc;
// //         rc = FAPI_ATTR_SET(ATTR_PM_SPIVID_FREQUENCY, &l_pTarget, attr_pm_spivid_frequency_set); if (rc) return rc;
 

//      	//---------------------------------------------------------- 
//  //     rc = FAPI_ATTR_SET(ATTR_PM_SPIVID_CLOCK_DIVIDER, &l_pTarget, attr_pm_spivid_clock_divider_set); 
// //      if (rc) { FAPI_ERR("fapiSetAttribute of ATTR_PM_SPIVID_CLOCK_DIVIDER with rc = 0x%x", (uint32_t)rc);  return rc; }


//      	//---------------------------------------------------------- 
// //      rc = FAPI_ATTR_SET(ATTR_PM_SPIVID_PORT_ENABLE, &l_pTarget, attr_pm_spivid_port_enable_set); 
// //      if (rc) { FAPI_ERR("fapiSetAttribute of ATTR_PM_SPIVID_PORT_ENABLE with rc = 0x%x", (uint32_t)rc);  return rc; }










    
    /// 	//---------------------------------------------------------- 
    /// rc = FAPI_ATTR_SET(ATTR_PM_PSTATE_STEPSIZE, &l_pTarget, attr_pm_pstate_stepsize_set); 
    /// if (rc) { FAPI_ERR("fapiSetAttribute of ATTR_PM_PSTATE_STEPSIZE with rc = 0x%x", (uint32_t)rc);  break; }

    /// 	//---------------------------------------------------------- 
    /// rc = FAPI_ATTR_SET(ATTR_PM_EXTERNAL_VRM_STEPDELAY_RANGE, &l_pTarget, attr_pm_external_vrm_stepdelay_range_set); 
    /// if (rc) { FAPI_ERR("fapiSetAttribute of ATTR_PM_EXTERNAL_VRM_STEPDELAY_RANGE with rc = 0x%x", (uint32_t)rc);  break; }

    /// 	//---------------------------------------------------------- 
    /// rc = FAPI_ATTR_SET(ATTR_PM_EXTERNAL_VRM_STEPDELAY_VALUE, &l_pTarget, attr_pm_external_vrm_stepdelay_value_set); 
    /// if (rc) { FAPI_ERR("fapiSetAttribute of ATTR_PM_EXTERNAL_VRM_STEPDELAY_VALUE with rc = 0x%x", (uint32_t)rc);  break; }

    /// 	//---------------------------------------------------------- 
    /// rc = FAPI_ATTR_SET(ATTR_PM_PMC_HANGPULSE_DIVIDER, &l_pTarget, attr_pm_pmc_hangpulse_divider_set); 
    /// if (rc) { FAPI_ERR("fapiSetAttribute of ATTR_PM_PMC_HANGPULSE_DIVIDER with rc = 0x%x", (uint32_t)rc);  break; }

    /// 	//---------------------------------------------------------- 
    /// rc = FAPI_ATTR_SET(ATTR_PM_PVSAFE_PSTATE, &l_pTarget, attr_pm_pvsafe_pstate_set); 
    /// if (rc) { FAPI_ERR("fapiSetAttribute of ATTR_PM_PVSAFE_PSTATE with rc = 0x%x", (uint32_t)rc);  break; }

    /// 	//---------------------------------------------------------- 
    /// rc = FAPI_ATTR_SET(ATTR_PM_PSTATE_UNDERVOLTING_MINIMUM, &l_pTarget, attr_pm_pstate_undervolting_minimum_set); 
    /// if (rc) { FAPI_ERR("fapiSetAttribute of ATTR_PM_PSTATE_UNDERVOLTING_MINIMUM with rc = 0x%x", (uint32_t)rc);  break; }

    /// 	//---------------------------------------------------------- 
    /// rc = FAPI_ATTR_SET(ATTR_PM_PSTATE_UNDERVOLTING_MAXIMUM, &l_pTarget, attr_pm_pstate_undervolting_maximum_set); 
    /// if (rc) { FAPI_ERR("fapiSetAttribute of ATTR_PM_PSTATE_UNDERVOLTING_MAXIMUM with rc = 0x%x", (uint32_t)rc);  break; }


//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_SET(ATTR_PM_OCC_HEARTBEAT_TIME, &l_pTarget, attr_pm_occ_heartbeat_time_set); 
//      if (rc) { FAPI_ERR("fapiSetAttribute of ATTR_PM_OCC_HEARTBEAT_TIME with rc = 0x%x", (uint32_t)rc);  break; }

// ------------------------------------------------------------------------------------------------------------------------------------------------

// Enable the get functions


//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_FRAME_SIZE, &l_pTarget, attr_pm_spivid_frame_size); 
//      if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_FRAME_SIZE with rc = 0x%x", (uint32_t)rc);  return rc; }
//      else { FAPI_INF (" value read from the attribute attr_pm_spivid_frame_size = 0x%x", attr_pm_spivid_frame_size );}

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_IN_DELAY_FRAME1, &l_pTarget, attr_pm_spivid_in_delay_frame1); 

//      if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_IN_DELAY_FRAME1 with rc = 0x%x", (uint32_t)rc);  return rc; }
//      else { FAPI_INF (" value read from the attribute attr_pm_spivid_in_delay_frame1 = 0x%x", attr_pm_spivid_in_delay_frame1);}

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_IN_DELAY_FRAME2, &l_pTarget, attr_pm_spivid_in_delay_frame2); 

//      if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_IN_DELAY_FRAME2 with rc = 0x%x", (uint32_t)rc);  return rc; }
//      else { FAPI_INF (" value read from the attribute attr_pm_spivid_in_delay_frame2 = 0x%x", attr_pm_spivid_in_delay_frame2);}

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_CLOCK_POLARITY, &l_pTarget, attr_pm_spivid_clock_polarity); 

//      if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_CLOCK_POLARITY with rc = 0x%x", (uint32_t)rc);  return rc; }
//      else { FAPI_INF (" value read from the attribute attr_pm_spivid_clock_polarity = 0x%x", attr_pm_spivid_clock_polarity);}

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_CLOCK_PHASE, &l_pTarget, attr_pm_spivid_clock_phase); 

//      if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_CLOCK_PHASE with rc = 0x%x", (uint32_t)rc);  return rc; }
//      else { FAPI_INF (" value read from the attribute attr_pm_spivid_clock_phase = 0x%x", attr_pm_spivid_clock_phase);}

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS, &l_pTarget, attr_pm_spivid_interframe_delay_write_status); 

//      if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS with rc = 0x%x", (uint32_t)rc);  return rc; }
//      else { FAPI_INF (" value read from the attribute attr_pm_spivid_interframe_delay_write_status = 0x%x", attr_pm_spivid_interframe_delay_write_status);}

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS_VALUE, &l_pTarget, attr_pm_spivid_interframe_delay_write_status_value); 

//      if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS_VALUE with rc = 0x%x", (uint32_t)rc);  return rc; }
//      else { FAPI_INF (" value read from the attribute attr_pm_spivid_interframe_delay_write_status_value = 0x%x", attr_pm_spivid_interframe_delay_write_status_value);}

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_INTER_RETRY_DELAY_VALUE, &l_pTarget, attr_pm_spivid_inter_retry_delay_value); 

//      if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_INTER_RETRY_DELAY_VALUE with rc = 0x%x", (uint32_t)rc);  return rc; }
//      else { FAPI_INF (" value read from the attribute attr_pm_spivid_inter_retry_delay_value = 0x%x", attr_pm_spivid_inter_retry_delay_value);}

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_INTER_RETRY_DELAY, &l_pTarget, attr_pm_spivid_inter_retry_delay); 

//      if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_INTER_RETRY_DELAY with rc = 0x%x", (uint32_t)rc);  return rc; }
//      else { FAPI_INF (" value read from the attribute attr_pm_spivid_inter_retry_delay = 0x%x", attr_pm_spivid_inter_retry_delay);}

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_CRC_GEN_ENABLE, &l_pTarget, attr_pm_spivid_crc_gen_enable); 

//      if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_CRC_GEN_ENABLE with rc = 0x%x", (uint32_t)rc);  return rc; }
//      else { FAPI_INF (" value read from the attribute attr_pm_spivid_crc_gen_enable = 0x%x", attr_pm_spivid_crc_gen_enable);}

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_CRC_CHECK_ENABLE, &l_pTarget, attr_pm_spivid_crc_check_enable); 

//      if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_CRC_CHECK_ENABLE with rc = 0x%x", (uint32_t)rc);  return rc; }
//      else { FAPI_INF (" value read from the attribute attr_pm_spivid_crc_check_enable = 0x%x", attr_pm_spivid_crc_check_enable);}

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_MAJORITY_VOTE_ENABLE, &l_pTarget, attr_pm_spivid_majority_vote_enable); 

//      if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_MAJORITY_VOTE_ENABLE with rc = 0x%x", (uint32_t)rc);  return rc; }
//      else { FAPI_INF (" value read from the attribute attr_pm_spivid_majority_vote_enable = 0x%x", attr_pm_spivid_majority_vote_enable);}

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_MAX_RETRIES, &l_pTarget, attr_pm_spivid_max_retries); 

//      if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_MAX_RETRIES with rc = 0x%x", (uint32_t)rc);  return rc; }
//      else { FAPI_INF (" value read from the attribute attr_pm_spivid_max_retries = 0x%x", attr_pm_spivid_max_retries);}

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_CRC_POLYNOMIAL_ENABLES, &l_pTarget, attr_pm_spivid_crc_polynomial_enables); 

//      if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_CRC_POLYNOMIAL_ENABLES with rc = 0x%x", (uint32_t)rc);  return rc; }
//      else { FAPI_INF (" value read from the attribute attr_pm_spivid_crc_polynomial_enables = 0x%x", attr_pm_spivid_crc_polynomial_enables);}


//      	//---------------------------------------------------------- 
//       rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_CLOCK_DIVIDER, &l_pTarget, attr_pm_spivid_clock_divider); 

//       if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_CLOCK_DIVIDER with rc = 0x%x", (uint32_t)rc);  return rc; }
//       else { FAPI_INF (" value read from the attribute attr_pm_spivid_clock_divider = 0x%x", attr_pm_spivid_clock_divider);}


//      	//---------------------------------------------------------- 
//       rc = FAPI_ATTR_GET(ATTR_PM_SPIVID_PORT_ENABLE, &l_pTarget, attr_pm_spivid_port_enable); 

//       if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_PORT_ENABLE with rc = 0x%x", (uint32_t)rc);  return rc; }
//      else { FAPI_INF (" value read from the attribute attr_pm_spivid_port_enable = 0x%x", attr_pm_spivid_port_enable);}


//      	//---------------------------------------------------------- 





    
    //--------------------------------------------------------------------
    //- >>> SCOM.INITFILE elements 
    //--------------------------------------------------------------------
