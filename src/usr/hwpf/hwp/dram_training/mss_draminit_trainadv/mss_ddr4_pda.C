/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_trainadv/mss_ddr4_pda.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
// $Id: mss_ddr4_pda.C,v 1.44 2015/10/23 15:11:24 sglancy Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2013
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE : mss_ddr4_pda.C
// *! DESCRIPTION : Tools for DDR4 DIMMs centaur procedures
// *! OWNER NAME  : Stephen Glancy       Email: sglancy@us.ibm.com
// *! BACKUP NAME : Andre Marin     Email: aamarin@us.ibm.com
// #! ADDITIONAL COMMENTS :
//

//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.13   | 10/23/15 | sglancy | Changed attribute names
//  1.12   | 10/21/15 | sglancy | Changed attribute names
//  1.11   | 07/23/15 | sglancy | Changed code to address FW comments
//  1.10   | 06/09/15 | sglancy | Fixed bug
//  1.9    | 05/27/15 | sglancy | Fixed bug
//  1.8    | 05/13/15 | sglancy | Added new checks, FFDC, and checked
//  1.7    | 05/11/15 | sglancy | Fixed compile errors
//  1.6    | 05/11/15 | sglancy | Updated for FW comments
//  1.5    | 05/07/15 | sglancy | Updated for FW comments
//  1.4    | 04/22/15 | sglancy | Fixed several code bugs
//  1.3    | 04/21/15 | sglancy | Added support for R and LR DIMMs as well as x8, fixed minor bug in setup and disable code
//  1.2    | 11/27/14 | sglancy | Updated to allow for file inputs and changed print statements
//  1.1    | 10/27/14 | sglancy | First revision


//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi.H>
#include <mss_ddr4_pda.H>
#include <mss_funcs.H>
#include <cen_scom_addresses.H>
#include <mss_access_delay_reg.H>
#include <vector>
#include <algorithm>
using namespace fapi;
using namespace std;
extern "C" {

//PDA_Scom_Storage constructor
PDA_Scom_Storage::PDA_Scom_Storage(uint64_t sa, uint32_t sb, uint32_t nb) {
   scom_addr = sa;
   start_bit = sb;
   num_bits = nb;
}
PDA_Scom_Storage::~PDA_Scom_Storage() {}

//PDA_MRS_Storage class constructor
PDA_MRS_Storage::PDA_MRS_Storage(uint8_t ad,uint32_t an,uint8_t dr,uint8_t di,uint8_t r,uint8_t p) {
   attribute_data = ad;
   attribute_name = an;
   dram = dr;
   dimm = di;
   rank = r;
   port = p;
   MRS = 0xFF;
   pda_string[0] = '\0';
}

const uint8_t MRS0_BA = 0;
const uint8_t MRS1_BA = 1;
const uint8_t MRS2_BA = 2;  
const uint8_t MRS3_BA = 3;
const uint8_t MRS4_BA = 4;
const uint8_t MRS5_BA = 5;
const uint8_t MRS6_BA = 6;
const uint8_t MAX_NUM_DP18S = 5;
const uint8_t MAX_NUM_PORTS = 2;
const uint8_t MAX_NUM_DIMMS = 2;
const uint8_t PORT_SIZE = 2;

//generates the string
void PDA_MRS_Storage::generatePDAString() {
   snprintf(pda_string,MAX_ECMD_STRING_LEN,"ATTR_NAME 0x%08x ATTR_DATA 0x%02x MRS %d P %d DI %d R %d DR %d",attribute_name,attribute_data,MRS,port,dimm,rank,dram);
}

//sends out the string
char * PDA_MRS_Storage::c_str() {
   //generate new string
   generatePDAString(); //note using a separate function here in case some other function would need to call the generation of the string
   return pda_string;
}

//Checks to make sure that 
ReturnCode PDA_MRS_Storage::checkPDAValid(Target& i_target) {
   ReturnCode rc;
   
   //checks constants first
   //ports out of range
   if(port >= MAX_NUM_PORTS) {
      const uint32_t PORT_VALUE = port;
      const uint32_t DIMM_VALUE = dimm;
      const uint32_t RANK_VALUE = rank;
      const uint32_t DRAM_VALUE = dram;
      const fapi::Target & MBA_TARGET = i_target; 
      FAPI_SET_HWP_ERROR(rc, RC_MSS_PDA_DRAM_DNE);
      FAPI_ERR("ERROR!! Port out of valid range! Exiting...");
      return rc;
   }
   
   //DIMMs out of range
   if(dimm >= MAX_NUM_DIMMS) {
      const uint32_t PORT_VALUE = port;
      const uint32_t DIMM_VALUE = dimm;
      const uint32_t RANK_VALUE = rank;
      const uint32_t DRAM_VALUE = dram;
      const fapi::Target & MBA_TARGET = i_target; 
      FAPI_SET_HWP_ERROR(rc, RC_MSS_PDA_DRAM_DNE);
      FAPI_ERR("ERROR!! DIMM out of valid range! Exiting...");
      return rc;
   }
   
   //now checks based upon attributes
   uint8_t num_ranks[2][2];
   rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM,&i_target,num_ranks); 
   if(rc) return rc;
   
   //no ranks on the selected dimm
   if(num_ranks[port][dimm] == 0) {
      const uint32_t PORT_VALUE = port;
      const uint32_t DIMM_VALUE = dimm;
      const uint32_t RANK_VALUE = rank;
      const uint32_t DRAM_VALUE = dram;
      const fapi::Target & MBA_TARGET = i_target; 
      FAPI_SET_HWP_ERROR(rc, RC_MSS_PDA_DRAM_DNE);
      FAPI_ERR("ERROR!! DIMM has no valid ranks! Exiting...");
      return rc;
   }
   
   //rank is out of range
   if(num_ranks[port][dimm] <= rank) {
      const uint32_t PORT_VALUE = port;
      const uint32_t DIMM_VALUE = dimm;
      const uint32_t RANK_VALUE = rank;
      const uint32_t DRAM_VALUE = dram;
      const fapi::Target & MBA_TARGET = i_target; 
      FAPI_SET_HWP_ERROR(rc, RC_MSS_PDA_DRAM_DNE);
      FAPI_ERR("ERROR!! Rank is out of bounds! Exiting...");
      return rc;
   }
   
   uint8_t num_spares[2][2][4];
   rc = FAPI_ATTR_GET(ATTR_VPD_DIMM_SPARE,&i_target,num_spares); 
   if(rc) return rc;
   
   uint8_t dram_width;
   rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH,&i_target,dram_width); 
   if(rc) return rc;
   
   uint8_t num_spare = 0;
   if(num_spares[port][dimm][rank] == ENUM_ATTR_VPD_DIMM_SPARE_LOW_NIBBLE) {
      num_spare = 1;
   }
   if(num_spares[port][dimm][rank] == ENUM_ATTR_VPD_DIMM_SPARE_HIGH_NIBBLE) {
      num_spare = 1;
   }
   if(num_spares[port][dimm][rank] == ENUM_ATTR_VPD_DIMM_SPARE_FULL_BYTE && dram_width == ENUM_ATTR_EFF_DRAM_WIDTH_X4) {
      num_spare = 2;
   }
   if(num_spares[port][dimm][rank] == ENUM_ATTR_VPD_DIMM_SPARE_FULL_BYTE && dram_width == ENUM_ATTR_EFF_DRAM_WIDTH_X8) {
      num_spare = 1;
   }
   
   uint8_t num_dram = 72/dram_width + num_spare;
   if(num_dram <= dram) {
      const uint32_t PORT_VALUE = port;
      const uint32_t DIMM_VALUE = dimm;
      const uint32_t RANK_VALUE = rank;
      const uint32_t DRAM_VALUE = dram;
      const fapi::Target & MBA_TARGET = i_target; 
      FAPI_SET_HWP_ERROR(rc, RC_MSS_PDA_DRAM_DNE);
      FAPI_ERR("ERROR!! DRAM is out of bounds! Exiting...");
      return rc;
   }
   
   return rc;
}

//sets the MRS variable based upon the inputted attribute name
ReturnCode PDA_MRS_Storage::setMRSbyAttr(Target& i_target) {
   fapi::ReturnCode rc;
   switch(attribute_name) {
   
   //MRS0
      case ATTR_EFF_DRAM_BL: MRS = MRS0_BA; break;
      case ATTR_EFF_DRAM_RBT: MRS = MRS0_BA; break;
      case ATTR_EFF_DRAM_CL: MRS = MRS0_BA; break;
      case ATTR_EFF_DRAM_TM: MRS = MRS0_BA; break;
      case ATTR_EFF_DRAM_DLL_RESET: MRS = MRS0_BA; break;
      case ATTR_EFF_DRAM_WR: MRS = MRS0_BA; break;
      case ATTR_EFF_DRAM_TRTP: MRS = MRS0_BA; break;
      case ATTR_EFF_DRAM_DLL_PPD: MRS = MRS0_BA; break;

   //MRS1
      case ATTR_EFF_DRAM_DLL_ENABLE: MRS = MRS1_BA; break;
      case ATTR_VPD_DRAM_RON: MRS = MRS1_BA; break;
      case ATTR_VPD_DRAM_RTT_NOM: MRS = MRS1_BA; break;
      case ATTR_EFF_DRAM_AL: MRS = MRS1_BA; break;
      case ATTR_EFF_DRAM_WR_LVL_ENABLE: MRS = MRS1_BA; break;
      case ATTR_EFF_DRAM_TDQS: MRS = MRS1_BA; break;
      case ATTR_EFF_DRAM_OUTPUT_BUFFER: MRS = MRS1_BA; break;
   
   //MRS2
      case ATTR_EFF_DRAM_LPASR: MRS = MRS2_BA; break;
      case ATTR_EFF_DRAM_CWL: MRS = MRS2_BA; break;
      case ATTR_VPD_DRAM_RTT_WR: MRS = MRS2_BA; break;
      case ATTR_EFF_WRITE_CRC: MRS = MRS2_BA; break;

   //MRS3
      case ATTR_EFF_MPR_MODE: MRS = MRS3_BA; break;
      case ATTR_EFF_MPR_PAGE: MRS = MRS3_BA; break;
      case ATTR_EFF_GEARDOWN_MODE: MRS = MRS3_BA; break;
      case ATTR_EFF_PER_DRAM_ACCESS: MRS = MRS3_BA; break;
      case ATTR_EFF_TEMP_READOUT: MRS = MRS3_BA; break;
      case ATTR_EFF_FINE_REFRESH_MODE: MRS = MRS3_BA; break;
      case ATTR_EFF_CRC_WR_LATENCY: MRS = MRS3_BA; break;
      case ATTR_EFF_MPR_RD_FORMAT: MRS = MRS3_BA; break;

   //MRS4
      case ATTR_EFF_MAX_POWERDOWN_MODE: MRS = MRS4_BA; break;
      case ATTR_EFF_TEMP_REF_RANGE: MRS = MRS4_BA; break;
      case ATTR_EFF_TEMP_REF_MODE: MRS = MRS4_BA; break;
      case ATTR_EFF_INT_VREF_MON: MRS = MRS4_BA; break;
      case ATTR_EFF_CS_CMD_LATENCY: MRS = MRS4_BA; break;
      case ATTR_EFF_SELF_REF_ABORT: MRS = MRS4_BA; break;
      case ATTR_EFF_RD_PREAMBLE_TRAIN: MRS = MRS4_BA; break;
      case ATTR_EFF_RD_PREAMBLE: MRS = MRS4_BA; break;
      case ATTR_EFF_WR_PREAMBLE: MRS = MRS4_BA; break;


   //MRS5
      case ATTR_EFF_CA_PARITY_LATENCY : MRS = MRS5_BA; break;
      case ATTR_EFF_CRC_ERROR_CLEAR : MRS = MRS5_BA; break;
      case ATTR_EFF_CA_PARITY_ERROR_STATUS : MRS = MRS5_BA; break;
      case ATTR_EFF_ODT_INPUT_BUFF : MRS = MRS5_BA; break;
      case ATTR_VPD_DRAM_RTT_PARK : MRS = MRS5_BA; break;
      case ATTR_EFF_CA_PARITY : MRS = MRS5_BA; break;
      case ATTR_EFF_DATA_MASK : MRS = MRS5_BA; break;
      case ATTR_EFF_WRITE_DBI : MRS = MRS5_BA; break;
      case ATTR_EFF_READ_DBI : MRS = MRS5_BA; break;

   //MRS6
      case ATTR_EFF_VREF_DQ_TRAIN_VALUE: MRS = MRS6_BA; break;
      case ATTR_EFF_VREF_DQ_TRAIN_RANGE: MRS = MRS6_BA; break;
      case ATTR_EFF_VREF_DQ_TRAIN_ENABLE: MRS = MRS6_BA; break;
      case ATTR_TCCD_L: MRS = MRS6_BA; break;
      
      //MRS attribute not found, error out
      default: 
         const uint32_t NONMRS_ATTR_NAME = attribute_name;
	 const fapi::Target & MBA_TARGET = i_target; 
	 FAPI_SET_HWP_ERROR(rc, RC_MSS_PDA_NONMRS_ATTR_NAME);
	 FAPI_ERR("ERROR!! Found attribute name not associated with an MRS! Exiting...");
   }
   return rc;
}//end setMRSbyAttr
  
//PDA_MRS_Storage class destructor
PDA_MRS_Storage::~PDA_MRS_Storage() {}

bool PDA_MRS_Storage::operator> (const PDA_MRS_Storage &PDA2) const {
   //check on the DRAM first
   //DRAM for A is greater than B return true
   if(dram > PDA2.dram) return true;
   //B > A -> false
   else if(dram < PDA2.dram) return false;
   //B == A, so go to port
   //A > B -> true
   else if(port > PDA2.port) return true;
   //A < B -> false
   else if(port < PDA2.port) return false;
   //ports are equal, so start comparing dimms
   //A > B -> true
   else if(dimm > PDA2.dimm) return true;
   //A < B -> false
   else if(dimm < PDA2.dimm) return false;
   //dimms are equal, so start comparing ranks
   //A > B -> true
   else if(rank > PDA2.rank) return true;
   //A < B -> false
   else if(rank < PDA2.rank) return false;
   //ports are equal, so start comparing the MRS number
   //A > B -> true
   else if(MRS > PDA2.MRS) return true;
   //A < B -> false
   else if(MRS < PDA2.MRS) return false;
   //ports are equal, so start comparing the attribute_name
   //A > B -> true
   else if(attribute_name > PDA2.attribute_name) return true;
   //A < B -> false
   else if(attribute_name < PDA2.attribute_name) return false;
   //ports are equal, so start comparing the attribute_data
   //A > B -> true
   else if(attribute_data > PDA2.attribute_data) return true;
   //equal or less than
   return false;
}//end operator>

bool PDA_MRS_Storage::operator< (const PDA_MRS_Storage &PDA2) const {
//check on the DRAM first
   //DRAM for A is less than B return true
   if(dram < PDA2.dram) return true;
   //B < A -> false
   else if(dram > PDA2.dram) return false;
   //B == A, so go to port
   //A < B -> true
   else if(port < PDA2.port) return true;
   //A > B -> false
   else if(port > PDA2.port) return false;
   //ports are equal, so start comparing dimms
   //A < B -> true
   else if(dimm < PDA2.dimm) return true;
   //A > B -> false
   else if(dimm > PDA2.dimm) return false;
   //dimms are equal, so start comparing ranks
   //A < B -> true
   else if(rank < PDA2.rank) return true;
   //A > B -> false
   else if(rank > PDA2.rank) return false;
   //ports are equal, so start comparing the MRS number
   //A < B -> true
   else if(MRS < PDA2.MRS) return true;
   //A > B -> false
   else if(MRS > PDA2.MRS) return false;
   //ports are equal, so start comparing the attribute_name
   //A < B -> true
   else if(attribute_name < PDA2.attribute_name) return true;
   //A > B -> false
   else if(attribute_name > PDA2.attribute_name) return false;
   //ports are equal, so start comparing the attribute_data
   //A < B -> true
   else if(attribute_data < PDA2.attribute_data) return true;
   //equal or greater than
   return false;
}//end operator<


