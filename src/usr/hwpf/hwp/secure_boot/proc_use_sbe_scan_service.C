/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/secure_boot/proc_use_sbe_scan_service.C $    */
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
// $Id: proc_use_sbe_scan_service.C,v 1.1 2015/05/14 21:49:17 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_use_sbe_scan_service.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2015
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_use_sbe_scan_service.C
// *! DESCRIPTION : Shared routine used to determine use of SBE runtime scan
// *!               service
// *!
// *! OWNER NAME  : Joe McGill               Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p8_scom_addresses.H>
#include <proc_use_sbe_scan_service.H>
#include <proc_check_master_sbe_seeprom.H>
#include <proc_check_security.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

extern "C"
{

//------------------------------------------------------------------------------
// function:
//      Use SBE runtime scan service?
//
// parameters: i_target => chip target
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_use_sbe_scan_service(
    const fapi::Target& i_target,
    bool& o_use_sbe_scan_service)
{
    // return codes
    fapi::ReturnCode rc;

    // mark function entry
    FAPI_DBG("Start");

    do
    {
        // make determination of scan path to use
        // use SBE scan service if:
        //   processor chip target AND
        //   slave chip AND
        //   ((secure boot enabled OR ATTR_FORCE_USE_SBE_SLAVE_SCAN_SERVICE) AND !ATTR_TRUSTED_SLAVE_SCAN_PATH_ACTIVE)

        // check for processor chip target
        o_use_sbe_scan_service = (i_target.getType() == fapi::TARGET_TYPE_PROC_CHIP);
        // check for slave chip
        if (o_use_sbe_scan_service)
        {
            bool is_master;
            FAPI_EXEC_HWP(rc, proc_check_master_sbe_seeprom, i_target, is_master);
            if (!rc.ok())
            {
                FAPI_ERR("Error from proc_check_master_sbe_seeprom");
                break;
            }
            o_use_sbe_scan_service = !is_master;
        }
        // check for security state/attribute direction
        if (o_use_sbe_scan_service)
        {
            bool is_secure;
            FAPI_EXEC_HWP(rc, proc_check_security, i_target, is_secure);
            if (!rc.ok())
            {
                FAPI_ERR("Error from proc_check_security");
                break;
            }
            o_use_sbe_scan_service = is_secure;

            // force use of SBE scan service by attribute
            if (!o_use_sbe_scan_service)
            {
                fapi::ATTR_FORCE_USE_SBE_SLAVE_SCAN_SERVICE_Type force_use_sbe_attr;
                rc = FAPI_ATTR_GET(ATTR_FORCE_USE_SBE_SLAVE_SCAN_SERVICE, NULL, force_use_sbe_attr);
                if (!rc.ok())
                {
                    FAPI_ERR("Error reading ATTR_FORCE_USE_SBE_SLAVE_SCAN_SERVICE");
                    break;
                }

                o_use_sbe_scan_service = (force_use_sbe_attr == fapi::ENUM_ATTR_FORCE_USE_SBE_SLAVE_SCAN_SERVICE_TRUE);
            }

            // discontinue use of SBE scan service once trusted scan path is available
            if (o_use_sbe_scan_service)
            {
                fapi::ATTR_TRUSTED_SLAVE_SCAN_PATH_ACTIVE_Type trusted_slave_scan_path_active;
                rc = FAPI_ATTR_GET(ATTR_TRUSTED_SLAVE_SCAN_PATH_ACTIVE, NULL, trusted_slave_scan_path_active);
                if (!rc.ok())
                {
                    FAPI_ERR("Error reading ATTR_TRUSTED_SLAVE_SCAN_PATH_ACTIVE");
                    break;
                }

                o_use_sbe_scan_service = (trusted_slave_scan_path_active == fapi::ENUM_ATTR_TRUSTED_SLAVE_SCAN_PATH_ACTIVE_FALSE);
            }
        }
    } while(0);

    // mark function entry
    FAPI_DBG("End");
    return rc;
}


} // extern "C"
