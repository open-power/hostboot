/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pss_init.C $           */
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
// $Id: p8_pss_init.C,v 1.2 2012/08/24 10:18:50 pchatnah Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pss_init.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE : p8_pss_init.C
// *! DESCRIPTION : Initializes P2S and HWC logic
// *! OWNER NAME  : Pradeep CN   Email: padeepcn@in.ibm.com
// *! BACKUP NAME :              Email:                      
// #! ADDITIONAL COMMENTS :
//
// 
///Procedure Summary:
//--------------------
///    One procedure to initialize both P2S and HWC SPIPSS registers to

///    second Procedure is to access APSS or DPSS through P2S Bridge
///    Third procedure is to access APSS or DPSS through HWC (hardware control)
//                     
// *!   High-level procedure flow:
//----------------------------------
/// *!     o INIT PROCEDURE(frame_size,cpol,cpha)
/// *!		- set SPIPSS_ADC_CTRL_REG0(24b) 
/// *!			hwctrl_frame_size = 16
/// *!		- set SPIPSS_ADC_CTRL_REG1
/// *!			hwctrl_fsm_enable = disable
/// *!			hwctrl_device     = APSS
/// *!			hwctrl_cpol       = 0 (set idle state = deasserted)
/// *!			hwctrl_cpha       = 0 (set 1st edge = capture 2nd edge = change)
/// *!			hwctrl_clock_divider = set to 10Mhz(0x1D)
/// *!			hwctrl_nr_of_frames (4b) = 16 (for auto 2 mode)
/// *!		- set SPIPSS_ADC_CTRL_REG2
/// *!                     hwctrl_interframe_delay = 0x0
/// *!             - clear SPIPSS_ADC_WDATA_REG

/// *!		- set SPIPSS_P2S_CTRL_REG0 (24b)
/// *!			p2s_frame_size  = 16
/// *!		- set SPIPSS_P2S_CTRL_REG1
/// *!			p2s_bridge_enable = disable
/// *!			p2s_device        = DPSS
/// *!			p2s_cpol          = 0
/// *!			p2s_cpha          = 0
/// *!			p2s_clock_divider = set to 10Mhz
/// *!			p2s_nr_of_frames (1b) = 0 (means 1 frame operation)
/// *!		- set SPIPSS_P2S_CTRL_REG2
/// *!                     p2s_interframe_delay = 0x0
/// *!             - clear SPIPSS_P2S_WDATA_REG
///
///
/// *!
/// *! Procedure Prereq:
/// *!   o System clocks are running
/// *!
///------------------------------------------------------------------------------
  
  
// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------

#include "p8_pm.H"
#include "p8_scom_addresses.H"

