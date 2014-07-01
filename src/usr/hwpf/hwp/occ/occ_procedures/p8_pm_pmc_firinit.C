/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_pmc_firinit.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
// $Id: p8_pm_pmc_firinit.C,v 1.20 2014/04/07 02:55:10 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_pmc_firinit.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
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
// *!  buildfapiprcd p8_pm_pmc_firinit.C 
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
    ecmdDataBufferBase  pmc_ocb_mask_hi(64);
    ecmdDataBufferBase  pmc_ocb_mask_lo(64);
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
            
            
            // Clear pmc_ocb_mask_[hi/lo] as these are really enables, not masks.
            e_rc |= pmc_ocb_mask_hi.flushTo0();
            e_rc |= pmc_ocb_mask_lo.flushTo0();
            if (e_rc)
            {
                rc.setEcmdError(e_rc);
                break;
            }
            
            //#--******************************************************************************
            //#-- PMC OCB Mask Hi
            //#--******************************************************************************

            rc = fapiPutScom(i_target, PMC_ERROR_INT_MASK_HI_0x00062067, pmc_ocb_mask_hi );
            if (rc)
            {
                  FAPI_ERR("fapiPutScom(PMC_ERROR_INT_MASK_HI_0x00062067) failed.");
                  break;
            }

            //#--******************************************************************************
            //#-- PMC OCB Mask Lo
            //#--******************************************************************************

            rc = fapiPutScom(i_target, PMC_ERROR_INT_MASK_LO_0x00062068, pmc_ocb_mask_lo );
            if (rc)
            {
                FAPI_ERR("fapiPutScom(PMC_ERROR_INT_MASK_LO_0x00062068) failed.");
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
            
            //--******************************************************************************
            //-- PMC_FIR_MASK (W0_OR_45) (WR_43) (WO_AND_44)
            //--******************************************************************************
            rc = fapiPutScom(i_target, PMC_LFIR_MASK_0x01010843, mask );
            if (rc)
            {
	            FAPI_ERR("fapiPutScom(PMC_LFIR_MASK_0x01010843) failed.");
                break;
            }
                        
            // Clear pmc_ocb_mask_[hi/lo] as these are really enables, not masks.
            e_rc |= pmc_ocb_mask_hi.flushTo0();
            e_rc |= pmc_ocb_mask_lo.flushTo0();
            if (e_rc)
            {
                rc.setEcmdError(e_rc);
                break;
            }
            
            //#--******************************************************************************
            //#-- PMC OCB Mask Hi
            //#--******************************************************************************

            rc = fapiPutScom(i_target, PMC_ERROR_INT_MASK_HI_0x00062067, pmc_ocb_mask_hi );
            if (rc)
            {
                  FAPI_ERR("fapiPutScom(PMC_ERROR_INT_MASK_HI_0x00062067) failed.");
                  break;
            }

            //#--******************************************************************************
            //#-- PMC OCB Mask Lo
            //#--******************************************************************************

            rc = fapiPutScom(i_target, PMC_ERROR_INT_MASK_LO_0x00062068, pmc_ocb_mask_lo );
            if (rc)
            {
                FAPI_ERR("fapiPutScom(PMC_ERROR_INT_MASK_LO_0x00062068) failed.");
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

            SET_RECOV_INTR(PSTATE_OCI_MASTER_RDERR              ); //  0  pstate_oci_master_rderr
            SET_RECOV_INTR(PSTATE_OCI_MASTER_RDDATA_PARITY_ERR  ); //  1  pstate_oci_master_rddata_parity_err
            SET_RECOV_INTR(PSTATE_GPST_CHECKBYTE_ERR            ); //  2  pstate_gpst_checkbyte_err
            SET_RECOV_INTR(PSTATE_GACK_TO_ERR                   ); //  3  pstate_gack_to_err
            SET_RECOV_INTR(PSTATE_PIB_MASTER_NONOFFLINE_ERR     ); //  4  pstate_pib_master_nonoffline_err
            SET_RECOV_INTR(PSTATE_PIB_MASTER_OFFLINE_ERR        ); //  5  pstate_pib_master_offline_err
            SET_RECOV_INTR(PSTATE_OCI_MASTER_TO_ERR             ); //  6  pstate_oci_master_to_err
            SET_RECOV_INTR(PSTATE_INTERCHIP_UE_ERR              ); //  7  pstate_interchip_ue_err
            SET_RECOV_INTR(PSTATE_INTERCHIP_ERRORFRAME_ERR      ); //  8  pstate_interchip_errorframe_err
            SET_RECOV_INTR(PSTATE_MS_FSM_ERR                    ); //  9  pstate_ms_fsm_err
            SET_MALF_ALERT(MS_COMP_PARITY_ERR                   ); // 10  ms_comp_parity_err
            SET_MALF_ALERT(IDLE_PORESW_FATAL_ERR                ); // 11  idle_poresw_fatal_err
            SET_MALF_ALERT(IDLE_PORESW_STATUS_RC_ERR            ); // 12  idle_poresw_status_rc_err
            SET_MALF_ALERT(IDLE_PORESW_STATUS_VALUE_ERR         ); // 13  idle_poresw_status_value_err
            SET_MALF_ALERT(IDLE_PORESW_WRITE_WHILE_INACTIVE_ERR ); // 14  idle_poresw_write_while_inactive_err
            SET_MALF_ALERT(IDLE_PORESW_TIMEOUT_ERR              ); // 15  idle_poresw_timeout_err
            SET_FIR_MASKED(IDLE_OCI_MASTER_WRITE_TIMEOUT_ERR    ); // 16  idle_oci_master_write_timeout_err
            SET_MALF_ALERT(IDLE_INTERNAL_ERR                    ); // 17  idle_internal_err
            SET_MALF_ALERT(INT_COMP_PARITY_ERR                  ); // 18  int_comp_parity_err
            SET_FIR_MASKED(PMC_OCC_HEARTBEAT_TIMEOUT            ); // 19  pmc_occ_heartbeat_timeout
            SET_FIR_MASKED(SPIVID_CRC_ERROR0                    ); // 20  spivid_crc_error0
            SET_FIR_MASKED(SPIVID_CRC_ERROR1                    ); // 21  spivid_crc_error1
            SET_FIR_MASKED(SPIVID_CRC_ERROR2                    ); // 22  spivid_crc_error2
            SET_RECOV_ATTN(SPIVID_RETRY_TIMEOUT                 ); // 23  spivid_retry_timeout
            SET_RECOV_ATTN(SPIVID_FSM_ERR                       ); // 24  spivid_fsm_err
            SET_FIR_MASKED(SPIVID_MAJORITY_DETECTED_A_MINORITY  ); // 25  spivid_majority_detected_a_minority
            SET_FIR_MASKED(O2S_CRC_ERROR0                       ); // 26  o2s_crc_error0
            SET_FIR_MASKED(O2S_CRC_ERROR1                       ); // 27  o2s_crc_error1
            SET_FIR_MASKED(O2S_CRC_ERROR2                       ); // 28  o2s_crc_error2
            SET_FIR_MASKED(O2S_RETRY_TIMEOUT                    ); // 29  o2s_retry_timeout
            SET_FIR_MASKED(O2S_WRITE_WHILE_BRIDGE_BUSY_ERR      ); // 30  o2s_write_while_bridge_busy_err
            SET_FIR_MASKED(O2S_FSM_ERR                          ); // 31  o2s_fsm_err
            SET_FIR_MASKED(O2S_MAJORITY_DETECTED_A_MINORITY     ); // 32  o2s_majority_detected_a_minority
            SET_FIR_MASKED(O2P_WRITE_WHILE_BRIDGE_BUSY_ERR      ); // 33  o2p_write_while_bridge_busy_err
            SET_FIR_MASKED(O2P_FSM_ERR                          ); // 34  o2p_fsm_err
            SET_FIR_MASKED(OCI_SLAVE_ERR                        ); // 35  oci_slave_err
            SET_MALF_ALERT(IF_COMP_PARITY_ERR                   ); // 36  if_comp_parity_err
            SET_RECOV_ATTN(IDLE_RECOVERY_NOTIFY_PRD             ); // 37  idle_recovery_notify_prd
            SET_FIR_MASKED(FIR_PARITY_ERR_DUP                   ); // 47  fir_parity_err_dup
            SET_FIR_MASKED(FIR_PARITY_ERR                       ); // 48  fir_parity_err

            if (e_rc)
            {
                rc.setEcmdError(e_rc);
                break;
            }

            FAPI_DBG(" action_0  => 0x%016llx ",  action_0.getDoubleWord(0));
            FAPI_DBG(" action_1  => 0x%016llx ",  action_1.getDoubleWord(0));
            FAPI_DBG(" mask      => 0x%016llx ",  mask.getDoubleWord(0));

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
            
            // Set the PMC OCB Masks to enable OCC interrupts on FIR bits
            // Note: the descrption of the bit says "mask" but it takes a 1
            // to enable them.
            
            e_rc |= pmc_ocb_mask_hi.flushTo0();
            e_rc |= pmc_ocb_mask_lo.flushTo0();

            // PMC OCB Mask Hi
            e_rc |= pmc_ocb_mask_hi.setBit(PSTATE_OCI_MASTER_RDERR              ); //  0  pstate_oci_master_rderr
            e_rc |= pmc_ocb_mask_hi.setBit(PSTATE_OCI_MASTER_RDDATA_PARITY_ERR  ); //  1  pstate_oci_master_rddata_parity_err
            e_rc |= pmc_ocb_mask_hi.setBit(PSTATE_GPST_CHECKBYTE_ERR            ); //  2  pstate_gpst_checkbyte_err
            e_rc |= pmc_ocb_mask_hi.setBit(PSTATE_GACK_TO_ERR                   ); //  3  pstate_gack_to_err
            e_rc |= pmc_ocb_mask_hi.setBit(PSTATE_PIB_MASTER_NONOFFLINE_ERR     ); //  4  pstate_pib_master_nonoffline_err
            e_rc |= pmc_ocb_mask_hi.setBit(PSTATE_PIB_MASTER_OFFLINE_ERR        ); //  5  pstate_pib_master_offline_err
            e_rc |= pmc_ocb_mask_hi.setBit(PSTATE_OCI_MASTER_TO_ERR             ); //  6  pstate_oci_master_to_err
            e_rc |= pmc_ocb_mask_hi.setBit(PSTATE_INTERCHIP_UE_ERR              ); //  7  pstate_interchip_ue_err
            e_rc |= pmc_ocb_mask_hi.setBit(PSTATE_INTERCHIP_ERRORFRAME_ERR      ); //  8  pstate_interchip_errorframe_err
            e_rc |= pmc_ocb_mask_hi.setBit(PSTATE_MS_FSM_ERR                    ); //  9  pstate_ms_fsm_err
            e_rc |= pmc_ocb_mask_hi.setBit(MS_COMP_PARITY_ERR                   ); // 10  ms_comp_parity_err
//          Left 0                        (IDLE_PORESW_FATAL_ERR                ); // 11  idle_poresw_fatal_err
//          Left 0                        (IDLE_PORESW_STATUS_RC_ERR            ); // 12  idle_poresw_status_rc_err
//          Left 0                        (IDLE_PORESW_STATUS_VALUE_ERR         ); // 13  idle_poresw_status_value_err
//          Left 0                        (IDLE_PORESW_WRITE_WHILE_INACTIVE_ERR ); // 14  idle_poresw_write_while_inactive_err
//          Left 0                        (IDLE_PORESW_TIMEOUT_ERR              ); // 15  idle_poresw_timeout_err
//          Left 0                        (IDLE_OCI_MASTER_WRITE_TIMEOUT_ERR    ); // 16  idle_oci_master_write_timeout_err
            e_rc |= pmc_ocb_mask_hi.setBit(IDLE_INTERNAL_ERR                    ); // 17  idle_internal_err
            e_rc |= pmc_ocb_mask_hi.setBit(INT_COMP_PARITY_ERR                  ); // 18  int_comp_parity_err
//          Left 0                        (PMC_OCC_HEARTBEAT_TIMEOUT            ); // 19  pmc_occ_heartbeat_timeout
//          Left 0                        (SPIVID_CRC_ERROR0                    ); // 20  spivid_crc_error0
//          Left 0                        (SPIVID_CRC_ERROR1                    ); // 21  spivid_crc_error1
//          Left 0                        (SPIVID_CRC_ERROR2                    ); // 22  spivid_crc_error2
            e_rc |= pmc_ocb_mask_hi.setBit(SPIVID_RETRY_TIMEOUT                 ); // 23  spivid_retry_timeout
            e_rc |= pmc_ocb_mask_hi.setBit(SPIVID_FSM_ERR                       ); // 24  spivid_fsm_err
//          Left 0                        (SPIVID_MAJORITY_DETECTED_A_MINORITY  ); // 25  spivid_majority_detected_a_minority
//          Left 0                        (O2S_CRC_ERROR0                       ); // 26  o2s_crc_error0
//          Left 0                        (O2S_CRC_ERROR1                       ); // 27  o2s_crc_error1
//          Left 0                        (O2S_CRC_ERROR2                       ); // 28  o2s_crc_error2
//          Left 0                        (O2S_RETRY_TIMEOUT                    ); // 29  o2s_retry_timeout
//          Left 0                        (O2S_WRITE_WHILE_BRIDGE_BUSY_ERR      ); // 30  o2s_write_while_bridge_busy_err
//          Left 0                        (O2S_FSM_ERR                          ); // 31  o2s_fsm_err

            // PMC OCB Mask Lo
//          Left 0                        (O2S_MAJORITY_DETECTED_A_MINORITY     ); // 32  o2s_majority_detected_a_minority
//          Left 0                        (O2P_WRITE_WHILE_BRIDGE_BUSY_ERR      ); // 33  o2p_write_while_bridge_busy_err
            e_rc |= pmc_ocb_mask_lo.setBit(O2P_FSM_ERR - 32                     ); // 34  o2p_fsm_err
            e_rc |= pmc_ocb_mask_lo.setBit(OCI_SLAVE_ERR - 32                   ); // 35  oci_slave_err
//                                        (IF_COMP_PARITY_ERR                   ); // 36  if_comp_parity_err
//                                        IDLE_RECOVERY_NOTIFY_PRD              ); // 37  idle_recovery_notify_prd
//          Left 0                        (FIR_PARITY_ERR_DUP                   ); // 47  fir_parity_err_dup
//          Left 0                        (FIR_PARITY_ERR                       ); // 48  fir_parity_err
            
            
            if (e_rc)
            {
                rc.setEcmdError(e_rc);
                break;
            }
            
            FAPI_DBG(" pmc_ocb_mask_hi  => 0x%016llx ",  pmc_ocb_mask_hi.getDoubleWord(0));
            FAPI_DBG(" pmc_ocb_mask_lo  => 0x%016llx ",  pmc_ocb_mask_lo.getDoubleWord(0));
            
            //#--******************************************************************************
            //#-- PMC OCB Mask Hi
            //#--******************************************************************************

            rc = fapiPutScom(i_target, PMC_ERROR_INT_MASK_HI_0x00062067, pmc_ocb_mask_hi );
            if (rc)
            {
                  FAPI_ERR("fapiPutScom(PMC_ERROR_INT_MASK_HI_0x00062067) failed.");
                  break;
            }

            //#--******************************************************************************
            //#-- PMC OCB Mask Lo
            //#--******************************************************************************

            rc = fapiPutScom(i_target, PMC_ERROR_INT_MASK_LO_0x00062068, pmc_ocb_mask_lo );
            if (rc)
            {
                FAPI_ERR("fapiPutScom(PMC_ERROR_INT_MASK_LO_0x00062068) failed.");
                break;
            }

        }
    } while(0);

    return rc ;

} // Procedure


} //end extern C
