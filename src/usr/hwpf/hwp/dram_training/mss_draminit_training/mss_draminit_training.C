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
// $Id: mss_draminit_training.C,v 1.51 2013/01/31 22:33:54 gollub Exp $
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|------------------------------------------------
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
//         |          |         | and disable regs to Bad Bit Mask function.
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
ReturnCode mss_check_cal_status(Target& i_target, uint8_t i_port, uint8_t i_group,  mss_draminit_training_result& io_status);
ReturnCode mss_check_error_status(Target& i_target, uint8_t i_port, uint8_t i_group,  mss_draminit_training_result& io_status);
ReturnCode mss_rtt_nom_rtt_wr_swap( Target& i_target, uint32_t i_port_number, uint8_t i_rank, uint32_t i_rank_pair_group, uint32_t& io_ccs_inst_cnt);
ReturnCode getC4dq2reg(const Target &i_mba, const uint8_t i_port, const uint8_t i_dimm, const uint8_t i_rank, ecmdDataBufferBase &o_reg);
ReturnCode setC4dq2reg(const Target &i_mba, const uint8_t i_port, const uint8_t i_dimm, const uint8_t i_rank, ecmdDataBufferBase &o_reg);
ReturnCode mss_set_bbm_regs (const fapi::Target & mba_target);
ReturnCode mss_get_bbm_regs (const fapi::Target & mba_target);


