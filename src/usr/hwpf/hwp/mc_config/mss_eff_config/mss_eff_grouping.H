/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_eff_grouping.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
// $Id: mss_eff_grouping.H,v 1.5 2012/09/25 16:22:25 bellows Exp $
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
//  1.5    | bellows  | 09/25/12| review updates made
//  1.4    | bellows  | 08/31/12| object updated, call updated
//  1.3    | bellows  | 07/27/12| updated for setup_bars full function
//  1.2    | bellows  | 07/16/12| added in Id tag
//  1.1    | gpaulraj | 03/19/12| Updated

#ifndef MSS_EFF_GROUPINGHWPB_H_
#define MSS_EFF_GROUPINGHWPB_H_


#include <fapi.H>

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

typedef fapi::ReturnCode (*mss_eff_grouping_FP_t)(const fapi::Target&, std::vector<fapi::Target> & i_associated_centaurs );

extern "C"
{

fapi::ReturnCode mss_eff_grouping(const fapi::Target & i_target,std::vector<fapi::Target> & i_associated_centaurs);



} // extern "C"

#endif // MSS_EFF_GROUPINGHWPB_H_
