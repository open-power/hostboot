/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_chiplet_scominit/proc_chiplet_scominit.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: proc_chiplet_scominit.C,v 1.9 2013/01/20 19:29:42 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_chiplet_scominit.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : proc_chiplet_scominit.C
// *! DESCRIPTION : Invoke initfiles for proc_chiplet_scominit istep (FAPI)
// *!
// *! OWNER NAME  : Mike Jones        Email: mjjones@us.ibm.com
// *! BACKUP NAME : Joe McGill        Email: jmcgill@us.ibm.com
// *!
// *! ADDITIONAL COMMENTS :
// *!
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <fapiHwpExecInitFile.H>
#include <proc_chiplet_scominit.H>

extern "C" {

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

// HWP entry point, comments in header
fapi::ReturnCode proc_chiplet_scominit(const fapi::Target & i_target)
{
    fapi::ReturnCode rc;
    fapi::TargetType target_type;
    std::vector<fapi::Target> initfile_targets;
    uint8_t nx_enabled;

    // mark HWP entry
    FAPI_INF("proc_chiplet_scominit: Start");

    do
    {
        // obtain target type to determine which initfile(s) to execute
        target_type = i_target.getType();

        // chip level target
        if (target_type == fapi::TARGET_TYPE_PROC_CHIP)
        {
            // execute FBC SCOM initfile
            initfile_targets.push_back(i_target);
            FAPI_INF("proc_chiplet_scominit: Executing %s on %s",
                     PROC_CHIPLET_SCOMINIT_FBC_IF, i_target.toEcmdString());
            FAPI_EXEC_HWP(
                rc,
                fapiHwpExecInitFile,
                initfile_targets,
                PROC_CHIPLET_SCOMINIT_FBC_IF);
            if (!rc.ok())
            {
                FAPI_ERR("proc_chiplet_scominit: Error from fapiHwpExecInitfile executing %s on %s",
                         PROC_CHIPLET_SCOMINIT_FBC_IF,
                         i_target.toEcmdString());
                break;
            }

            // query NX partial good attribute
            rc = FAPI_ATTR_GET(ATTR_PROC_NX_ENABLE,
                               &i_target,
                               nx_enabled);
            if (!rc.ok())
            {
                FAPI_ERR("proc_chiplet_scominit: Error querying ATTR_PROC_NX_ENABLE");
                break;
            }

            // apply NX/AS SCOM initfiles only if partial good attribute is set
            if (nx_enabled == fapi::ENUM_ATTR_PROC_NX_ENABLE_ENABLE)
            {
                // execute NX SCOM initfile
                initfile_targets.clear();
                initfile_targets.push_back(i_target);
                FAPI_INF("proc_chiplet_scominit: Executing %s on %s",
                         PROC_CHIPLET_SCOMINIT_NX_IF, i_target.toEcmdString());
                FAPI_EXEC_HWP(
                    rc,
                    fapiHwpExecInitFile,
                    initfile_targets,
                    PROC_CHIPLET_SCOMINIT_NX_IF);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_chiplet_scominit: Error from fapiHwpExecInitfile executing %s on %s",
                             PROC_CHIPLET_SCOMINIT_NX_IF,
                             i_target.toEcmdString());
                    break;
                }

                // execute AS SCOM initfile
                FAPI_INF("proc_chiplet_scominit: Executing %s on %s",
                         PROC_CHIPLET_SCOMINIT_AS_IF, i_target.toEcmdString());
                FAPI_EXEC_HWP(
                    rc,
                    fapiHwpExecInitFile,
                    initfile_targets,
                    PROC_CHIPLET_SCOMINIT_AS_IF);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_chiplet_scominit: Error from fapiHwpExecInitfile executing %s on %s",
                             PROC_CHIPLET_SCOMINIT_AS_IF,
                             i_target.toEcmdString());
                    break;
                }
            }
            else
            {
                FAPI_DBG("proc_chiplet_scominit: Skipping execution of %s/%s (partial good)",
                         PROC_CHIPLET_SCOMINIT_NX_IF, PROC_CHIPLET_SCOMINIT_AS_IF);
            }

            // determine set of functional MCS chiplets
            std::vector<fapi::Target> mcs_targets;
            rc = fapiGetChildChiplets(i_target,
                                      fapi::TARGET_TYPE_MCS_CHIPLET,
                                      mcs_targets,
                                      fapi::TARGET_STATE_FUNCTIONAL);
            if (!rc.ok())
            {
                FAPI_ERR("proc_chiplet_scominit: Error from fapiGetChildChiplets");
                break;
            }

            // apply MCS SCOM initfile only for functional chiplets
            for (std::vector<fapi::Target>::iterator i = mcs_targets.begin();
                 (i != mcs_targets.end()) && rc.ok();
                 i++)
            {
                // execute MCS SCOM initfile
                initfile_targets.clear();
                initfile_targets.push_back(*i);
                FAPI_INF("proc_chiplet_scominit: Executing %s on %s",
                         PROC_CHIPLET_SCOMINIT_MCS_IF, i->toEcmdString());
                FAPI_EXEC_HWP(
                    rc,
                    fapiHwpExecInitFile,
                    initfile_targets,
                    PROC_CHIPLET_SCOMINIT_MCS_IF);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_chiplet_scominit: Error from fapiHwpExecInitfile executing %s on %s",
                             PROC_CHIPLET_SCOMINIT_MCS_IF,
                             i->toEcmdString());
                    break;
                }
            }
            if (!rc.ok())
            {
                break;
            }
        }
        // unsupported target type
        else
        {
            FAPI_ERR("proc_chiplet_scominit: Unsupported target type");
            FAPI_SET_HWP_ERROR(rc, RC_PROC_CHIPLET_SCOMINIT_INVALID_TARGET);
            break;
        }
    } while(0);

    // mark HWP exit
    FAPI_INF("proc_chiplet_scominit: End");
    return rc;
}


} // extern "C"