/////////////////////////////////////////////////////////////////////////////////
/// PDA_MRS_Storage::copy
/// copies one PDA_MRS_Storage to this one
/////////////////////////////////////////////////////////////////////////////////
void PDA_MRS_Storage::copy(PDA_MRS_Storage &temp) {
   attribute_data = temp.attribute_data;
   attribute_name = temp.attribute_name;
   MRS            = temp.MRS	       ;
   dram           = temp.dram	       ;
   dimm           = temp.dimm	       ;
   rank           = temp.rank	       ;
   port           = temp.port	       ;
}

/////////////////////////////////////////////////////////////////////////////////
/// mss_ddr4_checksort_pda
/// sorts the vector of PDA_MRS_Storage, so the commands will be run in a more efficient order
/////////////////////////////////////////////////////////////////////////////////
ReturnCode mss_ddr4_checksort_pda(Target& i_target, vector<PDA_MRS_Storage>& pda) {
   ReturnCode rc;
   
   //does the check to make sure all given attributes are associated with an MRS 
   for(uint32_t i=0;i<pda.size();i++) {
      rc = pda[i].setMRSbyAttr(i_target);
      if(rc) return rc;
      rc = pda[i].checkPDAValid(i_target);
      if(rc) return rc;
   }
   
   //does the sort, sorting by the class comparator (should be DRAM first)
   sort(pda.begin(),pda.end());
   
   return rc;
}


/////////////////////////////////////////////////////////////////////////////////
/// mss_ddr4_setup_pda
/// sets up per-DRAM addressability funcitonality on both ports on the passed MBA
/////////////////////////////////////////////////////////////////////////////////
ReturnCode mss_ddr4_setup_pda(
            Target& i_target,
            uint32_t& io_ccs_inst_cnt
            )
{
    uint32_t i_port_number=0;
    uint32_t dimm_number;
    uint32_t rank_number;
    const uint32_t NUM_POLL = 10;
    const uint32_t WAIT_TIMER = 1500;
    ReturnCode rc;  
    ReturnCode rc_buff;
    uint32_t rc_num = 0;
    uint64_t reg_address;
    ecmdDataBufferBase data_buffer(64);
    ecmdDataBufferBase address_16(16);
    ecmdDataBufferBase bank_3(3);
    ecmdDataBufferBase activate_1(1);
    rc_num = rc_num | activate_1.setBit(0);
    ecmdDataBufferBase rasn_1(1);
    ecmdDataBufferBase casn_1(1);
    ecmdDataBufferBase wen_1(1);
    ecmdDataBufferBase cke_4(4);
    rc_num = rc_num | cke_4.setBit(0,4);
    ecmdDataBufferBase csn_8(8);
    rc_num = rc_num | csn_8.setBit(0,8);
    ecmdDataBufferBase odt_4(4);
    ecmdDataBufferBase ddr_cal_type_4(4);

    ecmdDataBufferBase num_idles_16(16);
    ecmdDataBufferBase num_repeat_16(16);
    ecmdDataBufferBase data_20(20);
    ecmdDataBufferBase read_compare_1(1);
    ecmdDataBufferBase rank_cal_4(4);
    ecmdDataBufferBase ddr_cal_enable_1(1);
    ecmdDataBufferBase ccs_end_1(1);

    ecmdDataBufferBase mrs3(16);
    uint16_t MRS3 = 0;
    
    uint8_t num_ranks_array[2][2]; //[port][dimm]
    
    uint8_t dimm_type;
    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target, dimm_type);
    if(rc) return rc;
    
    uint8_t num_ranks;
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target, num_ranks_array);
    if(rc) return rc;

    uint8_t is_sim = 0;
    rc = FAPI_ATTR_GET(ATTR_IS_SIMULATION, NULL, is_sim);
    if(rc) return rc;

    uint8_t address_mirror_map[2][2]; //address_mirror_map[port][dimm]
    rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_ADDRESS_MIRRORING, &i_target, address_mirror_map);
    if(rc) return rc;

    // WORKAROUNDS 
    rc = fapiGetScom(i_target, CCS_MODEQ_AB_REG_0x030106A7, data_buffer);
    if(rc) return rc;
    //Setting up CCS mode
    rc_num = rc_num | data_buffer.setBit(51);
    
    if (rc_num)
    {
    	FAPI_ERR( "mss_ddr4_setup_pda: Error setting up buffers");
    	rc_buff.setEcmdError(rc_num);
    	return rc_buff;
    }
    
    rc = fapiPutScom(i_target, CCS_MODEQ_AB_REG_0x030106A7, data_buffer);
    if(rc) return rc;
    
    //loops through port 0 and port 1 on the given MBA
    for(i_port_number=0;i_port_number<MAX_NUM_PORTS;i_port_number++) {
       // Raise CKE high with NOPS, waiting min Reset CKE exit time (tXPR) - 400 cycles
       rc_num = rc_num | cke_4.setBit(0,4);
       rc_num = rc_num | csn_8.setBit(0,8);
       rc_num = rc_num | address_16.clearBit(0, 16);
       rc_num = rc_num | odt_4.clearBit(0,4);
       rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 400, 0, 16);
       if (rc_num)
       {
    	    FAPI_ERR( "mss_ddr4_setup_pda: Error setting up buffers");
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
    }
    
    
    //Sets up MRS3 -> the MRS that has PDA
    uint8_t mpr_op; // MPR Op
    rc = FAPI_ATTR_GET(ATTR_EFF_MPR_MODE, &i_target, mpr_op);
    if(rc) return rc;
    uint8_t mpr_page; // MPR Page Selection  - NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_MPR_PAGE, &i_target, mpr_page);
    if(rc) return rc;
    uint8_t geardown_mode; // Gear Down Mode  - NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_GEARDOWN_MODE, &i_target, geardown_mode);
    if(rc) return rc;
    uint8_t temp_readout; // Temperature sensor readout  - NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_TEMP_READOUT, &i_target, temp_readout);
    if(rc) return rc;
    uint8_t fine_refresh; // fine refresh mode  - NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_FINE_REFRESH_MODE, &i_target, fine_refresh);
    if(rc) return rc;
    uint8_t wr_latency; // write latency for CRC and DM  - NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_CRC_WR_LATENCY, &i_target, wr_latency);
    if(rc) return rc;
    uint8_t read_format; // MPR READ FORMAT  - NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_MPR_RD_FORMAT, &i_target, read_format);
    if(rc) return rc;

    //enables PDA mode
    //loops through all ports
    for(i_port_number=0;i_port_number<MAX_NUM_PORTS;i_port_number++) {
    	// Dimm 0-1
    	for ( dimm_number = 0; dimm_number < MAX_NUM_DIMMS; dimm_number++)
    	{
    	    num_ranks = num_ranks_array[i_port_number][dimm_number];

    	    if (num_ranks == 0)
    	    {
    		FAPI_INF( "PORT%d DIMM%d not configured. Num_ranks: %d ", i_port_number, dimm_number, num_ranks);
    	    }
    	    else
    	    {
    		// Rank 0-3
    		for ( rank_number = 0; rank_number < num_ranks; rank_number++)
    		{
    		   // Only corresponding CS to rank
    		   rc_num = rc_num | csn_8.setBit(0,8); 
    		   rc_num = rc_num | csn_8.clearBit(rank_number+4*dimm_number);
    			
    		   rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 0, 1, 7);
    		   rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 1, 1, 6);
    		   rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 2, 1, 5);
    		   
		   //sets up MRS3 ecmd buffer
	           rc_num = rc_num | mrs3.insert((uint8_t) mpr_page, 0, 2);
	           rc_num = rc_num | mrs3.insert((uint8_t) mpr_op, 2, 1);
	           rc_num = rc_num | mrs3.insert((uint8_t) geardown_mode, 3, 1);
	           rc_num = rc_num | mrs3.insert((uint8_t) 0xff, 4, 1); //enables PDA mode!!!!
	           rc_num = rc_num | mrs3.insert((uint8_t) temp_readout, 5, 1);
	           rc_num = rc_num | mrs3.insert((uint8_t) fine_refresh, 6, 3);
	           rc_num = rc_num | mrs3.insert((uint8_t) wr_latency, 9, 2);
	           rc_num = rc_num | mrs3.insert((uint8_t) read_format, 11, 2);
	           rc_num = rc_num | mrs3.insert((uint8_t) 0x00, 13, 2);
	           rc_num = rc_num | mrs3.extractPreserve(&MRS3, 0, 16, 0);
	           rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 24, 0, 16);
		   rc_num = rc_num | address_16.insert(mrs3, 0, 16, 0);
		   
    		   if (rc_num)
    		   {
    		       FAPI_ERR( "mss_ddr4_setup_pda: Error setting up buffers");
    		       rc_buff.setEcmdError(rc_num);
    		       return rc_buff;
    		   }
    		   
	           
    		   if (( address_mirror_map[i_port_number][dimm_number] & (0x08 >> rank_number) ) && (is_sim == 0))
    		   {
    		      rc = mss_address_mirror_swizzle(i_target, i_port_number, dimm_number, rank_number, address_16, bank_3);
    		      if(rc) return rc;
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
		   
		   //if the DIMM is an R or LR DIMM, then run inverted for the B-Side DRAM
                    if ( (dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_RDIMM) || (dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM) ) 
                    {
		       //reload all MRS values (removes address swizzling)
		       // Only corresponding CS to rank
    		       rc_num = rc_num | csn_8.setBit(0,8); 
    		       rc_num = rc_num | csn_8.clearBit(rank_number+4*dimm_number);
    		    	    
    		       rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 0, 1, 7);
    		       rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 1, 1, 6);
    		       rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 2, 1, 5);
    		       
		       //sets up MRS3 ecmd buffer
		       rc_num = rc_num | address_16.insert(mrs3, 0, 16, 0);
		       
		       //FLIPS all necessary bits
		       // Indicate B-Side DRAMS BG1=1 
                       rc_num = rc_num | address_16.setBit(15);  // Set BG1 = 1
 
                       rc_num = rc_num | address_16.flipBit(3,7); // Invert A3:A9
                       rc_num = rc_num | address_16.flipBit(11);  // Invert A11
                       rc_num = rc_num | address_16.flipBit(13);  // Invert A13
                       rc_num = rc_num | address_16.flipBit(14);  // Invert A17
                       rc_num = rc_num | bank_3.flipBit(0,3);	  // Invert BA0,BA1,BG0
		       
		       if (rc_num)
    		       {
    		     	   FAPI_ERR( "mss_ddr4_setup_pda: Error setting up buffers");
    		     	   rc_buff.setEcmdError(rc_num);
    		     	   return rc_buff;
    		       }
		     	   
		     	   if (( address_mirror_map[i_port_number][dimm_number] & (0x08 >> rank_number) ) && (is_sim == 0))
    		       {
    		     	  rc = mss_address_mirror_swizzle(i_target, i_port_number, dimm_number, rank_number, address_16, bank_3);
    		     	  if(rc) return rc;
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
		    }
    		}    
    	    }
    	}
    }
    
    //runs a NOP command for 24 cycle
    rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 24, 0, 16);
    // Raise CKE high with NOPS, waiting min Reset CKE exit time (tXPR) - 400 cycles
    rc_num = rc_num | cke_4.setBit(0,4);
    rc_num = rc_num | csn_8.setBit(0,8);
    rc_num = rc_num | address_16.clearBit(0, 16);
    rc_num = rc_num | odt_4.clearBit(0,4);
    rc_num = rc_num | num_idles_16.clearBit(0,16);
    rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 24, 0, 16);
    rc_num = rc_num | rasn_1.setBit(0,1);
    rc_num = rc_num | casn_1.setBit(0,1);
    rc_num = rc_num | wen_1.setBit(0,1);
    
    if (rc_num)
    {
    	FAPI_ERR( "mss_ddr4_setup_pda: Error setting up buffers");
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
    
    //Setup end bit for CCS
    rc = mss_ccs_set_end_bit (i_target, io_ccs_inst_cnt);
    if (rc) return rc;
    
    //Enable CCS and set RAS/CAS/WE high during idles
   FAPI_INF("Enabling CCS\n");
   reg_address = CCS_MODEQ_AB_REG_0x030106A7;
   rc = fapiGetScom(i_target, reg_address, data_buffer);
   if(rc) return rc;

   rc_num |= data_buffer.setBit(29);    //Enable CCS
   rc_num |= data_buffer.setBit(52);    //RAS high
   rc_num |= data_buffer.setBit(53);    //CAS high
   rc_num |= data_buffer.setBit(54);    //WE high
   if (rc_num) {
      FAPI_ERR( "enable ccs setup: Error setting up buffers");
      rc.setEcmdError(rc_num);
      return rc;
   }
   rc = fapiPutScom(i_target, reg_address, data_buffer);
   if(rc) return rc;


   //Execute the CCS array
   FAPI_INF("Executing the CCS array\n");
   rc = mss_execute_ccs_inst_array (i_target, NUM_POLL, WAIT_TIMER);
   io_ccs_inst_cnt=0;
   
   //exits PDA
   //loops through the DP18's and sets everything to 1's - no PDA
   for(i_port_number=0;i_port_number<MAX_NUM_PORTS;i_port_number++) {
      for(uint8_t dp18 = 0; dp18<MAX_NUM_DP18S;dp18++) {
   	 reg_address = 0x800000010301143full + 0x0001000000000000ull*i_port_number+ 0x0000040000000000ull*(dp18);
   	 rc = fapiGetScom(i_target, reg_address, data_buffer);
   	 if(rc) return rc;

   	 rc_num |= data_buffer.setBit(60,4);	//Enable CCS
   	 if (rc_num) {
   	    FAPI_ERR( "enable ccs setup: Error setting up buffers");
   	    rc.setEcmdError(rc_num);
   	    return rc;
   	 }
   	 rc = fapiPutScom(i_target, reg_address, data_buffer);
   	 if(rc) return rc;
      }
   }
   
   rc = fapiGetScom(i_target,  DPHY01_DDRPHY_WC_CONFIG3_P0_0x8000CC050301143F, data_buffer);
   if(rc) return rc;
   //Setting up CCS mode
   rc_num = rc_num | data_buffer.setBit(48);
   if (rc_num)
   {
       FAPI_ERR( "mss_ddr4_setup_pda: Error setting up buffers");
       rc_buff.setEcmdError(rc_num);
       return rc_buff;
   }
   rc = fapiPutScom(i_target,  DPHY01_DDRPHY_WC_CONFIG3_P0_0x8000CC050301143F, data_buffer);	
   if(rc) return rc;
   
   rc = fapiGetScom(i_target,  DPHY01_DDRPHY_WC_CONFIG3_P1_0x8001CC050301143F, data_buffer);
   if(rc) return rc;
   //Setting up CCS mode
   rc_num = rc_num | data_buffer.setBit(48);
   if (rc_num)
   {
       FAPI_ERR( "mss_ddr4_setup_pda: Error setting up buffers");
       rc_buff.setEcmdError(rc_num);
       return rc_buff;
   }
   rc = fapiPutScom(i_target,  DPHY01_DDRPHY_WC_CONFIG3_P1_0x8001CC050301143F, data_buffer);	
   if(rc) return rc;
   
   return rc;
}// end mss_ddr4_setup_pda


