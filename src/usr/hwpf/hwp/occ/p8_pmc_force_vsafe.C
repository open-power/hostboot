/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/p8_pmc_force_vsafe.C $                   */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: p8_pmc_force_vsafe.C,v 1.16 2014/03/21 01:16:09 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pmc_force_vsafe.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Joe Procwriter         Email: asmartpersion@xx.ibm.com
// *!
// *! General Description: Forces the PMC to VSAFE mode
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
//  buildfapiprcd -e ../../xml/error_info/p8_force_vsafe_errors.xml,../../xml/error_info/p8_pstate_registers.xml p8_pmc_force_vsafe.C

// -----------------------------------------------------------------------------
//             Write a voltage value into
//             PVSAFE  - PMC_PARAMETER_REG1
// Actually, this value will be been written outside this procedure by the OCC pstate installation routine after the p8_build_pstate runs to build
// the Pstate superstructure.  We had identified a HWP ATTR (ATTR_PM_PVSAFE_PSTATE)  to be used by p8_pmc_init to set this up originally but we're
// going away from that approach so that we have             all things about  Pstates being done in one place (the OCC pstate installation routine).
// So, this step should not exist in the p8_pmc_force_vsafe procedure;        rather, you should write a value into the hardware with a script that
// represents what the OCC pstate install routine would have done

//                     ------------------
//               | Procedure Starts |
//                     ------------------
//                |
//                |
//                V
//             Write into PMC_OCC_HEARTBEAT_REG
//             PMC_OCC_HEARTBEAT_TIME  - Write the field to 0 to cause an immediate heartbeat loss.
//             PMC_OCC_HEARTBEAT_EN  - this bit needs to be 1 to acually cause the 0 time value to trigger the heartbeat loss.
//                |
//                |
//                V
//             POLL PMC_STATUS_REG (8)
//             VOLT_CHG_ONGOING (bit 8)   Yes... this bit needs to be 0 to indicate that the voltage controller is at its target.

// 1.3V Turbo to 0.8V (most of the supported range) in 25mV steps (the eVRM step size with iVRMs enabled)  is 20 steps which, at 12.5mV/5us rate
// (a modest time), yields 8us.   Given this an error case, we need a conservative time.           So let's set the timeout at 100us for the lab.
// To test the timeout, clear PMC.PMC_MODE_REG (3) (with a script) so that the PMC won't respond.




//             Check that the other bits in PMC_STATUS_REG do not indicate errors (eg they should be all zeros).  If any are 1
//                |         ^
//                |         |
//                V         |
//             timeout ------

// ----------------------------------------------------------------------
// Flowchart Ends
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <fapi.H>
#include "p8_scom_addresses.H"

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


