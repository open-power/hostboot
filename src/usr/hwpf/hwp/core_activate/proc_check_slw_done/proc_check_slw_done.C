/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/core_activate/proc_check_slw_done/proc_check_slw_done.C $ */
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
// $Id: proc_check_slw_done.C,v 1.7 2014/01/24 19:41:07 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_check_slw_done.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! OWNER NAME  : Greg Still    Email: stillgs@us.ibm.com
// *! BACKUP NAME : Michael Olsen Email: cmolsen@us.ibm.com
/// \file proc_check_slw_done.C
/// \brief  Check the SLW complex for proper state
///
/// \verbatim
///
///     Dependency: ATTR_PM_SLW_DEEP_SLEEP_EXIT_GOOD_HALT_ADDR has the 
///                 XIP offset of the good value for Deep Winkle
///                 For P8, this is set in p8_set_pore_bar.C
///
///     parms:  i_ex_target
///     {
///
///         Check that passed chiplet number is in the ETR chiplet vector
///         if not,
///             - call collect_ex_ffdc()
///             - return FAIL code
///
///         Check SLW is in clean state
///             - Control/Status register indicates stopped condition
///             - read ATTR_PM_SLW_DEEP_SLEEP_EXIT_GOOD_HALT_ADDR to get the 
///                 the value of the good halt address
///             - if good_halt_address is not NULL,
///                 - Compare PC (from Control/Status register) to the "good" address
///                 if miscompare,
///                     - put "good" address in FFDC data
///                     - collect PBA BAR2 and MASK2
///                     - collect_slw_ffdc()
///                     - collect_ex_ffdc()
///                     - image_meta_data()
///                     - return FAIL code
///
///             - For the passed chiplet
///                 - Read PMHistory
///                 - Compare PMHistory value with ETR transition value
///                 - if miscompare,
///                     - collect_slw_ffdc()
///                     - collect_ex_ffdc()
///                     - return FAIL code
///
///         Check PMC LFIR for SLW related bits
///         (Fatal err (11); Status RC (12); Status Value(13); Write while active (14);
///         Timeout (15))
///             if errors non-zero,
///                 - collect_slw_ffdc()
///                 - collect_ex_ffdc()
///                 - return FAIL code
///
///         exit
///      }
///
///      collect_slw_ffdc()
///      {
///          - EX number
///          - SLW Regs (including ETR which indicates the chiplets being hit)
///          - PMC LFIR
///          - PBA LFIR
///      }
///
///      collect_ex_ffdc()
///      {
///          - PMGP0
///          - GP3
///          - PMHistory
///          - PMErr
///      }
///
///
/// Background:
/// If a non-Success return occurs, it could be two possibilities
///     1) SLW engine never saw the IPI ---> in this case, the passed chiplet
///         number will not be in the ETR vector;
///             - gather FFDC for missing IPI due to HB bug OR HW settings
///         Dump IPC state AND a HB dump
///     2) SLW engine is in error --> gather FFDC for a SLW engine fail
///         Need to be able to callout the right thing -- VPD, memory UE, is it SLW engine itself
///
///  Procedure Prereq:
///     - System clocks are running
/// \endverbatim
///
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include "proc_check_slw_done.H"
#include "p8_pm.H"

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


/**
 * proc_check_slw_done
 *
 * @param[in] i_target EX target
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR
 */