/////////////////////////////////////////////////////////////////////////////////
/// mss_ddr4_pda
/// configures a vector of PDA accesses to run
/////////////////////////////////////////////////////////////////////////////////
ReturnCode mss_ddr4_pda(
            Target& i_target,
	    vector<PDA_MRS_Storage> pda
            )
{
    ReturnCode rc;
    uint8_t dram_loop_end;
    uint8_t dram_loop_end_with_spare;
    
    //gets the rank information
    uint8_t num_ranks_array[2][2]; //[port][dimm]
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target, num_ranks_array);
    if(rc) return rc;
    
    //gets the spare information
    uint8_t num_spare[2][2][4]; //[port][dimm]
    rc = FAPI_ATTR_GET(ATTR_VPD_DIMM_SPARE, &i_target, num_spare);
    if(rc) return rc;
    
    //gets the WR VREF information
    uint8_t wr_vref[2][2][4]; //[port][dimm]
    rc = FAPI_ATTR_GET(ATTR_EFF_VREF_DQ_TRAIN_VALUE, &i_target, wr_vref);
    if(rc) return rc;
    
    
    uint8_t dram_width;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target, dram_width);
    if(rc) return rc;
    
    //sets the loop_end value, to ensure that the proper number of loops are conducted
    if(dram_width == 0x08) {
       dram_loop_end = 9;
    }
    //must be a x4 DRAM
    else {
       dram_loop_end = 18;
    }
    
    uint8_t array[][2][19] = {{{0x18,0x18,0x1c,0x1c,0x18,0x18,0x1c,0x1c,0x18,0x1c,0x18,0x18,0x1c,0x1c,0x1c,0x18,0x1c,0x18,0x18},{0x18,0x1c,0x20,0x1c,0x20,0x1c,0x20,0x20,0x1c,0x1c,0x20,0x1c,0x18,0x1c,0x1c,0x1c,0x1c,0x18,0x18}},{{0x18,0x1c,0x1c,0x1c,0x20,0x1c,0x20,0x18,0x18,0x18,0x1c,0x1c,0x1c,0x18,0x18,0x1c,0x18,0x18,0x1c},{0x18,0x1c,0x18,0x1c,0x20,0x1c,0x18,0x1c,0x20,0x1c,0x1c,0x1c,0x1c,0x24,0x1c,0x1c,0x1c,0x1c,0x1c}}};


    //if pda is empty then, sets up the vector for the MRS storage
    if(pda.size() == 0) {
    	//loops through each port each dimm each rank each dram and sets everything
    	for(uint8_t port = 0; port < MAX_NUM_PORTS; port++) {
    	   for(uint8_t dimm = 0; dimm < MAX_NUM_DIMMS; dimm++) {
    	      for(uint8_t rank = 0; rank < num_ranks_array[port][dimm]; rank++) {
    		 //DIMM has a spare, add one DRAM to the loop
    		 if(num_spare[port][dimm][rank]) {
    		    dram_loop_end_with_spare = dram_loop_end+1;
    		 }
    		 else {
    		    dram_loop_end_with_spare = dram_loop_end;
    		 }
    		 //loops through all dram
    		 for(uint8_t dram = 0; dram < dram_loop_end_with_spare; dram++) {
    		 //uint8_t ad,uint32_t an,uint8_t d,uint8_t r,uint8_t 
    		    if(port == 0) wr_vref[port][dimm][rank] = dram*3;
    		    else wr_vref[port][dimm][rank] = 57-dram*3;
    		    if(wr_vref[port][dimm][rank]  > 50) wr_vref[port][dimm][rank] = 50;
    		    pda.push_back(PDA_MRS_Storage(array[port][dimm][dram],ATTR_EFF_VREF_DQ_TRAIN_VALUE,dram,dimm,rank,port));
    		    FAPI_INF("PDA STRING: %d %s",pda.size()-1,pda[pda.size()-1].c_str());
    		 }
    	      }
    	   }
    	}
    }
    rc = mss_ddr4_run_pda(i_target,pda);
    return rc;
}

/////////////////////////////////////////////////////////////////////////////////
/// mss_ddr4_run_pda
/// runs per-DRAM addressability funcitonality on both ports on the passed MBA
/////////////////////////////////////////////////////////////////////////////////
ReturnCode mss_ddr4_run_pda(
            Target& i_target,
	    vector<PDA_MRS_Storage> pda
            )
{
    ReturnCode rc;  
    //no PDA was entered, just exit
    if(pda.size() == 0) return rc;
    
    uint32_t io_ccs_inst_cnt = 0;
    const uint32_t NUM_POLL = 10;
    const uint32_t WAIT_TIMER = 1500;
    ReturnCode rc_buff;
    uint32_t rc_num = 0;
    ecmdDataBufferBase data_buffer_64(64);
    ecmdDataBufferBase address_16(16);
    ecmdDataBufferBase address_16_backup(16);
    ecmdDataBufferBase bank_3(3);
    ecmdDataBufferBase activate_1(1);
    rc_num = rc_num | activate_1.setBit(0);
    ecmdDataBufferBase rasn_1(1);
    ecmdDataBufferBase casn_1(1);
    ecmdDataBufferBase wen_1(1);
    ecmdDataBufferBase cke_4(4);
    rc_num = rc_num | cke_4.setBit(0,4);
    ecmdDataBufferBase csn_8(8);
    rc_num = rc_num | csn_8.setBit(0,8);
    ecmdDataBufferBase odt_4(4);
    
    ecmdDataBufferBase ddr_cal_type_4(4);

    ecmdDataBufferBase num_idles_16(16);
    ecmdDataBufferBase num_repeat_16(16);
    ecmdDataBufferBase data_20(20);
    ecmdDataBufferBase read_compare_1(1);
    ecmdDataBufferBase rank_cal_4(4);
    ecmdDataBufferBase ddr_cal_enable_1(1);
    ecmdDataBufferBase ccs_end_1(1);
    
    //checks each MRS and saves each 
    rc = mss_ddr4_checksort_pda(i_target,pda);
    if(rc) return rc;
    
    //loads in dram type
    uint8_t dimm_type;
    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target, dimm_type);
    if(rc) return rc;
    
    //dram density
    uint8_t dram_width;
    
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target, dram_width);
    if(rc) return rc;
    
    ecmdDataBufferBase data_buffer(64);
    
    uint8_t num_ranks_array[2][2]; //[port][dimm]
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target, num_ranks_array);
    if(rc) return rc;

    uint8_t is_sim = 0;
    rc = FAPI_ATTR_GET(ATTR_IS_SIMULATION, NULL, is_sim);
    if(rc) return rc;

    uint8_t address_mirror_map[2][2]; //address_mirror_map[port][dimm]
    rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_ADDRESS_MIRRORING, &i_target, address_mirror_map);
    if(rc) return rc;

    rc = mss_ddr4_setup_pda(i_target, io_ccs_inst_cnt );
    if(rc)  return rc;
    
    rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 100, 0, 16);
   
   
   
    rc_num = rc_num | cke_4.setBit(0,4);
    rc_num = rc_num | csn_8.setBit(0,8);
    rc_num = rc_num | address_16.clearBit(0, 16);
    rc_num = rc_num | odt_4.clearBit(0,4);
    rc_num = rc_num | rasn_1.clearBit(0,1);
    rc_num = rc_num | casn_1.clearBit(0,1);
    rc_num = rc_num | wen_1.clearBit(0,1);
   
   //gets the start PDA values
   uint8_t prev_dram = pda[0].dram;
   uint8_t prev_port = pda[0].port;
   uint8_t prev_rank = pda[0].rank;
   uint8_t prev_dimm = pda[0].dimm;
   uint8_t prev_mrs  = pda[0].MRS;
   rc = mss_ddr4_load_nominal_mrs_pda(i_target,bank_3,address_16, prev_mrs, prev_port, prev_dimm, prev_rank);
   if(rc) return rc;
   
   vector<PDA_Scom_Storage> scom_storage;
   scom_storage.clear();
   rc = mss_ddr4_add_dram_pda(i_target,prev_port,prev_dram,scom_storage);
   if(rc) return rc;
   
   //runs through each PDA command
   for(uint32_t i=0;i<pda.size();i++) {
      FAPI_INF("Target %s On PDA %d is %s",i_target.toEcmdString(),i,pda[i].c_str());
      //dram, port, rank, dimm, and mrs are the same
      if(prev_dram == pda[i].dram && prev_port == pda[i].port && prev_rank == pda[i].rank && prev_dimm == pda[i].dimm && prev_mrs == pda[i].MRS) {
         //modifies this attribute
         rc = mss_ddr4_modify_mrs_pda(i_target,address_16, pda[i].attribute_name,pda[i].attribute_data);
         if(rc) return rc;
      }
      //another MRS, so set this MRS.  do additional checks to later in the code
      else {
         
	 //adds values to a backup address_16 before doing the mirroring
	 address_16_backup.clearBit(0, 16);
	 rc_num = rc_num | address_16_backup.insert(address_16, 0, 16, 0);
	 
         //loads the previous DRAM
         if (( address_mirror_map[prev_port][prev_dimm] & (0x08 >> prev_rank) ) && (is_sim == 0))
   	 {
   	     rc = mss_address_mirror_swizzle(i_target, prev_port, prev_dimm, prev_rank, address_16, bank_3);
   	     if(rc) return rc;
   	 }
	 
	 // Only corresponding CS to rank
   	 rc_num = rc_num | csn_8.setBit(0,8); 
   	 rc_num = rc_num | csn_8.clearBit(prev_rank+4*prev_dimm);
	 
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
   	     	  prev_port);
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
	 
	 //is an R or LR DIMM -> do a B side MRS write
	 if ( (dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_RDIMM) || (dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM) ) {
	    //takes values from the backup
	    address_16.clearBit(0, 16);
	    rc_num = rc_num | address_16.insert(address_16_backup, 0, 16, 0);
	    
	    //FLIPS all necessary bits
	    // Indicate B-Side DRAMS BG1=1 
            rc_num = rc_num | address_16.setBit(15);  // Set BG1 = 1
 
            rc_num = rc_num | address_16.flipBit(3,7); // Invert A3:A9
            rc_num = rc_num | address_16.flipBit(11);  // Invert A11
            rc_num = rc_num | address_16.flipBit(13);  // Invert A13
            rc_num = rc_num | address_16.flipBit(14);  // Invert A17
            rc_num = rc_num | bank_3.flipBit(0,3);     // Invert BA0,BA1,BG0
	    
	    //loads the previous DRAM
            if (( address_mirror_map[prev_port][prev_dimm] & (0x08 >> prev_rank) ) && (is_sim == 0))
   	    {
   	   	rc = mss_address_mirror_swizzle(i_target, prev_port, prev_dimm, prev_rank, address_16, bank_3);
   	   	if(rc) return rc;
   	    }
	    
	    // Only corresponding CS to rank
   	    rc_num = rc_num | csn_8.setBit(0,8); 
   	    rc_num = rc_num | csn_8.clearBit(prev_rank+4*prev_dimm);
	    
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
   	   	     prev_port);
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
	 }
	 
	 //the DRAM are different, so kick off CCS, and clear out the MRS DRAMs and set up a new DRAM
	 if(prev_dram != pda[i].dram) {
	    //sets a NOP as the last command
	    rc_num = rc_num | cke_4.setBit(0,4);
    	    rc_num = rc_num | csn_8.setBit(0,8);
    	    rc_num = rc_num | address_16.clearBit(0, 16);
    	    rc_num = rc_num | rasn_1.setBit(0,1);
    	    rc_num = rc_num | casn_1.setBit(0,1);
    	    rc_num = rc_num | wen_1.setBit(0,1);
	    
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
                     prev_port);
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
	    
	    //Setup end bit for CCS
            rc = mss_ccs_set_end_bit (i_target, io_ccs_inst_cnt-1);
            if (rc) return rc;
   
            //Execute the CCS array
            FAPI_INF("Executing the CCS array\n");
            rc = mss_execute_ccs_inst_array (i_target, NUM_POLL, WAIT_TIMER);
            if(rc) return rc;
	    io_ccs_inst_cnt = 0;
	    
	    // Sets NOP as the first command
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
                     prev_port);
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
	    
	    rc_num = rc_num | cke_4.setBit(0,4);
    	    rc_num = rc_num | csn_8.setBit(0,8);
    	    rc_num = rc_num | address_16.clearBit(0, 16);
    	    rc_num = rc_num | rasn_1.clearBit(0,1);
    	    rc_num = rc_num | casn_1.clearBit(0,1);
    	    rc_num = rc_num | wen_1.clearBit(0,1);
	    
	    //loops through and clears out the storage class
	    for(uint32_t scoms = 0; scoms < scom_storage.size(); scoms++) {
	       rc = fapiGetScom(i_target, scom_storage[scoms].scom_addr, data_buffer);
               if(rc) return rc;

   	       rc_num |= data_buffer.setBit(scom_storage[scoms].start_bit,scom_storage[scoms].num_bits);  //Enable CCS
   	       if (rc_num) {
   	    	  FAPI_ERR( "enable ccs setup: Error setting up buffers");
   	    	  rc.setEcmdError(rc_num);
   	    	  return rc;
   	       }
   	       rc = fapiPutScom(i_target, scom_storage[scoms].scom_addr, data_buffer);
               if(rc) return rc;
	    }
	    scom_storage.clear();
	    //enables the next dram scom
	    rc = mss_ddr4_add_dram_pda(i_target,pda[i].port,pda[i].dram,scom_storage);
            if(rc) return rc;
	 }
	 //different port but same DRAM, enable the next scom
	 else if(prev_port != pda[i].port) {
	    //enables the next dram scom
	    rc = mss_ddr4_add_dram_pda(i_target,pda[i].port,pda[i].dram,scom_storage);
            if(rc) return rc;
	 }
	 
	 //loads in the nominal MRS for this target
	 prev_dram = pda[i].dram;
	 prev_port = pda[i].port;
	 prev_rank = pda[i].rank;
	 prev_dimm = pda[i].dimm;
	 prev_mrs  = pda[i].MRS;
	 
	 rc = mss_ddr4_load_nominal_mrs_pda(i_target,bank_3,address_16, prev_mrs, prev_port, prev_dimm, prev_rank);
	 //modifies the MRS
	 rc = mss_ddr4_modify_mrs_pda(i_target,address_16, pda[i].attribute_name,pda[i].attribute_data);
         if(rc) return rc;
      } 
   }      
   
   //runs the last PDA command
   //adds values to a backup address_16 before doing the mirroring
   address_16_backup.clearBit(0, 16);
   rc_num = rc_num | address_16_backup.insert(address_16, 0, 16, 0);

   //loads the previous DRAM
   if (( address_mirror_map[prev_port][prev_dimm] & (0x08 >> prev_rank) ) && (is_sim == 0))
   {
       rc = mss_address_mirror_swizzle(i_target, prev_port, prev_dimm, prev_rank, address_16, bank_3);
       if(rc) return rc;
   }

   // Only corresponding CS to rank
   rc_num = rc_num | csn_8.setBit(0,8); 
   rc_num = rc_num | csn_8.clearBit(prev_rank+4*prev_dimm);

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
   	    prev_port);
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

   //is an R or LR DIMM -> do a B side MRS write
   if ( (dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_RDIMM) || (dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM) ) {
      //takes values from the backup
      address_16.clearBit(0, 16);
      rc_num = rc_num | address_16.insert(address_16_backup, 0, 16, 0);
      
      //FLIPS all necessary bits
      // Indicate B-Side DRAMS BG1=1 
      rc_num = rc_num | address_16.setBit(15);  // Set BG1 = 1
 
      rc_num = rc_num | address_16.flipBit(3,7); // Invert A3:A9
      rc_num = rc_num | address_16.flipBit(11);  // Invert A11
      rc_num = rc_num | address_16.flipBit(13);  // Invert A13
      rc_num = rc_num | address_16.flipBit(14);  // Invert A17
      rc_num = rc_num | bank_3.flipBit(0,3);	 // Invert BA0,BA1,BG0
      
      //loads the previous DRAM
      if (( address_mirror_map[prev_port][prev_dimm] & (0x08 >> prev_rank) ) && (is_sim == 0))
      {
   	  rc = mss_address_mirror_swizzle(i_target, prev_port, prev_dimm, prev_rank, address_16, bank_3);
   	  if(rc) return rc;
      }
      
      // Only corresponding CS to rank
      rc_num = rc_num | csn_8.setBit(0,8); 
      rc_num = rc_num | csn_8.clearBit(prev_rank+4*prev_dimm);
      
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
   	       prev_port);
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
   }
   
   
   //sets a NOP as the last command
   rc_num = rc_num | cke_4.setBit(0,4);
   rc_num = rc_num | csn_8.setBit(0,8);
   rc_num = rc_num | address_16.clearBit(0, 16);
   rc_num = rc_num | rasn_1.setBit(0,1);
   rc_num = rc_num | casn_1.setBit(0,1);
   rc_num = rc_num | wen_1.setBit(0,1);

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
   	    prev_port);
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
   
   //Setup end bit for CCS
   rc = mss_ccs_set_end_bit (i_target, io_ccs_inst_cnt-1);
   if (rc) return rc;
   
   //Execute the CCS array
   FAPI_INF("Executing the CCS array\n");
   rc = mss_execute_ccs_inst_array (i_target, NUM_POLL, WAIT_TIMER);
   if(rc) return rc;
   
   //loops through and clears out the storage class
   for(uint32_t scoms = 0; scoms < scom_storage.size(); scoms++) {
      rc = fapiGetScom(i_target, scom_storage[scoms].scom_addr, data_buffer);
      if(rc) return rc;

      rc_num |= data_buffer.setBit(scom_storage[scoms].start_bit,scom_storage[scoms].num_bits);  //Enable CCS
      if (rc_num) {
   	 FAPI_ERR( "enable ccs setup: Error setting up buffers");
   	 rc.setEcmdError(rc_num);
   	 return rc;
      }
      rc = fapiPutScom(i_target, scom_storage[scoms].scom_addr, data_buffer);
      if(rc) return rc;
   }
   //}
      
   io_ccs_inst_cnt = 0;
   rc = mss_ddr4_disable_pda(i_target,io_ccs_inst_cnt);
   return rc;
}


