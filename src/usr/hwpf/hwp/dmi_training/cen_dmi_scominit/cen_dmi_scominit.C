/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dmi_training/cen_dmi_scominit/cen_dmi_scominit.C $ */
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
// $Id: cen_dmi_scominit.C,v 1.5 2013/10/28 23:07:05 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/cen_dmi_scominit.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : cen_dmi_scominit.C
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
//    1.5       10/28/13    jmcgill     Updates for RAS review
//    1.4       02/05/13    thomsen     Fixed typo that caused the procedure
//                                      to not compile
//    1.3       01/31/13    thomsen     Added separate calls to base & custom
//                                      scominit files. Removed separate calls
//                                      to SIM vs. HW scominit files. Fixed
//                                      informational print to not say Error
//    1.2       01/09/13    thomsen     Added separate calls to SIM vs. HW
//                                      scominit files
//                                      Added commented-out call to OVERRIDE
//                                      initfile for system/bus/lane specific
//                                      inits
//    1.1       8/11/12     jmcgill     Initial release
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <fapiHwpExecInitFile.H>
#include <cen_dmi_scominit.H>

extern "C" {

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

// HWP entry point, comments in header
fapi::ReturnCode cen_dmi_scominit(const fapi::Target & i_target)
{
    fapi::ReturnCode rc;
    fapi::TargetType target_type;
    std::vector<fapi::Target> targets;

    // mark HWP entry
    FAPI_INF("cen_dmi_scominit: Start");

    do
    {
        // obtain target type to determine which initfile(s) to execute
        target_type = i_target.getType();
        targets.push_back(i_target);

        // Centaur chip target
        if (target_type == fapi::TARGET_TYPE_MEMBUF_CHIP)
        {
            // Call BASE DMI SCOMINIT
            FAPI_INF("cen_dmi_scominit: fapiHwpExecInitfile executing %s on %s",
                     CEN_DMI_BASE_IF, i_target.toEcmdString());
            FAPI_EXEC_HWP(rc, fapiHwpExecInitFile, targets, CEN_DMI_BASE_IF);
            if (!rc.ok())
            {
                FAPI_ERR("cen_dmi_scominit: Error from fapiHwpExecInitfile executing %s on %s",
                         CEN_DMI_BASE_IF, i_target.toEcmdString());
                break;
            }
            // Call CUSTOMIZED DMI SCOMINIT
            FAPI_INF("cen_dmi_scominit: fapiHwpExecInitfile executing %s on %s",
                     CEN_DMI_CUSTOM_IF, i_target.toEcmdString());
            FAPI_EXEC_HWP(rc, fapiHwpExecInitFile, targets, CEN_DMI_CUSTOM_IF);
            if (!rc.ok())
            {
                FAPI_ERR("cen_dmi_scominit: Error from fapiHwpExecInitfile executing %s on %s",
                         CEN_DMI_CUSTOM_IF, i_target.toEcmdString());
                break;
            }
        }
        // unsupported target type
        else
        {
            FAPI_ERR("cen_dmi_scominit: Unsupported target type");
            const fapi::Target & TARGET = i_target;
            FAPI_SET_HWP_ERROR(rc, RC_CEN_DMI_SCOMINIT_INVALID_TARGET);
            break;
        }
    } while (0);

    // mark HWP exit
    FAPI_INF("cen_dmi_scominit: End");
    return rc;
}


} // extern "C"
