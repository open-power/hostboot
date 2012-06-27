/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/nest_chiplets/proc_chiplet_scominit/proc_chiplet_scominit.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : proc_chiplet_scominit.C
// *! DESCRIPTION : Wrapper HWP that invokes the proc_chiplet_scominit initfiles
// *! OWNER NAME  : Mike Jones        Email: mjjones@us.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// The purpose of this procedure execute memory initfiles in proper sequence.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.2   | mjjones  |26-JUN-12| Initial version

//----------------------------------------------------------------------
//  My Includes
//----------------------------------------------------------------------
#include <proc_chiplet_scominit.H>

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapiHwpExecInitFile.H>

const char * const MCS_DMI_IF = "p8.dmi.scom.if";
const char * const CEN_DMI_IF = "cen.dmi.scom.if";

extern "C" {

fapi::ReturnCode proc_chiplet_scominit(const fapi::Target & i_target)
{
    FAPI_INF("Performing HWP: proc_chiplet_scominit on %s",
             i_target.toEcmdString());
    
    fapi::ReturnCode l_rc;
    fapi::TargetType l_type = i_target.getType();
    std::vector<fapi::Target> l_target;
    l_target.push_back(i_target);
    
    do
    {
        if (l_type == fapi::TARGET_TYPE_MCS_CHIPLET)
        {
            FAPI_INF("Executing %s on %s", MCS_DMI_IF, i_target.toEcmdString());
            FAPI_EXEC_HWP(l_rc, fapiHwpExecInitFile, l_target, MCS_DMI_IF);
        
            if (l_rc)
            {
                FAPI_ERR("Error executing %s on %s", MCS_DMI_IF,
                         i_target.toEcmdString());
                break;
            }
        }
        else if (l_type == fapi::TARGET_TYPE_MEMBUF_CHIP)
        {
            FAPI_INF("Executing %s on %s", CEN_DMI_IF, i_target.toEcmdString());
            FAPI_EXEC_HWP(l_rc, fapiHwpExecInitFile, l_target, CEN_DMI_IF);
        
            if (l_rc)
            {
                FAPI_ERR("Error executing %s on %s", CEN_DMI_IF,
                         i_target.toEcmdString());
                break;
            }
        }
        else
        {
            FAPI_ERR("proc_chiplet_scominit has nothing to do for %s",
                     i_target.toEcmdString());
        }
        
    } while (0);

	return l_rc;
}

} // extern "C"