// function: xxx
/// \param[in] i_target Chip target
// returns: ECMD_SUCCESS if something good happens,
//          BAD_RETURN_CODE otherwise
fapi::ReturnCode
p8_pmc_force_vsafe( const fapi::Target& i_target,
                    const fapi::Target& i_dcm_target)
{
    fapi::ReturnCode    rc;
    ecmdDataBufferBase  data(64);
    ecmdDataBufferBase  pmcstatusreg(64);
    uint32_t            e_rc = 0;

    // maximum number of status poll attempts to make before giving up
    const uint32_t   MAX_POLL_ATTEMPTS    = 0x200;

    uint32_t            count = 0;
    uint16_t            pvsafe = 0;
    bool                l_set;
    uint16_t            pstate_target = 0;
    uint16_t            pstate_step_target = 0;
    uint16_t            pstate_actual = 0;
    uint8_t             DONE_FLAG = 0;
    uint8_t             pmc_error = 0;
    uint8_t             intchp_error = 0;
    uint8_t             any_error = 0;
    uint8_t             any_ongoing = 0;
    uint8_t             dummy = 0;

    FAPI_INF("p8_pmc_force_vsafe start to primary target %s",
                            i_target.toEcmdString());

    do
    {
        //  ******************************************************************
        //     -  PMC_MODE_REG checking
        //  ******************************************************************
        rc = fapiGetScom(i_target, PMC_MODE_REG_0x00062000, data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(PMC_MODE_REG_0x00062000) failed.");
            break;
        }


        if ( (data.isBitClear(0) && data.isBitClear(1) ))
        {
            FAPI_INF("PMC is not in HARDWARE or FIRMWARE AUCTION MODE so hardware mechanism cannot be used.");
            break;
        }

        if ( ( data.isBitClear(3) ))
        {
            FAPI_ERR("PMC is disabled for Voltage changes");
            const fapi::Target & CHIP = i_target;
            const uint64_t & PMCMODE  = data.getDoubleWord(0);
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_VOLTAGE_CHANGE_MODE_ERR);
            break;
        }

        if ( ( !data.isBitClear(5) ))
        {
            FAPI_ERR("PMC is disabled PMC_MASTER_SEQUENCER");
            const fapi::Target & CHIP = i_target;
            const uint64_t & PMCMODE  = data.getDoubleWord(0);
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_MST_SEQUENCER_STATE_ERR);
            break;
        }

        //  ****************************************************************************
        //     -  PMC_STATE_MONITOR_AND_CTRL_REG PMC_PARAMETER_REG1 before the psafe
        //  ****************************************************************************

        rc = fapiGetScom(i_target, PMC_PARAMETER_REG1_0x00062006, data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(PMC_PARAMETER_REG1_0x00062006) failed.");
            break;
        }

        e_rc |= data.extractToRight( &pvsafe,22,8);
        if (e_rc)
        {
            rc.setEcmdError(e_rc);
            break;
        }

        rc = fapiGetScom(i_target, PMC_PSTATE_MONITOR_AND_CTRL_REG_0x00062002, data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(PMC_PSTATE_MONITOR_AND_CTRL_REG_0x00062002) failed.");
            break;
        }

        e_rc |= data.extractToRight( &pstate_target,0,8);
        e_rc |= data.extractToRight( &pstate_step_target,8,8);
        e_rc |= data.extractToRight( &pstate_actual,16,8);
        if (e_rc)
        {
            rc.setEcmdError(e_rc);
            break;
        }

        FAPI_INF(" voltage values before the hearbeat loss " );
        FAPI_INF(" pvsafe => %x     , ptarget => %x   , pstarget  => %x ,pactual  =>  %x " , pvsafe , pstate_target ,pstate_step_target , pstate_actual);

        //  ******************************************************************
        //     -  SEE PMC_STATUS_REG if debug_mode ==1
        //  ******************************************************************

        rc = fapiGetScom(i_target, PMC_STATUS_REG_0x00062009, data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(PMC_STATUS_REG_0x00062009) failed.");
            break;
        }
        FAPI_DBG("   debug_mode : status_b4_heartbeat_loss      =>  0x%16llx",  data.getDoubleWord(0));

        l_set = data.isBitSet(0);
        FAPI_DBG("   pstate_processing_is_susp     => %x ",  l_set ) ;
        l_set = data.isBitSet(1);
        FAPI_DBG("   gpsa_bdcst_error              => %x ",  l_set );

        e_rc = data.extractToRight( &dummy,2,3);
        if (e_rc)
        {
            rc.setEcmdError(e_rc);
            break;
        }
        FAPI_DBG("   gpsa_bdcst_resp_info          => %x ",  dummy );
        l_set = data.isBitSet(5);
        FAPI_DBG("   gpsa_vchg_error               => %x ",  l_set );
        l_set = data.isBitSet(6);
        FAPI_DBG("   gpsa_timeout_error            => %x ",  l_set );
        l_set = data.isBitSet(7);
        FAPI_DBG("   gpsa_chg_ongoing              => %x ",  l_set );
        l_set = data.isBitSet(8);
        FAPI_DBG("   volt_chg_ongoing              => %x ",  l_set );
        l_set = data.isBitSet(9);
        FAPI_DBG("   brd_cst_ongoing               => %x ",  l_set );
        l_set = data.isBitSet(10);
        FAPI_DBG("   gpsa_table_error              => %x ",  l_set );
        l_set = data.isBitSet(11);
        FAPI_DBG("   pstate_interchip_error        => %x ",  l_set );
        l_set = data.isBitSet(12);
        FAPI_DBG("   istate_processing_is_susp     => %x ",  l_set );


        //  ******************************************************************
        //     -  PMC_OCC_HEARTBEAT_REG
        //  ******************************************************************

        FAPI_INF("Forcing PMC Heartbeat loss                  ");

        e_rc |= data.flushTo0();
        e_rc |= data.setBit(16);
        if (e_rc)
        {
            rc.setEcmdError(e_rc);
            break;
        }

        rc = fapiPutScom(i_target, PMC_OCC_HEARTBEAT_REG_0x00062066, data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(PMC_OCC_HEARTBEAT_REG_0x00062066) failed.");
            break;
        }

        // delay to reduce number of polling loops
        rc = fapiDelay(1000, 1000);

        //  ******************************************************************
        //       POLL for PMC_STATUS_REG --> BIT_8 to go to 0 or any errors
        //  ******************************************************************
        FAPI_DBG("Start polling for ongoing to go low ... ");
        // Loop only if count is less thean poll attempts and DONE_FLAG = 0 and no error
        for(count=0; ((count<=MAX_POLL_ATTEMPTS) && (DONE_FLAG == 0) && (any_error == 0)); count++)
        {
            rc = fapiGetScom(i_target, PMC_STATUS_REG_0x00062009, pmcstatusreg );
            if (rc)
            {
                FAPI_ERR("fapiGetScom(PMC_STATUS_REG_0x00062009) failed.");
                break;
            }

            FAPI_DBG("   PMC Status poll  => 0x%16llx",  pmcstatusreg.getDoubleWord(0));

            pmc_error = (   pmcstatusreg.isBitSet(1)  ||    // GPSA_BDCST_ERROR
                            pmcstatusreg.isBitSet(5)  ||    // GPSA_VCHG_ERROR
                            pmcstatusreg.isBitSet(6)  ||    // GPSA_TIMEOUT_ERROR
                            pmcstatusreg.isBitSet(10) ||    // GPS_TABLE_ERROR
                            pmcstatusreg.isBitSet(12)   );  // ISTATE_PROCESSING_IS_SUSPENDED

            any_ongoing = ( pmcstatusreg.isBitSet(7) ||     // GPSA_CHG_ONGOING
                            pmcstatusreg.isBitSet(8) ||     // VOLT_CHG_ONGOING
                            pmcstatusreg.isBitSet(9)   );   // BRD_CST_ONGOING

                       
            // If there is an interchip error, determine if it is expected or not
            // Unexpected:  gpsa_timeout or ECC UE error
            if (pmcstatusreg.isBitSet(11))                  // PSTATE_INTERCHIP_ERROR
            {
                rc = fapiGetScom(i_target, PMC_INTCHP_STATUS_REG_0x00062013, data );
                if (rc)
                {
                    FAPI_ERR("fapiGetScom(PMC_STATUS_REG_0x00062009) failed.");
                    break;
                }
                
                intchp_error = (data.isBitSet(18) ||        // GPSA_TIMEOUT_ERROR
                                data.isBitSet(19)   );      // ECC UE ERROR                
            }
            
            any_error = (pmc_error || intchp_error);
            
            // Check for voltage change has any error
            if (any_error)
            {
                // An error was detected
                FAPI_INF(" PMC_STATUS_REG upon Error");
                if (pmcstatusreg.isBitSet(0))
                    FAPI_ERR("   pstate_processing_is_susp active");
                if (pmcstatusreg.isBitSet(1))
                    FAPI_ERR("   gpsa_bdcst_error active");

                e_rc = pmcstatusreg.extractToRight( &dummy,2,3);
                if (e_rc)
                {
                    rc.setEcmdError(e_rc);
                    break;
                }
                if (dummy)
                    FAPI_ERR("   gpsa_bdcst_resp_info is non-zero => %x ",  dummy );

                if (pmcstatusreg.isBitSet(5))
                    FAPI_ERR("   gpsa_vchg_error active");
                if (pmcstatusreg.isBitSet(6))
                    FAPI_ERR("   gpsa_timeout_error active");
                if (pmcstatusreg.isBitSet(7))
                    FAPI_ERR("   gpsa_chg_ongoing active");
                if (pmcstatusreg.isBitSet(8))
                    FAPI_ERR("   volt_chg_ongoing active");
                if (pmcstatusreg.isBitSet(9))
                    FAPI_ERR("   brd_cst_ongoing active");
                if (pmcstatusreg.isBitSet(10))
                    FAPI_ERR("   gpsa_table_error active");
                if (pmcstatusreg.isBitSet(11))
                    FAPI_ERR("   pstate_interchip_error active");
                if (pmcstatusreg.isBitSet(12))
                    FAPI_ERR("   istate_processing_is_susp active");

                FAPI_ERR("Error detected with PMC on-going deassertion during safe voltage movement ");
                const fapi::Target & THISCHIP = i_target;
                const fapi::Target & DCMCHIP = i_dcm_target;
                FAPI_SET_HWP_ERROR(rc, RC_PROCPM_VLT_ERROR);
                break;

            } // end of error if
            else if (any_ongoing == 0)
            {
                // Voltage change done (not on-going) and not errors
                FAPI_INF("PMC completed performing safe mode transition");                                
                l_set = pmcstatusreg.isBitSet(0);
                if (l_set) FAPI_INF("   pstate_processing_is_susp => %x ",  l_set ) ;
                
                l_set = pmcstatusreg.isBitSet(1);
                if (l_set) FAPI_INF("   gpsa_bdcst_error          => %x ",  l_set );

                e_rc = pmcstatusreg.extractToRight( &dummy,2,3);
                if (e_rc)
                {
                    rc.setEcmdError(e_rc);
                    break;
                }
                if (l_set) FAPI_INF("   gpsa_bdcst_resp_info      => %x ",  dummy );
                
                l_set = pmcstatusreg.isBitSet(5);
                if (l_set) FAPI_INF("   gpsa_vchg_error           => %x ",  l_set );
                              
                l_set = pmcstatusreg.isBitSet(6);
                if (l_set) FAPI_INF("   gpsa_timeout_error        => %x ",  l_set );
                
                l_set = pmcstatusreg.isBitSet(7);
                if (l_set) FAPI_INF("   gpsa_chg_ongoing          => %x ",  l_set );
                
                l_set = pmcstatusreg.isBitSet(8);
                if (l_set) FAPI_INF("   volt_chg_ongoing          => %x ",  l_set );
                
                l_set = pmcstatusreg.isBitSet(9);
                if (l_set) FAPI_INF("   brd_cst_ongoing           => %x ",  l_set );
                
                l_set = pmcstatusreg.isBitSet(10);
                if (l_set) FAPI_INF("   gpsa_table_error          => %x ",  l_set );
                
                l_set = pmcstatusreg.isBitSet(11);
                if (l_set) FAPI_INF("   pstate_interchip_error    => %x ",  l_set );
                
                l_set = pmcstatusreg.isBitSet(12);
                if (l_set) FAPI_INF("   istate_processing_is_susp => %x ",  l_set );
                

                rc = fapiGetScom(i_target, PMC_PARAMETER_REG1_0x00062006, data );
                if (rc)
                {
                    FAPI_ERR("fapiGetScom(PMC_PARAMETER_REG1_0x00062006) failed.");
                    break;
                }

                e_rc = data.extractToRight( &pvsafe,22,8);
                if (e_rc)
                {
                    rc.setEcmdError(e_rc);
                    break;
                }

                rc = fapiGetScom(i_target, PMC_PSTATE_MONITOR_AND_CTRL_REG_0x00062002, data );
                if (rc)
                {
                    FAPI_ERR("fapiGetScom(PMC_PSTATE_MONITOR_AND_CTRL_REG_0x00062002) failed.");
                    break;
                }

                e_rc |= data.extractToRight( &pstate_target,0,8);
                e_rc |= data.extractToRight( &pstate_step_target,8,8);
                e_rc |= data.extractToRight( &pstate_actual,16,8);
                if (e_rc)
                {
                    rc.setEcmdError(e_rc);
                    break;
                }
                FAPI_INF(" pvsafe => %x     , ptarget => %x   , pstarget  => %x ,pactual  =>  %x " , pvsafe , pstate_target ,pstate_step_target , pstate_actual);

                // Check that PVSAFE Pstate (in PMC Parameter Reg1) is the value
                // in the voltage stepper in the following fields of
                // PMC_STATE_MONITOR_AND_CRTL_REG
                // 0:7      - Global Pstate Target
                // 8:15     - Global Pstate Step Target
                // 16:23    - Global Pstate Actual
                // if the above do not match, post an error
                if (pstate_target != pvsafe || pstate_step_target != pvsafe || pstate_actual != pvsafe )
                {
                    FAPI_ERR("Pstate monitor and control register targets did not match");
                    const fapi::Target & THISCHIP = i_target;
                    const fapi::Target & DCMCHIP = i_dcm_target;
                    const uint64_t & PSTATETARGET = (uint64_t)pstate_target;
                    const uint64_t & PSTATESTEPTARGET = (uint64_t)pstate_step_target;
                    const uint64_t & PSTATEACTUAL = (uint64_t)pstate_actual;
                    FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PSTATE_MONITOR_ERR);
                    break;
                }
                DONE_FLAG = 1;
            }
            else  // voltage change is ongoing so wait and then poll again
            {

                // wait for 1 millisecond in hardware
                rc = fapiDelay(1000*1000, 20000000);
                if (rc)
                {
                    FAPI_ERR("fapi delay ends up with error");
                    break;
                }
            }
        }  // For loop
        // Inner loop error check
        if (!rc.ok())
        {
            break;
        }

        // Check if the above loop timed out
        if (count>=MAX_POLL_ATTEMPTS)
        {
            FAPI_ERR("Timed out wait for voltage change on-going to drop");
            const uint64_t & PSTATETARGET = (uint64_t)pstate_target;
            const uint64_t & PSTATESTEPTARGET = (uint64_t)pstate_step_target;
            const uint64_t & PSTATEACTUAL = (uint64_t)pstate_actual;
            const fapi::Target & THISCHIP = i_target;
            const fapi::Target & DCMCHIP = i_dcm_target;
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_VLT_TIMEOUT);
            break;
        }

    } while(0);

    FAPI_INF("p8_pmc_force_vsafe end  ....");

    return rc ;
} // Procedure

} //end extern C
