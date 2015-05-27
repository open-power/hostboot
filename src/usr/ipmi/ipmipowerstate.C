/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/ipmipowerstate.C $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
/**
 *  @file ipmipowerstate.C
 *
 *  Ipmi set ACPI Power State
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <errl/errlentry.H>
#include <ipmi/ipmipowerstate.H>
#include <ipmi/ipmiif.H>

/******************************************************************************/
// Globals/Constants
/******************************************************************************/
// Defined in ipmidd.C
extern trace_desc_t * g_trac_ipmi;
#define IPMI_TRAC(printf_string,args...) \
    TRACFCOMP(g_trac_ipmi,"ps: " printf_string,##args)

namespace IPMI
{

/******************************************************************************/
// Functions
/******************************************************************************/

errlHndl_t setACPIPowerState()
{
    errlHndl_t err_ipmi = NULL;

    size_t len = 2; // IPMI spec has request data at 2 bytes

    //create request data buffer
    uint8_t* data = new uint8_t[len];

    IPMI::completion_code cc = IPMI::CC_UNKBAD;

    data[0] = SET_SYSTEM_POWER_STATE | SET_LEGACY_ON;
    data[1] = NO_CHANGE_DEVICE_POWER;

    err_ipmi = IPMI::sendrecv(IPMI::set_acpi_power_state(), cc, len, data);

    //cleanup buffer
    delete[] data;

    if(cc != IPMI::CC_OK)
    {
        IPMI_TRAC("Set ACPI Power State: BMC returned not ok CC[%x]",cc);
        // should we log error and then retry?
        // what happens if the communication is broken
        // reset will try and set it again.
    }

    return err_ipmi;
}

} // namespace

