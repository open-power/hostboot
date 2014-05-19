/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_trainadv/mss_draminit_training_advanced.H $ */
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
// $Id: mss_draminit_training_advanced.H,v 1.17 2014/01/23 17:10:05 sasethur Exp $
/* File is created by SARAVANAN SETHURAMAN on Thur Sept 28 2011. */

//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2007
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE :mss_draminit_training_advanced.H
// *! DESCRIPTION : Tools for centaur procedures
// *! OWNER NAME : SARAVANAN SETHURAMAN         email id: saravanans@in.ibm.com
// *! BACKUP NAME :MARK D BELLOWS		email id: bellows@us.ibm.com
// #! ADDITIONAL COMMENTS :
//
// General purpose funcs

//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author:  |  Date:   | Comment:
//---------|---------- |--------- |-----------------------------------------------
//  1.0    | 28-Sep-11 | sasethur | First drop of Centaur
//  1.1    | 18-Nov-11 | sasethur | Added typedef and comment update
//  1.2    | 13-Feb-12 | sasethur | Updated scom address naming convention
//  1.9    | 16-Jul-12 | bellows  | Added in Id tag
//  1.10   | 15-Oct-12 | sasethur | Updated user option  
//  1.11   | 26-Oct-12 | sasethur | Updated fapi:: and const Target & for HB environment
//  1.12   | 15-Nov-12 | sasethur | Updated fw review comments
//  1.13   | 07-Dec-12 | sasethur | Updated for fw review in comment section
//  1.14   | 10-May-13 | sasethur | Added user input for test type, pattern from wrapper
//  1.15   | 10-May-13 | sasethur | changed uint8_t to uint32_t for test type, pattern
//  1.16   | 08-Aug-13 | sasethur | Removed Pattern and testype
//  1.17   | 17-Jan-14 | mjjones  | RAS Review cleanup

#ifndef _MSS_DRAMINIT_TRAINING_ADVANCED_H
#define _MSS_DRAMINIT_TRAINING_ADVANCED_H

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi.H>

typedef fapi::ReturnCode (*mss_draminit_training_advanced_FP_t)(const fapi::Target &);


extern "C"
{
/**
 * @brief Draminit training advanced procedure shmoo's drv_impedance, slew, vref and receiver impedance and get the optimum value
 *
 * @param[in] i_target Reference to MBA target
 *
 * @return ReturnCode
 */
fapi::ReturnCode mss_draminit_training_advanced(const fapi::Target & i_target_mba);

} // extern C

#endif// _MSS_DRAMINIT_TRAINING_ADVANCED_H 
