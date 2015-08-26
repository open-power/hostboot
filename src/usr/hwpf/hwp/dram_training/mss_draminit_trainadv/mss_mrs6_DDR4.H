/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_trainadv/mss_mrs6_DDR4.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
// $Id: mss_mrs6_DDR4.H,v 1.2 2015/08/04 18:47:26 sglancy Exp $
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998, 2013
// *!           All Rights Reserved -- Property of IBM
// *!                   ***  ***
// *!***************************************************************************
// *! FILENAME             :  mss_mrs6_DDR4.H
// *! TITLE                : 
// *! DESCRIPTION          : MRS6 setting procedures
// *! CONTEXT              : 
// *!
// *! OWNER  NAME          : 
// *! BACKUP               : 
// *!***************************************************************************
// CHANGE HISTORY:
//-------------------------------------------------------------------------------
// Version:|Author: 	| Date:   | Comment:
//  1.2    | sglancy    | 08/04/15| Changed to address FW comments
//  1.1    | abhijsau   | 06/27/14| Initial Version
// --------|--------|---------|--------------------------------------------------
//------------------------------------------------------------------------------
#ifndef MSS_MR6_DDR4_H
#define MSS_MR6_DDR4_H


/****************************************************************************************/
/* mss_mcbist_address.H                                                                           */
/****************************************************************************************/
#include <fapi.H>

typedef fapi::ReturnCode (*mss_mrs6_DDR4_FP_t)(const fapi::Target& i_target);

extern "C"
{

using namespace fapi;
/**
 * @sets up and runs Mode Register Set 6 on a centaur.mba level target
 *
 * @param[in]  target:  Reference to centaur.mba target, 
 *
 * @return ReturnCode
 */

fapi::ReturnCode mss_mrs6_DDR4(fapi::Target& i_target);
/**
 * @Adds a no-op (NOP) command to the CCS array
 *
 * @param[in]  target:  Reference to centaur.mba target, 
 * @param[in]  addr_16: 16 wide ecmdDataBufferBase to be used for the address bus
 * @param[in]  instruction_number: current location in the CCS array
 * @param[in]  rank: current rank
 * @param[in]  bank: current bank
 * @param[in]  delay: delay to add for the command
 * @param[in]  port: current port to execute the NOP on
 *
 * @return ReturnCode
 */
fapi::ReturnCode add_nop_to_ccs(fapi::Target& i_target_mba, ecmdDataBufferBase &addr_16, uint32_t instruction_number,uint8_t rank,uint8_t bank,uint32_t delay,uint8_t port);
/**
 * @Loads in MRS6 for a given port number
 *
 * @param[in]  target:  Reference to centaur.mba target, 
 * @param[in]  i_port:  Current port to operate on
 * @param[in/out]  io_ccs_inst_cnt:  Reference to current CCS array position
 *
 * @return ReturnCode
 */
fapi::ReturnCode mss_mr6_loader(fapi::Target& i_target,uint32_t i_port_number,uint32_t& io_ccs_inst_cnt);
} // extern "C"

#endif // MSS_MR6_DDR4_H



