/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_lrdimm_funcs/mss_lrdimm_funcs.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
// $Id: mss_lrdimm_funcs.H,v 1.2 2013/09/16 13:28:55 bellows Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2013
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE : mss_lrdimm_funcs.H
// *! DESCRIPTION : Tools for lrdimm centaur procedures
// *! OWNER NAME : KCOOK
// *! BACKUP NAME : MWUU
// #! ADDITIONAL COMMENTS :
//
// CCS related and general utility functions.

//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.2    | 09/16/13 | bellows | Added ID tag
//  1.1    | 08/27/13 | kcook   | First drop of Centaur

#ifndef _MSS_LRDIMM_FUNCS_H
#define _MSS_LRDIMM_FUNCS_H

//#define LRDIMM 1

//----------------------------------------------------------------------
//  Constants 
//----------------------------------------------------------------------
const uint8_t PORT = 2;
const uint8_t DIMM = 2;
const uint8_t RANK = 4;
//----------------------------------------------------------------------
//  Enums 
//----------------------------------------------------------------------

struct mss_lrdimm_spd_data 
{
    uint8_t lr_addr_mirroring[PORT][DIMM];
    uint8_t lr_f0rc3_f0rc2[PORT][DIMM];
    uint8_t lr_f0rc5_f0rc4[PORT][DIMM];
    uint8_t lr_f1rc11_f1rc8[PORT][DIMM];
    uint8_t lr_f1rc13_f1rc12[PORT][DIMM];
    uint8_t lr_f1rc15_f1rc14[PORT][DIMM];
    uint8_t lr_f3rc9_f3rc8_for_800_1066[PORT][DIMM];
    uint8_t lr_f34rc11_f34rc10_for_800_1066[PORT][DIMM];
    uint8_t lr_f56rc11_f56rc10_for_800_1066[PORT][DIMM];
    uint8_t lr_f78rc11_f78rc10_for_800_1066[PORT][DIMM];
    uint8_t lr_f910rc11_f910rc10_for_800_1066[PORT][DIMM];
    uint8_t lr_mr12_for_800_1066[PORT][DIMM];
    uint8_t lr_f3rc9_f3rc8_for_1333_1600[PORT][DIMM];
    uint8_t lr_f34rc11_f34rc10_for_1333_1600[PORT][DIMM];
    uint8_t lr_f56rc11_f56rc10_for_1333_1600[PORT][DIMM];
    uint8_t lr_f78rc11_f78rc10_for_1333_1600[PORT][DIMM];
    uint8_t lr_f910rc11_f910rc10_for_1333_1600[PORT][DIMM];
    uint8_t lr_mr12_for_1333_1600[PORT][DIMM];
    uint8_t lr_f3rc9_f3rc8_for_1866_2133[PORT][DIMM];
    uint8_t lr_f34rc11_f34rc10_for_1866_2133[PORT][DIMM];
    uint8_t lr_f56rc11_f56rc10_for_1866_2133[PORT][DIMM];
    uint8_t lr_f78rc11_f78rc10_for_1866_2133[PORT][DIMM];
    uint8_t lr_f910rc11_f910rc10_for_1866_2133[PORT][DIMM];
    uint8_t lr_mr12_for_1866_2133[PORT][DIMM];
};


//----------------------------------------------------------------------
// LRDIMM FUNCS
//----------------------------------------------------------------------

//--------------------------------------------------------------
// mss_lrimm_rcd_load
// Set Function 1-13 RCD words
// Target = centaur.mba
//--------------------------------------------------------------
fapi::ReturnCode mss_lrdimm_rcd_load( fapi::Target& i_target, 
                                      uint32_t port_number,
                                      uint32_t& ccs_inst_cnt );

//--------------------------------------------------------------
// mss_lrdimm_mrs_load
// Set MRS1 settings for Rank 0 and Rank 1
// Target = centaur.mba
//--------------------------------------------------------------
fapi::ReturnCode mss_lrdimm_mrs_load( fapi::Target& i_target,
                                      uint32_t i_port_number,
                                      uint32_t dimm_number,
                                      uint32_t& io_ccs_inst_cnt);
//--------------------------------------------------------------
// mss_execute_lrdimm_mb_dram_training
// run lrdimm memory buffer training
// Target = centaur.mba
//--------------------------------------------------------------
fapi::ReturnCode mss_execute_lrdimm_mb_dram_training( fapi::Target& i_target); 

//--------------------------------------------------------------
// mss_lrdimm_eff_config
// run lrdimm attribute set up
// Target = centaur.mba
//--------------------------------------------------------------
fapi::ReturnCode mss_lrdimm_eff_config( const fapi::Target& i_target_mba,
                                  uint8_t cur_dimm_spd_valid_u8array[PORT][DIMM],
                                  uint32_t mss_freq,
                                  uint8_t eff_num_ranks_per_dimm[PORT][DIMM]);

//--------------------------------------------------------------
// mss_lrdimm_rewrite_odt
// eff config termination rewrite odts for dual drop
// Target = centaur.mba
//--------------------------------------------------------------
fapi::ReturnCode mss_lrdimm_rewrite_odt( const fapi::Target& i_target_mba,
                                         uint32_t *p_b_var_array,
                                         uint32_t *var_array_p_array[5]);


//--------------------------------------------------------------
// mss_lrdimm_term_atts  
// eff config termination rewrite odts for dual drop
// Target = centaur.mba
//--------------------------------------------------------------
fapi::ReturnCode mss_lrdimm_term_atts( const fapi::Target& i_target_mba);



//-----------------------------------------
// mss_spec_rcd_load
// execute RCD loads of specific control words. For LRDIMM.
// Target = centaur.mba
//-----------------------------------------
fapi::ReturnCode mss_spec_rcd_load(fapi::Target& i_target,
                                   uint32_t i_port_number,
                                   uint8_t * p_i_rcd_num_arr,
                                   uint8_t i_rcd_num_arr_length,
                                   uint64_t  i_rcd_word[],
                                   uint32_t& io_ccs_inst_cnt,
                                   uint8_t i_keep_cke_high=0);



#endif /* _MSS_LRDIMM_FUNCS_H */

