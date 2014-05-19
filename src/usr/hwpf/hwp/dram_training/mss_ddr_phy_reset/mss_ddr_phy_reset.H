/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_ddr_phy_reset/mss_ddr_phy_reset.H $ */
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
// $Id: mss_ddr_phy_reset.H,v 1.2 2012/03/21 18:12:28 mfred Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_ddr_phy_reset.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_ddr_phy_reset.H
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Mark Fredrickson  Email: mfred@us.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// Header file for mss_ddr_phy_reset.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.1    | mfred  | 11/19/11| Updated

#ifndef MSS_DDR_PHY_RESETHWPB_H_
#define MSS_DDR_PHY_RESETHWPB_H_

#include <fapi.H>

typedef fapi::ReturnCode (*mss_ddr_phy_reset_FP_t)(const fapi::Target& i_target);

extern "C"
{
    // Target is centaur.mba

/**
 * @brief mss_ddr_phy_reset procedure.  The purpose of this procedure is to do a soft reset of the DDR PHY logic and cause the DDR PLLs to lock.
 *
 * @param[in]  i_target  Reference to centaur.mba target
 *
 * @return ReturnCode
 */

    fapi::ReturnCode mss_ddr_phy_reset(const fapi::Target& i_target);
    // Target is centaur.mba

} // extern "C"

#endif // MSS_DDR_PHY_RESETHWPB_H_
