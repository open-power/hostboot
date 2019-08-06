/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/exp_draminit_utils.C $ */
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
/// @file exp_draminit_utils.C
/// @brief Procedure definition to initialize DRAM
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB
#ifdef P10_READY_FOR_EXP_HWP
#include <generic/memory/lib/utils/c_str.H>
#include <lib/exp_draminit_utils.H>

namespace mss
{
namespace exp
{

///
/// @brief host_fw_command_struct structure setup
/// @param[in] i_cmd_data_crc the command data CRC
/// @param[out] o_cmd the command parameters to set
///
void setup_cmd_params(const uint32_t i_cmd_data_crc, host_fw_command_struct& o_cmd)
{
    // Issue full boot mode cmd though EXP-FW REQ buffer
    o_cmd.cmd_id = mss::exp::omi::EXP_FW_DDR_PHY_INIT;
    o_cmd.cmd_flags = 0;

    // TK - Fabricated value need to figure out if we'll be creating req_id tables
    o_cmd.request_identifier = 0xBB;
    o_cmd.cmd_length = 0;
    o_cmd.cmd_crc = i_cmd_data_crc;
    o_cmd.host_work_area = 0;
    o_cmd.cmd_work_area = 0;
    memset(o_cmd.padding, 0, sizeof(o_cmd.padding));
}

///
/// @brief user_input_msdg structure setup
/// @tparam T the fapi2 TargetType
/// @param[in] i_target the fapi2 target
/// @param[out] o_phy_params the phy params data struct
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode setup_phy_params(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                   user_input_msdg& o_phy_params)
{
    for (const auto l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        fapi2::ReturnCode l_rc;
        const phy_params l_set_phy_params(l_port, l_rc);
        FAPI_TRY(l_rc, "Unable to instantiate phy_params for target %s", mss::c_str(i_target));

        // Set the params by fetching them from the attributes
        FAPI_TRY(l_set_phy_params.set_version_number(o_phy_params));
        FAPI_TRY(l_set_phy_params.setup_DimmType(o_phy_params));
        FAPI_TRY(l_set_phy_params.setup_CsPresent(o_phy_params));
        FAPI_TRY(l_set_phy_params.setup_DramDataWidth(o_phy_params));
        FAPI_TRY(l_set_phy_params.setup_Height3DS(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_ActiveDBYTE(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_ActiveNibble(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_AddrMirror(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_ColumnAddrWidth(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_RowAddrWidth(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_SpdCLSupported(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_SpdtAAmin(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_Rank4Mode(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_EncodedQuadCs(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_DDPCompatible(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_TSV8HSupport(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_MRAMSupport(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_MDSSupport(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_NumPStates(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_Frequency(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_PhyOdtImpedance(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_PhyDrvImpedancePU(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_PhyDrvImpedancePD(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_PhySlewRate(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_ATxImpedance(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_ATxSlewRate(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_CKTxImpedance(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_CKTxSlewRate(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_AlertOdtImpedance(o_phy_params));

        // TK to use the rank API once it's available
        // For now we are assuming ranks 2 and 3 are on DIMM1 for RttNom, RttWr and RttPark
        FAPI_TRY(l_set_phy_params.set_RttNom(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_RttWr(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_RttPark(o_phy_params));

        FAPI_TRY(l_set_phy_params.set_DramDic(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_DramWritePreamble(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_DramReadPreamble(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_PhyEqualization(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_InitVrefDQ(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_InitPhyVref(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_OdtWrMapCs(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_OdtRdMapCs(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_Geardown(o_phy_params));

        // TK need to check if this also includes RC0E
        FAPI_TRY(l_set_phy_params.set_CALatencyAdder(o_phy_params));

        FAPI_TRY(l_set_phy_params.set_BistCALMode(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_BistCAParityLatency(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_RcdDic(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_RcdVoltageCtrl(o_phy_params));

        // TK check bit ordering here for RcdIBTCtrl and RcdDBDic
        FAPI_TRY(l_set_phy_params.set_RcdIBTCtrl(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_RcdDBDic(o_phy_params));

        FAPI_TRY(l_set_phy_params.set_RcdSlewRate(o_phy_params));

        FAPI_TRY(l_set_phy_params.set_DFIMRL_DDRCLK(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_ATxDly_A(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_ATxDly_B(o_phy_params));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
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
                           const host_fw_response_struct& i_rsp)
{
    // Check if cmd was successful
    FAPI_ASSERT(i_rsp.response_argument[0] == omi::response_arg::SUCCESS,
                fapi2::MSS_EXP_RSP_ARG_FAILED().
                set_TARGET(i_target).
                set_RSP_ID(i_rsp.response_id).
                set_ERROR_CODE(i_rsp.response_argument[1]),
                "Failed to initialize the PHY for %s", mss::c_str(i_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

}//check

}// exp
}// mss
#endif
