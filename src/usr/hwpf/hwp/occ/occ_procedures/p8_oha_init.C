/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_oha_init.C $           */
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
// $Id: p8_oha_init.C,v 1.13 2013/09/12 16:08:45 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_oha_init.C,v $
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
/// \brief Setup OHA ( Power Proxy Trace Timer and Low Activity detect range)
///
/// \version
/// \version 1.12  stillgs 06/04/13 Fix Gerrit comment on e_rc setting into rc for OHA
/// \version       Mode register access
/// \version --------------------------------------------------------------------------
/// \version 1.11  stillgs 05/20/13 Removed AISS reset call as unncessary for OCC reset use
/// \version --------------------------------------------------------------------------
/// \version 1.9  mjjones 04/30/13 Removed unused variable
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
/// High-level procedure flow:
///
/// \verbatim
///
///  Procedure Prereq:
///  - completed istep procedure
///
///
///     if PM_CONFIG {
///
///        convert_ppt_time() - Convert Power Proxy Trace Time to Power Proxy Trace Time Select and Match feature attributes
///        With ATTR_PM_POWER_PROXY_TRACE_TIMER (binary in nanoseconds) to produce  ATTR_PM_PPT_TIMER_MATCH_VALUE and ATTR_PM_PPT_TIMER_TICK
///          0=0.25us , 1=0.5us, 2=1us, and 3=2us
///
///     else if PM_INIT {
///        loop over all valid chiplets {
///           Check if OHA is accessible as chiplet may not be enabled or are in winkle
///
///           Setup aiss hang time  in oha_mode_reg
///           Set aiss_timeout to max              --  oha_mode_reg (11:14) ,            ADR 1002000D (SCOM)
///                                                --  9 => longest time  512 ms
///           Setup low activity  in oha_low_activity_detect_mode_reg
///                                                -- oha_low_activity_detect_mode_reg,   ADR 10020003 (SCOM)
///             \todo  when should we enable the low activity detection or just setup the ranges??
///           Set lad_enable = 1??
///           Set lad_entry = 16                  -- bit index of a 24 bit counter based on base counter  0: longest, 23: shortest interval
///           Set lad_exit  = 17                  -- bit index of a 24 bit counter based on base counter  0: longest, 23: shortest interval
///
///
///           Setup Power Proxy Trace  in activity_sample_mode_reg
///           Set  ppt_int_timer_select           -- activity_sample_mode_reg (36:37)    ADR 10020000 (SCOM)
///                                                -- select precounter for ppt timer ( 0=0.25us, 1=0.5us, 2=1us, 3=2us )
///
///         )
///     } else if PM_RESET {
///         loop over all valid chiplets {
///           Check if OHA is accessible as chiplet may not be enabled or are
//            in winkle
///
///             Note: no function is defined!!!! AISS reset was here but this
///             reset should not be associcated with OCC resets
///
///         }
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

#include "p8_pm.H"
#include "p8_scom_addresses.H"
#include "p8_oha_init.H"
#include "p8_pcb_scom_errors.H"


