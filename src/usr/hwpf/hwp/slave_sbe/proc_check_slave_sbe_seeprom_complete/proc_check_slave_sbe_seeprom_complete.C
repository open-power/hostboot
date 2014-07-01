/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_check_slave_sbe_seeprom_complete.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
// $Id: proc_check_slave_sbe_seeprom_complete.C,v 1.14 2014/06/10 12:41:40 dsanner Exp $
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
// *! Overview:
// *!    Check if the SBE is still running
// *!    Check if the SBE stopped with success at the correct spot
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <proc_check_slave_sbe_seeprom_complete.H>
#include <p8_scom_addresses.H>
#include <p8_istep_num.H>
#include <proc_sbe_check_master.H>
#include <proc_sbe_enable_pnor.H>
#include <proc_extract_sbe_rc.H>
#include <proc_reset_i2cm_bus_fence.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const uint8_t  SBE_STOPPED_AT_BREAKPOINT_0xB = 0xB;
const uint8_t  SBE_EXIT_SUCCESS_0xF = 0xF;
const uint64_t NS_TO_FINISH = 10000000; //(10 ms)
const uint64_t MS_TO_FINISH = NS_TO_FINISH/1000000;
const uint64_t SIM_CYCLES_TO_FINISH = 10000000;
//Should really be 19.6*NS_TO_FINISH, but sim runs at about 11 hours per
//simulated second which is longer than we want to wait in error cases


