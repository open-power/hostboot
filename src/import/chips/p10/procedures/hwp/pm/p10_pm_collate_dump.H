/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_collate_dump.H $ */
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
/// @file    p10_pm_collate_dump.H
/// @brief   Loops across all functional procs in the system and consolidates
///          all the chip specific PM Dump data to one system level PM Dump in
///          the input buffer
//
// *HWP HW Owner : Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner : Amit Tendolkar <amit.tendolkar@in.ibm.com>
// *Team         : PM
// *Consumed by  : HB, CRO
// *Level        : 1
//
// EKB-Mirror-To: hostboot

#ifndef __P10_PM_COLLATE_DUMP__
#define __P10_PM_COLLATE_DUMP__

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

static const uint32_t PMDUMP_SZ_BYTES_PER_PROC = 0x10000; // 64 kB

typedef fapi2::ReturnCode (*p10_pm_collate_dump_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>&,
    void*,
    uint32_t&);

// -----------------------------------------------------------------------------
// Function Prototype
// -----------------------------------------------------------------------------
extern "C"
{
///
/// @brief Collates or consolidates PM dump data from each chip region to one
///        system wide PM dump
///
/// @param[in] i_systarget     Top level system target
/// @param[inout] io_pmdumpbuf Pointer to pre-allocated buffer where the system-
///                            wide PM Dump should be consolidated.
/// @param[out] o_pmdumpsz     Actual size of PM dump copied to buffer pointed
///                            by io_pmdumpbuf, in bytes
///
/// @return FAPI2_RC_SUCCESS on success, else error code.
/// @note   HWP expects a pre-allocated contiguous buffer of size (Total procs *
///         PMDUMP_SZ_BYTES_PER_PROC) pointed by io_pmdumpbuf
///
    fapi2::ReturnCode p10_pm_collate_dump (
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_systarget,
        void*     io_pmdumpbuf,
        uint32_t& o_pmdumpsz );

} // extern "C"
#endif // __P10_PM_COLLATE_DUMP__
