/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/io_fir_isolation.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: io_fir_isolation.H,v 1.5 2013/04/15 10:30:45 jaswamin Exp $
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 2012, 2013
// *!           All Rights Reserved -- Property of IBM
// *!                   *** IBM Confidential ***
// *!***************************************************************************
// *! FILENAME             : IO_fir_isolation.H
// *! TITLE                : 
// *! DESCRIPTION          : This procedure provides FFDC data obtained by isolating the errors based on the bit set in the 64 bit register. This can be used to root cause the issue.
// *! CONTEXT              : 
// *!
// *! OWNER  NAME          : Janani Swaminathan         Email: jaswamin@in.ibm.com
// *! BACKUP NAME          : Varkey Varghese            Email: varkey.kv@in.ibm.com      
// *!
// *!***************************************************************************
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|Author: | Date:  | Comment:
// --------|--------|--------|--------------------------------------------------
//   1.5   |jaswamin|13/04/15| Fixed the parameter description in comment.
//   1.4   |jaswamin|13/03/22| Changed it to conform with the FW specifications
//   1.3   |jaswamin|13/03/18| Made it more readable.
//   1.2   |jaswamin|13/03/06| Added cvs tag
//   1.1   |jaswamin|13/02/14| Initial check in
//------------------------------------------------------------------------------

/****************************************************************************************/
/* IO_FIR_ISOLATION.H                                                                           */
/****************************************************************************************/
#ifndef IO_FIR_ISOLATION_H
#define IO_FIR_ISOLATION_H

#include "io_clear_firs.H"

using namespace fapi;
typedef fapi::ReturnCode (*io_fir_isolation_FP_t)(const fapi::Target &target);

extern "C"
{

/**
 * io_fir_isoaltion HWP 
 *
 * target is any IO target P8 MCS,XBUS,Abus or centaur
 * 
 * 
 *
 * 
 */

 //! Function    : io_fir_isolation
 //! Paramteres  : i_target => FAPI target
 //! Returns     : o_rc => return code for function.
 //! Description : Wrapper code that calls the underlying error isolation procedures - to be used by the firmware for sending in target information.
 //!               This function gets target information and the 64 bit flat scom fir register value necessary for gathering FFDC data. 
fapi::ReturnCode io_fir_isolation(const fapi::Target &i_target);


} // extern "C"
#endif