extern "C" {

using namespace fapi;

 //------------------------------------------------------------------------------
 //Start scan zero value
 //------------------------------------------------------------------------------



// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------

fapi::ReturnCode oha_aiss_inject_winkle_entry(const fapi::Target & i_ex_target);

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
fapi::ReturnCode p8_oha_init_reset( const fapi::Target& i_target,
                                    uint32_t i_mode);
// Config function
fapi::ReturnCode p8_oha_init_config(const fapi::Target&  i_target);

// Init function
fapi::ReturnCode  p8_oha_init_init( const fapi::Target& i_target,
                                    struct_i_oha_val_init_type i_oha_val_init);

// ----------------------------------------------------------------------
// p8_oha_init wrapper to fetch the attributes and pass it on to p8_oha_init_core
// ----------------------------------------------------------------------

fapi::ReturnCode
p8_oha_init(const fapi::Target &i_target, uint32_t i_mode)
{
    fapi::ReturnCode rc;

    FAPI_INF("Procedure start");
    do
    {
     
        if ( i_mode == PM_CONFIG )
        {

            FAPI_INF("MODE: CONFIG Calling p8_oha_init_config");

            rc=p8_oha_init_config(i_target);
            if (rc)
            {
                FAPI_ERR(" p8_oha_init_config failed. With rc = 0x%x", (uint32_t)rc); 
                break;
            }

        } else if ( i_mode == PM_INIT )  {


            FAPI_INF("MODE: INIT Calling p8_oha_init_init");

            //Declare parms struct
            struct_i_oha_val_init_type i_oha_val_init;

            //Assign values to parms in struct
            // should come from MRWB
            i_oha_val_init.AISS_HANG_DETECT_TIMER_SEL = 9;  //  oha_mode_reg (11:14) - 0=1ms, 1=2ms, 3=4ms, ...9=512ms. others illegal
            i_oha_val_init.PPT_TIMER_SELECT = 3;            //  activity_sample_mode_reg (36:37) 0=0.25us, 1=0.5us, 2=1us, and 3=2us
            i_oha_val_init.LAD_ENTRY = 16;
            i_oha_val_init.LAD_EXIT = 17;

            rc=p8_oha_init_init(i_target,  i_oha_val_init);
            if (rc)
            {
                FAPI_ERR(" p8_oha_init_init failed. With rc = 0x%x", (uint32_t)rc);
                break;
            }

        }
        else if ( i_mode == PM_RESET )
        {

             FAPI_INF("MODE: RESET - none defined");
             /*

             GSS:  removed as this only resets (at this time) the AISS
             functions which are not influenced by OCC FW and are detrimental
             to operational chiplets

             FAPI_INF("MODE: RESET Calling p8_oha_init_reset");
             rc = p8_oha_init_reset( i_target, i_mode);
             if (rc)
             {
                FAPI_ERR(" p8_oha_init_reset failed. With rc = 0x%x", (uint32_t)rc);
                return rc;
             }
             */
        }
        else
        {

             FAPI_ERR("Unknown mode %x ....\n", i_mode);
             FAPI_SET_HWP_ERROR(rc, RC_PROC_OHA_CODE_BAD_MODE);

        }
    } while (0);

    FAPI_INF("Procedure end...\n");
   
    return rc;

}


//------------------------------------------------------------------------------
// OHA Config Function
//------------------------------------------------------------------------------
fapi::ReturnCode
p8_oha_init_config(const fapi::Target& i_target)
{
    fapi::ReturnCode rc;

    uint8_t  attr_pm_aiss_timeout;
    uint32_t attr_pm_power_proxy_trace_timer;
    uint32_t attr_pm_ppt_timer_tick;
    uint32_t attr_pm_ppt_timer_match_value;
    
    FAPI_INF("OHA config start...");
    do
    {      

        //  ******************************************************************
        //  Get Attributes for OHA Timers Delay
        //  ******************************************************************
        //  set defaults  if not available
        
        // Write all the timer attributes with defaults.  This also allocates
        // the attributes in Cronus environments.
        // If overrides exist, the overridden values will be returned when 
        // read back.

        attr_pm_ppt_timer_tick           = 2;       // Default 2: 1us
        
        SETATTR(rc,
                ATTR_PM_PPT_TIMER_TICK,
                "ATTR_PM_PPT_TIMER_TICK",
                &i_target,
                attr_pm_ppt_timer_tick);
                
        GETATTR(rc,
                ATTR_PM_PPT_TIMER_TICK,
                "ATTR_PM_PPT_TIMER_TICK",
                &i_target,
                attr_pm_ppt_timer_tick);
        
        attr_pm_aiss_timeout             = 5;       // Default 5: 32ms
        
        SETATTR(rc,
                ATTR_PM_AISS_TIMEOUT,
                "ATTR_PM_AISS_TIMEOUT",
                &i_target,
                attr_pm_aiss_timeout);
                
        GETATTR(rc,
                ATTR_PM_AISS_TIMEOUT,
                "ATTR_PM_AISS_TIMEOUT",
                &i_target,
                attr_pm_aiss_timeout);
       
        attr_pm_power_proxy_trace_timer  = 64000;   // Default 1us,,, 32us...64ms
        
        SETATTR(rc,
                ATTR_PM_POWER_PROXY_TRACE_TIMER,
                "ATTR_PM_POWER_PROXY_TRACE_TIMER",
                &i_target,
                attr_pm_power_proxy_trace_timer);
                
        GETATTR(rc,
                ATTR_PM_POWER_PROXY_TRACE_TIMER,
                "ATTR_PM_POWER_PROXY_TRACE_TIMER",
                &i_target,
                attr_pm_power_proxy_trace_timer);

        //  ******************************************************************
        //  Calculate OHA timer settings
        //  ******************************************************************

        FAPI_DBG("Calculate OHA timer settings");
        FAPI_DBG("Calculate:");
        FAPI_DBG("        ATTR_PM_PPT_TIMER_MATCH_VALUE");
        FAPI_DBG("        ATTR_PM_PPT_TIMER_TICK");
        FAPI_DBG("using:");
        FAPI_DBG("        ATTR_PM_POWER_PROXY_TRACE_TIMER");

        FAPI_DBG("Set  ATTR_PM_AISS_TIMEOUT to %X", attr_pm_aiss_timeout);
        attr_pm_ppt_timer_match_value  = attr_pm_power_proxy_trace_timer / 32  ;    //time in us / 32us

        FAPI_DBG("Set ATTR_PM_PPT_TIMER_MATCH_VALUE to %X", attr_pm_ppt_timer_match_value);


        //  ******************************************************************
        //  Set Attributes for OHA timers
        //  ******************************************************************

        SETATTR(rc,
                ATTR_PM_PPT_TIMER_MATCH_VALUE,
                "ATTR_PM_PPT_TIMER_MATCH_VALUE",
                &i_target,
                attr_pm_ppt_timer_match_value);       

    } while (0);
    
    FAPI_INF("OHA config end...\n");
     
    return rc;

}  //end CONFIG



//------------------------------------------------------------------------------
// OHA Init Function
//------------------------------------------------------------------------------
fapi::ReturnCode
p8_oha_init_init(const fapi::Target& i_target, struct_i_oha_val_init_type i_oha_val_init)
{
    fapi::ReturnCode rc;
    uint32_t l_rc;

    ecmdDataBufferBase              data(64);
    ecmdDataBufferBase              mask(64);

    std::vector<fapi::Target>       l_exChiplets;
//    std::vector<Target>::iterator  itr;
    uint8_t                         l_ex_number = 0;

    uint8_t                         attr_pm_aiss_timeout;
    uint32_t                        attr_pm_tod_pulse_count_match_val = 1024;
    uint32_t                        attr_pm_ppt_timer_tick;
    uint32_t                        attr_pm_ppt_timer_match_value;

    FAPI_INF("OHA init start...");
    do
    {
        

        //  ******************************************************************
        //  Get Attributes for OHA Timers Delay
        //  ******************************************************************
        
        GETATTR(rc,
                ATTR_PM_PPT_TIMER_TICK,
                "ATTR_PM_PPT_TIMER_TICK",
                &i_target,
                attr_pm_ppt_timer_tick);
        
        GETATTR(rc,
                ATTR_PM_PPT_TIMER_MATCH_VALUE,
                "ATTR_PM_PPT_TIMER_MATCH_VALUE",
                &i_target,
                attr_pm_ppt_timer_match_value);    

        GETATTR(rc,
                ATTR_PM_AISS_TIMEOUT,
                "ATTR_PM_AISS_TIMEOUT",
                &i_target,
                attr_pm_aiss_timeout);                

        //  ******************************************************************
        //  initialize all oha_reg with scan-zero values upfront
        //  ******************************************************************

        rc = fapiGetChildChiplets ( i_target,
                                    TARGET_TYPE_EX_CHIPLET,
                                    l_exChiplets,
                                    TARGET_STATE_FUNCTIONAL);
        if (rc)
        {
            FAPI_ERR("Error from fapiGetChildChiplets!");
            break;
        }
        FAPI_DBG("Number of chiplets  => %u", l_exChiplets.size());

        // Iterate through the returned chiplets
        //for (itr = l_exChiplets.begin(); itr != l_exChiplets.end(); itr++)
        for (uint8_t c=0; c < l_exChiplets.size(); c++)
        {          
            // Get the core number
            //rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, itr, c);
            rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_exChiplets[c], l_ex_number);
            if (rc)
            {
                FAPI_ERR("fapiGetAttribute of ATTR_CHIP_UNIT_POS error");
                break;
            }

            FAPI_DBG("Processing core : %d ", l_ex_number);

            //  ******************************************************************
            //  AISS hang timer setup
            //  ******************************************************************
            //  - set aiss_timeout to max time
            //  ******************************************************************
            //FAPI_DBG("**********************************************");
            FAPI_INF(" Setup aiss hang time in oha_mode_reg 1002000D");
            //FAPI_DBG("**********************************************");

            // Read register content
            //rc = fapiGetScom( (*itr), EX_OHA_MODE_REG_RWx1002000D , data );
            rc = fapiGetScom( l_exChiplets[c], EX_OHA_MODE_REG_RWx1002000D , data );
            if (rc)
            {
                FAPI_ERR("fapiGetScom(EX_OHA_MODE_REG) failed. With rc = 0x%x", (uint32_t)rc);
                break;
            }

            FAPI_DBG ("Content of EX_OHA_MODE_REG_0x1002000D  :  %016llX", data.getDoubleWord(0));

            //data.flushTo0();
            l_rc = data.insertFromRight(attr_pm_aiss_timeout    ,11,4);
            l_rc |= data.insertFromRight(attr_pm_tod_pulse_count_match_val    ,17,14);
            if (l_rc)
            {
                FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc);
                break;
            }

            // rc = fapiPutScom( (*itr), EX_OHA_MODE_REG_RWx1002000D , data );
            rc = fapiPutScom( l_exChiplets[c], EX_OHA_MODE_REG_RWx1002000D , data );
            if (rc)
            {
                FAPI_ERR("fapiPutScom(EX_OHA_MODE_REG) failed. With rc = 0x%x", (uint32_t)rc); 
                break;
            }


            //  ******************************************************************
            //  Low Activity Detect (LAD) setup
            //  ******************************************************************
            //  ******************************************************************
            //  - enable LAD
            //  - set LAD for entry
            //  - set LAD for exit
            //  ******************************************************************

            FAPI_INF(" Setup Low Activity Detect (LAD) in oha_low_activity_detect_mode_reg 10020003, but NOT ENABLED");

            // Read register content
            // rc = fapiGetScom( (*itr), EX_OHA_LOW_ACTIVITY_DETECT_MODE_REG_RWx10020003 , data );
            rc = fapiGetScom( l_exChiplets[c], EX_OHA_LOW_ACTIVITY_DETECT_MODE_REG_RWx10020003 , data );
            if (rc)
            {
               FAPI_ERR("fapiGetScom(EX_OHA_LOW_ACTIVITY_DETECT_MODE_REG_RWx10020003) failed. With rc = 0x%x", (uint32_t)rc);
               break;
            }
            FAPI_DBG(" Pre write content of EX_OHA_LOW_ACTIVITY_DETECT_MODE_REG_RWx10020003  :  %016llX", data.getDoubleWord(0));

            l_rc = data.setByte(0, i_oha_val_init.LAD_ENTRY);   // 16
            l_rc |= data.setByte(1, i_oha_val_init.LAD_EXIT);   // 17
            l_rc |= data.shiftRight(1);                         // LAD entry/exit starts at bit 1
            l_rc |= data.clearBit(0);
            if (l_rc)
            {
                FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);
                rc.setEcmdError(l_rc);
                break;
            }

            // rc = fapiPutScom((*itr), EX_OHA_LOW_ACTIVITY_DETECT_MODE_REG_RWx10020003 , data );
            rc = fapiPutScom( l_exChiplets[c], EX_OHA_LOW_ACTIVITY_DETECT_MODE_REG_RWx10020003 , data );
            if (rc)
            {
                FAPI_ERR("fapiGetScom(EX_OHA_LOW_ACTIVITY_DETECT_MODE_REG) failed. With rc = 0x%x", (uint32_t)rc);
                break;
            }

            FAPI_INF ("Done LAD setup. LAD Disabled " );

            //  ******************************************************************
            //  Power Proxy Trace (PPT) setup
            //  ******************************************************************
            //  ******************************************************************
            //  - set ppt_timer_select
            //  - set ppt_trace_timer_match_val
            //  ******************************************************************

            FAPI_INF(" Setup  Power Proxy Trace (PPT) in oha_activity_sample_mode_reg 10020000");

            // Read register content
            // rc = fapiGetScom( (*itr), EX_OHA_ACTIVITY_SAMPLE_MODE_REG_RWx10020000 , data );
            rc = fapiGetScom( l_exChiplets[c], EX_OHA_ACTIVITY_SAMPLE_MODE_REG_RWx10020000 , data );
            if (rc)
            {
                FAPI_ERR("fapiGetScom(EX_OHA_ACTIVITY_SAMPLE_MODE_REG) failed. With rc = 0x%x", (uint32_t)rc);
                break;
            }
            FAPI_DBG(" Pre write content of EX_OHA_ACTIVITY_SAMPLE_MODE_REG_RWx10020000  :  %016llX", data.getDoubleWord(0));


            // set ppt_int_timer_select to longest interval "11" = 2us
            //l_rc = data.setBit(36);
            //if (l_rc)
            //{
            //      FAPI_ERR("Bit operation failed.");
            //      FAPI_SET_HWP_ERROR(rc, RC_PROC_OHA_CODE_BITOP_FAILED);
            //}
            //l_rc = data.setBit(37);
            //if (l_rc)
            //{
            //      FAPI_ERR("Bit operation failed.");
            //      FAPI_SET_HWP_ERROR(rc, RC_PROC_OHA_CODE_BITOP_FAILED);
            //}

            l_rc = data.insertFromRight(attr_pm_ppt_timer_match_value    ,24,11);
            l_rc |= data.insertFromRight(attr_pm_ppt_timer_tick           ,36,2);
            if (l_rc)
            {
                FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);
                rc.setEcmdError(l_rc);
                break;
            }

            // rc = fapiPutScom((*itr), EX_OHA_ACTIVITY_SAMPLE_MODE_REG_RWx10020000 , data );
            rc = fapiPutScom( l_exChiplets[c], EX_OHA_ACTIVITY_SAMPLE_MODE_REG_RWx10020000 , data );
            if (rc)
            {
                FAPI_ERR("fapiGetScom(EX_OHA_ACTIVITY_SAMPLE_MODE_REG) failed. With rc = 0x%x", (uint32_t)rc);
                 break;
            }

            FAPI_INF ("Done PPT timer setup." );
        } // Chiplet loop
        
        // Error break is naturally handled
        
    } while(0);
    
    FAPI_INF("OHA init end...\n");
    return rc;

}  //end INIT



