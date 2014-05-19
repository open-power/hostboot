/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit/mss_draminit.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: mss_draminit.C,v 1.66 2014/05/09 16:40:04 jdsloat Exp $
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.66   | jdsloat  |09-MAY-14| Added an explicit 500us delay before execution of MRS cmds.
//  1.65   | jdsloat  |09-APL-14| Fixed ifdef around #include mss_lrdimm_ddr4_funcs.H
//  1.64   | jdsloat  |01-APL-14| RAS review edits/changes
//  1.63   | jdsloat  |01-APL-14| RAS review edits/changes
//  1.62   | jdsloat  |28-MAR-14| RAS review edits/changes
//  1.61   | kcook    | 03/18/13| Added include mss_lrdimm_ddr4_funcs.H
//  1.60   | kcook    | 03/14/13| Added calls to DDR4 ISDIMM functions.
//  1.59   | jdsloat  | 11/11/13| Changed EFF attributes to VPD named attributes
//  1.58   | jdsloat  | 10/15/13| Added rc checks in ddr4 shadow regs check per review request
//  1.57   | jdsloat  | 10/09/13| Added mrs_load_ddr4 with defines for ddr4 usage, added shadow regs, removed complicated flow
//  1.56   | bellows  | 09/16/13| Hostboot compile fix
//  1.55   | kcook    | 09/13/13| Updated define FAPI_LRDIMM token.
//  1.54   | kcook    | 08/27/13| Removed LRDIMM support to mss_lrdimm_funcs.C. 
//         |          |         | Added check for valid rank when flagging address mirroring.
//  1.53   | kcook    | 08/16/13| Added LRDIMM support. Use with mss_funcs.C v1.32.
//  1.52   | jdsloat  | 08/07/13| Added a single rc_num check and edited a debug/error message to make firmware happy.
//  1.51   | jdsloat  | 08/01/13| Fixed dimm/rank conversion in address mirroring phy setting for a 4 rank dimm scenario
//  1.50   | mwuu     | 07/17/13| Fixed CS when accessing RCD words on 1 rank RDIMMs
//         |          |         | Added checks for invalid RTT_NOM, RTT_WR
//  1.49   | jdsloat  | 06/11/13| Added several rc checks
//  1.48   | jdsloat  | 05/20/13| Updated Mirror mode for DDR4 and keyed off new mba mirror_mode attribute
//  1.47   | jdsloat  | 04/09/13| Added position info to debug messages
//         |          |         | Added setup cycle for 2N mode
//         |          |         | Added CKE high for RCD
//         |          |         | Moved address mirror mode into its own function in mss_funcs
//  1.46   | jdsloat  | 02/12/13| Fixed RTT_WR in MR2
//  1.45   | jdsloat  | 01/28/13| is_sim check for address mirror mode
//  1.44   | jdsloat  | 01/25/13| Address Mirror Mode added for dual drop CDIMMs
//  1.43   | bellows  | 12/06/12| Fixed Review Comment
//  1.42   | jdsloat  | 12/02/12| SHADOW REG PRINT OUT FIX
//  1.41   | jdsloat  | 11/19/12| RCD Bit order fix.
//  1.40   | jdsloat  | 11/17/12| MPR operation bit (MRS3, ADDR2) fix
//  1.39   | gollub   | 9/05/12 | Calling mss_unmask_draminit_errors after mss_draminit_cloned
//  1.38   | jdsloat  | 8/29/12 | Fixed Shadow Regs with Regression
//  1.37   | jdsloat  | 8/28/12 | Revert back to 1.35.
//  1.36   | jdsloat  | 7/25/12 | Printing out contents of MRS shadow registers.
//  1.35   | bellows  | 7/25/12 | CQ 216395 (move force mclk low deassert to phyreset, resetn toggle)
//  1.34   | bellows  | 7/16/12 | added in Id tag
//  1.33   | jdsloat  | 6/26/12 | Added rtt_nom rank by rank value.
//  1.32   | jdsloat  | 6/11/12 | Fixed Attributes: RTT_NOM, CL, DRAM_WR within the MRS load.
//  1.31   | bellows  | 5/24/12 | Removed GP Bit
//  1.30   | bellows  | 5/03/12 | MODEQ reg writes (HW191966). Has GP Bit for backwards compatibility
//  1.29   | bellows  | 5/03/12 | Workaround removed for (HW199042). Use new hardware or workaround.initfile after phyreset
//  1.28   | bellows  | 4/11/12 | fixed missing fapi:: for targets and return codes
//  1.27   | bellows  | 4/11/12 | Workaround for fixing up phy config reset (HW199042)
//  1.26   | jdsloat  | 3/20/12 | MRS bank fixe to remove reverse in ccs_inst_arry0
//  1.25   | jdsloat  | 3/09/12 | RCD address fix.  Cleaned up the RCD section.
//  1.24   | jdsloat  | 3/08/12 | Added CDIMM to RCD Check, MRS cycles through only configured ranks
//  1.23   | jdsloat  | 3/05/12 | Fixed dram_al enum typo
//  1.22   | jdsloat  | 2/27/12 | Fixed hostboot parenthesis error
//  1.21   | jdsloat  | 2/27/12 | Cycle through Ports local of MRS/RCD, CL shift fix, Initialization of address/CS, neg end bit bug fix
//  1.20   | jdsloat  | 2/23/12 | Fixed CL typo in MRS load
//  1.19   | jdsloat  | 2/23/12 | MRS per rank, Interpret MRS ENUM correctly, CSN initialized to 0xFF
//  1.18   | jdsloat  | 2/16/12 | Initialize rc_num, add num_ranks ==1 to MRS, Fix BA position in MRS
//  1.17   | jdsloat  | 2/14/12 | MBA target translation, if statement clarification, style fixes
//  1.16   | jdsloat  | 2/08/12 | Target to Target&, Described target with comment
//  1.15   | jdsloat  | 2/02/12 | Fixed attributes array sizes, added debug messagesTarget to Target&, Described target
//  1.14   | jdsloat  | 1/19/12 | Tabs to 4 spaces - properly
//  1.13   | jdsloat  | 1/16/12 | Tabs to 4 spaces
//  1.12   | jdsloat  | 1/13/12 | Curly Brackets, capitalization, "mss_" prefix, argument prefixes, no include C's, RC checks
//  1.11   | jdsloat  | 1/5/12  | Changed Attribute grab, cleaned up includes section, Got rid of Globals
//  1.10   | jdsloat  | 12/08/11| Changed MRS load  RAS, CAS, WEN
//  1.9    | jdsloat  | 12/07/11| CSN for 2 rank dimms 0x3 to 0xC
//  1.8    | jdsloat  | 11/08/11| Cycling through Ports - fix
//  1.7    | jdsloat  | 10/31/11| CCS Update - goto_inst now assumed to be +1, CCS_fail fix, CCS_status fix
//  1.6    | jdsloat  | 10/18/11| RCD execution fix, debug messages
//  1.5    | jdsloat  | 10/13/11| MRS fix, CCS count fix, get attribute fix, ecmdbuffer lengths within name
//  1.4    | jdsloat  | 10/11/11| Fix CS Lines, dataBuffer.insert functions, ASSERT_RESETN_DRIVE_MEM_CLKS fix, attribute names
//  1.3    | jdsloat  | 10/05/11| Convert integers to ecmdDataBufferBase in CCS_INST_1, CCS_INST_2, CCS_MODE
//  1.2    | jdsloat  |04-OCT-11| Changing cen_funcs.C, cen_funcs.H to mss_funcs.C, mss_funcs.H
//  1.1    | jdsloat  |04-OCT-11| First drop
//---------|----------|---------|-----------------------------------------------
//  1.6    | jdsloat  |29-Sep-11|Functional Changes: port flow, CCS changes, only configed CS, etc.  Compiles.
//  1.5    | jdsloat  |22-Sep-11|Converted to FAPI, functional changes to match documentation
//  1.3    | jdsloat  |14-Jul-11|Change GP4 register address from 1013 to 0x1013
//  1.2    | jdsloat  |22-Apr-11|Moved CCS operations to Cen_funcs.C, draminit_training to cen_draminit_training.C
//  1.1    | jdsloat  |31-Mar-11|First drop for centaur

//----------------------------------------------------------------------
//  FAPI function Includes
//----------------------------------------------------------------------

#include <fapi.H>

//----------------------------------------------------------------------
//  Centaur function Includes
//----------------------------------------------------------------------
#include <mss_funcs.H>
#include "cen_scom_addresses.H"
#include <mss_unmask_errors.H>
#include <mss_lrdimm_funcs.H>
#include <mss_ddr4_funcs.H>

#ifdef FAPI_LRDIMM
#include <mss_lrdimm_ddr4_funcs.H>
#endif

#ifndef FAPI_LRDIMM
using namespace fapi;
fapi::ReturnCode mss_lrdimm_rcd_load(Target& i_target, uint32_t port_number, uint32_t& ccs_inst_cnt)
{
   ReturnCode rc;

   FAPI_ERR("Invalid exec of mss_lrdimm_rcd_load on %s!", i_target.toEcmdString());
   FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR);
   return rc;

}
ReturnCode mss_lrdimm_mrs_load(Target& i_target, uint32_t i_port_number, uint32_t dimm_number, uint32_t& io_ccs_inst_cnt)
{
   ReturnCode rc;

   FAPI_ERR("Invalid exec of mss_lrdimm_mrs_load function on %s!", i_target.toEcmdString());
   FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR);
   return rc;

}
#endif

#ifndef FAPI_DDR4
using namespace fapi;
fapi::ReturnCode mss_mrs_load_ddr4(Target& i_target, uint32_t port_number, uint32_t& ccs_inst_cnt)
{
   ReturnCode rc;

   FAPI_ERR("Invalid exec of mrs_load_ddr4  %s!", i_target.toEcmdString());
   FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR);
   return rc;

}
fapi::ReturnCode mss_rcd_load_ddr4(Target& i_target, uint32_t i_port_number, uint32_t& io_ccs_inst_cnt)
{
   ReturnCode rc;

   FAPI_ERR("Invalid exec of rcd_load_ddr4  %s!", i_target.toEcmdString());
   FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR);
   return rc;

}
fapi::ReturnCode mss_lrdimm_ddr4_db_load(Target& i_target, uint32_t i_port_number, uint32_t& io_ccs_inst_cnt)
{
   ReturnCode rc;

   FAPI_ERR("Invalid exec of lrdimm_ddr4_db_load  %s!", i_target.toEcmdString());
   FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR);
   return rc;

}
fapi::ReturnCode mss_ddr4_invert_mpr_write(Target& i_target)
{
   ReturnCode rc;

   FAPI_ERR("Invalid exec of ddr4_invert_mpr_write  %s!", i_target.toEcmdString());
   FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR);
   return rc;

}

#endif

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------
const uint8_t MAX_NUM_DIMMS = 2;
const uint8_t MAX_NUM_PORTS = 2;
const uint8_t MAX_NUM_RANK_PAIR = 4;
const uint8_t MAX_NUM_LR_RANKS = 8;
const uint8_t MRS0_BA = 0;
const uint8_t MRS1_BA = 1;
const uint8_t MRS2_BA = 2;  
const uint8_t MRS3_BA = 3;
const uint8_t MRS4_BA = 4;
const uint8_t MRS5_BA = 5;
const uint8_t MRS6_BA = 6;
const uint8_t INVALID = 255;