extern "C"
{

//------------------------------------------------------------------------------
// Subroutine definitions
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// subroutine:
//      Get the SBE location from SBE VITAL
//
// parameters: i_target           => slave chip target
//             o_halt_code        => halt code (only valid if SBE stopped)
//             o_istep_num        => current istep number (0xMmm)
//             o_substep_num      => current substep within istep
//
// returns: FAPI_RC_SUCCESS if o_istep_num and o_substep_num are valid,
//          else error
//------------------------------------------------------------------------------
    fapi::ReturnCode proc_check_slave_sbe_seeprom_complete_get_location(
        const fapi::Target & i_target,
        uint8_t  & o_halt_code,
        uint16_t & o_istep_num,
        uint8_t  & o_substep_num
        )
    {
        // data buffer to hold register values
        ecmdDataBufferBase data(64);

        // return codes
        uint32_t rc_ecmd = 0;
        fapi::ReturnCode rc;

        do
        {
            //Check SBE VITAL
            FAPI_DBG("Checking SBE VITAL reg");
            rc = fapiGetScom(i_target, MBOX_SBEVITAL_0x0005001C, data);
            if(rc)
            {
                FAPI_ERR("Error reading SBE VITAL reg\n");
                break;
            }

            o_halt_code = 0;
            o_istep_num = 0;
            o_substep_num = 0;
            rc_ecmd |= data.extractToRight(&o_halt_code,
                                           HALT_CODE_BIT_POSITION,
                                           HALT_CODE_BIT_LENGTH);
            rc_ecmd |= data.extractToRight(&o_istep_num,
                                           ISTEP_NUM_BIT_POSITION,
                                           ISTEP_NUM_BIT_LENGTH);
            rc_ecmd |= data.extractToRight(&o_substep_num,
                                           SUBSTEP_NUM_BIT_POSITION,
                                           SUBSTEP_NUM_BIT_LENGTH);
            if(rc_ecmd)
            {
                FAPI_ERR("Error (0x%x) extracting data from ecmdDataBufferBase",
                         rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
        } while(0);
        return rc;
    }

//------------------------------------------------------------------------------
// subroutine:
//      Check if the SBE is still running
//
// parameters: i_target           => slave chip target
//             o_still_running    => true if still running, false otherwise
//
// returns: FAPI_RC_SUCCESS if o_still_running is valid, else error
//------------------------------------------------------------------------------
    fapi::ReturnCode proc_check_slave_sbe_seeprom_complete_check_running(
        const fapi::Target & i_target,
        bool  & o_still_running )
    {
        // data buffer to hold register values
        ecmdDataBufferBase data(64);

        // return codes
        uint32_t rc_ecmd = 0;
        fapi::ReturnCode rc;

        do
        {
            FAPI_DBG("Checking SBE control reg");
            rc = fapiGetScom(i_target, PORE_SBE_CONTROL_0x000E0001, data);
            if(rc)
            {
                FAPI_ERR("Error reading SBE control reg\n");
                break;
            }

            // Bit 0 : 1 = stopped, 0 = running (or stopped at breakpoint)
            if( data.isBitClear(0) )
            {
                o_still_running = true;

                //If running, check for stopped at breakpoint
                FAPI_DBG("Checking SBE status reg");
                rc = fapiGetScom(i_target, PORE_SBE_STATUS_0x000E0000, data);
                if(rc)
                {
                    FAPI_ERR("Error reading SBE status reg\n");
                    break;
                }
                uint8_t state = 0;
                uint64_t address = data.getDoubleWord(0) &
                    0x0000FFFFFFFFFFFFull;
                rc_ecmd |= data.extractToRight( &state, 3, 4 );
                if(rc_ecmd)
                {
                    FAPI_ERR("Error (0x%x) extracting SBE status",
                             rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }

                if( state == SBE_STOPPED_AT_BREAKPOINT_0xB )
                {
                    FAPI_ERR("SBE stopped at breakpoint (address 0x%012llX)",
                             address);
                    const fapi::Target & CHIP_IN_ERROR = i_target;
                    FAPI_SET_HWP_ERROR(rc,
                RC_PROC_CHECK_SLAVE_SBE_SEEPROM_COMPLETE_STOPPED_AT_BREAKPOINT);
                    break;
                }
            }
            else
            {
                o_still_running = false;
            }
        } while(0);
        return rc;
    }

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// function:
//      Check if the SBE is still running
//      Wait 1 sec, then check again if still running
//      When stopped, check if the SBE halt code, istep, and substep are correct
//
// parameters: i_target           => slave chip target
//             i_pSEEPROM         => pointer to the seeprom image (for errors)
//             i_wait_in_ms       => pointer to the seeprom image (for errors)
//
// returns: FAPI_RC_SUCCESS if the slave SBE stopped with success at the correct
//          location, else error
//------------------------------------------------------------------------------
    fapi::ReturnCode proc_check_slave_sbe_seeprom_complete(
        const fapi::Target & i_target,
        const void         * i_pSEEPROM,
        const size_t       i_wait_in_ms)
    {
        // data buffer to hold register values
        ecmdDataBufferBase data(64);

        // return codes
        uint32_t rc_ecmd = 0;
        fapi::ReturnCode rc;

        // track if procedure has cleared I2C master bus fence
        bool i2cm_bus_fence_cleared = false;

        // mark function entry
        FAPI_INF("Entry");

        do
        {
            //Check if the SBE is still running.  Loop until stopped
            //or loop time is exceeded.
            bool still_running = true;
            size_t loop_time = 0;
            rc = proc_check_slave_sbe_seeprom_complete_check_running(
                   i_target,
                   still_running );
            if( rc )
            {
                break;
            }

            while (still_running && (loop_time < i_wait_in_ms))
            {
                //Not done -- sleep 10ms, then check again
                loop_time += MS_TO_FINISH;
                rc = fapiDelay(NS_TO_FINISH, SIM_CYCLES_TO_FINISH);
                if( rc )
                {
                    FAPI_ERR("Error with delay\n");
                    break;
                }

                rc = proc_check_slave_sbe_seeprom_complete_check_running(
                       i_target,
                       still_running );
                if( rc )
                {
                    break;
                }
            }

            //Break if took an error
            if( rc )
            {
                break;
            }

            FAPI_INF("SBE is running [%d], wait time in ms[%d]",
                     still_running, loop_time);

            //Give up if we're still running
            if( still_running )
            {
                FAPI_ERR(
                        "SBE still running after waiting (%dns, %lld cycles)",
                        loop_time,
                        loop_time/MS_TO_FINISH*SIM_CYCLES_TO_FINISH );

                const fapi::Target & CHIP_IN_ERROR = i_target;
                FAPI_SET_HWP_ERROR(rc,
                      RC_PROC_CHECK_SLAVE_SBE_SEEPROM_COMPLETE_STILL_RUNNING);
                break;
            } //end if(still_running)

            //SBE is stopped. Let's see where
            uint8_t  halt_code = 0;
            uint16_t istep_num = 0;
            uint8_t  substep_num = 0;

            // before analysis proceeds, make sure that I2C master bus fence is cleared
            FAPI_EXEC_HWP(rc, proc_reset_i2cm_bus_fence, i_target);
            if (!rc.ok())
            {
                FAPI_ERR("Error from proc_reset_i2cm_bus_fence");
                break;
            }
            // mark that fence has been cleared
            i2cm_bus_fence_cleared = true;

            //Get current location from SBE VITAL
            rc = proc_check_slave_sbe_seeprom_complete_get_location(
                i_target,
                halt_code,
                istep_num,
                substep_num );
            if( rc )
            {
                FAPI_ERR("Unable to get the current SBE location");
                break;
            }

            //Did it stop with success?
            if( halt_code != SBE_EXIT_SUCCESS_0xF )
            {
                FAPI_ERR(
                    "SBE halted with error %i (istep 0x%X, substep %i)",
                    halt_code,
                    istep_num,
                    substep_num);
                //Get the error code from the SBE code
                FAPI_EXEC_HWP(rc, proc_extract_sbe_rc, i_target, i_pSEEPROM, SBE);
                break;
            }
            //Halt code was success

            //Did it stop in the correct istep?
            if(( istep_num != PROC_SBE_CHECK_MASTER_MAGIC_ISTEP_NUM ) &&
               ( istep_num != PROC_SBE_ENABLE_PNOR_MAGIC_ISTEP_NUM ) &&
               ( istep_num != PROC_SBE_EX_HOST_RUNTIME_SCOM_MAGIC_ISTEP_NUM ))
            {
                FAPI_ERR(
                    "SBE halted in wrong istep (istep 0x%X, substep %i)",
                    istep_num,
                    substep_num);
                const fapi::Target & CHIP_IN_ERROR = i_target;
                uint16_t & ISTEP_NUM = istep_num;
                uint8_t & SUBSTEP_NUM = substep_num;
                FAPI_SET_HWP_ERROR(rc,
                        RC_PROC_CHECK_SLAVE_SBE_SEEPROM_COMPLETE_BAD_ISTEP_NUM);
                break;
            }
            //Istep is correct

            //Did it stop in the correct substep?
            if( (( istep_num == PROC_SBE_CHECK_MASTER_MAGIC_ISTEP_NUM ) &&
                 ( substep_num != SUBSTEP_CHECK_MASTER_SLAVE_CHIP )) ||
                (( istep_num == PROC_SBE_ENABLE_PNOR_MAGIC_ISTEP_NUM ) &&
                 ( substep_num != SUBSTEP_ENABLE_PNOR_SLAVE_CHIP )))
            {
                FAPI_ERR(
                    "SBE halted in wrong substep (istep 0x%X, substep %i)",
                    istep_num,
                    substep_num);
                const fapi::Target & CHIP_IN_ERROR = i_target;
                uint16_t & ISTEP_NUM = istep_num;
                uint8_t & SUBSTEP_NUM = substep_num;
                FAPI_SET_HWP_ERROR(rc,
                      RC_PROC_CHECK_SLAVE_SBE_SEEPROM_COMPLETE_BAD_SUBSTEP_NUM);
                break;
            }
            //Substep is correct

            //Looks good!

            // Reset the SBE so it can be used for MPIPL if needed
            rc_ecmd |= data.flushTo0();
            rc_ecmd |= data.setBit(0);

            if(rc_ecmd)
            {
                FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(i_target, PORE_SBE_RESET_0x000E0002, data);
            if(!rc.ok())
            {
                FAPI_ERR("Scom error resetting SBE\n");
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
/* Local Variables: */
/* c-basic-offset: 4 */
/* End: */
