/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_set_pore_bar/p8_pfet_init.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
// $Id: p8_pfet_init.C,v 1.3 2013/03/18 17:58:33 pchatnah Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pfet_init.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Greg Still         Email: stillgs@us.ibm.com
// *!
/// \file p8_pfet_init.C
/// \brief Configure and initialize the EX PFET controllers based on 
///     attribute information and removes the override function.
///
/// High-level procedure flow:
/// \verbatim
///
///     Check for valid parameters
///     if PM_CONFIG {
///         Nop (all the work is done in PM_INIT as this procedure is not run
///         for the PM Reset path (eg, only done at IPL) 
///     else if PM_INIT {
///         Get the delay setting held in platform attributes 
///         Convert these to hardware values
///         for each EX chiplet {
///             Store the Core VDD delay and VRET/VOFF values
///             Store the Core VCS delay and VRET/VOFF values
///             Store the ECO VDD delay and VRET/VOFF values
///             Store the ECO VCS delay and VRET/VOFF values
///         }
///     } else if PM_RESET {
///         for each EX chiplet {
///             Restore the Core VDD delay and VRET/VOFF values
///             Restore the Core VCS delay and VRET/VOFF values
///             Restore the ECO VDD delay and VRET/VOFF values
///             Restore the ECO VCS delay and VRET/VOFF values
///     }
///
///  Procedure Prereq:
///     - System clocks are running
/// \endverbatim
///
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include "p8_pm.H"
#include "p8_pfet_init.H"
#include "p8_pfet_control.H"

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

fapi::ReturnCode pfet_init(const Target& i_target);
fapi::ReturnCode pfet_config(const Target& i_target);
fapi::ReturnCode pfet_set_delay( const fapi::Target& i_target,
                                 const uint64_t      i_address,
                                 const uint8_t       i_delay0,
                                 const uint8_t       i_delay1,
                                 const uint32_t      i_select);

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------


/// \param[in] i_target EX target
/// \param[in] mode     Control mode for the procedure
///                     (PM_CONFIG, PM_INIT, PM_RESET,
///                      PM_OVERRIDE)
/// \param[in] domain
/// \param[in] opcontrol

/// \retval FAPI_RC_SUCCESS
/// \retval ERROR defined in xml

fapi::ReturnCode
p8_pfet_init(const Target& i_target, uint32_t mode)
{
    fapi::ReturnCode      l_rc;

    FAPI_INF("Executing p8_pfet_init in mode %x ....", mode);

    /// -------------------------------
    /// Configuration:  perform translation of any Platform Attributes
    /// into Feature Attributes that are applied during Initalization
    if (mode == PM_CONFIG)
    {
        FAPI_INF("PFET config...");
        FAPI_INF("---> None is defined...");
    }

    /// -------------------------------
    /// Initialization:  perform order or dynamic operations to initialize
    /// the SLW using necessary Platform or Feature attributes.
    else if (mode == PM_INIT)
    {
        FAPI_INF("PFET init...");
        l_rc = pfet_init(i_target);
    }

    /// -------------------------------
    /// Reset:  perform reset of PFETs so that it can reconfigured and
    /// reinitialized
    else if (mode == PM_RESET)
    {
        FAPI_INF("PFET reset...");
        FAPI_INF("---> None is defined...");
    }

    /// -------------------------------
    /// Unsupported Mode
    else 
    {

        FAPI_ERR("Unknown mode passed to p8_pfet_init. Mode %x ....", mode);
        FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PFET_CODE_BAD_MODE);

    }

    return l_rc;
}

