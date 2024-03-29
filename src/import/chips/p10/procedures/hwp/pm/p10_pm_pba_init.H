/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_pba_init.H $    */
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
/// @file: p10_pm_pba_init.H
/// @brief: Initialize PBA registers for modes PM_INIT, PM_RESET
///
// *HWP HWP Owner           :   Greg Still  <stillgs@us.ibm.com>
// *HWP FW  Owner           :   Prem S Jha <premjha2@in.ibm.com>
// *HWP Team                :   PM
// *HWP Level               :   3
// *HWP Consumed by         :   HS


#ifndef _P10_PBAINIT_H_
#define _P10_PBAINIT_H_

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <fapi2.H>
#include <p10_pm.H>

// ----------------------------------------------------------------------
// Constant Defintions
// ----------------------------------------------------------------------
namespace p10pba
{
// BCDE and BCUE Status registers bits
enum PBA_BC_STAT
{
    PBA_BC_STAT_RUNNING = 0
};

// Valid command scope.
enum CMD_SCOPE
{
    LOCAL_NODAL    = 0x00,
    NEAR_NODE      = 0x02,
    GROUP          = 0x03,
    REMOTE_NODE    = 0x04,
    VECTORED_GROUP = 0x05
};

// Maximum number of Polls for PBA slave reset
enum PBA_SLAVE_POLL
{
    MAX_PBA_RESET_POLLS = 16 , // in microseconds
    PBA_RESET_POLL_DELAY = 1
};

// Maximum number of Polls for PBA Block Copy Stopping - 500ms timeout
enum PBA_BLOCK_COPY_POLL
{
    MAX_PBA_BC_STOP_POLLS = 256 ,        // in microseconds
};

const uint64_t PBA_SLVRESETs[4] =
{
    0x8000000000000000ull,
    0xA000000000000000ull,
    0xC000000000000000ull,
    0xE000000000000000ull
};

// structure of values for cmd_scope, pba and pbabar initialization
struct pba_cmd_init
{
    CMD_SCOPE cmd_scope;
    uint64_t  addr;
    uint64_t  size;
};
} //namespace

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_pm_pba_init_FP_t)
(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
 const pm::PM_FLOW_MODE);

extern "C" {

// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------

///
/// @brief Set the pba registers depending on "mode"
///
/// @param[in] i_target Chip target
/// @param[in] i_mode   Mode
///
/// @return FAPI2_RC_SUCCESS on success or error return code
///
    fapi2::ReturnCode p10_pm_pba_init
    (const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
     const pm::PM_FLOW_MODE i_mode);
}

#endif // _P10_PBAINIT_H_
