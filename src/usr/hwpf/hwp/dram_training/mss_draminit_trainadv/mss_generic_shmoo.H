/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_trainadv/mss_generic_shmoo.H $ */
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
// $Id: mss_generic_shmoo.H,v 1.22 2013/08/08 11:08:58 sasethur Exp $
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998
// *!           All Rights Reserved -- Property of IBM
// *!                   *** IBM Confidential ***
// *!***************************************************************************
// *! FILENAME             : mss_generic_shmoo.H
// *! TITLE                : MSS Generic Shmoo 
// *! DESCRIPTION          : Memory Subsystem Generic Shmoo -- abstraction for HB
// *! CONTEXT              : To make all shmoos share a common abstraction layer
// *!
// *! OWNER  NAME          : Abhijit Saurabh          Email:  abhijit.saurabh@in.ibm.com
// *! BACKUP NAME          :    
// *!
// *!***************************************************************************
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|Author: | Date:  | Comment:
// --------|--------|--------|--------------------------------------------------
//   1.22  |abhijit |8/08/13 |added binary schmoo functions 
//   1.20  |abhijit |7/17/13 |added functions for read dqs 
//   1.11  |abhijit |1/21/13 |fixed constructor definition  
//   1.9   |abhijit |06/12/12|fixed fw review comments 
//   1.4   |abhijit |09/27/11|made changes according to new design
//   1.5   |abhijit |10/29/12|made changes after target and returncode 
//   1.6   |abhijit |10/29/12|made changes  
//   1.7   |abhijit |11/15/12|made changes for fw review comments 
//------------------------------------------------------------------------------
#include <fapi.H>

#ifndef generic_shmoo_H
#define generic_shmoo_H

using namespace fapi;
//! Globals
#define SHMOO_DEBUG 0
#define SHMOO_DEBUG2 0
#include "mss_shmoo_common.H"
#include "mss_mcbist.H"
//#include "mss_draminit_training.H"
// #include <cen_scom_addresses.H>
// #include "mss_funcs.H"



//! MSS Generic Shmoo Class.. Inherits from PHY access class and the knob abstraction 
class generic_shmoo
{
    private:
        
        
        //! MBS Config : Port + Socket + Knobs
        struct SHMOO_SCENARIO{
            struct MBS_CONFIG{
               struct PORT{
                   struct RANK{
                        shmoo_knob_data_t K; // Set of knobs used by this shmoo 
                   }S[MAX_RANK];
               } P[MAX_PORT];
           }MBA;
           shmoo_knob_config_t static_knob; // Static info regarding the knob
        }SHMOO[MAX_SHMOO]; // Denote max shmoo scenarios we have
     
        //! Result Data 
	
        uint8_t convergence_gap;
        shmoo_algorithm_t algorithm;
        shmoo_mode mcbist_mode;
        uint8_t mcbist_error_map[MAX_PORT][MAX_RANK][MAX_BYTE][MAX_NIBBLES];
		uint8_t schmoo_error_map[MAX_PORT][MAX_RANK][20];
		uint8_t binary_done_map[MAX_PORT][MAX_RANK][20];
		shmoo_type_t shmoo_mask;
	uint8_t iv_addr;
	uint8_t iv_MAX_RANKS[MAX_PORT];
	uint8_t iv_MAX_BYTES;
	uint32_t iv_pattern;
	uint32_t iv_test_type;
	uint8_t iv_dmm_type;
	uint8_t iv_DQS_ON;
	uint8_t iv_shmoo_type;
	uint32_t iv_shmoo_param;
	uint32_t iv_binary_diff;
	uint32_t iv_vref_mul;
	uint8_t valid_rank[MAX_RANK];

        
    public:
        
    
	
	
        enum bound_t { LEFT , RIGHT};    
     
