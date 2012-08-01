/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/build_winkle_images/proc_set_pore_bar/proc_pba_slave_config.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */


//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Klaus P. Gungl         Email: kgungl@de.ibm.com
// *!
// *! General Description:
// *!        
// *! include file for proc_pba_slave_config 
// *!
//------------------------------------------------------------------------------
// 


// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*proc_pba_slave_config_FP_t) (const fapi::Target&, int, int, uint64_t);


extern "C" 
{



typedef struct {
    unsigned  enable:1;
    unsigned  mid_match_value:2;
    unsigned  Reserved1:1;
    unsigned  mid_care_mask:3;
    unsigned  write_ttype:3;
    unsigned  Reserved2: 1;
    unsigned  read_ttype:1;
    unsigned  read_prefetch_ctl:2;
    unsigned  buf_invalidate_ctl:8;
    unsigned  buf_alloc_w:1;
    unsigned  buf_alloc_a:1;
    unsigned  buf_alloc_b:1;
    unsigned  buf_alloc_c:1;
    unsigned  Reserved3:1;
    unsigned  dis_write_gather:1;
    unsigned  wr_gather_timeout:3;
    unsigned  write_tsize: 7;
    unsigned  extaddr: 14;
    unsigned  Reserved4: 2;
    unsigned  Reserved5: 13;
} pba_slvctl_reg_type;

typedef union {
  pba_slvctl_reg_type fields;
  uint64_t value;
} slvcntl_reg_type;



  // ReturnCode proc_pba_slave_config (Target i_target, 
  // 				proc_mode_type proc_mode, 
  // 				int index, 
  // 		     		struct_pba_bar_msk_scope_init_type* ps_pba_init
  // 				// pba_slvctl_type pba_slvctl_init
  // 				);

fapi::ReturnCode 
proc_pba_slave_config (const fapi::Target& i_target, 
                       int proc_mode, 
		               int index, 
		               uint64_t pba_slvctl_init);
}


