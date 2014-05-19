/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_eff_grouping.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: mss_eff_grouping.H,v 1.8 2014/04/10 18:45:31 jdsloat Exp $
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
//  1.8    | jdsloat  | 04/10/14| Mike Jones's rewrite.  
//  1.7    | gpaulraj | 08/12/13| moved constants to C file
//  1.6    | gpaulraj | 05/22/13| added constants for debugging purpose
//  1.5    | bellows  | 09/25/12| review updates made
//  1.4    | bellows  | 08/31/12| object updated, call updated
//  1.3    | bellows  | 07/27/12| updated for setup_bars full function
//  1.2    | bellows  | 07/16/12| added in Id tag
//  1.1    | gpaulraj | 03/19/12| Updated

#ifndef MSS_EFF_GROUPINGHWPB_H_
#define MSS_EFF_GROUPINGHWPB_H_

#include <fapi.H>

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*mss_eff_grouping_FP_t)(const fapi::Target &,
                                                  std::vector<fapi::Target> &);

extern "C"
{

/**
 * @brief mss_eff_grouping HW Procedure
 *
 * @param[in] i_target              Processor Chip Target
 * @param[in] i_associated_centaurs Memory Buffer Targets associated with the
 *                                  Processor Chip Target
 * @return fapi::ReturnCode
 */
fapi::ReturnCode mss_eff_grouping(const fapi::Target & i_target,
    std::vector<fapi::Target> & i_associated_centaurs);

}

#endif // MSS_EFF_GROUPINGHWPB_H_
