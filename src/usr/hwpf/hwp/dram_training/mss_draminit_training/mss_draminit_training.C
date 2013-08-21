/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_training/mss_draminit_training.C $ */
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
// $Id: mss_draminit_training.C,v 1.64 2013/08/01 18:32:48 jdsloat Exp $
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|------------------------------------------------
//  1.64   | jdsloat  |01-AUG-13| Fixed dimm/rank conversion in address mirroring mode for a 4 rank dimm scenario
//  1.63   | jdsloat  |29-JUN-13| Added JTAG mode and CONTROL SWITCH attribute checks to bad bit mask function calls.
//  1.62   | mwuu     |17-JUN-13| Fixed set_bbm function to disable0,disable1,wr_clk registers
//         |          |         | In x4 single bit fails disables entire nibble in set/get_bbm FN
//  1.61   | jdsloat  |13-JUN-13| Added a single RC check
//  1.60   | jdsloat  |11-JUN-13| Added a single RC check
//  1.59   | jdsloat  |04-JUN-13| Added RC checks and port 1 to delay reset function
//  1.58   | jdsloat  |20-MAY-13| Added a delay reset function for multiple training runs
//         |          |         | changed mss_rtt_nom_rtt_wr_swap to use mirror mode function in mss_funcs
//         |          |         | changed mss_rtt_nom_rtt_wr_swap to only execute on ddr3
//         |          |         | Mirror mode keyed off of mba level mirror_mode attribute.
//  1.57   | jdsloat  |27-FEB-13| Added second workaround adjustment to waterfall problem in order to use 2 rank pairs.
//  1.56   | jdsloat  |27-FEB-13| Fixed rtt_nom and rtt_wr swap bug during condition of rtt_nom = diabled and rtt_wr = non-disabled
//         |          |         | Added workaround on a per quad resolution
//	   |          |         | Added workaround as a seperate sub
//	   |          |         | Added framework of binning workaround based on timing reference
//	   |          |         | Added putscom to enable spare cke mirroring
//  1.55   | jdsloat  |25-FEB-13| Added MBA/Port info to debug messages.
//  1.54   | jdsloat  |22-FEB-13| Edited WRITE_READ workaround to also edit DQSCLK PHASE
//  1.53   | jdsloat  |14-FEB-13| Fixed WRITE_READ workaround so it will execute in a partial substep case
//         |          |         | Edited mss_rtt_nom_rtt_wr_swap to only write rtt_nom with rtt_wr or supplied rtt_nom
//         |          |         | Moved location of mss_rtt_nom_rtt_wr_swap around wr_lvl substep
//         |          |         | Added Address Mirror Mode.
//  1.52   | jdsloat  |07-FEB-13| Fixed address typo for RP3 in WRITE_READ workaround.
//  1.51   | gollub   |31-JAN-13| Uncommenting mss_unmask_draminit_training_errors
//  1.50   | jdsloat  |16-JAN-13| Fixed rank group enable within PC_INIT_CAL reg
//  1.49   | jdsloat  |08-JAN-13| Added clearing RD PHASE SELECT values post Read Centering Workaround.
//  1.48   | jdsloat  |08-JAN-13| Cleared Cal Config in PC_INIT_CAL on opposing port.
//  1.47   | jdsloat  |08-JAN-13| Fixed port 1 cal setup RMW and fixed doing individual rank pairs.  Both in PC_INIT_CAL_CONFIG0 regs.
//  1.46   | jdsloat  |03-JAN-13| RM temp edits to CAL0q and CAL1q; Cleared INIT_CAL_STATUS and INIT_CAL_ERROR Regs before every subtest, edited debug messages
//  1.45   | gollub   |21-DEC-12| Calling mss_unmask_draminit_training_errors after mss_draminit_training_cloned
//  1.43   | jdsloat  |20-DEC-12| Temporarily disabled RTT_NOM swap
//  1.42   | bellows  |06-DEC-12| Fixed up review comments
//  1.41   | jdsloat  |02-DEC-12| Fixed RTT_NOM swap for Port 1
//  1.40   | jdsloat  |30-NOV-12| Temporarily comment Bad Bit Mask.
//  1.39   | jdsloat  |18-NOV-12| Fixed CAL_STEP to allow Zq Cal.
//  1.38   | jdsloat  |16-NOV-12| Fixed Error Place holder and port addressing with BBM
//  1.37   | jdsloat  |12-NOV-12| Fixed a bracket typo.
//  1.36   | jdsloat  |07-NOV-12| Changed procedure to proceed through ALL rank_pair, Ports before reporting
//         |          |         | error status for partial good support. Added Bad Bit Mask to disable regs function
//         |          |        //  1.57   | jdsloat  |27-FEB-13|  | and disable regs to Bad Bit Mask function.
//  1.35   | jdsloat  |08-OCT-12| Changed Write to Read,Modify,Write of Phy Init Cal Config Reg
//  1.34   | jdsloat  |25-SEP-12| Bit 0 of Cal Step Attribute now offers an all at once option - bit 0 =1 if stepbystep
//  1.33   | jdsloat  |07-SEP-12| Broke init_cal down to step by step keyed off of CAL_STEP_ENABLE attribute
//  1.32   | jdsloat  |29-AUG-12| Fixed mss_rtt_nom_rtt_wr_swap and verified with regression
//  1.31   | bellows  |28-AUG-12| Revert back to 1.29 until regression pass again
//  1.30   | jdsloat  |23-AUG-12| Added mss_rtt_nom_rtt_wr_swap pre and post init_cal
//  1.29   | bellows  |16-Jul-12| bellows | added in Id tag
//  1.28   | bellows  |02-May-12| cal ranks are 4 bits, this needed to be adjusted
//  1.26   | asaetow  |12-Apr-12| Added "if(rc) return rc;" at line 180.
//  1.25   | asaetow  |06-Apr-12| Added "if(rc) return rc;" at line 165.
//  1.24   | asaetow  |03-Apr-12| Changed FAPI_INF to FAPI_ERR where applicable from lines 275 to 324, per Mike Jones.
//  1.23   | asaetow  |29-Mar-12| Fixed FAPI_SET_HWP_ERROR using temp error callout RC_MSS_PLACE_HOLDER_ERROR.
//         |          |         | Changed uint32_t NUM_POLL to const.
//  1.22   | divyakum |29-Mar-12| Fixed rc assignment. Added comments for error handling.
//  1.21   | divyakum |06-Mar-12| Added cal status checking function.
//         |          |         | Fixed init cal issue via CCS to account for both ports.
//  1.20   | divyakum |         | Modified to execute CCS after every instruction.
//         |          |         | Added error checking for calibration. Needs cen_scom_addresses.H v.1.15 or newer.
//  1.19   | divyakum |01-Mar-12| Fixed ddr_cal_enable_buffer_1 value for ZQ cal long
//  1.18   | divyakum |29-Feb-12| Removed call to ccs_mode function. writing to scom directly
//         |          |         | Fixed wen_buffer value when re-issuing zqcal
//         |          |         | Fixed test_buffer value when re-issuing zqcal
//         |          |         | Added cen_scom_addresses.H in include
//  1.17   | divyakum |20-Feb-12| Adding comments to include i_target type
//  1.16   | divyakum |20-Feb-12| Replaced calls to insertFromBin with setHalfWord and setBit functions
//  1.15   | divyakum |14-Feb-12| Removed port field from mss_ccs_mode, mss_ccs_inst_arry_1, mss_execute_ccs_inst_array.
//         |          |         | NOTE: compatible with mss_funcs.H v1.19 or newer
//  1.14   | divyakum |10-Feb-12| Added/Modified error codes, var names and declarations to meet coding guidlines
//  1.13   | divyakum |08-Feb-12| Modified Attributes to FAPI attributes
//         |          |         | Added rc checking
//  1.12   | divyakum |31-Jan-12| Modified number of ports to work with Brent's userlevel.
//  1.11   | divyakum |20-Jan-12| Modified print messages. Fixed indentations
//  1.16   | divyakum |20-Jan-12| Fixed CCS func names to match mss_funcs.H ver 1.16
//         | divyakum |         | Added resetn initialization.
//  1.15   | bellows  |23-Dec-11| Set poll count to 100, set the end bit and when to execute the array time
//  1.14   | divyakum |21-Dec-11| Added more info prints. Fixed Execution of CCS
//  1.13   | bellows  |20-Dec-11| Fixed up rank loop so that it goes over both DIMMs
//  1.12   | jdsloat  |23-Nov-11| Incremented instruction number, added info messages
//  1.11   | jdsloat  |21-Nov-11| Got rid of GOTO argument in CCS cmds.
//  1.10   | divyakum |18-Nov-11| Fixed function calls to match procedure name.
//  1.9    | divyakum |11-Oct-11| Fix to include mss_funcs instead of cen_funcs.
//	   |          |         | Changed usage of array attributes.
//         |          |         | NOTE: Needs to be compiled with mss_funcs v1.3.
//  1.8    | divyakum |03-Oct-11| Removed primary_ranks_arrayvariable. Fixed rank loop for Socket1
//  1.7    | divyakum |30-Sep-11| First drop for Centaur. This code compiles
//  1.6    | divyakum |28-Sep-11| Added Error path with cal fails.
//         |          |         | Modified CCS_MODE, CCS_EXECUTE call
//  1.5    | divyakum |27-Sep-11| Updated code to match with cen_funcs.H v.1.5
//  1.4    | divyakum |27-Sep-11| Added capability to issue CCS cmds to a port pair where possible.
//  1.3    | divyakum |26-Sep-11| Added calls to attributes and CCS array for ZQ and initial calibrations.
//         |          |         | Added rank loopers.
//  1.2    | jdsloat  |14-Jul-11| Proper call name fix
//  1.1    | jdsloat  |22-Apr-11| Initial draft


//----------------------------------------------------------------------
//  FAPI function Includes
//----------------------------------------------------------------------

#include <fapi.H>

//----------------------------------------------------------------------
//  Centaur function Includes
//----------------------------------------------------------------------
#include <cen_scom_addresses.H>
#include <mss_funcs.H>
#include <dimmBadDqBitmapFuncs.H>
#include <mss_unmask_errors.H>

//------------End My Includes-------------------------------------------

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------
const uint8_t MRS1_BA = 1;
const uint8_t MRS2_BA = 2;

#define MAX_PORTS 2
#define MAX_PRI_RANKS 4
#define TOTAL_BYTES 10
#define BITS_PER_REG 16
#define DP18_INSTANCES 5
#define BITS_PER_PORT (BITS_PER_REG*DP18_INSTANCES)

//----------------------------------------------------------------------
//  Enums
//----------------------------------------------------------------------

enum mss_draminit_training_result
{
    MSS_INIT_CAL_COMPLETE = 1,
    MSS_INIT_CAL_PASS = 2,
    MSS_INIT_CAL_STALL = 3,
    MSS_INIT_CAL_FAIL = 4
};