// #ifdef FAPIECMD
 extern "C" {
// #endif 


  using namespace fapi;



// ----------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------



 






// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------




// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

// // Transform Platform Attribute for SPI PSS to Feature Attributes
// fapi::ReturnCode
// pss_create_spi_settings(const Target& l_pTarget) 
// {
//     fapi::ReturnCode rc;
    



 






//     return rc ;
// }





fapi::ReturnCode
pss_config_spi_settings(const Target& l_pTarget) 
{
    fapi::ReturnCode rc;
    
    uint32_t attr_proc_pss_init_nest_frequency=2400; 
    uint32_t attr_pm_pss_init_spipss_frequency=10;
    uint8_t attr_pm_spipss_clock_divider ;







    
    rc = FAPI_ATTR_GET(ATTR_FREQ_PB, NULL , attr_proc_pss_init_nest_frequency); if (rc) return rc;
    //TODO RTC: 68461 - refresh procedures - hacked target in the line below to be NULL
    rc = FAPI_ATTR_GET(ATTR_PM_SPIPSS_FREQUENCY, NULL,attr_pm_pss_init_spipss_frequency); if (rc) return rc ;
    
  

    // calculation of clock divider
    attr_pm_spipss_clock_divider = ((attr_proc_pss_init_nest_frequency/attr_pm_pss_init_spipss_frequency)/8 )-1 ;   
    //    printf ("clk_dive = %d ",attr_pm_spipss_clock_divider);
    
    rc = FAPI_ATTR_SET(ATTR_PM_SPIPSS_CLOCK_DIVIDER, &l_pTarget, attr_pm_spipss_clock_divider); if (rc) return rc;
    

    return rc;
}

// function: xxx
// parameters: none
// returns: ECMD_SUCCESS if something good happens,
//          BAD_RETURN_CODE otherwise

fapi::ReturnCode
p8_pss_init(Target &i_target, uint32_t mode)
{
    fapi::ReturnCode rc;

    uint32_t attr_proc_pss_init_nest_frequency=2400; 
    //    uint32_t attr_pm_pss_init_spipss_frequency=10;
    uint8_t attr_pm_spipss_clock_divider ;


    uint8_t	 attr_pm_apss_chip_select=1 ;
    uint8_t	 attr_pm_spipss_frame_size ;
    // uint8_t  attr_pm_spipss_out_count ;
    // uint8_t	 attr_pm_spipss_in_delay ;
    // uint8_t	 attr_pm_spipss_in_count ;
    uint8_t	 attr_pm_spipss_clock_polarity ;
    uint8_t	 attr_pm_spipss_clock_phase ;

    uint32_t attr_pm_spipss_inter_frame_delay ;
    //      attr_pm_spipss_inter_frame_delay_setting ;
    uint32_t            e_rc = 0;
    uint32_t            pollcount=0;
    uint32_t            max_polls = 255;




    //  size_t i;

    //i = args.size();
    ecmdDataBufferBase data(64);
    ecmdDataBufferBase mask(64);

    /// -------------------------------
    /// Configuration:  perform translation of any Platform Attributes into Feature Attributes
    /// that are applied during Initalization
    if (mode == PM_CONFIG) 
    {

      FAPI_INF("PSS configuration..");

       rc=pss_config_spi_settings(i_target);

    } 
  
    /// -------------------------------
    /// Initialization:  perform order or dynamic operations to initialize 
    /// the PMC using necessary Platform or Feature attributes. 
    else if (mode == PM_INIT) 
    {
    

      FAPI_INF("PSS initialisation...");
      //       rc=pss_create_spi_settings(i_target);


//       rc = FAPI_ATTR_GET(ATTR_PM_SPIPSS_OUT_COUNT, &i_target, attr_pm_spipss_out_count);  if (rc) return rc; 
//       rc = FAPI_ATTR_GET(ATTR_PM_SPIPSS_IN_COUNT, &i_target, attr_pm_spipss_in_count);  if (rc) return rc; 

     	//---------------------------------------------------------- 
     rc = FAPI_ATTR_GET(ATTR_PM_SPIPSS_FRAME_SIZE, &i_target, attr_pm_spipss_frame_size); 
     if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIPSS_FRAME_SIZE with rc = 0x%x", (uint32_t)rc);  return rc; }
     else { FAPI_INF (" value read from the attribute attr_pm_spipss_frame_size = 0x%x", attr_pm_spipss_frame_size );}

     	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_GET(ATTR_PM_SPIPSS_IN_DELAY, &i_target, attr_pm_spipss_in_delay); 

//      if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIPSS_IN_DELAY with rc = 0x%x", (uint32_t)rc);  return rc; }
//      else { FAPI_INF (" value read from the attribute attr_pm_spipss_in_delay_frame1 = 0x%x", attr_pm_spipss_in_delay);}

     	//---------------------------------------------------------- 
     rc = FAPI_ATTR_GET(ATTR_PM_SPIPSS_CLOCK_POLARITY, &i_target, attr_pm_spipss_clock_polarity); 

     if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIPSS_CLOCK_POLARITY with rc = 0x%x", (uint32_t)rc);  return rc; }
     else { FAPI_INF (" value read from the attribute attr_pm_spipss_clock_polarity = 0x%x", attr_pm_spipss_clock_polarity);}

     	//---------------------------------------------------------- 
     rc = FAPI_ATTR_GET(ATTR_PM_SPIPSS_CLOCK_PHASE, &i_target, attr_pm_spipss_clock_phase); 

     if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIPSS_CLOCK_PHASE with rc = 0x%x", (uint32_t)rc);  return rc; }
     else { FAPI_INF (" value read from the attribute attr_pm_spipss_clock_phase = 0x%x", attr_pm_spipss_clock_phase);}

     	//---------------------------------------------------------- 
     rc = FAPI_ATTR_GET(ATTR_PM_SPIPSS_INTER_FRAME_DELAY, &i_target, attr_pm_spipss_inter_frame_delay); 

     if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIPSS_INTER_FRAME_DELAY with rc = 0x%x", (uint32_t)rc);  return rc; }
     else { FAPI_INF (" value read from the attribute attr_pm_spipss_interframe_delay = 0x%x", attr_pm_spipss_inter_frame_delay);}


    	//---------------------------------------------------------- 
      rc = FAPI_ATTR_GET(ATTR_PM_APSS_CHIP_SELECT, &i_target, attr_pm_apss_chip_select); 

      if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_APSS_CHIP_SELECT with rc = 0x%x", (uint32_t)rc);  return rc; }
      else { FAPI_INF (" value read from the attribute attr_pm_apss_chip_select = 0x%x", attr_pm_apss_chip_select);}

     	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_GET(ATTR_PM_SPIPSS_INTERFRAME_DELAY_WRITE_STATUS_VALUE, &i_target, attr_pm_spipss_interframe_delay_write_status_value); 

//      if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIPSS_INTERFRAME_DELAY_WRITE_STATUS_VALUE with rc = 0x%x", (uint32_t)rc);  return rc; }
//      else { FAPI_INF (" value read from the attribute attr_pm_spipss_interframe_delay_write_status_value = 0x%x", attr_pm_spipss_interframe_delay_write_status_value);}
   

     	//---------------------------------------------------------- 
      rc = FAPI_ATTR_GET(ATTR_PM_SPIPSS_CLOCK_DIVIDER, &i_target, attr_pm_spipss_clock_divider); 

      if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIPSS_CLOCK_DIVIDER with rc = 0x%x", (uint32_t)rc);  return rc; }
      else { FAPI_INF (" value read from the attribute attr_pm_spipss_clock_divider = 0x%x", attr_pm_spipss_clock_divider);}


















        // ------------------------------------------  
        //  -- Init procedure 
        // ------------------------------------------



        // modify_data here
//         uint8_t   hwctrl_frame_size ;
//         uint8_t   hwctrl_device =0    ;
//         uint8_t   hwctrl_clk_pol    ;
//         uint8_t   hwctrl_clk_pha    ;
//         uint32_t  hwctrl_clk_divider;
//         uint32_t  hwctrl_inter_frame_delay;
//         uint16_t  nest_freq ;
// 	//        uint16_t  spipss_freq ;
//         uint8_t   hwctrl_in_count;
//         uint8_t   hwctrl_out_count;
//         uint8_t   hwctrl_in_delay;


         uint8_t hwctrl_target = 0xA; 





   uint8_t  	 hwctrl_frame_size =         attr_pm_spipss_frame_size ;         
//    uint8_t       hwctrl_out_count =          attr_pm_spipss_out_count ;        
//    uint8_t       hwctrl_in_delay =           attr_pm_spipss_in_delay ;         
//    uint8_t       hwctrl_in_count =           attr_pm_spipss_in_count ;         
   uint8_t 	 hwctrl_clk_pol =     attr_pm_spipss_clock_polarity ;   
   uint8_t       hwctrl_clk_pha =        attr_pm_spipss_clock_phase ;      
   uint32_t       hwctrl_clk_divider =      attr_pm_spipss_clock_divider ;    
   uint32_t       hwctrl_inter_frame_delay =  attr_pm_spipss_inter_frame_delay ;
   uint8_t 	 hwctrl_device = attr_pm_apss_chip_select;
   uint8_t       nest_freq = attr_proc_pss_init_nest_frequency ;
        uint32_t  spipss_100ns_div_value ;
  spipss_100ns_div_value = 4 / ( attr_proc_pss_init_nest_frequency*1000000) * (100 /1000000000);







        //  ******************************************************************

        // 	- set SPIPSS_ADC_CTRL_REG0 (24b) 
        // 		adc_frame_size = 16

        //  ******************************************************************

        rc = fapiGetScom(i_target, SPIPSS_ADC_CTRL_REG0_0x00070000, data );
        if (rc) {
          FAPI_ERR("fapiGetScom(SPIPSS_ADC_CTRL_REG0) failed."); return rc;
        }

        
             
        //   data.flushTo0();
        //   data.setWord(1, 0x41000100);
	e_rc=data.insertFromRight(hwctrl_frame_size,0,6); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }

        // FAPI_INF("    -----------------------------------------------------");
        FAPI_INF("    SPIPSS ADC CTRL_REG_0 Configuration                  ");
        // FAPI_INF("    -----------------------------------------------------");  
        FAPI_INF("      frame size                 => %d ", hwctrl_frame_size);
        FAPI_INF("                                       "                   );
        FAPI_INF("                                       "                   );
        // FAPI_INF("    -----------------------------------------------------");



        rc = fapiPutScom(i_target, SPIPSS_ADC_CTRL_REG0_0x00070000, data );
        if (rc) {
          FAPI_ERR("fapiPutScom(SPIPSS_ADC_CTRL_REG0_0x00070000) failed."); return rc;
        }



        //  ******************************************************************
        // 	- set SPIPSS_ADC_CTRL_REG1
        // 		adc_fsm_enable = disable
        // 		adc_device     = APSS
        // 		adc_cpol       = 0
        // 		adc_cpha       = 0
        // 		adc_clock_divider = set to 10Mhz
        // 		adc_nr_of_frames (4b) = 16 (for auto 2 mode)
        //  ******************************************************************

        rc = fapiGetScom(i_target, SPIPSS_ADC_CTRL_REG1_0x00070001, data );
        if (rc) {
          FAPI_ERR("fapiGetScom(SPIPSS_ADC_CTRL_REG1) failed."); return rc;
        }

        // modify_data here

        uint8_t   hwctrl_fsm_enable = 0x0 ;  
        uint8_t   hwctrl_nr_of_frames = 0x10 ;   


        //   data.flushTo0();
        //   rc=data.setWord(1, 0x41000100); if (rc) return rc;
        e_rc=data.insertFromRight(hwctrl_fsm_enable   ,0,1); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }
        e_rc=data.insertFromRight(hwctrl_device       ,1,1); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }
        e_rc=data.insertFromRight(hwctrl_clk_pol      ,2,1); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }
        e_rc=data.insertFromRight(hwctrl_clk_pha      ,3,1); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }
        e_rc=data.insertFromRight(hwctrl_clk_divider  ,4,10); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }
        e_rc=data.insertFromRight(hwctrl_nr_of_frames ,14,4); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }

        // FAPI_INF("    -----------------------------------------------------");
        FAPI_INF("    SPIPSS ADC CTRL_REG_1 Configuration                  ");
        // FAPI_INF("    -----------------------------------------------------");  
        FAPI_INF("      hwctrl_fsm_enable          => %d ", hwctrl_fsm_enable  );
        FAPI_INF("      nest_freq                  => %d ", nest_freq  );
        FAPI_INF("      hwctrl_target              => %d ", hwctrl_target      );
        FAPI_INF("      hwctrl_device              => %d ", hwctrl_device      );
        FAPI_INF("      hwctrl_clk_pol             => %d ", hwctrl_clk_pol     );
        FAPI_INF("      hwctrl_clk_pha             => %d ", hwctrl_clk_pha     );
        FAPI_INF("      hwctrl_clk_divider         => %d ", hwctrl_clk_divider );
        FAPI_INF("      hwctrl_nr_of_frames        => %d ", hwctrl_nr_of_frames);
        FAPI_INF("                                       "                     );
        FAPI_INF("                                       "                     );
        // FAPI_INF("    -----------------------------------------------------");



        rc = fapiPutScom(i_target, SPIPSS_ADC_CTRL_REG1_0x00070001, data );
        if (rc) {
          FAPI_ERR("fapiPutScom(SPIPSS_ADC_CTRL_REG1_0x00070001) failed."); return rc;
        }



        //  ******************************************************************
        // 	- set SPIPSS_ADC_CTRL_REG2
        // 		adc_inter_frame_delay = 0x0
        //  ******************************************************************

        rc = fapiGetScom(i_target, SPIPSS_ADC_CTRL_REG2_0x00070002, data );
        if (rc) {
          FAPI_ERR("fapiGetScom(SPIPSS_ADC_CTRL_REG2) failed."); return rc;
        }
        //   FAPI_INF("sumne data %s                                   " data.genHexLeftStr(0,64)                   );
        
        // modify_data here


        //   rc=data.flushTo0(); if (rc) return rc;
        //   rc=data.setWord(1, 0x41000100); if (rc) return rc;
        e_rc=data.insertFromRight(hwctrl_inter_frame_delay,0,17); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }


        // FAPI_INF("    -----------------------------------------------------");
        FAPI_INF("    SPIPSS ADC CTRL_REG_2 Configuration                  ");
        // FAPI_INF("    -----------------------------------------------------");  
        FAPI_INF("      hwctrl_inter_frm_delay     => %d ", hwctrl_inter_frame_delay );
        FAPI_INF("                                       "                     );
        FAPI_INF("                                       "                     );
        // FAPI_INF("    -----------------------------------------------------");



        rc = fapiPutScom(i_target, SPIPSS_ADC_CTRL_REG2_0x00070002, data );
        if (rc) {
          FAPI_ERR("fapiPutScom(SPIPSS_ADC_CTRL_REG2_0x00070002) failed."); return rc;
        }


        //  ******************************************************************
        // 	- clear SPIPSS_ADC_Wdata_REG
        //  ******************************************************************
