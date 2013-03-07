/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_oha_init.C $           */
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
// $Id: p8_oha_init.C,v 1.3 2012/10/04 10:23:00 rmaier Exp $
// $Source: /afs/awd.austin.ibm.com/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_oha_init.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Ralf Maier         Email: ralf.maier@de.ibm.com
// *!
// *! General Description:
// *!        
// *!    The purpose of this procedure is to do a initial setup of OHA
// *!
// *! Procedure Prereq:
// *!   o completed istep procedure
// *!
//------------------------------------------------------------------------------
/// \file p8_oha_init.C
/// \brief Setup OHA ( AISS_HANG_DETECT_TIMER,  Power Proxy Trace Timer and Low Activity detect range)
///
///
///
///
/// \version
/// \version --------------------------------------------------------------------------
/// \version 1.3  rmaier 10/04/12 Replacing genHex*Str function
/// \version --------------------------------------------------------------------------
/// \version 1.1  rmaier 08/23/12 Renaming proc_ to p8_
/// \version --------------------------------------------------------------------------
/// \version 1.13 rmaier 08/02/12 Included review feedback Set 6
/// \version --------------------------------------------------------------------------
/// \version 1.12 rmaier 07/17/12 Included review feedback Set 5
/// \version --------------------------------------------------------------------------
/// \version 1.11 rmaier 07/17/12 Included review feedback Set 4
/// \version --------------------------------------------------------------------------
/// \version 1.10 rmaier 07/13/12 Included new review feedback
/// \version --------------------------------------------------------------------------
/// \version 1.9 rmaier 05/24/12 Included review feedback
/// \version --------------------------------------------------------------------------
/// \version 1.8 rmaier 05/15/12 Changed Error return code handling for SCOM access
/// \version --------------------------------------------------------------------------
/// \version 1.7 rmaier 05/09/12 Removed global variables
/// \version --------------------------------------------------------------------------
/// \version 1.6 rmaier 04/24/12 Updated Config-mode
/// \version --------------------------------------------------------------------------
/// \version 1.5 rmaier 03/20/12 Added AISS-reset
/// \version --------------------------------------------------------------------------
/// \version 1.4 rmaier 03/13/12 Added modes-structure
/// \version --------------------------------------------------------------------------
/// \version 1.0 rmaier 12/01/11 Initial Version 
/// \version ---------------------------------------------------------------------------
///
///
///
///
///
///
///
///
/// High-level procedure flow:
///
/// \verbatim
///
///  Procedure Prereq:
///  - completed istep procedure
///
///
///  loop over all valid chiplets {
///
///    Setup aiss hang time  in oha_mode_reg
///      set aiss_timeout to max              --  oha_mode_reg (11:14) ,            ADR 1002000D (SCOM)
///                                          --  9 => longest time  512 ms
///    Setup low activity  in oha_low_activity_detect_mode_reg
///                                          -- oha_low_activity_detect_mode_reg,   ADR 10020003 (SCOM)
/// \todo  when should we enable the low activity detection or just setup the ranges??
///      set lad_enable = 1??
///      set lad_entry = 16                  -- bit index of a 24 bit counter based on base counter  0: longest, 23: shortest interval
///      set lad_exit  = 17                  -- bit index of a 24 bit counter based on base counter  0: longest, 23: shortest interval
///
///
///    Setup Power Proxy Trace  in activity_sample_mode_reg
///      set  ppt_int_timer_select           -- activity_sample_mode_reg (36:37)    ADR 10020000 (SCOM)
///                                          -- select precounter for ppt timer ( 0=0.25us, 1=0.5us, 2=1us, 3=2us )
///
///     if PM_CONFIG {
///  
///                                            convert_ppt_time() - Convert Power Proxy Trace Time to Power Proxy Trace Time Select and Match feature attributes 
///                                            With ATTR_PM_POWER_PROXY_TRACE_TIMER (binary in nanoseconds) to produce  ATTR_PM_PPT_TIMER_MATCH_VALUE and ATTR_PM_PPT_TIMER_TICK
///                                             0=0.25us , 1=0.5us, 2=1us, and 3=2us
///
///     else if PM_INIT {
///    
///             Timer settings if not able to be done in the init file
///             - PPT timer
///             - AISS hang timer 
///
///     } else if PM_RESET {
///
///             AISS reset 
///
///       }   //end PM_RESET -mode
///
///