extern "C" {

using namespace fapi;

ReturnCode mss_draminit_training(Target& i_target);
ReturnCode mss_draminit_training_cloned(Target& i_target);
ReturnCode mss_check_cal_status(Target& i_target, uint8_t i_mbaPosition, uint8_t i_port, uint8_t i_group,  mss_draminit_training_result& io_status);
ReturnCode mss_check_error_status(Target& i_target, uint8_t i_mbaPosition, uint8_t i_port, uint8_t i_group,  uint8_t cur_cal_step, mss_draminit_training_result& io_status);
ReturnCode mss_rtt_nom_rtt_wr_swap( Target& i_target, uint8_t i_mbaPosition, uint32_t i_port_number, uint8_t i_rank, uint32_t i_rank_pair_group, uint32_t& io_ccs_inst_cnt, uint8_t& io_dram_rtt_nom_original);
ReturnCode mss_read_center_workaround(Target& i_target, uint8_t i_mbaPosition, uint32_t i_port, uint32_t i_rank_group);
ReturnCode mss_read_center_second_workaround(Target& i_target);
ReturnCode mss_reset_delay_values(Target& i_target);

ReturnCode getC4dq2reg(const Target &i_mba, const uint8_t i_port, const uint8_t i_dimm, const uint8_t i_rank, ecmdDataBufferBase &o_reg);
ReturnCode setC4dq2reg(const Target &i_mba, const uint8_t i_port, const uint8_t i_dimm, const uint8_t i_rank, ecmdDataBufferBase &o_reg);
ReturnCode mss_set_bbm_regs (const fapi::Target & mba_target);
ReturnCode mss_get_bbm_regs (const fapi::Target & mba_target);


ReturnCode mss_draminit_training(Target& i_target)
{
    // Target is centaur.mba

    fapi::ReturnCode l_rc;

    l_rc = mss_reset_delay_values(i_target);
    if (l_rc)
    {
	return l_rc;
    }

    l_rc = mss_draminit_training_cloned(i_target);
    if (l_rc)
    {
	return l_rc;
    }

	// If mss_unmask_draminit_training_errors gets it's own bad rc,
	// it will commit the passed in rc (if non-zero), and return it's own bad rc.
	// Else if mss_unmask_draminit_training_errors runs clean,
	// it will just return the passed in rc.
	l_rc = mss_unmask_draminit_training_errors(i_target, l_rc);
    if (l_rc)
    {
	return l_rc;
    }

	return l_rc;
}




ReturnCode mss_draminit_training_cloned(Target& i_target)
{
    // Target is centaur.mba
    //Enums and Constants
    enum size
    {
       MAX_NUM_PORT = 2,
       MAX_NUM_DIMM = 2,
       MAX_NUM_GROUP = 4,
       MAX_CAL_STEPS = 7, //read course and write course will occur at the sametime
       INVALID = 255
    };

    const uint32_t NUM_POLL = 10000;

    ReturnCode rc;
    uint32_t rc_num = 0;

    //Issue ZQ Cal first per rank
    uint32_t instruction_number = 0;
    ecmdDataBufferBase address_buffer_16(16);
    rc_num = rc_num | address_buffer_16.flushTo0();
    ecmdDataBufferBase bank_buffer_8(8);
    rc_num = rc_num | bank_buffer_8.flushTo0();
    ecmdDataBufferBase activate_buffer_1(1);
    rc_num = rc_num | activate_buffer_1.flushTo0();
    ecmdDataBufferBase rasn_buffer_1(1);
    ecmdDataBufferBase casn_buffer_1(1);
    ecmdDataBufferBase wen_buffer_1(1);
    ecmdDataBufferBase cke_buffer_8(8);
    rc_num = rc_num | cke_buffer_8.flushTo1();
    ecmdDataBufferBase csn_buffer_8(8);
    rc_num = rc_num | csn_buffer_8.flushTo1();
    ecmdDataBufferBase odt_buffer_8(8);
    rc_num = rc_num | odt_buffer_8.flushTo0();
    ecmdDataBufferBase test_buffer_4(4);

    ecmdDataBufferBase num_idles_buffer_16(16);
    rc_num = rc_num | num_idles_buffer_16.flushTo1();
    ecmdDataBufferBase num_repeat_buffer_16(16);
    rc_num = rc_num | num_repeat_buffer_16.flushTo0();
    ecmdDataBufferBase data_buffer_20(20);
    rc_num = rc_num | data_buffer_20.flushTo0();
    ecmdDataBufferBase read_compare_buffer_1(1);
    rc_num = rc_num | read_compare_buffer_1.flushTo0();
    ecmdDataBufferBase rank_cal_buffer_4(4);
    rc_num = rc_num | rank_cal_buffer_4.flushTo0();
    ecmdDataBufferBase ddr_cal_enable_buffer_1(1);
    ecmdDataBufferBase ccs_end_buffer_1(1);
    rc_num = rc_num | ccs_end_buffer_1.flushTo1();


    ecmdDataBufferBase stop_on_err_buffer_1(1);
    rc_num = rc_num | stop_on_err_buffer_1.flushTo0();
    ecmdDataBufferBase cal_timeout_cnt_buffer_16(16);
    rc_num = rc_num | cal_timeout_cnt_buffer_16.flushTo1();
    ecmdDataBufferBase resetn_buffer_1(1);
    rc_num = rc_num | resetn_buffer_1.setBit(0);
    ecmdDataBufferBase cal_timeout_cnt_mult_buffer_2(2);
    rc_num = rc_num | cal_timeout_cnt_mult_buffer_2.flushTo1();

    ecmdDataBufferBase data_buffer_64(64);

    if(rc_num)
    {
        rc.setEcmdError(rc_num);
        return rc;
    }

    uint8_t port = 0;
    uint8_t group = 0;
    uint8_t primary_ranks_array[4][2]; //primary_ranks_array[group][port]
    uint8_t cal_steps = 0;
    uint8_t cur_cal_step = 0;
    ecmdDataBufferBase cal_steps_8(8);

    uint8_t l_nwell_misplacement = 0;
    uint8_t dram_rtt_nom_original = 0;

    fapi::Target l_target_centaur;
    rc = fapiGetParentChip(i_target, l_target_centaur);
    if(rc) return rc;

    uint8_t control_switch = 0;
    rc = FAPI_ATTR_GET(ATTR_MSS_CONTROL_SWITCH, NULL, control_switch);
    if(rc) return rc;

    uint8_t jtag_mode = 0;
    rc = FAPI_ATTR_GET(ATTR_LAB_USE_JTAG_MODE, NULL, jtag_mode);
    if(rc) return rc;

    uint8_t dram_gen = 0;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_GEN, &i_target, dram_gen);
    if(rc) return rc;

    uint8_t waterfall_broken = 0;
    rc = FAPI_ATTR_GET(ATTR_MSS_BLUEWATERFALL_BROKEN, &l_target_centaur, waterfall_broken);
    if(rc) return rc;

    enum mss_draminit_training_result cur_complete_status = MSS_INIT_CAL_COMPLETE;
    enum mss_draminit_training_result cur_error_status = MSS_INIT_CAL_PASS;

    enum mss_draminit_training_result complete_status = MSS_INIT_CAL_COMPLETE;
    enum mss_draminit_training_result error_status = MSS_INIT_CAL_PASS;

    //populate primary_ranks_arrays_array
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP0, &i_target, primary_ranks_array[0]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP1, &i_target, primary_ranks_array[1]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP2, &i_target, primary_ranks_array[2]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP3, &i_target, primary_ranks_array[3]);
    if(rc) return rc;

    rc = FAPI_ATTR_GET(ATTR_MSS_NWELL_MISPLACEMENT, &l_target_centaur, l_nwell_misplacement);
    if(rc) return rc;

    uint8_t mbaPosition;
    // Get MBA position: 0 = mba01, 1 = mba23
    rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target, mbaPosition);
    if(rc)
    {
        FAPI_ERR("Error getting MBA position");
        return rc;
    }



    //Get which training steps we are to run
    rc = FAPI_ATTR_GET(ATTR_MSS_CAL_STEP_ENABLE, &i_target, cal_steps);
    if(rc) return rc;
    rc_num = rc_num | cal_steps_8.insert(cal_steps, 0, 8, 0);


    //Setup SPARE CKE enable bit
    rc = fapiGetScom(i_target, MBA01_MBARPC0Q_0x03010434, data_buffer_64);
    if(rc) return rc;
    rc_num = rc_num | data_buffer_64.setBit(42);
    rc = fapiPutScom(i_target, MBA01_MBARPC0Q_0x03010434, data_buffer_64);
    if(rc) return rc;

    //Set up CCS Mode Reg for Init cal
    rc = fapiGetScom(i_target, MEM_MBA01_CCS_MODEQ_0x030106A7, data_buffer_64);
    if(rc) return rc;

    rc_num = rc_num | data_buffer_64.insert(stop_on_err_buffer_1, 0, 1, 0);
    rc_num = rc_num | data_buffer_64.insert(cal_timeout_cnt_buffer_16, 8, 16, 0);
    rc_num = rc_num | data_buffer_64.insert(resetn_buffer_1, 24, 1, 0);
    rc_num = rc_num | data_buffer_64.insert(cal_timeout_cnt_mult_buffer_2, 30, 2, 0);
    if(rc_num)
    {
        rc.setEcmdError(rc_num);
        return rc;
    }

    rc = fapiPutScom(i_target, MEM_MBA01_CCS_MODEQ_0x030106A7, data_buffer_64);
    if(rc) return rc;

    if ( ( control_switch && 0x01 ) && (jtag_mode == 0) )
    {
        rc = mss_set_bbm_regs (i_target);
        if(rc)
        {
	   FAPI_ERR( "Error Moving bad bit information to the Phy regs. Exiting.");
	   return rc;
        }
    }

    if ( ( cal_steps_8.isBitSet(0) ) ||
	 ( (cal_steps_8.isBitClear(0)) && (cal_steps_8.isBitClear(1)) &&
	   (cal_steps_8.isBitClear(2)) && (cal_steps_8.isBitClear(3)) &&
	   (cal_steps_8.isBitClear(4)) && (cal_steps_8.isBitClear(5)) &&
	   (cal_steps_8.isBitClear(6)) && (cal_steps_8.isBitClear(7)) ))
    {
	FAPI_INF( "Performing External ZQ Calibration on %s.", i_target.toEcmdString());

        //Execute ZQ_CAL
	for(port = 0; port < MAX_NUM_PORT; port++)
	{
	    rc = mss_execute_zq_cal(i_target, port);
	    if(rc) return rc;
	}

    }

    for(port = 0; port < MAX_NUM_PORT; port++)
    {

	for(group = 0; group < MAX_NUM_GROUP; group++)
	{

	    //Check if rank group exists
	    if(primary_ranks_array[group][port] != INVALID)
	    {

	        //Set up for Init Cal - Done per port pair
		rc_num = rc_num | test_buffer_4.setBit(0, 2); //Init Cal test = 11XX
		rc_num = rc_num | wen_buffer_1.flushTo1(); //Init Cal ras/cas/we = 1/1/1
		rc_num = rc_num | casn_buffer_1.flushTo1();
		rc_num = rc_num | rasn_buffer_1.flushTo1();
		rc_num = rc_num | ddr_cal_enable_buffer_1.flushTo1(); //Init cal

		FAPI_INF( "+++ Setting up Init Cal on %s Port: %d rank group: %d cal_steps: 0x%02X +++", i_target.toEcmdString(), port, group, cal_steps);

		for(cur_cal_step = 1; cur_cal_step < MAX_CAL_STEPS; cur_cal_step++) //Cycle through all possible cal steps
		{

		    //Clearing any status or errors bits that may have occured in previous training subtest.
		    if(port == 0)
		    {
			//clear status reg
			rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_STATUS_P0_0x8000C0190301143F, data_buffer_64);
			if(rc) return rc;
			rc_num = rc_num | data_buffer_64.clearBit(48, 4);
			rc = fapiPutScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_STATUS_P0_0x8000C0190301143F, data_buffer_64);
			if(rc) return rc;

			//clear error reg
			rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_ERROR_P0_0x8000C0180301143F, data_buffer_64);
			if(rc) return rc;
			rc_num = rc_num | data_buffer_64.clearBit(48, 11);
			rc_num = rc_num | data_buffer_64.clearBit(60, 4);
			rc = fapiPutScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_ERROR_P0_0x8000C0180301143F, data_buffer_64);
			if(rc) return rc;

                        //clear other port
			rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_CONFIG0_P1_0x8001C0160301143F, data_buffer_64);
			if(rc) return rc;
			rc_num = rc_num | data_buffer_64.clearBit(48);
			rc_num = rc_num | data_buffer_64.clearBit(50);
			rc_num = rc_num | data_buffer_64.clearBit(51);
			rc_num = rc_num | data_buffer_64.clearBit(52);
			rc_num = rc_num | data_buffer_64.clearBit(53);
			rc_num = rc_num | data_buffer_64.clearBit(54);
			rc_num = rc_num | data_buffer_64.clearBit(55);
			rc_num = rc_num | data_buffer_64.clearBit(58);
			rc_num = rc_num | data_buffer_64.clearBit(60);
			rc_num = rc_num | data_buffer_64.clearBit(61);
			rc_num = rc_num | data_buffer_64.clearBit(62);
			rc_num = rc_num | data_buffer_64.clearBit(63);
			rc = fapiPutScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_CONFIG0_P1_0x8001C0160301143F, data_buffer_64);
			if(rc) return rc;

		        //Setup the Config Reg bit for the only cal step we want
			rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_CONFIG0_P0_0x8000C0160301143F, data_buffer_64);
			if(rc) return rc;

		    }
		    else
		    {
			//clear status reg
			rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_STATUS_P1_0x8001C0190301143F, data_buffer_64);
			if(rc) return rc;
			rc_num = rc_num | data_buffer_64.clearBit(48, 4);
			rc = fapiPutScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_STATUS_P1_0x8001C0190301143F, data_buffer_64);
			if(rc) return rc;

			//clear error reg
			rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_ERROR_P1_0x8001C0180301143F, data_buffer_64);
			if(rc) return rc;
			rc_num = rc_num | data_buffer_64.clearBit(48, 11);
			rc_num = rc_num | data_buffer_64.clearBit(60, 4);
			rc = fapiPutScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_ERROR_P1_0x8001C0180301143F, data_buffer_64);
			if(rc) return rc;

                        //clear other port
			rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_CONFIG0_P0_0x8000C0160301143F, data_buffer_64);
			if(rc) return rc;
			rc_num = rc_num | data_buffer_64.clearBit(48);
			rc_num = rc_num | data_buffer_64.clearBit(50);
			rc_num = rc_num | data_buffer_64.clearBit(51);
			rc_num = rc_num | data_buffer_64.clearBit(52);
			rc_num = rc_num | data_buffer_64.clearBit(53);
			rc_num = rc_num | data_buffer_64.clearBit(54);
			rc_num = rc_num | data_buffer_64.clearBit(55);
			rc_num = rc_num | data_buffer_64.clearBit(58);
			rc_num = rc_num | data_buffer_64.clearBit(60);
			rc_num = rc_num | data_buffer_64.clearBit(61);
			rc_num = rc_num | data_buffer_64.clearBit(62);
			rc_num = rc_num | data_buffer_64.clearBit(63);
			rc = fapiPutScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_CONFIG0_P0_0x8000C0160301143F, data_buffer_64);
			if(rc) return rc;

		        //Setup the Config Reg bit for the only cal step we want
			rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_CONFIG0_P1_0x8001C0160301143F, data_buffer_64);
			if(rc) return rc;

		    }

		    //Clear training cnfg
		    rc_num = rc_num | data_buffer_64.clearBit(48);
		    rc_num = rc_num | data_buffer_64.clearBit(50);
		    rc_num = rc_num | data_buffer_64.clearBit(51);
		    rc_num = rc_num | data_buffer_64.clearBit(52);
		    rc_num = rc_num | data_buffer_64.clearBit(53);
		    rc_num = rc_num | data_buffer_64.clearBit(54);
		    rc_num = rc_num | data_buffer_64.clearBit(55);
		    rc_num = rc_num | data_buffer_64.clearBit(60);
		    rc_num = rc_num | data_buffer_64.clearBit(61);
		    rc_num = rc_num | data_buffer_64.clearBit(62);
		    rc_num = rc_num | data_buffer_64.clearBit(63);

		    //Set stop on error
		    rc_num = rc_num | data_buffer_64.setBit(58);

		    //cnfg rank groups
		    if(group == 0){
			rc_num = rc_num | data_buffer_64.setBit(60);
		    }
		    else if(group == 1){
			rc_num = rc_num | data_buffer_64.setBit(61);
		    }
		    else if(group == 2){
			rc_num = rc_num | data_buffer_64.setBit(62);
		    }
		    else if(group == 3){
			rc_num = rc_num | data_buffer_64.setBit(63);
		    }

		    if ( (cur_cal_step == 1) && (cal_steps_8.isBitClear(0)) && (cal_steps_8.isBitClear(1)) &&
			 (cal_steps_8.isBitClear(2)) && (cal_steps_8.isBitClear(3)) &&
			 (cal_steps_8.isBitClear(4)) && (cal_steps_8.isBitClear(5)) &&
			 (cal_steps_8.isBitClear(6)) && (cal_steps_8.isBitClear(7)) )
		    {
			FAPI_INF( "+++ Executing ALL Cal Steps at the same time on %s Port: %d rank group: %d +++", i_target.toEcmdString(), port, group);
			rc_num = rc_num | data_buffer_64.setBit(48);
			rc_num = rc_num | data_buffer_64.setBit(50);
			rc_num = rc_num | data_buffer_64.setBit(51);
			rc_num = rc_num | data_buffer_64.setBit(52);
			rc_num = rc_num | data_buffer_64.setBit(53);
			rc_num = rc_num | data_buffer_64.setBit(54);
			rc_num = rc_num | data_buffer_64.setBit(55);
		    }
		    else if ( (cur_cal_step == 1) && (cal_steps_8.isBitSet(1)) )
		    {
			FAPI_INF( "+++ Write Leveling (WR_LVL) on %s Port %d rank group: %d +++", i_target.toEcmdString(), port, group);
			rc_num = rc_num | data_buffer_64.setBit(48);
		    }
		    else if ( (cur_cal_step == 2) && (cal_steps_8.isBitSet(2)) )
		    {
			FAPI_INF( "+++ DQS Align (DQS_ALIGN) on %s Port: %d rank group: %d +++", i_target.toEcmdString(), port, group);
			rc_num = rc_num | data_buffer_64.setBit(50);
		    }
		    else if ( (cur_cal_step == 3) && (cal_steps_8.isBitSet(3)) )
		    {
			FAPI_INF( "+++ RD CLK Align (RDCLK_ALIGN) on %s Port: %d rank group: %d +++", i_target.toEcmdString(), port, group);
			rc_num = rc_num | data_buffer_64.setBit(51);
		    }
		    else if ( (cur_cal_step == 4) && (cal_steps_8.isBitSet(4)) )
		    {
			FAPI_INF( "+++ Read Centering (READ_CTR) on %s Port: %d rank group: %d +++", i_target.toEcmdString(), port, group);
			rc_num = rc_num | data_buffer_64.setBit(52);
		    }
		    else if ( (cur_cal_step == 5) && (cal_steps_8.isBitSet(5)) )
		    {
			FAPI_INF( "+++ Write Centering (WRITE_CTR) on %s Port: %d rank group: %d +++", i_target.toEcmdString(), port, group);
			rc_num = rc_num | data_buffer_64.setBit(53);
		    }
		    else if ( (cur_cal_step == 6) && (cal_steps_8.isBitSet(6)) && (cal_steps_8.isBitClear(7)) )
		    {
			FAPI_INF( "+++ Initial Course Write (COURSE_WR) on %s Port: %d rank group: %d +++", i_target.toEcmdString(), port, group);
			rc_num = rc_num | data_buffer_64.setBit(54);
		    }
		    else if ( (cur_cal_step == 6) && (cal_steps_8.isBitClear(6)) && (cal_steps_8.isBitSet(7)) )
		    {
			FAPI_INF( "+++ Course Read (COURSE_RD) on %s Port: %d rank group: %d +++", i_target.toEcmdString(), port, group);
			rc_num = rc_num | data_buffer_64.setBit(55);
		    }
		    else if ( (cur_cal_step == 6) && (cal_steps_8.isBitSet(6)) && (cal_steps_8.isBitSet(7)) )
		    {
			FAPI_INF( "+++ Initial Course Write (COURSE_WR) and Course Read (COURSE_RD) simultaneously on %s Port: %d rank group: %d +++", i_target.toEcmdString(), port, group);
			rc_num = rc_num | data_buffer_64.setBit(54);
			rc_num = rc_num | data_buffer_64.setBit(55);
		    }

		    if(rc_num)
		    {
			rc.setEcmdError(rc_num);
			return rc;
		    }

		    if ( !( data_buffer_64.isBitClear(48, 8) ) ) // Only execute if we are doing a Cal Step
		    {

		        // Before WR_LVL --- Change the RTT_NOM to RTT_WR pre-WR_LVL
			if ( (cur_cal_step == 1) && (dram_gen == ENUM_ATTR_EFF_DRAM_GEN_DDR3))
			{
			    dram_rtt_nom_original = 0xFF;
			    rc = mss_rtt_nom_rtt_wr_swap(i_target,
							 mbaPosition,
							 port,
							 primary_ranks_array[group][port],
							 group,
							 instruction_number,
							 dram_rtt_nom_original);
			    if(rc) return rc;
			}


		        //Set the config register
			if(port == 0)
			{
			    rc = fapiPutScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_CONFIG0_P0_0x8000C0160301143F, data_buffer_64);
			    if(rc) return rc;
			}
			else
			{
			    rc = fapiPutScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_CONFIG0_P1_0x8001C0160301143F, data_buffer_64);
			    if(rc) return rc;
			}

			rc = mss_ccs_inst_arry_0(i_target,
						 instruction_number,
						 address_buffer_16,
						 bank_buffer_8,
						 activate_buffer_1,
						 rasn_buffer_1,
						 casn_buffer_1,
						 wen_buffer_1,
						 cke_buffer_8,
						 csn_buffer_8,
						 odt_buffer_8,
						 test_buffer_4,
						 port);

			if(rc) return rc; //Error handling for mss_ccs_inst built into mss_funcs

			FAPI_INF( "primary_ranks_array[%d][0]: %d [%d][1]: %d", group, primary_ranks_array[group][0], group, primary_ranks_array[group][1]);


			rc_num = rc_num | rank_cal_buffer_4.insert(primary_ranks_array[group][port], 0, 4, 4); // 8 bit storage, need last 4 bits
			if(rc_num)
			{
				rc.setEcmdError(rc_num);
				return rc;
			}

			rc = mss_ccs_inst_arry_1(i_target,
						 instruction_number,
						 num_idles_buffer_16,
						 num_repeat_buffer_16,
						 data_buffer_20,
						 read_compare_buffer_1,
						 rank_cal_buffer_4,
						 ddr_cal_enable_buffer_1,
						 ccs_end_buffer_1);

			if(rc) return rc; //Error handling for mss_ccs_inst built into mss_funcs


			rc = mss_execute_ccs_inst_array( i_target, NUM_POLL, 60);
			if(rc) return rc; //Error handling for mss_ccs_inst built into mss_funcs

			//Check to see if the training completes
			rc = mss_check_cal_status(i_target, mbaPosition, port, group, cur_complete_status);
			if(rc) return rc;

			if (cur_complete_status == MSS_INIT_CAL_STALL)
			{
			    complete_status = cur_complete_status;
			}

			//Check to see if the training errored out
			rc = mss_check_error_status(i_target, mbaPosition, port, group, cur_cal_step, cur_error_status);
			if(rc) return rc;

			if (cur_error_status == MSS_INIT_CAL_FAIL)
			{
			    error_status = cur_error_status;
			}

			// Following WR_LVL -- Restore RTT_NOM to orignal value post-wr_lvl
			if ((cur_cal_step == 1) && (dram_gen == ENUM_ATTR_EFF_DRAM_GEN_DDR3))
			{
			    rc = mss_rtt_nom_rtt_wr_swap(i_target,
							 mbaPosition,
							 port,
							 primary_ranks_array[group][port],
							 group,
							 instruction_number,
							 dram_rtt_nom_original);
			    if(rc) return rc;

			}

			// Following Read Centering -- Enter into READ CENTERING WORKAROUND
			if  ( (cur_cal_step == 4) &&
			    ( waterfall_broken == fapi::ENUM_ATTR_MSS_BLUEWATERFALL_BROKEN_TRUE  ) )
			{
				rc = mss_read_center_workaround(i_target, mbaPosition, port, group);
      		    if(rc) return rc;
			}
		    }
		}//end of step loop
	    }
	}//end of group loop
    }//end of port loop

    // Make sure the DQS_CLK values of each byte have matching nibble values, using the lowest
    if ( waterfall_broken == fapi::ENUM_ATTR_MSS_BLUEWATERFALL_BROKEN_TRUE )
    {
		rc = mss_read_center_second_workaround(i_target);
		if(rc) return rc;
    }

    if ( ( control_switch && 0x01 ) && (jtag_mode == 0) )
    {
    	rc = mss_get_bbm_regs(i_target);
    	if(rc)
	{
		FAPI_ERR( "Error Moving bad bit information from the Phy regs. Exiting.");
		return rc;
	}
    }

    if (complete_status == MSS_INIT_CAL_STALL)
    {
	FAPI_ERR( "+++ Partial/Full calibration stall. Check Debug trace. +++");
	FAPI_SET_HWP_ERROR(rc, RC_MSS_DRAMINIT_TRAINING_INIT_CAL_STALLED);
    }
    else if (error_status == MSS_INIT_CAL_FAIL)
    {
	FAPI_ERR( "+++ Partial/Full calibration fail. Check Debug trace. +++");
	FAPI_SET_HWP_ERROR(rc, RC_MSS_DRAMINIT_TRAINING_INIT_CAL_FAILED);
    }
    else
    {
	FAPI_INF( "+++ Full calibration successful. +++");
    }

    return rc;
}

ReturnCode mss_check_cal_status( Target& i_target,
				 uint8_t i_mbaPosition,
                                 uint8_t i_port,
                                 uint8_t i_group,
				 mss_draminit_training_result& io_status
                               )
{
    ecmdDataBufferBase cal_status_buffer_64(64);

    uint8_t poll_count = 1;
    uint32_t cal_status_reg_offset;

    cal_status_reg_offset = 48 + i_group;

    ReturnCode rc;

    if(i_port == 0)
    {
        rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_STATUS_P0_0x8000C0190301143F, cal_status_buffer_64);
        if(rc) return rc;
    }
    else
    {
        rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_STATUS_P1_0x8001C0190301143F, cal_status_buffer_64);
        if(rc) return rc;
    }

    while((!cal_status_buffer_64.isBitSet(cal_status_reg_offset)) &&
          (poll_count <= 20))
    {
        FAPI_INF( "+++ Calibration on %s port: %d rank group: %d in progress. Poll count: %d +++", i_target.toEcmdString(), i_port, i_group, poll_count);

        poll_count++;
        if(i_port == 0)
        {
            rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_STATUS_P0_0x8000C0190301143F, cal_status_buffer_64);
            if(rc) return rc;
        }
        else
        {
            rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_STATUS_P1_0x8001C0190301143F, cal_status_buffer_64);
            if(rc) return rc;
        }

    }

    if(cal_status_buffer_64.isBitSet(cal_status_reg_offset))
    {
	FAPI_INF( "+++ Calibration on %s port: %d rank group: %d finished. +++", i_target.toEcmdString(), i_port, i_group);
	io_status = MSS_INIT_CAL_COMPLETE;
    }
    else
    {
	FAPI_ERR( "+++ Calibration on %s port: %d rank group: %d has stalled! +++", i_target.toEcmdString(), i_port, i_group);
	io_status = MSS_INIT_CAL_STALL;
    }

    return rc;
}

ReturnCode mss_check_error_status( Target& i_target,
				 uint8_t i_mbaPosition,
                                 uint8_t i_port,
                                 uint8_t i_group,
				 uint8_t cur_cal_step,
				  mss_draminit_training_result& io_status
                               )
{

    ecmdDataBufferBase cal_error_buffer_64(64);
    ReturnCode rc;

    if(i_port == 0)
    {
        rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_ERROR_P0_0x8000C0180301143F, cal_error_buffer_64);
        if(rc) return rc;
    }
    else
    {
        rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_ERROR_P1_0x8001C0180301143F, cal_error_buffer_64);
        if(rc) return rc;
    }

    if((cal_error_buffer_64.isBitSet(60)) || (cal_error_buffer_64.isBitSet(61)) || (cal_error_buffer_64.isBitSet(62)) || (cal_error_buffer_64.isBitSet(63)))
    {
	io_status = MSS_INIT_CAL_FAIL;

        if(cal_error_buffer_64.isBitSet(48))
        {
            FAPI_ERR( "+++ Write leveling error occured on %s port: %d rank group: %d! +++", i_target.toEcmdString(), i_port, i_group);
        }
        if(cal_error_buffer_64.isBitSet(50))
        {
            FAPI_ERR( "+++ DQS Alignment error occured on %s port: %d rank group: %d! +++", i_target.toEcmdString(), i_port, i_group);
        }
        if(cal_error_buffer_64.isBitSet(51))
        {
            FAPI_ERR( "+++ RDCLK to SysClk alignment error occured on %s port: %d rank group: %d! +++", i_target.toEcmdString(), i_port, i_group);
        }
        if(cal_error_buffer_64.isBitSet(52))
        {
            FAPI_ERR( "+++ Read centering error occured on %s port: %d rank group: %d! +++", i_target.toEcmdString(), i_port, i_group);
        }
        if(cal_error_buffer_64.isBitSet(53))
        {
            FAPI_ERR( "+++ Write centering error occured on %s port: %d rank group: %d! +++", i_target.toEcmdString(), i_port, i_group);
        }
        if(cal_error_buffer_64.isBitSet(55))
        {
            FAPI_ERR( "+++ Coarse read centering error occured on %s port: %d rank group: %d! +++", i_target.toEcmdString(), i_port, i_group);
        }
        if(cal_error_buffer_64.isBitSet(56))
        {
            FAPI_ERR( "+++ Custom pattern read centering error occured on %s port: %d rank group: %d! +++", i_target.toEcmdString(), i_port, i_group);
        }
        if(cal_error_buffer_64.isBitSet(57))
        {
            FAPI_ERR( "+++ Custom pattern write centering error occured on %s port: %d rank group: %d! +++", i_target.toEcmdString(), i_port, i_group);
        }
        if(cal_error_buffer_64.isBitSet(58))
        {
            FAPI_ERR( "+++ Digital eye error occured on %s port: %d rank group: %d! +++", i_target.toEcmdString(), i_port, i_group);
        }
    }
    else
    {
  	if (cur_cal_step == 1)
	{
	    FAPI_INF( "+++ Write_leveling on %s port: %d rank group: %d was successful. +++", i_target.toEcmdString(), i_port, i_group);
	}
	else if (cur_cal_step == 2)
	{
	    FAPI_INF( "+++ DQS Alignment on %s port: %d rank group: %d was successful. +++", i_target.toEcmdString(), i_port, i_group);
	}
	else if (cur_cal_step == 3)
	{
	    FAPI_INF( "+++ RDCLK to SysClk alignment on %s port: %d rank group: %d was successful. +++", i_target.toEcmdString(), i_port, i_group);
	}
	else if (cur_cal_step == 4)
	{
	    FAPI_INF( "+++ Read Centering on %s port: %d rank group: %d was successful. +++", i_target.toEcmdString(), i_port, i_group);
	}
	else if (cur_cal_step == 5)
	{
	    FAPI_INF( "+++ Write Centering on %s port: %d rank group: %d was successful. +++", i_target.toEcmdString(), i_port, i_group);
	}
	else if (cur_cal_step == 6)
	{
	    FAPI_INF( "+++ Course Read and/or Course Write on %s port: %d rank group: %d was successful. +++", i_target.toEcmdString(), i_port, i_group);
	}

	io_status = MSS_INIT_CAL_PASS;
    }

    return rc;
}

