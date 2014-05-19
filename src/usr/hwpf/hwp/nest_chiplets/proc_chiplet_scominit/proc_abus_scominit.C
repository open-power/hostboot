/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_chiplet_scominit/proc_abus_scominit.C $ */
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
// $Id: proc_abus_scominit.C,v 1.6 2014/03/12 18:56:56 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_abus_scominit.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : proc_abus_scominit.C
// *! DESCRIPTION : Invoke ABUS initfile (FAPI)
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
//    1.4       02/18/13    thomsen     Changed targeting to use Abus_chiplet,
//                                      chip, connected_Abus_chiplet &
//                                      connected_chip to match Xbus and DMI
//                                      target list so they are common
//    1.3       02/10/13    jmcgill     Leverage chiplet level targeting, invoke
//                                      custom initfile
//    1.2       01/20/13    jmcgill     Add consistency check for A chiplet
//                                      partial good support
//    1.1       8/11/12     jmcgill     Initial release
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <fapiHwpExecInitFile.H>
#include <proc_abus_scominit.H>
#include <p8_scom_addresses.H>

//------------------------------------------------------------------------------
//  Constant definitions
//------------------------------------------------------------------------------

// map ABUS chiplet ID -> associated bus IORESET bit in ABUS SCOM_MODE_PB
// register
const uint8_t ABUS_SCOM_MODE_PB_IORESET_BIT[3] = { 2,3,4 };


extern "C" {

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

// HWP entry point, comments in header
fapi::ReturnCode proc_abus_scominit(const fapi::Target & i_abus_target,
                                    const fapi::Target & i_connected_abus_target)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;

    std::vector<fapi::Target> targets;
    fapi::Target this_pu_target;
    fapi::Target connected_pu_target;
    uint8_t abus_enable_attr;
    uint8_t abus_pos;

    ecmdDataBufferBase data(64);

    // mark HWP entry
    FAPI_INF("proc_abus_scominit: Start");

    do
    {
        // test target types to confirm correctness before calling initfile(s)
        // to execute
        if ((i_abus_target.getType()           == fapi::TARGET_TYPE_ABUS_ENDPOINT) &&
            (i_connected_abus_target.getType() == fapi::TARGET_TYPE_ABUS_ENDPOINT))
        {
            // get parent chip targets
            rc = fapiGetParentChip(i_abus_target, this_pu_target);
            if (!rc.ok())
            {
                FAPI_ERR("proc_abus_scominit: Error from fapiGetParentChip (this target, %s)",
                         i_abus_target.toEcmdString());
                break;
            }

            rc = fapiGetParentChip(i_connected_abus_target, connected_pu_target);
            if (!rc.ok())
            {
                FAPI_ERR("proc_abus_scominit: Error from fapiGetParentChip (connected target, %s)",
                         i_connected_abus_target.toEcmdString());
                break;
            }

            // populate targets vector
            targets.push_back(i_abus_target);           // chiplet target
            targets.push_back(this_pu_target);          // chip target
            targets.push_back(i_connected_abus_target); // connected chiplet target
            targets.push_back(connected_pu_target);     // connected chip target

            // query ABUS partial good attribute
            rc = FAPI_ATTR_GET(ATTR_PROC_A_ENABLE,
                               &this_pu_target,
                               abus_enable_attr);
            if (!rc.ok())
            {
                FAPI_ERR("proc_abus_scominit: Error querying ATTR_PROC_A_ENABLE (%s)",
                         this_pu_target.toEcmdString());
                break;
            }

            if (abus_enable_attr != fapi::ENUM_ATTR_PROC_A_ENABLE_ENABLE)
            {
                FAPI_ERR("proc_abus_scominit: Partial good attribute error");
                const fapi::Target & TARGET = this_pu_target;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_ABUS_SCOMINIT_PARTIAL_GOOD_ERR);
                break;
            }

            // assert IO reset to power-up bus endpoint logic
            rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_abus_target, abus_pos);
            if (!rc.ok())
            {
                FAPI_ERR("proc_abus_scominit: Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS) on %s",
                         i_abus_target.toEcmdString());
                break;
            }

            // read-modify-write, set single reset bit (HW auto-clears)
            // on writeback
            rc = fapiGetScom(i_abus_target, A_ABUS_SCOM_MODE_PB_0x08010C20, data);
            if (!rc.ok())
            {
                FAPI_ERR("proc_abus_scominit: Error from fapiGetScom (A_ABUS_SCOM_MODE_PB_0x08010C20) on %s",
                         i_abus_target.toEcmdString());
                break;
            }

            rc_ecmd |= data.setBit(ABUS_SCOM_MODE_PB_IORESET_BIT[abus_pos]);
            if (rc_ecmd)
            {
                FAPI_ERR("proc_abus_scominit: Error 0x%x forming ABUS SCOM Mode PB register data buffer on %s",
                         rc_ecmd, i_abus_target.toEcmdString());
                rc.setEcmdError(rc_ecmd);
                break;
            }

            rc = fapiPutScom(i_abus_target, A_ABUS_SCOM_MODE_PB_0x08010C20, data);
            if (!rc.ok())
            {
                FAPI_ERR("proc_abus_scominit: Error from fapiPutScom (A_ABUS_SCOM_MODE_PB_0x08010C20) on %s",
                         i_abus_target.toEcmdString());
                break;
            }


            // Call BASE ABUS SCOMINIT
            FAPI_INF("proc_abus_scominit: fapiHwpExecInitfile executing %s on %s, %s, %s, %s",
                ABUS_BASE_IF,
                i_abus_target.toEcmdString(), this_pu_target.toEcmdString(),
                i_connected_abus_target.toEcmdString(), connected_pu_target.toEcmdString());
            FAPI_EXEC_HWP(rc, fapiHwpExecInitFile, targets, ABUS_BASE_IF);
            if (!rc.ok())
            {
                FAPI_ERR("proc_abus_scominit: Error from fapiHwpExecInitfile executing %s on %s, %s, %s, %s",
                    ABUS_BASE_IF,
                    i_abus_target.toEcmdString(), this_pu_target.toEcmdString(),
                    i_connected_abus_target.toEcmdString(), connected_pu_target.toEcmdString());
                break;
            }

            // Call CUSTOMIZED ABUS SCOMINIT
            FAPI_INF("proc_abus_scominit: fapiHwpExecInitfile executing %s on %s, %s, %s, %s",
                ABUS_CUSTOM_IF,
                i_abus_target.toEcmdString(), this_pu_target.toEcmdString(),
                i_connected_abus_target.toEcmdString(), connected_pu_target.toEcmdString());
            FAPI_EXEC_HWP(rc, fapiHwpExecInitFile, targets, ABUS_CUSTOM_IF);
            if (!rc.ok())
            {
                FAPI_ERR("proc_abus_scominit: Error from fapiHwpExecInitfile executing %s on %s, %s, %s, %s",
                    ABUS_BASE_IF,
                    i_abus_target.toEcmdString(), this_pu_target.toEcmdString(),
                    i_connected_abus_target.toEcmdString(), connected_pu_target.toEcmdString());
                break;
            }
        }
        // unsupported target type
        else
        {
            FAPI_ERR("proc_abus_scominit: Unsupported target type(s)");
            const fapi::Target & THIS_ABUS_TARGET = i_abus_target;
            const fapi::Target & CONNECTED_ABUS_TARGET = i_connected_abus_target;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_ABUS_SCOMINIT_INVALID_TARGET);
            break;
        }
    } while (0);

    // mark HWP exit
    FAPI_INF("proc_abus_scominit: End");
    return rc;
}


} // extern "C"
