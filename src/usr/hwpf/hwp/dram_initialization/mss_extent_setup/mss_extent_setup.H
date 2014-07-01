/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/mss_extent_setup/mss_extent_setup.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
// $Id: mss_extent_setup.H,v 1.8 2012/07/17 13:22:51 bellows Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_extent_setup.H
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : girisankar paulraj     Email: gpaulraj@in.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// Header file for mss_extent_setup.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.8    | bellows  |16-Jul-12| added in Id tag
//  1.7    | bellows  |15-Jun-12| Updated for Firmware
//   1.2   |          |         |
//   1.1   | gpaulraj |11-NOV-11| First Draft.

#ifndef MSS_EXTENT_SETUP_H_
#define MSS_EXTENT_SETUP_H_

#include <fapi.H>

typedef fapi::ReturnCode (*mss_extent_setup_FP_t)();

extern "C"
{

/**
 * @brief extent setup  procedure -- currently an open shell until extent functions are found t obe needed 
 *
 *
 * @return ReturnCode
 */

fapi::ReturnCode mss_extent_setup();

} // extern "C"

#endif // MSS_EXTENT_SETUP_H_
