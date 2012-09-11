/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_scominit/mss_scominit.C $  */
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
// $Id: mss_scominit.C,v 1.11 2012/08/23 00:11:37 mwuu Exp $
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
#include <dimmBadDqBitmapFuncs.H>
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
// expects i_target = functional MBA target, MBA position (uint8_t)
// sets bad bit mask (disable0) registers in the PHY with data from SPD
//******************************************************************************
fapi::ReturnCode mss_set_bbm_regs (const fapi::Target & mba_target,
									const uint8_t mba_pos)
{
	// DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_0_0x8000007C0301143F
	const uint64_t base_addr = 0x8000007C0301143Full;
	const uint8_t rg_invalid[] = {
		ENUM_ATTR_EFF_PRIMARY_RANK_GROUP0_INVALID,
		ENUM_ATTR_EFF_PRIMARY_RANK_GROUP1_INVALID,
		ENUM_ATTR_EFF_PRIMARY_RANK_GROUP2_INVALID,
		ENUM_ATTR_EFF_PRIMARY_RANK_GROUP3_INVALID,
	};

    ReturnCode rc;
	uint64_t address = base_addr;
    ecmdDataBufferBase data_buffer(64);
	uint8_t prg[MAX_PRI_RANKS][MAX_PORTS];			// primary rank group values

	FAPI_INF("Running set bad bits FN:mss_set_bbm_regs on \nMBA%i,"
			" input Target: %s", mba_pos, mba_target.toEcmdString());

	std::vector<Target> mba_dimms;
	fapiGetAssociatedDimms(mba_target, mba_dimms);	// functional dimms

	FAPI_INF("***-------- Found %i functional DIMMS in MBA%i --------***",
			mba_dimms.size(), mba_pos);

	// 4 dimms per MBA, 2 per port
/*
	RAW SPD		0 1  2 3  4 5  6 7   8 9  A B  C D  E F
	  b0:		0000 0000 0000 0000  0000 0000 0000 0000
	  c0: 		0000 0000 0000 0000  0000 0000 0000	0000
	  d0: 		0000 0000 0000 0000  0000 0000 0000 0000
	  e0: 		0000 0000 0000 0000  0000 0000 0000 00FE
	  f0: 		0000 0000 0000 0000  0000 0000 0000 00FF
*/
//	uint8_t bad_dq_data[80] = {
//	/*  spd	 |------------  HEADER  -----------------------------------------
//	 * byte#	|--- magic number ----|-ver-|---- reserved ----|
//	 *  0-7 */	0xBA, 0xDD, 0x44, 0x71, 0x01, 0x00, 0x00, 0x00,
//	/* 			|------------------- DATA --------------------| ECC |SPARE|
//	 * 			  0		1	  2		3	  4		5	  6		7	  8		9
//	 *  8-17*/	0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//	/* 18-27*/ 	0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//	/* 28-37*/ 	0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//	/* 38-47*/	0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//	/* 48-49*/													0x00, 0x00,
//	/* 50-59*/	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00,
//	/* 60-69*/	0x00, 0x00, 0x00, 0xFE, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00,
//	/* 70-79*/	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0xFF
//	};
/*
	for (uint8_t d = 0; d < 8; d++)
	{
		rc=FAPI_ATTR_SET(ATTR_SPD_BAD_DQ_DATA, &mba_dimms[0], bad_dq_data);
		if (rc)
		{
			FAPI_ERR("Error performing FAPI_ATTR_SET on ATTR_SPD_BAD_DQ_DATA");
		}
	}
*/
	//	ATTR_EFF_PRIMARY_RANK_GROUP0[port], GROUP1[port], GROUP2[port], GROUP3[port]
	rc=FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP0, &mba_target, prg[0]);
	if(rc) return rc;
	rc=FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP1, &mba_target, prg[1]);
	if(rc) return rc;
	rc=FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP2, &mba_target, prg[2]);
	if(rc) return rc;
	rc=FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP3, &mba_target, prg[3]);
	if(rc) return rc;

	for (uint8_t port = 0; port < MAX_PORTS; port++ )	// [0:1]
	{
		uint8_t l_bbm[TOTAL_BYTES] = {0};				// bad bits

		// port 0 = 0x8000..., port 1 = 0x8001...
		address = address | ((uint64_t)port << 48);

		// loop through primary ranks [0:3]
		for (uint8_t prank = 0; prank < MAX_PRI_RANKS; prank++ )
		{
			// 0x800p 0r7C 0301 143F
			uint64_t r_addr = address | ((uint64_t)prank << 40);
			uint8_t dimm = prg[prank][port] >> 2;
			uint8_t rank = prg[prank][port] & 0x03;
			uint8_t bbm_e = 0, bbm_o = 0;

//			uint8_t spd_data[10] = {
//			//		|-------------------- DATA ----------- --------| ECC |SPARE|
//			//byte	  0		1	  2		3	  4		5	  6		7	  8		9
//					0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
//			};
/*
			rc = dimmSetBadDqBitmap(mba_target, port, dimm, rank, spd_data);
			if (rc)
			{
				FAPI_ERR("Error from dimmSetBadDqBitmap on MBA%ip%i: dimm=%i,
					rank=%i rc=%i",	mba_pos, port, dimm, rank,
					static_cast<uint32_t>(rc));
				return rc;
				break;
			}
*/
			if (prg[prank][port] != rg_invalid[prank])		// valid rank group
			{
				rc = dimmGetBadDqBitmap(mba_target, port, dimm, rank, l_bbm);
				if (rc)
				{
					FAPI_ERR("Error from dimmGetBadDqBitmap on MBA%ip%i: "
							"dimm=%i, rank=%i rc=%i", mba_pos, port, dimm, rank,
							static_cast<uint32_t>(rc));

					return rc;
					break;
				}
			}

			for ( uint8_t i=0; i < TOTAL_BYTES/2; i++ ) // [0:4] dp18 instances
			{
				uint64_t scom_addr = r_addr | ((uint64_t) i << 42);
				uint64_t l_data = 0;
				uint32_t l_ecmdRc = ECMD_DBUF_SUCCESS;

				if (prg[prank][port] == rg_invalid[prank])	// invalid rank
				{
					FAPI_INF("Primary rank group %i is invalid, prepare"
							" broadcast write to all instances", prank);

					l_data = 0xFFFF;				// invalidate data bits
					// set address to broadcast to all instances in the rank
					scom_addr = scom_addr | 0x00003C0000000000ull;
				}
				else
				{	// scom signifies port dimm rank byte
					bbm_e = l_bbm[i*2];		// even byte data
					bbm_o = l_bbm[(i*2)+1];	// odd byte data
					l_data = (bbm_e << 8) | bbm_o;
					if (l_data == 0)
					{
						// no need to set register since bits are good?
						continue;		// should double check!
					}
				}

				// ecmdDataBufferBase data_buffer(64);
				l_ecmdRc = data_buffer.setDoubleWord(0, l_data);

				if (l_ecmdRc != ECMD_DBUF_SUCCESS)
				{
					 FAPI_ERR("Error from ecmdDataBuffer setDoubleWord() "
							 "- rc 0x%.8X", l_ecmdRc);

					 rc.setEcmdError(l_ecmdRc);
					 break;
				}

				FAPI_INF("+++ Setting Bad Bit Mask in MBA%ip%i: PRG%i=%i,"
					   " addr=0x%llx, data=0x%04llx", mba_pos, port, prank,
					   prg[prank][port], scom_addr, l_data);

				rc = fapiPutScom(mba_target, scom_addr, data_buffer);
				if (rc)
				{
					FAPI_ERR("Error from fapiPutScom");
					break;
				}
				if (prg[prank][port] == rg_invalid[prank])  // invalid rank
				{
					FAPI_INF("Disabled primary rank group %i data bits"
							" via broadcast continuing to next rank", prank);

					// did broadcast to all instances in rank move to next rank
					break;
				}
			} // end byte loop
		} // end primary rank loop
	} // end port loop
    return rc;
} // end mss_set_bbm_regs

//******************************************************************************
//
//******************************************************************************
ReturnCode mss_scominit(const Target & i_target) {

	ReturnCode rc;
	std::vector<Target> vector_targets;
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

				// set bad bits from SPD into disable bit registers
				rc=mss_set_bbm_regs(vector_targets[i], l_unitPos);
				if (rc)
				{
					FAPI_INF("Error setting disable bit mask registers");
					return (rc);
				}
				else
				{
					FAPI_INF("mss_set_bbm_regs FN passed on MBA%i", l_unitPos);
				}
			} // end else, MBA fapiHwpExecInitFile
		} // end for loop, valid chip unit pos
	} // found functional MBAs

	return (rc);
} // end mss_scominit

} // extern "C"
