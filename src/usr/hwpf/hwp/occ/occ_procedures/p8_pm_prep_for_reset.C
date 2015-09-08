/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_prep_for_reset.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
// $Id: p8_pm_prep_for_reset.C,v 1.31 2015/05/13 03:12:36 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_prep_for_reset.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Greg Still         Email: stillgs@us.ibm.com
// *! OWNER NAME: Ralf Maier         Email: ralf.maier@de.ibm.com
// *!
/// \file p8_pm_prep_for_reset.C
/// \brief Reset Power Management function
///
//------------------------------------------------------------------------------
///
/// High-level procedure flow:
///
/// \verbatim
///
///     do {
///         - Clear the Deep Exit Masks to allow Special Wake-up to occur
///         - Put all EX chiplets in special wakeup
///         - Mask the PM FIRs
///         - Disable PMC OCC HEARTBEAT before halting and reset OCC
///         - Halt and then Reset the PPC405
///             - PMC moves to Vsafe value due to heartbeat loss
///         - Force Vsafe value into voltage controller to cover the case that the
///                 Pstate hardware didn't move correctly
///         - Reset PCBS-PM
///         - Reset PMC
///             As the PMC reset kills ALL of the configuration, the idle portion
///             must be reestablished to allow that portion to operate.
///         - Run SLW Initialiation
///             - This allows special wake-up removal before exit
///         - Reset PSS
///         - Reset GPEs
///         - Reset PBA
///         - Reset SRAM Controller
///         - Reset OCB
///         - Clear special wakeups
///     } while(0);
///
///     if error, clear special wakeups to leave this procedure clean
///
///     SLW engine reset is not done here as this will blow away all setup
///     in istep 15.  Thus, ALL manipulation of this is via calls to
///     p8_poreslw_ioit or by p8_poreslw_recovery.
///
///  \endverbatim
///
///  buildfapiprcd -e "../../xml/error_info/p8_pm_prep_for_reset_errors.xml" -C p8_pm_utils.C p8_pm_prep_for_reset.C
// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------

#include "fapiUtil.H"
#include "p8_pm.H"
#include "p8_pm_utils.H"
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

fapi::ReturnCode
clear_deep_exit_mask (const fapi::Target &i_target);

