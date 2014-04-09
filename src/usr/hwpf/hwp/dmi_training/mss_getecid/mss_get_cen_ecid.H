/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dmi_training/mss_getecid/mss_get_cen_ecid.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: mss_get_cen_ecid.H,v 1.12 2014/03/25 21:09:09 uid157495 Exp $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : mss_get_cen_ecid.H
// *! DESCRIPTION : Get ECID string from target using SCOM's
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
//   1.11  | sglancy  |25-MAR-14| Minor Review Comments addressed
//   1.10  | bellows  |02-OCT-13| Minor Review Comments addressed
//   1.9   | bellows  |17-SEP-13| Allow for external wrapper parsing
//   1.8   | bellows  |26-MAR-13| Reviewer found updates
//   1.7   | bellows  |22-MAR-13| Changed commented name of ECID Attribute per Firmware request
//   1.6   | bellows  |21-JAN-13| added in sub revision reader
//   1.5   | bellows  |15-JAN-13| moved Cache Enable Information to the caller
// 1.1-1.4 | various  |07-DEC-12| Original Program

#ifndef _MSS_GET_CEN_ECID_H_
#define _MSS_GET_CEN_ECID_H_


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi.H>
#include <cen_scom_addresses.H>

//defines enumerators
enum mss_get_cen_ecid_ddr_status
{
  MSS_GET_CEN_ECID_DDR_STATUS_ALL_GOOD = 0,
  MSS_GET_CEN_ECID_DDR_STATUS_MBA1_BAD = 1,
  MSS_GET_CEN_ECID_DDR_STATUS_MBA0_BAD = 2,
  MSS_GET_CEN_ECID_DDR_STATUS_ALL_BAD = 3,
};

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------
class  ecid_user_struct {
public:
  uint8_t  valid;
  uint8_t  i_checkL4CacheEnableUnknown;
  uint8_t  i_ecidContainsPortLogicBadIndication;
  uint8_t  i_user_defined;
  uint8_t  io_ec;
  uint64_t io_ecid[2];
  uint8_t  o_psro;
  uint8_t  o_bluewaterfall_broken;
  uint8_t  o_nwell_misplacement;

  ecid_user_struct();
};

inline   ecid_user_struct::ecid_user_struct() { valid=0; i_checkL4CacheEnableUnknown=0; i_ecidContainsPortLogicBadIndication=0; i_user_defined=0; io_ec=0; io_ecid[0]=0; io_ecid[1]=0;  }


// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode
(*mss_get_cen_ecid_FP_t)(const fapi::Target& i_target, uint8_t & o_ddr_port_status, uint8_t & o_cache_enable,      uint8_t & o_centaur_sub_revision, ecid_user_struct & user_data

                         );


//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

// function: FAPI mss_get_cen_ecid HWP entry point
// parameters: i_target => cen chip target
//             &o_ddr_port_status => indicates if the MBA's are bad, with MBA 1 being the rightmost bit and MBA 0 being the next to right most bit
//             &o_cache_enable => what it would have set the cache enable attribute to if it sets attributes
//             &o_centaur_sub_revision => the sub revision indicator between DD1.0 and DD1.01
// returns: FAPI_RC_SUCCESS if FBC stop is deasserted at end of execution
//          else FAPI return code for failing operation
// Updates attributes: ATTR_ECID[2] -> bits 1-64 and 65-128 of the ECID
//                     ATTR_MSS_PSRO -> average PSRO from 85C wafer test
//                     ATTR_MSS_NWELL_MISPLACEMENT -> indicates if nwell defect in hardware
  fapi::ReturnCode mss_get_cen_ecid(
                                    const fapi::Target& i_target,
                                    uint8_t & o_ddr_port_status,
                                    uint8_t & o_cache_enable,
                                    uint8_t & o_centaur_sub_revision,
                                    ecid_user_struct & user_data

                                    );

  fapi::ReturnCode mss_parse_ecid(
                                  uint64_t ecid[2], // input ECID in bit order
                                  const uint8_t l_checkL4CacheEnableUnknown, // input L4CacheEnableUnknown is possible
                                  const uint8_t l_ecidContainsPortLogicBadIndication, // input logic can be bad
                                  const uint8_t ec, // input ec of chip
                                  uint8_t & ddr_port, //output ddr ports are non functional
                                  uint8_t & cache_enable_o, // output cache is functional or not
                                  uint8_t & centaur_sub_revision_o, // output sub revsion number
                                  uint8_t & o_psro, // output psro
                                  uint8_t & o_bluewaterfall_broken, // output blue waterfall broken
                                  uint8_t & o_nwell_misplacement   // output nwell misplacement
                                  );



} // extern "C"

#endif // _MSS_GET_CEN_ECID_H_