extern "C" {

using namespace fapi;

ReturnCode mss_rcd_load( Target& i_target, uint32_t i_port_number, uint32_t& io_ccs_inst_cnt);
ReturnCode mss_mrs_load( Target& i_target, uint32_t i_port_number, uint32_t& io_ccs_inst_cnt);
ReturnCode mss_assert_resetn_drive_mem_clks( Target& i_target);
ReturnCode mss_deassert_force_mclk_low( Target& i_target);
ReturnCode mss_assert_resetn ( Target& i_target, uint8_t value);
ReturnCode mss_draminit_cloned(Target& i_target);

const uint64_t  DELAY_100NS             = 100;      // general purpose 100 ns delay for HW mode   (2000 sim cycles if simclk = 20ghz)
const uint64_t  DELAY_1US               = 1000;     // general purpose 1 usec delay for HW mode   (20000 sim cycles if simclk = 20ghz)
const uint64_t  DELAY_100US             = 100000;   // general purpose 100 usec delay for HW mode (2000000 sim cycles if simclk = 20ghz)
const uint64_t  DELAY_500US             = 500000;   // general purpose 500 usec delay for HW mode (10000000 sim cycles if simclk = 20ghz)
const uint64_t  DELAY_2000SIMCYCLES     = 2000;     // general purpose 2000 sim cycle delay for sim mode     (100 ns if simclk = 20Ghz)
const uint64_t  DELAY_20000SIMCYCLES    = 20000;    // general purpose 20000 sim cycle delay for sim mode    (1 usec if simclk = 20Ghz)
const uint64_t  DELAY_2000000SIMCYCLES  = 2000000;  // general purpose 2000000 sim cycle delay for sim mode  (100 usec if simclk = 20Ghz)
const uint64_t  DELAY_10000000SIMCYCLES  = 10000000;  // general purpose 10000000 sim cycle delay for sim mode  (500 usec if simclk = 20Ghz)

ReturnCode mss_draminit(Target& i_target)
{
    // Target is centaur.mba

    ReturnCode rc;

    rc = mss_draminit_cloned(i_target);

	// If mss_unmask_draminit_errors gets it's own bad rc,
	// it will commit the passed in rc (if non-zero), and return it's own bad rc.
	// Else if mss_unmask_draminit_errors runs clean,
	// it will just return the passed in rc.
	rc = mss_unmask_draminit_errors(i_target, rc);

	return rc;
}

ReturnCode mss_draminit_cloned(Target& i_target)
{
    // Target is centaur.mba
    //

    ReturnCode rc;
    ReturnCode rc_buff;
    uint32_t rc_num = 0;
    uint32_t port_number;
    uint32_t ccs_inst_cnt = 0;
    uint8_t dram_gen;
    uint8_t dimm_type;
    uint8_t rank_pair_group = 0;
    uint8_t bit_position = 0;
    ecmdDataBufferBase data_buffer_64(64);
    ecmdDataBufferBase mrs0(16); 
    ecmdDataBufferBase mrs1(16);
    ecmdDataBufferBase mrs2(16);
    ecmdDataBufferBase mrs3(16);
    ecmdDataBufferBase mrs4(16);
    ecmdDataBufferBase mrs5(16);
    ecmdDataBufferBase mrs6(16);
    uint16_t MRS0 = 0;
    uint16_t MRS1 = 0;
    uint16_t MRS2 = 0;
    uint16_t MRS3 = 0;
    uint16_t MRS4 = 0;
    uint16_t MRS5 = 0;
    uint16_t MRS6 = 0;
    uint8_t num_drops_per_port;
    uint8_t primary_ranks_array[4][2]; //primary_ranks_array[group][port]
    uint8_t secondary_ranks_array[4][2]; //secondary_ranks_array[group][port]
    uint8_t tertiary_ranks_array[4][2]; //tertiary_ranks_array[group][port]
    uint8_t quaternary_ranks_array[4][2]; //quaternary_ranks_array[group][port]
    uint8_t is_sim = 0;
    uint8_t pri_dimm = 0;
    uint8_t pri_dimm_rank = 0;
    uint8_t sec_dimm = 0;
    uint8_t sec_dimm_rank = 0;
    uint8_t ter_dimm = 0;
    uint8_t ter_dimm_rank = 0;
    uint8_t qua_dimm = 0;
    uint8_t qua_dimm_rank = 0;


    //populate primary_ranks_arrays_array
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP0, &i_target, primary_ranks_array[0]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP1, &i_target, primary_ranks_array[1]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP2, &i_target, primary_ranks_array[2]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP3, &i_target, primary_ranks_array[3]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_SECONDARY_RANK_GROUP0, &i_target, secondary_ranks_array[0]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_SECONDARY_RANK_GROUP1, &i_target, secondary_ranks_array[1]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_SECONDARY_RANK_GROUP2, &i_target, secondary_ranks_array[2]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_SECONDARY_RANK_GROUP3, &i_target, secondary_ranks_array[3]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_TERTIARY_RANK_GROUP0, &i_target, tertiary_ranks_array[0]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_TERTIARY_RANK_GROUP1, &i_target, tertiary_ranks_array[1]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_TERTIARY_RANK_GROUP2, &i_target, tertiary_ranks_array[2]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_TERTIARY_RANK_GROUP3, &i_target, tertiary_ranks_array[3]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_QUATERNARY_RANK_GROUP0, &i_target, quaternary_ranks_array[0]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_QUATERNARY_RANK_GROUP1, &i_target, quaternary_ranks_array[1]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_QUATERNARY_RANK_GROUP2, &i_target, quaternary_ranks_array[2]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_QUATERNARY_RANK_GROUP3, &i_target, quaternary_ranks_array[3]);
    if(rc) return rc;



    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_DROPS_PER_PORT, &i_target, num_drops_per_port);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_GEN, &i_target, dram_gen);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target, dimm_type);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_IS_SIMULATION, NULL, is_sim);
    if(rc) return rc;
    uint8_t address_mirror_map[2][2]; //address_mirror_map[port][dimm]
    rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_ADDRESS_MIRRORING, &i_target, address_mirror_map);
    if(rc) return rc;


    // Check to see if any dimm needs address mirror mode.  Set the approriate flag.
    if ( ( address_mirror_map[0][0] ||
	  address_mirror_map[0][1] ||
	  address_mirror_map[1][0] ||
	  address_mirror_map[1][1] )
	&& (is_sim == 0)   )
    {

	FAPI_INF( "Setting Address Mirroring in the PHY on %s ", i_target.toEcmdString());

	//Set the Address and BA bits affected by mirroring
	if (dram_gen == ENUM_ATTR_EFF_DRAM_GEN_DDR3)
	{
		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_RANK_GROUP_P0_0x8000C0110301143F, data_buffer_64);
		if(rc) return rc;
		rc_num = rc_num | data_buffer_64.setBit(58);
		rc_num = rc_num | data_buffer_64.setBit(59);
		rc_num = rc_num | data_buffer_64.setBit(60);
		rc_num = rc_num | data_buffer_64.setBit(62);
		rc = fapiPutScom(i_target, DPHY01_DDRPHY_PC_RANK_GROUP_P0_0x8000C0110301143F, data_buffer_64);
		if(rc) return rc;

		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_RANK_GROUP_P1_0x8001C0110301143F, data_buffer_64);
		if(rc) return rc;
		rc_num = rc_num | data_buffer_64.setBit(58);
		rc_num = rc_num | data_buffer_64.setBit(59);
		rc_num = rc_num | data_buffer_64.setBit(60);
		rc_num = rc_num | data_buffer_64.setBit(62);
		rc = fapiPutScom(i_target, DPHY01_DDRPHY_PC_RANK_GROUP_P1_0x8001C0110301143F, data_buffer_64);
		if(rc) return rc;
	}
	if (dram_gen == ENUM_ATTR_EFF_DRAM_GEN_DDR4)
	{
		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_RANK_GROUP_P0_0x8000C0110301143F, data_buffer_64);
		if(rc) return rc;
		rc_num = rc_num | data_buffer_64.setBit(58);
		rc_num = rc_num | data_buffer_64.setBit(59);
		rc_num = rc_num | data_buffer_64.setBit(60);
		rc_num = rc_num | data_buffer_64.setBit(61);
		rc_num = rc_num | data_buffer_64.setBit(62);
		rc_num = rc_num | data_buffer_64.setBit(63);
                rc = fapiPutScom(i_target, DPHY01_DDRPHY_PC_RANK_GROUP_P0_0x8000C0110301143F, data_buffer_64);
		if(rc) return rc;

		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_RANK_GROUP_P1_0x8001C0110301143F, data_buffer_64);
		if(rc) return rc;
		rc_num = rc_num | data_buffer_64.setBit(58);
		rc_num = rc_num | data_buffer_64.setBit(59);
		rc_num = rc_num | data_buffer_64.setBit(60);
		rc_num = rc_num | data_buffer_64.setBit(61);
		rc_num = rc_num | data_buffer_64.setBit(62);
		rc_num = rc_num | data_buffer_64.setBit(63);
		rc = fapiPutScom(i_target, DPHY01_DDRPHY_PC_RANK_GROUP_P1_0x8001C0110301143F, data_buffer_64);
		if(rc) return rc;
	}

	for ( port_number = 0; port_number < MAX_NUM_PORTS; port_number++)
	{
	    for ( rank_pair_group = 0; rank_pair_group < MAX_NUM_RANK_PAIR; rank_pair_group++)
	    {

	        // dimm 0, dimm_rank 0-3 = ranks 0-3; dimm 1, dimm_rank 0-3 = ranks 4-7
	        pri_dimm = (primary_ranks_array[rank_pair_group][port_number]) / 4;
	        pri_dimm_rank = primary_ranks_array[rank_pair_group][port_number] - 4*pri_dimm;
	        sec_dimm = (secondary_ranks_array[rank_pair_group][port_number]) / 4;
	        sec_dimm_rank = secondary_ranks_array[rank_pair_group][port_number] - 4*sec_dimm;
	        ter_dimm = (tertiary_ranks_array[rank_pair_group][port_number]) / 4;
	        ter_dimm_rank = tertiary_ranks_array[rank_pair_group][port_number] - 4*ter_dimm;
	        qua_dimm = (quaternary_ranks_array[rank_pair_group][port_number]) / 4;
	        qua_dimm_rank = quaternary_ranks_array[rank_pair_group][port_number] - 4*qua_dimm;
		// Set the rank pairs that will be affected.
		if ( port_number == 0 )
		{
                    if ( ( ( address_mirror_map[port_number][pri_dimm] & (0x08 >> pri_dimm_rank) ) ) && (primary_ranks_array[rank_pair_group][port_number] != 0xff ) )
		    {
			FAPI_INF( "Address Mirroring on %s PORT%d RANKPAIR%d RANK%d", i_target.toEcmdString(), port_number, rank_pair_group, primary_ranks_array[rank_pair_group][port_number]);
			bit_position = 2 * rank_pair_group + 48;
			FAPI_INF( "Setting bit %d", bit_position);
			rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_RANK_GROUP_P0_0x8000C0110301143F, data_buffer_64);
			if(rc) return rc;
			rc_num = rc_num | data_buffer_64.setBit(bit_position);
			rc = fapiPutScom(i_target, DPHY01_DDRPHY_PC_RANK_GROUP_P0_0x8000C0110301143F, data_buffer_64);
			if(rc) return rc;
		    }
		    if ( ( ( address_mirror_map[port_number][sec_dimm] & (0x08 >> sec_dimm_rank) ) ) && (secondary_ranks_array[rank_pair_group][port_number] != 0xff ) )
                    {
			FAPI_INF( "Address Mirroring on %s PORT%d RANKPAIR%d RANK%d", i_target.toEcmdString(), port_number, rank_pair_group, primary_ranks_array[rank_pair_group][port_number]);
			bit_position = 2 * rank_pair_group + 49;
			FAPI_INF( "Setting bit %d", bit_position);
			rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_RANK_GROUP_P0_0x8000C0110301143F, data_buffer_64);
			if(rc) return rc;
			rc_num = rc_num | data_buffer_64.setBit(bit_position);
			rc = fapiPutScom(i_target, DPHY01_DDRPHY_PC_RANK_GROUP_P0_0x8000C0110301143F, data_buffer_64);
			if(rc) return rc;
		    }
		    if ( ( ( address_mirror_map[port_number][ter_dimm] & (0x08 >> ter_dimm_rank) ) ) && (tertiary_ranks_array[rank_pair_group][port_number] != 0xff ) )
		    {
			FAPI_INF( "Address Mirroring on %s PORT%d RANKPAIR%d RANK%d", i_target.toEcmdString(), port_number, rank_pair_group, primary_ranks_array[rank_pair_group][port_number]);
			bit_position = 2 * rank_pair_group + 48;
			FAPI_INF( "Setting bit %d", bit_position);
			rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_RANK_GROUP_EXT_P0_0x8000C0350301143F, data_buffer_64);
			if(rc) return rc;
			rc_num = rc_num | data_buffer_64.setBit(bit_position);
			rc = fapiPutScom(i_target, DPHY01_DDRPHY_PC_RANK_GROUP_EXT_P0_0x8000C0350301143F, data_buffer_64);
			if(rc) return rc;
		    }
		    if ( ( ( address_mirror_map[port_number][qua_dimm] & (0x08 >> qua_dimm_rank) ) ) && (quaternary_ranks_array[rank_pair_group][port_number] != 0xff ) )
                    {
			FAPI_INF( "Address Mirroring on %s PORT%d RANKPAIR%d RANK%d", i_target.toEcmdString(), port_number, rank_pair_group, primary_ranks_array[rank_pair_group][port_number]);
			bit_position = 2 * rank_pair_group + 49;
			FAPI_INF( "Setting bit %d", bit_position);
			rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_RANK_GROUP_EXT_P0_0x8000C0350301143F, data_buffer_64);
			if(rc) return rc;
			rc_num = rc_num | data_buffer_64.setBit(bit_position);
			rc = fapiPutScom(i_target, DPHY01_DDRPHY_PC_RANK_GROUP_EXT_P0_0x8000C0350301143F, data_buffer_64);
			if(rc) return rc;
		    }
		}
		if ( port_number == 1 )
		{
		    if ( ( ( address_mirror_map[port_number][pri_dimm] & (0x08 >> pri_dimm_rank) ) ) && (primary_ranks_array[rank_pair_group][port_number] != 0xff ) )
		    {
			FAPI_INF( "Address Mirroring on %s PORT%d RANKPAIR%d RANK%d", i_target.toEcmdString(), port_number, rank_pair_group, primary_ranks_array[rank_pair_group][port_number]);
			bit_position = 2 * rank_pair_group + 48;
			FAPI_INF( "Setting bit %d", bit_position);
			rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_RANK_GROUP_P1_0x8001C0110301143F, data_buffer_64);
			if(rc) return rc;
			rc_num = rc_num | data_buffer_64.setBit(bit_position);
			rc = fapiPutScom(i_target, DPHY01_DDRPHY_PC_RANK_GROUP_P1_0x8001C0110301143F, data_buffer_64);
			if(rc) return rc;
		    }
		    if ( ( ( address_mirror_map[port_number][sec_dimm] & (0x08 >> sec_dimm_rank) ) ) && (secondary_ranks_array[rank_pair_group][port_number] != 0xff ) )
                    {
			FAPI_INF( "Address Mirroring on %s PORT%d RANKPAIR%d RANK%d", i_target.toEcmdString(), port_number, rank_pair_group, primary_ranks_array[rank_pair_group][port_number]);
			bit_position = 2 * rank_pair_group + 49;
			FAPI_INF( "Setting bit %d", bit_position);
			rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_RANK_GROUP_P1_0x8001C0110301143F, data_buffer_64);
			if(rc) return rc;
			rc_num = rc_num | data_buffer_64.setBit(bit_position);
			rc = fapiPutScom(i_target, DPHY01_DDRPHY_PC_RANK_GROUP_P1_0x8001C0110301143F, data_buffer_64);
			if(rc) return rc;
		    }
		    if ( ( ( address_mirror_map[port_number][ter_dimm] & (0x08 >> ter_dimm_rank) ) ) && (tertiary_ranks_array[rank_pair_group][port_number] != 0xff ) )
		    {
			FAPI_INF( "Address Mirroring on %s PORT%d RANKPAIR%d RANK%d", i_target.toEcmdString(), port_number, rank_pair_group, primary_ranks_array[rank_pair_group][port_number]);
			bit_position = 2 * rank_pair_group + 48;
			FAPI_INF( "Setting bit %d", bit_position);
			rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_RANK_GROUP_EXT_P1_0x8001C0350301143F, data_buffer_64);
			if(rc) return rc;
			rc_num = rc_num | data_buffer_64.setBit(bit_position);
			rc = fapiPutScom(i_target, DPHY01_DDRPHY_PC_RANK_GROUP_EXT_P1_0x8001C0350301143F, data_buffer_64);
			if(rc) return rc;
		    }
		    if ( ( ( address_mirror_map[port_number][qua_dimm] & (0x08 >> qua_dimm_rank) ) ) && (quaternary_ranks_array[rank_pair_group][port_number] != 0xff ) )
                    {
			FAPI_INF( "Address Mirroring on PORT%d RANKPAIR%d RANK%d", port_number, rank_pair_group, primary_ranks_array[rank_pair_group][port_number]);
			bit_position = 2 * rank_pair_group + 49;
			FAPI_INF( "Setting bit %d", bit_position);
			rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_RANK_GROUP_EXT_P1_0x8001C0350301143F, data_buffer_64);
			if(rc) return rc;
			rc_num = rc_num | data_buffer_64.setBit(bit_position);
			rc = fapiPutScom(i_target, DPHY01_DDRPHY_PC_RANK_GROUP_EXT_P1_0x8001C0350301143F, data_buffer_64);
			if(rc) return rc;
		    }
		}

	    }
	}
    }

        //Commented because Master Attention Reg Check not written yet.
        //Master Attntion Reg Check... Need to add appropriate call below.
        //MASTER_ATTENTION_REG_CHECK();

        // Step one: Deassert Force_mclk_low signal
        // this action needs to be done in ddr_phy_reset so that the plls can actually lock

        // Step two: Assert Resetn signal, Begin driving mem clks
        rc = mss_assert_resetn_drive_mem_clks(i_target);
        if(rc)
        {
            FAPI_ERR(" assert_resetn_drive_mem_clks Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
            return rc;
        }

        rc = mss_assert_resetn(i_target, 0 ); // assert a reset
        if(rc)
        {
            FAPI_ERR(" assert_resetn Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
            return rc;
        }

        rc = fapiDelay(DELAY_100US, DELAY_2000SIMCYCLES); // wait 2000 simcycles (in sim mode) OR 100 uS (in hw mode)
	if(rc) return rc;

        rc = mss_assert_resetn(i_target, 1 ); // de-assert a reset
        if(rc)
        {
            FAPI_ERR(" assert_resetn Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
            return rc;
        }
        // Cycle through Ports...
        // Ports 0-1
        for ( port_number = 0; port_number < MAX_NUM_PORTS; port_number++)
        {
            if (!((dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_UDIMM)||(dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_CDIMM)))
            {
                // Step three: Load RCD Control Words
                if (dram_gen == ENUM_ATTR_EFF_DRAM_GEN_DDR4) 
                {
                   rc = mss_rcd_load_ddr4(i_target, port_number, ccs_inst_cnt);
                   if(rc)
                   {
                       FAPI_ERR(" rcd_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
                       return rc;
                   }
                   if ( dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM )
                   {
                      // Set Data Buffer Function  words
                      rc = mss_lrdimm_ddr4_db_load(i_target, port_number, ccs_inst_cnt);
                      if(rc)
                      {
                          FAPI_ERR(" LRDIMM rcd_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
                          return rc;
                      }
                   }

                }
                else 
                {
                   rc = mss_rcd_load(i_target, port_number, ccs_inst_cnt);
                   if(rc)
                   {
                       FAPI_ERR(" rcd_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
                       return rc;
                   }

                   if ( dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM )
                   {
                      // Set Function 1-13 rcd words
                      rc = mss_lrdimm_rcd_load(i_target, port_number, ccs_inst_cnt);
                      if(rc)
                      {
                          FAPI_ERR(" LRDIMM rcd_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
                          return rc;
                      }
                   }
                } 
            }
        }

       	rc = fapiDelay(DELAY_500US, DELAY_10000000SIMCYCLES); // wait 10000 simcycles (in sim mode) OR 500 uS (in hw mode)

        // Cycle through Ports...
        // Ports 0-1
        for ( port_number = 0; port_number < MAX_NUM_PORTS; port_number++)
        {

            // Step four: Load MRS Setting
	    if (dram_gen == ENUM_ATTR_EFF_DRAM_GEN_DDR3)
	    {
		    rc = mss_mrs_load(i_target, port_number, ccs_inst_cnt);
		    if(rc)
		    {
		        FAPI_ERR(" mrs_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
		        return rc;
		    }
	    }
	    else
	    {
		    rc = mss_mrs_load_ddr4(i_target, port_number, ccs_inst_cnt);
		    if(rc)
		    {
		        FAPI_ERR(" mrs_load_ddr4 Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
		        return rc;
		    }
	    }

        }

        // Execute the contents of CCS array
        if (ccs_inst_cnt  > 0)
        {
	    // Set the End bit on the last CCS Instruction
            rc = mss_ccs_set_end_bit( i_target, ccs_inst_cnt-1);
            if(rc)
            {
                FAPI_ERR("CCS_SET_END_BIT FAILED rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
                return rc;
            }

            rc = mss_execute_ccs_inst_array(i_target, 10, 10);
            if(rc)
            {
                FAPI_ERR(" EXECUTE_CCS_INST_ARRAY FAILED rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
                return rc;
            }

            ccs_inst_cnt = 0;
        }
        else
        {
            FAPI_INF("No Memory configured.");
        }

        // Cycle through Ports...
        // Ports 0-1
        for ( port_number = 0; port_number < MAX_NUM_PORTS; port_number++)
        {

	for ( rank_pair_group = 0; rank_pair_group < MAX_NUM_RANK_PAIR; rank_pair_group++)
	{
	//Check if rank group exists
	    if((primary_ranks_array[rank_pair_group][0] != INVALID) || (primary_ranks_array[rank_pair_group][1] != INVALID))
	    {

		if (port_number == 0)
		{
	    		// Get contents of MRS Shadow Regs and Print it to output
			if (rank_pair_group == 0)
			{
		    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR0_PRI_RP0_P0_0x8000C01C0301143F, data_buffer_64);
                                if(rc) return rc;
		    		rc_num = rc_num | data_buffer_64.reverse();
		    		rc_num = rc_num | mrs0.insert(data_buffer_64, 0, 16);
		    		rc_num = rc_num | mrs0.extractPreserve(&MRS0, 0, 16, 0);
		    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 0 RP %d VALUE: 0x%04X", i_target.toEcmdString(), port_number, rank_pair_group, MRS0 );

		    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_PRI_RP0_P0_0x8000C01D0301143F, data_buffer_64);
                                if(rc) return rc;
		    		rc_num = rc_num | data_buffer_64.reverse();
		    		rc_num = rc_num | mrs1.insert(data_buffer_64, 0, 16);
		    		rc_num = rc_num | mrs1.extractPreserve(&MRS1, 0, 16, 0);
		    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 1 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS1);

		    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_PRI_RP0_P0_0x8000C01E0301143F, data_buffer_64);
                                if(rc) return rc;
		    		rc_num = rc_num | data_buffer_64.reverse();
		    		rc_num = rc_num | mrs2.insert(data_buffer_64, 0, 16);
		    		rc_num = rc_num | mrs2.extractPreserve(&MRS2, 0, 16, 0);
		    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 2 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS2);

		    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR3_PRI_RP0_P0_0x8000C01F0301143F, data_buffer_64);
                                if(rc) return rc;
		    		rc_num = rc_num | data_buffer_64.reverse();
		    		rc_num = rc_num | mrs3.insert(data_buffer_64, 0, 16);
		    		rc_num = rc_num | mrs3.extractPreserve(&MRS3, 0, 16, 0);
		    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 3 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS3);

				if (dram_gen == ENUM_ATTR_EFF_DRAM_GEN_DDR4)
				{
			    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR0_SEC_RP0_P0_0x8000C0200301143F, data_buffer_64);
                                	if(rc) return rc;
			    		rc_num = rc_num | data_buffer_64.reverse();
			    		rc_num = rc_num | mrs4.insert(data_buffer_64, 0, 16);
			    		rc_num = rc_num | mrs4.extractPreserve(&MRS4, 0, 16, 0);
			    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 4 RP %d VALUE: 0x%04X",  i_target.toEcmdString(),  port_number, rank_pair_group, MRS4);

			    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_SEC_RP0_P0_0x8000C0210301143F, data_buffer_64);
                                	if(rc) return rc;
			    		rc_num = rc_num | data_buffer_64.reverse();
			    		rc_num = rc_num | mrs5.insert(data_buffer_64, 0, 16);
			    		rc_num = rc_num | mrs5.extractPreserve(&MRS5, 0, 16, 0);
			    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 5 RP %d VALUE: 0x%04X",  i_target.toEcmdString(),  port_number, rank_pair_group, MRS5);

			    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_SEC_RP0_P0_0x8000C0220301143F, data_buffer_64);
                                	if(rc) return rc;
			    		rc_num = rc_num | data_buffer_64.reverse();
			    		rc_num = rc_num | mrs6.insert(data_buffer_64, 0, 16);
			    		rc_num = rc_num | mrs6.extractPreserve(&MRS6, 0, 16, 0);
			    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 6 RP %d VALUE: 0x%04X",  i_target.toEcmdString(),  port_number, rank_pair_group, MRS6);
				}

			}
			else if (rank_pair_group == 1)
			{
		    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR0_PRI_RP1_P0_0x8000C11C0301143F, data_buffer_64);
                                if(rc) return rc;
		    		rc_num = rc_num | data_buffer_64.reverse();
		    		rc_num = rc_num | mrs0.insert(data_buffer_64, 0, 16);
		    		rc_num = rc_num | mrs0.extractPreserve(&MRS0, 0, 16, 0);
		    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 0 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS0);

		    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_PRI_RP1_P0_0x8000C11D0301143F, data_buffer_64);
                                if(rc) return rc;
		    		rc_num = rc_num | data_buffer_64.reverse();
		    		rc_num = rc_num | mrs1.insert(data_buffer_64, 0, 16);
		    		rc_num = rc_num | mrs1.extractPreserve(&MRS1, 0, 16, 0);
		    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 1 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS1);

		    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_PRI_RP1_P0_0x8000C11E0301143F, data_buffer_64);
                                if(rc) return rc;
		    		rc_num = rc_num | data_buffer_64.reverse();
		    		rc_num = rc_num | mrs2.insert(data_buffer_64, 0, 16);
		    		rc_num = rc_num | mrs2.extractPreserve(&MRS2, 0, 16, 0);
		    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 2 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS2);

		    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR3_PRI_RP1_P0_0x8000C11F0301143F, data_buffer_64);
                                if(rc) return rc;
		    		rc_num = rc_num | data_buffer_64.reverse();
		    		rc_num = rc_num | mrs3.insert(data_buffer_64, 0, 16);
		    		rc_num = rc_num | mrs3.extractPreserve(&MRS3, 0, 16, 0);
		    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 3 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS3);

				if (dram_gen == ENUM_ATTR_EFF_DRAM_GEN_DDR4)
				{
			    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR0_SEC_RP1_P0_0x8000C1200301143F, data_buffer_64);
                                	if(rc) return rc;
			    		rc_num = rc_num | data_buffer_64.reverse();
			    		rc_num = rc_num | mrs4.insert(data_buffer_64, 0, 16);
			    		rc_num = rc_num | mrs4.extractPreserve(&MRS4, 0, 16, 0);
			    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 4 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS4);

			    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_SEC_RP1_P0_0x8000C1210301143F, data_buffer_64);
                                	if(rc) return rc;
			    		rc_num = rc_num | data_buffer_64.reverse();
			    		rc_num = rc_num | mrs5.insert(data_buffer_64, 0, 16);
			    		rc_num = rc_num | mrs5.extractPreserve(&MRS5, 0, 16, 0);
			    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 5 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS5);

			    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_SEC_RP1_P0_0x8000C1220301143F, data_buffer_64);
                                	if(rc) return rc;
			    		rc_num = rc_num | data_buffer_64.reverse();
			    		rc_num = rc_num | mrs6.insert(data_buffer_64, 0, 16);
			    		rc_num = rc_num | mrs6.extractPreserve(&MRS6, 0, 16, 0);
			    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 6 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS6);
				}

			}
			else if (rank_pair_group == 2)
			{
		   	       rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR0_PRI_RP2_P0_0x8000C21C0301143F, data_buffer_64);
                               if(rc) return rc;
		   	       rc_num = rc_num | data_buffer_64.reverse();
		   	       rc_num = rc_num | mrs0.insert(data_buffer_64, 0, 16);
		   	       rc_num = rc_num | mrs0.extractPreserve(&MRS0, 0, 16, 0);
		   	       FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 0 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS0);

		   	       rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_PRI_RP2_P0_0x8000C21D0301143F, data_buffer_64);
                               if(rc) return rc;
		   	       rc_num = rc_num | data_buffer_64.reverse();
		   	       rc_num = rc_num | mrs1.insert(data_buffer_64, 0, 16);
		   	       rc_num = rc_num | mrs1.extractPreserve(&MRS1, 0, 16, 0);
		   	       FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 1 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS1);

		   	       rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_PRI_RP2_P0_0x8000C21E0301143F, data_buffer_64);
                               if(rc) return rc;
		   	       rc_num = rc_num | data_buffer_64.reverse();
		   	       rc_num = rc_num | mrs2.insert(data_buffer_64, 0, 16);
		   	       rc_num = rc_num | mrs2.extractPreserve(&MRS2, 0, 16, 0);
		   	       FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 2 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS2);

		   	       rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR3_PRI_RP2_P0_0x8000C21F0301143F, data_buffer_64);
                               if(rc) return rc;
		   	       rc_num = rc_num | data_buffer_64.reverse();
		   	       rc_num = rc_num | mrs3.insert(data_buffer_64, 0, 16);
		   	       rc_num = rc_num | mrs3.extractPreserve(&MRS3, 0, 16, 0);
		   	       FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 3 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS3);

				if (dram_gen == ENUM_ATTR_EFF_DRAM_GEN_DDR4)
				{
			    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR0_SEC_RP2_P0_0x8000C2200301143F, data_buffer_64);
                                	if(rc) return rc;
			    		rc_num = rc_num | data_buffer_64.reverse();
			    		rc_num = rc_num | mrs4.insert(data_buffer_64, 0, 16);
			    		rc_num = rc_num | mrs4.extractPreserve(&MRS4, 0, 16, 0);
			    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 4 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS4);

			    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_SEC_RP2_P0_0x8000C2210301143F, data_buffer_64);
                                	if(rc) return rc;
			    		rc_num = rc_num | data_buffer_64.reverse();
			    		rc_num = rc_num | mrs5.insert(data_buffer_64, 0, 16);
			    		rc_num = rc_num | mrs5.extractPreserve(&MRS5, 0, 16, 0);
			    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 5 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS5);

			    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_SEC_RP2_P0_0x8000C2220301143F, data_buffer_64);
                                	if(rc) return rc;
			    		rc_num = rc_num | data_buffer_64.reverse();
			    		rc_num = rc_num | mrs6.insert(data_buffer_64, 0, 16);
			    		rc_num = rc_num | mrs6.extractPreserve(&MRS6, 0, 16, 0);
			    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 6 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS6);
				}

			}
			else if (rank_pair_group == 3)
			{
		   	       rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR0_PRI_RP3_P0_0x8000C31C0301143F, data_buffer_64);
                               if(rc) return rc;
		   	       rc_num = rc_num | data_buffer_64.reverse();
		   	       rc_num = rc_num | mrs0.insert(data_buffer_64, 0, 16);
		   	       rc_num = rc_num | mrs0.extractPreserve(&MRS0, 0, 16, 0);
		   	       FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 0 RP %d VALUE: 0x%04X", i_target.toEcmdString(),  port_number, rank_pair_group, MRS0);

		   	       rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_PRI_RP3_P0_0x8000C31D0301143F, data_buffer_64);
                               if(rc) return rc;
		   	       rc_num = rc_num | data_buffer_64.reverse();
		   	       rc_num = rc_num | mrs1.insert(data_buffer_64, 0, 16);
		   	       rc_num = rc_num | mrs1.extractPreserve(&MRS1, 0, 16, 0);
		   	       FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 1 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS1);

		   	       rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_PRI_RP3_P0_0x8000C31E0301143F, data_buffer_64);
                               if(rc) return rc;
		   	       rc_num = rc_num | data_buffer_64.reverse();
		   	       rc_num = rc_num | mrs2.insert(data_buffer_64, 0, 16);
		   	       rc_num = rc_num | mrs2.extractPreserve(&MRS2, 0, 16, 0);
		   	       FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 2 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS2);

		   	       rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR3_PRI_RP3_P0_0x8000C31F0301143F, data_buffer_64);
                               if(rc) return rc;
		   	       rc_num = rc_num | data_buffer_64.reverse();
		   	       rc_num = rc_num | mrs3.insert(data_buffer_64, 0, 16);
		   	       rc_num = rc_num | mrs3.extractPreserve(&MRS3, 0, 16, 0);
		   	       FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 3 RP %d VALUE: 0x%04X", i_target.toEcmdString(), port_number, rank_pair_group, MRS3);

				if (dram_gen == ENUM_ATTR_EFF_DRAM_GEN_DDR4)
				{
			    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR0_SEC_RP3_P0_0x8000C3200301143F, data_buffer_64);
                                	if(rc) return rc;
			    		rc_num = rc_num | data_buffer_64.reverse();
			    		rc_num = rc_num | mrs4.insert(data_buffer_64, 0, 16);
			    		rc_num = rc_num | mrs4.extractPreserve(&MRS4, 0, 16, 0);
			    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 4 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS4);

			    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_SEC_RP3_P0_0x8000C3210301143F, data_buffer_64);
                                	if(rc) return rc;
			    		rc_num = rc_num | data_buffer_64.reverse();
			    		rc_num = rc_num | mrs5.insert(data_buffer_64, 0, 16);
			    		rc_num = rc_num | mrs5.extractPreserve(&MRS5, 0, 16, 0);
			    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 5 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS5);

			    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_SEC_RP3_P0_0x8000C3220301143F, data_buffer_64);
                                	if(rc) return rc;
			    		rc_num = rc_num | data_buffer_64.reverse();
			    		rc_num = rc_num | mrs6.insert(data_buffer_64, 0, 16);
			    		rc_num = rc_num | mrs6.extractPreserve(&MRS6, 0, 16, 0);
			    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 6 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS6);
				}

			}
		}
		else if (port_number == 1)
		{
			if (rank_pair_group == 0)
			{
		    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR0_PRI_RP0_P1_0x8001C01C0301143F, data_buffer_64);
                                if(rc) return rc;
		    		rc_num = rc_num | data_buffer_64.reverse();
		    		rc_num = rc_num | mrs0.insert(data_buffer_64, 0, 16);
		    		rc_num = rc_num | mrs0.extractPreserve(&MRS0, 0, 16, 0);
		    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 0 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS0 );

		    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_PRI_RP0_P1_0x8001C01D0301143F, data_buffer_64);
                                if(rc) return rc;
		    		rc_num = rc_num | data_buffer_64.reverse();
		    		rc_num = rc_num | mrs1.insert(data_buffer_64, 0, 16);
		    		rc_num = rc_num | mrs1.extractPreserve(&MRS1, 0, 16, 0);
		    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 1 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS1);

		    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_PRI_RP0_P1_0x8001C01E0301143F, data_buffer_64);
                                if(rc) return rc;
		    		rc_num = rc_num | data_buffer_64.reverse();
		    		rc_num = rc_num | mrs2.insert(data_buffer_64, 0, 16);
		    		rc_num = rc_num | mrs2.extractPreserve(&MRS2, 0, 16, 0);
		    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 2 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS2);

		    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR3_PRI_RP0_P1_0x8001C01F0301143F, data_buffer_64);
                                if(rc) return rc;
		    		rc_num = rc_num | data_buffer_64.reverse();
		    		rc_num = rc_num | mrs3.insert(data_buffer_64, 0, 16);
		    		rc_num = rc_num | mrs3.extractPreserve(&MRS3, 0, 16, 0);
		    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 3 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS3);

				if (dram_gen == ENUM_ATTR_EFF_DRAM_GEN_DDR4)
				{
			    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR0_SEC_RP0_P1_0x8001C0200301143F, data_buffer_64);
                                	if(rc) return rc;
			    		rc_num = rc_num | data_buffer_64.reverse();
			    		rc_num = rc_num | mrs4.insert(data_buffer_64, 0, 16);
			    		rc_num = rc_num | mrs4.extractPreserve(&MRS4, 0, 16, 0);
			    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 4 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS4);

			    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_SEC_RP0_P1_0x8001C0210301143F, data_buffer_64);
                                	if(rc) return rc;
			    		rc_num = rc_num | data_buffer_64.reverse();
			    		rc_num = rc_num | mrs5.insert(data_buffer_64, 0, 16);
			    		rc_num = rc_num | mrs5.extractPreserve(&MRS5, 0, 16, 0);
			    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 5 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS5);

			    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_SEC_RP0_P1_0x8001C0220301143F, data_buffer_64);
                                	if(rc) return rc;
			    		rc_num = rc_num | data_buffer_64.reverse();
			    		rc_num = rc_num | mrs6.insert(data_buffer_64, 0, 16);
			    		rc_num = rc_num | mrs6.extractPreserve(&MRS6, 0, 16, 0);
			    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 6 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS6);
				}

			}
			else if (rank_pair_group == 1)
			{
		    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR0_PRI_RP1_P1_0x8001C11C0301143F, data_buffer_64);
                                if(rc) return rc;
		    		rc_num = rc_num | data_buffer_64.reverse();
		    		rc_num = rc_num | mrs0.insert(data_buffer_64, 0, 16);
		    		rc_num = rc_num | mrs0.extractPreserve(&MRS0, 0, 16, 0);
		    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 0 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS0);

		    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_PRI_RP1_P1_0x8001C11D0301143F, data_buffer_64);
                                if(rc) return rc;
		    		rc_num = rc_num | data_buffer_64.reverse();
		    		rc_num = rc_num | mrs1.insert(data_buffer_64, 0, 16);
		    		rc_num = rc_num | mrs1.extractPreserve(&MRS1, 0, 16, 0);
		    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 1 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS1);

		    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_PRI_RP1_P1_0x8001C11E0301143F, data_buffer_64);
                                if(rc) return rc;
		    		rc_num = rc_num | data_buffer_64.reverse();
		    		rc_num = rc_num | mrs2.insert(data_buffer_64, 0, 16);
		    		rc_num = rc_num | mrs2.extractPreserve(&MRS2, 0, 16, 0);
		    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 2 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS2);

		    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR3_PRI_RP1_P1_0x8001C11F0301143F, data_buffer_64);
                                if(rc) return rc;
		    		rc_num = rc_num | data_buffer_64.reverse();
		    		rc_num = rc_num | mrs3.insert(data_buffer_64, 0, 16);
		    		rc_num = rc_num | mrs3.extractPreserve(&MRS3, 0, 16, 0);
		    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 3 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS3);

				if (dram_gen == ENUM_ATTR_EFF_DRAM_GEN_DDR4)
				{
			    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR0_SEC_RP1_P1_0x8001C1200301143F, data_buffer_64);
                                	if(rc) return rc;
			    		rc_num = rc_num | data_buffer_64.reverse();
			    		rc_num = rc_num | mrs4.insert(data_buffer_64, 0, 16);
			    		rc_num = rc_num | mrs4.extractPreserve(&MRS4, 0, 16, 0);
			    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 4 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS4);

			    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_SEC_RP1_P1_0x8001C1210301143F, data_buffer_64);
                                	if(rc) return rc;
			    		rc_num = rc_num | data_buffer_64.reverse();
			    		rc_num = rc_num | mrs5.insert(data_buffer_64, 0, 16);
			    		rc_num = rc_num | mrs5.extractPreserve(&MRS5, 0, 16, 0);
			    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 5 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS5);

			    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_SEC_RP1_P1_0x8001C1220301143F, data_buffer_64);
                                	if(rc) return rc;
			    		rc_num = rc_num | data_buffer_64.reverse();
			    		rc_num = rc_num | mrs6.insert(data_buffer_64, 0, 16);
			    		rc_num = rc_num | mrs6.extractPreserve(&MRS6, 0, 16, 0);
			    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 6 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS6);

				}

			}
			else if (rank_pair_group == 2)
		        {
		   	       rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR0_PRI_RP2_P1_0x8001C21C0301143F, data_buffer_64);
                                if(rc) return rc;
		   	       rc_num = rc_num | data_buffer_64.reverse();
		   	       rc_num = rc_num | mrs0.insert(data_buffer_64, 0, 16);
		   	       rc_num = rc_num | mrs0.extractPreserve(&MRS0, 0, 16, 0);
		   	       FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 0 RP %d VALUE: 0x%04X", i_target.toEcmdString(), port_number, rank_pair_group, MRS0);

		   	       rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_PRI_RP2_P1_0x8001C21D0301143F, data_buffer_64);
                                if(rc) return rc;
		   	       rc_num = rc_num | data_buffer_64.reverse();
		   	       rc_num = rc_num | mrs1.insert(data_buffer_64, 0, 16);
		   	       rc_num = rc_num | mrs1.extractPreserve(&MRS1, 0, 16, 0);
		   	       FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 1 RP %d VALUE: 0x%04X", i_target.toEcmdString(), port_number, rank_pair_group, MRS1);

		   	       rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_PRI_RP2_P1_0x8001C21E0301143F, data_buffer_64);
                                if(rc) return rc;
		   	       rc_num = rc_num | data_buffer_64.reverse();
		   	       rc_num = rc_num | mrs2.insert(data_buffer_64, 0, 16);
		   	       rc_num = rc_num | mrs2.extractPreserve(&MRS2, 0, 16, 0);
		   	       FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 2 RP %d VALUE: 0x%04X", i_target.toEcmdString(), port_number, rank_pair_group, MRS2);

		   	       rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR3_PRI_RP2_P1_0x8001C21F0301143F, data_buffer_64);
                                if(rc) return rc;
		   	       rc_num = rc_num | data_buffer_64.reverse();
		   	       rc_num = rc_num | mrs3.insert(data_buffer_64, 0, 16);
		   	       rc_num = rc_num | mrs3.extractPreserve(&MRS3, 0, 16, 0);
		   	       FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 3 RP %d VALUE: 0x%04X", i_target.toEcmdString(), port_number, rank_pair_group, MRS3);

				if (dram_gen == ENUM_ATTR_EFF_DRAM_GEN_DDR4)
				{
			    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR0_SEC_RP2_P1_0x8001C2200301143F, data_buffer_64);
                                	if(rc) return rc;
			    		rc_num = rc_num | data_buffer_64.reverse();
			    		rc_num = rc_num | mrs4.insert(data_buffer_64, 0, 16);
			    		rc_num = rc_num | mrs4.extractPreserve(&MRS4, 0, 16, 0);
			    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 4 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS4);

			    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_SEC_RP2_P1_0x8001C2210301143F, data_buffer_64);
                                	if(rc) return rc;
			    		rc_num = rc_num | data_buffer_64.reverse();
			    		rc_num = rc_num | mrs5.insert(data_buffer_64, 0, 16);
			    		rc_num = rc_num | mrs5.extractPreserve(&MRS5, 0, 16, 0);
			    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 5 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS5);

			    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_SEC_RP2_P1_0x8001C2220301143F, data_buffer_64);
                                	if(rc) return rc;
			    		rc_num = rc_num | data_buffer_64.reverse();
			    		rc_num = rc_num | mrs6.insert(data_buffer_64, 0, 16);
			    		rc_num = rc_num | mrs6.extractPreserve(&MRS6, 0, 16, 0);
			    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 6 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS6);
				}

			}
			else if (rank_pair_group == 3)
			{
		   	       rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR0_PRI_RP3_P1_0x8001C31C0301143F, data_buffer_64);
                                if(rc) return rc;
		   	       rc_num = rc_num | data_buffer_64.reverse();
		   	       rc_num = rc_num | mrs0.insert(data_buffer_64, 0, 16);
		   	       rc_num = rc_num | mrs0.extractPreserve(&MRS0, 0, 16, 0);
		   	       FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 0 RP %d VALUE: 0x%04X", i_target.toEcmdString(), port_number, rank_pair_group, MRS0);

		   	       rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_PRI_RP3_P1_0x8001C31D0301143F, data_buffer_64);
                                if(rc) return rc;
		   	       rc_num = rc_num | data_buffer_64.reverse();
		   	       rc_num = rc_num | mrs1.insert(data_buffer_64, 0, 16);
		   	       rc_num = rc_num | mrs1.extractPreserve(&MRS1, 0, 16, 0);
		   	       FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 1 RP %d VALUE: 0x%04X", i_target.toEcmdString(), port_number, rank_pair_group, MRS1);

		   	       rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_PRI_RP3_P1_0x8001C31E0301143F, data_buffer_64);
                                if(rc) return rc;
		   	       rc_num = rc_num | data_buffer_64.reverse();
		   	       rc_num = rc_num | mrs2.insert(data_buffer_64, 0, 16);
		   	       rc_num = rc_num | mrs2.extractPreserve(&MRS2, 0, 16, 0);
		   	       FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 2 RP %d VALUE: 0x%04X", i_target.toEcmdString(), port_number, rank_pair_group, MRS2);

		   	       rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR3_PRI_RP3_P1_0x8001C31F0301143F, data_buffer_64);
                                if(rc) return rc;
		   	       rc_num = rc_num | data_buffer_64.reverse();
		   	       rc_num = rc_num | mrs3.insert(data_buffer_64, 0, 16);
		   	       rc_num = rc_num | mrs3.extractPreserve(&MRS3, 0, 16, 0);
		   	       FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 3 RP %d VALUE: 0x%04X", i_target.toEcmdString(), port_number, rank_pair_group, MRS3);

				if (dram_gen == ENUM_ATTR_EFF_DRAM_GEN_DDR4)
				{
			    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR0_SEC_RP3_P1_0x8001C3200301143F, data_buffer_64);
                                	if(rc) return rc;
			    		rc_num = rc_num | data_buffer_64.reverse();
			    		rc_num = rc_num | mrs4.insert(data_buffer_64, 0, 16);
			    		rc_num = rc_num | mrs4.extractPreserve(&MRS4, 0, 16, 0);
			    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 4 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS4);

			    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_SEC_RP3_P1_0x8001C3210301143F, data_buffer_64);
                                	if(rc) return rc;
			    		rc_num = rc_num | data_buffer_64.reverse();
			    		rc_num = rc_num | mrs5.insert(data_buffer_64, 0, 16);
			    		rc_num = rc_num | mrs5.extractPreserve(&MRS5, 0, 16, 0);
			    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 5 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS5);

			    		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_SEC_RP3_P1_0x8001C3220301143F, data_buffer_64);
                                	if(rc) return rc;
			    		rc_num = rc_num | data_buffer_64.reverse();
			    		rc_num = rc_num | mrs6.insert(data_buffer_64, 0, 16);
			    		rc_num = rc_num | mrs6.extractPreserve(&MRS6, 0, 16, 0);
			    		FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 6 RP %d VALUE: 0x%04X",  i_target.toEcmdString(), port_number, rank_pair_group, MRS6);
				}

			}

		}
		}
	    }
	}

        if ( (dram_gen == ENUM_ATTR_EFF_DRAM_GEN_DDR4) && (dimm_type == fapi::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM || dimm_type == fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM) ) 
        {
           FAPI_INF("Performing B-side address inversion MPR write pattern");

           rc = mss_ddr4_invert_mpr_write(i_target);
           if (rc) return rc;
        }

	if (rc_num)
	{
	    FAPI_ERR( "mss_draminit: Error setting up buffers");
	    rc_buff.setEcmdError(rc_num);
	    return rc_buff;
	}


        // TODO:
        // This is Commented out because RCD Parity Check has not been written yet.
        // Check RCD Parity
        //rc = RCD_PARITY_CHECK(i_target);
        //if(rc){
            //FAPI_ERR(" RCD_PARITY_CHECK FAILED rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
            //return rc;
        //}

        //Master Attntion Reg Check... Need to add appropriate call below.
        //MASTER_ATTENTION_REG_CHECK();

    return rc;
}