ReturnCode mss_read_center_workaround(
            Target& i_target,
            uint8_t i_mbaPosition,
            uint32_t i_port,
	    uint32_t i_rank_group
            )
{

    ReturnCode rc;
    uint32_t rc_num = 0;
    ecmdDataBufferBase data_buffer_64(64);


    uint64_t DQSCLK_RD_PHASE_ADDR_0 = 0;
    uint64_t DQSCLK_RD_PHASE_ADDR_1 = 0;
    uint64_t DQSCLK_RD_PHASE_ADDR_2 = 0;
    uint64_t DQSCLK_RD_PHASE_ADDR_3 = 0;
    uint64_t DQSCLK_RD_PHASE_ADDR_4 = 0;
    uint64_t RD_TIMING_REF0_ADDR_0 = 0;
    uint64_t RD_TIMING_REF0_ADDR_1 = 0;
    uint64_t RD_TIMING_REF0_ADDR_2 = 0;
    uint64_t RD_TIMING_REF0_ADDR_3 = 0;
    uint64_t RD_TIMING_REF0_ADDR_4 = 0;
    uint64_t RD_TIMING_REF1_ADDR_0 = 0;
    uint64_t RD_TIMING_REF1_ADDR_1 = 0;
    uint64_t RD_TIMING_REF1_ADDR_2 = 0;
    uint64_t RD_TIMING_REF1_ADDR_3 = 0;
    uint64_t RD_TIMING_REF1_ADDR_4 = 0;
    uint8_t l_value_u8 = 0;
    uint8_t l_new_value_u8 = 0;
    uint8_t quad0_workaround_type = 2;
    uint8_t quad1_workaround_type = 2;
    uint8_t quad2_workaround_type = 2;
    uint8_t quad3_workaround_type = 2;
    uint8_t dqs_clk_increment_wa0 = 0;
    uint8_t dqs_clk_increment_wa1 = 3;
    uint8_t dqs_clk_increment_wa2 = 2;
    uint8_t read_phase_value_wa0 = 0;
    uint8_t read_phase_value_wa1 = 0;
    uint8_t read_phase_value_wa2 = 0;
    uint8_t dqs_clk_increment_quad0 = 2;
    uint8_t dqs_clk_increment_quad1 = 2;
    uint8_t dqs_clk_increment_quad2 = 2;
    uint8_t dqs_clk_increment_quad3 = 2;
    uint8_t read_phase_value_quad0 = 0;
    uint8_t read_phase_value_quad1 = 0;
    uint8_t read_phase_value_quad2 = 0;
    uint8_t read_phase_value_quad3 = 0;
    uint8_t l_timing_ref_quad0 = 0;
    uint8_t l_timing_ref_quad1 = 0;
    uint8_t l_timing_ref_quad2 = 0;
    uint8_t l_timing_ref_quad3 = 0;

    FAPI_INF( "+++ Read Centering Workaround on %s Port: %d rank group: %d +++", i_target.toEcmdString(), i_port, i_rank_group);
    FAPI_INF( "+++ Choosing New RD PHASE SELECT values based on timing values. +++");
    FAPI_INF( "+++ Incrementing DQS CLK PHASE SELECT regs based on timing values. +++");

    if ( i_port == 0 )
    {

	RD_TIMING_REF0_ADDR_0 = DPHY01_DDRPHY_DP18_READ_TIMING_REFERENCE0_P0_0_0x800000700301143F;
	RD_TIMING_REF0_ADDR_1 = DPHY01_DDRPHY_DP18_READ_TIMING_REFERENCE0_P0_1_0x800004700301143F;
	RD_TIMING_REF0_ADDR_2 = DPHY01_DDRPHY_DP18_READ_TIMING_REFERENCE0_P0_2_0x800008700301143F;
	RD_TIMING_REF0_ADDR_3 = DPHY01_DDRPHY_DP18_READ_TIMING_REFERENCE0_P0_3_0x80000C700301143F;
	RD_TIMING_REF0_ADDR_4 = DPHY01_DDRPHY_DP18_READ_TIMING_REFERENCE0_P0_4_0x800010700301143F;
	RD_TIMING_REF1_ADDR_0 = DPHY01_DDRPHY_DP18_READ_TIMING_REFERENCE1_P0_0_0x800000710301143F;
	RD_TIMING_REF1_ADDR_1 = DPHY01_DDRPHY_DP18_READ_TIMING_REFERENCE1_P0_1_0x800004710301143F;
	RD_TIMING_REF1_ADDR_2 = DPHY01_DDRPHY_DP18_READ_TIMING_REFERENCE1_P0_2_0x800008710301143F;
	RD_TIMING_REF1_ADDR_3 = DPHY01_DDRPHY_DP18_READ_TIMING_REFERENCE1_P0_3_0x80000C710301143F;
	RD_TIMING_REF1_ADDR_4 = DPHY01_DDRPHY_DP18_READ_TIMING_REFERENCE1_P0_4_0x800010710301143F;

	if ( i_rank_group == 0 )
	{
	    DQSCLK_RD_PHASE_ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0_0x800000090301143F;
	    DQSCLK_RD_PHASE_ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_1_0x800004090301143F;
	    DQSCLK_RD_PHASE_ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_2_0x800008090301143F;
	    DQSCLK_RD_PHASE_ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_3_0x80000C090301143F;
	    DQSCLK_RD_PHASE_ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_4_0x800010090301143F;

	}
	else if ( i_rank_group == 1 )
	{
	    DQSCLK_RD_PHASE_ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_0_0x800001090301143F;
	    DQSCLK_RD_PHASE_ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_1_0x800005090301143F;
	    DQSCLK_RD_PHASE_ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_2_0x800009090301143F;
	    DQSCLK_RD_PHASE_ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_3_0x80000D090301143F;
	    DQSCLK_RD_PHASE_ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_4_0x800011090301143F;

	}
	else if ( i_rank_group == 2 )
	{
	    DQSCLK_RD_PHASE_ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_0_0x800002090301143F;
	    DQSCLK_RD_PHASE_ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_1_0x800006090301143F;
	    DQSCLK_RD_PHASE_ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_2_0x80000A090301143F;
	    DQSCLK_RD_PHASE_ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_3_0x80000E090301143F;
	    DQSCLK_RD_PHASE_ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_4_0x800012090301143F;

	}
	else if ( i_rank_group == 3 )
	{
	    DQSCLK_RD_PHASE_ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_0_0x800003090301143F;
	    DQSCLK_RD_PHASE_ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_1_0x800007090301143F;
	    DQSCLK_RD_PHASE_ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_2_0x80000B090301143F;
	    DQSCLK_RD_PHASE_ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_3_0x80000F090301143F;
	    DQSCLK_RD_PHASE_ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_4_0x800013090301143F;

	}
    }
    else if (i_port == 1 )
    {

	RD_TIMING_REF0_ADDR_0 = DPHY01_DDRPHY_DP18_READ_TIMING_REFERENCE0_P1_0_0x800100700301143F;
	RD_TIMING_REF0_ADDR_1 = DPHY01_DDRPHY_DP18_READ_TIMING_REFERENCE0_P1_1_0x800104700301143F;
	RD_TIMING_REF0_ADDR_2 = DPHY01_DDRPHY_DP18_READ_TIMING_REFERENCE0_P1_2_0x800108700301143F;
	RD_TIMING_REF0_ADDR_3 = DPHY01_DDRPHY_DP18_READ_TIMING_REFERENCE0_P1_3_0x80010C700301143F;
	RD_TIMING_REF0_ADDR_4 = DPHY01_DDRPHY_DP18_READ_TIMING_REFERENCE0_P1_4_0x800110700301143F;
	RD_TIMING_REF1_ADDR_0 = DPHY01_DDRPHY_DP18_READ_TIMING_REFERENCE1_P1_0_0x800100710301143F;
	RD_TIMING_REF1_ADDR_1 = DPHY01_DDRPHY_DP18_READ_TIMING_REFERENCE1_P1_1_0x800104710301143F;
	RD_TIMING_REF1_ADDR_2 = DPHY01_DDRPHY_DP18_READ_TIMING_REFERENCE1_P1_2_0x800108710301143F;
	RD_TIMING_REF1_ADDR_3 = DPHY01_DDRPHY_DP18_READ_TIMING_REFERENCE1_P1_3_0x80010C710301143F;
	RD_TIMING_REF1_ADDR_4 = DPHY01_DDRPHY_DP18_READ_TIMING_REFERENCE1_P1_4_0x800110710301143F;

	if ( i_rank_group == 0 )
	{
	    DQSCLK_RD_PHASE_ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_0_0x800100090301143F;
	    DQSCLK_RD_PHASE_ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_1_0x800104090301143F;
	    DQSCLK_RD_PHASE_ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_2_0x800108090301143F;
	    DQSCLK_RD_PHASE_ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_3_0x80010C090301143F;
	    DQSCLK_RD_PHASE_ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_4_0x800110090301143F;

	}
	else if ( i_rank_group == 1 )
	{
	    DQSCLK_RD_PHASE_ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P1_0_0x800101090301143F;
	    DQSCLK_RD_PHASE_ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P1_1_0x800105090301143F;
	    DQSCLK_RD_PHASE_ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P1_2_0x800109090301143F;
	    DQSCLK_RD_PHASE_ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P1_3_0x80010D090301143F;
	    DQSCLK_RD_PHASE_ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P1_4_0x800111090301143F;


	}
	else if ( i_rank_group == 2 )
	{
	    DQSCLK_RD_PHASE_ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P1_0_0x800102090301143F;
	    DQSCLK_RD_PHASE_ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P1_1_0x800106090301143F;
	    DQSCLK_RD_PHASE_ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P1_2_0x80010A090301143F;
	    DQSCLK_RD_PHASE_ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P1_3_0x80010E090301143F;
	    DQSCLK_RD_PHASE_ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P1_4_0x800112090301143F;

	}
	else if ( i_rank_group == 3 )
	{
	    DQSCLK_RD_PHASE_ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P1_0_0x800103090301143F;
	    DQSCLK_RD_PHASE_ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P1_1_0x800107090301143F;
	    DQSCLK_RD_PHASE_ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P1_2_0x80010B090301143F;
	    DQSCLK_RD_PHASE_ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P1_3_0x80010F090301143F;
	    DQSCLK_RD_PHASE_ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P1_4_0x800113090301143F;

	}
    }

    //Block 0
    rc = fapiGetScom(i_target, RD_TIMING_REF0_ADDR_0, data_buffer_64);
    if (rc) return rc;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_timing_ref_quad0, 49, 7);
    rc_num = rc_num | data_buffer_64.extractToRight(&l_timing_ref_quad1, 57, 7);
    rc = fapiGetScom(i_target, RD_TIMING_REF1_ADDR_0, data_buffer_64);
    if (rc) return rc;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_timing_ref_quad2, 49, 7);
    rc_num = rc_num | data_buffer_64.extractToRight(&l_timing_ref_quad3, 57, 7);

	if(rc_num)
	{
	rc.setEcmdError(rc_num);
	return rc;
	}

    if ( quad0_workaround_type == 0 )
    {
	dqs_clk_increment_quad0 = dqs_clk_increment_wa0;
	read_phase_value_quad0 = read_phase_value_wa0;
    }
    else if ( quad0_workaround_type == 1 )
    {
	dqs_clk_increment_quad0 = dqs_clk_increment_wa1;
	read_phase_value_quad0 = read_phase_value_wa1;
    }
    else if ( quad0_workaround_type == 2 )
    {
	dqs_clk_increment_quad0 = dqs_clk_increment_wa2;
	read_phase_value_quad0 = read_phase_value_wa2;
    }
    FAPI_INF( "+++ ALL Blocks ALL Quads using workaround number %d with dqs_clk_increment: %d read_phase_value: %d +++", quad0_workaround_type, dqs_clk_increment_quad0, read_phase_value_quad0);

    if ( quad1_workaround_type == 0 )
    {
	dqs_clk_increment_quad1 = dqs_clk_increment_wa0;
	read_phase_value_quad1 = read_phase_value_wa0;
    }
    else if ( quad1_workaround_type == 1 )
    {
	dqs_clk_increment_quad1 = dqs_clk_increment_wa1;
	read_phase_value_quad1 = read_phase_value_wa1;
    }
    else if ( quad1_workaround_type == 2 )
    {
	dqs_clk_increment_quad1 = dqs_clk_increment_wa2;
	read_phase_value_quad1 = read_phase_value_wa2;
    }

    if ( quad2_workaround_type == 0 )
    {
	dqs_clk_increment_quad2 = dqs_clk_increment_wa0;
	read_phase_value_quad2 = read_phase_value_wa0;
    }
    else if ( quad2_workaround_type == 1 )
    {
	dqs_clk_increment_quad2 = dqs_clk_increment_wa1;
	read_phase_value_quad2 = read_phase_value_wa1;
    }
    else if ( quad2_workaround_type == 2 )
    {
	dqs_clk_increment_quad2 = dqs_clk_increment_wa2;
	read_phase_value_quad2 = read_phase_value_wa2;
    }

    if ( quad3_workaround_type == 0 )
    {
	dqs_clk_increment_quad3 = dqs_clk_increment_wa0;
	read_phase_value_quad3 = read_phase_value_wa0;
    }
    else if ( quad3_workaround_type == 1 )
    {
	dqs_clk_increment_quad3 = dqs_clk_increment_wa1;
	read_phase_value_quad3 = read_phase_value_wa1;
    }
    else if ( quad3_workaround_type == 2 )
    {
	dqs_clk_increment_quad3 = dqs_clk_increment_wa2;
	read_phase_value_quad3 = read_phase_value_wa2;
    }

    rc = fapiGetScom(i_target, DQSCLK_RD_PHASE_ADDR_0, data_buffer_64);
    if (rc) return rc;

    // Set Read Phase.
    rc_num = rc_num | data_buffer_64.insertFromRight(read_phase_value_quad0, 50, 2);
    rc_num = rc_num | data_buffer_64.insertFromRight(read_phase_value_quad1, 54, 2);
    rc_num = rc_num | data_buffer_64.insertFromRight(read_phase_value_quad2, 58, 2);
    rc_num = rc_num | data_buffer_64.insertFromRight(read_phase_value_quad3, 62, 2);

    //Increment dqs clk. 4 is the limit, wrap around (IE 5 = 1, 6 = 2)
    l_value_u8 = 0;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_u8, 48, 2);
    l_new_value_u8 = (l_value_u8 + dqs_clk_increment_quad0) % 4;
    rc_num = rc_num | data_buffer_64.insertFromRight(&l_new_value_u8, 48, 2);
    l_value_u8 = 0;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_u8, 52, 2);
    l_new_value_u8 = (l_value_u8 + dqs_clk_increment_quad1) % 4;
    rc_num = rc_num | data_buffer_64.insertFromRight(&l_new_value_u8, 52, 2);
    l_value_u8 = 0;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_u8, 56, 2);
    l_new_value_u8 = (l_value_u8 + dqs_clk_increment_quad2) % 4;
    rc_num = rc_num | data_buffer_64.insertFromRight(&l_new_value_u8, 56, 2);
    l_value_u8 = 0;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_u8, 60, 2);
    l_new_value_u8 = (l_value_u8 + dqs_clk_increment_quad3) % 4;
    rc_num = rc_num | data_buffer_64.insertFromRight(&l_new_value_u8, 60, 2);

    rc = fapiPutScom(i_target, DQSCLK_RD_PHASE_ADDR_0, data_buffer_64);
    if (rc) return rc;

    //Block 1
    rc = fapiGetScom(i_target, RD_TIMING_REF0_ADDR_1, data_buffer_64);
    if (rc) return rc;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_timing_ref_quad0, 49, 7);
    rc_num = rc_num | data_buffer_64.extractToRight(&l_timing_ref_quad1, 57, 7);
    rc = fapiGetScom(i_target, RD_TIMING_REF1_ADDR_1, data_buffer_64);
    if (rc) return rc;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_timing_ref_quad2, 49, 7);
    rc_num = rc_num | data_buffer_64.extractToRight(&l_timing_ref_quad3, 57, 7);

    if(rc_num)
    {
	rc.setEcmdError(rc_num);
	return rc;
    }

    if ( quad0_workaround_type == 0 )
    {
	dqs_clk_increment_quad0 = dqs_clk_increment_wa0;
	read_phase_value_quad0 = read_phase_value_wa0;
    }
    else if ( quad0_workaround_type == 1 )
    {
	dqs_clk_increment_quad0 = dqs_clk_increment_wa1;
	read_phase_value_quad0 = read_phase_value_wa1;
    }
    else if ( quad0_workaround_type == 2 )
    {
	dqs_clk_increment_quad0 = dqs_clk_increment_wa2;
	read_phase_value_quad0 = read_phase_value_wa2;
    }

    if ( quad1_workaround_type == 0 )
    {
	dqs_clk_increment_quad1 = dqs_clk_increment_wa0;
	read_phase_value_quad1 = read_phase_value_wa0;
    }
    else if ( quad1_workaround_type == 1 )
    {
	dqs_clk_increment_quad1 = dqs_clk_increment_wa1;
	read_phase_value_quad1 = read_phase_value_wa1;
    }
    else if ( quad1_workaround_type == 2 )
    {
	dqs_clk_increment_quad1 = dqs_clk_increment_wa2;
	read_phase_value_quad1 = read_phase_value_wa2;
    }

    if ( quad2_workaround_type == 0 )
    {
	dqs_clk_increment_quad2 = dqs_clk_increment_wa0;
	read_phase_value_quad2 = read_phase_value_wa0;
    }
    else if ( quad2_workaround_type == 1 )
    {
	dqs_clk_increment_quad2 = dqs_clk_increment_wa1;
	read_phase_value_quad2 = read_phase_value_wa1;
    }
    else if ( quad2_workaround_type == 2 )
    {
	dqs_clk_increment_quad2 = dqs_clk_increment_wa2;
	read_phase_value_quad2 = read_phase_value_wa2;
    }

    if ( quad3_workaround_type == 0 )
    {
	dqs_clk_increment_quad3 = dqs_clk_increment_wa0;
	read_phase_value_quad3 = read_phase_value_wa0;
    }
    else if ( quad3_workaround_type == 1 )
    {
	dqs_clk_increment_quad3 = dqs_clk_increment_wa1;
	read_phase_value_quad3 = read_phase_value_wa1;
    }
    else if ( quad3_workaround_type == 2 )
    {
	dqs_clk_increment_quad3 = dqs_clk_increment_wa2;
	read_phase_value_quad3 = read_phase_value_wa2;
    }


    rc = fapiGetScom(i_target, DQSCLK_RD_PHASE_ADDR_1, data_buffer_64);
    if (rc) return rc;

    // Set Read Phase.
    rc_num = rc_num | data_buffer_64.insertFromRight(read_phase_value_quad0, 50, 2);
    rc_num = rc_num | data_buffer_64.insertFromRight(read_phase_value_quad1, 54, 2);
    rc_num = rc_num | data_buffer_64.insertFromRight(read_phase_value_quad2, 58, 2);
    rc_num = rc_num | data_buffer_64.insertFromRight(read_phase_value_quad3, 62, 2);

    //Increment dqs clk. 4 is the limit, wrap around (IE 5 = 1, 6 = 2)
    l_value_u8 = 0;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_u8, 48, 2);
    l_new_value_u8 = (l_value_u8 + dqs_clk_increment_quad0) % 4;
    rc_num = rc_num | data_buffer_64.insertFromRight(&l_new_value_u8, 48, 2);
    l_value_u8 = 0;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_u8, 52, 2);
    l_new_value_u8 = (l_value_u8 + dqs_clk_increment_quad1) % 4;
    rc_num = rc_num | data_buffer_64.insertFromRight(&l_new_value_u8, 52, 2);
    l_value_u8 = 0;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_u8, 56, 2);
    l_new_value_u8 = (l_value_u8 + dqs_clk_increment_quad2) % 4;
    rc_num = rc_num | data_buffer_64.insertFromRight(&l_new_value_u8, 56, 2);
    l_value_u8 = 0;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_u8, 60, 2);
    l_new_value_u8 = (l_value_u8 + dqs_clk_increment_quad3) % 4;
    rc_num = rc_num | data_buffer_64.insertFromRight(&l_new_value_u8, 60, 2);

    rc = fapiPutScom(i_target, DQSCLK_RD_PHASE_ADDR_1, data_buffer_64);
    if (rc) return rc;

    //Block 2
    rc = fapiGetScom(i_target, RD_TIMING_REF0_ADDR_2, data_buffer_64);
    if (rc) return rc;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_timing_ref_quad0, 49, 7);
    rc_num = rc_num | data_buffer_64.extractToRight(&l_timing_ref_quad1, 57, 7);
    rc = fapiGetScom(i_target, RD_TIMING_REF1_ADDR_2, data_buffer_64);
    if (rc) return rc;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_timing_ref_quad2, 49, 7);
    rc_num = rc_num | data_buffer_64.extractToRight(&l_timing_ref_quad3, 57, 7);

    if(rc_num)
    {
	rc.setEcmdError(rc_num);
	return rc;
    }

    if ( quad0_workaround_type == 0 )
    {
	dqs_clk_increment_quad0 = dqs_clk_increment_wa0;
	read_phase_value_quad0 = read_phase_value_wa0;
    }
    else if ( quad0_workaround_type == 1 )
    {
	dqs_clk_increment_quad0 = dqs_clk_increment_wa1;
	read_phase_value_quad0 = read_phase_value_wa1;
    }
    else if ( quad0_workaround_type == 2 )
    {
	dqs_clk_increment_quad0 = dqs_clk_increment_wa2;
	read_phase_value_quad0 = read_phase_value_wa2;
    }

    if ( quad1_workaround_type == 0 )
    {
	dqs_clk_increment_quad1 = dqs_clk_increment_wa0;
	read_phase_value_quad1 = read_phase_value_wa0;
    }
    else if ( quad1_workaround_type == 1 )
    {
	dqs_clk_increment_quad1 = dqs_clk_increment_wa1;
	read_phase_value_quad1 = read_phase_value_wa1;
    }
    else if ( quad1_workaround_type == 2 )
    {
	dqs_clk_increment_quad1 = dqs_clk_increment_wa2;
	read_phase_value_quad1 = read_phase_value_wa2;
    }

    if ( quad2_workaround_type == 0 )
    {
	dqs_clk_increment_quad2 = dqs_clk_increment_wa0;
	read_phase_value_quad2 = read_phase_value_wa0;
    }
    else if ( quad2_workaround_type == 1 )
    {
	dqs_clk_increment_quad2 = dqs_clk_increment_wa1;
	read_phase_value_quad2 = read_phase_value_wa1;
    }
    else if ( quad2_workaround_type == 2 )
    {
	dqs_clk_increment_quad2 = dqs_clk_increment_wa2;
	read_phase_value_quad2 = read_phase_value_wa2;
    }

    if ( quad3_workaround_type == 0 )
    {
	dqs_clk_increment_quad3 = dqs_clk_increment_wa0;
	read_phase_value_quad3 = read_phase_value_wa0;
    }
    else if ( quad3_workaround_type == 1 )
    {
	dqs_clk_increment_quad3 = dqs_clk_increment_wa1;
	read_phase_value_quad3 = read_phase_value_wa1;
    }
    else if ( quad3_workaround_type == 2 )
    {
	dqs_clk_increment_quad3 = dqs_clk_increment_wa2;
	read_phase_value_quad3 = read_phase_value_wa2;
    }


    rc = fapiGetScom(i_target, DQSCLK_RD_PHASE_ADDR_2, data_buffer_64);
    if (rc) return rc;

    // Set Read Phase.
    rc_num = rc_num | data_buffer_64.insertFromRight(read_phase_value_quad0, 50, 2);
    rc_num = rc_num | data_buffer_64.insertFromRight(read_phase_value_quad1, 54, 2);
    rc_num = rc_num | data_buffer_64.insertFromRight(read_phase_value_quad2, 58, 2);
    rc_num = rc_num | data_buffer_64.insertFromRight(read_phase_value_quad3, 62, 2);

    //Increment dqs clk. 4 is the limit, wrap around (IE 5 = 1, 6 = 2)
    l_value_u8 = 0;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_u8, 48, 2);
    l_new_value_u8 = (l_value_u8 + dqs_clk_increment_quad0) % 4;
    rc_num = rc_num | data_buffer_64.insertFromRight(&l_new_value_u8, 48, 2);
    l_value_u8 = 0;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_u8, 52, 2);
    l_new_value_u8 = (l_value_u8 + dqs_clk_increment_quad1) % 4;
    rc_num = rc_num | data_buffer_64.insertFromRight(&l_new_value_u8, 52, 2);
    l_value_u8 = 0;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_u8, 56, 2);
    l_new_value_u8 = (l_value_u8 + dqs_clk_increment_quad2) % 4;
    rc_num = rc_num | data_buffer_64.insertFromRight(&l_new_value_u8, 56, 2);
    l_value_u8 = 0;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_u8, 60, 2);
    l_new_value_u8 = (l_value_u8 + dqs_clk_increment_quad3) % 4;
    rc_num = rc_num | data_buffer_64.insertFromRight(&l_new_value_u8, 60, 2);

    rc = fapiPutScom(i_target, DQSCLK_RD_PHASE_ADDR_2, data_buffer_64);
    if (rc) return rc;

    //Block 3
    rc = fapiGetScom(i_target, RD_TIMING_REF0_ADDR_3, data_buffer_64);
    if (rc) return rc;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_timing_ref_quad0, 49, 7);
    rc_num = rc_num | data_buffer_64.extractToRight(&l_timing_ref_quad1, 57, 7);
    rc = fapiGetScom(i_target, RD_TIMING_REF1_ADDR_3, data_buffer_64);
    if (rc) return rc;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_timing_ref_quad2, 49, 7);
    rc_num = rc_num | data_buffer_64.extractToRight(&l_timing_ref_quad3, 57, 7);

    if(rc_num)
    {
	rc.setEcmdError(rc_num);
	return rc;
    }

    if ( quad0_workaround_type == 0 )
    {
	dqs_clk_increment_quad0 = dqs_clk_increment_wa0;
	read_phase_value_quad0 = read_phase_value_wa0;
    }
    else if ( quad0_workaround_type == 1 )
    {
	dqs_clk_increment_quad0 = dqs_clk_increment_wa1;
	read_phase_value_quad0 = read_phase_value_wa1;
    }
    else if ( quad0_workaround_type == 2 )
    {
	dqs_clk_increment_quad0 = dqs_clk_increment_wa2;
	read_phase_value_quad0 = read_phase_value_wa2;
    }

    if ( quad1_workaround_type == 0 )
    {
	dqs_clk_increment_quad1 = dqs_clk_increment_wa0;
	read_phase_value_quad1 = read_phase_value_wa0;
    }
    else if ( quad1_workaround_type == 1 )
    {
	dqs_clk_increment_quad1 = dqs_clk_increment_wa1;
	read_phase_value_quad1 = read_phase_value_wa1;
    }
    else if ( quad1_workaround_type == 2 )
    {
	dqs_clk_increment_quad1 = dqs_clk_increment_wa2;
	read_phase_value_quad1 = read_phase_value_wa2;
    }

    if ( quad2_workaround_type == 0 )
    {
	dqs_clk_increment_quad2 = dqs_clk_increment_wa0;
	read_phase_value_quad2 = read_phase_value_wa0;
    }
    else if ( quad2_workaround_type == 1 )
    {
	dqs_clk_increment_quad2 = dqs_clk_increment_wa1;
	read_phase_value_quad2 = read_phase_value_wa1;
    }
    else if ( quad2_workaround_type == 2 )
    {
	dqs_clk_increment_quad2 = dqs_clk_increment_wa2;
	read_phase_value_quad2 = read_phase_value_wa2;
    }

    if ( quad3_workaround_type == 0 )
    {
	dqs_clk_increment_quad3 = dqs_clk_increment_wa0;
	read_phase_value_quad3 = read_phase_value_wa0;
    }
    else if ( quad3_workaround_type == 1 )
    {
	dqs_clk_increment_quad3 = dqs_clk_increment_wa1;
	read_phase_value_quad3 = read_phase_value_wa1;
    }
    else if ( quad3_workaround_type == 2 )
    {
	dqs_clk_increment_quad3 = dqs_clk_increment_wa2;
	read_phase_value_quad3 = read_phase_value_wa2;
    }


    rc = fapiGetScom(i_target, DQSCLK_RD_PHASE_ADDR_3, data_buffer_64);
    if (rc) return rc;

    // Set Read Phase.
    rc_num = rc_num | data_buffer_64.insertFromRight(read_phase_value_quad0, 50, 2);
    rc_num = rc_num | data_buffer_64.insertFromRight(read_phase_value_quad1, 54, 2);
    rc_num = rc_num | data_buffer_64.insertFromRight(read_phase_value_quad2, 58, 2);
    rc_num = rc_num | data_buffer_64.insertFromRight(read_phase_value_quad3, 62, 2);

    //Increment dqs clk. 4 is the limit, wrap around (IE 5 = 1, 6 = 2)
    l_value_u8 = 0;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_u8, 48, 2);
    l_new_value_u8 = (l_value_u8 + dqs_clk_increment_quad0) % 4;
    rc_num = rc_num | data_buffer_64.insertFromRight(&l_new_value_u8, 48, 2);
    l_value_u8 = 0;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_u8, 52, 2);
    l_new_value_u8 = (l_value_u8 + dqs_clk_increment_quad1) % 4;
    rc_num = rc_num | data_buffer_64.insertFromRight(&l_new_value_u8, 52, 2);
    l_value_u8 = 0;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_u8, 56, 2);
    l_new_value_u8 = (l_value_u8 + dqs_clk_increment_quad2) % 4;
    rc_num = rc_num | data_buffer_64.insertFromRight(&l_new_value_u8, 56, 2);
    l_value_u8 = 0;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_u8, 60, 2);
    l_new_value_u8 = (l_value_u8 + dqs_clk_increment_quad3) % 4;
    rc_num = rc_num | data_buffer_64.insertFromRight(&l_new_value_u8, 60, 2);

    rc = fapiPutScom(i_target, DQSCLK_RD_PHASE_ADDR_3, data_buffer_64);
    if (rc) return rc;

    //Block 4
    rc = fapiGetScom(i_target, RD_TIMING_REF0_ADDR_4, data_buffer_64);
    if (rc) return rc;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_timing_ref_quad0, 49, 7);
    rc_num = rc_num | data_buffer_64.extractToRight(&l_timing_ref_quad1, 57, 7);
    rc = fapiGetScom(i_target, RD_TIMING_REF1_ADDR_4, data_buffer_64);
    if (rc) return rc;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_timing_ref_quad2, 49, 7);
    rc_num = rc_num | data_buffer_64.extractToRight(&l_timing_ref_quad3, 57, 7);

    if(rc_num)
    {
	rc.setEcmdError(rc_num);
	return rc;
    }

    if ( quad0_workaround_type == 0 )
    {
	dqs_clk_increment_quad0 = dqs_clk_increment_wa0;
	read_phase_value_quad0 = read_phase_value_wa0;
    }
    else if ( quad0_workaround_type == 1 )
    {
	dqs_clk_increment_quad0 = dqs_clk_increment_wa1;
	read_phase_value_quad0 = read_phase_value_wa1;
    }
    else if ( quad0_workaround_type == 2 )
    {
	dqs_clk_increment_quad0 = dqs_clk_increment_wa2;
	read_phase_value_quad0 = read_phase_value_wa2;
    }

    if ( quad1_workaround_type == 0 )
    {
	dqs_clk_increment_quad1 = dqs_clk_increment_wa0;
	read_phase_value_quad1 = read_phase_value_wa0;
    }
    else if ( quad1_workaround_type == 1 )
    {
	dqs_clk_increment_quad1 = dqs_clk_increment_wa1;
	read_phase_value_quad1 = read_phase_value_wa1;
    }
    else if ( quad1_workaround_type == 2 )
    {
	dqs_clk_increment_quad1 = dqs_clk_increment_wa2;
	read_phase_value_quad1 = read_phase_value_wa2;
    }

    if ( quad2_workaround_type == 0 )
    {
	dqs_clk_increment_quad2 = dqs_clk_increment_wa0;
	read_phase_value_quad2 = read_phase_value_wa0;
    }
    else if ( quad2_workaround_type == 1 )
    {
	dqs_clk_increment_quad2 = dqs_clk_increment_wa1;
	read_phase_value_quad2 = read_phase_value_wa1;
    }
    else if ( quad2_workaround_type == 2 )
    {
	dqs_clk_increment_quad2 = dqs_clk_increment_wa2;
	read_phase_value_quad2 = read_phase_value_wa2;
    }

    if ( quad3_workaround_type == 0 )
    {
	dqs_clk_increment_quad3 = dqs_clk_increment_wa0;
	read_phase_value_quad3 = read_phase_value_wa0;
    }
    else if ( quad3_workaround_type == 1 )
    {
	dqs_clk_increment_quad3 = dqs_clk_increment_wa1;
	read_phase_value_quad3 = read_phase_value_wa1;
    }
    else if ( quad3_workaround_type == 2 )
    {
	dqs_clk_increment_quad3 = dqs_clk_increment_wa2;
	read_phase_value_quad3 = read_phase_value_wa2;
    }


    rc = fapiGetScom(i_target, DQSCLK_RD_PHASE_ADDR_4, data_buffer_64);
    if (rc) return rc;

    // Set Read Phase.
    rc_num = rc_num | data_buffer_64.insertFromRight(read_phase_value_quad0, 50, 2);
    rc_num = rc_num | data_buffer_64.insertFromRight(read_phase_value_quad1, 54, 2);
    rc_num = rc_num | data_buffer_64.insertFromRight(read_phase_value_quad2, 58, 2);
    rc_num = rc_num | data_buffer_64.insertFromRight(read_phase_value_quad3, 62, 2);

    //Increment dqs clk. 4 is the limit, wrap around (IE 5 = 1, 6 = 2)
    l_value_u8 = 0;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_u8, 48, 2);
    l_new_value_u8 = (l_value_u8 + dqs_clk_increment_quad0) % 4;
    rc_num = rc_num | data_buffer_64.insertFromRight(&l_new_value_u8, 48, 2);
    l_value_u8 = 0;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_u8, 52, 2);
    l_new_value_u8 = (l_value_u8 + dqs_clk_increment_quad1) % 4;
    rc_num = rc_num | data_buffer_64.insertFromRight(&l_new_value_u8, 52, 2);
    l_value_u8 = 0;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_u8, 56, 2);
    l_new_value_u8 = (l_value_u8 + dqs_clk_increment_quad2) % 4;
    rc_num = rc_num | data_buffer_64.insertFromRight(&l_new_value_u8, 56, 2);
    l_value_u8 = 0;
    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_u8, 60, 2);
    l_new_value_u8 = (l_value_u8 + dqs_clk_increment_quad3) % 4;
    rc_num = rc_num | data_buffer_64.insertFromRight(&l_new_value_u8, 60, 2);

    rc = fapiPutScom(i_target, DQSCLK_RD_PHASE_ADDR_4, data_buffer_64);
    if (rc) return rc;

    if(rc_num)
    {
        rc.setEcmdError(rc_num);
        return rc;
    }

    return rc;
}

