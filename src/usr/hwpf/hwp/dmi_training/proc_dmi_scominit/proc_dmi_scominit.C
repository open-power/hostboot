/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dmi_training/proc_dmi_scominit/proc_dmi_scominit.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
// $Id: proc_dmi_scominit.C,v 1.5 2013/02/11 03:58:59 jmcgill Exp $
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
//  Version		Date		Owner		Description
//------------------------------------------------------------------------------
//    1.5	   	02/06/13	jmcgill		Change passed targets in order to match scominit file updates.
//    1.4	   	02/04/13	thomsen		Fixed informational print to not say Error
//    1.3	   	01/23/13	thomsen		Added separate calls to base & customized scominit files. Removed separate calls to SIM vs. HW scominit files
//    1.2	   	01/10/13	thomsen		Added separate calls to SIM vs. HW scominit files
//   									Added commented-out call to OVERRIDE initfile for system/bus/lane specific inits
//                                      Changed passed targets in order to match scominit file updates.
//                                      CO-REQs required: p8.dmi.vbu.scom.initfile v1.1 and p8.dmi.hw.scom.initfile v1.1
//    1.1       8/11/12     jmcgill		Initial release
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <fapiHwpExecInitFile.H>
#include <proc_dmi_scominit.H>

extern "C" {

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

// HWP entry point, comments in header
fapi::ReturnCode proc_dmi_scominit(const fapi::Target & i_target)
{
    fapi::ReturnCode rc;
    fapi::Target i_this_pu_target;
    std::vector<fapi::Target> targets;

    // mark HWP entry
    FAPI_INF("proc_dmi_scominit: Start");

    do
    {

	    // Get parent chip target
        rc = fapiGetParentChip(i_target, i_this_pu_target); if(rc) return rc;

		// populate targets vector (i_target=chiplet target)
        targets.push_back(i_target);

        // processor MCS chiplet target
        // test target type to confirm correct before calling initfile(s) to execute
        if (i_target.getType() == fapi::TARGET_TYPE_MCS_CHIPLET)
        {
		    // Call BASE DMI SCOMINIT
            FAPI_INF("proc_dmi_scominit: fapiHwpExecInitfile executing %s on %s",
                     MCS_DMI_BASE_IF, i_target.toEcmdString());
            FAPI_EXEC_HWP(rc, fapiHwpExecInitFile, targets, MCS_DMI_BASE_IF);
            if (!rc.ok())
            {
                FAPI_ERR("proc_dmi_scominit: Error from fapiHwpExecInitfile executing %s on %s",
                         MCS_DMI_BASE_IF, i_target.toEcmdString());
                break;
            }
		    // Call CUSTOMIZED DMI SCOMINIT (system specific)
            FAPI_INF("proc_dmi_scominit: fapiHwpExecInitfile executing %s on %s",
                     MCS_DMI_CUSTOM_IF, i_target.toEcmdString());
            FAPI_EXEC_HWP(rc, fapiHwpExecInitFile, targets, MCS_DMI_CUSTOM_IF);
            if (!rc.ok())
            {
                FAPI_ERR("proc_dmi_scominit: Error from fapiHwpExecInitfile executing %s on %s",
                         MCS_DMI_CUSTOM_IF, i_target.toEcmdString());
                break;
            }
	    }
        // unsupported target type
        else
        {
            FAPI_ERR("proc_dmi_scominit: Unsupported target type");
            FAPI_SET_HWP_ERROR(rc, RC_PROC_DMI_SCOMINIT_INVALID_TARGET);
            break;
        }
    } while (0);

    // mark HWP exit
    FAPI_INF("proc_dmi_scominit: End");
	return rc;
}


} // extern "C"
