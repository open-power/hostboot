/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_eff_grouping.H $ */
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
// $Id: mss_eff_grouping.H,v 1.7 2013/08/12 16:29:18 gpaulraj Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_eff_grouping.H
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Girisankar Paulraj     Email: gpaulraj@in.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// Header file for mss_eff_grouping
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.7    | gpaulraj | 08/12/13| moved constants to C file
//  1.6    | gpaulraj | 05/22/13| added constants for debugging purpose
//  1.5    | bellows  | 09/25/12| review updates made
//  1.4    | bellows  | 08/31/12| object updated, call updated
//  1.3    | bellows  | 07/27/12| updated for setup_bars full function
//  1.2    | bellows  | 07/16/12| added in Id tag
//  1.1    | gpaulraj | 03/19/12| Updated


#ifndef MSS_EFF_GROUPINGHWPB_H_
#define MSS_EFF_GROUPINGHWPB_H_
//------------------------------------------------------------------------------
//  Header file include Constant definitions
//------------------------------------------------------------------------------

#include <fapi.H>

//------------------------------------------------------------------------------
//  Constant definitions
//------------------------------------------------------------------------------

//const uint8_t MCS_SIZE         = 0;
//const uint8_t MCS_IN_GROUP     = 1;
//const uint8_t GROUP_SIZE       = 2;
///const uint8_t BASE_ADDR        = 3;
//const uint8_t MEMBERS_START_ID = 4;
//const uint8_t MEMBERS_END      = 11;
//const uint8_t ALT_VALID        = 12;
//const uint8_t ALT_SIZE         = 13;
//const uint8_t ALT_BASE_ADDR    = 14;
//const uint8_t LARGEST_MBA_SIZE = 15;

//------------------------------------------------------------------------------
// Class declaration
//------------------------------------------------------------------------------


class target_vector {
   public: std::vector<fapi::Target> t;
};

const int MBA_SIZE_MCS=8;
const int MBA_SIZE_PORT=2;
const int MBA_GROUP_SIZE=16;
const int MBA_GROUP_DATA=16;

class Eff_Grouping_Data {
public:
  uint8_t MBA_size[MBA_SIZE_MCS][MBA_SIZE_PORT]; // mcs, mba pairs, port, dimm
  uint32_t groupID[MBA_GROUP_SIZE][MBA_GROUP_DATA];
  uint32_t MCS_size[MBA_SIZE_MCS];
};

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

typedef fapi::ReturnCode (*mss_eff_grouping_FP_t)(const fapi::Target&, std::vector<fapi::Target> & i_associated_centaurs );

extern "C"
{

fapi::ReturnCode mss_eff_grouping(const fapi::Target & i_target,std::vector<fapi::Target> & i_associated_centaurs);



} // extern "C"

#endif // MSS_EFF_GROUPINGHWPB_H_
