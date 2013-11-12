/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_prep_for_reset.C $  */
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
// $Id: p8_pm_prep_for_reset.C,v 1.25 2013/10/30 17:13:09 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_prep_for_reset.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Ralf Maier         Email: ralf.maier@de.ibm.com
// *!
/// \file p8_pm_prep_for_reset.C
/// \brief Initialize powermanagement
/// *!
// *! Procedure Prereq:
// *!   o System clocks are running
// *!
//------------------------------------------------------------------------------
///
/// High-level procedure flow:
///
/// \verbatim
///     - call p8_occ_control.C *chiptarget, ENUM:OCC_STOP      ppc405_reset_ctrl = 2
///             - OCC PPC405 put into reset
///             - PMC moves to Vsafe value due to heartbeat loss
///
///     - call p8_cpu_special_wakeup.C  *chiptarget, ENUM:OCC_SPECIAL_WAKEUP
///             - For each chiplet,  put into Special Wake-up via the OCC special wake-up bit
///
///     - call p8_pmc_force_vsafe.C  *chiptarget,
///                    - Forces the Vsafe value into the voltage controller
///
///     - call p8_pcbs_init.C *chiptarget, ENUM:PCBSPM_RESET
///
///     - call p8_pmc_init.C *chiptarget, ENUM:PMC_RESET
///             - Issue reset to the PMC
///
///     - call p8_poregpe_init.C *chiptarget, ENUM:POREGPE_RESET
///
///     - call p8_pba_init.C *chiptarget, ENUM:PBA_RESET
///
///     - call p8_occ_sram_init.C *chiptarget, ENUM:OCC_SRAM_RESET
///
///     - call p8_ocb_init .C *chiptarget, ENUM:OCC_OCB_RESET
///
///     SLW engine reset is not done here as this will blow away all setup
///     in istep 15.  Thus, ALL manipulation of this is done there or by
///     p8_poreslw_recovery.
///
///  \endverbatim
///

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------

#include "p8_pm.H"
#include "p8_pm_prep_for_reset.H"

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

fapi::ReturnCode
special_wakeup_all (const fapi::Target &i_target, bool i_action);

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------