//------------------------------------------------------------------------------
// PFET Configuration Function
//------------------------------------------------------------------------------
fapi::ReturnCode
pfet_init(const Target& i_target)
{
    fapi::ReturnCode            l_rc;
    uint32_t                    e_rc = 0;
    ecmdDataBufferBase          data(64);

    std::vector<fapi::Target>   l_exChiplets;
    uint8_t                     l_functional = 0;
    uint8_t                     l_ex_number = 0;
    bool                        error_flag = false;
    
    uint64_t                    address;
    
    uint8_t                     core_vret_voff_value;
    uint8_t                     eco_vret_voff_value;

    uint32_t                    attr_proc_refclk_frequency;

    uint32_t                    attr_pm_pfet_powerup_core_delay0;
    uint32_t                    attr_pm_pfet_powerup_core_delay1;
    uint32_t                    attr_pm_pfet_powerdown_core_delay0;
    uint32_t                    attr_pm_pfet_powerdown_core_delay1;
    uint32_t                    attr_pm_pfet_powerup_eco_delay0;
    uint32_t                    attr_pm_pfet_powerup_eco_delay1;
    uint32_t                    attr_pm_pfet_powerdown_eco_delay0;
    uint32_t                    attr_pm_pfet_powerdown_eco_delay1;

    uint8_t                     attr_pm_pfet_powerup_core_delay0_value;
    uint8_t                     attr_pm_pfet_powerup_core_delay1_value;
    uint32_t                    attr_pm_pfet_powerup_core_sequence_delay_select;
    uint8_t                     attr_pm_pfet_powerdown_core_delay0_value;
    uint8_t                     attr_pm_pfet_powerdown_core_delay1_value;
    uint32_t                    attr_pm_pfet_powerdown_core_sequence_delay_select;
    uint8_t                     attr_pm_pfet_powerup_eco_delay0_value;
    uint8_t                     attr_pm_pfet_powerup_eco_delay1_value;
    uint32_t                    attr_pm_pfet_powerup_eco_sequence_delay_select;
    uint8_t                     attr_pm_pfet_powerdown_eco_delay0_value;
    uint8_t                     attr_pm_pfet_powerdown_eco_delay1_value;
    uint32_t                    attr_pm_pfet_powerdown_eco_sequence_delay_select;

    /// PFET Sequencing Delays
    ///      convert_pfet_delays() - Convert the following delays from platform
    ///         attributes (binary in nano/ seconds) to PFET delay value feature
    //          attributes.  The conversion uses ATTR_PROC_NEST_FREQUENCY.
    ///       Input platform attributes
    ///            ATTR_PM_PFET_POWERUP_CORE_DELAY0
    ///            ATTR_PM_PFET_POWERUP_CORE_DELAY1
    ///            ATTR_PM_PFET_POWERUP_ECO_DELAY0
    ///            ATTR_PM_PFET_POWERUP_ECO_DELAY1
    ///            ATTR_PM_PFET_POWERDOWN_CORE_DELAY0
    ///            ATTR_PM_PFET_POWERDOWN_CORE_DELAY1 
    ///            ATTR_PM_PFET_POWERDOWN_ECO_DELAY0
    ///            ATTR_PM_PFET_POWERDOWN_ECO_DELAY1
    ///       Output feature attributes
    ///            ATTR_PM_PFET_POWERUP_CORE_DELAY0_VALUE
    ///            ATTR_PM_PFET_POWERUP_CORE_DELAY1_VALUE
    ///            ATTR_PM_PFET_POWERUP_CORE_SEQUENCE_DELAY_SELECT
    ///            ATTR_PM_PFET_POWERUP_ECO_DELAY0_VALUE
    ///            ATTR_PM_PFET_POWERUP_ECO_DELAY1_VALUE
    ///            ATTR_PM_PFET_POWERUP_ECO_SEQUENCE_DELAY_SELECT
    ///            ATTR_PM_PFET_POWERDOWN_CORE_DELAY0_VALUE
    ///            ATTR_PM_PFET_POWERDOWN_CORE_DELAY1_VALUE
    ///            ATTR_PM_PFET_POWERDOWN_CORE_SEQUENCE_DELAY_SELECT
    ///            ATTR_PM_PFET_POWERDOWN_ECO_DELAY0_VALUE
    ///            ATTR_PM_PFET_POWERDOWN_ECO_DELAY1_VALUE
    ///            ATTR_PM_PFET_POWERDOWN_ECO_SEQUENCE_DELAY_SELECT

    do
    {

        FAPI_INF("Executing pfet_config...");
        
        // Harcoded defaults that don't come via attribute
        // Vret (not supported) = "off" (stage 0 = 0xB) for bits 0:3
        // Voff                 = "off" (stage 01 = 0xB) for bits 4:7
        // \todo  The scan0 values are zeros which indicate that the 
        // power won't go off.  Double check the setting below!!!
        core_vret_voff_value = 0xBB;
        eco_vret_voff_value = 0xBB;

        //  ******************************************************************
        //  Get Attributes for pFET Delay
        //  ******************************************************************

        // Hardcoded values (if needed)
        //  attr_pm_pfet_powerup_core_delay0            = 100;
        //  attr_pm_pfet_powerup_core_delay1            = 100;
        //  attr_pm_pfet_powerdown_core_delay0          = 100;
        //  attr_pm_pfet_powerdown_core_delay1          = 100;
        //  attr_pm_pfet_powerup_eco_delay0             = 100;
        //  attr_pm_pfet_powerup_eco_delay1             = 100;
        //  attr_pm_pfet_powerdown_eco_delay0           = 100;
        //  attr_pm_pfet_powerdown_eco_delay1           = 100;


        /// ----------------------------------------------------------
        l_rc = FAPI_ATTR_GET(   ATTR_FREQ_PROC_REFCLOCK,
                                NULL,
                                attr_proc_refclk_frequency);
        if (l_rc)
        {
            FAPI_ERR("fapiGetAttribute ATTR_FREQ_PROC_REFCLOCK");
	    //            FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PFET_GET_ATTR);
            break;
        }
        
        /// ----------------------------------------------------------
        l_rc = FAPI_ATTR_GET(   ATTR_PM_PFET_POWERUP_CORE_DELAY0,
                                &i_target,
                                attr_pm_pfet_powerup_core_delay0);
        if (l_rc)
        {
            FAPI_ERR("fapiGetAttribute ATTR_PM_PFET_POWERUP_CORE_DELAY0");
	    //            FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PFET_GET_ATTR);
            break;
        }

        /// ----------------------------------------------------------
        l_rc = FAPI_ATTR_GET(   ATTR_PM_PFET_POWERUP_CORE_DELAY1,
                                &i_target,
                                attr_pm_pfet_powerup_core_delay1);
        if (l_rc)
        {
            FAPI_ERR("fapiGetAttribute ATTR_PM_PFET_POWERUP_CORE_DELAY1");
	    //            FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PFET_GET_ATTR);
            break;
        }

        /// ----------------------------------------------------------
        l_rc = FAPI_ATTR_GET(   ATTR_PM_PFET_POWERDOWN_CORE_DELAY0,
                                &i_target,
                                attr_pm_pfet_powerdown_core_delay0);
        if (l_rc)
        {
            FAPI_ERR("fapiGetAttribute ATTR_PM_PFET_POWERDOWN_CORE_DELAY0");
	    //            FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PFET_GET_ATTR);
            break;
        }

        /// ----------------------------------------------------------
        l_rc = FAPI_ATTR_GET(   ATTR_PM_PFET_POWERDOWN_CORE_DELAY1,
                                &i_target,
                                attr_pm_pfet_powerdown_core_delay1);
        if (l_rc)
        {
            FAPI_ERR("fapiGetAttribute ATTR_PM_PFET_POWERDOWN_CORE_DELAY1");
	    //            FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PFET_GET_ATTR);
            break;
        }

        /// ----------------------------------------------------------
        l_rc = FAPI_ATTR_GET(   ATTR_PM_PFET_POWERUP_ECO_DELAY0,
                                &i_target,
                                attr_pm_pfet_powerup_eco_delay0);
        if (l_rc)
        {
            FAPI_ERR("fapiGetAttribute ATTR_PM_PFET_POWERUP_ECO_DELAY0");
	    //            FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PFET_GET_ATTR);
            break;
        }


        /// ----------------------------------------------------------
        l_rc = FAPI_ATTR_GET(   ATTR_PM_PFET_POWERUP_ECO_DELAY1,
                                &i_target,
                                attr_pm_pfet_powerup_eco_delay1);
        if (l_rc)
        {
            FAPI_ERR("fapiGetAttribute ATTR_PM_PFET_POWERUP_ECO_DELAY1");
	    //            FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PFET_GET_ATTR);
            break;
        }

        /// ----------------------------------------------------------
        l_rc = FAPI_ATTR_GET(   ATTR_PM_PFET_POWERDOWN_ECO_DELAY0,
        &i_target, attr_pm_pfet_powerdown_eco_delay0);
        if (l_rc)
        {
            FAPI_ERR("fapiGetAttribute ATTR_PM_PFET_POWERDOWN_ECO_DELAY0");
	    //            FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PFET_GET_ATTR);
            break;
        }

        /// ----------------------------------------------------------
        l_rc = FAPI_ATTR_GET(   ATTR_PM_PFET_POWERDOWN_ECO_DELAY1,
                                &i_target,
                                attr_pm_pfet_powerdown_eco_delay1);
        if (l_rc)
        {
            FAPI_ERR("fapiGetAttribute ATTR_PM_PFET_POWERDOWN_ECO_DELAY1");
	    //            FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PFET_GET_ATTR);
            break;
        }


        //  ******************************************************************
        //  Calculate Delay values out of pFET Delays
        //  ******************************************************************
        FAPI_DBG("*************************************");
        FAPI_DBG("Calculates Delay values out of pFET Delays");
        FAPI_DBG("*************************************");
        FAPI_DBG("Calculate:");
        FAPI_DBG("        ATTR_PM_PFET_POWERUP_CORE_DELAY0_VALUE");
        FAPI_DBG("        ATTR_PM_PFET_POWERUP_CORE_DELAY1_VALUE");
        FAPI_DBG("        ATTR_PM_PFET_POWERUP_ECO_DELAY0_VALUE");
        FAPI_DBG("        ATTR_PM_PFET_POWERUP_ECO_DELAY1_VALUE");
        FAPI_DBG("        ATTR_PM_PFET_POWERDOWN_CORE_DELAY0_VALUE");
        FAPI_DBG("        ATTR_PM_PFET_POWERDOWN_CORE_DELAY1_VALUE");
        FAPI_DBG("        ATTR_PM_PFET_POWERDOWN_ECO_DELAY0_VALUE");
        FAPI_DBG("        ATTR_PM_PFET_POWERDOWN_ECO_DELAY1_VALUE");
        FAPI_DBG("using:");
        FAPI_DBG("        ATTR_PM_PFET_POWERUP_CORE_DELAY0");
        FAPI_DBG("        ATTR_PM_PFET_POWERUP_CORE_DELAY1");
        FAPI_DBG("        ATTR_PM_PFET_POWERUP_ECO_DELAY0");
        FAPI_DBG("        ATTR_PM_PFET_POWERUP_ECO_DELAY1");
        FAPI_DBG("        ATTR_PM_PFET_POWERDOWN_CORE_DELAY0");
        FAPI_DBG("        ATTR_PM_PFET_POWERDOWN_CORE_DELAY1");
        FAPI_DBG("        ATTR_PM_PFET_POWERDOWN_ECO_DELAY0");
        FAPI_DBG("        ATTR_PM_PFET_POWERDOWN_ECO_DELAY1");
        FAPI_DBG("**************************************************************************");
        FAPI_DBG("        Set  ATTR_PM_PFET_POWERUP_CORE_SEQUENCE_DELAY_SELECT    to 0 (choosing always pfetdelay0 )");
        FAPI_DBG("        Set  ATTR_PM_PFET_POWERDOWN_CORE_SEQUENCE_DELAY_SELECT  to 0 (choosing always pfetdelay0 )");
        FAPI_DBG("        Set  ATTR_PM_PFET_POWERUP_ECO_SEQUENCE_DELAY_SELECT     to 0 (choosing always pfetdelay0 )");
        FAPI_DBG("        Set  ATTR_PM_PFET_POWERDOWN_ECO_SEQUENCE_DELAY_SELECT   to 0 (choosing always pfetdelay0 )");
        FAPI_DBG("**************************************************************************");

        //value = 15 - log2(delay * refclk);
        attr_pm_pfet_powerup_core_delay0_value          =
                convert_delay_to_value( attr_pm_pfet_powerup_core_delay0,
                                        attr_proc_refclk_frequency);

        attr_pm_pfet_powerup_core_delay1_value          =
                convert_delay_to_value( attr_pm_pfet_powerup_core_delay1,
                                        attr_proc_refclk_frequency);

        attr_pm_pfet_powerdown_core_delay0_value        =
                convert_delay_to_value( attr_pm_pfet_powerdown_core_delay0 ,
                                        attr_proc_refclk_frequency);

        attr_pm_pfet_powerdown_core_delay1_value        =
                convert_delay_to_value( attr_pm_pfet_powerdown_core_delay1 ,
                                        attr_proc_refclk_frequency);

        attr_pm_pfet_powerup_eco_delay0_value           =
                convert_delay_to_value( attr_pm_pfet_powerup_eco_delay0 ,
                                        attr_proc_refclk_frequency);

        attr_pm_pfet_powerup_eco_delay1_value           =
                convert_delay_to_value( attr_pm_pfet_powerup_eco_delay1 ,
                                        attr_proc_refclk_frequency);

        attr_pm_pfet_powerdown_eco_delay0_value         =
                convert_delay_to_value( attr_pm_pfet_powerdown_eco_delay0 ,
                                        attr_proc_refclk_frequency);

        attr_pm_pfet_powerdown_eco_delay1_value         =
                convert_delay_to_value( attr_pm_pfet_powerdown_eco_delay1 ,
                                        attr_proc_refclk_frequency);
        
        // Choosing always delay0
        attr_pm_pfet_powerup_core_sequence_delay_select         = 0;  
        attr_pm_pfet_powerdown_core_sequence_delay_select       = 0;
        attr_pm_pfet_powerup_eco_sequence_delay_select          = 0;
        attr_pm_pfet_powerdown_eco_sequence_delay_select        = 0;

        FAPI_DBG("*************************************");
        FAPI_DBG("attr_pm_pfet_powerup_core_delay0_value           :  %X", attr_pm_pfet_powerup_core_delay0_value);
        FAPI_DBG("attr_pm_pfet_powerup_core_delay1_value           :  %X", attr_pm_pfet_powerup_core_delay1_value);
        FAPI_DBG("attr_pm_pfet_powerup_core_sequence_delay_select  :  %X", attr_pm_pfet_powerup_core_sequence_delay_select);
        FAPI_DBG("attr_pm_pfet_powerdown_core_delay0_value         :  %X", attr_pm_pfet_powerdown_core_delay0_value);
        FAPI_DBG("attr_pm_pfet_powerdown_core_delay1_value         :  %X", attr_pm_pfet_powerdown_core_delay1_value);
        FAPI_DBG("attr_pm_pfet_powerdown_core_sequence_delay_select:  %X", attr_pm_pfet_powerdown_core_sequence_delay_select);
        FAPI_DBG("attr_pm_pfet_powerup_eco_delay0_value            :  %X", attr_pm_pfet_powerup_eco_delay0_value);
        FAPI_DBG("attr_pm_pfet_powerup_eco_delay1_value            :  %X", attr_pm_pfet_powerup_eco_delay1_value);
        FAPI_DBG("attr_pm_pfet_powerup_eco_sequence_delay_select   :  %X", attr_pm_pfet_powerup_eco_sequence_delay_select);
        FAPI_DBG("attr_pm_pfet_powerdown_eco_delay0_value          :  %X", attr_pm_pfet_powerdown_eco_delay0_value);
        FAPI_DBG("attr_pm_pfet_powerdown_eco_delay1_value          :  %X", attr_pm_pfet_powerdown_eco_delay1_value);
        FAPI_DBG("attr_pm_pfet_powerdown_eco_sequence_delay_select :  %X", attr_pm_pfet_powerdown_eco_sequence_delay_select);
        FAPI_DBG("*************************************");

        //  ******************************************************************
        //  Install in the hardware
        //      Loop through all the functional chiplets
        //  ******************************************************************

        l_rc = fapiGetChildChiplets(i_target, 
                                    TARGET_TYPE_EX_CHIPLET, 
                                    l_exChiplets,
                                    TARGET_STATE_PRESENT);
	    if (l_rc)
	    {
	        FAPI_ERR("Error from fapiGetChildChiplets!");
	        break;
	    }

	    FAPI_DBG("\tChiplet vector size  => %u ", l_exChiplets.size());

        // Iterate through the returned chiplets
	    for (uint8_t j=0; j < l_exChiplets.size(); j++)
	    {
            // Determine if it's functional
            l_rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL, &l_exChiplets[j], l_functional);
            if (l_rc)
            {
                FAPI_ERR("fapiGetAttribute of ATTR_FUNCTIONAL error");
                error_flag = true;
                break;
            }
            else if ( l_functional )
            {
                // Get the core number
                l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_exChiplets[j], l_ex_number);
                if (l_rc)
                {
                    FAPI_ERR("fapiGetAttribute of ATTR_CHIP_UNIT_POS error");
                    error_flag = true;
                    break;
                }

                FAPI_DBG("\tGP0(0) from core %x (@ %08llx) => 0x%16llx",
                                l_ex_number,
                                EX_GP3_0x100F0012+(l_ex_number*0x01000000),
                                data.getDoubleWord(0));


                FAPI_INF("\tSet the PFET attribute values into the appropriate registers");

                // -------------------------------------------------------------
                FAPI_DBG("\tSetting Core Power up Delays");
                address = EX_CorePFPUDly_REG_0x100F012C + (0x01000000 * l_ex_number);
                l_rc=pfet_set_delay(i_target,
                                    address,
                                    attr_pm_pfet_powerup_core_delay0_value,
                                    attr_pm_pfet_powerup_core_delay1_value,
                                    attr_pm_pfet_powerup_core_sequence_delay_select
                                   );
                if (l_rc)
                {
                    FAPI_ERR("pfet_step_delay error 0x%08llu", address);
                    break;
                }

                // -------------------------------------------------------------
                FAPI_DBG("\tSetting Core Power down Delays");
                address = EX_CorePFPDDly_REG_0x100F012D + (0x01000000 * l_ex_number);
                l_rc=pfet_set_delay(i_target,
                                    address,
                                    attr_pm_pfet_powerup_core_delay0_value,
                                    attr_pm_pfet_powerup_core_delay1_value,
                                    attr_pm_pfet_powerup_core_sequence_delay_select
                                   );
                if (l_rc)
                {
                    FAPI_ERR("pfet_step_delay error 0x%08llu", address);
                    break;
                }


                // -------------------------------------------------------------
                FAPI_DBG("\tSetting Core Voff Settings");
                e_rc |= data.setBitLength(64);
	            e_rc |= data.insertFromRight(core_vret_voff_value, 0, 8);
                if (e_rc)
                {
                    FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
                    l_rc.setEcmdError(e_rc);
                    break;
                }

                address = EX_CorePFVRET_REG_0x100F0130 + (0x01000000 * l_ex_number);
                l_rc=fapiPutScom(i_target, address, data );
                if (l_rc)
                {
                    FAPI_ERR("pfet_step_delay error 0x%08llu", address);
                    break;
                }

                // -------------------------------------------------------------
                FAPI_DBG("\tSetting ECO Power up Delays");
                address = EX_ECOPFPUDly_REG_0x100F014C + (0x01000000 * l_ex_number);
                l_rc=pfet_set_delay(i_target,
                                    address,
                                    attr_pm_pfet_powerup_core_delay0_value,
                                    attr_pm_pfet_powerup_core_delay1_value,
                                    attr_pm_pfet_powerup_core_sequence_delay_select
                                   );
                if (l_rc)
                {
                    FAPI_ERR("pfet_step_delay error 0x%08llu", address);
                    break;
                }

                // -------------------------------------------------------------
                FAPI_DBG("\tSetting ECO Power down Delays");
                address = EX_ECOPFPDDly_REG_0x100F014D + (0x01000000 * l_ex_number);
                l_rc=pfet_set_delay(i_target,
                                    address,
                                    attr_pm_pfet_powerup_core_delay0_value,
                                    attr_pm_pfet_powerup_core_delay1_value,
                                    attr_pm_pfet_powerup_core_sequence_delay_select
                                   );
                if (l_rc)
                {
                    FAPI_ERR("pfet_step_delay error 0x%08llu", address);
                    break;
                }


                // -------------------------------------------------------------
                FAPI_DBG("\tSetting ECO Voff Settings");
                e_rc |= data.setBitLength(64);
	            e_rc |= data.insertFromRight(eco_vret_voff_value, 0, 8);  
                if (e_rc)
                {
                    FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
                    l_rc.setEcmdError(e_rc);
                    break;
                }

                address = EX_ECOPFVRET_REG_0x100F0150 + (0x01000000 * l_ex_number);
                l_rc=fapiPutScom(i_target, address, data );
                if (l_rc)
                {
                    FAPI_ERR("pfet_step_delay error 0x%08llu", address);
                    break;
                }

            }
            // Not Functional - disable the PFETs
            else
            {
                // Do nothing
            }
        } // chiplet loop
    } while(0);

    return l_rc;
}