// FSM trace wrapper
fapi::ReturnCode
p4rs_pcbs_fsm_trace (const fapi::Target& i_primary_target,
                     const fapi::Target& i_secondary_target,
                     const char *        i_msg);

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
    fapi::ReturnCode                rc_hold;
    uint32_t                        e_rc = 0;
    std::vector<fapi::Target>       l_exChiplets;
    ecmdDataBufferBase              data(64);
    ecmdDataBufferBase              mask(64);
    uint64_t                        address = 0;

    const char *        PM_MODE_NAME_VAR; // Defines storage for PM_MODE_NAME

    bool                            b_special_wakeup_pri = false;
    bool                            b_special_wakeup_sec = false;

    fapi::Target dummy;

    do
    {

        FAPI_INF("p8_pm_prep_for_reset start  ....");

        uint8_t ipl_mode = 0;
        rc = FAPI_ATTR_GET(ATTR_IS_MPIPL, NULL, ipl_mode);
        if (!rc.ok())
        {
            FAPI_ERR("fapiGetAttribute of ATTR_IS_MPIPL rc = 0x%x", (uint32_t)rc);
            break;
        }

        FAPI_INF("IPL mode = %s", ipl_mode ? "MPIPL" : "NORMAL");


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
            FAPI_INF("Running on SCM");
        }
        else
        {
            FAPI_INF("Running on DCM");
        }

        // ******************************************************************
        //  Clear the Deep Exit Masks to allow Special Wake-up to occur
        // ******************************************************************
        
        // Primary
        rc = clear_deep_exit_mask(i_primary_chip_target);
        if (rc)
        {
            FAPI_ERR("clear_deep_exit_mask: Failed for Primary Target %s",
                        i_primary_chip_target.toEcmdString());
            break;
        }

        // Secondary
        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
            rc = clear_deep_exit_mask(i_secondary_chip_target);
            if (rc)
            {
                FAPI_ERR("clear_deep_exit_mask: Failed for Secondary Target %s",
                            i_secondary_chip_target.toEcmdString());
                break;
            }
        }


        //  ******************************************************************
        //  FSM trace
        //  ******************************************************************
        rc = p4rs_pcbs_fsm_trace (i_primary_chip_target, i_secondary_chip_target, "start of prep for reset");
        if (!rc.ok())
        {
            break;
        }

        //  ******************************************************************
        //  Put all EX chiplets in special wakeup
        //  *****************************************************************
        //  This is done before FIR masking to ensure that idle functions
        //  are properly monitored

        // Primary
        rc = special_wakeup_all (i_primary_chip_target, true);
        if (rc)
        {
            FAPI_ERR("special_wakeup_all - Enable: Failed for Target %s",
                        i_primary_chip_target.toEcmdString());
            break;
        }
        b_special_wakeup_pri = true;

        rc = p8_pm_glob_fir_trace (i_primary_chip_target, "after SPWKUP");
        if (!rc.ok()) { break; }

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
            b_special_wakeup_sec = true;

            rc = p8_pm_glob_fir_trace (i_secondary_chip_target, "after SPWKUP");
            if (!rc.ok()) { break; }

        }

        //  ******************************************************************
        //  FSM trace
        //  ******************************************************************
        rc = p4rs_pcbs_fsm_trace (i_primary_chip_target, i_secondary_chip_target,
                    "after special wake-up setting");
        if (!rc.ok())
        {
            break;
        }

        //  ******************************************************************
        //  Mask the FIRs as error can occur in what follows
        //  ******************************************************************
        FAPI_INF("Executing:p8_pm_firinit in mode PM_RESET");

        FAPI_EXEC_HWP(rc, p8_pm_firinit, i_primary_chip_target , i_mode );
        if (rc)
        {
            FAPI_ERR("ERROR: p8_pm_firinit detected failed  result");
            break;
        }

        rc = p8_pm_glob_fir_trace (i_primary_chip_target, "after Masking");
        if (!rc.ok()) { break; }

        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {

            FAPI_EXEC_HWP(rc, p8_pm_firinit, i_secondary_chip_target , PM_RESET );
            if (rc)
            {
                FAPI_ERR("ERROR: p8_pm_firinit detected failed  result");
                break;
            }

            rc = p8_pm_glob_fir_trace (i_secondary_chip_target, "after Masking");
            if (!rc.ok()) { break; }
        }

        //  ******************************************************************
        //  FSM trace
        //  ******************************************************************
        rc = p4rs_pcbs_fsm_trace (i_primary_chip_target, i_secondary_chip_target,
                    "after FIR masking");
        if (!rc.ok())
        {
            break;
        }

        //  ******************************************************************
        //  Disable PMC OCC HEARTBEAT before reset OCC
        //  ******************************************************************
        // Primary
        rc = fapiGetScom(i_primary_chip_target, PMC_OCC_HEARTBEAT_REG_0x00062066 , data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(PMC_OCC_HEARTBEAT_REG_0x00062066) failed.");
            break;
        }

        e_rc = data.clearBit(16);
        if (e_rc)
        {
            FAPI_ERR("ecmdDataBufferBase error setting up PMC_OCC_HEARTBEAT_REG_0x00062066 on master during reset");
            rc.setEcmdError(e_rc);
            break;
        }

        rc = fapiPutScom(i_primary_chip_target, PMC_OCC_HEARTBEAT_REG_0x00062066 , data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(PMC_OCC_HEARTBEAT_REG_0x00062066) failed.");
            break;
        }

        // Secondary
        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
        rc = fapiGetScom(i_secondary_chip_target, PMC_OCC_HEARTBEAT_REG_0x00062066 , data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(PMC_OCC_HEARTBEAT_REG_0x00062066) failed.");
            break;
        }

        e_rc = data.clearBit(16);
        if (e_rc)
        {
            FAPI_ERR("ecmdDataBufferBase error setting up PMC_OCC_HEARTBEAT_REG_0x00062066 on slave during reset");
            rc.setEcmdError(e_rc);
            break;
        }

        rc = fapiPutScom(i_secondary_chip_target, PMC_OCC_HEARTBEAT_REG_0x00062066 , data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(PMC_OCC_HEARTBEAT_REG_0x00062066) failed.");
            break;
        }
        }

        //  ******************************************************************
        //  Put OCC PPC405 into reset safely
        //  ******************************************************************
        FAPI_INF("Put OCC PPC405 into reset safely");
        FAPI_DBG("Executing: p8_occ_control.C");

        FAPI_EXEC_HWP(rc, p8_occ_control, i_primary_chip_target, PPC405_RESET_SEQUENCE, 0);
        if (rc)
        {
            FAPI_ERR("p8_occ_control: Failed to prepare OCC for RESET. With rc = 0x%x", (uint32_t)rc);
            break;
        }

        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
            FAPI_EXEC_HWP(rc, p8_occ_control, i_secondary_chip_target, PPC405_RESET_SEQUENCE, 0);
            if (rc)
            {
              FAPI_ERR("p8_occ_control: Failed to prepare OCC for RESET. With rc = 0x%x", (uint32_t)rc);
              break;
            }
        }

        //  ******************************************************************
        //  FSM trace
        //  ******************************************************************
        rc = p4rs_pcbs_fsm_trace (i_primary_chip_target, i_secondary_chip_target,
                    "after OCC Reset");
        if (!rc.ok())
        {
            break;
        }

        //  Check for xstops and recoverables

        rc = p8_pm_glob_fir_trace (i_primary_chip_target, "after OCC Reset");
        if (!rc.ok()) { break; }

        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
            rc = p8_pm_glob_fir_trace (i_secondary_chip_target, "after OCC Reset");
            if (!rc.ok()) { break; }
        }

        //  ******************************************************************
        //  Force Vsafe value into voltage controller
        //  ******************************************************************
        FAPI_INF("Force Vsafe value into voltage controller");
        FAPI_DBG("Executing: p8_pmc_force_vsafe.C");

        // Primary
        //   Secondary passed in for FFDC reasons upon error
        FAPI_EXEC_HWP(rc, p8_pmc_force_vsafe, i_primary_chip_target, i_secondary_chip_target);
        if (rc)
        {
            FAPI_ERR("Failed to force Vsafe value into voltage controller. With rc = 0x%x", (uint32_t)rc);
            break;
        }

        // Secondary
        //   Primary passed in for FFDC reasons upon error
        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
            FAPI_EXEC_HWP(rc, p8_pmc_force_vsafe, i_secondary_chip_target, i_primary_chip_target);
            if (rc)
            {
              FAPI_ERR("Failed to force Vsafe value into voltage controller. With rc = 0x%x", (uint32_t)rc);
              break;
            }
        }

        //  ******************************************************************
        //  FSM trace
        //  ******************************************************************
        rc = p4rs_pcbs_fsm_trace (i_primary_chip_target, i_secondary_chip_target,
                    "after force Vsafe");
        if (!rc.ok())
        {
            break;
        }

        //  Check for xstops and recoverables
        rc = p8_pm_glob_fir_trace (i_primary_chip_target, "after Force Vsafe");
        if (!rc.ok()) { break; }

        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
            rc = p8_pm_glob_fir_trace (i_secondary_chip_target, "after Force Vsafe");
            if (!rc.ok()) { break; }
        }

        //  ******************************************************************
        //  Prepare PCBS_PM for RESET
        //  ******************************************************************
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

        address =  READ_GLOBAL_RECOV_FIR_0x570F001C;
        GETSCOM(rc, i_primary_chip_target, address, data);
        if (data.getNumBitsSet(0,64))
        {
            FAPI_INF("Recoverable attention is **ACTIVE** in prep_for_reset after PCBS reset");
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

            GETSCOM(rc, i_secondary_chip_target, address, data);
            if (data.getNumBitsSet(0,64))
            {
                FAPI_INF("Recoverable attention is **ACTIVE** in prep_for_reset after  PCBS reset");
            }
        }

        //  ******************************************************************
        //  FSM trace
        //  ******************************************************************
        rc = p4rs_pcbs_fsm_trace (i_primary_chip_target, i_secondary_chip_target, "after PCBS reset");
        if (!rc.ok())
        {
            break;
        }

        //  Check for xstops and recoverables
        rc = p8_pm_glob_fir_trace (i_primary_chip_target, "after PCBS reset");
        if (!rc.ok()) { break; }

        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
            rc = p8_pm_glob_fir_trace (i_secondary_chip_target, "after PCBS reset");
            if (!rc.ok()) { break; }
        }

        //  ******************************************************************
        //  Reset PMC
        //  ******************************************************************
        FAPI_INF("Issue reset to PMC");
        FAPI_DBG("Executing: p8_pmc_init");

        FAPI_EXEC_HWP(rc, p8_pmc_init, i_primary_chip_target, i_secondary_chip_target, i_mode);
        if (rc)
        {
            FAPI_ERR("p8_pmc_init: Failed to issue PMC reset. With rc = 0x%x", (uint32_t)rc);
            break;
        }

        //  ******************************************************************
        //  FSM trace
        //  ******************************************************************
        rc = p4rs_pcbs_fsm_trace (i_primary_chip_target, i_secondary_chip_target,
                    "after PMC reset");
        if (!rc.ok())
        {
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

        //  Check for xstops and recoverables
        rc = p8_pm_glob_fir_trace (i_primary_chip_target,  "after PMC and SLW reinit");
        if (!rc.ok()) { break; }

        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
            rc = p8_pm_glob_fir_trace (i_secondary_chip_target,  "after PMC and SLW reinit");
            if (!rc.ok()) { break; }
        }

        //  ******************************************************************
        //  Issue reset to PSS macro
        //  ******************************************************************
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
        //  Note:  this voids the channel used by the SLW engine
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
        //  Check for xstops and recoverables
        rc = p8_pm_glob_fir_trace (i_primary_chip_target, "after PBA reset");
        if (!rc.ok()) { break; }

        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
            rc = p8_pm_glob_fir_trace (i_secondary_chip_target, "after PBA reset");
            if (!rc.ok()) { break; }
        }

        //  ******************************************************************
        //  Issue reset to OCC-SRAM
        //  ******************************************************************
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

        //  Check for xstops and recoverables
        rc = p8_pm_glob_fir_trace (i_primary_chip_target, "after OCB reset");
        if (!rc.ok()) { break; }

        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
            rc = p8_pm_glob_fir_trace (i_secondary_chip_target, "after OCB reset");
            if (!rc.ok()) { break; }
        }
        //  ******************************************************************
        //  Remove the EX chiplet special wakeups
        //  *****************************************************************

        // Primary
        rc = special_wakeup_all (i_primary_chip_target, false);
        if (rc)
        {
            FAPI_ERR("special_wakeup_all - Disable: Failed for Target %s",
                        i_primary_chip_target.toEcmdString());
            break;
        }
        b_special_wakeup_pri = false;


        // Secondary
        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
            rc = special_wakeup_all (i_secondary_chip_target, false);
            if (rc)
            {
                FAPI_ERR("special_wakeup_all - Disable: Failed for Target %s",
                            i_secondary_chip_target.toEcmdString());
                break;
            }

            b_special_wakeup_sec = false;
        }


        //  ******************************************************************
        //  FSM trace
        //  ******************************************************************
        rc = p4rs_pcbs_fsm_trace (i_primary_chip_target, i_secondary_chip_target,
                    "after special wake-up clearing");
        if (!rc.ok())
        {
            break;
        }

        //  Check for xstops and recoverables
        rc = p8_pm_glob_fir_trace (i_primary_chip_target, "after special wake-up clearing");
        if (!rc.ok()) { break; }

        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
            rc = p8_pm_glob_fir_trace (i_secondary_chip_target, "after special wake-up clearing");
            if (!rc.ok()) { break; }
        }

    } while(0);


    // Clear special wakeups that might have been set before a subsequent
    // error occured.  Only attempts them on targets that have the boolean
    // flag set that they were successfully put into special wakeup.
    if (!rc.ok())
    {
        // Save the original RC
        rc_hold = rc;

        do
        {
            // Primary
            if (b_special_wakeup_pri)
            {
                // Primary
                rc = special_wakeup_all (i_primary_chip_target, false);
                if (rc)
                {
                    FAPI_ERR("special_wakeup_all - Disable: Failed during cleanup from a previous error for Target %s",
                                i_primary_chip_target.toEcmdString());
                    FAPI_ERR("special_wakeup_all - Disable: The original error is being returned");
                    fapiLogError(rc, fapi::FAPI_ERRL_SEV_RECOVERED);
                    break;
                }
            }

            // Secondary
            if (b_special_wakeup_sec)
            {
                rc = special_wakeup_all (i_secondary_chip_target, false);
                if (rc)
                {
                    FAPI_ERR("special_wakeup_all - Disable: Failed during cleanup from a previous error for Target %s",
                                i_primary_chip_target.toEcmdString());
                    FAPI_ERR("special_wakeup_all - Disable: The original error is being returned");
                    fapiLogError(rc, fapi::FAPI_ERRL_SEV_RECOVERED);
                    break;
                }
            }
        } while(0);

        // Restore the original RC
        rc = rc_hold;
    }

    FAPI_INF("p8_pm_prep_for_reset end ....");

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