//////////////////////////////////////////////////////////////////////////////////
/// mss_ddr4_add_dram_pda
/// adds a specific DRAM on a specific port to receive the current MRS command in PDA mode
//////////////////////////////////////////////////////////////////////////////////
ReturnCode mss_ddr4_add_dram_pda(Target& i_target,uint8_t port,uint8_t dram,vector<PDA_Scom_Storage> & scom_storage) {
   ReturnCode rc;
   ecmdDataBufferBase data_buffer(64);
   //access delay regs function
   uint8_t i_rank_pair = 0;
   input_type_t i_input_type_e = WR_DQ;
   uint8_t i_input_index = 75;
   uint8_t i_verbose = 1;
   uint8_t phy_lane = 6;
   uint8_t phy_block = 6;
   uint8_t flag = 0;
   uint32_t scom_len = 0;
   uint32_t scom_start = 0;
   uint32_t rc_num = 0;
   
   
   uint8_t dram_width;
   rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target, dram_width);
   if(rc) return rc;
   
   // C4 DQ to lane/block (flag = 0) in PHY or lane/block to C4 DQ (flag = 1) 
   // In this case moving from lane/block to C4 DQ to use access_delay_reg
   i_input_index = 4*dram;
   rc = mss_c4_phy(i_target,port,i_rank_pair,i_input_type_e,i_input_index,i_verbose,phy_lane,phy_block,flag); 

   uint64_t reg_address = 0x800000010301143full + 0x0001000000000000ull*port+ 0x0000040000000000ull*(phy_block);
   //gets the lane and number of bits to set to 0's
   if(dram_width == 0x04) {
      scom_start = 60 + (uint32_t)(phy_lane/4);
      scom_len = 1;
   }
   //x8 DIMM
   else {
      scom_start = 60 + (uint32_t)((phy_lane/8)*2);
      scom_len = 2;
   }
   FAPI_INF("Enabling %016llx start at %d for %d bits",reg_address,scom_start,scom_len);
   
   rc = fapiGetScom(i_target, reg_address, data_buffer);
   if(rc) return rc;

   rc_num |= data_buffer.clearBit(scom_start,scom_len);	 //Enable CCS
   if (rc_num) {
      FAPI_ERR( "enable ccs setup: Error setting up buffers");
      rc.setEcmdError(rc_num);
      return rc;
   }
   rc = fapiPutScom(i_target, reg_address, data_buffer);
   if(rc) return rc;
   
   scom_storage.push_back(PDA_Scom_Storage(reg_address,scom_start,scom_len));
   
   return rc;
}

//////////////////////////////////////////////////////////////////////////////////
/// mss_ddr4_disable_pda
/// disables per-DRAM addressability funcitonality on both ports on the passed MBA
//////////////////////////////////////////////////////////////////////////////////
ReturnCode mss_ddr4_disable_pda(Target& i_target,uint32_t& io_ccs_inst_cnt) {
    uint32_t i_port_number=0;
    uint32_t dimm_number;
    uint32_t rank_number;
    const uint32_t NUM_POLL = 10;
    const uint32_t WAIT_TIMER = 1500;
    ReturnCode rc;  
    ReturnCode rc_buff;
    uint32_t rc_num = 0;
    uint64_t reg_address;
    ecmdDataBufferBase data_buffer(64);
    ecmdDataBufferBase data_buffer_64(64);
    ecmdDataBufferBase address_16(16);
    ecmdDataBufferBase bank_3(3);
    ecmdDataBufferBase activate_1(1);
    rc_num = rc_num | activate_1.setBit(0);
    ecmdDataBufferBase rasn_1(1);
    ecmdDataBufferBase casn_1(1);
    ecmdDataBufferBase wen_1(1);
    ecmdDataBufferBase cke_4(4);
    rc_num = rc_num | cke_4.setBit(0,4);
    ecmdDataBufferBase csn_8(8);
    rc_num = rc_num | csn_8.setBit(0,8);
    ecmdDataBufferBase odt_4(4);
    ecmdDataBufferBase ddr_cal_type_4(4);

    ecmdDataBufferBase num_idles_16(16);
    ecmdDataBufferBase num_repeat_16(16);
    ecmdDataBufferBase data_20(20);
    ecmdDataBufferBase read_compare_1(1);
    ecmdDataBufferBase rank_cal_4(4);
    ecmdDataBufferBase ddr_cal_enable_1(1);
    ecmdDataBufferBase ccs_end_1(1);

    ecmdDataBufferBase mrs3(16);
    uint16_t MRS3 = 0;
    
    uint8_t num_ranks_array[2][2]; //[port][dimm]
    
    uint8_t num_ranks;
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target, num_ranks_array);
    if(rc) return rc;

    uint8_t dimm_type;
    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target, dimm_type);
    if(rc) return rc;

    uint8_t is_sim = 0;
    rc = FAPI_ATTR_GET(ATTR_IS_SIMULATION, NULL, is_sim);
    if(rc) return rc;

    uint8_t address_mirror_map[2][2]; //address_mirror_map[port][dimm]
    rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_ADDRESS_MIRRORING, &i_target, address_mirror_map);
    if(rc) return rc;

    // WORKAROUNDS 
    rc = fapiGetScom(i_target, CCS_MODEQ_AB_REG_0x030106A7, data_buffer);
    if(rc) return rc;
    //Setting up CCS mode
    rc_num = rc_num | data_buffer.setBit(51);
    if (rc_num) {
      FAPI_ERR( "disable ccs setup: Error disabling up buffers");
      rc_buff.setEcmdError(rc_num);
      return rc_buff;
    }
    rc = fapiPutScom(i_target, CCS_MODEQ_AB_REG_0x030106A7, data_buffer);
    if(rc) return rc;   
    
    //loops through port 0 and port 1 on the given MBA
    for(i_port_number=0;i_port_number<MAX_NUM_PORTS;i_port_number++) {
       // Raise CKE high with NOPS, waiting min Reset CKE exit time (tXPR) - 400 cycles
       rc_num = rc_num | cke_4.setBit(0,4);
       rc_num = rc_num | csn_8.setBit(0,8);
       rc_num = rc_num | address_16.clearBit(0, 16);
       rc_num = rc_num | odt_4.clearBit(0,4);
       rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 400, 0, 16);
       if (rc_num) {
          FAPI_ERR( "disable ccs setup: Error disabling up buffers");
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
    }
    
    
    //Sets up MRS3 -> the MRS that has PDA
    uint8_t mpr_op; // MPR Op
    rc = FAPI_ATTR_GET(ATTR_EFF_MPR_MODE, &i_target, mpr_op);
    if(rc) return rc;
    uint8_t mpr_page; // MPR Page Selection  
    rc = FAPI_ATTR_GET(ATTR_EFF_MPR_PAGE, &i_target, mpr_page);
    if(rc) return rc;
    uint8_t geardown_mode; // Gear Down Mode  
    rc = FAPI_ATTR_GET(ATTR_EFF_GEARDOWN_MODE, &i_target, geardown_mode);
    if(rc) return rc;
    uint8_t temp_readout; // Temperature sensor readout  
    rc = FAPI_ATTR_GET(ATTR_EFF_TEMP_READOUT, &i_target, temp_readout);
    if(rc) return rc;
    uint8_t fine_refresh; // fine refresh mode  
    rc = FAPI_ATTR_GET(ATTR_EFF_FINE_REFRESH_MODE, &i_target, fine_refresh);
    if(rc) return rc;
    uint8_t wr_latency; // write latency for CRC and DM  
    rc = FAPI_ATTR_GET(ATTR_EFF_CRC_WR_LATENCY, &i_target, wr_latency);
    if(rc) return rc;
    uint8_t read_format; // MPR READ FORMAT  
    rc = FAPI_ATTR_GET(ATTR_EFF_MPR_RD_FORMAT, &i_target, read_format);
    if(rc) return rc;
    
    //exits PDA
    for(i_port_number=0;i_port_number<2;i_port_number++) {
    //loops through the DP18's and sets everything to 0's
      for(uint8_t dp18 = 0; dp18<MAX_NUM_DP18S;dp18++) {
   	 reg_address = 0x800000010301143full + 0x0001000000000000ull*i_port_number+ 0x0000040000000000ull*(dp18);
   	 rc = fapiGetScom(i_target, reg_address, data_buffer);
   	 if(rc) return rc;

   	 rc_num |= data_buffer.clearBit(60,4);    //Enable CCS
   	 if (rc_num) {
   	    FAPI_ERR( "enable ccs setup: Error setting up buffers");
   	    rc.setEcmdError(rc_num);
   	    return rc;
   	 }
   	 rc = fapiPutScom(i_target, reg_address, data_buffer);
   	 if(rc) return rc;
      }
   }
    
    //exits PDA
    for(i_port_number=0;i_port_number<2;i_port_number++) {
    	for ( dimm_number = 0; dimm_number < MAX_NUM_DIMMS; dimm_number++)
    	{
    	    num_ranks = num_ranks_array[i_port_number][dimm_number];

    	    if (num_ranks == 0)
    	    {
    		FAPI_INF( "PORT%d DIMM%d not configured. Num_ranks: %d ", i_port_number, dimm_number, num_ranks);
    	    }
    	    else
    	    {
    		// Rank 0-3
    		for ( rank_number = 0; rank_number < num_ranks; rank_number++)
    		{
    		   // Only corresponding CS to rank
    		   rc_num = rc_num | csn_8.setBit(0,8); 
    		   rc_num = rc_num | csn_8.clearBit(rank_number+4*dimm_number);
    			
    		   rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 0, 1, 7);
    		   rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 1, 1, 6);
    		   rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 2, 1, 5);
    				
	           //enables PDA
	           rc_num = rc_num | mrs3.insert((uint8_t) mpr_page, 0, 2);
	           rc_num = rc_num | mrs3.insert((uint8_t) mpr_op, 2, 1);
	           rc_num = rc_num | mrs3.insert((uint8_t) geardown_mode, 3, 1);
	           rc_num = rc_num | mrs3.insert((uint8_t) 0x00, 4, 1);
	           rc_num = rc_num | mrs3.insert((uint8_t) temp_readout, 5, 1);
	           rc_num = rc_num | mrs3.insert((uint8_t) fine_refresh, 6, 3);
	           rc_num = rc_num | mrs3.insert((uint8_t) wr_latency, 9, 2);
	           rc_num = rc_num | mrs3.insert((uint8_t) read_format, 11, 2);
	           rc_num = rc_num | mrs3.insert((uint8_t) 0x00, 13, 2);
	           rc_num = rc_num | mrs3.extractPreserve(&MRS3, 0, 16, 0);
	           rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 100, 0, 16);
		   
		   //copies over values
    		   rc_num = rc_num | address_16.insert(mrs3, 0, 16, 0);
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
		   
		   //if the DIMM is an R or LR DIMM, then run inverted for the B-Side DRAM
                   if ( (dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_RDIMM) || (dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM) ) 
		   {
		   
		       //reload all MRS values (removes address swizzling)
		        // Only corresponding CS to rank
    		       rc_num = rc_num | csn_8.setBit(0,8); 
    		       rc_num = rc_num | csn_8.clearBit(rank_number+4*dimm_number);
    		    	    
    		       rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 0, 1, 7);
    		       rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 1, 1, 6);
    		       rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 2, 1, 5);
    		    		    
	               //enables PDA
	               rc_num = rc_num | mrs3.insert((uint8_t) mpr_page, 0, 2);
	               rc_num = rc_num | mrs3.insert((uint8_t) mpr_op, 2, 1);
	               rc_num = rc_num | mrs3.insert((uint8_t) geardown_mode, 3, 1);
	               rc_num = rc_num | mrs3.insert((uint8_t) 0x00, 4, 1);
	               rc_num = rc_num | mrs3.insert((uint8_t) temp_readout, 5, 1);
	               rc_num = rc_num | mrs3.insert((uint8_t) fine_refresh, 6, 3);
	               rc_num = rc_num | mrs3.insert((uint8_t) wr_latency, 9, 2);
	               rc_num = rc_num | mrs3.insert((uint8_t) read_format, 11, 2);
	               rc_num = rc_num | mrs3.insert((uint8_t) 0x00, 13, 2);
	               rc_num = rc_num | mrs3.extractPreserve(&MRS3, 0, 16, 0);
	               rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 100, 0, 16);
		       //copies over values
		       rc_num = rc_num | address_16.insert(mrs3, 0, 16, 0);
		       
		       //FLIPS all necessary bits
		       // Indicate B-Side DRAMS BG1=1 
                       rc_num = rc_num | address_16.setBit(15);  // Set BG1 = 1
 
                       rc_num = rc_num | address_16.flipBit(3,7); // Invert A3:A9
                       rc_num = rc_num | address_16.flipBit(11);  // Invert A11
                       rc_num = rc_num | address_16.flipBit(13);  // Invert A13
                       rc_num = rc_num | address_16.flipBit(14);  // Invert A17
                       rc_num = rc_num | bank_3.flipBit(0,3);	  // Invert BA0,BA1,BG0
		       
		       if (rc_num)
    		       {
    		     	   FAPI_ERR( "mss_ddr4_setup_pda: Error setting up buffers");
    		     	   rc_buff.setEcmdError(rc_num);
    		     	   return rc_buff;
    		       }
		     	   
		     	   if (( address_mirror_map[i_port_number][dimm_number] & (0x08 >> rank_number) ) && (is_sim == 0))
    		       {
    		     	  rc = mss_address_mirror_swizzle(i_target, i_port_number, dimm_number, rank_number, address_16, bank_3);
    		     	  if(rc) return rc;
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
		    }
    		}    
    	    }
    	}
   }
   
   //Setup end bit for CCS
    rc = mss_ccs_set_end_bit (i_target, io_ccs_inst_cnt-1);
    if (rc) return rc;
   
   //Execute the CCS array
   FAPI_INF("Executing the CCS array\n");
   rc = mss_execute_ccs_inst_array (i_target, NUM_POLL, WAIT_TIMER);
   
   //Disable CCS
   FAPI_INF("Disabling CCS\n");
   reg_address = CCS_MODEQ_AB_REG_0x030106A7;
   rc = fapiGetScom(i_target, reg_address, data_buffer);
   if(rc) return rc;


   rc_num |= data_buffer.clearBit(29);
   if (rc_num) {
      FAPI_ERR( "disable ccs setup: Error disabling up buffers");
      rc_buff.setEcmdError(rc_num);
      return rc_buff;
   }
   rc = fapiPutScom(i_target, reg_address, data_buffer);
   if(rc) return rc;
   
   //disables the DDR4 PDA mode writes  
   rc = fapiGetScom(i_target,  DPHY01_DDRPHY_WC_CONFIG3_P0_0x8000CC050301143F, data_buffer);
    if(rc) return rc;
    //Setting up CCS mode
    rc_num = rc_num | data_buffer.clearBit(48);
    if (rc_num)
    {
    	FAPI_ERR( "mss_ddr4_setup_pda: Error setting up buffers");
    	rc_buff.setEcmdError(rc_num);
    	return rc_buff;
    }
    rc = fapiPutScom(i_target,  DPHY01_DDRPHY_WC_CONFIG3_P0_0x8000CC050301143F, data_buffer);    
    if(rc) return rc;
    
    rc = fapiGetScom(i_target,  DPHY01_DDRPHY_WC_CONFIG3_P1_0x8001CC050301143F, data_buffer);
    if(rc) return rc;
    //Setting up CCS mode
    rc_num = rc_num | data_buffer.clearBit(48);
    if (rc_num)
    {
    	FAPI_ERR( "mss_ddr4_setup_pda: Error setting up buffers");
    	rc_buff.setEcmdError(rc_num);
    	return rc_buff;
    }
    rc = fapiPutScom(i_target,  DPHY01_DDRPHY_WC_CONFIG3_P1_0x8001CC050301143F, data_buffer);    
    if(rc) return rc;
   
   FAPI_INF("Successfully exited out of PDA mode.");
   io_ccs_inst_cnt = 0;
   return rc;
}

