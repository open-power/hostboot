/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/secure_boot/proc_stop_sbe_scan_service.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
// $Id: proc_stop_sbe_scan_service.C,v 1.2 2015/07/27 00:48:38 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_stop_sbe_scan_service.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2015
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_stop_sbe_scan_service.C
// *! DESCRIPTION : Stop SBE runtime scan service
// *!
// *! OWNER NAME  : Joe McGill               Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <proc_stop_sbe_scan_service.H>
#include <p8_scom_addresses.H>
#include <p8_istep_num.H>
#include <proc_sbe_scan_service.H>
#include <proc_use_sbe_scan_service.H>
#include <proc_extract_sbe_rc.H>
#include <proc_reset_i2cm_bus_fence.H>
#include <proc_sbe_utils.H>


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// SBE progress constants
const uint8_t  SBE_EXIT_SUCCESS_0xF = 0xF;

// SBE polling constants
const uint32_t SBE_HALT_POLL_MAX_LOOPS = 10;
const uint32_t SBE_HALT_POLL_DELAY_HW = 2000000;
const uint32_t SBE_HALT_POLL_DELAY_SIM = 10000000;

// SBE Mailbox0 Register scan request format constants
const uint32_t MBOX0_REQUEST_VALID_BIT = 0;
const uint32_t MBOX0_HALT_PATTERN_START_BIT = 16;
const uint32_t MBOX0_HALT_PATTERN_END_BIT = 31;
const uint32_t MBOX0_HALT_PATTERN = 0xD05E;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

