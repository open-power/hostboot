/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dmi_training/proc_dmi_scominit/proc_dmi_scominit.C $ */
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
// $Id: proc_dmi_scominit.C,v 1.10 2014/05/08 20:46:32 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_dmi_scominit.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : proc_dmi_scominit.C
// *! DESCRIPTION : Invoke DMI initfiles (FAPI)
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
//    1.9       03/10/14    jmcgill     Add endpoint power up
//    1.8       10/08/13    jmcgill     Updates for RAS review
//    1.7       05/14/13    jmcgill     Address review comments
//    1.6       05/01/13    jgrell      Added proc chip target
//    1.5       02/06/13    jmcgill     Change passed targets in order to match
//                                      scominit file updates.
//    1.4       02/04/13    thomsen     Fixed informational print to not say
//                                      Error
//    1.3       01/23/13    thomsen     Added separate calls to base &
//                                      customized scominit files. Removed
//                                      separate calls to SIM vs. HW scominit
//                                      files
//    1.2       01/10/13    thomsen     Added separate calls to SIM vs. HW
//                                      scominit files
//                                      Added commented-out call to OVERRIDE
//                                      initfile for system/bus/lane specific
//                                      inits
//                                      Changed passed targets in order to match
//                                      scominit file updates.
//                                      CO-REQs required:
//                                        p8.dmi.vbu.scom.initfile v1.1 and
//                                        p8.dmi.hw.scom.initfile v1.1
//    1.1       8/11/12     jmcgill     Initial release
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <fapiHwpExecInitFile.H>
#include <proc_dmi_scominit.H>
#include <p8_scom_addresses.H>


//------------------------------------------------------------------------------
//  Constant definitions
//------------------------------------------------------------------------------

// map MCS chiplet ID -> associated bus IORESET bit in IOMC SCOM_MODE_PB
// register
const uint8_t IOMC_SCOM_MODE_PB_IORESET_BIT[8] = { 5,4,2,3,5,4,2,3 };


extern "C" {

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

// HWP entry point, comments in header
fapi::ReturnCode proc_dmi_scominit(const fapi::Target & i_target)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;

    fapi::Target this_pu_target;
    std::vector<fapi::Target> targets;
    fapi::Target cen_target;

    uint8_t mcs_pos;
    ecmdDataBufferBase data(64);

    // mark HWP entry
    FAPI_INF("proc_dmi_scominit: Start");

    do
    {
        // test target type to confirm correct before calling initfile(s)
        // to execute
        if (i_target.getType() == fapi::TARGET_TYPE_MCS_CHIPLET)
        {

            rc = fapiGetOtherSideOfMemChannel(i_target,
                                              cen_target,
                                              fapi::TARGET_STATE_FUNCTIONAL);
            // use return code only to indicate presence of connected Centaur,
            // do not propogate/emit error if not connected
            if (rc.ok())
            {
                // set the init state attribute to DMI_ACTIVE
                uint8_t attr_mss_init_state = fapi::ENUM_ATTR_MSS_INIT_STATE_DMI_ACTIVE;
                rc = FAPI_ATTR_SET(ATTR_MSS_INIT_STATE,
                                   &cen_target,
                                   attr_mss_init_state);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_dmi_scominit: Error from FAPI_ATTR_SET (ATTR_MSS_INIT_STATE) on %s",
                             cen_target.toEcmdString());
                    break;
                }
            }
            else
            {
                rc = fapi::FAPI_RC_SUCCESS;
            }


            // assert IO reset to power-up bus endpoint logic
            rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target, mcs_pos);
            if (!rc.ok())
            {
                FAPI_ERR("proc_dmi_scominit: Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS) on %s",
                         i_target.toEcmdString());
                break;
            }

            // read-modify-write, set single reset bit (HW auto-clears)
            // on writeback
            rc = fapiGetScom(i_target, IOMC_SCOM_MODE_PB_0x02011A20, data);
            if (!rc.ok())
            {
                FAPI_ERR("proc_dmi_scominit: Error from fapiGetScom (IOMC_SCOM_MODE_PB_0x02011A20) on %s",
                         i_target.toEcmdString());
                break;
            }

            rc_ecmd |= data.setBit(IOMC_SCOM_MODE_PB_IORESET_BIT[mcs_pos]);
            if (rc_ecmd)
            {
                FAPI_ERR("proc_dmi_scominit: Error 0x%x forming IOMC SCOM Mode PB register data buffer on %s",
                         rc_ecmd, i_target.toEcmdString());
                rc.setEcmdError(rc_ecmd);
                break;
            }

            rc = fapiPutScom(i_target, IOMC_SCOM_MODE_PB_0x02011A20, data);
            if (!rc.ok())
            {
                FAPI_ERR("proc_dmi_scominit: Error from fapiPutScom (IOMC_SCOM_MODE_PB_0x02011A20) on %s",
                         i_target.toEcmdString());
                break;
            }

            // get parent chip target
            rc = fapiGetParentChip(i_target, this_pu_target);
            if (!rc.ok())
            {
                FAPI_ERR("proc_dmi_scominit: Error from fapiGetParentChip (%s)",
                         i_target.toEcmdString());
                break;
            }

            // populate targets vector
            targets.push_back(i_target);       // chiplet target
            targets.push_back(this_pu_target); // chip target

            // Call BASE DMI SCOMINIT
            FAPI_INF("proc_dmi_scominit: fapiHwpExecInitfile executing %s on %s, %s",
                     MCS_DMI_BASE_IF,
                     i_target.toEcmdString(),
                     this_pu_target.toEcmdString());
            FAPI_EXEC_HWP(rc, fapiHwpExecInitFile, targets, MCS_DMI_BASE_IF);
            if (!rc.ok())
            {
                FAPI_ERR("proc_dmi_scominit: Error from fapiHwpExecInitfile executing %s on %s, %s",
                         MCS_DMI_BASE_IF,
                         i_target.toEcmdString(),
                         this_pu_target.toEcmdString());
                break;
            }

            // Call CUSTOMIZED DMI SCOMINIT
            FAPI_INF("proc_dmi_scominit: fapiHwpExecInitfile executing %s on %s, %s",
                     MCS_DMI_CUSTOM_IF,
                     i_target.toEcmdString(),
                     this_pu_target.toEcmdString());
            FAPI_EXEC_HWP(rc, fapiHwpExecInitFile, targets, MCS_DMI_CUSTOM_IF);
            if (!rc.ok())
            {
                FAPI_ERR("proc_dmi_scominit: Error from fapiHwpExecInitfile executing %s on %s, %s",
                         MCS_DMI_CUSTOM_IF,
                         i_target.toEcmdString(),
                         this_pu_target.toEcmdString());
                break;
            }
        }
        // unsupported target type
        else
        {
            FAPI_ERR("proc_dmi_scominit: Unsupported target type");
            const fapi::Target & MCS_TARGET = i_target;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_DMI_SCOMINIT_INVALID_TARGET);
            break;
        }
    } while (0);

    // mark HWP exit
    FAPI_INF("proc_dmi_scominit: End");
    return rc;
}


} // extern "C"
