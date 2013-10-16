/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit/mss_ddr4_funcs.H $ */
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
// $Id: mss_ddr4_funcs.H,v 1.3 2013/10/10 20:28:25 bellows Exp $

//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2013
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE : mss_ddr4_funcs.H
// *! DESCRIPTION : Tools for DDR4 DIMMs centaur procedures
// *! OWNER NAME : jdsloat@us.ibm.com
// *! BACKUP NAME : sglancy@us.ibm.com
// #! ADDITIONAL COMMENTS :
//

//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//         |          |         |
//  1.3    | 10/10/13 | bellows | Added required CVS Id comment
//  1.2    | 10/09/13 | jdsloat | Fixed argument list in function call
//  1.1    | 10/04/13 | jdsloat | First revision

#ifndef _MSS_DDR4_FUNCS_H
#define _MSS_DDR4_FUNCS_H


//----------------------------------------------------------------------
// DDR4 FUNCS
//----------------------------------------------------------------------


//--------------------------------------------------------------
// mss_mrs_load_ddr4
// Set MRS1 settings for Rank 0 and Rank 1
// Target = centaur.mba
//--------------------------------------------------------------
fapi::ReturnCode mss_mrs_load_ddr4( fapi::Target& i_target,
                                      uint32_t i_port_number,
                                      uint32_t& io_ccs_inst_cnt);



#endif /* _MSS_DDR4_FUNCS_H */


