/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_erepairGetFailedLanesHwp.H $ */
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
/// @file p9_io_erepairGetFailedLanesHwp.H
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

#ifndef P9_IO_EREPAIRGETFAILEDLANESHWP_H_
#define P9_IO_EREPAIRGETFAILEDLANESHWP_H_

#include <fapi2.H>
#include <p9_io_erepairConsts.H>


template<fapi2::TargetType K>
using p9_io_erepairGetFailedLanesHwp_FP_t = fapi2::ReturnCode (*)(
            const fapi2::Target < K >&           i_target,
            EREPAIR::erepairVpdType            i_vpdType,
            const uint8_t                      i_clkGroup,
            std::vector<uint8_t>&              o_txFailLanes,
            std::vector<uint8_t>&              o_rxFailLanes);


/**
 * @brief FW Team HWP that retrieves the eRepair fail lanes.
 *        It retrieves the eRepair data from the P9 MVPD and the Centaur FRU
 *        VPD sections depending on the passed target type. It then parses the
 *        eRepair data to determine the fail lane numbers on the sub-interfaces
 *        (Tx and Rx) of the passed bus target.
 *
 * @param[in] i_tgtHandle   Reference to X-Bus or A-Bus or MCS or memBuf Target
 * @param[in] i_vpdType     Specifies which VPD (MNFG or Field) to access.
 * @param[in] i_clkGroup    Specifies clock group 0:[XOA, X1A,..] 1:[X0B, X1B,..]
 * @param[o]  o_txFailLanes Reference to a vector that will hold eRepair fail
 *                          lane numbers of the Tx sub-interface.
 * @param[o]  o_rxFailLanes Reference to a vector that will hold eRepair fail
 *                          lane numbers of the Rx sub-interface.
 *
 * @return ReturnCode
 *
 */
template<fapi2::TargetType K>
fapi2::ReturnCode p9_io_erepairGetFailedLanesHwp(
    const fapi2::Target < K >&           i_target,
    EREPAIR::erepairVpdType            i_vpdType,
    const uint8_t                      i_clkGroup,
    std::vector<uint8_t>&              o_txFailLanes,
    std::vector<uint8_t>&              o_rxFailLanes);


#endif