ReturnCode mss_read_center_second_workaround(
            Target& i_target
            )
{
    //MBA target level
    //DQS_CLK for each nibble of a byte is being adjusted to the lowest value for the given byte
    //Across all byte lanes

    uint8_t primary_ranks_array[4][2]; //primary_ranks_array[group][port]
    ecmdDataBufferBase data_buffer_64(64);
    uint64_t DQSCLK_RD_PHASE_ADDR_0 = 0;
    uint64_t DQSCLK_RD_PHASE_ADDR_1 = 0;
    uint64_t DQSCLK_RD_PHASE_ADDR_2 = 0;
    uint64_t DQSCLK_RD_PHASE_ADDR_3 = 0;
    uint64_t DQSCLK_RD_PHASE_ADDR_4 = 0;
    uint64_t GATE_DELAY_ADDR_0 = 0;
    uint64_t GATE_DELAY_ADDR_1 = 0;
    uint64_t GATE_DELAY_ADDR_2 = 0;
    uint64_t GATE_DELAY_ADDR_3 = 0;
    uint64_t GATE_DELAY_ADDR_4 = 0;
    uint8_t port = 0;
    uint8_t rank_group = 0;
    uint8_t l_value_n0_u8 = 0;
    uint8_t l_value_n1_u8 = 0;
    //uint8_t l_lowest_value_u8 = 0;
    ReturnCode rc;
    uint32_t rc_num = 0;

    uint32_t block;
    uint32_t maxblocks = 5;
    uint32_t byte;
    uint32_t maxbytes = 2;
    uint32_t nibble;
    uint32_t maxnibbles = 2;

    uint8_t l_lowest_value_u8[4][5][2][2]; // l_lowest_value_u8[group][block][byte_of_reg][nibble_of_byte]
    uint8_t l_gate_delay_value_u8[4][5][2][2]; // l_lowest_value_u8[group][block][byte_of_reg][nibble_of_byte]


    //populate primary_ranks_arrays_array
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP0, &i_target, primary_ranks_array[0]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP1, &i_target, primary_ranks_array[1]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP2, &i_target, primary_ranks_array[2]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP3, &i_target, primary_ranks_array[3]);
    if(rc) return rc;


    for(port = 0; port < MAX_PORTS; port++)
    {


	//FAPI_INF( "DQS_CLK Byte matching Workaround being applied on  %s  PORT: %d RP: %d", i_target.toEcmdString(), port, rank_group);

	//Gather all the byte information
        for(rank_group = 0; rank_group < MAX_PRI_RANKS; rank_group++)
	{

	     //Initialize values
	     for(block = 0; block < maxblocks; block++)
	     {
		for (byte = 0; byte < maxbytes; byte++)
		{
			for (nibble = 0; nibble < maxnibbles; nibble++)
			{
				l_lowest_value_u8[rank_group][block][byte][nibble] = 255;
				l_gate_delay_value_u8[rank_group][block][byte][nibble] = 255;
			}
		}
	     }

	    //Check if rank group exists
	    if(primary_ranks_array[rank_group][port] != 255)
	    {
	        FAPI_INF( "DQS_CLK Byte matching Workaround being applied on  %s  PORT: %d RP: %d", i_target.toEcmdString(), port, rank_group);
    		if ( port == 0 )
    		{

			if ( rank_group == 0 )
			{
			    DQSCLK_RD_PHASE_ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0_0x800000090301143F;
			    DQSCLK_RD_PHASE_ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_1_0x800004090301143F;
			    DQSCLK_RD_PHASE_ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_2_0x800008090301143F;
			    DQSCLK_RD_PHASE_ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_3_0x80000C090301143F;
			    DQSCLK_RD_PHASE_ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_4_0x800010090301143F;
			    GATE_DELAY_ADDR_0 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P0_0_0x800000130301143F;
			    GATE_DELAY_ADDR_1 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P0_1_0x800004130301143F;
			    GATE_DELAY_ADDR_2 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P0_2_0x800008130301143F;
			    GATE_DELAY_ADDR_3 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P0_3_0x80000C130301143F;
			    GATE_DELAY_ADDR_4 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P0_4_0x800010130301143F;

			}
			else if ( rank_group == 1 )
			{
			    DQSCLK_RD_PHASE_ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_0_0x800001090301143F;
			    DQSCLK_RD_PHASE_ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_1_0x800005090301143F;
			    DQSCLK_RD_PHASE_ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_2_0x800009090301143F;
			    DQSCLK_RD_PHASE_ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_3_0x80000D090301143F;
			    DQSCLK_RD_PHASE_ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_4_0x800011090301143F;
			    GATE_DELAY_ADDR_0 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P0_0_0x800001130301143F;
			    GATE_DELAY_ADDR_1 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P0_1_0x800005130301143F;
			    GATE_DELAY_ADDR_2 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P0_2_0x800009130301143F;
			    GATE_DELAY_ADDR_3 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P0_3_0x80000D130301143F;
			    GATE_DELAY_ADDR_4 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P0_4_0x800011130301143F;

			}
			else if ( rank_group == 2 )
			{
			    DQSCLK_RD_PHASE_ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_0_0x800002090301143F;
			    DQSCLK_RD_PHASE_ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_1_0x800006090301143F;
			    DQSCLK_RD_PHASE_ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_2_0x80000A090301143F;
			    DQSCLK_RD_PHASE_ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_3_0x80000E090301143F;
			    DQSCLK_RD_PHASE_ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_4_0x800012090301143F;
			    GATE_DELAY_ADDR_0 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P0_0_0x800002130301143F;
			    GATE_DELAY_ADDR_1 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P0_1_0x800006130301143F;
			    GATE_DELAY_ADDR_2 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P0_2_0x80000A130301143F;
			    GATE_DELAY_ADDR_3 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P0_3_0x80000E130301143F;
			    GATE_DELAY_ADDR_4 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P0_4_0x800012130301143F;

			}
			else if ( rank_group == 3 )
			{
			    DQSCLK_RD_PHASE_ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_0_0x800003090301143F;
			    DQSCLK_RD_PHASE_ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_1_0x800007090301143F;
			    DQSCLK_RD_PHASE_ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_2_0x80000B090301143F;
			    DQSCLK_RD_PHASE_ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_3_0x80000F090301143F;
			    DQSCLK_RD_PHASE_ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_4_0x800013090301143F;
			    GATE_DELAY_ADDR_0 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P0_0_0x800003130301143F;
			    GATE_DELAY_ADDR_1 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P0_1_0x800007130301143F;
			    GATE_DELAY_ADDR_2 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P0_2_0x80000B130301143F;
			    GATE_DELAY_ADDR_3 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P0_3_0x80000F130301143F;
			    GATE_DELAY_ADDR_4 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P0_4_0x800013130301143F;

			}
		    }
		    else if (port == 1 )
		    {

			if ( rank_group == 0 )
			{
			    DQSCLK_RD_PHASE_ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_0_0x800100090301143F;
			    DQSCLK_RD_PHASE_ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_1_0x800104090301143F;
			    DQSCLK_RD_PHASE_ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_2_0x800108090301143F;
			    DQSCLK_RD_PHASE_ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_3_0x80010C090301143F;
			    DQSCLK_RD_PHASE_ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_4_0x800110090301143F;
			    GATE_DELAY_ADDR_0 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P1_0_0x800100130301143F;
			    GATE_DELAY_ADDR_1 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P1_1_0x800104130301143F;
			    GATE_DELAY_ADDR_2 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P1_2_0x800108130301143F;
			    GATE_DELAY_ADDR_3 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P1_3_0x80010C130301143F;
			    GATE_DELAY_ADDR_4 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P1_4_0x800110130301143F;

			}
			else if ( rank_group == 1 )
			{
			    DQSCLK_RD_PHASE_ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P1_0_0x800101090301143F;
			    DQSCLK_RD_PHASE_ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P1_1_0x800105090301143F;
			    DQSCLK_RD_PHASE_ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P1_2_0x800109090301143F;
			    DQSCLK_RD_PHASE_ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P1_3_0x80010D090301143F;
			    DQSCLK_RD_PHASE_ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P1_4_0x800111090301143F;
			    GATE_DELAY_ADDR_0 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P1_0_0x800101130301143F;
			    GATE_DELAY_ADDR_1 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P1_1_0x800105130301143F;
			    GATE_DELAY_ADDR_2 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P1_2_0x800109130301143F;
			    GATE_DELAY_ADDR_3 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P1_3_0x80010D130301143F;
			    GATE_DELAY_ADDR_4 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P1_4_0x800111130301143F;

			}
			else if ( rank_group == 2 )
			{
			    DQSCLK_RD_PHASE_ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P1_0_0x800102090301143F;
			    DQSCLK_RD_PHASE_ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P1_1_0x800106090301143F;
			    DQSCLK_RD_PHASE_ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P1_2_0x80010A090301143F;
			    DQSCLK_RD_PHASE_ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P1_3_0x80010E090301143F;
			    DQSCLK_RD_PHASE_ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P1_4_0x800112090301143F;
			    GATE_DELAY_ADDR_0 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P1_0_0x800102130301143F;
			    GATE_DELAY_ADDR_1 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P1_1_0x800106130301143F;
			    GATE_DELAY_ADDR_2 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P1_2_0x80010A130301143F;
			    GATE_DELAY_ADDR_3 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P1_3_0x80010E130301143F;
			    GATE_DELAY_ADDR_4 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P1_4_0x800112130301143F;

			}
			else if ( rank_group == 3 )
			{
			    DQSCLK_RD_PHASE_ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P1_0_0x800103090301143F;
			    DQSCLK_RD_PHASE_ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P1_1_0x800107090301143F;
			    DQSCLK_RD_PHASE_ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P1_2_0x80010B090301143F;
			    DQSCLK_RD_PHASE_ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P1_3_0x80010F090301143F;
			    DQSCLK_RD_PHASE_ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P1_4_0x800113090301143F;
			    GATE_DELAY_ADDR_0 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P1_0_0x800103130301143F;
			    GATE_DELAY_ADDR_1 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P1_1_0x800107130301143F;
			    GATE_DELAY_ADDR_2 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P1_2_0x80010B130301143F;
			    GATE_DELAY_ADDR_3 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P1_3_0x80010F130301143F;
			    GATE_DELAY_ADDR_4 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P1_4_0x800113130301143F;

			}
		    }


		    // PHY BLOCK 0
		    rc = fapiGetScom(i_target, DQSCLK_RD_PHASE_ADDR_0, data_buffer_64);
		    if (rc) return rc;
		    // Grabbing 2 nibbles of the same byte and making them equal to the same lowest value
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n0_u8, 48, 2);
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n1_u8, 52, 2);
		    l_lowest_value_u8[rank_group][0][0][0] = l_value_n0_u8;
		    l_lowest_value_u8[rank_group][0][0][1] = l_value_n1_u8;
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n0_u8, 56, 2);
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n1_u8, 60, 2);
		    l_lowest_value_u8[rank_group][0][1][0] = l_value_n0_u8;
		    l_lowest_value_u8[rank_group][0][1][1] = l_value_n1_u8;

		    rc = fapiGetScom(i_target, GATE_DELAY_ADDR_0, data_buffer_64);
		    if (rc) return rc;
		    // Grabbing 2 nibbles of the same byte and making them equal the same lowest value
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n0_u8, 49, 3);
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n1_u8, 53, 3);
		    l_gate_delay_value_u8[rank_group][0][0][0] = l_value_n0_u8;
		    l_gate_delay_value_u8[rank_group][0][0][1] = l_value_n1_u8;
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n0_u8, 57, 3);
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n1_u8, 61, 3);
		    l_gate_delay_value_u8[rank_group][0][1][0] = l_value_n0_u8;
		    l_gate_delay_value_u8[rank_group][0][1][1] = l_value_n1_u8;

		    // PHY BLOCK 1
		    rc = fapiGetScom(i_target, DQSCLK_RD_PHASE_ADDR_1, data_buffer_64);
		    if (rc) return rc;
		    // Grabbing 2 nibbles of the same byte and making them equal to the same lowest value
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n0_u8, 48, 2);
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n1_u8, 52, 2);
		    l_lowest_value_u8[rank_group][1][0][0] = l_value_n0_u8;
		    l_lowest_value_u8[rank_group][1][0][1] = l_value_n1_u8;
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n0_u8, 56, 2);
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n1_u8, 60, 2);
		    l_lowest_value_u8[rank_group][1][1][0] = l_value_n0_u8;
		    l_lowest_value_u8[rank_group][1][1][1] = l_value_n1_u8;

		    rc = fapiGetScom(i_target, GATE_DELAY_ADDR_1, data_buffer_64);
		    if (rc) return rc;
		    // Grabbing 2 nibbles of the same byte and making them equal the same lowest value
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n0_u8, 49, 3);
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n1_u8, 53, 3);
		    l_gate_delay_value_u8[rank_group][1][0][0] = l_value_n0_u8;
		    l_gate_delay_value_u8[rank_group][1][0][1] = l_value_n1_u8;
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n0_u8, 57, 3);
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n1_u8, 61, 3);
		    l_gate_delay_value_u8[rank_group][1][1][0] = l_value_n0_u8;
		    l_gate_delay_value_u8[rank_group][1][1][1] = l_value_n1_u8;

		    // PHY BLOCK 2
		    rc = fapiGetScom(i_target, DQSCLK_RD_PHASE_ADDR_2, data_buffer_64);
		    if (rc) return rc;
		    // Grabbing 2 nibbles of the same byte and making them equal to the same lowest value
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n0_u8, 48, 2);
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n1_u8, 52, 2);
		    l_lowest_value_u8[rank_group][2][0][0] = l_value_n0_u8;
		    l_lowest_value_u8[rank_group][2][0][1] = l_value_n1_u8;
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n0_u8, 56, 2);
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n1_u8, 60, 2);
		    l_lowest_value_u8[rank_group][2][1][0] = l_value_n0_u8;
		    l_lowest_value_u8[rank_group][2][1][1] = l_value_n1_u8;

		    rc = fapiGetScom(i_target, GATE_DELAY_ADDR_2, data_buffer_64);
		    if (rc) return rc;
		    // Grabbing 2 nibbles of the same byte and making them equal the same lowest value
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n0_u8, 49, 3);
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n1_u8, 53, 3);
		    l_gate_delay_value_u8[rank_group][2][0][0] = l_value_n0_u8;
		    l_gate_delay_value_u8[rank_group][2][0][1] = l_value_n1_u8;
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n0_u8, 57, 3);
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n1_u8, 61, 3);
		    l_gate_delay_value_u8[rank_group][2][1][0] = l_value_n0_u8;
		    l_gate_delay_value_u8[rank_group][2][1][1] = l_value_n1_u8;

		    // PHY BLOCK 3
		    rc = fapiGetScom(i_target, DQSCLK_RD_PHASE_ADDR_3, data_buffer_64);
		    if (rc) return rc;
		    // Grabbing 2 nibbles of the same byte and making them equal to the same lowest value
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n0_u8, 48, 2);
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n1_u8, 52, 2);
		    l_lowest_value_u8[rank_group][3][0][0] = l_value_n0_u8;
		    l_lowest_value_u8[rank_group][3][0][1] = l_value_n1_u8;
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n0_u8, 56, 2);
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n1_u8, 60, 2);
		    l_lowest_value_u8[rank_group][3][1][0] = l_value_n0_u8;
		    l_lowest_value_u8[rank_group][3][1][1] = l_value_n1_u8;

		    rc = fapiGetScom(i_target, GATE_DELAY_ADDR_3, data_buffer_64);
		    if (rc) return rc;
		    // Grabbing 2 nibbles of the same byte and making them equal the same lowest value
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n0_u8, 49, 3);
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n1_u8, 53, 3);
		    l_gate_delay_value_u8[rank_group][3][0][0] = l_value_n0_u8;
		    l_gate_delay_value_u8[rank_group][3][0][1] = l_value_n1_u8;
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n0_u8, 57, 3);
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n1_u8, 61, 3);
		    l_gate_delay_value_u8[rank_group][3][1][0] = l_value_n0_u8;
		    l_gate_delay_value_u8[rank_group][3][1][1] = l_value_n1_u8;

		    // PHY BLOCK 4
		    rc = fapiGetScom(i_target, DQSCLK_RD_PHASE_ADDR_4, data_buffer_64);
		    if (rc) return rc;
		    // Grabbing 2 nibbles of the same byte and making them equal to the same lowest value
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n0_u8, 48, 2);
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n1_u8, 52, 2);
		    l_lowest_value_u8[rank_group][4][0][0] = l_value_n0_u8;
		    l_lowest_value_u8[rank_group][4][0][1] = l_value_n1_u8;
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n0_u8, 56, 2);
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n1_u8, 60, 2);
		    l_lowest_value_u8[rank_group][4][1][0] = l_value_n0_u8;
		    l_lowest_value_u8[rank_group][4][1][1] = l_value_n1_u8;

		    rc = fapiGetScom(i_target, GATE_DELAY_ADDR_4, data_buffer_64);
		    if (rc) return rc;
		    // Grabbing 2 nibbles of the same byte and making them equal the same lowest value
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n0_u8, 49, 3);
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n1_u8, 53, 3);
		    l_gate_delay_value_u8[rank_group][4][0][0] = l_value_n0_u8;
		    l_gate_delay_value_u8[rank_group][4][0][1] = l_value_n1_u8;
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n0_u8, 57, 3);
		    rc_num = rc_num | data_buffer_64.extractToRight(&l_value_n1_u8, 61, 3);
		    l_gate_delay_value_u8[rank_group][4][1][0] = l_value_n0_u8;
		    l_gate_delay_value_u8[rank_group][4][1][1] = l_value_n1_u8;

		    if(rc_num)
		    {
			rc.setEcmdError(rc_num);
			return rc;
		    }

		}
	}

	//Finding the lowest Value
        for(block = 0; block < maxblocks; block++)
	{
		for (byte = 0; byte < maxbytes; byte++)
		{

			for (nibble = 0; nibble < maxnibbles; nibble++)
			{

			    if ( (l_lowest_value_u8[0][block][byte][nibble] == 0) ||
				 (l_lowest_value_u8[1][block][byte][nibble] == 0) ||
				 (l_lowest_value_u8[2][block][byte][nibble] == 0) ||
				 (l_lowest_value_u8[3][block][byte][nibble] == 0) )
			    {
				    if ( (l_lowest_value_u8[0][block][byte][nibble] == 3) ||
					 (l_lowest_value_u8[1][block][byte][nibble] == 3) ||
					 (l_lowest_value_u8[2][block][byte][nibble] == 3) ||
					 (l_lowest_value_u8[3][block][byte][nibble] == 3) )
				    {

					//In this case alone we make all gate values equal the gate of the lowest DQSCLK
					if (l_lowest_value_u8[0][block][byte][nibble] == 3)
					{
						l_gate_delay_value_u8[1][block][byte][nibble] = l_gate_delay_value_u8[0][block][byte][nibble];
						l_gate_delay_value_u8[2][block][byte][nibble] = l_gate_delay_value_u8[0][block][byte][nibble];
						l_gate_delay_value_u8[3][block][byte][nibble] = l_gate_delay_value_u8[0][block][byte][nibble];
					}
					else if (l_lowest_value_u8[1][block][byte][nibble] == 3)
					{
						l_gate_delay_value_u8[0][block][byte][nibble] = l_gate_delay_value_u8[1][block][byte][nibble];
						l_gate_delay_value_u8[2][block][byte][nibble] = l_gate_delay_value_u8[1][block][byte][nibble];
						l_gate_delay_value_u8[3][block][byte][nibble] = l_gate_delay_value_u8[1][block][byte][nibble];
					}
					else if (l_lowest_value_u8[2][block][byte][nibble] == 3)
					{
						l_gate_delay_value_u8[0][block][byte][nibble] = l_gate_delay_value_u8[2][block][byte][nibble];
						l_gate_delay_value_u8[1][block][byte][nibble] = l_gate_delay_value_u8[2][block][byte][nibble];
						l_gate_delay_value_u8[3][block][byte][nibble] = l_gate_delay_value_u8[2][block][byte][nibble];
					}
					else if (l_lowest_value_u8[3][block][byte][nibble] == 3)
					{
						l_gate_delay_value_u8[0][block][byte][nibble] = l_gate_delay_value_u8[3][block][byte][nibble];
						l_gate_delay_value_u8[1][block][byte][nibble] = l_gate_delay_value_u8[3][block][byte][nibble];
						l_gate_delay_value_u8[2][block][byte][nibble] = l_gate_delay_value_u8[3][block][byte][nibble];
					}

					l_lowest_value_u8[0][block][byte][nibble] = 3;
					l_lowest_value_u8[1][block][byte][nibble] = 3;
					l_lowest_value_u8[2][block][byte][nibble] = 3;
					l_lowest_value_u8[3][block][byte][nibble] = 3;
				    }
				    else
				    {
					l_lowest_value_u8[0][block][byte][nibble] = 0;
					l_lowest_value_u8[1][block][byte][nibble] = 0;
					l_lowest_value_u8[2][block][byte][nibble] = 0;
					l_lowest_value_u8[3][block][byte][nibble] = 0;

				    }
			    }
			    else if ( (l_lowest_value_u8[0][block][byte][nibble] == 2) ||
				    (l_lowest_value_u8[1][block][byte][nibble] == 2) ||
				    (l_lowest_value_u8[2][block][byte][nibble] == 2) ||
				    (l_lowest_value_u8[3][block][byte][nibble] == 2) )
			    {
				    if ( (l_lowest_value_u8[0][block][byte][nibble] == 1) ||
					 (l_lowest_value_u8[1][block][byte][nibble] == 1) ||
					 (l_lowest_value_u8[2][block][byte][nibble] == 1) ||
					 (l_lowest_value_u8[3][block][byte][nibble] == 1) )
				    {
					l_lowest_value_u8[0][block][byte][nibble] = 1;
					l_lowest_value_u8[1][block][byte][nibble] = 1;
					l_lowest_value_u8[2][block][byte][nibble] = 1;
					l_lowest_value_u8[3][block][byte][nibble] = 1;

				    }
				    else
				    {
					l_lowest_value_u8[0][block][byte][nibble] = 2;
					l_lowest_value_u8[1][block][byte][nibble] = 2;
					l_lowest_value_u8[2][block][byte][nibble] = 2;
					l_lowest_value_u8[3][block][byte][nibble] = 2;

				    }
			    }

			}
		}

	}


	//Scoming in the New Values
        for(rank_group = 0; rank_group < MAX_PRI_RANKS; rank_group++)
	{

	    //Check if rank group exists
	    if(primary_ranks_array[rank_group][port] != 255)
	    {

    		if ( port == 0 )
    		{

			if ( rank_group == 0 )
			{
			    DQSCLK_RD_PHASE_ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0_0x800000090301143F;
			    DQSCLK_RD_PHASE_ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_1_0x800004090301143F;
			    DQSCLK_RD_PHASE_ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_2_0x800008090301143F;
			    DQSCLK_RD_PHASE_ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_3_0x80000C090301143F;
			    DQSCLK_RD_PHASE_ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_4_0x800010090301143F;
			    GATE_DELAY_ADDR_0 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P0_0_0x800000130301143F;
			    GATE_DELAY_ADDR_1 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P0_1_0x800004130301143F;
			    GATE_DELAY_ADDR_2 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P0_2_0x800008130301143F;
			    GATE_DELAY_ADDR_3 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P0_3_0x80000C130301143F;
			    GATE_DELAY_ADDR_4 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P0_4_0x800010130301143F;

			}
			else if ( rank_group == 1 )
			{
			    DQSCLK_RD_PHASE_ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_0_0x800001090301143F;
			    DQSCLK_RD_PHASE_ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_1_0x800005090301143F;
			    DQSCLK_RD_PHASE_ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_2_0x800009090301143F;
			    DQSCLK_RD_PHASE_ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_3_0x80000D090301143F;
			    DQSCLK_RD_PHASE_ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_4_0x800011090301143F;
			    GATE_DELAY_ADDR_0 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P0_0_0x800001130301143F;
			    GATE_DELAY_ADDR_1 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P0_1_0x800005130301143F;
			    GATE_DELAY_ADDR_2 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P0_2_0x800009130301143F;
			    GATE_DELAY_ADDR_3 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P0_3_0x80000D130301143F;
			    GATE_DELAY_ADDR_4 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P0_4_0x800011130301143F;

			}
			else if ( rank_group == 2 )
			{
			    DQSCLK_RD_PHASE_ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_0_0x800002090301143F;
			    DQSCLK_RD_PHASE_ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_1_0x800006090301143F;
			    DQSCLK_RD_PHASE_ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_2_0x80000A090301143F;
			    DQSCLK_RD_PHASE_ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_3_0x80000E090301143F;
			    DQSCLK_RD_PHASE_ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_4_0x800012090301143F;
			    GATE_DELAY_ADDR_0 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P0_0_0x800002130301143F;
			    GATE_DELAY_ADDR_1 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P0_1_0x800006130301143F;
			    GATE_DELAY_ADDR_2 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P0_2_0x80000A130301143F;
			    GATE_DELAY_ADDR_3 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P0_3_0x80000E130301143F;
			    GATE_DELAY_ADDR_4 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P0_4_0x800012130301143F;

			}
			else if ( rank_group == 3 )
			{
			    DQSCLK_RD_PHASE_ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_0_0x800003090301143F;
			    DQSCLK_RD_PHASE_ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_1_0x800007090301143F;
			    DQSCLK_RD_PHASE_ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_2_0x80000B090301143F;
			    DQSCLK_RD_PHASE_ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_3_0x80000F090301143F;
			    DQSCLK_RD_PHASE_ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_4_0x800013090301143F;
			    GATE_DELAY_ADDR_0 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P0_0_0x800003130301143F;
			    GATE_DELAY_ADDR_1 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P0_1_0x800007130301143F;
			    GATE_DELAY_ADDR_2 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P0_2_0x80000B130301143F;
			    GATE_DELAY_ADDR_3 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P0_3_0x80000F130301143F;
			    GATE_DELAY_ADDR_4 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P0_4_0x800013130301143F;

			}
		    }
		    else if (port == 1 )
		    {

			if ( rank_group == 0 )
			{
			    DQSCLK_RD_PHASE_ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_0_0x800100090301143F;
			    DQSCLK_RD_PHASE_ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_1_0x800104090301143F;
			    DQSCLK_RD_PHASE_ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_2_0x800108090301143F;
			    DQSCLK_RD_PHASE_ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_3_0x80010C090301143F;
			    DQSCLK_RD_PHASE_ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_4_0x800110090301143F;
			    GATE_DELAY_ADDR_0 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P1_0_0x800100130301143F;
			    GATE_DELAY_ADDR_1 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P1_1_0x800104130301143F;
			    GATE_DELAY_ADDR_2 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P1_2_0x800108130301143F;
			    GATE_DELAY_ADDR_3 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P1_3_0x80010C130301143F;
			    GATE_DELAY_ADDR_4 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P1_4_0x800110130301143F;

			}
			else if ( rank_group == 1 )
			{
			    DQSCLK_RD_PHASE_ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P1_0_0x800101090301143F;
			    DQSCLK_RD_PHASE_ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P1_1_0x800105090301143F;
			    DQSCLK_RD_PHASE_ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P1_2_0x800109090301143F;
			    DQSCLK_RD_PHASE_ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P1_3_0x80010D090301143F;
			    DQSCLK_RD_PHASE_ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P1_4_0x800111090301143F;
			    GATE_DELAY_ADDR_0 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P1_0_0x800101130301143F;
			    GATE_DELAY_ADDR_1 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P1_1_0x800105130301143F;
			    GATE_DELAY_ADDR_2 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P1_2_0x800109130301143F;
			    GATE_DELAY_ADDR_3 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P1_3_0x80010D130301143F;
			    GATE_DELAY_ADDR_4 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P1_4_0x800111130301143F;

			}
			else if ( rank_group == 2 )
			{
			    DQSCLK_RD_PHASE_ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P1_0_0x800102090301143F;
			    DQSCLK_RD_PHASE_ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P1_1_0x800106090301143F;
			    DQSCLK_RD_PHASE_ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P1_2_0x80010A090301143F;
			    DQSCLK_RD_PHASE_ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P1_3_0x80010E090301143F;
			    DQSCLK_RD_PHASE_ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P1_4_0x800112090301143F;
			    GATE_DELAY_ADDR_0 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P1_0_0x800102130301143F;
			    GATE_DELAY_ADDR_1 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P1_1_0x800106130301143F;
			    GATE_DELAY_ADDR_2 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P1_2_0x80010A130301143F;
			    GATE_DELAY_ADDR_3 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P1_3_0x80010E130301143F;
			    GATE_DELAY_ADDR_4 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P1_4_0x800112130301143F;

			}
			else if ( rank_group == 3 )
			{
			    DQSCLK_RD_PHASE_ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P1_0_0x800103090301143F;
			    DQSCLK_RD_PHASE_ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P1_1_0x800107090301143F;
			    DQSCLK_RD_PHASE_ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P1_2_0x80010B090301143F;
			    DQSCLK_RD_PHASE_ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P1_3_0x80010F090301143F;
			    DQSCLK_RD_PHASE_ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P1_4_0x800113090301143F;
			    GATE_DELAY_ADDR_0 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P1_0_0x800103130301143F;
			    GATE_DELAY_ADDR_1 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P1_1_0x800107130301143F;
			    GATE_DELAY_ADDR_2 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P1_2_0x80010B130301143F;
			    GATE_DELAY_ADDR_3 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P1_3_0x80010F130301143F;
			    GATE_DELAY_ADDR_4 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P1_4_0x800113130301143F;

			}
		    }

		    //BLOCK 0
		    rc = fapiGetScom(i_target, DQSCLK_RD_PHASE_ADDR_0, data_buffer_64);
		    if (rc) return rc;
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_lowest_value_u8[rank_group][0][0][0], 48, 2);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_lowest_value_u8[rank_group][0][0][1], 52, 2);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_lowest_value_u8[rank_group][0][1][0], 56, 2);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_lowest_value_u8[rank_group][0][1][1], 60, 2);
		    rc = fapiPutScom(i_target, DQSCLK_RD_PHASE_ADDR_0, data_buffer_64);
		    if (rc) return rc;

		    rc = fapiGetScom(i_target, GATE_DELAY_ADDR_0, data_buffer_64);
		    if (rc) return rc;
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_gate_delay_value_u8[rank_group][0][0][0], 49, 3);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_gate_delay_value_u8[rank_group][0][0][1], 53, 3);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_gate_delay_value_u8[rank_group][0][1][0], 57, 3);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_gate_delay_value_u8[rank_group][0][1][1], 61, 3);
		    rc = fapiPutScom(i_target, GATE_DELAY_ADDR_0, data_buffer_64);
		    if (rc) return rc;

		    //BLOCK 1
		    rc = fapiGetScom(i_target, DQSCLK_RD_PHASE_ADDR_1, data_buffer_64);
		    if (rc) return rc;
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_lowest_value_u8[rank_group][1][0][0], 48, 2);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_lowest_value_u8[rank_group][1][0][1], 52, 2);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_lowest_value_u8[rank_group][1][1][0], 56, 2);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_lowest_value_u8[rank_group][1][1][1], 60, 2);
		    rc = fapiPutScom(i_target, DQSCLK_RD_PHASE_ADDR_1, data_buffer_64);
		    if (rc) return rc;

		    rc = fapiGetScom(i_target, GATE_DELAY_ADDR_1, data_buffer_64);
		    if (rc) return rc;
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_gate_delay_value_u8[rank_group][1][0][0], 49, 3);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_gate_delay_value_u8[rank_group][1][0][1], 53, 3);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_gate_delay_value_u8[rank_group][1][1][0], 57, 3);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_gate_delay_value_u8[rank_group][1][1][1], 61, 3);
		    rc = fapiPutScom(i_target, GATE_DELAY_ADDR_1, data_buffer_64);
		    if (rc) return rc;

		    //BLOCK 2
		    rc = fapiGetScom(i_target, DQSCLK_RD_PHASE_ADDR_2, data_buffer_64);
		    if (rc) return rc;
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_lowest_value_u8[rank_group][2][0][0], 48, 2);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_lowest_value_u8[rank_group][2][0][1], 52, 2);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_lowest_value_u8[rank_group][2][1][0], 56, 2);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_lowest_value_u8[rank_group][2][1][1], 60, 2);
		    rc = fapiPutScom(i_target, DQSCLK_RD_PHASE_ADDR_2, data_buffer_64);
		    if (rc) return rc;

		    rc = fapiGetScom(i_target, GATE_DELAY_ADDR_2, data_buffer_64);
		    if (rc) return rc;
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_gate_delay_value_u8[rank_group][2][0][0], 49, 3);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_gate_delay_value_u8[rank_group][2][0][1], 53, 3);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_gate_delay_value_u8[rank_group][2][1][0], 57, 3);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_gate_delay_value_u8[rank_group][2][1][1], 61, 3);
		    rc = fapiPutScom(i_target, GATE_DELAY_ADDR_2, data_buffer_64);
		    if (rc) return rc;

		    //BLOCK 3
		    rc = fapiGetScom(i_target, DQSCLK_RD_PHASE_ADDR_3, data_buffer_64);
		    if (rc) return rc;
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_lowest_value_u8[rank_group][3][0][0], 48, 2);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_lowest_value_u8[rank_group][3][0][1], 52, 2);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_lowest_value_u8[rank_group][3][1][0], 56, 2);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_lowest_value_u8[rank_group][3][1][1], 60, 2);
		    rc = fapiPutScom(i_target, DQSCLK_RD_PHASE_ADDR_3, data_buffer_64);
		    if (rc) return rc;

		    rc = fapiGetScom(i_target, GATE_DELAY_ADDR_3, data_buffer_64);
		    if (rc) return rc;
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_gate_delay_value_u8[rank_group][3][0][0], 49, 3);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_gate_delay_value_u8[rank_group][3][0][1], 53, 3);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_gate_delay_value_u8[rank_group][3][1][0], 57, 3);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_gate_delay_value_u8[rank_group][3][1][1], 61, 3);
		    rc = fapiPutScom(i_target, GATE_DELAY_ADDR_3, data_buffer_64);
		    if (rc) return rc;

		    //Block 4
		    rc = fapiGetScom(i_target, DQSCLK_RD_PHASE_ADDR_4, data_buffer_64);
		    if (rc) return rc;
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_lowest_value_u8[rank_group][4][0][0], 48, 2);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_lowest_value_u8[rank_group][4][0][1], 52, 2);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_lowest_value_u8[rank_group][4][1][0], 56, 2);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_lowest_value_u8[rank_group][4][1][1], 60, 2);
		    rc = fapiPutScom(i_target, DQSCLK_RD_PHASE_ADDR_4, data_buffer_64);
		    if (rc) return rc;

		    rc = fapiGetScom(i_target, GATE_DELAY_ADDR_4, data_buffer_64);
		    if (rc) return rc;
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_gate_delay_value_u8[rank_group][4][0][0], 49, 3);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_gate_delay_value_u8[rank_group][4][0][1], 53, 3);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_gate_delay_value_u8[rank_group][4][1][0], 57, 3);
		    rc_num = rc_num | data_buffer_64.insertFromRight(&l_gate_delay_value_u8[rank_group][4][1][1], 61, 3);

		    if(rc_num)
		    {
			rc.setEcmdError(rc_num);
			return rc;
		    }

		    rc = fapiPutScom(i_target, GATE_DELAY_ADDR_4, data_buffer_64);
		    if (rc) return rc;

		}
	}
    }

    return rc;
}

