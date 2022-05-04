/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/phy/ody_draminit_utils.C $ */
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
// EKB-Mirror-To: hostboot
///
/// @file ody_draminit_utils.C
/// @brief Odyssey PHY draminit utility functions
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <generic/memory/lib/utils/poll.H>
#include <ody_scom_mp_apbonly0.H>
#include <ody_scom_mp_drtub0.H>
#include <mss_odyssey_attribute_getters.H>

// TODO:ZEN:MST-1571 Update Odyssey PHY registers when the official values are merged into the EKB
#include <lib/phy/ody_draminit_utils.H>
#include <lib/phy/ody_phy_utils.H>
#include <ody_consts.H>

namespace mss
{
namespace ody
{
namespace phy
{

// TODO:ZEN:MST-1571 Update Odyssey PHY registers when the official values are merged into the EKB
// For now using the Synopsys register location documentation
constexpr uint64_t MIRCORESET = 0x000d0099;
constexpr uint64_t CALZAP     = 0x00020089;

constexpr uint64_t MIRCORESET_STALLTOMICRO = 60;
constexpr uint64_t MIRCORESET_RESETTOMICRO = 63;

constexpr uint64_t CALZAP_CALZAP     = 63;

///
/// @brief Initializes the protocol for mailbox interaction
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode init_mailbox_protocol(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    // Protocol initialization is writing 1 to following 2 registers.
    FAPI_TRY(fapi2::putScom(i_target, scomt::mp::DWC_DDRPHYA_APBONLY0_DCTWRITEPROT, PROTOCOL_INIT));
    FAPI_TRY(fapi2::putScom(i_target, scomt::mp::DWC_DDRPHYA_DRTUB0_UCTWRITEPROT, PROTOCOL_INIT));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get the message passed through the mailbox protocol
/// @param[in] i_target the target on which to operate
/// @param[in] i_mode 16 bit or 32 bit to read major message or streaming & SMBus messages
/// @param[in] i_mailbox_poll_count poll count for reading UCT_PROT_SHADOW.
/// @param[out] o_mail message read from the mailbox protocol.
/// note: mode is set in the calling function. mail is returned based on that.
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode get_mail (const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                            const uint8_t i_mode,
                            const uint64_t i_mailbox_poll_count,
                            fapi2::buffer<uint64_t>& o_mail)
{
    FAPI_TRY(poll_for_message_available(i_target, i_mailbox_poll_count));
    FAPI_TRY(read_message(i_target, i_mode, o_mail));
    FAPI_TRY(acknowledge_mail(i_target, i_mailbox_poll_count));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Poll for mail to be available
/// @param[in] i_target the target on which to operate
/// @param[in] i_mailbox_poll_count poll count for reading UCT_PROT_SHADOW.
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode poll_for_message_available(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint64_t i_mailbox_poll_count)
{
    fapi2::buffer<uint64_t> l_data;
    mss::poll_parameters l_poll_params(DELAY_10NS,
                                       200,
                                       mss::DELAY_1MS,
                                       200,
                                       i_mailbox_poll_count);

    // Poll for getting 0 at UctWriteProtShadow.
    bool l_poll_return = mss::poll(i_target, l_poll_params, [&i_target]()->bool
    {
        fapi2::buffer<uint64_t> l_data = 0xFF;
        FAPI_TRY(fapi2::getScom(i_target, scomt::mp::DWC_DDRPHYA_APBONLY0_UCTSHADOWREGS, l_data));
        return MESSAGE_AVAILABLE == l_data;

    fapi_try_exit:
        FAPI_ERR("mss::poll() hit an error in mss::getScom");
        return false;
    });
    // following FAPI_TRY to preserve the scom failure in lambda.
    FAPI_TRY(fapi2::current_err);
    FAPI_ASSERT(l_poll_return,
                fapi2::ODY_GET_MAIL_FAILURE().
                set_PORT_TARGET(i_target),
                TARGTIDFORMAT " poll for getting mail timed out during DRAM training", TARGTID);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief reads the message after it is available
/// @param[in] i_target the target on which to operate
/// @param[in] i_mode 16 bit or 32 bit to read major message or streaming & SMBus messages
/// @param[out] o_mail message read from the mailbox protocol.
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode read_message(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                               const uint8_t i_mode,
                               fapi2::buffer<uint64_t>& o_mail)
{
    FAPI_TRY(fapi2::getScom(i_target, scomt::mp::DWC_DDRPHYA_APBONLY0_UCTWRITEONLYSHADOW, o_mail));

    if ( STREAMING_SMBUS_MSG_MODE == i_mode)
    {
        fapi2::buffer<uint64_t> l_data;
        FAPI_TRY(fapi2::getScom(i_target, scomt::mp::DWC_DDRPHYA_APBONLY0_UCTDATWRITEONLYSHADOW, l_data));
        o_mail = (o_mail << 16 ) | l_data;
    }

    // Writing 0 to DctWriteProt.
    FAPI_TRY(fapi2::putScom(i_target, scomt::mp::DWC_DDRPHYA_APBONLY0_DCTWRITEPROT, RECEPTION_ACK));

fapi_try_exit:
    return fapi2::current_err;
}
///
/// @brief Acknowledges that mail is received
/// @param[in] i_target the target on which to operate
/// @param[in] i_mailbox_poll_count poll count for reading UCT_PROT_SHADOW.
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode acknowledge_mail(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                   const uint64_t i_mailbox_poll_count)
{
    bool l_poll_return;
    mss::poll_parameters l_poll_params(DELAY_10NS,
                                       200,
                                       mss::DELAY_1MS,
                                       200,
                                       i_mailbox_poll_count);

    // Poll for getting 0 at UctWriteProtShadow.
    l_poll_return = mss::poll(i_target, l_poll_params, [i_target]()->bool
    {
        fapi2::buffer<uint64_t> l_data;
        FAPI_TRY(fapi2::getScom(i_target, scomt::mp::DWC_DDRPHYA_APBONLY0_UCTSHADOWREGS, l_data));
        return ACK_MESSAGE == l_data;

    fapi_try_exit:
        FAPI_ERR("mss::poll() hit an error in mss::getScom");
        return false;
    });
    // following FAPI_TRY to preserve the scom failure in lambda.
    FAPI_TRY(fapi2::current_err);
    FAPI_ASSERT( l_poll_return,
                 fapi2::ODY_GET_MAIL_FAILURE().
                 set_PORT_TARGET(i_target),
                 TARGTIDFORMAT " poll for getting mail acknowledgement timed out while getting message through mailbox", TARGTID);

    // Writing 1 here completes the mail reading process.
    FAPI_TRY(fapi2::putScom(i_target, scomt::mp::DWC_DDRPHYA_APBONLY0_DCTWRITEPROT, ACK_MESSAGE));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Polls the mail until completion message is received
/// @param[in] i_target the target on which to operate
/// @param[in] i_training_poll_count poll count for getting mail.
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode poll_for_completion(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                      const uint64_t i_training_poll_count )
{
    mss::poll_parameters l_poll_params(DELAY_10NS,
                                       200,
                                       mss::DELAY_1MS,
                                       200,
                                       i_training_poll_count);
    fapi2::buffer<uint64_t> l_mail;
    bool l_poll_return ;
    fapi2::ATTR_PHY_GET_MAIL_TIMEOUT_Type l_mailbox_poll_count;
    FAPI_TRY(mss::attr::get_phy_get_mail_timeout(i_target , l_mailbox_poll_count));
    l_poll_return = mss::poll(i_target, l_poll_params, [&i_target, &l_mailbox_poll_count, &l_mail]()->bool
    {
        uint8_t l_mode = MAJOR_MSG_MODE; // 16 bit mode to read major message.
        // check the message content.
        FAPI_TRY(mss::ody::phy::get_mail(i_target, l_mode, l_mailbox_poll_count, l_mail));

        if (STREAMING_MSG == l_mail)
        {
            ;
            //decode streaming messages.
            //TODO : ZEN-MST-1588 Add APIs for Decoding streaming messages and handling SMBus messages from mailbox protocol
        }
        else if (SMBUS_MSG == l_mail)
        {
            ;
            // handle SMBus messages.
            //TODO : ZEN-MST-1588 Add APIs for Decoding streaming messages and handling SMBus messages from mailbox protocol
        }
        FAPI_TRY(fapi2::delay(mss::DELAY_1MS, 200));
        // return true if mail content is either successful completion or failed completion.
        return check_for_completion(l_mail);
    fapi_try_exit:
        FAPI_ERR("mss::poll() hit an error in mss::getScom");
        return false;
    });
    // following FAPI_TRY to preserve the scom failure in lambda.
    FAPI_TRY(fapi2::current_err);

    FAPI_ASSERT(l_poll_return,
                fapi2::ODY_DRAMINIT_TRAINING_FAILURE().
                set_PORT_TARGET(i_target).
                set_mail(l_mail),
                TARGTIDFORMAT " poll for draminit training completion timed out", TARGTID);

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Checks the completion condition for training
/// @param[in] i_mail mail content to check for completion
/// @return True if mail content is same as one of the completion values , false otherwise
///
bool check_for_completion(const fapi2::buffer<uint64_t>& i_mail)
{
    return ((SUCCESSFUL_COMPLETION == i_mail) || (FAILED_COMPLETION == i_mail));
}

///
/// @brief Configures the DRAM training message block
/// @param[in] i_target the memory port on which to operate
/// @param[out] o_struct the message block
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode configure_dram_train_message_block(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        PMU_SMB_DDR5U_1D_t& o_struct)
{
    // Note: this is currently configured to match the simulation environment
    // Note: the MR's are moved to their separate section just for clarity
    // Note: some variables are listed as output only. Just setting these to 0 for safety (as the constructor does not intialize them)
    o_struct.AdvTrainOpt = 0;
    // Note: if MsgMisc updates to set UsePerDeviceVrefDq, then update VrefDqR*Nib*
    o_struct.MsgMisc = 0x06; // fast simulation
    o_struct.PmuRevision = 0;
    o_struct.Pstate = 0; // We only use pstate 0
    o_struct.PllBypassEn = 0;
    o_struct.DRAMFreq = 4800; // Simulation DDR freq of 4800
    o_struct.RCW05_next = 0;
    o_struct.RCW06_next = 0;
    o_struct.RXEN_ADJ = 0;
    o_struct.RX2D_DFE_Misc = 0;
    o_struct.PhyVref = 0x40;
    o_struct.D5Misc = 0x40; // CK ANIB delays adjusted during training for better margins
    o_struct.WL_ADJ = 0;
    o_struct.CsTestFail = 0;
    o_struct.SequenceCtrl = 0x821f;
    o_struct.HdtCtrl = 0x0A;
    o_struct.PhyCfg = 0;
    o_struct.ResultAddrOffset = 0;
    o_struct.DFIMRLMargin = 0x02; // This needs to be large enough for max tDQSCK variation
    o_struct.X16Present = 0;
    o_struct.UseBroadcastMR = 0;
    o_struct.D5Quickboot = 0;
    o_struct.DisabledDbyte = 0; // Mismatch to XTB environment, but we're using all the DBYTE's available
    o_struct.CATrainOpt = 0x1c;
    o_struct.TX2D_DFE_Misc = 0x00;
    o_struct.RX2D_TrainOpt = 0x1e;
    o_struct.TX2D_TrainOpt = 0x1e;
    o_struct.Share2DVrefResult  = 0x00;
    o_struct.MRE_MIN_PULSE = 0x00;
    o_struct.DWL_MIN_PULSE = 0x00;
    o_struct.PhyConfigOverride = 0x0000;
    o_struct.EnabledDQsChA = 36; // 36 bits on each channel for a UDIMM
    o_struct.CsPresentChA = 0x01; // There's a chip select on channel A
    o_struct.CS_Dly_Margin_A0 = 0;
    o_struct.CS_Vref_Margin_A0 = 0;
    o_struct.CA_Dly_Margin_A0 = 0;
    o_struct.CA_Vref_Margin_A0 = 0;
    o_struct.DFE_GainBias_A0 = 0;
    o_struct.CS_Dly_Margin_A1 = 0;
    o_struct.CS_Vref_Margin_A1 = 0;
    o_struct.CA_Dly_Margin_A1 = 0;
    o_struct.CA_Vref_Margin_A1 = 0;
    o_struct.DFE_GainBias_A1 = 0;
    o_struct.CS_Dly_Margin_A2 = 0;
    o_struct.CS_Vref_Margin_A2 = 0;
    o_struct.CA_Dly_Margin_A2 = 0;
    o_struct.CA_Vref_Margin_A2 = 0;
    o_struct.DFE_GainBias_A2 = 0;
    o_struct.CS_Dly_Margin_A3 = 0;
    o_struct.CS_Vref_Margin_A3 = 0;
    o_struct.CA_Dly_Margin_A3 = 0;
    o_struct.CA_Vref_Margin_A3 = 0;
    o_struct.DFE_GainBias_A3 = 0;
    o_struct.ReservedF6 = 0;
    o_struct.ReservedF7 = 0;
    o_struct.ReservedF8 = 0;
    o_struct.ReservedF9 = 0;
    o_struct.BCW04_next = 0x00;
    o_struct.BCW05_next = 0x00;
    o_struct.WR_RD_RTT_PARK_A0 = 0x00; // RTT_PARK disabled
    o_struct.WR_RD_RTT_PARK_A1 = 0x00; // RTT_PARK disabled
    o_struct.WR_RD_RTT_PARK_A2 = 0x00; // RTT_PARK disabled
    o_struct.WR_RD_RTT_PARK_A3 = 0x00; // RTT_PARK disabled
    o_struct.RxClkDly_Margin_A0 = 0;
    o_struct.VrefDac_Margin_A0 = 0;
    o_struct.TxDqDly_Margin_A0 = 0;
    o_struct.DeviceVref_Margin_A0 = 0;
    o_struct.RxClkDly_Margin_A1 = 0;
    o_struct.VrefDac_Margin_A1 = 0;
    o_struct.TxDqDly_Margin_A1 = 0;
    o_struct.DeviceVref_Margin_A1 = 0;
    o_struct.RxClkDly_Margin_A2 = 0;
    o_struct.VrefDac_Margin_A2 = 0;
    o_struct.TxDqDly_Margin_A2 = 0;
    o_struct.DeviceVref_Margin_A2 = 0;
    o_struct.RxClkDly_Margin_A3 = 0;
    o_struct.VrefDac_Margin_A3 = 0;
    o_struct.TxDqDly_Margin_A3 = 0;
    o_struct.DeviceVref_Margin_A3 = 0;
    o_struct.EnabledDQsChB = 36; // 36 bits on each channel for a UDIMM
    o_struct.CsPresentChB = 0x01;
    o_struct.CS_Dly_Margin_B0 = 0;
    o_struct.CS_Vref_Margin_B0 = 0;
    o_struct.CA_Dly_Margin_B0 = 0;
    o_struct.CA_Vref_Margin_B0 = 0;
    o_struct.DFE_GainBias_B0 = 0;
    o_struct.CS_Dly_Margin_B1 = 0;
    o_struct.CS_Vref_Margin_B1 = 0;
    o_struct.CA_Dly_Margin_B1 = 0;
    o_struct.CA_Vref_Margin_B1 = 0;
    o_struct.DFE_GainBias_B1 = 0;
    o_struct.CS_Dly_Margin_B2 = 0;
    o_struct.CS_Vref_Margin_B2 = 0;
    o_struct.CA_Dly_Margin_B2 = 0;
    o_struct.CA_Vref_Margin_B2 = 0;
    o_struct.DFE_GainBias_B2 = 0;
    o_struct.CS_Dly_Margin_B3 = 0;
    o_struct.CS_Vref_Margin_B3 = 0;
    o_struct.CA_Dly_Margin_B3 = 0;
    o_struct.CA_Vref_Margin_B3 = 0;
    o_struct.DFE_GainBias_B3 = 0x00;
    o_struct.Reserved1E2 = 0;
    o_struct.Reserved1E3 = 0;
    o_struct.Reserved1E4 = 0;
    o_struct.Reserved1E5 = 0;
    o_struct.Reserved1E6 = 0;
    o_struct.Reserved1E7 = 0;
    o_struct.WR_RD_RTT_PARK_B0 = 0x00; // RTT_PARK disabled
    o_struct.WR_RD_RTT_PARK_B1 = 0x00; // RTT_PARK disabled
    o_struct.WR_RD_RTT_PARK_B2 = 0x00; // RTT_PARK disabled
    o_struct.WR_RD_RTT_PARK_B3 = 0x00; // RTT_PARK disabled
    o_struct.RxClkDly_Margin_B0 = 0;
    o_struct.VrefDac_Margin_B0 = 0;
    o_struct.TxDqDly_Margin_B0 = 0;
    o_struct.DeviceVref_Margin_B0 = 0;
    o_struct.RxClkDly_Margin_B1 = 0;
    o_struct.VrefDac_Margin_B1 = 0;
    o_struct.TxDqDly_Margin_B1 = 0;
    o_struct.DeviceVref_Margin_B1 = 0;
    o_struct.RxClkDly_Margin_B2 = 0;
    o_struct.VrefDac_Margin_B2 = 0;
    o_struct.TxDqDly_Margin_B2 = 0;
    o_struct.DeviceVref_Margin_B2 = 0;
    o_struct.RxClkDly_Margin_B3 = 0;
    o_struct.VrefDac_Margin_B3 = 0;
    o_struct.TxDqDly_Margin_B3 = 0;
    o_struct.DeviceVref_Margin_B3 = 0;
    o_struct.WL_ADJ_START = 0x00;
    o_struct.WL_ADJ_END = 0x00;
    o_struct.RCW00_ChA_D0 = 0;
    o_struct.RCW01_ChA_D0 = 0;
    o_struct.RCW02_ChA_D0 = 0;
    o_struct.RCW03_ChA_D0 = 0;
    o_struct.RCW04_ChA_D0 = 0;
    o_struct.RCW05_ChA_D0 = 0;
    o_struct.RCW06_ChA_D0 = 0;
    o_struct.RCW07_ChA_D0 = 0;
    o_struct.RCW08_ChA_D0 = 0;
    o_struct.RCW09_ChA_D0 = 0;
    o_struct.RCW0A_ChA_D0 = 0;
    o_struct.RCW0B_ChA_D0 = 0;
    o_struct.RCW0C_ChA_D0 = 0;
    o_struct.RCW0D_ChA_D0 = 0;
    o_struct.RCW0E_ChA_D0 = 0;
    o_struct.RCW0F_ChA_D0 = 0;
    o_struct.RCW10_ChA_D0 = 0;
    o_struct.RCW11_ChA_D0 = 0;
    o_struct.RCW12_ChA_D0 = 0;
    o_struct.RCW13_ChA_D0 = 0;
    o_struct.RCW14_ChA_D0 = 0;
    o_struct.RCW15_ChA_D0 = 0;
    o_struct.RCW16_ChA_D0 = 0;
    o_struct.RCW17_ChA_D0 = 0;
    o_struct.RCW18_ChA_D0 = 0;
    o_struct.RCW19_ChA_D0 = 0;
    o_struct.RCW1A_ChA_D0 = 0;
    o_struct.RCW1B_ChA_D0 = 0;
    o_struct.RCW1C_ChA_D0 = 0;
    o_struct.RCW1D_ChA_D0 = 0;
    o_struct.RCW1E_ChA_D0 = 0;
    o_struct.RCW1F_ChA_D0 = 0;
    o_struct.RCW20_ChA_D0 = 0;
    o_struct.RCW21_ChA_D0 = 0;
    o_struct.RCW22_ChA_D0 = 0;
    o_struct.RCW23_ChA_D0 = 0;
    o_struct.RCW24_ChA_D0 = 0;
    o_struct.RCW25_ChA_D0 = 0;
    o_struct.RCW26_ChA_D0 = 0;
    o_struct.RCW27_ChA_D0 = 0;
    o_struct.RCW28_ChA_D0 = 0;
    o_struct.RCW29_ChA_D0 = 0;
    o_struct.RCW2A_ChA_D0 = 0;
    o_struct.RCW2B_ChA_D0 = 0;
    o_struct.RCW2C_ChA_D0 = 0;
    o_struct.RCW2D_ChA_D0 = 0;
    o_struct.RCW2E_ChA_D0 = 0;
    o_struct.RCW2F_ChA_D0 = 0;
    o_struct.RCW30_ChA_D0 = 0;
    o_struct.RCW31_ChA_D0 = 0;
    o_struct.RCW32_ChA_D0 = 0;
    o_struct.RCW33_ChA_D0 = 0;
    o_struct.RCW34_ChA_D0 = 0;
    o_struct.RCW35_ChA_D0 = 0;
    o_struct.RCW36_ChA_D0 = 0;
    o_struct.RCW37_ChA_D0 = 0;
    o_struct.RCW38_ChA_D0 = 0;
    o_struct.RCW39_ChA_D0 = 0;
    o_struct.RCW3A_ChA_D0 = 0;
    o_struct.RCW3B_ChA_D0 = 0;
    o_struct.RCW3C_ChA_D0 = 0;
    o_struct.RCW3D_ChA_D0 = 0;
    o_struct.RCW3E_ChA_D0 = 0;
    o_struct.RCW3F_ChA_D0 = 0;
    o_struct.RCW40_ChA_D0 = 0;
    o_struct.RCW41_ChA_D0 = 0;
    o_struct.RCW42_ChA_D0 = 0;
    o_struct.RCW43_ChA_D0 = 0;
    o_struct.RCW44_ChA_D0 = 0;
    o_struct.RCW45_ChA_D0 = 0;
    o_struct.RCW46_ChA_D0 = 0;
    o_struct.RCW47_ChA_D0 = 0;
    o_struct.RCW48_ChA_D0 = 0;
    o_struct.RCW49_ChA_D0 = 0;
    o_struct.RCW4A_ChA_D0 = 0;
    o_struct.RCW4B_ChA_D0 = 0;
    o_struct.RCW4C_ChA_D0 = 0;
    o_struct.RCW4D_ChA_D0 = 0;
    o_struct.RCW4E_ChA_D0 = 0;
    o_struct.RCW4F_ChA_D0 = 0;
    o_struct.RCW50_ChA_D0 = 0;
    o_struct.RCW51_ChA_D0 = 0;
    o_struct.RCW52_ChA_D0 = 0;
    o_struct.RCW53_ChA_D0 = 0;
    o_struct.RCW54_ChA_D0 = 0;
    o_struct.RCW55_ChA_D0 = 0;
    o_struct.RCW56_ChA_D0 = 0;
    o_struct.RCW57_ChA_D0 = 0;
    o_struct.RCW58_ChA_D0 = 0;
    o_struct.RCW59_ChA_D0 = 0;
    o_struct.RCW5A_ChA_D0 = 0;
    o_struct.RCW5B_ChA_D0 = 0;
    o_struct.RCW5C_ChA_D0 = 0;
    o_struct.RCW5D_ChA_D0 = 0;
    o_struct.RCW5E_ChA_D0 = 0;
    o_struct.RCW5F_ChA_D0 = 0;
    o_struct.RCW60_ChA_D0 = 0;
    o_struct.RCW61_ChA_D0 = 0;
    o_struct.RCW62_ChA_D0 = 0;
    o_struct.RCW63_ChA_D0 = 0;
    o_struct.RCW64_ChA_D0 = 0;
    o_struct.RCW65_ChA_D0 = 0;
    o_struct.RCW66_ChA_D0 = 0;
    o_struct.RCW67_ChA_D0 = 0;
    o_struct.RCW68_ChA_D0 = 0;
    o_struct.RCW69_ChA_D0 = 0;
    o_struct.RCW6A_ChA_D0 = 0;
    o_struct.RCW6B_ChA_D0 = 0;
    o_struct.RCW6C_ChA_D0 = 0;
    o_struct.RCW6D_ChA_D0 = 0;
    o_struct.RCW6E_ChA_D0 = 0;
    o_struct.RCW6F_ChA_D0 = 0;
    o_struct.RCW70_ChA_D0 = 0;
    o_struct.RCW71_ChA_D0 = 0;
    o_struct.RCW72_ChA_D0 = 0;
    o_struct.RCW73_ChA_D0 = 0;
    o_struct.RCW74_ChA_D0 = 0;
    o_struct.RCW75_ChA_D0 = 0;
    o_struct.RCW76_ChA_D0 = 0;
    o_struct.RCW77_ChA_D0 = 0;
    o_struct.RCW78_ChA_D0 = 0;
    o_struct.RCW79_ChA_D0 = 0;
    o_struct.RCW7A_ChA_D0 = 0;
    o_struct.RCW7B_ChA_D0 = 0;
    o_struct.RCW7C_ChA_D0 = 0;
    o_struct.RCW7D_ChA_D0 = 0;
    o_struct.RCW7E_ChA_D0 = 0;
    o_struct.RCW7F_ChA_D0 = 0;
    o_struct.BCW00_ChA_D0 = 0;
    o_struct.BCW01_ChA_D0 = 0;
    o_struct.BCW02_ChA_D0 = 0;
    o_struct.BCW03_ChA_D0 = 0;
    o_struct.BCW04_ChA_D0 = 0;
    o_struct.BCW05_ChA_D0 = 0;
    o_struct.BCW06_ChA_D0 = 0;
    o_struct.BCW07_ChA_D0 = 0;
    o_struct.BCW08_ChA_D0 = 0;
    o_struct.BCW09_ChA_D0 = 0;
    o_struct.BCW0A_ChA_D0 = 0;
    o_struct.BCW0B_ChA_D0 = 0;
    o_struct.BCW0C_ChA_D0 = 0;
    o_struct.BCW0D_ChA_D0 = 0;
    o_struct.BCW0E_ChA_D0 = 0;
    o_struct.BCW0F_ChA_D0 = 0;
    o_struct.BCW10_ChA_D0 = 0;
    o_struct.BCW11_ChA_D0 = 0;
    o_struct.BCW12_ChA_D0 = 0;
    o_struct.BCW13_ChA_D0 = 0;
    o_struct.BCW14_ChA_D0 = 0;
    o_struct.BCW15_ChA_D0 = 0;
    o_struct.BCW16_ChA_D0 = 0;
    o_struct.BCW17_ChA_D0 = 0;
    o_struct.BCW18_ChA_D0 = 0;
    o_struct.BCW19_ChA_D0 = 0;
    o_struct.BCW1A_ChA_D0 = 0;
    o_struct.BCW1B_ChA_D0 = 0;
    o_struct.BCW1C_ChA_D0 = 0;
    o_struct.BCW1D_ChA_D0 = 0;
    o_struct.BCW1E_ChA_D0 = 0;
    o_struct.BCW1F_ChA_D0 = 0;
    o_struct.BCW20_ChA_D0 = 0;
    o_struct.BCW21_ChA_D0 = 0;
    o_struct.BCW22_ChA_D0 = 0;
    o_struct.BCW23_ChA_D0 = 0;
    o_struct.BCW24_ChA_D0 = 0;
    o_struct.BCW25_ChA_D0 = 0;
    o_struct.BCW26_ChA_D0 = 0;
    o_struct.BCW27_ChA_D0 = 0;
    o_struct.BCW28_ChA_D0 = 0;
    o_struct.BCW29_ChA_D0 = 0;
    o_struct.BCW2A_ChA_D0 = 0;
    o_struct.BCW2B_ChA_D0 = 0;
    o_struct.BCW2C_ChA_D0 = 0;
    o_struct.BCW2D_ChA_D0 = 0;
    o_struct.BCW2E_ChA_D0 = 0;
    o_struct.BCW2F_ChA_D0 = 0;
    o_struct.BCW30_ChA_D0 = 0;
    o_struct.BCW31_ChA_D0 = 0;
    o_struct.BCW32_ChA_D0 = 0;
    o_struct.BCW33_ChA_D0 = 0;
    o_struct.BCW34_ChA_D0 = 0;
    o_struct.BCW35_ChA_D0 = 0;
    o_struct.BCW36_ChA_D0 = 0;
    o_struct.BCW37_ChA_D0 = 0;
    o_struct.BCW38_ChA_D0 = 0;
    o_struct.BCW39_ChA_D0 = 0;
    o_struct.BCW3A_ChA_D0 = 0;
    o_struct.BCW3B_ChA_D0 = 0;
    o_struct.BCW3C_ChA_D0 = 0;
    o_struct.BCW3D_ChA_D0 = 0;
    o_struct.BCW3E_ChA_D0 = 0;
    o_struct.BCW3F_ChA_D0 = 0;
    o_struct.BCW40_ChA_D0 = 0;
    o_struct.BCW41_ChA_D0 = 0;
    o_struct.BCW42_ChA_D0 = 0;
    o_struct.BCW43_ChA_D0 = 0;
    o_struct.BCW44_ChA_D0 = 0;
    o_struct.BCW45_ChA_D0 = 0;
    o_struct.BCW46_ChA_D0 = 0;
    o_struct.BCW47_ChA_D0 = 0;
    o_struct.BCW48_ChA_D0 = 0;
    o_struct.BCW49_ChA_D0 = 0;
    o_struct.BCW4A_ChA_D0 = 0;
    o_struct.BCW4B_ChA_D0 = 0;
    o_struct.BCW4C_ChA_D0 = 0;
    o_struct.BCW4D_ChA_D0 = 0;
    o_struct.BCW4E_ChA_D0 = 0;
    o_struct.BCW4F_ChA_D0 = 0;
    o_struct.BCW50_ChA_D0 = 0;
    o_struct.BCW51_ChA_D0 = 0;
    o_struct.BCW52_ChA_D0 = 0;
    o_struct.BCW53_ChA_D0 = 0;
    o_struct.BCW54_ChA_D0 = 0;
    o_struct.BCW55_ChA_D0 = 0;
    o_struct.BCW56_ChA_D0 = 0;
    o_struct.BCW57_ChA_D0 = 0;
    o_struct.BCW58_ChA_D0 = 0;
    o_struct.BCW59_ChA_D0 = 0;
    o_struct.BCW5A_ChA_D0 = 0;
    o_struct.BCW5B_ChA_D0 = 0;
    o_struct.BCW5C_ChA_D0 = 0;
    o_struct.BCW5D_ChA_D0 = 0;
    o_struct.BCW5E_ChA_D0 = 0;
    o_struct.BCW5F_ChA_D0 = 0;
    o_struct.BCW60_ChA_D0 = 0;
    o_struct.BCW61_ChA_D0 = 0;
    o_struct.BCW62_ChA_D0 = 0;
    o_struct.BCW63_ChA_D0 = 0;
    o_struct.BCW64_ChA_D0 = 0;
    o_struct.BCW65_ChA_D0 = 0;
    o_struct.BCW66_ChA_D0 = 0;
    o_struct.BCW67_ChA_D0 = 0;
    o_struct.BCW68_ChA_D0 = 0;
    o_struct.BCW69_ChA_D0 = 0;
    o_struct.BCW6A_ChA_D0 = 0;
    o_struct.BCW6B_ChA_D0 = 0;
    o_struct.BCW6C_ChA_D0 = 0;
    o_struct.BCW6D_ChA_D0 = 0;
    o_struct.BCW6E_ChA_D0 = 0;
    o_struct.BCW6F_ChA_D0 = 0;
    o_struct.BCW70_ChA_D0 = 0;
    o_struct.BCW71_ChA_D0 = 0;
    o_struct.BCW72_ChA_D0 = 0;
    o_struct.BCW73_ChA_D0 = 0;
    o_struct.BCW74_ChA_D0 = 0;
    o_struct.BCW75_ChA_D0 = 0;
    o_struct.BCW76_ChA_D0 = 0;
    o_struct.BCW77_ChA_D0 = 0;
    o_struct.BCW78_ChA_D0 = 0;
    o_struct.BCW79_ChA_D0 = 0;
    o_struct.BCW7A_ChA_D0 = 0;
    o_struct.BCW7B_ChA_D0 = 0;
    o_struct.BCW7C_ChA_D0 = 0;
    o_struct.BCW7D_ChA_D0 = 0;
    o_struct.BCW7E_ChA_D0 = 0;
    o_struct.BCW7F_ChA_D0 = 0;
    o_struct.RCW00_ChA_D1 = 0;
    o_struct.RCW01_ChA_D1 = 0;
    o_struct.RCW02_ChA_D1 = 0;
    o_struct.RCW03_ChA_D1 = 0;
    o_struct.RCW04_ChA_D1 = 0;
    o_struct.RCW05_ChA_D1 = 0;
    o_struct.RCW06_ChA_D1 = 0;
    o_struct.RCW07_ChA_D1 = 0;
    o_struct.RCW08_ChA_D1 = 0;
    o_struct.RCW09_ChA_D1 = 0;
    o_struct.RCW0A_ChA_D1 = 0;
    o_struct.RCW0B_ChA_D1 = 0;
    o_struct.RCW0C_ChA_D1 = 0;
    o_struct.RCW0D_ChA_D1 = 0;
    o_struct.RCW0E_ChA_D1 = 0;
    o_struct.RCW0F_ChA_D1 = 0;
    o_struct.RCW10_ChA_D1 = 0;
    o_struct.RCW11_ChA_D1 = 0;
    o_struct.RCW12_ChA_D1 = 0;
    o_struct.RCW13_ChA_D1 = 0;
    o_struct.RCW14_ChA_D1 = 0;
    o_struct.RCW15_ChA_D1 = 0;
    o_struct.RCW16_ChA_D1 = 0;
    o_struct.RCW17_ChA_D1 = 0;
    o_struct.RCW18_ChA_D1 = 0;
    o_struct.RCW19_ChA_D1 = 0;
    o_struct.RCW1A_ChA_D1 = 0;
    o_struct.RCW1B_ChA_D1 = 0;
    o_struct.RCW1C_ChA_D1 = 0;
    o_struct.RCW1D_ChA_D1 = 0;
    o_struct.RCW1E_ChA_D1 = 0;
    o_struct.RCW1F_ChA_D1 = 0;
    o_struct.RCW20_ChA_D1 = 0;
    o_struct.RCW21_ChA_D1 = 0;
    o_struct.RCW22_ChA_D1 = 0;
    o_struct.RCW23_ChA_D1 = 0;
    o_struct.RCW24_ChA_D1 = 0;
    o_struct.RCW25_ChA_D1 = 0;
    o_struct.RCW26_ChA_D1 = 0;
    o_struct.RCW27_ChA_D1 = 0;
    o_struct.RCW28_ChA_D1 = 0;
    o_struct.RCW29_ChA_D1 = 0;
    o_struct.RCW2A_ChA_D1 = 0;
    o_struct.RCW2B_ChA_D1 = 0;
    o_struct.RCW2C_ChA_D1 = 0;
    o_struct.RCW2D_ChA_D1 = 0;
    o_struct.RCW2E_ChA_D1 = 0;
    o_struct.RCW2F_ChA_D1 = 0;
    o_struct.RCW30_ChA_D1 = 0;
    o_struct.RCW31_ChA_D1 = 0;
    o_struct.RCW32_ChA_D1 = 0;
    o_struct.RCW33_ChA_D1 = 0;
    o_struct.RCW34_ChA_D1 = 0;
    o_struct.RCW35_ChA_D1 = 0;
    o_struct.RCW36_ChA_D1 = 0;
    o_struct.RCW37_ChA_D1 = 0;
    o_struct.RCW38_ChA_D1 = 0;
    o_struct.RCW39_ChA_D1 = 0;
    o_struct.RCW3A_ChA_D1 = 0;
    o_struct.RCW3B_ChA_D1 = 0;
    o_struct.RCW3C_ChA_D1 = 0;
    o_struct.RCW3D_ChA_D1 = 0;
    o_struct.RCW3E_ChA_D1 = 0;
    o_struct.RCW3F_ChA_D1 = 0;
    o_struct.RCW40_ChA_D1 = 0;
    o_struct.RCW41_ChA_D1 = 0;
    o_struct.RCW42_ChA_D1 = 0;
    o_struct.RCW43_ChA_D1 = 0;
    o_struct.RCW44_ChA_D1 = 0;
    o_struct.RCW45_ChA_D1 = 0;
    o_struct.RCW46_ChA_D1 = 0;
    o_struct.RCW47_ChA_D1 = 0;
    o_struct.RCW48_ChA_D1 = 0;
    o_struct.RCW49_ChA_D1 = 0;
    o_struct.RCW4A_ChA_D1 = 0;
    o_struct.RCW4B_ChA_D1 = 0;
    o_struct.RCW4C_ChA_D1 = 0;
    o_struct.RCW4D_ChA_D1 = 0;
    o_struct.RCW4E_ChA_D1 = 0;
    o_struct.RCW4F_ChA_D1 = 0;
    o_struct.RCW50_ChA_D1 = 0;
    o_struct.RCW51_ChA_D1 = 0;
    o_struct.RCW52_ChA_D1 = 0;
    o_struct.RCW53_ChA_D1 = 0;
    o_struct.RCW54_ChA_D1 = 0;
    o_struct.RCW55_ChA_D1 = 0;
    o_struct.RCW56_ChA_D1 = 0;
    o_struct.RCW57_ChA_D1 = 0;
    o_struct.RCW58_ChA_D1 = 0;
    o_struct.RCW59_ChA_D1 = 0;
    o_struct.RCW5A_ChA_D1 = 0;
    o_struct.RCW5B_ChA_D1 = 0;
    o_struct.RCW5C_ChA_D1 = 0;
    o_struct.RCW5D_ChA_D1 = 0;
    o_struct.RCW5E_ChA_D1 = 0;
    o_struct.RCW5F_ChA_D1 = 0;
    o_struct.RCW60_ChA_D1 = 0;
    o_struct.RCW61_ChA_D1 = 0;
    o_struct.RCW62_ChA_D1 = 0;
    o_struct.RCW63_ChA_D1 = 0;
    o_struct.RCW64_ChA_D1 = 0;
    o_struct.RCW65_ChA_D1 = 0;
    o_struct.RCW66_ChA_D1 = 0;
    o_struct.RCW67_ChA_D1 = 0;
    o_struct.RCW68_ChA_D1 = 0;
    o_struct.RCW69_ChA_D1 = 0;
    o_struct.RCW6A_ChA_D1 = 0;
    o_struct.RCW6B_ChA_D1 = 0;
    o_struct.RCW6C_ChA_D1 = 0;
    o_struct.RCW6D_ChA_D1 = 0;
    o_struct.RCW6E_ChA_D1 = 0;
    o_struct.RCW6F_ChA_D1 = 0;
    o_struct.RCW70_ChA_D1 = 0;
    o_struct.RCW71_ChA_D1 = 0;
    o_struct.RCW72_ChA_D1 = 0;
    o_struct.RCW73_ChA_D1 = 0;
    o_struct.RCW74_ChA_D1 = 0;
    o_struct.RCW75_ChA_D1 = 0;
    o_struct.RCW76_ChA_D1 = 0;
    o_struct.RCW77_ChA_D1 = 0;
    o_struct.RCW78_ChA_D1 = 0;
    o_struct.RCW79_ChA_D1 = 0;
    o_struct.RCW7A_ChA_D1 = 0;
    o_struct.RCW7B_ChA_D1 = 0;
    o_struct.RCW7C_ChA_D1 = 0;
    o_struct.RCW7D_ChA_D1 = 0;
    o_struct.RCW7E_ChA_D1 = 0;
    o_struct.RCW7F_ChA_D1 = 0;
    o_struct.BCW00_ChA_D1 = 0;
    o_struct.BCW01_ChA_D1 = 0;
    o_struct.BCW02_ChA_D1 = 0;
    o_struct.BCW03_ChA_D1 = 0;
    o_struct.BCW04_ChA_D1 = 0;
    o_struct.BCW05_ChA_D1 = 0;
    o_struct.BCW06_ChA_D1 = 0;
    o_struct.BCW07_ChA_D1 = 0;
    o_struct.BCW08_ChA_D1 = 0;
    o_struct.BCW09_ChA_D1 = 0;
    o_struct.BCW0A_ChA_D1 = 0;
    o_struct.BCW0B_ChA_D1 = 0;
    o_struct.BCW0C_ChA_D1 = 0;
    o_struct.BCW0D_ChA_D1 = 0;
    o_struct.BCW0E_ChA_D1 = 0;
    o_struct.BCW0F_ChA_D1 = 0;
    o_struct.BCW10_ChA_D1 = 0;
    o_struct.BCW11_ChA_D1 = 0;
    o_struct.BCW12_ChA_D1 = 0;
    o_struct.BCW13_ChA_D1 = 0;
    o_struct.BCW14_ChA_D1 = 0;
    o_struct.BCW15_ChA_D1 = 0;
    o_struct.BCW16_ChA_D1 = 0;
    o_struct.BCW17_ChA_D1 = 0;
    o_struct.BCW18_ChA_D1 = 0;
    o_struct.BCW19_ChA_D1 = 0;
    o_struct.BCW1A_ChA_D1 = 0;
    o_struct.BCW1B_ChA_D1 = 0;
    o_struct.BCW1C_ChA_D1 = 0;
    o_struct.BCW1D_ChA_D1 = 0;
    o_struct.BCW1E_ChA_D1 = 0;
    o_struct.BCW1F_ChA_D1 = 0;
    o_struct.BCW20_ChA_D1 = 0;
    o_struct.BCW21_ChA_D1 = 0;
    o_struct.BCW22_ChA_D1 = 0;
    o_struct.BCW23_ChA_D1 = 0;
    o_struct.BCW24_ChA_D1 = 0;
    o_struct.BCW25_ChA_D1 = 0;
    o_struct.BCW26_ChA_D1 = 0;
    o_struct.BCW27_ChA_D1 = 0;
    o_struct.BCW28_ChA_D1 = 0;
    o_struct.BCW29_ChA_D1 = 0;
    o_struct.BCW2A_ChA_D1 = 0;
    o_struct.BCW2B_ChA_D1 = 0;
    o_struct.BCW2C_ChA_D1 = 0;
    o_struct.BCW2D_ChA_D1 = 0;
    o_struct.BCW2E_ChA_D1 = 0;
    o_struct.BCW2F_ChA_D1 = 0;
    o_struct.BCW30_ChA_D1 = 0;
    o_struct.BCW31_ChA_D1 = 0;
    o_struct.BCW32_ChA_D1 = 0;
    o_struct.BCW33_ChA_D1 = 0;
    o_struct.BCW34_ChA_D1 = 0;
    o_struct.BCW35_ChA_D1 = 0;
    o_struct.BCW36_ChA_D1 = 0;
    o_struct.BCW37_ChA_D1 = 0;
    o_struct.BCW38_ChA_D1 = 0;
    o_struct.BCW39_ChA_D1 = 0;
    o_struct.BCW3A_ChA_D1 = 0;
    o_struct.BCW3B_ChA_D1 = 0;
    o_struct.BCW3C_ChA_D1 = 0;
    o_struct.BCW3D_ChA_D1 = 0;
    o_struct.BCW3E_ChA_D1 = 0;
    o_struct.BCW3F_ChA_D1 = 0;
    o_struct.BCW40_ChA_D1 = 0;
    o_struct.BCW41_ChA_D1 = 0;
    o_struct.BCW42_ChA_D1 = 0;
    o_struct.BCW43_ChA_D1 = 0;
    o_struct.BCW44_ChA_D1 = 0;
    o_struct.BCW45_ChA_D1 = 0;
    o_struct.BCW46_ChA_D1 = 0;
    o_struct.BCW47_ChA_D1 = 0;
    o_struct.BCW48_ChA_D1 = 0;
    o_struct.BCW49_ChA_D1 = 0;
    o_struct.BCW4A_ChA_D1 = 0;
    o_struct.BCW4B_ChA_D1 = 0;
    o_struct.BCW4C_ChA_D1 = 0;
    o_struct.BCW4D_ChA_D1 = 0;
    o_struct.BCW4E_ChA_D1 = 0;
    o_struct.BCW4F_ChA_D1 = 0;
    o_struct.BCW50_ChA_D1 = 0;
    o_struct.BCW51_ChA_D1 = 0;
    o_struct.BCW52_ChA_D1 = 0;
    o_struct.BCW53_ChA_D1 = 0;
    o_struct.BCW54_ChA_D1 = 0;
    o_struct.BCW55_ChA_D1 = 0;
    o_struct.BCW56_ChA_D1 = 0;
    o_struct.BCW57_ChA_D1 = 0;
    o_struct.BCW58_ChA_D1 = 0;
    o_struct.BCW59_ChA_D1 = 0;
    o_struct.BCW5A_ChA_D1 = 0;
    o_struct.BCW5B_ChA_D1 = 0;
    o_struct.BCW5C_ChA_D1 = 0;
    o_struct.BCW5D_ChA_D1 = 0;
    o_struct.BCW5E_ChA_D1 = 0;
    o_struct.BCW5F_ChA_D1 = 0;
    o_struct.BCW60_ChA_D1 = 0;
    o_struct.BCW61_ChA_D1 = 0;
    o_struct.BCW62_ChA_D1 = 0;
    o_struct.BCW63_ChA_D1 = 0;
    o_struct.BCW64_ChA_D1 = 0;
    o_struct.BCW65_ChA_D1 = 0;
    o_struct.BCW66_ChA_D1 = 0;
    o_struct.BCW67_ChA_D1 = 0;
    o_struct.BCW68_ChA_D1 = 0;
    o_struct.BCW69_ChA_D1 = 0;
    o_struct.BCW6A_ChA_D1 = 0;
    o_struct.BCW6B_ChA_D1 = 0;
    o_struct.BCW6C_ChA_D1 = 0;
    o_struct.BCW6D_ChA_D1 = 0;
    o_struct.BCW6E_ChA_D1 = 0;
    o_struct.BCW6F_ChA_D1 = 0;
    o_struct.BCW70_ChA_D1 = 0;
    o_struct.BCW71_ChA_D1 = 0;
    o_struct.BCW72_ChA_D1 = 0;
    o_struct.BCW73_ChA_D1 = 0;
    o_struct.BCW74_ChA_D1 = 0;
    o_struct.BCW75_ChA_D1 = 0;
    o_struct.BCW76_ChA_D1 = 0;
    o_struct.BCW77_ChA_D1 = 0;
    o_struct.BCW78_ChA_D1 = 0;
    o_struct.BCW79_ChA_D1 = 0;
    o_struct.BCW7A_ChA_D1 = 0;
    o_struct.BCW7B_ChA_D1 = 0;
    o_struct.BCW7C_ChA_D1 = 0;
    o_struct.BCW7D_ChA_D1 = 0;
    o_struct.BCW7E_ChA_D1 = 0;
    o_struct.BCW7F_ChA_D1 = 0;
    o_struct.RCW00_ChB_D0 = 0;
    o_struct.RCW01_ChB_D0 = 0;
    o_struct.RCW02_ChB_D0 = 0;
    o_struct.RCW03_ChB_D0 = 0;
    o_struct.RCW04_ChB_D0 = 0;
    o_struct.RCW05_ChB_D0 = 0;
    o_struct.RCW06_ChB_D0 = 0;
    o_struct.RCW07_ChB_D0 = 0;
    o_struct.RCW08_ChB_D0 = 0;
    o_struct.RCW09_ChB_D0 = 0;
    o_struct.RCW0A_ChB_D0 = 0;
    o_struct.RCW0B_ChB_D0 = 0;
    o_struct.RCW0C_ChB_D0 = 0;
    o_struct.RCW0D_ChB_D0 = 0;
    o_struct.RCW0E_ChB_D0 = 0;
    o_struct.RCW0F_ChB_D0 = 0;
    o_struct.RCW10_ChB_D0 = 0;
    o_struct.RCW11_ChB_D0 = 0;
    o_struct.RCW12_ChB_D0 = 0;
    o_struct.RCW13_ChB_D0 = 0;
    o_struct.RCW14_ChB_D0 = 0;
    o_struct.RCW15_ChB_D0 = 0;
    o_struct.RCW16_ChB_D0 = 0;
    o_struct.RCW17_ChB_D0 = 0;
    o_struct.RCW18_ChB_D0 = 0;
    o_struct.RCW19_ChB_D0 = 0;
    o_struct.RCW1A_ChB_D0 = 0;
    o_struct.RCW1B_ChB_D0 = 0;
    o_struct.RCW1C_ChB_D0 = 0;
    o_struct.RCW1D_ChB_D0 = 0;
    o_struct.RCW1E_ChB_D0 = 0;
    o_struct.RCW1F_ChB_D0 = 0;
    o_struct.RCW20_ChB_D0 = 0;
    o_struct.RCW21_ChB_D0 = 0;
    o_struct.RCW22_ChB_D0 = 0;
    o_struct.RCW23_ChB_D0 = 0;
    o_struct.RCW24_ChB_D0 = 0;
    o_struct.RCW25_ChB_D0 = 0;
    o_struct.RCW26_ChB_D0 = 0;
    o_struct.RCW27_ChB_D0 = 0;
    o_struct.RCW28_ChB_D0 = 0;
    o_struct.RCW29_ChB_D0 = 0;
    o_struct.RCW2A_ChB_D0 = 0;
    o_struct.RCW2B_ChB_D0 = 0;
    o_struct.RCW2C_ChB_D0 = 0;
    o_struct.RCW2D_ChB_D0 = 0;
    o_struct.RCW2E_ChB_D0 = 0;
    o_struct.RCW2F_ChB_D0 = 0;
    o_struct.RCW30_ChB_D0 = 0;
    o_struct.RCW31_ChB_D0 = 0;
    o_struct.RCW32_ChB_D0 = 0;
    o_struct.RCW33_ChB_D0 = 0;
    o_struct.RCW34_ChB_D0 = 0;
    o_struct.RCW35_ChB_D0 = 0;
    o_struct.RCW36_ChB_D0 = 0;
    o_struct.RCW37_ChB_D0 = 0;
    o_struct.RCW38_ChB_D0 = 0;
    o_struct.RCW39_ChB_D0 = 0;
    o_struct.RCW3A_ChB_D0 = 0;
    o_struct.RCW3B_ChB_D0 = 0;
    o_struct.RCW3C_ChB_D0 = 0;
    o_struct.RCW3D_ChB_D0 = 0;
    o_struct.RCW3E_ChB_D0 = 0;
    o_struct.RCW3F_ChB_D0 = 0;
    o_struct.RCW40_ChB_D0 = 0;
    o_struct.RCW41_ChB_D0 = 0;
    o_struct.RCW42_ChB_D0 = 0;
    o_struct.RCW43_ChB_D0 = 0;
    o_struct.RCW44_ChB_D0 = 0;
    o_struct.RCW45_ChB_D0 = 0;
    o_struct.RCW46_ChB_D0 = 0;
    o_struct.RCW47_ChB_D0 = 0;
    o_struct.RCW48_ChB_D0 = 0;
    o_struct.RCW49_ChB_D0 = 0;
    o_struct.RCW4A_ChB_D0 = 0;
    o_struct.RCW4B_ChB_D0 = 0;
    o_struct.RCW4C_ChB_D0 = 0;
    o_struct.RCW4D_ChB_D0 = 0;
    o_struct.RCW4E_ChB_D0 = 0;
    o_struct.RCW4F_ChB_D0 = 0;
    o_struct.RCW50_ChB_D0 = 0;
    o_struct.RCW51_ChB_D0 = 0;
    o_struct.RCW52_ChB_D0 = 0;
    o_struct.RCW53_ChB_D0 = 0;
    o_struct.RCW54_ChB_D0 = 0;
    o_struct.RCW55_ChB_D0 = 0;
    o_struct.RCW56_ChB_D0 = 0;
    o_struct.RCW57_ChB_D0 = 0;
    o_struct.RCW58_ChB_D0 = 0;
    o_struct.RCW59_ChB_D0 = 0;
    o_struct.RCW5A_ChB_D0 = 0;
    o_struct.RCW5B_ChB_D0 = 0;
    o_struct.RCW5C_ChB_D0 = 0;
    o_struct.RCW5D_ChB_D0 = 0;
    o_struct.RCW5E_ChB_D0 = 0;
    o_struct.RCW5F_ChB_D0 = 0;
    o_struct.RCW60_ChB_D0 = 0;
    o_struct.RCW61_ChB_D0 = 0;
    o_struct.RCW62_ChB_D0 = 0;
    o_struct.RCW63_ChB_D0 = 0;
    o_struct.RCW64_ChB_D0 = 0;
    o_struct.RCW65_ChB_D0 = 0;
    o_struct.RCW66_ChB_D0 = 0;
    o_struct.RCW67_ChB_D0 = 0;
    o_struct.RCW68_ChB_D0 = 0;
    o_struct.RCW69_ChB_D0 = 0;
    o_struct.RCW6A_ChB_D0 = 0;
    o_struct.RCW6B_ChB_D0 = 0;
    o_struct.RCW6C_ChB_D0 = 0;
    o_struct.RCW6D_ChB_D0 = 0;
    o_struct.RCW6E_ChB_D0 = 0;
    o_struct.RCW6F_ChB_D0 = 0;
    o_struct.RCW70_ChB_D0 = 0;
    o_struct.RCW71_ChB_D0 = 0;
    o_struct.RCW72_ChB_D0 = 0;
    o_struct.RCW73_ChB_D0 = 0;
    o_struct.RCW74_ChB_D0 = 0;
    o_struct.RCW75_ChB_D0 = 0;
    o_struct.RCW76_ChB_D0 = 0;
    o_struct.RCW77_ChB_D0 = 0;
    o_struct.RCW78_ChB_D0 = 0;
    o_struct.RCW79_ChB_D0 = 0;
    o_struct.RCW7A_ChB_D0 = 0;
    o_struct.RCW7B_ChB_D0 = 0;
    o_struct.RCW7C_ChB_D0 = 0;
    o_struct.RCW7D_ChB_D0 = 0;
    o_struct.RCW7E_ChB_D0 = 0;
    o_struct.RCW7F_ChB_D0 = 0;
    o_struct.BCW00_ChB_D0 = 0;
    o_struct.BCW01_ChB_D0 = 0;
    o_struct.BCW02_ChB_D0 = 0;
    o_struct.BCW03_ChB_D0 = 0;
    o_struct.BCW04_ChB_D0 = 0;
    o_struct.BCW05_ChB_D0 = 0;
    o_struct.BCW06_ChB_D0 = 0;
    o_struct.BCW07_ChB_D0 = 0;
    o_struct.BCW08_ChB_D0 = 0;
    o_struct.BCW09_ChB_D0 = 0;
    o_struct.BCW0A_ChB_D0 = 0;
    o_struct.BCW0B_ChB_D0 = 0;
    o_struct.BCW0C_ChB_D0 = 0;
    o_struct.BCW0D_ChB_D0 = 0;
    o_struct.BCW0E_ChB_D0 = 0;
    o_struct.BCW0F_ChB_D0 = 0;
    o_struct.BCW10_ChB_D0 = 0;
    o_struct.BCW11_ChB_D0 = 0;
    o_struct.BCW12_ChB_D0 = 0;
    o_struct.BCW13_ChB_D0 = 0;
    o_struct.BCW14_ChB_D0 = 0;
    o_struct.BCW15_ChB_D0 = 0;
    o_struct.BCW16_ChB_D0 = 0;
    o_struct.BCW17_ChB_D0 = 0;
    o_struct.BCW18_ChB_D0 = 0;
    o_struct.BCW19_ChB_D0 = 0;
    o_struct.BCW1A_ChB_D0 = 0;
    o_struct.BCW1B_ChB_D0 = 0;
    o_struct.BCW1C_ChB_D0 = 0;
    o_struct.BCW1D_ChB_D0 = 0;
    o_struct.BCW1E_ChB_D0 = 0;
    o_struct.BCW1F_ChB_D0 = 0;
    o_struct.BCW20_ChB_D0 = 0;
    o_struct.BCW21_ChB_D0 = 0;
    o_struct.BCW22_ChB_D0 = 0;
    o_struct.BCW23_ChB_D0 = 0;
    o_struct.BCW24_ChB_D0 = 0;
    o_struct.BCW25_ChB_D0 = 0;
    o_struct.BCW26_ChB_D0 = 0;
    o_struct.BCW27_ChB_D0 = 0;
    o_struct.BCW28_ChB_D0 = 0;
    o_struct.BCW29_ChB_D0 = 0;
    o_struct.BCW2A_ChB_D0 = 0;
    o_struct.BCW2B_ChB_D0 = 0;
    o_struct.BCW2C_ChB_D0 = 0;
    o_struct.BCW2D_ChB_D0 = 0;
    o_struct.BCW2E_ChB_D0 = 0;
    o_struct.BCW2F_ChB_D0 = 0;
    o_struct.BCW30_ChB_D0 = 0;
    o_struct.BCW31_ChB_D0 = 0;
    o_struct.BCW32_ChB_D0 = 0;
    o_struct.BCW33_ChB_D0 = 0;
    o_struct.BCW34_ChB_D0 = 0;
    o_struct.BCW35_ChB_D0 = 0;
    o_struct.BCW36_ChB_D0 = 0;
    o_struct.BCW37_ChB_D0 = 0;
    o_struct.BCW38_ChB_D0 = 0;
    o_struct.BCW39_ChB_D0 = 0;
    o_struct.BCW3A_ChB_D0 = 0;
    o_struct.BCW3B_ChB_D0 = 0;
    o_struct.BCW3C_ChB_D0 = 0;
    o_struct.BCW3D_ChB_D0 = 0;
    o_struct.BCW3E_ChB_D0 = 0;
    o_struct.BCW3F_ChB_D0 = 0;
    o_struct.BCW40_ChB_D0 = 0;
    o_struct.BCW41_ChB_D0 = 0;
    o_struct.BCW42_ChB_D0 = 0;
    o_struct.BCW43_ChB_D0 = 0;
    o_struct.BCW44_ChB_D0 = 0;
    o_struct.BCW45_ChB_D0 = 0;
    o_struct.BCW46_ChB_D0 = 0;
    o_struct.BCW47_ChB_D0 = 0;
    o_struct.BCW48_ChB_D0 = 0;
    o_struct.BCW49_ChB_D0 = 0;
    o_struct.BCW4A_ChB_D0 = 0;
    o_struct.BCW4B_ChB_D0 = 0;
    o_struct.BCW4C_ChB_D0 = 0;
    o_struct.BCW4D_ChB_D0 = 0;
    o_struct.BCW4E_ChB_D0 = 0;
    o_struct.BCW4F_ChB_D0 = 0;
    o_struct.BCW50_ChB_D0 = 0;
    o_struct.BCW51_ChB_D0 = 0;
    o_struct.BCW52_ChB_D0 = 0;
    o_struct.BCW53_ChB_D0 = 0;
    o_struct.BCW54_ChB_D0 = 0;
    o_struct.BCW55_ChB_D0 = 0;
    o_struct.BCW56_ChB_D0 = 0;
    o_struct.BCW57_ChB_D0 = 0;
    o_struct.BCW58_ChB_D0 = 0;
    o_struct.BCW59_ChB_D0 = 0;
    o_struct.BCW5A_ChB_D0 = 0;
    o_struct.BCW5B_ChB_D0 = 0;
    o_struct.BCW5C_ChB_D0 = 0;
    o_struct.BCW5D_ChB_D0 = 0;
    o_struct.BCW5E_ChB_D0 = 0;
    o_struct.BCW5F_ChB_D0 = 0;
    o_struct.BCW60_ChB_D0 = 0;
    o_struct.BCW61_ChB_D0 = 0;
    o_struct.BCW62_ChB_D0 = 0;
    o_struct.BCW63_ChB_D0 = 0;
    o_struct.BCW64_ChB_D0 = 0;
    o_struct.BCW65_ChB_D0 = 0;
    o_struct.BCW66_ChB_D0 = 0;
    o_struct.BCW67_ChB_D0 = 0;
    o_struct.BCW68_ChB_D0 = 0;
    o_struct.BCW69_ChB_D0 = 0;
    o_struct.BCW6A_ChB_D0 = 0;
    o_struct.BCW6B_ChB_D0 = 0;
    o_struct.BCW6C_ChB_D0 = 0;
    o_struct.BCW6D_ChB_D0 = 0;
    o_struct.BCW6E_ChB_D0 = 0;
    o_struct.BCW6F_ChB_D0 = 0;
    o_struct.BCW70_ChB_D0 = 0;
    o_struct.BCW71_ChB_D0 = 0;
    o_struct.BCW72_ChB_D0 = 0;
    o_struct.BCW73_ChB_D0 = 0;
    o_struct.BCW74_ChB_D0 = 0;
    o_struct.BCW75_ChB_D0 = 0;
    o_struct.BCW76_ChB_D0 = 0;
    o_struct.BCW77_ChB_D0 = 0;
    o_struct.BCW78_ChB_D0 = 0;
    o_struct.BCW79_ChB_D0 = 0;
    o_struct.BCW7A_ChB_D0 = 0;
    o_struct.BCW7B_ChB_D0 = 0;
    o_struct.BCW7C_ChB_D0 = 0;
    o_struct.BCW7D_ChB_D0 = 0;
    o_struct.BCW7E_ChB_D0 = 0;
    o_struct.BCW7F_ChB_D0 = 0;
    o_struct.RCW00_ChB_D1 = 0;
    o_struct.RCW01_ChB_D1 = 0;
    o_struct.RCW02_ChB_D1 = 0;
    o_struct.RCW03_ChB_D1 = 0;
    o_struct.RCW04_ChB_D1 = 0;
    o_struct.RCW05_ChB_D1 = 0;
    o_struct.RCW06_ChB_D1 = 0;
    o_struct.RCW07_ChB_D1 = 0;
    o_struct.RCW08_ChB_D1 = 0;
    o_struct.RCW09_ChB_D1 = 0;
    o_struct.RCW0A_ChB_D1 = 0;
    o_struct.RCW0B_ChB_D1 = 0;
    o_struct.RCW0C_ChB_D1 = 0;
    o_struct.RCW0D_ChB_D1 = 0;
    o_struct.RCW0E_ChB_D1 = 0;
    o_struct.RCW0F_ChB_D1 = 0;
    o_struct.RCW10_ChB_D1 = 0;
    o_struct.RCW11_ChB_D1 = 0;
    o_struct.RCW12_ChB_D1 = 0;
    o_struct.RCW13_ChB_D1 = 0;
    o_struct.RCW14_ChB_D1 = 0;
    o_struct.RCW15_ChB_D1 = 0;
    o_struct.RCW16_ChB_D1 = 0;
    o_struct.RCW17_ChB_D1 = 0;
    o_struct.RCW18_ChB_D1 = 0;
    o_struct.RCW19_ChB_D1 = 0;
    o_struct.RCW1A_ChB_D1 = 0;
    o_struct.RCW1B_ChB_D1 = 0;
    o_struct.RCW1C_ChB_D1 = 0;
    o_struct.RCW1D_ChB_D1 = 0;
    o_struct.RCW1E_ChB_D1 = 0;
    o_struct.RCW1F_ChB_D1 = 0;
    o_struct.RCW20_ChB_D1 = 0;
    o_struct.RCW21_ChB_D1 = 0;
    o_struct.RCW22_ChB_D1 = 0;
    o_struct.RCW23_ChB_D1 = 0;
    o_struct.RCW24_ChB_D1 = 0;
    o_struct.RCW25_ChB_D1 = 0;
    o_struct.RCW26_ChB_D1 = 0;
    o_struct.RCW27_ChB_D1 = 0;
    o_struct.RCW28_ChB_D1 = 0;
    o_struct.RCW29_ChB_D1 = 0;
    o_struct.RCW2A_ChB_D1 = 0;
    o_struct.RCW2B_ChB_D1 = 0;
    o_struct.RCW2C_ChB_D1 = 0;
    o_struct.RCW2D_ChB_D1 = 0;
    o_struct.RCW2E_ChB_D1 = 0;
    o_struct.RCW2F_ChB_D1 = 0;
    o_struct.RCW30_ChB_D1 = 0;
    o_struct.RCW31_ChB_D1 = 0;
    o_struct.RCW32_ChB_D1 = 0;
    o_struct.RCW33_ChB_D1 = 0;
    o_struct.RCW34_ChB_D1 = 0;
    o_struct.RCW35_ChB_D1 = 0;
    o_struct.RCW36_ChB_D1 = 0;
    o_struct.RCW37_ChB_D1 = 0;
    o_struct.RCW38_ChB_D1 = 0;
    o_struct.RCW39_ChB_D1 = 0;
    o_struct.RCW3A_ChB_D1 = 0;
    o_struct.RCW3B_ChB_D1 = 0;
    o_struct.RCW3C_ChB_D1 = 0;
    o_struct.RCW3D_ChB_D1 = 0;
    o_struct.RCW3E_ChB_D1 = 0;
    o_struct.RCW3F_ChB_D1 = 0;
    o_struct.RCW40_ChB_D1 = 0;
    o_struct.RCW41_ChB_D1 = 0;
    o_struct.RCW42_ChB_D1 = 0;
    o_struct.RCW43_ChB_D1 = 0;
    o_struct.RCW44_ChB_D1 = 0;
    o_struct.RCW45_ChB_D1 = 0;
    o_struct.RCW46_ChB_D1 = 0;
    o_struct.RCW47_ChB_D1 = 0;
    o_struct.RCW48_ChB_D1 = 0;
    o_struct.RCW49_ChB_D1 = 0;
    o_struct.RCW4A_ChB_D1 = 0;
    o_struct.RCW4B_ChB_D1 = 0;
    o_struct.RCW4C_ChB_D1 = 0;
    o_struct.RCW4D_ChB_D1 = 0;
    o_struct.RCW4E_ChB_D1 = 0;
    o_struct.RCW4F_ChB_D1 = 0;
    o_struct.RCW50_ChB_D1 = 0;
    o_struct.RCW51_ChB_D1 = 0;
    o_struct.RCW52_ChB_D1 = 0;
    o_struct.RCW53_ChB_D1 = 0;
    o_struct.RCW54_ChB_D1 = 0;
    o_struct.RCW55_ChB_D1 = 0;
    o_struct.RCW56_ChB_D1 = 0;
    o_struct.RCW57_ChB_D1 = 0;
    o_struct.RCW58_ChB_D1 = 0;
    o_struct.RCW59_ChB_D1 = 0;
    o_struct.RCW5A_ChB_D1 = 0;
    o_struct.RCW5B_ChB_D1 = 0;
    o_struct.RCW5C_ChB_D1 = 0;
    o_struct.RCW5D_ChB_D1 = 0;
    o_struct.RCW5E_ChB_D1 = 0;
    o_struct.RCW5F_ChB_D1 = 0;
    o_struct.RCW60_ChB_D1 = 0;
    o_struct.RCW61_ChB_D1 = 0;
    o_struct.RCW62_ChB_D1 = 0;
    o_struct.RCW63_ChB_D1 = 0;
    o_struct.RCW64_ChB_D1 = 0;
    o_struct.RCW65_ChB_D1 = 0;
    o_struct.RCW66_ChB_D1 = 0;
    o_struct.RCW67_ChB_D1 = 0;
    o_struct.RCW68_ChB_D1 = 0;
    o_struct.RCW69_ChB_D1 = 0;
    o_struct.RCW6A_ChB_D1 = 0;
    o_struct.RCW6B_ChB_D1 = 0;
    o_struct.RCW6C_ChB_D1 = 0;
    o_struct.RCW6D_ChB_D1 = 0;
    o_struct.RCW6E_ChB_D1 = 0;
    o_struct.RCW6F_ChB_D1 = 0;
    o_struct.RCW70_ChB_D1 = 0;
    o_struct.RCW71_ChB_D1 = 0;
    o_struct.RCW72_ChB_D1 = 0;
    o_struct.RCW73_ChB_D1 = 0;
    o_struct.RCW74_ChB_D1 = 0;
    o_struct.RCW75_ChB_D1 = 0;
    o_struct.RCW76_ChB_D1 = 0;
    o_struct.RCW77_ChB_D1 = 0;
    o_struct.RCW78_ChB_D1 = 0;
    o_struct.RCW79_ChB_D1 = 0;
    o_struct.RCW7A_ChB_D1 = 0;
    o_struct.RCW7B_ChB_D1 = 0;
    o_struct.RCW7C_ChB_D1 = 0;
    o_struct.RCW7D_ChB_D1 = 0;
    o_struct.RCW7E_ChB_D1 = 0;
    o_struct.RCW7F_ChB_D1 = 0;
    o_struct.BCW00_ChB_D1 = 0;
    o_struct.BCW01_ChB_D1 = 0;
    o_struct.BCW02_ChB_D1 = 0;
    o_struct.BCW03_ChB_D1 = 0;
    o_struct.BCW04_ChB_D1 = 0;
    o_struct.BCW05_ChB_D1 = 0;
    o_struct.BCW06_ChB_D1 = 0;
    o_struct.BCW07_ChB_D1 = 0;
    o_struct.BCW08_ChB_D1 = 0;
    o_struct.BCW09_ChB_D1 = 0;
    o_struct.BCW0A_ChB_D1 = 0;
    o_struct.BCW0B_ChB_D1 = 0;
    o_struct.BCW0C_ChB_D1 = 0;
    o_struct.BCW0D_ChB_D1 = 0;
    o_struct.BCW0E_ChB_D1 = 0;
    o_struct.BCW0F_ChB_D1 = 0;
    o_struct.BCW10_ChB_D1 = 0;
    o_struct.BCW11_ChB_D1 = 0;
    o_struct.BCW12_ChB_D1 = 0;
    o_struct.BCW13_ChB_D1 = 0;
    o_struct.BCW14_ChB_D1 = 0;
    o_struct.BCW15_ChB_D1 = 0;
    o_struct.BCW16_ChB_D1 = 0;
    o_struct.BCW17_ChB_D1 = 0;
    o_struct.BCW18_ChB_D1 = 0;
    o_struct.BCW19_ChB_D1 = 0;
    o_struct.BCW1A_ChB_D1 = 0;
    o_struct.BCW1B_ChB_D1 = 0;
    o_struct.BCW1C_ChB_D1 = 0;
    o_struct.BCW1D_ChB_D1 = 0;
    o_struct.BCW1E_ChB_D1 = 0;
    o_struct.BCW1F_ChB_D1 = 0;
    o_struct.BCW20_ChB_D1 = 0;
    o_struct.BCW21_ChB_D1 = 0;
    o_struct.BCW22_ChB_D1 = 0;
    o_struct.BCW23_ChB_D1 = 0;
    o_struct.BCW24_ChB_D1 = 0;
    o_struct.BCW25_ChB_D1 = 0;
    o_struct.BCW26_ChB_D1 = 0;
    o_struct.BCW27_ChB_D1 = 0;
    o_struct.BCW28_ChB_D1 = 0;
    o_struct.BCW29_ChB_D1 = 0;
    o_struct.BCW2A_ChB_D1 = 0;
    o_struct.BCW2B_ChB_D1 = 0;
    o_struct.BCW2C_ChB_D1 = 0;
    o_struct.BCW2D_ChB_D1 = 0;
    o_struct.BCW2E_ChB_D1 = 0;
    o_struct.BCW2F_ChB_D1 = 0;
    o_struct.BCW30_ChB_D1 = 0;
    o_struct.BCW31_ChB_D1 = 0;
    o_struct.BCW32_ChB_D1 = 0;
    o_struct.BCW33_ChB_D1 = 0;
    o_struct.BCW34_ChB_D1 = 0;
    o_struct.BCW35_ChB_D1 = 0;
    o_struct.BCW36_ChB_D1 = 0;
    o_struct.BCW37_ChB_D1 = 0;
    o_struct.BCW38_ChB_D1 = 0;
    o_struct.BCW39_ChB_D1 = 0;
    o_struct.BCW3A_ChB_D1 = 0;
    o_struct.BCW3B_ChB_D1 = 0;
    o_struct.BCW3C_ChB_D1 = 0;
    o_struct.BCW3D_ChB_D1 = 0;
    o_struct.BCW3E_ChB_D1 = 0;
    o_struct.BCW3F_ChB_D1 = 0;
    o_struct.BCW40_ChB_D1 = 0;
    o_struct.BCW41_ChB_D1 = 0;
    o_struct.BCW42_ChB_D1 = 0;
    o_struct.BCW43_ChB_D1 = 0;
    o_struct.BCW44_ChB_D1 = 0;
    o_struct.BCW45_ChB_D1 = 0;
    o_struct.BCW46_ChB_D1 = 0;
    o_struct.BCW47_ChB_D1 = 0;
    o_struct.BCW48_ChB_D1 = 0;
    o_struct.BCW49_ChB_D1 = 0;
    o_struct.BCW4A_ChB_D1 = 0;
    o_struct.BCW4B_ChB_D1 = 0;
    o_struct.BCW4C_ChB_D1 = 0;
    o_struct.BCW4D_ChB_D1 = 0;
    o_struct.BCW4E_ChB_D1 = 0;
    o_struct.BCW4F_ChB_D1 = 0;
    o_struct.BCW50_ChB_D1 = 0;
    o_struct.BCW51_ChB_D1 = 0;
    o_struct.BCW52_ChB_D1 = 0;
    o_struct.BCW53_ChB_D1 = 0;
    o_struct.BCW54_ChB_D1 = 0;
    o_struct.BCW55_ChB_D1 = 0;
    o_struct.BCW56_ChB_D1 = 0;
    o_struct.BCW57_ChB_D1 = 0;
    o_struct.BCW58_ChB_D1 = 0;
    o_struct.BCW59_ChB_D1 = 0;
    o_struct.BCW5A_ChB_D1 = 0;
    o_struct.BCW5B_ChB_D1 = 0;
    o_struct.BCW5C_ChB_D1 = 0;
    o_struct.BCW5D_ChB_D1 = 0;
    o_struct.BCW5E_ChB_D1 = 0;
    o_struct.BCW5F_ChB_D1 = 0;
    o_struct.BCW60_ChB_D1 = 0;
    o_struct.BCW61_ChB_D1 = 0;
    o_struct.BCW62_ChB_D1 = 0;
    o_struct.BCW63_ChB_D1 = 0;
    o_struct.BCW64_ChB_D1 = 0;
    o_struct.BCW65_ChB_D1 = 0;
    o_struct.BCW66_ChB_D1 = 0;
    o_struct.BCW67_ChB_D1 = 0;
    o_struct.BCW68_ChB_D1 = 0;
    o_struct.BCW69_ChB_D1 = 0;
    o_struct.BCW6A_ChB_D1 = 0;
    o_struct.BCW6B_ChB_D1 = 0;
    o_struct.BCW6C_ChB_D1 = 0;
    o_struct.BCW6D_ChB_D1 = 0;
    o_struct.BCW6E_ChB_D1 = 0;
    o_struct.BCW6F_ChB_D1 = 0;
    o_struct.BCW70_ChB_D1 = 0;
    o_struct.BCW71_ChB_D1 = 0;
    o_struct.BCW72_ChB_D1 = 0;
    o_struct.BCW73_ChB_D1 = 0;
    o_struct.BCW74_ChB_D1 = 0;
    o_struct.BCW75_ChB_D1 = 0;
    o_struct.BCW76_ChB_D1 = 0;
    o_struct.BCW77_ChB_D1 = 0;
    o_struct.BCW78_ChB_D1 = 0;
    o_struct.BCW79_ChB_D1 = 0;
    o_struct.BCW7A_ChB_D1 = 0;
    o_struct.BCW7B_ChB_D1 = 0;
    o_struct.BCW7C_ChB_D1 = 0;
    o_struct.BCW7D_ChB_D1 = 0;
    o_struct.BCW7E_ChB_D1 = 0;
    o_struct.BCW7F_ChB_D1 = 0;

    // Note: copied the 0 values over from PHY init -> this is due to MsgMisc's UsePerDeviceVrefDq being set to a 0
    o_struct.VrefDqR0Nib0 = 0;
    o_struct.VrefDqR0Nib1 = 0;
    o_struct.VrefDqR0Nib2 = 0;
    o_struct.VrefDqR0Nib3 = 0;
    o_struct.VrefDqR0Nib4 = 0;
    o_struct.VrefDqR0Nib5 = 0;
    o_struct.VrefDqR0Nib6 = 0;
    o_struct.VrefDqR0Nib7 = 0;
    o_struct.VrefDqR0Nib8 = 0;
    o_struct.VrefDqR0Nib9 = 0;
    o_struct.VrefDqR0Nib10 = 0;
    o_struct.VrefDqR0Nib11 = 0;
    o_struct.VrefDqR0Nib12 = 0;
    o_struct.VrefDqR0Nib13 = 0;
    o_struct.VrefDqR0Nib14 = 0;
    o_struct.VrefDqR0Nib15 = 0;
    o_struct.VrefDqR0Nib16 = 0;
    o_struct.VrefDqR0Nib17 = 0;
    o_struct.VrefDqR0Nib18 = 0;
    o_struct.VrefDqR0Nib19 = 0;
    o_struct.VrefDqR1Nib0 = 0;
    o_struct.VrefDqR1Nib1 = 0;
    o_struct.VrefDqR1Nib2 = 0;
    o_struct.VrefDqR1Nib3 = 0;
    o_struct.VrefDqR1Nib4 = 0;
    o_struct.VrefDqR1Nib5 = 0;
    o_struct.VrefDqR1Nib6 = 0;
    o_struct.VrefDqR1Nib7 = 0;
    o_struct.VrefDqR1Nib8 = 0;
    o_struct.VrefDqR1Nib9 = 0;
    o_struct.VrefDqR1Nib10 = 0;
    o_struct.VrefDqR1Nib11 = 0;
    o_struct.VrefDqR1Nib12 = 0;
    o_struct.VrefDqR1Nib13 = 0;
    o_struct.VrefDqR1Nib14 = 0;
    o_struct.VrefDqR1Nib15 = 0;
    o_struct.VrefDqR1Nib16 = 0;
    o_struct.VrefDqR1Nib17 = 0;
    o_struct.VrefDqR1Nib18 = 0;
    o_struct.VrefDqR1Nib19 = 0;
    o_struct.VrefDqR2Nib0 = 0;
    o_struct.VrefDqR2Nib1 = 0;
    o_struct.VrefDqR2Nib2 = 0;
    o_struct.VrefDqR2Nib3 = 0;
    o_struct.VrefDqR2Nib4 = 0;
    o_struct.VrefDqR2Nib5 = 0;
    o_struct.VrefDqR2Nib6 = 0;
    o_struct.VrefDqR2Nib7 = 0;
    o_struct.VrefDqR2Nib8 = 0;
    o_struct.VrefDqR2Nib9 = 0;
    o_struct.VrefDqR2Nib10 = 0;
    o_struct.VrefDqR2Nib11 = 0;
    o_struct.VrefDqR2Nib12 = 0;
    o_struct.VrefDqR2Nib13 = 0;
    o_struct.VrefDqR2Nib14 = 0;
    o_struct.VrefDqR2Nib15 = 0;
    o_struct.VrefDqR2Nib16 = 0;
    o_struct.VrefDqR2Nib17 = 0;
    o_struct.VrefDqR2Nib18 = 0;
    o_struct.VrefDqR2Nib19 = 0;
    o_struct.VrefDqR3Nib0 = 0;
    o_struct.VrefDqR3Nib1 = 0;
    o_struct.VrefDqR3Nib2 = 0;
    o_struct.VrefDqR3Nib3 = 0;
    o_struct.VrefDqR3Nib4 = 0;
    o_struct.VrefDqR3Nib5 = 0;
    o_struct.VrefDqR3Nib6 = 0;
    o_struct.VrefDqR3Nib7 = 0;
    o_struct.VrefDqR3Nib8 = 0;
    o_struct.VrefDqR3Nib9 = 0;
    o_struct.VrefDqR3Nib10 = 0;
    o_struct.VrefDqR3Nib11 = 0;
    o_struct.VrefDqR3Nib12 = 0;
    o_struct.VrefDqR3Nib13 = 0;
    o_struct.VrefDqR3Nib14 = 0;
    o_struct.VrefDqR3Nib15 = 0;
    o_struct.VrefDqR3Nib16 = 0;
    o_struct.VrefDqR3Nib17 = 0;
    o_struct.VrefDqR3Nib18 = 0;
    o_struct.VrefDqR3Nib19 = 0;

    // Note: the MR's are moved to their separate section just for clarity

    // Note: not seeing these set in PHY init and that seems incorrect
    o_struct.VrefCSR0Nib0 = 0;
    o_struct.VrefCSR0Nib1 = 0;
    o_struct.VrefCSR0Nib2 = 0;
    o_struct.VrefCSR0Nib3 = 0;
    o_struct.VrefCSR0Nib4 = 0;
    o_struct.VrefCSR0Nib5 = 0;
    o_struct.VrefCSR0Nib6 = 0;
    o_struct.VrefCSR0Nib7 = 0;
    o_struct.VrefCSR0Nib8 = 0;
    o_struct.VrefCSR0Nib9 = 0;
    o_struct.VrefCSR0Nib10 = 0;
    o_struct.VrefCSR0Nib11 = 0;
    o_struct.VrefCSR0Nib12 = 0;
    o_struct.VrefCSR0Nib13 = 0;
    o_struct.VrefCSR0Nib14 = 0;
    o_struct.VrefCSR0Nib15 = 0;
    o_struct.VrefCSR0Nib16 = 0;
    o_struct.VrefCSR0Nib17 = 0;
    o_struct.VrefCSR0Nib18 = 0;
    o_struct.VrefCSR0Nib19 = 0;
    o_struct.VrefCSR1Nib0 = 0;
    o_struct.VrefCSR1Nib1 = 0;
    o_struct.VrefCSR1Nib2 = 0;
    o_struct.VrefCSR1Nib3 = 0;
    o_struct.VrefCSR1Nib4 = 0;
    o_struct.VrefCSR1Nib5 = 0;
    o_struct.VrefCSR1Nib6 = 0;
    o_struct.VrefCSR1Nib7 = 0;
    o_struct.VrefCSR1Nib8 = 0;
    o_struct.VrefCSR1Nib9 = 0;
    o_struct.VrefCSR1Nib10 = 0;
    o_struct.VrefCSR1Nib11 = 0;
    o_struct.VrefCSR1Nib12 = 0;
    o_struct.VrefCSR1Nib13 = 0;
    o_struct.VrefCSR1Nib14 = 0;
    o_struct.VrefCSR1Nib15 = 0;
    o_struct.VrefCSR1Nib16 = 0;
    o_struct.VrefCSR1Nib17 = 0;
    o_struct.VrefCSR1Nib18 = 0;
    o_struct.VrefCSR1Nib19 = 0;
    o_struct.VrefCSR2Nib0 = 0;
    o_struct.VrefCSR2Nib1 = 0;
    o_struct.VrefCSR2Nib2 = 0;
    o_struct.VrefCSR2Nib3 = 0;
    o_struct.VrefCSR2Nib4 = 0;
    o_struct.VrefCSR2Nib5 = 0;
    o_struct.VrefCSR2Nib6 = 0;
    o_struct.VrefCSR2Nib7 = 0;
    o_struct.VrefCSR2Nib8 = 0;
    o_struct.VrefCSR2Nib9 = 0;
    o_struct.VrefCSR2Nib10 = 0;
    o_struct.VrefCSR2Nib11 = 0;
    o_struct.VrefCSR2Nib12 = 0;
    o_struct.VrefCSR2Nib13 = 0;
    o_struct.VrefCSR2Nib14 = 0;
    o_struct.VrefCSR2Nib15 = 0;
    o_struct.VrefCSR2Nib16 = 0;
    o_struct.VrefCSR2Nib17 = 0;
    o_struct.VrefCSR2Nib18 = 0;
    o_struct.VrefCSR2Nib19 = 0;
    o_struct.VrefCSR3Nib0 = 0;
    o_struct.VrefCSR3Nib1 = 0;
    o_struct.VrefCSR3Nib2 = 0;
    o_struct.VrefCSR3Nib3 = 0;
    o_struct.VrefCSR3Nib4 = 0;
    o_struct.VrefCSR3Nib5 = 0;
    o_struct.VrefCSR3Nib6 = 0;
    o_struct.VrefCSR3Nib7 = 0;
    o_struct.VrefCSR3Nib8 = 0;
    o_struct.VrefCSR3Nib9 = 0;
    o_struct.VrefCSR3Nib10 = 0;
    o_struct.VrefCSR3Nib11 = 0;
    o_struct.VrefCSR3Nib12 = 0;
    o_struct.VrefCSR3Nib13 = 0;
    o_struct.VrefCSR3Nib14 = 0;
    o_struct.VrefCSR3Nib15 = 0;
    o_struct.VrefCSR3Nib16 = 0;
    o_struct.VrefCSR3Nib17 = 0;
    o_struct.VrefCSR3Nib18 = 0;
    o_struct.VrefCSR3Nib19 = 0;
    o_struct.VrefCAR0Nib0 = 0;
    o_struct.VrefCAR0Nib1 = 0;
    o_struct.VrefCAR0Nib2 = 0;
    o_struct.VrefCAR0Nib3 = 0;
    o_struct.VrefCAR0Nib4 = 0;
    o_struct.VrefCAR0Nib5 = 0;
    o_struct.VrefCAR0Nib6 = 0;
    o_struct.VrefCAR0Nib7 = 0;
    o_struct.VrefCAR0Nib8 = 0;
    o_struct.VrefCAR0Nib9 = 0;
    o_struct.VrefCAR0Nib10 = 0;
    o_struct.VrefCAR0Nib11 = 0;
    o_struct.VrefCAR0Nib12 = 0;
    o_struct.VrefCAR0Nib13 = 0;
    o_struct.VrefCAR0Nib14 = 0;
    o_struct.VrefCAR0Nib15 = 0;
    o_struct.VrefCAR0Nib16 = 0;
    o_struct.VrefCAR0Nib17 = 0;
    o_struct.VrefCAR0Nib18 = 0;
    o_struct.VrefCAR0Nib19 = 0;
    o_struct.VrefCAR1Nib0 = 0;
    o_struct.VrefCAR1Nib1 = 0;
    o_struct.VrefCAR1Nib2 = 0;
    o_struct.VrefCAR1Nib3 = 0;
    o_struct.VrefCAR1Nib4 = 0;
    o_struct.VrefCAR1Nib5 = 0;
    o_struct.VrefCAR1Nib6 = 0;
    o_struct.VrefCAR1Nib7 = 0;
    o_struct.VrefCAR1Nib8 = 0;
    o_struct.VrefCAR1Nib9 = 0;
    o_struct.VrefCAR1Nib10 = 0;
    o_struct.VrefCAR1Nib11 = 0;
    o_struct.VrefCAR1Nib12 = 0;
    o_struct.VrefCAR1Nib13 = 0;
    o_struct.VrefCAR1Nib14 = 0;
    o_struct.VrefCAR1Nib15 = 0;
    o_struct.VrefCAR1Nib16 = 0;
    o_struct.VrefCAR1Nib17 = 0;
    o_struct.VrefCAR1Nib18 = 0;
    o_struct.VrefCAR1Nib19 = 0;
    o_struct.VrefCAR2Nib0 = 0;
    o_struct.VrefCAR2Nib1 = 0;
    o_struct.VrefCAR2Nib2 = 0;
    o_struct.VrefCAR2Nib3 = 0;
    o_struct.VrefCAR2Nib4 = 0;
    o_struct.VrefCAR2Nib5 = 0;
    o_struct.VrefCAR2Nib6 = 0;
    o_struct.VrefCAR2Nib7 = 0;
    o_struct.VrefCAR2Nib8 = 0;
    o_struct.VrefCAR2Nib9 = 0;
    o_struct.VrefCAR2Nib10 = 0;
    o_struct.VrefCAR2Nib11 = 0;
    o_struct.VrefCAR2Nib12 = 0;
    o_struct.VrefCAR2Nib13 = 0;
    o_struct.VrefCAR2Nib14 = 0;
    o_struct.VrefCAR2Nib15 = 0;
    o_struct.VrefCAR2Nib16 = 0;
    o_struct.VrefCAR2Nib17 = 0;
    o_struct.VrefCAR2Nib18 = 0;
    o_struct.VrefCAR2Nib19 = 0;
    o_struct.VrefCAR3Nib0 = 0;
    o_struct.VrefCAR3Nib1 = 0;
    o_struct.VrefCAR3Nib2 = 0;
    o_struct.VrefCAR3Nib3 = 0;
    o_struct.VrefCAR3Nib4 = 0;
    o_struct.VrefCAR3Nib5 = 0;
    o_struct.VrefCAR3Nib6 = 0;
    o_struct.VrefCAR3Nib7 = 0;
    o_struct.VrefCAR3Nib8 = 0;
    o_struct.VrefCAR3Nib9 = 0;
    o_struct.VrefCAR3Nib10 = 0;
    o_struct.VrefCAR3Nib11 = 0;
    o_struct.VrefCAR3Nib12 = 0;
    o_struct.VrefCAR3Nib13 = 0;
    o_struct.VrefCAR3Nib14 = 0;
    o_struct.VrefCAR3Nib15 = 0;
    o_struct.VrefCAR3Nib16 = 0;
    o_struct.VrefCAR3Nib17 = 0;
    o_struct.VrefCAR3Nib18 = 0;
    o_struct.VrefCAR3Nib19 = 0;

    // No lanes disabled
    o_struct.DisabledDB0LaneR0 = 0;
    o_struct.DisabledDB1LaneR0 = 0;
    o_struct.DisabledDB2LaneR0 = 0;
    o_struct.DisabledDB3LaneR0 = 0;
    o_struct.DisabledDB4LaneR0 = 0;
    o_struct.DisabledDB5LaneR0 = 0;
    o_struct.DisabledDB6LaneR0 = 0;
    o_struct.DisabledDB7LaneR0 = 0;
    o_struct.DisabledDB8LaneR0 = 0;
    o_struct.DisabledDB9LaneR0 = 0;
    o_struct.DisabledDB0LaneR1 = 0;
    o_struct.DisabledDB1LaneR1 = 0;
    o_struct.DisabledDB2LaneR1 = 0;
    o_struct.DisabledDB3LaneR1 = 0;
    o_struct.DisabledDB4LaneR1 = 0;
    o_struct.DisabledDB5LaneR1 = 0;
    o_struct.DisabledDB6LaneR1 = 0;
    o_struct.DisabledDB7LaneR1 = 0;
    o_struct.DisabledDB8LaneR1 = 0;
    o_struct.DisabledDB9LaneR1 = 0;
    o_struct.DisabledDB0LaneR2 = 0;
    o_struct.DisabledDB1LaneR2 = 0;
    o_struct.DisabledDB2LaneR2 = 0;
    o_struct.DisabledDB3LaneR2 = 0;
    o_struct.DisabledDB4LaneR2 = 0;
    o_struct.DisabledDB5LaneR2 = 0;
    o_struct.DisabledDB6LaneR2 = 0;
    o_struct.DisabledDB7LaneR2 = 0;
    o_struct.DisabledDB8LaneR2 = 0;
    o_struct.DisabledDB9LaneR2 = 0;
    o_struct.DisabledDB0LaneR3 = 0;
    o_struct.DisabledDB1LaneR3 = 0;
    o_struct.DisabledDB2LaneR3 = 0;
    o_struct.DisabledDB3LaneR3 = 0;
    o_struct.DisabledDB4LaneR3 = 0;
    o_struct.DisabledDB5LaneR3 = 0;
    o_struct.DisabledDB6LaneR3 = 0;
    o_struct.DisabledDB7LaneR3 = 0;
    o_struct.DisabledDB8LaneR3 = 0;
    o_struct.DisabledDB9LaneR3 = 0;
    o_struct.QCS_Dly_Margin_A0 = 0;
    o_struct.QCA_Dly_Margin_A0 = 0;
    o_struct.QCS_Dly_Margin_A1 = 0;
    o_struct.QCA_Dly_Margin_A1 = 0;
    o_struct.QCS_Dly_Margin_A2 = 0;
    o_struct.QCA_Dly_Margin_A2 = 0;
    o_struct.QCS_Dly_Margin_A3 = 0;
    o_struct.QCA_Dly_Margin_A3 = 0;
    o_struct.QCS_Dly_Margin_B0 = 0;
    o_struct.QCA_Dly_Margin_B0 = 0;
    o_struct.QCS_Dly_Margin_B1 = 0;
    o_struct.QCA_Dly_Margin_B1 = 0;
    o_struct.QCS_Dly_Margin_B2 = 0;
    o_struct.QCA_Dly_Margin_B2 = 0;
    o_struct.QCS_Dly_Margin_B3 = 0;
    o_struct.QCA_Dly_Margin_B3 = 0;
    o_struct.PmuInternalRev0 = 0;
    o_struct.PmuInternalRev1 = 0;

    // Initializes the MR values - splitting this off so it's easy to see
    {
        // MR0 is a 24 to correspond with CL=40
        o_struct.MR0_A0 = 0x24;
        o_struct.MR0_A1 = 0x24;
        o_struct.MR0_A2 = 0x24;
        o_struct.MR0_A3 = 0x24;
        o_struct.MR0_B0 = 0x24;
        o_struct.MR0_B1 = 0x24;
        o_struct.MR0_B2 = 0x24;
        o_struct.MR0_B3 = 0x24;

        // Internal write timing and CS assertion during MPC are both 1's
        o_struct.MR2_A0 = 0x90;
        o_struct.MR2_A1 = 0x90;
        o_struct.MR2_A2 = 0x90;
        o_struct.MR2_A3 = 0x90;
        o_struct.MR2_B0 = 0x90;
        o_struct.MR2_B1 = 0x90;
        o_struct.MR2_B2 = 0x90;
        o_struct.MR2_B3 = 0x90;

        // No internal cycle alignments yet
        o_struct.MR3_A0 = 0;
        o_struct.MR3_A1 = 0;
        o_struct.MR3_A2 = 0;
        o_struct.MR3_A3 = 0;
        o_struct.MR3_B0 = 0;
        o_struct.MR3_B1 = 0;
        o_struct.MR3_B2 = 0;
        o_struct.MR3_B3 = 0;
        o_struct.MR3R0Nib0 = 0;
        o_struct.MR3R0Nib1 = 0;
        o_struct.MR3R0Nib10 = 0;
        o_struct.MR3R0Nib11 = 0;
        o_struct.MR3R0Nib12 = 0;
        o_struct.MR3R0Nib13 = 0;
        o_struct.MR3R0Nib14 = 0;
        o_struct.MR3R0Nib15 = 0;
        o_struct.MR3R0Nib16 = 0;
        o_struct.MR3R0Nib17 = 0;
        o_struct.MR3R0Nib18 = 0;
        o_struct.MR3R0Nib19 = 0;
        o_struct.MR3R0Nib2 = 0;
        o_struct.MR3R0Nib3 = 0;
        o_struct.MR3R0Nib4 = 0;
        o_struct.MR3R0Nib5 = 0;
        o_struct.MR3R0Nib6 = 0;
        o_struct.MR3R0Nib7 = 0;
        o_struct.MR3R0Nib8 = 0;
        o_struct.MR3R0Nib9 = 0;
        o_struct.MR3R1Nib0 = 0;
        o_struct.MR3R1Nib1 = 0;
        o_struct.MR3R1Nib10 = 0;
        o_struct.MR3R1Nib11 = 0;
        o_struct.MR3R1Nib12 = 0;
        o_struct.MR3R1Nib13 = 0;
        o_struct.MR3R1Nib14 = 0;
        o_struct.MR3R1Nib15 = 0;
        o_struct.MR3R1Nib16 = 0;
        o_struct.MR3R1Nib17 = 0;
        o_struct.MR3R1Nib18 = 0;
        o_struct.MR3R1Nib19 = 0;
        o_struct.MR3R1Nib2 = 0;
        o_struct.MR3R1Nib3 = 0;
        o_struct.MR3R1Nib4 = 0;
        o_struct.MR3R1Nib5 = 0;
        o_struct.MR3R1Nib6 = 0;
        o_struct.MR3R1Nib7 = 0;
        o_struct.MR3R1Nib8 = 0;
        o_struct.MR3R1Nib9 = 0;
        o_struct.MR3R2Nib0 = 0;
        o_struct.MR3R2Nib1 = 0;
        o_struct.MR3R2Nib10 = 0;
        o_struct.MR3R2Nib11 = 0;
        o_struct.MR3R2Nib12 = 0;
        o_struct.MR3R2Nib13 = 0;
        o_struct.MR3R2Nib14 = 0;
        o_struct.MR3R2Nib15 = 0;
        o_struct.MR3R2Nib16 = 0;
        o_struct.MR3R2Nib17 = 0;
        o_struct.MR3R2Nib18 = 0;
        o_struct.MR3R2Nib19 = 0;
        o_struct.MR3R2Nib2 = 0;
        o_struct.MR3R2Nib3 = 0;
        o_struct.MR3R2Nib4 = 0;
        o_struct.MR3R2Nib5 = 0;
        o_struct.MR3R2Nib6 = 0;
        o_struct.MR3R2Nib7 = 0;
        o_struct.MR3R2Nib8 = 0;
        o_struct.MR3R2Nib9 = 0;
        o_struct.MR3R3Nib0 = 0;
        o_struct.MR3R3Nib1 = 0;
        o_struct.MR3R3Nib10 = 0;
        o_struct.MR3R3Nib11 = 0;
        o_struct.MR3R3Nib12 = 0;
        o_struct.MR3R3Nib13 = 0;
        o_struct.MR3R3Nib14 = 0;
        o_struct.MR3R3Nib15 = 0;
        o_struct.MR3R3Nib16 = 0;
        o_struct.MR3R3Nib17 = 0;
        o_struct.MR3R3Nib18 = 0;
        o_struct.MR3R3Nib19 = 0;
        o_struct.MR3R3Nib2 = 0;
        o_struct.MR3R3Nib3 = 0;
        o_struct.MR3R3Nib4 = 0;
        o_struct.MR3R3Nib5 = 0;
        o_struct.MR3R3Nib6 = 0;
        o_struct.MR3R3Nib7 = 0;
        o_struct.MR3R3Nib8 = 0;
        o_struct.MR3R3Nib9 = 0;

        // tREFI x1
        o_struct.MR4_A0 = 0x01;
        o_struct.MR4_A1 = 0x01;
        o_struct.MR4_A2 = 0x01;
        o_struct.MR4_A3 = 0x01;
        o_struct.MR4_B0 = 0x01;
        o_struct.MR4_B1 = 0x01;
        o_struct.MR4_B2 = 0x01;
        o_struct.MR4_B3 = 0x01;

        o_struct.MR5_A0 = 0x00;
        o_struct.MR5_A1 = 0x00;
        o_struct.MR5_A2 = 0x00;
        o_struct.MR5_A3 = 0x00;
        o_struct.MR5_B0 = 0x00;
        o_struct.MR5_B1 = 0x00;
        o_struct.MR5_B2 = 0x00;
        o_struct.MR5_B3 = 0x00;

        // tWR = 72, tRTP = 18
        o_struct.MR6_A0 = 0x44;
        o_struct.MR6_A1 = 0x44;
        o_struct.MR6_A2 = 0x44;
        o_struct.MR6_A3 = 0x44;
        o_struct.MR6_B0 = 0x44;
        o_struct.MR6_B1 = 0x44;
        o_struct.MR6_B2 = 0x44;
        o_struct.MR6_B3 = 0x44;

        // Pre/post amble settings using the default
        o_struct.MR8_A0 = 0x08;
        o_struct.MR8_A1 = 0x08;
        o_struct.MR8_A2 = 0x08;
        o_struct.MR8_A3 = 0x08;
        o_struct.MR8_B0 = 0x08;
        o_struct.MR8_B1 = 0x08;
        o_struct.MR8_B2 = 0x08;
        o_struct.MR8_B3 = 0x08;

        // VREF settings -> using 75% (completely fudged)
        o_struct.MR10_A0 = 0x29;
        o_struct.MR10_A1 = 0x29;
        o_struct.MR10_A2 = 0x29;
        o_struct.MR10_A3 = 0x29;
        o_struct.MR10_B0 = 0x29;
        o_struct.MR10_B1 = 0x29;
        o_struct.MR10_B2 = 0x29;
        o_struct.MR10_B3 = 0x29;
        o_struct.MR11_A0 = 0x29;
        o_struct.MR11_A1 = 0x29;
        o_struct.MR11_A2 = 0x29;
        o_struct.MR11_A3 = 0x29;
        o_struct.MR11_B0 = 0x29;
        o_struct.MR11_B1 = 0x29;
        o_struct.MR11_B2 = 0x29;
        o_struct.MR11_B3 = 0x29;
        o_struct.MR11_A0_next = 0x29;
        o_struct.MR11_A1_next = 0x29;
        o_struct.MR11_A2_next = 0x29;
        o_struct.MR11_A3_next = 0x29;
        o_struct.MR11_B0_next = 0x29;
        o_struct.MR11_B1_next = 0x29;
        o_struct.MR11_B2_next = 0x29;
        o_struct.MR11_B3_next = 0x29;
        o_struct.MR12_A0 = 0x29;
        o_struct.MR12_A1 = 0x29;
        o_struct.MR12_A2 = 0x29;
        o_struct.MR12_A3 = 0x29;
        o_struct.MR12_B0 = 0x29;
        o_struct.MR12_B1 = 0x29;
        o_struct.MR12_B2 = 0x29;
        o_struct.MR12_B3 = 0x29;
        o_struct.MR12_A0_next = 0x29;
        o_struct.MR12_A1_next = 0x29;
        o_struct.MR12_A2_next = 0x29;
        o_struct.MR12_A3_next = 0x29;
        o_struct.MR12_B0_next = 0x29;
        o_struct.MR12_B1_next = 0x29;
        o_struct.MR12_B2_next = 0x29;
        o_struct.MR12_B3_next = 0x29;

        // tDLLK=1536
        o_struct.MR13_A0 = 0x04;
        o_struct.MR13_A1 = 0x04;
        o_struct.MR13_A2 = 0x04;
        o_struct.MR13_A3 = 0x04;
        o_struct.MR13_B0 = 0x04;
        o_struct.MR13_B1 = 0x04;
        o_struct.MR13_B2 = 0x04;
        o_struct.MR13_B3 = 0x04;
        o_struct.MR13_A0_next = 0x04;
        o_struct.MR13_A1_next = 0x04;
        o_struct.MR13_A2_next = 0x04;
        o_struct.MR13_A3_next = 0x04;
        o_struct.MR13_B0_next = 0x04;
        o_struct.MR13_B1_next = 0x04;
        o_struct.MR13_B2_next = 0x04;
        o_struct.MR13_B3_next = 0x04;

        // Default ECC settings
        o_struct.MR14_A0 = 0x00;
        o_struct.MR14_A1 = 0x00;
        o_struct.MR14_A2 = 0x00;
        o_struct.MR14_A3 = 0x00;
        o_struct.MR14_B0 = 0x00;
        o_struct.MR14_B1 = 0x00;
        o_struct.MR14_B2 = 0x00;
        o_struct.MR14_B3 = 0x00;

        // Default ECC settings
        o_struct.MR15_A0 = 0x00;
        o_struct.MR15_A1 = 0x00;
        o_struct.MR15_A2 = 0x00;
        o_struct.MR15_A3 = 0x00;
        o_struct.MR15_B0 = 0x00;
        o_struct.MR15_B1 = 0x00;
        o_struct.MR15_B2 = 0x00;
        o_struct.MR15_B3 = 0x00;

        // Clock ODT disable - going with default
        o_struct.MR32_A0 = 0x00;
        o_struct.MR32_A1 = 0x00;
        o_struct.MR32_A2 = 0x00;
        o_struct.MR32_A3 = 0x00;
        o_struct.MR32_B0 = 0x00;
        o_struct.MR32_B1 = 0x00;
        o_struct.MR32_B2 = 0x00;
        o_struct.MR32_B3 = 0x00;
        o_struct.MR32_A0_next = 0x00;
        o_struct.MR32_A1_next = 0x00;
        o_struct.MR32_A2_next = 0x00;
        o_struct.MR32_A3_next = 0x00;
        o_struct.MR32_B0_next = 0x00;
        o_struct.MR32_B1_next = 0x00;
        o_struct.MR32_B2_next = 0x00;
        o_struct.MR32_B3_next = 0x00;
        o_struct.MR32_ORG_A0 = 0x00;
        o_struct.MR32_ORG_A1 = 0x00;
        o_struct.MR32_ORG_A2 = 0x00;
        o_struct.MR32_ORG_A3 = 0x00;
        o_struct.MR32_ORG_B0 = 0x00;
        o_struct.MR32_ORG_B1 = 0x00;
        o_struct.MR32_ORG_B2 = 0x00;
        o_struct.MR32_ORG_B3 = 0x00;
        o_struct.MR32_ORG_A0_next = 0x00;
        o_struct.MR32_ORG_A1_next = 0x00;
        o_struct.MR32_ORG_A2_next = 0x00;
        o_struct.MR32_ORG_A3_next = 0x00;
        o_struct.MR32_ORG_B0_next = 0x00;
        o_struct.MR32_ORG_B1_next = 0x00;
        o_struct.MR32_ORG_B2_next = 0x00;
        o_struct.MR32_ORG_B3_next = 0x00;

        // CA/DQS park disable -> going with default
        o_struct.MR33_A0 = 0x00;
        o_struct.MR33_A1 = 0x00;
        o_struct.MR33_A2 = 0x00;
        o_struct.MR33_A3 = 0x00;
        o_struct.MR33_B0 = 0x00;
        o_struct.MR33_B1 = 0x00;
        o_struct.MR33_B2 = 0x00;
        o_struct.MR33_B3 = 0x00;
        o_struct.MR33_A0_next = 0x00;
        o_struct.MR33_A1_next = 0x00;
        o_struct.MR33_A2_next = 0x00;
        o_struct.MR33_A3_next = 0x00;
        o_struct.MR33_B0_next = 0x00;
        o_struct.MR33_B1_next = 0x00;
        o_struct.MR33_B2_next = 0x00;
        o_struct.MR33_B3_next = 0x00;
        o_struct.MR33_ORG_A0 = 0x00;
        o_struct.MR33_ORG_A1 = 0x00;
        o_struct.MR33_ORG_A2 = 0x00;
        o_struct.MR33_ORG_A3 = 0x00;
        o_struct.MR33_ORG_B0 = 0x00;
        o_struct.MR33_ORG_B1 = 0x00;
        o_struct.MR33_ORG_B2 = 0x00;
        o_struct.MR33_ORG_B3 = 0x00;
        o_struct.MR33_ORG_A0_next = 0x00;
        o_struct.MR33_ORG_A1_next = 0x00;
        o_struct.MR33_ORG_A2_next = 0x00;
        o_struct.MR33_ORG_A3_next = 0x00;
        o_struct.MR33_ORG_B0_next = 0x00;
        o_struct.MR33_ORG_B1_next = 0x00;
        o_struct.MR33_ORG_B2_next = 0x00;
        o_struct.MR33_ORG_B3_next = 0x00;

        // RTT park disabled going with default
        o_struct.MR34_A0 = 0x00;
        o_struct.MR34_A1 = 0x00;
        o_struct.MR34_A2 = 0x00;
        o_struct.MR34_A3 = 0x00;
        o_struct.MR34_B0 = 0x00;
        o_struct.MR34_B1 = 0x00;
        o_struct.MR34_B2 = 0x00;
        o_struct.MR34_B3 = 0x00;

        // RTT_NOM off going with default
        o_struct.MR35_A0 = 0x00;
        o_struct.MR35_A1 = 0x00;
        o_struct.MR35_A2 = 0x00;
        o_struct.MR35_A3 = 0x00;
        o_struct.MR35_B0 = 0x00;
        o_struct.MR35_B1 = 0x00;
        o_struct.MR35_B2 = 0x00;
        o_struct.MR35_B3 = 0x00;

        // ODTL WR control offset -> 0 clock
        o_struct.MR37_A0 = 0x2d;
        o_struct.MR37_A1 = 0x2d;
        o_struct.MR37_A2 = 0x2d;
        o_struct.MR37_A3 = 0x2d;
        o_struct.MR37_B0 = 0x2d;
        o_struct.MR37_B1 = 0x2d;
        o_struct.MR37_B2 = 0x2d;
        o_struct.MR37_B3 = 0x2d;

        // ODTL NT control offset -> 0 clock
        o_struct.MR38_A0 = 0x2d;
        o_struct.MR38_A1 = 0x2d;
        o_struct.MR38_A2 = 0x2d;
        o_struct.MR38_A3 = 0x2d;
        o_struct.MR38_B0 = 0x2d;
        o_struct.MR38_B1 = 0x2d;
        o_struct.MR38_B2 = 0x2d;
        o_struct.MR38_B3 = 0x2d;

        // ODTL RD control offset -> 0 clock
        o_struct.MR39_A0 = 0x2d;
        o_struct.MR39_A1 = 0x2d;
        o_struct.MR39_A2 = 0x2d;
        o_struct.MR39_A3 = 0x2d;
        o_struct.MR39_B0 = 0x2d;
        o_struct.MR39_B1 = 0x2d;
        o_struct.MR39_B2 = 0x2d;
        o_struct.MR39_B3 = 0x2d;

        // ECC disabled
        o_struct.MR50_A0 = 0x00;
        o_struct.MR50_A1 = 0x00;
        o_struct.MR50_A2 = 0x00;
        o_struct.MR50_A3 = 0x00;
        o_struct.MR50_B0 = 0x00;
        o_struct.MR50_B1 = 0x00;
        o_struct.MR50_B2 = 0x00;
        o_struct.MR50_B3 = 0x00;

        // No CRC threshold
        o_struct.MR51_A0 = 0x00;
        o_struct.MR51_A1 = 0x00;
        o_struct.MR51_A2 = 0x00;
        o_struct.MR51_A3 = 0x00;
        o_struct.MR51_B0 = 0x00;
        o_struct.MR51_B1 = 0x00;
        o_struct.MR51_B2 = 0x00;
        o_struct.MR51_B3 = 0x00;

        // No CRC threshold
        o_struct.MR52_A0 = 0x00;
        o_struct.MR52_A1 = 0x00;
        o_struct.MR52_A2 = 0x00;
        o_struct.MR52_A3 = 0x00;
        o_struct.MR52_B0 = 0x00;
        o_struct.MR52_B1 = 0x00;
        o_struct.MR52_B2 = 0x00;
        o_struct.MR52_B3 = 0x00;

        // DFE enabled down to 4-tap
        o_struct.MR111_A0 = 0x00;
        o_struct.MR111_A1 = 0x00;
        o_struct.MR111_A2 = 0x00;
        o_struct.MR111_A3 = 0x00;
        o_struct.MR111_B0 = 0x00;
        o_struct.MR111_B1 = 0x00;
        o_struct.MR111_B2 = 0x00;
        o_struct.MR111_B3 = 0x00;
    }

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Starts the firmware draminit training
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note Assumes that the firmware binaries and data structures are loaded appropriately
///
fapi2::ReturnCode start_training(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    // TODO:ZEN:MST-1571 Update Odyssey PHY registers when the official values are merged into the EKB
    const uint64_t MIRCORESET_IBM = convert_synopsys_to_ibm_reg_addr(MIRCORESET);

    // Per the Synopsys documentation, to start the training, there is a latching sequence
    // 1. Configure the PHY to allow training access (wait 40 cycles)
    // 2. Reset and stall the processor (gets it into a base state but does not start it)
    // 3. Stall the processor (releases reset but does not start it)
    // 4. Start training (release stall/reset)
    fapi2::buffer<uint64_t> l_data;

    // 1. Configure the PHY to allow training access (wait 40 cycles after)
    // Note: OFF_N refers to scom access -> so this enables training access
    FAPI_TRY(configure_phy_scom_access(i_target, mss::states::OFF_N));
    // Note: pausing for 100 ns, which should be more than 40 cycles at Odyssey's min frequency
    FAPI_TRY( fapi2::delay( 100, 40) );

    // 2. Reset and stall the processor (gets it into a base state but does not start it)
    l_data.setBit<MIRCORESET_STALLTOMICRO>().setBit<MIRCORESET_RESETTOMICRO>();
    FAPI_TRY(fapi2::putScom(i_target, MIRCORESET_IBM, l_data));

    // 3. Stall the processor (releases reset but does not start it)
    l_data.flush<0>().setBit<MIRCORESET_STALLTOMICRO>();
    FAPI_TRY(fapi2::putScom(i_target, MIRCORESET_IBM, l_data));

    // 4. Start training (release stall/reset)
    l_data.flush<0>();
    FAPI_TRY(fapi2::putScom(i_target, MIRCORESET_IBM, l_data));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Cleans up from the firmware draminit training
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note puts the processor into a stall state
///
fapi2::ReturnCode cleanup_training(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    // TODO:ZEN:MST-1571 Update Odyssey PHY registers when the official values are merged into the EKB
    const uint64_t MIRCORESET_IBM = convert_synopsys_to_ibm_reg_addr(MIRCORESET);
    const uint64_t CALZAP_IBM = convert_synopsys_to_ibm_reg_addr(CALZAP);

    // Per the Synopsys documentation, to cleanup after the training:
    // 1. Stop the processor (stall it)
    // 2. Reset the calibration engines to their initial state (cal Zap!)
    fapi2::buffer<uint64_t> l_data;

    // 1. Stop the processor (stall it)
    l_data.setBit<MIRCORESET_STALLTOMICRO>();
    FAPI_TRY(fapi2::putScom(i_target, MIRCORESET_IBM, l_data));

    // 2. Reset the calibration engines to their initial state (cal Zap!)
    l_data.flush<0>().setBit<CALZAP_CALZAP>();
    FAPI_TRY(fapi2::putScom(i_target, CALZAP_IBM, l_data));

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace phy
} // namespace ody
} // namespace mss