//////////////////////////////////////////////////////////////////////////////////
/// mss_ddr4_modify_mrs_pda
/// disables per-DRAM addressability funcitonality on both ports on the passed MBA
//////////////////////////////////////////////////////////////////////////////////
ReturnCode mss_ddr4_modify_mrs_pda(Target& i_target,ecmdDataBufferBase& address_16,uint32_t attribute_name,uint8_t attribute_data) {
   ReturnCode rc;
   uint32_t rc_num = 0;
   uint8_t dram_bl = attribute_data;
   uint8_t read_bt = attribute_data; //Read Burst Type 
   uint8_t dram_cl = attribute_data;
   uint8_t test_mode = attribute_data; //TEST MODE 
   uint8_t dll_reset = attribute_data; //DLL Reset 
   uint8_t dram_wr = attribute_data; //DRAM write recovery
   uint8_t dram_rtp = attribute_data; //DRAM RTP - read to precharge
   uint8_t dram_wr_rtp = attribute_data;
   uint8_t dll_precharge = attribute_data; //DLL Control For Precharge if (dll_precharge == ENUM_ATTR_EFF_DRAM_DLL_PPD_SLOWEXIT)
   uint8_t dll_enable = attribute_data; //DLL Enable 
   uint8_t out_drv_imp_cntl = attribute_data;
   uint8_t dram_rtt_nom = attribute_data;
   uint8_t dram_al = attribute_data;
   uint8_t wr_lvl = attribute_data; //write leveling enable
   uint8_t tdqs_enable = attribute_data; //TDQS Enable 
   uint8_t q_off = attribute_name; //Qoff - Output buffer Enable 
   uint8_t lpasr = attribute_data; // Low Power Auto Self-Refresh -- new not yet supported
   uint8_t cwl = attribute_data; // CAS Write Latency 
   uint8_t dram_rtt_wr = attribute_data;
   uint8_t mpr_op = attribute_data; // MPR Op
   uint8_t mpr_page = attribute_data; // MPR Page Selection  
   uint8_t geardown_mode = attribute_data; // Gear Down Mode  
   uint8_t temp_readout = attribute_data; // Temperature sensor readout  
   uint8_t fine_refresh = attribute_data; // fine refresh mode  
   uint8_t wr_latency = attribute_data; // write latency for CRC and DM  
   uint8_t write_crc = attribute_data; // CAS Write Latency 
   uint8_t read_format = attribute_data; // MPR READ FORMAT  
   uint8_t max_pd_mode = attribute_data; // Max Power down mode 
   uint8_t temp_ref_range = attribute_data; // Temp ref range 
   uint8_t temp_ref_mode = attribute_data; // Temp controlled ref mode 
   uint8_t vref_mon = attribute_data; // Internal Vref Monitor 
   uint8_t cs_cmd_latency = attribute_data; // CS to CMD/ADDR Latency 
   uint8_t ref_abort = attribute_data; // Self Refresh Abort 
   uint8_t rd_pre_train_mode = attribute_data; // Read Pre amble Training Mode 
   uint8_t rd_preamble = attribute_data; // Read Pre amble 
   uint8_t wr_preamble = attribute_data; // Write Pre amble 
   uint8_t ca_parity_latency = attribute_data; //C/A Parity Latency Mode  
   uint8_t crc_error_clear = attribute_data; //CRC Error Clear  
   uint8_t ca_parity_error_status = attribute_data; //C/A Parity Error Status  
   uint8_t odt_input_buffer = attribute_data; //ODT Input Buffer during power down  
   uint8_t rtt_park = attribute_data; //RTT_Park value  
   uint8_t ca_parity = attribute_data; //CA Parity Persistance Error  
   uint8_t data_mask = attribute_data; //Data Mask  
   uint8_t write_dbi = attribute_data; //Write DBI  
   uint8_t read_dbi = attribute_data; //Read DBI  
   uint8_t vrefdq_train_value = attribute_data; //vrefdq_train value   
   uint8_t vrefdq_train_range = attribute_data; //vrefdq_train range   
   uint8_t vrefdq_train_enable = attribute_data; //vrefdq_train enable  
   uint8_t tccd_l = attribute_data; //tccd_l  
   uint8_t dram_access;

   switch (attribute_name) {
       case ATTR_EFF_DRAM_BL:
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
	   rc_num = rc_num | address_16.insert((uint8_t) dram_bl, 0, 2, 0);
	   break;
       case ATTR_EFF_DRAM_RBT:
	   if (read_bt == ENUM_ATTR_EFF_DRAM_RBT_SEQUENTIAL)
           {
               read_bt = 0x00;
           }
           else if (read_bt == ENUM_ATTR_EFF_DRAM_RBT_INTERLEAVE)
           {
               read_bt = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) read_bt, 3, 1, 0);
	   break;
       case ATTR_EFF_DRAM_CL:
	   if ((dram_cl > 8)&&(dram_cl < 17))
           {
               dram_cl = dram_cl - 9; 
           }
           else if ((dram_cl > 17)&&(dram_cl < 25))
           {
               dram_cl = (dram_cl >> 1) - 1;   
           }
           dram_cl = mss_reverse_8bits(dram_cl);
           rc_num = rc_num | address_16.insert((uint8_t) dram_cl, 2, 1, 0);
           rc_num = rc_num | address_16.insert((uint8_t) dram_cl, 4, 3, 1);
	   break;
       case ATTR_EFF_DRAM_TM:
	   if (test_mode == ENUM_ATTR_EFF_DRAM_TM_NORMAL)
           {
               test_mode = 0x00;
           }
           else if (test_mode == ENUM_ATTR_EFF_DRAM_TM_TEST)
           {
               test_mode = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) test_mode, 7, 1);
	   break;
       case ATTR_EFF_DRAM_DLL_RESET:
	   dll_reset = 0x00;
	   FAPI_ERR( "ERROR: ATTR_EFF_DRAM_DLL_RESET accessed during PDA functionality, overwritten");
           rc_num = rc_num | address_16.insert((uint8_t) dll_reset, 8, 1);
	   break;
       case ATTR_EFF_DRAM_WR:
           if ( (dram_wr == 10) )//&& (dram_rtp == 5) )
           {
               dram_wr_rtp = 0x00;
           }
           else if ( (dram_wr == 12) )//&& (dram_rtp == 6) )
           {
               dram_wr_rtp = 0x80;
           }
           else if ( (dram_wr == 13) )//&& (dram_rtp == 7) )
           {
               dram_wr_rtp = 0x40;
           }
           else if ( (dram_wr == 14) )//&& (dram_rtp == 8) )
           {
               dram_wr_rtp = 0xC0;
           }
           else if ( (dram_wr == 18) )//&& (dram_rtp == 9) )
           {
               dram_wr_rtp = 0x20;
           }
           else if ( (dram_wr == 20) )//&& (dram_rtp == 10) )
           {
               dram_wr_rtp = 0xA0;
           }
           else if ( (dram_wr == 24) )//&& (dram_rtp == 12) )
           {
               dram_wr_rtp = 0x60;
           }
    	   rc_num = rc_num | address_16.insert((uint8_t) dram_wr_rtp, 9, 3);
	   break;
       case ATTR_EFF_DRAM_TRTP:
           if ( (dram_rtp == 5) )
           {
               dram_wr_rtp = 0x00;
           }
           else if ( (dram_rtp == 6) )
           {
               dram_wr_rtp = 0x80;
           }
           else if ( (dram_rtp == 7) )
           {
               dram_wr_rtp = 0x40;
           }
           else if ( (dram_rtp == 8) )
           {
               dram_wr_rtp = 0xC0;
           }
           else if ( (dram_rtp == 9) )
           {
               dram_wr_rtp = 0x20;
           }
           else if ( (dram_rtp == 10) )
           {
               dram_wr_rtp = 0xA0;
           }
           else if ( (dram_rtp == 12) )
           {
               dram_wr_rtp = 0x60;
           }
    	   rc_num = rc_num | address_16.insert((uint8_t) dram_wr_rtp, 9, 3);
	   break;
       case ATTR_EFF_DRAM_DLL_PPD:
           if (dll_precharge == ENUM_ATTR_EFF_DRAM_DLL_PPD_SLOWEXIT)
	   {
               dll_precharge = 0x00;
           }
           else if (dll_precharge == ENUM_ATTR_EFF_DRAM_DLL_PPD_FASTEXIT)
           {
               dll_precharge = 0xFF;
           }
	   FAPI_INF("ERROR: ATTR_EFF_DRAM_DLL_PPD is an unused MRS value!!! Skipping...");
	   break;
       case ATTR_EFF_DRAM_DLL_ENABLE:
           if (dll_enable == ENUM_ATTR_EFF_DRAM_DLL_ENABLE_DISABLE)
           {
               dll_enable = 0x00;
           }
           else if (dll_enable == ENUM_ATTR_EFF_DRAM_DLL_ENABLE_ENABLE)
           {
               dll_enable = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) dll_enable, 0, 1, 0);
	   break;
       case ATTR_VPD_DRAM_RON:
	   if (out_drv_imp_cntl == ENUM_ATTR_VPD_DRAM_RON_OHM34)
           {
               out_drv_imp_cntl = 0x00;
           }
    	   // Not currently supported
           else if (out_drv_imp_cntl == ENUM_ATTR_VPD_DRAM_RON_OHM48) //not supported
           {
               out_drv_imp_cntl = 0x80;
           }
           rc_num = rc_num | address_16.insert((uint8_t) out_drv_imp_cntl, 1, 2, 0);
	   break;
       case ATTR_VPD_DRAM_RTT_NOM:
	   if (dram_rtt_nom == ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE)
           {
               dram_rtt_nom = 0x00;
           }
           else if (dram_rtt_nom == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM240) //not supported
           {
               dram_rtt_nom = 0x20;
           }
           else if (dram_rtt_nom == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM48) //not supported
           {
               dram_rtt_nom = 0xA0;
           }
           else if (dram_rtt_nom == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40)
           {
               dram_rtt_nom = 0xC0;
           }
           else if (dram_rtt_nom == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM60)
           {
               dram_rtt_nom = 0x80;
           }
           else if (dram_rtt_nom == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM120)
           {
               dram_rtt_nom = 0x40;
           }
           else if (dram_rtt_nom == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM80) // not supported
           {
               dram_rtt_nom = 0x60;
           }
           else if (dram_rtt_nom == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM34) // not supported
           {
               dram_rtt_nom = 0xE0;
           }
	   
           rc_num = rc_num | address_16.insert((uint8_t) dram_rtt_nom, 8, 3, 0);
	   break;
       case ATTR_EFF_DRAM_AL:
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
           rc_num = rc_num | address_16.insert((uint8_t) dram_al, 3, 2, 0);
	   break;
       case ATTR_EFF_DRAM_WR_LVL_ENABLE:
	   if (wr_lvl == ENUM_ATTR_EFF_DRAM_WR_LVL_ENABLE_DISABLE)
           {
               wr_lvl = 0x00;
           }
           else if (wr_lvl == ENUM_ATTR_EFF_DRAM_WR_LVL_ENABLE_ENABLE)
           {
               wr_lvl = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) wr_lvl, 7, 1, 0);
	   break;
       case ATTR_EFF_DRAM_TDQS:
	   if (tdqs_enable == ENUM_ATTR_EFF_DRAM_TDQS_DISABLE)
           {
               tdqs_enable = 0x00;
           }
           else if (tdqs_enable == ENUM_ATTR_EFF_DRAM_TDQS_ENABLE)
           {
               tdqs_enable = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) tdqs_enable, 11, 1, 0);
	   break;
       case ATTR_EFF_DRAM_OUTPUT_BUFFER:
           if (q_off == ENUM_ATTR_EFF_DRAM_OUTPUT_BUFFER_DISABLE)
           {
               q_off = 0xFF;
           }
           else if (q_off == ENUM_ATTR_EFF_DRAM_OUTPUT_BUFFER_ENABLE)
           {
               q_off = 0x00;
           }
           rc_num = rc_num | address_16.insert((uint8_t) q_off, 12, 1, 0);
	   break;
       case ATTR_EFF_DRAM_LPASR:
           if (lpasr == ENUM_ATTR_EFF_DRAM_LPASR_MANUAL_NORMAL)
           {
               lpasr = 0x00;
           }
           else if (lpasr == ENUM_ATTR_EFF_DRAM_LPASR_MANUAL_REDUCED)
           {
               lpasr = 0x80;
           }
           else if (lpasr == ENUM_ATTR_EFF_DRAM_LPASR_MANUAL_EXTENDED)
           {
               lpasr = 0x40;
           }
           else if (lpasr == ENUM_ATTR_EFF_DRAM_LPASR_ASR)
           {
               lpasr = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) lpasr, 6, 2);
	   break;
       case ATTR_EFF_DRAM_CWL:
	   if ((cwl > 8)&&(cwl < 13))
           {
               cwl = cwl - 9; 
           }
           else if ((cwl > 13)&&(cwl < 19))
           {
               cwl = (cwl >> 1) - 3;   
           }
           else
           {
              //no correcct value for CWL was found
              FAPI_INF("ERROR: Improper CWL value found. Setting CWL to 9 and continuing...");
              cwl = 0;
           }
	   cwl = mss_reverse_8bits(cwl);
	   rc_num = rc_num | address_16.insert((uint8_t) cwl, 3, 3);
	   break;
       case ATTR_VPD_DRAM_RTT_WR:
	   if (dram_rtt_wr == ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE)
           {
               dram_rtt_wr = 0x00;
           }
           else if (dram_rtt_wr == ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120)
           {
               dram_rtt_wr = 0x80;
           }
           else if (dram_rtt_wr == 240)//ENUM_ATTR_EFF_DRAM_RTT_WR_OHM240)
           {
               dram_rtt_wr = 0x40;
           }
           else if (dram_rtt_wr == 0xFF)//ENUM_ATTR_EFF_DRAM_RTT_WR_HIGHZ)
           {
               dram_rtt_wr = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) dram_rtt_wr, 9, 2);
           break;
       case ATTR_EFF_WRITE_CRC:
	   if ( write_crc == ENUM_ATTR_EFF_WRITE_CRC_ENABLE)
           {
               write_crc = 0xFF;
           }
           else if (write_crc == ENUM_ATTR_EFF_WRITE_CRC_DISABLE)
           {
               write_crc = 0x00;
           }
           rc_num = rc_num | address_16.insert((uint8_t) write_crc, 12, 1);
	   break;
       case ATTR_EFF_MPR_MODE:
	   if (mpr_op == ENUM_ATTR_EFF_MPR_MODE_ENABLE)
           {
               mpr_op = 0xFF;
           }
           else if (mpr_op == ENUM_ATTR_EFF_MPR_MODE_DISABLE)
           {
               mpr_op = 0x00;
           }
           rc_num = rc_num | address_16.insert((uint8_t) mpr_op, 2, 1);
	   break;
       case ATTR_EFF_MPR_PAGE:
           mpr_page = mss_reverse_8bits(mpr_page);
    	   rc_num = rc_num | address_16.insert((uint8_t) mpr_page, 0, 2);
	   break;
       case ATTR_EFF_GEARDOWN_MODE:
	   if ( geardown_mode == ENUM_ATTR_EFF_GEARDOWN_MODE_HALF)
           {
        	geardown_mode = 0x00;
           }
           else if ( geardown_mode == ENUM_ATTR_EFF_GEARDOWN_MODE_QUARTER)
           {
        	geardown_mode = 0xFF;
           }
           
           if (temp_readout == ENUM_ATTR_EFF_TEMP_READOUT_ENABLE)
           {
               temp_readout = 0xFF;
           }
           else if (temp_readout == ENUM_ATTR_EFF_TEMP_READOUT_DISABLE)
           {
               temp_readout = 0x00;
           }
           rc_num = rc_num | address_16.insert((uint8_t) geardown_mode, 3, 1);
	   break;
       case ATTR_EFF_TEMP_READOUT:
	   if (temp_readout == ENUM_ATTR_EFF_TEMP_READOUT_ENABLE)
    	   {
    	       temp_readout = 0xFF;
    	   }
    	   else if (temp_readout == ENUM_ATTR_EFF_TEMP_READOUT_DISABLE)
    	   {
    	       temp_readout = 0x00;
    	   }
           rc_num = rc_num | address_16.insert((uint8_t) temp_readout, 5, 1);
	   break;
       case ATTR_EFF_FINE_REFRESH_MODE:
	   if (fine_refresh == ENUM_ATTR_EFF_FINE_REFRESH_MODE_NORMAL)
           {
               fine_refresh = 0x00;
           }
           else if (fine_refresh == ENUM_ATTR_EFF_FINE_REFRESH_MODE_FIXED_2X)
           {
               fine_refresh = 0x80;
           }
           else if (fine_refresh == ENUM_ATTR_EFF_FINE_REFRESH_MODE_FIXED_4X)
           {
               fine_refresh = 0x40;
           }
           else if (fine_refresh == ENUM_ATTR_EFF_FINE_REFRESH_MODE_FLY_2X)
           {
               fine_refresh = 0xA0;
           }
           else if (fine_refresh == ENUM_ATTR_EFF_FINE_REFRESH_MODE_FLY_4X)
           {
               fine_refresh = 0x60;
           }
           rc_num = rc_num | address_16.insert((uint8_t) fine_refresh, 6, 3);
	   break;
       case ATTR_EFF_CRC_WR_LATENCY:
           if (wr_latency == ENUM_ATTR_EFF_CRC_WR_LATENCY_4NCK)
           {
               wr_latency = 0x00;
           }
           else if (wr_latency == ENUM_ATTR_EFF_CRC_WR_LATENCY_5NCK)
           {
               wr_latency = 0x80;
           }
           else if (wr_latency == ENUM_ATTR_EFF_CRC_WR_LATENCY_6NCK)
           {
               wr_latency = 0xC0;
           }
           rc_num = rc_num | address_16.insert((uint8_t) wr_latency, 9, 2);
	   break;
       case ATTR_EFF_MPR_RD_FORMAT:
           if (read_format == ENUM_ATTR_EFF_MPR_RD_FORMAT_SERIAL)
           {
               read_format = 0x00;
           }
           else if (read_format == ENUM_ATTR_EFF_MPR_RD_FORMAT_PARALLEL)
           {
               read_format = 0x80;
           }
           else if (read_format == ENUM_ATTR_EFF_MPR_RD_FORMAT_STAGGERED)
           {
               read_format = 0x40;
           }
           else if (read_format == ENUM_ATTR_EFF_MPR_RD_FORMAT_RESERVED_TEMP)
           {
               read_format = 0xC0;
           }
           rc_num = rc_num | address_16.insert((uint8_t) read_format, 11, 2);
	   break;
       case ATTR_EFF_PER_DRAM_ACCESS:
           FAPI_INF("ERROR: ATTR_EFF_PER_DRAM_ACCESS selected.  Forcing PDA to be on for this function");
	   dram_access = 0xFF;
	   rc_num = rc_num | address_16.insert((uint8_t) dram_access, 4, 1);
	   break;
       case ATTR_EFF_MAX_POWERDOWN_MODE:
	   if ( max_pd_mode == ENUM_ATTR_EFF_MAX_POWERDOWN_MODE_ENABLE)
           {
               max_pd_mode = 0xF0;
           }
           else if ( max_pd_mode == ENUM_ATTR_EFF_MAX_POWERDOWN_MODE_DISABLE)
           {
               max_pd_mode = 0x00;
           }
           rc_num = rc_num | address_16.insert((uint8_t) max_pd_mode, 1, 1);
	   break;
       case ATTR_EFF_TEMP_REF_RANGE:
	   if (temp_ref_range == ENUM_ATTR_EFF_TEMP_REF_RANGE_NORMAL)
           {
               temp_ref_range = 0x00;
           }
           else if ( temp_ref_range== ENUM_ATTR_EFF_TEMP_REF_RANGE_EXTEND)
           {
               temp_ref_range = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) temp_ref_range, 2, 1);
	   break;
       case ATTR_EFF_TEMP_REF_MODE:
	   if (temp_ref_mode == ENUM_ATTR_EFF_TEMP_REF_MODE_ENABLE)
           {
               temp_ref_mode = 0x80;
           }
           else if (temp_ref_mode == ENUM_ATTR_EFF_TEMP_REF_MODE_DISABLE)
           {
               temp_ref_mode = 0x00;
           }
           rc_num = rc_num | address_16.insert((uint8_t) temp_ref_mode, 3, 1);
	   break;
       case ATTR_EFF_INT_VREF_MON:
	   if ( vref_mon == ENUM_ATTR_EFF_INT_VREF_MON_ENABLE)
           {
               vref_mon = 0xFF;
           }
           else if ( vref_mon == ENUM_ATTR_EFF_INT_VREF_MON_DISABLE)
           {
               vref_mon = 0x00;
           }
           rc_num = rc_num | address_16.insert((uint8_t) vref_mon, 4, 1);
	   break;
       case ATTR_EFF_CS_CMD_LATENCY:
	   if ( cs_cmd_latency == 3)
           {
               cs_cmd_latency = 0x80;
           }
           else if (cs_cmd_latency == 4)
           {
               cs_cmd_latency = 0x40;
           }
           else if (cs_cmd_latency == 5)
           {
               cs_cmd_latency = 0xC0;
           }
           else if (cs_cmd_latency == 6)
           {
               cs_cmd_latency = 0x20;
           }
           else if (cs_cmd_latency == 8)
           {
               cs_cmd_latency = 0xA0;
           }
           rc_num = rc_num | address_16.insert((uint8_t) cs_cmd_latency, 6, 3);
	   break;
       case ATTR_EFF_SELF_REF_ABORT:
	   if (ref_abort == ENUM_ATTR_EFF_SELF_REF_ABORT_ENABLE)
           {
               ref_abort = 0xFF;
           }
           else if (ref_abort == ENUM_ATTR_EFF_SELF_REF_ABORT_DISABLE)
           {
               ref_abort = 0x00;
           }
           rc_num = rc_num | address_16.insert((uint8_t) ref_abort, 9, 1);
	   break;
       case ATTR_EFF_RD_PREAMBLE_TRAIN:
	   if (rd_pre_train_mode == ENUM_ATTR_EFF_RD_PREAMBLE_TRAIN_ENABLE)
           {
               rd_pre_train_mode = 0xFF;
           }
           else if (rd_pre_train_mode == ENUM_ATTR_EFF_RD_PREAMBLE_TRAIN_DISABLE)
           {
               rd_pre_train_mode = 0x00;
           }
           rc_num = rc_num | address_16.insert((uint8_t) rd_pre_train_mode, 10, 1);
	   break;
       case ATTR_EFF_RD_PREAMBLE:
	   if (rd_preamble == ENUM_ATTR_EFF_RD_PREAMBLE_1NCLK)
           {
               rd_preamble = 0x00;
           }
           else if (rd_preamble == ENUM_ATTR_EFF_RD_PREAMBLE_2NCLK)
           {
               rd_preamble = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) rd_preamble, 11, 1);
	   break;
       case ATTR_EFF_WR_PREAMBLE:
           if (wr_preamble == ENUM_ATTR_EFF_WR_PREAMBLE_1NCLK)
           {
               wr_preamble = 0x00;
           }
           else if (wr_preamble == ENUM_ATTR_EFF_WR_PREAMBLE_2NCLK)
           {
               wr_preamble = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) wr_preamble, 12, 1);
	   break;
       case ATTR_EFF_CA_PARITY_LATENCY:
	   if (ca_parity_latency == 4)
           {
               ca_parity_latency = 0x80;
           }
           else if (ca_parity_latency == 5)
           {
               ca_parity_latency = 0x40;
           }
           else if (ca_parity_latency == 6)
           {
               ca_parity_latency = 0xC0;
           }
           else if (ca_parity_latency == 8)
           {
               ca_parity_latency = 0x20;
           }
           else if (ca_parity_latency == ENUM_ATTR_EFF_CA_PARITY_LATENCY_DISABLE)
           {
               ca_parity_latency = 0x00;
           }
           rc_num = rc_num | address_16.insert((uint8_t) ca_parity_latency, 0, 2);
	   break;
       case ATTR_EFF_CRC_ERROR_CLEAR:
	   if (crc_error_clear == ENUM_ATTR_EFF_CRC_ERROR_CLEAR_ERROR)
           {
               crc_error_clear = 0xFF;
           }
           else if (crc_error_clear == ENUM_ATTR_EFF_CRC_ERROR_CLEAR_CLEAR)
           {
               crc_error_clear = 0x00;
           }
           rc_num = rc_num | address_16.insert((uint8_t) crc_error_clear, 3, 1);
	   break;
       case ATTR_EFF_CA_PARITY_ERROR_STATUS:
	   if (ca_parity_error_status == ENUM_ATTR_EFF_CA_PARITY_ERROR_STATUS_ERROR)
           {
               ca_parity_error_status = 0xFF;
           }
           else if (ca_parity_error_status == ENUM_ATTR_EFF_CA_PARITY_ERROR_STATUS_CLEAR)
           {
               ca_parity_error_status = 0x00;
           }
           rc_num = rc_num | address_16.insert((uint8_t) ca_parity_error_status, 4, 1);
	   break;
       case ATTR_EFF_ODT_INPUT_BUFF:
	   if (odt_input_buffer == ENUM_ATTR_EFF_ODT_INPUT_BUFF_ACTIVATED)
           {
               odt_input_buffer = 0x00;
           }
           else if (odt_input_buffer == ENUM_ATTR_EFF_ODT_INPUT_BUFF_DEACTIVATED)
           {
               odt_input_buffer = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) odt_input_buffer, 5, 1);
	   break;
       case ATTR_VPD_DRAM_RTT_PARK:
	   if (rtt_park == ENUM_ATTR_VPD_DRAM_RTT_PARK_DISABLE)
           {
               rtt_park = 0x00;
           }
           else if (rtt_park == ENUM_ATTR_VPD_DRAM_RTT_PARK_60OHM)
           {
               rtt_park = 0x80;
           }
           else if (rtt_park == ENUM_ATTR_VPD_DRAM_RTT_PARK_40OHM)
           {
               rtt_park = 0xC0;
           }
           else if (rtt_park == ENUM_ATTR_VPD_DRAM_RTT_PARK_120OHM)
           {
               rtt_park = 0x40;
           }
           else if (rtt_park == ENUM_ATTR_VPD_DRAM_RTT_PARK_240OHM)
           {
               rtt_park = 0x20;
           }
           else if (rtt_park == ENUM_ATTR_VPD_DRAM_RTT_PARK_48OHM)
           {
               rtt_park = 0xA0;
           }
           else if (rtt_park == ENUM_ATTR_VPD_DRAM_RTT_PARK_80OHM)
           {
               rtt_park = 0x60;
           }
           else if (rtt_park == ENUM_ATTR_VPD_DRAM_RTT_PARK_34OHM)
           {
               rtt_park = 0xE0;
           }
           rc_num = rc_num | address_16.insert((uint8_t) rtt_park, 6, 3);
	   break;
       case ATTR_EFF_CA_PARITY:
	   if (ca_parity == ENUM_ATTR_EFF_CA_PARITY_ENABLE)
           {
               ca_parity = 0xFF;
           }
           else if (ca_parity == ENUM_ATTR_EFF_CA_PARITY_DISABLE)
           {
               ca_parity = 0x00;
           }
           rc_num = rc_num | address_16.insert((uint8_t) ca_parity, 9, 1);
	   break;
       case ATTR_EFF_DATA_MASK:
	   if (data_mask == ENUM_ATTR_EFF_DATA_MASK_DISABLE)
           {
               data_mask = 0x00;
           }
           else if (data_mask == ENUM_ATTR_EFF_DATA_MASK_ENABLE)
           {
               data_mask = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) data_mask, 10, 1);
	   break;
       case ATTR_EFF_WRITE_DBI:
	   if (write_dbi == ENUM_ATTR_EFF_WRITE_DBI_DISABLE)
           {
               write_dbi = 0x00;
           }
           else if (write_dbi == ENUM_ATTR_EFF_WRITE_DBI_ENABLE)
           {
               write_dbi = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) write_dbi, 11, 1);
	   break;
       case ATTR_EFF_READ_DBI:
           if (read_dbi == ENUM_ATTR_EFF_READ_DBI_DISABLE)
           {
               read_dbi = 0x00;
           }
           else if (read_dbi == ENUM_ATTR_EFF_READ_DBI_ENABLE)
           {
               read_dbi = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) read_dbi, 12, 1);
	   break;
       case ATTR_EFF_VREF_DQ_TRAIN_VALUE:
	   vrefdq_train_value = mss_reverse_8bits(vrefdq_train_value);
           rc_num = rc_num | address_16.insert((uint8_t) vrefdq_train_value, 0, 6);
	   break;
       case ATTR_EFF_VREF_DQ_TRAIN_RANGE:
	   if (vrefdq_train_range == ENUM_ATTR_EFF_VREF_DQ_TRAIN_RANGE_RANGE1)
           {
               vrefdq_train_range = 0x00;
           }
           else if (vrefdq_train_range == ENUM_ATTR_EFF_VREF_DQ_TRAIN_RANGE_RANGE2)
           {
               vrefdq_train_range = 0xFF;
           } 
           rc_num = rc_num | address_16.insert((uint8_t) vrefdq_train_range, 6, 1);
	   break;
       case ATTR_EFF_VREF_DQ_TRAIN_ENABLE:
	   if (vrefdq_train_enable == ENUM_ATTR_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE)
           {
               vrefdq_train_enable = 0xFF;
           }
           else if (vrefdq_train_enable == ENUM_ATTR_EFF_VREF_DQ_TRAIN_ENABLE_DISABLE)
           {
               vrefdq_train_enable = 0x00;
           }   
           rc_num = rc_num | address_16.insert((uint8_t) vrefdq_train_enable, 7, 1);
	   break;
       case ATTR_TCCD_L:
           if (tccd_l == 4)
           {
               tccd_l = 0x00;
           }
           else if (tccd_l == 5)
           {
               tccd_l = 0x80;
           }
           else if (tccd_l == 6)
           {
               tccd_l = 0x40;
           }	
           else if (tccd_l == 7)
           {
               tccd_l = 0xC0;
           }
           else if (tccd_l == 8)
           {
               tccd_l = 0x20;
           }
           rc_num = rc_num | address_16.insert((uint8_t) tccd_l, 10, 3);
	   break;
	//MRS attribute not found, error out
      default: 
         const uint32_t NONMRS_ATTR_NAME = attribute_name;
	 const fapi::Target & MBA_TARGET = i_target; 
	 FAPI_SET_HWP_ERROR(rc, RC_MSS_PDA_NONMRS_ATTR_NAME);
	 FAPI_ERR("ERROR!! Found attribute name not associated with an MRS! Exiting...");
   }
   if (rc_num)
   {
       FAPI_ERR( "mss_ddr4_modify_mrs_pda: Error setting up buffers");
       rc.setEcmdError(rc_num);
       return rc;
   }
   return rc;
}