//         rc = fapiGetScom(i_target, SPIPSS_ADC_WDATA_REG_0x00070010, data );
//         if (rc) {
//           FAPI_ERR("fapiGetScom(SPIPSS_ADC_WDATA_REG_0x00070010) failed."); return rc;
//         }

        // modify_data here

        uint32_t   hwctrl_wdata    = 0x0;

        e_rc=data.flushTo0(); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }

        //   e_rc=data.setWord(1, 0x41000100); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }
	e_rc=data.insertFromRight(hwctrl_wdata    ,0,16); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }

        // FAPI_INF("    -----------------------------------------------------");
        FAPI_INF("    SPIPSS_WDATA_REG is cleared                           ");
        // FAPI_INF("    -----------------------------------------------------");  
        FAPI_INF("      hwctrl_wdata               => %d ", hwctrl_wdata       );
        FAPI_INF("                                       "                     );
        FAPI_INF("                                       "                     );
        // FAPI_INF("    -----------------------------------------------------");



        rc = fapiPutScom(i_target, SPIPSS_ADC_WDATA_REG_0x00070010, data );
        if (rc) {
          FAPI_ERR("fapiPutScom(SPIPSS_ADC_WDATA_REG_0x00070010) failed."); return rc;
        }


        //  ******************************************************************
        // 	- set SPIPSS_P2S_CTRL_REG0 (24b) 
        // 		p2s_frame_size = 16
        //  ******************************************************************

        rc = fapiGetScom(i_target, SPIPSS_P2S_CTRL_REG0_0x00070040, data );
        if (rc) {
          FAPI_ERR("fapiGetScom(SPIPSS_P2S_CTRL_REG0) failed."); return rc;
        }

        // modify_data here
        uint8_t   p2s_frame_size = 0x02 ;  
        uint8_t   p2s_device     = 0;  
        uint8_t   p2s_clk_pol    = 0;  
        uint8_t   p2s_clk_pha    = 0;  
        uint16_t  p2s_clk_divider= 0x1D;
        uint8_t   p2s_target = 0xA;// DPSS 
        uint32_t   p2s_inter_frame_delay = 0x0;
