/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_l2_flush.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file p9_l2_flush.H
/// @brief Flush the P9 L2 cache (FAPI)
///
/// *HWP HWP Owner   : Benjamin Gass <bgass@us.ibm.com>
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : Quad
/// *HWP Consumed by : FSP and SBE
/// *HWP Level       : 3
///
///  Procedure Additional Comments:
///
///  High-level procedure flow:
///    o Poll Purge Engine Command Register to confirm that purge engine
///      is idle before starting (fail if self-imposed timeout occurs)
///    o Write Purge Engine Command Register to kick off complete/requested
///      cache flush operation
///    o Poll Purge Engine Command Register to wait for completion of
///      flush (fail if self-imposed timeout occurs) & check for errors
///
///  Successful operations assumes that:
///    o System clocks are running
///    o While not strictly required, to guarantee a completely empty cache
///      at the end of the procedure execution, instructions should be
///      stopped on the core underneath the L2 being flushed before the flush
///      is executed
///

#ifndef _P9_L2_FLUSH_H_
#define _P9_L2_FLUSH_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------
namespace p9core
{

// This structure specifies the data needed in case when there
// is request for specific L2 purges
struct purgeData_t
{
    uint8_t iv_cmdType: 4;
    uint8_t iv_cmdMem: 3;
    uint8_t iv_cmdBank: 1;
    uint8_t iv_cmdCGC: 8;

    purgeData_t(): iv_cmdType(0),
        iv_cmdMem(0),
        iv_cmdBank(0),
        iv_cmdCGC(0) {}
};

} // end of p9core namespace

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------
typedef fapi2::ReturnCode (*p9_l2_flush_FP_t)
(const fapi2::Target < fapi2::TARGET_TYPE_EX >& i_target,
 const p9core::purgeData_t& i_purgeData);

extern "C"
{

///
/// @brief  Utility function to check for a purge operation to be completed.
///         This function polls the EX_PRD_PURGE_CMD_REG_BUSY bit of
///         EX_PRD_PURGE_CMD_REG.
///           - If this bit is clear before the input loop threshold is
///             reached, it returns FAPi2_RC_SUCCESS.
///           - Otherwise, it returns an error code.
///
/// @param[in]  i_target          => EX chiplet target
/// @param[in]  i_busyCount       => Max busy count waiting for PURGE to complete.
/// @param[out] o_prdPurgeCmdReg  => EX_PRD_PURGE_CMD_REG value.
///
/// @return FAPI2_RC_SUCCESS if engine status returns as idle (with no errors)
///         before maximum number of polls has been reached
///         else, return error.
    fapi2::ReturnCode purgeCompleteCheck(
        const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_target,
        const uint64_t i_busyCount,
        fapi2::buffer<uint64_t>& o_prdPurgeCmdReg);

///-----------------------------------------------------------------------------
/// @brief Utility subroutine to setup and trigger a PRD PURGE based
///        on input purge data specification.
///
/// @param[in]  i_target          EX target
/// @param[in]  i_purgeData       Structure having values for MEM, CGC, BANK
///                               passed by the user
/// @param[in]  i_prdPurgeCmdReg  EX_PRD_PURGE_CMD_REG value.
///
/// @return  FAPI2_RC_SUCCESS if purge operation was started,
///          else error code.
///-----------------------------------------------------------------------------
    fapi2::ReturnCode setupAndTriggerPrdPurge(
        const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_target,
        const p9core::purgeData_t& i_purgeData,
        fapi2::buffer<uint64_t>& i_prdPurgeCmdReg);

///
/// @brief Flush entire content of L2 cache via purge engine
/// @param[in] i_target EX target
/// @param[in] i_purgeData Specifies a particular purge type
/// @return: FAPI2_RC_SUCCESS if purge operation completes successfully,
///          P9_L2_FLUSH_PURGE_REQ_OUTSTANDING
///              if called when existing L2 purge is in progress,
///          RC_P9_PURGE_COMPLETE_TIMEOUT
///              if purge operation does not complete in expected time,
///          RC_P9_PURGE_CMD_REG_ERR
///              if purge operation reports error,
///          else FAPI getscom/putscom return code for failing operation
///
    fapi2::ReturnCode p9_l2_flush(
        const fapi2::Target < fapi2::TARGET_TYPE_EX >&   i_target,
        const p9core::purgeData_t& i_purgeData);

} // end of extern C

#endif // _P9_L2_FLUSH_H_
