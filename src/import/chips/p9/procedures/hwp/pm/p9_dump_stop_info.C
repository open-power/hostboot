/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_dump_stop_info.C $   */
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
/// @file p9_dump_stop_info.C
/// @brief Dump the state of STOP processing hardware (including relevant PPEs)
///        for first failure capture debug.
///
//  *HWP HWP Owner: Amit Kumar <akumar3@us.ibm.com>
//  *HWP FW Owner: Prem Jha <premjha1@in.ibm.com>
//  *HWP Team: PM
//  *HWP Level: 1
//  *HWP Consumed by: FSP:HS
///
/// @verbatim
/// High-level procedure flow:
///
///      set bool to enable FAPI_ERR output
///      clear bool to enable Error Logging (likely to come in a second phase)
///      Read control attributes to adjust above control vars
///         -- functions below would honor these controls as to what is output
///
///      for each CME
///          check (and log) CME operational state
///          call p9_ppe_state (CME address, HALT) to extract PPE core state
///          call p9_intr_regs (CME address) to extract CME interrupts
///          call p9_mib_state (CME address) to extract CME memory interface state
///          call p9_cme_regs (CME address) to extract CME SCOMs (including CME FIR)
///
///      for each CORE
///          log STOP History register
///          log Special Wakeup registers (FSP, OCC, HYP, OTR)
///          log Core PPM Error Summary register
///          log NetCntl0 register
///          log PFETCNTLSTAT register
///
///      for each EQ
///          log STOP History register
///          log Quad Chiplet Control register
///
///      // Chip content - SGPE and OCB functions
///      call p9_ppe_state (SGPE address, HALT) to extract PPE core state
///      call p9_mib_state (SGPE address) to extract SGPOE memory interface state
///      call p9_gpe_regs (SGPE address) to extract SGPE SCOMs
///      log OCC LFIR
///      log OCC Flags
///      log OISR0,1
///      log OIMR0,1
///      log OPIT2C* to gather STOP transtion interrupts
///
///      Extract SGPE PK trace
///
///
/// Procedure Prereq:
///    - System clocks are running
/// @endverbatim
///
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------

#include <p9_dump_stop_info.H>

// ----------------------------------------------------------------------
// Procedure Function
// ----------------------------------------------------------------------

/// @brief Dump the state of STOP processing hardware (including relevant PPEs)
///        for first failure capture debug.

fapi2::ReturnCode p9_dump_stop_info(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_INF("> p9_dump_stop_info...");


    FAPI_INF("< p9_dump_stop_info...");

    return fapi2::FAPI2_RC_SUCCESS;
}