//------------------------------------------------------------------------------
// OHA Reset Function
//------------------------------------------------------------------------------
fapi::ReturnCode
p8_oha_init_reset(const Target &i_target,  uint32_t i_mode)
{
    fapi::ReturnCode                rc;
    fapi::ReturnCode                e_rc;
    uint32_t                        l_rc = 0;

    ecmdDataBufferBase              data(64);
    ecmdDataBufferBase              mask(64);


//    std::vector<Target>::iterator   itr;
    std::vector<fapi::Target>       l_exChiplets;
    uint8_t                         l_ex_number = 0;
    
    uint8_t                         platform;
    
    FAPI_INF("OHA init start...");
    do
    {
        rc = fapiGetChildChiplets ( i_target,
                                    TARGET_TYPE_EX_CHIPLET,
                                    l_exChiplets,
                                    TARGET_STATE_FUNCTIONAL);
        if (rc)
        {
            FAPI_ERR("Error from fapiGetChildChiplets!");
            break;
        }
        FAPI_DBG("Number of chiplets  => %u", l_exChiplets.size());

        // Iterate through the returned chiplets
        //for (itr = l_exChiplets.begin(); itr != l_exChiplets.end(); itr++)
        for (uint8_t c=0; c < l_exChiplets.size(); c++)
        {

            // Get the core number
            //rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, itr, c);
            rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_exChiplets[c], l_ex_number);
            if (rc)
            {
                FAPI_ERR("fapiGetAttribute of ATTR_CHIP_UNIT_POS error");
                break;
            }

            FAPI_DBG("Processing core : %d ", l_ex_number);

            // --------------------------------------
            // Check if SBE code has already cleared the OHA override.
            // As chiplets may be enabled but offline (eg in Winkle)
            // treat SCOM errors as off-line (eg skip it).  If online
            // and set, clear the override.

            //  GSS:  removed as Cronus always puts a message out of (PCB_OFFLINE)
            //  even though this code is meant to handle it. As this message
            //  can cause confusion in the lab, the check is being removed.
            bool            oha_accessible = true;
            uint32_t        fsierror = 0;
            const uint32_t  IDLE_STATE_OVERRIDE_EN = 6;


            e_rc = fapiGetScom(l_exChiplets[c], EX_OHA_MODE_REG_RWx1002000D, data);
            if(!e_rc.ok())
            {
                FAPI_ERR("Error reading EX_OHA_MODE_REG_RWx1002000D . Further debugging");

                // Based on the execution platorm, access different facilities to 
                // determine the error code
                GETATTR(rc,
                        ATTR_EXECUTION_PLATFORM,
                        "ATTR_EXECUTION_PLATFORM",
                        NULL,
                        platform);

                if( platform == fapi::ENUM_ATTR_EXECUTION_PLATFORM_FSP) 
                {      
                    rc = fapiGetCfamRegister( i_target, CFAM_FSI_STATUS_0x00001007, data );
                    if(!rc.ok())
                    {
                        FAPI_ERR("Error reading CFAM FSI Status Register");
                        break;
                    }
                    FAPI_INF( "CFAM_FSI_STATUS_0x00001007: 0x%X", data.getWord(0));
                    l_rc |= data.extractToRight( &fsierror, 17, 3 );

                    if ( l_rc )
                    {
                        rc.setEcmdError(l_rc);
                        break;
                    }
                }
                else if( platform == fapi::ENUM_ATTR_EXECUTION_PLATFORM_HOST )
                {
                    // Find the ADU status reg with the same PIB scresp

                }
                else
                {
                    FAPI_ERR("Invalid execution platform: %X", platform);
                    // \todo Add CML point
                    break;
                }
                if (fsierror == PIB_OFFLINE_ERROR)
                {
                    FAPI_INF( "Chiplet offline error detected. Skipping OHA Override clearing");
                    oha_accessible = false;
                }
                else
                {
                    FAPI_ERR("Scom reading OHA_MODE");
                    uint32_t & ERRORS = fsierror;
                    rc = e_rc ;
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_OHA_CODE_PUTGETSCOM_FAILED);
                    break;
                }
            }
            // Process if OHA accessible.
            if (oha_accessible)
            {
                if (data.isBitSet(IDLE_STATE_OVERRIDE_EN))
                {

                    FAPI_INF("\tClear the OHA Idle State Override for EX %x", l_ex_number);
                    l_rc |= data.clearBit(IDLE_STATE_OVERRIDE_EN);
                    if (l_rc)
                    {
                       FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", l_rc);
                       rc.setEcmdError(l_rc);
                       break;
                    }

                    rc = fapiPutScom(l_exChiplets[c], EX_OHA_MODE_REG_RWx1002000D, data);
                    if(!rc.ok())
                    {
                        FAPI_ERR("Scom error writing OHA_MODE");
                        break;
                    }
                }
            }
            //        End of check removal

            // GSS: removed AISS reset as this should only be used for SLW
            // recovery, not OCC reset.
            //
            // If this function were to ever be restored here (for whatever
            // reason), a check for special wake-up state must be made.
            // This, too, needs care in implementation as AISS reset affects
            // the special wake-up condition and must be forced from the PCBS-PM
            // via the override mechanism there.

        } // chiplet loop
    } while(0);

    FAPI_INF("OHA reset end...\n");
    return rc;
}

} //end extern C
