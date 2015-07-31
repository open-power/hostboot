/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/core_activate/proc_stop_deadman_timer/proc_stop_deadman_timer.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
// -*- mode: C++; c-file-style: "linux";  -*-
// $Id: proc_stop_deadman_timer.C,v 1.14 2015/08/04 19:56:09 thi Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_stop_deadman_timer.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_stop_deadman_timer.C
// *! DESCRIPTION : Stops deadman timer
// *!
// *! OWNER NAME  : Greg Still              Email: stillgs@us.ibm.com
// *!
// *! Overview:
// *!    Notify SBE that HB is alive again
// *!    Conditionally stop the SBE
// *!
// *!    Here's the flow of SBE_VITAL substeps:
// *!    SBE (automatic on procedure entry): substep_proc_entry
// *!    SBE                               : substep_sbe_ready
// *!    HB (proc_prep_master_winkle)      : substep_deadman_start
// *!    SBE                               : substep_deadman_waiting_for_winkle
// *!    SBE                               : substep_deadman_waiting_for_wakeup
// *!    HB (proc_stop_deadman_timer)      : substep_hostboot_alive_again
// *!    SBE                   : (stops with error code 0xF to indicate success)
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <proc_stop_deadman_timer.H>
#include <p8_scom_addresses.H>
#include <p8_istep_num.H>
#include <proc_sbe_trigger_winkle.H>
#include <proc_sbe_intr_service.H>
#include <proc_sbe_utils.H>


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const uint64_t NS_TO_FINISH = 10000000; //(10 ms)
const uint64_t MS_TO_FINISH = NS_TO_FINISH/1000000;
const uint64_t SIM_CYCLES_TO_FINISH = 10000000;

const uint64_t MAX_WAIT_TIME_MS = 1000;

const uint8_t  SBE_EXIT_SUCCESS_0xF = 0xF;


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