//------------------------------------------------------------------------------
// pfet_set_delay
//  Helper function to set delay registers
//------------------------------------------------------------------------------
fapi::ReturnCode
pfet_set_delay( const fapi::Target& i_target,
                const uint64_t      i_address,
                const uint8_t       i_delay0,
                const uint8_t       i_delay1,
                const uint32_t      i_select)
{
    fapi::ReturnCode            l_rc;
    uint32_t                    e_rc = 0;
    ecmdDataBufferBase          data;

    do
    {

        e_rc |= data.setBitLength(64);
	    e_rc |= data.insertFromRight(i_delay0, 0, 4);   // bits 0:3
	    e_rc |= data.insertFromRight(i_delay1, 4, 4);   // bits 4:7
        e_rc |= data.insertFromRight(i_select, 8, 12);  // bits 8:19
        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }

	    l_rc=fapiPutScom(i_target, i_address, data );
        if (l_rc)
        {
            FAPI_ERR("PutScom error 0x%08llu", i_address);
            break;
        }

    } while(0);
    return l_rc;
}


//------------------------------------------------------------------------------
// convert_delay_to_value
//  Helper function to convert time values (binary in ns)to hardware delays
//------------------------------------------------------------------------------
uint8_t 
convert_delay_to_value (uint32_t i_delay, 
                        uint32_t i_attr_proc_nest_frequency)
{
    uint8_t   pfet_delay_value;
    float     dly; 
    //  attr_proc_nest_frequency [MHz]
    //  delay [ns]
    //  pfet_delay_value = 15 - log2( i_delay * i_attr_proc_nest_frequency/1000);
    //  since log2 function is not available, this is done manual
    //  pfet_delay_value = 15 - log2( dly );
    dly = ( i_delay * i_attr_proc_nest_frequency/1000);

    if                          ( dly <= 1.4 )    {pfet_delay_value = 15 - 0 ;}
    else if (( 1.4   < dly ) && ( dly <= 2.8 )  ) {pfet_delay_value = 15 - 1 ;}
    else if (( 2.8   < dly ) && ( dly <= 5.6 )  ) {pfet_delay_value = 15 - 2 ;}
    else if (( 5.6   < dly ) && ( dly <= 11.5 ) ) {pfet_delay_value = 15 - 3 ;}
    else if (( 11.5  < dly ) && ( dly <= 23 )   ) {pfet_delay_value = 15 - 4 ;}
    else if (( 23    < dly ) && ( dly <= 46 )   ) {pfet_delay_value = 15 - 5 ;}
    else if (( 46    < dly ) && ( dly <= 92 )   ) {pfet_delay_value = 15 - 6 ;}
    else if (( 92    < dly ) && ( dly <= 182 )  ) {pfet_delay_value = 15 - 7 ;}
    else if (( 182   < dly ) && ( dly <= 364 )  ) {pfet_delay_value = 15 - 8 ;}
    else if (( 364   < dly ) && ( dly <= 728 )  ) {pfet_delay_value = 15 - 9 ;}
    else if (( 728   < dly ) && ( dly <= 1456 ) ) {pfet_delay_value = 15 - 10;}
    else if (( 1456  < dly ) && ( dly <= 2912 ) ) {pfet_delay_value = 15 - 11;}
    else if (( 2912  < dly ) && ( dly <= 5824 ) ) {pfet_delay_value = 15 - 12;}
    else if (( 5824  < dly ) && ( dly <= 11648 )) {pfet_delay_value = 15 - 13;}
    else if (( 11648 < dly ) && ( dly <= 23296 )) {pfet_delay_value = 15 - 14;}
    else if  ( 23296 < dly )                      {pfet_delay_value = 15 - 15;}
    else                                          {pfet_delay_value = 15 - 15;}

    return (pfet_delay_value);
}



/*
*************** Do not edit this area ***************
This section is automatically updated by CVS when you check in this file.
Be sure to create CVS comments when you commit so that they can be included here.


*/



} //end extern