extern "C"
{

//------------------------------------------------------------------------------
// function:
//      Stop SBE runtime scan service
//
// parameters: i_target => chip target
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_stop_sbe_scan_service(
    const fapi::Target& i_target,
    const void* i_pSEEPROM)
{
    // return codes
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    // track if procedure has cleared I2C master bus fence
    bool i2cm_bus_fence_cleared = false;

    // mark function entry
    FAPI_DBG("Start");

    do
    {
        // check SBE progress
        bool sbe_running = true;
        size_t loop_time = 0;
        uint8_t halt_code = 0;
        uint16_t istep_num = 0;
        uint8_t substep_num = 0;
        bool scan_service_loop_reached = false;

        // retrieve status
        rc = proc_sbe_utils_check_status(
            i_target,
            sbe_running,
            halt_code,
            istep_num,
            substep_num);
        if (!rc.ok())
        {
            FAPI_ERR("Error from proc_check_sbe_state_check_status");
            break;
        }

        // get HB->SBE request mailbox, check that it is clear
        ecmdDataBufferBase mbox_data(64);
        bool sbe_ready = false;
        rc = fapiGetScom(i_target, MBOX_SCRATCH_REG0_0x00050038, mbox_data);
        if (!rc.ok())
        {
            FAPI_ERR("Scom error reading SBE MBOX0 Register");
            break;
        }
        sbe_ready = (mbox_data.getDoubleWord(0) == 0);

        scan_service_loop_reached =
            sbe_running &&
            sbe_ready &&
            !halt_code &&
            (istep_num == PROC_SBE_SCAN_SERVICE_ISTEP_NUM) &&
            (substep_num == SUBSTEP_SBE_READY);

        FAPI_INF("SBE is running [%d], loop time [%zd], scan service loop reached [%d]",
                 sbe_running, loop_time, scan_service_loop_reached);

        if (!sbe_running)
        {
            FAPI_INF("SBE is stopped, exiting!");
            break;
        }
        else if (scan_service_loop_reached)
        {
            // format stop request
            rc_ecmd |= mbox_data.setBit(MBOX0_REQUEST_VALID_BIT);
            rc_ecmd |= mbox_data.insertFromRight(MBOX0_HALT_PATTERN,
                                                 MBOX0_HALT_PATTERN_START_BIT,
                                                 (MBOX0_HALT_PATTERN_END_BIT-
                                                  MBOX0_HALT_PATTERN_START_BIT)+1);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting up SBE MBOX0 data buffer.", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }

            // submit stop request to SBE
            FAPI_DBG("Submitting stop request to SBE");
            rc = fapiPutScom(i_target, MBOX_SCRATCH_REG0_0x00050038, mbox_data);
            if (!rc.ok())
            {
                FAPI_ERR("Error writing SBE MBOX0 Register");
                break;
            }

            // pause to allow request to be processed
            uint32_t loop_num = 0;
            while (sbe_running && (loop_num < SBE_HALT_POLL_MAX_LOOPS))
            {
                loop_num++;
                rc = fapiDelay(SBE_HALT_POLL_DELAY_HW, SBE_HALT_POLL_DELAY_SIM);
                if (!rc.ok())
                {
                    FAPI_ERR("Error from fapiDelay");
                    break;
                }

                // retrieve status
                rc = proc_sbe_utils_check_status(
                    i_target,
                    sbe_running,
                    halt_code,
                    istep_num,
                    substep_num);
                if (!rc.ok())
                {
                    FAPI_ERR("Error from proc_check_sbe_state_check_status");
                    break;
                }
            }
            if (rc)
            {
                break;
            }
            if (sbe_running)
            {
                FAPI_ERR("SBE is STILL running!");
                const fapi::Target & TARGET = i_target;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_STOP_SBE_SCAN_SERVICE_SBE_NOT_STOPPED);
                break;
            }

            // before analysis proceeds, make sure that I2C master bus fence is cleared
            FAPI_EXEC_HWP(rc, proc_reset_i2cm_bus_fence, i_target);
            if (!rc.ok())
            {
                FAPI_ERR("Error from proc_reset_i2cm_bus_fence");
                break;
            }
            // mark that fence has been cleared
            i2cm_bus_fence_cleared = true;

            //  ensure correct halt code is captured
            rc = proc_sbe_utils_check_status(
                i_target,
                sbe_running,
                halt_code,
                istep_num,
                substep_num);
            if (!rc.ok())
            {
                FAPI_ERR("Error from proc_check_sbe_state_check_status");
                break;
            }

            // confirm that expected halt point was reached
            if (halt_code != SBE_EXIT_SUCCESS_0xF)
            {
                FAPI_ERR("SBE halted with error 0x%X (istep 0x%03X, substep 0x%X)",
                         halt_code, istep_num, substep_num);
                // extract & return error code from analyzing SBE state
                FAPI_EXEC_HWP(rc, proc_extract_sbe_rc, i_target, NULL, i_pSEEPROM, SBE);
                break;
            }

            if ((istep_num != PROC_SBE_SCAN_SERVICE_ISTEP_NUM) ||
                (substep_num != SUBSTEP_HALT_SUCCESS))
            {
                FAPI_ERR("Expected SBE istep 0x%03llX, substep 0x%X but found istep 0x%03X, substep 0x%X",
                         PROC_SBE_SCAN_SERVICE_ISTEP_NUM, SUBSTEP_HALT_SUCCESS,
                         istep_num, substep_num);
                const fapi::Target & TARGET = i_target;
                const uint32_t & ISTEP_NUM = istep_num;
                const uint32_t & SUBSTEP_NUM = substep_num;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_STOP_SBE_SCAN_SERVICE_SBE_BAD_HALT);
                break;
            }

            // Reset the SBE so it can be used for MPIPL if needed
            ecmdDataBufferBase sbe_reset_data(64);
            rc = fapiPutScom(i_target, PORE_SBE_RESET_0x000E0002, sbe_reset_data);
            if (!rc.ok())
            {
                FAPI_ERR("Scom error resetting SBE\n");
                break;
            }
        }
        // error
        else
        {
            FAPI_ERR("SBE did not reach acceptable final state!");
            const fapi::Target & TARGET = i_target;
            const bool & SBE_RUNNING = sbe_running;
            const uint8_t & HALT_CODE = halt_code;
            const uint16_t & ISTEP_NUM = istep_num;
            const uint8_t & SUBSTEP_NUM = substep_num;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_STOP_SBE_SCAN_SERVICE_UNEXPECTED_FINAL_STATE);
            break;
        }

    } while(0);

    // if an error occurred prior to the I2C master bus fence
    // being cleared, attempt to clear it prior to exit
    if (!rc.ok() && !i2cm_bus_fence_cleared)
    {
        // discard rc, return that of original fail
        fapi::ReturnCode rc_unused;
        FAPI_EXEC_HWP(rc_unused, proc_reset_i2cm_bus_fence, i_target);
    }

    // mark function entry
    FAPI_DBG("End");
    return rc;
}


} // extern "C"
