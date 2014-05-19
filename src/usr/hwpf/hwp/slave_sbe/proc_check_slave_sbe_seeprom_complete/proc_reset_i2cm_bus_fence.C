/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_reset_i2cm_bus_fence.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
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
// $Id: proc_reset_i2cm_bus_fence.C,v 1.1 2014/02/18 19:53:44 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_reset_i2cm_bus_fence.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : proc_reset_i2cm_bus_fence.C
// *! DESCRIPTION : Clear i2cm bus fence to restore FSP access (FAPI)
// *!
// *! OWNER NAME : Joe McGill        Email: jmcgill@us.ibm.com
// *!
// *! ADDITIONAL COMMENTS :
// *!
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <proc_reset_i2cm_bus_fence.H>
#include <p8_scom_addresses.H>


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const uint32_t CFAM_FSI_GP4_I2CM_BUS_FENCE_BIT = 20;


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

extern "C" {

// HWP entry point, comments in header
fapi::ReturnCode proc_reset_i2cm_bus_fence(const fapi::Target & i_target)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    ecmdDataBufferBase cfam_data(32);

    // mark HWP entry
    FAPI_INF("proc_reset_i2cm_bus_fence: Start");

    do
    {
        // read FSI GP4
        rc = fapiGetCfamRegister(i_target, CFAM_FSI_GP4_0x00002813, cfam_data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_reset_i2cm_bus_fence: Error from fapiGetCfamRegister (CFAM_FSI_GP4_0x00002813)");
            break;
        }

        // clear fence bit
        rc_ecmd |= cfam_data.clearBit(CFAM_FSI_GP4_I2CM_BUS_FENCE_BIT);
        if (rc_ecmd)
        {
            FAPI_ERR("proc_reset_i2cm_bus_fence: Error 0x%x forming FSI GP4 register write data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // write back modified data
        rc = fapiPutCfamRegister(i_target, CFAM_FSI_GP4_0x00002813, cfam_data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_reset_i2cm_bus_fence: Error from fapiGetCfamRegister (CFAM_FSI_GP4_0x00002813)");
            break;
        }

    } while(0);

    // mark HWP exit
    FAPI_INF("proc_reset_i2cm_bus_fence: End");
    return rc;
}


} // extern "C"