        generic_shmoo(uint8_t iv_addr,shmoo_type_t shmoo_mask,shmoo_algorithm_t shmoo_algorithm);// Constructor
        generic_shmoo(){};
        ~generic_shmoo(){};  // Destructor
        void  init_multi_array(uint32_t (&array)[MAX_DQ][MAX_RPS],uint32_t init_val); //initialize multi dim arrays to known value
	fapi::ReturnCode init_multi_array_dqs(uint32_t (&array)[MAX_DQ][MAX_RPS],uint32_t init_val);
        fapi::ReturnCode get_all_noms(const fapi::Target & i_target); //! Read in all the Nominal values of the relevant knobs
		fapi::ReturnCode set_all_binary(const fapi::Target & i_target,bound_t bound);
		fapi::ReturnCode get_all_noms_dqs(const fapi::Target & i_target); //! Read in all the Nominal values of the relevant knobs
		fapi::ReturnCode get_all_noms_gate(const fapi::Target & i_target); //! Read in all the Nominal values of the relevant knobs
		fapi::ReturnCode get_all_noms_data_disable(const fapi::Target & i_target);
		fapi::ReturnCode put_all_noms_data_disable(const fapi::Target & i_target,uint8_t flag);
		//fapi::ReturnCode put_all_zero_data_disable(const fapi::Target & i_target);
        fapi::ReturnCode find_bound(const fapi::Target & i_target,bound_t); // generic Right bound
        fapi::ReturnCode knob_update(const fapi::Target & i_target,bound_t bound,uint8_t scenario,uint8_t bit,uint8_t pass,bool &flag); // Increment or decrement the knob
		fapi::ReturnCode knob_update_bin(const fapi::Target & i_target,bound_t bound,uint8_t scenario,uint8_t bit,uint8_t pass,bool &flag); 
	fapi::ReturnCode knob_update_gate(const fapi::Target & i_target,bound_t bound,uint8_t scenario,uint8_t pass,bool &flag); // Increment or decrement the knob
	//fapi::ReturnCode knob_update_gate(const fapi::Target & i_target,bound_t bound,uint8_t scenario,uint8_t bit,uint8_t pass,bool &flag); 
	fapi::ReturnCode knob_update_gate_train(const fapi::Target & i_target,bound_t bound,uint8_t scenario,uint8_t pass);
	fapi::ReturnCode knob_update_dqs_by8(const fapi::Target & i_target,bound_t bound,uint8_t scenario,uint8_t bit,uint8_t pass,bool &flag); 
	fapi::ReturnCode knob_update_dqs_by4(const fapi::Target & i_target,bound_t bound,uint8_t scenario,uint8_t bit,uint8_t pass,bool &flag);
        fapi::ReturnCode print_report(const fapi::Target & i_target); // Print Shmoo report to  STDOUT
        fapi::ReturnCode print_report_dqs(const fapi::Target & i_target);
		fapi::ReturnCode print_report_gate(const fapi::Target & i_target);
		//fapi::ReturnCode print_shmoo_parms();
	fapi::ReturnCode get_margin(const fapi::Target & i_target);
	fapi::ReturnCode get_margin_dqs_by8(const fapi::Target & i_target);
	fapi::ReturnCode get_margin_dqs_by4(const fapi::Target & i_target);
	fapi::ReturnCode get_min_margin(const fapi::Target & i_target,uint32_t *o_right_min_margin,uint32_t *o_left_min_margin);
	fapi::ReturnCode get_min_margin_dqs(const fapi::Target & i_target,uint32_t *o_right_min_margin,uint32_t *o_left_min_margin);
        fapi::ReturnCode do_mcbist_test(const fapi::Target & i_target);
		fapi::ReturnCode do_mcbist_reset(const fapi::Target & i_target);
        fapi::ReturnCode  check_error_map(const fapi::Target & i_target,uint8_t port,uint8_t &pass);
        fapi::ReturnCode sanity_check(const fapi::Target & i_target);
		fapi::ReturnCode schmoo_setup_mcb( const fapi::Target & i_target);
		fapi::ReturnCode get_error_cnt(const fapi::Target & i_target,uint8_t port,uint8_t rank,uint8_t rank_pair,uint8_t bit,bound_t bound);
		fapi::ReturnCode knob_update_dqs_by8_isdimm(const fapi::Target & i_target,bound_t bound,uint8_t scenario,uint8_t bit,uint8_t pass,bool &flag); 
	fapi::ReturnCode knob_update_dqs_by4_isdimm(const fapi::Target & i_target,bound_t bound,uint8_t scenario,uint8_t bit,uint8_t pass,bool &flag);
        fapi::ReturnCode run(const fapi::Target & i_target,uint32_t *right_min_margin,uint32_t *left_min_margin,uint32_t i_vref_mul);
	fapi::ReturnCode shmoo_save_rest(const fapi::Target & i_target,uint64_t i_content_array[],uint8_t i_mode);
	
};
#endif