//------------------------------------------------------------------------------
/**
 * p8_pm_prep_for_reset Call underlying unit procedure to perform readiness for
 *          reinitialization of PM complex.
 *
 * @param[in] i_primary_chip_target   Primary Chip target which will be passed
 *        to all the procedures
 * @param[in] i_secondary_chip_target Secondary Chip target will be passed for
 *        pmc_init -reset only if it is DCM otherwise this should be NULL.
 * @param[in] i_mode (PM_RESET (hard - will kill the PMC);
 *                    PM_RESET_SOFT (will not fully reset the PMC))
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode
p8_pm_prep_for_reset(   const fapi::Target &i_primary_chip_target,
                        const fapi::Target &i_secondary_chip_target,
                        uint32_t            i_mode                  )
{

    fapi::ReturnCode                rc;

    std::vector<fapi::Target>       l_exChiplets;
    ecmdDataBufferBase              data(64);
    ecmdDataBufferBase              mask(64);

    const char *        PM_MODE_NAME_VAR; // Defines storage for PM_MODE_NAME

    fapi::Target dummy;

    do
    {

        FAPI_INF("p8_pm_prep_for_reset start  ....");

        if (i_mode == PM_RESET)
        {
            FAPI_INF("Hard reset detected");
        }
        else if (i_mode == PM_RESET_SOFT)
        {
            FAPI_INF("Soft reset detected.  Idle functions will not be affected");
        }
        else
        {
            FAPI_ERR("Mode parameter value not supported: %u", i_mode);
            uint32_t & MODE = i_mode;
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PREP_UNSUPPORTED_MODE_ERR);
            break;
        }

        if ( i_secondary_chip_target.getType() == TARGET_TYPE_NONE )
        {
            if ( i_primary_chip_target.getType() == TARGET_TYPE_NONE )
            {
                FAPI_ERR("Set primay target properly for SCM " );
                const fapi::Target PRIMARY_TARGET = i_primary_chip_target;
                FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PREP_TARGET_ERR);
                break;
            }
            FAPI_DBG("Running on SCM");
        }
        else
        {
            FAPI_DBG("Running on DCM");
        }

        //  ******************************************************************
        //  Put OCC PPC405 into reset
        //  ******************************************************************
        //  ******************************************************************
        //  - call p8_occ_control.C *chiptarget, ENUM:OCC_STOP      ppc405_reset_ctrl = 2s
        //
        //  ******************************************************************

        FAPI_INF("Put OCC PPC405 into reset");
        FAPI_DBG("Executing: p8_occ_control.C");

        FAPI_EXEC_HWP(rc, p8_occ_control, i_primary_chip_target, PPC405_RESET_ON, 0);
        if (rc)
        {
            FAPI_ERR("p8_occ_control: Failed to prepare OCC for RESET. With rc = 0x%x", (uint32_t)rc);
            break;
        }

        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
            FAPI_EXEC_HWP(rc, p8_occ_control, i_secondary_chip_target, PPC405_RESET_ON, 0);
            if (rc)
            {
              FAPI_ERR("p8_occ_control: Failed to prepare OCC for RESET. With rc = 0x%x", (uint32_t)rc);
              break;
            }
        }

        //  ******************************************************************
        //  Put all EX chiplet special wakeup
        //  *****************************************************************
                
        // Primary
        rc = special_wakeup_all (i_primary_chip_target, true);
        if (rc)
        {
            FAPI_ERR("special_wakeup_all - Enable: Failed for Target %s", 
                        i_primary_chip_target.toEcmdString());
            break;
        }
                

        // Secondary
        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
            rc = special_wakeup_all (i_secondary_chip_target, true);
            if (rc)
            {
                FAPI_ERR("special_wakeup_all - Enable: Failed for Target %s", 
                            i_secondary_chip_target.toEcmdString());
                break;
            }

        }

        //  ******************************************************************
        //  Mask the FIRs
        //  ******************************************************************

        FAPI_INF("Executing:p8_pm_firinit in mode PM_RESET");

        FAPI_EXEC_HWP(rc, p8_pm_firinit, i_primary_chip_target , i_mode );
        if (rc)
        {
            FAPI_ERR("ERROR: p8_pm_firinit detected failed  result");
            break;
        }

        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {

            FAPI_EXEC_HWP(rc, p8_pm_firinit, i_secondary_chip_target , PM_RESET );
            if (rc)
            {
                FAPI_ERR("ERROR: p8_pm_firinit detected failed  result");
                break;
            }
        }

        //  ******************************************************************
        //  Force Vsafe value into voltage controller
        //  ******************************************************************
        //     - call p8_pmc_force_vsafe.C  *chiptarget,
        //                    - Forces the Vsafe value into the voltage controller
        //

        FAPI_INF("Force Vsafe value into voltage controller");
        FAPI_DBG("Executing: p8_pmc_force_vsafe.C");

        // Primary

        FAPI_EXEC_HWP(rc, p8_pmc_force_vsafe, i_primary_chip_target);
        if (rc)
        {
            FAPI_ERR("Failed to force Vsafe value into voltage controller. With rc = 0x%x", (uint32_t)rc);
            break;
        }

        // Secondary
        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
            FAPI_EXEC_HWP(rc, p8_pmc_force_vsafe, i_secondary_chip_target);
            if (rc)
            {
              FAPI_ERR("Failed to force Vsafe value into voltage controller. With rc = 0x%x", (uint32_t)rc);
              break;
            }
        }

        //  ******************************************************************
        //  Prepare PCBSLV_PM for RESET
        //  ******************************************************************
        //      - call p8_pcbs_init.C *chiptarget, ENUM:PCBSPM_RESET
        //
        //      - p8_pcbs_init internally loops over all enabled chiplets

        FAPI_INF("Prepare PCBSLV_PM for RESET");
        FAPI_DBG("Executing: p8_pcbs_init.C");

        // Primary
        FAPI_EXEC_HWP(rc, p8_pcbs_init, i_primary_chip_target, PM_RESET);
        if (rc)
        {
            FAPI_ERR("p8_pcbs_init: Failed to prepare PCBSLV_PM for RESET. With rc = 0x%x", (uint32_t)rc);
            break;
        }

        // Secondary
        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {

            FAPI_EXEC_HWP(rc, p8_pcbs_init, i_secondary_chip_target, PM_RESET);
            if (rc)
            {
              FAPI_ERR("p8_pcbs_init: Failed to prepare PCBSLV_PM for RESET. With rc = 0x%x", (uint32_t)rc);
              break;
            }
        }

        //  ******************************************************************
        //  Reset PMC
        //  ******************************************************************
        //     - call p8_pmc_init.C *chiptarget, ENUM:PMC_RESET_SOFT
        //

        FAPI_INF("Issue reset to PMC");
        FAPI_DBG("Executing: p8_pmc_init");

        FAPI_EXEC_HWP(rc, p8_pmc_init, i_primary_chip_target, i_secondary_chip_target, i_mode);
        if (rc)
        {
            FAPI_ERR("p8_pmc_init: Failed to issue PMC reset. With rc = 0x%x", (uint32_t)rc);
            break;
        }
        
        //  ******************************************************************
        //  As the PMC reset kills ALL of the configuration, the idle portion
        //  must be reestablished to allow that portion to operate.  This is 
        //  what p8_poreslw_init -init does. Additionally, this lets us drop 
        //  special wake-up  before exiting.
        //  ******************************************************************
        //     - call p8_poreslw_init.C *chiptarget, ENUM:PM_INIT
        //

        FAPI_INF("Re-establish PMC Idle configuration");
        FAPI_DBG("Executing: p8_poreslw_init in mode %s", PM_MODE_NAME(PM_INIT_PMC));
        
        // Primary
        FAPI_EXEC_HWP(rc, p8_poreslw_init, i_primary_chip_target, PM_INIT_PMC);
        if (rc)
        {
            FAPI_ERR("p8_poreslw_init: Failed to to reinialize the idle portion of the PMC. With rc = 0x%x", (uint32_t)rc);
            break;
        }

        // Secondary
        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {

            FAPI_EXEC_HWP(rc, p8_poreslw_init, i_secondary_chip_target, PM_INIT_PMC);
            if (rc)
            {
                FAPI_ERR("p8_poreslw_init: Failed to to reinialize the idle portion of the PMC. With rc = 0x%x", (uint32_t)rc);
                break;
            }

        }

        //  ******************************************************************
        //  Issue reset to PSS macro
        //  ******************************************************************
        //     - call p8_pss_init.C *chiptarget, ENUM:PM_RESET
        //

        FAPI_INF("Issue reset to PSS macro");
        FAPI_DBG("Executing: p8_pss_init.C");

        // Primary
        FAPI_EXEC_HWP(rc, p8_pss_init, i_primary_chip_target, PM_RESET);
        if (rc)
        {
            FAPI_ERR("p8_pss_init: Failed to issue reset to PSS macro. With rc = 0x%x", (uint32_t)rc);
            break;
        }

        // Secondary
        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {

            FAPI_DBG("FAPI_EXEC_HWP(rc, p8_pss_init, i_secondary_chip_target, PM_RESET);");

            FAPI_EXEC_HWP(rc, p8_pss_init, i_secondary_chip_target, PM_RESET);
            if (rc)
            {
                FAPI_ERR("p8_pss_init: Failed to issue reset to PSS macro. With rc = 0x%x", (uint32_t)rc);
                break;
            }
        }
               
        //  ******************************************************************
        //  Issue reset to PORE General Purpose Engine
        //  ******************************************************************
        //     - call p8_poregpe_init.C *chiptarget, ENUM:POREGPE_RESET

        FAPI_INF("Issue reset to PORE General Purpose Engine");
        FAPI_DBG("Executing: p8_poregpe_init.C");

        // Primary
        FAPI_EXEC_HWP(rc, p8_poregpe_init, i_primary_chip_target, PM_RESET, GPEALL );
        if (rc)
        {
            FAPI_ERR("p8_poregpe_init: Failed to issue reset to PORE General Purpose Engine. With rc = 0x%x", (uint32_t)rc);
            break;
        }

        // Secondary
        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
            FAPI_EXEC_HWP(rc, p8_poregpe_init, i_secondary_chip_target, PM_RESET, GPEALL );
            if (rc)
            {
                FAPI_ERR("p8_poregpe_init: Failed to issue reset to PORE General Purpose Engine. With rc = 0x%x", (uint32_t)rc);
                break;
            }
        }

        //  ******************************************************************
        //  Issue reset to PBA
        //  ******************************************************************
        //     - call p8_pba_init.C *chiptarget, ENUM:PBA_RESET
        //

        FAPI_INF("Issue reset to PBA");
        FAPI_DBG("Executing: p8_pba_init.C");

        // Primary
        FAPI_EXEC_HWP(rc, p8_pba_init, i_primary_chip_target, PM_RESET );
        if (rc)
        {
            FAPI_ERR("p8_pba_init: Failed to issue reset to PBA. With rc = 0x%x", (uint32_t)rc);
            break;
        }

        // Secondary
        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
            FAPI_EXEC_HWP(rc, p8_pba_init, i_secondary_chip_target, PM_RESET );
            if (rc)
            {
                FAPI_ERR("p8_pba_init: Failed to issue reset to PBA. With rc = 0x%x", (uint32_t)rc);
                break;
            }
        }

        //  ******************************************************************
        //  Issue reset to OCC-SRAM
        //  ******************************************************************
        //     - call p8_occ_sram_init.C *chiptarget, ENUM:OCC_SRAM_RESET
        //

        FAPI_INF("Issue reset to OCC-SRAM");
        FAPI_DBG("Executing: p8_occ_sram_init.C");

        // Primary
        FAPI_EXEC_HWP(rc, p8_occ_sram_init, i_primary_chip_target, PM_RESET );
        if (rc)
        {
            FAPI_ERR("p8_occ_sram_init: Failed to issue reset to OCC-SRAM. With rc = 0x%x", (uint32_t)rc);
            break;
        }

        // Secondary
        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
            FAPI_EXEC_HWP(rc, p8_occ_sram_init, i_secondary_chip_target, PM_RESET );
            if (rc)
            {
                FAPI_ERR("p8_occ_sram_init: Failed to issue reset to OCC-SRAM. With rc = 0x%x", (uint32_t)rc);
                break;
            }
        }

        //  ******************************************************************
        //  Issue reset to OCB
        //  ******************************************************************
        //     - call p8_ocb_init.C *chiptarget, ENUM:OCC_OCB_RESET

        FAPI_INF("Issue reset to OCB");
        FAPI_DBG("Executing: p8_ocb_init.C");

        // Primary
        FAPI_EXEC_HWP(rc, p8_ocb_init, i_primary_chip_target, PM_RESET,0 , 0, 0, 0, 0, 0 );
        if (rc)
        {
            FAPI_ERR("p8_ocb_init: Failed to issue reset to OCB. With rc = 0x%x", (uint32_t)rc);
            break;
        }

        // Secondary
        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
            FAPI_EXEC_HWP(rc, p8_ocb_init, i_secondary_chip_target, PM_RESET,0 , 0, 0, 0, 0, 0 );
            if (rc)
            {
                FAPI_ERR("p8_ocb_init: Failed to issue reset to OCB. With rc = 0x%x", (uint32_t)rc);
                break;
            }
        }
        
        //  ******************************************************************
        //  Remove the EX chiplet special wakeups
        //  *****************************************************************
                
        // Primary
        rc = special_wakeup_all (i_primary_chip_target, false);
        if (rc)
        {
            FAPI_ERR("special_wakeup_all - Enable: Failed for Target %s", 
                        i_primary_chip_target.toEcmdString());
            break;
        }
                

        // Secondary
        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
            rc = special_wakeup_all (i_secondary_chip_target, false);
            if (rc)
            {
                FAPI_ERR("special_wakeup_all - Enable: Failed for Target %s", 
                            i_secondary_chip_target.toEcmdString());
                break;
            }

        }


    } while(0);

    FAPI_INF("p8_pm_prep_for_reset start  ....");

    return rc;
} // Procedure



/**
 * special_wakeup_all - Sets or clears special wake-up on all configured EX on a 
 *                     target
 *
 * @param[in] i_target   Chip target w
 * @param[in] i_action   true - ENABLE; false - DISABLE
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode
special_wakeup_all (const fapi::Target &i_target, bool i_action)
{
    fapi::ReturnCode                rc;    
    std::vector<fapi::Target>       l_exChiplets;
    uint8_t                         l_ex_number = 0;    
    
    do
    {   
             
        rc = fapiGetChildChiplets (  i_target,
                                     TARGET_TYPE_EX_CHIPLET,
                                     l_exChiplets,
                                     TARGET_STATE_FUNCTIONAL);
        if (rc)
        {
            FAPI_ERR("Error from fapiGetChildChiplets!");
            break;
        }
        
	    // Iterate through the returned chiplets
        for (uint8_t j=0; j < l_exChiplets.size(); j++)
	    {
            
            FAPI_INF("\t%s special wake-up on %s",  
                    i_action ? "Setting" : "Clearing", 
                    l_exChiplets[j].toEcmdString());
            
            // Build the SCOM address
            rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_exChiplets[j], l_ex_number);
            FAPI_DBG("Running special wakeup on ex chiplet %d ", l_ex_number);

            // Set special wakeup for EX
            rc = fapiSpecialWakeup(l_exChiplets[j], i_action);
            if (rc)
            {
                FAPI_ERR("fapiSpecialWakeup: Failed to put CORE %d into special wakeup. With rc = 0x%x",  
                            l_ex_number, (uint32_t)rc);
                break;
            }

        }  // chiplet loop

        // Exit if error
        if  (!rc.ok())
        {
            break;
        }
        
    } while(0);
    return rc;
}



} //end extern C

