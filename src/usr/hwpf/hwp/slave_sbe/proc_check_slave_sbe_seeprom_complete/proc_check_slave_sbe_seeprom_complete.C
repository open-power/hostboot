/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_check_slave_sbe_seeprom_complete.C $ */
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
// $Id: proc_check_slave_sbe_seeprom_complete.C,v 1.18 2015/07/27 00:36:23 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_check_slave_sbe_seeprom_complete.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_check_slave_sbe_seeprom_complete.C
// *! DESCRIPTION : Check if a slave has completed the seeprom code
// *!
// *! OWNER NAME  : Joe McGill              Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <proc_check_slave_sbe_seeprom_complete.H>
#include <p8_scom_addresses.H>
#include <p8_istep_num.H>
#include <proc_sbe_check_master.H>
#include <proc_sbe_enable_pnor.H>
#include <proc_sbe_scan_service.H>
#include <proc_extract_sbe_rc.H>
#include <proc_reset_i2cm_bus_fence.H>
#include <proc_sbe_utils.H>


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const uint64_t NS_TO_FINISH = 10000000; //(10 ms)
const uint64_t MS_TO_FINISH = NS_TO_FINISH/1000000;
const uint64_t SIM_CYCLES_TO_FINISH = 10000000;

const uint8_t  SBE_EXIT_SUCCESS_0xF = 0xF;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

extern "C"
{

fapi::ReturnCode proc_check_slave_sbe_seeprom_complete(
    const fapi::Target & i_target,
    const void         * i_pSEEPROM,
    const size_t       i_wait_in_ms)
{
    // return codes
    fapi::ReturnCode rc;

    // track if procedure has cleared I2C master bus fence
    bool i2cm_bus_fence_cleared = false;

    // mark function entry
    FAPI_INF("Start");

    do
    {
        //
        // ensure SBE was started
        //

        ecmdDataBufferBase sbe_vital_data(32);
        FAPI_DBG("Checking SBE Vital register");
        rc = fapiGetCfamRegister(i_target, CFAM_FSI_SBE_VITAL_0x0000281C, sbe_vital_data);
        if (!rc.ok())
        {
            FAPI_ERR("Error reading SBE Vital register");
            break;
        }
        if (sbe_vital_data.isBitClear(12,20))
        {
            // status has not been updated, something is wrong
            FAPI_ERR("SBE does not appear to have started");
            // Call proc_extract_sbe_rc here to see what went wrong
            FAPI_EXEC_HWP(rc, proc_extract_sbe_rc, i_target, NULL, i_pSEEPROM, SBE);
            break;
        }

        //
        // check SBE progress
        // Loop until:
        //   SBE stopped OR
        //   scan service ready loop is reached OR
        //   loop time is exceeded
        //

        bool sbe_running = true;
        size_t loop_time = 0;
        uint8_t halt_code = 0;
        uint16_t istep_num = 0;
        uint8_t substep_num = 0;
        bool scan_service_loop_reached = false;
        while (sbe_running &&
               !scan_service_loop_reached &&
               (loop_time < i_wait_in_ms))
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

            scan_service_loop_reached =
                sbe_running &&
                !halt_code &&
                (istep_num == PROC_SBE_SCAN_SERVICE_ISTEP_NUM) &&
                (substep_num == SUBSTEP_SBE_READY);
        }

        // break if we took an error in the while loop
        if (rc)
        {
            break;
        }

        FAPI_INF("SBE is running [%d], loop time [%zd], scan service loop reached [%d]",
                 sbe_running, loop_time, scan_service_loop_reached);


        // two valid possibilities
        // 1) SBE halted with success
        // 2) scan service routine is running
        if (!sbe_running)
        {
            //SBE is stopped. Let's see where
            // before analysis proceeds, make sure that I2C master bus fence is cleared
            FAPI_EXEC_HWP(rc, proc_reset_i2cm_bus_fence, i_target);
            if (!rc.ok())
            {
                FAPI_ERR("Error from proc_reset_i2cm_bus_fence");
                break;
            }
            // mark that fence has been cleared
            i2cm_bus_fence_cleared = true;

            // did it stop with success?
            if (halt_code != SBE_EXIT_SUCCESS_0xF)
            {
                FAPI_ERR("SBE halted with error %i (istep 0x%X, substep %i)",
                         halt_code,
                         istep_num,
                         substep_num);
                FAPI_EXEC_HWP(rc, proc_extract_sbe_rc, i_target, NULL, i_pSEEPROM, SBE);
                break;
            }

            // did it stop in the correct istep?
            if (!(((istep_num == PROC_SBE_CHECK_MASTER_MAGIC_ISTEP_NUM ) &&
                   (substep_num == SUBSTEP_CHECK_MASTER_SLAVE_CHIP)) ||
                  ((istep_num == PROC_SBE_ENABLE_PNOR_MAGIC_ISTEP_NUM ) &&
                   (substep_num == SUBSTEP_ENABLE_PNOR_SLAVE_CHIP)) ||
                  (istep_num == PROC_SBE_EX_HOST_RUNTIME_SCOM_MAGIC_ISTEP_NUM)))
            {
                FAPI_ERR(
                    "SBE halted in wrong istep (istep 0x%X, substep %i)",
                    istep_num,
                    substep_num);
                const fapi::Target & CHIP_IN_ERROR = i_target;
                uint16_t & ISTEP_NUM = istep_num;
                uint8_t & SUBSTEP_NUM = substep_num;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_CHECK_SLAVE_SBE_SEEPROM_COMPLETE_BAD_ISTEP_NUM);
                break;
            }

            // reset the SBE so it can be used for MPIPL if needed
            rc = proc_sbe_utils_reset_sbe(i_target);
            if (!rc.ok())
            {
                FAPI_ERR("Error from proc_sbe_utils_reset_sbe");
                break;
            }
        }
        else if (scan_service_loop_reached)
        {
            FAPI_INF("SBE finished, scan service is running!");
            break;
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
            FAPI_SET_HWP_ERROR(rc, RC_PROC_CHECK_SLAVE_SBE_SEEPROM_COMPLETE_UNEXPECTED_FINAL_STATE);
            break;
        }

    } while (0);

    // if an error occurred prior to the I2C master bus fence
    // being cleared, attempt to clear it prior to exit
    if (!rc.ok() && !i2cm_bus_fence_cleared)
    {
        // discard rc, return that of original fail
        fapi::ReturnCode rc_unused;
        FAPI_EXEC_HWP(rc_unused, proc_reset_i2cm_bus_fence, i_target);
    }

    // mark function exit
    FAPI_INF("Exit");
    return rc;
}


} // extern "C"
