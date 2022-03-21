/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_dump.C $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
/// @file    p10_pm_dump.C
/// @brief   Collects PM Display HW Registers and PM Engines microcode FFDC data
///          into a chip level PM Dump Structure in a region in mainstore memory
//
// *HWP HW Owner : Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner : Amit Tendolkar <amit.tendolkar@in.ibm.com>
// *Team         : PM
// *Consumed by  : HB, CRO
// *Level        : 1
//
// EKB-Mirror-To: hostboot

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_pm_dump.H>

// -----------------------------------------------------------------------------
// Procedure
// -----------------------------------------------------------------------------
fapi2::ReturnCode
p10_pm_dump (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    void* io_buffer )
{
    return fapi2::current_err;
}