ReturnCode mss_reset_delay_values(
            Target& i_target
            )
{
    //MBA target level
    //Reset Wr_level delays and Gate Delays
    //Across all configed rank pairs, in order

    uint8_t primary_ranks_array[4][2]; //primary_ranks_array[group][port]
    ecmdDataBufferBase data_buffer_64(64);
    uint64_t GATE_DELAY_ADDR_0 = 0;
    uint64_t GATE_DELAY_ADDR_1 = 0;
    uint64_t GATE_DELAY_ADDR_2 = 0;
    uint64_t GATE_DELAY_ADDR_3 = 0;
    uint64_t GATE_DELAY_ADDR_4 = 0;
    uint8_t port = 0;
    uint8_t rank_group = 0;
    ReturnCode rc;
    uint32_t rc_num = 0;


    //populate primary_ranks_arrays_array
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP0, &i_target, primary_ranks_array[0]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP1, &i_target, primary_ranks_array[1]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP2, &i_target, primary_ranks_array[2]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP3, &i_target, primary_ranks_array[3]);
    if(rc) return rc;

    //Hit the reset button for wr_lvl values
    //These won't reset until the next run of wr_lvl
    rc = fapiGetScom(i_target, DPHY01_DDRPHY_WC_CONFIG2_P0_0x8000CC020301143F, data_buffer_64);
    if (rc) return rc;
    rc_num = rc_num | data_buffer_64.insertFromRight((uint8_t) 0xFF, 63, 1);
    rc = fapiPutScom(i_target, DPHY01_DDRPHY_WC_CONFIG2_P0_0x8000CC020301143F, data_buffer_64);
    if (rc) return rc;

    rc = fapiGetScom(i_target, DPHY01_DDRPHY_WC_CONFIG2_P1_0x8001CC020301143F, data_buffer_64);
    if (rc) return rc;
    rc_num = rc_num | data_buffer_64.insertFromRight((uint8_t) 0xFF, 63, 1);
    rc = fapiPutScom(i_target, DPHY01_DDRPHY_WC_CONFIG2_P1_0x8001CC020301143F, data_buffer_64);
    if (rc) return rc;

    if(rc_num)
    {
	rc.setEcmdError(rc_num);
	return rc;
    }

    //Scoming in zeros into the Gate delay registers.
    for(port = 0; port < MAX_PORTS; port++)
    {

	for(rank_group = 0; rank_group < MAX_PRI_RANKS; rank_group++)
	{

	    //Check if rank group exists
	    if(primary_ranks_array[rank_group][port] != 255)
	    {

		   if ( port == 0 )
		   {

			if ( rank_group == 0 )
			{

			    GATE_DELAY_ADDR_0 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P0_0_0x800000130301143F;
			    GATE_DELAY_ADDR_1 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P0_1_0x800004130301143F;
			    GATE_DELAY_ADDR_2 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P0_2_0x800008130301143F;
			    GATE_DELAY_ADDR_3 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P0_3_0x80000C130301143F;
			    GATE_DELAY_ADDR_4 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P0_4_0x800010130301143F;

			}
			else if ( rank_group == 1 )
			{

			    GATE_DELAY_ADDR_0 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P0_0_0x800001130301143F;
			    GATE_DELAY_ADDR_1 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P0_1_0x800005130301143F;
			    GATE_DELAY_ADDR_2 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P0_2_0x800009130301143F;
			    GATE_DELAY_ADDR_3 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P0_3_0x80000D130301143F;
			    GATE_DELAY_ADDR_4 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P0_4_0x800011130301143F;

			}
			else if ( rank_group == 2 )
			{

			    GATE_DELAY_ADDR_0 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P0_0_0x800002130301143F;
			    GATE_DELAY_ADDR_1 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P0_1_0x800006130301143F;
			    GATE_DELAY_ADDR_2 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P0_2_0x80000A130301143F;
			    GATE_DELAY_ADDR_3 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P0_3_0x80000E130301143F;
			    GATE_DELAY_ADDR_4 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P0_4_0x800012130301143F;

			}
			else if ( rank_group == 3 )
			{

			    GATE_DELAY_ADDR_0 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P0_0_0x800003130301143F;
			    GATE_DELAY_ADDR_1 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P0_1_0x800007130301143F;
			    GATE_DELAY_ADDR_2 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P0_2_0x80000B130301143F;
			    GATE_DELAY_ADDR_3 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P0_3_0x80000F130301143F;
			    GATE_DELAY_ADDR_4 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P0_4_0x800013130301143F;

			}
		    }
		    else if (port == 1 )
		    {

			if ( rank_group == 0 )
			{

			    GATE_DELAY_ADDR_0 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P1_0_0x800100130301143F;
			    GATE_DELAY_ADDR_1 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P1_1_0x800104130301143F;
			    GATE_DELAY_ADDR_2 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P1_2_0x800108130301143F;
			    GATE_DELAY_ADDR_3 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P1_3_0x80010C130301143F;
			    GATE_DELAY_ADDR_4 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP0_P1_4_0x800110130301143F;

			}
			else if ( rank_group == 1 )
			{

			    GATE_DELAY_ADDR_0 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P1_0_0x800101130301143F;
			    GATE_DELAY_ADDR_1 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P1_1_0x800105130301143F;
			    GATE_DELAY_ADDR_2 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P1_2_0x800109130301143F;
			    GATE_DELAY_ADDR_3 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P1_3_0x80010D130301143F;
			    GATE_DELAY_ADDR_4 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP1_P1_4_0x800111130301143F;

			}
			else if ( rank_group == 2 )
			{

			    GATE_DELAY_ADDR_0 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P1_0_0x800102130301143F;
			    GATE_DELAY_ADDR_1 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P1_1_0x800106130301143F;
			    GATE_DELAY_ADDR_2 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P1_2_0x80010A130301143F;
			    GATE_DELAY_ADDR_3 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P1_3_0x80010E130301143F;
			    GATE_DELAY_ADDR_4 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP2_P1_4_0x800112130301143F;

			}
			else if ( rank_group == 3 )
			{

			    GATE_DELAY_ADDR_0 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P1_0_0x800103130301143F;
			    GATE_DELAY_ADDR_1 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P1_1_0x800107130301143F;
			    GATE_DELAY_ADDR_2 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P1_2_0x80010B130301143F;
			    GATE_DELAY_ADDR_3 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P1_3_0x80010F130301143F;
			    GATE_DELAY_ADDR_4 = DPHY01_DDRPHY_DP18_GATE_DELAY_RP3_P1_4_0x800113130301143F;

			}
		    }

		    rc_num = rc_num | data_buffer_64.flushTo0();
		    if(rc_num)
		    {
			rc.setEcmdError(rc_num);
			return rc;
		    }

		    //BLOCK 0
		    rc = fapiPutScom(i_target, GATE_DELAY_ADDR_0, data_buffer_64);
		    if (rc) return rc;
		    //BLOCK 1
		    rc = fapiPutScom(i_target, GATE_DELAY_ADDR_1, data_buffer_64);
		    if (rc) return rc;
		    //BLOCK 2
		    rc = fapiPutScom(i_target, GATE_DELAY_ADDR_2, data_buffer_64);
		    if (rc) return rc;
		    //BLOCK 3
		    rc = fapiPutScom(i_target, GATE_DELAY_ADDR_3, data_buffer_64);
		    if (rc) return rc;
		    //BLOCK 4
		    rc = fapiPutScom(i_target, GATE_DELAY_ADDR_4, data_buffer_64);
		    if (rc) return rc;


		}
	   }

	}


    return rc;
}



