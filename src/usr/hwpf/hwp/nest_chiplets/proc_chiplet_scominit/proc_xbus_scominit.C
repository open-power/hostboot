/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_chiplet_scominit/proc_xbus_scominit.C $ */
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
// $Id: proc_xbus_scominit.C,v 1.4 2013/02/06 22:21:31 thomsen Exp $
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
//  Version		Date		Owner		Description
//------------------------------------------------------------------------------
//    1.3	   	01/31/13	thomsen		Added separate calls to base & customized scominit files. Removed separate calls to SIM vs. HW scominit files
//    1.2	   	01/09/13	thomsen		Added separate calls to SIM vs. HW scominit files
//                                      Added parent chip and connected targets to vector of passed targets. This is to match scominit file updates.
//    									Added commented-out call to OVERRIDE initfile for system/bus/lane specific inits
//    1.1       8/11/12     jmcgill		Initial release
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <fapiHwpExecInitFile.H>
#include <proc_xbus_scominit.H>

extern "C" {

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

// HWP entry point, comments in header
fapi::ReturnCode proc_xbus_scominit( const fapi::Target & i_xbus_target,
                                     const fapi::Target & i_connected_xbus_target)
{
    fapi::ReturnCode rc;
    std::vector<fapi::Target> targets;
    fapi::Target i_this_pu_target;
    fapi::Target i_connected_pu_target;
    uint8_t xbus_enable_attr;

    // mark HWP entry
    FAPI_INF("proc_xbus_scominit: Start");

    do
    {
  
	    // Get parent chip targets
        rc = fapiGetParentChip(i_xbus_target, i_this_pu_target); if(rc) return rc;
        rc = fapiGetParentChip(i_connected_xbus_target, i_connected_pu_target); if(rc) return rc;

		// populate targets vector
        targets.push_back(i_xbus_target);
        targets.push_back(i_this_pu_target);
        targets.push_back(i_connected_xbus_target);
        targets.push_back(i_connected_pu_target);
       
        // query XBUS partial good attribute
        rc = FAPI_ATTR_GET(ATTR_PROC_X_ENABLE,
                           &i_this_pu_target,
                           xbus_enable_attr);
        if (!rc.ok())
        {
            FAPI_ERR("proc_xbus_scominit: Error querying ATTR_PROC_X_ENABLE");
            break;
        }

        if (xbus_enable_attr != fapi::ENUM_ATTR_PROC_X_ENABLE_ENABLE)
        {
            FAPI_ERR("proc_xbus_scominit: Partial good attribute error");
            FAPI_SET_HWP_ERROR(rc, RC_PROC_XBUS_SCOMINIT_PARTIAL_GOOD_ERR);
            break;
        }

        // processor target, processor MCS chiplet target
        // test target types to confirm correct before calling initfile(s) to execute
        if ((i_this_pu_target.getType()        == fapi::TARGET_TYPE_PROC_CHIP)     &&
            (i_xbus_target.getType()           == fapi::TARGET_TYPE_XBUS_ENDPOINT) &&
            (i_connected_pu_target.getType()   == fapi::TARGET_TYPE_PROC_CHIP)     &&
            (i_connected_xbus_target.getType() == fapi::TARGET_TYPE_XBUS_ENDPOINT))
        {
		    // Call BASE DMI SCOMINIT
            FAPI_INF("proc_xbus_scominit: fapiHwpExecInitfile executing %s on %s, %s, %s, %s",
                     XBUS_BASE_IF, i_this_pu_target.toEcmdString(), i_xbus_target.toEcmdString(),
			    	                 i_connected_pu_target.toEcmdString(), i_connected_xbus_target.toEcmdString());
            FAPI_EXEC_HWP(rc, fapiHwpExecInitFile, targets, XBUS_BASE_IF);
            if (!rc.ok())
            {
                FAPI_ERR("proc_xbus_scominit: Error with fapiHwpExecInitfile executing %s on %s, %s, %s, %s",
                     XBUS_BASE_IF, i_this_pu_target.toEcmdString(), i_xbus_target.toEcmdString(),
			 	                 i_connected_pu_target.toEcmdString(), i_connected_xbus_target.toEcmdString());
                break;
            }
		    // Call CUSTOMIZED DMI SCOMINIT (system specific)
			FAPI_INF("proc_xbus_scominit: fapiHwpExecInitfile executing %s on %s, %s, %s, %s",
                     XBUS_CUSTOM_IF, i_this_pu_target.toEcmdString(), i_xbus_target.toEcmdString(),
			    	                 i_connected_pu_target.toEcmdString(), i_connected_xbus_target.toEcmdString());
            FAPI_EXEC_HWP(rc, fapiHwpExecInitFile, targets, XBUS_CUSTOM_IF);
            if (!rc.ok())
            {
                FAPI_ERR("proc_xbus_scominit: Error with fapiHwpExecInitfile executing %s on %s, %s, %s, %s",
                     XBUS_CUSTOM_IF, i_this_pu_target.toEcmdString(), i_xbus_target.toEcmdString(),
			 	                 i_connected_pu_target.toEcmdString(), i_connected_xbus_target.toEcmdString());
                break;
            }

        }
        // unsupported target type
        else
        {
            FAPI_ERR("proc_xbus_scominit: Unsupported target type(s)");
            FAPI_SET_HWP_ERROR(rc, RC_PROC_XBUS_SCOMINIT_INVALID_TARGET);
            break;
        }
    } while (0);


    // mark HWP exit
    FAPI_INF("proc_xbus_scominit: End");
	return rc;
}


} // extern "C"
