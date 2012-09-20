/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_chiplet_scominit/proc_chiplet_scominit.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
// $Id: proc_chiplet_scominit.C,v 1.5 2012/08/11 03:43:10 jmcgill Exp $
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
    std::vector<fapi::Target> targets;

    // mark HWP entry
    FAPI_INF("proc_chiplet_scominit: Start");

    do
    {
        // obtain target type to determine which initfile(s) to execute
        target_type = i_target.getType();
        targets.push_back(i_target);

        // chip level target
        if (target_type == fapi::TARGET_TYPE_PROC_CHIP)
        {
            // execute FBC initfile
            FAPI_INF("proc_chiplet_scominit: Executing %s on %s",
                     PROC_CHIPLET_SCOMINIT_FBC_IF, i_target.toEcmdString());
            FAPI_EXEC_HWP(
                rc,
                fapiHwpExecInitFile,
                targets,
                PROC_CHIPLET_SCOMINIT_FBC_IF);
            if (!rc.ok())
            {
                FAPI_ERR("proc_chiplet_scominit: Error from fapiHwpExecInitfile executing %s on %s",
                         PROC_CHIPLET_SCOMINIT_FBC_IF,
                         i_target.toEcmdString());
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
