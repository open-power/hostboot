/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/exp_draminit_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
/// @file exp_draminit_utils.H
/// @brief Procedure definition to initialize DRAM
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef __MSS_EXP_DRAMINIT_UTILS__
#define __MSS_EXP_DRAMINIT_UTILS__

#include <fapi2.H>
#include <lib/shared/exp_consts.H>
#include <exp_data_structs.H>

namespace mss
{
namespace exp
{

///
/// @brief host_fw_command_struct structure setup
/// @param[in] i_cmd_data_crc the command data CRC
/// @param[out] o_cmd the command parameters to set
///
void setup_cmd_params(const uint32_t i_cmd_data_crc, host_fw_command_struct& o_cmd);

///
/// @brief user_input_msdg structure setup
/// @tparam T the fapi2 TargetType
/// @param[in] i_target the fapi2 target
/// @param[out] o_param
/// @return FAPI2_RC_SUCCESS iff okay
///
template < fapi2::TargetType T >
fapi2::ReturnCode setup_phy_params(const fapi2::Target<T>& i_target,
                                   user_input_msdg& o_params)
{
    // TODO: exp_mss_draminit VPO prep: Replace hardcode with attr derived data
    o_params.DimmType = 0;
    o_params.CsPresent = 0x1;
    o_params.DramDataWidth = 8;
    o_params.Height3DS = 0;
    o_params.ActiveDBYTE = 0;
    o_params.ActiveNibble = 0;
    o_params.AddrMirror = 0;
    o_params.ColumnAddrWidth = 10;
    o_params.RowAddrWidth = 16;
    o_params.SpdCLSupported = 0x002BFFFC;
    o_params.SpdtAAmin = 12500;
    o_params.Rank4Mode = 0;
    o_params.DDPCompatible = 0;
    o_params.TSV8HSupport = 0;
    o_params.MRAMSupport = 0;
    o_params.NumPStates = 1;
    o_params.Frequency[0] = 1600;

    // PHY parameters are fabricated and not relevant for emulation
    o_params.PhyOdtImpedance[0] = 0;
    o_params.PhyDrvImpedancePU[0] = 240;
    o_params.PhySlewRate[0] = 0;
    o_params.ATxImpedance = 120;
    o_params.ATxSlewRate = 0;
    o_params.CKTxImpedance = 120;
    o_params.CKTxSlewRate = 0;
    o_params.AlertOdtImpedance = 0;
    o_params.DramRttNomR0[0] = 0;
    o_params.DramRttNomR1[0] = 0;
    o_params.DramRttNomR2[0] = 0;
    o_params.DramRttNomR3[0] = 0;
    o_params.DramRttWrR0[0] = 0;
    o_params.DramRttWrR1[0] = 0;
    o_params.DramRttWrR2[0] = 0;
    o_params.DramRttWrR3[0] = 0;
    o_params.DramRttParkR0[0] = 0;
    o_params.DramRttParkR1[0] = 0;
    o_params.DramRttParkR2[0] = 0;
    o_params.DramRttParkR3[0] = 0;
    o_params.DramDic[0] = 48;
    o_params.DramWritePreamble[0] = 0;
    o_params.DramReadPreamble[0] = 0;
    o_params.PhyEqualization = 0;
    o_params.InitVrefDQ[0] = 0x9;
    o_params.InitPhyVref[0] = 0x60;
    o_params.OdtWrMapCs[0] = 0;
    o_params.OdtRdMapCs[0] = 0;
    o_params.Geardown[0] = 0;
    o_params.CALatencyAdder[0] = 0;
    o_params.BistCALMode[0] = 0;
    o_params.BistCAParityLatency[0] = 0;
    o_params.RcdDic[0] = 0;
    o_params.RcdVoltageCtrl[0] = 0;
    o_params.RcdIBTCtrl = 0;
    o_params.RcdDBDic = 0;
    o_params.RcdSlewRate = 0;
    o_params.EmulationSupport = 1;

    return fapi2::FAPI2_RC_SUCCESS;
}

namespace check
{

///
/// @brief Checks explorer response argument for a successful command
/// @param[in] i_target OCMB target
/// @param[in] i_rsp response command
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode response(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                           const host_fw_response_struct& i_rsp);

}//check

}// exp
}// mss

#endif