//////////////////////////////////////////////////////////////////////////////////
/// mss_ddr4_load_nominal_mrs_pda
/// disables per-DRAM addressability funcitonality on both ports on the passed MBA
//////////////////////////////////////////////////////////////////////////////////
ReturnCode mss_ddr4_load_nominal_mrs_pda(Target& i_target,ecmdDataBufferBase& bank_3,ecmdDataBufferBase& address_16,uint8_t MRS,uint8_t i_port_number, uint8_t dimm_number, uint8_t rank_number) {
    ReturnCode rc;  
    ReturnCode rc_buff;
    uint32_t rc_num = 0;
    
    rc_num = rc_num | address_16.clearBit(0,16);
    rc_num = rc_num | bank_3.clearBit(0,3);
    if (rc_num)
    {
    	FAPI_ERR( "mss_mrs_load: Error setting up buffers");
    	rc_buff.setEcmdError(rc_num);
    	return rc_buff;
    }

    //Lines commented out in the following section are waiting for xml attribute adds
    //MRS0
    if(MRS == MRS0_BA) {
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
    	uint8_t dram_wr; //DRAM write recovery
    	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WR, &i_target, dram_wr);
    	if(rc) return rc;
    	uint8_t dram_rtp; //DRAM RTP - read to precharge
    	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_TRTP, &i_target, dram_rtp);
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

    	uint8_t dram_wr_rtp = 0x00;
    	if ( (dram_wr == 10) )//&& (dram_rtp == 5) )
    	{
    	    dram_wr_rtp = 0x00;
    	}
    	else if ( (dram_wr == 12) )//&& (dram_rtp == 6) )
    	{
    	    dram_wr_rtp = 0x80;
    	}
    	else if ( (dram_wr == 13) )//&& (dram_rtp == 7) )
    	{
    	    dram_wr_rtp = 0x40;
    	}
    	else if ( (dram_wr == 14) )//&& (dram_rtp == 8) )
    	{
    	    dram_wr_rtp = 0xC0;
    	}
    	else if ( (dram_wr == 18) )//&& (dram_rtp == 9) )
    	{
    	    dram_wr_rtp = 0x20;
    	}
    	else if ( (dram_wr == 20) )//&& (dram_rtp == 10) )
    	{
    	    dram_wr_rtp = 0xA0;
    	}
    	else if ( (dram_wr == 24) )//&& (dram_rtp == 12) )
    	{
    	    dram_wr_rtp = 0x60;
    	}

    	if (read_bt == ENUM_ATTR_EFF_DRAM_RBT_SEQUENTIAL)
    	{
    	    read_bt = 0x00;
    	}
    	else if (read_bt == ENUM_ATTR_EFF_DRAM_RBT_INTERLEAVE)
    	{
    	    read_bt = 0xFF;
    	}

    	if ((dram_cl > 8)&&(dram_cl < 17))
    	{
    	    dram_cl = dram_cl - 9; 
    	}
    	else if ((dram_cl > 17)&&(dram_cl < 25))
    	{
    	    dram_cl = (dram_cl >> 1) - 1;   
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
	
	FAPI_INF("Overwriting DLL reset with values to not reset the DRAM.");
    	dll_reset = 0x00;

    	if (dll_precharge == ENUM_ATTR_EFF_DRAM_DLL_PPD_SLOWEXIT)
    	{
    	    dll_precharge = 0x00;
    	}
    	else if (dll_precharge == ENUM_ATTR_EFF_DRAM_DLL_PPD_FASTEXIT)
    	{
    	    dll_precharge = 0xFF;
    	}
	//For DDR4:
	//Address 14 = Address 17, Address 15 = BG1
        rc_num = rc_num | address_16.insert((uint8_t) dram_bl, 0, 2, 0);
        rc_num = rc_num | address_16.insert((uint8_t) dram_cl, 2, 1, 0);
        rc_num = rc_num | address_16.insert((uint8_t) read_bt, 3, 1, 0);
        rc_num = rc_num | address_16.insert((uint8_t) dram_cl, 4, 3, 1);
        rc_num = rc_num | address_16.insert((uint8_t) test_mode, 7, 1);
        rc_num = rc_num | address_16.insert((uint8_t) dll_reset, 8, 1);
	rc_num = rc_num | address_16.insert((uint8_t) dram_wr_rtp, 9, 3);
	rc_num = rc_num | address_16.insert((uint8_t) 0x00, 12, 4);
	
	rc_num = rc_num | bank_3.insert((uint8_t) MRS0_BA, 0, 1, 7);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS0_BA, 1, 1, 6);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS0_BA, 2, 1, 5);
	if (rc_num)
        {
            FAPI_ERR( "mss_mrs_load: Error setting up buffers");
            rc_buff.setEcmdError(rc_num);
            return rc_buff;
        }
    }
    
    //MRS1
    else if(MRS == MRS1_BA) {
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

    	if (dll_enable == ENUM_ATTR_EFF_DRAM_DLL_ENABLE_DISABLE)
    	{
    	    dll_enable = 0x00;
    	}
    	else if (dll_enable == ENUM_ATTR_EFF_DRAM_DLL_ENABLE_ENABLE)
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
        if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE)
        {
            dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0x00;
        }
        else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM240) //not supported
        {
            dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0x20;
        }
        else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM48) //not supported
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
        else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM80) // not supported
        {
            dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0x60;
        }
        else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM34) // not supported
        {
            dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0xE0;
        }

        if (out_drv_imp_cntl[i_port_number][dimm_number] == ENUM_ATTR_VPD_DRAM_RON_OHM34)
        {
            out_drv_imp_cntl[i_port_number][dimm_number] = 0x00;
        }
	// Not currently supported
        else if (out_drv_imp_cntl[i_port_number][dimm_number] == ENUM_ATTR_VPD_DRAM_RON_OHM48) //not supported
        {
            out_drv_imp_cntl[i_port_number][dimm_number] = 0x80;
        }

	//For DDR4:
	//Address 14 = Address 17, Address 15 = BG1
        rc_num = rc_num | address_16.insert((uint8_t) dll_enable, 0, 1, 0);
        rc_num = rc_num | address_16.insert((uint8_t) out_drv_imp_cntl[i_port_number][dimm_number], 1, 2, 0);
        rc_num = rc_num | address_16.insert((uint8_t) dram_al, 3, 2, 0);
        rc_num = rc_num | address_16.insert((uint8_t) 0x00, 5, 2);
        rc_num = rc_num | address_16.insert((uint8_t) wr_lvl, 7, 1, 0);
        rc_num = rc_num | address_16.insert((uint8_t) dram_rtt_nom[i_port_number][dimm_number][rank_number], 8, 3, 0);
        rc_num = rc_num | address_16.insert((uint8_t) tdqs_enable, 11, 1, 0);
        rc_num = rc_num | address_16.insert((uint8_t) q_off, 12, 1, 0);
        rc_num = rc_num | address_16.insert((uint8_t) 0x00, 13, 3);
	
	rc_num = rc_num | bank_3.insert((uint8_t) MRS1_BA, 0, 1, 7);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS1_BA, 1, 1, 6);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS1_BA, 2, 1, 5);
	if (rc_num)
        {
            FAPI_ERR( "mss_mrs_load: Error setting up buffers");
            rc_buff.setEcmdError(rc_num);
            return rc_buff;
        }
    }
    //MRS2
    else if(MRS == MRS2_BA) {
    	uint8_t lpasr; // Low Power Auto Self-Refresh -- new not yet supported
    	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_LPASR, &i_target, lpasr);
    	if(rc) return rc;
    	uint8_t cwl; // CAS Write Latency 
    	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_CWL, &i_target, cwl);
    	if(rc) return rc;
    	uint8_t dram_rtt_wr[2][2][4];
    	rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_RTT_WR, &i_target, dram_rtt_wr);
    	if(rc) return rc;
    	uint8_t write_crc; // CAS Write Latency 
    	rc = FAPI_ATTR_GET(ATTR_EFF_WRITE_CRC, &i_target, write_crc);
    	if(rc) return rc;

    	if (lpasr == ENUM_ATTR_EFF_DRAM_LPASR_MANUAL_NORMAL)
    	{
    	    lpasr = 0x00;
    	}
    	else if (lpasr == ENUM_ATTR_EFF_DRAM_LPASR_MANUAL_REDUCED)
    	{
    	    lpasr = 0x80;
    	}
    	else if (lpasr == ENUM_ATTR_EFF_DRAM_LPASR_MANUAL_EXTENDED)
    	{
    	    lpasr = 0x40;
    	}
    	else if (lpasr == ENUM_ATTR_EFF_DRAM_LPASR_ASR)
    	{
    	    lpasr = 0xFF;
    	}

    	if ((cwl > 8)&&(cwl < 13))
    	{
    	    cwl = cwl - 9; 
    	}
    	else if ((cwl > 13)&&(cwl < 19))
    	{
    	    cwl = (cwl >> 1) - 3;   
    	}
    	else
    	{
    	   //no correcct value for CWL was found
    	   FAPI_INF("ERROR: Improper CWL value found. Setting CWL to 9 and continuing...");
    	   cwl = 0;
    	}
    	cwl = mss_reverse_8bits(cwl);

    	if ( write_crc == ENUM_ATTR_EFF_WRITE_CRC_ENABLE)
    	{
    	    write_crc = 0xFF;
    	}
    	else if (write_crc == ENUM_ATTR_EFF_WRITE_CRC_DISABLE)
    	{
    	    write_crc = 0x00;
    	}
	if (dram_rtt_wr[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE)
        {
            dram_rtt_wr[i_port_number][dimm_number][rank_number] = 0x00;
        }
        else if (dram_rtt_wr[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120)
        {
            dram_rtt_wr[i_port_number][dimm_number][rank_number] = 0x80;
        }
        else if (dram_rtt_wr[i_port_number][dimm_number][rank_number] == 240)//ENUM_ATTR_EFF_DRAM_RTT_WR_OHM240)
        {
            dram_rtt_wr[i_port_number][dimm_number][rank_number] = 0x40;
        }
        else if (dram_rtt_wr[i_port_number][dimm_number][rank_number] == 0xFF)//ENUM_ATTR_EFF_DRAM_RTT_WR_HIGHZ)
        {
            dram_rtt_wr[i_port_number][dimm_number][rank_number] = 0xFF;
        }

        rc_num = rc_num | address_16.insert((uint8_t) 0x00, 0, 3);
        rc_num = rc_num | address_16.insert((uint8_t) cwl, 3, 3);
        rc_num = rc_num | address_16.insert((uint8_t) lpasr, 6, 2);
        rc_num = rc_num | address_16.insert((uint8_t) 0x00, 8, 1);
        rc_num = rc_num | address_16.insert((uint8_t) dram_rtt_wr[i_port_number][dimm_number][rank_number], 9, 2);
        rc_num = rc_num | address_16.insert((uint8_t) 0x00, 11, 1);
        rc_num = rc_num | address_16.insert((uint8_t) write_crc, 12, 1);
        rc_num = rc_num | address_16.insert((uint8_t) 0x00, 13, 2);
	
	rc_num = rc_num | bank_3.insert((uint8_t) MRS2_BA, 0, 1, 7);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS2_BA, 1, 1, 6);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS2_BA, 2, 1, 5);
	if (rc_num)
        {
            FAPI_ERR( "mss_mrs_load: Error setting up buffers");
            rc_buff.setEcmdError(rc_num);
            return rc_buff;
        }
    }
    //MRS3
    else if(MRS == MRS3_BA) {
    	uint8_t mpr_op; // MPR Op
    	rc = FAPI_ATTR_GET(ATTR_EFF_MPR_MODE, &i_target, mpr_op);
    	if(rc) return rc;
    	uint8_t mpr_page; // MPR Page Selection  - NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_MPR_PAGE, &i_target, mpr_page);
    	if(rc) return rc;
    	uint8_t geardown_mode; // Gear Down Mode  - NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_GEARDOWN_MODE, &i_target, geardown_mode);
    	if(rc) return rc;
    	uint8_t temp_readout; // Temperature sensor readout  - NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_TEMP_READOUT, &i_target, temp_readout);
    	if(rc) return rc;
    	uint8_t fine_refresh; // fine refresh mode  - NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_FINE_REFRESH_MODE, &i_target, fine_refresh);
    	if(rc) return rc;
    	uint8_t wr_latency; // write latency for CRC and DM  - NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_CRC_WR_LATENCY, &i_target, wr_latency);
    	if(rc) return rc;
    	uint8_t read_format; // MPR READ FORMAT  - NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_MPR_RD_FORMAT, &i_target, read_format);
    	if(rc) return rc;

    	if (mpr_op == ENUM_ATTR_EFF_MPR_MODE_ENABLE)
    	{
    	    mpr_op = 0xFF;
    	}
    	else if (mpr_op == ENUM_ATTR_EFF_MPR_MODE_DISABLE)
    	{
    	    mpr_op = 0x00;
    	}

    	mpr_page = mss_reverse_8bits(mpr_page);

    	if ( geardown_mode == ENUM_ATTR_EFF_GEARDOWN_MODE_HALF)
    	{
    	     geardown_mode = 0x00;
    	}
    	else if ( geardown_mode == ENUM_ATTR_EFF_GEARDOWN_MODE_QUARTER)
    	{
    	     geardown_mode = 0xFF;
    	}
    	
    	if (temp_readout == ENUM_ATTR_EFF_TEMP_READOUT_ENABLE)
    	{
    	    temp_readout = 0xFF;
    	}
    	else if (temp_readout == ENUM_ATTR_EFF_TEMP_READOUT_DISABLE)
    	{
    	    temp_readout = 0x00;
    	}

    	if (fine_refresh == ENUM_ATTR_EFF_FINE_REFRESH_MODE_NORMAL)
    	{
    	    fine_refresh = 0x00;
    	}
    	else if (fine_refresh == ENUM_ATTR_EFF_FINE_REFRESH_MODE_FIXED_2X)
    	{
    	    fine_refresh = 0x80;
    	}
    	else if (fine_refresh == ENUM_ATTR_EFF_FINE_REFRESH_MODE_FIXED_4X)
    	{
    	    fine_refresh = 0x40;
    	}
    	else if (fine_refresh == ENUM_ATTR_EFF_FINE_REFRESH_MODE_FLY_2X)
    	{
    	    fine_refresh = 0xA0;
    	}
    	else if (fine_refresh == ENUM_ATTR_EFF_FINE_REFRESH_MODE_FLY_4X)
    	{
    	    fine_refresh = 0x60;
    	}

    	if (wr_latency == ENUM_ATTR_EFF_CRC_WR_LATENCY_4NCK)
    	{
    	    wr_latency = 0x00;
    	}
    	else if (wr_latency == ENUM_ATTR_EFF_CRC_WR_LATENCY_5NCK)
    	{
    	    wr_latency = 0x80;
    	}
    	else if (wr_latency == ENUM_ATTR_EFF_CRC_WR_LATENCY_6NCK)
    	{
    	    wr_latency = 0xC0;
    	}

    	if (read_format == ENUM_ATTR_EFF_MPR_RD_FORMAT_SERIAL)
    	{
    	    read_format = 0x00;
    	}
    	else if (read_format == ENUM_ATTR_EFF_MPR_RD_FORMAT_PARALLEL)
    	{
    	    read_format = 0x80;
    	}
    	else if (read_format == ENUM_ATTR_EFF_MPR_RD_FORMAT_STAGGERED)
    	{
    	    read_format = 0x40;
    	}
    	else if (read_format == ENUM_ATTR_EFF_MPR_RD_FORMAT_RESERVED_TEMP)
    	{
    	    read_format = 0xC0;
    	}
	
	rc_num = rc_num | address_16.insert((uint8_t) mpr_page, 0, 2);
        rc_num = rc_num | address_16.insert((uint8_t) mpr_op, 2, 1);
        rc_num = rc_num | address_16.insert((uint8_t) geardown_mode, 3, 1);
        rc_num = rc_num | address_16.insert((uint8_t) 0xFF, 4, 1); //has PDA mode enabled!!!! just for this code!
        rc_num = rc_num | address_16.insert((uint8_t) temp_readout, 5, 1);
        rc_num = rc_num | address_16.insert((uint8_t) fine_refresh, 6, 3);
        rc_num = rc_num | address_16.insert((uint8_t) wr_latency, 9, 2);
        rc_num = rc_num | address_16.insert((uint8_t) read_format, 11, 2);
        rc_num = rc_num | address_16.insert((uint8_t) 0x00, 13, 2);
	
	rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 0, 1, 7);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 1, 1, 6);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 2, 1, 5);
	if (rc_num)
        {
            FAPI_ERR( "mss_mrs_load: Error setting up buffers");
            rc_buff.setEcmdError(rc_num);
            return rc_buff;
        }
    }
    //MRS4
    else if(MRS == MRS4_BA) {
    	uint8_t max_pd_mode; // Max Power down mode -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_MAX_POWERDOWN_MODE, &i_target, max_pd_mode);
    	if(rc) return rc;
    	uint8_t temp_ref_range; // Temp ref range -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_TEMP_REF_RANGE, &i_target, temp_ref_range);
    	if(rc) return rc;
    	uint8_t temp_ref_mode; // Temp controlled ref mode -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_TEMP_REF_MODE, &i_target, temp_ref_mode);
    	if(rc) return rc;
    	uint8_t vref_mon; // Internal Vref Monitor -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_INT_VREF_MON, &i_target, vref_mon);
    	if(rc) return rc;
    	uint8_t cs_cmd_latency; // CS to CMD/ADDR Latency -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_CS_CMD_LATENCY, &i_target, cs_cmd_latency);
    	if(rc) return rc;
    	uint8_t ref_abort; // Self Refresh Abort -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_SELF_REF_ABORT, &i_target, ref_abort);
    	if(rc) return rc;
    	uint8_t rd_pre_train_mode; // Read Pre amble Training Mode -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_RD_PREAMBLE_TRAIN, &i_target, rd_pre_train_mode);
    	if(rc) return rc;
    	uint8_t rd_preamble; // Read Pre amble -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_RD_PREAMBLE, &i_target, rd_preamble);
    	if(rc) return rc;
    	uint8_t wr_preamble; // Write Pre amble -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_WR_PREAMBLE, &i_target, wr_preamble);
    	if(rc) return rc;

    	if ( max_pd_mode == ENUM_ATTR_EFF_MAX_POWERDOWN_MODE_ENABLE)
    	{
    	    max_pd_mode = 0xF0;
    	}
    	else if ( max_pd_mode == ENUM_ATTR_EFF_MAX_POWERDOWN_MODE_DISABLE)
    	{
    	    max_pd_mode = 0x00;
    	}

    	if (temp_ref_range == ENUM_ATTR_EFF_TEMP_REF_RANGE_NORMAL)
    	{
    	    temp_ref_range = 0x00;
    	}
    	else if ( temp_ref_range== ENUM_ATTR_EFF_TEMP_REF_RANGE_EXTEND)
    	{
    	    temp_ref_range = 0xFF;
    	}

    	if (temp_ref_mode == ENUM_ATTR_EFF_TEMP_REF_MODE_ENABLE)
    	{
    	    temp_ref_mode = 0x80;
    	}
    	else if (temp_ref_mode == ENUM_ATTR_EFF_TEMP_REF_MODE_DISABLE)
    	{
    	    temp_ref_mode = 0x00;
    	}

    	if ( vref_mon == ENUM_ATTR_EFF_INT_VREF_MON_ENABLE)
    	{
    	    vref_mon = 0xFF;
    	}
    	else if ( vref_mon == ENUM_ATTR_EFF_INT_VREF_MON_DISABLE)
    	{
    	    vref_mon = 0x00;
    	}


    	if ( cs_cmd_latency == 3)
    	{
    	    cs_cmd_latency = 0x80;
    	}
    	else if (cs_cmd_latency == 4)
    	{
    	    cs_cmd_latency = 0x40;
    	}
    	else if (cs_cmd_latency == 5)
    	{
    	    cs_cmd_latency = 0xC0;
    	}
    	else if (cs_cmd_latency == 6)
    	{
    	    cs_cmd_latency = 0x20;
    	}
    	else if (cs_cmd_latency == 8)
    	{
    	    cs_cmd_latency = 0xA0;
    	}

    	if (ref_abort == ENUM_ATTR_EFF_SELF_REF_ABORT_ENABLE)
    	{
    	    ref_abort = 0xFF;
    	}
    	else if (ref_abort == ENUM_ATTR_EFF_SELF_REF_ABORT_DISABLE)
    	{
    	    ref_abort = 0x00;
    	}

    	if (rd_pre_train_mode == ENUM_ATTR_EFF_RD_PREAMBLE_TRAIN_ENABLE)
    	{
    	    rd_pre_train_mode = 0xFF;
    	}
    	else if (rd_pre_train_mode == ENUM_ATTR_EFF_RD_PREAMBLE_TRAIN_DISABLE)
    	{
    	    rd_pre_train_mode = 0x00;
    	}

    	if (rd_preamble == ENUM_ATTR_EFF_RD_PREAMBLE_1NCLK)
    	{
    	    rd_preamble = 0x00;
    	}
    	else if (rd_preamble == ENUM_ATTR_EFF_RD_PREAMBLE_2NCLK)
    	{
    	    rd_preamble = 0xFF;
    	}

    	if (wr_preamble == ENUM_ATTR_EFF_WR_PREAMBLE_1NCLK)
    	{
    	    wr_preamble = 0x00;
    	}
    	else if (wr_preamble == ENUM_ATTR_EFF_WR_PREAMBLE_2NCLK)
    	{
    	    wr_preamble = 0xFF;
    	}
    	rc_num = rc_num | address_16.insert((uint8_t) 0x00, 0, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) max_pd_mode, 1, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) temp_ref_range, 2, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) temp_ref_mode, 3, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) vref_mon, 4, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) 0x00, 5, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) cs_cmd_latency, 6, 3);
    	rc_num = rc_num | address_16.insert((uint8_t) ref_abort, 9, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) rd_pre_train_mode, 10, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) rd_preamble, 11, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) wr_preamble, 12, 1);
	
	rc_num = rc_num | bank_3.insert((uint8_t) MRS4_BA, 0, 1, 7);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS4_BA, 1, 1, 6);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS4_BA, 2, 1, 5);
	if (rc_num)
        {
            FAPI_ERR( "mss_mrs_load: Error setting up buffers");
            rc_buff.setEcmdError(rc_num);
            return rc_buff;
        }
    }
    //MRS5
    else if(MRS == MRS5_BA) {
    	uint8_t ca_parity_latency; //C/A Parity Latency Mode  -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_CA_PARITY_LATENCY , &i_target, ca_parity_latency);
    	if(rc) return rc;
    	uint8_t crc_error_clear; //CRC Error Clear  -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_CRC_ERROR_CLEAR , &i_target, crc_error_clear);
    	if(rc) return rc;
    	uint8_t ca_parity_error_status; //C/A Parity Error Status  -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_CA_PARITY_ERROR_STATUS , &i_target, ca_parity_error_status);
    	if(rc) return rc;
    	uint8_t odt_input_buffer; //ODT Input Buffer during power down  -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_ODT_INPUT_BUFF , &i_target, odt_input_buffer);
    	if(rc) return rc;
    	uint8_t rtt_park[2][2][4]; //RTT_Park value  -  NEW
    	rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_RTT_PARK , &i_target, rtt_park);
    	if(rc) return rc;
    	uint8_t ca_parity; //CA Parity Persistance Error  -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_CA_PARITY , &i_target, ca_parity);
    	if(rc) return rc;
    	uint8_t data_mask; //Data Mask  -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_DATA_MASK , &i_target, data_mask);
    	if(rc) return rc;
    	uint8_t write_dbi; //Write DBI  -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_WRITE_DBI , &i_target, write_dbi);
    	if(rc) return rc;
    	uint8_t read_dbi; //Read DBI  -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_READ_DBI , &i_target, read_dbi);
    	if(rc) return rc;


    	if (ca_parity_latency == 4)
    	{
    	    ca_parity_latency = 0x80;
    	}
    	else if (ca_parity_latency == 5)
    	{
    	    ca_parity_latency = 0x40;
    	}
    	else if (ca_parity_latency == 6)
    	{
    	    ca_parity_latency = 0xC0;
    	}
    	else if (ca_parity_latency == 8)
    	{
    	    ca_parity_latency = 0x20;
    	}
    	else if (ca_parity_latency == ENUM_ATTR_EFF_CA_PARITY_LATENCY_DISABLE)
    	{
    	    ca_parity_latency = 0x00;
    	}

    	if (crc_error_clear == ENUM_ATTR_EFF_CRC_ERROR_CLEAR_ERROR)
    	{
    	    crc_error_clear = 0xFF;
    	}
    	else if (crc_error_clear == ENUM_ATTR_EFF_CRC_ERROR_CLEAR_CLEAR)
    	{
    	    crc_error_clear = 0x00;
    	}

    	if (ca_parity_error_status == ENUM_ATTR_EFF_CA_PARITY_ERROR_STATUS_ERROR)
    	{
    	    ca_parity_error_status = 0xFF;
    	}
    	else if (ca_parity_error_status == ENUM_ATTR_EFF_CA_PARITY_ERROR_STATUS_CLEAR)
    	{
    	    ca_parity_error_status = 0x00;
    	}

    	if (odt_input_buffer == ENUM_ATTR_EFF_ODT_INPUT_BUFF_ACTIVATED)
    	{
    	    odt_input_buffer = 0x00;
    	}
    	else if (odt_input_buffer == ENUM_ATTR_EFF_ODT_INPUT_BUFF_DEACTIVATED)
    	{
    	    odt_input_buffer = 0xFF;
    	}


    	if (ca_parity == ENUM_ATTR_EFF_CA_PARITY_ENABLE)
    	{
    	    ca_parity = 0xFF;
    	}
    	else if (ca_parity == ENUM_ATTR_EFF_CA_PARITY_DISABLE)
    	{
    	    ca_parity = 0x00;
    	}

    	if (data_mask == ENUM_ATTR_EFF_DATA_MASK_DISABLE)
    	{
    	    data_mask = 0x00;
    	}
    	else if (data_mask == ENUM_ATTR_EFF_DATA_MASK_ENABLE)
    	{
    	    data_mask = 0xFF;
    	}

    	if (write_dbi == ENUM_ATTR_EFF_WRITE_DBI_DISABLE)
    	{
    	    write_dbi = 0x00;
    	}
    	else if (write_dbi == ENUM_ATTR_EFF_WRITE_DBI_ENABLE)
    	{
    	    write_dbi = 0xFF;
    	}

    	if (read_dbi == ENUM_ATTR_EFF_READ_DBI_DISABLE)
    	{
    	    read_dbi = 0x00;
    	}
    	else if (read_dbi == ENUM_ATTR_EFF_READ_DBI_ENABLE)
    	{
    	    read_dbi = 0xFF;
    	}
    	if (rtt_park[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_PARK_DISABLE)
    	{
    	    rtt_park[i_port_number][dimm_number][rank_number] = 0x00;
    	}
    	else if (rtt_park[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_PARK_60OHM)
    	{
    	    rtt_park[i_port_number][dimm_number][rank_number] = 0x80;
    	}
    	else if (rtt_park[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_PARK_40OHM)
    	{
    	    rtt_park[i_port_number][dimm_number][rank_number] = 0xC0;
    	}
    	else if (rtt_park[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_PARK_120OHM)
    	{
    	    rtt_park[i_port_number][dimm_number][rank_number] = 0x40;
    	}
    	else if (rtt_park[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_PARK_240OHM)
    	{
    	    rtt_park[i_port_number][dimm_number][rank_number] = 0x20;
    	}
    	else if (rtt_park[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_PARK_48OHM)
    	{
    	    rtt_park[i_port_number][dimm_number][rank_number] = 0xA0;
    	}
    	else if (rtt_park[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_PARK_80OHM)
    	{
    	    rtt_park[i_port_number][dimm_number][rank_number] = 0x60;
    	}
    	else if (rtt_park[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_PARK_34OHM)
    	{
    	    rtt_park[i_port_number][dimm_number][rank_number] = 0xE0;
    	}

    	rc_num = rc_num | address_16.insert((uint8_t) ca_parity_latency, 0, 2);
    	rc_num = rc_num | address_16.insert((uint8_t) crc_error_clear, 3, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) ca_parity_error_status, 4, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) odt_input_buffer, 5, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) rtt_park[i_port_number][dimm_number][rank_number], 6, 3);
    	rc_num = rc_num | address_16.insert((uint8_t) ca_parity, 9, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) data_mask, 10, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) write_dbi, 11, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) read_dbi, 12, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) 0x00, 13, 2);
	
	rc_num = rc_num | bank_3.insert((uint8_t) MRS5_BA, 0, 1, 7);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS5_BA, 1, 1, 6);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS5_BA, 2, 1, 5);
	if (rc_num)
        {
            FAPI_ERR( "mss_mrs_load: Error setting up buffers");
            rc_buff.setEcmdError(rc_num);
            return rc_buff;
        }
    }
    //MRS6
    else if(MRS == MRS6_BA) {
    	uint8_t vrefdq_train_value[2][2][4]; //vrefdq_train value   -  NEW
    	rc = FAPI_ATTR_GET( ATTR_EFF_VREF_DQ_TRAIN_VALUE, &i_target, vrefdq_train_value);
    	if(rc) return rc;
    	uint8_t vrefdq_train_range[2][2][4]; //vrefdq_train range   -  NEW
    	rc = FAPI_ATTR_GET( ATTR_EFF_VREF_DQ_TRAIN_RANGE, &i_target, vrefdq_train_range);
    	if(rc) return rc;
    	uint8_t vrefdq_train_enable[2][2][4]; //vrefdq_train enable  -  NEW
    	rc = FAPI_ATTR_GET( ATTR_EFF_VREF_DQ_TRAIN_ENABLE, &i_target, vrefdq_train_enable);
    	if(rc) return rc;
    	uint8_t tccd_l; //tccd_l  -  NEW
    	rc = FAPI_ATTR_GET( ATTR_TCCD_L, &i_target, tccd_l);
    	if(rc) return rc;
    	if (tccd_l == 4)
    	{
    	    tccd_l = 0x00;
    	}
    	else if (tccd_l == 5)
    	{
    	    tccd_l = 0x80;
    	}
    	else if (tccd_l == 6)
    	{
    	    tccd_l = 0x40;
    	}    
    	else if (tccd_l == 7)
    	{
    	    tccd_l = 0xC0;
    	}
    	else if (tccd_l == 8)
    	{
    	    tccd_l = 0x20;
    	}

    	vrefdq_train_value[i_port_number][dimm_number][rank_number] = mss_reverse_8bits(vrefdq_train_value[i_port_number][dimm_number][rank_number]);

    	if (vrefdq_train_range[i_port_number][dimm_number][rank_number] == ENUM_ATTR_EFF_VREF_DQ_TRAIN_RANGE_RANGE1)
    	{
    	    vrefdq_train_range[i_port_number][dimm_number][rank_number] = 0x00;
    	}
    	else if (vrefdq_train_range[i_port_number][dimm_number][rank_number] == ENUM_ATTR_EFF_VREF_DQ_TRAIN_RANGE_RANGE2)
    	{
    	    vrefdq_train_range[i_port_number][dimm_number][rank_number] = 0xFF;
    	}   

    	if (vrefdq_train_enable[i_port_number][dimm_number][rank_number] == ENUM_ATTR_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE)
    	{
    	    vrefdq_train_enable[i_port_number][dimm_number][rank_number] = 0xFF;
    	}
    	else if (vrefdq_train_enable[i_port_number][dimm_number][rank_number] == ENUM_ATTR_EFF_VREF_DQ_TRAIN_ENABLE_DISABLE)
    	{
    	    vrefdq_train_enable[i_port_number][dimm_number][rank_number] = 0x00;
    	}   

    	rc_num = rc_num | address_16.insert((uint8_t) vrefdq_train_value[i_port_number][dimm_number][rank_number], 0, 6);
    	rc_num = rc_num | address_16.insert((uint8_t) vrefdq_train_range[i_port_number][dimm_number][rank_number], 6, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) vrefdq_train_enable[i_port_number][dimm_number][rank_number], 7, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) 0x00, 8, 2);
    	rc_num = rc_num | address_16.insert((uint8_t) tccd_l, 10, 3);
    	rc_num = rc_num | address_16.insert((uint8_t) 0x00, 13, 2);
	
	rc_num = rc_num | bank_3.insert((uint8_t) MRS6_BA, 0, 1, 7);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS6_BA, 1, 1, 6);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS6_BA, 2, 1, 5);
	if (rc_num)
        {
            FAPI_ERR( "mss_mrs_load: Error setting up buffers");
            rc_buff.setEcmdError(rc_num);
            return rc_buff;
        }
    }
    else {
        const uint32_t MRS_VALUE = MRS;
	const fapi::Target & MBA_TARGET = i_target; 
	FAPI_SET_HWP_ERROR(rc, RC_MSS_PDA_MRS_NOT_FOUND);
	FAPI_ERR("ERROR!! Found attribute name not associated with an MRS! Exiting...");
    }
    
    return rc;
}
}