ReturnCode mss_rtt_nom_rtt_wr_swap(
            Target& i_target,
            uint8_t i_mbaPosition,
            uint32_t i_port_number,
            uint8_t i_rank,
	    uint32_t i_rank_pair_group,
            uint32_t& io_ccs_inst_cnt,
	    uint8_t& io_dram_rtt_nom_original
            )
{
    // Target MBA level
    // This is a function written specifically for mss_draminit_training
    // Meant for placing RTT_WR into RTT_NOM within MR1 before wr_lvl
    // If the function argument dram_rtt_nom_original has a value of 0xFF it will put the original rtt_nom there
    // and write rtt_wr to the rtt_nom value
    // If the function argument dram_rtt_nom_original has any value besides 0xFF it will try to write that value to rtt_nom.


    ReturnCode rc;
    ReturnCode rc_buff;
    uint32_t rc_num = 0;

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
    rc_num = rc_num | odt_4.setBit(0,4);
    ecmdDataBufferBase ddr_cal_type_4(4);

    ecmdDataBufferBase num_idles_16(16);
    ecmdDataBufferBase num_repeat_16(16);
    ecmdDataBufferBase data_20(20);
    ecmdDataBufferBase read_compare_1(1);
    ecmdDataBufferBase rank_cal_4(4);
    ecmdDataBufferBase ddr_cal_enable_1(1);
    ecmdDataBufferBase ccs_end_1(1);

    ecmdDataBufferBase mrs1_16(16);
    ecmdDataBufferBase mrs2_16(16);

    ecmdDataBufferBase data_buffer_64(64);

    uint16_t MRS1 = 0;
    uint16_t MRS2 = 0;
    uint8_t dimm = 0;
    uint8_t dimm_rank = 0;

    // dimm 0, dimm_rank 0-3 = ranks 0-3; dimm 1, dimm_rank 0-3 = ranks 4-7
    dimm = (i_rank) / 4;
    dimm_rank = i_rank - 4*dimm;


    uint8_t dimm_type;
    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target, dimm_type);
    if(rc) return rc;

    uint8_t is_sim = 0;
    rc = FAPI_ATTR_GET(ATTR_IS_SIMULATION, NULL, is_sim);
    if(rc) return rc;

    uint8_t address_mirror_map[2][2]; //address_mirror_map[port][dimm]
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_ADDRESS_MIRRORING, &i_target, address_mirror_map);
    if(rc) return rc;


    // Raise CKE high with NOPS, waiting min Reset CKE exit time (tXPR) - 400 cycles
    rc_num = rc_num | csn_8.setBit(0,8);
    rc_num = rc_num | address_16.clearBit(0, 16);
    rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 400, 0, 16);
    if(rc_num)
    {
	rc.setEcmdError(rc_num);
	return rc;
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

    rc_num = rc_num | csn_8.setBit(0,8);
    if (i_rank == 0)
    {
	rc_num = rc_num | csn_8.clearBit(0);
    }
    else if (i_rank == 1)
    {
	rc_num = rc_num | csn_8.clearBit(1);
    }
    else if (i_rank == 2)
    {
	rc_num = rc_num | csn_8.clearBit(2);
    }
    else if (i_rank == 3)
    {
	rc_num = rc_num | csn_8.clearBit(3);
    }
    else if (i_rank == 4)
    {
	rc_num = rc_num | csn_8.clearBit(4);
    }
    else if (i_rank == 5)
    {
	rc_num = rc_num | csn_8.clearBit(5);
    }
    else if (i_rank == 6)
    {
	rc_num = rc_num | csn_8.clearBit(6);
    }
    else if (i_rank == 7)
    {
	rc_num = rc_num | csn_8.clearBit(7);
    }

    // MRS CMD to CMD spacing = 12 cycles
    rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 12, 0, 16);
    if(rc_num)
    {
	rc.setEcmdError(rc_num);
	return rc;
    }

    FAPI_INF( "Editing RTT_NOM during wr_lvl for %s PORT: %d RP: %d", i_target.toEcmdString(), i_port_number, i_rank_pair_group);

    //MRS1
    // Get contents of MRS 1 Shadow Reg

    if (i_port_number == 0){
    	if (i_rank_pair_group == 0)
    	{
		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_PRI_RP0_P0_0x8000C01D0301143F, data_buffer_64);
	    	if(rc) return rc;
    	}
    	else if (i_rank_pair_group == 1)
    	{
		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_PRI_RP1_P0_0x8000C11D0301143F, data_buffer_64);
	    	if(rc) return rc;
    	}
    	else if (i_rank_pair_group == 2)
    	{
		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_PRI_RP2_P0_0x8000C21D0301143F, data_buffer_64);
	    	if(rc) return rc;
    	}
    	else if (i_rank_pair_group == 3)
    	{
		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_PRI_RP3_P0_0x8000C31D0301143F, data_buffer_64);
	    	if(rc) return rc;
    	}
    }
    else if (i_port_number == 1){
    	if (i_rank_pair_group == 0)
    	{
		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_PRI_RP0_P1_0x8001C01D0301143F, data_buffer_64);
	    	if(rc) return rc;
    	}
    	else if (i_rank_pair_group == 1)
    	{
		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_PRI_RP1_P1_0x8001C11D0301143F, data_buffer_64);
	    	if(rc) return rc;
    	}
    	else if (i_rank_pair_group == 2)
    	{
		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_PRI_RP2_P1_0x8001C21D0301143F, data_buffer_64);
	    	if(rc) return rc;
    	}
    	else if (i_rank_pair_group == 3)
    	{
		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_PRI_RP3_P1_0x8001C31D0301143F, data_buffer_64);
	    	if(rc) return rc;
    	}
    }

    rc_num = rc_num | data_buffer_64.reverse();
    rc_num = rc_num | mrs1_16.insert(data_buffer_64, 0, 16, 0);
    rc_num = rc_num | mrs1_16.extractPreserve(&MRS1, 0, 16, 0);
    if(rc_num)
    {
	rc.setEcmdError(rc_num);
	return rc;
    }
    FAPI_INF( "CURRENT MRS 1: 0x%04X", MRS1);

    uint8_t dll_enable = 0x00; //DLL Enable
    if (mrs1_16.isBitSet(0))
    {
	// DLL disabled
	dll_enable = 0xFF;
    }
    else if (mrs1_16.isBitClear(0))
    {
	// DLL enabled
	dll_enable = 0x00;
    }

    uint8_t out_drv_imp_cntl = 0x00;
    if ( (mrs1_16.isBitClear(1)) && (mrs1_16.isBitClear(5)) )
    {
	// out_drv_imp_ctrl set to 40 (Rzq/6)
	out_drv_imp_cntl = 0x00;
    }
    else if ( (mrs1_16.isBitSet(1)) && (mrs1_16.isBitClear(5)) )
    {
	// out_drv_imp_ctrl set to 34 (Rzq/7)
	out_drv_imp_cntl = 0x80;
    }

    uint8_t dram_rtt_nom = 0x00;
    if ( (mrs1_16.isBitClear(2)) && (mrs1_16.isBitClear(6)) && (mrs1_16.isBitClear(9)) )
    {
	// RTT_NOM set to disabled
	FAPI_INF( "DRAM_RTT_NOM orignally set to Disabled.");
	dram_rtt_nom = 0x00;

    }
    else if ( (mrs1_16.isBitClear(2)) && (mrs1_16.isBitClear(6)) && (mrs1_16.isBitSet(9)) )
    {
	// RTT_NOM set to 20
	FAPI_INF( "DRAM_RTT_NOM orignally set to 20 Ohm.");
	dram_rtt_nom = 0x20;
    }
    else if ( (mrs1_16.isBitSet(2)) && (mrs1_16.isBitClear(6)) && (mrs1_16.isBitSet(9)) )
    {
	// RTT_NOM set to 30
	FAPI_INF( "DRAM_RTT_NOM orignally set to 30 Ohm.");
	dram_rtt_nom = 0xA0;
    }
    else if ( (mrs1_16.isBitSet(2)) && (mrs1_16.isBitSet(6)) && (mrs1_16.isBitClear(9)) )
    {
	// RTT_NOM set to 40
	FAPI_INF( "DRAM_RTT_NOM orignally set to 40 Ohm.");
	dram_rtt_nom = 0xC0;
    }
    else if ( (mrs1_16.isBitSet(2)) && (mrs1_16.isBitSet(6)) && (mrs1_16.isBitClear(9)) )
    {
        // RTT_NOM set to 60
	FAPI_INF( "DRAM_RTT_NOM orignally set to 60 Ohm.");
	dram_rtt_nom = 0x80;
    }
    else if ( (mrs1_16.isBitClear(2)) && (mrs1_16.isBitSet(6)) && (mrs1_16.isBitClear(9)) )
    {
	// RTT_NOM set to 120
	FAPI_INF( "DRAM_RTT_NOM orignally set to 120 Ohm.");
	dram_rtt_nom = 0x40;
    }

    uint8_t dram_al = 0x00;
    if ( (mrs1_16.isBitClear(3)) && (mrs1_16.isBitClear(4)) )
    {
	//AL DISABLED
        dram_al = 0x00;
    }
    else if ( (mrs1_16.isBitSet(3)) && (mrs1_16.isBitClear(4)) )
    {
	// AL = CL -1
        dram_al = 0x80;
    }
    else if ( (mrs1_16.isBitClear(3)) && (mrs1_16.isBitSet(4)) )
    {
	// AL = CL -2
        dram_al = 0x40;
    }

    uint8_t wr_lvl = 0x00; //write leveling enable
    if (mrs1_16.isBitClear(7))
    {
	// WR_LVL DISABLED
        wr_lvl = 0x00;
    }
    else if (mrs1_16.isBitSet(7))
    {
	// WR_LVL ENABLED
        wr_lvl = 0xFF;
    }

    uint8_t tdqs_enable = 0x00; //TDQS Enable
    if (mrs1_16.isBitClear(11))
    {
	//TDQS DISABLED
        tdqs_enable = 0x00;
    }
    else if (mrs1_16.isBitSet(11))
    {
	//TDQS ENABLED
        tdqs_enable = 0xFF;
    }

    uint8_t q_off = 0x00; //Qoff - Output buffer Enable
    if (mrs1_16.isBitSet(12))
    {
	//Output Buffer Disabled
        q_off = 0xFF;
    }
    else if (mrs1_16.isBitClear(12))
    {
	//Output Buffer Enabled
        q_off = 0x00;
    }


    // Get contents of MRS 2 Shadow Reg
    if (i_port_number == 0){
    	if (i_rank_pair_group == 0)
    	{
		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_PRI_RP0_P0_0x8000C01E0301143F, data_buffer_64);
	    	if(rc) return rc;
	}
	else if (i_rank_pair_group == 1)
	{
		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_PRI_RP1_P0_0x8000C11E0301143F, data_buffer_64);
	    	if(rc) return rc;
        }
        else if (i_rank_pair_group == 2)
        {
	        rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_PRI_RP2_P0_0x8000C21E0301143F, data_buffer_64);
	    	if(rc) return rc;
        }
        else if (i_rank_pair_group == 3)
        {
     	        rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_PRI_RP3_P0_0x8000C31E0301143F, data_buffer_64);
	    	if(rc) return rc;
        }
    }
    else if (i_port_number == 1){
    	if (i_rank_pair_group == 0)
    	{
		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_PRI_RP0_P1_0x8001C01E0301143F, data_buffer_64);
	    	if(rc) return rc;
	}
	else if (i_rank_pair_group == 1)
	{
		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_PRI_RP1_P1_0x8001C11E0301143F, data_buffer_64);
	    	if(rc) return rc;
        }
        else if (i_rank_pair_group == 2)
        {
	        rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_PRI_RP2_P1_0x8001C21E0301143F, data_buffer_64);
	    	if(rc) return rc;
        }
        else if (i_rank_pair_group == 3)
        {
     	        rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_PRI_RP3_P1_0x8001C31E0301143F, data_buffer_64);
	    	if(rc) return rc;
        }
    }

    rc_num = rc_num | data_buffer_64.reverse();
    rc_num = rc_num | mrs2_16.insert(data_buffer_64, 0, 16, 0);
    rc_num = rc_num | mrs2_16.extractPreserve(&MRS2, 0, 16, 0);
    if(rc_num)
    {
	rc.setEcmdError(rc_num);
	return rc;
    }
    FAPI_INF( "MRS 2: 0x%04X", MRS2);

    uint8_t dram_rtt_wr = 0x00;
    if ( (mrs2_16.isBitClear(9)) && (mrs2_16.isBitClear(10)) )
    {
	//RTT WR DISABLE
	FAPI_INF( "DRAM_RTT_WR currently set to Disable.");
	dram_rtt_wr = 0x00;

	//RTT NOM CODE FOR THIS VALUE IS
	// dram_rtt_nom = 0x00

    }
    else if ( (mrs2_16.isBitSet(9)) && (mrs2_16.isBitClear(10)) )
    {
	//RTT WR 60 OHM
	FAPI_INF( "DRAM_RTT_WR currently set to 60 Ohm.");
	dram_rtt_wr = 0x80;

        //RTT NOM CODE FOR THIS VALUE IS
	// dram_rtt_nom = 0x80

    }
    else if ( (mrs2_16.isBitClear(9)) && (mrs2_16.isBitSet(10)) )
    {
	//RTT WR 120 OHM
	FAPI_INF( "DRAM_RTT_WR currently set to 120 Ohm.");
	dram_rtt_wr = 0x40;

        //RTT NOM CODE FOR THIS VALUE IS
	// dram_rtt_nom = 0x40

    }


    // If you have a 0 value in dram_rtt_nom_orignal
    // you will use dram_rtt_nom_original to save the original value
    if (io_dram_rtt_nom_original  == 0xFF)
    {
	io_dram_rtt_nom_original = dram_rtt_nom;
	dram_rtt_nom = dram_rtt_wr;

	if (dram_rtt_wr == 0x00)
	{
	    FAPI_INF( "DRAM_RTT_NOM to be set to DRAM_RTT_WR which is Disable.");
	}
	else if (dram_rtt_wr == 0x80)
	{
	    FAPI_INF( "DRAM_RTT_NOM to be set to DRAM_RTT_WR which is 60 Ohm.");
	}
	else if (dram_rtt_wr == 0x40)
	{
	    FAPI_INF( "DRAM_RTT_NOM to be set to DRAM_RTT_WR which is 120 Ohm.");
	}
    }
    else if (io_dram_rtt_nom_original != 0xFF)
    {
	dram_rtt_nom = io_dram_rtt_nom_original;

	if ( dram_rtt_nom == 0x00 )
	{
	    // RTT_NOM set to disabled
	    FAPI_INF( "DRAM_RTT_NOM being set back to Disabled.");

	}
	else if ( dram_rtt_nom == 0x20 )
	{
	    // RTT_NOM set to 20
	    FAPI_INF( "DRAM_RTT_NOM being set back to 20 Ohm.");
	}
	else if ( dram_rtt_nom == 0xA0 )
	{
	    // RTT_NOM set to 30
	    FAPI_INF( "DRAM_RTT_NOM being set back to 30 Ohm.");
	}
	else if ( dram_rtt_nom == 0xC0 )
	{
	    // RTT_NOM set to 40
	    FAPI_INF( "DRAM_RTT_NOM being set back to 40 Ohm.");
	}
	else if ( dram_rtt_nom == 0x80 )
	{
	    // RTT_NOM set to 60
	    FAPI_INF( "DRAM_RTT_NOM being set back to 60 Ohm.");
	}
	else if ( dram_rtt_nom == 0x40 )
	{
	    // RTT_NOM set to 120
	    FAPI_INF( "DRAM_RTT_NOM being set back to 120 Ohm.");
	}
	else
	{
	    FAPI_INF( "Proposed DRAM_RTT_NOM value is a non-supported.  Using Disabled.");
	    dram_rtt_nom = 0x00;
	}
    }


    rc_num = rc_num | mrs1_16.insert((uint8_t) dll_enable, 0, 1, 0);
    rc_num = rc_num | mrs1_16.insert((uint8_t) out_drv_imp_cntl, 1, 1, 0);
    rc_num = rc_num | mrs1_16.insert((uint8_t) dram_rtt_nom, 2, 1, 0);
    rc_num = rc_num | mrs1_16.insert((uint8_t) dram_al, 3, 2, 0);
    rc_num = rc_num | mrs1_16.insert((uint8_t) out_drv_imp_cntl, 5, 1, 1);
    rc_num = rc_num | mrs1_16.insert((uint8_t) dram_rtt_nom, 6, 1, 1);
    rc_num = rc_num | mrs1_16.insert((uint8_t) wr_lvl, 7, 1, 0);
    rc_num = rc_num | mrs1_16.insert((uint8_t) 0x00, 8, 1);
    rc_num = rc_num | mrs1_16.insert((uint8_t) dram_rtt_nom, 9, 1, 2);
    rc_num = rc_num | mrs1_16.insert((uint8_t) 0x00, 10, 1);
    rc_num = rc_num | mrs1_16.insert((uint8_t) tdqs_enable, 11, 1, 0);
    rc_num = rc_num | mrs1_16.insert((uint8_t) q_off, 12, 1, 0);
    rc_num = rc_num | mrs1_16.insert((uint8_t) 0x00, 13, 3);

    rc_num = rc_num | mrs1_16.extractPreserve(&MRS1, 0, 16, 0);
    FAPI_INF( "NEW MRS 1: 0x%04X", MRS1);

    // Copying the current MRS into address buffer matching the MRS_array order
    // Setting the bank address

    rc_num = rc_num | address_16.insert(mrs1_16, 0, 16, 0);
    rc_num = rc_num | bank_3.insert((uint8_t) MRS1_BA, 0, 1, 7);
    rc_num = rc_num | bank_3.insert((uint8_t) MRS1_BA, 1, 1, 6);
    rc_num = rc_num | bank_3.insert((uint8_t) MRS1_BA, 2, 1, 5);



    if ( ( address_mirror_map[i_port_number][dimm] & (0x08 >> dimm_rank) ) && (is_sim == 0))
    {
	//dimm and rank are only for print trace only, functionally not needed
	rc = mss_address_mirror_swizzle(i_target, i_port_number, dimm, dimm_rank, address_16, bank_3);
	if(rc) return rc;

    }

    if (rc_num)
    {
	FAPI_ERR( "mss_mrs_load: Error setting up buffers");
	rc_buff.setEcmdError(rc_num);
	return rc_buff;
    }

    ccs_end_1.setBit(0);

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

    uint32_t NUM_POLL = 100;
    rc = mss_execute_ccs_inst_array( i_target, NUM_POLL, 60);
    if(rc) return rc; //Error handling for mss_ccs_inst built into mss_funcs

    io_ccs_inst_cnt = 0;

    return rc;

}