/**
 * clear deep exit mask
 *
 * @param[in] i_target   Chip target w
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode
clear_deep_exit_mask (const fapi::Target &i_target)
{
    fapi::ReturnCode      rc;
    ecmdDataBufferBase    data(64);

    do
    {
        
        FAPI_INF("Clearing PMC Deep Exit Mask");
        
        // Read the present values for debug
        rc = fapiGetScom(i_target, PMC_DEEPEXIT_MASK_0x00062092, data);
        if(!rc.ok())
        {
            FAPI_ERR("Scom error reading PMC_DEEPEXIT_MASK_0x00062092");
            break;
        }
        
        FAPI_INF("PMC Deep Exit Mask value before clearing:  0x%16llX",
                        data.getDoubleWord(0));

        // Clear the PMC Deep Exit Mask
        data.flushTo0();
        rc = fapiPutScom(i_target, PMC_DEEPEXIT_MASK_0x00062092, data);
        if(!rc.ok())
        {
            FAPI_ERR("Scom error reading PMC_DEEPEXIT_MASK_0x00062092");
            break;
        }
        
        rc = fapiGetScom(i_target, PMC_DEEPEXIT_MASK_0x00062092, data);
        if(!rc.ok())
        {
            FAPI_ERR("Scom error reading PMC_DEEPEXIT_MASK_0x00062092");
            break;
        }
        
        FAPI_INF("PMC Deep Exit Mask value after clearing:   0x%16llX",
                        data.getDoubleWord(0));

    } while(0);
    return rc;
}


//------------------------------------------------------------------------------
/**
 * Trace PCBS FSMs across primary and secondary chips
 *
 * @param[in] i_target Chip target
 * @param[in] i_msg    String to put out in the trace
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode
p4rs_pcbs_fsm_trace(const fapi::Target& i_primary_target,
                    const fapi::Target& i_secondary_target,
                    const char *       i_msg)
{
    fapi::ReturnCode                rc;

    do
    {

        rc = p8_pm_pcbs_fsm_trace_chip (i_primary_target, i_msg);
        if (rc)
        {
            FAPI_ERR("pcbs_fsm_trace_chip failed for Target %s",
                        i_primary_target.toEcmdString());
            break;
        }

        if ( i_secondary_target.getType() != TARGET_TYPE_NONE )
        {
            rc = p8_pm_pcbs_fsm_trace_chip (i_secondary_target, i_msg);
            if (rc)
            {
                FAPI_ERR("pcbs_fsm_trace_chip failed for Target %s",
                            i_secondary_target.toEcmdString());
                break;
            }
        }
    } while(0);
    return rc;
}

} //end extern C

