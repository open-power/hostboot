/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_set_pore_bar/p8_pfet_init.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: p8_pfet_init.C,v 1.14 2014/02/17 02:56:59 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pfet_init.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Greg Still         Email: stillgs@us.ibm.com
// *!
// *! Build cmd:  buildfapiprcd -e "../../xml/error_info/p8_pfet_init_errors.xml" p8_pfet_init.C
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
#include "p8_pm_utils.H"
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

fapi::ReturnCode pfet_init(const Target& i_target, uint32_t i_mode);
fapi::ReturnCode pfet_config(const Target& i_target);
fapi::ReturnCode pfet_set_delay( const fapi::Target& i_target,
                                 const uint64_t      i_address,
                                 const uint8_t       i_delay0,
                                 const uint8_t       i_delay1,
                                 const uint32_t      i_select);
uint8_t convert_delay_to_value ( uint32_t   i_delay,
                                 uint32_t   i_attr_proc_nest_frequency);

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------


/// \param[in] i_target EX target
/// \param[in] i_mode   Control mode for the procedure
///                     (PM_CONFIG, PM_INIT, PM_RESET,
///                      PM_OVERRIDE)
///
/// \retval FAPI_RC_SUCCESS
/// \retval ERROR defined in xml

fapi::ReturnCode
p8_pfet_init(const Target& i_target, uint32_t i_mode)
{
    fapi::ReturnCode      l_rc;

    FAPI_INF("Executing p8_pfet_init in mode %x ....", i_mode);

    /// -------------------------------
    /// Configuration:  perform translation of any Platform Attributes
    /// into Feature Attributes that are applied during Initalization
    if (i_mode == PM_CONFIG)
    {
        FAPI_INF("PFET config...");
        FAPI_INF("---> None is defined...");
    }

    /// -------------------------------
    /// Initialization:  perform order or dynamic operations to initialize
    /// the SLW using necessary Platform or Feature attributes.
    else if (i_mode == PM_INIT || i_mode == PM_INIT_SPECIAL)
    {
        FAPI_INF("PFET init...");
        l_rc = pfet_init(i_target, i_mode);
    }

    /// -------------------------------
    /// Reset:  perform reset of PFETs so that it can reconfigured and
    /// reinitialized
    else if (i_mode == PM_RESET)
    {
        FAPI_INF("PFET reset...");
        FAPI_INF("---> None is defined...");
    }

    /// -------------------------------
    /// Unsupported Mode
    else
    {

        FAPI_ERR("Unknown mode passed to p8_pfet_init. Mode %x ....", i_mode);
        FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PFET_CODE_BAD_MODE);

    }

    return l_rc;
}