fapi::ReturnCode
proc_check_slw_done(const fapi::Target& i_ex_target)
{
    fapi::ReturnCode    rc;
    uint32_t            e_rc = 0;

    ecmdDataBufferBase  data(64);
    ecmdDataBufferBase  etr(64);
    ecmdDataBufferBase  gp3(64);
    ecmdDataBufferBase  pmgp0(64);
    ecmdDataBufferBase  pmgp1(64);
    ecmdDataBufferBase  pmhist(64);
    ecmdDataBufferBase  pmerr(64);

    uint8_t             l_ex_number = 0;
    fapi::Target        l_parentTarget;
    uint64_t            address;
    uint64_t            ex_offset;
    
    uint32_t            good_halt_address = 0;

    uint32_t            idle_transition = 0;
    uint32_t            ex_vector = 0;
    uint32_t            ex_test_bit = 0;
    uint32_t            slw_fsm_state = 0;
    uint32_t            slw_stack_state = 0;
    uint64_t            slw_address = 0;
    uint32_t            pm_hist_state = 0;
    uint32_t            pmc_lfir_slw = 0;

    // 24 bit mask
    const uint64_t      SLW_ADDRESS_MASK = 0x0000000000FFFFFF;

    bool                b_state_error = false;

    do
    {

        FAPI_INF("Beginnning proc_check_slw_done...");

        // Get the parent chip to target the PCBS registers
        rc = fapiGetParentChip(i_ex_target, l_parentTarget);
        if (rc)
        {
            FAPI_ERR("fapiGetParentChip access");
            break;
        }

        // Get the core number
        rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_ex_target, l_ex_number);
        if (rc)
        {
            FAPI_ERR("fapiGetAttribute of ATTR_CHIP_UNIT_POS with rc = 0x%x", (uint32_t)rc);
            break;
        }

        FAPI_INF("Checking EX %d on %s", l_ex_number, l_parentTarget.toEcmdString());

        ex_offset = l_ex_number * 0x01000000;

        // Read the pertinent registers

        address = EX_GP3_0x100F0012 + ex_offset;
        GETSCOM(rc, l_parentTarget, address, gp3);

        address = EX_PMGP0_0x100F0100 + ex_offset;
        GETSCOM(rc, l_parentTarget, address, pmgp0);

        address = EX_PMGP1_0x100F0103 + ex_offset;
        GETSCOM(rc, l_parentTarget, address, pmgp1);

        address = EX_PMErr_REG_0x100F0109 + ex_offset;
        GETSCOM(rc, l_parentTarget, address, pmerr);

        address = EX_PMSTATEHISTPHYP_REG_0x100F0110 + ex_offset;
        GETSCOM(rc, l_parentTarget, address, pmhist);

        // Check that passed chiplet number is in the ETR chiplet vector
        GETSCOM(rc, l_parentTarget, PORE_SLW_EXE_TRIGGER_0x00068009, etr);

        e_rc |= etr.extractToRight( &idle_transition, 8, 4 );
        e_rc |= etr.extractToRight( &ex_vector, 32, 16 );
        E_RC_CHECK(e_rc, rc);

        ex_test_bit = (ex_vector>>(16-l_ex_number-1) & 0x0001);
        FAPI_DBG("\tex_vector: 0x%04X;  ex_test_bit: %1X", ex_vector, ex_test_bit);

        // If chiplet not in ETR, collected FFDC and return
        if (!ex_test_bit)
        {
            FAPI_ERR("EX %d is not in current SLW EXE Trigger 0x%016llX", l_ex_number, data.getDoubleWord(0));
            const uint64_t& GP3     = gp3.getDoubleWord(0);
            const uint64_t& PMGP0   = pmgp0.getDoubleWord(0);
            const uint64_t& PMGP1   = pmgp1.getDoubleWord(0);
            const uint64_t& PMERR   = pmerr.getDoubleWord(0);
            const uint64_t& PMHIST  = pmhist.getDoubleWord(0);
            const uint64_t& EX      = l_ex_number;
            const fapi::Target& CHIP_IN_ERROR = l_parentTarget;
            FAPI_SET_HWP_ERROR(rc, RC_PMPROC_CHKSLW_NOT_IN_ETR);
            break;

        }

        // Check SLW is in clean state
        address = PORE_SLW_STATUS_0x00068000;
        GETSCOM(rc, l_parentTarget, address, data);

        e_rc |= data.extractToRight( &slw_fsm_state,    3, 4 );
        e_rc |= data.extractToRight( &slw_stack_state, 12, 4 );
        E_RC_CHECK(e_rc, rc);

        slw_address = data.getDoubleWord(0);
        slw_address &= SLW_ADDRESS_MASK;

        if ((slw_fsm_state & 0x000F) != 0x1)
        {
            FAPI_ERR("SLW FSM not in Wait state");
            b_state_error = true;
        }
        if ((slw_stack_state & 0x000F) != 0x1)
        {
            FAPI_ERR("SLW FSM stack is not empty");
            b_state_error = true;
        }

        address = PORE_SLW_CONTROL_0x00068001;
        GETSCOM(rc, l_parentTarget, address, data);

        if (data.isBitClear(0))
        {
            FAPI_ERR("SLW engine is not stopped");
            b_state_error = true;
        }

        if (b_state_error)
        {
            const uint64_t& EX = l_ex_number;
            const fapi::Target& CHIP_IN_ERROR = l_parentTarget;

            // XML will dump the SLW registers

            FAPI_SET_HWP_ERROR(rc, RC_PMPROC_CHKSLW_INVALID_STATE);
            break;
        }
        
        // Get the good_halt_address
        GETATTR(rc,
                ATTR_PM_SLW_DEEP_WINKLE_EXIT_GOOD_HALT_ADDR,
                "ATTR_PM_SLW_DEEP_WINKLE_EXIT_GOOD_HALT_ADDR",
                NULL,
                good_halt_address);

        // if good_halt_address is not NULL, compare PC to the "good" address
        if (good_halt_address)
        {
            FAPI_INF("Checking for good halt address: 0x%08llX", (uint64_t)good_halt_address );
            uint64_t good_halt_address_masked = good_halt_address & SLW_ADDRESS_MASK;
            uint64_t slw_address_masked = slw_address & SLW_ADDRESS_MASK;
            if ((good_halt_address_masked) != slw_address_masked)
            {
                FAPI_ERR("SLW engine address does not match the expected address: actual = 0x%016llX; expected =  0x%016llX",
                                slw_address_masked, good_halt_address_masked);
                const uint64_t& PMHIST  = pmhist.getDoubleWord(0);
                const uint64_t& GP3     = gp3.getDoubleWord(0);
                const uint64_t& PMGP0   = pmgp0.getDoubleWord(0);
                const uint64_t& PMGP1   = pmgp1.getDoubleWord(0);
                const uint64_t& PMERR   = pmerr.getDoubleWord(0);
                const uint64_t& GOODHALTADDR = (uint64_t)good_halt_address;
                const uint64_t& EX      = l_ex_number;
                const fapi::Target& CHIP_IN_ERROR = l_parentTarget;

                 // XML will dump the SLW registers

                FAPI_SET_HWP_ERROR(rc, RC_PMPROC_CHKSLW_ADDRESS_MISMATCH);
                break;
            }
            else
            {
                FAPI_INF("Good halt address checking passed");

            }
        }
        else
        {
            FAPI_INF("No good halt address is available;  bypassing address check");
        }

        // For the passed chiplet, check for running
        FAPI_INF("Checking EX %d for RUNNING state", l_ex_number);
        e_rc |= pmhist.extractToRight( &pm_hist_state, 0, 2 );
        E_RC_CHECK(e_rc, rc);

        FAPI_DBG("\tPMHist = 0x%016llX; pm_hist_state = 0x%08X", pmhist.getDoubleWord(0), pm_hist_state);

        // History = 0 means running;  something other than that is not good
        if (pm_hist_state)
        {
            FAPI_ERR("EX %d is not in expected RUNNING state: PMHist = 0x%016llX", l_ex_number, pmhist.getDoubleWord(0));
            const uint64_t& PMHIST  = pmhist.getDoubleWord(0);
            const uint64_t& GP3     = gp3.getDoubleWord(0);
            const uint64_t& PMGP0   = pmgp0.getDoubleWord(0);
            const uint64_t& PMGP1   = pmgp1.getDoubleWord(0);
            const uint64_t& PMERR   = pmerr.getDoubleWord(0);
            const uint64_t& EX      = l_ex_number;
            const fapi::Target& CHIP_IN_ERROR = l_parentTarget;

             // XML will dump the SLW registers

            FAPI_SET_HWP_ERROR(rc, RC_PMPROC_CHKSLW_EX_NOT_RUNNING);
            break;
        }

        // Check PMC LFIR for SLW related bits
        //      Fatal err (11)
        //      Status RC (12)
        //      Status Value(13)
        //      Write while active (14)
        //      Timeout (15)
        FAPI_INF("Checking PMC Local FIR for SLW errors");
        address = PMC_LFIR_0x01010840;
        GETSCOM(rc, l_parentTarget, address, data);

        e_rc |= data.extractToRight( &pmc_lfir_slw, 11, 5 );
        E_RC_CHECK(e_rc, rc);

        FAPI_DBG("\tPMC LFIR = 0x%016llX; pmc_lfir_slw = 0x%08X", data.getDoubleWord(0), pmc_lfir_slw);

        // Non-zero is not good
        if (pmc_lfir_slw)
        {
            FAPI_ERR("PMC LFIR has unexpeced SLW bits on: PMC LFIR = 0x%016llX", data.getDoubleWord(0));
            const uint64_t& PMCLFIR = data.getDoubleWord(0);

            const uint64_t& GP3     = gp3.getDoubleWord(0);
            const uint64_t& PMGP0   = pmgp0.getDoubleWord(0);
            const uint64_t& PMGP1   = pmgp1.getDoubleWord(0);
            const uint64_t& PMERR   = pmerr.getDoubleWord(0);
            const uint64_t& EX      = l_ex_number;
            const fapi::Target& CHIP_IN_ERROR = l_parentTarget;


             // XML will dump the SLW registers

            FAPI_SET_HWP_ERROR(rc, RC_PMPROC_CHKSLW_PMC_FIR_ERRORS);
            break;
        }

    } while(0);
    
    FAPI_INF("Exiting proc_check_slw_done...");
    return rc;
}

} //end extern C
