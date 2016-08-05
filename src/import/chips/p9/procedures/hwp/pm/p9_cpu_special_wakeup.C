/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_cpu_special_wakeup.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
///  @file          :     p9_cpu_special_wakeup.C
///  @brief         :     HWP to perform special wakeup of core, EQ or EX.

// *HWP HW Owner    :    Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner    :    Prem S Jha <premjha2@in.ibm.com>
// *HWP Team        :    PM
// *HWP Level       :    1
// *HWP Consumed by :    OCC:FSP:HOST

// ---------------------------------------------------------------------
// Includes
// ---------------------------------------------------------------------
#include <p9_cpu_special_wakeup.H>

using namespace p9specialWakeup;
enum
{
    NUM_SPCWKUP_ENTITIES = 4,
    NUM_SPCWKUP_OPS = 3,
};

fapi2::ReturnCode
p9_cpu_special_wakeup(  const FAPI2_WAKEUP_CHIPLET& i_chipletTarget,
                        const PROC_SPCWKUP_OPS i_operation,
                        const PROC_SPCWKUP_ENTITY i_entity )
{
    FAPI_DBG("Entering p9_cpu_special_wakeup");

    FAPI_DBG("Exit p9_cpu_special_wakeup" );
    return fapi2::FAPI2_RC_SUCCESS;
}
