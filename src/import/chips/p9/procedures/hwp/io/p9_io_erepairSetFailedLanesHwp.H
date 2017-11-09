/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_erepairSetFailedLanesHwp.H $ */
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
/// @file p9_io_erepairSetFailedLanesHwp.H
/// @brief FW Team HWP that accesses the fail lanes of Fabric and Memory buses.
///
//----------------------------------------------------------------------------
// *HWP HWP Owner       : Chris Steffen <cwsteffen@us.ibm.com>
// *HWP HWP Backup Owner: Gary Peterson <garyp@us.ibm.com>
// *HWP FW Owner        : Sumit Kumar <sumit_kumar@in.ibm.com>
// *HWP Team            : IO
// *HWP Level           : 2
// *HWP Consumed by     : FSP:HB
//----------------------------------------------------------------------------

#ifndef P9_IO_EREPAIRSETFAILEDLANESHWP_H_
#define P9_IO_EREPAIRSETFAILEDLANESHWP_H_

#include <fapi2.H>
#include <p9_io_erepairConsts.H>

template<fapi2::TargetType K>
using p9_io_erepairSetFailedLanesHwp_FP_t = fapi2::ReturnCode (*)(
            const fapi2::Target < K >&         i_target,
            EREPAIR::erepairVpdType            i_vpdType,
            const uint8_t                      i_clkGroup,
            const std::vector<uint8_t>&        i_txFailLanes,
            const std::vector<uint8_t>&        i_rxFailLanes);


/**
 * @brief FW Team HWP that writes the eRepair fail lanes to the VPD.
 *        The fail lanes will be written to either the P9 MVPD or the
 *        Centaur FRU VPD depending on the passed target type.
 *
 * @param[in] i_target      Reference to X-Bus or O-Bus or MCS or memBuf Target
 * @param[in] i_vpdType     Specifies which VPD (MNFG or Field) to access.
 * @param[in] i_clkGroup    Specifies clock group 0:[XOA, X1A,..] 1:[X0B, X1B,..]
 * @param[in] i_txFailLanes Reference to a vector that has the Tx side
 *                          (of i_tgtHandle) fail lane numbers that need
 *                          to be written to the VPD
 * @param[in] i_rxFailLanes Reference to a vector that has the Rx side
 *                          (of i_tgtHandle) fail lane numbers that need
 *                          to be written to the VPD
 *
 * @return ReturnCode
 *
 */
template<fapi2::TargetType K>
fapi2::ReturnCode p9_io_erepairSetFailedLanesHwp(
    const fapi2::Target < K >&         i_target,
    EREPAIR::erepairVpdType            i_vpdType,
    const uint8_t                      i_clkGroup,
    const std::vector<uint8_t>&        i_txFailLanes,
    const std::vector<uint8_t>&        i_rxFailLanes);

#endif
