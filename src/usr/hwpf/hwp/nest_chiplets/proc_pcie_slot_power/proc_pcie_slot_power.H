/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/proc_pcie_slot_power/proc_pcie_slot_power.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
// $Id: proc_pcie_slot_power.H,v 1.3 2014/07/28 21:40:41 ricmata Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_pcie_slot_power.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
//------------------------------------------------------------------------------
// *! TITLE       : proc_pcie_slot_power.C
// *! DESCRIPTION : Disable/Enable slot power on hot-plug controlled slots.
// *!
// *! OWNER NAME  : Rick Mata         Email: ricmata@us.ibm.com
// */ BACKUP NAME : Rick Mata	      Email: ricmata@us.ibm.com
// *!
// *! ADDITIONAL COMMENTS :
// *!
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//  Version     Date        Owner       Description
//------------------------------------------------------------------------------
//    1.0       7/22/14     ricmata     Initial release: Brazos support only.
//------------------------------------------------------------------------------
#ifndef _PROC_PCIE_SLOT_POWER_H_
#define _PROC_PCIE_SLOT_POWER_H_

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include "fapi.H"

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

const uint32_t I2C_MODE_DATA		   = 0x01760000;
const uint32_t I2C_CMD_DATA_2B		   = 0xD0000002;
const uint32_t I2C_CMD_DATA_1B		   = 0xD0000001;
const uint64_t I2CMS_FIFO1_READ_0x000A0024 = 0x00000000000A0024ULL;
const uint64_t I2CMS_COMMAND_0x000A0025    = 0x00000000000A0025ULL;
const uint64_t I2CMS_MODE_0x000A0026       = 0x00000000000A0026ULL;
const uint64_t I2CMS_STATUS_0x000A002B     = 0x00000000000A002BULL;
const uint64_t I2CMS_EXT_STATUS_0x000A002C = 0x00000000000A002CULL;

//------------------------------------------------------------------------------
// Structure Definition(s)
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode
(*proc_pcie_slot_power_FP_t)(const fapi::Target &i_target, const bool);

extern "C"
{
  /**
  * @brief Disable/enable slot power to hot-plug controlled slots.
  *
  * @param[in] (1) 'i_target' is reference to chip target
  *            (2) 'i_enable_slot_power' is reference to boolean object: True = ON, False = OFF.
  *
  * @return ReturnCode
  *
  *
  */
  fapi::ReturnCode proc_pcie_slot_power(const fapi::Target &i_target, const bool i_enable_slot_power);

} //extern "C"

#endif
