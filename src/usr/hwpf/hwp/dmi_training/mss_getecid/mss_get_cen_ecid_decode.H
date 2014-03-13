/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dmi_training/mss_getecid/mss_get_cen_ecid_decode.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: mss_get_cen_ecid_decode.H,v 1.4 2014/02/19 13:41:32 bellows Exp $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2013
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : mss_get_cen_ecid_decode.H
// *! DESCRIPTION : Decode the ECID into a string
// *!
// *! OWNER NAME  : Mark Bellows Email: bellows@us.ibm.com
// *! Copied From : Joe McGill's proc_cleanup code 
// *!
// *! ADDITIONAL COMMENTS:
// *!
// *!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.4   | bellows  |19-FEB-14| RAS Review Updates
//   1.3   | bellows  |02-OCT-13| Minor Review Comments addressed
//   1.2   | bellows  |24-SEP-13| Fixed typo
//   1.1   | bellows  |17-SEP-13| Original Program

#ifndef _MSS_GET_CEN_ECID_DECODE_H_
#define _MSS_GET_CEN_ECID_DECODE_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi.H>
#include <mss_get_cen_ecid.H>



// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode
(*mss_get_cen_ecid_decode_FP_t)(uint8_t & i_ddr_port_status, uint8_t & i_cache_enable,      uint8_t & i_centaur_sub_revision, ecid_user_struct & i_user_data, char *o_display_string
                         );

const int MSS_GET_CEN_ECID_DECODE_STRING_LENGTH=1000;

//void decode_base_code(uint64_t ecid[2], uint8_t ddr_port, uint8_t cache_enable_o, uint8_t centaur_sub_revision_o, uint8_t o_nwell_misplacement, uint8_t o_bluewaterfall_broken, uint8_t user_defined, uint8_t psro, uint8_t i_ec );
//ReturnCode get_ecid_char(uint8_t c, char *creturn);
//void get_ecid_checksum(char ECID[12]);

enum user_flags {
  USER_INPUT_ECID = 1,
  CSV = 2,
  COMMENT = 4,
};

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

// function: FAPI mss_get_cen_ecid_decode HWP entry point
// parameters:
//             &o_ddr_port_status => indicates if the MBA's are bad, with MBA 1 being the rightmost bit and MBA 0 being the next to right most bit
//             &o_cache_enable => what it would have set the cache enable attribute to if it sets attributes
//             &o_centaur_sub_revision => the sub revision indicator between DD1.0 and DD1.01
//             &o_user_data => holder for additional information for printing
//             &o_display_string -> output string- max of MSS_GET_CEN_ECID_DECODE_STRING_LENGTH length  
// returns: FAPI_RC_SUCCESS if FBC stop is deasserted at end of execution
//          else FAPI return code for failing operation
  fapi::ReturnCode mss_get_cen_ecid_decode(
                                    uint8_t & i_ddr_port_status,
                                    uint8_t & i_cache_enable,
                                    uint8_t & i_centaur_sub_revision,
                                    ecid_user_struct & i_user_data,
                                    char * o_display_string

                                    );
  fapi::ReturnCode get_ecid_char(uint8_t c, char *creturn); // print helping function
  void get_ecid_checksum(char ECID[13]);

} // extern "C"

#endif // _MSS_GET_CEN_ECID_DECODE_H_