//         uint8_t   p2s_in_count1;
//         uint8_t   p2s_out_count1;
//         uint8_t   p2s_in_delay1;
//         uint8_t   p2s_in_count2;
//         uint8_t   p2s_out_count2;
//         uint8_t   p2s_in_delay2;


//         if (p2s_target == 13)
//         { 
//             p2s_device = 1;
//             FAPI_INF("      p2s_target_DPSS   " );
//         }
//         else if (p2s_target == 10)
//         {
//             p2s_device = 0;
//             FAPI_INF("      p2s_target_APSS   " );
//         }
// 	    else
// 	    {   FAPI_INF("         " );
// 	        FAPI_ERR("wrong device taget : make sure that you use 0xA=APSS and 0XD=DPSS no other value works");
//             FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PSS_WRONG_DEVICE);
// 	        return rc;   
//         }




//         p2s_frame_size = 0x10 ;  
//         p2s_clk_pol    = 0;  
//         p2s_clk_pha    = 0;  
//         p2s_clk_divider= 0x1D;  
//         p2s_inter_frame_delay = 0x0;

        // calculation of clock divider
//         p2s_clk_divider= nest_freq/spipss_freq/8-1 ;   


	 p2s_frame_size =         attr_pm_spipss_frame_size ;         
	 //	 p2s_out_count =          attr_pm_spipss_out_count ;        
	 //	 p2s_in_delay =           attr_pm_spipss_in_delay ;         
	 //	 p2s_in_count =           attr_pm_spipss_in_count ;         
	 p2s_clk_pol =     attr_pm_spipss_clock_polarity ;   
	 p2s_clk_pha =        attr_pm_spipss_clock_phase ;      
	 p2s_clk_divider =      attr_pm_spipss_clock_divider ;    
	 p2s_inter_frame_delay =  attr_pm_spipss_inter_frame_delay ;
       // nest_freq = attr_p8_pss_init_nest_frequency ;
       //       spipss_freq = attr_pm_pss_init_spipss_frequency;
       p2s_device = attr_pm_apss_chip_select;




        //  ******************************************************************
        // 	- set SPIPSS_P2S_CTRL_REG0
        //  ******************************************************************


        rc = fapiGetScom(i_target, SPIPSS_P2S_CTRL_REG0_0x00070040, data );
        if (rc) {
          FAPI_ERR("fapiGetScom(SPIPSS_P2S_CTRL_REG0) failed."); return rc;
        }


	//         e_rc=data.flushTo0(); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }
        //   e_rc=data.setWord(1, 0x41000100); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }
        e_rc=data.insertFromRight(p2s_frame_size,0,6); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }

        // FAPI_INF("    -----------------------------------------------------");
        FAPI_INF("    SPIPSS P2S CTRL_REG_0 Configuration                  ");
        // FAPI_INF("    -----------------------------------------------------");  
        FAPI_INF("      frame size                 => %d ", p2s_frame_size);
        FAPI_INF("                                       "                   );
        FAPI_INF("                                       "                   );
        // FAPI_INF("    -----------------------------------------------------");



        rc = fapiPutScom(i_target, SPIPSS_P2S_CTRL_REG0_0x00070040, data );
        if (rc) {
          FAPI_ERR("fapiPutScom(SPIPSS_P2S_CTRL_REG0_0x00070040) failed."); return rc;
        }



        //  ******************************************************************
        // 	- set SPIPSS_P2S_CTRL_REG1
        // 		p2s_fsm_enable = disable
        // 		p2s_device     = APSS
        // 		p2s_cpol       = 0
        // 		p2s_cpha       = 0
        // 		p2s_clock_divider = set to 10Mhz
        // 		p2s_nr_of_frames (4b) = 16 (for auto 2 mode)
        //  ******************************************************************

        rc = fapiGetScom(i_target, SPIPSS_P2S_CTRL_REG1_0x00070041, data );
        if (rc) {
          FAPI_ERR("fapiGetScom(SPIPSS_P2S_CTRL_REG1) failed."); return rc;
        }

        // modify_data here

        uint8_t   p2s_fsm_enable = 0x0 ;  
        uint8_t   p2s_nr_of_frames = 0x10 ;   

	//      e_rc=data.flushTo0(); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }
        //   e_rc=data.setWord(1, 0x41000100); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }
        e_rc=data.insertFromRight(p2s_fsm_enable   ,0,1); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }
        e_rc=data.insertFromRight(p2s_device       ,1,1); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }
        e_rc=data.insertFromRight(p2s_clk_pol      ,2,1); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }
        e_rc=data.insertFromRight(p2s_clk_pha      ,3,1); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }
        e_rc=data.insertFromRight(p2s_clk_divider  ,4,10); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }
        e_rc=data.insertFromRight(p2s_nr_of_frames ,14,4); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }

        // FAPI_INF("    -----------------------------------------------------");
        FAPI_INF("    SPIPSS P2S CTRL_REG_1 Configuration                  ");
        // FAPI_INF("    -----------------------------------------------------");  
        FAPI_INF("      p2s_fsm_enable          => %d ", p2s_fsm_enable  );
        FAPI_INF("      p2s_target              => %d ", p2s_target      );
        FAPI_INF("      p2s_device              => %d ", p2s_device      );
        FAPI_INF("      p2s_clk_pol             => %d ", p2s_clk_pol     );
        FAPI_INF("      p2s_clk_pha             => %d ", p2s_clk_pha     );
        FAPI_INF("      p2s_clk_divider         => %d ", p2s_clk_divider );
        FAPI_INF("      p2s_nr_of_frames        => %d ", p2s_nr_of_frames);
        FAPI_INF("                                       "                     );
        FAPI_INF("                                       "                     );
        // FAPI_INF("    -----------------------------------------------------");



        rc = fapiPutScom(i_target, SPIPSS_P2S_CTRL_REG1_0x00070041, data );
        if (rc) {
          FAPI_ERR("fapiPutScom(SPIPSS_P2S_CTRL_REG1_0x00070041) failed."); return rc;
        }


        //  ******************************************************************
        // 	- set SPIPSS_P2S_CTRL_REG2
        // 		p2s_inter_frame_delay = 0x0
        //  ******************************************************************

        rc = fapiGetScom(i_target, SPIPSS_P2S_CTRL_REG2_0x00070042, data );
        if (rc) {
          FAPI_ERR("fapiGetScom(SPIPSS_P2S_CTRL_REG2) failed."); return rc;
        }

        // modify_data here

      //   e_rc=data.flushTo0(); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }
        //   e_rc=data.setWord(1, 0x41000100); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }
        e_rc=data.insertFromRight(p2s_inter_frame_delay,0,17); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }


        // FAPI_INF("    -----------------------------------------------------");
        FAPI_INF("    SPIPSS P2S CTRL_REG_2 Configuration                  ");
        // FAPI_INF("    -----------------------------------------------------");  
        FAPI_INF("      p2s_inter_frm_delay     => %d ", p2s_inter_frame_delay );
        FAPI_INF("                                       "                     );
        FAPI_INF("                                       "                     );
        // FAPI_INF("    -----------------------------------------------------");



        rc = fapiPutScom(i_target, SPIPSS_P2S_CTRL_REG2_0x00070042, data );
        if (rc) {
          FAPI_ERR("fapiPutScom(SPIPSS_P2S_CTRL_REG2_0x00070042) failed."); return rc;
        }


        //  ******************************************************************
        // 	- clear SPIPSS_P2S_Wdata_REG
        //  ******************************************************************
        rc = fapiGetScom(i_target, SPIPSS_P2S_WDATA_REG_0x00070050, data );
        if (rc) {
          FAPI_ERR("fapiGetScom(SPIPSS_P2S_WDATA_REG_0x00070050) failed."); return rc;
        }

