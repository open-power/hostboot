/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_scominit/mss_scominit.C $  */
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
// $Id: mss_scominit.C,v 1.17 2013/07/02 21:05:23 mwuu Exp $
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
//	 1.17  | menlowuu |02-JUL-13| Fixed vector insert for L4 targets
//	 1.16  | menlowuu |02-JUL-13| Added L4 targets for MBS initfile
//	 1.15  | menlowuu |11-NOV-12| Removed include of dimmBadDqBitmapFuncs.H>
//   1.14  | menlowuu |09-NOV-12| Removed mss_set_bbm_regs FN since now handled
//  							  in draminit_training.
//   1.13  | menlowuu |26-SEP-12| Changed ORing of port to SCOM address
//   1.12  | menlowuu |19-SEP-12| Fixed some return codes.
//   1.11  | menlowuu |22-AUG-12| Added return code for mss_set_bbm_regs FN.
//   1.10  | menlowuu |21-AUG-12| Removed running *_mcbist files since it was
//      					moved into the *_def files.
//   1.9   | menlowuu |15-AUG-12| Added disable bit set FN, reused rc, added
//   					mbs/mba_mcbist.if to the scominit FN.
//   1.8   | bellows  |16-JUL-12| added in Id tag
//   1.7   | menlowuu |14-JUN-12| Added fixes suggested by Mike,
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
#include <fapi.H>
#include <fapiHwpExecInitFile.H>

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------
#define MAX_PORTS 2
#define MAX_PRI_RANKS 4
#define TOTAL_BYTES 10

extern "C" {
    using namespace fapi;

//******************************************************************************
//
//******************************************************************************
ReturnCode mss_scominit(const Target & i_target) {

	ReturnCode rc;
	std::vector<Target> vector_targets, vector_l4_targets;
	const char* mbs_if[] = {
		"mbs_def.if",
		/* "mbs_mcbist.if"	// moved into mbs_def file */
	};
	const char* mba_if[] = {
		"mba_def.if",
		/* "mba_mcbist.if",	// moved into mba_def file */
		"cen_ddrphy.if"
	};

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
		FAPI_ERR("fapiGetChildChiplets returned present MBAs != 2");
		FAPI_SET_HWP_ERROR(rc, RC_MSS_NUM_MBA_ERROR);
		FAPI_ERR("Present MBAs = %i, generating RC_MSS_NUM_MBA_ERROR = 0x%x",
				vector_targets.size(), static_cast<uint32_t>(rc));
		return (rc);
	}
	else
	{
		// insert centaur target at beginning of vector
		vector_targets.insert(vector_targets.begin(),i_target);

		FAPI_INF("Getting L4 targets");
		// Get L4 vectors
		rc = fapiGetChildChiplets(i_target, TARGET_TYPE_L4,
								vector_l4_targets, TARGET_STATE_PRESENT);

		if (rc)
		{
			FAPI_ERR("Error from fapiGetChildChiplets getting L4 targets!");
			FAPI_ERR("RC = 0x%x", static_cast<uint32_t>(rc));
			return (rc);
		}
		
		if (vector_l4_targets.size() != 1)
		{
			FAPI_ERR("Error target does not have L4!");
			FAPI_ERR("RC = 0x%x", static_cast<uint32_t>(rc));
			return (rc);
		}

		// insert L4 targets at the end	
		vector_targets.insert(vector_targets.end(),vector_l4_targets.begin(), vector_l4_targets.end());

		// run mbs initfile...
		uint8_t num_mbs_files = sizeof(mbs_if)/sizeof(char*);
		for (uint8_t itr=0; itr < num_mbs_files; itr++)
		{
			FAPI_EXEC_HWP(rc, fapiHwpExecInitFile, vector_targets, mbs_if[itr]);

			if (rc)
			{
				FAPI_ERR("  !!!  Error running MBS %s, RC = 0x%x",
						mbs_if[itr], static_cast<uint32_t>(rc));
				return (rc);
			}
			else
			{
				FAPI_INF("MBS scom initfile %s passed", mbs_if[itr]);
			}
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

		FAPI_INF("Found %i functional MBA chiplets", vector_targets.size());

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

				// run mba initfiles...
				uint8_t num_mba_files = sizeof(mba_if)/sizeof(char*);
				for (uint8_t itr=0; itr < num_mba_files; itr++)
				{
					FAPI_EXEC_HWP(rc, fapiHwpExecInitFile, mba_cen_targets,
							mba_if[itr]);

					if (rc)
					{
						FAPI_ERR("  !!!  Error running MBA %s, RC = 0x%x",
								mba_if[itr], static_cast<uint32_t>(rc));
						return (rc);
					}
					else
					{
						FAPI_INF("MBA scom initfile %s passed", mba_if[itr]);
					}
				} // end for loop, running MBA/PHY initfiles
			} // end else, MBA fapiHwpExecInitFile
		} // end for loop, valid chip unit pos
	} // found functional MBAs

	return (rc);
} // end mss_scominit

} // extern "C"