ReturnCode mss_draminit_training(Target& i_target)
{
    // Target is centaur.mba
    
    fapi::ReturnCode l_rc;
    
    l_rc = mss_draminit_training_cloned(i_target);
    
	// If mss_unmask_draminit_training_errors gets it's own bad rc,
	// it will commit the passed in rc (if non-zero), and return it's own bad rc.
	// Else if mss_unmask_draminit_training_errors runs clean, 
	// it will just return the passed in rc.
	l_rc = mss_unmask_draminit_training_errors(i_target, l_rc);

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

    const uint32_t NUM_POLL = 100;

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
    uint64_t ADDR_0 = 0;
    uint64_t ADDR_1 = 0;
    uint64_t ADDR_2 = 0;
    uint64_t ADDR_3 = 0;
    uint64_t ADDR_4 = 0;
    
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

    //Get which training steps we are to run
    rc = FAPI_ATTR_GET(ATTR_MSS_CAL_STEP_ENABLE, &i_target, cal_steps);
    if(rc) return rc;
    rc_num = rc_num | cal_steps_8.insert(cal_steps, 0, 8, 0);

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


    //rc = mss_set_bbm_regs (i_target);
    //if(rc)
    //{
	//FAPI_ERR( "Error Moving bad bit information to the Phy regs. Exiting.");
	//return rc;
    //}

    if ( ( cal_steps_8.isBitSet(0) ) ||
	 ( (cal_steps_8.isBitClear(0)) && (cal_steps_8.isBitClear(1)) &&
	   (cal_steps_8.isBitClear(2)) && (cal_steps_8.isBitClear(3)) &&
	   (cal_steps_8.isBitClear(4)) && (cal_steps_8.isBitClear(5)) &&
	   (cal_steps_8.isBitClear(6)) && (cal_steps_8.isBitClear(7)) ))
    {
	FAPI_INF( "Performing External ZQ Calibration.");

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

		// Temporarily disable this function for HW debug
	        // Change the RTT_NOM to RTT_WR, RTT_WR to RTT_NOM
		//rc = mss_rtt_nom_rtt_wr_swap(i_target, port, primary_ranks_array[group][port], group, instruction_number);
                if(rc) return rc;


	        //Set up for Init Cal - Done per port pair
		rc_num = rc_num | test_buffer_4.setBit(0, 2); //Init Cal test = 11XX
		rc_num = rc_num | wen_buffer_1.flushTo1(); //Init Cal ras/cas/we = 1/1/1
		rc_num = rc_num | casn_buffer_1.flushTo1();
		rc_num = rc_num | rasn_buffer_1.flushTo1();
		rc_num = rc_num | ddr_cal_enable_buffer_1.flushTo1(); //Init cal

		FAPI_INF( "+++ Setting up Init Cal on rank group: %d cal_steps: 0x%02X +++", group, cal_steps);

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
			FAPI_INF( "+++ Executing ALL Cal Steps at the same time on rank group: %d +++", group);
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
			FAPI_INF( "+++ Write Leveling (WR_LVL) on rank group: %d +++", group);
			rc_num = rc_num | data_buffer_64.setBit(48);
		    }
		    else if ( (cur_cal_step == 2) && (cal_steps_8.isBitSet(2)) )
		    {
			FAPI_INF( "+++ DQS Align (DQS_ALIGN) on rank group: %d +++", group);
			rc_num = rc_num | data_buffer_64.setBit(50);
		    }
		    else if ( (cur_cal_step == 3) && (cal_steps_8.isBitSet(3)) )
		    {
			FAPI_INF( "+++ RD CLK Align (RDCLK_ALIGN) on rank group: %d +++", group);
			rc_num = rc_num | data_buffer_64.setBit(51);
		    }
		    else if ( (cur_cal_step == 4) && (cal_steps_8.isBitSet(4)) )
		    {
			FAPI_INF( "+++ Read Centering (READ_CTR) on rank group: %d +++", group);
			rc_num = rc_num | data_buffer_64.setBit(52);
		    }
		    else if ( (cur_cal_step == 5) && (cal_steps_8.isBitSet(5)) )
		    {
			FAPI_INF( "+++ Write Centering (WRITE_CTR) on rank group: %d +++", group);
			rc_num = rc_num | data_buffer_64.setBit(53);
		    }
		    else if ( (cur_cal_step == 6) && (cal_steps_8.isBitSet(6)) && (cal_steps_8.isBitClear(7)) )
		    {
			FAPI_INF( "+++ Initial Course Write (COURSE_WR) on rank group: %d +++", group);
			rc_num = rc_num | data_buffer_64.setBit(54);
		    }
		    else if ( (cur_cal_step == 6) && (cal_steps_8.isBitClear(6)) && (cal_steps_8.isBitSet(7)) )
		    {
			FAPI_INF( "+++ Course Read (COURSE_RD) on rank group: %d +++", group);
			rc_num = rc_num | data_buffer_64.setBit(55);
		    }
		    else if ( (cur_cal_step == 6) && (cal_steps_8.isBitSet(6)) && (cal_steps_8.isBitSet(7)) )
		    {
			FAPI_INF( "+++ Initial Course Write (COURSE_WR) and Course Read (COURSE_RD) simultaneously on rank group: %d +++", group);
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
			rc = mss_check_cal_status(i_target, port, group, cur_complete_status);
			if(rc) return rc;

			if (cur_complete_status == MSS_INIT_CAL_STALL)
			{
			    complete_status = cur_complete_status;
			}

			//Check to see if the training errored out
			rc = mss_check_error_status(i_target, port, group, cur_error_status);
			if(rc) return rc;

			if (cur_error_status == MSS_INIT_CAL_FAIL)
			{
			    error_status = cur_error_status;
			}

			if ( (cur_cal_step == 4) && (cal_steps_8.isBitSet(5)) )
			{
			    FAPI_INF( "+++ Read Centering Workaround on rank group: %d +++", group);
			    FAPI_INF( "+++ Clearing values from RD PHASE SELECT regs. +++");

			    if ( port == 0 )
			    {
				if ( group == 0 )
				{
				    ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0_0x800000090301143F;
				    ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_1_0x800004090301143F;
				    ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_2_0x800008090301143F;
				    ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_3_0x80000C090301143F;
				    ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_4_0x800010090301143F;
				}
				else if ( group == 1 )
				{
				    ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_0_0x800001090301143F;
				    ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_1_0x800005090301143F;
				    ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_2_0x800009090301143F;
				    ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_3_0x80000D090301143F;
				    ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_4_0x800011090301143F;	
				}
				else if ( group == 2 )
				{
				    ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_0_0x800002090301143F;
				    ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_1_0x800006090301143F;
				    ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_2_0x80000A090301143F;
				    ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_3_0x80000E090301143F;
				    ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_4_0x800012090301143F;
				}
				else if ( group == 3 )
				{
				    ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_0_0x800002090301143F;
				    ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_1_0x800006090301143F;
				    ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_2_0x80000A090301143F;
				    ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_3_0x80000E090301143F;
				    ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_4_0x800012090301143F;
				}
			    }
			    else if (port == 1 )
			    {
				if ( group == 0 )
				{
				    ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_0_0x800100090301143F;
				    ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_1_0x800104090301143F;
				    ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_2_0x800108090301143F;
				    ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_3_0x80010C090301143F;
				    ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_4_0x800110090301143F;
				}
				else if ( group == 1 )
				{
				    ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P1_0_0x800101090301143F;
				    ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P1_1_0x800105090301143F;
				    ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P1_2_0x800109090301143F;
				    ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P1_3_0x80010D090301143F;
				    ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P1_4_0x800111090301143F;	
				}
				else if ( group == 2 )
				{
				    ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P1_0_0x800102090301143F;
				    ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P1_1_0x800106090301143F;
				    ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P1_2_0x80010A090301143F;
				    ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P1_3_0x80010E090301143F;
				    ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P1_4_0x800112090301143F;
				}
				else if ( group == 3 )
				{
				    ADDR_0 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P1_0_0x800103090301143F;
				    ADDR_1 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P1_1_0x800107090301143F;
				    ADDR_2 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P1_2_0x80010B090301143F;
				    ADDR_3 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P1_3_0x80010F090301143F;
				    ADDR_4 = DPHY01_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P1_4_0x800113090301143F;
				}
			    }

			    rc = fapiGetScom(i_target, ADDR_0, data_buffer_64);
			    rc_num = rc_num | data_buffer_64.clearBit(50, 2);
			    rc_num = rc_num | data_buffer_64.clearBit(54, 2);
			    rc_num = rc_num | data_buffer_64.clearBit(58, 2);
			    rc_num = rc_num | data_buffer_64.clearBit(62, 2);
			    rc = fapiPutScom(i_target, ADDR_0, data_buffer_64);

			    rc = fapiGetScom(i_target, ADDR_1, data_buffer_64);
			    rc_num = rc_num | data_buffer_64.clearBit(50, 2);
			    rc_num = rc_num | data_buffer_64.clearBit(54, 2);
			    rc_num = rc_num | data_buffer_64.clearBit(58, 2);
			    rc_num = rc_num | data_buffer_64.clearBit(62, 2);
			    rc = fapiPutScom(i_target, ADDR_1, data_buffer_64);

			    rc = fapiGetScom(i_target, ADDR_2, data_buffer_64);
			    rc_num = rc_num | data_buffer_64.clearBit(50, 2);
			    rc_num = rc_num | data_buffer_64.clearBit(54, 2);
			    rc_num = rc_num | data_buffer_64.clearBit(58, 2);
			    rc_num = rc_num | data_buffer_64.clearBit(62, 2);
			    rc = fapiPutScom(i_target, ADDR_2, data_buffer_64);

			    rc = fapiGetScom(i_target, ADDR_3, data_buffer_64);
			    rc_num = rc_num | data_buffer_64.clearBit(50, 2);
			    rc_num = rc_num | data_buffer_64.clearBit(54, 2);
			    rc_num = rc_num | data_buffer_64.clearBit(58, 2);
			    rc_num = rc_num | data_buffer_64.clearBit(62, 2);
			    rc = fapiPutScom(i_target, ADDR_3, data_buffer_64);

			    rc = fapiGetScom(i_target, ADDR_4, data_buffer_64);
			    rc_num = rc_num | data_buffer_64.clearBit(50, 2);
			    rc_num = rc_num | data_buffer_64.clearBit(54, 2);
			    rc_num = rc_num | data_buffer_64.clearBit(58, 2);
			    rc_num = rc_num | data_buffer_64.clearBit(62, 2);
			    rc = fapiPutScom(i_target, ADDR_4, data_buffer_64);

			}

		    }
		}//end of step loop

		// Temporarily disable this function for HW debug
	        // Change the RTT_NOM to RTT_WR, RTT_WR to RTT_NOM
		//rc = mss_rtt_nom_rtt_wr_swap(i_target, port, primary_ranks_array[group][port], group, instruction_number);
	    }
	}//end of group loop
    }//end of port loop

    if(rc) return rc;
    //rc = mss_get_bbm_regs(i_target);
    //if(rc)
    //{
	//FAPI_ERR( "Error Moving bad bit information from the Phy regs. Exiting.");
	//return rc;
    //}

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
        FAPI_INF( "+++ Calibration on port: %d rank group: %d in progress. Poll count: %d +++", i_port, i_group, poll_count);

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
	FAPI_INF( "+++ Calibration on port: %d rank group: %d finished. +++", i_port, i_group);
	io_status = MSS_INIT_CAL_COMPLETE;
    }
    else
    {
	FAPI_ERR( "+++ Calibration on port: %d rank group: %d has stalled! +++", i_port, i_group);
	io_status = MSS_INIT_CAL_STALL;
    }

    return rc;
}