// modify_data here

        uint32_t   p2s_wdata    = 0x0;
        e_rc=data.flushTo0(); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }
        e_rc=data.insertFromRight(p2s_wdata    ,0,16); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }

        // FAPI_INF("    -----------------------------------------------------");
        FAPI_INF("    SPIPSS_P2S_WDATA_REG is cleared                           ");
        // FAPI_INF("    -----------------------------------------------------");  
        FAPI_INF("      p2s_wdata               => %d ", p2s_wdata       );
        FAPI_INF("                                       "                     );
        FAPI_INF("                                       "                     );
        // FAPI_INF("    -----------------------------------------------------");




        rc = fapiPutScom(i_target, SPIPSS_P2S_WDATA_REG_0x00070050, data );
        if (rc) {
            FAPI_ERR("fapiPutScom(SPIPSS_P2Sb_WDATA_REG_0x00070050) failed."); return rc;
        }
   
        //  ******************************************************************
        // 	- Set 100ns Register for Interframe delay

        //  ******************************************************************
        rc = fapiGetScom(i_target, SPIPSS_100NS_REG_0x00070028, data );
        if (rc) {
            FAPI_ERR("fapiGetScom(SPIPSS_100NS_REG_0x00070028) failed."); return rc;
        }

        // modify_data here


	e_rc=data.insertFromRight(spipss_100ns_div_value ,0,32); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }


         // FAPI_INF("    -----------------------------------------------------");
         FAPI_INF("    SPIPSS_100NS_REG is set the value                     ");
         // FAPI_INF("    -----------------------------------------------------");  
         FAPI_INF("      spipss_100ns_div_value     => %d ", spipss_100ns_div_value       );
         FAPI_INF("                                       "                     );
         FAPI_INF("                                       "                     );
         // FAPI_INF("    -----------------------------------------------------");

         rc = fapiPutScom(i_target, SPIPSS_100NS_REG_0x00070028, data );
         if (rc) {
           FAPI_ERR("fapiPutScom(SPIPSS_100NS_REG_0x00070028) failed."); return rc;
         }



        FAPI_INF("");
        FAPI_INF("Executing p8_pss_init  ....");

    }  
    // -------------------------------
    /// Reset:  perform reset of PSS
    else if (mode == PM_RESET) 
    {

      FAPI_INF("PSS reset...");
      //    FAPI_INF("PSS reset not yet supported!!!!...");


//  ******************************************************************
// 	- POLLing status register for ongoing or errors

//  ******************************************************************
   rc = fapiGetScom(i_target, SPIPSS_ADC_STATUS_REG_0x00070003, data );
   if (rc) {
     FAPI_ERR("fapiGetScom(SPIPSS_ADC_STATUS_REG_0x00070003) failed."); return rc;
   }
   FAPI_INF("polling for ongoing to go low ... ");

      while (data.isBitSet(0) && data.isBitClear(5) && pollcount < max_polls)
     {
       rc = fapiGetScom(i_target, SPIPSS_ADC_STATUS_REG_0x00070003, data );
       if (rc) {
	 FAPI_ERR("fapiGetScom(SPIPSS_ADC_STATUS_REG_0x00070003) failed."); return rc;
       }
       FAPI_INF(".");
       pollcount++;
       
     }

   FAPI_INF("Send all the frames from ADC to the device.So now resetting it ");

   pollcount = 0;

//  ******************************************************************
// 	- POLLing status register for ongoing or errors

//  ******************************************************************
   rc = fapiGetScom(i_target, SPIPSS_P2S_STATUS_REG_0x00070043, data );
   if (rc) {
     FAPI_ERR("fapiGetScom(SPIPSS_P2S_STATUS_REG_0x00070043) failed."); return rc;
   }
   FAPI_INF("polling for ongoing to go low ... ");

      while (data.isBitSet(0) && data.isBitClear(5)&& pollcount < max_polls)
     {
       rc = fapiGetScom(i_target, SPIPSS_P2S_STATUS_REG_0x00070043, data );
       if (rc) {
	 FAPI_ERR("fapiGetScom(SPIPSS_P2S_STATUS_REG_0x00070043) failed."); return rc;
       }
       FAPI_INF(".");
       pollcount++;
     }

   FAPI_INF("Sent all the frames from P2S bridge to the device.");


//  ******************************************************************
// 	- Resetting both ADC and P2S bridge 
//  ******************************************************************


   FAPI_INF("Resetting P2S and ADC bridge.");


   e_rc=data.flushTo0(); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }
      e_rc=data.setBit(1); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }
      rc=fapiPutScom(i_target,  SPIPSS_ADC_RESET_REGISTER_0x00070005 , data); if(rc) return rc;   
      rc=fapiPutScom(i_target,  SPIPSS_P2S_RESET_REGISTER_0x00070045 , data); if(rc) return rc;   

      //  Reset PMC.  However, the bit used means the entire PMC must be reconfigured!
      //e_rc=data.clear(); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }
      //e_rc=data.setBit(12); if (e_rc) { rc.setEcmdError(e_rc);     return rc; }
      // rc=fapiPutScom(i_target, PMC_MODE_REG_0x00062000 , data); if(rc) return rc;

   FAPI_INF("Reset procedure is done .");

    } 

    /// -------------------------------
    /// Unsupported Mode

    else {

      FAPI_ERR("Unknown mode passed to p8_pss_init. Mode %x ....", mode);
      uint32_t & MODE = mode;
      FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PSS_CODE_BAD_MODE);

    }

    return rc;

}



