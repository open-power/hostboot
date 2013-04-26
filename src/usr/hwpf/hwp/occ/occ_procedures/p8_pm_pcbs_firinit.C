/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_pcbs_firinit.C $    */
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
// $Id: p8_pm_pcbs_firinit.C,v 1.10 2013/04/01 04:25:41 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_pcbs_firinit.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Ralf Maier         Email: ralf.maier@de.ibm.com
// *!
/// \file p8_pm_pcbs_firinit.C
/// \brief Configures the PCBS FIR errors

/// \todo
///
/// \verbatim
///
///  Procedure Prereq:
///  - completed istep procedure
///
/// High-level procedure flow:
///
///  get all functional child chiplets
///
///  loop over all functional chiplets {
///     calculate address
///     set the error mask in order to mask all errors
///
///  }
///
/// \endverbatim
//------------------------------------------------------------------------------



// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <fapi.H>
#include "p8_scom_addresses.H"
#include "p8_pm_pcbs_firinit.H"

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

// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------


fapi::ReturnCode
p8_pm_pcbs_firinit(const fapi::Target &i_target , uint32_t mode )
{

    fapi::ReturnCode rc;
    ecmdDataBufferBase             action_0(64);
    ecmdDataBufferBase             action_1(64);
    ecmdDataBufferBase             mask(64);
    std::vector<fapi::Target>      l_exChiplets;
    fapi::TargetState              l_state = TARGET_STATE_FUNCTIONAL;
    uint8_t                        l_functional = 0;
    uint8_t                        l_ex_number = 0;
    uint32_t                       e_rc = 0;

    FAPI_INF("Executing proc_pm_pcbs_firinit  ...");
    do
    {
        if (mode == PM_RESET)
        {
            e_rc  = mask.flushTo0();
            e_rc |= mask.setBit(0,PCB_FIR_REGISTER_LENGTH);
            if (e_rc)
            {
                rc.setEcmdError(e_rc);
                break;
            }

            //    #--***********************************************************
            //    #-- Mask EX_PMErrMask_REG_0x100F010A
            //    #--***********************************************************



            rc = fapiGetChildChiplets(  i_target,
                                        fapi::TARGET_TYPE_EX_CHIPLET,
                                        l_exChiplets,
                                        l_state);
            if (rc) return rc;
            FAPI_DBG("  chiplet vector size          => %u", l_exChiplets.size());



            for (uint8_t c=0; c< l_exChiplets.size(); c++)
            {
                rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL, &l_exChiplets[c], l_functional);
                if (rc)
                {
                    FAPI_ERR("fapiGetAttribute of ATTR_FUNCTIONAL with rc = 0x%x", (uint32_t)rc);
                    break;
                }

                if (l_functional)
                {
                    // The ex is functional let's build the SCOM address
                    rc = FAPI_ATTR_GET( ATTR_CHIP_UNIT_POS,
                                        &l_exChiplets[c],
                                        l_ex_number);
                    if (rc)
                    {
                       FAPI_ERR("fapiGetAttribute of ATTR_CHIP_UNIT_POS with rc = 0x%x", (uint32_t)rc);
                       break;
                    }

                    FAPI_DBG("Core number = %d", l_ex_number);
                    // Use the l_ex_number to build the SCOM address;
                    rc = fapiPutScom(   i_target,
                                        EX_PMErrMask_REG_0x100F010A +
                                            (l_ex_number * 0x01000000),
                                        mask );
                    if (rc)
                    {
                        FAPI_ERR("fapiPutScom(EX_PMErrMask_REG_0x100F010A) failed.");
                        break;
                    }
                } // Functional
            } // Chiplet loop
        }
        else
        {

            SET_FIR_MASKED(PCBS_SLEEP_ENTRY_NOTIFY_PMC_HANG_ERR_MASK);
            SET_FIR_MASKED(PCBS_SLEEP_ENTRY_NOTIFY_PMC_ASSIST_HANG_ERR_MASK);
            SET_FIR_MASKED(PCBS_SLEEP_ENTRY_NOTIFY_PMC_ERR_MASK);
            SET_FIR_MASKED(PCBS_SLEEP_EXIT_INVOKE_PORE_ERR_MASK);
            SET_FIR_MASKED(PCBS_WINKLE_ENTRY_NOTIFY_PMC_ERR_MASK);
            SET_FIR_MASKED(PCBS_WINKLE_ENTRY_SEND_INT_ASSIST_ERR_MASK);
            SET_FIR_MASKED(PCBS_WINKLE_EXIT_NOTIFY_PMC_ERR_MASK);
            SET_FIR_MASKED(PCBS_WAIT_DPLL_LOCK_ERR_MASK);
            SET_FIR_MASKED(PCBS_SPARE8_ERR_MASK);
            SET_FIR_MASKED(PCBS_WINKLE_EXIT_SEND_INT_ASSIST_ERR_MASK);
            SET_FIR_MASKED(PCBS_WINKLE_EXIT_SEND_INT_POWUP_ASSIST_ERR_MASK);
            SET_FIR_MASKED(PCBS_WRITE_FSM_GOTO_REG_IN_INVALID_STATE_ERR_MASK);
            SET_FIR_MASKED(PCBS_WRITE_PMGP0_IN_INVALID_STATE_ERR_MASK);
            SET_FIR_MASKED(PCBS_FREQ_OVERFLOW_IN_PSTATE_MODE_ERR_MASK);
            SET_FIR_MASKED(PCBS_ECO_RS_BYPASS_CONFUSION_ERR_MASK);
            SET_FIR_MASKED(PCBS_CORE_RS_BYPASS_CONFUSION_ERR_MASK);
            SET_FIR_MASKED(PCBS_READ_LPST_IN_PSTATE_MODE_ERR_MASK);
            SET_FIR_MASKED(PCBS_LPST_READ_CORR_ERR_MASK);
            SET_FIR_MASKED(PCBS_LPST_READ_UNCORR_ERR_MASK);
            SET_FIR_MASKED(PCBS_PFET_STRENGTH_OVERFLOW_ERR_MASK);
            SET_FIR_MASKED(PCBS_VDS_LOOKUP_ERR_MASK);
            SET_FIR_MASKED(PCBS_IDLE_INTERRUPT_TIMEOUT_ERR_MASK);
            SET_FIR_MASKED(PCBS_PSTATE_INTERRUPT_TIMEOUT_ERR_MASK);
            SET_FIR_MASKED(PCBS_GLOBAL_ACTUAL_SYNC_INTERRUPT_TIMEOUT_ERR_MASK);
            SET_FIR_MASKED(PCBS_PMAX_SYNC_INTERRUPT_TIMEOUT_ERR_MASK);
            SET_FIR_MASKED(PCBS_GLOBAL_ACTUAL_PSTATE_PROTOCOL_ERR_MASK);
            SET_FIR_MASKED(PCBS_PMAX_PROTOCOL_ERR_MASK);
            SET_FIR_MASKED(PCBS_IVRM_GROSS_OR_FINE_ERR_MASK);
            SET_FIR_MASKED(PCBS_IVRM_RANGE_ERR_MASK);
            SET_FIR_MASKED(PCBS_DPLL_CPM_FMIN_ERR_MASK);
            SET_FIR_MASKED(PCBS_DPLL_DCO_FULL_ERR_MASK);
            SET_FIR_MASKED(PCBS_DPLL_DCO_EMPTY_ERR_MASK);
            SET_FIR_MASKED(PCBS_DPLL_INT_ERR_MASK);
            SET_FIR_MASKED(PCBS_FMIN_AND_NOT_CPMBIT_ERR_MASK);
            SET_FIR_MASKED(PCBS_DPLL_FASTER_THAN_FMAX_PLUS_DELTA1_ERR_MASK);
            SET_FIR_MASKED(PCBS_DPLL_SLOWER_THAN_FMIN_MINUS_DELTA2_ERR_MASK);
            SET_FIR_MASKED(PCBS_RESCLK_CSB_INSTR_VECTOR_CHG_IN_INVALID_STATE_ERR_MASK);
            SET_FIR_MASKED(PCBS_RESLKC_BAND_BOUNDARY_CHG_IN_INVALID_STATE_ERR_MASK);
            SET_FIR_MASKED(PCBS_OCC_HEARTBEAT_LOSS_ERR_MASK);
            SET_FIR_MASKED(PCBS_SPARE39_ERR_MASK);
            SET_FIR_MASKED(PCBS_SPARE40_ERR_MASK);
            SET_FIR_MASKED(PCBS_SPARE41_ERR_MASK);
            SET_FIR_MASKED(PCBS_SPARE42_ERR_MASK);


            if (e_rc)
            {
                rc.setEcmdError(e_rc);
                break;
            }

            //    #--************************************************************
            //    #-- Mask EX_PMErrMask_REG_0x100F010A
            //    #--************************************************************

            rc = fapiGetChildChiplets(   i_target,
                                         fapi::TARGET_TYPE_EX_CHIPLET,
                                         l_exChiplets,
                                         l_state);
            if (rc)
            {
	            FAPI_ERR("fapiGetChildChiplets failed.");
                break;
	        }

            FAPI_DBG("  chiplet vector size          => %u", l_exChiplets.size());

            for (uint8_t c=0; c< l_exChiplets.size(); c++)
            {
                rc = FAPI_ATTR_GET( ATTR_FUNCTIONAL,
                                    &l_exChiplets[c],
                                    l_functional);
                if (rc)
                {
                   FAPI_ERR("fapiGetAttribute of ATTR_FUNCTIONAL with rc = 0x%x", (uint32_t)rc);
                   break;
                }

                if (l_functional)
                {
                   // The ex is functional let's build the SCOM address
                   rc = FAPI_ATTR_GET(  ATTR_CHIP_UNIT_POS,
                                        &l_exChiplets[c],
                                        l_ex_number);
                   if (rc)
                   {
                        FAPI_ERR("fapiGetAttribute of ATTR_CHIP_UNIT_POS with rc = 0x%x", (uint32_t)rc);
                        break;
                   }

                   FAPI_DBG("Core number = %d", l_ex_number);
                   // Use the l_ex_number to build the SCOM address;
                   rc = fapiPutScom(    i_target,
                                        EX_PMErrMask_REG_0x100F010A +
                                            (l_ex_number * 0x01000000),
                                        mask );
                   if (rc)
                   {
                        FAPI_ERR("fapiPutScom(EX_PMErrMask_REG_0x100F010A) failed.");
                        break;
                   }
                } // Functional
            } // Chiplet loop

            // Exit if error detected
            if (!rc.ok())
            {
                break;
            }
        } // Mode

    } while(0);

    return rc;

} // Procedure

} //end extern C
