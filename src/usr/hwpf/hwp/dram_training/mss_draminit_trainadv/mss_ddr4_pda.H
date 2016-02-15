/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_trainadv/mss_ddr4_pda.H $ */
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
// $Id: mss_ddr4_pda.H,v 1.41 2016/02/12 19:45:54 sglancy Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2013
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE : mss_ddr4_pda.H
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
//  1.7    | 02/16/16 | sglancy | Addressed FW comments
//  1.6    | 11/09/15 | sglancy | Added new function call
//  1.5    | 05/13/15 | sglancy | Added dox and updated functions for better FFDC
//  1.4    | 05/11/15 | sglancy | Addressed FW comments
//  1.3    | 05/07/15 | sglancy | Updated Doxygen header
//  1.2    | 02/13/15 | sglancy | Updated to allow for file inputs
//  1.1    | 10/27/14 | sglancy | First revision

#ifndef _MSS_DDR4_PDA_H
#define _MSS_DDR4_PDA_H
#include <fapi.H>
using namespace fapi;
using namespace std;
class PDA_MRS_Storage {
private:
   char pda_string[MAX_ECMD_STRING_LEN]; //aware that this isn't threadsafe but should be called w/in each thread
public:
   uint8_t attribute_data;
   uint32_t attribute_name;
   uint8_t MRS;
   uint8_t dimm;
   uint8_t dram;
   uint8_t rank;
   uint8_t port;
   PDA_MRS_Storage(uint8_t ad,uint32_t an,uint8_t dr,uint8_t di,uint8_t r,uint8_t p);
   ~PDA_MRS_Storage();
   bool operator> (const PDA_MRS_Storage &PDA2) const;
   bool operator< (const PDA_MRS_Storage &PDA2) const;
   void copy(PDA_MRS_Storage &temp);
   ReturnCode setMRSbyAttr(Target& i_target);
   ReturnCode checkPDAValid(Target& i_target);
   char * c_str();
   void generatePDAString();
};

class PDA_Scom_Storage {
public:
   uint64_t scom_addr;
   uint32_t start_bit;
   uint32_t num_bits;
   PDA_Scom_Storage(uint64_t sa, uint32_t sb, uint32_t nb);
   ~PDA_Scom_Storage();
};

typedef ReturnCode (*mss_ddr4_pda_FP_t)(Target& i_target, vector<PDA_MRS_Storage> pda);

extern "C"
{

/**
 * @runs through the vector of given PDA values and issues the PDA commands to the requested DRAMs
 *
 * @param[in]  target:  Reference to centaur.mba target, 
 * @param[in]  vector:  Vector of PDA_MRS_Storage class elements - initialized by the user and contains DRAM information and attribute override information
 *
 * @return ReturnCode
 */
ReturnCode mss_ddr4_run_pda(Target& i_target,vector<PDA_MRS_Storage> pda);
/**
 * @Puts the DRAM in per-DRAM addressability mode (PDA mode)
 *
 * @param[in]  target:  Reference to centaur.mba target, 
 * @param[in/out]  io_ccs_inst_cnt: starting point of CCS array - needed to properly setup CCS
 *
 * @return ReturnCode
 */
ReturnCode mss_ddr4_setup_pda(
            Target& i_target,
            uint32_t& io_ccs_inst_cnt,
	    uint8_t dimm_to_run,
	    uint8_t rank_to_run
            );
/**
 * @Takes the DRAM out of per-DRAM addressability mode (PDA mode)
 *
 * @param[in]  target:  Reference to centaur.mba target, 
 * @param[in/out]  io_ccs_inst_cnt: starting point of CCS array - needed to properly setup CCS
 * @param[in]  dimm_to_run: which DIMM to run PDA commands on 
 * @param[in]  rank_to_run: which rank on which DIMM to run PDA commands on 
 *
 * @return ReturnCode
 */
ReturnCode mss_ddr4_disable_pda(Target& i_target,uint32_t& io_ccs_inst_cnt, uint8_t dimm_to_run, uint8_t rank_to_run);
/**
 * @called by wrapper - sets up a PDA vector if it's not already configured
 *
 * @param[in]  target:  Reference to centaur.mba target, 
 * @param[in]  vector:  Vector of PDA_MRS_Storage class elements - initialized by the user and contains DRAM information and attribute override information
 *
 * @return ReturnCode
 */
ReturnCode mss_ddr4_pda(Target& i_target,vector<PDA_MRS_Storage> pda);
/**
 * @Checks the passed in PDA vector to ensure that all entries are good. then sorts the vector to ensure more efficient command stream
 *
 * @param[in]  target:  Reference to centaur.mba target, 
 * @param[in/out]  vector:  Vector of PDA_MRS_Storage class elements - initialized by the user and contains DRAM information and attribute override information
 *
 * @return ReturnCode
 */
ReturnCode mss_ddr4_checksort_pda(Target& i_target, vector<PDA_MRS_Storage>& pda);
/**
 * @Adds a given DRAM into the scom_storage vector
 *
 * @param[in]  target:  Reference to centaur.mba target, 
 * @param[in]  uint8_t port:  identifies which port the given DRAM is on
 * @param[in]  uint8_t dram:  identifies which DRAM identifier is to be added
 * @param[in/out]  vector:  list of all DRAMs being modified by PDA. contains address, bit, and length
 *
 * @return ReturnCode
 */
ReturnCode mss_ddr4_add_dram_pda(Target& i_target,uint8_t port,uint8_t dram,vector<PDA_Scom_Storage> & scom_storage);

/**
 * @Adds a given DRAM into the scom_storage vector
 *
 * @param[in]  target:  Reference to centaur.mba target, 
 * @param[out]  uint8_t wl_launch_time:  holds the number of cycles that the data must be launched after the PDA command is issued
 * @param[out]  uint8_t odt_hold_time:  holds the number of cycles that the ODT must be held for PDA
 * @param[out]  uint8_t post_odt_nop_idle:  holds the number of cycles that 
 *
 * @return ReturnCode
 */
ReturnCode mss_get_pda_odt_timings(Target& i_target,uint8_t & wl_launch_time,uint8_t & odt_hold_time,uint8_t & post_odt_nop_idle);
ReturnCode mss_ddr4_run_pda_by_dimm_rank(
            Target& i_target,
	    vector<PDA_MRS_Storage> pda,
	    uint8_t dimm_to_run,
	    uint8_t rank_to_run
            );

uint32_t mss_ddr4_check_pda_empty_for_rank(
	    vector<PDA_MRS_Storage> pda,
	    uint8_t dimm_to_run,
	    uint8_t rank_to_run
            );

} // extern "C"

#endif /* _MSS_DDR4_PDA_H */


