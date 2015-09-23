/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
///
/// @file p9_pm.H
/// @brief Common header for Power Manangement procedures
///

// *HWP HWP Owner       : Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Bilicon Patil <bilpatil@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 1
// *HWP Consumed by     : HS

#ifndef _P9_PM_H_
#define _P9_PM_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#if 0 // Use appropriate scom address file
    #include <abc_scom_addresses.H>
#endif

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
namespace p9pm
{

enum PM_FLOW_MODE
{
    PM_RESET        = 0x1,
    PM_INIT         = 0x2,
    PM_SETUP        = 0x3,
    PM_SETUP_PIB    = 0x4,
    PM_SETUP_ALL    = 0x5,
    PM_RESET_SOFT   = 0x6,
    PM_INIT_SOFT    = 0x7,
    PM_INIT_SPECIAL = 0x8,
};

} // end of namespace p9pm

#endif // _P9_PM_H_
