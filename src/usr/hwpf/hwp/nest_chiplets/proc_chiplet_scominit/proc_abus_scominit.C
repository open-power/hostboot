/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_chiplet_scominit/proc_abus_scominit.C $ */
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
// $Id: proc_abus_scominit.C,v 1.4 2013/04/18 22:35:35 jgrell Exp $
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
//  Version		Date		Owner		Description
//------------------------------------------------------------------------------
//    1.4	   	02/18/13	thomsen		Changed targeting to use Abus_chiplet, chip, connected_Abus_chiplet & connected_chip to match Xbus and DMI target list so they are common
//    1.3	   	02/10/13	jmcgill     Leverage chiplet level targeting, invoke custom initfile
//    1.2	   	01/20/13	jmcgill		Add consistency check for A chiplet partial good support
//    1.1       8/11/12     jmcgill		Initial release
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <fapiHwpExecInitFile.H>
#include <proc_abus_scominit.H>

extern "C" {

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

// HWP entry point, comments in header
fapi::ReturnCode proc_abus_scominit( const fapi::Target & i_abus_target,
                                     const fapi::Target & i_connected_abus_target)
{
    fapi::ReturnCode rc;
    std::vector<fapi::Target> targets;
    fapi::Target i_this_pu_target;
    fapi::Target i_connected_pu_target;
    uint8_t abus_enable_attr;

    // mark HWP entry
    FAPI_INF("proc_abus_scominit: Start");

    do
    {

	    // Get parent chip targets
        rc = fapiGetParentChip(i_abus_target, i_this_pu_target); if(rc) return rc;
        rc = fapiGetParentChip(i_connected_abus_target, i_connected_pu_target); if(rc) return rc;

		// populate targets vector
        targets.push_back(i_abus_target);               // Chiplet target
        targets.push_back(i_this_pu_target);            // Proc target
        targets.push_back(i_connected_abus_target);     // Connected Chiplet target
        targets.push_back(i_connected_pu_target);       // Connected Proc target

        // query ABUS partial good attribute
        rc = FAPI_ATTR_GET(ATTR_PROC_A_ENABLE,
                           &i_this_pu_target,
                           abus_enable_attr);
        if (!rc.ok())
        {
            FAPI_ERR("proc_abus_scominit: Error querying ATTR_PROC_A_ENABLE");
            break;
        }

        if (abus_enable_attr != fapi::ENUM_ATTR_PROC_A_ENABLE_ENABLE)
        {
            FAPI_ERR("proc_abus_scominit: Partial good attribute error");
            FAPI_SET_HWP_ERROR(rc, RC_PROC_ABUS_SCOMINIT_PARTIAL_GOOD_ERR);
            break;
        }

        // processor target, processor MCS chiplet target
        // test target types to confirm correct before calling initfile(s) to execute
        if ((i_this_pu_target.getType()        == fapi::TARGET_TYPE_PROC_CHIP)     &&
            (i_abus_target.getType()           == fapi::TARGET_TYPE_ABUS_ENDPOINT) &&
            (i_connected_pu_target.getType()   == fapi::TARGET_TYPE_PROC_CHIP)     &&
            (i_connected_abus_target.getType() == fapi::TARGET_TYPE_ABUS_ENDPOINT))
        {
		    // Call BASE DMI SCOMINIT
            FAPI_INF("proc_abus_scominit: fapiHwpExecInitfile executing %s on %s, %s, %s, %s",
                     ABUS_BASE_IF, i_this_pu_target.toEcmdString(), i_abus_target.toEcmdString(),
			    	                 i_connected_pu_target.toEcmdString(), i_connected_abus_target.toEcmdString());
            FAPI_EXEC_HWP(rc, fapiHwpExecInitFile, targets, ABUS_BASE_IF);
            if (!rc.ok())
            {
                FAPI_ERR("proc_abus_scominit: Error from fapiHwpExecInitfile executing %s on %s, %s, %s, %s",
                     ABUS_BASE_IF, i_this_pu_target.toEcmdString(), i_abus_target.toEcmdString(),
			   	                 i_connected_pu_target.toEcmdString(), i_connected_abus_target.toEcmdString());
                break;
            }

		    // Call CUSTOMIZED DMI SCOMINIT (system specific)
            FAPI_INF("proc_abus_scominit: fapiHwpExecInitfile executing %s on %s, %s, %s, %s",
                     ABUS_CUSTOM_IF, i_this_pu_target.toEcmdString(), i_abus_target.toEcmdString(),
			    	                 i_connected_pu_target.toEcmdString(), i_connected_abus_target.toEcmdString());
            FAPI_EXEC_HWP(rc, fapiHwpExecInitFile, targets, ABUS_CUSTOM_IF);
            if (!rc.ok())
            {
                FAPI_ERR("proc_abus_scominit: Error from fapiHwpExecInitfile executing %s on %s, %s, %s, %s",
                         ABUS_CUSTOM_IF, i_abus_target.toEcmdString(), i_abus_target.toEcmdString(),
			   	                 i_connected_pu_target.toEcmdString(), i_connected_abus_target.toEcmdString());
                break;
            }
		}
        // unsupported target type
        else
        {
            FAPI_ERR("proc_abus_scominit: Unsupported target type(s)");
            FAPI_SET_HWP_ERROR(rc, RC_PROC_ABUS_SCOMINIT_INVALID_TARGET);
            break;
        }
    } while (0);

    // mark HWP exit
    FAPI_INF("proc_abus_scominit: End");
	return rc;
}


} // extern "C"
