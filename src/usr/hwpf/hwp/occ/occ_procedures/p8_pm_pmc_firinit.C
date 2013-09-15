/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_pmc_firinit.C $     */
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
// $Id: p8_pm_pmc_firinit.C,v 1.15 2013/08/26 12:44:38 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_pmc_firinit.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Pradeep CN         Email: pradeepcn@in.ibm.com
// *!
// *! General Description: Configures the FIR errors
// *!
// *!   The purpose of this procedure is to ......
// *!
// *!   High-level procedure flow:
// *!     o Set the particluar bits of databuffers action0 , action 1 and mask for the correspoding actions via MACROS
// *!     o Write the action1 , actionn0 and mask registers of FIRs
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
#include <fapi.H>
#include "p8_scom_addresses.H"
#include "p8_pm_pmc_firinit.H"

extern "C" {

using namespace fapi;

// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------


 // ----------------------------------------------------------------------
// Macro definitions
// ----------------------------------------------------------------------
// ALL the below Macros are calling other macros SET_FIR_ACTION / SET_FIR_MASK .
// Whcih are present in p8_pm_firinit.H
// #define SET_CHECK_STOP(b){SET_FIR_ACTION(b, 0, 0);}
// #define SET_RECOV_ATTN(b){SET_FIR_ACTION(b, 0, 1);}
// #define SET_RECOV_INTR(b){SET_FIR_ACTION(b, 1, 0);}
// #define SET_MALF_ALERT(b){SET_FIR_ACTION(b, 1, 1);}
// #define SET_FIR_MASKED(b){SET_FIR_MASK(b,1);}

// ----------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// function: FAPI p8_pm_pmc_firinit  HWP entry point
//           operates on chips passed in i_target argument to perform
//           desired settings of FIRS of PMC macro
// parameters: i_target        => chip target

// returns: FAPI_RC_SUCCESS if all specified operations complete successfully,
//          else return code for failing operation
//------------------------------------------------------------------------------

fapi::ReturnCode
p8_pm_pmc_firinit(const fapi::Target& i_target , uint32_t mode  )
{
    fapi::ReturnCode    rc;
    ecmdDataBufferBase  fir(64);
    ecmdDataBufferBase  action_0(64);
    ecmdDataBufferBase  action_1(64);
    ecmdDataBufferBase  mask(64);
    uint32_t            e_rc = 0;

   
    FAPI_DBG("Executing p8_pm_pmc_firinit  ...");
    do
    {
        if (mode == PM_RESET)
        {
            FAPI_INF("Hard reset detected.  Full PMC LFIR is masked");
            e_rc  = mask.flushTo0();
            e_rc |= mask.setBit(0,PMC_FIR_REGISTER_LENGTH);
            if (e_rc)
            {
                rc.setEcmdError(e_rc);
                break;
            }

            //--******************************************************************************
            //-- PMC_FIR_MASK (W0_OR_45) (WR_43) (WO_AND_44)
            //--******************************************************************************
            rc = fapiPutScom(i_target, PMC_LFIR_MASK_0x01010843, mask );
            if (rc)
            {
	            FAPI_ERR("fapiPutScom(PMC_LFIR_MASK_0x01010843) failed.");
                break;
            }
        }
        else if (mode == PM_RESET_SOFT)
        {
            FAPI_INF("Soft reset detected.  Only non-idle PMC LFIR bits are masked");
            // Only mask the bits that that do not deal with SLW
            rc = fapiGetScom(i_target, PMC_LFIR_MASK_0x01010843, mask );
            if (rc)
            {
	            FAPI_ERR("fapiGetScom(PMC_LFIR_MASK_0x01010843) failed.");
                break;
            }
                                           
            // The following is done to keep SIMICS model from complaining about
            // setting non-implemented bits.

            e_rc |= mask.setBit(0,IDLE_PORESW_FATAL_ERR);
            e_rc |= mask.setBit(IDLE_INTERNAL_ERR+1,
                                PMC_FIR_REGISTER_LENGTH-IDLE_INTERNAL_ERR);
            if (e_rc)
            {
                rc.setEcmdError(e_rc);
                break;
            }

            //--******************************************************************************
            //-- PMC_FIR_MASK (W0_OR_45) (WR_43) (WO_AND_44)
            //--******************************************************************************
            rc = fapiPutScom(i_target, PMC_LFIR_MASK_0x01010843, mask );
            if (rc)
            {
	            FAPI_ERR("fapiPutScom(PMC_LFIR_MASK_0x01010843) failed.");
                break;
            }
        }
        else
        {            
            e_rc |= fir.flushTo0();
            e_rc |= action_0.flushTo0();
            e_rc |= action_1.flushTo0();
            e_rc |= mask.flushTo0()    ;
            if (e_rc)
            {
                rc.setEcmdError(e_rc);
                break;
            }

            SET_RECOV_INTR(PSTATE_OCI_MASTER_RDERR                 ); // pstate_oci_master_rderr
            SET_RECOV_INTR(PSTATE_OCI_MASTER_RDDATA_PARITY_ERR     ); // pstate_oci_master_rddata_parity_err
            SET_RECOV_INTR(PSTATE_GPST_CHECKBYTE_ERR               ); // pstate_gpst_checkbyte_err
            SET_RECOV_INTR(PSTATE_GACK_TO_ERR                      ); // pstate_gack_to_err
            SET_RECOV_INTR(PSTATE_PIB_MASTER_NONOFFLINE_ERR        ); // pstate_pib_master_nonoffline_err
            SET_RECOV_INTR(PSTATE_PIB_MASTER_OFFLINE_ERR           ); // pstate_pib_master_offline_err
            SET_RECOV_INTR(PSTATE_OCI_MASTER_TO_ERR                ); // pstate_oci_master_to_err
            SET_RECOV_INTR(PSTATE_INTERCHIP_UE_ERR                 ); // pstate_interchip_ue_err
            SET_RECOV_INTR(PSTATE_INTERCHIP_ERRORFRAME_ERR         ); // pstate_interchip_errorframe_err
            SET_RECOV_INTR(PSTATE_MS_FSM_ERR                       ); // pstate_ms_fsm_err
            SET_MALF_ALERT(MS_COMP_PARITY_ERR                      ); // ms_comp_parity_err
            SET_MALF_ALERT(IDLE_PORESW_FATAL_ERR                   ); // idle_poresw_fatal_err
            SET_MALF_ALERT(IDLE_PORESW_STATUS_RC_ERR               ); // idle_poresw_status_rc_err
            SET_MALF_ALERT(IDLE_PORESW_STATUS_VALUE_ERR            ); // idle_poresw_status_value_err
            SET_MALF_ALERT(IDLE_PORESW_WRITE_WHILE_INACTIVE_ERR    ); // idle_poresw_write_while_inactive_err
            SET_MALF_ALERT(IDLE_PORESW_TIMEOUT_ERR                 ); // idle_poresw_timeout_err
            SET_FIR_MASKED(IDLE_OCI_MASTER_WRITE_TIMEOUT_ERR       ); // idle_oci_master_write_timeout_err
            SET_MALF_ALERT(IDLE_INTERNAL_ERR                       ); // idle_internal_err
            SET_MALF_ALERT(INT_COMP_PARITY_ERR                     ); // int_comp_parity_err
            SET_FIR_MASKED(PMC_OCC_HEARTBEAT_TIMEOUT               ); // pmc_occ_heartbeat_timeout
            SET_FIR_MASKED(SPIVID_CRC_ERROR0                       ); // spivid_crc_error0
            SET_FIR_MASKED(SPIVID_CRC_ERROR1                       ); // spivid_crc_error1
            SET_FIR_MASKED(SPIVID_CRC_ERROR2                       ); // spivid_crc_error2
            SET_FIR_MASKED(SPIVID_RETRY_TIMEOUT                    ); // spivid_retry_timeout
            SET_FIR_MASKED(SPIVID_FSM_ERR                          ); // spivid_fsm_err
            SET_FIR_MASKED(SPIVID_MAJORITY_DETECTED_A_MINORITY     ); // spivid_majority_detected_a_minority
            SET_FIR_MASKED(O2S_CRC_ERROR0                          ); // o2s_crc_error0
            SET_FIR_MASKED(O2S_CRC_ERROR1                          ); // o2s_crc_error1
            SET_FIR_MASKED(O2S_CRC_ERROR2                          ); // o2s_crc_error2
            SET_FIR_MASKED(O2S_RETRY_TIMEOUT                       ); // o2s_retry_timeout
            SET_FIR_MASKED(O2S_WRITE_WHILE_BRIDGE_BUSY_ERR         ); // o2s_write_while_bridge_busy_err
            SET_FIR_MASKED(O2S_FSM_ERR                             ); // o2s_fsm_err
            SET_FIR_MASKED(O2S_MAJORITY_DETECTED_A_MINORITY        ); // o2s_majority_detected_a_minority
            SET_FIR_MASKED(O2P_WRITE_WHILE_BRIDGE_BUSY_ERR         ); // o2p_write_while_bridge_busy_err
            SET_FIR_MASKED(O2P_FSM_ERR                             ); // o2p_fsm_err
            SET_FIR_MASKED(OCI_SLAVE_ERR                           ); // oci_slave_err
            SET_MALF_ALERT(IF_COMP_PARITY_ERR                      ); // if_comp_parity_err 37:46   spare_fir
            SET_RECOV_ATTN(FIR_PARITY_ERR_DUP                      ); // fir_parity_err_dup
            SET_RECOV_ATTN(FIR_PARITY_ERR                          ); // fir_parity_err

            if (e_rc)
            {
                rc.setEcmdError(e_rc);
                break;
            }

            FAPI_DBG(" action_0  => 0x%16llx ",  action_0.getDoubleWord(0));
            FAPI_DBG(" action_1  => 0x%16llx ",  action_1.getDoubleWord(0));
            FAPI_DBG(" mask      => 0x%16llx ",  mask.getDoubleWord(0));

            //#--******************************************************************************
            //#-- PMC_FIR - clear
            //#--******************************************************************************

            rc = fapiPutScom(i_target, PMC_LFIR_0x01010840, fir);
            if (rc)
            {
                  FAPI_ERR("fapiPutScom(PMC_LFIR_0x01010840) failed.");
                  break;
            }

            //#--******************************************************************************
            //#-- PMC_FIR_ACTION0
            //#--******************************************************************************

            rc = fapiPutScom(i_target, PMC_LFIR_ACT0_0x01010846, action_0 );
            if (rc)
            {
                  FAPI_ERR("fapiPutScom(PMC_LFIR_ACT0_0x01010846) failed.");
                  break;
            }

            //#--******************************************************************************
            //#-- PMC_FIR_ACTION1
            //#--******************************************************************************

            rc = fapiPutScom(i_target, PMC_LFIR_ACT1_0x01010847, action_1 );
            if (rc)
            {
                FAPI_ERR("fapiPutScom(PMC_LFIR_ACT1_0x01010847) failed.");
                break;
            }

            //--******************************************************************************
            //-- PMC_FIR_MASK (W0_OR_45) (WR_43) (WO_AND_44)
            //--******************************************************************************
            rc = fapiPutScom(i_target, PMC_LFIR_MASK_0x01010843, mask );
            if (rc)
            {
                FAPI_ERR("fapiPutScom(PMC_LFIR_MASK_0x01010843) failed.");
                break;
            }
        }
    } while(0);

    return rc ;

} // Procedure


} //end extern C