ReturnCode mss_assert_resetn_drive_mem_clks(
            Target& i_target
            )
{
    // mcbist_ddr_resetn = 1 -- to deassert DDR RESET#
    //mcbist_ddr_dphy_nclk = 01, mcbist_ddr_dphy_pclk = 10 -- to drive the memory clks

    ReturnCode rc;
    ReturnCode rc_buff;
    uint32_t rc_num = 0;
    ecmdDataBufferBase stop_on_err_1(1);
    ecmdDataBufferBase ue_disable_1(1);
    ecmdDataBufferBase data_sel_2(2);
    ecmdDataBufferBase pclk_2(2);
    rc_num = rc_num | pclk_2.insertFromRight((uint32_t) 2, 0, 2);
    ecmdDataBufferBase nclk_2(2);
    rc_num = rc_num | nclk_2.insertFromRight((uint32_t) 1, 0, 2);
    ecmdDataBufferBase cal_time_cnt_16(16);
    ecmdDataBufferBase resetn_1(1);
    rc_num = rc_num | resetn_1.setBit(0);
    ecmdDataBufferBase reset_recover_1(1);
    ecmdDataBufferBase copy_spare_cke_1(1);
    rc_num = rc_num | copy_spare_cke_1.setBit(0); // mdb : clk enable on for spare

    FAPI_INF( "+++++++++++++++++++++ ASSERTING RESETN, DRIVING MEM CLKS +++++++++++++++++++++");

    if (rc_num)
    {
        FAPI_ERR( "mss_assert_resetn_drive_mem_clks: Error setting up buffers");
        rc_buff.setEcmdError(rc_num);
        return rc_buff;
    }

    // Setting CCS Mode
    rc = mss_ccs_mode(i_target,
                      stop_on_err_1,
                      ue_disable_1,
                      data_sel_2,
                      pclk_2,
                      nclk_2,
                      cal_time_cnt_16,
                      resetn_1,
                      reset_recover_1,
                      copy_spare_cke_1);

    return rc;
}

