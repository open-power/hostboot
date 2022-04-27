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
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <generic/memory/lib/utils/poll.H>
#include <ody_scom_mp_apbonly0.H>
#include <ody_scom_mp_drtub0.H>
#include <mss_odyssey_attribute_getters.H>

// TODO:ZEN:MST-1571 Update Odyssey PHY registers when the official values are merged into the EKB
#include <lib/phy/ody_draminit_utils.H>
#include <lib/phy/ody_phy_utils.H>
#include <ody_consts.H>
#include <ody_scom_mp_apbonly0.H>

namespace mss
{
namespace ody
{
namespace phy
{

// TODO:ZEN:MST-1571 Update Odyssey PHY registers when the official values are merged into the EKB
// For now using the Synopsys register location documentation
constexpr uint64_t MIRCORESET = 0x000d0099;
constexpr uint64_t CALZAP = 0x00020089;

constexpr uint64_t MIRCORESET_STALLTOMICRO = 60;
constexpr uint64_t MIRCORESET_RESETTOMICRO = 63;

constexpr uint64_t CALZAP_CALZAP = 63;

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
        o_mail     = (o_mail << 16 ) | l_data;
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
            // Decodes and prints streaming messages
            FAPI_TRY(process_streaming_message(i_target));
        }
        else if (SMBUS_MSG == l_mail)
        {
            // Processes and handles the SMBus messages including sending out the RCW over i2c
            FAPI_TRY(process_smbus_message(i_target));
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
    o_struct.AdvTrainOpt         = 0;
    // Note: if MsgMisc updates to set UsePerDeviceVrefDq, then update VrefDqR*Nib*
    o_struct.MsgMisc             = 0x06; // fast simulation
    o_struct.PmuRevision         = 0;
    o_struct.Pstate              = 0; // We only use pstate 0
    o_struct.PllBypassEn         = 0;
    o_struct.DRAMFreq            = 4800; // Simulation DDR freq of 4800
    o_struct.RCW05_next          = 0;
    o_struct.RCW06_next          = 0;
    o_struct.RXEN_ADJ            = 0;
    o_struct.RX2D_DFE_Misc       = 0;
    o_struct.PhyVref             = 0x40;
    o_struct.D5Misc              = 0x40; // CK ANIB delays adjusted during training for better margins
    o_struct.WL_ADJ              = 0;
    o_struct.CsTestFail          = 0;
    o_struct.SequenceCtrl        = 0x821f;
    o_struct.HdtCtrl             = 0x0A;
    o_struct.PhyCfg              = 0;
    o_struct.ResultAddrOffset    = 0;
    o_struct.DFIMRLMargin        = 0x02; // This needs to be large enough for max tDQSCK variation
    o_struct.X16Present          = 0;
    o_struct.UseBroadcastMR      = 0;
    o_struct.D5Quickboot         = 0;
    o_struct.DisabledDbyte       = 0; // Mismatch to XTB environment, but we're using all the DBYTE's available
    o_struct.CATrainOpt          = 0x1c;
    o_struct.TX2D_DFE_Misc       = 0x00;
    o_struct.RX2D_TrainOpt       = 0x1e;
    o_struct.TX2D_TrainOpt       = 0x1e;
    o_struct.Share2DVrefResult   = 0x00;
    o_struct.MRE_MIN_PULSE       = 0x00;
    o_struct.DWL_MIN_PULSE       = 0x00;
    o_struct.PhyConfigOverride   = 0x0000;
    o_struct.EnabledDQsChA       = 36; // 36 bits on each channel for a UDIMM
    o_struct.CsPresentChA        = 0x01; // There's a chip select on channel A
    o_struct.CS_Dly_Margin_A0    = 0;
    o_struct.CS_Vref_Margin_A0   = 0;
    o_struct.CA_Dly_Margin_A0    = 0;
    o_struct.CA_Vref_Margin_A0   = 0;
    o_struct.DFE_GainBias_A0     = 0;
    o_struct.CS_Dly_Margin_A1    = 0;
    o_struct.CS_Vref_Margin_A1   = 0;
    o_struct.CA_Dly_Margin_A1    = 0;
    o_struct.CA_Vref_Margin_A1   = 0;
    o_struct.DFE_GainBias_A1     = 0;
    o_struct.CS_Dly_Margin_A2    = 0;
    o_struct.CS_Vref_Margin_A2   = 0;
    o_struct.CA_Dly_Margin_A2    = 0;
    o_struct.CA_Vref_Margin_A2   = 0;
    o_struct.DFE_GainBias_A2     = 0;
    o_struct.CS_Dly_Margin_A3    = 0;
    o_struct.CS_Vref_Margin_A3   = 0;
    o_struct.CA_Dly_Margin_A3    = 0;
    o_struct.CA_Vref_Margin_A3   = 0;
    o_struct.DFE_GainBias_A3     = 0;
    o_struct.ReservedF6          = 0;
    o_struct.ReservedF7          = 0;
    o_struct.ReservedF8          = 0;
    o_struct.ReservedF9          = 0;
    o_struct.BCW04_next          = 0x00;
    o_struct.BCW05_next          = 0x00;
    o_struct.WR_RD_RTT_PARK_A0     = 0x00; // RTT_PARK disabled
    o_struct.WR_RD_RTT_PARK_A1     = 0x00; // RTT_PARK disabled
    o_struct.WR_RD_RTT_PARK_A2     = 0x00; // RTT_PARK disabled
    o_struct.WR_RD_RTT_PARK_A3     = 0x00; // RTT_PARK disabled
    o_struct.RxClkDly_Margin_A0    = 0;
    o_struct.VrefDac_Margin_A0     = 0;
    o_struct.TxDqDly_Margin_A0     = 0;
    o_struct.DeviceVref_Margin_A0  = 0;
    o_struct.RxClkDly_Margin_A1    = 0;
    o_struct.VrefDac_Margin_A1     = 0;
    o_struct.TxDqDly_Margin_A1     = 0;
    o_struct.DeviceVref_Margin_A1  = 0;
    o_struct.RxClkDly_Margin_A2    = 0;
    o_struct.VrefDac_Margin_A2     = 0;
    o_struct.TxDqDly_Margin_A2     = 0;
    o_struct.DeviceVref_Margin_A2  = 0;
    o_struct.RxClkDly_Margin_A3    = 0;
    o_struct.VrefDac_Margin_A3     = 0;
    o_struct.TxDqDly_Margin_A3     = 0;
    o_struct.DeviceVref_Margin_A3  = 0;
    o_struct.EnabledDQsChB     = 36; // 36 bits on each channel for a UDIMM
    o_struct.CsPresentChB      = 0x01;
    o_struct.CS_Dly_Margin_B0  = 0;
    o_struct.CS_Vref_Margin_B0 = 0;
    o_struct.CA_Dly_Margin_B0  = 0;
    o_struct.CA_Vref_Margin_B0 = 0;
    o_struct.DFE_GainBias_B0   = 0;
    o_struct.CS_Dly_Margin_B1  = 0;
    o_struct.CS_Vref_Margin_B1 = 0;
    o_struct.CA_Dly_Margin_B1  = 0;
    o_struct.CA_Vref_Margin_B1 = 0;
    o_struct.DFE_GainBias_B1   = 0;
    o_struct.CS_Dly_Margin_B2  = 0;
    o_struct.CS_Vref_Margin_B2 = 0;
    o_struct.CA_Dly_Margin_B2  = 0;
    o_struct.CA_Vref_Margin_B2 = 0;
    o_struct.DFE_GainBias_B2   = 0;
    o_struct.CS_Dly_Margin_B3  = 0;
    o_struct.CS_Vref_Margin_B3 = 0;
    o_struct.CA_Dly_Margin_B3  = 0;
    o_struct.CA_Vref_Margin_B3 = 0;
    o_struct.DFE_GainBias_B3 = 0x00;
    o_struct.Reserved1E2     = 0;
    o_struct.Reserved1E3     = 0;
    o_struct.Reserved1E4     = 0;
    o_struct.Reserved1E5     = 0;
    o_struct.Reserved1E6     = 0;
    o_struct.Reserved1E7     = 0;
    o_struct.WR_RD_RTT_PARK_B0        = 0x00; // RTT_PARK disabled
    o_struct.WR_RD_RTT_PARK_B1        = 0x00; // RTT_PARK disabled
    o_struct.WR_RD_RTT_PARK_B2        = 0x00; // RTT_PARK disabled
    o_struct.WR_RD_RTT_PARK_B3        = 0x00; // RTT_PARK disabled
    o_struct.RxClkDly_Margin_B0       = 0;
    o_struct.VrefDac_Margin_B0        = 0;
    o_struct.TxDqDly_Margin_B0        = 0;
    o_struct.DeviceVref_Margin_B0     = 0;
    o_struct.RxClkDly_Margin_B1       = 0;
    o_struct.VrefDac_Margin_B1        = 0;
    o_struct.TxDqDly_Margin_B1        = 0;
    o_struct.DeviceVref_Margin_B1     = 0;
    o_struct.RxClkDly_Margin_B2       = 0;
    o_struct.VrefDac_Margin_B2        = 0;
    o_struct.TxDqDly_Margin_B2        = 0;
    o_struct.DeviceVref_Margin_B2     = 0;
    o_struct.RxClkDly_Margin_B3       = 0;
    o_struct.VrefDac_Margin_B3        = 0;
    o_struct.TxDqDly_Margin_B3        = 0;
    o_struct.DeviceVref_Margin_B3     = 0;
    o_struct.WL_ADJ_START     = 0x00;
    o_struct.WL_ADJ_END       = 0x00;
    o_struct.RCW00_ChA_D0     = 0;
    o_struct.RCW01_ChA_D0     = 0;
    o_struct.RCW02_ChA_D0     = 0;
    o_struct.RCW03_ChA_D0     = 0;
    o_struct.RCW04_ChA_D0     = 0;
    o_struct.RCW05_ChA_D0     = 0;
    o_struct.RCW06_ChA_D0     = 0;
    o_struct.RCW07_ChA_D0     = 0;
    o_struct.RCW08_ChA_D0     = 0;
    o_struct.RCW09_ChA_D0     = 0;
    o_struct.RCW0A_ChA_D0     = 0;
    o_struct.RCW0B_ChA_D0     = 0;
    o_struct.RCW0C_ChA_D0     = 0;
    o_struct.RCW0D_ChA_D0     = 0;
    o_struct.RCW0E_ChA_D0     = 0;
    o_struct.RCW0F_ChA_D0     = 0;
    o_struct.RCW10_ChA_D0     = 0;
    o_struct.RCW11_ChA_D0     = 0;
    o_struct.RCW12_ChA_D0     = 0;
    o_struct.RCW13_ChA_D0     = 0;
    o_struct.RCW14_ChA_D0     = 0;
    o_struct.RCW15_ChA_D0     = 0;
    o_struct.RCW16_ChA_D0     = 0;
    o_struct.RCW17_ChA_D0     = 0;
    o_struct.RCW18_ChA_D0     = 0;
    o_struct.RCW19_ChA_D0     = 0;
    o_struct.RCW1A_ChA_D0     = 0;
    o_struct.RCW1B_ChA_D0     = 0;
    o_struct.RCW1C_ChA_D0     = 0;
    o_struct.RCW1D_ChA_D0     = 0;
    o_struct.RCW1E_ChA_D0     = 0;
    o_struct.RCW1F_ChA_D0     = 0;
    o_struct.RCW20_ChA_D0     = 0;
    o_struct.RCW21_ChA_D0     = 0;
    o_struct.RCW22_ChA_D0     = 0;
    o_struct.RCW23_ChA_D0     = 0;
    o_struct.RCW24_ChA_D0     = 0;
    o_struct.RCW25_ChA_D0     = 0;
    o_struct.RCW26_ChA_D0     = 0;
    o_struct.RCW27_ChA_D0     = 0;
    o_struct.RCW28_ChA_D0     = 0;
    o_struct.RCW29_ChA_D0     = 0;
    o_struct.RCW2A_ChA_D0     = 0;
    o_struct.RCW2B_ChA_D0     = 0;
    o_struct.RCW2C_ChA_D0     = 0;
    o_struct.RCW2D_ChA_D0     = 0;
    o_struct.RCW2E_ChA_D0     = 0;
    o_struct.RCW2F_ChA_D0     = 0;
    o_struct.RCW30_ChA_D0     = 0;
    o_struct.RCW31_ChA_D0     = 0;
    o_struct.RCW32_ChA_D0     = 0;
    o_struct.RCW33_ChA_D0     = 0;
    o_struct.RCW34_ChA_D0     = 0;
    o_struct.RCW35_ChA_D0     = 0;
    o_struct.RCW36_ChA_D0     = 0;
    o_struct.RCW37_ChA_D0     = 0;
    o_struct.RCW38_ChA_D0     = 0;
    o_struct.RCW39_ChA_D0     = 0;
    o_struct.RCW3A_ChA_D0     = 0;
    o_struct.RCW3B_ChA_D0     = 0;
    o_struct.RCW3C_ChA_D0     = 0;
    o_struct.RCW3D_ChA_D0     = 0;
    o_struct.RCW3E_ChA_D0     = 0;
    o_struct.RCW3F_ChA_D0     = 0;
    o_struct.RCW40_ChA_D0     = 0;
    o_struct.RCW41_ChA_D0     = 0;
    o_struct.RCW42_ChA_D0     = 0;
    o_struct.RCW43_ChA_D0     = 0;
    o_struct.RCW44_ChA_D0     = 0;
    o_struct.RCW45_ChA_D0     = 0;
    o_struct.RCW46_ChA_D0     = 0;
    o_struct.RCW47_ChA_D0     = 0;
    o_struct.RCW48_ChA_D0     = 0;
    o_struct.RCW49_ChA_D0     = 0;
    o_struct.RCW4A_ChA_D0     = 0;
    o_struct.RCW4B_ChA_D0     = 0;
    o_struct.RCW4C_ChA_D0     = 0;
    o_struct.RCW4D_ChA_D0     = 0;
    o_struct.RCW4E_ChA_D0     = 0;
    o_struct.RCW4F_ChA_D0     = 0;
    o_struct.RCW50_ChA_D0     = 0;
    o_struct.RCW51_ChA_D0     = 0;
    o_struct.RCW52_ChA_D0     = 0;
    o_struct.RCW53_ChA_D0     = 0;
    o_struct.RCW54_ChA_D0     = 0;
    o_struct.RCW55_ChA_D0     = 0;
    o_struct.RCW56_ChA_D0     = 0;
    o_struct.RCW57_ChA_D0     = 0;
    o_struct.RCW58_ChA_D0     = 0;
    o_struct.RCW59_ChA_D0     = 0;
    o_struct.RCW5A_ChA_D0     = 0;
    o_struct.RCW5B_ChA_D0     = 0;
    o_struct.RCW5C_ChA_D0     = 0;
    o_struct.RCW5D_ChA_D0     = 0;
    o_struct.RCW5E_ChA_D0     = 0;
    o_struct.RCW5F_ChA_D0     = 0;
    o_struct.RCW60_ChA_D0     = 0;
    o_struct.RCW61_ChA_D0     = 0;
    o_struct.RCW62_ChA_D0     = 0;
    o_struct.RCW63_ChA_D0     = 0;
    o_struct.RCW64_ChA_D0     = 0;
    o_struct.RCW65_ChA_D0     = 0;
    o_struct.RCW66_ChA_D0     = 0;
    o_struct.RCW67_ChA_D0     = 0;
    o_struct.RCW68_ChA_D0     = 0;
    o_struct.RCW69_ChA_D0     = 0;
    o_struct.RCW6A_ChA_D0     = 0;
    o_struct.RCW6B_ChA_D0     = 0;
    o_struct.RCW6C_ChA_D0     = 0;
    o_struct.RCW6D_ChA_D0     = 0;
    o_struct.RCW6E_ChA_D0     = 0;
    o_struct.RCW6F_ChA_D0     = 0;
    o_struct.RCW70_ChA_D0     = 0;
    o_struct.RCW71_ChA_D0     = 0;
    o_struct.RCW72_ChA_D0     = 0;
    o_struct.RCW73_ChA_D0     = 0;
    o_struct.RCW74_ChA_D0     = 0;
    o_struct.RCW75_ChA_D0     = 0;
    o_struct.RCW76_ChA_D0     = 0;
    o_struct.RCW77_ChA_D0     = 0;
    o_struct.RCW78_ChA_D0     = 0;
    o_struct.RCW79_ChA_D0     = 0;
    o_struct.RCW7A_ChA_D0     = 0;
    o_struct.RCW7B_ChA_D0     = 0;
    o_struct.RCW7C_ChA_D0     = 0;
    o_struct.RCW7D_ChA_D0     = 0;
    o_struct.RCW7E_ChA_D0     = 0;
    o_struct.RCW7F_ChA_D0     = 0;
    o_struct.BCW00_ChA_D0     = 0;
    o_struct.BCW01_ChA_D0     = 0;
    o_struct.BCW02_ChA_D0     = 0;
    o_struct.BCW03_ChA_D0     = 0;
    o_struct.BCW04_ChA_D0     = 0;
    o_struct.BCW05_ChA_D0     = 0;
    o_struct.BCW06_ChA_D0     = 0;
    o_struct.BCW07_ChA_D0     = 0;
    o_struct.BCW08_ChA_D0     = 0;
    o_struct.BCW09_ChA_D0     = 0;
    o_struct.BCW0A_ChA_D0     = 0;
    o_struct.BCW0B_ChA_D0     = 0;
    o_struct.BCW0C_ChA_D0     = 0;
    o_struct.BCW0D_ChA_D0     = 0;
    o_struct.BCW0E_ChA_D0     = 0;
    o_struct.BCW0F_ChA_D0     = 0;
    o_struct.BCW10_ChA_D0     = 0;
    o_struct.BCW11_ChA_D0     = 0;
    o_struct.BCW12_ChA_D0     = 0;
    o_struct.BCW13_ChA_D0     = 0;
    o_struct.BCW14_ChA_D0     = 0;
    o_struct.BCW15_ChA_D0     = 0;
    o_struct.BCW16_ChA_D0     = 0;
    o_struct.BCW17_ChA_D0     = 0;
    o_struct.BCW18_ChA_D0     = 0;
    o_struct.BCW19_ChA_D0     = 0;
    o_struct.BCW1A_ChA_D0     = 0;
    o_struct.BCW1B_ChA_D0     = 0;
    o_struct.BCW1C_ChA_D0     = 0;
    o_struct.BCW1D_ChA_D0     = 0;
    o_struct.BCW1E_ChA_D0     = 0;
    o_struct.BCW1F_ChA_D0     = 0;
    o_struct.BCW20_ChA_D0     = 0;
    o_struct.BCW21_ChA_D0     = 0;
    o_struct.BCW22_ChA_D0     = 0;
    o_struct.BCW23_ChA_D0     = 0;
    o_struct.BCW24_ChA_D0     = 0;
    o_struct.BCW25_ChA_D0     = 0;
    o_struct.BCW26_ChA_D0     = 0;
    o_struct.BCW27_ChA_D0     = 0;
    o_struct.BCW28_ChA_D0     = 0;
    o_struct.BCW29_ChA_D0     = 0;
    o_struct.BCW2A_ChA_D0     = 0;
    o_struct.BCW2B_ChA_D0     = 0;
    o_struct.BCW2C_ChA_D0     = 0;
    o_struct.BCW2D_ChA_D0     = 0;
    o_struct.BCW2E_ChA_D0     = 0;
    o_struct.BCW2F_ChA_D0     = 0;
    o_struct.BCW30_ChA_D0     = 0;
    o_struct.BCW31_ChA_D0     = 0;
    o_struct.BCW32_ChA_D0     = 0;
    o_struct.BCW33_ChA_D0     = 0;
    o_struct.BCW34_ChA_D0     = 0;
    o_struct.BCW35_ChA_D0     = 0;
    o_struct.BCW36_ChA_D0     = 0;
    o_struct.BCW37_ChA_D0     = 0;
    o_struct.BCW38_ChA_D0     = 0;
    o_struct.BCW39_ChA_D0     = 0;
    o_struct.BCW3A_ChA_D0     = 0;
    o_struct.BCW3B_ChA_D0     = 0;
    o_struct.BCW3C_ChA_D0     = 0;
    o_struct.BCW3D_ChA_D0     = 0;
    o_struct.BCW3E_ChA_D0     = 0;
    o_struct.BCW3F_ChA_D0     = 0;
    o_struct.BCW40_ChA_D0     = 0;
    o_struct.BCW41_ChA_D0     = 0;
    o_struct.BCW42_ChA_D0     = 0;
    o_struct.BCW43_ChA_D0     = 0;
    o_struct.BCW44_ChA_D0     = 0;
    o_struct.BCW45_ChA_D0     = 0;
    o_struct.BCW46_ChA_D0     = 0;
    o_struct.BCW47_ChA_D0     = 0;
    o_struct.BCW48_ChA_D0     = 0;
    o_struct.BCW49_ChA_D0     = 0;
    o_struct.BCW4A_ChA_D0     = 0;
    o_struct.BCW4B_ChA_D0     = 0;
    o_struct.BCW4C_ChA_D0     = 0;
    o_struct.BCW4D_ChA_D0     = 0;
    o_struct.BCW4E_ChA_D0     = 0;
    o_struct.BCW4F_ChA_D0     = 0;
    o_struct.BCW50_ChA_D0     = 0;
    o_struct.BCW51_ChA_D0     = 0;
    o_struct.BCW52_ChA_D0     = 0;
    o_struct.BCW53_ChA_D0     = 0;
    o_struct.BCW54_ChA_D0     = 0;
    o_struct.BCW55_ChA_D0     = 0;
    o_struct.BCW56_ChA_D0     = 0;
    o_struct.BCW57_ChA_D0     = 0;
    o_struct.BCW58_ChA_D0     = 0;
    o_struct.BCW59_ChA_D0     = 0;
    o_struct.BCW5A_ChA_D0     = 0;
    o_struct.BCW5B_ChA_D0     = 0;
    o_struct.BCW5C_ChA_D0     = 0;
    o_struct.BCW5D_ChA_D0     = 0;
    o_struct.BCW5E_ChA_D0     = 0;
    o_struct.BCW5F_ChA_D0     = 0;
    o_struct.BCW60_ChA_D0     = 0;
    o_struct.BCW61_ChA_D0     = 0;
    o_struct.BCW62_ChA_D0     = 0;
    o_struct.BCW63_ChA_D0     = 0;
    o_struct.BCW64_ChA_D0     = 0;
    o_struct.BCW65_ChA_D0     = 0;
    o_struct.BCW66_ChA_D0     = 0;
    o_struct.BCW67_ChA_D0     = 0;
    o_struct.BCW68_ChA_D0     = 0;
    o_struct.BCW69_ChA_D0     = 0;
    o_struct.BCW6A_ChA_D0     = 0;
    o_struct.BCW6B_ChA_D0     = 0;
    o_struct.BCW6C_ChA_D0     = 0;
    o_struct.BCW6D_ChA_D0     = 0;
    o_struct.BCW6E_ChA_D0     = 0;
    o_struct.BCW6F_ChA_D0     = 0;
    o_struct.BCW70_ChA_D0     = 0;
    o_struct.BCW71_ChA_D0     = 0;
    o_struct.BCW72_ChA_D0     = 0;
    o_struct.BCW73_ChA_D0     = 0;
    o_struct.BCW74_ChA_D0     = 0;
    o_struct.BCW75_ChA_D0     = 0;
    o_struct.BCW76_ChA_D0     = 0;
    o_struct.BCW77_ChA_D0     = 0;
    o_struct.BCW78_ChA_D0     = 0;
    o_struct.BCW79_ChA_D0     = 0;
    o_struct.BCW7A_ChA_D0     = 0;
    o_struct.BCW7B_ChA_D0     = 0;
    o_struct.BCW7C_ChA_D0     = 0;
    o_struct.BCW7D_ChA_D0     = 0;
    o_struct.BCW7E_ChA_D0     = 0;
    o_struct.BCW7F_ChA_D0     = 0;
    o_struct.RCW00_ChA_D1     = 0;
    o_struct.RCW01_ChA_D1     = 0;
    o_struct.RCW02_ChA_D1     = 0;
    o_struct.RCW03_ChA_D1     = 0;
    o_struct.RCW04_ChA_D1     = 0;
    o_struct.RCW05_ChA_D1     = 0;
    o_struct.RCW06_ChA_D1     = 0;
    o_struct.RCW07_ChA_D1     = 0;
    o_struct.RCW08_ChA_D1     = 0;
    o_struct.RCW09_ChA_D1     = 0;
    o_struct.RCW0A_ChA_D1     = 0;
    o_struct.RCW0B_ChA_D1     = 0;
    o_struct.RCW0C_ChA_D1     = 0;
    o_struct.RCW0D_ChA_D1     = 0;
    o_struct.RCW0E_ChA_D1     = 0;
    o_struct.RCW0F_ChA_D1     = 0;
    o_struct.RCW10_ChA_D1     = 0;
    o_struct.RCW11_ChA_D1     = 0;
    o_struct.RCW12_ChA_D1     = 0;
    o_struct.RCW13_ChA_D1     = 0;
    o_struct.RCW14_ChA_D1     = 0;
    o_struct.RCW15_ChA_D1     = 0;
    o_struct.RCW16_ChA_D1     = 0;
    o_struct.RCW17_ChA_D1     = 0;
    o_struct.RCW18_ChA_D1     = 0;
    o_struct.RCW19_ChA_D1     = 0;
    o_struct.RCW1A_ChA_D1     = 0;
    o_struct.RCW1B_ChA_D1     = 0;
    o_struct.RCW1C_ChA_D1     = 0;
    o_struct.RCW1D_ChA_D1     = 0;
    o_struct.RCW1E_ChA_D1     = 0;
    o_struct.RCW1F_ChA_D1     = 0;
    o_struct.RCW20_ChA_D1     = 0;
    o_struct.RCW21_ChA_D1     = 0;
    o_struct.RCW22_ChA_D1     = 0;
    o_struct.RCW23_ChA_D1     = 0;
    o_struct.RCW24_ChA_D1     = 0;
    o_struct.RCW25_ChA_D1     = 0;
    o_struct.RCW26_ChA_D1     = 0;
    o_struct.RCW27_ChA_D1     = 0;
    o_struct.RCW28_ChA_D1     = 0;
    o_struct.RCW29_ChA_D1     = 0;
    o_struct.RCW2A_ChA_D1     = 0;
    o_struct.RCW2B_ChA_D1     = 0;
    o_struct.RCW2C_ChA_D1     = 0;
    o_struct.RCW2D_ChA_D1     = 0;
    o_struct.RCW2E_ChA_D1     = 0;
    o_struct.RCW2F_ChA_D1     = 0;
    o_struct.RCW30_ChA_D1     = 0;
    o_struct.RCW31_ChA_D1     = 0;
    o_struct.RCW32_ChA_D1     = 0;
    o_struct.RCW33_ChA_D1     = 0;
    o_struct.RCW34_ChA_D1     = 0;
    o_struct.RCW35_ChA_D1     = 0;
    o_struct.RCW36_ChA_D1     = 0;
    o_struct.RCW37_ChA_D1     = 0;
    o_struct.RCW38_ChA_D1     = 0;
    o_struct.RCW39_ChA_D1     = 0;
    o_struct.RCW3A_ChA_D1     = 0;
    o_struct.RCW3B_ChA_D1     = 0;
    o_struct.RCW3C_ChA_D1     = 0;
    o_struct.RCW3D_ChA_D1     = 0;
    o_struct.RCW3E_ChA_D1     = 0;
    o_struct.RCW3F_ChA_D1     = 0;
    o_struct.RCW40_ChA_D1     = 0;
    o_struct.RCW41_ChA_D1     = 0;
    o_struct.RCW42_ChA_D1     = 0;
    o_struct.RCW43_ChA_D1     = 0;
    o_struct.RCW44_ChA_D1     = 0;
    o_struct.RCW45_ChA_D1     = 0;
    o_struct.RCW46_ChA_D1     = 0;
    o_struct.RCW47_ChA_D1     = 0;
    o_struct.RCW48_ChA_D1     = 0;
    o_struct.RCW49_ChA_D1     = 0;
    o_struct.RCW4A_ChA_D1     = 0;
    o_struct.RCW4B_ChA_D1     = 0;
    o_struct.RCW4C_ChA_D1     = 0;
    o_struct.RCW4D_ChA_D1     = 0;
    o_struct.RCW4E_ChA_D1     = 0;
    o_struct.RCW4F_ChA_D1     = 0;
    o_struct.RCW50_ChA_D1     = 0;
    o_struct.RCW51_ChA_D1     = 0;
    o_struct.RCW52_ChA_D1     = 0;
    o_struct.RCW53_ChA_D1     = 0;
    o_struct.RCW54_ChA_D1     = 0;
    o_struct.RCW55_ChA_D1     = 0;
    o_struct.RCW56_ChA_D1     = 0;
    o_struct.RCW57_ChA_D1     = 0;
    o_struct.RCW58_ChA_D1     = 0;
    o_struct.RCW59_ChA_D1     = 0;
    o_struct.RCW5A_ChA_D1     = 0;
    o_struct.RCW5B_ChA_D1     = 0;
    o_struct.RCW5C_ChA_D1     = 0;
    o_struct.RCW5D_ChA_D1     = 0;
    o_struct.RCW5E_ChA_D1     = 0;
    o_struct.RCW5F_ChA_D1     = 0;
    o_struct.RCW60_ChA_D1     = 0;
    o_struct.RCW61_ChA_D1     = 0;
    o_struct.RCW62_ChA_D1     = 0;
    o_struct.RCW63_ChA_D1     = 0;
    o_struct.RCW64_ChA_D1     = 0;
    o_struct.RCW65_ChA_D1     = 0;
    o_struct.RCW66_ChA_D1     = 0;
    o_struct.RCW67_ChA_D1     = 0;
    o_struct.RCW68_ChA_D1     = 0;
    o_struct.RCW69_ChA_D1     = 0;
    o_struct.RCW6A_ChA_D1     = 0;
    o_struct.RCW6B_ChA_D1     = 0;
    o_struct.RCW6C_ChA_D1     = 0;
    o_struct.RCW6D_ChA_D1     = 0;
    o_struct.RCW6E_ChA_D1     = 0;
    o_struct.RCW6F_ChA_D1     = 0;
    o_struct.RCW70_ChA_D1     = 0;
    o_struct.RCW71_ChA_D1     = 0;
    o_struct.RCW72_ChA_D1     = 0;
    o_struct.RCW73_ChA_D1     = 0;
    o_struct.RCW74_ChA_D1     = 0;
    o_struct.RCW75_ChA_D1     = 0;
    o_struct.RCW76_ChA_D1     = 0;
    o_struct.RCW77_ChA_D1     = 0;
    o_struct.RCW78_ChA_D1     = 0;
    o_struct.RCW79_ChA_D1     = 0;
    o_struct.RCW7A_ChA_D1     = 0;
    o_struct.RCW7B_ChA_D1     = 0;
    o_struct.RCW7C_ChA_D1     = 0;
    o_struct.RCW7D_ChA_D1     = 0;
    o_struct.RCW7E_ChA_D1     = 0;
    o_struct.RCW7F_ChA_D1     = 0;
    o_struct.BCW00_ChA_D1     = 0;
    o_struct.BCW01_ChA_D1     = 0;
    o_struct.BCW02_ChA_D1     = 0;
    o_struct.BCW03_ChA_D1     = 0;
    o_struct.BCW04_ChA_D1     = 0;
    o_struct.BCW05_ChA_D1     = 0;
    o_struct.BCW06_ChA_D1     = 0;
    o_struct.BCW07_ChA_D1     = 0;
    o_struct.BCW08_ChA_D1     = 0;
    o_struct.BCW09_ChA_D1     = 0;
    o_struct.BCW0A_ChA_D1     = 0;
    o_struct.BCW0B_ChA_D1     = 0;
    o_struct.BCW0C_ChA_D1     = 0;
    o_struct.BCW0D_ChA_D1     = 0;
    o_struct.BCW0E_ChA_D1     = 0;
    o_struct.BCW0F_ChA_D1     = 0;
    o_struct.BCW10_ChA_D1     = 0;
    o_struct.BCW11_ChA_D1     = 0;
    o_struct.BCW12_ChA_D1     = 0;
    o_struct.BCW13_ChA_D1     = 0;
    o_struct.BCW14_ChA_D1     = 0;
    o_struct.BCW15_ChA_D1     = 0;
    o_struct.BCW16_ChA_D1     = 0;
    o_struct.BCW17_ChA_D1     = 0;
    o_struct.BCW18_ChA_D1     = 0;
    o_struct.BCW19_ChA_D1     = 0;
    o_struct.BCW1A_ChA_D1     = 0;
    o_struct.BCW1B_ChA_D1     = 0;
    o_struct.BCW1C_ChA_D1     = 0;
    o_struct.BCW1D_ChA_D1     = 0;
    o_struct.BCW1E_ChA_D1     = 0;
    o_struct.BCW1F_ChA_D1     = 0;
    o_struct.BCW20_ChA_D1     = 0;
    o_struct.BCW21_ChA_D1     = 0;
    o_struct.BCW22_ChA_D1     = 0;
    o_struct.BCW23_ChA_D1     = 0;
    o_struct.BCW24_ChA_D1     = 0;
    o_struct.BCW25_ChA_D1     = 0;
    o_struct.BCW26_ChA_D1     = 0;
    o_struct.BCW27_ChA_D1     = 0;
    o_struct.BCW28_ChA_D1     = 0;
    o_struct.BCW29_ChA_D1     = 0;
    o_struct.BCW2A_ChA_D1     = 0;
    o_struct.BCW2B_ChA_D1     = 0;
    o_struct.BCW2C_ChA_D1     = 0;
    o_struct.BCW2D_ChA_D1     = 0;
    o_struct.BCW2E_ChA_D1     = 0;
    o_struct.BCW2F_ChA_D1     = 0;
    o_struct.BCW30_ChA_D1     = 0;
    o_struct.BCW31_ChA_D1     = 0;
    o_struct.BCW32_ChA_D1     = 0;
    o_struct.BCW33_ChA_D1     = 0;
    o_struct.BCW34_ChA_D1     = 0;
    o_struct.BCW35_ChA_D1     = 0;
    o_struct.BCW36_ChA_D1     = 0;
    o_struct.BCW37_ChA_D1     = 0;
    o_struct.BCW38_ChA_D1     = 0;
    o_struct.BCW39_ChA_D1     = 0;
    o_struct.BCW3A_ChA_D1     = 0;
    o_struct.BCW3B_ChA_D1     = 0;
    o_struct.BCW3C_ChA_D1     = 0;
    o_struct.BCW3D_ChA_D1     = 0;
    o_struct.BCW3E_ChA_D1     = 0;
    o_struct.BCW3F_ChA_D1     = 0;
    o_struct.BCW40_ChA_D1     = 0;
    o_struct.BCW41_ChA_D1     = 0;
    o_struct.BCW42_ChA_D1     = 0;
    o_struct.BCW43_ChA_D1     = 0;
    o_struct.BCW44_ChA_D1     = 0;
    o_struct.BCW45_ChA_D1     = 0;
    o_struct.BCW46_ChA_D1     = 0;
    o_struct.BCW47_ChA_D1     = 0;
    o_struct.BCW48_ChA_D1     = 0;
    o_struct.BCW49_ChA_D1     = 0;
    o_struct.BCW4A_ChA_D1     = 0;
    o_struct.BCW4B_ChA_D1     = 0;
    o_struct.BCW4C_ChA_D1     = 0;
    o_struct.BCW4D_ChA_D1     = 0;
    o_struct.BCW4E_ChA_D1     = 0;
    o_struct.BCW4F_ChA_D1     = 0;
    o_struct.BCW50_ChA_D1     = 0;
    o_struct.BCW51_ChA_D1     = 0;
    o_struct.BCW52_ChA_D1     = 0;
    o_struct.BCW53_ChA_D1     = 0;
    o_struct.BCW54_ChA_D1     = 0;
    o_struct.BCW55_ChA_D1     = 0;
    o_struct.BCW56_ChA_D1     = 0;
    o_struct.BCW57_ChA_D1     = 0;
    o_struct.BCW58_ChA_D1     = 0;
    o_struct.BCW59_ChA_D1     = 0;
    o_struct.BCW5A_ChA_D1     = 0;
    o_struct.BCW5B_ChA_D1     = 0;
    o_struct.BCW5C_ChA_D1     = 0;
    o_struct.BCW5D_ChA_D1     = 0;
    o_struct.BCW5E_ChA_D1     = 0;
    o_struct.BCW5F_ChA_D1     = 0;
    o_struct.BCW60_ChA_D1     = 0;
    o_struct.BCW61_ChA_D1     = 0;
    o_struct.BCW62_ChA_D1     = 0;
    o_struct.BCW63_ChA_D1     = 0;
    o_struct.BCW64_ChA_D1     = 0;
    o_struct.BCW65_ChA_D1     = 0;
    o_struct.BCW66_ChA_D1     = 0;
    o_struct.BCW67_ChA_D1     = 0;
    o_struct.BCW68_ChA_D1     = 0;
    o_struct.BCW69_ChA_D1     = 0;
    o_struct.BCW6A_ChA_D1     = 0;
    o_struct.BCW6B_ChA_D1     = 0;
    o_struct.BCW6C_ChA_D1     = 0;
    o_struct.BCW6D_ChA_D1     = 0;
    o_struct.BCW6E_ChA_D1     = 0;
    o_struct.BCW6F_ChA_D1     = 0;
    o_struct.BCW70_ChA_D1     = 0;
    o_struct.BCW71_ChA_D1     = 0;
    o_struct.BCW72_ChA_D1     = 0;
    o_struct.BCW73_ChA_D1     = 0;
    o_struct.BCW74_ChA_D1     = 0;
    o_struct.BCW75_ChA_D1     = 0;
    o_struct.BCW76_ChA_D1     = 0;
    o_struct.BCW77_ChA_D1     = 0;
    o_struct.BCW78_ChA_D1     = 0;
    o_struct.BCW79_ChA_D1     = 0;
    o_struct.BCW7A_ChA_D1     = 0;
    o_struct.BCW7B_ChA_D1     = 0;
    o_struct.BCW7C_ChA_D1     = 0;
    o_struct.BCW7D_ChA_D1     = 0;
    o_struct.BCW7E_ChA_D1     = 0;
    o_struct.BCW7F_ChA_D1     = 0;
    o_struct.RCW00_ChB_D0     = 0;
    o_struct.RCW01_ChB_D0     = 0;
    o_struct.RCW02_ChB_D0     = 0;
    o_struct.RCW03_ChB_D0     = 0;
    o_struct.RCW04_ChB_D0     = 0;
    o_struct.RCW05_ChB_D0     = 0;
    o_struct.RCW06_ChB_D0     = 0;
    o_struct.RCW07_ChB_D0     = 0;
    o_struct.RCW08_ChB_D0     = 0;
    o_struct.RCW09_ChB_D0     = 0;
    o_struct.RCW0A_ChB_D0     = 0;
    o_struct.RCW0B_ChB_D0     = 0;
    o_struct.RCW0C_ChB_D0     = 0;
    o_struct.RCW0D_ChB_D0     = 0;
    o_struct.RCW0E_ChB_D0     = 0;
    o_struct.RCW0F_ChB_D0     = 0;
    o_struct.RCW10_ChB_D0     = 0;
    o_struct.RCW11_ChB_D0     = 0;
    o_struct.RCW12_ChB_D0     = 0;
    o_struct.RCW13_ChB_D0     = 0;
    o_struct.RCW14_ChB_D0     = 0;
    o_struct.RCW15_ChB_D0     = 0;
    o_struct.RCW16_ChB_D0     = 0;
    o_struct.RCW17_ChB_D0     = 0;
    o_struct.RCW18_ChB_D0     = 0;
    o_struct.RCW19_ChB_D0     = 0;
    o_struct.RCW1A_ChB_D0     = 0;
    o_struct.RCW1B_ChB_D0     = 0;
    o_struct.RCW1C_ChB_D0     = 0;
    o_struct.RCW1D_ChB_D0     = 0;
    o_struct.RCW1E_ChB_D0     = 0;
    o_struct.RCW1F_ChB_D0     = 0;
    o_struct.RCW20_ChB_D0     = 0;
    o_struct.RCW21_ChB_D0     = 0;
    o_struct.RCW22_ChB_D0     = 0;
    o_struct.RCW23_ChB_D0     = 0;
    o_struct.RCW24_ChB_D0     = 0;
    o_struct.RCW25_ChB_D0     = 0;
    o_struct.RCW26_ChB_D0     = 0;
    o_struct.RCW27_ChB_D0     = 0;
    o_struct.RCW28_ChB_D0     = 0;
    o_struct.RCW29_ChB_D0     = 0;
    o_struct.RCW2A_ChB_D0     = 0;
    o_struct.RCW2B_ChB_D0     = 0;
    o_struct.RCW2C_ChB_D0     = 0;
    o_struct.RCW2D_ChB_D0     = 0;
    o_struct.RCW2E_ChB_D0     = 0;
    o_struct.RCW2F_ChB_D0     = 0;
    o_struct.RCW30_ChB_D0     = 0;
    o_struct.RCW31_ChB_D0     = 0;
    o_struct.RCW32_ChB_D0     = 0;
    o_struct.RCW33_ChB_D0     = 0;
    o_struct.RCW34_ChB_D0     = 0;
    o_struct.RCW35_ChB_D0     = 0;
    o_struct.RCW36_ChB_D0     = 0;
    o_struct.RCW37_ChB_D0     = 0;
    o_struct.RCW38_ChB_D0     = 0;
    o_struct.RCW39_ChB_D0     = 0;
    o_struct.RCW3A_ChB_D0     = 0;
    o_struct.RCW3B_ChB_D0     = 0;
    o_struct.RCW3C_ChB_D0     = 0;
    o_struct.RCW3D_ChB_D0     = 0;
    o_struct.RCW3E_ChB_D0     = 0;
    o_struct.RCW3F_ChB_D0     = 0;
    o_struct.RCW40_ChB_D0     = 0;
    o_struct.RCW41_ChB_D0     = 0;
    o_struct.RCW42_ChB_D0     = 0;
    o_struct.RCW43_ChB_D0     = 0;
    o_struct.RCW44_ChB_D0     = 0;
    o_struct.RCW45_ChB_D0     = 0;
    o_struct.RCW46_ChB_D0     = 0;
    o_struct.RCW47_ChB_D0     = 0;
    o_struct.RCW48_ChB_D0     = 0;
    o_struct.RCW49_ChB_D0     = 0;
    o_struct.RCW4A_ChB_D0     = 0;
    o_struct.RCW4B_ChB_D0     = 0;
    o_struct.RCW4C_ChB_D0     = 0;
    o_struct.RCW4D_ChB_D0     = 0;
    o_struct.RCW4E_ChB_D0     = 0;
    o_struct.RCW4F_ChB_D0     = 0;
    o_struct.RCW50_ChB_D0     = 0;
    o_struct.RCW51_ChB_D0     = 0;
    o_struct.RCW52_ChB_D0     = 0;
    o_struct.RCW53_ChB_D0     = 0;
    o_struct.RCW54_ChB_D0     = 0;
    o_struct.RCW55_ChB_D0     = 0;
    o_struct.RCW56_ChB_D0     = 0;
    o_struct.RCW57_ChB_D0     = 0;
    o_struct.RCW58_ChB_D0     = 0;
    o_struct.RCW59_ChB_D0     = 0;
    o_struct.RCW5A_ChB_D0     = 0;
    o_struct.RCW5B_ChB_D0     = 0;
    o_struct.RCW5C_ChB_D0     = 0;
    o_struct.RCW5D_ChB_D0     = 0;
    o_struct.RCW5E_ChB_D0     = 0;
    o_struct.RCW5F_ChB_D0     = 0;
    o_struct.RCW60_ChB_D0     = 0;
    o_struct.RCW61_ChB_D0     = 0;
    o_struct.RCW62_ChB_D0     = 0;
    o_struct.RCW63_ChB_D0     = 0;
    o_struct.RCW64_ChB_D0     = 0;
    o_struct.RCW65_ChB_D0     = 0;
    o_struct.RCW66_ChB_D0     = 0;
    o_struct.RCW67_ChB_D0     = 0;
    o_struct.RCW68_ChB_D0     = 0;
    o_struct.RCW69_ChB_D0     = 0;
    o_struct.RCW6A_ChB_D0     = 0;
    o_struct.RCW6B_ChB_D0     = 0;
    o_struct.RCW6C_ChB_D0     = 0;
    o_struct.RCW6D_ChB_D0     = 0;
    o_struct.RCW6E_ChB_D0     = 0;
    o_struct.RCW6F_ChB_D0     = 0;
    o_struct.RCW70_ChB_D0     = 0;
    o_struct.RCW71_ChB_D0     = 0;
    o_struct.RCW72_ChB_D0     = 0;
    o_struct.RCW73_ChB_D0     = 0;
    o_struct.RCW74_ChB_D0     = 0;
    o_struct.RCW75_ChB_D0     = 0;
    o_struct.RCW76_ChB_D0     = 0;
    o_struct.RCW77_ChB_D0     = 0;
    o_struct.RCW78_ChB_D0     = 0;
    o_struct.RCW79_ChB_D0     = 0;
    o_struct.RCW7A_ChB_D0     = 0;
    o_struct.RCW7B_ChB_D0     = 0;
    o_struct.RCW7C_ChB_D0     = 0;
    o_struct.RCW7D_ChB_D0     = 0;
    o_struct.RCW7E_ChB_D0     = 0;
    o_struct.RCW7F_ChB_D0     = 0;
    o_struct.BCW00_ChB_D0     = 0;
    o_struct.BCW01_ChB_D0     = 0;
    o_struct.BCW02_ChB_D0     = 0;
    o_struct.BCW03_ChB_D0     = 0;
    o_struct.BCW04_ChB_D0     = 0;
    o_struct.BCW05_ChB_D0     = 0;
    o_struct.BCW06_ChB_D0     = 0;
    o_struct.BCW07_ChB_D0     = 0;
    o_struct.BCW08_ChB_D0     = 0;
    o_struct.BCW09_ChB_D0     = 0;
    o_struct.BCW0A_ChB_D0     = 0;
    o_struct.BCW0B_ChB_D0     = 0;
    o_struct.BCW0C_ChB_D0     = 0;
    o_struct.BCW0D_ChB_D0     = 0;
    o_struct.BCW0E_ChB_D0     = 0;
    o_struct.BCW0F_ChB_D0     = 0;
    o_struct.BCW10_ChB_D0     = 0;
    o_struct.BCW11_ChB_D0     = 0;
    o_struct.BCW12_ChB_D0     = 0;
    o_struct.BCW13_ChB_D0     = 0;
    o_struct.BCW14_ChB_D0     = 0;
    o_struct.BCW15_ChB_D0     = 0;
    o_struct.BCW16_ChB_D0     = 0;
    o_struct.BCW17_ChB_D0     = 0;
    o_struct.BCW18_ChB_D0     = 0;
    o_struct.BCW19_ChB_D0     = 0;
    o_struct.BCW1A_ChB_D0     = 0;
    o_struct.BCW1B_ChB_D0     = 0;
    o_struct.BCW1C_ChB_D0     = 0;
    o_struct.BCW1D_ChB_D0     = 0;
    o_struct.BCW1E_ChB_D0     = 0;
    o_struct.BCW1F_ChB_D0     = 0;
    o_struct.BCW20_ChB_D0     = 0;
    o_struct.BCW21_ChB_D0     = 0;
    o_struct.BCW22_ChB_D0     = 0;
    o_struct.BCW23_ChB_D0     = 0;
    o_struct.BCW24_ChB_D0     = 0;
    o_struct.BCW25_ChB_D0     = 0;
    o_struct.BCW26_ChB_D0     = 0;
    o_struct.BCW27_ChB_D0     = 0;
    o_struct.BCW28_ChB_D0     = 0;
    o_struct.BCW29_ChB_D0     = 0;
    o_struct.BCW2A_ChB_D0     = 0;
    o_struct.BCW2B_ChB_D0     = 0;
    o_struct.BCW2C_ChB_D0     = 0;
    o_struct.BCW2D_ChB_D0     = 0;
    o_struct.BCW2E_ChB_D0     = 0;
    o_struct.BCW2F_ChB_D0     = 0;
    o_struct.BCW30_ChB_D0     = 0;
    o_struct.BCW31_ChB_D0     = 0;
    o_struct.BCW32_ChB_D0     = 0;
    o_struct.BCW33_ChB_D0     = 0;
    o_struct.BCW34_ChB_D0     = 0;
    o_struct.BCW35_ChB_D0     = 0;
    o_struct.BCW36_ChB_D0     = 0;
    o_struct.BCW37_ChB_D0     = 0;
    o_struct.BCW38_ChB_D0     = 0;
    o_struct.BCW39_ChB_D0     = 0;
    o_struct.BCW3A_ChB_D0     = 0;
    o_struct.BCW3B_ChB_D0     = 0;
    o_struct.BCW3C_ChB_D0     = 0;
    o_struct.BCW3D_ChB_D0     = 0;
    o_struct.BCW3E_ChB_D0     = 0;
    o_struct.BCW3F_ChB_D0     = 0;
    o_struct.BCW40_ChB_D0     = 0;
    o_struct.BCW41_ChB_D0     = 0;
    o_struct.BCW42_ChB_D0     = 0;
    o_struct.BCW43_ChB_D0     = 0;
    o_struct.BCW44_ChB_D0     = 0;
    o_struct.BCW45_ChB_D0     = 0;
    o_struct.BCW46_ChB_D0     = 0;
    o_struct.BCW47_ChB_D0     = 0;
    o_struct.BCW48_ChB_D0     = 0;
    o_struct.BCW49_ChB_D0     = 0;
    o_struct.BCW4A_ChB_D0     = 0;
    o_struct.BCW4B_ChB_D0     = 0;
    o_struct.BCW4C_ChB_D0     = 0;
    o_struct.BCW4D_ChB_D0     = 0;
    o_struct.BCW4E_ChB_D0     = 0;
    o_struct.BCW4F_ChB_D0     = 0;
    o_struct.BCW50_ChB_D0     = 0;
    o_struct.BCW51_ChB_D0     = 0;
    o_struct.BCW52_ChB_D0     = 0;
    o_struct.BCW53_ChB_D0     = 0;
    o_struct.BCW54_ChB_D0     = 0;
    o_struct.BCW55_ChB_D0     = 0;
    o_struct.BCW56_ChB_D0     = 0;
    o_struct.BCW57_ChB_D0     = 0;
    o_struct.BCW58_ChB_D0     = 0;
    o_struct.BCW59_ChB_D0     = 0;
    o_struct.BCW5A_ChB_D0     = 0;
    o_struct.BCW5B_ChB_D0     = 0;
    o_struct.BCW5C_ChB_D0     = 0;
    o_struct.BCW5D_ChB_D0     = 0;
    o_struct.BCW5E_ChB_D0     = 0;
    o_struct.BCW5F_ChB_D0     = 0;
    o_struct.BCW60_ChB_D0     = 0;
    o_struct.BCW61_ChB_D0     = 0;
    o_struct.BCW62_ChB_D0     = 0;
    o_struct.BCW63_ChB_D0     = 0;
    o_struct.BCW64_ChB_D0     = 0;
    o_struct.BCW65_ChB_D0     = 0;
    o_struct.BCW66_ChB_D0     = 0;
    o_struct.BCW67_ChB_D0     = 0;
    o_struct.BCW68_ChB_D0     = 0;
    o_struct.BCW69_ChB_D0     = 0;
    o_struct.BCW6A_ChB_D0     = 0;
    o_struct.BCW6B_ChB_D0     = 0;
    o_struct.BCW6C_ChB_D0     = 0;
    o_struct.BCW6D_ChB_D0     = 0;
    o_struct.BCW6E_ChB_D0     = 0;
    o_struct.BCW6F_ChB_D0     = 0;
    o_struct.BCW70_ChB_D0     = 0;
    o_struct.BCW71_ChB_D0     = 0;
    o_struct.BCW72_ChB_D0     = 0;
    o_struct.BCW73_ChB_D0     = 0;
    o_struct.BCW74_ChB_D0     = 0;
    o_struct.BCW75_ChB_D0     = 0;
    o_struct.BCW76_ChB_D0     = 0;
    o_struct.BCW77_ChB_D0     = 0;
    o_struct.BCW78_ChB_D0     = 0;
    o_struct.BCW79_ChB_D0     = 0;
    o_struct.BCW7A_ChB_D0     = 0;
    o_struct.BCW7B_ChB_D0     = 0;
    o_struct.BCW7C_ChB_D0     = 0;
    o_struct.BCW7D_ChB_D0     = 0;
    o_struct.BCW7E_ChB_D0     = 0;
    o_struct.BCW7F_ChB_D0     = 0;
    o_struct.RCW00_ChB_D1     = 0;
    o_struct.RCW01_ChB_D1     = 0;
    o_struct.RCW02_ChB_D1     = 0;
    o_struct.RCW03_ChB_D1     = 0;
    o_struct.RCW04_ChB_D1     = 0;
    o_struct.RCW05_ChB_D1     = 0;
    o_struct.RCW06_ChB_D1     = 0;
    o_struct.RCW07_ChB_D1     = 0;
    o_struct.RCW08_ChB_D1     = 0;
    o_struct.RCW09_ChB_D1     = 0;
    o_struct.RCW0A_ChB_D1     = 0;
    o_struct.RCW0B_ChB_D1     = 0;
    o_struct.RCW0C_ChB_D1     = 0;
    o_struct.RCW0D_ChB_D1     = 0;
    o_struct.RCW0E_ChB_D1     = 0;
    o_struct.RCW0F_ChB_D1     = 0;
    o_struct.RCW10_ChB_D1     = 0;
    o_struct.RCW11_ChB_D1     = 0;
    o_struct.RCW12_ChB_D1     = 0;
    o_struct.RCW13_ChB_D1     = 0;
    o_struct.RCW14_ChB_D1     = 0;
    o_struct.RCW15_ChB_D1     = 0;
    o_struct.RCW16_ChB_D1     = 0;
    o_struct.RCW17_ChB_D1     = 0;
    o_struct.RCW18_ChB_D1     = 0;
    o_struct.RCW19_ChB_D1     = 0;
    o_struct.RCW1A_ChB_D1     = 0;
    o_struct.RCW1B_ChB_D1     = 0;
    o_struct.RCW1C_ChB_D1     = 0;
    o_struct.RCW1D_ChB_D1     = 0;
    o_struct.RCW1E_ChB_D1     = 0;
    o_struct.RCW1F_ChB_D1     = 0;
    o_struct.RCW20_ChB_D1     = 0;
    o_struct.RCW21_ChB_D1     = 0;
    o_struct.RCW22_ChB_D1     = 0;
    o_struct.RCW23_ChB_D1     = 0;
    o_struct.RCW24_ChB_D1     = 0;
    o_struct.RCW25_ChB_D1     = 0;
    o_struct.RCW26_ChB_D1     = 0;
    o_struct.RCW27_ChB_D1     = 0;
    o_struct.RCW28_ChB_D1     = 0;
    o_struct.RCW29_ChB_D1     = 0;
    o_struct.RCW2A_ChB_D1     = 0;
    o_struct.RCW2B_ChB_D1     = 0;
    o_struct.RCW2C_ChB_D1     = 0;
    o_struct.RCW2D_ChB_D1     = 0;
    o_struct.RCW2E_ChB_D1     = 0;
    o_struct.RCW2F_ChB_D1     = 0;
    o_struct.RCW30_ChB_D1     = 0;
    o_struct.RCW31_ChB_D1     = 0;
    o_struct.RCW32_ChB_D1     = 0;
    o_struct.RCW33_ChB_D1     = 0;
    o_struct.RCW34_ChB_D1     = 0;
    o_struct.RCW35_ChB_D1     = 0;
    o_struct.RCW36_ChB_D1     = 0;
    o_struct.RCW37_ChB_D1     = 0;
    o_struct.RCW38_ChB_D1     = 0;
    o_struct.RCW39_ChB_D1     = 0;
    o_struct.RCW3A_ChB_D1     = 0;
    o_struct.RCW3B_ChB_D1     = 0;
    o_struct.RCW3C_ChB_D1     = 0;
    o_struct.RCW3D_ChB_D1     = 0;
    o_struct.RCW3E_ChB_D1     = 0;
    o_struct.RCW3F_ChB_D1     = 0;
    o_struct.RCW40_ChB_D1     = 0;
    o_struct.RCW41_ChB_D1     = 0;
    o_struct.RCW42_ChB_D1     = 0;
    o_struct.RCW43_ChB_D1     = 0;
    o_struct.RCW44_ChB_D1     = 0;
    o_struct.RCW45_ChB_D1     = 0;
    o_struct.RCW46_ChB_D1     = 0;
    o_struct.RCW47_ChB_D1     = 0;
    o_struct.RCW48_ChB_D1     = 0;
    o_struct.RCW49_ChB_D1     = 0;
    o_struct.RCW4A_ChB_D1     = 0;
    o_struct.RCW4B_ChB_D1     = 0;
    o_struct.RCW4C_ChB_D1     = 0;
    o_struct.RCW4D_ChB_D1     = 0;
    o_struct.RCW4E_ChB_D1     = 0;
    o_struct.RCW4F_ChB_D1     = 0;
    o_struct.RCW50_ChB_D1     = 0;
    o_struct.RCW51_ChB_D1     = 0;
    o_struct.RCW52_ChB_D1     = 0;
    o_struct.RCW53_ChB_D1     = 0;
    o_struct.RCW54_ChB_D1     = 0;
    o_struct.RCW55_ChB_D1     = 0;
    o_struct.RCW56_ChB_D1     = 0;
    o_struct.RCW57_ChB_D1     = 0;
    o_struct.RCW58_ChB_D1     = 0;
    o_struct.RCW59_ChB_D1     = 0;
    o_struct.RCW5A_ChB_D1     = 0;
    o_struct.RCW5B_ChB_D1     = 0;
    o_struct.RCW5C_ChB_D1     = 0;
    o_struct.RCW5D_ChB_D1     = 0;
    o_struct.RCW5E_ChB_D1     = 0;
    o_struct.RCW5F_ChB_D1     = 0;
    o_struct.RCW60_ChB_D1     = 0;
    o_struct.RCW61_ChB_D1     = 0;
    o_struct.RCW62_ChB_D1     = 0;
    o_struct.RCW63_ChB_D1     = 0;
    o_struct.RCW64_ChB_D1     = 0;
    o_struct.RCW65_ChB_D1     = 0;
    o_struct.RCW66_ChB_D1     = 0;
    o_struct.RCW67_ChB_D1     = 0;
    o_struct.RCW68_ChB_D1     = 0;
    o_struct.RCW69_ChB_D1     = 0;
    o_struct.RCW6A_ChB_D1     = 0;
    o_struct.RCW6B_ChB_D1     = 0;
    o_struct.RCW6C_ChB_D1     = 0;
    o_struct.RCW6D_ChB_D1     = 0;
    o_struct.RCW6E_ChB_D1     = 0;
    o_struct.RCW6F_ChB_D1     = 0;
    o_struct.RCW70_ChB_D1     = 0;
    o_struct.RCW71_ChB_D1     = 0;
    o_struct.RCW72_ChB_D1     = 0;
    o_struct.RCW73_ChB_D1     = 0;
    o_struct.RCW74_ChB_D1     = 0;
    o_struct.RCW75_ChB_D1     = 0;
    o_struct.RCW76_ChB_D1     = 0;
    o_struct.RCW77_ChB_D1     = 0;
    o_struct.RCW78_ChB_D1     = 0;
    o_struct.RCW79_ChB_D1     = 0;
    o_struct.RCW7A_ChB_D1     = 0;
    o_struct.RCW7B_ChB_D1     = 0;
    o_struct.RCW7C_ChB_D1     = 0;
    o_struct.RCW7D_ChB_D1     = 0;
    o_struct.RCW7E_ChB_D1     = 0;
    o_struct.RCW7F_ChB_D1     = 0;
    o_struct.BCW00_ChB_D1     = 0;
    o_struct.BCW01_ChB_D1     = 0;
    o_struct.BCW02_ChB_D1     = 0;
    o_struct.BCW03_ChB_D1     = 0;
    o_struct.BCW04_ChB_D1     = 0;
    o_struct.BCW05_ChB_D1     = 0;
    o_struct.BCW06_ChB_D1     = 0;
    o_struct.BCW07_ChB_D1     = 0;
    o_struct.BCW08_ChB_D1     = 0;
    o_struct.BCW09_ChB_D1     = 0;
    o_struct.BCW0A_ChB_D1     = 0;
    o_struct.BCW0B_ChB_D1     = 0;
    o_struct.BCW0C_ChB_D1     = 0;
    o_struct.BCW0D_ChB_D1     = 0;
    o_struct.BCW0E_ChB_D1     = 0;
    o_struct.BCW0F_ChB_D1     = 0;
    o_struct.BCW10_ChB_D1     = 0;
    o_struct.BCW11_ChB_D1     = 0;
    o_struct.BCW12_ChB_D1     = 0;
    o_struct.BCW13_ChB_D1     = 0;
    o_struct.BCW14_ChB_D1     = 0;
    o_struct.BCW15_ChB_D1     = 0;
    o_struct.BCW16_ChB_D1     = 0;
    o_struct.BCW17_ChB_D1     = 0;
    o_struct.BCW18_ChB_D1     = 0;
    o_struct.BCW19_ChB_D1     = 0;
    o_struct.BCW1A_ChB_D1     = 0;
    o_struct.BCW1B_ChB_D1     = 0;
    o_struct.BCW1C_ChB_D1     = 0;
    o_struct.BCW1D_ChB_D1     = 0;
    o_struct.BCW1E_ChB_D1     = 0;
    o_struct.BCW1F_ChB_D1     = 0;
    o_struct.BCW20_ChB_D1     = 0;
    o_struct.BCW21_ChB_D1     = 0;
    o_struct.BCW22_ChB_D1     = 0;
    o_struct.BCW23_ChB_D1     = 0;
    o_struct.BCW24_ChB_D1     = 0;
    o_struct.BCW25_ChB_D1     = 0;
    o_struct.BCW26_ChB_D1     = 0;
    o_struct.BCW27_ChB_D1     = 0;
    o_struct.BCW28_ChB_D1     = 0;
    o_struct.BCW29_ChB_D1     = 0;
    o_struct.BCW2A_ChB_D1     = 0;
    o_struct.BCW2B_ChB_D1     = 0;
    o_struct.BCW2C_ChB_D1     = 0;
    o_struct.BCW2D_ChB_D1     = 0;
    o_struct.BCW2E_ChB_D1     = 0;
    o_struct.BCW2F_ChB_D1     = 0;
    o_struct.BCW30_ChB_D1     = 0;
    o_struct.BCW31_ChB_D1     = 0;
    o_struct.BCW32_ChB_D1     = 0;
    o_struct.BCW33_ChB_D1     = 0;
    o_struct.BCW34_ChB_D1     = 0;
    o_struct.BCW35_ChB_D1     = 0;
    o_struct.BCW36_ChB_D1     = 0;
    o_struct.BCW37_ChB_D1     = 0;
    o_struct.BCW38_ChB_D1     = 0;
    o_struct.BCW39_ChB_D1     = 0;
    o_struct.BCW3A_ChB_D1     = 0;
    o_struct.BCW3B_ChB_D1     = 0;
    o_struct.BCW3C_ChB_D1     = 0;
    o_struct.BCW3D_ChB_D1     = 0;
    o_struct.BCW3E_ChB_D1     = 0;
    o_struct.BCW3F_ChB_D1     = 0;
    o_struct.BCW40_ChB_D1     = 0;
    o_struct.BCW41_ChB_D1     = 0;
    o_struct.BCW42_ChB_D1     = 0;
    o_struct.BCW43_ChB_D1     = 0;
    o_struct.BCW44_ChB_D1     = 0;
    o_struct.BCW45_ChB_D1     = 0;
    o_struct.BCW46_ChB_D1     = 0;
    o_struct.BCW47_ChB_D1     = 0;
    o_struct.BCW48_ChB_D1     = 0;
    o_struct.BCW49_ChB_D1     = 0;
    o_struct.BCW4A_ChB_D1     = 0;
    o_struct.BCW4B_ChB_D1     = 0;
    o_struct.BCW4C_ChB_D1     = 0;
    o_struct.BCW4D_ChB_D1     = 0;
    o_struct.BCW4E_ChB_D1     = 0;
    o_struct.BCW4F_ChB_D1     = 0;
    o_struct.BCW50_ChB_D1     = 0;
    o_struct.BCW51_ChB_D1     = 0;
    o_struct.BCW52_ChB_D1     = 0;
    o_struct.BCW53_ChB_D1     = 0;
    o_struct.BCW54_ChB_D1     = 0;
    o_struct.BCW55_ChB_D1     = 0;
    o_struct.BCW56_ChB_D1     = 0;
    o_struct.BCW57_ChB_D1     = 0;
    o_struct.BCW58_ChB_D1     = 0;
    o_struct.BCW59_ChB_D1     = 0;
    o_struct.BCW5A_ChB_D1     = 0;
    o_struct.BCW5B_ChB_D1     = 0;
    o_struct.BCW5C_ChB_D1     = 0;
    o_struct.BCW5D_ChB_D1     = 0;
    o_struct.BCW5E_ChB_D1     = 0;
    o_struct.BCW5F_ChB_D1     = 0;
    o_struct.BCW60_ChB_D1     = 0;
    o_struct.BCW61_ChB_D1     = 0;
    o_struct.BCW62_ChB_D1     = 0;
    o_struct.BCW63_ChB_D1     = 0;
    o_struct.BCW64_ChB_D1     = 0;
    o_struct.BCW65_ChB_D1     = 0;
    o_struct.BCW66_ChB_D1     = 0;
    o_struct.BCW67_ChB_D1     = 0;
    o_struct.BCW68_ChB_D1     = 0;
    o_struct.BCW69_ChB_D1     = 0;
    o_struct.BCW6A_ChB_D1     = 0;
    o_struct.BCW6B_ChB_D1     = 0;
    o_struct.BCW6C_ChB_D1     = 0;
    o_struct.BCW6D_ChB_D1     = 0;
    o_struct.BCW6E_ChB_D1     = 0;
    o_struct.BCW6F_ChB_D1     = 0;
    o_struct.BCW70_ChB_D1     = 0;
    o_struct.BCW71_ChB_D1     = 0;
    o_struct.BCW72_ChB_D1     = 0;
    o_struct.BCW73_ChB_D1     = 0;
    o_struct.BCW74_ChB_D1     = 0;
    o_struct.BCW75_ChB_D1     = 0;
    o_struct.BCW76_ChB_D1     = 0;
    o_struct.BCW77_ChB_D1     = 0;
    o_struct.BCW78_ChB_D1     = 0;
    o_struct.BCW79_ChB_D1     = 0;
    o_struct.BCW7A_ChB_D1     = 0;
    o_struct.BCW7B_ChB_D1     = 0;
    o_struct.BCW7C_ChB_D1     = 0;
    o_struct.BCW7D_ChB_D1     = 0;
    o_struct.BCW7E_ChB_D1     = 0;
    o_struct.BCW7F_ChB_D1     = 0;

    // Note: copied the 0 values over from PHY init -> this is due to MsgMisc's UsePerDeviceVrefDq being set to a 0
    o_struct.VrefDqR0Nib0     = 0;
    o_struct.VrefDqR0Nib1     = 0;
    o_struct.VrefDqR0Nib2     = 0;
    o_struct.VrefDqR0Nib3     = 0;
    o_struct.VrefDqR0Nib4     = 0;
    o_struct.VrefDqR0Nib5     = 0;
    o_struct.VrefDqR0Nib6     = 0;
    o_struct.VrefDqR0Nib7     = 0;
    o_struct.VrefDqR0Nib8     = 0;
    o_struct.VrefDqR0Nib9     = 0;
    o_struct.VrefDqR0Nib10     = 0;
    o_struct.VrefDqR0Nib11     = 0;
    o_struct.VrefDqR0Nib12     = 0;
    o_struct.VrefDqR0Nib13     = 0;
    o_struct.VrefDqR0Nib14     = 0;
    o_struct.VrefDqR0Nib15     = 0;
    o_struct.VrefDqR0Nib16     = 0;
    o_struct.VrefDqR0Nib17     = 0;
    o_struct.VrefDqR0Nib18     = 0;
    o_struct.VrefDqR0Nib19     = 0;
    o_struct.VrefDqR1Nib0     = 0;
    o_struct.VrefDqR1Nib1     = 0;
    o_struct.VrefDqR1Nib2     = 0;
    o_struct.VrefDqR1Nib3     = 0;
    o_struct.VrefDqR1Nib4     = 0;
    o_struct.VrefDqR1Nib5     = 0;
    o_struct.VrefDqR1Nib6     = 0;
    o_struct.VrefDqR1Nib7     = 0;
    o_struct.VrefDqR1Nib8     = 0;
    o_struct.VrefDqR1Nib9     = 0;
    o_struct.VrefDqR1Nib10     = 0;
    o_struct.VrefDqR1Nib11     = 0;
    o_struct.VrefDqR1Nib12     = 0;
    o_struct.VrefDqR1Nib13     = 0;
    o_struct.VrefDqR1Nib14     = 0;
    o_struct.VrefDqR1Nib15     = 0;
    o_struct.VrefDqR1Nib16     = 0;
    o_struct.VrefDqR1Nib17     = 0;
    o_struct.VrefDqR1Nib18     = 0;
    o_struct.VrefDqR1Nib19     = 0;
    o_struct.VrefDqR2Nib0     = 0;
    o_struct.VrefDqR2Nib1     = 0;
    o_struct.VrefDqR2Nib2     = 0;
    o_struct.VrefDqR2Nib3     = 0;
    o_struct.VrefDqR2Nib4     = 0;
    o_struct.VrefDqR2Nib5     = 0;
    o_struct.VrefDqR2Nib6     = 0;
    o_struct.VrefDqR2Nib7     = 0;
    o_struct.VrefDqR2Nib8     = 0;
    o_struct.VrefDqR2Nib9     = 0;
    o_struct.VrefDqR2Nib10     = 0;
    o_struct.VrefDqR2Nib11     = 0;
    o_struct.VrefDqR2Nib12     = 0;
    o_struct.VrefDqR2Nib13     = 0;
    o_struct.VrefDqR2Nib14     = 0;
    o_struct.VrefDqR2Nib15     = 0;
    o_struct.VrefDqR2Nib16     = 0;
    o_struct.VrefDqR2Nib17     = 0;
    o_struct.VrefDqR2Nib18     = 0;
    o_struct.VrefDqR2Nib19     = 0;
    o_struct.VrefDqR3Nib0     = 0;
    o_struct.VrefDqR3Nib1     = 0;
    o_struct.VrefDqR3Nib2     = 0;
    o_struct.VrefDqR3Nib3     = 0;
    o_struct.VrefDqR3Nib4     = 0;
    o_struct.VrefDqR3Nib5     = 0;
    o_struct.VrefDqR3Nib6     = 0;
    o_struct.VrefDqR3Nib7     = 0;
    o_struct.VrefDqR3Nib8     = 0;
    o_struct.VrefDqR3Nib9     = 0;
    o_struct.VrefDqR3Nib10     = 0;
    o_struct.VrefDqR3Nib11     = 0;
    o_struct.VrefDqR3Nib12     = 0;
    o_struct.VrefDqR3Nib13     = 0;
    o_struct.VrefDqR3Nib14     = 0;
    o_struct.VrefDqR3Nib15     = 0;
    o_struct.VrefDqR3Nib16     = 0;
    o_struct.VrefDqR3Nib17     = 0;
    o_struct.VrefDqR3Nib18     = 0;
    o_struct.VrefDqR3Nib19     = 0;

    // Note: the MR's are moved to their separate section just for clarity

    // Note: not seeing these set in PHY init and that seems incorrect
    o_struct.VrefCSR0Nib0     = 0;
    o_struct.VrefCSR0Nib1     = 0;
    o_struct.VrefCSR0Nib2     = 0;
    o_struct.VrefCSR0Nib3     = 0;
    o_struct.VrefCSR0Nib4     = 0;
    o_struct.VrefCSR0Nib5     = 0;
    o_struct.VrefCSR0Nib6     = 0;
    o_struct.VrefCSR0Nib7     = 0;
    o_struct.VrefCSR0Nib8     = 0;
    o_struct.VrefCSR0Nib9     = 0;
    o_struct.VrefCSR0Nib10     = 0;
    o_struct.VrefCSR0Nib11     = 0;
    o_struct.VrefCSR0Nib12     = 0;
    o_struct.VrefCSR0Nib13     = 0;
    o_struct.VrefCSR0Nib14     = 0;
    o_struct.VrefCSR0Nib15     = 0;
    o_struct.VrefCSR0Nib16     = 0;
    o_struct.VrefCSR0Nib17     = 0;
    o_struct.VrefCSR0Nib18     = 0;
    o_struct.VrefCSR0Nib19     = 0;
    o_struct.VrefCSR1Nib0     = 0;
    o_struct.VrefCSR1Nib1     = 0;
    o_struct.VrefCSR1Nib2     = 0;
    o_struct.VrefCSR1Nib3     = 0;
    o_struct.VrefCSR1Nib4     = 0;
    o_struct.VrefCSR1Nib5     = 0;
    o_struct.VrefCSR1Nib6     = 0;
    o_struct.VrefCSR1Nib7     = 0;
    o_struct.VrefCSR1Nib8     = 0;
    o_struct.VrefCSR1Nib9     = 0;
    o_struct.VrefCSR1Nib10     = 0;
    o_struct.VrefCSR1Nib11     = 0;
    o_struct.VrefCSR1Nib12     = 0;
    o_struct.VrefCSR1Nib13     = 0;
    o_struct.VrefCSR1Nib14     = 0;
    o_struct.VrefCSR1Nib15     = 0;
    o_struct.VrefCSR1Nib16     = 0;
    o_struct.VrefCSR1Nib17     = 0;
    o_struct.VrefCSR1Nib18     = 0;
    o_struct.VrefCSR1Nib19     = 0;
    o_struct.VrefCSR2Nib0     = 0;
    o_struct.VrefCSR2Nib1     = 0;
    o_struct.VrefCSR2Nib2     = 0;
    o_struct.VrefCSR2Nib3     = 0;
    o_struct.VrefCSR2Nib4     = 0;
    o_struct.VrefCSR2Nib5     = 0;
    o_struct.VrefCSR2Nib6     = 0;
    o_struct.VrefCSR2Nib7     = 0;
    o_struct.VrefCSR2Nib8     = 0;
    o_struct.VrefCSR2Nib9     = 0;
    o_struct.VrefCSR2Nib10     = 0;
    o_struct.VrefCSR2Nib11     = 0;
    o_struct.VrefCSR2Nib12     = 0;
    o_struct.VrefCSR2Nib13     = 0;
    o_struct.VrefCSR2Nib14     = 0;
    o_struct.VrefCSR2Nib15     = 0;
    o_struct.VrefCSR2Nib16     = 0;
    o_struct.VrefCSR2Nib17     = 0;
    o_struct.VrefCSR2Nib18     = 0;
    o_struct.VrefCSR2Nib19     = 0;
    o_struct.VrefCSR3Nib0     = 0;
    o_struct.VrefCSR3Nib1     = 0;
    o_struct.VrefCSR3Nib2     = 0;
    o_struct.VrefCSR3Nib3     = 0;
    o_struct.VrefCSR3Nib4     = 0;
    o_struct.VrefCSR3Nib5     = 0;
    o_struct.VrefCSR3Nib6     = 0;
    o_struct.VrefCSR3Nib7     = 0;
    o_struct.VrefCSR3Nib8     = 0;
    o_struct.VrefCSR3Nib9     = 0;
    o_struct.VrefCSR3Nib10     = 0;
    o_struct.VrefCSR3Nib11     = 0;
    o_struct.VrefCSR3Nib12     = 0;
    o_struct.VrefCSR3Nib13     = 0;
    o_struct.VrefCSR3Nib14     = 0;
    o_struct.VrefCSR3Nib15     = 0;
    o_struct.VrefCSR3Nib16     = 0;
    o_struct.VrefCSR3Nib17     = 0;
    o_struct.VrefCSR3Nib18     = 0;
    o_struct.VrefCSR3Nib19     = 0;
    o_struct.VrefCAR0Nib0     = 0;
    o_struct.VrefCAR0Nib1     = 0;
    o_struct.VrefCAR0Nib2     = 0;
    o_struct.VrefCAR0Nib3     = 0;
    o_struct.VrefCAR0Nib4     = 0;
    o_struct.VrefCAR0Nib5     = 0;
    o_struct.VrefCAR0Nib6     = 0;
    o_struct.VrefCAR0Nib7     = 0;
    o_struct.VrefCAR0Nib8     = 0;
    o_struct.VrefCAR0Nib9     = 0;
    o_struct.VrefCAR0Nib10     = 0;
    o_struct.VrefCAR0Nib11     = 0;
    o_struct.VrefCAR0Nib12     = 0;
    o_struct.VrefCAR0Nib13     = 0;
    o_struct.VrefCAR0Nib14     = 0;
    o_struct.VrefCAR0Nib15     = 0;
    o_struct.VrefCAR0Nib16     = 0;
    o_struct.VrefCAR0Nib17     = 0;
    o_struct.VrefCAR0Nib18     = 0;
    o_struct.VrefCAR0Nib19     = 0;
    o_struct.VrefCAR1Nib0     = 0;
    o_struct.VrefCAR1Nib1     = 0;
    o_struct.VrefCAR1Nib2     = 0;
    o_struct.VrefCAR1Nib3     = 0;
    o_struct.VrefCAR1Nib4     = 0;
    o_struct.VrefCAR1Nib5     = 0;
    o_struct.VrefCAR1Nib6     = 0;
    o_struct.VrefCAR1Nib7     = 0;
    o_struct.VrefCAR1Nib8     = 0;
    o_struct.VrefCAR1Nib9     = 0;
    o_struct.VrefCAR1Nib10     = 0;
    o_struct.VrefCAR1Nib11     = 0;
    o_struct.VrefCAR1Nib12     = 0;
    o_struct.VrefCAR1Nib13     = 0;
    o_struct.VrefCAR1Nib14     = 0;
    o_struct.VrefCAR1Nib15     = 0;
    o_struct.VrefCAR1Nib16     = 0;
    o_struct.VrefCAR1Nib17     = 0;
    o_struct.VrefCAR1Nib18     = 0;
    o_struct.VrefCAR1Nib19     = 0;
    o_struct.VrefCAR2Nib0     = 0;
    o_struct.VrefCAR2Nib1     = 0;
    o_struct.VrefCAR2Nib2     = 0;
    o_struct.VrefCAR2Nib3     = 0;
    o_struct.VrefCAR2Nib4     = 0;
    o_struct.VrefCAR2Nib5     = 0;
    o_struct.VrefCAR2Nib6     = 0;
    o_struct.VrefCAR2Nib7     = 0;
    o_struct.VrefCAR2Nib8     = 0;
    o_struct.VrefCAR2Nib9     = 0;
    o_struct.VrefCAR2Nib10     = 0;
    o_struct.VrefCAR2Nib11     = 0;
    o_struct.VrefCAR2Nib12     = 0;
    o_struct.VrefCAR2Nib13     = 0;
    o_struct.VrefCAR2Nib14     = 0;
    o_struct.VrefCAR2Nib15     = 0;
    o_struct.VrefCAR2Nib16     = 0;
    o_struct.VrefCAR2Nib17     = 0;
    o_struct.VrefCAR2Nib18     = 0;
    o_struct.VrefCAR2Nib19     = 0;
    o_struct.VrefCAR3Nib0     = 0;
    o_struct.VrefCAR3Nib1     = 0;
    o_struct.VrefCAR3Nib2     = 0;
    o_struct.VrefCAR3Nib3     = 0;
    o_struct.VrefCAR3Nib4     = 0;
    o_struct.VrefCAR3Nib5     = 0;
    o_struct.VrefCAR3Nib6     = 0;
    o_struct.VrefCAR3Nib7     = 0;
    o_struct.VrefCAR3Nib8     = 0;
    o_struct.VrefCAR3Nib9     = 0;
    o_struct.VrefCAR3Nib10     = 0;
    o_struct.VrefCAR3Nib11     = 0;
    o_struct.VrefCAR3Nib12     = 0;
    o_struct.VrefCAR3Nib13     = 0;
    o_struct.VrefCAR3Nib14     = 0;
    o_struct.VrefCAR3Nib15     = 0;
    o_struct.VrefCAR3Nib16     = 0;
    o_struct.VrefCAR3Nib17     = 0;
    o_struct.VrefCAR3Nib18     = 0;
    o_struct.VrefCAR3Nib19     = 0;

    // No lanes disabled
    o_struct.DisabledDB0LaneR0     = 0;
    o_struct.DisabledDB1LaneR0     = 0;
    o_struct.DisabledDB2LaneR0     = 0;
    o_struct.DisabledDB3LaneR0     = 0;
    o_struct.DisabledDB4LaneR0     = 0;
    o_struct.DisabledDB5LaneR0     = 0;
    o_struct.DisabledDB6LaneR0     = 0;
    o_struct.DisabledDB7LaneR0     = 0;
    o_struct.DisabledDB8LaneR0     = 0;
    o_struct.DisabledDB9LaneR0     = 0;
    o_struct.DisabledDB0LaneR1     = 0;
    o_struct.DisabledDB1LaneR1     = 0;
    o_struct.DisabledDB2LaneR1     = 0;
    o_struct.DisabledDB3LaneR1     = 0;
    o_struct.DisabledDB4LaneR1     = 0;
    o_struct.DisabledDB5LaneR1     = 0;
    o_struct.DisabledDB6LaneR1     = 0;
    o_struct.DisabledDB7LaneR1     = 0;
    o_struct.DisabledDB8LaneR1     = 0;
    o_struct.DisabledDB9LaneR1     = 0;
    o_struct.DisabledDB0LaneR2     = 0;
    o_struct.DisabledDB1LaneR2     = 0;
    o_struct.DisabledDB2LaneR2     = 0;
    o_struct.DisabledDB3LaneR2     = 0;
    o_struct.DisabledDB4LaneR2     = 0;
    o_struct.DisabledDB5LaneR2     = 0;
    o_struct.DisabledDB6LaneR2     = 0;
    o_struct.DisabledDB7LaneR2     = 0;
    o_struct.DisabledDB8LaneR2     = 0;
    o_struct.DisabledDB9LaneR2     = 0;
    o_struct.DisabledDB0LaneR3     = 0;
    o_struct.DisabledDB1LaneR3     = 0;
    o_struct.DisabledDB2LaneR3     = 0;
    o_struct.DisabledDB3LaneR3     = 0;
    o_struct.DisabledDB4LaneR3     = 0;
    o_struct.DisabledDB5LaneR3     = 0;
    o_struct.DisabledDB6LaneR3     = 0;
    o_struct.DisabledDB7LaneR3     = 0;
    o_struct.DisabledDB8LaneR3     = 0;
    o_struct.DisabledDB9LaneR3     = 0;
    o_struct.QCS_Dly_Margin_A0     = 0;
    o_struct.QCA_Dly_Margin_A0     = 0;
    o_struct.QCS_Dly_Margin_A1     = 0;
    o_struct.QCA_Dly_Margin_A1     = 0;
    o_struct.QCS_Dly_Margin_A2     = 0;
    o_struct.QCA_Dly_Margin_A2     = 0;
    o_struct.QCS_Dly_Margin_A3     = 0;
    o_struct.QCA_Dly_Margin_A3     = 0;
    o_struct.QCS_Dly_Margin_B0     = 0;
    o_struct.QCA_Dly_Margin_B0     = 0;
    o_struct.QCS_Dly_Margin_B1     = 0;
    o_struct.QCA_Dly_Margin_B1     = 0;
    o_struct.QCS_Dly_Margin_B2     = 0;
    o_struct.QCA_Dly_Margin_B2     = 0;
    o_struct.QCS_Dly_Margin_B3     = 0;
    o_struct.QCA_Dly_Margin_B3     = 0;
    o_struct.PmuInternalRev0     = 0;
    o_struct.PmuInternalRev1     = 0;

    // Initializes the MR values - splitting this off so it's easy to see
    {
        // MR0 is a 24 to correspond with CL=40
        o_struct.MR0_A0     = 0x24;
        o_struct.MR0_A1     = 0x24;
        o_struct.MR0_A2     = 0x24;
        o_struct.MR0_A3     = 0x24;
        o_struct.MR0_B0     = 0x24;
        o_struct.MR0_B1     = 0x24;
        o_struct.MR0_B2     = 0x24;
        o_struct.MR0_B3     = 0x24;

        // Internal write timing and CS assertion during MPC are both 1's
        o_struct.MR2_A0     = 0x90;
        o_struct.MR2_A1     = 0x90;
        o_struct.MR2_A2     = 0x90;
        o_struct.MR2_A3     = 0x90;
        o_struct.MR2_B0     = 0x90;
        o_struct.MR2_B1     = 0x90;
        o_struct.MR2_B2     = 0x90;
        o_struct.MR2_B3     = 0x90;

        // No internal cycle alignments yet
        o_struct.MR3_A0     = 0;
        o_struct.MR3_A1     = 0;
        o_struct.MR3_A2     = 0;
        o_struct.MR3_A3     = 0;
        o_struct.MR3_B0     = 0;
        o_struct.MR3_B1     = 0;
        o_struct.MR3_B2     = 0;
        o_struct.MR3_B3     = 0;
        o_struct.MR3R0Nib0     = 0;
        o_struct.MR3R0Nib1     = 0;
        o_struct.MR3R0Nib10     = 0;
        o_struct.MR3R0Nib11     = 0;
        o_struct.MR3R0Nib12     = 0;
        o_struct.MR3R0Nib13     = 0;
        o_struct.MR3R0Nib14     = 0;
        o_struct.MR3R0Nib15     = 0;
        o_struct.MR3R0Nib16     = 0;
        o_struct.MR3R0Nib17     = 0;
        o_struct.MR3R0Nib18     = 0;
        o_struct.MR3R0Nib19     = 0;
        o_struct.MR3R0Nib2     = 0;
        o_struct.MR3R0Nib3     = 0;
        o_struct.MR3R0Nib4     = 0;
        o_struct.MR3R0Nib5     = 0;
        o_struct.MR3R0Nib6     = 0;
        o_struct.MR3R0Nib7     = 0;
        o_struct.MR3R0Nib8     = 0;
        o_struct.MR3R0Nib9     = 0;
        o_struct.MR3R1Nib0     = 0;
        o_struct.MR3R1Nib1     = 0;
        o_struct.MR3R1Nib10     = 0;
        o_struct.MR3R1Nib11     = 0;
        o_struct.MR3R1Nib12     = 0;
        o_struct.MR3R1Nib13     = 0;
        o_struct.MR3R1Nib14     = 0;
        o_struct.MR3R1Nib15     = 0;
        o_struct.MR3R1Nib16     = 0;
        o_struct.MR3R1Nib17     = 0;
        o_struct.MR3R1Nib18     = 0;
        o_struct.MR3R1Nib19     = 0;
        o_struct.MR3R1Nib2     = 0;
        o_struct.MR3R1Nib3     = 0;
        o_struct.MR3R1Nib4     = 0;
        o_struct.MR3R1Nib5     = 0;
        o_struct.MR3R1Nib6     = 0;
        o_struct.MR3R1Nib7     = 0;
        o_struct.MR3R1Nib8     = 0;
        o_struct.MR3R1Nib9     = 0;
        o_struct.MR3R2Nib0     = 0;
        o_struct.MR3R2Nib1     = 0;
        o_struct.MR3R2Nib10     = 0;
        o_struct.MR3R2Nib11     = 0;
        o_struct.MR3R2Nib12     = 0;
        o_struct.MR3R2Nib13     = 0;
        o_struct.MR3R2Nib14     = 0;
        o_struct.MR3R2Nib15     = 0;
        o_struct.MR3R2Nib16     = 0;
        o_struct.MR3R2Nib17     = 0;
        o_struct.MR3R2Nib18     = 0;
        o_struct.MR3R2Nib19     = 0;
        o_struct.MR3R2Nib2     = 0;
        o_struct.MR3R2Nib3     = 0;
        o_struct.MR3R2Nib4     = 0;
        o_struct.MR3R2Nib5     = 0;
        o_struct.MR3R2Nib6     = 0;
        o_struct.MR3R2Nib7     = 0;
        o_struct.MR3R2Nib8     = 0;
        o_struct.MR3R2Nib9     = 0;
        o_struct.MR3R3Nib0     = 0;
        o_struct.MR3R3Nib1     = 0;
        o_struct.MR3R3Nib10     = 0;
        o_struct.MR3R3Nib11     = 0;
        o_struct.MR3R3Nib12     = 0;
        o_struct.MR3R3Nib13     = 0;
        o_struct.MR3R3Nib14     = 0;
        o_struct.MR3R3Nib15     = 0;
        o_struct.MR3R3Nib16     = 0;
        o_struct.MR3R3Nib17     = 0;
        o_struct.MR3R3Nib18     = 0;
        o_struct.MR3R3Nib19     = 0;
        o_struct.MR3R3Nib2     = 0;
        o_struct.MR3R3Nib3     = 0;
        o_struct.MR3R3Nib4     = 0;
        o_struct.MR3R3Nib5     = 0;
        o_struct.MR3R3Nib6     = 0;
        o_struct.MR3R3Nib7     = 0;
        o_struct.MR3R3Nib8     = 0;
        o_struct.MR3R3Nib9     = 0;

        // tREFI x1
        o_struct.MR4_A0     = 0x01;
        o_struct.MR4_A1     = 0x01;
        o_struct.MR4_A2     = 0x01;
        o_struct.MR4_A3     = 0x01;
        o_struct.MR4_B0     = 0x01;
        o_struct.MR4_B1     = 0x01;
        o_struct.MR4_B2     = 0x01;
        o_struct.MR4_B3     = 0x01;

        o_struct.MR5_A0     = 0x00;
        o_struct.MR5_A1     = 0x00;
        o_struct.MR5_A2     = 0x00;
        o_struct.MR5_A3     = 0x00;
        o_struct.MR5_B0     = 0x00;
        o_struct.MR5_B1     = 0x00;
        o_struct.MR5_B2     = 0x00;
        o_struct.MR5_B3     = 0x00;

        // tWR     = 72, tRTP     = 18
        o_struct.MR6_A0     = 0x44;
        o_struct.MR6_A1     = 0x44;
        o_struct.MR6_A2     = 0x44;
        o_struct.MR6_A3     = 0x44;
        o_struct.MR6_B0     = 0x44;
        o_struct.MR6_B1     = 0x44;
        o_struct.MR6_B2     = 0x44;
        o_struct.MR6_B3     = 0x44;

        // Pre/post amble settings using the default
        o_struct.MR8_A0     = 0x08;
        o_struct.MR8_A1     = 0x08;
        o_struct.MR8_A2     = 0x08;
        o_struct.MR8_A3     = 0x08;
        o_struct.MR8_B0     = 0x08;
        o_struct.MR8_B1     = 0x08;
        o_struct.MR8_B2     = 0x08;
        o_struct.MR8_B3     = 0x08;

        // VREF settings -> using 75% (completely fudged)
        o_struct.MR10_A0     = 0x29;
        o_struct.MR10_A1     = 0x29;
        o_struct.MR10_A2     = 0x29;
        o_struct.MR10_A3     = 0x29;
        o_struct.MR10_B0     = 0x29;
        o_struct.MR10_B1     = 0x29;
        o_struct.MR10_B2     = 0x29;
        o_struct.MR10_B3     = 0x29;
        o_struct.MR11_A0     = 0x29;
        o_struct.MR11_A1     = 0x29;
        o_struct.MR11_A2     = 0x29;
        o_struct.MR11_A3     = 0x29;
        o_struct.MR11_B0     = 0x29;
        o_struct.MR11_B1     = 0x29;
        o_struct.MR11_B2     = 0x29;
        o_struct.MR11_B3     = 0x29;
        o_struct.MR11_A0_next     = 0x29;
        o_struct.MR11_A1_next     = 0x29;
        o_struct.MR11_A2_next     = 0x29;
        o_struct.MR11_A3_next     = 0x29;
        o_struct.MR11_B0_next     = 0x29;
        o_struct.MR11_B1_next     = 0x29;
        o_struct.MR11_B2_next     = 0x29;
        o_struct.MR11_B3_next     = 0x29;
        o_struct.MR12_A0     = 0x29;
        o_struct.MR12_A1     = 0x29;
        o_struct.MR12_A2     = 0x29;
        o_struct.MR12_A3     = 0x29;
        o_struct.MR12_B0     = 0x29;
        o_struct.MR12_B1     = 0x29;
        o_struct.MR12_B2     = 0x29;
        o_struct.MR12_B3     = 0x29;
        o_struct.MR12_A0_next     = 0x29;
        o_struct.MR12_A1_next     = 0x29;
        o_struct.MR12_A2_next     = 0x29;
        o_struct.MR12_A3_next     = 0x29;
        o_struct.MR12_B0_next     = 0x29;
        o_struct.MR12_B1_next     = 0x29;
        o_struct.MR12_B2_next     = 0x29;
        o_struct.MR12_B3_next     = 0x29;

        // tDLLK=1536
        o_struct.MR13_A0     = 0x04;
        o_struct.MR13_A1     = 0x04;
        o_struct.MR13_A2     = 0x04;
        o_struct.MR13_A3     = 0x04;
        o_struct.MR13_B0     = 0x04;
        o_struct.MR13_B1     = 0x04;
        o_struct.MR13_B2     = 0x04;
        o_struct.MR13_B3     = 0x04;
        o_struct.MR13_A0_next     = 0x04;
        o_struct.MR13_A1_next     = 0x04;
        o_struct.MR13_A2_next     = 0x04;
        o_struct.MR13_A3_next     = 0x04;
        o_struct.MR13_B0_next     = 0x04;
        o_struct.MR13_B1_next     = 0x04;
        o_struct.MR13_B2_next     = 0x04;
        o_struct.MR13_B3_next     = 0x04;

        // Default ECC settings
        o_struct.MR14_A0     = 0x00;
        o_struct.MR14_A1     = 0x00;
        o_struct.MR14_A2     = 0x00;
        o_struct.MR14_A3     = 0x00;
        o_struct.MR14_B0     = 0x00;
        o_struct.MR14_B1     = 0x00;
        o_struct.MR14_B2     = 0x00;
        o_struct.MR14_B3     = 0x00;

        // Default ECC settings
        o_struct.MR15_A0     = 0x00;
        o_struct.MR15_A1     = 0x00;
        o_struct.MR15_A2     = 0x00;
        o_struct.MR15_A3     = 0x00;
        o_struct.MR15_B0     = 0x00;
        o_struct.MR15_B1     = 0x00;
        o_struct.MR15_B2     = 0x00;
        o_struct.MR15_B3     = 0x00;

        // Clock ODT disable - going with default
        o_struct.MR32_A0     = 0x00;
        o_struct.MR32_A1     = 0x00;
        o_struct.MR32_A2     = 0x00;
        o_struct.MR32_A3     = 0x00;
        o_struct.MR32_B0     = 0x00;
        o_struct.MR32_B1     = 0x00;
        o_struct.MR32_B2     = 0x00;
        o_struct.MR32_B3     = 0x00;
        o_struct.MR32_A0_next     = 0x00;
        o_struct.MR32_A1_next     = 0x00;
        o_struct.MR32_A2_next     = 0x00;
        o_struct.MR32_A3_next     = 0x00;
        o_struct.MR32_B0_next     = 0x00;
        o_struct.MR32_B1_next     = 0x00;
        o_struct.MR32_B2_next     = 0x00;
        o_struct.MR32_B3_next     = 0x00;
        o_struct.MR32_ORG_A0     = 0x00;
        o_struct.MR32_ORG_A1     = 0x00;
        o_struct.MR32_ORG_A2     = 0x00;
        o_struct.MR32_ORG_A3     = 0x00;
        o_struct.MR32_ORG_B0     = 0x00;
        o_struct.MR32_ORG_B1     = 0x00;
        o_struct.MR32_ORG_B2     = 0x00;
        o_struct.MR32_ORG_B3     = 0x00;
        o_struct.MR32_ORG_A0_next     = 0x00;
        o_struct.MR32_ORG_A1_next     = 0x00;
        o_struct.MR32_ORG_A2_next     = 0x00;
        o_struct.MR32_ORG_A3_next     = 0x00;
        o_struct.MR32_ORG_B0_next     = 0x00;
        o_struct.MR32_ORG_B1_next     = 0x00;
        o_struct.MR32_ORG_B2_next     = 0x00;
        o_struct.MR32_ORG_B3_next     = 0x00;

        // CA/DQS park disable -> going with default
        o_struct.MR33_A0     = 0x00;
        o_struct.MR33_A1     = 0x00;
        o_struct.MR33_A2     = 0x00;
        o_struct.MR33_A3     = 0x00;
        o_struct.MR33_B0     = 0x00;
        o_struct.MR33_B1     = 0x00;
        o_struct.MR33_B2     = 0x00;
        o_struct.MR33_B3     = 0x00;
        o_struct.MR33_A0_next     = 0x00;
        o_struct.MR33_A1_next     = 0x00;
        o_struct.MR33_A2_next     = 0x00;
        o_struct.MR33_A3_next     = 0x00;
        o_struct.MR33_B0_next     = 0x00;
        o_struct.MR33_B1_next     = 0x00;
        o_struct.MR33_B2_next     = 0x00;
        o_struct.MR33_B3_next     = 0x00;
        o_struct.MR33_ORG_A0     = 0x00;
        o_struct.MR33_ORG_A1     = 0x00;
        o_struct.MR33_ORG_A2     = 0x00;
        o_struct.MR33_ORG_A3     = 0x00;
        o_struct.MR33_ORG_B0     = 0x00;
        o_struct.MR33_ORG_B1     = 0x00;
        o_struct.MR33_ORG_B2     = 0x00;
        o_struct.MR33_ORG_B3     = 0x00;
        o_struct.MR33_ORG_A0_next     = 0x00;
        o_struct.MR33_ORG_A1_next     = 0x00;
        o_struct.MR33_ORG_A2_next     = 0x00;
        o_struct.MR33_ORG_A3_next     = 0x00;
        o_struct.MR33_ORG_B0_next     = 0x00;
        o_struct.MR33_ORG_B1_next     = 0x00;
        o_struct.MR33_ORG_B2_next     = 0x00;
        o_struct.MR33_ORG_B3_next     = 0x00;

        // RTT park disabled going with default
        o_struct.MR34_A0     = 0x00;
        o_struct.MR34_A1     = 0x00;
        o_struct.MR34_A2     = 0x00;
        o_struct.MR34_A3     = 0x00;
        o_struct.MR34_B0     = 0x00;
        o_struct.MR34_B1     = 0x00;
        o_struct.MR34_B2     = 0x00;
        o_struct.MR34_B3     = 0x00;

        // RTT_NOM off going with default
        o_struct.MR35_A0     = 0x00;
        o_struct.MR35_A1     = 0x00;
        o_struct.MR35_A2     = 0x00;
        o_struct.MR35_A3     = 0x00;
        o_struct.MR35_B0     = 0x00;
        o_struct.MR35_B1     = 0x00;
        o_struct.MR35_B2     = 0x00;
        o_struct.MR35_B3     = 0x00;

        // ODTL WR control offset -> 0 clock
        o_struct.MR37_A0     = 0x2d;
        o_struct.MR37_A1     = 0x2d;
        o_struct.MR37_A2     = 0x2d;
        o_struct.MR37_A3     = 0x2d;
        o_struct.MR37_B0     = 0x2d;
        o_struct.MR37_B1     = 0x2d;
        o_struct.MR37_B2     = 0x2d;
        o_struct.MR37_B3     = 0x2d;

        // ODTL NT control offset -> 0 clock
        o_struct.MR38_A0     = 0x2d;
        o_struct.MR38_A1     = 0x2d;
        o_struct.MR38_A2     = 0x2d;
        o_struct.MR38_A3     = 0x2d;
        o_struct.MR38_B0     = 0x2d;
        o_struct.MR38_B1     = 0x2d;
        o_struct.MR38_B2     = 0x2d;
        o_struct.MR38_B3     = 0x2d;

        // ODTL RD control offset -> 0 clock
        o_struct.MR39_A0     = 0x2d;
        o_struct.MR39_A1     = 0x2d;
        o_struct.MR39_A2     = 0x2d;
        o_struct.MR39_A3     = 0x2d;
        o_struct.MR39_B0     = 0x2d;
        o_struct.MR39_B1     = 0x2d;
        o_struct.MR39_B2     = 0x2d;
        o_struct.MR39_B3     = 0x2d;

        // ECC disabled
        o_struct.MR50_A0     = 0x00;
        o_struct.MR50_A1     = 0x00;
        o_struct.MR50_A2     = 0x00;
        o_struct.MR50_A3     = 0x00;
        o_struct.MR50_B0     = 0x00;
        o_struct.MR50_B1     = 0x00;
        o_struct.MR50_B2     = 0x00;
        o_struct.MR50_B3     = 0x00;

        // No CRC threshold
        o_struct.MR51_A0     = 0x00;
        o_struct.MR51_A1     = 0x00;
        o_struct.MR51_A2     = 0x00;
        o_struct.MR51_A3     = 0x00;
        o_struct.MR51_B0     = 0x00;
        o_struct.MR51_B1     = 0x00;
        o_struct.MR51_B2     = 0x00;
        o_struct.MR51_B3     = 0x00;

        // No CRC threshold
        o_struct.MR52_A0     = 0x00;
        o_struct.MR52_A1     = 0x00;
        o_struct.MR52_A2     = 0x00;
        o_struct.MR52_A3     = 0x00;
        o_struct.MR52_B0     = 0x00;
        o_struct.MR52_B1     = 0x00;
        o_struct.MR52_B2     = 0x00;
        o_struct.MR52_B3     = 0x00;

        // DFE enabled down to 4-tap
        o_struct.MR111_A0     = 0x00;
        o_struct.MR111_A1     = 0x00;
        o_struct.MR111_A2     = 0x00;
        o_struct.MR111_A3     = 0x00;
        o_struct.MR111_B0     = 0x00;
        o_struct.MR111_B1     = 0x00;
        o_struct.MR111_B2     = 0x00;
        o_struct.MR111_B3     = 0x00;
    }

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Processes a streaming message from the mailbox protocol
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode process_streaming_message(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    constexpr uint64_t STRING_INDEX     = 32;
    constexpr uint64_t STRING_INDEX_LEN = 32;
    constexpr uint64_t DATA             = 32;
    constexpr uint64_t DATA_LEN         = 32;
    constexpr uint64_t NUM_DATA         = 48;
    constexpr uint64_t NUM_DATA_LEN     = 16;

    // Grabbing a streaming message should be almost instantaneous
    // Only using a loop count of 1 (1 ms) to hopefully allow draminit to run quickly
    constexpr uint64_t LOOP_COUNT = 1;
    fapi2::buffer<uint64_t> l_mail;
    uint32_t l_string_index = 0;
    uint16_t l_num_data = 0;

    // Streaming messages use the 32-bit mode
    FAPI_TRY(mss::ody::phy::get_mail(i_target, STREAMING_SMBUS_MSG_MODE, LOOP_COUNT, l_mail));

    // Each streaming message is at least 32-bits
    // The first message is a 32-bit string index
    // The right most 16 bits contain the number of additional pieces of data to grab
    // Processing out this information here
    l_mail.extractToRight<STRING_INDEX, STRING_INDEX_LEN>(l_string_index)
    .extractToRight<NUM_DATA, NUM_DATA_LEN>(l_num_data);

    // Print out the message's "string index" to use to decode the string
    FAPI_INF(TARGTIDFORMAT " Message string index: 0x%08x has %u more data pieces for decode", TARGTID, l_string_index,
             l_num_data);

    // Print out the data pieces that are included in the string index
    // Each piece of data is another 32-bit mode mailbox interaction
    for(uint16_t l_num = 0; l_num < l_num_data; ++l_num)
    {
        uint32_t l_data = 0;
        FAPI_TRY(mss::ody::phy::get_mail(i_target, STREAMING_SMBUS_MSG_MODE, LOOP_COUNT, l_mail));

        // Grab the data
        l_mail.extractToRight<DATA, DATA_LEN>(l_data);

        // Print the data
        // The data can be post processed using the Synopsys .strings file (not including here as it could be size prohibitive)
        FAPI_INF(TARGTIDFORMAT " message data %5u: 0x%08x", TARGTID, l_num, l_data);
    }

    FAPI_INF(TARGTIDFORMAT " End of message", TARGTID);

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Processes an SMBus message request (aka runs an RCW via i2c)
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note This function only handles the message interface for right now
/// TODO:ZEN:MST-1541 Add DDR5 RCW writes using i2c when SMBus message is received
///
fapi2::ReturnCode process_smbus_message(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    // Grabbing an SMBUS message should be relatively quick
    // Only using a loop count of 10 (10 ms) to hopefully allow draminit to run quickly
    constexpr uint64_t LOOP_COUNT = 10;

    fapi2::buffer<uint64_t> l_mail;

    // SMBus messages (containing data) use the 32 bit interface
    FAPI_TRY(mss::ody::phy::get_mail(i_target, STREAMING_SMBUS_MSG_MODE, LOOP_COUNT, l_mail));

    {
        // Process the mail data into the RCW format
        const rcw_id l_rcw_info(l_mail);

        FAPI_INF(TARGTIDFORMAT " RCW info. Channel id: 0x%x, DIMM id: 0x%x, RCW id: 0x%02x, RCW page: 0x%02x, RCW val: 0x%02x",
                 TARGTID, l_rcw_info.iv_channel_id, l_rcw_info.iv_dimm_id, l_rcw_info.iv_rcw_id, l_rcw_info.iv_rcw_page,
                 l_rcw_info.iv_rcw_val);

        // Send the RCW: Note: we cannot do this yet see the below TODO
        // TODO:ZEN:MST-1541 Add DDR5 RCW writes using i2c when SMBus message is received
    }

    // Look for the SMBus complete message (only 16 bits!)
    FAPI_TRY(mss::ody::phy::get_mail(i_target, MAJOR_MSG_MODE, LOOP_COUNT, l_mail));

    // If we do not get the SMBus complete message, assert but log the error as recovered
    // We might be able to continue, but this is definitely weird
    // Note: uint16_t is ok for the print as the mail is only 16bits
    FAPI_ASSERT(l_mail == SMBUS_SYNC,
                fapi2::ODY_DRAMINIT_SMBUS_SYNC_MSG_NOT_FOUND(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                .set_PORT_TARGET(i_target)
                .set_SYNOPSYS_MESSAGE(l_mail),
                TARGTIDFORMAT " sees a message of 0x%x instead of 0x51 (SMBUS_SYNC)", TARGTID, uint16_t(l_mail));

fapi_try_exit:
    return fapi2::current_err;
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
    const uint64_t MIRCORESET_IBM     = convert_synopsys_to_ibm_reg_addr(MIRCORESET);

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
/// @brief Stops the ARC processor
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode stall_arc_processor(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    // Stops training (aka stalls the ARC processor)
    fapi2::buffer<uint64_t> l_data;
    l_data.setBit<scomt::mp::DWC_DDRPHYA_APBONLY0_MICRORESET_STALLTOMICRO>();
    return fapi2::putScom(i_target, scomt::mp::DWC_DDRPHYA_APBONLY0_MICRORESET, l_data);
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
    const uint64_t CALZAP_IBM     = convert_synopsys_to_ibm_reg_addr(CALZAP);

    // Per the Synopsys documentation, to cleanup after the training:
    // 1. Stop the processor (stall it)
    // 2. Reset the calibration engines to their initial state (cal Zap!)
    fapi2::buffer<uint64_t> l_data;

    // 1. Stop the processor (stall it)
    FAPI_TRY(stall_arc_processor(i_target));

    // 2. Reset the calibration engines to their initial state (cal Zap!)
    l_data.flush<0>().setBit<CALZAP_CALZAP>();
    FAPI_TRY(fapi2::putScom(i_target, CALZAP_IBM, l_data));

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Prints the fields from the message block structure
/// @param[in] i_target the target on which to operate
/// @param[in] i_msg_blk message block structure
/// @return None
///
void display_msg_block(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                       const _PMU_SMB_DDR5_1D_t& i_msg_block)
{
    FAPI_INF("   _PMU_SMB_DDR5_1D_t   = { // " TARGTIDFORMAT, TARGTID);
    FAPI_INF("  .AdvTrainOpt          = 0x%02x; // " TARGTIDFORMAT, i_msg_block.AdvTrainOpt, TARGTID);
    FAPI_INF("  .MsgMisc              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MsgMisc, TARGTID);
    FAPI_INF("  .PmuRevision          = 0x%04x; // " TARGTIDFORMAT, i_msg_block.PmuRevision, TARGTID);
    FAPI_INF("  .Pstate               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.Pstate, TARGTID);
    FAPI_INF("  .PllBypassEn          = 0x%02x; // " TARGTIDFORMAT, i_msg_block.PllBypassEn, TARGTID);
    FAPI_INF("  .DRAMFreq             = 0x%04x; // " TARGTIDFORMAT, i_msg_block.DRAMFreq, TARGTID);
    FAPI_INF("  .RCW05_next           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW05_next, TARGTID);
    FAPI_INF("  .RCW06_next           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW06_next, TARGTID);
    FAPI_INF("  .RXEN_ADJ             = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RXEN_ADJ, TARGTID);
    FAPI_INF("  .RX2D_DFE_Misc        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RX2D_DFE_Misc, TARGTID);
    FAPI_INF("  .PhyVref              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.PhyVref, TARGTID);
    FAPI_INF("  .D5Misc               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.D5Misc, TARGTID);
    FAPI_INF("  .WL_ADJ               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.WL_ADJ, TARGTID);
    FAPI_INF("  .CsTestFail           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CsTestFail, TARGTID);
    FAPI_INF("  .SequenceCtrl         = 0x%04x; // " TARGTIDFORMAT, i_msg_block.SequenceCtrl, TARGTID);
    FAPI_INF("  .HdtCtrl              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.HdtCtrl, TARGTID);
    FAPI_INF("  .PhyCfg               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.PhyCfg, TARGTID);
    FAPI_INF("  .ResultAddrOffset     = 0x%04x; // " TARGTIDFORMAT, i_msg_block.ResultAddrOffset, TARGTID);
    FAPI_INF("  .DFIMRLMargin         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DFIMRLMargin, TARGTID);
    FAPI_INF("  .X16Present           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.X16Present, TARGTID);
    FAPI_INF("  .UseBroadcastMR       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.UseBroadcastMR, TARGTID);
    FAPI_INF("  .D5Quickboot          = 0x%02x; // " TARGTIDFORMAT, i_msg_block.D5Quickboot, TARGTID);
    FAPI_INF("  .DisabledDbyte        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDbyte, TARGTID);
    FAPI_INF("  .CATrainOpt           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CATrainOpt, TARGTID);
    FAPI_INF("  .TX2D_DFE_Misc        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.TX2D_DFE_Misc, TARGTID);
    FAPI_INF("  .RX2D_TrainOpt        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RX2D_TrainOpt, TARGTID);
    FAPI_INF("  .TX2D_TrainOpt        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.TX2D_TrainOpt, TARGTID);
    FAPI_INF("  .Share2DVrefResult    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.Share2DVrefResult, TARGTID);
    FAPI_INF("  .MRE_MIN_PULSE        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MRE_MIN_PULSE, TARGTID);
    FAPI_INF("  .DWL_MIN_PULSE        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DWL_MIN_PULSE, TARGTID);
    FAPI_INF("  .PhyConfigOverride    = 0x%04x; // " TARGTIDFORMAT, i_msg_block.PhyConfigOverride, TARGTID);
    FAPI_INF("  .EnabledDQsChA        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.EnabledDQsChA, TARGTID);
    FAPI_INF("  .CsPresentChA         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CsPresentChA, TARGTID);
    FAPI_INF("  .CDD_ChA_RR_3_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RR_3_2, TARGTID);
    FAPI_INF("  .CDD_ChA_RR_3_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RR_3_1, TARGTID);
    FAPI_INF("  .CDD_ChA_RR_3_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RR_3_0, TARGTID);
    FAPI_INF("  .CDD_ChA_RR_2_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RR_2_3, TARGTID);
    FAPI_INF("  .CDD_ChA_RR_2_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RR_2_1, TARGTID);
    FAPI_INF("  .CDD_ChA_RR_2_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RR_2_0, TARGTID);
    FAPI_INF("  .CDD_ChA_RR_1_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RR_1_3, TARGTID);
    FAPI_INF("  .CDD_ChA_RR_1_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RR_1_2, TARGTID);
    FAPI_INF("  .CDD_ChA_RR_1_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RR_1_0, TARGTID);
    FAPI_INF("  .CDD_ChA_RR_0_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RR_0_3, TARGTID);
    FAPI_INF("  .CDD_ChA_RR_0_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RR_0_2, TARGTID);
    FAPI_INF("  .CDD_ChA_RR_0_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RR_0_1, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_3_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_3_3, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_3_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_3_2, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_3_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_3_1, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_3_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_3_0, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_2_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_2_3, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_2_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_2_2, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_2_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_2_1, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_2_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_2_0, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_1_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_1_3, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_1_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_1_2, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_1_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_1_1, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_1_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_1_0, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_0_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_0_3, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_0_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_0_2, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_0_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_0_1, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_0_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_0_0, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_3_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_3_3, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_3_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_3_2, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_3_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_3_1, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_3_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_3_0, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_2_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_2_3, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_2_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_2_2, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_2_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_2_1, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_2_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_2_0, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_1_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_1_3, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_1_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_1_2, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_1_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_1_1, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_1_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_1_0, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_0_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_0_3, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_0_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_0_2, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_0_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_0_1, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_0_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_0_0, TARGTID);
    FAPI_INF("  .CDD_ChA_WW_3_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WW_3_2, TARGTID);
    FAPI_INF("  .CDD_ChA_WW_3_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WW_3_1, TARGTID);
    FAPI_INF("  .CDD_ChA_WW_3_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WW_3_0, TARGTID);
    FAPI_INF("  .CDD_ChA_WW_2_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WW_2_3, TARGTID);
    FAPI_INF("  .CDD_ChA_WW_2_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WW_2_1, TARGTID);
    FAPI_INF("  .CDD_ChA_WW_2_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WW_2_0, TARGTID);
    FAPI_INF("  .CDD_ChA_WW_1_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WW_1_3, TARGTID);
    FAPI_INF("  .CDD_ChA_WW_1_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WW_1_2, TARGTID);
    FAPI_INF("  .CDD_ChA_WW_1_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WW_1_0, TARGTID);
    FAPI_INF("  .CDD_ChA_WW_0_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WW_0_3, TARGTID);
    FAPI_INF("  .CDD_ChA_WW_0_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WW_0_2, TARGTID);
    FAPI_INF("  .CDD_ChA_WW_0_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WW_0_1, TARGTID);
    FAPI_INF("  .MR0_A0               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR0_A0, TARGTID);
    FAPI_INF("  .MR2_A0               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR2_A0, TARGTID);
    FAPI_INF("  .MR3_A0               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3_A0, TARGTID);
    FAPI_INF("  .MR4_A0               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR4_A0, TARGTID);
    FAPI_INF("  .MR5_A0               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR5_A0, TARGTID);
    FAPI_INF("  .MR6_A0               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR6_A0, TARGTID);
    FAPI_INF("  .MR32_A0_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_A0_next, TARGTID);
    FAPI_INF("  .MR8_A0               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR8_A0, TARGTID);
    FAPI_INF("  .MR32_ORG_A0_next     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_ORG_A0_next, TARGTID);
    FAPI_INF("  .MR10_A0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR10_A0, TARGTID);
    FAPI_INF("  .MR11_A0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR11_A0, TARGTID);
    FAPI_INF("  .MR12_A0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR12_A0, TARGTID);
    FAPI_INF("  .MR13_A0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR13_A0, TARGTID);
    FAPI_INF("  .MR14_A0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR14_A0, TARGTID);
    FAPI_INF("  .MR15_A0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR15_A0, TARGTID);
    FAPI_INF("  .MR111_A0             = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR111_A0, TARGTID);
    FAPI_INF("  .MR32_A0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_A0, TARGTID);
    FAPI_INF("  .MR33_A0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_A0, TARGTID);
    FAPI_INF("  .MR34_A0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR34_A0, TARGTID);
    FAPI_INF("  .MR35_A0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR35_A0, TARGTID);
    FAPI_INF("  .MR32_ORG_A0          = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_ORG_A0, TARGTID);
    FAPI_INF("  .MR37_A0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR37_A0, TARGTID);
    FAPI_INF("  .MR38_A0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR38_A0, TARGTID);
    FAPI_INF("  .MR39_A0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR39_A0, TARGTID);
    FAPI_INF("  .MR33_ORG_A0          = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_ORG_A0, TARGTID);
    FAPI_INF("  .MR11_A0_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR11_A0_next, TARGTID);
    FAPI_INF("  .MR12_A0_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR12_A0_next, TARGTID);
    FAPI_INF("  .MR13_A0_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR13_A0_next, TARGTID);
    FAPI_INF("  .CS_Dly_Margin_A0     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CS_Dly_Margin_A0, TARGTID);
    FAPI_INF("  .CS_Vref_Margin_A0    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CS_Vref_Margin_A0, TARGTID);
    FAPI_INF("  .CA_Dly_Margin_A0     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CA_Dly_Margin_A0, TARGTID);
    FAPI_INF("  .CA_Vref_Margin_A0    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CA_Vref_Margin_A0, TARGTID);
    FAPI_INF("  .MR33_ORG_A0_next     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_ORG_A0_next, TARGTID);
    FAPI_INF("  .MR33_A0_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_A0_next, TARGTID);
    FAPI_INF("  .MR50_A0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR50_A0, TARGTID);
    FAPI_INF("  .MR51_A0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR51_A0, TARGTID);
    FAPI_INF("  .MR52_A0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR52_A0, TARGTID);
    FAPI_INF("  .DFE_GainBias_A0      = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DFE_GainBias_A0, TARGTID);
    FAPI_INF("  .MR0_A1               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR0_A1, TARGTID);
    FAPI_INF("  .MR2_A1               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR2_A1, TARGTID);
    FAPI_INF("  .MR3_A1               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3_A1, TARGTID);
    FAPI_INF("  .MR4_A1               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR4_A1, TARGTID);
    FAPI_INF("  .MR5_A1               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR5_A1, TARGTID);
    FAPI_INF("  .MR6_A1               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR6_A1, TARGTID);
    FAPI_INF("  .MR32_A1_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_A1_next, TARGTID);
    FAPI_INF("  .MR8_A1               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR8_A1, TARGTID);
    FAPI_INF("  .MR32_ORG_A1_next     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_ORG_A1_next, TARGTID);
    FAPI_INF("  .MR10_A1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR10_A1, TARGTID);
    FAPI_INF("  .MR11_A1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR11_A1, TARGTID);
    FAPI_INF("  .MR12_A1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR12_A1, TARGTID);
    FAPI_INF("  .MR13_A1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR13_A1, TARGTID);
    FAPI_INF("  .MR14_A1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR14_A1, TARGTID);
    FAPI_INF("  .MR15_A1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR15_A1, TARGTID);
    FAPI_INF("  .MR111_A1             = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR111_A1, TARGTID);
    FAPI_INF("  .MR32_A1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_A1, TARGTID);
    FAPI_INF("  .MR33_A1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_A1, TARGTID);
    FAPI_INF("  .MR34_A1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR34_A1, TARGTID);
    FAPI_INF("  .MR35_A1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR35_A1, TARGTID);
    FAPI_INF("  .MR32_ORG_A1          = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_ORG_A1, TARGTID);
    FAPI_INF("  .MR37_A1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR37_A1, TARGTID);
    FAPI_INF("  .MR38_A1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR38_A1, TARGTID);
    FAPI_INF("  .MR39_A1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR39_A1, TARGTID);
    FAPI_INF("  .MR33_ORG_A1          = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_ORG_A1, TARGTID);
    FAPI_INF("  .MR11_A1_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR11_A1_next, TARGTID);
    FAPI_INF("  .MR12_A1_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR12_A1_next, TARGTID);
    FAPI_INF("  .MR13_A1_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR13_A1_next, TARGTID);
    FAPI_INF("  .CS_Dly_Margin_A1     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CS_Dly_Margin_A1, TARGTID);
    FAPI_INF("  .CS_Vref_Margin_A1    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CS_Vref_Margin_A1, TARGTID);
    FAPI_INF("  .CA_Dly_Margin_A1     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CA_Dly_Margin_A1, TARGTID);
    FAPI_INF("  .CA_Vref_Margin_A1    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CA_Vref_Margin_A1, TARGTID);
    FAPI_INF("  .MR33_ORG_A1_next     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_ORG_A1_next, TARGTID);
    FAPI_INF("  .MR33_A1_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_A1_next, TARGTID);
    FAPI_INF("  .MR50_A1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR50_A1, TARGTID);
    FAPI_INF("  .MR51_A1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR51_A1, TARGTID);
    FAPI_INF("  .MR52_A1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR52_A1, TARGTID);
    FAPI_INF("  .DFE_GainBias_A1      = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DFE_GainBias_A1, TARGTID);
    FAPI_INF("  .MR0_A2               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR0_A2, TARGTID);
    FAPI_INF("  .MR2_A2               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR2_A2, TARGTID);
    FAPI_INF("  .MR3_A2               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3_A2, TARGTID);
    FAPI_INF("  .MR4_A2               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR4_A2, TARGTID);
    FAPI_INF("  .MR5_A2               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR5_A2, TARGTID);
    FAPI_INF("  .MR6_A2               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR6_A2, TARGTID);
    FAPI_INF("  .MR32_A2_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_A2_next, TARGTID);
    FAPI_INF("  .MR8_A2               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR8_A2, TARGTID);
    FAPI_INF("  .MR32_ORG_A2_next     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_ORG_A2_next, TARGTID);
    FAPI_INF("  .MR10_A2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR10_A2, TARGTID);
    FAPI_INF("  .MR11_A2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR11_A2, TARGTID);
    FAPI_INF("  .MR12_A2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR12_A2, TARGTID);
    FAPI_INF("  .MR13_A2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR13_A2, TARGTID);
    FAPI_INF("  .MR14_A2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR14_A2, TARGTID);
    FAPI_INF("  .MR15_A2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR15_A2, TARGTID);
    FAPI_INF("  .MR111_A2             = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR111_A2, TARGTID);
    FAPI_INF("  .MR32_A2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_A2, TARGTID);
    FAPI_INF("  .MR33_A2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_A2, TARGTID);
    FAPI_INF("  .MR34_A2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR34_A2, TARGTID);
    FAPI_INF("  .MR35_A2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR35_A2, TARGTID);
    FAPI_INF("  .MR32_ORG_A2          = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_ORG_A2, TARGTID);
    FAPI_INF("  .MR37_A2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR37_A2, TARGTID);
    FAPI_INF("  .MR38_A2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR38_A2, TARGTID);
    FAPI_INF("  .MR39_A2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR39_A2, TARGTID);
    FAPI_INF("  .MR33_ORG_A2          = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_ORG_A2, TARGTID);
    FAPI_INF("  .MR11_A2_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR11_A2_next, TARGTID);
    FAPI_INF("  .MR12_A2_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR12_A2_next, TARGTID);
    FAPI_INF("  .MR13_A2_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR13_A2_next, TARGTID);
    FAPI_INF("  .CS_Dly_Margin_A2     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CS_Dly_Margin_A2, TARGTID);
    FAPI_INF("  .CS_Vref_Margin_A2    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CS_Vref_Margin_A2, TARGTID);
    FAPI_INF("  .CA_Dly_Margin_A2     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CA_Dly_Margin_A2, TARGTID);
    FAPI_INF("  .CA_Vref_Margin_A2    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CA_Vref_Margin_A2, TARGTID);
    FAPI_INF("  .MR33_ORG_A2_next     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_ORG_A2_next, TARGTID);
    FAPI_INF("  .MR33_A2_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_A2_next, TARGTID);
    FAPI_INF("  .MR50_A2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR50_A2, TARGTID);
    FAPI_INF("  .MR51_A2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR51_A2, TARGTID);
    FAPI_INF("  .MR52_A2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR52_A2, TARGTID);
    FAPI_INF("  .DFE_GainBias_A2      = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DFE_GainBias_A2, TARGTID);
    FAPI_INF("  .MR0_A3               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR0_A3, TARGTID);
    FAPI_INF("  .MR2_A3               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR2_A3, TARGTID);
    FAPI_INF("  .MR3_A3               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3_A3, TARGTID);
    FAPI_INF("  .MR4_A3               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR4_A3, TARGTID);
    FAPI_INF("  .MR5_A3               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR5_A3, TARGTID);
    FAPI_INF("  .MR6_A3               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR6_A3, TARGTID);
    FAPI_INF("  .MR32_A3_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_A3_next, TARGTID);
    FAPI_INF("  .MR8_A3               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR8_A3, TARGTID);
    FAPI_INF("  .MR32_ORG_A3_next     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_ORG_A3_next, TARGTID);
    FAPI_INF("  .MR10_A3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR10_A3, TARGTID);
    FAPI_INF("  .MR11_A3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR11_A3, TARGTID);
    FAPI_INF("  .MR12_A3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR12_A3, TARGTID);
    FAPI_INF("  .MR13_A3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR13_A3, TARGTID);
    FAPI_INF("  .MR14_A3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR14_A3, TARGTID);
    FAPI_INF("  .MR15_A3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR15_A3, TARGTID);
    FAPI_INF("  .MR111_A3             = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR111_A3, TARGTID);
    FAPI_INF("  .MR32_A3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_A3, TARGTID);
    FAPI_INF("  .MR33_A3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_A3, TARGTID);
    FAPI_INF("  .MR34_A3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR34_A3, TARGTID);
    FAPI_INF("  .MR35_A3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR35_A3, TARGTID);
    FAPI_INF("  .MR32_ORG_A3          = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_ORG_A3, TARGTID);
    FAPI_INF("  .MR37_A3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR37_A3, TARGTID);
    FAPI_INF("  .MR38_A3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR38_A3, TARGTID);
    FAPI_INF("  .MR39_A3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR39_A3, TARGTID);
    FAPI_INF("  .MR33_ORG_A3          = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_ORG_A3, TARGTID);
    FAPI_INF("  .MR11_A3_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR11_A3_next, TARGTID);
    FAPI_INF("  .MR12_A3_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR12_A3_next, TARGTID);
    FAPI_INF("  .MR13_A3_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR13_A3_next, TARGTID);
    FAPI_INF("  .CS_Dly_Margin_A3     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CS_Dly_Margin_A3, TARGTID);
    FAPI_INF("  .CS_Vref_Margin_A3    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CS_Vref_Margin_A3, TARGTID);
    FAPI_INF("  .CA_Dly_Margin_A3     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CA_Dly_Margin_A3, TARGTID);
    FAPI_INF("  .CA_Vref_Margin_A3    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CA_Vref_Margin_A3, TARGTID);
    FAPI_INF("  .MR33_ORG_A3_next     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_ORG_A3_next, TARGTID);
    FAPI_INF("  .MR33_A3_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_A3_next, TARGTID);
    FAPI_INF("  .MR50_A3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR50_A3, TARGTID);
    FAPI_INF("  .MR51_A3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR51_A3, TARGTID);
    FAPI_INF("  .MR52_A3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR52_A3, TARGTID);
    FAPI_INF("  .DFE_GainBias_A3      = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DFE_GainBias_A3, TARGTID);
    FAPI_INF("  .ReservedF6           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.ReservedF6, TARGTID);
    FAPI_INF("  .ReservedF7           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.ReservedF7, TARGTID);
    FAPI_INF("  .ReservedF8           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.ReservedF8, TARGTID);
    FAPI_INF("  .ReservedF9           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.ReservedF9, TARGTID);
    FAPI_INF("  .BCW04_next           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW04_next, TARGTID);
    FAPI_INF("  .BCW05_next           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW05_next, TARGTID);
    FAPI_INF("  .WR_RD_RTT_PARK_A0    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.WR_RD_RTT_PARK_A0, TARGTID);
    FAPI_INF("  .WR_RD_RTT_PARK_A1    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.WR_RD_RTT_PARK_A1, TARGTID);
    FAPI_INF("  .WR_RD_RTT_PARK_A2    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.WR_RD_RTT_PARK_A2, TARGTID);
    FAPI_INF("  .WR_RD_RTT_PARK_A3    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.WR_RD_RTT_PARK_A3, TARGTID);
    FAPI_INF("  .RxClkDly_Margin_A0   = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RxClkDly_Margin_A0, TARGTID);
    FAPI_INF("  .VrefDac_Margin_A0    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDac_Margin_A0, TARGTID);
    FAPI_INF("  .TxDqDly_Margin_A0    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.TxDqDly_Margin_A0, TARGTID);
    FAPI_INF("  .DeviceVref_Margin_A0 = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DeviceVref_Margin_A0, TARGTID);
    FAPI_INF("  .RxClkDly_Margin_A1   = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RxClkDly_Margin_A1, TARGTID);
    FAPI_INF("  .VrefDac_Margin_A1    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDac_Margin_A1, TARGTID);
    FAPI_INF("  .TxDqDly_Margin_A1    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.TxDqDly_Margin_A1, TARGTID);
    FAPI_INF("  .DeviceVref_Margin_A1 = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DeviceVref_Margin_A1, TARGTID);
    FAPI_INF("  .RxClkDly_Margin_A2   = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RxClkDly_Margin_A2, TARGTID);
    FAPI_INF("  .VrefDac_Margin_A2    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDac_Margin_A2, TARGTID);
    FAPI_INF("  .TxDqDly_Margin_A2    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.TxDqDly_Margin_A2, TARGTID);
    FAPI_INF("  .DeviceVref_Margin_A2 = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DeviceVref_Margin_A2, TARGTID);
    FAPI_INF("  .RxClkDly_Margin_A3   = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RxClkDly_Margin_A3, TARGTID);
    FAPI_INF("  .VrefDac_Margin_A3    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDac_Margin_A3, TARGTID);
    FAPI_INF("  .TxDqDly_Margin_A3    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.TxDqDly_Margin_A3, TARGTID);
    FAPI_INF("  .DeviceVref_Margin_A3 = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DeviceVref_Margin_A3, TARGTID);
    FAPI_INF("  .EnabledDQsChB        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.EnabledDQsChB, TARGTID);
    FAPI_INF("  .CsPresentChB         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CsPresentChB, TARGTID);
    FAPI_INF("  .CDD_ChB_RR_3_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RR_3_2, TARGTID);
    FAPI_INF("  .CDD_ChB_RR_3_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RR_3_1, TARGTID);
    FAPI_INF("  .CDD_ChB_RR_3_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RR_3_0, TARGTID);
    FAPI_INF("  .CDD_ChB_RR_2_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RR_2_3, TARGTID);
    FAPI_INF("  .CDD_ChB_RR_2_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RR_2_1, TARGTID);
    FAPI_INF("  .CDD_ChB_RR_2_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RR_2_0, TARGTID);
    FAPI_INF("  .CDD_ChB_RR_1_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RR_1_3, TARGTID);
    FAPI_INF("  .CDD_ChB_RR_1_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RR_1_2, TARGTID);
    FAPI_INF("  .CDD_ChB_RR_1_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RR_1_0, TARGTID);
    FAPI_INF("  .CDD_ChB_RR_0_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RR_0_3, TARGTID);
    FAPI_INF("  .CDD_ChB_RR_0_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RR_0_2, TARGTID);
    FAPI_INF("  .CDD_ChB_RR_0_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RR_0_1, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_3_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_3_3, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_3_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_3_2, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_3_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_3_1, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_3_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_3_0, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_2_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_2_3, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_2_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_2_2, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_2_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_2_1, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_2_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_2_0, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_1_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_1_3, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_1_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_1_2, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_1_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_1_1, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_1_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_1_0, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_0_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_0_3, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_0_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_0_2, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_0_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_0_1, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_0_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_0_0, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_3_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_3_3, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_3_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_3_2, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_3_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_3_1, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_3_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_3_0, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_2_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_2_3, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_2_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_2_2, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_2_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_2_1, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_2_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_2_0, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_1_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_1_3, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_1_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_1_2, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_1_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_1_1, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_1_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_1_0, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_0_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_0_3, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_0_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_0_2, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_0_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_0_1, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_0_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_0_0, TARGTID);
    FAPI_INF("  .CDD_ChB_WW_3_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WW_3_2, TARGTID);
    FAPI_INF("  .CDD_ChB_WW_3_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WW_3_1, TARGTID);
    FAPI_INF("  .CDD_ChB_WW_3_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WW_3_0, TARGTID);
    FAPI_INF("  .CDD_ChB_WW_2_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WW_2_3, TARGTID);
    FAPI_INF("  .CDD_ChB_WW_2_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WW_2_1, TARGTID);
    FAPI_INF("  .CDD_ChB_WW_2_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WW_2_0, TARGTID);
    FAPI_INF("  .CDD_ChB_WW_1_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WW_1_3, TARGTID);
    FAPI_INF("  .CDD_ChB_WW_1_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WW_1_2, TARGTID);
    FAPI_INF("  .CDD_ChB_WW_1_0       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WW_1_0, TARGTID);
    FAPI_INF("  .CDD_ChB_WW_0_3       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WW_0_3, TARGTID);
    FAPI_INF("  .CDD_ChB_WW_0_2       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WW_0_2, TARGTID);
    FAPI_INF("  .CDD_ChB_WW_0_1       = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WW_0_1, TARGTID);
    FAPI_INF("  .MR0_B0               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR0_B0, TARGTID);
    FAPI_INF("  .MR2_B0               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR2_B0, TARGTID);
    FAPI_INF("  .MR3_B0               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3_B0, TARGTID);
    FAPI_INF("  .MR4_B0               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR4_B0, TARGTID);
    FAPI_INF("  .MR5_B0               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR5_B0, TARGTID);
    FAPI_INF("  .MR6_B0               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR6_B0, TARGTID);
    FAPI_INF("  .MR32_B0_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_B0_next, TARGTID);
    FAPI_INF("  .MR8_B0               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR8_B0, TARGTID);
    FAPI_INF("  .MR32_ORG_B0_next     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_ORG_B0_next, TARGTID);
    FAPI_INF("  .MR10_B0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR10_B0, TARGTID);
    FAPI_INF("  .MR11_B0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR11_B0, TARGTID);
    FAPI_INF("  .MR12_B0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR12_B0, TARGTID);
    FAPI_INF("  .MR13_B0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR13_B0, TARGTID);
    FAPI_INF("  .MR14_B0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR14_B0, TARGTID);
    FAPI_INF("  .MR15_B0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR15_B0, TARGTID);
    FAPI_INF("  .MR111_B0             = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR111_B0, TARGTID);
    FAPI_INF("  .MR32_B0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_B0, TARGTID);
    FAPI_INF("  .MR33_B0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_B0, TARGTID);
    FAPI_INF("  .MR34_B0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR34_B0, TARGTID);
    FAPI_INF("  .MR35_B0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR35_B0, TARGTID);
    FAPI_INF("  .MR32_ORG_B0          = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_ORG_B0, TARGTID);
    FAPI_INF("  .MR37_B0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR37_B0, TARGTID);
    FAPI_INF("  .MR38_B0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR38_B0, TARGTID);
    FAPI_INF("  .MR39_B0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR39_B0, TARGTID);
    FAPI_INF("  .MR33_ORG_B0          = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_ORG_B0, TARGTID);
    FAPI_INF("  .MR11_B0_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR11_B0_next, TARGTID);
    FAPI_INF("  .MR12_B0_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR12_B0_next, TARGTID);
    FAPI_INF("  .MR13_B0_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR13_B0_next, TARGTID);
    FAPI_INF("  .CS_Dly_Margin_B0     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CS_Dly_Margin_B0, TARGTID);
    FAPI_INF("  .CS_Vref_Margin_B0    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CS_Vref_Margin_B0, TARGTID);
    FAPI_INF("  .CA_Dly_Margin_B0     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CA_Dly_Margin_B0, TARGTID);
    FAPI_INF("  .CA_Vref_Margin_B0    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CA_Vref_Margin_B0, TARGTID);
    FAPI_INF("  .MR33_ORG_B0_next     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_ORG_B0_next, TARGTID);
    FAPI_INF("  .MR33_B0_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_B0_next, TARGTID);
    FAPI_INF("  .MR50_B0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR50_B0, TARGTID);
    FAPI_INF("  .MR51_B0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR51_B0, TARGTID);
    FAPI_INF("  .MR52_B0              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR52_B0, TARGTID);
    FAPI_INF("  .DFE_GainBias_B0      = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DFE_GainBias_B0, TARGTID);
    FAPI_INF("  .MR0_B1               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR0_B1, TARGTID);
    FAPI_INF("  .MR2_B1               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR2_B1, TARGTID);
    FAPI_INF("  .MR3_B1               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3_B1, TARGTID);
    FAPI_INF("  .MR4_B1               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR4_B1, TARGTID);
    FAPI_INF("  .MR5_B1               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR5_B1, TARGTID);
    FAPI_INF("  .MR6_B1               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR6_B1, TARGTID);
    FAPI_INF("  .MR32_B1_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_B1_next, TARGTID);
    FAPI_INF("  .MR8_B1               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR8_B1, TARGTID);
    FAPI_INF("  .MR32_ORG_B1_next     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_ORG_B1_next, TARGTID);
    FAPI_INF("  .MR10_B1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR10_B1, TARGTID);
    FAPI_INF("  .MR11_B1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR11_B1, TARGTID);
    FAPI_INF("  .MR12_B1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR12_B1, TARGTID);
    FAPI_INF("  .MR13_B1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR13_B1, TARGTID);
    FAPI_INF("  .MR14_B1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR14_B1, TARGTID);
    FAPI_INF("  .MR15_B1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR15_B1, TARGTID);
    FAPI_INF("  .MR111_B1             = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR111_B1, TARGTID);
    FAPI_INF("  .MR32_B1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_B1, TARGTID);
    FAPI_INF("  .MR33_B1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_B1, TARGTID);
    FAPI_INF("  .MR34_B1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR34_B1, TARGTID);
    FAPI_INF("  .MR35_B1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR35_B1, TARGTID);
    FAPI_INF("  .MR32_ORG_B1          = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_ORG_B1, TARGTID);
    FAPI_INF("  .MR37_B1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR37_B1, TARGTID);
    FAPI_INF("  .MR38_B1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR38_B1, TARGTID);
    FAPI_INF("  .MR39_B1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR39_B1, TARGTID);
    FAPI_INF("  .MR33_ORG_B1          = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_ORG_B1, TARGTID);
    FAPI_INF("  .MR11_B1_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR11_B1_next, TARGTID);
    FAPI_INF("  .MR12_B1_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR12_B1_next, TARGTID);
    FAPI_INF("  .MR13_B1_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR13_B1_next, TARGTID);
    FAPI_INF("  .CS_Dly_Margin_B1     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CS_Dly_Margin_B1, TARGTID);
    FAPI_INF("  .CS_Vref_Margin_B1    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CS_Vref_Margin_B1, TARGTID);
    FAPI_INF("  .CA_Dly_Margin_B1     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CA_Dly_Margin_B1, TARGTID);
    FAPI_INF("  .CA_Vref_Margin_B1    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CA_Vref_Margin_B1, TARGTID);
    FAPI_INF("  .MR33_ORG_B1_next     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_ORG_B1_next, TARGTID);
    FAPI_INF("  .MR33_B1_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_B1_next, TARGTID);
    FAPI_INF("  .MR50_B1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR50_B1, TARGTID);
    FAPI_INF("  .MR51_B1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR51_B1, TARGTID);
    FAPI_INF("  .MR52_B1              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR52_B1, TARGTID);
    FAPI_INF("  .DFE_GainBias_B1      = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DFE_GainBias_B1, TARGTID);
    FAPI_INF("  .MR0_B2               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR0_B2, TARGTID);
    FAPI_INF("  .MR2_B2               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR2_B2, TARGTID);
    FAPI_INF("  .MR3_B2               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3_B2, TARGTID);
    FAPI_INF("  .MR4_B2               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR4_B2, TARGTID);
    FAPI_INF("  .MR5_B2               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR5_B2, TARGTID);
    FAPI_INF("  .MR6_B2               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR6_B2, TARGTID);
    FAPI_INF("  .MR32_B2_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_B2_next, TARGTID);
    FAPI_INF("  .MR8_B2               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR8_B2, TARGTID);
    FAPI_INF("  .MR32_ORG_B2_next     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_ORG_B2_next, TARGTID);
    FAPI_INF("  .MR10_B2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR10_B2, TARGTID);
    FAPI_INF("  .MR11_B2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR11_B2, TARGTID);
    FAPI_INF("  .MR12_B2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR12_B2, TARGTID);
    FAPI_INF("  .MR13_B2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR13_B2, TARGTID);
    FAPI_INF("  .MR14_B2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR14_B2, TARGTID);
    FAPI_INF("  .MR15_B2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR15_B2, TARGTID);
    FAPI_INF("  .MR111_B2             = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR111_B2, TARGTID);
    FAPI_INF("  .MR32_B2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_B2, TARGTID);
    FAPI_INF("  .MR33_B2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_B2, TARGTID);
    FAPI_INF("  .MR34_B2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR34_B2, TARGTID);
    FAPI_INF("  .MR35_B2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR35_B2, TARGTID);
    FAPI_INF("  .MR32_ORG_B2          = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_ORG_B2, TARGTID);
    FAPI_INF("  .MR37_B2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR37_B2, TARGTID);
    FAPI_INF("  .MR38_B2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR38_B2, TARGTID);
    FAPI_INF("  .MR39_B2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR39_B2, TARGTID);
    FAPI_INF("  .MR33_ORG_B2          = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_ORG_B2, TARGTID);
    FAPI_INF("  .MR11_B2_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR11_B2_next, TARGTID);
    FAPI_INF("  .MR12_B2_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR12_B2_next, TARGTID);
    FAPI_INF("  .MR13_B2_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR13_B2_next, TARGTID);
    FAPI_INF("  .CS_Dly_Margin_B2     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CS_Dly_Margin_B2, TARGTID);
    FAPI_INF("  .CS_Vref_Margin_B2    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CS_Vref_Margin_B2, TARGTID);
    FAPI_INF("  .CA_Dly_Margin_B2     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CA_Dly_Margin_B2, TARGTID);
    FAPI_INF("  .CA_Vref_Margin_B2    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CA_Vref_Margin_B2, TARGTID);
    FAPI_INF("  .MR33_ORG_B2_next     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_ORG_B2_next, TARGTID);
    FAPI_INF("  .MR33_B2_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_B2_next, TARGTID);
    FAPI_INF("  .MR50_B2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR50_B2, TARGTID);
    FAPI_INF("  .MR51_B2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR51_B2, TARGTID);
    FAPI_INF("  .MR52_B2              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR52_B2, TARGTID);
    FAPI_INF("  .DFE_GainBias_B2      = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DFE_GainBias_B2, TARGTID);
    FAPI_INF("  .MR0_B3               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR0_B3, TARGTID);
    FAPI_INF("  .MR2_B3               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR2_B3, TARGTID);
    FAPI_INF("  .MR3_B3               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3_B3, TARGTID);
    FAPI_INF("  .MR4_B3               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR4_B3, TARGTID);
    FAPI_INF("  .MR5_B3               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR5_B3, TARGTID);
    FAPI_INF("  .MR6_B3               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR6_B3, TARGTID);
    FAPI_INF("  .MR32_B3_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_B3_next, TARGTID);
    FAPI_INF("  .MR8_B3               = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR8_B3, TARGTID);
    FAPI_INF("  .MR32_ORG_B3_next     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_ORG_B3_next, TARGTID);
    FAPI_INF("  .MR10_B3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR10_B3, TARGTID);
    FAPI_INF("  .MR11_B3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR11_B3, TARGTID);
    FAPI_INF("  .MR12_B3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR12_B3, TARGTID);
    FAPI_INF("  .MR13_B3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR13_B3, TARGTID);
    FAPI_INF("  .MR14_B3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR14_B3, TARGTID);
    FAPI_INF("  .MR15_B3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR15_B3, TARGTID);
    FAPI_INF("  .MR111_B3             = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR111_B3, TARGTID);
    FAPI_INF("  .MR32_B3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_B3, TARGTID);
    FAPI_INF("  .MR33_B3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_B3, TARGTID);
    FAPI_INF("  .MR34_B3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR34_B3, TARGTID);
    FAPI_INF("  .MR35_B3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR35_B3, TARGTID);
    FAPI_INF("  .MR32_ORG_B3          = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR32_ORG_B3, TARGTID);
    FAPI_INF("  .MR37_B3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR37_B3, TARGTID);
    FAPI_INF("  .MR38_B3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR38_B3, TARGTID);
    FAPI_INF("  .MR39_B3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR39_B3, TARGTID);
    FAPI_INF("  .MR33_ORG_B3          = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_ORG_B3, TARGTID);
    FAPI_INF("  .MR11_B3_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR11_B3_next, TARGTID);
    FAPI_INF("  .MR12_B3_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR12_B3_next, TARGTID);
    FAPI_INF("  .MR13_B3_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR13_B3_next, TARGTID);
    FAPI_INF("  .CS_Dly_Margin_B3     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CS_Dly_Margin_B3, TARGTID);
    FAPI_INF("  .CS_Vref_Margin_B3    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CS_Vref_Margin_B3, TARGTID);
    FAPI_INF("  .CA_Dly_Margin_B3     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CA_Dly_Margin_B3, TARGTID);
    FAPI_INF("  .CA_Vref_Margin_B3    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.CA_Vref_Margin_B3, TARGTID);
    FAPI_INF("  .MR33_ORG_B3_next     = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_ORG_B3_next, TARGTID);
    FAPI_INF("  .MR33_B3_next         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR33_B3_next, TARGTID);
    FAPI_INF("  .MR50_B3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR50_B3, TARGTID);
    FAPI_INF("  .MR51_B3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR51_B3, TARGTID);
    FAPI_INF("  .MR52_B3              = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR52_B3, TARGTID);
    FAPI_INF("  .DFE_GainBias_B3      = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DFE_GainBias_B3, TARGTID);
    FAPI_INF("  .Reserved1E2          = 0x%02x; // " TARGTIDFORMAT, i_msg_block.Reserved1E2, TARGTID);
    FAPI_INF("  .Reserved1E3          = 0x%02x; // " TARGTIDFORMAT, i_msg_block.Reserved1E3, TARGTID);
    FAPI_INF("  .Reserved1E4          = 0x%02x; // " TARGTIDFORMAT, i_msg_block.Reserved1E4, TARGTID);
    FAPI_INF("  .Reserved1E5          = 0x%02x; // " TARGTIDFORMAT, i_msg_block.Reserved1E5, TARGTID);
    FAPI_INF("  .Reserved1E6          = 0x%02x; // " TARGTIDFORMAT, i_msg_block.Reserved1E6, TARGTID);
    FAPI_INF("  .Reserved1E7          = 0x%02x; // " TARGTIDFORMAT, i_msg_block.Reserved1E7, TARGTID);
    FAPI_INF("  .WR_RD_RTT_PARK_B0    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.WR_RD_RTT_PARK_B0, TARGTID);
    FAPI_INF("  .WR_RD_RTT_PARK_B1    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.WR_RD_RTT_PARK_B1, TARGTID);
    FAPI_INF("  .WR_RD_RTT_PARK_B2    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.WR_RD_RTT_PARK_B2, TARGTID);
    FAPI_INF("  .WR_RD_RTT_PARK_B3    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.WR_RD_RTT_PARK_B3, TARGTID);
    FAPI_INF("  .RxClkDly_Margin_B0   = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RxClkDly_Margin_B0, TARGTID);
    FAPI_INF("  .VrefDac_Margin_B0    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDac_Margin_B0, TARGTID);
    FAPI_INF("  .TxDqDly_Margin_B0    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.TxDqDly_Margin_B0, TARGTID);
    FAPI_INF("  .DeviceVref_Margin_B0 = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DeviceVref_Margin_B0, TARGTID);
    FAPI_INF("  .RxClkDly_Margin_B1   = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RxClkDly_Margin_B1, TARGTID);
    FAPI_INF("  .VrefDac_Margin_B1    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDac_Margin_B1, TARGTID);
    FAPI_INF("  .TxDqDly_Margin_B1    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.TxDqDly_Margin_B1, TARGTID);
    FAPI_INF("  .DeviceVref_Margin_B1 = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DeviceVref_Margin_B1, TARGTID);
    FAPI_INF("  .RxClkDly_Margin_B2   = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RxClkDly_Margin_B2, TARGTID);
    FAPI_INF("  .VrefDac_Margin_B2    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDac_Margin_B2, TARGTID);
    FAPI_INF("  .TxDqDly_Margin_B2    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.TxDqDly_Margin_B2, TARGTID);
    FAPI_INF("  .DeviceVref_Margin_B2 = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DeviceVref_Margin_B2, TARGTID);
    FAPI_INF("  .RxClkDly_Margin_B3   = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RxClkDly_Margin_B3, TARGTID);
    FAPI_INF("  .VrefDac_Margin_B3    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDac_Margin_B3, TARGTID);
    FAPI_INF("  .TxDqDly_Margin_B3    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.TxDqDly_Margin_B3, TARGTID);
    FAPI_INF("  .DeviceVref_Margin_B3 = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DeviceVref_Margin_B3, TARGTID);
    FAPI_INF("  .WL_ADJ_START         = 0x%04x; // " TARGTIDFORMAT, i_msg_block.WL_ADJ_START, TARGTID);
    FAPI_INF("  .WL_ADJ_END           = 0x%04x; // " TARGTIDFORMAT, i_msg_block.WL_ADJ_END, TARGTID);
    FAPI_INF("  .RCW00_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW00_ChA_D0, TARGTID);
    FAPI_INF("  .RCW01_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW01_ChA_D0, TARGTID);
    FAPI_INF("  .RCW02_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW02_ChA_D0, TARGTID);
    FAPI_INF("  .RCW03_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW03_ChA_D0, TARGTID);
    FAPI_INF("  .RCW04_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW04_ChA_D0, TARGTID);
    FAPI_INF("  .RCW05_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW05_ChA_D0, TARGTID);
    FAPI_INF("  .RCW06_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW06_ChA_D0, TARGTID);
    FAPI_INF("  .RCW07_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW07_ChA_D0, TARGTID);
    FAPI_INF("  .RCW08_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW08_ChA_D0, TARGTID);
    FAPI_INF("  .RCW09_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW09_ChA_D0, TARGTID);
    FAPI_INF("  .RCW0A_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW0A_ChA_D0, TARGTID);
    FAPI_INF("  .RCW0B_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW0B_ChA_D0, TARGTID);
    FAPI_INF("  .RCW0C_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW0C_ChA_D0, TARGTID);
    FAPI_INF("  .RCW0D_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW0D_ChA_D0, TARGTID);
    FAPI_INF("  .RCW0E_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW0E_ChA_D0, TARGTID);
    FAPI_INF("  .RCW0F_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW0F_ChA_D0, TARGTID);
    FAPI_INF("  .RCW10_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW10_ChA_D0, TARGTID);
    FAPI_INF("  .RCW11_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW11_ChA_D0, TARGTID);
    FAPI_INF("  .RCW12_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW12_ChA_D0, TARGTID);
    FAPI_INF("  .RCW13_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW13_ChA_D0, TARGTID);
    FAPI_INF("  .RCW14_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW14_ChA_D0, TARGTID);
    FAPI_INF("  .RCW15_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW15_ChA_D0, TARGTID);
    FAPI_INF("  .RCW16_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW16_ChA_D0, TARGTID);
    FAPI_INF("  .RCW17_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW17_ChA_D0, TARGTID);
    FAPI_INF("  .RCW18_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW18_ChA_D0, TARGTID);
    FAPI_INF("  .RCW19_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW19_ChA_D0, TARGTID);
    FAPI_INF("  .RCW1A_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW1A_ChA_D0, TARGTID);
    FAPI_INF("  .RCW1B_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW1B_ChA_D0, TARGTID);
    FAPI_INF("  .RCW1C_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW1C_ChA_D0, TARGTID);
    FAPI_INF("  .RCW1D_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW1D_ChA_D0, TARGTID);
    FAPI_INF("  .RCW1E_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW1E_ChA_D0, TARGTID);
    FAPI_INF("  .RCW1F_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW1F_ChA_D0, TARGTID);
    FAPI_INF("  .RCW20_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW20_ChA_D0, TARGTID);
    FAPI_INF("  .RCW21_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW21_ChA_D0, TARGTID);
    FAPI_INF("  .RCW22_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW22_ChA_D0, TARGTID);
    FAPI_INF("  .RCW23_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW23_ChA_D0, TARGTID);
    FAPI_INF("  .RCW24_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW24_ChA_D0, TARGTID);
    FAPI_INF("  .RCW25_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW25_ChA_D0, TARGTID);
    FAPI_INF("  .RCW26_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW26_ChA_D0, TARGTID);
    FAPI_INF("  .RCW27_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW27_ChA_D0, TARGTID);
    FAPI_INF("  .RCW28_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW28_ChA_D0, TARGTID);
    FAPI_INF("  .RCW29_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW29_ChA_D0, TARGTID);
    FAPI_INF("  .RCW2A_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW2A_ChA_D0, TARGTID);
    FAPI_INF("  .RCW2B_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW2B_ChA_D0, TARGTID);
    FAPI_INF("  .RCW2C_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW2C_ChA_D0, TARGTID);
    FAPI_INF("  .RCW2D_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW2D_ChA_D0, TARGTID);
    FAPI_INF("  .RCW2E_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW2E_ChA_D0, TARGTID);
    FAPI_INF("  .RCW2F_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW2F_ChA_D0, TARGTID);
    FAPI_INF("  .RCW30_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW30_ChA_D0, TARGTID);
    FAPI_INF("  .RCW31_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW31_ChA_D0, TARGTID);
    FAPI_INF("  .RCW32_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW32_ChA_D0, TARGTID);
    FAPI_INF("  .RCW33_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW33_ChA_D0, TARGTID);
    FAPI_INF("  .RCW34_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW34_ChA_D0, TARGTID);
    FAPI_INF("  .RCW35_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW35_ChA_D0, TARGTID);
    FAPI_INF("  .RCW36_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW36_ChA_D0, TARGTID);
    FAPI_INF("  .RCW37_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW37_ChA_D0, TARGTID);
    FAPI_INF("  .RCW38_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW38_ChA_D0, TARGTID);
    FAPI_INF("  .RCW39_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW39_ChA_D0, TARGTID);
    FAPI_INF("  .RCW3A_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW3A_ChA_D0, TARGTID);
    FAPI_INF("  .RCW3B_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW3B_ChA_D0, TARGTID);
    FAPI_INF("  .RCW3C_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW3C_ChA_D0, TARGTID);
    FAPI_INF("  .RCW3D_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW3D_ChA_D0, TARGTID);
    FAPI_INF("  .RCW3E_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW3E_ChA_D0, TARGTID);
    FAPI_INF("  .RCW3F_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW3F_ChA_D0, TARGTID);
    FAPI_INF("  .RCW40_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW40_ChA_D0, TARGTID);
    FAPI_INF("  .RCW41_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW41_ChA_D0, TARGTID);
    FAPI_INF("  .RCW42_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW42_ChA_D0, TARGTID);
    FAPI_INF("  .RCW43_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW43_ChA_D0, TARGTID);
    FAPI_INF("  .RCW44_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW44_ChA_D0, TARGTID);
    FAPI_INF("  .RCW45_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW45_ChA_D0, TARGTID);
    FAPI_INF("  .RCW46_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW46_ChA_D0, TARGTID);
    FAPI_INF("  .RCW47_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW47_ChA_D0, TARGTID);
    FAPI_INF("  .RCW48_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW48_ChA_D0, TARGTID);
    FAPI_INF("  .RCW49_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW49_ChA_D0, TARGTID);
    FAPI_INF("  .RCW4A_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW4A_ChA_D0, TARGTID);
    FAPI_INF("  .RCW4B_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW4B_ChA_D0, TARGTID);
    FAPI_INF("  .RCW4C_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW4C_ChA_D0, TARGTID);
    FAPI_INF("  .RCW4D_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW4D_ChA_D0, TARGTID);
    FAPI_INF("  .RCW4E_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW4E_ChA_D0, TARGTID);
    FAPI_INF("  .RCW4F_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW4F_ChA_D0, TARGTID);
    FAPI_INF("  .RCW50_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW50_ChA_D0, TARGTID);
    FAPI_INF("  .RCW51_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW51_ChA_D0, TARGTID);
    FAPI_INF("  .RCW52_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW52_ChA_D0, TARGTID);
    FAPI_INF("  .RCW53_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW53_ChA_D0, TARGTID);
    FAPI_INF("  .RCW54_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW54_ChA_D0, TARGTID);
    FAPI_INF("  .RCW55_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW55_ChA_D0, TARGTID);
    FAPI_INF("  .RCW56_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW56_ChA_D0, TARGTID);
    FAPI_INF("  .RCW57_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW57_ChA_D0, TARGTID);
    FAPI_INF("  .RCW58_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW58_ChA_D0, TARGTID);
    FAPI_INF("  .RCW59_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW59_ChA_D0, TARGTID);
    FAPI_INF("  .RCW5A_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW5A_ChA_D0, TARGTID);
    FAPI_INF("  .RCW5B_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW5B_ChA_D0, TARGTID);
    FAPI_INF("  .RCW5C_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW5C_ChA_D0, TARGTID);
    FAPI_INF("  .RCW5D_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW5D_ChA_D0, TARGTID);
    FAPI_INF("  .RCW5E_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW5E_ChA_D0, TARGTID);
    FAPI_INF("  .RCW5F_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW5F_ChA_D0, TARGTID);
    FAPI_INF("  .RCW60_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW60_ChA_D0, TARGTID);
    FAPI_INF("  .RCW61_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW61_ChA_D0, TARGTID);
    FAPI_INF("  .RCW62_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW62_ChA_D0, TARGTID);
    FAPI_INF("  .RCW63_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW63_ChA_D0, TARGTID);
    FAPI_INF("  .RCW64_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW64_ChA_D0, TARGTID);
    FAPI_INF("  .RCW65_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW65_ChA_D0, TARGTID);
    FAPI_INF("  .RCW66_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW66_ChA_D0, TARGTID);
    FAPI_INF("  .RCW67_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW67_ChA_D0, TARGTID);
    FAPI_INF("  .RCW68_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW68_ChA_D0, TARGTID);
    FAPI_INF("  .RCW69_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW69_ChA_D0, TARGTID);
    FAPI_INF("  .RCW6A_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW6A_ChA_D0, TARGTID);
    FAPI_INF("  .RCW6B_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW6B_ChA_D0, TARGTID);
    FAPI_INF("  .RCW6C_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW6C_ChA_D0, TARGTID);
    FAPI_INF("  .RCW6D_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW6D_ChA_D0, TARGTID);
    FAPI_INF("  .RCW6E_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW6E_ChA_D0, TARGTID);
    FAPI_INF("  .RCW6F_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW6F_ChA_D0, TARGTID);
    FAPI_INF("  .RCW70_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW70_ChA_D0, TARGTID);
    FAPI_INF("  .RCW71_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW71_ChA_D0, TARGTID);
    FAPI_INF("  .RCW72_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW72_ChA_D0, TARGTID);
    FAPI_INF("  .RCW73_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW73_ChA_D0, TARGTID);
    FAPI_INF("  .RCW74_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW74_ChA_D0, TARGTID);
    FAPI_INF("  .RCW75_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW75_ChA_D0, TARGTID);
    FAPI_INF("  .RCW76_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW76_ChA_D0, TARGTID);
    FAPI_INF("  .RCW77_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW77_ChA_D0, TARGTID);
    FAPI_INF("  .RCW78_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW78_ChA_D0, TARGTID);
    FAPI_INF("  .RCW79_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW79_ChA_D0, TARGTID);
    FAPI_INF("  .RCW7A_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW7A_ChA_D0, TARGTID);
    FAPI_INF("  .RCW7B_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW7B_ChA_D0, TARGTID);
    FAPI_INF("  .RCW7C_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW7C_ChA_D0, TARGTID);
    FAPI_INF("  .RCW7D_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW7D_ChA_D0, TARGTID);
    FAPI_INF("  .RCW7E_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW7E_ChA_D0, TARGTID);
    FAPI_INF("  .RCW7F_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW7F_ChA_D0, TARGTID);
    FAPI_INF("  .BCW00_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW00_ChA_D0, TARGTID);
    FAPI_INF("  .BCW01_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW01_ChA_D0, TARGTID);
    FAPI_INF("  .BCW02_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW02_ChA_D0, TARGTID);
    FAPI_INF("  .BCW03_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW03_ChA_D0, TARGTID);
    FAPI_INF("  .BCW04_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW04_ChA_D0, TARGTID);
    FAPI_INF("  .BCW05_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW05_ChA_D0, TARGTID);
    FAPI_INF("  .BCW06_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW06_ChA_D0, TARGTID);
    FAPI_INF("  .BCW07_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW07_ChA_D0, TARGTID);
    FAPI_INF("  .BCW08_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW08_ChA_D0, TARGTID);
    FAPI_INF("  .BCW09_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW09_ChA_D0, TARGTID);
    FAPI_INF("  .BCW0A_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW0A_ChA_D0, TARGTID);
    FAPI_INF("  .BCW0B_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW0B_ChA_D0, TARGTID);
    FAPI_INF("  .BCW0C_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW0C_ChA_D0, TARGTID);
    FAPI_INF("  .BCW0D_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW0D_ChA_D0, TARGTID);
    FAPI_INF("  .BCW0E_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW0E_ChA_D0, TARGTID);
    FAPI_INF("  .BCW0F_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW0F_ChA_D0, TARGTID);
    FAPI_INF("  .BCW10_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW10_ChA_D0, TARGTID);
    FAPI_INF("  .BCW11_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW11_ChA_D0, TARGTID);
    FAPI_INF("  .BCW12_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW12_ChA_D0, TARGTID);
    FAPI_INF("  .BCW13_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW13_ChA_D0, TARGTID);
    FAPI_INF("  .BCW14_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW14_ChA_D0, TARGTID);
    FAPI_INF("  .BCW15_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW15_ChA_D0, TARGTID);
    FAPI_INF("  .BCW16_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW16_ChA_D0, TARGTID);
    FAPI_INF("  .BCW17_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW17_ChA_D0, TARGTID);
    FAPI_INF("  .BCW18_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW18_ChA_D0, TARGTID);
    FAPI_INF("  .BCW19_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW19_ChA_D0, TARGTID);
    FAPI_INF("  .BCW1A_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW1A_ChA_D0, TARGTID);
    FAPI_INF("  .BCW1B_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW1B_ChA_D0, TARGTID);
    FAPI_INF("  .BCW1C_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW1C_ChA_D0, TARGTID);
    FAPI_INF("  .BCW1D_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW1D_ChA_D0, TARGTID);
    FAPI_INF("  .BCW1E_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW1E_ChA_D0, TARGTID);
    FAPI_INF("  .BCW1F_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW1F_ChA_D0, TARGTID);
    FAPI_INF("  .BCW20_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW20_ChA_D0, TARGTID);
    FAPI_INF("  .BCW21_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW21_ChA_D0, TARGTID);
    FAPI_INF("  .BCW22_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW22_ChA_D0, TARGTID);
    FAPI_INF("  .BCW23_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW23_ChA_D0, TARGTID);
    FAPI_INF("  .BCW24_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW24_ChA_D0, TARGTID);
    FAPI_INF("  .BCW25_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW25_ChA_D0, TARGTID);
    FAPI_INF("  .BCW26_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW26_ChA_D0, TARGTID);
    FAPI_INF("  .BCW27_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW27_ChA_D0, TARGTID);
    FAPI_INF("  .BCW28_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW28_ChA_D0, TARGTID);
    FAPI_INF("  .BCW29_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW29_ChA_D0, TARGTID);
    FAPI_INF("  .BCW2A_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW2A_ChA_D0, TARGTID);
    FAPI_INF("  .BCW2B_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW2B_ChA_D0, TARGTID);
    FAPI_INF("  .BCW2C_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW2C_ChA_D0, TARGTID);
    FAPI_INF("  .BCW2D_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW2D_ChA_D0, TARGTID);
    FAPI_INF("  .BCW2E_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW2E_ChA_D0, TARGTID);
    FAPI_INF("  .BCW2F_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW2F_ChA_D0, TARGTID);
    FAPI_INF("  .BCW30_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW30_ChA_D0, TARGTID);
    FAPI_INF("  .BCW31_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW31_ChA_D0, TARGTID);
    FAPI_INF("  .BCW32_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW32_ChA_D0, TARGTID);
    FAPI_INF("  .BCW33_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW33_ChA_D0, TARGTID);
    FAPI_INF("  .BCW34_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW34_ChA_D0, TARGTID);
    FAPI_INF("  .BCW35_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW35_ChA_D0, TARGTID);
    FAPI_INF("  .BCW36_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW36_ChA_D0, TARGTID);
    FAPI_INF("  .BCW37_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW37_ChA_D0, TARGTID);
    FAPI_INF("  .BCW38_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW38_ChA_D0, TARGTID);
    FAPI_INF("  .BCW39_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW39_ChA_D0, TARGTID);
    FAPI_INF("  .BCW3A_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW3A_ChA_D0, TARGTID);
    FAPI_INF("  .BCW3B_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW3B_ChA_D0, TARGTID);
    FAPI_INF("  .BCW3C_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW3C_ChA_D0, TARGTID);
    FAPI_INF("  .BCW3D_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW3D_ChA_D0, TARGTID);
    FAPI_INF("  .BCW3E_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW3E_ChA_D0, TARGTID);
    FAPI_INF("  .BCW3F_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW3F_ChA_D0, TARGTID);
    FAPI_INF("  .BCW40_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW40_ChA_D0, TARGTID);
    FAPI_INF("  .BCW41_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW41_ChA_D0, TARGTID);
    FAPI_INF("  .BCW42_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW42_ChA_D0, TARGTID);
    FAPI_INF("  .BCW43_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW43_ChA_D0, TARGTID);
    FAPI_INF("  .BCW44_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW44_ChA_D0, TARGTID);
    FAPI_INF("  .BCW45_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW45_ChA_D0, TARGTID);
    FAPI_INF("  .BCW46_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW46_ChA_D0, TARGTID);
    FAPI_INF("  .BCW47_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW47_ChA_D0, TARGTID);
    FAPI_INF("  .BCW48_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW48_ChA_D0, TARGTID);
    FAPI_INF("  .BCW49_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW49_ChA_D0, TARGTID);
    FAPI_INF("  .BCW4A_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW4A_ChA_D0, TARGTID);
    FAPI_INF("  .BCW4B_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW4B_ChA_D0, TARGTID);
    FAPI_INF("  .BCW4C_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW4C_ChA_D0, TARGTID);
    FAPI_INF("  .BCW4D_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW4D_ChA_D0, TARGTID);
    FAPI_INF("  .BCW4E_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW4E_ChA_D0, TARGTID);
    FAPI_INF("  .BCW4F_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW4F_ChA_D0, TARGTID);
    FAPI_INF("  .BCW50_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW50_ChA_D0, TARGTID);
    FAPI_INF("  .BCW51_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW51_ChA_D0, TARGTID);
    FAPI_INF("  .BCW52_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW52_ChA_D0, TARGTID);
    FAPI_INF("  .BCW53_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW53_ChA_D0, TARGTID);
    FAPI_INF("  .BCW54_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW54_ChA_D0, TARGTID);
    FAPI_INF("  .BCW55_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW55_ChA_D0, TARGTID);
    FAPI_INF("  .BCW56_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW56_ChA_D0, TARGTID);
    FAPI_INF("  .BCW57_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW57_ChA_D0, TARGTID);
    FAPI_INF("  .BCW58_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW58_ChA_D0, TARGTID);
    FAPI_INF("  .BCW59_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW59_ChA_D0, TARGTID);
    FAPI_INF("  .BCW5A_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW5A_ChA_D0, TARGTID);
    FAPI_INF("  .BCW5B_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW5B_ChA_D0, TARGTID);
    FAPI_INF("  .BCW5C_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW5C_ChA_D0, TARGTID);
    FAPI_INF("  .BCW5D_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW5D_ChA_D0, TARGTID);
    FAPI_INF("  .BCW5E_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW5E_ChA_D0, TARGTID);
    FAPI_INF("  .BCW5F_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW5F_ChA_D0, TARGTID);
    FAPI_INF("  .BCW60_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW60_ChA_D0, TARGTID);
    FAPI_INF("  .BCW61_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW61_ChA_D0, TARGTID);
    FAPI_INF("  .BCW62_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW62_ChA_D0, TARGTID);
    FAPI_INF("  .BCW63_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW63_ChA_D0, TARGTID);
    FAPI_INF("  .BCW64_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW64_ChA_D0, TARGTID);
    FAPI_INF("  .BCW65_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW65_ChA_D0, TARGTID);
    FAPI_INF("  .BCW66_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW66_ChA_D0, TARGTID);
    FAPI_INF("  .BCW67_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW67_ChA_D0, TARGTID);
    FAPI_INF("  .BCW68_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW68_ChA_D0, TARGTID);
    FAPI_INF("  .BCW69_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW69_ChA_D0, TARGTID);
    FAPI_INF("  .BCW6A_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW6A_ChA_D0, TARGTID);
    FAPI_INF("  .BCW6B_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW6B_ChA_D0, TARGTID);
    FAPI_INF("  .BCW6C_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW6C_ChA_D0, TARGTID);
    FAPI_INF("  .BCW6D_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW6D_ChA_D0, TARGTID);
    FAPI_INF("  .BCW6E_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW6E_ChA_D0, TARGTID);
    FAPI_INF("  .BCW6F_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW6F_ChA_D0, TARGTID);
    FAPI_INF("  .BCW70_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW70_ChA_D0, TARGTID);
    FAPI_INF("  .BCW71_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW71_ChA_D0, TARGTID);
    FAPI_INF("  .BCW72_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW72_ChA_D0, TARGTID);
    FAPI_INF("  .BCW73_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW73_ChA_D0, TARGTID);
    FAPI_INF("  .BCW74_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW74_ChA_D0, TARGTID);
    FAPI_INF("  .BCW75_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW75_ChA_D0, TARGTID);
    FAPI_INF("  .BCW76_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW76_ChA_D0, TARGTID);
    FAPI_INF("  .BCW77_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW77_ChA_D0, TARGTID);
    FAPI_INF("  .BCW78_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW78_ChA_D0, TARGTID);
    FAPI_INF("  .BCW79_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW79_ChA_D0, TARGTID);
    FAPI_INF("  .BCW7A_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW7A_ChA_D0, TARGTID);
    FAPI_INF("  .BCW7B_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW7B_ChA_D0, TARGTID);
    FAPI_INF("  .BCW7C_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW7C_ChA_D0, TARGTID);
    FAPI_INF("  .BCW7D_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW7D_ChA_D0, TARGTID);
    FAPI_INF("  .BCW7E_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW7E_ChA_D0, TARGTID);
    FAPI_INF("  .BCW7F_ChA_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW7F_ChA_D0, TARGTID);
    FAPI_INF("  .RCW00_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW00_ChA_D1, TARGTID);
    FAPI_INF("  .RCW01_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW01_ChA_D1, TARGTID);
    FAPI_INF("  .RCW02_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW02_ChA_D1, TARGTID);
    FAPI_INF("  .RCW03_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW03_ChA_D1, TARGTID);
    FAPI_INF("  .RCW04_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW04_ChA_D1, TARGTID);
    FAPI_INF("  .RCW05_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW05_ChA_D1, TARGTID);
    FAPI_INF("  .RCW06_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW06_ChA_D1, TARGTID);
    FAPI_INF("  .RCW07_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW07_ChA_D1, TARGTID);
    FAPI_INF("  .RCW08_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW08_ChA_D1, TARGTID);
    FAPI_INF("  .RCW09_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW09_ChA_D1, TARGTID);
    FAPI_INF("  .RCW0A_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW0A_ChA_D1, TARGTID);
    FAPI_INF("  .RCW0B_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW0B_ChA_D1, TARGTID);
    FAPI_INF("  .RCW0C_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW0C_ChA_D1, TARGTID);
    FAPI_INF("  .RCW0D_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW0D_ChA_D1, TARGTID);
    FAPI_INF("  .RCW0E_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW0E_ChA_D1, TARGTID);
    FAPI_INF("  .RCW0F_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW0F_ChA_D1, TARGTID);
    FAPI_INF("  .RCW10_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW10_ChA_D1, TARGTID);
    FAPI_INF("  .RCW11_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW11_ChA_D1, TARGTID);
    FAPI_INF("  .RCW12_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW12_ChA_D1, TARGTID);
    FAPI_INF("  .RCW13_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW13_ChA_D1, TARGTID);
    FAPI_INF("  .RCW14_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW14_ChA_D1, TARGTID);
    FAPI_INF("  .RCW15_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW15_ChA_D1, TARGTID);
    FAPI_INF("  .RCW16_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW16_ChA_D1, TARGTID);
    FAPI_INF("  .RCW17_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW17_ChA_D1, TARGTID);
    FAPI_INF("  .RCW18_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW18_ChA_D1, TARGTID);
    FAPI_INF("  .RCW19_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW19_ChA_D1, TARGTID);
    FAPI_INF("  .RCW1A_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW1A_ChA_D1, TARGTID);
    FAPI_INF("  .RCW1B_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW1B_ChA_D1, TARGTID);
    FAPI_INF("  .RCW1C_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW1C_ChA_D1, TARGTID);
    FAPI_INF("  .RCW1D_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW1D_ChA_D1, TARGTID);
    FAPI_INF("  .RCW1E_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW1E_ChA_D1, TARGTID);
    FAPI_INF("  .RCW1F_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW1F_ChA_D1, TARGTID);
    FAPI_INF("  .RCW20_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW20_ChA_D1, TARGTID);
    FAPI_INF("  .RCW21_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW21_ChA_D1, TARGTID);
    FAPI_INF("  .RCW22_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW22_ChA_D1, TARGTID);
    FAPI_INF("  .RCW23_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW23_ChA_D1, TARGTID);
    FAPI_INF("  .RCW24_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW24_ChA_D1, TARGTID);
    FAPI_INF("  .RCW25_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW25_ChA_D1, TARGTID);
    FAPI_INF("  .RCW26_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW26_ChA_D1, TARGTID);
    FAPI_INF("  .RCW27_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW27_ChA_D1, TARGTID);
    FAPI_INF("  .RCW28_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW28_ChA_D1, TARGTID);
    FAPI_INF("  .RCW29_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW29_ChA_D1, TARGTID);
    FAPI_INF("  .RCW2A_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW2A_ChA_D1, TARGTID);
    FAPI_INF("  .RCW2B_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW2B_ChA_D1, TARGTID);
    FAPI_INF("  .RCW2C_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW2C_ChA_D1, TARGTID);
    FAPI_INF("  .RCW2D_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW2D_ChA_D1, TARGTID);
    FAPI_INF("  .RCW2E_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW2E_ChA_D1, TARGTID);
    FAPI_INF("  .RCW2F_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW2F_ChA_D1, TARGTID);
    FAPI_INF("  .RCW30_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW30_ChA_D1, TARGTID);
    FAPI_INF("  .RCW31_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW31_ChA_D1, TARGTID);
    FAPI_INF("  .RCW32_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW32_ChA_D1, TARGTID);
    FAPI_INF("  .RCW33_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW33_ChA_D1, TARGTID);
    FAPI_INF("  .RCW34_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW34_ChA_D1, TARGTID);
    FAPI_INF("  .RCW35_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW35_ChA_D1, TARGTID);
    FAPI_INF("  .RCW36_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW36_ChA_D1, TARGTID);
    FAPI_INF("  .RCW37_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW37_ChA_D1, TARGTID);
    FAPI_INF("  .RCW38_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW38_ChA_D1, TARGTID);
    FAPI_INF("  .RCW39_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW39_ChA_D1, TARGTID);
    FAPI_INF("  .RCW3A_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW3A_ChA_D1, TARGTID);
    FAPI_INF("  .RCW3B_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW3B_ChA_D1, TARGTID);
    FAPI_INF("  .RCW3C_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW3C_ChA_D1, TARGTID);
    FAPI_INF("  .RCW3D_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW3D_ChA_D1, TARGTID);
    FAPI_INF("  .RCW3E_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW3E_ChA_D1, TARGTID);
    FAPI_INF("  .RCW3F_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW3F_ChA_D1, TARGTID);
    FAPI_INF("  .RCW40_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW40_ChA_D1, TARGTID);
    FAPI_INF("  .RCW41_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW41_ChA_D1, TARGTID);
    FAPI_INF("  .RCW42_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW42_ChA_D1, TARGTID);
    FAPI_INF("  .RCW43_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW43_ChA_D1, TARGTID);
    FAPI_INF("  .RCW44_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW44_ChA_D1, TARGTID);
    FAPI_INF("  .RCW45_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW45_ChA_D1, TARGTID);
    FAPI_INF("  .RCW46_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW46_ChA_D1, TARGTID);
    FAPI_INF("  .RCW47_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW47_ChA_D1, TARGTID);
    FAPI_INF("  .RCW48_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW48_ChA_D1, TARGTID);
    FAPI_INF("  .RCW49_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW49_ChA_D1, TARGTID);
    FAPI_INF("  .RCW4A_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW4A_ChA_D1, TARGTID);
    FAPI_INF("  .RCW4B_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW4B_ChA_D1, TARGTID);
    FAPI_INF("  .RCW4C_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW4C_ChA_D1, TARGTID);
    FAPI_INF("  .RCW4D_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW4D_ChA_D1, TARGTID);
    FAPI_INF("  .RCW4E_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW4E_ChA_D1, TARGTID);
    FAPI_INF("  .RCW4F_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW4F_ChA_D1, TARGTID);
    FAPI_INF("  .RCW50_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW50_ChA_D1, TARGTID);
    FAPI_INF("  .RCW51_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW51_ChA_D1, TARGTID);
    FAPI_INF("  .RCW52_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW52_ChA_D1, TARGTID);
    FAPI_INF("  .RCW53_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW53_ChA_D1, TARGTID);
    FAPI_INF("  .RCW54_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW54_ChA_D1, TARGTID);
    FAPI_INF("  .RCW55_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW55_ChA_D1, TARGTID);
    FAPI_INF("  .RCW56_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW56_ChA_D1, TARGTID);
    FAPI_INF("  .RCW57_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW57_ChA_D1, TARGTID);
    FAPI_INF("  .RCW58_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW58_ChA_D1, TARGTID);
    FAPI_INF("  .RCW59_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW59_ChA_D1, TARGTID);
    FAPI_INF("  .RCW5A_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW5A_ChA_D1, TARGTID);
    FAPI_INF("  .RCW5B_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW5B_ChA_D1, TARGTID);
    FAPI_INF("  .RCW5C_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW5C_ChA_D1, TARGTID);
    FAPI_INF("  .RCW5D_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW5D_ChA_D1, TARGTID);
    FAPI_INF("  .RCW5E_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW5E_ChA_D1, TARGTID);
    FAPI_INF("  .RCW5F_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW5F_ChA_D1, TARGTID);
    FAPI_INF("  .RCW60_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW60_ChA_D1, TARGTID);
    FAPI_INF("  .RCW61_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW61_ChA_D1, TARGTID);
    FAPI_INF("  .RCW62_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW62_ChA_D1, TARGTID);
    FAPI_INF("  .RCW63_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW63_ChA_D1, TARGTID);
    FAPI_INF("  .RCW64_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW64_ChA_D1, TARGTID);
    FAPI_INF("  .RCW65_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW65_ChA_D1, TARGTID);
    FAPI_INF("  .RCW66_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW66_ChA_D1, TARGTID);
    FAPI_INF("  .RCW67_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW67_ChA_D1, TARGTID);
    FAPI_INF("  .RCW68_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW68_ChA_D1, TARGTID);
    FAPI_INF("  .RCW69_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW69_ChA_D1, TARGTID);
    FAPI_INF("  .RCW6A_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW6A_ChA_D1, TARGTID);
    FAPI_INF("  .RCW6B_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW6B_ChA_D1, TARGTID);
    FAPI_INF("  .RCW6C_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW6C_ChA_D1, TARGTID);
    FAPI_INF("  .RCW6D_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW6D_ChA_D1, TARGTID);
    FAPI_INF("  .RCW6E_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW6E_ChA_D1, TARGTID);
    FAPI_INF("  .RCW6F_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW6F_ChA_D1, TARGTID);
    FAPI_INF("  .RCW70_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW70_ChA_D1, TARGTID);
    FAPI_INF("  .RCW71_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW71_ChA_D1, TARGTID);
    FAPI_INF("  .RCW72_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW72_ChA_D1, TARGTID);
    FAPI_INF("  .RCW73_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW73_ChA_D1, TARGTID);
    FAPI_INF("  .RCW74_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW74_ChA_D1, TARGTID);
    FAPI_INF("  .RCW75_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW75_ChA_D1, TARGTID);
    FAPI_INF("  .RCW76_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW76_ChA_D1, TARGTID);
    FAPI_INF("  .RCW77_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW77_ChA_D1, TARGTID);
    FAPI_INF("  .RCW78_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW78_ChA_D1, TARGTID);
    FAPI_INF("  .RCW79_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW79_ChA_D1, TARGTID);
    FAPI_INF("  .RCW7A_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW7A_ChA_D1, TARGTID);
    FAPI_INF("  .RCW7B_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW7B_ChA_D1, TARGTID);
    FAPI_INF("  .RCW7C_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW7C_ChA_D1, TARGTID);
    FAPI_INF("  .RCW7D_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW7D_ChA_D1, TARGTID);
    FAPI_INF("  .RCW7E_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW7E_ChA_D1, TARGTID);
    FAPI_INF("  .RCW7F_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW7F_ChA_D1, TARGTID);
    FAPI_INF("  .BCW00_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW00_ChA_D1, TARGTID);
    FAPI_INF("  .BCW01_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW01_ChA_D1, TARGTID);
    FAPI_INF("  .BCW02_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW02_ChA_D1, TARGTID);
    FAPI_INF("  .BCW03_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW03_ChA_D1, TARGTID);
    FAPI_INF("  .BCW04_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW04_ChA_D1, TARGTID);
    FAPI_INF("  .BCW05_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW05_ChA_D1, TARGTID);
    FAPI_INF("  .BCW06_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW06_ChA_D1, TARGTID);
    FAPI_INF("  .BCW07_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW07_ChA_D1, TARGTID);
    FAPI_INF("  .BCW08_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW08_ChA_D1, TARGTID);
    FAPI_INF("  .BCW09_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW09_ChA_D1, TARGTID);
    FAPI_INF("  .BCW0A_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW0A_ChA_D1, TARGTID);
    FAPI_INF("  .BCW0B_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW0B_ChA_D1, TARGTID);
    FAPI_INF("  .BCW0C_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW0C_ChA_D1, TARGTID);
    FAPI_INF("  .BCW0D_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW0D_ChA_D1, TARGTID);
    FAPI_INF("  .BCW0E_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW0E_ChA_D1, TARGTID);
    FAPI_INF("  .BCW0F_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW0F_ChA_D1, TARGTID);
    FAPI_INF("  .BCW10_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW10_ChA_D1, TARGTID);
    FAPI_INF("  .BCW11_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW11_ChA_D1, TARGTID);
    FAPI_INF("  .BCW12_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW12_ChA_D1, TARGTID);
    FAPI_INF("  .BCW13_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW13_ChA_D1, TARGTID);
    FAPI_INF("  .BCW14_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW14_ChA_D1, TARGTID);
    FAPI_INF("  .BCW15_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW15_ChA_D1, TARGTID);
    FAPI_INF("  .BCW16_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW16_ChA_D1, TARGTID);
    FAPI_INF("  .BCW17_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW17_ChA_D1, TARGTID);
    FAPI_INF("  .BCW18_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW18_ChA_D1, TARGTID);
    FAPI_INF("  .BCW19_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW19_ChA_D1, TARGTID);
    FAPI_INF("  .BCW1A_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW1A_ChA_D1, TARGTID);
    FAPI_INF("  .BCW1B_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW1B_ChA_D1, TARGTID);
    FAPI_INF("  .BCW1C_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW1C_ChA_D1, TARGTID);
    FAPI_INF("  .BCW1D_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW1D_ChA_D1, TARGTID);
    FAPI_INF("  .BCW1E_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW1E_ChA_D1, TARGTID);
    FAPI_INF("  .BCW1F_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW1F_ChA_D1, TARGTID);
    FAPI_INF("  .BCW20_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW20_ChA_D1, TARGTID);
    FAPI_INF("  .BCW21_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW21_ChA_D1, TARGTID);
    FAPI_INF("  .BCW22_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW22_ChA_D1, TARGTID);
    FAPI_INF("  .BCW23_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW23_ChA_D1, TARGTID);
    FAPI_INF("  .BCW24_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW24_ChA_D1, TARGTID);
    FAPI_INF("  .BCW25_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW25_ChA_D1, TARGTID);
    FAPI_INF("  .BCW26_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW26_ChA_D1, TARGTID);
    FAPI_INF("  .BCW27_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW27_ChA_D1, TARGTID);
    FAPI_INF("  .BCW28_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW28_ChA_D1, TARGTID);
    FAPI_INF("  .BCW29_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW29_ChA_D1, TARGTID);
    FAPI_INF("  .BCW2A_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW2A_ChA_D1, TARGTID);
    FAPI_INF("  .BCW2B_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW2B_ChA_D1, TARGTID);
    FAPI_INF("  .BCW2C_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW2C_ChA_D1, TARGTID);
    FAPI_INF("  .BCW2D_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW2D_ChA_D1, TARGTID);
    FAPI_INF("  .BCW2E_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW2E_ChA_D1, TARGTID);
    FAPI_INF("  .BCW2F_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW2F_ChA_D1, TARGTID);
    FAPI_INF("  .BCW30_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW30_ChA_D1, TARGTID);
    FAPI_INF("  .BCW31_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW31_ChA_D1, TARGTID);
    FAPI_INF("  .BCW32_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW32_ChA_D1, TARGTID);
    FAPI_INF("  .BCW33_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW33_ChA_D1, TARGTID);
    FAPI_INF("  .BCW34_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW34_ChA_D1, TARGTID);
    FAPI_INF("  .BCW35_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW35_ChA_D1, TARGTID);
    FAPI_INF("  .BCW36_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW36_ChA_D1, TARGTID);
    FAPI_INF("  .BCW37_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW37_ChA_D1, TARGTID);
    FAPI_INF("  .BCW38_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW38_ChA_D1, TARGTID);
    FAPI_INF("  .BCW39_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW39_ChA_D1, TARGTID);
    FAPI_INF("  .BCW3A_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW3A_ChA_D1, TARGTID);
    FAPI_INF("  .BCW3B_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW3B_ChA_D1, TARGTID);
    FAPI_INF("  .BCW3C_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW3C_ChA_D1, TARGTID);
    FAPI_INF("  .BCW3D_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW3D_ChA_D1, TARGTID);
    FAPI_INF("  .BCW3E_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW3E_ChA_D1, TARGTID);
    FAPI_INF("  .BCW3F_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW3F_ChA_D1, TARGTID);
    FAPI_INF("  .BCW40_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW40_ChA_D1, TARGTID);
    FAPI_INF("  .BCW41_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW41_ChA_D1, TARGTID);
    FAPI_INF("  .BCW42_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW42_ChA_D1, TARGTID);
    FAPI_INF("  .BCW43_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW43_ChA_D1, TARGTID);
    FAPI_INF("  .BCW44_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW44_ChA_D1, TARGTID);
    FAPI_INF("  .BCW45_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW45_ChA_D1, TARGTID);
    FAPI_INF("  .BCW46_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW46_ChA_D1, TARGTID);
    FAPI_INF("  .BCW47_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW47_ChA_D1, TARGTID);
    FAPI_INF("  .BCW48_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW48_ChA_D1, TARGTID);
    FAPI_INF("  .BCW49_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW49_ChA_D1, TARGTID);
    FAPI_INF("  .BCW4A_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW4A_ChA_D1, TARGTID);
    FAPI_INF("  .BCW4B_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW4B_ChA_D1, TARGTID);
    FAPI_INF("  .BCW4C_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW4C_ChA_D1, TARGTID);
    FAPI_INF("  .BCW4D_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW4D_ChA_D1, TARGTID);
    FAPI_INF("  .BCW4E_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW4E_ChA_D1, TARGTID);
    FAPI_INF("  .BCW4F_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW4F_ChA_D1, TARGTID);
    FAPI_INF("  .BCW50_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW50_ChA_D1, TARGTID);
    FAPI_INF("  .BCW51_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW51_ChA_D1, TARGTID);
    FAPI_INF("  .BCW52_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW52_ChA_D1, TARGTID);
    FAPI_INF("  .BCW53_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW53_ChA_D1, TARGTID);
    FAPI_INF("  .BCW54_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW54_ChA_D1, TARGTID);
    FAPI_INF("  .BCW55_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW55_ChA_D1, TARGTID);
    FAPI_INF("  .BCW56_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW56_ChA_D1, TARGTID);
    FAPI_INF("  .BCW57_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW57_ChA_D1, TARGTID);
    FAPI_INF("  .BCW58_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW58_ChA_D1, TARGTID);
    FAPI_INF("  .BCW59_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW59_ChA_D1, TARGTID);
    FAPI_INF("  .BCW5A_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW5A_ChA_D1, TARGTID);
    FAPI_INF("  .BCW5B_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW5B_ChA_D1, TARGTID);
    FAPI_INF("  .BCW5C_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW5C_ChA_D1, TARGTID);
    FAPI_INF("  .BCW5D_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW5D_ChA_D1, TARGTID);
    FAPI_INF("  .BCW5E_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW5E_ChA_D1, TARGTID);
    FAPI_INF("  .BCW5F_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW5F_ChA_D1, TARGTID);
    FAPI_INF("  .BCW60_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW60_ChA_D1, TARGTID);
    FAPI_INF("  .BCW61_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW61_ChA_D1, TARGTID);
    FAPI_INF("  .BCW62_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW62_ChA_D1, TARGTID);
    FAPI_INF("  .BCW63_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW63_ChA_D1, TARGTID);
    FAPI_INF("  .BCW64_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW64_ChA_D1, TARGTID);
    FAPI_INF("  .BCW65_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW65_ChA_D1, TARGTID);
    FAPI_INF("  .BCW66_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW66_ChA_D1, TARGTID);
    FAPI_INF("  .BCW67_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW67_ChA_D1, TARGTID);
    FAPI_INF("  .BCW68_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW68_ChA_D1, TARGTID);
    FAPI_INF("  .BCW69_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW69_ChA_D1, TARGTID);
    FAPI_INF("  .BCW6A_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW6A_ChA_D1, TARGTID);
    FAPI_INF("  .BCW6B_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW6B_ChA_D1, TARGTID);
    FAPI_INF("  .BCW6C_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW6C_ChA_D1, TARGTID);
    FAPI_INF("  .BCW6D_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW6D_ChA_D1, TARGTID);
    FAPI_INF("  .BCW6E_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW6E_ChA_D1, TARGTID);
    FAPI_INF("  .BCW6F_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW6F_ChA_D1, TARGTID);
    FAPI_INF("  .BCW70_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW70_ChA_D1, TARGTID);
    FAPI_INF("  .BCW71_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW71_ChA_D1, TARGTID);
    FAPI_INF("  .BCW72_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW72_ChA_D1, TARGTID);
    FAPI_INF("  .BCW73_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW73_ChA_D1, TARGTID);
    FAPI_INF("  .BCW74_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW74_ChA_D1, TARGTID);
    FAPI_INF("  .BCW75_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW75_ChA_D1, TARGTID);
    FAPI_INF("  .BCW76_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW76_ChA_D1, TARGTID);
    FAPI_INF("  .BCW77_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW77_ChA_D1, TARGTID);
    FAPI_INF("  .BCW78_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW78_ChA_D1, TARGTID);
    FAPI_INF("  .BCW79_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW79_ChA_D1, TARGTID);
    FAPI_INF("  .BCW7A_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW7A_ChA_D1, TARGTID);
    FAPI_INF("  .BCW7B_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW7B_ChA_D1, TARGTID);
    FAPI_INF("  .BCW7C_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW7C_ChA_D1, TARGTID);
    FAPI_INF("  .BCW7D_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW7D_ChA_D1, TARGTID);
    FAPI_INF("  .BCW7E_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW7E_ChA_D1, TARGTID);
    FAPI_INF("  .BCW7F_ChA_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW7F_ChA_D1, TARGTID);
    FAPI_INF("  .RCW00_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW00_ChB_D0, TARGTID);
    FAPI_INF("  .RCW01_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW01_ChB_D0, TARGTID);
    FAPI_INF("  .RCW02_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW02_ChB_D0, TARGTID);
    FAPI_INF("  .RCW03_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW03_ChB_D0, TARGTID);
    FAPI_INF("  .RCW04_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW04_ChB_D0, TARGTID);
    FAPI_INF("  .RCW05_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW05_ChB_D0, TARGTID);
    FAPI_INF("  .RCW06_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW06_ChB_D0, TARGTID);
    FAPI_INF("  .RCW07_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW07_ChB_D0, TARGTID);
    FAPI_INF("  .RCW08_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW08_ChB_D0, TARGTID);
    FAPI_INF("  .RCW09_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW09_ChB_D0, TARGTID);
    FAPI_INF("  .RCW0A_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW0A_ChB_D0, TARGTID);
    FAPI_INF("  .RCW0B_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW0B_ChB_D0, TARGTID);
    FAPI_INF("  .RCW0C_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW0C_ChB_D0, TARGTID);
    FAPI_INF("  .RCW0D_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW0D_ChB_D0, TARGTID);
    FAPI_INF("  .RCW0E_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW0E_ChB_D0, TARGTID);
    FAPI_INF("  .RCW0F_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW0F_ChB_D0, TARGTID);
    FAPI_INF("  .RCW10_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW10_ChB_D0, TARGTID);
    FAPI_INF("  .RCW11_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW11_ChB_D0, TARGTID);
    FAPI_INF("  .RCW12_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW12_ChB_D0, TARGTID);
    FAPI_INF("  .RCW13_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW13_ChB_D0, TARGTID);
    FAPI_INF("  .RCW14_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW14_ChB_D0, TARGTID);
    FAPI_INF("  .RCW15_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW15_ChB_D0, TARGTID);
    FAPI_INF("  .RCW16_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW16_ChB_D0, TARGTID);
    FAPI_INF("  .RCW17_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW17_ChB_D0, TARGTID);
    FAPI_INF("  .RCW18_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW18_ChB_D0, TARGTID);
    FAPI_INF("  .RCW19_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW19_ChB_D0, TARGTID);
    FAPI_INF("  .RCW1A_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW1A_ChB_D0, TARGTID);
    FAPI_INF("  .RCW1B_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW1B_ChB_D0, TARGTID);
    FAPI_INF("  .RCW1C_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW1C_ChB_D0, TARGTID);
    FAPI_INF("  .RCW1D_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW1D_ChB_D0, TARGTID);
    FAPI_INF("  .RCW1E_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW1E_ChB_D0, TARGTID);
    FAPI_INF("  .RCW1F_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW1F_ChB_D0, TARGTID);
    FAPI_INF("  .RCW20_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW20_ChB_D0, TARGTID);
    FAPI_INF("  .RCW21_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW21_ChB_D0, TARGTID);
    FAPI_INF("  .RCW22_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW22_ChB_D0, TARGTID);
    FAPI_INF("  .RCW23_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW23_ChB_D0, TARGTID);
    FAPI_INF("  .RCW24_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW24_ChB_D0, TARGTID);
    FAPI_INF("  .RCW25_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW25_ChB_D0, TARGTID);
    FAPI_INF("  .RCW26_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW26_ChB_D0, TARGTID);
    FAPI_INF("  .RCW27_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW27_ChB_D0, TARGTID);
    FAPI_INF("  .RCW28_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW28_ChB_D0, TARGTID);
    FAPI_INF("  .RCW29_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW29_ChB_D0, TARGTID);
    FAPI_INF("  .RCW2A_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW2A_ChB_D0, TARGTID);
    FAPI_INF("  .RCW2B_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW2B_ChB_D0, TARGTID);
    FAPI_INF("  .RCW2C_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW2C_ChB_D0, TARGTID);
    FAPI_INF("  .RCW2D_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW2D_ChB_D0, TARGTID);
    FAPI_INF("  .RCW2E_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW2E_ChB_D0, TARGTID);
    FAPI_INF("  .RCW2F_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW2F_ChB_D0, TARGTID);
    FAPI_INF("  .RCW30_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW30_ChB_D0, TARGTID);
    FAPI_INF("  .RCW31_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW31_ChB_D0, TARGTID);
    FAPI_INF("  .RCW32_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW32_ChB_D0, TARGTID);
    FAPI_INF("  .RCW33_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW33_ChB_D0, TARGTID);
    FAPI_INF("  .RCW34_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW34_ChB_D0, TARGTID);
    FAPI_INF("  .RCW35_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW35_ChB_D0, TARGTID);
    FAPI_INF("  .RCW36_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW36_ChB_D0, TARGTID);
    FAPI_INF("  .RCW37_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW37_ChB_D0, TARGTID);
    FAPI_INF("  .RCW38_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW38_ChB_D0, TARGTID);
    FAPI_INF("  .RCW39_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW39_ChB_D0, TARGTID);
    FAPI_INF("  .RCW3A_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW3A_ChB_D0, TARGTID);
    FAPI_INF("  .RCW3B_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW3B_ChB_D0, TARGTID);
    FAPI_INF("  .RCW3C_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW3C_ChB_D0, TARGTID);
    FAPI_INF("  .RCW3D_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW3D_ChB_D0, TARGTID);
    FAPI_INF("  .RCW3E_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW3E_ChB_D0, TARGTID);
    FAPI_INF("  .RCW3F_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW3F_ChB_D0, TARGTID);
    FAPI_INF("  .RCW40_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW40_ChB_D0, TARGTID);
    FAPI_INF("  .RCW41_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW41_ChB_D0, TARGTID);
    FAPI_INF("  .RCW42_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW42_ChB_D0, TARGTID);
    FAPI_INF("  .RCW43_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW43_ChB_D0, TARGTID);
    FAPI_INF("  .RCW44_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW44_ChB_D0, TARGTID);
    FAPI_INF("  .RCW45_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW45_ChB_D0, TARGTID);
    FAPI_INF("  .RCW46_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW46_ChB_D0, TARGTID);
    FAPI_INF("  .RCW47_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW47_ChB_D0, TARGTID);
    FAPI_INF("  .RCW48_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW48_ChB_D0, TARGTID);
    FAPI_INF("  .RCW49_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW49_ChB_D0, TARGTID);
    FAPI_INF("  .RCW4A_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW4A_ChB_D0, TARGTID);
    FAPI_INF("  .RCW4B_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW4B_ChB_D0, TARGTID);
    FAPI_INF("  .RCW4C_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW4C_ChB_D0, TARGTID);
    FAPI_INF("  .RCW4D_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW4D_ChB_D0, TARGTID);
    FAPI_INF("  .RCW4E_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW4E_ChB_D0, TARGTID);
    FAPI_INF("  .RCW4F_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW4F_ChB_D0, TARGTID);
    FAPI_INF("  .RCW50_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW50_ChB_D0, TARGTID);
    FAPI_INF("  .RCW51_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW51_ChB_D0, TARGTID);
    FAPI_INF("  .RCW52_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW52_ChB_D0, TARGTID);
    FAPI_INF("  .RCW53_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW53_ChB_D0, TARGTID);
    FAPI_INF("  .RCW54_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW54_ChB_D0, TARGTID);
    FAPI_INF("  .RCW55_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW55_ChB_D0, TARGTID);
    FAPI_INF("  .RCW56_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW56_ChB_D0, TARGTID);
    FAPI_INF("  .RCW57_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW57_ChB_D0, TARGTID);
    FAPI_INF("  .RCW58_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW58_ChB_D0, TARGTID);
    FAPI_INF("  .RCW59_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW59_ChB_D0, TARGTID);
    FAPI_INF("  .RCW5A_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW5A_ChB_D0, TARGTID);
    FAPI_INF("  .RCW5B_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW5B_ChB_D0, TARGTID);
    FAPI_INF("  .RCW5C_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW5C_ChB_D0, TARGTID);
    FAPI_INF("  .RCW5D_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW5D_ChB_D0, TARGTID);
    FAPI_INF("  .RCW5E_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW5E_ChB_D0, TARGTID);
    FAPI_INF("  .RCW5F_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW5F_ChB_D0, TARGTID);
    FAPI_INF("  .RCW60_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW60_ChB_D0, TARGTID);
    FAPI_INF("  .RCW61_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW61_ChB_D0, TARGTID);
    FAPI_INF("  .RCW62_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW62_ChB_D0, TARGTID);
    FAPI_INF("  .RCW63_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW63_ChB_D0, TARGTID);
    FAPI_INF("  .RCW64_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW64_ChB_D0, TARGTID);
    FAPI_INF("  .RCW65_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW65_ChB_D0, TARGTID);
    FAPI_INF("  .RCW66_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW66_ChB_D0, TARGTID);
    FAPI_INF("  .RCW67_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW67_ChB_D0, TARGTID);
    FAPI_INF("  .RCW68_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW68_ChB_D0, TARGTID);
    FAPI_INF("  .RCW69_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW69_ChB_D0, TARGTID);
    FAPI_INF("  .RCW6A_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW6A_ChB_D0, TARGTID);
    FAPI_INF("  .RCW6B_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW6B_ChB_D0, TARGTID);
    FAPI_INF("  .RCW6C_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW6C_ChB_D0, TARGTID);
    FAPI_INF("  .RCW6D_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW6D_ChB_D0, TARGTID);
    FAPI_INF("  .RCW6E_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW6E_ChB_D0, TARGTID);
    FAPI_INF("  .RCW6F_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW6F_ChB_D0, TARGTID);
    FAPI_INF("  .RCW70_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW70_ChB_D0, TARGTID);
    FAPI_INF("  .RCW71_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW71_ChB_D0, TARGTID);
    FAPI_INF("  .RCW72_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW72_ChB_D0, TARGTID);
    FAPI_INF("  .RCW73_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW73_ChB_D0, TARGTID);
    FAPI_INF("  .RCW74_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW74_ChB_D0, TARGTID);
    FAPI_INF("  .RCW75_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW75_ChB_D0, TARGTID);
    FAPI_INF("  .RCW76_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW76_ChB_D0, TARGTID);
    FAPI_INF("  .RCW77_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW77_ChB_D0, TARGTID);
    FAPI_INF("  .RCW78_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW78_ChB_D0, TARGTID);
    FAPI_INF("  .RCW79_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW79_ChB_D0, TARGTID);
    FAPI_INF("  .RCW7A_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW7A_ChB_D0, TARGTID);
    FAPI_INF("  .RCW7B_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW7B_ChB_D0, TARGTID);
    FAPI_INF("  .RCW7C_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW7C_ChB_D0, TARGTID);
    FAPI_INF("  .RCW7D_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW7D_ChB_D0, TARGTID);
    FAPI_INF("  .RCW7E_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW7E_ChB_D0, TARGTID);
    FAPI_INF("  .RCW7F_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW7F_ChB_D0, TARGTID);
    FAPI_INF("  .BCW00_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW00_ChB_D0, TARGTID);
    FAPI_INF("  .BCW01_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW01_ChB_D0, TARGTID);
    FAPI_INF("  .BCW02_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW02_ChB_D0, TARGTID);
    FAPI_INF("  .BCW03_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW03_ChB_D0, TARGTID);
    FAPI_INF("  .BCW04_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW04_ChB_D0, TARGTID);
    FAPI_INF("  .BCW05_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW05_ChB_D0, TARGTID);
    FAPI_INF("  .BCW06_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW06_ChB_D0, TARGTID);
    FAPI_INF("  .BCW07_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW07_ChB_D0, TARGTID);
    FAPI_INF("  .BCW08_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW08_ChB_D0, TARGTID);
    FAPI_INF("  .BCW09_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW09_ChB_D0, TARGTID);
    FAPI_INF("  .BCW0A_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW0A_ChB_D0, TARGTID);
    FAPI_INF("  .BCW0B_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW0B_ChB_D0, TARGTID);
    FAPI_INF("  .BCW0C_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW0C_ChB_D0, TARGTID);
    FAPI_INF("  .BCW0D_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW0D_ChB_D0, TARGTID);
    FAPI_INF("  .BCW0E_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW0E_ChB_D0, TARGTID);
    FAPI_INF("  .BCW0F_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW0F_ChB_D0, TARGTID);
    FAPI_INF("  .BCW10_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW10_ChB_D0, TARGTID);
    FAPI_INF("  .BCW11_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW11_ChB_D0, TARGTID);
    FAPI_INF("  .BCW12_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW12_ChB_D0, TARGTID);
    FAPI_INF("  .BCW13_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW13_ChB_D0, TARGTID);
    FAPI_INF("  .BCW14_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW14_ChB_D0, TARGTID);
    FAPI_INF("  .BCW15_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW15_ChB_D0, TARGTID);
    FAPI_INF("  .BCW16_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW16_ChB_D0, TARGTID);
    FAPI_INF("  .BCW17_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW17_ChB_D0, TARGTID);
    FAPI_INF("  .BCW18_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW18_ChB_D0, TARGTID);
    FAPI_INF("  .BCW19_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW19_ChB_D0, TARGTID);
    FAPI_INF("  .BCW1A_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW1A_ChB_D0, TARGTID);
    FAPI_INF("  .BCW1B_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW1B_ChB_D0, TARGTID);
    FAPI_INF("  .BCW1C_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW1C_ChB_D0, TARGTID);
    FAPI_INF("  .BCW1D_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW1D_ChB_D0, TARGTID);
    FAPI_INF("  .BCW1E_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW1E_ChB_D0, TARGTID);
    FAPI_INF("  .BCW1F_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW1F_ChB_D0, TARGTID);
    FAPI_INF("  .BCW20_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW20_ChB_D0, TARGTID);
    FAPI_INF("  .BCW21_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW21_ChB_D0, TARGTID);
    FAPI_INF("  .BCW22_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW22_ChB_D0, TARGTID);
    FAPI_INF("  .BCW23_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW23_ChB_D0, TARGTID);
    FAPI_INF("  .BCW24_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW24_ChB_D0, TARGTID);
    FAPI_INF("  .BCW25_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW25_ChB_D0, TARGTID);
    FAPI_INF("  .BCW26_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW26_ChB_D0, TARGTID);
    FAPI_INF("  .BCW27_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW27_ChB_D0, TARGTID);
    FAPI_INF("  .BCW28_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW28_ChB_D0, TARGTID);
    FAPI_INF("  .BCW29_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW29_ChB_D0, TARGTID);
    FAPI_INF("  .BCW2A_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW2A_ChB_D0, TARGTID);
    FAPI_INF("  .BCW2B_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW2B_ChB_D0, TARGTID);
    FAPI_INF("  .BCW2C_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW2C_ChB_D0, TARGTID);
    FAPI_INF("  .BCW2D_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW2D_ChB_D0, TARGTID);
    FAPI_INF("  .BCW2E_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW2E_ChB_D0, TARGTID);
    FAPI_INF("  .BCW2F_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW2F_ChB_D0, TARGTID);
    FAPI_INF("  .BCW30_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW30_ChB_D0, TARGTID);
    FAPI_INF("  .BCW31_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW31_ChB_D0, TARGTID);
    FAPI_INF("  .BCW32_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW32_ChB_D0, TARGTID);
    FAPI_INF("  .BCW33_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW33_ChB_D0, TARGTID);
    FAPI_INF("  .BCW34_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW34_ChB_D0, TARGTID);
    FAPI_INF("  .BCW35_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW35_ChB_D0, TARGTID);
    FAPI_INF("  .BCW36_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW36_ChB_D0, TARGTID);
    FAPI_INF("  .BCW37_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW37_ChB_D0, TARGTID);
    FAPI_INF("  .BCW38_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW38_ChB_D0, TARGTID);
    FAPI_INF("  .BCW39_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW39_ChB_D0, TARGTID);
    FAPI_INF("  .BCW3A_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW3A_ChB_D0, TARGTID);
    FAPI_INF("  .BCW3B_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW3B_ChB_D0, TARGTID);
    FAPI_INF("  .BCW3C_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW3C_ChB_D0, TARGTID);
    FAPI_INF("  .BCW3D_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW3D_ChB_D0, TARGTID);
    FAPI_INF("  .BCW3E_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW3E_ChB_D0, TARGTID);
    FAPI_INF("  .BCW3F_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW3F_ChB_D0, TARGTID);
    FAPI_INF("  .BCW40_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW40_ChB_D0, TARGTID);
    FAPI_INF("  .BCW41_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW41_ChB_D0, TARGTID);
    FAPI_INF("  .BCW42_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW42_ChB_D0, TARGTID);
    FAPI_INF("  .BCW43_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW43_ChB_D0, TARGTID);
    FAPI_INF("  .BCW44_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW44_ChB_D0, TARGTID);
    FAPI_INF("  .BCW45_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW45_ChB_D0, TARGTID);
    FAPI_INF("  .BCW46_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW46_ChB_D0, TARGTID);
    FAPI_INF("  .BCW47_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW47_ChB_D0, TARGTID);
    FAPI_INF("  .BCW48_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW48_ChB_D0, TARGTID);
    FAPI_INF("  .BCW49_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW49_ChB_D0, TARGTID);
    FAPI_INF("  .BCW4A_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW4A_ChB_D0, TARGTID);
    FAPI_INF("  .BCW4B_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW4B_ChB_D0, TARGTID);
    FAPI_INF("  .BCW4C_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW4C_ChB_D0, TARGTID);
    FAPI_INF("  .BCW4D_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW4D_ChB_D0, TARGTID);
    FAPI_INF("  .BCW4E_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW4E_ChB_D0, TARGTID);
    FAPI_INF("  .BCW4F_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW4F_ChB_D0, TARGTID);
    FAPI_INF("  .BCW50_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW50_ChB_D0, TARGTID);
    FAPI_INF("  .BCW51_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW51_ChB_D0, TARGTID);
    FAPI_INF("  .BCW52_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW52_ChB_D0, TARGTID);
    FAPI_INF("  .BCW53_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW53_ChB_D0, TARGTID);
    FAPI_INF("  .BCW54_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW54_ChB_D0, TARGTID);
    FAPI_INF("  .BCW55_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW55_ChB_D0, TARGTID);
    FAPI_INF("  .BCW56_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW56_ChB_D0, TARGTID);
    FAPI_INF("  .BCW57_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW57_ChB_D0, TARGTID);
    FAPI_INF("  .BCW58_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW58_ChB_D0, TARGTID);
    FAPI_INF("  .BCW59_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW59_ChB_D0, TARGTID);
    FAPI_INF("  .BCW5A_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW5A_ChB_D0, TARGTID);
    FAPI_INF("  .BCW5B_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW5B_ChB_D0, TARGTID);
    FAPI_INF("  .BCW5C_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW5C_ChB_D0, TARGTID);
    FAPI_INF("  .BCW5D_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW5D_ChB_D0, TARGTID);
    FAPI_INF("  .BCW5E_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW5E_ChB_D0, TARGTID);
    FAPI_INF("  .BCW5F_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW5F_ChB_D0, TARGTID);
    FAPI_INF("  .BCW60_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW60_ChB_D0, TARGTID);
    FAPI_INF("  .BCW61_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW61_ChB_D0, TARGTID);
    FAPI_INF("  .BCW62_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW62_ChB_D0, TARGTID);
    FAPI_INF("  .BCW63_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW63_ChB_D0, TARGTID);
    FAPI_INF("  .BCW64_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW64_ChB_D0, TARGTID);
    FAPI_INF("  .BCW65_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW65_ChB_D0, TARGTID);
    FAPI_INF("  .BCW66_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW66_ChB_D0, TARGTID);
    FAPI_INF("  .BCW67_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW67_ChB_D0, TARGTID);
    FAPI_INF("  .BCW68_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW68_ChB_D0, TARGTID);
    FAPI_INF("  .BCW69_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW69_ChB_D0, TARGTID);
    FAPI_INF("  .BCW6A_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW6A_ChB_D0, TARGTID);
    FAPI_INF("  .BCW6B_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW6B_ChB_D0, TARGTID);
    FAPI_INF("  .BCW6C_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW6C_ChB_D0, TARGTID);
    FAPI_INF("  .BCW6D_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW6D_ChB_D0, TARGTID);
    FAPI_INF("  .BCW6E_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW6E_ChB_D0, TARGTID);
    FAPI_INF("  .BCW6F_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW6F_ChB_D0, TARGTID);
    FAPI_INF("  .BCW70_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW70_ChB_D0, TARGTID);
    FAPI_INF("  .BCW71_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW71_ChB_D0, TARGTID);
    FAPI_INF("  .BCW72_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW72_ChB_D0, TARGTID);
    FAPI_INF("  .BCW73_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW73_ChB_D0, TARGTID);
    FAPI_INF("  .BCW74_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW74_ChB_D0, TARGTID);
    FAPI_INF("  .BCW75_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW75_ChB_D0, TARGTID);
    FAPI_INF("  .BCW76_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW76_ChB_D0, TARGTID);
    FAPI_INF("  .BCW77_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW77_ChB_D0, TARGTID);
    FAPI_INF("  .BCW78_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW78_ChB_D0, TARGTID);
    FAPI_INF("  .BCW79_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW79_ChB_D0, TARGTID);
    FAPI_INF("  .BCW7A_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW7A_ChB_D0, TARGTID);
    FAPI_INF("  .BCW7B_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW7B_ChB_D0, TARGTID);
    FAPI_INF("  .BCW7C_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW7C_ChB_D0, TARGTID);
    FAPI_INF("  .BCW7D_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW7D_ChB_D0, TARGTID);
    FAPI_INF("  .BCW7E_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW7E_ChB_D0, TARGTID);
    FAPI_INF("  .BCW7F_ChB_D0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW7F_ChB_D0, TARGTID);
    FAPI_INF("  .RCW00_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW00_ChB_D1, TARGTID);
    FAPI_INF("  .RCW01_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW01_ChB_D1, TARGTID);
    FAPI_INF("  .RCW02_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW02_ChB_D1, TARGTID);
    FAPI_INF("  .RCW03_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW03_ChB_D1, TARGTID);
    FAPI_INF("  .RCW04_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW04_ChB_D1, TARGTID);
    FAPI_INF("  .RCW05_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW05_ChB_D1, TARGTID);
    FAPI_INF("  .RCW06_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW06_ChB_D1, TARGTID);
    FAPI_INF("  .RCW07_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW07_ChB_D1, TARGTID);
    FAPI_INF("  .RCW08_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW08_ChB_D1, TARGTID);
    FAPI_INF("  .RCW09_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW09_ChB_D1, TARGTID);
    FAPI_INF("  .RCW0A_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW0A_ChB_D1, TARGTID);
    FAPI_INF("  .RCW0B_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW0B_ChB_D1, TARGTID);
    FAPI_INF("  .RCW0C_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW0C_ChB_D1, TARGTID);
    FAPI_INF("  .RCW0D_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW0D_ChB_D1, TARGTID);
    FAPI_INF("  .RCW0E_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW0E_ChB_D1, TARGTID);
    FAPI_INF("  .RCW0F_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW0F_ChB_D1, TARGTID);
    FAPI_INF("  .RCW10_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW10_ChB_D1, TARGTID);
    FAPI_INF("  .RCW11_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW11_ChB_D1, TARGTID);
    FAPI_INF("  .RCW12_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW12_ChB_D1, TARGTID);
    FAPI_INF("  .RCW13_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW13_ChB_D1, TARGTID);
    FAPI_INF("  .RCW14_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW14_ChB_D1, TARGTID);
    FAPI_INF("  .RCW15_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW15_ChB_D1, TARGTID);
    FAPI_INF("  .RCW16_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW16_ChB_D1, TARGTID);
    FAPI_INF("  .RCW17_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW17_ChB_D1, TARGTID);
    FAPI_INF("  .RCW18_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW18_ChB_D1, TARGTID);
    FAPI_INF("  .RCW19_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW19_ChB_D1, TARGTID);
    FAPI_INF("  .RCW1A_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW1A_ChB_D1, TARGTID);
    FAPI_INF("  .RCW1B_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW1B_ChB_D1, TARGTID);
    FAPI_INF("  .RCW1C_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW1C_ChB_D1, TARGTID);
    FAPI_INF("  .RCW1D_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW1D_ChB_D1, TARGTID);
    FAPI_INF("  .RCW1E_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW1E_ChB_D1, TARGTID);
    FAPI_INF("  .RCW1F_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW1F_ChB_D1, TARGTID);
    FAPI_INF("  .RCW20_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW20_ChB_D1, TARGTID);
    FAPI_INF("  .RCW21_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW21_ChB_D1, TARGTID);
    FAPI_INF("  .RCW22_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW22_ChB_D1, TARGTID);
    FAPI_INF("  .RCW23_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW23_ChB_D1, TARGTID);
    FAPI_INF("  .RCW24_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW24_ChB_D1, TARGTID);
    FAPI_INF("  .RCW25_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW25_ChB_D1, TARGTID);
    FAPI_INF("  .RCW26_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW26_ChB_D1, TARGTID);
    FAPI_INF("  .RCW27_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW27_ChB_D1, TARGTID);
    FAPI_INF("  .RCW28_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW28_ChB_D1, TARGTID);
    FAPI_INF("  .RCW29_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW29_ChB_D1, TARGTID);
    FAPI_INF("  .RCW2A_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW2A_ChB_D1, TARGTID);
    FAPI_INF("  .RCW2B_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW2B_ChB_D1, TARGTID);
    FAPI_INF("  .RCW2C_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW2C_ChB_D1, TARGTID);
    FAPI_INF("  .RCW2D_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW2D_ChB_D1, TARGTID);
    FAPI_INF("  .RCW2E_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW2E_ChB_D1, TARGTID);
    FAPI_INF("  .RCW2F_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW2F_ChB_D1, TARGTID);
    FAPI_INF("  .RCW30_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW30_ChB_D1, TARGTID);
    FAPI_INF("  .RCW31_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW31_ChB_D1, TARGTID);
    FAPI_INF("  .RCW32_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW32_ChB_D1, TARGTID);
    FAPI_INF("  .RCW33_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW33_ChB_D1, TARGTID);
    FAPI_INF("  .RCW34_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW34_ChB_D1, TARGTID);
    FAPI_INF("  .RCW35_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW35_ChB_D1, TARGTID);
    FAPI_INF("  .RCW36_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW36_ChB_D1, TARGTID);
    FAPI_INF("  .RCW37_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW37_ChB_D1, TARGTID);
    FAPI_INF("  .RCW38_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW38_ChB_D1, TARGTID);
    FAPI_INF("  .RCW39_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW39_ChB_D1, TARGTID);
    FAPI_INF("  .RCW3A_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW3A_ChB_D1, TARGTID);
    FAPI_INF("  .RCW3B_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW3B_ChB_D1, TARGTID);
    FAPI_INF("  .RCW3C_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW3C_ChB_D1, TARGTID);
    FAPI_INF("  .RCW3D_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW3D_ChB_D1, TARGTID);
    FAPI_INF("  .RCW3E_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW3E_ChB_D1, TARGTID);
    FAPI_INF("  .RCW3F_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW3F_ChB_D1, TARGTID);
    FAPI_INF("  .RCW40_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW40_ChB_D1, TARGTID);
    FAPI_INF("  .RCW41_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW41_ChB_D1, TARGTID);
    FAPI_INF("  .RCW42_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW42_ChB_D1, TARGTID);
    FAPI_INF("  .RCW43_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW43_ChB_D1, TARGTID);
    FAPI_INF("  .RCW44_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW44_ChB_D1, TARGTID);
    FAPI_INF("  .RCW45_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW45_ChB_D1, TARGTID);
    FAPI_INF("  .RCW46_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW46_ChB_D1, TARGTID);
    FAPI_INF("  .RCW47_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW47_ChB_D1, TARGTID);
    FAPI_INF("  .RCW48_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW48_ChB_D1, TARGTID);
    FAPI_INF("  .RCW49_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW49_ChB_D1, TARGTID);
    FAPI_INF("  .RCW4A_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW4A_ChB_D1, TARGTID);
    FAPI_INF("  .RCW4B_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW4B_ChB_D1, TARGTID);
    FAPI_INF("  .RCW4C_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW4C_ChB_D1, TARGTID);
    FAPI_INF("  .RCW4D_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW4D_ChB_D1, TARGTID);
    FAPI_INF("  .RCW4E_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW4E_ChB_D1, TARGTID);
    FAPI_INF("  .RCW4F_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW4F_ChB_D1, TARGTID);
    FAPI_INF("  .RCW50_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW50_ChB_D1, TARGTID);
    FAPI_INF("  .RCW51_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW51_ChB_D1, TARGTID);
    FAPI_INF("  .RCW52_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW52_ChB_D1, TARGTID);
    FAPI_INF("  .RCW53_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW53_ChB_D1, TARGTID);
    FAPI_INF("  .RCW54_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW54_ChB_D1, TARGTID);
    FAPI_INF("  .RCW55_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW55_ChB_D1, TARGTID);
    FAPI_INF("  .RCW56_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW56_ChB_D1, TARGTID);
    FAPI_INF("  .RCW57_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW57_ChB_D1, TARGTID);
    FAPI_INF("  .RCW58_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW58_ChB_D1, TARGTID);
    FAPI_INF("  .RCW59_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW59_ChB_D1, TARGTID);
    FAPI_INF("  .RCW5A_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW5A_ChB_D1, TARGTID);
    FAPI_INF("  .RCW5B_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW5B_ChB_D1, TARGTID);
    FAPI_INF("  .RCW5C_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW5C_ChB_D1, TARGTID);
    FAPI_INF("  .RCW5D_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW5D_ChB_D1, TARGTID);
    FAPI_INF("  .RCW5E_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW5E_ChB_D1, TARGTID);
    FAPI_INF("  .RCW5F_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW5F_ChB_D1, TARGTID);
    FAPI_INF("  .RCW60_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW60_ChB_D1, TARGTID);
    FAPI_INF("  .RCW61_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW61_ChB_D1, TARGTID);
    FAPI_INF("  .RCW62_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW62_ChB_D1, TARGTID);
    FAPI_INF("  .RCW63_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW63_ChB_D1, TARGTID);
    FAPI_INF("  .RCW64_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW64_ChB_D1, TARGTID);
    FAPI_INF("  .RCW65_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW65_ChB_D1, TARGTID);
    FAPI_INF("  .RCW66_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW66_ChB_D1, TARGTID);
    FAPI_INF("  .RCW67_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW67_ChB_D1, TARGTID);
    FAPI_INF("  .RCW68_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW68_ChB_D1, TARGTID);
    FAPI_INF("  .RCW69_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW69_ChB_D1, TARGTID);
    FAPI_INF("  .RCW6A_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW6A_ChB_D1, TARGTID);
    FAPI_INF("  .RCW6B_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW6B_ChB_D1, TARGTID);
    FAPI_INF("  .RCW6C_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW6C_ChB_D1, TARGTID);
    FAPI_INF("  .RCW6D_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW6D_ChB_D1, TARGTID);
    FAPI_INF("  .RCW6E_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW6E_ChB_D1, TARGTID);
    FAPI_INF("  .RCW6F_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW6F_ChB_D1, TARGTID);
    FAPI_INF("  .RCW70_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW70_ChB_D1, TARGTID);
    FAPI_INF("  .RCW71_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW71_ChB_D1, TARGTID);
    FAPI_INF("  .RCW72_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW72_ChB_D1, TARGTID);
    FAPI_INF("  .RCW73_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW73_ChB_D1, TARGTID);
    FAPI_INF("  .RCW74_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW74_ChB_D1, TARGTID);
    FAPI_INF("  .RCW75_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW75_ChB_D1, TARGTID);
    FAPI_INF("  .RCW76_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW76_ChB_D1, TARGTID);
    FAPI_INF("  .RCW77_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW77_ChB_D1, TARGTID);
    FAPI_INF("  .RCW78_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW78_ChB_D1, TARGTID);
    FAPI_INF("  .RCW79_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW79_ChB_D1, TARGTID);
    FAPI_INF("  .RCW7A_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW7A_ChB_D1, TARGTID);
    FAPI_INF("  .RCW7B_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW7B_ChB_D1, TARGTID);
    FAPI_INF("  .RCW7C_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW7C_ChB_D1, TARGTID);
    FAPI_INF("  .RCW7D_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW7D_ChB_D1, TARGTID);
    FAPI_INF("  .RCW7E_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW7E_ChB_D1, TARGTID);
    FAPI_INF("  .RCW7F_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.RCW7F_ChB_D1, TARGTID);
    FAPI_INF("  .BCW00_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW00_ChB_D1, TARGTID);
    FAPI_INF("  .BCW01_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW01_ChB_D1, TARGTID);
    FAPI_INF("  .BCW02_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW02_ChB_D1, TARGTID);
    FAPI_INF("  .BCW03_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW03_ChB_D1, TARGTID);
    FAPI_INF("  .BCW04_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW04_ChB_D1, TARGTID);
    FAPI_INF("  .BCW05_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW05_ChB_D1, TARGTID);
    FAPI_INF("  .BCW06_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW06_ChB_D1, TARGTID);
    FAPI_INF("  .BCW07_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW07_ChB_D1, TARGTID);
    FAPI_INF("  .BCW08_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW08_ChB_D1, TARGTID);
    FAPI_INF("  .BCW09_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW09_ChB_D1, TARGTID);
    FAPI_INF("  .BCW0A_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW0A_ChB_D1, TARGTID);
    FAPI_INF("  .BCW0B_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW0B_ChB_D1, TARGTID);
    FAPI_INF("  .BCW0C_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW0C_ChB_D1, TARGTID);
    FAPI_INF("  .BCW0D_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW0D_ChB_D1, TARGTID);
    FAPI_INF("  .BCW0E_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW0E_ChB_D1, TARGTID);
    FAPI_INF("  .BCW0F_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW0F_ChB_D1, TARGTID);
    FAPI_INF("  .BCW10_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW10_ChB_D1, TARGTID);
    FAPI_INF("  .BCW11_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW11_ChB_D1, TARGTID);
    FAPI_INF("  .BCW12_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW12_ChB_D1, TARGTID);
    FAPI_INF("  .BCW13_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW13_ChB_D1, TARGTID);
    FAPI_INF("  .BCW14_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW14_ChB_D1, TARGTID);
    FAPI_INF("  .BCW15_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW15_ChB_D1, TARGTID);
    FAPI_INF("  .BCW16_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW16_ChB_D1, TARGTID);
    FAPI_INF("  .BCW17_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW17_ChB_D1, TARGTID);
    FAPI_INF("  .BCW18_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW18_ChB_D1, TARGTID);
    FAPI_INF("  .BCW19_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW19_ChB_D1, TARGTID);
    FAPI_INF("  .BCW1A_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW1A_ChB_D1, TARGTID);
    FAPI_INF("  .BCW1B_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW1B_ChB_D1, TARGTID);
    FAPI_INF("  .BCW1C_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW1C_ChB_D1, TARGTID);
    FAPI_INF("  .BCW1D_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW1D_ChB_D1, TARGTID);
    FAPI_INF("  .BCW1E_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW1E_ChB_D1, TARGTID);
    FAPI_INF("  .BCW1F_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW1F_ChB_D1, TARGTID);
    FAPI_INF("  .BCW20_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW20_ChB_D1, TARGTID);
    FAPI_INF("  .BCW21_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW21_ChB_D1, TARGTID);
    FAPI_INF("  .BCW22_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW22_ChB_D1, TARGTID);
    FAPI_INF("  .BCW23_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW23_ChB_D1, TARGTID);
    FAPI_INF("  .BCW24_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW24_ChB_D1, TARGTID);
    FAPI_INF("  .BCW25_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW25_ChB_D1, TARGTID);
    FAPI_INF("  .BCW26_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW26_ChB_D1, TARGTID);
    FAPI_INF("  .BCW27_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW27_ChB_D1, TARGTID);
    FAPI_INF("  .BCW28_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW28_ChB_D1, TARGTID);
    FAPI_INF("  .BCW29_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW29_ChB_D1, TARGTID);
    FAPI_INF("  .BCW2A_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW2A_ChB_D1, TARGTID);
    FAPI_INF("  .BCW2B_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW2B_ChB_D1, TARGTID);
    FAPI_INF("  .BCW2C_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW2C_ChB_D1, TARGTID);
    FAPI_INF("  .BCW2D_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW2D_ChB_D1, TARGTID);
    FAPI_INF("  .BCW2E_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW2E_ChB_D1, TARGTID);
    FAPI_INF("  .BCW2F_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW2F_ChB_D1, TARGTID);
    FAPI_INF("  .BCW30_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW30_ChB_D1, TARGTID);
    FAPI_INF("  .BCW31_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW31_ChB_D1, TARGTID);
    FAPI_INF("  .BCW32_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW32_ChB_D1, TARGTID);
    FAPI_INF("  .BCW33_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW33_ChB_D1, TARGTID);
    FAPI_INF("  .BCW34_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW34_ChB_D1, TARGTID);
    FAPI_INF("  .BCW35_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW35_ChB_D1, TARGTID);
    FAPI_INF("  .BCW36_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW36_ChB_D1, TARGTID);
    FAPI_INF("  .BCW37_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW37_ChB_D1, TARGTID);
    FAPI_INF("  .BCW38_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW38_ChB_D1, TARGTID);
    FAPI_INF("  .BCW39_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW39_ChB_D1, TARGTID);
    FAPI_INF("  .BCW3A_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW3A_ChB_D1, TARGTID);
    FAPI_INF("  .BCW3B_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW3B_ChB_D1, TARGTID);
    FAPI_INF("  .BCW3C_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW3C_ChB_D1, TARGTID);
    FAPI_INF("  .BCW3D_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW3D_ChB_D1, TARGTID);
    FAPI_INF("  .BCW3E_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW3E_ChB_D1, TARGTID);
    FAPI_INF("  .BCW3F_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW3F_ChB_D1, TARGTID);
    FAPI_INF("  .BCW40_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW40_ChB_D1, TARGTID);
    FAPI_INF("  .BCW41_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW41_ChB_D1, TARGTID);
    FAPI_INF("  .BCW42_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW42_ChB_D1, TARGTID);
    FAPI_INF("  .BCW43_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW43_ChB_D1, TARGTID);
    FAPI_INF("  .BCW44_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW44_ChB_D1, TARGTID);
    FAPI_INF("  .BCW45_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW45_ChB_D1, TARGTID);
    FAPI_INF("  .BCW46_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW46_ChB_D1, TARGTID);
    FAPI_INF("  .BCW47_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW47_ChB_D1, TARGTID);
    FAPI_INF("  .BCW48_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW48_ChB_D1, TARGTID);
    FAPI_INF("  .BCW49_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW49_ChB_D1, TARGTID);
    FAPI_INF("  .BCW4A_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW4A_ChB_D1, TARGTID);
    FAPI_INF("  .BCW4B_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW4B_ChB_D1, TARGTID);
    FAPI_INF("  .BCW4C_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW4C_ChB_D1, TARGTID);
    FAPI_INF("  .BCW4D_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW4D_ChB_D1, TARGTID);
    FAPI_INF("  .BCW4E_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW4E_ChB_D1, TARGTID);
    FAPI_INF("  .BCW4F_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW4F_ChB_D1, TARGTID);
    FAPI_INF("  .BCW50_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW50_ChB_D1, TARGTID);
    FAPI_INF("  .BCW51_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW51_ChB_D1, TARGTID);
    FAPI_INF("  .BCW52_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW52_ChB_D1, TARGTID);
    FAPI_INF("  .BCW53_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW53_ChB_D1, TARGTID);
    FAPI_INF("  .BCW54_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW54_ChB_D1, TARGTID);
    FAPI_INF("  .BCW55_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW55_ChB_D1, TARGTID);
    FAPI_INF("  .BCW56_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW56_ChB_D1, TARGTID);
    FAPI_INF("  .BCW57_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW57_ChB_D1, TARGTID);
    FAPI_INF("  .BCW58_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW58_ChB_D1, TARGTID);
    FAPI_INF("  .BCW59_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW59_ChB_D1, TARGTID);
    FAPI_INF("  .BCW5A_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW5A_ChB_D1, TARGTID);
    FAPI_INF("  .BCW5B_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW5B_ChB_D1, TARGTID);
    FAPI_INF("  .BCW5C_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW5C_ChB_D1, TARGTID);
    FAPI_INF("  .BCW5D_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW5D_ChB_D1, TARGTID);
    FAPI_INF("  .BCW5E_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW5E_ChB_D1, TARGTID);
    FAPI_INF("  .BCW5F_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW5F_ChB_D1, TARGTID);
    FAPI_INF("  .BCW60_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW60_ChB_D1, TARGTID);
    FAPI_INF("  .BCW61_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW61_ChB_D1, TARGTID);
    FAPI_INF("  .BCW62_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW62_ChB_D1, TARGTID);
    FAPI_INF("  .BCW63_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW63_ChB_D1, TARGTID);
    FAPI_INF("  .BCW64_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW64_ChB_D1, TARGTID);
    FAPI_INF("  .BCW65_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW65_ChB_D1, TARGTID);
    FAPI_INF("  .BCW66_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW66_ChB_D1, TARGTID);
    FAPI_INF("  .BCW67_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW67_ChB_D1, TARGTID);
    FAPI_INF("  .BCW68_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW68_ChB_D1, TARGTID);
    FAPI_INF("  .BCW69_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW69_ChB_D1, TARGTID);
    FAPI_INF("  .BCW6A_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW6A_ChB_D1, TARGTID);
    FAPI_INF("  .BCW6B_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW6B_ChB_D1, TARGTID);
    FAPI_INF("  .BCW6C_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW6C_ChB_D1, TARGTID);
    FAPI_INF("  .BCW6D_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW6D_ChB_D1, TARGTID);
    FAPI_INF("  .BCW6E_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW6E_ChB_D1, TARGTID);
    FAPI_INF("  .BCW6F_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW6F_ChB_D1, TARGTID);
    FAPI_INF("  .BCW70_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW70_ChB_D1, TARGTID);
    FAPI_INF("  .BCW71_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW71_ChB_D1, TARGTID);
    FAPI_INF("  .BCW72_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW72_ChB_D1, TARGTID);
    FAPI_INF("  .BCW73_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW73_ChB_D1, TARGTID);
    FAPI_INF("  .BCW74_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW74_ChB_D1, TARGTID);
    FAPI_INF("  .BCW75_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW75_ChB_D1, TARGTID);
    FAPI_INF("  .BCW76_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW76_ChB_D1, TARGTID);
    FAPI_INF("  .BCW77_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW77_ChB_D1, TARGTID);
    FAPI_INF("  .BCW78_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW78_ChB_D1, TARGTID);
    FAPI_INF("  .BCW79_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW79_ChB_D1, TARGTID);
    FAPI_INF("  .BCW7A_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW7A_ChB_D1, TARGTID);
    FAPI_INF("  .BCW7B_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW7B_ChB_D1, TARGTID);
    FAPI_INF("  .BCW7C_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW7C_ChB_D1, TARGTID);
    FAPI_INF("  .BCW7D_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW7D_ChB_D1, TARGTID);
    FAPI_INF("  .BCW7E_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW7E_ChB_D1, TARGTID);
    FAPI_INF("  .BCW7F_ChB_D1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.BCW7F_ChB_D1, TARGTID);
    FAPI_INF("  .VrefDqR0Nib0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR0Nib0, TARGTID);
    FAPI_INF("  .VrefDqR0Nib1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR0Nib1, TARGTID);
    FAPI_INF("  .VrefDqR0Nib2         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR0Nib2, TARGTID);
    FAPI_INF("  .VrefDqR0Nib3         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR0Nib3, TARGTID);
    FAPI_INF("  .VrefDqR0Nib4         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR0Nib4, TARGTID);
    FAPI_INF("  .VrefDqR0Nib5         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR0Nib5, TARGTID);
    FAPI_INF("  .VrefDqR0Nib6         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR0Nib6, TARGTID);
    FAPI_INF("  .VrefDqR0Nib7         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR0Nib7, TARGTID);
    FAPI_INF("  .VrefDqR0Nib8         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR0Nib8, TARGTID);
    FAPI_INF("  .VrefDqR0Nib9         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR0Nib9, TARGTID);
    FAPI_INF("  .VrefDqR0Nib10        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR0Nib10, TARGTID);
    FAPI_INF("  .VrefDqR0Nib11        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR0Nib11, TARGTID);
    FAPI_INF("  .VrefDqR0Nib12        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR0Nib12, TARGTID);
    FAPI_INF("  .VrefDqR0Nib13        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR0Nib13, TARGTID);
    FAPI_INF("  .VrefDqR0Nib14        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR0Nib14, TARGTID);
    FAPI_INF("  .VrefDqR0Nib15        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR0Nib15, TARGTID);
    FAPI_INF("  .VrefDqR0Nib16        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR0Nib16, TARGTID);
    FAPI_INF("  .VrefDqR0Nib17        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR0Nib17, TARGTID);
    FAPI_INF("  .VrefDqR0Nib18        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR0Nib18, TARGTID);
    FAPI_INF("  .VrefDqR0Nib19        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR0Nib19, TARGTID);
    FAPI_INF("  .VrefDqR1Nib0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR1Nib0, TARGTID);
    FAPI_INF("  .VrefDqR1Nib1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR1Nib1, TARGTID);
    FAPI_INF("  .VrefDqR1Nib2         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR1Nib2, TARGTID);
    FAPI_INF("  .VrefDqR1Nib3         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR1Nib3, TARGTID);
    FAPI_INF("  .VrefDqR1Nib4         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR1Nib4, TARGTID);
    FAPI_INF("  .VrefDqR1Nib5         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR1Nib5, TARGTID);
    FAPI_INF("  .VrefDqR1Nib6         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR1Nib6, TARGTID);
    FAPI_INF("  .VrefDqR1Nib7         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR1Nib7, TARGTID);
    FAPI_INF("  .VrefDqR1Nib8         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR1Nib8, TARGTID);
    FAPI_INF("  .VrefDqR1Nib9         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR1Nib9, TARGTID);
    FAPI_INF("  .VrefDqR1Nib10        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR1Nib10, TARGTID);
    FAPI_INF("  .VrefDqR1Nib11        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR1Nib11, TARGTID);
    FAPI_INF("  .VrefDqR1Nib12        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR1Nib12, TARGTID);
    FAPI_INF("  .VrefDqR1Nib13        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR1Nib13, TARGTID);
    FAPI_INF("  .VrefDqR1Nib14        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR1Nib14, TARGTID);
    FAPI_INF("  .VrefDqR1Nib15        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR1Nib15, TARGTID);
    FAPI_INF("  .VrefDqR1Nib16        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR1Nib16, TARGTID);
    FAPI_INF("  .VrefDqR1Nib17        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR1Nib17, TARGTID);
    FAPI_INF("  .VrefDqR1Nib18        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR1Nib18, TARGTID);
    FAPI_INF("  .VrefDqR1Nib19        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR1Nib19, TARGTID);
    FAPI_INF("  .VrefDqR2Nib0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR2Nib0, TARGTID);
    FAPI_INF("  .VrefDqR2Nib1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR2Nib1, TARGTID);
    FAPI_INF("  .VrefDqR2Nib2         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR2Nib2, TARGTID);
    FAPI_INF("  .VrefDqR2Nib3         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR2Nib3, TARGTID);
    FAPI_INF("  .VrefDqR2Nib4         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR2Nib4, TARGTID);
    FAPI_INF("  .VrefDqR2Nib5         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR2Nib5, TARGTID);
    FAPI_INF("  .VrefDqR2Nib6         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR2Nib6, TARGTID);
    FAPI_INF("  .VrefDqR2Nib7         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR2Nib7, TARGTID);
    FAPI_INF("  .VrefDqR2Nib8         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR2Nib8, TARGTID);
    FAPI_INF("  .VrefDqR2Nib9         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR2Nib9, TARGTID);
    FAPI_INF("  .VrefDqR2Nib10        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR2Nib10, TARGTID);
    FAPI_INF("  .VrefDqR2Nib11        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR2Nib11, TARGTID);
    FAPI_INF("  .VrefDqR2Nib12        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR2Nib12, TARGTID);
    FAPI_INF("  .VrefDqR2Nib13        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR2Nib13, TARGTID);
    FAPI_INF("  .VrefDqR2Nib14        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR2Nib14, TARGTID);
    FAPI_INF("  .VrefDqR2Nib15        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR2Nib15, TARGTID);
    FAPI_INF("  .VrefDqR2Nib16        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR2Nib16, TARGTID);
    FAPI_INF("  .VrefDqR2Nib17        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR2Nib17, TARGTID);
    FAPI_INF("  .VrefDqR2Nib18        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR2Nib18, TARGTID);
    FAPI_INF("  .VrefDqR2Nib19        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR2Nib19, TARGTID);
    FAPI_INF("  .VrefDqR3Nib0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR3Nib0, TARGTID);
    FAPI_INF("  .VrefDqR3Nib1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR3Nib1, TARGTID);
    FAPI_INF("  .VrefDqR3Nib2         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR3Nib2, TARGTID);
    FAPI_INF("  .VrefDqR3Nib3         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR3Nib3, TARGTID);
    FAPI_INF("  .VrefDqR3Nib4         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR3Nib4, TARGTID);
    FAPI_INF("  .VrefDqR3Nib5         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR3Nib5, TARGTID);
    FAPI_INF("  .VrefDqR3Nib6         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR3Nib6, TARGTID);
    FAPI_INF("  .VrefDqR3Nib7         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR3Nib7, TARGTID);
    FAPI_INF("  .VrefDqR3Nib8         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR3Nib8, TARGTID);
    FAPI_INF("  .VrefDqR3Nib9         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR3Nib9, TARGTID);
    FAPI_INF("  .VrefDqR3Nib10        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR3Nib10, TARGTID);
    FAPI_INF("  .VrefDqR3Nib11        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR3Nib11, TARGTID);
    FAPI_INF("  .VrefDqR3Nib12        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR3Nib12, TARGTID);
    FAPI_INF("  .VrefDqR3Nib13        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR3Nib13, TARGTID);
    FAPI_INF("  .VrefDqR3Nib14        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR3Nib14, TARGTID);
    FAPI_INF("  .VrefDqR3Nib15        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR3Nib15, TARGTID);
    FAPI_INF("  .VrefDqR3Nib16        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR3Nib16, TARGTID);
    FAPI_INF("  .VrefDqR3Nib17        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR3Nib17, TARGTID);
    FAPI_INF("  .VrefDqR3Nib18        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR3Nib18, TARGTID);
    FAPI_INF("  .VrefDqR3Nib19        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefDqR3Nib19, TARGTID);
    FAPI_INF("  .MR3R0Nib0            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R0Nib0, TARGTID);
    FAPI_INF("  .MR3R0Nib1            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R0Nib1, TARGTID);
    FAPI_INF("  .MR3R0Nib2            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R0Nib2, TARGTID);
    FAPI_INF("  .MR3R0Nib3            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R0Nib3, TARGTID);
    FAPI_INF("  .MR3R0Nib4            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R0Nib4, TARGTID);
    FAPI_INF("  .MR3R0Nib5            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R0Nib5, TARGTID);
    FAPI_INF("  .MR3R0Nib6            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R0Nib6, TARGTID);
    FAPI_INF("  .MR3R0Nib7            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R0Nib7, TARGTID);
    FAPI_INF("  .MR3R0Nib8            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R0Nib8, TARGTID);
    FAPI_INF("  .MR3R0Nib9            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R0Nib9, TARGTID);
    FAPI_INF("  .MR3R0Nib10           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R0Nib10, TARGTID);
    FAPI_INF("  .MR3R0Nib11           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R0Nib11, TARGTID);
    FAPI_INF("  .MR3R0Nib12           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R0Nib12, TARGTID);
    FAPI_INF("  .MR3R0Nib13           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R0Nib13, TARGTID);
    FAPI_INF("  .MR3R0Nib14           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R0Nib14, TARGTID);
    FAPI_INF("  .MR3R0Nib15           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R0Nib15, TARGTID);
    FAPI_INF("  .MR3R0Nib16           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R0Nib16, TARGTID);
    FAPI_INF("  .MR3R0Nib17           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R0Nib17, TARGTID);
    FAPI_INF("  .MR3R0Nib18           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R0Nib18, TARGTID);
    FAPI_INF("  .MR3R0Nib19           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R0Nib19, TARGTID);
    FAPI_INF("  .MR3R1Nib0            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R1Nib0, TARGTID);
    FAPI_INF("  .MR3R1Nib1            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R1Nib1, TARGTID);
    FAPI_INF("  .MR3R1Nib2            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R1Nib2, TARGTID);
    FAPI_INF("  .MR3R1Nib3            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R1Nib3, TARGTID);
    FAPI_INF("  .MR3R1Nib4            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R1Nib4, TARGTID);
    FAPI_INF("  .MR3R1Nib5            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R1Nib5, TARGTID);
    FAPI_INF("  .MR3R1Nib6            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R1Nib6, TARGTID);
    FAPI_INF("  .MR3R1Nib7            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R1Nib7, TARGTID);
    FAPI_INF("  .MR3R1Nib8            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R1Nib8, TARGTID);
    FAPI_INF("  .MR3R1Nib9            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R1Nib9, TARGTID);
    FAPI_INF("  .MR3R1Nib10           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R1Nib10, TARGTID);
    FAPI_INF("  .MR3R1Nib11           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R1Nib11, TARGTID);
    FAPI_INF("  .MR3R1Nib12           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R1Nib12, TARGTID);
    FAPI_INF("  .MR3R1Nib13           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R1Nib13, TARGTID);
    FAPI_INF("  .MR3R1Nib14           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R1Nib14, TARGTID);
    FAPI_INF("  .MR3R1Nib15           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R1Nib15, TARGTID);
    FAPI_INF("  .MR3R1Nib16           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R1Nib16, TARGTID);
    FAPI_INF("  .MR3R1Nib17           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R1Nib17, TARGTID);
    FAPI_INF("  .MR3R1Nib18           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R1Nib18, TARGTID);
    FAPI_INF("  .MR3R1Nib19           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R1Nib19, TARGTID);
    FAPI_INF("  .MR3R2Nib0            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R2Nib0, TARGTID);
    FAPI_INF("  .MR3R2Nib1            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R2Nib1, TARGTID);
    FAPI_INF("  .MR3R2Nib2            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R2Nib2, TARGTID);
    FAPI_INF("  .MR3R2Nib3            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R2Nib3, TARGTID);
    FAPI_INF("  .MR3R2Nib4            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R2Nib4, TARGTID);
    FAPI_INF("  .MR3R2Nib5            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R2Nib5, TARGTID);
    FAPI_INF("  .MR3R2Nib6            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R2Nib6, TARGTID);
    FAPI_INF("  .MR3R2Nib7            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R2Nib7, TARGTID);
    FAPI_INF("  .MR3R2Nib8            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R2Nib8, TARGTID);
    FAPI_INF("  .MR3R2Nib9            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R2Nib9, TARGTID);
    FAPI_INF("  .MR3R2Nib10           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R2Nib10, TARGTID);
    FAPI_INF("  .MR3R2Nib11           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R2Nib11, TARGTID);
    FAPI_INF("  .MR3R2Nib12           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R2Nib12, TARGTID);
    FAPI_INF("  .MR3R2Nib13           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R2Nib13, TARGTID);
    FAPI_INF("  .MR3R2Nib14           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R2Nib14, TARGTID);
    FAPI_INF("  .MR3R2Nib15           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R2Nib15, TARGTID);
    FAPI_INF("  .MR3R2Nib16           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R2Nib16, TARGTID);
    FAPI_INF("  .MR3R2Nib17           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R2Nib17, TARGTID);
    FAPI_INF("  .MR3R2Nib18           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R2Nib18, TARGTID);
    FAPI_INF("  .MR3R2Nib19           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R2Nib19, TARGTID);
    FAPI_INF("  .MR3R3Nib0            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R3Nib0, TARGTID);
    FAPI_INF("  .MR3R3Nib1            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R3Nib1, TARGTID);
    FAPI_INF("  .MR3R3Nib2            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R3Nib2, TARGTID);
    FAPI_INF("  .MR3R3Nib3            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R3Nib3, TARGTID);
    FAPI_INF("  .MR3R3Nib4            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R3Nib4, TARGTID);
    FAPI_INF("  .MR3R3Nib5            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R3Nib5, TARGTID);
    FAPI_INF("  .MR3R3Nib6            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R3Nib6, TARGTID);
    FAPI_INF("  .MR3R3Nib7            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R3Nib7, TARGTID);
    FAPI_INF("  .MR3R3Nib8            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R3Nib8, TARGTID);
    FAPI_INF("  .MR3R3Nib9            = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R3Nib9, TARGTID);
    FAPI_INF("  .MR3R3Nib10           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R3Nib10, TARGTID);
    FAPI_INF("  .MR3R3Nib11           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R3Nib11, TARGTID);
    FAPI_INF("  .MR3R3Nib12           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R3Nib12, TARGTID);
    FAPI_INF("  .MR3R3Nib13           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R3Nib13, TARGTID);
    FAPI_INF("  .MR3R3Nib14           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R3Nib14, TARGTID);
    FAPI_INF("  .MR3R3Nib15           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R3Nib15, TARGTID);
    FAPI_INF("  .MR3R3Nib16           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R3Nib16, TARGTID);
    FAPI_INF("  .MR3R3Nib17           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R3Nib17, TARGTID);
    FAPI_INF("  .MR3R3Nib18           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R3Nib18, TARGTID);
    FAPI_INF("  .MR3R3Nib19           = 0x%02x; // " TARGTIDFORMAT, i_msg_block.MR3R3Nib19, TARGTID);
    FAPI_INF("  .VrefCSR0Nib0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR0Nib0, TARGTID);
    FAPI_INF("  .VrefCSR0Nib1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR0Nib1, TARGTID);
    FAPI_INF("  .VrefCSR0Nib2         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR0Nib2, TARGTID);
    FAPI_INF("  .VrefCSR0Nib3         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR0Nib3, TARGTID);
    FAPI_INF("  .VrefCSR0Nib4         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR0Nib4, TARGTID);
    FAPI_INF("  .VrefCSR0Nib5         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR0Nib5, TARGTID);
    FAPI_INF("  .VrefCSR0Nib6         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR0Nib6, TARGTID);
    FAPI_INF("  .VrefCSR0Nib7         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR0Nib7, TARGTID);
    FAPI_INF("  .VrefCSR0Nib8         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR0Nib8, TARGTID);
    FAPI_INF("  .VrefCSR0Nib9         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR0Nib9, TARGTID);
    FAPI_INF("  .VrefCSR0Nib10        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR0Nib10, TARGTID);
    FAPI_INF("  .VrefCSR0Nib11        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR0Nib11, TARGTID);
    FAPI_INF("  .VrefCSR0Nib12        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR0Nib12, TARGTID);
    FAPI_INF("  .VrefCSR0Nib13        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR0Nib13, TARGTID);
    FAPI_INF("  .VrefCSR0Nib14        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR0Nib14, TARGTID);
    FAPI_INF("  .VrefCSR0Nib15        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR0Nib15, TARGTID);
    FAPI_INF("  .VrefCSR0Nib16        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR0Nib16, TARGTID);
    FAPI_INF("  .VrefCSR0Nib17        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR0Nib17, TARGTID);
    FAPI_INF("  .VrefCSR0Nib18        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR0Nib18, TARGTID);
    FAPI_INF("  .VrefCSR0Nib19        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR0Nib19, TARGTID);
    FAPI_INF("  .VrefCSR1Nib0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR1Nib0, TARGTID);
    FAPI_INF("  .VrefCSR1Nib1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR1Nib1, TARGTID);
    FAPI_INF("  .VrefCSR1Nib2         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR1Nib2, TARGTID);
    FAPI_INF("  .VrefCSR1Nib3         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR1Nib3, TARGTID);
    FAPI_INF("  .VrefCSR1Nib4         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR1Nib4, TARGTID);
    FAPI_INF("  .VrefCSR1Nib5         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR1Nib5, TARGTID);
    FAPI_INF("  .VrefCSR1Nib6         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR1Nib6, TARGTID);
    FAPI_INF("  .VrefCSR1Nib7         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR1Nib7, TARGTID);
    FAPI_INF("  .VrefCSR1Nib8         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR1Nib8, TARGTID);
    FAPI_INF("  .VrefCSR1Nib9         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR1Nib9, TARGTID);
    FAPI_INF("  .VrefCSR1Nib10        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR1Nib10, TARGTID);
    FAPI_INF("  .VrefCSR1Nib11        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR1Nib11, TARGTID);
    FAPI_INF("  .VrefCSR1Nib12        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR1Nib12, TARGTID);
    FAPI_INF("  .VrefCSR1Nib13        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR1Nib13, TARGTID);
    FAPI_INF("  .VrefCSR1Nib14        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR1Nib14, TARGTID);
    FAPI_INF("  .VrefCSR1Nib15        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR1Nib15, TARGTID);
    FAPI_INF("  .VrefCSR1Nib16        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR1Nib16, TARGTID);
    FAPI_INF("  .VrefCSR1Nib17        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR1Nib17, TARGTID);
    FAPI_INF("  .VrefCSR1Nib18        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR1Nib18, TARGTID);
    FAPI_INF("  .VrefCSR1Nib19        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR1Nib19, TARGTID);
    FAPI_INF("  .VrefCSR2Nib0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR2Nib0, TARGTID);
    FAPI_INF("  .VrefCSR2Nib1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR2Nib1, TARGTID);
    FAPI_INF("  .VrefCSR2Nib2         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR2Nib2, TARGTID);
    FAPI_INF("  .VrefCSR2Nib3         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR2Nib3, TARGTID);
    FAPI_INF("  .VrefCSR2Nib4         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR2Nib4, TARGTID);
    FAPI_INF("  .VrefCSR2Nib5         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR2Nib5, TARGTID);
    FAPI_INF("  .VrefCSR2Nib6         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR2Nib6, TARGTID);
    FAPI_INF("  .VrefCSR2Nib7         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR2Nib7, TARGTID);
    FAPI_INF("  .VrefCSR2Nib8         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR2Nib8, TARGTID);
    FAPI_INF("  .VrefCSR2Nib9         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR2Nib9, TARGTID);
    FAPI_INF("  .VrefCSR2Nib10        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR2Nib10, TARGTID);
    FAPI_INF("  .VrefCSR2Nib11        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR2Nib11, TARGTID);
    FAPI_INF("  .VrefCSR2Nib12        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR2Nib12, TARGTID);
    FAPI_INF("  .VrefCSR2Nib13        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR2Nib13, TARGTID);
    FAPI_INF("  .VrefCSR2Nib14        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR2Nib14, TARGTID);
    FAPI_INF("  .VrefCSR2Nib15        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR2Nib15, TARGTID);
    FAPI_INF("  .VrefCSR2Nib16        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR2Nib16, TARGTID);
    FAPI_INF("  .VrefCSR2Nib17        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR2Nib17, TARGTID);
    FAPI_INF("  .VrefCSR2Nib18        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR2Nib18, TARGTID);
    FAPI_INF("  .VrefCSR2Nib19        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR2Nib19, TARGTID);
    FAPI_INF("  .VrefCSR3Nib0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR3Nib0, TARGTID);
    FAPI_INF("  .VrefCSR3Nib1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR3Nib1, TARGTID);
    FAPI_INF("  .VrefCSR3Nib2         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR3Nib2, TARGTID);
    FAPI_INF("  .VrefCSR3Nib3         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR3Nib3, TARGTID);
    FAPI_INF("  .VrefCSR3Nib4         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR3Nib4, TARGTID);
    FAPI_INF("  .VrefCSR3Nib5         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR3Nib5, TARGTID);
    FAPI_INF("  .VrefCSR3Nib6         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR3Nib6, TARGTID);
    FAPI_INF("  .VrefCSR3Nib7         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR3Nib7, TARGTID);
    FAPI_INF("  .VrefCSR3Nib8         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR3Nib8, TARGTID);
    FAPI_INF("  .VrefCSR3Nib9         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR3Nib9, TARGTID);
    FAPI_INF("  .VrefCSR3Nib10        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR3Nib10, TARGTID);
    FAPI_INF("  .VrefCSR3Nib11        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR3Nib11, TARGTID);
    FAPI_INF("  .VrefCSR3Nib12        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR3Nib12, TARGTID);
    FAPI_INF("  .VrefCSR3Nib13        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR3Nib13, TARGTID);
    FAPI_INF("  .VrefCSR3Nib14        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR3Nib14, TARGTID);
    FAPI_INF("  .VrefCSR3Nib15        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR3Nib15, TARGTID);
    FAPI_INF("  .VrefCSR3Nib16        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR3Nib16, TARGTID);
    FAPI_INF("  .VrefCSR3Nib17        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR3Nib17, TARGTID);
    FAPI_INF("  .VrefCSR3Nib18        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR3Nib18, TARGTID);
    FAPI_INF("  .VrefCSR3Nib19        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCSR3Nib19, TARGTID);
    FAPI_INF("  .VrefCAR0Nib0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR0Nib0, TARGTID);
    FAPI_INF("  .VrefCAR0Nib1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR0Nib1, TARGTID);
    FAPI_INF("  .VrefCAR0Nib2         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR0Nib2, TARGTID);
    FAPI_INF("  .VrefCAR0Nib3         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR0Nib3, TARGTID);
    FAPI_INF("  .VrefCAR0Nib4         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR0Nib4, TARGTID);
    FAPI_INF("  .VrefCAR0Nib5         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR0Nib5, TARGTID);
    FAPI_INF("  .VrefCAR0Nib6         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR0Nib6, TARGTID);
    FAPI_INF("  .VrefCAR0Nib7         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR0Nib7, TARGTID);
    FAPI_INF("  .VrefCAR0Nib8         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR0Nib8, TARGTID);
    FAPI_INF("  .VrefCAR0Nib9         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR0Nib9, TARGTID);
    FAPI_INF("  .VrefCAR0Nib10        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR0Nib10, TARGTID);
    FAPI_INF("  .VrefCAR0Nib11        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR0Nib11, TARGTID);
    FAPI_INF("  .VrefCAR0Nib12        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR0Nib12, TARGTID);
    FAPI_INF("  .VrefCAR0Nib13        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR0Nib13, TARGTID);
    FAPI_INF("  .VrefCAR0Nib14        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR0Nib14, TARGTID);
    FAPI_INF("  .VrefCAR0Nib15        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR0Nib15, TARGTID);
    FAPI_INF("  .VrefCAR0Nib16        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR0Nib16, TARGTID);
    FAPI_INF("  .VrefCAR0Nib17        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR0Nib17, TARGTID);
    FAPI_INF("  .VrefCAR0Nib18        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR0Nib18, TARGTID);
    FAPI_INF("  .VrefCAR0Nib19        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR0Nib19, TARGTID);
    FAPI_INF("  .VrefCAR1Nib0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR1Nib0, TARGTID);
    FAPI_INF("  .VrefCAR1Nib1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR1Nib1, TARGTID);
    FAPI_INF("  .VrefCAR1Nib2         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR1Nib2, TARGTID);
    FAPI_INF("  .VrefCAR1Nib3         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR1Nib3, TARGTID);
    FAPI_INF("  .VrefCAR1Nib4         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR1Nib4, TARGTID);
    FAPI_INF("  .VrefCAR1Nib5         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR1Nib5, TARGTID);
    FAPI_INF("  .VrefCAR1Nib6         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR1Nib6, TARGTID);
    FAPI_INF("  .VrefCAR1Nib7         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR1Nib7, TARGTID);
    FAPI_INF("  .VrefCAR1Nib8         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR1Nib8, TARGTID);
    FAPI_INF("  .VrefCAR1Nib9         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR1Nib9, TARGTID);
    FAPI_INF("  .VrefCAR1Nib10        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR1Nib10, TARGTID);
    FAPI_INF("  .VrefCAR1Nib11        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR1Nib11, TARGTID);
    FAPI_INF("  .VrefCAR1Nib12        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR1Nib12, TARGTID);
    FAPI_INF("  .VrefCAR1Nib13        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR1Nib13, TARGTID);
    FAPI_INF("  .VrefCAR1Nib14        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR1Nib14, TARGTID);
    FAPI_INF("  .VrefCAR1Nib15        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR1Nib15, TARGTID);
    FAPI_INF("  .VrefCAR1Nib16        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR1Nib16, TARGTID);
    FAPI_INF("  .VrefCAR1Nib17        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR1Nib17, TARGTID);
    FAPI_INF("  .VrefCAR1Nib18        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR1Nib18, TARGTID);
    FAPI_INF("  .VrefCAR1Nib19        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR1Nib19, TARGTID);
    FAPI_INF("  .VrefCAR2Nib0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR2Nib0, TARGTID);
    FAPI_INF("  .VrefCAR2Nib1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR2Nib1, TARGTID);
    FAPI_INF("  .VrefCAR2Nib2         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR2Nib2, TARGTID);
    FAPI_INF("  .VrefCAR2Nib3         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR2Nib3, TARGTID);
    FAPI_INF("  .VrefCAR2Nib4         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR2Nib4, TARGTID);
    FAPI_INF("  .VrefCAR2Nib5         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR2Nib5, TARGTID);
    FAPI_INF("  .VrefCAR2Nib6         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR2Nib6, TARGTID);
    FAPI_INF("  .VrefCAR2Nib7         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR2Nib7, TARGTID);
    FAPI_INF("  .VrefCAR2Nib8         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR2Nib8, TARGTID);
    FAPI_INF("  .VrefCAR2Nib9         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR2Nib9, TARGTID);
    FAPI_INF("  .VrefCAR2Nib10        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR2Nib10, TARGTID);
    FAPI_INF("  .VrefCAR2Nib11        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR2Nib11, TARGTID);
    FAPI_INF("  .VrefCAR2Nib12        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR2Nib12, TARGTID);
    FAPI_INF("  .VrefCAR2Nib13        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR2Nib13, TARGTID);
    FAPI_INF("  .VrefCAR2Nib14        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR2Nib14, TARGTID);
    FAPI_INF("  .VrefCAR2Nib15        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR2Nib15, TARGTID);
    FAPI_INF("  .VrefCAR2Nib16        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR2Nib16, TARGTID);
    FAPI_INF("  .VrefCAR2Nib17        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR2Nib17, TARGTID);
    FAPI_INF("  .VrefCAR2Nib18        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR2Nib18, TARGTID);
    FAPI_INF("  .VrefCAR2Nib19        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR2Nib19, TARGTID);
    FAPI_INF("  .VrefCAR3Nib0         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR3Nib0, TARGTID);
    FAPI_INF("  .VrefCAR3Nib1         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR3Nib1, TARGTID);
    FAPI_INF("  .VrefCAR3Nib2         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR3Nib2, TARGTID);
    FAPI_INF("  .VrefCAR3Nib3         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR3Nib3, TARGTID);
    FAPI_INF("  .VrefCAR3Nib4         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR3Nib4, TARGTID);
    FAPI_INF("  .VrefCAR3Nib5         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR3Nib5, TARGTID);
    FAPI_INF("  .VrefCAR3Nib6         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR3Nib6, TARGTID);
    FAPI_INF("  .VrefCAR3Nib7         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR3Nib7, TARGTID);
    FAPI_INF("  .VrefCAR3Nib8         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR3Nib8, TARGTID);
    FAPI_INF("  .VrefCAR3Nib9         = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR3Nib9, TARGTID);
    FAPI_INF("  .VrefCAR3Nib10        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR3Nib10, TARGTID);
    FAPI_INF("  .VrefCAR3Nib11        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR3Nib11, TARGTID);
    FAPI_INF("  .VrefCAR3Nib12        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR3Nib12, TARGTID);
    FAPI_INF("  .VrefCAR3Nib13        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR3Nib13, TARGTID);
    FAPI_INF("  .VrefCAR3Nib14        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR3Nib14, TARGTID);
    FAPI_INF("  .VrefCAR3Nib15        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR3Nib15, TARGTID);
    FAPI_INF("  .VrefCAR3Nib16        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR3Nib16, TARGTID);
    FAPI_INF("  .VrefCAR3Nib17        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR3Nib17, TARGTID);
    FAPI_INF("  .VrefCAR3Nib18        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR3Nib18, TARGTID);
    FAPI_INF("  .VrefCAR3Nib19        = 0x%02x; // " TARGTIDFORMAT, i_msg_block.VrefCAR3Nib19, TARGTID);
    FAPI_INF("  .DisabledDB0LaneR0    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB0LaneR0, TARGTID);
    FAPI_INF("  .DisabledDB1LaneR0    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB1LaneR0, TARGTID);
    FAPI_INF("  .DisabledDB2LaneR0    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB2LaneR0, TARGTID);
    FAPI_INF("  .DisabledDB3LaneR0    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB3LaneR0, TARGTID);
    FAPI_INF("  .DisabledDB4LaneR0    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB4LaneR0, TARGTID);
    FAPI_INF("  .DisabledDB5LaneR0    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB5LaneR0, TARGTID);
    FAPI_INF("  .DisabledDB6LaneR0    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB6LaneR0, TARGTID);
    FAPI_INF("  .DisabledDB7LaneR0    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB7LaneR0, TARGTID);
    FAPI_INF("  .DisabledDB8LaneR0    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB8LaneR0, TARGTID);
    FAPI_INF("  .DisabledDB9LaneR0    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB9LaneR0, TARGTID);
    FAPI_INF("  .DisabledDB0LaneR1    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB0LaneR1, TARGTID);
    FAPI_INF("  .DisabledDB1LaneR1    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB1LaneR1, TARGTID);
    FAPI_INF("  .DisabledDB2LaneR1    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB2LaneR1, TARGTID);
    FAPI_INF("  .DisabledDB3LaneR1    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB3LaneR1, TARGTID);
    FAPI_INF("  .DisabledDB4LaneR1    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB4LaneR1, TARGTID);
    FAPI_INF("  .DisabledDB5LaneR1    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB5LaneR1, TARGTID);
    FAPI_INF("  .DisabledDB6LaneR1    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB6LaneR1, TARGTID);
    FAPI_INF("  .DisabledDB7LaneR1    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB7LaneR1, TARGTID);
    FAPI_INF("  .DisabledDB8LaneR1    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB8LaneR1, TARGTID);
    FAPI_INF("  .DisabledDB9LaneR1    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB9LaneR1, TARGTID);
    FAPI_INF("  .DisabledDB0LaneR2    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB0LaneR2, TARGTID);
    FAPI_INF("  .DisabledDB1LaneR2    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB1LaneR2, TARGTID);
    FAPI_INF("  .DisabledDB2LaneR2    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB2LaneR2, TARGTID);
    FAPI_INF("  .DisabledDB3LaneR2    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB3LaneR2, TARGTID);
    FAPI_INF("  .DisabledDB4LaneR2    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB4LaneR2, TARGTID);
    FAPI_INF("  .DisabledDB5LaneR2    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB5LaneR2, TARGTID);
    FAPI_INF("  .DisabledDB6LaneR2    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB6LaneR2, TARGTID);
    FAPI_INF("  .DisabledDB7LaneR2    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB7LaneR2, TARGTID);
    FAPI_INF("  .DisabledDB8LaneR2    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB8LaneR2, TARGTID);
    FAPI_INF("  .DisabledDB9LaneR2    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB9LaneR2, TARGTID);
    FAPI_INF("  .DisabledDB0LaneR3    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB0LaneR3, TARGTID);
    FAPI_INF("  .DisabledDB1LaneR3    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB1LaneR3, TARGTID);
    FAPI_INF("  .DisabledDB2LaneR3    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB2LaneR3, TARGTID);
    FAPI_INF("  .DisabledDB3LaneR3    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB3LaneR3, TARGTID);
    FAPI_INF("  .DisabledDB4LaneR3    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB4LaneR3, TARGTID);
    FAPI_INF("  .DisabledDB5LaneR3    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB5LaneR3, TARGTID);
    FAPI_INF("  .DisabledDB6LaneR3    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB6LaneR3, TARGTID);
    FAPI_INF("  .DisabledDB7LaneR3    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB7LaneR3, TARGTID);
    FAPI_INF("  .DisabledDB8LaneR3    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB8LaneR3, TARGTID);
    FAPI_INF("  .DisabledDB9LaneR3    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.DisabledDB9LaneR3, TARGTID);
    FAPI_INF("  .QCS_Dly_Margin_A0    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.QCS_Dly_Margin_A0, TARGTID);
    FAPI_INF("  .QCA_Dly_Margin_A0    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.QCA_Dly_Margin_A0, TARGTID);
    FAPI_INF("  .QCS_Dly_Margin_A1    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.QCS_Dly_Margin_A1, TARGTID);
    FAPI_INF("  .QCA_Dly_Margin_A1    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.QCA_Dly_Margin_A1, TARGTID);
    FAPI_INF("  .QCS_Dly_Margin_A2    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.QCS_Dly_Margin_A2, TARGTID);
    FAPI_INF("  .QCA_Dly_Margin_A2    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.QCA_Dly_Margin_A2, TARGTID);
    FAPI_INF("  .QCS_Dly_Margin_A3    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.QCS_Dly_Margin_A3, TARGTID);
    FAPI_INF("  .QCA_Dly_Margin_A3    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.QCA_Dly_Margin_A3, TARGTID);
    FAPI_INF("  .QCS_Dly_Margin_B0    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.QCS_Dly_Margin_B0, TARGTID);
    FAPI_INF("  .QCA_Dly_Margin_B0    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.QCA_Dly_Margin_B0, TARGTID);
    FAPI_INF("  .QCS_Dly_Margin_B1    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.QCS_Dly_Margin_B1, TARGTID);
    FAPI_INF("  .QCA_Dly_Margin_B1    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.QCA_Dly_Margin_B1, TARGTID);
    FAPI_INF("  .QCS_Dly_Margin_B2    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.QCS_Dly_Margin_B2, TARGTID);
    FAPI_INF("  .QCA_Dly_Margin_B2    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.QCA_Dly_Margin_B2, TARGTID);
    FAPI_INF("  .QCS_Dly_Margin_B3    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.QCS_Dly_Margin_B3, TARGTID);
    FAPI_INF("  .QCA_Dly_Margin_B3    = 0x%02x; // " TARGTIDFORMAT, i_msg_block.QCA_Dly_Margin_B3, TARGTID);
    FAPI_INF("  .PmuInternalRev0      = 0x%04x; // " TARGTIDFORMAT, i_msg_block.PmuInternalRev0, TARGTID);
    FAPI_INF("  .PmuInternalRev1      = 0x%04x; // " TARGTIDFORMAT, i_msg_block.PmuInternalRev1, TARGTID);
    FAPI_INF("} // _PMU_SMB_DDR5_1D_t " TARGTIDFORMAT, TARGTID);

}

} // namespace phy
} // namespace ody
} // namespace mss
