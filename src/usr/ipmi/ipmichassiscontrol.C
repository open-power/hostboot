/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/ipmichassiscontrol.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2016                        */
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
 *  @file ipmichassiscontrol.C
 *
 *  Ipmi send chassis control command
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <errl/errlentry.H>
#include <ipmi/ipmichassiscontrol.H>
#include <ipmi/ipmiif.H>
#include <initservice/istepdispatcherif.H>

/******************************************************************************/
// Globals/Constants
/******************************************************************************/
// Defined in ipmidd.C
extern trace_desc_t * g_trac_ipmi;
#define IPMI_TRAC(printf_string,args...) \
    TRACFCOMP(g_trac_ipmi,"cc: " printf_string,##args)

namespace IPMI
{

/******************************************************************************/
// Functions
/******************************************************************************/

errlHndl_t chassisControl(const uint8_t i_chassisControlState )
{
    errlHndl_t err_ipmi = NULL;

    size_t len = 1; // IPMI spec has request data at 1 bytes

    //create request data buffer
    uint8_t* data = new uint8_t[len];

    IPMI::completion_code cc = IPMI::CC_UNKBAD;

    data[0] = i_chassisControlState;

    err_ipmi = IPMI::sendrecv(IPMI::chassis_power_off(), cc, len, data);

    //cleanup buffer
    delete[] data;

    if(cc != IPMI::CC_OK)
    {
        IPMI_TRAC("Chassis control : BMC returned not ok CC[%x]",cc);
    }

    // power off command has been sent to the BMC, tell the istep dispacher to
    // stop executing steps.
    INITSERVICE::stopIpl();

    return err_ipmi;
}
} // namespace