ReturnCode mss_check_error_status( Target& i_target, 
                                 uint8_t i_port,
                                 uint8_t i_group,
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
            FAPI_ERR( "+++ Write leveling error occured on port: %d rank group: %d! +++", i_port, i_group);
        }
        if(cal_error_buffer_64.isBitSet(50))
        {
            FAPI_ERR( "+++ DQS Alignment error occured on port: %d rank group: %d! +++", i_port, i_group);
        }
        if(cal_error_buffer_64.isBitSet(51))
        {
            FAPI_ERR( "+++ RDCLK to SysClk alignment error occured on port: %d rank group: %d! +++", i_port, i_group);
        }
        if(cal_error_buffer_64.isBitSet(52))
        {
            FAPI_ERR( "+++ Read centering error occured on port: %d rank group: %d! +++", i_port, i_group);
        }
        if(cal_error_buffer_64.isBitSet(53))
        {
            FAPI_ERR( "+++ Write centering error occured on port: %d rank group: %d! +++", i_port, i_group);
        }
        if(cal_error_buffer_64.isBitSet(55))
        {
            FAPI_ERR( "+++ Coarse read centering error occured on port: %d rank group: %d! +++", i_port, i_group);
        }
        if(cal_error_buffer_64.isBitSet(56))
        {
            FAPI_ERR( "+++ Custom pattern read centering error occured on port: %d rank group: %d! +++", i_port, i_group);
        }
        if(cal_error_buffer_64.isBitSet(57))
        {
            FAPI_ERR( "+++ Custom pattern write centering error occured on port: %d rank group: %d! +++", i_port, i_group);
        }
        if(cal_error_buffer_64.isBitSet(58))
        {
            FAPI_ERR( "+++ Digital eye error occured on port: %d rank group: %d! +++", i_port, i_group);
        }
    }
    else
    {
	FAPI_INF( "+++ Calibration on port: %d rank group: %d was successful. +++", i_port, i_group);
	io_status = MSS_INIT_CAL_PASS;
    }

    return rc;
}