fapi::ReturnCode mss_set_bbm_regs (const fapi::Target & mba_target)
{
    // Flash to registers.
	// disable0=dq bits, disable1=dqs (need to use swizzle),
	// wrclk_en=dqs follows quad, same as disable0

	const uint64_t disable_reg[MAX_PORTS][MAX_PRI_RANKS][DP18_INSTANCES] = {
	/* port 0 */
	{	// primary rank pair 0
	   {DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_0_0x8000007c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_1_0x8000047c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_2_0x8000087c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_3_0x80000c7c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_4_0x8000107c0301143F},
		// primary rank pair 1
	   {DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P0_0_0x8000017c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P0_1_0x8000057c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P0_2_0x8000097c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P0_3_0x80000d7c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P0_4_0x8000117c0301143F},
		// primary rank pair 2
	   {DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P0_0_0x8000027c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P0_1_0x8000067c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P0_2_0x80000a7c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P0_3_0x80000e7c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P0_4_0x8000127c0301143F},
		// primary rank pair 3
	   {DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P0_0_0x8000037c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P0_1_0x8000077c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P0_2_0x80000b7c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P0_3_0x80000f7c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P0_4_0x8000137c0301143F}
	},
	/* port 1 */
	{
	   // primary rank pair 0
	   {DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P1_0_0x8001007c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P1_1_0x8001047c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P1_2_0x8001087c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P1_3_0x80010c7c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P1_4_0x8001107c0301143F},
           // primary rank pair 1
	   {DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P1_0_0x8001017c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P1_1_0x8001057c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P1_2_0x8001097c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P1_3_0x80010d7c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P1_4_0x8001117c0301143F},
           // primary rank pair 2
	   {DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P1_0_0x8001027c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P1_1_0x8001067c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P1_2_0x80010a7c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P1_3_0x80010e7c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P1_4_0x8001127c0301143F},
           // primary rank pair 3
	   {DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P1_0_0x8001037c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P1_1_0x8001077c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P1_2_0x80010b7c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P1_3_0x80010f7c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P1_4_0x8001137c0301143F}
	}};
	const uint8_t rg_invalid[] = {
		ENUM_ATTR_EFF_PRIMARY_RANK_GROUP0_INVALID,
		ENUM_ATTR_EFF_PRIMARY_RANK_GROUP1_INVALID,
		ENUM_ATTR_EFF_PRIMARY_RANK_GROUP2_INVALID,
		ENUM_ATTR_EFF_PRIMARY_RANK_GROUP3_INVALID,
	};

	const uint8_t disable1_mask_lookup[4][DP18_INSTANCES][4] = { 	// for swizzle map
    // port 0
	//     q0   q1   q2   q3
      { {0xC0,0x30,0x03,0x0C},  // DP18 block 0 instance
        {0xC0,0x30,0x03,0x0C},  // ...  block 1
        {0xC0,0x30,0x0C,0x03},  // ...  block 2
        {0xC0,0x30,0x0C,0x03},  // ...  block 3
        {0xC0,0x30,0x0C,0x03}	// ...  block 4
      },
    // port 1
      { {0x30,0xC0,0x0C,0x03},	// 0xC0 = disable lanes 16,17
        {0x30,0xC0,0x0C,0x03},	// 0x30 = disable lanes 18,19
        {0xC0,0x30,0x0C,0x03},	// 0x0C = disable lanes 20,21
        {0xC0,0x30,0x0C,0x03},	// 0x03 = disable lanes 22,23
        {0xC0,0x30,0x03,0x0C}
      },
    // port 2
      { {0xC0,0x30,0x0C,0x03},
        {0xC0,0x30,0x03,0x0C},
        {0xC0,0x30,0x0C,0x03},
        {0xC0,0x30,0x0C,0x03},
        {0xC0,0x30,0x0C,0x03}
      },
    // port 3
      { {0xC0,0x30,0x0C,0x03},
        {0xC0,0x30,0x0C,0x03},
        {0xC0,0x30,0x03,0x0C},
        {0x30,0xC0,0x0C,0x03},
        {0xC0,0x30,0x0C,0x03}
      }
    };

	const uint16_t wrclk_disable_mask[] = {		// by quads
		0x8800, 0x4400, 0x2280, 0x1140
	};

	uint8_t l_dram_width, l_mbaPos;
	uint64_t l_addr;
	// 0x8000007d0301143f
	const uint64_t l_disable1_addr_offset = 0x0000000100000000ull;	// from disable0 register
	// 0x800000050301143f
	const uint64_t l_wrclk_en_addr_mask   = 0xFFFFFF07FFFFFFFFull;	// from disable1 register

	ReturnCode rc;
	ecmdDataBufferBase data_buffer(64);
	ecmdDataBufferBase db_reg(BITS_PER_PORT);
	uint32_t l_ecmdRc = ECMD_DBUF_SUCCESS;
	uint8_t prg[MAX_PRI_RANKS][MAX_PORTS];			// primary rank group values

	FAPI_INF("Running set bad bits FN:mss_set_bbm_regs,"
			" input Target: %s", mba_target.toEcmdString());

	std::vector<Target> mba_dimms;
	fapiGetAssociatedDimms(mba_target, mba_dimms);	// functional dimms

	FAPI_INF("***-------- Found %i functional DIMMS --------***",
			mba_dimms.size());

	//	ATTR_EFF_PRIMARY_RANK_GROUP0[port], GROUP1[port], GROUP2[port], GROUP3[port]
	rc=FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP0, &mba_target, prg[0]);
	if(rc) return rc;
	rc=FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP1, &mba_target, prg[1]);
	if(rc) return rc;
	rc=FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP2, &mba_target, prg[2]);
	if(rc) return rc;
	rc=FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP3, &mba_target, prg[3]);
	if(rc) return rc;

	rc=FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &mba_target, l_mbaPos);
	if(rc) return rc;

	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &mba_target, l_dram_width);
	if(rc) return rc;

	switch (l_dram_width)
	{
		case ENUM_ATTR_EFF_DRAM_WIDTH_X4:
			l_dram_width = 4;
			break;
		case ENUM_ATTR_EFF_DRAM_WIDTH_X8:
			l_dram_width = 8;
			break;
		case ENUM_ATTR_EFF_DRAM_WIDTH_X16:
			l_dram_width = 16;
			break;
		case ENUM_ATTR_EFF_DRAM_WIDTH_X32:
			l_dram_width = 32;
			break;
		default:
			FAPI_ERR("ATTR_EFF_DRAM_WIDTH is invalid %u", l_dram_width);
			FAPI_SET_HWP_ERROR(rc, RC_MSS_IMP_INPUT_ERROR);
			return rc;
	}

	l_ecmdRc = data_buffer.flushTo0();
	if (l_ecmdRc != ECMD_DBUF_SUCCESS)
	{
		 FAPI_ERR("Error from ecmdDataBuffer flushTo0() "
				 "- rc 0x%.8X", l_ecmdRc);

		 rc.setEcmdError(l_ecmdRc);
		 return rc;
	}
	for (uint8_t port = 0; port < MAX_PORTS; port++ )	// [0:1]
	{
		uint8_t aport = (l_mbaPos*2) + port;

		// loop through primary ranks [0:3]
		for (uint8_t prank = 0; prank < MAX_PRI_RANKS; prank++ )
		{
			uint8_t dimm = prg[prank][port] >> 2;
			uint8_t rank = prg[prank][port] & 0x03;
			uint16_t l_data = 0;

			if (prg[prank][port] == rg_invalid[prank])	// invalid rank
			{
				FAPI_INF("Primary rank group %i is INVALID, continuing...",
						prank);
				continue;
			}

			rc = getC4dq2reg(mba_target, port, dimm, rank, db_reg);
			if (rc)
			{
				FAPI_ERR("Error from getting register bitmap port=%i: "
						"dimm=%i, rank=%i rc=%i", port, dimm, rank,
						static_cast<uint32_t>(rc));
				return rc;
			}
			// quick test to move on to next rank if no bits need to be set
			if (db_reg.getNumBitsSet(0, BITS_PER_PORT) == 0)
			{
				FAPI_INF("No bad bits found for p%i:d%i:r%i(rg%i):cs%i",
						port, dimm, rank, prank, prg[prank][port]);
				continue;
			}

			for ( uint8_t i=0; i < DP18_INSTANCES; i++ ) // dp18 [0:4]
			{
				uint16_t disable1_data = 0;
				uint16_t wrclk_mask = 0;

				// check or not to check(always set register)?
				l_data = db_reg.getHalfWord(i);
				if (l_data == 0)
				{
					FAPI_INF("DP18_%i has no bad bits set, continuing...", i);
					continue;
				}
				// clear bits 48:63
				l_ecmdRc = data_buffer.flushTo0();
				if (l_ecmdRc != ECMD_DBUF_SUCCESS)
				{
					 FAPI_ERR("Error from ecmdDataBuffer flushTo0() "
							 "- rc 0x%.8X", l_ecmdRc);

					 rc.setEcmdError(l_ecmdRc);
					 return rc;
				}

				if (l_dram_width == 4) {		// disable entire nibble if bad bit found
					uint16_t mask = 0xF000;
					for (uint8_t n=0; n < 4; n++) {	// check each nibble
						uint16_t nmask = mask >> (4*n);
						if ((nmask & l_data) > 0) {
							l_data = l_data | nmask;
							FAPI_INF("Disabling nibble %i",n);
						}
					}
				}

				l_ecmdRc = data_buffer.setHalfWord(3, l_data);
				if (l_ecmdRc != ECMD_DBUF_SUCCESS)
				{
					 FAPI_ERR("Error from ecmdDataBuffer setHalfWord() "
							 "- rc 0x%.8X", l_ecmdRc);

					 rc.setEcmdError(l_ecmdRc);
					 return rc;
				}

				l_addr = disable_reg[port][prank][i];

				FAPI_INF("+++ Setting Disable0 Bad Bit Mask p%i: DIMM%i PRG%i "
					"Rank%i \tdp18_%i addr=0x%llx, data=0x%04X", port,
					dimm, prank, prg[prank][port], i, l_addr , l_data);

//				rc = fapiPutScom(mba_target, l_addr, data_buffer);
				rc = fapiPutScomUnderMask(mba_target, l_addr, data_buffer, data_buffer);
				if (rc)
				{
					FAPI_ERR("Error from fapiPutScom writing disable0 reg");
					return rc;
				}

				if (l_dram_width == 4) {
					uint16_t bn_mask = 0xF000;
					uint16_t mask;
					for (uint8_t q=0; q < 4; q++) {
						mask = bn_mask >> (4*q);
						if ((l_data & mask) == mask) {
							disable1_data |= disable1_mask_lookup[aport][i][q];
							wrclk_mask |= wrclk_disable_mask[q];
	FAPI_DBG("x4 disable1_data=0x%04X, wrclk_mask=0x%04X",disable1_data,wrclk_mask);
						}
					}
				} else {
					uint16_t bn_mask = 0xFF00;
					uint16_t mask;
					for (uint8_t q=0; q < 4; q=q+2) {
						mask = bn_mask >> (4*q);
						if ((l_data & mask) == mask) {
							disable1_data |= disable1_mask_lookup[aport][i][q] |
								disable1_mask_lookup[aport][i][q+1];
							wrclk_mask |= wrclk_disable_mask[q] | wrclk_disable_mask[q+1];
	FAPI_DBG("x8 disable1_data=0x%04X, wrclk_mask=0x%04X",disable1_data,wrclk_mask);
						}
					}
				}

				if (disable1_data != 0) {
					// shift over 8 bits since disable1_lookup is 8 bits, and reg is 16
					disable1_data = disable1_data << 8;
					l_addr += l_disable1_addr_offset;	// set address for disable1 reg

					l_ecmdRc = data_buffer.flushTo0();	// clear buffer
					if (l_ecmdRc != ECMD_DBUF_SUCCESS)
					{
						 FAPI_ERR("Error from ecmdDataBuffer flushTo0() "
								 "- rc 0x%.8X", l_ecmdRc);

						 rc.setEcmdError(l_ecmdRc);
						 return rc;
					}

					l_ecmdRc = data_buffer.setHalfWord(3, disable1_data);
					if (l_ecmdRc != ECMD_DBUF_SUCCESS)
					{
						 FAPI_ERR("Error from ecmdDataBuffer setHalfWord() "
								 "- rc 0x%.8X", l_ecmdRc);

						 rc.setEcmdError(l_ecmdRc);
						 return rc;
					}

					// write disable1 register
//					rc = fapiPutScom(mba_target, l_addr, data_buffer);
					rc = fapiPutScomUnderMask(mba_target, l_addr, data_buffer, data_buffer);
					if (rc)
					{
						FAPI_ERR("Error from fapiPutScom writing disable1 reg");
						return rc;
					}

//  for DD1.X chips since disable1 register not fully working... can take out wrclk stuff for DD2+
					l_addr &= l_wrclk_en_addr_mask;		// set address for wrclk_en register

					l_ecmdRc = data_buffer.flushTo0();	// clear buffer
					if (l_ecmdRc != ECMD_DBUF_SUCCESS)
					{
						 FAPI_ERR("Error from ecmdDataBuffer flushTo0() "
								 "- rc 0x%.8X", l_ecmdRc);

						 rc.setEcmdError(l_ecmdRc);
						 return rc;
					}

					ecmdDataBufferBase put_mask(64);
					l_ecmdRc = put_mask.setHalfWord(3, wrclk_mask);
					if (l_ecmdRc != ECMD_DBUF_SUCCESS)
					{
						 FAPI_ERR("Error from ecmdDataBuffer setHalfWord() for wrclk_mask"
								 "- rc 0x%.8X", l_ecmdRc);

						 rc.setEcmdError(l_ecmdRc);
						 return rc;
					}
					// clear(0) out the unused quads
					rc = fapiPutScomUnderMask(mba_target, l_addr, data_buffer, put_mask);
					if (rc)
					{
						FAPI_ERR("Error from fapiPutScomUnderMask writing wrclk_en reg");
						return rc;
					}
				}
			} // end DP18 instance loop
		} // end primary rank loop
	} // end port loop
    return rc;
} // end mss_set_bbm_regs



