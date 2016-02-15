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
// $Id: mss_ddr4_pda.C,v 1.51 2016/02/19 21:14:34 sglancy Exp $
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
//  1.16   | 02/19/16 | sglancy | Fixed B-side MRS inversion bug
//  1.15   | 02/12/16 | sglancy | Addressed FW comments
//  1.15   | 02/03/16 | sglancy | Fixed FW compile issues
//  1.15   | 01/11/16 | sglancy | Fixed issue with PDA timings
//  1.15   | 11/09/15 | sglancy | Patch to fix cronus compile issue
//  1.14   | 11/03/15 | sglancy | Fixed attribute names for DDR4 RDIMM
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
#include <mss_ddr4_funcs.H>
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
   uint8_t dram_stack[2][2];
   rc = FAPI_ATTR_GET(ATTR_EFF_STACK_TYPE, &i_target, dram_stack);
   if(rc) return rc;
   //get num master ranks per dimm for 3DS
   if(dram_stack[0][0] == ENUM_ATTR_EFF_STACK_TYPE_STACK_3DS) {
      rc = FAPI_ATTR_GET(ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM, &i_target, num_ranks);
   }
   //get num ranks per dimm for non-3DS
   else {
      rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target, num_ranks);
   }
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
            uint32_t& io_ccs_inst_cnt,
	    uint8_t dimm_to_run,
	    uint8_t rank_to_run
            )
{
    uint32_t i_port_number=0;
    uint32_t dimm_number = dimm_to_run;
    uint32_t rank_number = rank_to_run;
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
    
    uint8_t dram_stack[2][2];
    rc = FAPI_ATTR_GET(ATTR_EFF_STACK_TYPE, &i_target, dram_stack);
    if(rc) return rc;
    
    uint8_t dimm_type;
    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target, dimm_type);
    if(rc) return rc;
    
    uint8_t dram_gen;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_GEN, &i_target, dram_gen);
    if(rc) return rc;
    
    //get num master ranks per dimm for 3DS
    if(dram_stack[dimm_to_run][rank_to_run] == ENUM_ATTR_EFF_STACK_TYPE_STACK_3DS) {
       rc = FAPI_ATTR_GET(ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM, &i_target, num_ranks_array);
    }
    //get num ranks per dimm for non-3DS
    else {
       rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target, num_ranks_array);
    }
    if(rc) return rc;

    uint8_t is_sim = 0;
    rc = FAPI_ATTR_GET(ATTR_IS_SIMULATION, NULL, is_sim);
    if(rc) return rc;

    uint8_t address_mirror_map[2][2]; //address_mirror_map[port][dimm]
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_ADDRESS_MIRRORING, &i_target, address_mirror_map);
    if(rc) return rc;

    // WORKAROUNDS 
    rc = fapiGetScom(i_target, CCS_MODEQ_AB_REG_0x030106A7, data_buffer);
    if(rc) return rc;
    //Setting up CCS mode
    rc_num = rc_num | data_buffer.setBit(51);
    //if in DDR4 mode, count the parity bit and set it
    if((dram_gen == ENUM_ATTR_EFF_DRAM_GEN_DDR4) && (dimm_type == fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM || dimm_type == fapi::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM) ) {
       rc_num = rc_num | data_buffer.insertFromRight( (uint8_t)0xff, 61, 1);
    }
    
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
       
       if(dram_stack[0][0] == ENUM_ATTR_EFF_STACK_TYPE_STACK_3DS) {
          rc_num = rc_num | csn_8.clearBit(2,2); 
          rc_num = rc_num | csn_8.clearBit(6,2); 
       }
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
    
    //Does the RTT_WR to RTT_NOM swapping
    //loops through all ports
    for(i_port_number=0;i_port_number<MAX_NUM_PORTS;i_port_number++) {
       uint8_t io_dram_rtt_nom_original = 0xff;
       rc = mss_ddr4_rtt_nom_rtt_wr_swap(i_target,0,i_port_number,rank_to_run+dimm_to_run*4,0xFF,io_ccs_inst_cnt,io_dram_rtt_nom_original);
       if(rc) return rc;
       io_ccs_inst_cnt = 0;
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
    	
       // Only corresponding CS to rank
       rc_num = rc_num | csn_8.setBit(0,8); 
       if(dram_stack[0][0] == ENUM_ATTR_EFF_STACK_TYPE_STACK_3DS) {
          rc_num = rc_num | csn_8.clearBit(2,2); 
          rc_num = rc_num | csn_8.clearBit(6,2); 
       }
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
           if(dram_stack[0][0] == ENUM_ATTR_EFF_STACK_TYPE_STACK_3DS) {
              rc_num = rc_num | csn_8.clearBit(2,2); 
              rc_num = rc_num | csn_8.clearBit(6,2); 
           }
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
           rc_num = rc_num | bank_3.flipBit(0,3);     // Invert BA0,BA1,BG0
           
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
   //if in DDR4 mode, count the parity bit and set it
    if((dram_gen == ENUM_ATTR_EFF_DRAM_GEN_DDR4) && (dimm_type == fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM || dimm_type == fapi::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM) ) {
       rc_num = rc_num | data_buffer.insertFromRight( (uint8_t)0xff, 61, 1);
    }
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
   
   
   //sets up the DRAM DQ drive time
   uint8_t wl_launch_time;
   uint8_t odt_hold_time;
   uint8_t post_odt_nop_idle;
   rc = mss_get_pda_odt_timings(i_target, wl_launch_time, odt_hold_time, post_odt_nop_idle);
   if(rc) return rc;
   wl_launch_time -= 7;
   
   rc = fapiGetScom(i_target,  DPHY01_DDRPHY_WC_CONFIG3_P0_0x8000CC050301143F, data_buffer);
   if(rc) return rc;
   //Setting up CCS mode
   rc_num = rc_num | data_buffer.setBit(48);
   rc_num = rc_num | data_buffer.insertFromRight((uint8_t)0x00,49,6);
   rc_num = rc_num | data_buffer.insertFromRight((uint8_t)0xFF,55,6);
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
   rc_num = rc_num | data_buffer.insertFromRight((uint8_t)0x00,49,6);
   rc_num = rc_num | data_buffer.insertFromRight((uint8_t)0xFF,55,6);
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
    FAPI_INF("Commonly used PDA attributes: fapi::ATTR_EFF_VREF_DQ_TRAIN_ENABLE=0x%08x fapi::ATTR_EFF_VREF_DQ_TRAIN_VALUE=0x%08x",ATTR_EFF_VREF_DQ_TRAIN_ENABLE,ATTR_EFF_VREF_DQ_TRAIN_VALUE);
    //gets the rank information
    uint8_t num_ranks_array[2][2]; //[port][dimm]
    uint8_t dram_stack[2][2];
    rc = FAPI_ATTR_GET(ATTR_EFF_STACK_TYPE, &i_target, dram_stack);
    if(rc) return rc;
    //get num master ranks per dimm for 3DS
    if(dram_stack[0][0] == ENUM_ATTR_EFF_STACK_TYPE_STACK_3DS) {
       rc = FAPI_ATTR_GET(ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM, &i_target, num_ranks_array);
    }
    //get num ranks per dimm for non-3DS
    else {
       rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target, num_ranks_array);
    }
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