ReturnCode mss_rtt_nom_rtt_wr_swap(
            Target& i_target,
            uint32_t i_port_number,
            uint8_t i_rank,
	    uint32_t i_rank_pair_group,
            uint32_t& io_ccs_inst_cnt
            )
{

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

    // MRS CMD to CMD spacing = 12 cycles
    rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 12, 0, 16);

    FAPI_INF( "SWAPPING RTT_NOM AND RTT_WR FOR PORT%d RP%d", i_port_number, i_rank_pair_group);

    //MRS1
    // Get contents of MRS 1 Shadow Reg

    if (i_port_number == 0){
    	if (i_rank_pair_group == 0)
    	{
		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_PRI_RP0_P0_0x8000C01D0301143F, data_buffer_64);
    	}
    	else if (i_rank_pair_group == 1)
    	{
		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_PRI_RP1_P0_0x8000C11D0301143F, data_buffer_64);
    	}
    	else if (i_rank_pair_group == 2)
    	{
		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_PRI_RP2_P0_0x8000C21D0301143F, data_buffer_64);
    	}
    	else if (i_rank_pair_group == 3)
    	{
		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_PRI_RP3_P0_0x8000C31D0301143F, data_buffer_64);
    	}
    }
    else if (i_port_number == 1){
    	if (i_rank_pair_group == 0)
    	{
		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_PRI_RP0_P1_0x8001C01D0301143F, data_buffer_64);
    	}
    	else if (i_rank_pair_group == 1)
    	{
		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_PRI_RP1_P1_0x8001C11D0301143F, data_buffer_64);
    	}
    	else if (i_rank_pair_group == 2)
    	{
		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_PRI_RP2_P1_0x8001C21D0301143F, data_buffer_64);
    	}
    	else if (i_rank_pair_group == 3)
    	{
		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR1_PRI_RP3_P1_0x8001C31D0301143F, data_buffer_64);
    	}
    }

    rc_num = rc_num | data_buffer_64.reverse();
    rc_num = rc_num | mrs1_16.insert(data_buffer_64, 0, 16, 0);
    rc_num = rc_num | mrs1_16.extractPreserve(&MRS1, 0, 16, 0);
    FAPI_INF( "ORIGINAL MRS 1: 0x%04X", MRS1);

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

    uint8_t dram_rtt_wr = 0x00;
    if ( (mrs1_16.isBitClear(2)) && (mrs1_16.isBitClear(6)) && (mrs1_16.isBitClear(9)) )
    {
	// RTT_NOM set to disabled
        //RTT WR Disabled
	dram_rtt_wr = 0x00;
    }
    else if ( (mrs1_16.isBitClear(2)) && (mrs1_16.isBitClear(6)) && (mrs1_16.isBitSet(9)) )
    {
	// RTT_NOM set to 20
        //RTT WR 60 OHM
	dram_rtt_wr = 0x80;
    }
    else if ( (mrs1_16.isBitSet(2)) && (mrs1_16.isBitClear(6)) && (mrs1_16.isBitSet(9)) )
    {
	// RTT_NOM set to 30
        //RTT WR 60 OHM
	dram_rtt_wr = 0x80;
    }
    else if ( (mrs1_16.isBitSet(2)) && (mrs1_16.isBitSet(6)) && (mrs1_16.isBitClear(9)) )
    {
	// RTT_NOM set to 40
	//RTT WR 60 OHM
	dram_rtt_wr = 0x80;
    }
    else if ( (mrs1_16.isBitSet(2)) && (mrs1_16.isBitSet(6)) && (mrs1_16.isBitClear(9)) )
    {
        // RTT_NOM set to 60
        //RTT WR 60 OHM
	dram_rtt_wr = 0x80;
    }
    else if ( (mrs1_16.isBitClear(2)) && (mrs1_16.isBitSet(6)) && (mrs1_16.isBitClear(9)) )
    {
	// RTT_NOM set to 120
	// RTT_WR set to 120
	dram_rtt_wr = 0x40;
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

    //MRS2
    // MRS CMD to CMD spacing = 12 cycles
    rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 12, 0, 16);

    // Get contents of MRS 1 Shadow Reg
    if (i_port_number == 0){
    	if (i_rank_pair_group == 0)
    	{
		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_PRI_RP0_P0_0x8000C01E0301143F, data_buffer_64);
	}
	else if (i_rank_pair_group == 1)
	{
		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_PRI_RP1_P0_0x8000C11E0301143F, data_buffer_64);
        }
        else if (i_rank_pair_group == 2)
        {
	        rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_PRI_RP2_P0_0x8000C21E0301143F, data_buffer_64);
        }
        else if (i_rank_pair_group == 3)
        {
     	        rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_PRI_RP3_P0_0x8000C31E0301143F, data_buffer_64);
        }
    }
    else if (i_port_number == 1){
    	if (i_rank_pair_group == 0)
    	{
		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_PRI_RP0_P1_0x8001C01E0301143F, data_buffer_64);
	}
	else if (i_rank_pair_group == 1)
	{
		rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_PRI_RP1_P1_0x8001C11E0301143F, data_buffer_64);
        }
        else if (i_rank_pair_group == 2)
        {
	        rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_PRI_RP2_P1_0x8001C21E0301143F, data_buffer_64);
        }
        else if (i_rank_pair_group == 3)
        {
     	        rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_MR2_PRI_RP3_P1_0x8001C31E0301143F, data_buffer_64);
        }
    }

    rc_num = rc_num | data_buffer_64.reverse();
    rc_num = rc_num | mrs2_16.insert(data_buffer_64, 0, 16, 0);
    rc_num = rc_num | mrs2_16.extractPreserve(&MRS2, 0, 16, 0);
    FAPI_INF( "ORIGINAL MRS 2: 0x%04X", MRS2);

    uint8_t pt_arr_sr = 0x00; //Partial Array Self Refresh  
    if ( (mrs2_16.isBitClear(0)) && (mrs2_16.isBitClear(1)) && (mrs2_16.isBitClear(2)) )
    {
	//PASR FULL
        pt_arr_sr = 0x00;
    }
    else if ( (mrs2_16.isBitSet(0)) && (mrs2_16.isBitClear(1)) && (mrs2_16.isBitClear(2)) )
    {
	//PASR FIRST HALF
        pt_arr_sr = 0x80;
    }
    else if ( (mrs2_16.isBitClear(0)) && (mrs2_16.isBitSet(1)) && (mrs2_16.isBitClear(2)) )
    {
	// PASR FIRST QUARTER
        pt_arr_sr = 0x40;
    }
    else if ( (mrs2_16.isBitSet(0)) && (mrs2_16.isBitSet(1)) && (mrs2_16.isBitClear(2)) )
    {
	// PASR FIRST EIGHTH
        pt_arr_sr = 0xC0;
    }
    else if ( (mrs2_16.isBitClear(0)) && (mrs2_16.isBitClear(1)) && (mrs2_16.isBitSet(2)) )
    {
	// PASR LAST FOURTH
        pt_arr_sr = 0x20;
    }
    else if ( (mrs2_16.isBitSet(0)) && (mrs2_16.isBitClear(1)) && (mrs2_16.isBitSet(2)) )
    {
	// PASR LAST HALF
        pt_arr_sr = 0xA0;
    }
    else if ( (mrs2_16.isBitClear(0)) && (mrs2_16.isBitSet(1)) && (mrs2_16.isBitSet(2)) )
    {
	// PASR LAST QUARTER
        pt_arr_sr = 0x60;
    }
    else if ( (mrs2_16.isBitSet(0)) && (mrs2_16.isBitSet(1)) && (mrs2_16.isBitSet(2)) )
    {
	// PASR LAST EIGHTH
        pt_arr_sr = 0xE0;
    }

    uint8_t cwl = 0x00; // CAS Write Latency 
    if ( (mrs2_16.isBitClear(3)) && (mrs2_16.isBitClear(4)) && (mrs2_16.isBitClear(5)) )
    {
	// CWL = 5
        cwl = 0x00;
    }
    else if ( (mrs2_16.isBitSet(3)) && (mrs2_16.isBitClear(4)) && (mrs2_16.isBitClear(5)) )
    {
	// CWL = 6
        cwl = 0x80;
    }
    else if ( (mrs2_16.isBitClear(3)) && (mrs2_16.isBitSet(4)) && (mrs2_16.isBitClear(5)) )
    {
	// CWL = 7
        cwl = 0x40;
    }
    else if ( (mrs2_16.isBitSet(3)) && (mrs2_16.isBitSet(4)) && (mrs2_16.isBitClear(5)) )
    {
	// CWL = 8
        cwl = 0xC0;
    }
    else if ( (mrs2_16.isBitClear(3)) && (mrs2_16.isBitClear(4)) && (mrs2_16.isBitSet(5)) )
    {
	// CWL = 9
        cwl = 0x20;
    }
    else if ( (mrs2_16.isBitSet(3)) && (mrs2_16.isBitClear(4)) && (mrs2_16.isBitSet(5)) )
    {
	// CWL = 10
        cwl = 0xA0;
    }
    else if ( (mrs2_16.isBitClear(3)) && (mrs2_16.isBitSet(4)) && (mrs2_16.isBitSet(5)) )
    {
	// CWL = 11
        cwl = 0x60;
    }
    else if ( (mrs2_16.isBitSet(3)) && (mrs2_16.isBitSet(4)) && (mrs2_16.isBitSet(5)) )
    {
	// CWL = 12
        cwl = 0xE0;
    }

    uint8_t auto_sr = 0x00; // Auto Self-Refresh
    if ( (mrs2_16.isBitClear(6)) )
    {
	//AUTO SR = SRT
        auto_sr = 0x00;
    }
    else if ( (mrs2_16.isBitSet(6)) )
    {
	//AUTO SR = ASR ENABLE
        auto_sr = 0xFF;
    }

    uint8_t sr_temp = 0x00; // Self-Refresh Temp Range
    if ( (mrs2_16.isBitClear(7)) )
    {
	//SRT NORMAL
        sr_temp = 0x00;
    }
    else if ( (mrs2_16.isBitSet(7)) )
    {
	//SRT EXTEND
        sr_temp = 0xFF;
    }

    uint8_t dram_rtt_nom = 0x00;
    if ( (mrs2_16.isBitClear(9)) && (mrs2_16.isBitClear(10)) )
    {
	//RTT WR DISABLE
	// RTT_NOM set to disabled
	dram_rtt_nom = 0x00;
    }
    else if ( (mrs2_16.isBitSet(9)) && (mrs2_16.isBitClear(10)) )
    {
	//RTT WR 60 OHM
        // RTT_NOM set to 60
	dram_rtt_nom = 0x80;
    }
    else if ( (mrs2_16.isBitClear(9)) && (mrs2_16.isBitSet(10)) )
    {
	//RTT WR 120 OHM
	// RTT_NOM set to 120
	dram_rtt_nom = 0x40;
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

    rc_num = rc_num | address_16.insert(mrs1_16, 0, 16, 0);
    rc_num = rc_num | bank_3.insert((uint8_t) MRS1_BA, 0, 1, 7);
    rc_num = rc_num | bank_3.insert((uint8_t) MRS1_BA, 1, 1, 6);
    rc_num = rc_num | bank_3.insert((uint8_t) MRS1_BA, 2, 1, 5);

    if (rc_num)
    {
	FAPI_ERR( "mss_mrs_load: Error setting up buffers");
	rc_buff.setEcmdError(rc_num);
	return rc_buff;
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
    io_ccs_inst_cnt++;	


    rc_num = rc_num | mrs2_16.insert((uint8_t) pt_arr_sr, 0, 3);
    rc_num = rc_num | mrs2_16.insert((uint8_t) cwl, 3, 3);
    rc_num = rc_num | mrs2_16.insert((uint8_t) auto_sr, 6, 1);
    rc_num = rc_num | mrs2_16.insert((uint8_t) sr_temp, 7, 1);
    rc_num = rc_num | mrs2_16.insert((uint8_t) 0x00, 8, 1);
    rc_num = rc_num | mrs2_16.insert((uint8_t) dram_rtt_wr, 9, 2);
    rc_num = rc_num | mrs2_16.insert((uint8_t) 0x00, 10, 6);

    rc_num = rc_num | mrs2_16.extractPreserve(&MRS2, 0, 16, 0);
    FAPI_INF( "NEW MRS 2: 0x%04X", MRS2);

    rc_num = rc_num | address_16.insert(mrs2_16, 0, 16, 0);
    rc_num = rc_num | bank_3.insert((uint8_t) MRS2_BA, 0, 1, 7);
    rc_num = rc_num | bank_3.insert((uint8_t) MRS2_BA, 1, 1, 6);
    rc_num = rc_num | bank_3.insert((uint8_t) MRS2_BA, 2, 1, 5);

    if (rc_num)
    {
	FAPI_ERR( "mss_mrs_load: Error setting up buffers");
	rc_buff.setEcmdError(rc_num);
	return rc_buff;
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
    io_ccs_inst_cnt++;

    return rc;

}

fapi::ReturnCode mss_set_bbm_regs (const fapi::Target & mba_target)
{
    // Flash to registers.


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
				// clear bits 48:63
				l_ecmdRc = data_buffer.clearBit(48, BITS_PER_REG);
				l_data = db_reg.getHalfWord(i);

                                //	check or not to check(always set register)?
				if (l_data == 0)
				{
					FAPI_INF("DP18_%i has no bad bits set, continuing...", i);
					continue;
				}

				l_ecmdRc |= data_buffer.setHalfWord(3, l_data);
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

				rc = fapiPutScom(mba_target, disable_reg[port][prank][i],
						data_buffer);
				if (rc)
				{
					FAPI_ERR("Error from fapiPutScom writing disable reg");
					return rc;
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

				l_ecmdRc |= db_reg.setHalfWord(i, l_data);
 
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
} // end mss_set_bbm_regs

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