//------------------------------------------------------------------------------
// PFET Configuration Function
//------------------------------------------------------------------------------
fapi::ReturnCode
pfet_init(const Target& i_target, uint32_t i_mode)
{
    fapi::ReturnCode            l_rc;
    uint32_t                    e_rc = 0;
    ecmdDataBufferBase          data(64);

    std::vector<fapi::Target>   l_exChiplets;
    uint8_t                     l_functional = 0;
    uint8_t                     l_ex_number = 0;

    uint64_t                    address;

    uint8_t                     core_vret_voff_value;
    uint8_t                     eco_vret_voff_value;

    pfet_force_t                off_mode;
    
    // detect PCBS Error Reset capaiblity
    uint8_t                     chipHasPcbsErrReset = 0;

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

        // VRET settings need to be "ON" as PFET VRET is not supported
        // The iVRM hardware will tell the PFET controller to go 'OFF"
        // in its support of Vret.  These values do not pertain in that
        // case.
        core_vret_voff_value = 0x00;
        eco_vret_voff_value = 0x00;

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
            break;
        }

        /// ----------------------------------------------------------
        l_rc = FAPI_ATTR_GET(   ATTR_PM_PFET_POWERUP_CORE_DELAY0,
                                &i_target,
                                attr_pm_pfet_powerup_core_delay0);
        if (l_rc)
        {
            FAPI_ERR("fapiGetAttribute ATTR_PM_PFET_POWERUP_CORE_DELAY0");
            break;
        }

        /// ----------------------------------------------------------
        l_rc = FAPI_ATTR_GET(   ATTR_PM_PFET_POWERUP_CORE_DELAY1,
                                &i_target,
                                attr_pm_pfet_powerup_core_delay1);
        if (l_rc)
        {
            FAPI_ERR("fapiGetAttribute ATTR_PM_PFET_POWERUP_CORE_DELAY1");
            break;
        }

        /// ----------------------------------------------------------
        l_rc = FAPI_ATTR_GET(   ATTR_PM_PFET_POWERDOWN_CORE_DELAY0,
                                &i_target,
                                attr_pm_pfet_powerdown_core_delay0);
        if (l_rc)
        {
            FAPI_ERR("fapiGetAttribute ATTR_PM_PFET_POWERDOWN_CORE_DELAY0");
            break;
        }

        /// ----------------------------------------------------------
        l_rc = FAPI_ATTR_GET(   ATTR_PM_PFET_POWERDOWN_CORE_DELAY1,
                                &i_target,
                                attr_pm_pfet_powerdown_core_delay1);
        if (l_rc)
        {
            FAPI_ERR("fapiGetAttribute ATTR_PM_PFET_POWERDOWN_CORE_DELAY1");
            break;
        }

        /// ----------------------------------------------------------
        l_rc = FAPI_ATTR_GET(   ATTR_PM_PFET_POWERUP_ECO_DELAY0,
                                &i_target,
                                attr_pm_pfet_powerup_eco_delay0);
        if (l_rc)
        {
            FAPI_ERR("fapiGetAttribute ATTR_PM_PFET_POWERUP_ECO_DELAY0");
            break;
        }


        /// ----------------------------------------------------------
        l_rc = FAPI_ATTR_GET(   ATTR_PM_PFET_POWERUP_ECO_DELAY1,
                                &i_target,
                                attr_pm_pfet_powerup_eco_delay1);
        if (l_rc)
        {
            FAPI_ERR("fapiGetAttribute ATTR_PM_PFET_POWERUP_ECO_DELAY1");
            break;
        }

        /// ----------------------------------------------------------
        l_rc = FAPI_ATTR_GET(   ATTR_PM_PFET_POWERDOWN_ECO_DELAY0,
                                &i_target,
                                attr_pm_pfet_powerdown_eco_delay0);
        if (l_rc)
        {
            FAPI_ERR("fapiGetAttribute ATTR_PM_PFET_POWERDOWN_ECO_DELAY0");
            break;
        }

        /// ----------------------------------------------------------
        l_rc = FAPI_ATTR_GET(   ATTR_PM_PFET_POWERDOWN_ECO_DELAY1,
                                &i_target,
                                attr_pm_pfet_powerdown_eco_delay1);
        if (l_rc)
        {
            FAPI_ERR("fapiGetAttribute ATTR_PM_PFET_POWERDOWN_ECO_DELAY1");
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

        FAPI_DBG("\tNumber of EX chiplets present => %u", l_exChiplets.size());

        // Iterate through the returned chiplets
        for (uint8_t j=0; j < l_exChiplets.size(); j++)
        {
            // Determine if it's functional
            l_rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL, &l_exChiplets[j], l_functional);
            if (l_rc)
            {
                FAPI_ERR("fapiGetAttribute of ATTR_FUNCTIONAL error");
                break;
            }

            // Get the core number
            l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_exChiplets[j], l_ex_number);
            if (l_rc)
            {
                FAPI_ERR("fapiGetAttribute of ATTR_CHIP_UNIT_POS error");
                break;
            }


            FAPI_INF("Set PFET attribute values into EX %X", l_ex_number);

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
                FAPI_ERR("pfet_set_delay error 0x%08llu", address);
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
                FAPI_ERR("pfet_set_delay error 0x%08llu", address);
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
                FAPI_ERR("PutScom error 0x%08llu", address);
                break;
            }

            // -------------------------------------------------------------
            FAPI_DBG("\tSetting ECO Power up Delays");
            address = EX_ECOPFPUDly_REG_0x100F014C + (0x01000000 * l_ex_number);
            l_rc=pfet_set_delay(i_target,
                                address,
                                attr_pm_pfet_powerup_eco_delay0_value,
                                attr_pm_pfet_powerup_eco_delay1_value,
                                attr_pm_pfet_powerup_eco_sequence_delay_select
                               );
            if (l_rc)
            {
                FAPI_ERR("pfet_set_delay error 0x%08llu", address);
                break;
            }

            // -------------------------------------------------------------
            FAPI_DBG("\tSetting ECO Power down Delays");
            address = EX_ECOPFPDDly_REG_0x100F014D + (0x01000000 * l_ex_number);
            l_rc=pfet_set_delay(i_target,
                                address,
                                attr_pm_pfet_powerdown_eco_delay0_value,
                                attr_pm_pfet_powerdown_eco_delay1_value,
                                attr_pm_pfet_powerdown_eco_sequence_delay_select
                               );
            if (l_rc)
            {
                FAPI_ERR("pfet_set_delay error 0x%08llu", address);
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
                FAPI_ERR("PutScom error 0x%08llu", address);
                break;
            }

            // Make a note of PMGP0-invalid-write-snitch bit PMErr_REG(12).
            address = EX_PMErr_REG_0x100F0109 + (l_ex_number * 0x01000000);
            l_rc=fapiGetScom(i_target, address, data);
            if (l_rc)
            {
                FAPI_ERR("GetScom error 0x%08llu", address);
                break;
            }
            FAPI_DBG("PMErr_REG (before calling p8_pfet_control): 0x%016llx",data.getDoubleWord(0));
            
            // Functional - run any work-arounds necessary
            if (l_functional)
            {
                l_rc = p8_pm_pcbs_fsm_trace (i_target, l_ex_number, 
                                "before p8_pfet_control functional");
                if (!l_rc.ok()) { break; }
            
                // \todo:  make DD1 relevent
                FAPI_INF("Perform iVRM work-around on configured EX %d", l_ex_number);

                FAPI_EXEC_HWP(l_rc, p8_pfet_control,    i_target,
                                                        l_ex_number,
                                                           BOTH,
                                                          VON);
                if(l_rc)
                {
                    FAPI_ERR("iVRM / PFET Controller error");
                    break;
                }
                
                l_rc = p8_pm_pcbs_fsm_trace (i_target, l_ex_number, 
                                "after p8_pfet_control functional");
                if (!l_rc.ok()) { break; }

            }
            // Not Functional - disable the PFETs
            // Only done on hardware as this can cause sim issue for unpopulated
            // chiplest
            uint8_t is_sim;

            l_rc = FAPI_ATTR_GET(ATTR_IS_SIMULATION, NULL, is_sim);
            if (l_rc)
            {
                FAPI_ERR("fapi_attr_get(ATTR_IS_SIMULATION ) failed. "
                 "With rc = 0x%x", (uint32_t) l_rc );
                break;
            }
            if(!is_sim)
            {
                if (!l_functional )
                {
                
                    l_rc = p8_pm_pcbs_fsm_trace (i_target, l_ex_number, 
                                "before p8_pfet_control non-functional");
                    if (!l_rc.ok()) { break; }
                
                    FAPI_INF("Turn off PFETs on EX %d", l_ex_number);
                    off_mode = VOFF;
                    if (i_mode == PM_INIT_SPECIAL)
                    {
                        FAPI_INF("\tUsing PFET override mode");
                        off_mode = VOFF_OVERRIDE;
                    }

                   FAPI_EXEC_HWP(l_rc, p8_pfet_control,    i_target,
                       l_ex_number,
                       BOTH,
                       off_mode);

                    if(l_rc)
                    {
                        FAPI_ERR("PFET Controller error");
                        break;
                    }
                    
                    l_rc = p8_pm_pcbs_fsm_trace (i_target, l_ex_number, 
                                "after p8_pfet_control non-functional");
                    if (!l_rc.ok()) { break; }
                }
            }
            else
            {
                FAPI_INF("Simulation detected: Not disabling PFETs in deconfigured chiplets");
            }
            
            // Make a note of PMGP0-invalid-write-snitch bit PMErr_REG(12).
            // And, if bit12 set, clear all of PMErr_REG.
            // Note, even though we attempt below to only clear the PMErr_REG(12) bit,
            // the mere write action to PMErr_REG will cause the whole register to clear.
            
            l_rc = FAPI_ATTR_GET(ATTR_CHIP_EC_FEATURE_PCBS_ERR_RESET,
                                &i_target,
                                chipHasPcbsErrReset);
            if(l_rc)
            {
     		    FAPI_ERR("Error querying Chip EC feature: "
                         "ATTR_CHIP_EC_FEATURE_PCBS_ERR_RESET");
                break;
            }
                        
            address = EX_PMErr_REG_0x100F0109 + (l_ex_number * 0x01000000);
            l_rc=fapiGetScom(i_target, address, data);
            if (l_rc)
            {
                FAPI_ERR("GetScom error 0x%08llu", address);
                break;
            }
            FAPI_DBG("PMErr_REG (after returning from p8_pfet_control): 0x%016llx",data.getDoubleWord(0));
            if (data.getBit(12))
            {
                e_rc |= data.clearBit(12);
                if (e_rc)
                {
                    FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
                    l_rc.setEcmdError(e_rc);
                    break;
                }
                
                FAPI_INF("PCBS Error Reset is %s being performed",
                         (chipHasPcbsErrReset ? "" : "NOT"));      

                if (chipHasPcbsErrReset)
                {                         
                    l_rc = fapiPutScom(i_target, address, data);
                    if (l_rc)
                    {
                        FAPI_ERR("PutScom error 0x%08llu", address);
                        break;
                    }
                    l_rc=fapiGetScom(i_target, address, data);
                    if (l_rc)
                    {
                        FAPI_ERR("GetScom error 0x%08llu", address);
                        break;
                    }
                    FAPI_DBG("PMErr_REG (after clearing it): 0x%016llx",data.getDoubleWord(0));
                }
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

