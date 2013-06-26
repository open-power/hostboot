/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_check_slave_sbe_seeprom_complete.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
// -*- mode: C++; c-file-style: "linux";  -*-
// $Id: proc_check_slave_sbe_seeprom_complete.C,v 1.7 2013/06/21 14:24:28 jeshua Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_check_slave_sbe_seeprom_complete.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_check_slave_sbe_seeprom_complete.C
// *! DESCRIPTION : Check if a slave has completed the seeprom code
// *!
// *! OWNER NAME  : Jeshua Smith            Email: jeshua@us.ibm.com
// *!
// *! Overview:
// *!    Check if the SBE is still running
// *!    Check if the SBE stopped with success at the correct spot
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_check_slave_sbe_seeprom_complete.H"
#include "p8_scom_addresses.H"
#include "p8_istep_num.H"
#include "proc_sbe_check_master.H"
#include "proc_sbe_enable_pnor.H"
#include "proc_extract_sbe_rc.H"

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const uint8_t  SBE_STOPPED_AT_BREAKPOINT_0xB = 0xB;
const uint8_t  SBE_EXIT_SUCCESS_0xF = 0xF;
const uint64_t NS_TO_FINISH = 10^9; //(1 second)
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
//
// returns: FAPI_RC_SUCCESS if the slave SBE stopped with success at the correct
//          location, else error
//------------------------------------------------------------------------------
    fapi::ReturnCode proc_check_slave_sbe_seeprom_complete(
        const fapi::Target & i_target)
    {
        // data buffer to hold register values
        ecmdDataBufferBase data(64);

        // return codes
        fapi::ReturnCode rc;

        // mark function entry
        FAPI_INF("Entry");

        do
        {
            //Check if the SBE is still running
            bool still_running = true;
            rc = proc_check_slave_sbe_seeprom_complete_check_running(
                i_target,
                still_running );
            if( rc )
            {
                break;
            }

            if( still_running )
            {
                //SBE still running, so give it a second to finish
                FAPI_DBG("Waiting for SBE to stop (%lldns, %lld cycles)",
                         NS_TO_FINISH,
                         SIM_CYCLES_TO_FINISH );
                rc = fapiDelay(NS_TO_FINISH, SIM_CYCLES_TO_FINISH);
                if(rc)
                {
                    FAPI_ERR("Error with delay\n");
                    break;
                }

                //Check the SBE again
                rc = proc_check_slave_sbe_seeprom_complete_check_running(
                    i_target,
                    still_running );
                if( rc )
                {
                    break;
                }

                //Give up if we're still running
                if( still_running )
                {
                    FAPI_ERR(
                        "SBE still running after waiting (%lldns, %lld cycles)",
                        NS_TO_FINISH,
                        SIM_CYCLES_TO_FINISH );
                    const fapi::Target & CHIP_IN_ERROR = i_target;
                    FAPI_SET_HWP_ERROR(rc,
                        RC_PROC_CHECK_SLAVE_SBE_SEEPROM_COMPLETE_STILL_RUNNING);
                    break;
                }
            } //end if(still_running)

            //SBE is stopped. Let's see where

            uint8_t  halt_code = 0;
            uint16_t istep_num = 0;
            uint8_t  substep_num = 0;

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
                //JDS TODO - how do I get the pointer to the SEEPROM?
                FAPI_EXEC_HWP(rc, proc_extract_sbe_rc, i_target, NULL, SBE);
                break;
            }
            //Halt code was success

            //Did it stop in the correct istep?
            if(( istep_num != PROC_SBE_CHECK_MASTER_ISTEP_NUM ) &&
               ( istep_num != PROC_SBE_ENABLE_PNOR_ISTEP_NUM ) &&
               ( istep_num != PROC_SBE_EX_HOST_RUNTIME_SCOM_ISTEP_NUM ))
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
            if( (( istep_num == PROC_SBE_CHECK_MASTER_ISTEP_NUM ) &&
                 ( substep_num != SUBSTEP_CHECK_MASTER_SLAVE_CHIP )) ||
                (( istep_num == PROC_SBE_ENABLE_PNOR_ISTEP_NUM ) &&
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
        } while (0);

        // mark function exit
        FAPI_INF("Exit");
        return rc;
    }

} // extern "C"
/* Local Variables: */
/* c-basic-offset: 4 */
/* End: */
