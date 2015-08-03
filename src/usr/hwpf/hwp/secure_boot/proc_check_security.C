/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/secure_boot/proc_check_security.C $          */
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
// $Id: proc_check_security.C,v 1.2 2015/08/03 14:04:43 thi Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_check_security.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2015
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_check_security.C
// *! DESCRIPTION : Determine state of processor security controls
// *!
// *! OWNER NAME  : Joe McGill               Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p8_scom_addresses.H>
#include <proc_check_security.H>


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// Security Switch register field/bit definitions
const uint32_t OTPC_M_SECURITY_SWITCH_TRUSTED_BOOT_BIT = 1;


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

extern "C"
{

//------------------------------------------------------------------------------
// function:
//      Determine state of processor security controls
//
// parameters: i_target => chip target
//             o_secure => true if security enabled, else false
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_check_security(
    const fapi::Target& i_target,
    bool & o_secure)
{
    // return codes
    fapi::ReturnCode rc;

    // mark function entry
    FAPI_DBG("Start");

    do
    {
        ecmdDataBufferBase security_switch_data(64);
        rc = fapiGetScom(i_target, OTPC_M_SECURITY_SWITCH_0x00010005, security_switch_data);
        if (!rc.ok())
        {
            FAPI_ERR("Error reading Security Switch Register");
            break;
        }
        o_secure = security_switch_data.isBitSet(OTPC_M_SECURITY_SWITCH_TRUSTED_BOOT_BIT);

    } while(0);

    // mark function entry
    FAPI_DBG("End");
    return rc;
}


} // extern "C"