//#ifdef FAPIECMD
} //end extern C
//#endif 



// Backups

// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------
//  CONST_UINT64_T( SPIPSS_ADC_CTRL_REG0_0x00070000         , ULL(0x00070000) );
//  CONST_UINT64_T( SPIPSS_ADC_CTRL_REG1_0x00070001          , ULL(0x00070001) );
//  CONST_UINT64_T( SPIPSS_ADC_CTRL_REG2_0x00070002          , ULL(0x00070002) );
//  CONST_UINT64_T( SPIPSS_ADC_STATUS_REG_0x00070003         , ULL(0x00070003) );
//  CONST_UINT64_T( SPIPSS_ADC_CMD_REG_0x00070004            , ULL(0x00070004) );

//  CONST_UINT64_T( SPIPSS_ADC_WDATA_REG_0x00070010          , ULL(0x00070010) );
//  CONST_UINT64_T( SPIPSS_ADC_RDATA_REG0_0x00070020         , ULL(0x00070020) );
//  CONST_UINT64_T( SPIPSS_ADC_RDATA_REG1_0x00070021         , ULL(0x00070021) );
//  CONST_UINT64_T( SPIPSS_ADC_RDATA_REG2_0x00070022         , ULL(0x00070022) );
//  CONST_UINT64_T( SPIPSS_ADC_RDATA_REG3_0x00070023         , ULL(0x00070023) );
//  CONST_UINT64_T( SPIPSS_100NS_REG_0x00070028              , ULL(0x00070028) );
//  CONST_UINT64_T( SPIPSS_P2S_CTRL_REG0_0x00070040          , ULL(0x00070040) );
//  CONST_UINT64_T( SPIPSS_P2S_CTRL_REG1_0x00070041          , ULL(0x00070041) );
//  CONST_UINT64_T( SPIPSS_P2S_CTRL_REG2_0x00070042          , ULL(0x00070042) );
//  CONST_UINT64_T( SPIPSS_P2S_STATUS_REG_0x00070043         , ULL(0x00070043) );
//  CONST_UINT64_T( SPIPSS_P2S_COMMAND_REG_0x00070044        , ULL(0x00070044) );