ReturnCode mss_rcd_load(
            Target& i_target,
            uint32_t i_port_number,
            uint32_t& io_ccs_inst_cnt
            )    {

    ReturnCode rc;
    ReturnCode rc_buff;
    uint32_t rc_num = 0;
    uint32_t dimm_number;
    uint32_t rcd_number;

    ecmdDataBufferBase rcd_cntl_wrd_4(8);
    ecmdDataBufferBase rcd_cntl_wrd_64(64);
    uint16_t num_ranks;

    ecmdDataBufferBase address_16(16);
    ecmdDataBufferBase bank_3(3);
    ecmdDataBufferBase activate_1(1);
    ecmdDataBufferBase rasn_1(1);
    rc_num = rc_num | rasn_1.setBit(0);
    ecmdDataBufferBase casn_1(1);
    rc_num = rc_num | casn_1.setBit(0);
    ecmdDataBufferBase wen_1(1);
    rc_num = rc_num | wen_1.setBit(0);
    ecmdDataBufferBase cke_4(4);
    rc_num = rc_num | cke_4.setBit(0,4);
    ecmdDataBufferBase csn_8(8);
    rc_num = rc_num | csn_8.setBit(0,8);
    ecmdDataBufferBase odt_4(4);
    rc_num = rc_num | odt_4.clearBit(0,4);
    ecmdDataBufferBase ddr_cal_type_4(4);

    ecmdDataBufferBase num_idles_16(16);
    ecmdDataBufferBase num_repeat_16(16);
    ecmdDataBufferBase data_20(20);
    ecmdDataBufferBase read_compare_1(1);
    ecmdDataBufferBase rank_cal_4(4);
    ecmdDataBufferBase ddr_cal_enable_1(1);
    ecmdDataBufferBase ccs_end_1(1);

    uint8_t num_ranks_array[2][2]; //[port][dimm]
    uint64_t rcd_array[2][2]; //[port][dimm]
    uint8_t dimm_type;
            
    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target, dimm_type);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target, num_ranks_array);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_RCD_CNTL_WORD_0_15, &i_target, rcd_array);
    if(rc) return rc;

    // Raise CKE high with NOPS, waiting min Reset CKE exit time (tXPR) - 400 cycles
    rc_num = rc_num | address_16.clearBit(0, 16);
    rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 400, 0, 16);
    rc = mss_ccs_inst_arry_0( i_target,
                              io_ccs_inst_cnt,
                              address_16,
                              bank_3,
                              activate_1,
                              rasn_1,
                              casn_1,
                              wen_1,
                              cke_4,
                              csn_8,
                              odt_4,
                              ddr_cal_type_4,
                              i_port_number);
    if(rc) return rc;
    rc = mss_ccs_inst_arry_1( i_target,
                              io_ccs_inst_cnt,
                              num_idles_16,
                              num_repeat_16,
                              data_20,
                              read_compare_1,
                              rank_cal_4,
                              ddr_cal_enable_1,
                              ccs_end_1);
    if(rc) return rc;
    io_ccs_inst_cnt ++;

    FAPI_INF( "+++++++++++++++++++++ LOADING RCD CONTROL WORDS FOR %s PORT %d +++++++++++++++++++++", i_target.toEcmdString(), i_port_number);

    for ( dimm_number = 0; dimm_number < MAX_NUM_DIMMS; dimm_number++)
    {
        num_ranks = num_ranks_array[i_port_number][dimm_number];

        if (num_ranks == 0)
        {
            FAPI_INF( "PORT%d DIMM%d not configured. Num_ranks: %d", i_port_number, dimm_number, num_ranks);
        }
        else
        {
            FAPI_INF( "RCD SETTINGS FOR %s PORT%d DIMM%d ", i_target.toEcmdString(), i_port_number, dimm_number);
	    FAPI_INF( "RCD Control Word: 0x%016llX", rcd_array[i_port_number][dimm_number]);

            if (rc_num)
            {
                FAPI_ERR( "mss_rcd_load: Error setting up buffers");
                rc_buff.setEcmdError(rc_num);
                return rc_buff;
            }

            // ALL active CS lines at a time.
            rc_num = rc_num | csn_8.setBit(0,8);
            if (dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM)
            {
                // for dimm0 use CS0,1 (active low); for dimm1 use CS4,5 (active low)
                rc_num = rc_num | csn_8.clearBit((4*dimm_number), 2 );
            }
            else if ((num_ranks == 1) || (num_ranks == 2))
            {
                rc_num = rc_num | csn_8.clearBit(0+4*dimm_number);
                rc_num = rc_num | csn_8.clearBit(1+4*dimm_number);
            }
            else if (num_ranks == 4)
            {
                rc_num = rc_num | csn_8.clearBit(0+4*dimm_number);
                rc_num = rc_num | csn_8.clearBit(1+4*dimm_number);
                rc_num = rc_num | csn_8.clearBit(2+4*dimm_number);
                rc_num = rc_num | csn_8.clearBit(3+4*dimm_number);
            }

            // Propogate through the 16, 4-bit control words
            for ( rcd_number = 0; rcd_number<= 15; rcd_number++)
            {
		rc_num = rc_num | bank_3.clearBit(0, 3);
                rc_num = rc_num | address_16.clearBit(0, 16);

                rc_num = rc_num | rcd_cntl_wrd_64.setDoubleWord(0, rcd_array[i_port_number][dimm_number]);
                rc_num = rc_num | rcd_cntl_wrd_64.extract(rcd_cntl_wrd_4, 4*rcd_number, 4);

                //control word number code bits A0, A1, A2, BA2
                rc_num = rc_num | address_16.insert(rcd_number, 2, 1, 29);
                rc_num = rc_num | address_16.insert(rcd_number, 1, 1, 30);
                rc_num = rc_num | address_16.insert(rcd_number, 0, 1, 31);
                rc_num = rc_num | bank_3.insert(rcd_number, 2, 1, 28);

                //control word values RCD0 = A3, RCD1 = A4, RCD2 = BA0, RCD3 = BA1
                rc_num = rc_num | address_16.insert(rcd_cntl_wrd_4, 3, 1, 3);
                rc_num = rc_num | address_16.insert(rcd_cntl_wrd_4, 4, 1, 2);
                rc_num = rc_num | bank_3.insert(rcd_cntl_wrd_4, 0, 1, 1);
                rc_num = rc_num | bank_3.insert(rcd_cntl_wrd_4, 1, 1, 0);

                // Send out to the CCS array
                if ( dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM && (rcd_number == 2 || rcd_number == 10) )
                {
                   rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 4000, 0 , 16 ); // wait tStab for clock timing rcd words
                }
                else
                {
                   rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 12, 0, 16);
                }


	        if (rc_num)
	        {
	           FAPI_ERR( "mss_rcd_load: Error setting up buffers");
	           rc_buff.setEcmdError(rc_num);
	           return rc_buff;
	        }

                rc = mss_ccs_inst_arry_0( i_target,
                                          io_ccs_inst_cnt,
                                          address_16,
                                          bank_3,
                                          activate_1,
                                          rasn_1,
                                          casn_1,
                                          wen_1,
                                          cke_4,
                                          csn_8,
                                          odt_4,
                                          ddr_cal_type_4,
                                          i_port_number);
                if(rc) return rc;
                rc = mss_ccs_inst_arry_1( i_target,
                                          io_ccs_inst_cnt,
                                          num_idles_16,
                                          num_repeat_16,
                                          data_20,
                                          read_compare_1,
                                          rank_cal_4,
                                          ddr_cal_enable_1,
                                          ccs_end_1);
                if(rc) return rc;
                io_ccs_inst_cnt ++;

                if (rc_num)
                {
                    FAPI_ERR( "mss_rcd_load: Error setting up buffers");
                    rc_buff.setEcmdError(rc_num);
                    return rc_buff;
                }
            }
        }
    }
    return rc;
}