//loops through and runs PDA on all MBA's
ReturnCode mss_ddr4_run_pda(
            Target& i_target,
	    vector<PDA_MRS_Storage> pda
            ) {
   ReturnCode rc;  
   if(pda.size() == 0) return rc;
   
   
   uint8_t num_ranks_array[2][2]; //[port][dimm]
   
   uint8_t dram_stack[2][2];
   rc = FAPI_ATTR_GET(ATTR_EFF_STACK_TYPE, &i_target, dram_stack);
   if(rc) return rc;
   
   if(dram_stack[0][0]  == ENUM_ATTR_EFF_STACK_TYPE_STACK_3DS) {
      rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target, num_ranks_array);
   }
   else {
      rc = FAPI_ATTR_GET(ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM, &i_target, num_ranks_array);
   }
   if(rc) return rc;
   
   //loops through all DIMMs all Ranks
   for(uint8_t dimm_to_run=0;dimm_to_run<2;dimm_to_run++) {
      uint8_t largest_num_ranks = num_ranks_array[0][dimm_to_run];
      if(largest_num_ranks < num_ranks_array[1][dimm_to_run]) largest_num_ranks = num_ranks_array[1][dimm_to_run];
      
      for(uint8_t rank_to_run=0;rank_to_run<largest_num_ranks;rank_to_run++) {
         FAPI_INF("Running PDA on DIMM %d Rank %d!!",dimm_to_run, rank_to_run);
         rc = mss_ddr4_run_pda_by_dimm_rank(i_target, pda, dimm_to_run, rank_to_run);
	 if(rc) return rc;
      }
   }
   
   return rc;
}


