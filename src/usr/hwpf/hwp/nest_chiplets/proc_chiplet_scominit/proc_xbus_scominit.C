/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_chiplet_scominit/proc_xbus_scominit.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: proc_xbus_scominit.C,v 1.6 2014/03/12 18:56:56 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_xbus_scominit.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : proc_xbus_scominit.C
// *! DESCRIPTION : Invoke XBUS initfile (FAPI)
// *!
// *! OWNER NAME  : Mike Jones        Email: mjjones@us.ibm.com
// *! BACKUP NAME : Joe McGill        Email: jmcgill@us.ibm.com
// *!
// *! ADDITIONAL COMMENTS :
// *!
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//  Version     Date        Owner       Description
//------------------------------------------------------------------------------
//    1.6       03/10/14    jmcgill     Add endpoint power up
//    1.5       11/08/13    jmcgill     Updates for RAS review
//    1.4       02/06/13    thomsen     Changed order of targets expected by
//                                      initfile
//    1.3       01/31/13    thomsen     Added separate calls to base &
//                                      customized scominit files. Removed
//                                      separate calls to SIM vs. HW scominit
//                                      files
//    1.2       01/09/13    thomsen     Added separate calls to SIM vs. HW
//                                      scominit files
//                                      Added parent chip and connected targets
//                                      to vector of passed targets. This is to
//                                      match scominit file updates.
//                                      Added commented-out call to OVERRIDE
//                                      initfile for system/bus/lane specific
//                                      inits
//    1.1       8/11/12     jmcgill     Initial release
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <fapiHwpExecInitFile.H>
#include <proc_xbus_scominit.H>
#include <p8_scom_addresses.H>

extern "C" {

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

// HWP entry point, comments in header
fapi::ReturnCode proc_xbus_scominit(const fapi::Target & i_xbus_target,
                                    const fapi::Target & i_connected_xbus_target)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;

    std::vector<fapi::Target> targets;
    fapi::Target this_pu_target;
    fapi::Target connected_pu_target;
    uint8_t xbus_enable_attr;

    ecmdDataBufferBase data(64);

    // mark HWP entry
    FAPI_INF("proc_xbus_scominit: Start");

    do
    {
        // test target types to confirm correctness before calling initfile(s)
        // to execute
        if ((i_xbus_target.getType()           == fapi::TARGET_TYPE_XBUS_ENDPOINT) &&
            (i_connected_xbus_target.getType() == fapi::TARGET_TYPE_XBUS_ENDPOINT))
        {
            // get parent chip targets
            rc = fapiGetParentChip(i_xbus_target, this_pu_target);
            if (!rc.ok())
            {
                FAPI_ERR("proc_xbus_scominit: Error from fapiGetParentChip (this target, %s)",
                         i_xbus_target.toEcmdString());
                break;
            }

            rc = fapiGetParentChip(i_connected_xbus_target, connected_pu_target);
            if (!rc.ok())
            {
                FAPI_ERR("proc_xbus_scominit: Error from fapiGetParentChip (connected target, %s)",
                         i_connected_xbus_target.toEcmdString());
                break;
            }

            // populate targets vector
            targets.push_back(i_xbus_target);           // chiplet target
            targets.push_back(this_pu_target);          // chip target
            targets.push_back(i_connected_xbus_target); // connected chiplet target
            targets.push_back(connected_pu_target);     // connected chip target

            // query XBUS partial good attribute
            rc = FAPI_ATTR_GET(ATTR_PROC_X_ENABLE,
                               &this_pu_target,
                               xbus_enable_attr);
            if (!rc.ok())
            {
                FAPI_ERR("proc_xbus_scominit: Error querying ATTR_PROC_X_ENABLE (%s)",
                         this_pu_target.toEcmdString());
                break;
            }

            if (xbus_enable_attr != fapi::ENUM_ATTR_PROC_X_ENABLE_ENABLE)
            {
                FAPI_ERR("proc_xbus_scominit: Partial good attribute error");
                const fapi::Target & TARGET = this_pu_target;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_XBUS_SCOMINIT_PARTIAL_GOOD_ERR);
                break;
            }

            // assert IO reset to power-up bus endpoint logic
            // read-modify-write, set single reset bit (HW auto-clears)
            // on writeback
            rc = fapiGetScom(i_xbus_target, X_XBUS_SCOM_MODE_PB_0x04011020, data);
            if (!rc.ok())
            {
                FAPI_ERR("proc_xbus_scominit: Error from fapiGetScom (X_XBUS_SCOM_MODE_PB_0x04011020) on %s",
                         i_xbus_target.toEcmdString());
                break;
            }

            rc_ecmd |= data.setBit(2,5);
            if (rc_ecmd)
            {
                FAPI_ERR("proc_xbus_scominit: Error 0x%x forming XBUS SCOM Mode PB register data buffer on %s",
                         rc_ecmd, i_xbus_target.toEcmdString());
                rc.setEcmdError(rc_ecmd);
                break;
            }

            rc = fapiPutScom(i_xbus_target, X_XBUS_SCOM_MODE_PB_0x04011020, data);
            if (!rc.ok())
            {
                FAPI_ERR("proc_xbus_scominit: Error from fapiPutScom (X_XBUS_SCOM_MODE_PB_0x04011020) on %s",
                         i_xbus_target.toEcmdString());
                break;
            }


            // Call BASE XBUS SCOMINIT
            FAPI_INF("proc_xbus_scominit: fapiHwpExecInitfile executing %s on %s, %s, %s, %s",
                XBUS_BASE_IF,
                i_xbus_target.toEcmdString(), this_pu_target.toEcmdString(),
                i_connected_xbus_target.toEcmdString(), connected_pu_target.toEcmdString());
            FAPI_EXEC_HWP(rc, fapiHwpExecInitFile, targets, XBUS_BASE_IF);
            if (!rc.ok())
            {
                FAPI_ERR("proc_xbus_scominit: Error from fapiHwpExecInitfile executing %s on %s, %s, %s, %s",
                    XBUS_BASE_IF,
                    i_xbus_target.toEcmdString(), this_pu_target.toEcmdString(),
                    i_connected_xbus_target.toEcmdString(), connected_pu_target.toEcmdString());
                break;
            }

            // Call CUSTOMIZED XBUS SCOMINIT
            FAPI_INF("proc_xbus_scominit: fapiHwpExecInitfile executing %s on %s, %s, %s, %s",
                XBUS_CUSTOM_IF,
                i_xbus_target.toEcmdString(), this_pu_target.toEcmdString(),
                i_connected_xbus_target.toEcmdString(), connected_pu_target.toEcmdString());
            FAPI_EXEC_HWP(rc, fapiHwpExecInitFile, targets, XBUS_CUSTOM_IF);
            if (!rc.ok())
            {
                FAPI_ERR("proc_xbus_scominit: Error from fapiHwpExecInitfile executing %s on %s, %s, %s, %s",
                    XBUS_BASE_IF,
                    i_xbus_target.toEcmdString(), this_pu_target.toEcmdString(),
                    i_connected_xbus_target.toEcmdString(), connected_pu_target.toEcmdString());
                break;
            }
        }
        // unsupported target type
        else
        {
            FAPI_ERR("proc_xbus_scominit: Unsupported target type(s)");
            const fapi::Target & THIS_XBUS_TARGET = i_xbus_target;
            const fapi::Target & CONNECTED_XBUS_TARGET = i_connected_xbus_target;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_XBUS_SCOMINIT_INVALID_TARGET);
            break;
        }
    } while (0);

    // mark HWP exit
    FAPI_INF("proc_xbus_scominit: End");
    return rc;
}


} // extern "C"
