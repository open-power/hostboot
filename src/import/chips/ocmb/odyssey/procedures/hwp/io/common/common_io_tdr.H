/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/common/common_io_tdr.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
// EKB-Mirror-To: hostboot
///
/// @file common_io_tdr.H
/// @brief TDR Functions
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Josh Chica <Josh.Chica@ibm.com>
/// *HW FW Maintainer:
/// *HW Consumed by  : SBE
///-----------------------------------------------------------------------------

#include <fapi2.H>

#define GENERIC_FAPI_IO_TARGET fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP|fapi2::TARGET_TYPE_OMI>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------
enum TdrResult
{
    None = 0x0000,
    Good = 0x0010,
    Open = 0x0020,
    Short = 0x0030,
    ShortToGnd = 0x0001 | Short,
    ShortToVdd = 0x0002 | Short,
    DidNotRun = 0x2000,
    NotSupported = 0x4000,
    UnableToDetermine = 0x8000
};

enum TdrRegisters
{
    tx_cntl3_pl = 0x088,
    tx_ctl_cntl4_pg = 0x18B,
    tx_ctl_cntl5_pg = 0x18C,
    tx_ctl_cntl6_pg = 0x18D,
    tx_stat1_pl = 0x0A4,
    tx_ctl_mode1_pg = 0x181
};

struct TdrStruct
{
    uint32_t iv_lane;
    TdrResult iv_status;
    uint32_t iv_length;
};

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*common_io_tdr_FP_t)(
    const GENERIC_FAPI_IO_TARGET&,
    const uint64_t,
    const uint32_t,
    const uint32_t,
    const uint32_t,
    TdrResult&,
    uint32_t&);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------
extern "C"
{
    /// @brief Use TDR to check for net opens and shorts
    /// @param[in] i_iolink_target      IOLINK target to get thread id for
    /// @param[in] i_lanes              Lanes to run TDR on
    /// @param[out] o_status            Status of the net (Open, Short, Good)
    /// @param[out] o_length_mm         Length from TX to open (in mm)
    /// @return FAPI_RC_SUCCESS if arguments are valid
    fapi2::ReturnCode common_io_tdr(
        const GENERIC_FAPI_IO_TARGET& i_target,
        const uint64_t i_baseAddr,
        const uint32_t i_group,
        const uint32_t i_lane,
        const uint32_t i_freq,
        TdrResult& o_status,
        uint32_t& o_length_ps);

} // extern "C"