ReturnCode mss_mrs_load(
            Target& i_target,
            uint32_t i_port_number,
            uint32_t& io_ccs_inst_cnt
            )
{

    uint32_t dimm_number;
    uint32_t rank_number;
    uint32_t mrs_number;
    ReturnCode rc;
    ReturnCode rc_buff;
    uint32_t rc_num = 0;

    ecmdDataBufferBase data_buffer_64(64);
    ecmdDataBufferBase address_16(16);
    ecmdDataBufferBase bank_3(3);
    ecmdDataBufferBase activate_1(1);
    ecmdDataBufferBase rasn_1(1);
    rc_num = rc_num | rasn_1.clearBit(0);
    ecmdDataBufferBase casn_1(1);
    rc_num = rc_num | casn_1.clearBit(0);
    ecmdDataBufferBase wen_1(1);
    rc_num = rc_num | wen_1.clearBit(0);
    ecmdDataBufferBase cke_4(4);
    rc_num = rc_num | cke_4.setBit(0,4);
    ecmdDataBufferBase csn_8(8);
    rc_num = rc_num | csn_8.setBit(0,8);
    ecmdDataBufferBase odt_4(4);
    rc_num = rc_num | odt_4.clearBit(0,4);
    ecmdDataBufferBase ddr_cal_type_4(4);

    ecmdDataBufferBase csn_setup_8(8);
    rc_num = rc_num | csn_setup_8.setBit(0,8);

    ecmdDataBufferBase num_idles_16(16);
    ecmdDataBufferBase num_idles_setup_16(16);
    rc_num = rc_num | num_idles_setup_16.insertFromRight((uint32_t) 400, 0, 16);

    ecmdDataBufferBase num_repeat_16(16);
    ecmdDataBufferBase data_20(20);
    ecmdDataBufferBase read_compare_1(1);
    ecmdDataBufferBase rank_cal_4(4);
    ecmdDataBufferBase ddr_cal_enable_1(1);
    ecmdDataBufferBase ccs_end_1(1);

    ecmdDataBufferBase mrs0(16);
    ecmdDataBufferBase mrs1(16);
    ecmdDataBufferBase mrs2(16);
    ecmdDataBufferBase mrs3(16);
    uint16_t MRS0 = 0;
    uint16_t MRS1 = 0;
    uint16_t MRS2 = 0;
    uint16_t MRS3 = 0;

    uint16_t num_ranks = 0;
    uint8_t lrdimm_rank_mult_mode = 0;


    FAPI_INF( "+++++++++++++++++++++ LOADING MRS SETTINGS FOR %s PORT %d +++++++++++++++++++++", i_target.toEcmdString(), i_port_number);

    uint8_t num_ranks_array[2][2]; //[port][dimm]
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target, num_ranks_array);
    if(rc) return rc;

    uint8_t dimm_type;
    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target, dimm_type);
    if(rc) return rc;

    uint8_t is_sim = 0;
    rc = FAPI_ATTR_GET(ATTR_IS_SIMULATION, NULL, is_sim);
    if(rc) return rc;

    uint8_t dram_2n_mode = 0;
    rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_2N_MODE_ENABLED, &i_target, dram_2n_mode);
    if(rc) return rc;

    uint8_t address_mirror_map[2][2]; //address_mirror_map[port][dimm]
    rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_ADDRESS_MIRRORING, &i_target, address_mirror_map);
    if(rc) return rc;


    //Lines commented out in the following section are waiting for xml attribute adds
    //MRS0
    uint8_t dram_bl;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_BL, &i_target, dram_bl);
    if(rc) return rc;
    uint8_t read_bt; //Read Burst Type
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_RBT, &i_target, read_bt);
    if(rc) return rc;
    uint8_t dram_cl;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_CL, &i_target, dram_cl);
    if(rc) return rc;
    uint8_t test_mode; //TEST MODE
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_TM, &i_target, test_mode);
    if(rc) return rc;
    uint8_t dll_reset; //DLL Reset
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_DLL_RESET, &i_target, dll_reset);
    if(rc) return rc;
    uint8_t dram_wr;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WR, &i_target, dram_wr);
    if(rc) return rc;
    uint8_t dll_precharge; //DLL Control For Precharge
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_DLL_PPD, &i_target, dll_precharge);
    if(rc) return rc;

    if (dram_bl == ENUM_ATTR_EFF_DRAM_BL_BL8)
    {
        dram_bl = 0x00;
    }
    else if (dram_bl == ENUM_ATTR_EFF_DRAM_BL_OTF)
    {
        dram_bl = 0x80;
    }
    else if (dram_bl == ENUM_ATTR_EFF_DRAM_BL_BC4)
    {
        dram_bl = 0x40;
    }

    if (dram_wr == 16)
    {
	dram_wr = 0x00;
    }
    else if (dram_wr == 5)
    {
        dram_wr = 0x80;
    }
    else if (dram_wr == 6)
    {
        dram_wr = 0x40;
    }
    else if (dram_wr == 7)
    {
        dram_wr = 0xC0;
    }
    else if (dram_wr == 8)
    {
        dram_wr = 0x20;
    }
    else if (dram_wr == 10)
    {
        dram_wr = 0xA0;
    }
    else if (dram_wr == 12)
    {
        dram_wr = 0x60;
    }
    else if (dram_wr == 14)
    {
        dram_wr = 0xE0;
    }


    if (read_bt == ENUM_ATTR_EFF_DRAM_RBT_SEQUENTIAL)
    {
        read_bt = 0x00;
    }
    else if (read_bt == ENUM_ATTR_EFF_DRAM_RBT_INTERLEAVE)
    {
        read_bt = 0xFF;
    }

    if ((dram_cl > 4)&&(dram_cl < 12))
    {
        dram_cl = (dram_cl - 4) << 1;
    }
    else if ((dram_cl > 11)&&(dram_cl < 17))
    {
        dram_cl = ((dram_cl - 12) << 1) + 1;
    }
    dram_cl = mss_reverse_8bits(dram_cl);

    if (test_mode == ENUM_ATTR_EFF_DRAM_TM_NORMAL)
    {
        test_mode = 0x00;
    }
    else if (test_mode == ENUM_ATTR_EFF_DRAM_TM_TEST)
    {
        test_mode = 0xFF;
    }

    if (dll_reset == ENUM_ATTR_EFF_DRAM_DLL_RESET_YES)
    {
        dll_reset = 0xFF;
    }
    else if (dll_reset == ENUM_ATTR_EFF_DRAM_DLL_RESET_NO)
    {
        dll_reset = 0x00;
    }

    if (dll_precharge == ENUM_ATTR_EFF_DRAM_DLL_PPD_SLOWEXIT)
    {
        dll_precharge = 0x00;
    }
    else if (dll_precharge == ENUM_ATTR_EFF_DRAM_DLL_PPD_FASTEXIT)
    {
        dll_precharge = 0xFF;
    }

    //MRS1
    uint8_t dll_enable; //DLL Enable
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_DLL_ENABLE, &i_target, dll_enable);
    if(rc) return rc;
    uint8_t out_drv_imp_cntl[2][2];
    rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_RON, &i_target, out_drv_imp_cntl);
    if(rc) return rc;
    uint8_t dram_rtt_nom[2][2][4];
    rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_RTT_NOM, &i_target, dram_rtt_nom);
    if(rc) return rc;
    uint8_t dram_al;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_AL, &i_target, dram_al);
    if(rc) return rc;
    uint8_t wr_lvl; //write leveling enable
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WR_LVL_ENABLE, &i_target, wr_lvl);
    if(rc) return rc;
    uint8_t tdqs_enable; //TDQS Enable
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_TDQS, &i_target, tdqs_enable);
    if(rc) return rc;
    uint8_t q_off; //Qoff - Output buffer Enable
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_OUTPUT_BUFFER, &i_target, q_off);
    if(rc) return rc;

    if (dll_enable == ENUM_ATTR_EFF_DRAM_DLL_ENABLE_ENABLE)
    {
        dll_enable = 0x00;
    }
    else if (dll_enable == ENUM_ATTR_EFF_DRAM_DLL_ENABLE_DISABLE)
    {
        dll_enable = 0xFF;
    }

    if (dram_al == ENUM_ATTR_EFF_DRAM_AL_DISABLE)
    {
        dram_al = 0x00;
    }
    else if (dram_al == ENUM_ATTR_EFF_DRAM_AL_CL_MINUS_1)
    {
        dram_al = 0x80;
    }
    else if (dram_al == ENUM_ATTR_EFF_DRAM_AL_CL_MINUS_2)
    {
        dram_al = 0x40;
    }

    if (wr_lvl == ENUM_ATTR_EFF_DRAM_WR_LVL_ENABLE_DISABLE)
    {
        wr_lvl = 0x00;
    }
    else if (wr_lvl == ENUM_ATTR_EFF_DRAM_WR_LVL_ENABLE_ENABLE)
    {
        wr_lvl = 0xFF;
    }

    if (tdqs_enable == ENUM_ATTR_EFF_DRAM_TDQS_DISABLE)
    {
        tdqs_enable = 0x00;
    }
    else if (tdqs_enable == ENUM_ATTR_EFF_DRAM_TDQS_ENABLE)
    {
        tdqs_enable = 0xFF;
    }

    if (q_off == ENUM_ATTR_EFF_DRAM_OUTPUT_BUFFER_DISABLE)
    {
        q_off = 0xFF;
    }
    else if (q_off == ENUM_ATTR_EFF_DRAM_OUTPUT_BUFFER_ENABLE)
    {
        q_off = 0x00;
    }

    //MRS2
    uint8_t pt_arr_sr; //Partial Array Self Refresh
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_PASR, &i_target, pt_arr_sr);
    if(rc) return rc;
    uint8_t cwl; // CAS Write Latency
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_CWL, &i_target, cwl);
    if(rc) return rc;
    uint8_t auto_sr; // Auto Self-Refresh
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_ASR, &i_target, auto_sr);
    if(rc) return rc;
    uint8_t sr_temp; // Self-Refresh Temp Range
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_SRT, &i_target, sr_temp);
    if(rc) return rc;
    uint8_t dram_rtt_wr[2][2][4];
    rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_RTT_WR, &i_target, dram_rtt_wr);
    if(rc) return rc;

    if (pt_arr_sr == ENUM_ATTR_EFF_DRAM_PASR_FULL)
    {
        pt_arr_sr = 0x00;
    }
    else if (pt_arr_sr == ENUM_ATTR_EFF_DRAM_PASR_FIRST_HALF)
    {
        pt_arr_sr = 0x80;
    }
    else if (pt_arr_sr == ENUM_ATTR_EFF_DRAM_PASR_FIRST_QUARTER)
    {
        pt_arr_sr = 0x40;
    }
    else if (pt_arr_sr == ENUM_ATTR_EFF_DRAM_PASR_FIRST_EIGHTH)
    {
        pt_arr_sr = 0xC0;
    }
    else if (pt_arr_sr == ENUM_ATTR_EFF_DRAM_PASR_LAST_THREE_FOURTH)
    {
        pt_arr_sr = 0x20;
    }
    else if (pt_arr_sr == ENUM_ATTR_EFF_DRAM_PASR_LAST_HALF)
    {
        pt_arr_sr = 0xA0;
    }
    else if (pt_arr_sr == ENUM_ATTR_EFF_DRAM_PASR_LAST_QUARTER)
    {
        pt_arr_sr = 0x60;
    }
    else if (pt_arr_sr == ENUM_ATTR_EFF_DRAM_PASR_LAST_EIGHTH)
    {
        pt_arr_sr = 0xE0;
    }

    cwl = mss_reverse_8bits(cwl - 5);

    if (auto_sr == ENUM_ATTR_EFF_DRAM_ASR_SRT)
    {
        auto_sr = 0x00;
    }
    else if (auto_sr == ENUM_ATTR_EFF_DRAM_ASR_ASR)
    {
        auto_sr = 0xFF;
    }

    if (sr_temp == ENUM_ATTR_EFF_DRAM_SRT_NORMAL)
    {
        sr_temp = 0x00;
    }
    else if (sr_temp == ENUM_ATTR_EFF_DRAM_SRT_EXTEND)
    {
        sr_temp = 0xFF;
    }

    //MRS3
    uint8_t mpr_loc; // MPR Location
    rc = FAPI_ATTR_GET(ATTR_EFF_MPR_LOC, &i_target, mpr_loc);
    if(rc) return rc;
    uint8_t mpr_op; // MPR Operation Mode
    rc = FAPI_ATTR_GET(ATTR_EFF_MPR_MODE, &i_target, mpr_op);
    if(rc) return rc;

    mpr_loc = mss_reverse_8bits(mpr_loc);

    if (mpr_op == ENUM_ATTR_EFF_MPR_MODE_ENABLE)
    {
        mpr_op = 0xFF;
    }
    else if (mpr_op == ENUM_ATTR_EFF_MPR_MODE_DISABLE)
    {
        mpr_op = 0x00;
    }

    // Raise CKE high with NOPS, waiting min Reset CKE exit time (tXPR) - 400 cycles
    rc_num = rc_num | csn_8.setBit(0,8);
    rc_num = rc_num | address_16.clearBit(0, 16);
    rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 400, 0, 16);
    rc = mss_ccs_inst_arry_0( i_target,
                              io_ccs_inst_cnt,
                              address_16,
                              bank_3,
                              activate_1,
                              rasn_1,
                              casn_1,
                              wen_1,
                              cke_4,
                              csn_8,
                              odt_4,
                              ddr_cal_type_4,
                              i_port_number);	
    if(rc) return rc;
    rc = mss_ccs_inst_arry_1( i_target,
                              io_ccs_inst_cnt,
                              num_idles_16,
                              num_repeat_16,
                              data_20,
                              read_compare_1,
                              rank_cal_4,
                              ddr_cal_enable_1,
                              ccs_end_1);
    if(rc) return rc;
    io_ccs_inst_cnt ++;

    // Dimm 0-1
    for ( dimm_number = 0; dimm_number < MAX_NUM_DIMMS; dimm_number++)
    {
        num_ranks = num_ranks_array[i_port_number][dimm_number];

        if (num_ranks == 0)
        {
            FAPI_INF( " %s PORT%d DIMM%d not configured. Num_ranks: %d ", i_target.toEcmdString(), i_port_number, dimm_number, num_ranks);
        }
        else
        {
          
            if (dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM)
            {
                rc = FAPI_ATTR_GET(ATTR_LRDIMM_RANK_MULT_MODE, &i_target, lrdimm_rank_mult_mode);
                if(rc) return rc;

                if ( (lrdimm_rank_mult_mode == 4) && (num_ranks == 8) ) 
                {
                   num_ranks = 2;
                }
            }

            // Rank 0-3
            for ( rank_number = 0; rank_number < num_ranks; rank_number++)
            {
                    FAPI_INF( "MRS SETTINGS FOR %s PORT%d DIMM%d RANK%d", i_target.toEcmdString(), i_port_number, dimm_number, rank_number);

                    rc_num = rc_num | csn_8.setBit(0,8);
                    rc_num = rc_num | address_16.clearBit(0, 16);

                    rc_num = rc_num | mrs0.insert((uint8_t) dram_bl, 0, 2, 0);
                    rc_num = rc_num | mrs0.insert((uint8_t) dram_cl, 2, 1, 0);
                    rc_num = rc_num | mrs0.insert((uint8_t) read_bt, 3, 1, 0);
                    rc_num = rc_num | mrs0.insert((uint8_t) dram_cl, 4, 3, 1);
                    rc_num = rc_num | mrs0.insert((uint8_t) test_mode, 7, 1);
                    rc_num = rc_num | mrs0.insert((uint8_t) dll_reset, 8, 1);
                    rc_num = rc_num | mrs0.insert((uint8_t) dram_wr, 9, 3);
                    rc_num = rc_num | mrs0.insert((uint8_t) dll_precharge, 12, 1);
                    rc_num = rc_num | mrs0.insert((uint8_t) 0x00, 13, 3);

	            rc_num = rc_num | mrs0.extractPreserve(&MRS0, 0, 16, 0);

                    if ( lrdimm_rank_mult_mode != 0 )
                    {
                        dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0x00;
                    }
                    else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE)
                    {
                        dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0x00;
                    }
                    else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM20)
                    {
                        dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0x20;
                    }
                    else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30)
                    {
                        dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0xA0;
                    }
                    else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40)
                    {
                        dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0xC0;
                    }
                    else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM60)
                    {
                        dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0x80;
                    }
                    else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM120)
                    {
                        dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0x40;
                    }
                    else
                    {
			//DECONFIG and FFDC INFO
			const fapi::Target & TARGET_MBA_ERROR = i_target;
                        const uint8_t & IMP = dram_rtt_nom[i_port_number][dimm_number][rank_number];
                        const uint32_t & PORT = i_port_number;
                        const uint32_t & DIMM = dimm_number;
                        const uint32_t & RANK = rank_number;

                        FAPI_ERR( "mss_mrs_load: Error determining ATTR_VPD_DRAM_RTT_NOM value: %d from attribute", dram_rtt_nom[i_port_number][dimm_number][rank_number]);
                        FAPI_SET_HWP_ERROR(rc, RC_MSS_DRAMINIT_RTT_NOM_IMP_INPUT_ERROR);
                        return rc;
                    }

                    if (out_drv_imp_cntl[i_port_number][dimm_number] == ENUM_ATTR_VPD_DRAM_RON_OHM40)
                    {
                        out_drv_imp_cntl[i_port_number][dimm_number] = 0x00;
                    }
                    else if (out_drv_imp_cntl[i_port_number][dimm_number] == ENUM_ATTR_VPD_DRAM_RON_OHM34)
                    {
                        out_drv_imp_cntl[i_port_number][dimm_number] = 0x80;
                    }

                    rc_num = rc_num | mrs1.insert((uint8_t) dll_enable, 0, 1, 0);
                    rc_num = rc_num | mrs1.insert((uint8_t) out_drv_imp_cntl[i_port_number][dimm_number], 1, 1, 0);
                    rc_num = rc_num | mrs1.insert((uint8_t) dram_rtt_nom[i_port_number][dimm_number][rank_number], 2, 1, 0);
                    rc_num = rc_num | mrs1.insert((uint8_t) dram_al, 3, 2, 0);
                    rc_num = rc_num | mrs1.insert((uint8_t) out_drv_imp_cntl[i_port_number][dimm_number], 5, 1, 1);
                    rc_num = rc_num | mrs1.insert((uint8_t) dram_rtt_nom[i_port_number][dimm_number][rank_number], 6, 1, 1);
                    rc_num = rc_num | mrs1.insert((uint8_t) wr_lvl, 7, 1, 0);
                    rc_num = rc_num | mrs1.insert((uint8_t) 0x00, 8, 1);
                    rc_num = rc_num | mrs1.insert((uint8_t) dram_rtt_nom[i_port_number][dimm_number][rank_number], 9, 1, 2);
                    rc_num = rc_num | mrs1.insert((uint8_t) 0x00, 10, 1);
                    rc_num = rc_num | mrs1.insert((uint8_t) tdqs_enable, 11, 1, 0);
                    rc_num = rc_num | mrs1.insert((uint8_t) q_off, 12, 1, 0);
                    rc_num = rc_num | mrs1.insert((uint8_t) 0x00, 13, 3);

        	    rc_num = rc_num | mrs1.extractPreserve(&MRS1, 0, 16, 0);


                    if ( (lrdimm_rank_mult_mode != 0) && (rank_number > 1) )
                    {
                        dram_rtt_wr[i_port_number][dimm_number][rank_number] = dram_rtt_wr[i_port_number][dimm_number][0];
                    }
                    else if (dram_rtt_wr[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE)
                    {
                        dram_rtt_wr[i_port_number][dimm_number][rank_number] = 0x00;
                    }
                    else if (dram_rtt_wr[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60)
                    {
                        dram_rtt_wr[i_port_number][dimm_number][rank_number] = 0x80;
                    }
                    else if (dram_rtt_wr[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120)
                    {
                        dram_rtt_wr[i_port_number][dimm_number][rank_number] = 0x40;
                    }
		    else
		    {

			//DECONFIG and FFDC INFO
			const fapi::Target & TARGET_MBA_ERROR = i_target;
                        const uint8_t & IMP = dram_rtt_nom[i_port_number][dimm_number][rank_number];
                        const uint32_t & PORT = i_port_number;
                        const uint32_t & DIMM = dimm_number;
                        const uint32_t & RANK = rank_number;

                        FAPI_ERR( "mss_mrs_load: Error determining ATTR_VPD_DRAM_RTT_WR value: %d from attribute", dram_rtt_wr[i_port_number][dimm_number][rank_number]);
                        FAPI_SET_HWP_ERROR(rc, RC_MSS_DRAMINIT_RTT_WR_IMP_INPUT_ERROR);
                        return rc;
                    }

                    rc_num = rc_num | mrs2.insert((uint8_t) pt_arr_sr, 0, 3);
                    rc_num = rc_num | mrs2.insert((uint8_t) cwl, 3, 3);
                    rc_num = rc_num | mrs2.insert((uint8_t) auto_sr, 6, 1);
                    rc_num = rc_num | mrs2.insert((uint8_t) sr_temp, 7, 1);
                    rc_num = rc_num | mrs2.insert((uint8_t) 0x00, 8, 1);
                    rc_num = rc_num | mrs2.insert((uint8_t) dram_rtt_wr[i_port_number][dimm_number][rank_number], 9, 2);
                    rc_num = rc_num | mrs2.insert((uint8_t) 0x00, 11, 5);

        	    rc_num = rc_num | mrs2.extractPreserve(&MRS2, 0, 16, 0);

                    rc_num = rc_num | mrs3.insert((uint8_t) mpr_loc, 0, 2);
                    rc_num = rc_num | mrs3.insert((uint8_t) mpr_op, 2, 1);
                    rc_num = rc_num | mrs3.insert((uint16_t) 0x0000, 3, 13);

        	    rc_num = rc_num | mrs3.extractPreserve(&MRS3, 0, 16, 0);
        	    FAPI_INF( "MRS 0: 0x%04X", MRS0);
        	    FAPI_INF( "MRS 1: 0x%04X", MRS1);
        	    FAPI_INF( "MRS 2: 0x%04X", MRS2);	
                    FAPI_INF( "MRS 3: 0x%04X", MRS3);

                    if (rc_num)
                    {
                        FAPI_ERR( "mss_mrs_load: Error setting up buffers");
                        rc_buff.setEcmdError(rc_num);
                        return rc_buff;
                    }

                    // Only corresponding CS to rank
                    rc_num = rc_num | csn_8.setBit(0,8);
                    rc_num = rc_num | csn_8.clearBit(rank_number+4*dimm_number);

                    // Propogate through the 4 MRS cmds
                    for ( mrs_number = 0; mrs_number < 4; mrs_number++)
                    {

                        // Copying the current MRS into address buffer matching the MRS_array order
                        // Setting the bank address
                        if (mrs_number == 0)
                        {
                            rc_num = rc_num | address_16.insert(mrs2, 0, 16, 0);
			    rc_num = rc_num | bank_3.insert((uint8_t) MRS2_BA, 0, 1, 7);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS2_BA, 1, 1, 6);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS2_BA, 2, 1, 5);
                        }
                        else if ( mrs_number == 1)
                        {
                            rc_num = rc_num | address_16.insert(mrs3, 0, 16, 0);
			    rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 0, 1, 7);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 1, 1, 6);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 2, 1, 5);
                        }
                        else if ( mrs_number == 2)
                        {
                            rc_num = rc_num | address_16.insert(mrs1, 0, 16, 0);
			    rc_num = rc_num | bank_3.insert((uint8_t) MRS1_BA, 0, 1, 7);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS1_BA, 1, 1, 6);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS1_BA, 2, 1, 5);
                        }
                        else if ( mrs_number == 3)
                        {
                            rc_num = rc_num | address_16.insert(mrs0, 0, 16, 0);
			    rc_num = rc_num | bank_3.insert((uint8_t) MRS0_BA, 0, 1, 7);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS0_BA, 1, 1, 6);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS0_BA, 2, 1, 5);
                        }

                        if (rc_num)
                        {
                            FAPI_ERR( "mss_mrs_load: Error setting up buffers");
                            rc_buff.setEcmdError(rc_num);
                            return rc_buff;
                        }

		        if (( address_mirror_map[i_port_number][dimm_number] & (0x08 >> rank_number) ) && (is_sim == 0))
			{
		            rc = mss_address_mirror_swizzle(i_target, i_port_number, dimm_number, rank_number, address_16, bank_3);
                            if(rc) return rc;
			}


			if (dram_2n_mode  == ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_TRUE)
			{

                        // Send out to the CCS array a "setup" cycle
                        rc = mss_ccs_inst_arry_0( i_target,
                                          io_ccs_inst_cnt,
                                          address_16,
                                          bank_3,
                                          activate_1,
                                          rasn_1,
                                          casn_1,
                                          wen_1,
                                          cke_4,
                                          csn_setup_8,
                                          odt_4,
                                          ddr_cal_type_4,
                                          i_port_number);
                        if(rc) return rc;
                        rc = mss_ccs_inst_arry_1( i_target,
                                          io_ccs_inst_cnt,
                                          num_idles_setup_16,
                                          num_repeat_16,
                                          data_20,
                                          read_compare_1,
                                          rank_cal_4,
                                          ddr_cal_enable_1,
                                          ccs_end_1);
                        if(rc) return rc;

                        io_ccs_inst_cnt ++;

			}

                        // Send out to the CCS array
                        rc = mss_ccs_inst_arry_0( i_target,
                                          io_ccs_inst_cnt,
                                          address_16,
                                          bank_3,
                                          activate_1,
                                          rasn_1,
                                          casn_1,
                                          wen_1,
                                          cke_4,
                                          csn_8,
                                          odt_4,
                                          ddr_cal_type_4,
                                          i_port_number);
                        if(rc) return rc;
                        rc = mss_ccs_inst_arry_1( i_target,
                                          io_ccs_inst_cnt,
                                          num_idles_16,
                                          num_repeat_16,
                                          data_20,
                                          read_compare_1,
                                          rank_cal_4,
                                          ddr_cal_enable_1,
                                          ccs_end_1);
                        if(rc) return rc;
                        io_ccs_inst_cnt ++;
                    } // end mrs loop
            } // end rank loop

            // For LRDIMM  Set Rtt_nom, rtt_wr, driver impedance for R0 and R1
            if ( (dimm_type == fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM) && lrdimm_rank_mult_mode != 0 )
            {
                 rc = mss_lrdimm_mrs_load(i_target, i_port_number, dimm_number, io_ccs_inst_cnt);
                 if(rc) return rc;
            } // end LRDIMM 8R dir MRS 1

        } // end if has ranks
    } // end dimm loop

    return rc;
}

ReturnCode mss_assert_resetn (
            Target& i_target,
            uint8_t value
            )
{
// value of 1 deasserts reset

    ReturnCode rc;
    ReturnCode rc_buff;
    uint32_t rc_num = 0;
    ecmdDataBufferBase data_buffer(64);

    FAPI_INF( "+++++++++++++++++++++ ASSERTING RESETN to the value of %d +++++++++++++++++++++", value);

    rc = fapiGetScom(i_target, CCS_MODEQ_AB_REG_0x030106A7, data_buffer);
    if(rc) return rc;

    //Setting up CCS mode
    rc_num = rc_num | data_buffer.insert( value, 24, 1, 7); // use bit 7

    if (rc_num)
    {
        FAPI_ERR( "mss_assert_resetn: Error setting up buffers");
        rc_buff.setEcmdError(rc_num);
        return rc_buff;
    }

    rc = fapiPutScom(i_target, CCS_MODEQ_AB_REG_0x030106A7, data_buffer);
    if(rc) return rc;

    return rc;
}


} //end extern C