extern "C"
{

fapi::ReturnCode proc_stop_deadman_timer(const fapi::Target & i_target,
                                         bool & o_intr_service_running)
{
    // return codes
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    // mark function entry
    FAPI_INF("Start");

    do
    {
        //
        // check SBE progress
        //

        // given this procedure is running, the SBE deadman function should have worked
        // check that the SBE VITAL reached the correct spot
        bool sbe_running;
        size_t loop_time = 0;
        uint8_t halt_code;
        uint16_t istep_num;
        uint8_t substep_num;
        bool intr_service_loop_reached = false;
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

        if (!(sbe_running &&
              !halt_code &&
              (istep_num == proc_sbe_trigger_winkle_istep_num) &&
              (substep_num == SUBSTEP_DEADMAN_WAITING_FOR_HOSTBOOT)))
        {
            FAPI_ERR("Expected istep/substep num %llX/%X but found %X/%X",
                     proc_sbe_trigger_winkle_istep_num,
                     SUBSTEP_DEADMAN_WAITING_FOR_HOSTBOOT,
                     istep_num,
                     substep_num);
            const fapi::Target & CHIP_IN_ERROR = i_target;
            const bool & SBE_RUNNING = sbe_running;
            const uint8_t & HALT_CODE = halt_code;
            const uint16_t & ISTEP_NUM = istep_num;
            const uint8_t & SUBSTEP_NUM = substep_num;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_STOP_DEADMAN_TIMER_UNEXPECTED_INITIAL_STATE);
            fapiLogError(rc);
        }

        //
        // send SBE message -- HOSTBOOT_ALIVE_AGAIN
        //

        rc = proc_sbe_utils_update_substep(
            i_target,
            SUBSTEP_HOSTBOOT_ALIVE_AGAIN);
        if (!rc.ok())
        {
            FAPI_ERR("Error from proc_sbe_utils_update_substep");
            break;
        }

        //
        // Loop until:
        //   SBE stopped OR
        //   interrupt serivce ready loop is reached OR
        //   loop time is exceeded
        //

        while (sbe_running &&
               !intr_service_loop_reached &&
               (loop_time < MAX_WAIT_TIME_MS))
        {
            // sleep 10ms, then check again
            loop_time += MS_TO_FINISH;
            rc = fapiDelay(NS_TO_FINISH, SIM_CYCLES_TO_FINISH);
            if (rc)
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

            intr_service_loop_reached =
                sbe_running &&
                !halt_code &&
                (istep_num == PROC_SBE_INTR_SERVICE_ISTEP_NUM) &&
                (substep_num == SUBSTEP_SBE_READY);
        }

        // break if we took an error in the while loop
        if (rc)
        {
            break;
        }

        FAPI_INF("SBE is running [%d], loop time [%zd], interrupt service loop reached [%d]",
                 sbe_running, loop_time, intr_service_loop_reached);

        // ensure correct halt code is captured
        if (!sbe_running)
        {
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

        // handle three valid possibilities:
        // 1) SBE stopped at end of deadman timer routine (SBE code supports interrupt service, but the service is not enabled)
        // 2) SBE is running interrupt service routine (SBE code supports interrupt service, and the service is enabled)
        // 3) SBE is still running deadman timer routine (SBE code does not support interrupt service)
        // If not in one of those 3 expected states, error out
        if (!sbe_running &&
            (halt_code == SBE_EXIT_SUCCESS_0xF) &&
            (istep_num == proc_sbe_trigger_winkle_istep_num) &&
            (substep_num == SUBSTEP_HOSTBOOT_ALIVE_AGAIN))
        {
            FAPI_INF("SBE halted at end of deadman timer routine, interrupt service is NOT running!");
            o_intr_service_running = false;

            // reset the SBE so it can be used for MPIPL if needed
            rc = proc_sbe_utils_reset_sbe(i_target);
            if (!rc.ok())
            {
                FAPI_ERR("Error from proc_sbe_utils_reset_sbe");
                break;
            }
        }
        else if (intr_service_loop_reached)
        {
            FAPI_INF("SBE finished deadman timer routine, interrupt service is running!");
            o_intr_service_running = true;
        }
        else if ( (sbe_running) &&
                  (istep_num == proc_sbe_trigger_winkle_istep_num) &&
                  (substep_num == SUBSTEP_HOSTBOOT_ALIVE_AGAIN) )
         
        {
            FAPI_INF("SBE is still running but not SBE interrupt.  Stop and "
                     "reset the SBE!");

            // Stop the SBE
            ecmdDataBufferBase data(64);
            rc = fapiGetScom(i_target, PORE_SBE_CONTROL_0x000E0001, data);
            if (!rc.ok())
            {
                FAPI_ERR("Error returned from fapiGetScom, addr 0x%.16llX ",
                         PORE_SBE_CONTROL_0x000E0001);
                break;
            }
            rc_ecmd |= data.setBit( 0 );
            if (rc_ecmd)
            {
                FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }

            rc = fapiPutScom(i_target, PORE_SBE_CONTROL_0x000E0001, data);
            if ( !rc.ok() )
            {
                FAPI_ERR("Error returned from fapiPutScom to stop "
                         "SBE, addr 0x%.16llX", PORE_SBE_CONTROL_0x000E0001);
                break;
            }

            // Reset the SBE
            rc = proc_sbe_utils_reset_sbe(i_target);
            if (!rc.ok())
            {
                FAPI_ERR("Error from proc_sbe_utils_reset_sbe");
                break;
            }

            // Set flag to indicate SBE interrupt is not running
            o_intr_service_running = false;
        }
        // error
        else
        {
            FAPI_ERR("SBE did not reach acceptable final state!");
            const fapi::Target & CHIP_IN_ERROR = i_target;
            const bool & SBE_RUNNING = sbe_running;
            const uint8_t & HALT_CODE = halt_code;
            const uint16_t & ISTEP_NUM = istep_num;
            const uint8_t & SUBSTEP_NUM = substep_num;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_STOP_DEADMAN_TIMER_UNEXPECTED_FINAL_STATE);
            break;
        }

    } while (0);

    // mark function exit
    FAPI_INF("Exit");
    return rc;
}

} // extern "C"
