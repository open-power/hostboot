/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/core_activate/proc_stop_deadman_timer/proc_stop_deadman_timer.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: proc_stop_deadman_timer.C,v 1.10 2014/02/10 04:40:32 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_stop_deadman_timer.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_stop_deadman_timer.C
// *! DESCRIPTION : Stops deadman timer and SBE
// *!
// *! OWNER NAME  : Greg Still              Email: stillgs@us.ibm.com
// *!
// *! Overview:
// *!    Notify SBE that HB is alive again
// *!    Make sure SBE stopped
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

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

extern "C"
{


//------------------------------------------------------------------------------
// function: proc_stop_deadman_timer
//     Notify SBE that HB is alive again
//     Force the SBE to stop running
//
// parameters: i_target  => chip target
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
    fapi::ReturnCode proc_stop_deadman_timer(const fapi::Target & i_target)
    {
        // data buffer to hold register values
        ecmdDataBufferBase data(64);

        // return codes
        uint32_t rc_ecmd = 0;
        fapi::ReturnCode rc;

        // mark function entry
        FAPI_INF("Entry new\n");

        do
        {
            // Given this procedure is running, the SBE deadman function did
            // its job. Check that for the SBE_VITAL being at the correct spot
            rc = fapiGetScom(i_target, MBOX_SBEVITAL_0x0005001C, data);
            if(!rc.ok())
            {
                FAPI_ERR("Scom error reading SBE VITAL\n");
                break;
            }

            uint32_t istep_num = 0;
            uint8_t substep_num = 0;
            rc_ecmd |= data.extractToRight(&istep_num,
                                           ISTEP_NUM_BIT_POSITION,
                                           ISTEP_NUM_BIT_LENGTH);
            rc_ecmd |= data.extractToRight(&substep_num,
                                           SUBSTEP_NUM_BIT_POSITION,
                                           SUBSTEP_NUM_BIT_LENGTH);
            if(rc_ecmd)
            {
                FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            if( istep_num != proc_sbe_trigger_winkle_istep_num )
            {

                FAPI_ERR("Expected istep num %llX but found %X\n",
                         proc_sbe_trigger_winkle_istep_num,
                         istep_num );
                const fapi::Target & CHIP_IN_ERROR = i_target;
                ecmdDataBufferBase & SBE_VITAL = data;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_STOP_DEADMAN_TIMER_BAD_ISTEP_NUM);
                fapiLogError(rc);
            }

            if( substep_num != SUBSTEP_DEADMAN_WAITING_FOR_HOSTBOOT )
            {
                FAPI_ERR("Expected substep num %X but found %X\n",
                         SUBSTEP_DEADMAN_WAITING_FOR_HOSTBOOT,
                         substep_num );
                const fapi::Target & CHIP_IN_ERROR = i_target;
                ecmdDataBufferBase & SBE_VITAL = data;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_STOP_DEADMAN_TIMER_BAD_SUBSTEP_NUM);
                fapiLogError(rc);
            }

            //Notify SBE that HB is alive again
            substep_num = SUBSTEP_HOSTBOOT_ALIVE_AGAIN;
            rc_ecmd |= data.insertFromRight(&substep_num,
                                            SUBSTEP_NUM_BIT_POSITION,
                                            SUBSTEP_NUM_BIT_LENGTH);
            if(rc_ecmd)
            {
                FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(i_target, MBOX_SBEVITAL_0x0005001C, data);
            if(!rc.ok())
            {
                FAPI_ERR("Scom error updating SBE VITAL\n");
                break;
            }

            // Stop SBE if needed
            rc = fapiGetScom(i_target, PORE_SBE_CONTROL_0x000E0001, data);
            if(!rc.ok())
            {
                FAPI_ERR("Scom error reading SBE STATUS\n");
                break;
            }
            if( data.isBitSet( 0 ) )
            {
                FAPI_INF("SBE/Deadman timer successfully stopped\n");
                break;
            }
            else
            {
                rc_ecmd |= data.setBit( 0 );
                if(rc_ecmd)
                {
                    FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom(i_target, PORE_SBE_CONTROL_0x000E0001, data);
                if(!rc.ok())
                {
                    FAPI_ERR("Scom error stopping SBE\n");
                    break;
                }
            }

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

        // mark function exit
        FAPI_INF("Exit");
        return rc;
    }

} // extern "C"
/* Local Variables: */
/* c-basic-offset: 4 */
/* End: */