/////////////////////////////////////////////////////////////////////////////////
/// mss_ddr4_run_pda_by_dimm_rank
/// runs per-DRAM addressability funcitonality on both ports on the passed MBA by dimm and rank
/////////////////////////////////////////////////////////////////////////////////
ReturnCode mss_ddr4_run_pda_by_dimm_rank(
            Target& i_target,
	    vector<PDA_MRS_Storage> pda,
	    uint8_t dimm_to_run,
	    uint8_t rank_to_run
            )
{
    ReturnCode rc;  
    //no PDA was entered, just exit
    if(pda.size() == 0) return rc;
    
    //DIMM/rank not found - exit
    if(mss_ddr4_check_pda_empty_for_rank(pda,dimm_to_run,rank_to_run)) return rc;
    
    uint32_t io_ccs_inst_cnt = 0;
    const uint32_t NUM_POLL = 10;
    const uint32_t WAIT_TIMER = 1500;
    ReturnCode rc_buff;
    uint32_t rc_num = 0;
    ecmdDataBufferBase data_buffer_64(64);
    ecmdDataBufferBase address_16(16);
    ecmdDataBufferBase address_16_backup(16);
    ecmdDataBufferBase bank_3(3);
    ecmdDataBufferBase bank_3_backup(3);
    ecmdDataBufferBase activate_1(1);
    rc_num = rc_num | activate_1.setBit(0);
    ecmdDataBufferBase rasn_1(1);
    ecmdDataBufferBase casn_1(1);
    ecmdDataBufferBase wen_1(1);
    ecmdDataBufferBase rasn_1_odt(1);
    ecmdDataBufferBase casn_1_odt(1);
    ecmdDataBufferBase wen_1_odt(1);
    ecmdDataBufferBase num_repeat_16_odt(16);
    ecmdDataBufferBase num_idles_16_odt(16);
    ecmdDataBufferBase csn_8_odt(8);
    rc_num = rc_num | rasn_1_odt.clearBit(0,1);
    rc_num = rc_num | casn_1_odt.clearBit(0,1);
    rc_num = rc_num | wen_1_odt.clearBit(0,1);
    rc_num = rc_num | csn_8_odt.setBit(0,8);
    rc_num = rc_num | csn_8_odt.clearBit(7,1);
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
    
    uint8_t dram_stack[2][2];
    rc = FAPI_ATTR_GET(ATTR_EFF_STACK_TYPE, &i_target, dram_stack);
    if(rc) return rc;

    uint8_t is_sim = 0;
    rc = FAPI_ATTR_GET(ATTR_IS_SIMULATION, NULL, is_sim);
    if(rc) return rc;

    uint8_t address_mirror_map[2][2]; //address_mirror_map[port][dimm]
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_ADDRESS_MIRRORING, &i_target, address_mirror_map);
    if(rc) return rc;

   rc = mss_ddr4_setup_pda(i_target, io_ccs_inst_cnt, dimm_to_run,rank_to_run );
   if(rc) return rc;
   
   uint8_t wl_launch_time;
   uint8_t odt_hold_time;
   uint8_t post_odt_nop_idle;
   rc = mss_get_pda_odt_timings(i_target, wl_launch_time, odt_hold_time, post_odt_nop_idle);
   
   rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 0, 0, 16);
   rc_num = rc_num | num_repeat_16.insertFromRight((uint32_t) 0, 0, 16);
   
   rc_num = rc_num | num_idles_16_odt.insertFromRight( post_odt_nop_idle, 0, 8);
   rc_num = rc_num | num_repeat_16_odt.insertFromRight( odt_hold_time, 0, 8);
   
   
   
   rc_num = rc_num | cke_4.setBit(0,4);
   rc_num = rc_num | csn_8.setBit(0,8);
   rc_num = rc_num | address_16.clearBit(0, 16);
   rc_num = rc_num | odt_4.clearBit(0,4);
   rc_num = rc_num | rasn_1.clearBit(0,1);
   rc_num = rc_num | casn_1.clearBit(0,1);
   rc_num = rc_num | wen_1.clearBit(0,1);
   
   if(rc_num)
   {
       rc.setEcmdError(rc_num);
       return rc;
   }
   
   uint8_t odt_wr[2][2][4];
   rc = FAPI_ATTR_GET(ATTR_VPD_ODT_WR,  &i_target, odt_wr);
   if(rc) return rc;
   
   bool prev_dram_set = false;
   vector<PDA_Scom_Storage> scom_storage;
   uint8_t prev_dram = 0;
   uint8_t prev_port = 0;
   uint8_t prev_rank = 0;
   uint8_t prev_dimm = 0;
   uint8_t prev_mrs  = 0;

   //runs through each PDA command
   for(uint32_t i=0;i<pda.size();i++) {
      //did not find a PDA with the same DIMM and rank as requested
      if(pda[i].rank != rank_to_run || pda[i].dimm != dimm_to_run) {
         continue;
      }
      
      //found a PDA of the same dimm and rank, but storage not set
      if(!prev_dram_set) {
         //gets the start PDA values
         prev_dram = pda[i].dram;
         prev_port = pda[i].port;
         prev_rank = pda[i].rank;
         prev_dimm = pda[i].dimm;
         prev_mrs  = pda[i].MRS;
	 prev_dram_set = true;
	 
         rc = mss_ddr4_load_nominal_mrs_pda(i_target,bank_3,address_16, prev_mrs, prev_port, prev_dimm, prev_rank);
         if(rc) return rc;
	 
	 scom_storage.clear();
	 rc = mss_ddr4_add_dram_pda(i_target,prev_port,prev_dram,scom_storage);
	 if(rc) return rc;
      }
   
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
	 rc_num = rc_num | address_16_backup.clearBit(0, 16);
	 rc_num = rc_num | address_16_backup.insert(address_16, 0, 16, 0);
	 rc_num = rc_num | bank_3_backup.clearBit(0,3);
	 rc_num = rc_num | bank_3_backup.insert(bank_3, 0, 3, 0);
	 if(rc_num)
         {
             rc.setEcmdError(rc_num);
             return rc;
         }
	 
         //loads the previous DRAM
         if (( address_mirror_map[prev_port][prev_dimm] & (0x08 >> prev_rank) ) && (is_sim == 0))
   	 {
   	     rc = mss_address_mirror_swizzle(i_target, prev_port, prev_dimm, prev_rank, address_16, bank_3);
   	     if(rc) return rc;
   	 }
	 
	 // Only corresponding CS to rank
   	 rc_num = rc_num | csn_8.setBit(0,8); 
   	 rc_num = rc_num | csn_8.clearBit(prev_rank+4*prev_dimm);
	 
         if(dram_stack[0][0] == ENUM_ATTR_EFF_STACK_TYPE_STACK_3DS) {
            rc_num = rc_num | csn_8.clearBit(2,2); 
            rc_num = rc_num | csn_8.clearBit(6,2); 
         }
	 rc_num = rc_num | odt_4.insert(odt_wr[prev_port][prev_dimm][prev_rank], 0, 4, 0);
	 if(rc_num)
    	 {
    	     rc.setEcmdError(rc_num);
    	     return rc;
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
	 
	 // Send out to the CCS array 
   	 rc = mss_ccs_inst_arry_0( i_target,
   	     	  io_ccs_inst_cnt,
   	     	  address_16,
   	     	  bank_3,
   	     	  activate_1,
   	     	  rasn_1_odt,
   	     	  casn_1_odt,
   	     	  wen_1_odt,
   	     	  cke_4,
   	     	  csn_8_odt,
   	     	  odt_4,
   	     	  ddr_cal_type_4,
   	     	  prev_port);
   	 if(rc) return rc;
   	 rc = mss_ccs_inst_arry_1( i_target,
   	     	  io_ccs_inst_cnt,
   	     	  num_idles_16_odt,
   	     	  num_repeat_16_odt,
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
	    rc_num = rc_num | address_16.clearBit(0, 16);
	    rc_num = rc_num | address_16.insert(address_16_backup, 0, 16, 0);
	    rc_num = rc_num | bank_3.clearBit(0,3);
	    rc_num = rc_num | bank_3.insert(bank_3_backup, 0, 3, 0);
	 
	    //FLIPS all necessary bits
	    // Indicate B-Side DRAMS BG1=1 
            rc_num = rc_num | address_16.setBit(15);  // Set BG1 = 1
 
            rc_num = rc_num | address_16.flipBit(3,7); // Invert A3:A9
            rc_num = rc_num | address_16.flipBit(11);  // Invert A11
            rc_num = rc_num | address_16.flipBit(13);  // Invert A13
            rc_num = rc_num | address_16.flipBit(14);  // Invert A17
            rc_num = rc_num | bank_3.flipBit(0,3);     // Invert BA0,BA1,BG0
	    if(rc_num)
            {
                rc.setEcmdError(rc_num);
                return rc;
            }
	    
	    //loads the previous DRAM
            if (( address_mirror_map[prev_port][prev_dimm] & (0x08 >> prev_rank) ) && (is_sim == 0))
   	    {
   	   	rc = mss_address_mirror_swizzle(i_target, prev_port, prev_dimm, prev_rank, address_16, bank_3);
   	   	if(rc) return rc;
   	    }
	    
	    // Only corresponding CS to rank
   	    rc_num = rc_num | csn_8.setBit(0,8); 
   	    rc_num = rc_num | csn_8.clearBit(prev_rank+4*prev_dimm);
	    
            if(dram_stack[0][0] == ENUM_ATTR_EFF_STACK_TYPE_STACK_3DS) {
               rc_num = rc_num | csn_8.clearBit(2,2); 
               rc_num = rc_num | csn_8.clearBit(6,2); 
            }
	    rc_num = rc_num | odt_4.insert(odt_wr[prev_port][prev_dimm][prev_rank], 0, 4, 0);
	    if(rc_num)
    	    {
    	        rc.setEcmdError(rc_num);
    	        return rc;
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
	    
	    // Send out to the CCS array 
            rc = mss_ccs_inst_arry_0( i_target,
            	     io_ccs_inst_cnt,
            	     address_16,
            	     bank_3,
            	     activate_1,
            	     rasn_1_odt,
            	     casn_1_odt,
            	     wen_1_odt,
            	     cke_4,
            	     csn_8_odt,
            	     odt_4,
            	     ddr_cal_type_4,
            	     prev_port);
            if(rc) return rc;
            rc = mss_ccs_inst_arry_1( i_target,
            	     io_ccs_inst_cnt,
            	     num_idles_16_odt,
            	     num_repeat_16_odt,
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
	    rc_num = rc_num | odt_4.insert((uint8_t) 0, 0, 4, 0);
	    
	    if(rc_num)
    	    {
    	        rc.setEcmdError(rc_num);
    	        return rc;
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
   
   //runs the last PDA command, if and only if a PDA of the desired rank and dimm was run
   if(prev_dram_set) {
      //adds values to a backup address_16 before doing the mirroring
      rc_num = rc_num | address_16_backup.clearBit(0, 16);
      rc_num = rc_num | address_16_backup.insert(address_16, 0, 16, 0);
      rc_num = rc_num | bank_3_backup.clearBit(0, 3);
      rc_num = rc_num | bank_3_backup.insert(bank_3, 0, 3, 0);
      rc_num = rc_num | odt_4.insert(odt_wr[prev_port][prev_dimm][prev_rank], 0, 4, 0);
      
      if(rc_num)
      {
          rc.setEcmdError(rc_num);
          return rc;
      }

      //loads the previous DRAM
      if (( address_mirror_map[prev_port][prev_dimm] & (0x08 >> prev_rank) ) && (is_sim == 0))
      {
   	  rc = mss_address_mirror_swizzle(i_target, prev_port, prev_dimm, prev_rank, address_16, bank_3);
   	  if(rc) return rc;
      }

      // Only corresponding CS to rank
      rc_num = rc_num | csn_8.setBit(0,8); 
      
      if(dram_stack[0][0] == ENUM_ATTR_EFF_STACK_TYPE_STACK_3DS) {
   	 rc_num = rc_num | csn_8.clearBit(2,2); 
   	 rc_num = rc_num | csn_8.clearBit(6,2); 
      }
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
      
      // Send out to the CCS array 
      rc = mss_ccs_inst_arry_0( i_target,
   	       io_ccs_inst_cnt,
   	       address_16,
   	       bank_3,
   	       activate_1,
   	       rasn_1_odt,
   	       casn_1_odt,
   	       wen_1_odt,
   	       cke_4,
   	       csn_8_odt,
   	       odt_4,
   	       ddr_cal_type_4,
   	       prev_port);
      if(rc) return rc;
      rc = mss_ccs_inst_arry_1( i_target,
   	       io_ccs_inst_cnt,
   	       num_idles_16_odt,
   	       num_repeat_16_odt,
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
	 rc_num = rc_num | address_16.clearBit(0, 16);
	 rc_num = rc_num | address_16.insert(address_16_backup, 0, 16, 0);
	 rc_num = rc_num | bank_3.clearBit(0,3);
	 rc_num = rc_num | bank_3.insert(bank_3_backup, 0, 3, 0);
   	 
   	 //FLIPS all necessary bits
   	 // Indicate B-Side DRAMS BG1=1 
   	 rc_num = rc_num | address_16.setBit(15);  // Set BG1 = 1
    
   	 rc_num = rc_num | address_16.flipBit(3,7); // Invert A3:A9
   	 rc_num = rc_num | address_16.flipBit(11);  // Invert A11
   	 rc_num = rc_num | address_16.flipBit(13);  // Invert A13
   	 rc_num = rc_num | address_16.flipBit(14);  // Invert A17
   	 rc_num = rc_num | bank_3.flipBit(0,3);     // Invert BA0,BA1,BG0
   	 
	 if(rc_num)
    	 {
    	     rc.setEcmdError(rc_num);
    	     return rc;
    	 }
	 
   	 //loads the previous DRAM
   	 if (( address_mirror_map[prev_port][prev_dimm] & (0x08 >> prev_rank) ) && (is_sim == 0))
   	 {
   	     rc = mss_address_mirror_swizzle(i_target, prev_port, prev_dimm, prev_rank, address_16, bank_3);
   	     if(rc) return rc;
   	 }
   	 
   	 // Only corresponding CS to rank
   	 rc_num = rc_num | csn_8.setBit(0,8); 
   	 
   	 if(dram_stack[0][0] == ENUM_ATTR_EFF_STACK_TYPE_STACK_3DS) {
   	    rc_num = rc_num | csn_8.clearBit(2,2); 
   	    rc_num = rc_num | csn_8.clearBit(6,2); 
   	 }
   	 rc_num = rc_num | csn_8.clearBit(prev_rank+4*prev_dimm);
   	 
	 if(rc_num)
    	 {
    	     rc.setEcmdError(rc_num);
    	     return rc;
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
   	 
   	 // Send out to the CCS array 
   	 rc = mss_ccs_inst_arry_0( i_target,
   		  io_ccs_inst_cnt,
   		  address_16,
   		  bank_3,
   		  activate_1,
   		  rasn_1_odt,
   		  casn_1_odt,
   		  wen_1_odt,
   		  cke_4,
   		  csn_8_odt,
   		  odt_4,
   		  ddr_cal_type_4,
   		  prev_port);
   	 if(rc) return rc;
   	 rc = mss_ccs_inst_arry_1( i_target,
   		  io_ccs_inst_cnt,
   		  num_idles_16_odt,
   		  num_repeat_16_odt,
   		  data_20,
   		  read_compare_1,
   		  rank_cal_4,
   		  ddr_cal_enable_1,
   		  ccs_end_1);
   	 if(rc) return rc;
   	 io_ccs_inst_cnt ++;
      }
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
   	    csn_8_odt,
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
   rc = mss_ddr4_disable_pda(i_target,io_ccs_inst_cnt,dimm_to_run,rank_to_run);
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
   FAPI_INF("Enabling %016llx start at %d for %d bits for port %d dram %d",reg_address,scom_start,scom_len,port,dram);
   
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
ReturnCode mss_ddr4_disable_pda(Target& i_target,uint32_t& io_ccs_inst_cnt, uint8_t dimm_to_run, uint8_t rank_to_run) {
    uint32_t i_port_number=0;
    uint32_t dimm_number = dimm_to_run;
    uint32_t rank_number = rank_to_run;
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
    
    ecmdDataBufferBase rasn_1_odt(1);
    ecmdDataBufferBase casn_1_odt(1);
    ecmdDataBufferBase wen_1_odt(1);
    ecmdDataBufferBase num_repeat_16_odt(16);
    ecmdDataBufferBase num_idles_16_odt(16);
    ecmdDataBufferBase csn_8_odt(8);
    rc_num = rc_num | rasn_1_odt.clearBit(0,1);
    rc_num = rc_num | casn_1_odt.clearBit(0,1);
    rc_num = rc_num | wen_1_odt.clearBit(0,1);
    rc_num = rc_num | csn_8_odt.setBit(0,8);
    rc_num = rc_num | csn_8_odt.clearBit(7,1);
    
    if (rc_num) {
       FAPI_ERR( "disable ccs setup: Error disabling up buffers");
       rc_buff.setEcmdError(rc_num);
       return rc_buff;
    }

    ecmdDataBufferBase mrs3(16);
    uint16_t MRS3 = 0;
    
    uint8_t dram_gen;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_GEN, &i_target, dram_gen);
    if(rc) return rc;
    
    uint8_t odt_wr[2][2][4];
    rc = FAPI_ATTR_GET(ATTR_VPD_ODT_WR,  &i_target, odt_wr);
    if(rc) return rc;
    
    uint8_t dram_stack[2][2];
    rc = FAPI_ATTR_GET(ATTR_EFF_STACK_TYPE, &i_target, dram_stack);
    if(rc) return rc;

    uint8_t dimm_type;
    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target, dimm_type);
    if(rc) return rc;

    uint8_t is_sim = 0;
    rc = FAPI_ATTR_GET(ATTR_IS_SIMULATION, NULL, is_sim);
    if(rc) return rc;

    uint8_t address_mirror_map[2][2]; //address_mirror_map[port][dimm]
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_ADDRESS_MIRRORING, &i_target, address_mirror_map);
    if(rc) return rc;

    // WORKAROUNDS 
    rc = fapiGetScom(i_target, CCS_MODEQ_AB_REG_0x030106A7, data_buffer);
    if(rc) return rc;
    //Setting up CCS mode
    rc_num = rc_num | data_buffer.setBit(51);
    //if in DDR4 mode, count the parity bit and set it
    if((dram_gen == ENUM_ATTR_EFF_DRAM_GEN_DDR4) && (dimm_type == fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM || dimm_type == fapi::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM) ) {
       rc_num = rc_num | data_buffer.insertFromRight( (uint8_t)0xff, 61, 1);
    }
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
    
    
    //sets up the DRAM DQ drive time
    uint8_t wl_launch_time;
    uint8_t odt_hold_time;
    uint8_t post_odt_nop_idle;
    rc = mss_get_pda_odt_timings(i_target, wl_launch_time, odt_hold_time, post_odt_nop_idle);
   
    rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 0, 0, 16);
    rc_num = rc_num | num_repeat_16.insertFromRight((uint32_t) 0, 0, 16);
   
    rc_num = rc_num | num_idles_16_odt.insertFromRight( post_odt_nop_idle, 0, 8);
    rc_num = rc_num | num_repeat_16_odt.insertFromRight( odt_hold_time, 0, 8);
    
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
       // Only corresponding CS to rank
       rc_num = rc_num | csn_8.setBit(0,8); 
       if(dram_stack[0][0] == ENUM_ATTR_EFF_STACK_TYPE_STACK_3DS) {
          rc_num = rc_num | csn_8.clearBit(2,2); 
          rc_num = rc_num | csn_8.clearBit(6,2); 
       }
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
       rc_num = rc_num | odt_4.insert(odt_wr[i_port_number][dimm_number][rank_number], 0, 4, 0);

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

       // Send out to the CCS array 
       rc = mss_ccs_inst_arry_0( i_target,
        	io_ccs_inst_cnt,
        	address_16,
        	bank_3,
        	activate_1,
        	rasn_1_odt,
        	casn_1_odt,
        	wen_1_odt,
        	cke_4,
        	csn_8_odt,
        	odt_4,
        	ddr_cal_type_4,
        	i_port_number);
       if(rc) return rc;
       rc = mss_ccs_inst_arry_1( i_target,
        	io_ccs_inst_cnt,
        	num_idles_16_odt,
        	num_repeat_16_odt,
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
           if(dram_stack[0][0] == ENUM_ATTR_EFF_STACK_TYPE_STACK_3DS) {
              rc_num = rc_num | csn_8.clearBit(2,2); 
              rc_num = rc_num | csn_8.clearBit(6,2); 
           }
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
           rc_num = rc_num | bank_3.flipBit(0,3);     // Invert BA0,BA1,BG0
           
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
           
           // Send out to the CCS array 
           rc = mss_ccs_inst_arry_0( i_target,
	    	    io_ccs_inst_cnt,
	    	    address_16,
	    	    bank_3,
	    	    activate_1,
	    	    rasn_1_odt,
	    	    casn_1_odt,
	    	    wen_1_odt,
	    	    cke_4,
	    	    csn_8_odt,
	    	    odt_4,
	    	    ddr_cal_type_4,
	    	    i_port_number);
           if(rc) return rc;
           rc = mss_ccs_inst_arry_1( i_target,
	    	    io_ccs_inst_cnt,
	    	    num_idles_16_odt,
	    	    num_repeat_16_odt,
	    	    data_20,
	    	    read_compare_1,
	    	    rank_cal_4,
	    	    ddr_cal_enable_1,
	    	    ccs_end_1);
           if(rc) return rc;
           io_ccs_inst_cnt ++;
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
   
   //Does the RTT_WR to RTT_NOM swapping
    //loops through all ports
    for(i_port_number=0;i_port_number<MAX_NUM_PORTS;i_port_number++) {
       uint8_t io_dram_rtt_nom_original = 0;
       rc = mss_ddr4_rtt_nom_rtt_wr_swap(i_target,0,i_port_number,rank_number+dimm_number*4,0xFF,io_ccs_inst_cnt,io_dram_rtt_nom_original);
       if(rc) return rc;
       io_ccs_inst_cnt = 0;
    }
   
   return rc;
}


//sets up the ODT holdtime and number of idles to be issued after 
ReturnCode mss_get_pda_odt_timings(Target& i_target,uint8_t & wl_launch_time,uint8_t & odt_hold_time,uint8_t & post_odt_nop_idle) {
    ReturnCode rc;  
    ReturnCode rc_buff;
    uint32_t rc_num = 0;
    ecmdDataBufferBase data_buffer(64);
    
    //reads out the register values
    rc = fapiGetScom(i_target, MBA01_MBA_DSM0_0x0301040a, data_buffer);
    if(rc) return rc;
    
    //gets the hold time
    uint8_t launch_delay;
    rc_num = rc_num | data_buffer.extractToRight(&launch_delay,12,6);
    rc_num = rc_num | data_buffer.extractToRight(&odt_hold_time,18,6);
    
    odt_hold_time = odt_hold_time + launch_delay;
    
    if(rc_num)
    {
	rc.setEcmdError(rc_num);
	return rc;
    }
    
    //gets write latency
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_CWL, &i_target, wl_launch_time);
    if(rc) return rc;
    
    wl_launch_time += launch_delay;
    
    uint8_t dram_al;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_AL, &i_target, dram_al);
    if(rc) return rc;
    
    //Addative latency enabled - need to add CL-AL
    if(dram_al != ENUM_ATTR_EFF_DRAM_AL_DISABLE) {
       uint8_t dram_cl;
       rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_CL, &i_target, dram_cl);
       if(rc) return rc;
       wl_launch_time += (dram_cl-dram_al);
    }
    
    post_odt_nop_idle = wl_launch_time + odt_hold_time + 50;
    
    return rc;
}

//returns a 1 if the PDA is empty for the given DIMM rank - returns 0 if not empty
uint32_t mss_ddr4_check_pda_empty_for_rank(
	    vector<PDA_MRS_Storage> pda,
	    uint8_t dimm_to_run,
	    uint8_t rank_to_run
            ) {
   uint32_t rc = 1;
   
   for(uint32_t i=0;i<pda.size();i++) {
      //found, return 0
      if(pda[i].dimm == dimm_to_run && pda[i].rank == rank_to_run) return 0;
   }
   
   //not found, return 1
   return rc;
}
}