fapi::ReturnCode mss_get_bbm_regs (const fapi::Target & mba_target)
{
// Registers to Flash.

	const uint64_t disable_reg[MAX_PORTS][MAX_PRI_RANKS][DP18_INSTANCES] = {
	/* port 0 */
	{	// primary rank pair 0
	   {DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_0_0x8000007c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_1_0x8000047c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_2_0x8000087c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_3_0x80000c7c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_4_0x8000107c0301143F},
		// primary rank pair 1
	   {DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P0_0_0x8000017c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P0_1_0x8000057c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P0_2_0x8000097c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P0_3_0x80000d7c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P0_4_0x8000117c0301143F},
		// primary rank pair 2
	   {DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P0_0_0x8000027c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P0_1_0x8000067c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P0_2_0x80000a7c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P0_3_0x80000e7c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P0_4_0x8000127c0301143F},
		// primary rank pair 3
	   {DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P0_0_0x8000037c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P0_1_0x8000077c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P0_2_0x80000b7c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P0_3_0x80000f7c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P0_4_0x8000137c0301143F}
	},
	/* port 1 */
	{
	   // primary rank pair 0
	   {DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P1_0_0x8001007c0301143F,
		DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P1_1_0x8001047c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P1_2_0x8001087c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P1_3_0x80010c7c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P1_4_0x8001107c0301143F},
           // primary rank pair 1
	   {DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P1_0_0x8001017c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P1_1_0x8001057c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P1_2_0x8001097c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P1_3_0x80010d7c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P1_4_0x8001117c0301143F},
           // primary rank pair 2
	   {DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P1_0_0x8001027c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P1_1_0x8001067c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P1_2_0x80010a7c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P1_3_0x80010e7c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P1_4_0x8001127c0301143F},
           // primary rank pair 3
	   {DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P1_0_0x8001037c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P1_1_0x8001077c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P1_2_0x80010b7c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P1_3_0x80010f7c0301143F,
	    DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P1_4_0x8001137c0301143F}

	}};

	const uint8_t rg_invalid[] = {
		ENUM_ATTR_EFF_PRIMARY_RANK_GROUP0_INVALID,
		ENUM_ATTR_EFF_PRIMARY_RANK_GROUP1_INVALID,
		ENUM_ATTR_EFF_PRIMARY_RANK_GROUP2_INVALID,
		ENUM_ATTR_EFF_PRIMARY_RANK_GROUP3_INVALID,
	};

    ReturnCode rc;
    ecmdDataBufferBase data_buffer(64);
    ecmdDataBufferBase db_reg(BITS_PER_PORT);
	uint32_t l_ecmdRc = ECMD_DBUF_SUCCESS;
	uint8_t prg[MAX_PRI_RANKS][MAX_PORTS];			// primary rank group values
	uint8_t l_dram_width;

	FAPI_INF("Running set bad bits FN:mss_set_bbm_regs \n"
			" input Target: %s", mba_target.toEcmdString());

	std::vector<Target> mba_dimms;
	fapiGetAssociatedDimms(mba_target, mba_dimms);	// functional dimms

	FAPI_INF("***-------- Found %i functional DIMMS --------***",
			mba_dimms.size());

	// 4 dimms per MBA, 2 per port

	//	ATTR_EFF_PRIMARY_RANK_GROUP0[port], GROUP1[port], GROUP2[port], GROUP3[port]
	rc=FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP0, &mba_target, prg[0]);
	if(rc) return rc;
	rc=FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP1, &mba_target, prg[1]);
	if(rc) return rc;
	rc=FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP2, &mba_target, prg[2]);
	if(rc) return rc;
	rc=FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP3, &mba_target, prg[3]);
	if(rc) return rc;

	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &mba_target, l_dram_width);
	if(rc) return rc;

	switch (l_dram_width)
	{
		case ENUM_ATTR_EFF_DRAM_WIDTH_X4:
			l_dram_width = 4;
			break;
		case ENUM_ATTR_EFF_DRAM_WIDTH_X8:
			l_dram_width = 8;
			break;
		case ENUM_ATTR_EFF_DRAM_WIDTH_X16:
			l_dram_width = 16;
			break;
		case ENUM_ATTR_EFF_DRAM_WIDTH_X32:
			l_dram_width = 32;
			break;
		default:
			FAPI_ERR("ATTR_EFF_DRAM_WIDTH is invalid %u", l_dram_width);
			FAPI_SET_HWP_ERROR(rc, RC_MSS_IMP_INPUT_ERROR);
			return rc;
	}

	l_ecmdRc = data_buffer.flushTo0();
	if (l_ecmdRc != ECMD_DBUF_SUCCESS)
	{
		 FAPI_ERR("Error from ecmdDataBuffer flushTo0() "
				 "- rc 0x%.8X", l_ecmdRc);

		 rc.setEcmdError(l_ecmdRc);
		 return rc;
	}
	for (uint8_t port = 0; port < MAX_PORTS; port++ )	// [0:1]
	{
		// loop through primary ranks [0:3]
		for (uint8_t prank = 0; prank < MAX_PRI_RANKS; prank++ )
		{
			uint8_t dimm = prg[prank][port] >> 2;
			uint8_t rank = prg[prank][port] & 0x03;
			uint16_t l_data = 0;

			if (prg[prank][port] == rg_invalid[prank])	// invalid rank
			{
				FAPI_INF("Primary rank group %i is INVALID, continuing...",
						prank);
				continue;
			}

			for ( uint8_t i=0; i < DP18_INSTANCES; i++ ) // dp18 [0:4]
			{

				// clear bits 48:63
				l_ecmdRc = data_buffer.clearBit(48, BITS_PER_REG);
				if (l_ecmdRc != ECMD_DBUF_SUCCESS)
				{
					 FAPI_ERR("Error from ecmdDataBuffer setHalfWord() "
							 "- rc 0x%.8X", l_ecmdRc);

					 rc.setEcmdError(l_ecmdRc);
					 return rc;
				}

				rc = fapiGetScom(mba_target, disable_reg[port][prank][i],
						data_buffer);
				if (rc)
				{
					FAPI_ERR("Error from fapiPutScom writing disable reg");
					return rc;
				}

				l_data = data_buffer.getHalfWord(3);
				if (l_ecmdRc != ECMD_DBUF_SUCCESS)
				{
					 FAPI_ERR("Error from ecmdDataBuffer setHalfWord() "
							 "- rc 0x%.8X", l_ecmdRc);

					 rc.setEcmdError(l_ecmdRc);
					 return rc;
				}

				if (l_dram_width == 4) {		// disable entire nibble if bad bit found
					uint16_t mask = 0xF000;
					for (uint8_t n=0; n < 4; n++) {	// check each nibble
						uint16_t nmask = mask >> (4*n);
						if ((nmask & l_data) > 0) {
							l_data = l_data | nmask;
							FAPI_INF("Disabling nibble %i",n);
						}
					}
				}

				l_ecmdRc |= db_reg.setHalfWord(i, l_data);
				if (l_ecmdRc != ECMD_DBUF_SUCCESS)
				{
					 FAPI_ERR("Error from ecmdDataBuffer setHalfWord() "
							 "- rc 0x%.8X", l_ecmdRc);

					 rc.setEcmdError(l_ecmdRc);
					 return rc;
				}

				FAPI_INF("+++ Setting Bad Bit Mask p%i: DIMM%i PRG%i "
					"Rank%i \tdp18_%i addr=0x%llx, data=0x%04X", port,
					dimm, prank, prg[prank][port], i,
					disable_reg[port][prank][i], l_data);

			} // end DP18 instance loop

			rc = setC4dq2reg(mba_target, port, dimm, rank, db_reg);
			if (rc)
			{
				FAPI_ERR("Error from setting register bitmap p%i: "
						"dimm=%i, rank=%i rc=%i", port, dimm, rank,
						static_cast<uint32_t>(rc));
				return rc;
			}

		} // end primary rank loop
	} // end port loop
    return rc;
} // end mss_get_bbm_regs


// output reg = in phy based order
ReturnCode getC4dq2reg(const Target & i_mba, const uint8_t i_port, const uint8_t i_dimm, const uint8_t i_rank, ecmdDataBufferBase &o_reg)
{
	// [port][bits per port]
    const uint8_t lookup[4][BITS_PER_PORT] = {
	// port 0
	{65,66,67,64, 70,69,68,71, 21,20,23,22, 18,16,19,17,	// DP18 block 0
	 61,63,60,62, 57,58,59,56, 73,74,75,72, 78,77,79,76,	// ...  block 1
	  7, 5, 4, 6,  0, 2, 1, 3, 12,13,15,14, 10, 8,11, 9, 	// ...  block 2
	 47,44,46,45, 43,42,41,40, 31,29,30,28, 26,24,27,25,	// ...  block 3
	 55,53,54,52, 50,48,49,51, 33,34,35,32, 36,37,38,39},	// ...  block 4
	// port 1
	{17,16,18,19, 20,21,22,23,  2, 0, 3, 1,  7, 4, 5, 6,
	 70,71,69,68, 66,64,67,65, 27,24,26,25, 29,30,31,28,
	 37,36,38,39, 35,32,34,33, 77,76,79,78, 73,75,72,74,
	 40,42,41,43, 45,44,46,47,  9,11, 8,10, 12,13,14,15,
	 48,51,49,50, 52,53,54,55, 61,63,62,60, 56,58,59,57},
	// port 2
	{22,23,20,21, 19,16,17,18, 26,25,24,27, 29,28,31,30,
	 67,64,65,66, 71,70,69,68,  7, 5, 6, 4,  2, 0, 3, 1,
	 45,44,47,46, 42,43,41,40, 39,38,37,36, 33,34,35,32,
	 48,50,49,51, 54,52,53,55, 15,13,12,14,  9, 8,10,11,
	 61,60,62,63, 59,56,58,57, 74,72,73,75, 76,79,78,77},
	// port 3
	{25,26,27,24, 28,31,29,30, 17,19,16,18, 20,21,23,22,
	 64,67,66,65, 71,69,68,70, 75,74,72,73, 76,77,79,78,
	  4, 5, 7, 6,  0, 1, 2, 3, 12,13,14,15,  8, 9,11,10,
	 47,45,46,44, 43,41,42,40, 35,32,33,34, 39,37,36,38,
	 55,52,53,54, 51,48,49,50, 60,62,61,63, 57,59,56,58}
    };

    uint8_t l_bbm[TOTAL_BYTES] = {0};	// bad bitmap from dimmGetBadDqBitmap
    ecmdDataBufferBase c4dqbmp(BITS_PER_PORT);	// databuffer of C4 dq bitmap
    ReturnCode rc;
    uint8_t l_port = i_port;	// port # relative to Centaur
    uint8_t mba_pos = 0;
    uint32_t ecmdrc = ECMD_DBUF_SUCCESS;

    ecmdrc = o_reg.flushTo0();		// clear output databuffer
    if (ecmdrc != ECMD_DBUF_SUCCESS)
    {
	FAPI_ERR("Error from ecmdDataBuffer flushTo0() "
		 "- rc 0x%.8X", ecmdrc);

	rc.setEcmdError(ecmdrc);
	return rc;
    }
    rc=FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_mba, mba_pos);
    if (rc)
    {
	FAPI_ERR("Error getting ATTR_CHIP_UNIT_POS for MBA");
	return (rc);
    }

    // get Centaur dq bitmap (C4 signal) order=[0:79], array of bytes
    rc = dimmGetBadDqBitmap(i_mba, i_port, i_dimm, i_rank, l_bbm);
    if (rc)
    {
	FAPI_ERR("Error from dimmGetBadDqBitmap on MBA%ip%i: "
		 "dimm=%i, rank=%i rc=%i", mba_pos, i_port, i_dimm, i_rank,
		 static_cast<uint32_t>(rc));
	return rc;
    }

    // create databuffer from C4 dq bitmap array
    ecmdrc = c4dqbmp.insertFromRight(l_bbm, 0, BITS_PER_PORT);
    if (ecmdrc != ECMD_DBUF_SUCCESS)
    {
        FAPI_ERR("Error from ecmdDataBuffer insertFromRight() "
            "- rc 0x%.8X", ecmdrc);

        rc.setEcmdError(ecmdrc);
        return rc;
    }

    // quick check if there no bits on, we're done
    if (c4dqbmp.getNumBitsSet(0, BITS_PER_PORT) == 0)
    {
	return rc;
    }
    l_port = i_port + (mba_pos * MAX_PORTS);	// relative to Centaur

    for (uint8_t i=0; i < BITS_PER_PORT; i++)
    {
	if (c4dqbmp.isBitSet(lookup[l_port][i]))
	{
	    o_reg.setBit(i);
	    FAPI_DBG("set bad bit C4_dq=%i,\t dp18_%i_lane%i\t (bit %i)",
		     lookup[l_port][i], (i / 16), (i % 16), i);
	}
    }

    return rc;
}

ReturnCode setC4dq2reg(const Target &i_mba, const uint8_t i_port, const uint8_t i_dimm, const uint8_t i_rank, ecmdDataBufferBase &o_reg)
{

	const uint8_t lookup[4][BITS_PER_PORT] = {
	// port 0
	{65,66,67,64,70,69,68,71,21,20,23,22,18,16,19,17,	// DP18 block 0
	 61,63,60,62,57,58,59,56,73,74,75,72,78,77,79,76,	// ...  block 1
	  7, 5, 4, 6, 0, 2, 1, 3,12,13,15,14,10, 8,11, 9, 	// ...  block 2
	 47,44,46,45,43,42,41,40,31,29,30,28,26,24,27,25,	// ...  block 3
	 55,53,54,52,50,48,49,51,33,34,35,32,36,37,38,39},	// ...  block 4
	// port 1
	{17,16,18,19,20,21,22,23, 2, 0, 3, 1, 7, 4, 5, 6,
	 70,71,69,68,66,64,67,65,27,24,26,25,29,30,31,28,
	 37,36,38,39,35,32,34,33,77,76,79,78,73,75,72,74,
	 40,42,41,43,45,44,46,47, 9,11, 8,10,12,13,14,15,
	 48,51,49,50,52,53,54,55,61,63,62,60,56,58,59,57},
	// port 2
	{22,23,20,21,19,16,17,18,26,25,24,27,29,28,31,30,
	 67,64,65,66,71,70,69,68, 7, 5, 6, 4, 2, 0, 3, 1,
	 45,44,47,46,42,43,41,40,39,38,37,36,33,34,35,32,
	 48,50,49,51,54,52,53,55,15,13,12,14, 9, 8,10,11,
	 61,60,62,63,59,56,58,57,74,72,73,75,76,79,78,77},
	// port 3
	{25,26,27,24,28,31,29,30,17,19,16,18,20,21,23,22,
	 64,67,66,65,71,69,68,70,75,74,72,73,76,77,79,78,
	  4, 5, 7, 6, 0, 1, 2, 3,12,13,14,15, 8, 9,11,10,
	 47,45,46,44,43,41,42,40,35,32,33,34,39,37,36,38,
	 55,52,53,54,51,48,49,50,60,62,61,63,57,59,56,58}
	};
	uint8_t l_bbm [TOTAL_BYTES] = {0};
	ecmdDataBufferBase c4dqbmp(BITS_PER_PORT);
	ReturnCode rc;
	uint8_t l_port = i_port;
	uint8_t mba_pos = 0;
	uint32_t ecmdrc = ECMD_DBUF_SUCCESS;

        // clear output databuffer
	ecmdrc = c4dqbmp.flushTo0();
	if (ecmdrc != ECMD_DBUF_SUCCESS)
	{
		FAPI_ERR("Error from ecmdDataBuffer flushTo0() "
			"- rc 0x%.8X", ecmdrc);

		rc.setEcmdError(ecmdrc);
		return rc;
	}

	// Set Port info
	rc=FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_mba, mba_pos);
	if (rc)
	{
		FAPI_ERR("Error getting ATTR_CHIP_UNIT_POS for MBA");
		return (rc);
	}

	l_port = i_port + (mba_pos * MAX_PORTS);

	// translate c4 from input
	for (uint8_t i=0; i < BITS_PER_PORT; i++)
	{
		if (o_reg.isBitSet(i))
		{
		    c4dqbmp.setBit(lookup[l_port][i]);
		}
	}

	// create array from databuffer
	for (uint8_t b=0; b < TOTAL_BYTES; b++)
	{
		l_bbm[b] = c4dqbmp.getByte(b);
	}

	// set Centaur dq bitmap (C4 signal) order=[0:79], array of bytes
	rc = dimmSetBadDqBitmap(i_mba, i_port, i_dimm, i_rank, l_bbm);
	if (rc)
	{
		FAPI_ERR("Error from dimmSetBadDqBitmap on MBA%ip%i: "
				"dimm=%i, rank=%i rc=%i", mba_pos, i_port, i_dimm, i_rank,
				static_cast<uint32_t>(rc));
		return rc;
	}

	return rc;
}

} //end extern C

