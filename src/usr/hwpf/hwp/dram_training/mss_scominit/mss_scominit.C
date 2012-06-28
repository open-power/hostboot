/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/dram_training/mss_scominit/mss_scominit.C $
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
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_scominit
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Menlo Wuu         Email: menlowuu@us.ibm.com
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
//	 1.7   | menlowuu |14-JUN-12| Added fixes suggested by Mike,
//	 					replace rc_num with ReturnCode, created RC for when
//	 					MBAs != 2, and return on all errors 
//   1.6   | menlowuu |08-JUN-12| Fixed inserting centaur vector & return code.
//   1.5   | menlowuu |06-JUN-12| Added code to use
//  		 primary centaur target, secondary mba[0/1] for mbs.if;
//   		 primary mba[0|1] target, secondary centaur for mba.if, phy.if
//   1.4   | menlowuu |05-JUN-12| Added vector target for fapiHwpExecInitFile
//   1.3   | menlowuu |15-MAY-12| Added fapi namespace to rc_num definition
//   0.1   | menlowuu |01-DEC-11| First Draft.


//----------------------------------------------------------------------
//  My Includes
//----------------------------------------------------------------------
#include <mss_scominit.H>

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapiHwpExecInitFile.H>

extern "C" {
    using namespace fapi;

//******************************************************************************
//
//******************************************************************************
ReturnCode mss_scominit(const Target & i_target) {

	ReturnCode rc;
	std::vector<Target> vector_targets;
	const char* mbs_if = "mbs_def.if";
	const char* mba_if = "mba_def.if";
	const char* phy_if = "cen_ddrphy.if";

	FAPI_INF("Performing HWP: mss_scominit");

	// Print the ecmd string of the chip
	FAPI_INF("Input Target: %s", i_target.toEcmdString());

	// Get a vector of the present MBA targets
	rc = fapiGetChildChiplets(i_target, TARGET_TYPE_MBA_CHIPLET,
							vector_targets, TARGET_STATE_PRESENT);

	if (rc)
	{
		FAPI_ERR("Error from fapiGetChildChiplets getting present MBA's!");
		FAPI_ERR("RC = 0x%x", static_cast<uint32_t>(rc));
		return (rc);
	}
	else if (vector_targets.size() != 2)
	{
		ReturnCode l_rc;
		FAPI_ERR("fapiGetChildChiplets returned present MBAs != 2");
		FAPI_SET_HWP_ERROR(l_rc, RC_MSS_NUM_MBA_ERROR);
		FAPI_ERR("Present MBAs = %i, generating RC_MSS_NUM_MBA_ERROR = 0x%x",
				vector_targets.size(), static_cast<uint32_t>(l_rc));
		return (l_rc);
	}
	else
	{
		// insert centaur target at beginning of vector
		vector_targets.insert(vector_targets.begin(),i_target);

		// run mbs initfile...
		FAPI_EXEC_HWP(rc, fapiHwpExecInitFile, vector_targets, mbs_if);

		if (rc)
		{
			FAPI_ERR("  !!!  Error running MBS %s, RC = 0x%x",
					mbs_if,	static_cast<uint32_t>(rc));
			return (rc);
		}
		else
		{
			FAPI_INF("MBS scom initfile %s passed", mbs_if);
		}
	}

	// Clear vector targets
	vector_targets.clear();

	// Get a vector of the functional MBA targets
	rc=fapiGetChildChiplets(i_target, TARGET_TYPE_MBA_CHIPLET, vector_targets);

	if (rc)
	{
		FAPI_ERR("Error from fapiGetChildChiplets getting functional MBA's!");
		return (rc);
	}
	else
	{
		uint8_t l_unitPos = 0;

		FAPI_INF("Found %i MBA chiplets", vector_targets.size());

		// Iterate through the returned chiplets
		for (uint32_t i = 0; i < vector_targets.size(); i++)
		{
			// Find the position of the MBA chiplet
			rc=FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &vector_targets[i], l_unitPos);

			if (rc)
			{
				FAPI_ERR("Error getting ATTR_CHIP_UNIT_POS for MBA");
				return (rc);
			}
			else
			{
				std::vector<Target> mba_cen_targets;

				FAPI_INF("MBA%i valid", l_unitPos);

				// push current mba target then centaur target
				mba_cen_targets.push_back(vector_targets[i]);
				mba_cen_targets.push_back(i_target);

				// run mba and phy initfiles...
				// Call Hwp to execute the mba_if file
				FAPI_EXEC_HWP(rc, fapiHwpExecInitFile, mba_cen_targets, mba_if);

				if (rc)
				{
					FAPI_ERR("  !!!  Error running MBA%i %s, RC = 0x%x",
							l_unitPos, mba_if, static_cast<uint32_t>(rc));
					return (rc);
				}
				else
				{
					FAPI_INF("MBA%i initfile %s passed", l_unitPos, mba_if);
				}

				// Call Hwp to execute the phy_if file
				FAPI_EXEC_HWP(rc, fapiHwpExecInitFile, mba_cen_targets, phy_if);

				if (rc)
				{
					FAPI_ERR("  !!!  Error running MBA%i %s, RC = 0x%x",
							l_unitPos, phy_if, static_cast<uint32_t>(rc));
					return (rc);
				}
				else
				{
					FAPI_INF("MBA%i PHY initfile %s passed", l_unitPos, phy_if);
				}
			} // end MBA/PHY fapiHwpExecInitFile
		} // valid chip unit pos
	} // found functional MBAs

	return (rc);
}

} // extern "C"