///  \endverbatim
///
//------------------------------------------------------------------------------
//----------------------------------------------------------------------
//  eCMD Includes
//----------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <fapi.H>
#include "p8_pm.H"
#include "p8_scom_addresses.H"
#include "p8_oha_init.H"




extern "C" {
 


using namespace fapi;

 //------------------------------------------------------------------------------
 //Start scan zero value
 //------------------------------------------------------------------------------



// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------


typedef struct {
  int8_t   AISS_HANG_DETECT_TIMER_SEL;     //  oha_mode_reg (11:14) - 0=1ms, 1=2ms, 3=4ms, ...9=512ms. others illegal
  int8_t   PPT_TIMER_SELECT;               //  activity_sample_mode_reg (36:37) 0=0.25us, 1=0.5us, 2=1us, and 3=2us
  int8_t   LAD_ENTRY;
  int8_t   LAD_EXIT;
} struct_i_oha_val_init_type;


// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

// Reset function   
fapi::ReturnCode p8_oha_init_reset    (const Target  &i_target, uint32_t i_mode);
// Config function
fapi::ReturnCode p8_oha_init_config   (const fapi::Target&  i_target) ;
// INIT 
fapi::ReturnCode  p8_oha_init_init    (const fapi::Target& i_target, struct_i_oha_val_init_type i_oha_val_init) ; 


// ----------------------------------------------------------------------
// p8_oha_init wrapper to fetch the attributes and pass it on to p8_oha_init_core
// ----------------------------------------------------------------------

fapi::ReturnCode
p8_oha_init(const fapi::Target &i_target, uint32_t i_mode)
{
  fapi::ReturnCode rc;


  
  
  
  if ( i_mode == PM_CONFIG ) {

    FAPI_DBG("*************************************");
    FAPI_INF("MODE:  CONFIG , Calling: p8_oha_init_config");
    FAPI_DBG("*************************************");
    rc=p8_oha_init_config(i_target);

    if (rc) {
        FAPI_ERR(" p8_oha_init_config failed. With rc = 0x%x", (uint32_t)rc); return rc;  
    }                      
    
  } else if ( i_mode == PM_INIT )  { 

    
    FAPI_DBG("*************************************");
    FAPI_INF("MODE:  INIT , Calling: p8_oha_init_init");
    FAPI_DBG("*************************************");
    
    //  ******************************************************************
    /// \todo   should this values be attributes?? The get those attributes here
    //#ifndef ATTRIBUTES_AVAIL
    
          //Declare parms struct 
          struct_i_oha_val_init_type i_oha_val_init;
          
          //Assign values to parms in struct
          // should come from MRWB
          i_oha_val_init.AISS_HANG_DETECT_TIMER_SEL = 9;  //  oha_mode_reg (11:14) - 0=1ms, 1=2ms, 3=4ms, ...9=512ms. others illegal
          i_oha_val_init.PPT_TIMER_SELECT = 3;            //  activity_sample_mode_reg (36:37) 0=0.25us, 1=0.5us, 2=1us, and 3=2us
          i_oha_val_init.LAD_ENTRY = 16;
          i_oha_val_init.LAD_EXIT = 17;
      
       
    //#else
    //      FAPI_ATTR_GET("IVRMS_ENABLED", i_target,(unit8_t) ivrms_enabled);         //VENICE or SALERNO
    
    //#endif
    
    //  ******************************************************************
    
    
    
    rc=p8_oha_init_init(i_target,  i_oha_val_init);
    
    if (rc) {
        FAPI_ERR(" p8_oha_init_init failed. With rc = 0x%x", (uint32_t)rc); return rc;  
    }            
    
    
  } else if ( i_mode == PM_RESET )  {
    FAPI_DBG("*************************************");
    FAPI_INF("MODE:  RESET");
    FAPI_DBG("*************************************");
        
  
 
 
              //Declare parms struct 
              struct_i_oha_val_init_type i_oha_val_init;
              
              //Assign values to parms in struct
              // should come from MRWB
              i_oha_val_init.AISS_HANG_DETECT_TIMER_SEL = 9;  //  oha_mode_reg (11:14) - 0=1ms, 1=2ms, 3=4ms, ...9=512ms. others illegal
              i_oha_val_init.PPT_TIMER_SELECT = 3;            //  activity_sample_mode_reg (36:37) 0=0.25us, 1=0.5us, 2=1us, and 3=2us
              i_oha_val_init.LAD_ENTRY = 16;
              i_oha_val_init.LAD_EXIT = 17;
              
              //  ******************************************************************
              /// \todo   should this values be attributes?? The get those attributes here
              
              #ifndef ATTRIBUTES_AVAIL
              
              
              #else
              //      FAPI_ATTR_GET("IVRMS_ENABLED", i_target,(unit8_t) ivrms_enabled);         //VENICE or SALERNO
              
              #endif
              
              //  ******************************************************************
              
 
 
 
    //FAPI_DBG("*************************************");
    FAPI_INF("Calling: p8_oha_init_reset");
    //FAPI_DBG("*************************************");
    rc = p8_oha_init_reset( i_target, i_mode); 
    
    if (rc) {
      FAPI_ERR(" p8_oha_init_reset failed. With rc = 0x%x", (uint32_t)rc); return rc;  
    }            
    
  } else {
    //FAPI_DBG("*************************************");
    FAPI_ERR("Unknown mode passed to p8_oha_init. Mode %x ....\n", i_mode);
    FAPI_SET_HWP_ERROR(rc, RC_PROC_OHA_CODE_BAD_MODE);
    //FAPI_DBG("*************************************");
  }; 
  
  
 
  return rc; 
  
}  



fapi::ReturnCode
p8_oha_init_config(const fapi::Target& i_target) 
{
  fapi::ReturnCode rc;
  
    uint8_t  attr_pm_aiss_timeout;
    uint32_t attr_pm_power_proxy_trace_timer;
    uint32_t attr_pm_ppt_timer_tick;
    uint32_t attr_pm_ppt_timer_match_value;
    
        
        //  ******************************************************************
        //  Get Attributes for OHA Timers Delay      
        //  ******************************************************************     
        //  set defaults  if not available        

               attr_pm_ppt_timer_tick           = 2;           // Default 2: 1us

        
        
        /// \todo PLAT attr ... not there yet
                 attr_pm_aiss_timeout             = 5;           // Default 5: 32ms        
        //               rc = FAPI_ATTR_GET(ATTR_PM_AISS_TIMEOUT, &i_target, attr_pm_aiss_timeout); 
        //               if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_AISS_TIMEOUT with rc = 0x%x", (uint32_t)rc);  return rc; }
        //               

        /// \todo PLAT attr ... not there yet
                 attr_pm_power_proxy_trace_timer  = 64000;       // Default 1us,,, 32us...64ms
        //               rc = FAPI_ATTR_GET(ATTR_PM_POWER_PROXY_TRACE_TIMER, &i_target, attr_pm_power_proxy_trace_timer); 
        //               if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_POWER_PROXY_TRACE_TIMER with rc = 0x%x", (uint32_t)rc);  return rc; }

             
        
        
        //  ******************************************************************
        //  Calculate OHA timer settings      
        //  ******************************************************************            
        //FAPI_DBG("*************************************");
        FAPI_DBG("Calculate OHA timer settings");
        //FAPI_DBG("*************************************");  
        //FAPI_DBG("*************************************");
        FAPI_DBG("Calculate:");
        FAPI_DBG("        ATTR_PM_PPT_TIMER_MATCH_VALUE");
        FAPI_DBG("        ATTR_PM_PPT_TIMER_TICK");
        FAPI_DBG("using:");
        FAPI_DBG("        ATTR_PM_POWER_PROXY_TRACE_TIMER");
        //FAPI_DBG("**************************************************************************");          
        FAPI_DBG("        Set  ATTR_PM_AISS_TIMEOUT   to 5 (32ms)");
        //FAPI_DBG("**************************************************************************");        
        
        
        
        
        //
        attr_pm_ppt_timer_match_value  = attr_pm_power_proxy_trace_timer / 32  ;    //time in us / 32us 
               
           
                
             
        
          FAPI_DBG("*************************************");
          FAPI_DBG("attr_pm_aiss_timeout                    :  %X", attr_pm_aiss_timeout);
          FAPI_DBG("attr_pm_ppt_timer_match_value           :  %X", attr_pm_ppt_timer_match_value);         
          FAPI_DBG("*************************************");
          

        //  ******************************************************************
        //  Set Attributes for OHA timers      
        //  ******************************************************************                  
       
        //     rc = FAPI_ATTR_SET(ATTR_PM_AISS_TIMEOUT, &i_target, attr_pm_aiss_timeout); 
        //     if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_AISS_TIMEOUT with rc = 0x%x", (uint32_t)rc);  return; }
      
            rc = FAPI_ATTR_SET(ATTR_PM_PPT_TIMER_MATCH_VALUE, &i_target, attr_pm_ppt_timer_match_value); 
            if (rc) { FAPI_ERR("fapiSetAttribute of ATTR_PM_PPT_TIMER_MATCH_VALUE with rc = 0x%x", (uint32_t)rc);  return rc; }
            rc = FAPI_ATTR_SET(ATTR_PM_PPT_TIMER_TICK, &i_target, attr_pm_ppt_timer_tick); 
            if (rc) { FAPI_ERR("fapiSetAttribute of ATTR_PM_PPT_TIMER_TICK with rc = 0x%x", (uint32_t)rc);  return rc; }
       
  
 
  return rc;
  
}  //end CONFIG






fapi::ReturnCode
p8_oha_init_init(const fapi::Target& i_target, struct_i_oha_val_init_type i_oha_val_init) 
{
    fapi::ReturnCode rc;
 
    ecmdDataBufferBase data(64);
    ecmdDataBufferBase mask(64);
    
    std::vector<fapi::Target>      l_chiplets;
    std::vector<Target>::iterator  itr;
    
    
    // Variables
//TODO RTC: 68461 - refresh procedures uint32_t c  = 0 ;
    uint32_t l_rc;

    
    uint8_t  attr_pm_aiss_timeout;
    uint32_t attr_pm_ppt_timer_tick;
    uint32_t attr_pm_ppt_timer_match_value;
    
    FAPI_INF("");
    //FAPI_DBG("********* ******************* *********");
    FAPI_INF("Executing  ....p8_oha_init");
    //FAPI_DBG("********* ******************* *********");
    FAPI_INF("");
    
    
      
    
    rc = fapiGetChildChiplets (i_target, TARGET_TYPE_EX_CHIPLET, l_chiplets); if (rc) return rc;
    FAPI_DBG("  chiplet vector size          => %u", l_chiplets.size());
    
   
    
    
    //FAPI_DBG("***********************************************");
    FAPI_INF(" Welcome to p8_oha_init INIT-mode ");
    //FAPI_DBG("***********************************************");
    
   
    
    //  ******************************************************************
    //  Get Attributes for OHA Timers Delay      
    //  ******************************************************************     
     #ifndef ATTRIBUTES_AVAIL       
         //  ******************************************************************
         //  set defaults  if not available        
         attr_pm_ppt_timer_tick           = 2;           // Default 2: 1us
         attr_pm_ppt_timer_match_value    = 0x7FF;       // Default 0x7FF: 64ms
         attr_pm_aiss_timeout             = 5;           // Default 5: 32ms       
     #else    
/// \todo PLAT attr ... not there yet
        //rc = FAPI_ATTR_GET(ATTR_PM_AISS_TIMEOUT, &i_target, attr_pm_aiss_timeout); 
        //if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_AISS_TIMEOUT with rc = 0x%x", (uint32_t)rc);  return rc; }     
        rc = FAPI_ATTR_GET(ATTR_PM_PPT_TIMER_TICK, &i_target, attr_pm_ppt_timer_tick); 
        if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_PPT_TIMER_TICK with rc = 0x%x", (uint32_t)rc);  return rc; }
        rc = FAPI_ATTR_GET(ATTR_PM_PPT_TIMER_MATCH_VALUE, &i_target, attr_pm_ppt_timer_match_value); 
        if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_PPT_TIMER_MATCH_VALUE with rc = 0x%x", (uint32_t)rc);  return rc; }
    #endif    
    
    
    
    //  ******************************************************************
    //  initialize all oha_reg with scan-zero values upfront
    //  ******************************************************************
    
 
    
    for (itr = l_chiplets.begin(); itr != l_chiplets.end(); itr++){
      
              
              FAPI_DBG("Content Loop Variable C : %d ", c);
              
            
              
              //  ******************************************************************
              //  AISS hang timer setup
              //  ******************************************************************
              //  ******************************************************************
              
              //  - set aiss_timeout to max time
              //  ******************************************************************
              //FAPI_DBG("**********************************************");
              FAPI_INF(" Setup aiss hang time in oha_mode_reg 1002000D");
              //FAPI_DBG("**********************************************");
              
              // Read register content
              rc = fapiGetScom( (*itr), EX_OHA_MODE_REG_RWx1002000D , data );
              if (rc) {FAPI_ERR("fapiGetScom(EX_OHA_MODE_REG) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }
              
              FAPI_DBG ("Content of EX_OHA_MODE_REG_0x1002000D  :  %016llX", data.getDoubleWord(0));

              
                            
             
              //data.flushTo0();
              l_rc = data.insertFromRight(attr_pm_aiss_timeout    ,11,4);              
              if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
              
              rc = fapiPutScom( (*itr), EX_OHA_MODE_REG_RWx1002000D , data );
              if (rc) {
                FAPI_ERR("fapiPutScom(EX_OHA_MODE_REG) failed. With rc = 0x%x", (uint32_t)rc); return rc;  
              }              
                         
              
              
              
              //  ******************************************************************
              //  Low Activity Detect (LAD) setup
              //  ******************************************************************
              //  ******************************************************************
              //  - enable LAD
              //  - set LAD for entry
              //  - set LAD for exit
              //  ******************************************************************
              //FAPI_DBG("**********************************************************************************************");
              FAPI_INF(" Setup Low Activity Detect (LAD) in oha_low_activity_detect_mode_reg 10020003, but NOT ENABLED");
              //FAPI_DBG("**********************************************************************************************");
              
              // Read register content
              //if (VERBOSE) {
                rc = fapiGetScom( (*itr), EX_OHA_LOW_ACTIVITY_DETECT_MODE_REG_RWx10020003 , data );
                if (rc) { FAPI_ERR("fapiGetScom(EX_OHA_LOW_ACTIVITY_DETECT_MODE_REG_RWx10020003) failed. With rc = 0x%x", (uint32_t)rc);  return rc;     }
                FAPI_DBG(" Pre write content of EX_OHA_LOW_ACTIVITY_DETECT_MODE_REG_RWx10020003  :  %016llX", data.getDoubleWord(0));
              //}
              
              //
              l_rc = data.setByte(0, i_oha_val_init.LAD_ENTRY);   // 16             
              l_rc |= data.setByte(1, i_oha_val_init.LAD_EXIT);    // 17
              l_rc |= data.shiftRight(1);                         // LAD entry/exit starts at bit 1              
              l_rc |= data.clearBit(0);
              if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
              //FAPI_DBG(" !!!!!!!!!!!!!!!!!!!!!!returncode   :  %d", rc);
              
              
              
              
              
              rc = fapiPutScom((*itr), EX_OHA_LOW_ACTIVITY_DETECT_MODE_REG_RWx10020003 , data );
              if (rc) {
                FAPI_ERR("fapiGetScom(EX_OHA_LOW_ACTIVITY_DETECT_MODE_REG) failed. With rc = 0x%x", (uint32_t)rc);  return rc;  
              }
              
              // if debug mode read back
              //if (VERBOSE) {
              //  rc = fapiGetScom((*itr), EX_OHA_LOW_ACTIVITY_DETECT_MODE_REG_RWx10020003, data); if (rc) return rc;
              //  FAPI_DBG(" Post write content of EX_OHA_LOW_ACTIVITY_DETECT_MODE_REG_RWx10020003  :  %016llX", data.getDoubleWord(0));
              //}
              FAPI_INF ("Done LAD setup. LAD Disabled " );
              
              
              
              //  ******************************************************************
              //  Power Proxy Trace (PPT) setup
              //  ******************************************************************
              //  ******************************************************************
              //  - set ppt_timer_select
              //  - set ppt_trace_timer_match_val
              //  ******************************************************************
              //FAPI_DBG("********************************************************************************");
              FAPI_INF(" Setup  Power Proxy Trace (PPT) in oha_activity_sample_mode_reg 10020000");
              //FAPI_DBG("********************************************************************************");
              
              // Read register content            
              rc = fapiGetScom( (*itr), EX_OHA_ACTIVITY_SAMPLE_MODE_REG_RWx10020000 , data );
              if (rc) {
                FAPI_ERR("fapiGetScom(EX_OHA_ACTIVITY_SAMPLE_MODE_REG) failed. With rc = 0x%x", (uint32_t)rc);  return rc;  
              }
              FAPI_DBG(" Pre write content of EX_OHA_ACTIVITY_SAMPLE_MODE_REG_RWx10020000  :  %016llX", data.getDoubleWord(0));
             
              
              // set ppt_int_timer_select to longest interval "11" = 2us 
              //l_rc = data.setBit(36);
              //if (l_rc) { FAPI_ERR("Bit operation failed.");  FAPI_SET_HWP_ERROR(rc, RC_PROC_OHA_CODE_BITOP_FAILED);       }              
              //l_rc = data.setBit(37);
              //if (l_rc) { FAPI_ERR("Bit operation failed.");  FAPI_SET_HWP_ERROR(rc, RC_PROC_OHA_CODE_BITOP_FAILED);       }              
              
              l_rc = data.insertFromRight(attr_pm_ppt_timer_match_value    ,24,11);                                      
              l_rc |= data.insertFromRight(attr_pm_ppt_timer_tick           ,36,2);             
              if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
              
              
              
              rc = fapiPutScom((*itr), EX_OHA_ACTIVITY_SAMPLE_MODE_REG_RWx10020000 , data );
              if (rc) {
                FAPI_ERR("fapiGetScom(EX_OHA_ACTIVITY_SAMPLE_MODE_REG) failed. With rc = 0x%x", (uint32_t)rc);  return rc;  
              }
              
              // if debug mode read back
              //if (VERBOSE) {
                rc = fapiGetScom((*itr), EX_OHA_ACTIVITY_SAMPLE_MODE_REG_RWx10020000, data); if (rc) return rc;
                FAPI_DBG(" Post write content of EX_OHA_ACTIVITY_SAMPLE_MODE_REG_RWx10020000  :  %016llX", data.getDoubleWord(0));
              //}
              FAPI_INF ("Done PPT timer setup." );
    }
  
    
    
    return rc;
  
}  //end INIT




ReturnCode
p8_oha_init_reset(const Target &i_target,  uint32_t i_mode)
{
    ReturnCode rc;

//std::string PROCEDURE = "p8_oha_init";            // procedure name
//std::string REVISION  = "$Revision: 1.3 $";        // procedure CVS revision


    ecmdDataBufferBase data(64);
    ecmdDataBufferBase mask(64);

    std::vector<fapi::Target>      l_chiplets;
    std::vector<Target>::iterator  itr;


    // Variables
//TODO RTC: 68461 - refresh procedures  uint32_t c  = 0 ;
    uint32_t l_rc;
    
   FAPI_DBG("");
   //FAPI_DBG("********* ******************* *********");
   FAPI_INF("Executing p8_oha_init...");
   //FAPI_DBG("********* ******************* *********");
   FAPI_DBG("");






    // rc = fapiGetExistingChiplets (i_target, TARGET_TYPE_EX_CHIPLET, l_chiplets); if (rc) return rc;
    rc = fapiGetChildChiplets (i_target, TARGET_TYPE_EX_CHIPLET, l_chiplets); if (rc) return rc;
    FAPI_DBG("  chiplet vector size          => %u", l_chiplets.size());

  


 

              //FAPI_DBG("***********************************************");
              FAPI_INF(" Welcome to p8_oha_init_reset ");
              //FAPI_DBG("***********************************************");


for (itr = l_chiplets.begin(); itr != l_chiplets.end(); itr++){


              FAPI_DBG("Content Loop Variable C : %d ", c);

              
              
              
              
              //FAPI_DBG("*************************************");
              FAPI_INF("Reset AISS  ");
              FAPI_INF("Write to register OHA_ARCH_IDLE_STATE_REG  ");
              //FAPI_DBG("*************************************");
              
              
             
              rc = fapiGetScom( (*itr), EX_OHA_ARCH_IDLE_STATE_REG_RWx10020011, data); 
              if (rc) {
                FAPI_ERR("fapiGetScom(EX_OHA_ARCH_IDLE_STATE_REG) failed. With rc = 0x%x", (uint32_t)rc);  return rc;  
              }
              FAPI_DBG(" Pre write content of EX_OHA_ARCH_IDLE_STATE_REG_RWx10020011 :  %016llX",  data.getDoubleWord(0) );                
                                               
              l_rc = data.setBit(9);   //reset_idle_state_sequencer_in ... reset pulse gets generated. Not unsetting required
              if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
              
              rc = fapiPutScom((*itr), EX_OHA_ARCH_IDLE_STATE_REG_RWx10020011 , data );
              if (rc) {
                FAPI_ERR("fapiPutScom(EX_OHA_ARCH_IDLE_STATE_REG) failed. With rc = 0x%x", (uint32_t)rc);  return rc;  
              }
              
              // if debug mode read back
              //if (VERBOSE) {
                rc = fapiGetScom( (*itr), EX_OHA_ARCH_IDLE_STATE_REG_RWx10020011, data); if (rc) return rc;
                FAPI_DBG(" Post write content of EX_OHA_ARCH_IDLE_STATE_REG_RWx10020011 :  %016llX",  data.getDoubleWord(0) );        
              //}
              if (rc) {
                FAPI_ERR("fapiGetScom(EX_OHA_ARCH_IDLE_STATE_REG) failed. With rc = 0x%x", (uint32_t)rc);  return rc;  
              }             
  
  




}
              
   

   FAPI_INF("");
   FAPI_INF("Executing proc_OHA_init  ....\n");


  return rc;
}









} //end extern C
 
