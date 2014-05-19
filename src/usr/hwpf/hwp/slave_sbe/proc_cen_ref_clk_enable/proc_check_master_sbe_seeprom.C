/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_cen_ref_clk_enable/proc_check_master_sbe_seeprom.C $ */
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
// $Id: proc_check_master_sbe_seeprom.C,v 1.1 2013/09/23 22:04:00 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_check_master_sbe_seeprom.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_check_master_sbe_seeprom.C
// *! DESCRIPTION : Determine if given chip is the drawer master (FAPI)
// *!
// *! OWNER NAME  : Joe McGill    Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_check_master_sbe_seeprom.H"
#include "p8_scom_addresses.H"


extern "C"
{

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi::ReturnCode proc_check_master_sbe_seeprom(
    const fapi::Target & i_target,
    bool & o_is_master)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    ecmdDataBufferBase data;

    bool pri_master = false;
    uint8_t chip_id;

    FAPI_DBG("proc_check_master_sbe_seeprom: Start");

    do
    {
        // read SBE vital to determine primary/secondary master bit state
        rc = fapiGetScom(i_target,
                         MBOX_SBEVITAL_0x0005001C,
                         data);

        if (!rc.ok())
        {
            FAPI_ERR("proc_check_master_sbe_seeprom: Error from fapiGetScom (MBOX_SBEVITAL_0x005001C)");
            break;
        }

        // extract primary/secondary master bit
        pri_master = data.isBitClear(MBOX_SBEVITAL_SBE_SELECT_MODE_MASTER_BIT);

        // read device ID register to determine chip position
        rc = fapiGetScom(i_target,
                         PCBMS_DEVICE_ID_0x000F000F,
                         data);

        if (!rc.ok())
        {
            FAPI_ERR("proc_check_master_sbe_seeprom: Error from fapiGetScom (PCBMS_DEVICE_ID_0x000F000F)");
            break;
        }

        // extract socketID and chip position fields
        rc_ecmd |= data.extractToRight(
            &chip_id,
            PCBMS_DEVICE_ID_CHIP_ID_START_BIT,
            (PCBMS_DEVICE_ID_CHIP_ID_END_BIT-
             PCBMS_DEVICE_ID_CHIP_ID_START_BIT)+1);

        // check data buffer manipulation return code
        if (rc_ecmd)
        {
            FAPI_ERR("proc_check_master_sbe_seeprom: Error 0x%X extracting socket/chip position",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // compare SBE Vital/Device ID fields with expected values
        // for master chip
        if ((pri_master && (chip_id == PCBMS_DEVICE_ID_PRIMARY_MASTER)) ||
            (!pri_master && (chip_id == PCBMS_DEVICE_ID_ALTERNATE_MASTER)))
        {
            o_is_master = true;
        }
        else
        {
            o_is_master = false;
        }
    } while(0);

    FAPI_DBG("proc_check_master_sbe_seeprom: End");
    return rc;
}


} // extern "C"