//  CONST_UINT64_T( SPIPSS_P2S_WDATA_REG_0x00070050          , ULL(0x00070050) );
//  CONST_UINT64_T( SPIPSS_P2S_RDATA_REG_0x00070060          , ULL(0x00070060) );
// CONST_UINT64_T( SPIPSS_ADC_RESET_REGISTER_0x00070005  , ULL(0x00070005) );
// CONST_UINT64_T( SPIPSS_P2S_RESET_REGISTER_0x00070045  , ULL(0x00070045) );







//         if (hwctrl_target == 13)
//         { 
//             hwctrl_device = 1;
//             FAPI_INF("      hwctrl_target_DPSS   " );
//         }
//         else if (hwctrl_target == 10)
//         {
//             hwctrl_device = 0;
//             FAPI_INF("      hwctrl_target_APSS   " );
//         }
// 	    else
// 	    {      
//             FAPI_INF("         " );
// 	        FAPI_ERR("wrong device taget : make sure that you use 0xA=APSS and 0XD=DPSS no other value works");
//             FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PSS_WRONG_DEVICE);
//             return rc;
//         }

        // **********************************************
        // Add All Attributes related to hwctrl here
        // **********************************************


//         hwctrl_frame_size = 0x10 ;  
//         hwctrl_clk_pol    = 0;  
//         hwctrl_clk_pha    = 0;  
//         hwctrl_clk_divider= 0x1D;  
//         hwctrl_inter_frame_delay = 0x0;
//         nest_freq = 600;
//         spipss_freq = 10;
//         hwctrl_in_count=0;
//         hwctrl_out_count=0;
//         hwctrl_in_delay=0;  



    
// uint8_t	 attr_pm_spipss_frame_size_set = 16 ;
// uint8_t  attr_pm_spipss_out_count_set = 16;
// uint8_t	 attr_pm_spipss_in_delay_set = 0;
// uint8_t	 attr_pm_spipss_in_count_set = 16;
// uint8_t	 attr_pm_spipss_clock_polarity_set =0 ;
// uint8_t	 attr_pm_spipss_clock_phase_set = 0;
// //uint32_t attr_pm_spipss_clock_divider_set = 0;
// uint32_t attr_pm_spipss_inter_frame_delay_set = 1;

  

