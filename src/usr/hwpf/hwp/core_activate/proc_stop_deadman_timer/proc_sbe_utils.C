/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/core_activate/proc_stop_deadman_timer/proc_sbe_utils.C $ */
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
// $Id: proc_sbe_utils.C,v 1.1 2015/07/27 00:39:15 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_sbe_utils.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2015
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_sbe_utils.C
// *! DESCRIPTION : SBE utility functions
// *!
// *! OWNER NAME  : Joe McGill              Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <proc_sbe_utils.H>
#include <p8_scom_addresses.H>
#include <p8_istep_num.H>
#include <sbe_vital.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const uint8_t SBE_STOPPED_AT_BREAKPOINT_0xB = 0xB;


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
extern "C"
{


fapi::ReturnCode proc_sbe_utils_reset_sbe(
    const fapi::Target & i_target)
{
    ecmdDataBufferBase sbe_reset_data(64);
    uint32_t rc_ecmd = 0;
    fapi::ReturnCode rc;

    do
    {
        rc_ecmd |= sbe_reset_data.flushTo0();
        rc_ecmd |= sbe_reset_data.setBit(0);

        if (rc_ecmd)
        {
            FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(i_target, PORE_SBE_RESET_0x000E0002, sbe_reset_data);
        if (!rc.ok())
        {
            FAPI_ERR("Scom error resetting SBE");
            break;
        }
    } while(0);

    return rc;
}


fapi::ReturnCode proc_sbe_utils_update_substep(
    const fapi::Target & i_target,
    uint8_t i_substep_num)
{
    // data buffer to hold register values
    ecmdDataBufferBase sbe_vital_data(64);

    // return codes
    uint32_t rc_ecmd = 0;
    fapi::ReturnCode rc;

    do
    {
        // read SBE Vital register
        FAPI_DBG("Checking SBE Vital register");
        rc = fapiGetScom(i_target, MBOX_SBEVITAL_0x0005001C, sbe_vital_data);
        if (!rc.ok())
        {
            FAPI_ERR("Error reading SBE Vital register");
            break;
        }

        rc_ecmd |= sbe_vital_data.insertFromRight(&i_substep_num,
                                                  SUBSTEP_NUM_BIT_POSITION,
                                                  SUBSTEP_NUM_BIT_LENGTH);
        if (rc_ecmd)
        {
            FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(i_target, MBOX_SBEVITAL_0x0005001C, sbe_vital_data);
        if(!rc.ok())
        {
            FAPI_ERR("Error updating SBE Vital register");
            break;
        }
    } while(0);

    return(rc);
}



fapi::ReturnCode proc_sbe_utils_check_status(
    const fapi::Target & i_target,
    bool & o_running,
    uint8_t & o_halt_code,
    uint16_t & o_istep_num,
    uint8_t & o_substep_num)
{
    // data buffer to hold register values
    ecmdDataBufferBase sbe_vital_data(64);
    ecmdDataBufferBase sbe_control_data(64);
    ecmdDataBufferBase sbe_status_data(64);

    // return codes
    uint32_t rc_ecmd = 0;
    fapi::ReturnCode rc;

    do
    {
        // read SBE Control register
        FAPI_DBG("Checking SBE Control register");
        rc = fapiGetScom(i_target, PORE_SBE_CONTROL_0x000E0001, sbe_control_data);
        if (!rc.ok())
        {
            FAPI_ERR("Error reading SBE Control register");
            break;
        }

        // Bit 0 : 1=stopped, 0=running (or stopped at breakpoint)
        if (sbe_control_data.isBitClear(0))
        {
            o_running = true;

            // if running, check for stopped at breakpoint
            FAPI_DBG("Checking SBE Status register");
            rc = fapiGetScom(i_target, PORE_SBE_STATUS_0x000E0000, sbe_status_data);
            if (!rc.ok())
            {
                FAPI_ERR("Error reading SBE Status register");
                break;
            }

            uint8_t state = 0;
            uint64_t address = sbe_status_data.getDoubleWord(0) & 0x0000FFFFFFFFFFFFULL;
            rc_ecmd |= sbe_status_data.extractToRight(&state, 3, 4);
            if (rc_ecmd)
            {
                FAPI_ERR("Error (0x%x) extracting data from SBE Status data buffer",
                         rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }

            if (state == SBE_STOPPED_AT_BREAKPOINT_0xB)
            {
                FAPI_INF("SBE stopped at breakpoint (address 0x%012llX)",
                         address);
                o_running = false;
                break;
            }
        }
        else
        {
            o_running = false;
        }

        // read SBE Vital register
        FAPI_DBG("Checking SBE Vital register");
        rc = fapiGetScom(i_target, MBOX_SBEVITAL_0x0005001C, sbe_vital_data);
        if (!rc.ok())
        {
            FAPI_ERR("Error reading SBE Vital register");
            break;
        }

        // parse out halt code & istep progress information
        o_halt_code = 0;
        o_istep_num = 0;
        o_substep_num = 0;
        rc_ecmd |= sbe_vital_data.extractToRight(&o_halt_code,
                                                 HALT_CODE_BIT_POSITION,
                                                 HALT_CODE_BIT_LENGTH);
        rc_ecmd |= sbe_vital_data.extractToRight(&o_istep_num,
                                                 ISTEP_NUM_BIT_POSITION,
                                                 ISTEP_NUM_BIT_LENGTH);
        rc_ecmd |= sbe_vital_data.extractToRight(&o_substep_num,
                                                 SUBSTEP_NUM_BIT_POSITION,
                                                 SUBSTEP_NUM_BIT_LENGTH);
        if (rc_ecmd)
        {
            FAPI_ERR("Error (0x%x) extracting data from SBE Vital data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

    } while(0);

    return rc;
}


} // extern "C"