//      rc = FAPI_ATTR_SET(ATTR_PM_SPIPSS_FRAME_SIZE, &l_pTarget, attr_pm_spipss_frame_size_set); if (rc) return rc; 
//      rc = FAPI_ATTR_SET(ATTR_PM_SPIPSS_OUT_COUNT, &l_pTarget, attr_pm_spipss_out_count_set);  if (rc) return rc; 
//      rc = FAPI_ATTR_SET(ATTR_PM_SPIPSS_IN_COUNT, &l_pTarget, attr_pm_spipss_in_count_set);  if (rc) return rc; 
//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_SET(ATTR_PM_SPIPSS_IN_DELAY, &l_pTarget, attr_pm_spipss_in_delay_set);  if (rc) return rc; 

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_SET(ATTR_PM_SPIPSS_CLOCK_POLARITY, &l_pTarget, attr_pm_spipss_clock_polarity_set);  if (rc) return rc; 

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_SET(ATTR_PM_SPIPSS_CLOCK_PHASE, &l_pTarget, attr_pm_spipss_clock_phase_set);  if (rc) return rc; 

//      	//---------------------------------------------------------- 
//      rc = FAPI_ATTR_SET(ATTR_PM_SPIPSS_INTER_FRAME_DELAY, &l_pTarget, attr_pm_spipss_inter_frame_delay_set);  if (rc) return rc; 

//      	//---------------------------------------------------------- 
//      //          rc = FAPI_ATTR_SET(ATTR_PM_SPIPSS_INTER_FRAME_DELAY_WRITE_SETTNG, &l_pTarget, attr_pm_spipss_interframe_delay_write_status_value_set); 

   

//      	//---------------------------------------------------------- 
// //      rc = FAPI_ATTR_SET(ATTR_PM_SPIPSS_CLOCK_DIVIDER, &l_pTarget, attr_pm_spipss_clock_divider_set); 




