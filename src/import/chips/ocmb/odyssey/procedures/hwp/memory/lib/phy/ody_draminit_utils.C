/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/phy/ody_draminit_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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

#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <generic/memory/lib/utils/poll.H>
#include <generic/memory/lib/utils/mss_bad_bits.H>
#include <ody_scom_mp_apbonly0.H>
#include <ody_scom_mp_mastr_b0.H>
#include <ody_scom_mp_drtub0.H>
#include <mss_odyssey_attribute_getters.H>
#include <mss_odyssey_attribute_setters.H>
#include <lib/phy/ody_draminit_utils.H>
#include <lib/phy/ody_phy_utils.H>
#include <ody_consts.H>
#include <generic/memory/lib/utils/num.H>
#include <lib/dimm/ody_rank.H>

#include <generic/memory/lib/dimm/ddr5/ddr5_mr3.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr10.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr11.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr12.H>

#ifndef __PPE__
    // Included for progress / time left reporting (Cronus only)
    #include <ctime>
#endif

namespace mss
{
namespace ody
{
namespace phy
{

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
                                       20000,
                                       i_mailbox_poll_count);

    // Poll for getting 0 at UctWriteProtShadow.
    bool l_poll_return = mss::poll(i_target, l_poll_params, [&i_target]()->bool
    {
        fapi2::buffer<uint64_t> l_data = 0xFF;
        FAPI_TRY(fapi2::getScom(i_target, scomt::mp::DWC_DDRPHYA_APBONLY0_UCTSHADOWREGS, l_data));
        return (l_data.getBit<scomt::mp::DWC_DDRPHYA_APBONLY0_UCTSHADOWREGS_UCTWRITEPROTSHADOW>() == MESSAGE_AVAILABLE);

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
    FAPI_INF(TARGTIDFORMAT " received mail message", TARGTID);

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
        o_mail     = (l_data << 16 ) | o_mail;
    }

    // Writing 0 to DctWriteProt.
    FAPI_TRY(fapi2::putScom(i_target, scomt::mp::DWC_DDRPHYA_APBONLY0_DCTWRITEPROT, RECEPTION_ACK));

    FAPI_INF(TARGTIDFORMAT " o_mail message: 0x%016x", TARGTID, o_mail);

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
                                       20000,
                                       i_mailbox_poll_count);

    // Poll for getting 0 at UctWriteProtShadow.
    l_poll_return = mss::poll(i_target, l_poll_params, [i_target]()->bool
    {
        fapi2::buffer<uint64_t> l_data;
        FAPI_TRY(fapi2::getScom(i_target, scomt::mp::DWC_DDRPHYA_APBONLY0_UCTSHADOWREGS, l_data));
        return (l_data.getBit<scomt::mp::DWC_DDRPHYA_APBONLY0_UCTSHADOWREGS_UCTWRITEPROTSHADOW>() == ACK_MESSAGE);

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

    FAPI_INF(TARGTIDFORMAT " mail acknowledged", TARGTID);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Polls the mail until completion message is received
/// @param[in] i_target the target on which to operate
/// @param[in] i_training_poll_count poll count for getting mail.
/// @param[out] o_status final mail message from training, PASS/FAIL status if it completed
/// @param[out] o_log_data hwp_data_ostream of streaming log
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode poll_for_completion(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                      const uint64_t i_training_poll_count,
                                      uint64_t& o_status,
                                      fapi2::hwp_data_ostream& o_log_data )
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
    l_poll_return = mss::poll(i_target, l_poll_params, [&i_target, &l_mailbox_poll_count, &l_mail, &o_log_data]()->bool
    {
        uint8_t l_mode = MAJOR_MSG_MODE; // 16 bit mode to read major message.
        bool l_loop_end = false;
        // check the message content.
        FAPI_TRY(mss::ody::phy::get_mail(i_target, l_mode, l_mailbox_poll_count, l_mail));

        // Process and decode 'major' messages, and handle SMBus and streaming message protocol if necessary
        FAPI_TRY(check_for_completion_and_decode(i_target, l_mail, o_log_data, l_loop_end));

        if (l_loop_end)
        {
            return(l_loop_end);
        }
        FAPI_TRY(fapi2::delay(mss::DELAY_1MS, 200));

    fapi_try_exit:
        FAPI_ERR("mss::poll() hit an error in mss::getScom");
        return false;
    });
    // following FAPI_TRY to preserve the scom failure in lambda.
    FAPI_TRY(fapi2::current_err);

    FAPI_ASSERT(l_poll_return,
                fapi2::ODY_DRAMINIT_TRAINING_TIMEOUT().
                set_PORT_TARGET(i_target).
                set_mail(l_mail),
                TARGTIDFORMAT " poll for draminit training completion timed out", TARGTID);

    o_status = l_mail;

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Checks the completion condition for training and decodes respective message
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_mail mail content to check for completion
/// @param[out] o_log_data hwp_data_ostream of streaming log
/// @param[out] o_loop_end flags that completion was detected, ending polling loop and skipping delay.
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode check_for_completion_and_decode(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const fapi2::buffer<uint64_t>& i_mail,
        fapi2::hwp_data_ostream& o_log_data,
        bool& o_loop_end)
{
    o_loop_end = false;

    switch(i_mail)
    {
        case SUCCESSFUL_COMPLETION:
            o_loop_end = true;
            FAPI_INF(TARGTIDFORMAT" Successful completion, code: 0x%016x", TARGTID, i_mail);
            break;

        case FAILED_COMPLETION:
            o_loop_end = true;
            FAPI_INF(TARGTIDFORMAT" Failed completion, code: 0x%016x", TARGTID, i_mail);
            break;

        case END_OF_INITILIAZATION:
            FAPI_INF(TARGTIDFORMAT" End of initiliazation, code: 0x%016x", TARGTID, i_mail);
            break;

        case END_OF_FINE_WRITE_LEVELING:
            FAPI_INF(TARGTIDFORMAT" End of fine write training, code: 0x%016x", TARGTID, i_mail);
            break;

        case END_OF_READ_ENABLE_TRAINING:
            FAPI_INF(TARGTIDFORMAT" End of read enable training, code: 0x%016x", TARGTID, i_mail);
            break;

        case END_OF_RD_DLY_CNTR_OPT:
            FAPI_INF(TARGTIDFORMAT" End of read delay center optimization, code: 0x%016x", TARGTID, i_mail);
            break;

        case END_OF_WR_DLY_CNTR_OPT:
            FAPI_INF(TARGTIDFORMAT" End of write delay center optimization, code: 0x%016x", TARGTID, i_mail);
            break;

        case END_OF_2D_RD_DLY_V_CNTR_OPT:
            FAPI_INF(TARGTIDFORMAT" End of 2D read delay /voltage center optimization, code: 0x%016x", TARGTID, i_mail);
            break;

        case END_OF_2D_WR_DLY_V_CNTR_OPT:
            FAPI_INF(TARGTIDFORMAT" End of 2D write delay /voltage center optimization, code: 0x%016x", TARGTID, i_mail);
            break;

        case END_OF_MAX_RD_LAT_TRAINING:
            FAPI_INF(TARGTIDFORMAT" End of max read latency training, code: 0x%016x", TARGTID, i_mail);
            break;

        case END_OF_RD_DQ_DSKEW_TRAINING:
            FAPI_INF(TARGTIDFORMAT" End of read DQ deskew training, code: 0x%016x", TARGTID, i_mail);
            break;

        case TRAINING_STAGE_RESERVED:
            FAPI_INF(TARGTIDFORMAT" Reserved, code: 0x%016x", TARGTID, i_mail);
            break;

        case END_OF_CS_CA_TRAINING:
            FAPI_INF(TARGTIDFORMAT" End of CS/CA training, code: 0x%016x", TARGTID, i_mail);
            break;

        case END_OF_RCD_QCS_QCA_TRAINING:
            FAPI_INF(TARGTIDFORMAT" End of RCD QCS/QCA training, code: 0x%016x", TARGTID, i_mail);
            break;

        case END_OF_LRDIMM_MREP_TRAINING:
            FAPI_INF(TARGTIDFORMAT" End of LRDIMM MREP training, code: 0x%016x", TARGTID, i_mail);
            break;

        case END_OF_LRDIMM_DWL_TRAINING:
            FAPI_INF(TARGTIDFORMAT" End of LRDIMM DWL training, code: 0x%016x", TARGTID, i_mail);
            break;

        case END_OF_LRDIMM_MRD_TRAINING:
            FAPI_INF(TARGTIDFORMAT" End of LRDIMM MRD training, code: 0x%016x", TARGTID, i_mail);
            break;

        case END_OF_LRDIMM_MWD_TRAINING:
            FAPI_INF(TARGTIDFORMAT" End of LRDIMM MWD training, code: 0x%016x", TARGTID, i_mail);
            break;

        case GEN_WRT_NOISE_SYN:
            FAPI_INF(TARGTIDFORMAT" Generate write noise synchronization Stage, code: 0x%016x", TARGTID, i_mail);
            break;

        case END_OF_MPR_RD_DLY_CNTR_OPT:
            FAPI_INF(TARGTIDFORMAT" End of MPR read delay center optimization Stage, code: 0x%016x", TARGTID, i_mail);
            break;

        case END_OF_WR_LVL_COARSE_DLY:
            FAPI_INF(TARGTIDFORMAT" End of write level coarse delay Stage, code: 0x%016x", TARGTID, i_mail);
            break;

        case STREAMING_MSG:
            // Decodes and prints streaming messages
            FAPI_TRY(process_streaming_message(i_target, o_log_data));
            break;

        case SMBUS_MSG:
            // Processes and handles the SMBus messages including sending out the RCW over i2c
            FAPI_TRY(process_smbus_message(i_target));
            break;

        default:
            FAPI_INF(TARGTIDFORMAT" Unknown major message: 0x%016x", TARGTID, i_mail);
            break;
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configures the DRAM training message block using sim environment hardcoded values
/// @param[in] i_target the memory port on which to operate
/// @param[out] o_struct the message block
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode configure_dram_train_message_block_hardcodes(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>&
        i_target,
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
    // WL_ADJ_START and WL_ADJ_END should be set according to the DDR5 spec, section 4.21.4
    // for our hard codes, we have tWPRE=2
    //  WL_ADJ_START = -0.75 tCK from table 110, and there are 128 fine steps per clock in the PHY, so use 3*128/4
    o_struct.WL_ADJ_START     = 0x0060;
    //  WL_ADJ_END = 1.25 tCK from table 110, and there are 128 fine steps per clock in the PHY, so use 5*128/4
    o_struct.WL_ADJ_END       = 0x00A0;
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
/// @brief Configures the DRAM training message block using attributes
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_sim value of ATTR_IS_SIMULATION
/// @param[out] o_struct the message block
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode configure_dram_train_message_block(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint8_t i_sim,
        PMU_SMB_DDR5U_1D_t& o_struct)
{
    fapi2::ReturnCode l_rc;

    const msg_block_params l_msg_block_config(i_target, l_rc);
    FAPI_TRY(l_rc, "Unable to instantiate msg_block_params for target " TARGTIDFORMAT, TARGTID);

    FAPI_TRY(l_msg_block_config.setup_AdvTrainOpt(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MsgMisc(o_struct));
    FAPI_TRY(l_msg_block_config.setup_Pstate(o_struct));
    FAPI_TRY(l_msg_block_config.setup_PllBypassEn(o_struct));
    FAPI_TRY(l_msg_block_config.setup_DRAMFreq(o_struct));
    FAPI_TRY(l_msg_block_config.setup_RCW05_next(o_struct));
    FAPI_TRY(l_msg_block_config.setup_RCW06_next(o_struct));
    FAPI_TRY(l_msg_block_config.setup_RXEN_ADJ(o_struct));
    FAPI_TRY(l_msg_block_config.setup_RX2D_DFE_Misc(o_struct));
    FAPI_TRY(l_msg_block_config.setup_PhyVref(o_struct));
    FAPI_TRY(l_msg_block_config.setup_D5Misc(o_struct));
    FAPI_TRY(l_msg_block_config.setup_WL_ADJ(o_struct));
    FAPI_TRY(l_msg_block_config.setup_SequenceCtrl(o_struct));
    FAPI_TRY(l_msg_block_config.setup_HdtCtrl(o_struct));
    FAPI_TRY(l_msg_block_config.setup_PhyCfg(o_struct));
    FAPI_TRY(l_msg_block_config.setup_DFIMRLMargin(o_struct));
    FAPI_TRY(l_msg_block_config.setup_X16Present(o_struct));
    FAPI_TRY(l_msg_block_config.setup_UseBroadcastMR(o_struct));
    FAPI_TRY(l_msg_block_config.setup_D5Quickboot(o_struct));
    FAPI_TRY(l_msg_block_config.setup_DisabledDbyte(o_struct));
    FAPI_TRY(l_msg_block_config.setup_CATrainOpt(i_sim, o_struct));
    FAPI_TRY(l_msg_block_config.setup_TX2D_DFE_Misc(i_sim, o_struct));
    FAPI_TRY(l_msg_block_config.setup_RX2D_TrainOpt(i_sim, o_struct));
    FAPI_TRY(l_msg_block_config.setup_TX2D_TrainOpt(i_sim, o_struct));
    FAPI_TRY(l_msg_block_config.setup_Share2DVrefResult(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MRE_MIN_PULSE(o_struct));
    FAPI_TRY(l_msg_block_config.setup_DWL_MIN_PULSE(o_struct));
    FAPI_TRY(l_msg_block_config.setup_PhyConfigOverride(o_struct));
    FAPI_TRY(l_msg_block_config.setup_EnabledDQsChA(o_struct));
    FAPI_TRY(l_msg_block_config.setup_CsPresentChA(o_struct));
    FAPI_TRY(l_msg_block_config.setup_EnabledDQsChB(o_struct));
    FAPI_TRY(l_msg_block_config.setup_CsPresentChB(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR0(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR2(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR3(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR4(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR5(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR6(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR32_next(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR8(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR32_ORG_next(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR10(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR11(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR12(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR13(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR14(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR15(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR111(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR32(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR33(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR34(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR35(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR32_ORG(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR37(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR38(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR39(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR33_ORG(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR11_next(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR12_next(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR13_next(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR33_ORG_next(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR33_next(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR50(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR51(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR52(o_struct));
    FAPI_TRY(l_msg_block_config.setup_DFE_GainBias(o_struct));
    FAPI_TRY(l_msg_block_config.setup_ReservedF6(o_struct));
    FAPI_TRY(l_msg_block_config.setup_ReservedF7(o_struct));
    FAPI_TRY(l_msg_block_config.setup_ReservedF8(o_struct));
    FAPI_TRY(l_msg_block_config.setup_ReservedF9(o_struct));
    FAPI_TRY(l_msg_block_config.setup_BCW04_next(o_struct));
    FAPI_TRY(l_msg_block_config.setup_BCW05_next(o_struct));
    FAPI_TRY(l_msg_block_config.setup_WR_RD_RTT_PARK(o_struct));
    FAPI_TRY(l_msg_block_config.setup_Reserved1E2(i_sim, o_struct));
    FAPI_TRY(l_msg_block_config.setup_Reserved1E3(o_struct));
    FAPI_TRY(l_msg_block_config.setup_Reserved1E4(o_struct));
    FAPI_TRY(l_msg_block_config.setup_Reserved1E5(o_struct));
    FAPI_TRY(l_msg_block_config.setup_Reserved1E6(o_struct));
    FAPI_TRY(l_msg_block_config.setup_Reserved1E7(o_struct));
    FAPI_TRY(l_msg_block_config.setup_WL_ADJ_START(o_struct));
    FAPI_TRY(l_msg_block_config.setup_WL_ADJ_END(o_struct));
    // TODO: Zen:MST-1732 Fill in RCW fields in ody_draminit message block from attributes
    FAPI_TRY(l_msg_block_config.setup_RCW(o_struct));
    FAPI_TRY(l_msg_block_config.setup_BCW(o_struct));
    FAPI_TRY(l_msg_block_config.setup_VrefDq(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR3_per_dram(o_struct));
    FAPI_TRY(l_msg_block_config.setup_VrefCS(o_struct));
    FAPI_TRY(l_msg_block_config.setup_VrefCA(o_struct));
    FAPI_TRY(l_msg_block_config.setup_DisabledDB(o_struct));
    FAPI_TRY(l_msg_block_config.setup_output_fields(o_struct));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Processes a streaming message from the mailbox protocol
/// @param[in] i_target the target on which to operate
/// @param[out] o_log_data hwp_data_ostream of streaming log
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode process_streaming_message(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        fapi2::hwp_data_ostream& o_log_data)
{
    constexpr uint64_t STRING_INDEX     = 32;
    constexpr uint64_t STRING_INDEX_LEN = 32;
    constexpr uint64_t DATA             = 32;
    constexpr uint64_t DATA_LEN         = 32;
    constexpr uint64_t NUM_DATA         = 48;
    constexpr uint64_t NUM_DATA_LEN     = 16;

    // Grabbing a streaming message should be almost instantaneous
    // Only using a loop count of 10 (10 ms) to hopefully allow draminit to run quickly
    // Need to run at least 2 loops here to get streaming message in sim
    constexpr uint64_t LOOP_COUNT = 10;
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

    // Put the string index into the output stream
    FAPI_TRY(o_log_data.put(static_cast<fapi2::hwp_data_unit>(l_string_index)));

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

        // Put the data piece into the output stream
        FAPI_TRY(o_log_data.put(static_cast<fapi2::hwp_data_unit>(l_data)));

        // Print the data
        // The data can be post processed using the Synopsys .strings file (not including here as it could be size prohibitive)
        FAPI_INF(TARGTIDFORMAT " message data %5u: 0x%08x", TARGTID, l_num, l_data);
    }

    FAPI_INF(TARGTIDFORMAT " End of message", TARGTID);

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Configure and load the msg block on to snps phy
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode configure_and_load_dram_train_message_block(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>&
        i_target,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    uint8_t l_sim = 0;
    uint8_t l_data_source = 0;

    FAPI_TRY(mss::attr::get_is_simulation(l_sim));
    FAPI_TRY(mss::attr::get_ody_msg_block_data_source(i_target, l_data_source));

    // Configure the message block structure
    // TODO: Zen:MST-1895 Make a helper function for this or remove the hardcodes
    if (l_data_source == fapi2::ENUM_ATTR_ODY_MSG_BLOCK_DATA_SOURCE_USE_HARDCODES)
    {
        FAPI_TRY(configure_dram_train_message_block_hardcodes(i_target, io_msg_block));
    }
    else
    {
        FAPI_TRY(configure_dram_train_message_block(i_target, l_sim, io_msg_block));
    }

    // Load the message block on to snps phy
    FAPI_TRY(load_msg_block(i_target, io_msg_block));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Assembles a single registers worth of data from the buffer
/// @param[in] i_mem_size size of the dmem/imem istream to be transferred per loop
/// @param[in,out] io_bytes_copied the number of bytes copied
/// @param[in] i_current_byte the pointer to the current byte
/// @param[in,out] io_data the data for this register address
/// @return The updated pointer to the current byte
///
const uint8_t* assemble_mem_bin_data_reg(const uint32_t i_mem_size,
        uint32_t& io_bytes_copied,
        const uint8_t* i_current_byte,
        fapi2::buffer<uint64_t>& io_data)
{
    // Copy the last 8(56-63) bits of data
    if (io_bytes_copied < i_mem_size)
    {
        io_data.insertFromRight < 64 - BITS_PER_BYTE, BITS_PER_BYTE > (*i_current_byte);
        io_bytes_copied++;
        i_current_byte++;
    }

    if (io_bytes_copied < i_mem_size)
    {
        // Copy the next 8(48-55) bits of data
        io_data.insertFromRight < 64 - 2 * BITS_PER_BYTE, BITS_PER_BYTE > (*i_current_byte);
        io_bytes_copied++;
        i_current_byte++;
    }

    return i_current_byte;
}

///
/// @brief Loads binary into registers
/// @param[in] i_target the target on which to operate
/// @param[in] i_is_first_load value noting if this is the first load of the given memory array
/// @param[in] i_start_addr start address of  imem/dmem binary
/// @param[in] i_data_start data pointer  of imem/dmem
/// @param[in] i_mem_size size of the dmem/imem istream to be transferred per loop
/// @param[in] i_mem_total_size total size of the dmem/imem
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode load_mem_bin_data(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                    const uint8_t i_is_first_load,
                                    const uint32_t i_start_addr,
                                    uint8_t* const i_data_start,
                                    const uint32_t i_mem_size,
                                    const uint32_t i_mem_total_size)
{
    // Get all the mem port targets
    const auto& l_port_targets = mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target);

    uint64_t l_curr_addr = i_start_addr;
    uint32_t l_bytes_copied = 0;
    const uint8_t* l_curr_byte = i_data_start;

#ifndef __PPE__
    constexpr uint64_t SECONDS_PER_MINUTE = 60;
    uint32_t l_progress_pct = 0;
    // Passing in a nullptr gets us the current time
    const auto l_start_time = time(nullptr);
#endif
    FAPI_ASSERT(i_data_start != NULL,
                fapi2::ODY_DRAMINIT_START_DATA_PTR_NULL().
                set_TARGET(i_target),
                TARGTIDFORMAT  " The start address is NULL.", TARGTID);

    while(l_bytes_copied < i_mem_size)
    {
        // Local buffer for getting data from registers
        fapi2::buffer<uint64_t> l_buffer_even;
        fapi2::buffer<uint64_t> l_buffer_odd;

        l_curr_byte = assemble_mem_bin_data_reg(i_mem_size, l_bytes_copied, l_curr_byte, l_buffer_even);
        l_curr_byte = assemble_mem_bin_data_reg(i_mem_size, l_bytes_copied, l_curr_byte, l_buffer_odd);

        // Write l_buffer to the registers
        for(const auto& l_port : l_port_targets)
        {
            FAPI_TRY(phy_mem_load_helper( l_port,
                                          i_is_first_load,
                                          l_curr_addr,
                                          l_buffer_even,
                                          l_buffer_odd));
        }

        // The registers are written in pairs so we increment by 2
        // Additionally, we need to write the same data to the same register in each port
        // Therefore, the address is incremented outside of the port loop
        l_curr_addr += 2;

#ifndef __PPE__
        {
            // Report progress at 1% intervals (only in Cronus)
            // Percentage of the number of bytes copied so far
            uint32_t l_new_progress_pct = 100 * (l_bytes_copied) / i_mem_total_size;

            // Calculate the time progress
            const auto l_current_time = time(nullptr);
            const auto l_elapsed_time = difftime(l_current_time, l_start_time);
            const uint32_t l_predicted_total_time = 100 * l_elapsed_time /
                                                    ((l_new_progress_pct < 1) ? 1 : l_new_progress_pct);
            const auto l_remaining_time = static_cast<uint64_t>(l_predicted_total_time - l_elapsed_time);
            const auto l_remaining_minutes = l_remaining_time / SECONDS_PER_MINUTE;

            if (l_progress_pct != l_new_progress_pct)
            {
                FAPI_INF(TARGTIDFORMAT " Percent copied so far: %d%% (about %d minutes remaining)",
                         TARGTID, l_new_progress_pct, l_remaining_minutes);
            }

            l_progress_pct = l_new_progress_pct;
        }
#endif

    } // end while

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
    l_data.setBit<scomt::mp::DWC_DDRPHYA_APBONLY0_MICRORESET_STALLTOMICRO>().setBit<scomt::mp::DWC_DDRPHYA_APBONLY0_MICRORESET_RESETTOMICRO>();
    FAPI_TRY(fapi2::putScom(i_target, scomt::mp::DWC_DDRPHYA_APBONLY0_MICRORESET, l_data));

    // 3. Stall the processor (releases reset but does not start it)
    l_data.flush<0>().setBit<scomt::mp::DWC_DDRPHYA_APBONLY0_MICRORESET_STALLTOMICRO>();
    FAPI_TRY(fapi2::putScom(i_target, scomt::mp::DWC_DDRPHYA_APBONLY0_MICRORESET, l_data));

    // 4. Start training (release stall/reset)
    l_data.flush<0>();
    FAPI_TRY(fapi2::putScom(i_target, scomt::mp::DWC_DDRPHYA_APBONLY0_MICRORESET, l_data));

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

    // Per the Synopsys documentation, to cleanup after the training:
    // 1. Stop the processor (stall it)
    // 2. Disable the CalZap register
    // 3. Configure CSR access
    fapi2::buffer<uint64_t> l_data;

    // 1. Stop the processor (stall it)
    FAPI_TRY(stall_arc_processor(i_target));

    // 2. Disable the CalZap register before reading out the training results
    FAPI_TRY(fapi2::putScom(i_target, scomt::mp::DWC_DDRPHYA_MASTER0_BASE0_CALZAP, l_data));

    // 3. Configure CSR access as well
    // Note: ON_N refers to scom access -> so this enables scom access
    FAPI_TRY(configure_phy_scom_access(i_target, mss::states::ON_N));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Calculates the end addr of IMEM/DMEM image
/// @param[in] i_start_addr starting address of the image
/// @param[in] i_size size that needs to transferred at a time
/// @return uint32_t calculated end address
///
uint32_t calculate_image_end_addr(const uint32_t i_start_addr, const uint32_t i_size)
{
    return (i_start_addr + (i_size / 2) + (i_size % 2) - 1);
}

///
/// @brief Helper function to ody_load_dmem()
/// @param[in] i_target the ocmb chip target
/// @param[in] i_dmem_data dmem data image
/// @param[in] i_dmem_size size that needs to transferred at a time
/// @param[in] i_dmem_offset address offset of this chunk within the dmem image(in bytes)
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode ody_load_dmem_helper(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                       uint8_t* const i_dmem_data,
                                       const uint32_t i_dmem_size,
                                       const uint32_t i_dmem_offset)
{
    constexpr uint8_t DMEM = mss::ody::phy_mem_types::DMEM;
    constexpr uint64_t DMEM_ST_ADDR = 0x58000;
    const uint32_t l_start_addr = (i_dmem_offset / 2) + DMEM_ST_ADDR;
    constexpr uint64_t DMEM_END_ADDR = 0x60000;
    constexpr size_t MAX_IMAGE_SIZE = 65536;

    // Get all the mem port targets
    const auto& l_port_targets = mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target);
    uint8_t l_is_first_load = 0;

    // Get the end address
    const auto l_end_addr = mss::ody::phy::calculate_image_end_addr(l_start_addr, i_dmem_size);

    // OFFSET check
    FAPI_ASSERT(!is_odd(i_dmem_offset),
                fapi2::ODY_DRAMINIT_OFFSET_UNSUPPORTED()
                .set_TARGET(i_target)
                .set_MEM_TYPE(DMEM)
                .set_START_ADDR(DMEM_ST_ADDR)
                .set_END_ADDR(DMEM_END_ADDR)
                .set_IMAGE_ST_ADDR(l_start_addr)
                .set_IMAGE_SIZE(i_dmem_size),
                TARGTIDFORMAT " DMEM offset(0x%04x) not supported. Offset cannot be odd", TARGTID, i_dmem_offset);

    // ADDR check
    FAPI_ASSERT(l_start_addr >= DMEM_ST_ADDR && l_end_addr < DMEM_END_ADDR,
                fapi2::ODY_DRAMINIT_MEM_ADDR_RANGE_OUT_OF_BOUNDS()
                .set_TARGET(i_target)
                .set_MEM_TYPE(DMEM)
                .set_START_ADDR(DMEM_ST_ADDR)
                .set_END_ADDR(DMEM_END_ADDR)
                .set_IMAGE_ST_ADDR(l_start_addr)
                .set_IMAGE_SIZE(i_dmem_size),
                TARGTIDFORMAT " DMEM start address(0x%08x) or size(0x%04x) puts image out of range in phy.", TARGTID,
                l_start_addr, i_dmem_size);

    // If there is at least one port configured, use that port to grab the first load attribute
    // Going to make the assumption that the ports are always loaded together and that errors did not occur setting the attributes on both ports
    // This seems like a safe assumption as attribute set/get errors are extremely rare
    if(!l_port_targets.empty())
    {
        FAPI_TRY(mss::attr::get_ody_dmem_first_load(l_port_targets[0], l_is_first_load));
    }

    return mss::ody::phy::load_mem_bin_data(i_target,
                                            l_is_first_load,
                                            l_start_addr,
                                            i_dmem_data,
                                            i_dmem_size,
                                            MAX_IMAGE_SIZE);

    // Note: we specifically do NOT set the first load attributes here
    // Due to memory size constraints on the SBE, this procedure can be called multiple times
    // Setting the attributes here could cause speed ups within the helper functions to not be run
    // for the second or third executions of the memory load
    // For normal boots, these attributes will be set in the draminit procedure

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to ody_load_imem()
/// @param[in] i_target the ocmb chip target
/// @param[in] i_imem_data imem data image
/// @param[in] i_imem_size size that needs to transferred at a time
/// @param[in] i_imem_offset address offset of this chunk within the imem image(in bytes)
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode ody_load_imem_helper(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                       uint8_t* const i_imem_data,
                                       const uint32_t i_imem_size,
                                       const uint32_t i_imem_offset)
{
    constexpr uint8_t IMEM = mss::ody::phy_mem_types::IMEM;
    constexpr uint64_t IMEM_ST_ADDR = 0x50000;
    const uint32_t l_start_addr = (i_imem_offset / 2) + IMEM_ST_ADDR;
    constexpr uint64_t IMEM_END_ADDR = 0x58000;
    // This is an estimation based on the size of the first IMEM
    // we got from Synopsys
    constexpr size_t MAX_IMAGE_SIZE = 53076;

    // Get the end address
    const auto l_end_addr = mss::ody::phy::calculate_image_end_addr(l_start_addr, i_imem_size);

    // OFFSET check
    FAPI_ASSERT(!is_odd(i_imem_offset),
                fapi2::ODY_DRAMINIT_OFFSET_UNSUPPORTED()
                .set_TARGET(i_target)
                .set_MEM_TYPE(IMEM)
                .set_START_ADDR(IMEM_ST_ADDR)
                .set_END_ADDR(IMEM_END_ADDR)
                .set_IMAGE_ST_ADDR(l_start_addr)
                .set_IMAGE_SIZE(i_imem_size),
                TARGTIDFORMAT " IMEM offset(0x%04x) not supported. Offset cannot be odd.", TARGTID, i_imem_offset);

    // ADDR check
    FAPI_ASSERT(l_start_addr >= IMEM_ST_ADDR && l_end_addr < IMEM_END_ADDR,
                fapi2::ODY_DRAMINIT_MEM_ADDR_RANGE_OUT_OF_BOUNDS()
                .set_TARGET(i_target)
                .set_MEM_TYPE(IMEM)
                .set_START_ADDR(IMEM_ST_ADDR)
                .set_END_ADDR(IMEM_END_ADDR)
                .set_IMAGE_ST_ADDR(l_start_addr)
                .set_IMAGE_SIZE(i_imem_size),
                TARGTIDFORMAT " IMEM start address(0x%08x) or size(0x%04x) puts image out of range in phy.", TARGTID, l_start_addr,
                i_imem_size);

    // Note: the IMEM is not guaranteed to be initialized to zeroes, so this load is considered to NOT be the first load
    // This will skip some efficiency boosts we can use for the DMEM load
    return mss::ody::phy::load_mem_bin_data(i_target,
                                            fapi2::ENUM_ATTR_ODY_DMEM_FIRST_LOAD_NO,
                                            l_start_addr,
                                            i_imem_data,
                                            i_imem_size,
                                            MAX_IMAGE_SIZE);

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Loads the message block values into the DMEM regs
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_struct the message block
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note Only loads the "input" fields
///
fapi2::ReturnCode load_msg_block(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                 const _PMU_SMB_DDR5_1D_t& i_struct)
{
    constexpr uint64_t SYNOPSYS_DATA = 48;
    constexpr uint64_t DATA_16B_LEN = 16;
    fapi2::buffer<uint64_t> l_data;

    load_dmem_8bit_fields(i_struct.AdvTrainOpt, i_struct.MsgMisc, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58000), l_data));

    // Need to write to paired even/odd addresses in order to "complete" the write
    l_data.flush<0>();
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58001), l_data));

    load_dmem_8bit_fields(i_struct.Pstate, i_struct.PllBypassEn, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58002), l_data));

    l_data.insertFromRight<SYNOPSYS_DATA, DATA_16B_LEN>(i_struct.DRAMFreq);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58003), l_data));

    load_dmem_8bit_fields(i_struct.RCW05_next, i_struct.RCW06_next, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58004), l_data));

    load_dmem_8bit_fields(i_struct.RXEN_ADJ, i_struct.RX2D_DFE_Misc, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58005), l_data));

    load_dmem_8bit_fields(i_struct.PhyVref, i_struct.D5Misc, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58006), l_data));

    load_dmem_8bit_fields(i_struct.WL_ADJ, i_struct.CsTestFail, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58007), l_data));

    l_data.insertFromRight<SYNOPSYS_DATA, DATA_16B_LEN>(i_struct.SequenceCtrl);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58008), l_data));

    load_dmem_8bit_fields(i_struct.HdtCtrl, i_struct.PhyCfg, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58009), l_data));

    // Need to write to paired even/odd addresses in order to "complete" the write
    l_data.flush<0>();
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5800a), l_data));

    load_dmem_8bit_fields(i_struct.DFIMRLMargin, i_struct.X16Present, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5800b), l_data));

    load_dmem_8bit_fields(i_struct.UseBroadcastMR, i_struct.D5Quickboot, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5800c), l_data));

    load_dmem_8bit_fields(i_struct.DisabledDbyte, i_struct.CATrainOpt, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5800d), l_data));

    load_dmem_8bit_fields(i_struct.TX2D_DFE_Misc, i_struct.RX2D_TrainOpt, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5800e), l_data));

    load_dmem_8bit_fields(i_struct.TX2D_TrainOpt, i_struct.Share2DVrefResult, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5800f), l_data));

    load_dmem_8bit_fields(i_struct.MRE_MIN_PULSE, i_struct.DWL_MIN_PULSE, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58010), l_data));

    l_data.insertFromRight<SYNOPSYS_DATA, DATA_16B_LEN>(i_struct.PhyConfigOverride);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58011), l_data));

    load_dmem_8bit_fields(i_struct.EnabledDQsChA, i_struct.CsPresentChA, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58012), l_data));

    // Need to write to paired even/odd addresses in order to "complete" the write
    l_data.flush<0>();
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58013), l_data));

    // Need to write to paired even/odd addresses in order to "complete" the write
    l_data.flush<0>();
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5802e), l_data));

    load_dmem_8bit_fields(i_struct.MR0_A0, i_struct.MR2_A0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5802f), l_data));

    load_dmem_8bit_fields(i_struct.MR3_A0, i_struct.MR4_A0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58030), l_data));

    load_dmem_8bit_fields(i_struct.MR5_A0, i_struct.MR6_A0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58031), l_data));

    load_dmem_8bit_fields(i_struct.MR32_A0_next, i_struct.MR8_A0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58032), l_data));

    load_dmem_8bit_fields(i_struct.MR32_ORG_A0_next, i_struct.MR10_A0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58033), l_data));

    load_dmem_8bit_fields(i_struct.MR11_A0, i_struct.MR12_A0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58034), l_data));

    load_dmem_8bit_fields(i_struct.MR13_A0, i_struct.MR14_A0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58035), l_data));

    load_dmem_8bit_fields(i_struct.MR15_A0, i_struct.MR111_A0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58036), l_data));

    load_dmem_8bit_fields(i_struct.MR32_A0, i_struct.MR33_A0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58037), l_data));

    load_dmem_8bit_fields(i_struct.MR34_A0, i_struct.MR35_A0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58038), l_data));

    load_dmem_8bit_fields(i_struct.MR32_ORG_A0, i_struct.MR37_A0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58039), l_data));

    load_dmem_8bit_fields(i_struct.MR38_A0, i_struct.MR39_A0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5803a), l_data));

    load_dmem_8bit_fields(i_struct.MR33_ORG_A0, i_struct.MR11_A0_next, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5803b), l_data));

    load_dmem_8bit_fields(i_struct.MR12_A0_next, i_struct.MR13_A0_next, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5803c), l_data));

    // Need to write to paired even/odd addresses in order to "complete" the write
    l_data.flush<0>();
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5803d), l_data));
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5803e), l_data));

    load_dmem_8bit_fields(i_struct.MR33_ORG_A0_next, i_struct.MR33_A0_next, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5803f), l_data));

    load_dmem_8bit_fields(i_struct.MR50_A0, i_struct.MR51_A0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58040), l_data));

    load_dmem_8bit_fields(i_struct.MR52_A0, i_struct.DFE_GainBias_A0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58041), l_data));

    load_dmem_8bit_fields(i_struct.MR0_A1, i_struct.MR2_A1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58042), l_data));

    load_dmem_8bit_fields(i_struct.MR3_A1, i_struct.MR4_A1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58043), l_data));

    load_dmem_8bit_fields(i_struct.MR5_A1, i_struct.MR6_A1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58044), l_data));

    load_dmem_8bit_fields(i_struct.MR32_A1_next, i_struct.MR8_A1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58045), l_data));

    load_dmem_8bit_fields(i_struct.MR32_ORG_A1_next, i_struct.MR10_A1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58046), l_data));

    load_dmem_8bit_fields(i_struct.MR11_A1, i_struct.MR12_A1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58047), l_data));

    load_dmem_8bit_fields(i_struct.MR13_A1, i_struct.MR14_A1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58048), l_data));

    load_dmem_8bit_fields(i_struct.MR15_A1, i_struct.MR111_A1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58049), l_data));

    load_dmem_8bit_fields(i_struct.MR32_A1, i_struct.MR33_A1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5804a), l_data));

    load_dmem_8bit_fields(i_struct.MR34_A1, i_struct.MR35_A1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5804b), l_data));

    load_dmem_8bit_fields(i_struct.MR32_ORG_A1, i_struct.MR37_A1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5804c), l_data));

    load_dmem_8bit_fields(i_struct.MR38_A1, i_struct.MR39_A1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5804d), l_data));

    load_dmem_8bit_fields(i_struct.MR33_ORG_A1, i_struct.MR11_A1_next, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5804e), l_data));

    load_dmem_8bit_fields(i_struct.MR12_A1_next, i_struct.MR13_A1_next, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5804f), l_data));

    load_dmem_8bit_fields(i_struct.MR33_ORG_A1_next, i_struct.MR33_A1_next, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58052), l_data));

    load_dmem_8bit_fields(i_struct.MR50_A1, i_struct.MR51_A1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58053), l_data));

    load_dmem_8bit_fields(i_struct.MR52_A1, i_struct.DFE_GainBias_A1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58054), l_data));

    load_dmem_8bit_fields(i_struct.MR0_A2, i_struct.MR2_A2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58055), l_data));

    load_dmem_8bit_fields(i_struct.MR3_A2, i_struct.MR4_A2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58056), l_data));

    load_dmem_8bit_fields(i_struct.MR5_A2, i_struct.MR6_A2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58057), l_data));

    load_dmem_8bit_fields(i_struct.MR32_A2_next, i_struct.MR8_A2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58058), l_data));

    load_dmem_8bit_fields(i_struct.MR32_ORG_A2_next, i_struct.MR10_A2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58059), l_data));

    load_dmem_8bit_fields(i_struct.MR11_A2, i_struct.MR12_A2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5805a), l_data));

    load_dmem_8bit_fields(i_struct.MR13_A2, i_struct.MR14_A2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5805b), l_data));

    load_dmem_8bit_fields(i_struct.MR15_A2, i_struct.MR111_A2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5805c), l_data));

    load_dmem_8bit_fields(i_struct.MR32_A2, i_struct.MR33_A2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5805d), l_data));

    load_dmem_8bit_fields(i_struct.MR34_A2, i_struct.MR35_A2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5805e), l_data));

    load_dmem_8bit_fields(i_struct.MR32_ORG_A2, i_struct.MR37_A2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5805f), l_data));

    load_dmem_8bit_fields(i_struct.MR38_A2, i_struct.MR39_A2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58060), l_data));

    load_dmem_8bit_fields(i_struct.MR33_ORG_A2, i_struct.MR11_A2_next, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58061), l_data));

    load_dmem_8bit_fields(i_struct.MR12_A2_next, i_struct.MR13_A2_next, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58062), l_data));

    // Need to write to paired even/odd addresses in order to "complete" the write
    l_data.flush<0>();
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58063), l_data));
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58064), l_data));

    load_dmem_8bit_fields(i_struct.MR33_ORG_A2_next, i_struct.MR33_A2_next, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58065), l_data));

    load_dmem_8bit_fields(i_struct.MR50_A2, i_struct.MR51_A2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58066), l_data));

    load_dmem_8bit_fields(i_struct.MR52_A2, i_struct.DFE_GainBias_A2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58067), l_data));

    load_dmem_8bit_fields(i_struct.MR0_A3, i_struct.MR2_A3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58068), l_data));

    load_dmem_8bit_fields(i_struct.MR3_A3, i_struct.MR4_A3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58069), l_data));

    load_dmem_8bit_fields(i_struct.MR5_A3, i_struct.MR6_A3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5806a), l_data));

    load_dmem_8bit_fields(i_struct.MR32_A3_next, i_struct.MR8_A3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5806b), l_data));

    load_dmem_8bit_fields(i_struct.MR32_ORG_A3_next, i_struct.MR10_A3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5806c), l_data));

    load_dmem_8bit_fields(i_struct.MR11_A3, i_struct.MR12_A3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5806d), l_data));

    load_dmem_8bit_fields(i_struct.MR13_A3, i_struct.MR14_A3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5806e), l_data));

    load_dmem_8bit_fields(i_struct.MR15_A3, i_struct.MR111_A3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5806f), l_data));

    load_dmem_8bit_fields(i_struct.MR32_A3, i_struct.MR33_A3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58070), l_data));

    load_dmem_8bit_fields(i_struct.MR34_A3, i_struct.MR35_A3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58071), l_data));

    load_dmem_8bit_fields(i_struct.MR32_ORG_A3, i_struct.MR37_A3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58072), l_data));

    load_dmem_8bit_fields(i_struct.MR38_A3, i_struct.MR39_A3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58073), l_data));

    load_dmem_8bit_fields(i_struct.MR33_ORG_A3, i_struct.MR11_A3_next, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58074), l_data));

    load_dmem_8bit_fields(i_struct.MR12_A3_next, i_struct.MR13_A3_next, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58075), l_data));

    load_dmem_8bit_fields(i_struct.MR33_ORG_A3_next, i_struct.MR33_A3_next, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58078), l_data));

    load_dmem_8bit_fields(i_struct.MR50_A3, i_struct.MR51_A3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58079), l_data));

    load_dmem_8bit_fields(i_struct.MR52_A3, i_struct.DFE_GainBias_A3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5807a), l_data));

    load_dmem_8bit_fields(i_struct.ReservedF6, i_struct.ReservedF7, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5807b), l_data));

    load_dmem_8bit_fields(i_struct.ReservedF8, i_struct.ReservedF9, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5807c), l_data));

    load_dmem_8bit_fields(i_struct.BCW04_next, i_struct.BCW05_next, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5807d), l_data));

    load_dmem_8bit_fields(i_struct.WR_RD_RTT_PARK_A0, i_struct.WR_RD_RTT_PARK_A1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5807e), l_data));

    load_dmem_8bit_fields(i_struct.WR_RD_RTT_PARK_A2, i_struct.WR_RD_RTT_PARK_A3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5807f), l_data));

    load_dmem_8bit_fields(i_struct.EnabledDQsChB, i_struct.CsPresentChB, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58088), l_data));

    // Need to write to paired even/odd addresses in order to "complete" the write
    l_data.flush<0>();
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58089), l_data));
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580a4), l_data));

    load_dmem_8bit_fields(i_struct.MR0_B0, i_struct.MR2_B0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580a5), l_data));

    load_dmem_8bit_fields(i_struct.MR3_B0, i_struct.MR4_B0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580a6), l_data));

    load_dmem_8bit_fields(i_struct.MR5_B0, i_struct.MR6_B0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580a7), l_data));

    load_dmem_8bit_fields(i_struct.MR32_B0_next, i_struct.MR8_B0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580a8), l_data));

    load_dmem_8bit_fields(i_struct.MR32_ORG_B0_next, i_struct.MR10_B0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580a9), l_data));

    load_dmem_8bit_fields(i_struct.MR11_B0, i_struct.MR12_B0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580aa), l_data));

    load_dmem_8bit_fields(i_struct.MR13_B0, i_struct.MR14_B0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580ab), l_data));

    load_dmem_8bit_fields(i_struct.MR15_B0, i_struct.MR111_B0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580ac), l_data));

    load_dmem_8bit_fields(i_struct.MR32_B0, i_struct.MR33_B0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580ad), l_data));

    load_dmem_8bit_fields(i_struct.MR34_B0, i_struct.MR35_B0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580ae), l_data));

    load_dmem_8bit_fields(i_struct.MR32_ORG_B0, i_struct.MR37_B0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580af), l_data));

    load_dmem_8bit_fields(i_struct.MR38_B0, i_struct.MR39_B0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580b0), l_data));

    load_dmem_8bit_fields(i_struct.MR33_ORG_B0, i_struct.MR11_B0_next, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580b1), l_data));

    load_dmem_8bit_fields(i_struct.MR12_B0_next, i_struct.MR13_B0_next, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580b2), l_data));

    // Need to write to paired even/odd addresses in order to "complete" the write
    l_data.flush<0>();
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580b3), l_data));
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580b4), l_data));

    load_dmem_8bit_fields(i_struct.MR33_ORG_B0_next, i_struct.MR33_B0_next, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580b5), l_data));

    load_dmem_8bit_fields(i_struct.MR50_B0, i_struct.MR51_B0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580b6), l_data));

    load_dmem_8bit_fields(i_struct.MR52_B0, i_struct.DFE_GainBias_B0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580b7), l_data));

    load_dmem_8bit_fields(i_struct.MR0_B1, i_struct.MR2_B1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580b8), l_data));

    load_dmem_8bit_fields(i_struct.MR3_B1, i_struct.MR4_B1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580b9), l_data));

    load_dmem_8bit_fields(i_struct.MR5_B1, i_struct.MR6_B1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580ba), l_data));

    load_dmem_8bit_fields(i_struct.MR32_B1_next, i_struct.MR8_B1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580bb), l_data));

    load_dmem_8bit_fields(i_struct.MR32_ORG_B1_next, i_struct.MR10_B1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580bc), l_data));

    load_dmem_8bit_fields(i_struct.MR11_B1, i_struct.MR12_B1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580bd), l_data));

    load_dmem_8bit_fields(i_struct.MR13_B1, i_struct.MR14_B1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580be), l_data));

    load_dmem_8bit_fields(i_struct.MR15_B1, i_struct.MR111_B1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580bf), l_data));

    load_dmem_8bit_fields(i_struct.MR32_B1, i_struct.MR33_B1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580c0), l_data));

    load_dmem_8bit_fields(i_struct.MR34_B1, i_struct.MR35_B1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580c1), l_data));

    load_dmem_8bit_fields(i_struct.MR32_ORG_B1, i_struct.MR37_B1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580c2), l_data));

    load_dmem_8bit_fields(i_struct.MR38_B1, i_struct.MR39_B1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580c3), l_data));

    load_dmem_8bit_fields(i_struct.MR33_ORG_B1, i_struct.MR11_B1_next, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580c4), l_data));

    load_dmem_8bit_fields(i_struct.MR12_B1_next, i_struct.MR13_B1_next, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580c5), l_data));

    load_dmem_8bit_fields(i_struct.MR33_ORG_B1_next, i_struct.MR33_B1_next, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580c8), l_data));

    load_dmem_8bit_fields(i_struct.MR50_B1, i_struct.MR51_B1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580c9), l_data));

    load_dmem_8bit_fields(i_struct.MR52_B1, i_struct.DFE_GainBias_B1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580ca), l_data));

    load_dmem_8bit_fields(i_struct.MR0_B2, i_struct.MR2_B2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580cb), l_data));

    load_dmem_8bit_fields(i_struct.MR3_B2, i_struct.MR4_B2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580cc), l_data));

    load_dmem_8bit_fields(i_struct.MR5_B2, i_struct.MR6_B2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580cd), l_data));

    load_dmem_8bit_fields(i_struct.MR32_B2_next, i_struct.MR8_B2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580ce), l_data));

    load_dmem_8bit_fields(i_struct.MR32_ORG_B2_next, i_struct.MR10_B2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580cf), l_data));

    load_dmem_8bit_fields(i_struct.MR11_B2, i_struct.MR12_B2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580d0), l_data));

    load_dmem_8bit_fields(i_struct.MR13_B2, i_struct.MR14_B2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580d1), l_data));

    load_dmem_8bit_fields(i_struct.MR15_B2, i_struct.MR111_B2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580d2), l_data));

    load_dmem_8bit_fields(i_struct.MR32_B2, i_struct.MR33_B2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580d3), l_data));

    load_dmem_8bit_fields(i_struct.MR34_B2, i_struct.MR35_B2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580d4), l_data));

    load_dmem_8bit_fields(i_struct.MR32_ORG_B2, i_struct.MR37_B2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580d5), l_data));

    load_dmem_8bit_fields(i_struct.MR38_B2, i_struct.MR39_B2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580d6), l_data));

    load_dmem_8bit_fields(i_struct.MR33_ORG_B2, i_struct.MR11_B2_next, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580d7), l_data));

    load_dmem_8bit_fields(i_struct.MR12_B2_next, i_struct.MR13_B2_next, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580d8), l_data));

    // Need to write to paired even/odd addresses in order to "complete" the write
    l_data.flush<0>();
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580d9), l_data));
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580da), l_data));

    load_dmem_8bit_fields(i_struct.MR33_ORG_B2_next, i_struct.MR33_B2_next, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580db), l_data));

    load_dmem_8bit_fields(i_struct.MR50_B2, i_struct.MR51_B2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580dc), l_data));

    load_dmem_8bit_fields(i_struct.MR52_B2, i_struct.DFE_GainBias_B2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580dd), l_data));

    load_dmem_8bit_fields(i_struct.MR0_B3, i_struct.MR2_B3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580de), l_data));

    load_dmem_8bit_fields(i_struct.MR3_B3, i_struct.MR4_B3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580df), l_data));

    load_dmem_8bit_fields(i_struct.MR5_B3, i_struct.MR6_B3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580e0), l_data));

    load_dmem_8bit_fields(i_struct.MR32_B3_next, i_struct.MR8_B3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580e1), l_data));

    load_dmem_8bit_fields(i_struct.MR32_ORG_B3_next, i_struct.MR10_B3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580e2), l_data));

    load_dmem_8bit_fields(i_struct.MR11_B3, i_struct.MR12_B3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580e3), l_data));

    load_dmem_8bit_fields(i_struct.MR13_B3, i_struct.MR14_B3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580e4), l_data));

    load_dmem_8bit_fields(i_struct.MR15_B3, i_struct.MR111_B3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580e5), l_data));

    load_dmem_8bit_fields(i_struct.MR32_B3, i_struct.MR33_B3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580e6), l_data));

    load_dmem_8bit_fields(i_struct.MR34_B3, i_struct.MR35_B3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580e7), l_data));

    load_dmem_8bit_fields(i_struct.MR32_ORG_B3, i_struct.MR37_B3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580e8), l_data));

    load_dmem_8bit_fields(i_struct.MR38_B3, i_struct.MR39_B3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580e9), l_data));

    load_dmem_8bit_fields(i_struct.MR33_ORG_B3, i_struct.MR11_B3_next, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580ea), l_data));

    load_dmem_8bit_fields(i_struct.MR12_B3_next, i_struct.MR13_B3_next, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580eb), l_data));

    load_dmem_8bit_fields(i_struct.MR33_ORG_B3_next, i_struct.MR33_B3_next, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580ee), l_data));

    load_dmem_8bit_fields(i_struct.MR50_B3, i_struct.MR51_B3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580ef), l_data));

    load_dmem_8bit_fields(i_struct.MR52_B3, i_struct.DFE_GainBias_B3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580f0), l_data));

    load_dmem_8bit_fields(i_struct.Reserved1E2, i_struct.Reserved1E3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580f1), l_data));

    load_dmem_8bit_fields(i_struct.Reserved1E4, i_struct.Reserved1E5, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580f2), l_data));

    load_dmem_8bit_fields(i_struct.Reserved1E6, i_struct.Reserved1E7, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580f3), l_data));

    load_dmem_8bit_fields(i_struct.WR_RD_RTT_PARK_B0, i_struct.WR_RD_RTT_PARK_B1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580f4), l_data));

    load_dmem_8bit_fields(i_struct.WR_RD_RTT_PARK_B2, i_struct.WR_RD_RTT_PARK_B3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580f5), l_data));

    l_data.insertFromRight<SYNOPSYS_DATA, DATA_16B_LEN>(i_struct.WL_ADJ_START);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580fe), l_data));

    l_data.insertFromRight<SYNOPSYS_DATA, DATA_16B_LEN>(i_struct.WL_ADJ_END);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580ff), l_data));

    load_dmem_8bit_fields(i_struct.RCW00_ChA_D0, i_struct.RCW01_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58100), l_data));

    load_dmem_8bit_fields(i_struct.RCW02_ChA_D0, i_struct.RCW03_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58101), l_data));

    load_dmem_8bit_fields(i_struct.RCW04_ChA_D0, i_struct.RCW05_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58102), l_data));

    load_dmem_8bit_fields(i_struct.RCW06_ChA_D0, i_struct.RCW07_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58103), l_data));

    load_dmem_8bit_fields(i_struct.RCW08_ChA_D0, i_struct.RCW09_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58104), l_data));

    load_dmem_8bit_fields(i_struct.RCW0A_ChA_D0, i_struct.RCW0B_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58105), l_data));

    load_dmem_8bit_fields(i_struct.RCW0C_ChA_D0, i_struct.RCW0D_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58106), l_data));

    load_dmem_8bit_fields(i_struct.RCW0E_ChA_D0, i_struct.RCW0F_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58107), l_data));

    load_dmem_8bit_fields(i_struct.RCW10_ChA_D0, i_struct.RCW11_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58108), l_data));

    load_dmem_8bit_fields(i_struct.RCW12_ChA_D0, i_struct.RCW13_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58109), l_data));

    load_dmem_8bit_fields(i_struct.RCW14_ChA_D0, i_struct.RCW15_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5810a), l_data));

    load_dmem_8bit_fields(i_struct.RCW16_ChA_D0, i_struct.RCW17_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5810b), l_data));

    load_dmem_8bit_fields(i_struct.RCW18_ChA_D0, i_struct.RCW19_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5810c), l_data));

    load_dmem_8bit_fields(i_struct.RCW1A_ChA_D0, i_struct.RCW1B_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5810d), l_data));

    load_dmem_8bit_fields(i_struct.RCW1C_ChA_D0, i_struct.RCW1D_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5810e), l_data));

    load_dmem_8bit_fields(i_struct.RCW1E_ChA_D0, i_struct.RCW1F_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5810f), l_data));

    load_dmem_8bit_fields(i_struct.RCW20_ChA_D0, i_struct.RCW21_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58110), l_data));

    load_dmem_8bit_fields(i_struct.RCW22_ChA_D0, i_struct.RCW23_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58111), l_data));

    load_dmem_8bit_fields(i_struct.RCW24_ChA_D0, i_struct.RCW25_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58112), l_data));

    load_dmem_8bit_fields(i_struct.RCW26_ChA_D0, i_struct.RCW27_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58113), l_data));

    load_dmem_8bit_fields(i_struct.RCW28_ChA_D0, i_struct.RCW29_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58114), l_data));

    load_dmem_8bit_fields(i_struct.RCW2A_ChA_D0, i_struct.RCW2B_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58115), l_data));

    load_dmem_8bit_fields(i_struct.RCW2C_ChA_D0, i_struct.RCW2D_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58116), l_data));

    load_dmem_8bit_fields(i_struct.RCW2E_ChA_D0, i_struct.RCW2F_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58117), l_data));

    load_dmem_8bit_fields(i_struct.RCW30_ChA_D0, i_struct.RCW31_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58118), l_data));

    load_dmem_8bit_fields(i_struct.RCW32_ChA_D0, i_struct.RCW33_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58119), l_data));

    load_dmem_8bit_fields(i_struct.RCW34_ChA_D0, i_struct.RCW35_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5811a), l_data));

    load_dmem_8bit_fields(i_struct.RCW36_ChA_D0, i_struct.RCW37_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5811b), l_data));

    load_dmem_8bit_fields(i_struct.RCW38_ChA_D0, i_struct.RCW39_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5811c), l_data));

    load_dmem_8bit_fields(i_struct.RCW3A_ChA_D0, i_struct.RCW3B_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5811d), l_data));

    load_dmem_8bit_fields(i_struct.RCW3C_ChA_D0, i_struct.RCW3D_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5811e), l_data));

    load_dmem_8bit_fields(i_struct.RCW3E_ChA_D0, i_struct.RCW3F_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5811f), l_data));

    load_dmem_8bit_fields(i_struct.RCW40_ChA_D0, i_struct.RCW41_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58120), l_data));

    load_dmem_8bit_fields(i_struct.RCW42_ChA_D0, i_struct.RCW43_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58121), l_data));

    load_dmem_8bit_fields(i_struct.RCW44_ChA_D0, i_struct.RCW45_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58122), l_data));

    load_dmem_8bit_fields(i_struct.RCW46_ChA_D0, i_struct.RCW47_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58123), l_data));

    load_dmem_8bit_fields(i_struct.RCW48_ChA_D0, i_struct.RCW49_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58124), l_data));

    load_dmem_8bit_fields(i_struct.RCW4A_ChA_D0, i_struct.RCW4B_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58125), l_data));

    load_dmem_8bit_fields(i_struct.RCW4C_ChA_D0, i_struct.RCW4D_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58126), l_data));

    load_dmem_8bit_fields(i_struct.RCW4E_ChA_D0, i_struct.RCW4F_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58127), l_data));

    load_dmem_8bit_fields(i_struct.RCW50_ChA_D0, i_struct.RCW51_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58128), l_data));

    load_dmem_8bit_fields(i_struct.RCW52_ChA_D0, i_struct.RCW53_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58129), l_data));

    load_dmem_8bit_fields(i_struct.RCW54_ChA_D0, i_struct.RCW55_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5812a), l_data));

    load_dmem_8bit_fields(i_struct.RCW56_ChA_D0, i_struct.RCW57_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5812b), l_data));

    load_dmem_8bit_fields(i_struct.RCW58_ChA_D0, i_struct.RCW59_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5812c), l_data));

    load_dmem_8bit_fields(i_struct.RCW5A_ChA_D0, i_struct.RCW5B_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5812d), l_data));

    load_dmem_8bit_fields(i_struct.RCW5C_ChA_D0, i_struct.RCW5D_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5812e), l_data));

    load_dmem_8bit_fields(i_struct.RCW5E_ChA_D0, i_struct.RCW5F_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5812f), l_data));

    load_dmem_8bit_fields(i_struct.RCW60_ChA_D0, i_struct.RCW61_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58130), l_data));

    load_dmem_8bit_fields(i_struct.RCW62_ChA_D0, i_struct.RCW63_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58131), l_data));

    load_dmem_8bit_fields(i_struct.RCW64_ChA_D0, i_struct.RCW65_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58132), l_data));

    load_dmem_8bit_fields(i_struct.RCW66_ChA_D0, i_struct.RCW67_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58133), l_data));

    load_dmem_8bit_fields(i_struct.RCW68_ChA_D0, i_struct.RCW69_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58134), l_data));

    load_dmem_8bit_fields(i_struct.RCW6A_ChA_D0, i_struct.RCW6B_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58135), l_data));

    load_dmem_8bit_fields(i_struct.RCW6C_ChA_D0, i_struct.RCW6D_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58136), l_data));

    load_dmem_8bit_fields(i_struct.RCW6E_ChA_D0, i_struct.RCW6F_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58137), l_data));

    load_dmem_8bit_fields(i_struct.RCW70_ChA_D0, i_struct.RCW71_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58138), l_data));

    load_dmem_8bit_fields(i_struct.RCW72_ChA_D0, i_struct.RCW73_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58139), l_data));

    load_dmem_8bit_fields(i_struct.RCW74_ChA_D0, i_struct.RCW75_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5813a), l_data));

    load_dmem_8bit_fields(i_struct.RCW76_ChA_D0, i_struct.RCW77_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5813b), l_data));

    load_dmem_8bit_fields(i_struct.RCW78_ChA_D0, i_struct.RCW79_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5813c), l_data));

    load_dmem_8bit_fields(i_struct.RCW7A_ChA_D0, i_struct.RCW7B_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5813d), l_data));

    load_dmem_8bit_fields(i_struct.RCW7C_ChA_D0, i_struct.RCW7D_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5813e), l_data));

    load_dmem_8bit_fields(i_struct.RCW7E_ChA_D0, i_struct.RCW7F_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5813f), l_data));

    load_dmem_8bit_fields(i_struct.BCW00_ChA_D0, i_struct.BCW01_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58140), l_data));

    load_dmem_8bit_fields(i_struct.BCW02_ChA_D0, i_struct.BCW03_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58141), l_data));

    load_dmem_8bit_fields(i_struct.BCW04_ChA_D0, i_struct.BCW05_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58142), l_data));

    load_dmem_8bit_fields(i_struct.BCW06_ChA_D0, i_struct.BCW07_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58143), l_data));

    load_dmem_8bit_fields(i_struct.BCW08_ChA_D0, i_struct.BCW09_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58144), l_data));

    load_dmem_8bit_fields(i_struct.BCW0A_ChA_D0, i_struct.BCW0B_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58145), l_data));

    load_dmem_8bit_fields(i_struct.BCW0C_ChA_D0, i_struct.BCW0D_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58146), l_data));

    load_dmem_8bit_fields(i_struct.BCW0E_ChA_D0, i_struct.BCW0F_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58147), l_data));

    load_dmem_8bit_fields(i_struct.BCW10_ChA_D0, i_struct.BCW11_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58148), l_data));

    load_dmem_8bit_fields(i_struct.BCW12_ChA_D0, i_struct.BCW13_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58149), l_data));

    load_dmem_8bit_fields(i_struct.BCW14_ChA_D0, i_struct.BCW15_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5814a), l_data));

    load_dmem_8bit_fields(i_struct.BCW16_ChA_D0, i_struct.BCW17_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5814b), l_data));

    load_dmem_8bit_fields(i_struct.BCW18_ChA_D0, i_struct.BCW19_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5814c), l_data));

    load_dmem_8bit_fields(i_struct.BCW1A_ChA_D0, i_struct.BCW1B_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5814d), l_data));

    load_dmem_8bit_fields(i_struct.BCW1C_ChA_D0, i_struct.BCW1D_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5814e), l_data));

    load_dmem_8bit_fields(i_struct.BCW1E_ChA_D0, i_struct.BCW1F_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5814f), l_data));

    load_dmem_8bit_fields(i_struct.BCW20_ChA_D0, i_struct.BCW21_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58150), l_data));

    load_dmem_8bit_fields(i_struct.BCW22_ChA_D0, i_struct.BCW23_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58151), l_data));

    load_dmem_8bit_fields(i_struct.BCW24_ChA_D0, i_struct.BCW25_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58152), l_data));

    load_dmem_8bit_fields(i_struct.BCW26_ChA_D0, i_struct.BCW27_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58153), l_data));

    load_dmem_8bit_fields(i_struct.BCW28_ChA_D0, i_struct.BCW29_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58154), l_data));

    load_dmem_8bit_fields(i_struct.BCW2A_ChA_D0, i_struct.BCW2B_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58155), l_data));

    load_dmem_8bit_fields(i_struct.BCW2C_ChA_D0, i_struct.BCW2D_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58156), l_data));

    load_dmem_8bit_fields(i_struct.BCW2E_ChA_D0, i_struct.BCW2F_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58157), l_data));

    load_dmem_8bit_fields(i_struct.BCW30_ChA_D0, i_struct.BCW31_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58158), l_data));

    load_dmem_8bit_fields(i_struct.BCW32_ChA_D0, i_struct.BCW33_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58159), l_data));

    load_dmem_8bit_fields(i_struct.BCW34_ChA_D0, i_struct.BCW35_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5815a), l_data));

    load_dmem_8bit_fields(i_struct.BCW36_ChA_D0, i_struct.BCW37_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5815b), l_data));

    load_dmem_8bit_fields(i_struct.BCW38_ChA_D0, i_struct.BCW39_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5815c), l_data));

    load_dmem_8bit_fields(i_struct.BCW3A_ChA_D0, i_struct.BCW3B_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5815d), l_data));

    load_dmem_8bit_fields(i_struct.BCW3C_ChA_D0, i_struct.BCW3D_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5815e), l_data));

    load_dmem_8bit_fields(i_struct.BCW3E_ChA_D0, i_struct.BCW3F_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5815f), l_data));

    load_dmem_8bit_fields(i_struct.BCW40_ChA_D0, i_struct.BCW41_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58160), l_data));

    load_dmem_8bit_fields(i_struct.BCW42_ChA_D0, i_struct.BCW43_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58161), l_data));

    load_dmem_8bit_fields(i_struct.BCW44_ChA_D0, i_struct.BCW45_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58162), l_data));

    load_dmem_8bit_fields(i_struct.BCW46_ChA_D0, i_struct.BCW47_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58163), l_data));

    load_dmem_8bit_fields(i_struct.BCW48_ChA_D0, i_struct.BCW49_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58164), l_data));

    load_dmem_8bit_fields(i_struct.BCW4A_ChA_D0, i_struct.BCW4B_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58165), l_data));

    load_dmem_8bit_fields(i_struct.BCW4C_ChA_D0, i_struct.BCW4D_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58166), l_data));

    load_dmem_8bit_fields(i_struct.BCW4E_ChA_D0, i_struct.BCW4F_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58167), l_data));

    load_dmem_8bit_fields(i_struct.BCW50_ChA_D0, i_struct.BCW51_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58168), l_data));

    load_dmem_8bit_fields(i_struct.BCW52_ChA_D0, i_struct.BCW53_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58169), l_data));

    load_dmem_8bit_fields(i_struct.BCW54_ChA_D0, i_struct.BCW55_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5816a), l_data));

    load_dmem_8bit_fields(i_struct.BCW56_ChA_D0, i_struct.BCW57_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5816b), l_data));

    load_dmem_8bit_fields(i_struct.BCW58_ChA_D0, i_struct.BCW59_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5816c), l_data));

    load_dmem_8bit_fields(i_struct.BCW5A_ChA_D0, i_struct.BCW5B_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5816d), l_data));

    load_dmem_8bit_fields(i_struct.BCW5C_ChA_D0, i_struct.BCW5D_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5816e), l_data));

    load_dmem_8bit_fields(i_struct.BCW5E_ChA_D0, i_struct.BCW5F_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5816f), l_data));

    load_dmem_8bit_fields(i_struct.BCW60_ChA_D0, i_struct.BCW61_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58170), l_data));

    load_dmem_8bit_fields(i_struct.BCW62_ChA_D0, i_struct.BCW63_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58171), l_data));

    load_dmem_8bit_fields(i_struct.BCW64_ChA_D0, i_struct.BCW65_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58172), l_data));

    load_dmem_8bit_fields(i_struct.BCW66_ChA_D0, i_struct.BCW67_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58173), l_data));

    load_dmem_8bit_fields(i_struct.BCW68_ChA_D0, i_struct.BCW69_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58174), l_data));

    load_dmem_8bit_fields(i_struct.BCW6A_ChA_D0, i_struct.BCW6B_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58175), l_data));

    load_dmem_8bit_fields(i_struct.BCW6C_ChA_D0, i_struct.BCW6D_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58176), l_data));

    load_dmem_8bit_fields(i_struct.BCW6E_ChA_D0, i_struct.BCW6F_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58177), l_data));

    load_dmem_8bit_fields(i_struct.BCW70_ChA_D0, i_struct.BCW71_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58178), l_data));

    load_dmem_8bit_fields(i_struct.BCW72_ChA_D0, i_struct.BCW73_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58179), l_data));

    load_dmem_8bit_fields(i_struct.BCW74_ChA_D0, i_struct.BCW75_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5817a), l_data));

    load_dmem_8bit_fields(i_struct.BCW76_ChA_D0, i_struct.BCW77_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5817b), l_data));

    load_dmem_8bit_fields(i_struct.BCW78_ChA_D0, i_struct.BCW79_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5817c), l_data));

    load_dmem_8bit_fields(i_struct.BCW7A_ChA_D0, i_struct.BCW7B_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5817d), l_data));

    load_dmem_8bit_fields(i_struct.BCW7C_ChA_D0, i_struct.BCW7D_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5817e), l_data));

    load_dmem_8bit_fields(i_struct.BCW7E_ChA_D0, i_struct.BCW7F_ChA_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5817f), l_data));

    load_dmem_8bit_fields(i_struct.RCW00_ChA_D1, i_struct.RCW01_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58180), l_data));

    load_dmem_8bit_fields(i_struct.RCW02_ChA_D1, i_struct.RCW03_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58181), l_data));

    load_dmem_8bit_fields(i_struct.RCW04_ChA_D1, i_struct.RCW05_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58182), l_data));

    load_dmem_8bit_fields(i_struct.RCW06_ChA_D1, i_struct.RCW07_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58183), l_data));

    load_dmem_8bit_fields(i_struct.RCW08_ChA_D1, i_struct.RCW09_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58184), l_data));

    load_dmem_8bit_fields(i_struct.RCW0A_ChA_D1, i_struct.RCW0B_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58185), l_data));

    load_dmem_8bit_fields(i_struct.RCW0C_ChA_D1, i_struct.RCW0D_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58186), l_data));

    load_dmem_8bit_fields(i_struct.RCW0E_ChA_D1, i_struct.RCW0F_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58187), l_data));

    load_dmem_8bit_fields(i_struct.RCW10_ChA_D1, i_struct.RCW11_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58188), l_data));

    load_dmem_8bit_fields(i_struct.RCW12_ChA_D1, i_struct.RCW13_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58189), l_data));

    load_dmem_8bit_fields(i_struct.RCW14_ChA_D1, i_struct.RCW15_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5818a), l_data));

    load_dmem_8bit_fields(i_struct.RCW16_ChA_D1, i_struct.RCW17_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5818b), l_data));

    load_dmem_8bit_fields(i_struct.RCW18_ChA_D1, i_struct.RCW19_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5818c), l_data));

    load_dmem_8bit_fields(i_struct.RCW1A_ChA_D1, i_struct.RCW1B_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5818d), l_data));

    load_dmem_8bit_fields(i_struct.RCW1C_ChA_D1, i_struct.RCW1D_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5818e), l_data));

    load_dmem_8bit_fields(i_struct.RCW1E_ChA_D1, i_struct.RCW1F_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5818f), l_data));

    load_dmem_8bit_fields(i_struct.RCW20_ChA_D1, i_struct.RCW21_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58190), l_data));

    load_dmem_8bit_fields(i_struct.RCW22_ChA_D1, i_struct.RCW23_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58191), l_data));

    load_dmem_8bit_fields(i_struct.RCW24_ChA_D1, i_struct.RCW25_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58192), l_data));

    load_dmem_8bit_fields(i_struct.RCW26_ChA_D1, i_struct.RCW27_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58193), l_data));

    load_dmem_8bit_fields(i_struct.RCW28_ChA_D1, i_struct.RCW29_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58194), l_data));

    load_dmem_8bit_fields(i_struct.RCW2A_ChA_D1, i_struct.RCW2B_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58195), l_data));

    load_dmem_8bit_fields(i_struct.RCW2C_ChA_D1, i_struct.RCW2D_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58196), l_data));

    load_dmem_8bit_fields(i_struct.RCW2E_ChA_D1, i_struct.RCW2F_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58197), l_data));

    load_dmem_8bit_fields(i_struct.RCW30_ChA_D1, i_struct.RCW31_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58198), l_data));

    load_dmem_8bit_fields(i_struct.RCW32_ChA_D1, i_struct.RCW33_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58199), l_data));

    load_dmem_8bit_fields(i_struct.RCW34_ChA_D1, i_struct.RCW35_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5819a), l_data));

    load_dmem_8bit_fields(i_struct.RCW36_ChA_D1, i_struct.RCW37_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5819b), l_data));

    load_dmem_8bit_fields(i_struct.RCW38_ChA_D1, i_struct.RCW39_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5819c), l_data));

    load_dmem_8bit_fields(i_struct.RCW3A_ChA_D1, i_struct.RCW3B_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5819d), l_data));

    load_dmem_8bit_fields(i_struct.RCW3C_ChA_D1, i_struct.RCW3D_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5819e), l_data));

    load_dmem_8bit_fields(i_struct.RCW3E_ChA_D1, i_struct.RCW3F_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5819f), l_data));

    load_dmem_8bit_fields(i_struct.RCW40_ChA_D1, i_struct.RCW41_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581a0), l_data));

    load_dmem_8bit_fields(i_struct.RCW42_ChA_D1, i_struct.RCW43_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581a1), l_data));

    load_dmem_8bit_fields(i_struct.RCW44_ChA_D1, i_struct.RCW45_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581a2), l_data));

    load_dmem_8bit_fields(i_struct.RCW46_ChA_D1, i_struct.RCW47_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581a3), l_data));

    load_dmem_8bit_fields(i_struct.RCW48_ChA_D1, i_struct.RCW49_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581a4), l_data));

    load_dmem_8bit_fields(i_struct.RCW4A_ChA_D1, i_struct.RCW4B_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581a5), l_data));

    load_dmem_8bit_fields(i_struct.RCW4C_ChA_D1, i_struct.RCW4D_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581a6), l_data));

    load_dmem_8bit_fields(i_struct.RCW4E_ChA_D1, i_struct.RCW4F_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581a7), l_data));

    load_dmem_8bit_fields(i_struct.RCW50_ChA_D1, i_struct.RCW51_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581a8), l_data));

    load_dmem_8bit_fields(i_struct.RCW52_ChA_D1, i_struct.RCW53_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581a9), l_data));

    load_dmem_8bit_fields(i_struct.RCW54_ChA_D1, i_struct.RCW55_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581aa), l_data));

    load_dmem_8bit_fields(i_struct.RCW56_ChA_D1, i_struct.RCW57_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581ab), l_data));

    load_dmem_8bit_fields(i_struct.RCW58_ChA_D1, i_struct.RCW59_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581ac), l_data));

    load_dmem_8bit_fields(i_struct.RCW5A_ChA_D1, i_struct.RCW5B_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581ad), l_data));

    load_dmem_8bit_fields(i_struct.RCW5C_ChA_D1, i_struct.RCW5D_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581ae), l_data));

    load_dmem_8bit_fields(i_struct.RCW5E_ChA_D1, i_struct.RCW5F_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581af), l_data));

    load_dmem_8bit_fields(i_struct.RCW60_ChA_D1, i_struct.RCW61_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581b0), l_data));

    load_dmem_8bit_fields(i_struct.RCW62_ChA_D1, i_struct.RCW63_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581b1), l_data));

    load_dmem_8bit_fields(i_struct.RCW64_ChA_D1, i_struct.RCW65_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581b2), l_data));

    load_dmem_8bit_fields(i_struct.RCW66_ChA_D1, i_struct.RCW67_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581b3), l_data));

    load_dmem_8bit_fields(i_struct.RCW68_ChA_D1, i_struct.RCW69_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581b4), l_data));

    load_dmem_8bit_fields(i_struct.RCW6A_ChA_D1, i_struct.RCW6B_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581b5), l_data));

    load_dmem_8bit_fields(i_struct.RCW6C_ChA_D1, i_struct.RCW6D_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581b6), l_data));

    load_dmem_8bit_fields(i_struct.RCW6E_ChA_D1, i_struct.RCW6F_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581b7), l_data));

    load_dmem_8bit_fields(i_struct.RCW70_ChA_D1, i_struct.RCW71_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581b8), l_data));

    load_dmem_8bit_fields(i_struct.RCW72_ChA_D1, i_struct.RCW73_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581b9), l_data));

    load_dmem_8bit_fields(i_struct.RCW74_ChA_D1, i_struct.RCW75_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581ba), l_data));

    load_dmem_8bit_fields(i_struct.RCW76_ChA_D1, i_struct.RCW77_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581bb), l_data));

    load_dmem_8bit_fields(i_struct.RCW78_ChA_D1, i_struct.RCW79_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581bc), l_data));

    load_dmem_8bit_fields(i_struct.RCW7A_ChA_D1, i_struct.RCW7B_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581bd), l_data));

    load_dmem_8bit_fields(i_struct.RCW7C_ChA_D1, i_struct.RCW7D_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581be), l_data));

    load_dmem_8bit_fields(i_struct.RCW7E_ChA_D1, i_struct.RCW7F_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581bf), l_data));

    load_dmem_8bit_fields(i_struct.BCW00_ChA_D1, i_struct.BCW01_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581c0), l_data));

    load_dmem_8bit_fields(i_struct.BCW02_ChA_D1, i_struct.BCW03_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581c1), l_data));

    load_dmem_8bit_fields(i_struct.BCW04_ChA_D1, i_struct.BCW05_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581c2), l_data));

    load_dmem_8bit_fields(i_struct.BCW06_ChA_D1, i_struct.BCW07_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581c3), l_data));

    load_dmem_8bit_fields(i_struct.BCW08_ChA_D1, i_struct.BCW09_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581c4), l_data));

    load_dmem_8bit_fields(i_struct.BCW0A_ChA_D1, i_struct.BCW0B_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581c5), l_data));

    load_dmem_8bit_fields(i_struct.BCW0C_ChA_D1, i_struct.BCW0D_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581c6), l_data));

    load_dmem_8bit_fields(i_struct.BCW0E_ChA_D1, i_struct.BCW0F_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581c7), l_data));

    load_dmem_8bit_fields(i_struct.BCW10_ChA_D1, i_struct.BCW11_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581c8), l_data));

    load_dmem_8bit_fields(i_struct.BCW12_ChA_D1, i_struct.BCW13_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581c9), l_data));

    load_dmem_8bit_fields(i_struct.BCW14_ChA_D1, i_struct.BCW15_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581ca), l_data));

    load_dmem_8bit_fields(i_struct.BCW16_ChA_D1, i_struct.BCW17_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581cb), l_data));

    load_dmem_8bit_fields(i_struct.BCW18_ChA_D1, i_struct.BCW19_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581cc), l_data));

    load_dmem_8bit_fields(i_struct.BCW1A_ChA_D1, i_struct.BCW1B_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581cd), l_data));

    load_dmem_8bit_fields(i_struct.BCW1C_ChA_D1, i_struct.BCW1D_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581ce), l_data));

    load_dmem_8bit_fields(i_struct.BCW1E_ChA_D1, i_struct.BCW1F_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581cf), l_data));

    load_dmem_8bit_fields(i_struct.BCW20_ChA_D1, i_struct.BCW21_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581d0), l_data));

    load_dmem_8bit_fields(i_struct.BCW22_ChA_D1, i_struct.BCW23_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581d1), l_data));

    load_dmem_8bit_fields(i_struct.BCW24_ChA_D1, i_struct.BCW25_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581d2), l_data));

    load_dmem_8bit_fields(i_struct.BCW26_ChA_D1, i_struct.BCW27_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581d3), l_data));

    load_dmem_8bit_fields(i_struct.BCW28_ChA_D1, i_struct.BCW29_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581d4), l_data));

    load_dmem_8bit_fields(i_struct.BCW2A_ChA_D1, i_struct.BCW2B_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581d5), l_data));

    load_dmem_8bit_fields(i_struct.BCW2C_ChA_D1, i_struct.BCW2D_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581d6), l_data));

    load_dmem_8bit_fields(i_struct.BCW2E_ChA_D1, i_struct.BCW2F_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581d7), l_data));

    load_dmem_8bit_fields(i_struct.BCW30_ChA_D1, i_struct.BCW31_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581d8), l_data));

    load_dmem_8bit_fields(i_struct.BCW32_ChA_D1, i_struct.BCW33_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581d9), l_data));

    load_dmem_8bit_fields(i_struct.BCW34_ChA_D1, i_struct.BCW35_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581da), l_data));

    load_dmem_8bit_fields(i_struct.BCW36_ChA_D1, i_struct.BCW37_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581db), l_data));

    load_dmem_8bit_fields(i_struct.BCW38_ChA_D1, i_struct.BCW39_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581dc), l_data));

    load_dmem_8bit_fields(i_struct.BCW3A_ChA_D1, i_struct.BCW3B_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581dd), l_data));

    load_dmem_8bit_fields(i_struct.BCW3C_ChA_D1, i_struct.BCW3D_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581de), l_data));

    load_dmem_8bit_fields(i_struct.BCW3E_ChA_D1, i_struct.BCW3F_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581df), l_data));

    load_dmem_8bit_fields(i_struct.BCW40_ChA_D1, i_struct.BCW41_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581e0), l_data));

    load_dmem_8bit_fields(i_struct.BCW42_ChA_D1, i_struct.BCW43_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581e1), l_data));

    load_dmem_8bit_fields(i_struct.BCW44_ChA_D1, i_struct.BCW45_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581e2), l_data));

    load_dmem_8bit_fields(i_struct.BCW46_ChA_D1, i_struct.BCW47_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581e3), l_data));

    load_dmem_8bit_fields(i_struct.BCW48_ChA_D1, i_struct.BCW49_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581e4), l_data));

    load_dmem_8bit_fields(i_struct.BCW4A_ChA_D1, i_struct.BCW4B_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581e5), l_data));

    load_dmem_8bit_fields(i_struct.BCW4C_ChA_D1, i_struct.BCW4D_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581e6), l_data));

    load_dmem_8bit_fields(i_struct.BCW4E_ChA_D1, i_struct.BCW4F_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581e7), l_data));

    load_dmem_8bit_fields(i_struct.BCW50_ChA_D1, i_struct.BCW51_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581e8), l_data));

    load_dmem_8bit_fields(i_struct.BCW52_ChA_D1, i_struct.BCW53_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581e9), l_data));

    load_dmem_8bit_fields(i_struct.BCW54_ChA_D1, i_struct.BCW55_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581ea), l_data));

    load_dmem_8bit_fields(i_struct.BCW56_ChA_D1, i_struct.BCW57_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581eb), l_data));

    load_dmem_8bit_fields(i_struct.BCW58_ChA_D1, i_struct.BCW59_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581ec), l_data));

    load_dmem_8bit_fields(i_struct.BCW5A_ChA_D1, i_struct.BCW5B_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581ed), l_data));

    load_dmem_8bit_fields(i_struct.BCW5C_ChA_D1, i_struct.BCW5D_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581ee), l_data));

    load_dmem_8bit_fields(i_struct.BCW5E_ChA_D1, i_struct.BCW5F_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581ef), l_data));

    load_dmem_8bit_fields(i_struct.BCW60_ChA_D1, i_struct.BCW61_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581f0), l_data));

    load_dmem_8bit_fields(i_struct.BCW62_ChA_D1, i_struct.BCW63_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581f1), l_data));

    load_dmem_8bit_fields(i_struct.BCW64_ChA_D1, i_struct.BCW65_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581f2), l_data));

    load_dmem_8bit_fields(i_struct.BCW66_ChA_D1, i_struct.BCW67_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581f3), l_data));

    load_dmem_8bit_fields(i_struct.BCW68_ChA_D1, i_struct.BCW69_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581f4), l_data));

    load_dmem_8bit_fields(i_struct.BCW6A_ChA_D1, i_struct.BCW6B_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581f5), l_data));

    load_dmem_8bit_fields(i_struct.BCW6C_ChA_D1, i_struct.BCW6D_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581f6), l_data));

    load_dmem_8bit_fields(i_struct.BCW6E_ChA_D1, i_struct.BCW6F_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581f7), l_data));

    load_dmem_8bit_fields(i_struct.BCW70_ChA_D1, i_struct.BCW71_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581f8), l_data));

    load_dmem_8bit_fields(i_struct.BCW72_ChA_D1, i_struct.BCW73_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581f9), l_data));

    load_dmem_8bit_fields(i_struct.BCW74_ChA_D1, i_struct.BCW75_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581fa), l_data));

    load_dmem_8bit_fields(i_struct.BCW76_ChA_D1, i_struct.BCW77_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581fb), l_data));

    load_dmem_8bit_fields(i_struct.BCW78_ChA_D1, i_struct.BCW79_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581fc), l_data));

    load_dmem_8bit_fields(i_struct.BCW7A_ChA_D1, i_struct.BCW7B_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581fd), l_data));

    load_dmem_8bit_fields(i_struct.BCW7C_ChA_D1, i_struct.BCW7D_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581fe), l_data));

    load_dmem_8bit_fields(i_struct.BCW7E_ChA_D1, i_struct.BCW7F_ChA_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581ff), l_data));

    load_dmem_8bit_fields(i_struct.RCW00_ChB_D0, i_struct.RCW01_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58200), l_data));

    load_dmem_8bit_fields(i_struct.RCW02_ChB_D0, i_struct.RCW03_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58201), l_data));

    load_dmem_8bit_fields(i_struct.RCW04_ChB_D0, i_struct.RCW05_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58202), l_data));

    load_dmem_8bit_fields(i_struct.RCW06_ChB_D0, i_struct.RCW07_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58203), l_data));

    load_dmem_8bit_fields(i_struct.RCW08_ChB_D0, i_struct.RCW09_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58204), l_data));

    load_dmem_8bit_fields(i_struct.RCW0A_ChB_D0, i_struct.RCW0B_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58205), l_data));

    load_dmem_8bit_fields(i_struct.RCW0C_ChB_D0, i_struct.RCW0D_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58206), l_data));

    load_dmem_8bit_fields(i_struct.RCW0E_ChB_D0, i_struct.RCW0F_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58207), l_data));

    load_dmem_8bit_fields(i_struct.RCW10_ChB_D0, i_struct.RCW11_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58208), l_data));

    load_dmem_8bit_fields(i_struct.RCW12_ChB_D0, i_struct.RCW13_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58209), l_data));

    load_dmem_8bit_fields(i_struct.RCW14_ChB_D0, i_struct.RCW15_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5820a), l_data));

    load_dmem_8bit_fields(i_struct.RCW16_ChB_D0, i_struct.RCW17_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5820b), l_data));

    load_dmem_8bit_fields(i_struct.RCW18_ChB_D0, i_struct.RCW19_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5820c), l_data));

    load_dmem_8bit_fields(i_struct.RCW1A_ChB_D0, i_struct.RCW1B_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5820d), l_data));

    load_dmem_8bit_fields(i_struct.RCW1C_ChB_D0, i_struct.RCW1D_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5820e), l_data));

    load_dmem_8bit_fields(i_struct.RCW1E_ChB_D0, i_struct.RCW1F_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5820f), l_data));

    load_dmem_8bit_fields(i_struct.RCW20_ChB_D0, i_struct.RCW21_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58210), l_data));

    load_dmem_8bit_fields(i_struct.RCW22_ChB_D0, i_struct.RCW23_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58211), l_data));

    load_dmem_8bit_fields(i_struct.RCW24_ChB_D0, i_struct.RCW25_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58212), l_data));

    load_dmem_8bit_fields(i_struct.RCW26_ChB_D0, i_struct.RCW27_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58213), l_data));

    load_dmem_8bit_fields(i_struct.RCW28_ChB_D0, i_struct.RCW29_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58214), l_data));

    load_dmem_8bit_fields(i_struct.RCW2A_ChB_D0, i_struct.RCW2B_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58215), l_data));

    load_dmem_8bit_fields(i_struct.RCW2C_ChB_D0, i_struct.RCW2D_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58216), l_data));

    load_dmem_8bit_fields(i_struct.RCW2E_ChB_D0, i_struct.RCW2F_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58217), l_data));

    load_dmem_8bit_fields(i_struct.RCW30_ChB_D0, i_struct.RCW31_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58218), l_data));

    load_dmem_8bit_fields(i_struct.RCW32_ChB_D0, i_struct.RCW33_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58219), l_data));

    load_dmem_8bit_fields(i_struct.RCW34_ChB_D0, i_struct.RCW35_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5821a), l_data));

    load_dmem_8bit_fields(i_struct.RCW36_ChB_D0, i_struct.RCW37_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5821b), l_data));

    load_dmem_8bit_fields(i_struct.RCW38_ChB_D0, i_struct.RCW39_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5821c), l_data));

    load_dmem_8bit_fields(i_struct.RCW3A_ChB_D0, i_struct.RCW3B_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5821d), l_data));

    load_dmem_8bit_fields(i_struct.RCW3C_ChB_D0, i_struct.RCW3D_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5821e), l_data));

    load_dmem_8bit_fields(i_struct.RCW3E_ChB_D0, i_struct.RCW3F_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5821f), l_data));

    load_dmem_8bit_fields(i_struct.RCW40_ChB_D0, i_struct.RCW41_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58220), l_data));

    load_dmem_8bit_fields(i_struct.RCW42_ChB_D0, i_struct.RCW43_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58221), l_data));

    load_dmem_8bit_fields(i_struct.RCW44_ChB_D0, i_struct.RCW45_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58222), l_data));

    load_dmem_8bit_fields(i_struct.RCW46_ChB_D0, i_struct.RCW47_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58223), l_data));

    load_dmem_8bit_fields(i_struct.RCW48_ChB_D0, i_struct.RCW49_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58224), l_data));

    load_dmem_8bit_fields(i_struct.RCW4A_ChB_D0, i_struct.RCW4B_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58225), l_data));

    load_dmem_8bit_fields(i_struct.RCW4C_ChB_D0, i_struct.RCW4D_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58226), l_data));

    load_dmem_8bit_fields(i_struct.RCW4E_ChB_D0, i_struct.RCW4F_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58227), l_data));

    load_dmem_8bit_fields(i_struct.RCW50_ChB_D0, i_struct.RCW51_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58228), l_data));

    load_dmem_8bit_fields(i_struct.RCW52_ChB_D0, i_struct.RCW53_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58229), l_data));

    load_dmem_8bit_fields(i_struct.RCW54_ChB_D0, i_struct.RCW55_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5822a), l_data));

    load_dmem_8bit_fields(i_struct.RCW56_ChB_D0, i_struct.RCW57_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5822b), l_data));

    load_dmem_8bit_fields(i_struct.RCW58_ChB_D0, i_struct.RCW59_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5822c), l_data));

    load_dmem_8bit_fields(i_struct.RCW5A_ChB_D0, i_struct.RCW5B_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5822d), l_data));

    load_dmem_8bit_fields(i_struct.RCW5C_ChB_D0, i_struct.RCW5D_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5822e), l_data));

    load_dmem_8bit_fields(i_struct.RCW5E_ChB_D0, i_struct.RCW5F_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5822f), l_data));

    load_dmem_8bit_fields(i_struct.RCW60_ChB_D0, i_struct.RCW61_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58230), l_data));

    load_dmem_8bit_fields(i_struct.RCW62_ChB_D0, i_struct.RCW63_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58231), l_data));

    load_dmem_8bit_fields(i_struct.RCW64_ChB_D0, i_struct.RCW65_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58232), l_data));

    load_dmem_8bit_fields(i_struct.RCW66_ChB_D0, i_struct.RCW67_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58233), l_data));

    load_dmem_8bit_fields(i_struct.RCW68_ChB_D0, i_struct.RCW69_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58234), l_data));

    load_dmem_8bit_fields(i_struct.RCW6A_ChB_D0, i_struct.RCW6B_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58235), l_data));

    load_dmem_8bit_fields(i_struct.RCW6C_ChB_D0, i_struct.RCW6D_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58236), l_data));

    load_dmem_8bit_fields(i_struct.RCW6E_ChB_D0, i_struct.RCW6F_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58237), l_data));

    load_dmem_8bit_fields(i_struct.RCW70_ChB_D0, i_struct.RCW71_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58238), l_data));

    load_dmem_8bit_fields(i_struct.RCW72_ChB_D0, i_struct.RCW73_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58239), l_data));

    load_dmem_8bit_fields(i_struct.RCW74_ChB_D0, i_struct.RCW75_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5823a), l_data));

    load_dmem_8bit_fields(i_struct.RCW76_ChB_D0, i_struct.RCW77_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5823b), l_data));

    load_dmem_8bit_fields(i_struct.RCW78_ChB_D0, i_struct.RCW79_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5823c), l_data));

    load_dmem_8bit_fields(i_struct.RCW7A_ChB_D0, i_struct.RCW7B_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5823d), l_data));

    load_dmem_8bit_fields(i_struct.RCW7C_ChB_D0, i_struct.RCW7D_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5823e), l_data));

    load_dmem_8bit_fields(i_struct.RCW7E_ChB_D0, i_struct.RCW7F_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5823f), l_data));

    load_dmem_8bit_fields(i_struct.BCW00_ChB_D0, i_struct.BCW01_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58240), l_data));

    load_dmem_8bit_fields(i_struct.BCW02_ChB_D0, i_struct.BCW03_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58241), l_data));

    load_dmem_8bit_fields(i_struct.BCW04_ChB_D0, i_struct.BCW05_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58242), l_data));

    load_dmem_8bit_fields(i_struct.BCW06_ChB_D0, i_struct.BCW07_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58243), l_data));

    load_dmem_8bit_fields(i_struct.BCW08_ChB_D0, i_struct.BCW09_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58244), l_data));

    load_dmem_8bit_fields(i_struct.BCW0A_ChB_D0, i_struct.BCW0B_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58245), l_data));

    load_dmem_8bit_fields(i_struct.BCW0C_ChB_D0, i_struct.BCW0D_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58246), l_data));

    load_dmem_8bit_fields(i_struct.BCW0E_ChB_D0, i_struct.BCW0F_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58247), l_data));

    load_dmem_8bit_fields(i_struct.BCW10_ChB_D0, i_struct.BCW11_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58248), l_data));

    load_dmem_8bit_fields(i_struct.BCW12_ChB_D0, i_struct.BCW13_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58249), l_data));

    load_dmem_8bit_fields(i_struct.BCW14_ChB_D0, i_struct.BCW15_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5824a), l_data));

    load_dmem_8bit_fields(i_struct.BCW16_ChB_D0, i_struct.BCW17_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5824b), l_data));

    load_dmem_8bit_fields(i_struct.BCW18_ChB_D0, i_struct.BCW19_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5824c), l_data));

    load_dmem_8bit_fields(i_struct.BCW1A_ChB_D0, i_struct.BCW1B_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5824d), l_data));

    load_dmem_8bit_fields(i_struct.BCW1C_ChB_D0, i_struct.BCW1D_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5824e), l_data));

    load_dmem_8bit_fields(i_struct.BCW1E_ChB_D0, i_struct.BCW1F_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5824f), l_data));

    load_dmem_8bit_fields(i_struct.BCW20_ChB_D0, i_struct.BCW21_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58250), l_data));

    load_dmem_8bit_fields(i_struct.BCW22_ChB_D0, i_struct.BCW23_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58251), l_data));

    load_dmem_8bit_fields(i_struct.BCW24_ChB_D0, i_struct.BCW25_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58252), l_data));

    load_dmem_8bit_fields(i_struct.BCW26_ChB_D0, i_struct.BCW27_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58253), l_data));

    load_dmem_8bit_fields(i_struct.BCW28_ChB_D0, i_struct.BCW29_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58254), l_data));

    load_dmem_8bit_fields(i_struct.BCW2A_ChB_D0, i_struct.BCW2B_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58255), l_data));

    load_dmem_8bit_fields(i_struct.BCW2C_ChB_D0, i_struct.BCW2D_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58256), l_data));

    load_dmem_8bit_fields(i_struct.BCW2E_ChB_D0, i_struct.BCW2F_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58257), l_data));

    load_dmem_8bit_fields(i_struct.BCW30_ChB_D0, i_struct.BCW31_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58258), l_data));

    load_dmem_8bit_fields(i_struct.BCW32_ChB_D0, i_struct.BCW33_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58259), l_data));

    load_dmem_8bit_fields(i_struct.BCW34_ChB_D0, i_struct.BCW35_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5825a), l_data));

    load_dmem_8bit_fields(i_struct.BCW36_ChB_D0, i_struct.BCW37_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5825b), l_data));

    load_dmem_8bit_fields(i_struct.BCW38_ChB_D0, i_struct.BCW39_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5825c), l_data));

    load_dmem_8bit_fields(i_struct.BCW3A_ChB_D0, i_struct.BCW3B_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5825d), l_data));

    load_dmem_8bit_fields(i_struct.BCW3C_ChB_D0, i_struct.BCW3D_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5825e), l_data));

    load_dmem_8bit_fields(i_struct.BCW3E_ChB_D0, i_struct.BCW3F_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5825f), l_data));

    load_dmem_8bit_fields(i_struct.BCW40_ChB_D0, i_struct.BCW41_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58260), l_data));

    load_dmem_8bit_fields(i_struct.BCW42_ChB_D0, i_struct.BCW43_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58261), l_data));

    load_dmem_8bit_fields(i_struct.BCW44_ChB_D0, i_struct.BCW45_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58262), l_data));

    load_dmem_8bit_fields(i_struct.BCW46_ChB_D0, i_struct.BCW47_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58263), l_data));

    load_dmem_8bit_fields(i_struct.BCW48_ChB_D0, i_struct.BCW49_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58264), l_data));

    load_dmem_8bit_fields(i_struct.BCW4A_ChB_D0, i_struct.BCW4B_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58265), l_data));

    load_dmem_8bit_fields(i_struct.BCW4C_ChB_D0, i_struct.BCW4D_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58266), l_data));

    load_dmem_8bit_fields(i_struct.BCW4E_ChB_D0, i_struct.BCW4F_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58267), l_data));

    load_dmem_8bit_fields(i_struct.BCW50_ChB_D0, i_struct.BCW51_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58268), l_data));

    load_dmem_8bit_fields(i_struct.BCW52_ChB_D0, i_struct.BCW53_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58269), l_data));

    load_dmem_8bit_fields(i_struct.BCW54_ChB_D0, i_struct.BCW55_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5826a), l_data));

    load_dmem_8bit_fields(i_struct.BCW56_ChB_D0, i_struct.BCW57_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5826b), l_data));

    load_dmem_8bit_fields(i_struct.BCW58_ChB_D0, i_struct.BCW59_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5826c), l_data));

    load_dmem_8bit_fields(i_struct.BCW5A_ChB_D0, i_struct.BCW5B_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5826d), l_data));

    load_dmem_8bit_fields(i_struct.BCW5C_ChB_D0, i_struct.BCW5D_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5826e), l_data));

    load_dmem_8bit_fields(i_struct.BCW5E_ChB_D0, i_struct.BCW5F_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5826f), l_data));

    load_dmem_8bit_fields(i_struct.BCW60_ChB_D0, i_struct.BCW61_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58270), l_data));

    load_dmem_8bit_fields(i_struct.BCW62_ChB_D0, i_struct.BCW63_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58271), l_data));

    load_dmem_8bit_fields(i_struct.BCW64_ChB_D0, i_struct.BCW65_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58272), l_data));

    load_dmem_8bit_fields(i_struct.BCW66_ChB_D0, i_struct.BCW67_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58273), l_data));

    load_dmem_8bit_fields(i_struct.BCW68_ChB_D0, i_struct.BCW69_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58274), l_data));

    load_dmem_8bit_fields(i_struct.BCW6A_ChB_D0, i_struct.BCW6B_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58275), l_data));

    load_dmem_8bit_fields(i_struct.BCW6C_ChB_D0, i_struct.BCW6D_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58276), l_data));

    load_dmem_8bit_fields(i_struct.BCW6E_ChB_D0, i_struct.BCW6F_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58277), l_data));

    load_dmem_8bit_fields(i_struct.BCW70_ChB_D0, i_struct.BCW71_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58278), l_data));

    load_dmem_8bit_fields(i_struct.BCW72_ChB_D0, i_struct.BCW73_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58279), l_data));

    load_dmem_8bit_fields(i_struct.BCW74_ChB_D0, i_struct.BCW75_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5827a), l_data));

    load_dmem_8bit_fields(i_struct.BCW76_ChB_D0, i_struct.BCW77_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5827b), l_data));

    load_dmem_8bit_fields(i_struct.BCW78_ChB_D0, i_struct.BCW79_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5827c), l_data));

    load_dmem_8bit_fields(i_struct.BCW7A_ChB_D0, i_struct.BCW7B_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5827d), l_data));

    load_dmem_8bit_fields(i_struct.BCW7C_ChB_D0, i_struct.BCW7D_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5827e), l_data));

    load_dmem_8bit_fields(i_struct.BCW7E_ChB_D0, i_struct.BCW7F_ChB_D0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5827f), l_data));

    load_dmem_8bit_fields(i_struct.RCW00_ChB_D1, i_struct.RCW01_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58280), l_data));

    load_dmem_8bit_fields(i_struct.RCW02_ChB_D1, i_struct.RCW03_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58281), l_data));

    load_dmem_8bit_fields(i_struct.RCW04_ChB_D1, i_struct.RCW05_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58282), l_data));

    load_dmem_8bit_fields(i_struct.RCW06_ChB_D1, i_struct.RCW07_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58283), l_data));

    load_dmem_8bit_fields(i_struct.RCW08_ChB_D1, i_struct.RCW09_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58284), l_data));

    load_dmem_8bit_fields(i_struct.RCW0A_ChB_D1, i_struct.RCW0B_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58285), l_data));

    load_dmem_8bit_fields(i_struct.RCW0C_ChB_D1, i_struct.RCW0D_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58286), l_data));

    load_dmem_8bit_fields(i_struct.RCW0E_ChB_D1, i_struct.RCW0F_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58287), l_data));

    load_dmem_8bit_fields(i_struct.RCW10_ChB_D1, i_struct.RCW11_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58288), l_data));

    load_dmem_8bit_fields(i_struct.RCW12_ChB_D1, i_struct.RCW13_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58289), l_data));

    load_dmem_8bit_fields(i_struct.RCW14_ChB_D1, i_struct.RCW15_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5828a), l_data));

    load_dmem_8bit_fields(i_struct.RCW16_ChB_D1, i_struct.RCW17_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5828b), l_data));

    load_dmem_8bit_fields(i_struct.RCW18_ChB_D1, i_struct.RCW19_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5828c), l_data));

    load_dmem_8bit_fields(i_struct.RCW1A_ChB_D1, i_struct.RCW1B_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5828d), l_data));

    load_dmem_8bit_fields(i_struct.RCW1C_ChB_D1, i_struct.RCW1D_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5828e), l_data));

    load_dmem_8bit_fields(i_struct.RCW1E_ChB_D1, i_struct.RCW1F_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5828f), l_data));

    load_dmem_8bit_fields(i_struct.RCW20_ChB_D1, i_struct.RCW21_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58290), l_data));

    load_dmem_8bit_fields(i_struct.RCW22_ChB_D1, i_struct.RCW23_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58291), l_data));

    load_dmem_8bit_fields(i_struct.RCW24_ChB_D1, i_struct.RCW25_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58292), l_data));

    load_dmem_8bit_fields(i_struct.RCW26_ChB_D1, i_struct.RCW27_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58293), l_data));

    load_dmem_8bit_fields(i_struct.RCW28_ChB_D1, i_struct.RCW29_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58294), l_data));

    load_dmem_8bit_fields(i_struct.RCW2A_ChB_D1, i_struct.RCW2B_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58295), l_data));

    load_dmem_8bit_fields(i_struct.RCW2C_ChB_D1, i_struct.RCW2D_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58296), l_data));

    load_dmem_8bit_fields(i_struct.RCW2E_ChB_D1, i_struct.RCW2F_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58297), l_data));

    load_dmem_8bit_fields(i_struct.RCW30_ChB_D1, i_struct.RCW31_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58298), l_data));

    load_dmem_8bit_fields(i_struct.RCW32_ChB_D1, i_struct.RCW33_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58299), l_data));

    load_dmem_8bit_fields(i_struct.RCW34_ChB_D1, i_struct.RCW35_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5829a), l_data));

    load_dmem_8bit_fields(i_struct.RCW36_ChB_D1, i_struct.RCW37_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5829b), l_data));

    load_dmem_8bit_fields(i_struct.RCW38_ChB_D1, i_struct.RCW39_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5829c), l_data));

    load_dmem_8bit_fields(i_struct.RCW3A_ChB_D1, i_struct.RCW3B_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5829d), l_data));

    load_dmem_8bit_fields(i_struct.RCW3C_ChB_D1, i_struct.RCW3D_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5829e), l_data));

    load_dmem_8bit_fields(i_struct.RCW3E_ChB_D1, i_struct.RCW3F_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5829f), l_data));

    load_dmem_8bit_fields(i_struct.RCW40_ChB_D1, i_struct.RCW41_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582a0), l_data));

    load_dmem_8bit_fields(i_struct.RCW42_ChB_D1, i_struct.RCW43_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582a1), l_data));

    load_dmem_8bit_fields(i_struct.RCW44_ChB_D1, i_struct.RCW45_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582a2), l_data));

    load_dmem_8bit_fields(i_struct.RCW46_ChB_D1, i_struct.RCW47_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582a3), l_data));

    load_dmem_8bit_fields(i_struct.RCW48_ChB_D1, i_struct.RCW49_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582a4), l_data));

    load_dmem_8bit_fields(i_struct.RCW4A_ChB_D1, i_struct.RCW4B_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582a5), l_data));

    load_dmem_8bit_fields(i_struct.RCW4C_ChB_D1, i_struct.RCW4D_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582a6), l_data));

    load_dmem_8bit_fields(i_struct.RCW4E_ChB_D1, i_struct.RCW4F_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582a7), l_data));

    load_dmem_8bit_fields(i_struct.RCW50_ChB_D1, i_struct.RCW51_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582a8), l_data));

    load_dmem_8bit_fields(i_struct.RCW52_ChB_D1, i_struct.RCW53_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582a9), l_data));

    load_dmem_8bit_fields(i_struct.RCW54_ChB_D1, i_struct.RCW55_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582aa), l_data));

    load_dmem_8bit_fields(i_struct.RCW56_ChB_D1, i_struct.RCW57_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582ab), l_data));

    load_dmem_8bit_fields(i_struct.RCW58_ChB_D1, i_struct.RCW59_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582ac), l_data));

    load_dmem_8bit_fields(i_struct.RCW5A_ChB_D1, i_struct.RCW5B_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582ad), l_data));

    load_dmem_8bit_fields(i_struct.RCW5C_ChB_D1, i_struct.RCW5D_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582ae), l_data));

    load_dmem_8bit_fields(i_struct.RCW5E_ChB_D1, i_struct.RCW5F_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582af), l_data));

    load_dmem_8bit_fields(i_struct.RCW60_ChB_D1, i_struct.RCW61_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582b0), l_data));

    load_dmem_8bit_fields(i_struct.RCW62_ChB_D1, i_struct.RCW63_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582b1), l_data));

    load_dmem_8bit_fields(i_struct.RCW64_ChB_D1, i_struct.RCW65_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582b2), l_data));

    load_dmem_8bit_fields(i_struct.RCW66_ChB_D1, i_struct.RCW67_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582b3), l_data));

    load_dmem_8bit_fields(i_struct.RCW68_ChB_D1, i_struct.RCW69_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582b4), l_data));

    load_dmem_8bit_fields(i_struct.RCW6A_ChB_D1, i_struct.RCW6B_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582b5), l_data));

    load_dmem_8bit_fields(i_struct.RCW6C_ChB_D1, i_struct.RCW6D_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582b6), l_data));

    load_dmem_8bit_fields(i_struct.RCW6E_ChB_D1, i_struct.RCW6F_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582b7), l_data));

    load_dmem_8bit_fields(i_struct.RCW70_ChB_D1, i_struct.RCW71_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582b8), l_data));

    load_dmem_8bit_fields(i_struct.RCW72_ChB_D1, i_struct.RCW73_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582b9), l_data));

    load_dmem_8bit_fields(i_struct.RCW74_ChB_D1, i_struct.RCW75_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582ba), l_data));

    load_dmem_8bit_fields(i_struct.RCW76_ChB_D1, i_struct.RCW77_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582bb), l_data));

    load_dmem_8bit_fields(i_struct.RCW78_ChB_D1, i_struct.RCW79_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582bc), l_data));

    load_dmem_8bit_fields(i_struct.RCW7A_ChB_D1, i_struct.RCW7B_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582bd), l_data));

    load_dmem_8bit_fields(i_struct.RCW7C_ChB_D1, i_struct.RCW7D_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582be), l_data));

    load_dmem_8bit_fields(i_struct.RCW7E_ChB_D1, i_struct.RCW7F_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582bf), l_data));

    load_dmem_8bit_fields(i_struct.BCW00_ChB_D1, i_struct.BCW01_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582c0), l_data));

    load_dmem_8bit_fields(i_struct.BCW02_ChB_D1, i_struct.BCW03_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582c1), l_data));

    load_dmem_8bit_fields(i_struct.BCW04_ChB_D1, i_struct.BCW05_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582c2), l_data));

    load_dmem_8bit_fields(i_struct.BCW06_ChB_D1, i_struct.BCW07_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582c3), l_data));

    load_dmem_8bit_fields(i_struct.BCW08_ChB_D1, i_struct.BCW09_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582c4), l_data));

    load_dmem_8bit_fields(i_struct.BCW0A_ChB_D1, i_struct.BCW0B_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582c5), l_data));

    load_dmem_8bit_fields(i_struct.BCW0C_ChB_D1, i_struct.BCW0D_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582c6), l_data));

    load_dmem_8bit_fields(i_struct.BCW0E_ChB_D1, i_struct.BCW0F_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582c7), l_data));

    load_dmem_8bit_fields(i_struct.BCW10_ChB_D1, i_struct.BCW11_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582c8), l_data));

    load_dmem_8bit_fields(i_struct.BCW12_ChB_D1, i_struct.BCW13_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582c9), l_data));

    load_dmem_8bit_fields(i_struct.BCW14_ChB_D1, i_struct.BCW15_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582ca), l_data));

    load_dmem_8bit_fields(i_struct.BCW16_ChB_D1, i_struct.BCW17_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582cb), l_data));

    load_dmem_8bit_fields(i_struct.BCW18_ChB_D1, i_struct.BCW19_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582cc), l_data));

    load_dmem_8bit_fields(i_struct.BCW1A_ChB_D1, i_struct.BCW1B_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582cd), l_data));

    load_dmem_8bit_fields(i_struct.BCW1C_ChB_D1, i_struct.BCW1D_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582ce), l_data));

    load_dmem_8bit_fields(i_struct.BCW1E_ChB_D1, i_struct.BCW1F_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582cf), l_data));

    load_dmem_8bit_fields(i_struct.BCW20_ChB_D1, i_struct.BCW21_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582d0), l_data));

    load_dmem_8bit_fields(i_struct.BCW22_ChB_D1, i_struct.BCW23_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582d1), l_data));

    load_dmem_8bit_fields(i_struct.BCW24_ChB_D1, i_struct.BCW25_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582d2), l_data));

    load_dmem_8bit_fields(i_struct.BCW26_ChB_D1, i_struct.BCW27_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582d3), l_data));

    load_dmem_8bit_fields(i_struct.BCW28_ChB_D1, i_struct.BCW29_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582d4), l_data));

    load_dmem_8bit_fields(i_struct.BCW2A_ChB_D1, i_struct.BCW2B_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582d5), l_data));

    load_dmem_8bit_fields(i_struct.BCW2C_ChB_D1, i_struct.BCW2D_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582d6), l_data));

    load_dmem_8bit_fields(i_struct.BCW2E_ChB_D1, i_struct.BCW2F_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582d7), l_data));

    load_dmem_8bit_fields(i_struct.BCW30_ChB_D1, i_struct.BCW31_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582d8), l_data));

    load_dmem_8bit_fields(i_struct.BCW32_ChB_D1, i_struct.BCW33_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582d9), l_data));

    load_dmem_8bit_fields(i_struct.BCW34_ChB_D1, i_struct.BCW35_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582da), l_data));

    load_dmem_8bit_fields(i_struct.BCW36_ChB_D1, i_struct.BCW37_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582db), l_data));

    load_dmem_8bit_fields(i_struct.BCW38_ChB_D1, i_struct.BCW39_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582dc), l_data));

    load_dmem_8bit_fields(i_struct.BCW3A_ChB_D1, i_struct.BCW3B_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582dd), l_data));

    load_dmem_8bit_fields(i_struct.BCW3C_ChB_D1, i_struct.BCW3D_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582de), l_data));

    load_dmem_8bit_fields(i_struct.BCW3E_ChB_D1, i_struct.BCW3F_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582df), l_data));

    load_dmem_8bit_fields(i_struct.BCW40_ChB_D1, i_struct.BCW41_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582e0), l_data));

    load_dmem_8bit_fields(i_struct.BCW42_ChB_D1, i_struct.BCW43_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582e1), l_data));

    load_dmem_8bit_fields(i_struct.BCW44_ChB_D1, i_struct.BCW45_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582e2), l_data));

    load_dmem_8bit_fields(i_struct.BCW46_ChB_D1, i_struct.BCW47_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582e3), l_data));

    load_dmem_8bit_fields(i_struct.BCW48_ChB_D1, i_struct.BCW49_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582e4), l_data));

    load_dmem_8bit_fields(i_struct.BCW4A_ChB_D1, i_struct.BCW4B_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582e5), l_data));

    load_dmem_8bit_fields(i_struct.BCW4C_ChB_D1, i_struct.BCW4D_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582e6), l_data));

    load_dmem_8bit_fields(i_struct.BCW4E_ChB_D1, i_struct.BCW4F_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582e7), l_data));

    load_dmem_8bit_fields(i_struct.BCW50_ChB_D1, i_struct.BCW51_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582e8), l_data));

    load_dmem_8bit_fields(i_struct.BCW52_ChB_D1, i_struct.BCW53_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582e9), l_data));

    load_dmem_8bit_fields(i_struct.BCW54_ChB_D1, i_struct.BCW55_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582ea), l_data));

    load_dmem_8bit_fields(i_struct.BCW56_ChB_D1, i_struct.BCW57_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582eb), l_data));

    load_dmem_8bit_fields(i_struct.BCW58_ChB_D1, i_struct.BCW59_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582ec), l_data));

    load_dmem_8bit_fields(i_struct.BCW5A_ChB_D1, i_struct.BCW5B_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582ed), l_data));

    load_dmem_8bit_fields(i_struct.BCW5C_ChB_D1, i_struct.BCW5D_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582ee), l_data));

    load_dmem_8bit_fields(i_struct.BCW5E_ChB_D1, i_struct.BCW5F_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582ef), l_data));

    load_dmem_8bit_fields(i_struct.BCW60_ChB_D1, i_struct.BCW61_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582f0), l_data));

    load_dmem_8bit_fields(i_struct.BCW62_ChB_D1, i_struct.BCW63_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582f1), l_data));

    load_dmem_8bit_fields(i_struct.BCW64_ChB_D1, i_struct.BCW65_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582f2), l_data));

    load_dmem_8bit_fields(i_struct.BCW66_ChB_D1, i_struct.BCW67_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582f3), l_data));

    load_dmem_8bit_fields(i_struct.BCW68_ChB_D1, i_struct.BCW69_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582f4), l_data));

    load_dmem_8bit_fields(i_struct.BCW6A_ChB_D1, i_struct.BCW6B_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582f5), l_data));

    load_dmem_8bit_fields(i_struct.BCW6C_ChB_D1, i_struct.BCW6D_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582f6), l_data));

    load_dmem_8bit_fields(i_struct.BCW6E_ChB_D1, i_struct.BCW6F_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582f7), l_data));

    load_dmem_8bit_fields(i_struct.BCW70_ChB_D1, i_struct.BCW71_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582f8), l_data));

    load_dmem_8bit_fields(i_struct.BCW72_ChB_D1, i_struct.BCW73_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582f9), l_data));

    load_dmem_8bit_fields(i_struct.BCW74_ChB_D1, i_struct.BCW75_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582fa), l_data));

    load_dmem_8bit_fields(i_struct.BCW76_ChB_D1, i_struct.BCW77_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582fb), l_data));

    load_dmem_8bit_fields(i_struct.BCW78_ChB_D1, i_struct.BCW79_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582fc), l_data));

    load_dmem_8bit_fields(i_struct.BCW7A_ChB_D1, i_struct.BCW7B_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582fd), l_data));

    load_dmem_8bit_fields(i_struct.BCW7C_ChB_D1, i_struct.BCW7D_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582fe), l_data));

    load_dmem_8bit_fields(i_struct.BCW7E_ChB_D1, i_struct.BCW7F_ChB_D1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582ff), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR0Nib0, i_struct.VrefDqR0Nib1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58300), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR0Nib2, i_struct.VrefDqR0Nib3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58301), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR0Nib4, i_struct.VrefDqR0Nib5, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58302), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR0Nib6, i_struct.VrefDqR0Nib7, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58303), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR0Nib8, i_struct.VrefDqR0Nib9, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58304), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR0Nib10, i_struct.VrefDqR0Nib11, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58305), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR0Nib12, i_struct.VrefDqR0Nib13, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58306), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR0Nib14, i_struct.VrefDqR0Nib15, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58307), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR0Nib16, i_struct.VrefDqR0Nib17, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58308), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR0Nib18, i_struct.VrefDqR0Nib19, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58309), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR1Nib0, i_struct.VrefDqR1Nib1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5830a), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR1Nib2, i_struct.VrefDqR1Nib3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5830b), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR1Nib4, i_struct.VrefDqR1Nib5, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5830c), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR1Nib6, i_struct.VrefDqR1Nib7, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5830d), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR1Nib8, i_struct.VrefDqR1Nib9, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5830e), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR1Nib10, i_struct.VrefDqR1Nib11, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5830f), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR1Nib12, i_struct.VrefDqR1Nib13, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58310), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR1Nib14, i_struct.VrefDqR1Nib15, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58311), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR1Nib16, i_struct.VrefDqR1Nib17, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58312), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR1Nib18, i_struct.VrefDqR1Nib19, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58313), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR2Nib0, i_struct.VrefDqR2Nib1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58314), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR2Nib2, i_struct.VrefDqR2Nib3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58315), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR2Nib4, i_struct.VrefDqR2Nib5, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58316), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR2Nib6, i_struct.VrefDqR2Nib7, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58317), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR2Nib8, i_struct.VrefDqR2Nib9, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58318), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR2Nib10, i_struct.VrefDqR2Nib11, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58319), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR2Nib12, i_struct.VrefDqR2Nib13, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5831a), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR2Nib14, i_struct.VrefDqR2Nib15, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5831b), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR2Nib16, i_struct.VrefDqR2Nib17, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5831c), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR2Nib18, i_struct.VrefDqR2Nib19, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5831d), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR3Nib0, i_struct.VrefDqR3Nib1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5831e), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR3Nib2, i_struct.VrefDqR3Nib3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5831f), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR3Nib4, i_struct.VrefDqR3Nib5, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58320), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR3Nib6, i_struct.VrefDqR3Nib7, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58321), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR3Nib8, i_struct.VrefDqR3Nib9, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58322), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR3Nib10, i_struct.VrefDqR3Nib11, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58323), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR3Nib12, i_struct.VrefDqR3Nib13, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58324), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR3Nib14, i_struct.VrefDqR3Nib15, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58325), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR3Nib16, i_struct.VrefDqR3Nib17, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58326), l_data));

    load_dmem_8bit_fields(i_struct.VrefDqR3Nib18, i_struct.VrefDqR3Nib19, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58327), l_data));

    load_dmem_8bit_fields(i_struct.MR3R0Nib0, i_struct.MR3R0Nib1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58328), l_data));

    load_dmem_8bit_fields(i_struct.MR3R0Nib2, i_struct.MR3R0Nib3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58329), l_data));

    load_dmem_8bit_fields(i_struct.MR3R0Nib4, i_struct.MR3R0Nib5, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5832a), l_data));

    load_dmem_8bit_fields(i_struct.MR3R0Nib6, i_struct.MR3R0Nib7, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5832b), l_data));

    load_dmem_8bit_fields(i_struct.MR3R0Nib8, i_struct.MR3R0Nib9, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5832c), l_data));

    load_dmem_8bit_fields(i_struct.MR3R0Nib10, i_struct.MR3R0Nib11, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5832d), l_data));

    load_dmem_8bit_fields(i_struct.MR3R0Nib12, i_struct.MR3R0Nib13, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5832e), l_data));

    load_dmem_8bit_fields(i_struct.MR3R0Nib14, i_struct.MR3R0Nib15, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5832f), l_data));

    load_dmem_8bit_fields(i_struct.MR3R0Nib16, i_struct.MR3R0Nib17, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58330), l_data));

    load_dmem_8bit_fields(i_struct.MR3R0Nib18, i_struct.MR3R0Nib19, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58331), l_data));

    load_dmem_8bit_fields(i_struct.MR3R1Nib0, i_struct.MR3R1Nib1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58332), l_data));

    load_dmem_8bit_fields(i_struct.MR3R1Nib2, i_struct.MR3R1Nib3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58333), l_data));

    load_dmem_8bit_fields(i_struct.MR3R1Nib4, i_struct.MR3R1Nib5, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58334), l_data));

    load_dmem_8bit_fields(i_struct.MR3R1Nib6, i_struct.MR3R1Nib7, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58335), l_data));

    load_dmem_8bit_fields(i_struct.MR3R1Nib8, i_struct.MR3R1Nib9, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58336), l_data));

    load_dmem_8bit_fields(i_struct.MR3R1Nib10, i_struct.MR3R1Nib11, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58337), l_data));

    load_dmem_8bit_fields(i_struct.MR3R1Nib12, i_struct.MR3R1Nib13, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58338), l_data));

    load_dmem_8bit_fields(i_struct.MR3R1Nib14, i_struct.MR3R1Nib15, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58339), l_data));

    load_dmem_8bit_fields(i_struct.MR3R1Nib16, i_struct.MR3R1Nib17, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5833a), l_data));

    load_dmem_8bit_fields(i_struct.MR3R1Nib18, i_struct.MR3R1Nib19, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5833b), l_data));

    load_dmem_8bit_fields(i_struct.MR3R2Nib0, i_struct.MR3R2Nib1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5833c), l_data));

    load_dmem_8bit_fields(i_struct.MR3R2Nib2, i_struct.MR3R2Nib3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5833d), l_data));

    load_dmem_8bit_fields(i_struct.MR3R2Nib4, i_struct.MR3R2Nib5, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5833e), l_data));

    load_dmem_8bit_fields(i_struct.MR3R2Nib6, i_struct.MR3R2Nib7, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5833f), l_data));

    load_dmem_8bit_fields(i_struct.MR3R2Nib8, i_struct.MR3R2Nib9, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58340), l_data));

    load_dmem_8bit_fields(i_struct.MR3R2Nib10, i_struct.MR3R2Nib11, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58341), l_data));

    load_dmem_8bit_fields(i_struct.MR3R2Nib12, i_struct.MR3R2Nib13, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58342), l_data));

    load_dmem_8bit_fields(i_struct.MR3R2Nib14, i_struct.MR3R2Nib15, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58343), l_data));

    load_dmem_8bit_fields(i_struct.MR3R2Nib16, i_struct.MR3R2Nib17, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58344), l_data));

    load_dmem_8bit_fields(i_struct.MR3R2Nib18, i_struct.MR3R2Nib19, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58345), l_data));

    load_dmem_8bit_fields(i_struct.MR3R3Nib0, i_struct.MR3R3Nib1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58346), l_data));

    load_dmem_8bit_fields(i_struct.MR3R3Nib2, i_struct.MR3R3Nib3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58347), l_data));

    load_dmem_8bit_fields(i_struct.MR3R3Nib4, i_struct.MR3R3Nib5, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58348), l_data));

    load_dmem_8bit_fields(i_struct.MR3R3Nib6, i_struct.MR3R3Nib7, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58349), l_data));

    load_dmem_8bit_fields(i_struct.MR3R3Nib8, i_struct.MR3R3Nib9, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5834a), l_data));

    load_dmem_8bit_fields(i_struct.MR3R3Nib10, i_struct.MR3R3Nib11, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5834b), l_data));

    load_dmem_8bit_fields(i_struct.MR3R3Nib12, i_struct.MR3R3Nib13, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5834c), l_data));

    load_dmem_8bit_fields(i_struct.MR3R3Nib14, i_struct.MR3R3Nib15, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5834d), l_data));

    load_dmem_8bit_fields(i_struct.MR3R3Nib16, i_struct.MR3R3Nib17, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5834e), l_data));

    load_dmem_8bit_fields(i_struct.MR3R3Nib18, i_struct.MR3R3Nib19, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5834f), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR0Nib0, i_struct.VrefCSR0Nib1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58350), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR0Nib2, i_struct.VrefCSR0Nib3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58351), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR0Nib4, i_struct.VrefCSR0Nib5, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58352), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR0Nib6, i_struct.VrefCSR0Nib7, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58353), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR0Nib8, i_struct.VrefCSR0Nib9, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58354), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR0Nib10, i_struct.VrefCSR0Nib11, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58355), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR0Nib12, i_struct.VrefCSR0Nib13, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58356), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR0Nib14, i_struct.VrefCSR0Nib15, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58357), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR0Nib16, i_struct.VrefCSR0Nib17, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58358), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR0Nib18, i_struct.VrefCSR0Nib19, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58359), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR1Nib0, i_struct.VrefCSR1Nib1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5835a), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR1Nib2, i_struct.VrefCSR1Nib3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5835b), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR1Nib4, i_struct.VrefCSR1Nib5, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5835c), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR1Nib6, i_struct.VrefCSR1Nib7, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5835d), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR1Nib8, i_struct.VrefCSR1Nib9, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5835e), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR1Nib10, i_struct.VrefCSR1Nib11, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5835f), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR1Nib12, i_struct.VrefCSR1Nib13, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58360), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR1Nib14, i_struct.VrefCSR1Nib15, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58361), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR1Nib16, i_struct.VrefCSR1Nib17, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58362), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR1Nib18, i_struct.VrefCSR1Nib19, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58363), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR2Nib0, i_struct.VrefCSR2Nib1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58364), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR2Nib2, i_struct.VrefCSR2Nib3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58365), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR2Nib4, i_struct.VrefCSR2Nib5, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58366), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR2Nib6, i_struct.VrefCSR2Nib7, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58367), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR2Nib8, i_struct.VrefCSR2Nib9, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58368), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR2Nib10, i_struct.VrefCSR2Nib11, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58369), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR2Nib12, i_struct.VrefCSR2Nib13, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5836a), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR2Nib14, i_struct.VrefCSR2Nib15, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5836b), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR2Nib16, i_struct.VrefCSR2Nib17, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5836c), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR2Nib18, i_struct.VrefCSR2Nib19, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5836d), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR3Nib0, i_struct.VrefCSR3Nib1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5836e), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR3Nib2, i_struct.VrefCSR3Nib3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5836f), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR3Nib4, i_struct.VrefCSR3Nib5, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58370), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR3Nib6, i_struct.VrefCSR3Nib7, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58371), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR3Nib8, i_struct.VrefCSR3Nib9, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58372), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR3Nib10, i_struct.VrefCSR3Nib11, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58373), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR3Nib12, i_struct.VrefCSR3Nib13, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58374), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR3Nib14, i_struct.VrefCSR3Nib15, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58375), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR3Nib16, i_struct.VrefCSR3Nib17, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58376), l_data));

    load_dmem_8bit_fields(i_struct.VrefCSR3Nib18, i_struct.VrefCSR3Nib19, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58377), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR0Nib0, i_struct.VrefCAR0Nib1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58378), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR0Nib2, i_struct.VrefCAR0Nib3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58379), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR0Nib4, i_struct.VrefCAR0Nib5, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5837a), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR0Nib6, i_struct.VrefCAR0Nib7, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5837b), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR0Nib8, i_struct.VrefCAR0Nib9, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5837c), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR0Nib10, i_struct.VrefCAR0Nib11, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5837d), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR0Nib12, i_struct.VrefCAR0Nib13, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5837e), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR0Nib14, i_struct.VrefCAR0Nib15, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5837f), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR0Nib16, i_struct.VrefCAR0Nib17, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58380), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR0Nib18, i_struct.VrefCAR0Nib19, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58381), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR1Nib0, i_struct.VrefCAR1Nib1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58382), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR1Nib2, i_struct.VrefCAR1Nib3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58383), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR1Nib4, i_struct.VrefCAR1Nib5, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58384), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR1Nib6, i_struct.VrefCAR1Nib7, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58385), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR1Nib8, i_struct.VrefCAR1Nib9, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58386), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR1Nib10, i_struct.VrefCAR1Nib11, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58387), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR1Nib12, i_struct.VrefCAR1Nib13, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58388), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR1Nib14, i_struct.VrefCAR1Nib15, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58389), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR1Nib16, i_struct.VrefCAR1Nib17, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5838a), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR1Nib18, i_struct.VrefCAR1Nib19, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5838b), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR2Nib0, i_struct.VrefCAR2Nib1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5838c), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR2Nib2, i_struct.VrefCAR2Nib3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5838d), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR2Nib4, i_struct.VrefCAR2Nib5, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5838e), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR2Nib6, i_struct.VrefCAR2Nib7, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5838f), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR2Nib8, i_struct.VrefCAR2Nib9, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58390), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR2Nib10, i_struct.VrefCAR2Nib11, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58391), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR2Nib12, i_struct.VrefCAR2Nib13, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58392), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR2Nib14, i_struct.VrefCAR2Nib15, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58393), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR2Nib16, i_struct.VrefCAR2Nib17, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58394), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR2Nib18, i_struct.VrefCAR2Nib19, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58395), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR3Nib0, i_struct.VrefCAR3Nib1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58396), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR3Nib2, i_struct.VrefCAR3Nib3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58397), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR3Nib4, i_struct.VrefCAR3Nib5, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58398), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR3Nib6, i_struct.VrefCAR3Nib7, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58399), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR3Nib8, i_struct.VrefCAR3Nib9, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5839a), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR3Nib10, i_struct.VrefCAR3Nib11, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5839b), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR3Nib12, i_struct.VrefCAR3Nib13, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5839c), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR3Nib14, i_struct.VrefCAR3Nib15, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5839d), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR3Nib16, i_struct.VrefCAR3Nib17, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5839e), l_data));

    load_dmem_8bit_fields(i_struct.VrefCAR3Nib18, i_struct.VrefCAR3Nib19, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5839f), l_data));

    load_dmem_8bit_fields(i_struct.DisabledDB0LaneR0, i_struct.DisabledDB1LaneR0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583a0), l_data));

    load_dmem_8bit_fields(i_struct.DisabledDB2LaneR0, i_struct.DisabledDB3LaneR0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583a1), l_data));

    load_dmem_8bit_fields(i_struct.DisabledDB4LaneR0, i_struct.DisabledDB5LaneR0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583a2), l_data));

    load_dmem_8bit_fields(i_struct.DisabledDB6LaneR0, i_struct.DisabledDB7LaneR0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583a3), l_data));

    load_dmem_8bit_fields(i_struct.DisabledDB8LaneR0, i_struct.DisabledDB9LaneR0, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583a4), l_data));

    load_dmem_8bit_fields(i_struct.DisabledDB0LaneR1, i_struct.DisabledDB1LaneR1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583a5), l_data));

    load_dmem_8bit_fields(i_struct.DisabledDB2LaneR1, i_struct.DisabledDB3LaneR1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583a6), l_data));

    load_dmem_8bit_fields(i_struct.DisabledDB4LaneR1, i_struct.DisabledDB5LaneR1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583a7), l_data));

    load_dmem_8bit_fields(i_struct.DisabledDB6LaneR1, i_struct.DisabledDB7LaneR1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583a8), l_data));

    load_dmem_8bit_fields(i_struct.DisabledDB8LaneR1, i_struct.DisabledDB9LaneR1, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583a9), l_data));

    load_dmem_8bit_fields(i_struct.DisabledDB0LaneR2, i_struct.DisabledDB1LaneR2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583aa), l_data));

    load_dmem_8bit_fields(i_struct.DisabledDB2LaneR2, i_struct.DisabledDB3LaneR2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583ab), l_data));

    load_dmem_8bit_fields(i_struct.DisabledDB4LaneR2, i_struct.DisabledDB5LaneR2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583ac), l_data));

    load_dmem_8bit_fields(i_struct.DisabledDB6LaneR2, i_struct.DisabledDB7LaneR2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583ad), l_data));

    load_dmem_8bit_fields(i_struct.DisabledDB8LaneR2, i_struct.DisabledDB9LaneR2, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583ae), l_data));

    load_dmem_8bit_fields(i_struct.DisabledDB0LaneR3, i_struct.DisabledDB1LaneR3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583af), l_data));

    load_dmem_8bit_fields(i_struct.DisabledDB2LaneR3, i_struct.DisabledDB3LaneR3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583b0), l_data));

    load_dmem_8bit_fields(i_struct.DisabledDB4LaneR3, i_struct.DisabledDB5LaneR3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583b1), l_data));

    load_dmem_8bit_fields(i_struct.DisabledDB6LaneR3, i_struct.DisabledDB7LaneR3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583b2), l_data));

    load_dmem_8bit_fields(i_struct.DisabledDB8LaneR3, i_struct.DisabledDB9LaneR3, l_data);
    FAPI_TRY(fapi2::putScom(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583b3), l_data));



fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Reads the DMEM regs and updates the message block values
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_struct the message block
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note Only loads the "output" fields into the msg block
/// @note The guts of this function is auto-generated using gen_dmem_func.py
///       located in the ekb-lab/ody/mem/tools
///
fapi2::ReturnCode read_msg_block(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                 _PMU_SMB_DDR5_1D_t& io_struct)
{
    // Packed variables cannot be passed by reference
    // As such, we have to use temp variables here
    uint8_t l_temp8_even = 0;
    uint8_t l_temp8_odd = 0;
    uint16_t l_temp16 = 0;

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58001),
                             l_temp16));
    io_struct.PmuRevision = l_temp16; // uint16_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58007),
                             l_temp8_even, l_temp8_odd));
    io_struct.CsTestFail = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5800a),
                             l_temp16));
    io_struct.ResultAddrOffset = l_temp16; // uint16_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58013),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RR_3_2 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RR_3_1 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58014),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RR_3_0 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RR_2_3 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58015),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RR_2_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RR_2_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58016),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RR_1_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RR_1_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58017),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RR_1_0 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RR_0_3 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58018),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RR_0_2 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RR_0_1 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58019),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RW_3_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RW_3_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5801a),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RW_3_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RW_3_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5801b),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RW_2_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RW_2_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5801c),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RW_2_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RW_2_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5801d),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RW_1_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RW_1_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5801e),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RW_1_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RW_1_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5801f),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RW_0_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RW_0_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58020),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RW_0_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RW_0_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58021),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WR_3_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WR_3_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58022),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WR_3_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WR_3_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58023),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WR_2_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WR_2_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58024),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WR_2_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WR_2_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58025),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WR_1_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WR_1_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58026),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WR_1_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WR_1_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58027),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WR_0_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WR_0_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58028),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WR_0_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WR_0_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58029),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WW_3_2 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WW_3_1 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5802a),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WW_3_0 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WW_2_3 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5802b),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WW_2_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WW_2_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5802c),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WW_1_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WW_1_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5802d),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WW_1_0 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WW_0_3 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5802e),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WW_0_2 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WW_0_1 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5803d),
                             l_temp8_even, l_temp8_odd));
    io_struct.CS_Dly_Margin_A0 = l_temp8_even; // uint8_t
    io_struct.CS_Vref_Margin_A0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5803e),
                             l_temp8_even, l_temp8_odd));
    io_struct.CA_Dly_Margin_A0 = l_temp8_even; // uint8_t
    io_struct.CA_Vref_Margin_A0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58050),
                             l_temp8_even, l_temp8_odd));
    io_struct.CS_Dly_Margin_A1 = l_temp8_even; // uint8_t
    io_struct.CS_Vref_Margin_A1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58051),
                             l_temp8_even, l_temp8_odd));
    io_struct.CA_Dly_Margin_A1 = l_temp8_even; // uint8_t
    io_struct.CA_Vref_Margin_A1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58063),
                             l_temp8_even, l_temp8_odd));
    io_struct.CS_Dly_Margin_A2 = l_temp8_even; // uint8_t
    io_struct.CS_Vref_Margin_A2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58064),
                             l_temp8_even, l_temp8_odd));
    io_struct.CA_Dly_Margin_A2 = l_temp8_even; // uint8_t
    io_struct.CA_Vref_Margin_A2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58076),
                             l_temp8_even, l_temp8_odd));
    io_struct.CS_Dly_Margin_A3 = l_temp8_even; // uint8_t
    io_struct.CS_Vref_Margin_A3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58077),
                             l_temp8_even, l_temp8_odd));
    io_struct.CA_Dly_Margin_A3 = l_temp8_even; // uint8_t
    io_struct.CA_Vref_Margin_A3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58080),
                             l_temp8_even, l_temp8_odd));
    io_struct.RxClkDly_Margin_A0 = l_temp8_even; // uint8_t
    io_struct.VrefDac_Margin_A0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58081),
                             l_temp8_even, l_temp8_odd));
    io_struct.TxDqDly_Margin_A0 = l_temp8_even; // uint8_t
    io_struct.DeviceVref_Margin_A0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58082),
                             l_temp8_even, l_temp8_odd));
    io_struct.RxClkDly_Margin_A1 = l_temp8_even; // uint8_t
    io_struct.VrefDac_Margin_A1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58083),
                             l_temp8_even, l_temp8_odd));
    io_struct.TxDqDly_Margin_A1 = l_temp8_even; // uint8_t
    io_struct.DeviceVref_Margin_A1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58084),
                             l_temp8_even, l_temp8_odd));
    io_struct.RxClkDly_Margin_A2 = l_temp8_even; // uint8_t
    io_struct.VrefDac_Margin_A2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58085),
                             l_temp8_even, l_temp8_odd));
    io_struct.TxDqDly_Margin_A2 = l_temp8_even; // uint8_t
    io_struct.DeviceVref_Margin_A2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58086),
                             l_temp8_even, l_temp8_odd));
    io_struct.RxClkDly_Margin_A3 = l_temp8_even; // uint8_t
    io_struct.VrefDac_Margin_A3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58087),
                             l_temp8_even, l_temp8_odd));
    io_struct.TxDqDly_Margin_A3 = l_temp8_even; // uint8_t
    io_struct.DeviceVref_Margin_A3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58089),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RR_3_2 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RR_3_1 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5808a),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RR_3_0 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RR_2_3 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5808b),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RR_2_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RR_2_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5808c),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RR_1_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RR_1_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5808d),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RR_1_0 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RR_0_3 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5808e),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RR_0_2 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RR_0_1 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5808f),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RW_3_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RW_3_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58090),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RW_3_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RW_3_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58091),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RW_2_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RW_2_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58092),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RW_2_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RW_2_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58093),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RW_1_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RW_1_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58094),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RW_1_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RW_1_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58095),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RW_0_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RW_0_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58096),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RW_0_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RW_0_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58097),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WR_3_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WR_3_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58098),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WR_3_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WR_3_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58099),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WR_2_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WR_2_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5809a),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WR_2_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WR_2_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5809b),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WR_1_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WR_1_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5809c),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WR_1_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WR_1_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5809d),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WR_0_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WR_0_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5809e),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WR_0_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WR_0_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5809f),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WW_3_2 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WW_3_1 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580a0),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WW_3_0 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WW_2_3 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580a1),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WW_2_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WW_2_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580a2),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WW_1_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WW_1_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580a3),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WW_1_0 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WW_0_3 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580a4),
                             l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WW_0_2 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WW_0_1 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580b3),
                             l_temp8_even, l_temp8_odd));
    io_struct.CS_Dly_Margin_B0 = l_temp8_even; // uint8_t
    io_struct.CS_Vref_Margin_B0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580b4),
                             l_temp8_even, l_temp8_odd));
    io_struct.CA_Dly_Margin_B0 = l_temp8_even; // uint8_t
    io_struct.CA_Vref_Margin_B0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580c6),
                             l_temp8_even, l_temp8_odd));
    io_struct.CS_Dly_Margin_B1 = l_temp8_even; // uint8_t
    io_struct.CS_Vref_Margin_B1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580c7),
                             l_temp8_even, l_temp8_odd));
    io_struct.CA_Dly_Margin_B1 = l_temp8_even; // uint8_t
    io_struct.CA_Vref_Margin_B1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580d9),
                             l_temp8_even, l_temp8_odd));
    io_struct.CS_Dly_Margin_B2 = l_temp8_even; // uint8_t
    io_struct.CS_Vref_Margin_B2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580da),
                             l_temp8_even, l_temp8_odd));
    io_struct.CA_Dly_Margin_B2 = l_temp8_even; // uint8_t
    io_struct.CA_Vref_Margin_B2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580ec),
                             l_temp8_even, l_temp8_odd));
    io_struct.CS_Dly_Margin_B3 = l_temp8_even; // uint8_t
    io_struct.CS_Vref_Margin_B3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580ed),
                             l_temp8_even, l_temp8_odd));
    io_struct.CA_Dly_Margin_B3 = l_temp8_even; // uint8_t
    io_struct.CA_Vref_Margin_B3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580f1),
                             l_temp8_even, l_temp8_odd));
    io_struct.Reserved1E3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580f6),
                             l_temp8_even, l_temp8_odd));
    io_struct.RxClkDly_Margin_B0 = l_temp8_even; // uint8_t
    io_struct.VrefDac_Margin_B0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580f7),
                             l_temp8_even, l_temp8_odd));
    io_struct.TxDqDly_Margin_B0 = l_temp8_even; // uint8_t
    io_struct.DeviceVref_Margin_B0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580f8),
                             l_temp8_even, l_temp8_odd));
    io_struct.RxClkDly_Margin_B1 = l_temp8_even; // uint8_t
    io_struct.VrefDac_Margin_B1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580f9),
                             l_temp8_even, l_temp8_odd));
    io_struct.TxDqDly_Margin_B1 = l_temp8_even; // uint8_t
    io_struct.DeviceVref_Margin_B1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580fa),
                             l_temp8_even, l_temp8_odd));
    io_struct.RxClkDly_Margin_B2 = l_temp8_even; // uint8_t
    io_struct.VrefDac_Margin_B2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580fb),
                             l_temp8_even, l_temp8_odd));
    io_struct.TxDqDly_Margin_B2 = l_temp8_even; // uint8_t
    io_struct.DeviceVref_Margin_B2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580fc),
                             l_temp8_even, l_temp8_odd));
    io_struct.RxClkDly_Margin_B3 = l_temp8_even; // uint8_t
    io_struct.VrefDac_Margin_B3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x580fd),
                             l_temp8_even, l_temp8_odd));
    io_struct.TxDqDly_Margin_B3 = l_temp8_even; // uint8_t
    io_struct.DeviceVref_Margin_B3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58120),
                             l_temp8_even, l_temp8_odd));
    io_struct.RCW40_ChA_D0 = l_temp8_even; // uint8_t
    io_struct.RCW41_ChA_D0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58121),
                             l_temp8_even, l_temp8_odd));
    io_struct.RCW42_ChA_D0 = l_temp8_even; // uint8_t
    io_struct.RCW43_ChA_D0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58122),
                             l_temp8_even, l_temp8_odd));
    io_struct.RCW44_ChA_D0 = l_temp8_even; // uint8_t
    io_struct.RCW45_ChA_D0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58123),
                             l_temp8_even, l_temp8_odd));
    io_struct.RCW46_ChA_D0 = l_temp8_even; // uint8_t
    io_struct.RCW47_ChA_D0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58124),
                             l_temp8_even, l_temp8_odd));
    io_struct.RCW48_ChA_D0 = l_temp8_even; // uint8_t
    io_struct.RCW49_ChA_D0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581a0),
                             l_temp8_even, l_temp8_odd));
    io_struct.RCW40_ChA_D1 = l_temp8_even; // uint8_t
    io_struct.RCW41_ChA_D1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581a1),
                             l_temp8_even, l_temp8_odd));
    io_struct.RCW42_ChA_D1 = l_temp8_even; // uint8_t
    io_struct.RCW43_ChA_D1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581a2),
                             l_temp8_even, l_temp8_odd));
    io_struct.RCW44_ChA_D1 = l_temp8_even; // uint8_t
    io_struct.RCW45_ChA_D1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581a3),
                             l_temp8_even, l_temp8_odd));
    io_struct.RCW46_ChA_D1 = l_temp8_even; // uint8_t
    io_struct.RCW47_ChA_D1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x581a4),
                             l_temp8_even, l_temp8_odd));
    io_struct.RCW48_ChA_D1 = l_temp8_even; // uint8_t
    io_struct.RCW49_ChA_D1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58220),
                             l_temp8_even, l_temp8_odd));
    io_struct.RCW40_ChB_D0 = l_temp8_even; // uint8_t
    io_struct.RCW41_ChB_D0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58221),
                             l_temp8_even, l_temp8_odd));
    io_struct.RCW42_ChB_D0 = l_temp8_even; // uint8_t
    io_struct.RCW43_ChB_D0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58222),
                             l_temp8_even, l_temp8_odd));
    io_struct.RCW44_ChB_D0 = l_temp8_even; // uint8_t
    io_struct.RCW45_ChB_D0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58223),
                             l_temp8_even, l_temp8_odd));
    io_struct.RCW46_ChB_D0 = l_temp8_even; // uint8_t
    io_struct.RCW47_ChB_D0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58224),
                             l_temp8_even, l_temp8_odd));
    io_struct.RCW48_ChB_D0 = l_temp8_even; // uint8_t
    io_struct.RCW49_ChB_D0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582a0),
                             l_temp8_even, l_temp8_odd));
    io_struct.RCW40_ChB_D1 = l_temp8_even; // uint8_t
    io_struct.RCW41_ChB_D1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582a1),
                             l_temp8_even, l_temp8_odd));
    io_struct.RCW42_ChB_D1 = l_temp8_even; // uint8_t
    io_struct.RCW43_ChB_D1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582a2),
                             l_temp8_even, l_temp8_odd));
    io_struct.RCW44_ChB_D1 = l_temp8_even; // uint8_t
    io_struct.RCW45_ChB_D1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582a3),
                             l_temp8_even, l_temp8_odd));
    io_struct.RCW46_ChB_D1 = l_temp8_even; // uint8_t
    io_struct.RCW47_ChB_D1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x582a4),
                             l_temp8_even, l_temp8_odd));
    io_struct.RCW48_ChB_D1 = l_temp8_even; // uint8_t
    io_struct.RCW49_ChB_D1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58300),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR0Nib0 = l_temp8_even; // uint8_t
    io_struct.VrefDqR0Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58301),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR0Nib2 = l_temp8_even; // uint8_t
    io_struct.VrefDqR0Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58302),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR0Nib4 = l_temp8_even; // uint8_t
    io_struct.VrefDqR0Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58303),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR0Nib6 = l_temp8_even; // uint8_t
    io_struct.VrefDqR0Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58304),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR0Nib8 = l_temp8_even; // uint8_t
    io_struct.VrefDqR0Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58305),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR0Nib10 = l_temp8_even; // uint8_t
    io_struct.VrefDqR0Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58306),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR0Nib12 = l_temp8_even; // uint8_t
    io_struct.VrefDqR0Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58307),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR0Nib14 = l_temp8_even; // uint8_t
    io_struct.VrefDqR0Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58308),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR0Nib16 = l_temp8_even; // uint8_t
    io_struct.VrefDqR0Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58309),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR0Nib18 = l_temp8_even; // uint8_t
    io_struct.VrefDqR0Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5830a),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR1Nib0 = l_temp8_even; // uint8_t
    io_struct.VrefDqR1Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5830b),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR1Nib2 = l_temp8_even; // uint8_t
    io_struct.VrefDqR1Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5830c),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR1Nib4 = l_temp8_even; // uint8_t
    io_struct.VrefDqR1Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5830d),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR1Nib6 = l_temp8_even; // uint8_t
    io_struct.VrefDqR1Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5830e),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR1Nib8 = l_temp8_even; // uint8_t
    io_struct.VrefDqR1Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5830f),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR1Nib10 = l_temp8_even; // uint8_t
    io_struct.VrefDqR1Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58310),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR1Nib12 = l_temp8_even; // uint8_t
    io_struct.VrefDqR1Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58311),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR1Nib14 = l_temp8_even; // uint8_t
    io_struct.VrefDqR1Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58312),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR1Nib16 = l_temp8_even; // uint8_t
    io_struct.VrefDqR1Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58313),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR1Nib18 = l_temp8_even; // uint8_t
    io_struct.VrefDqR1Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58314),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR2Nib0 = l_temp8_even; // uint8_t
    io_struct.VrefDqR2Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58315),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR2Nib2 = l_temp8_even; // uint8_t
    io_struct.VrefDqR2Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58316),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR2Nib4 = l_temp8_even; // uint8_t
    io_struct.VrefDqR2Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58317),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR2Nib6 = l_temp8_even; // uint8_t
    io_struct.VrefDqR2Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58318),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR2Nib8 = l_temp8_even; // uint8_t
    io_struct.VrefDqR2Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58319),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR2Nib10 = l_temp8_even; // uint8_t
    io_struct.VrefDqR2Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5831a),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR2Nib12 = l_temp8_even; // uint8_t
    io_struct.VrefDqR2Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5831b),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR2Nib14 = l_temp8_even; // uint8_t
    io_struct.VrefDqR2Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5831c),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR2Nib16 = l_temp8_even; // uint8_t
    io_struct.VrefDqR2Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5831d),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR2Nib18 = l_temp8_even; // uint8_t
    io_struct.VrefDqR2Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5831e),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR3Nib0 = l_temp8_even; // uint8_t
    io_struct.VrefDqR3Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5831f),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR3Nib2 = l_temp8_even; // uint8_t
    io_struct.VrefDqR3Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58320),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR3Nib4 = l_temp8_even; // uint8_t
    io_struct.VrefDqR3Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58321),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR3Nib6 = l_temp8_even; // uint8_t
    io_struct.VrefDqR3Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58322),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR3Nib8 = l_temp8_even; // uint8_t
    io_struct.VrefDqR3Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58323),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR3Nib10 = l_temp8_even; // uint8_t
    io_struct.VrefDqR3Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58324),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR3Nib12 = l_temp8_even; // uint8_t
    io_struct.VrefDqR3Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58325),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR3Nib14 = l_temp8_even; // uint8_t
    io_struct.VrefDqR3Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58326),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR3Nib16 = l_temp8_even; // uint8_t
    io_struct.VrefDqR3Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58327),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR3Nib18 = l_temp8_even; // uint8_t
    io_struct.VrefDqR3Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58328),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R0Nib0 = l_temp8_even; // uint8_t
    io_struct.MR3R0Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58329),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R0Nib2 = l_temp8_even; // uint8_t
    io_struct.MR3R0Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5832a),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R0Nib4 = l_temp8_even; // uint8_t
    io_struct.MR3R0Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5832b),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R0Nib6 = l_temp8_even; // uint8_t
    io_struct.MR3R0Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5832c),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R0Nib8 = l_temp8_even; // uint8_t
    io_struct.MR3R0Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5832d),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R0Nib10 = l_temp8_even; // uint8_t
    io_struct.MR3R0Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5832e),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R0Nib12 = l_temp8_even; // uint8_t
    io_struct.MR3R0Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5832f),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R0Nib14 = l_temp8_even; // uint8_t
    io_struct.MR3R0Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58330),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R0Nib16 = l_temp8_even; // uint8_t
    io_struct.MR3R0Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58331),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R0Nib18 = l_temp8_even; // uint8_t
    io_struct.MR3R0Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58332),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R1Nib0 = l_temp8_even; // uint8_t
    io_struct.MR3R1Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58333),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R1Nib2 = l_temp8_even; // uint8_t
    io_struct.MR3R1Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58334),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R1Nib4 = l_temp8_even; // uint8_t
    io_struct.MR3R1Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58335),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R1Nib6 = l_temp8_even; // uint8_t
    io_struct.MR3R1Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58336),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R1Nib8 = l_temp8_even; // uint8_t
    io_struct.MR3R1Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58337),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R1Nib10 = l_temp8_even; // uint8_t
    io_struct.MR3R1Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58338),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R1Nib12 = l_temp8_even; // uint8_t
    io_struct.MR3R1Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58339),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R1Nib14 = l_temp8_even; // uint8_t
    io_struct.MR3R1Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5833a),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R1Nib16 = l_temp8_even; // uint8_t
    io_struct.MR3R1Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5833b),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R1Nib18 = l_temp8_even; // uint8_t
    io_struct.MR3R1Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5833c),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R2Nib0 = l_temp8_even; // uint8_t
    io_struct.MR3R2Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5833d),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R2Nib2 = l_temp8_even; // uint8_t
    io_struct.MR3R2Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5833e),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R2Nib4 = l_temp8_even; // uint8_t
    io_struct.MR3R2Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5833f),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R2Nib6 = l_temp8_even; // uint8_t
    io_struct.MR3R2Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58340),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R2Nib8 = l_temp8_even; // uint8_t
    io_struct.MR3R2Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58341),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R2Nib10 = l_temp8_even; // uint8_t
    io_struct.MR3R2Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58342),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R2Nib12 = l_temp8_even; // uint8_t
    io_struct.MR3R2Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58343),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R2Nib14 = l_temp8_even; // uint8_t
    io_struct.MR3R2Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58344),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R2Nib16 = l_temp8_even; // uint8_t
    io_struct.MR3R2Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58345),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R2Nib18 = l_temp8_even; // uint8_t
    io_struct.MR3R2Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58346),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R3Nib0 = l_temp8_even; // uint8_t
    io_struct.MR3R3Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58347),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R3Nib2 = l_temp8_even; // uint8_t
    io_struct.MR3R3Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58348),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R3Nib4 = l_temp8_even; // uint8_t
    io_struct.MR3R3Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58349),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R3Nib6 = l_temp8_even; // uint8_t
    io_struct.MR3R3Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5834a),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R3Nib8 = l_temp8_even; // uint8_t
    io_struct.MR3R3Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5834b),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R3Nib10 = l_temp8_even; // uint8_t
    io_struct.MR3R3Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5834c),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R3Nib12 = l_temp8_even; // uint8_t
    io_struct.MR3R3Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5834d),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R3Nib14 = l_temp8_even; // uint8_t
    io_struct.MR3R3Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5834e),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R3Nib16 = l_temp8_even; // uint8_t
    io_struct.MR3R3Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5834f),
                             l_temp8_even, l_temp8_odd));
    io_struct.MR3R3Nib18 = l_temp8_even; // uint8_t
    io_struct.MR3R3Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58350),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR0Nib0 = l_temp8_even; // uint8_t
    io_struct.VrefCSR0Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58351),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR0Nib2 = l_temp8_even; // uint8_t
    io_struct.VrefCSR0Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58352),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR0Nib4 = l_temp8_even; // uint8_t
    io_struct.VrefCSR0Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58353),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR0Nib6 = l_temp8_even; // uint8_t
    io_struct.VrefCSR0Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58354),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR0Nib8 = l_temp8_even; // uint8_t
    io_struct.VrefCSR0Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58355),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR0Nib10 = l_temp8_even; // uint8_t
    io_struct.VrefCSR0Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58356),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR0Nib12 = l_temp8_even; // uint8_t
    io_struct.VrefCSR0Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58357),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR0Nib14 = l_temp8_even; // uint8_t
    io_struct.VrefCSR0Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58358),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR0Nib16 = l_temp8_even; // uint8_t
    io_struct.VrefCSR0Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58359),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR0Nib18 = l_temp8_even; // uint8_t
    io_struct.VrefCSR0Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5835a),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR1Nib0 = l_temp8_even; // uint8_t
    io_struct.VrefCSR1Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5835b),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR1Nib2 = l_temp8_even; // uint8_t
    io_struct.VrefCSR1Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5835c),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR1Nib4 = l_temp8_even; // uint8_t
    io_struct.VrefCSR1Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5835d),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR1Nib6 = l_temp8_even; // uint8_t
    io_struct.VrefCSR1Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5835e),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR1Nib8 = l_temp8_even; // uint8_t
    io_struct.VrefCSR1Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5835f),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR1Nib10 = l_temp8_even; // uint8_t
    io_struct.VrefCSR1Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58360),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR1Nib12 = l_temp8_even; // uint8_t
    io_struct.VrefCSR1Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58361),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR1Nib14 = l_temp8_even; // uint8_t
    io_struct.VrefCSR1Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58362),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR1Nib16 = l_temp8_even; // uint8_t
    io_struct.VrefCSR1Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58363),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR1Nib18 = l_temp8_even; // uint8_t
    io_struct.VrefCSR1Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58364),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR2Nib0 = l_temp8_even; // uint8_t
    io_struct.VrefCSR2Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58365),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR2Nib2 = l_temp8_even; // uint8_t
    io_struct.VrefCSR2Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58366),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR2Nib4 = l_temp8_even; // uint8_t
    io_struct.VrefCSR2Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58367),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR2Nib6 = l_temp8_even; // uint8_t
    io_struct.VrefCSR2Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58368),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR2Nib8 = l_temp8_even; // uint8_t
    io_struct.VrefCSR2Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58369),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR2Nib10 = l_temp8_even; // uint8_t
    io_struct.VrefCSR2Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5836a),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR2Nib12 = l_temp8_even; // uint8_t
    io_struct.VrefCSR2Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5836b),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR2Nib14 = l_temp8_even; // uint8_t
    io_struct.VrefCSR2Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5836c),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR2Nib16 = l_temp8_even; // uint8_t
    io_struct.VrefCSR2Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5836d),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR2Nib18 = l_temp8_even; // uint8_t
    io_struct.VrefCSR2Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5836e),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR3Nib0 = l_temp8_even; // uint8_t
    io_struct.VrefCSR3Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5836f),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR3Nib2 = l_temp8_even; // uint8_t
    io_struct.VrefCSR3Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58370),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR3Nib4 = l_temp8_even; // uint8_t
    io_struct.VrefCSR3Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58371),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR3Nib6 = l_temp8_even; // uint8_t
    io_struct.VrefCSR3Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58372),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR3Nib8 = l_temp8_even; // uint8_t
    io_struct.VrefCSR3Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58373),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR3Nib10 = l_temp8_even; // uint8_t
    io_struct.VrefCSR3Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58374),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR3Nib12 = l_temp8_even; // uint8_t
    io_struct.VrefCSR3Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58375),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR3Nib14 = l_temp8_even; // uint8_t
    io_struct.VrefCSR3Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58376),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR3Nib16 = l_temp8_even; // uint8_t
    io_struct.VrefCSR3Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58377),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR3Nib18 = l_temp8_even; // uint8_t
    io_struct.VrefCSR3Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58378),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR0Nib0 = l_temp8_even; // uint8_t
    io_struct.VrefCAR0Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58379),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR0Nib2 = l_temp8_even; // uint8_t
    io_struct.VrefCAR0Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5837a),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR0Nib4 = l_temp8_even; // uint8_t
    io_struct.VrefCAR0Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5837b),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR0Nib6 = l_temp8_even; // uint8_t
    io_struct.VrefCAR0Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5837c),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR0Nib8 = l_temp8_even; // uint8_t
    io_struct.VrefCAR0Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5837d),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR0Nib10 = l_temp8_even; // uint8_t
    io_struct.VrefCAR0Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5837e),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR0Nib12 = l_temp8_even; // uint8_t
    io_struct.VrefCAR0Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5837f),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR0Nib14 = l_temp8_even; // uint8_t
    io_struct.VrefCAR0Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58380),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR0Nib16 = l_temp8_even; // uint8_t
    io_struct.VrefCAR0Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58381),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR0Nib18 = l_temp8_even; // uint8_t
    io_struct.VrefCAR0Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58382),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR1Nib0 = l_temp8_even; // uint8_t
    io_struct.VrefCAR1Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58383),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR1Nib2 = l_temp8_even; // uint8_t
    io_struct.VrefCAR1Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58384),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR1Nib4 = l_temp8_even; // uint8_t
    io_struct.VrefCAR1Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58385),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR1Nib6 = l_temp8_even; // uint8_t
    io_struct.VrefCAR1Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58386),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR1Nib8 = l_temp8_even; // uint8_t
    io_struct.VrefCAR1Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58387),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR1Nib10 = l_temp8_even; // uint8_t
    io_struct.VrefCAR1Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58388),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR1Nib12 = l_temp8_even; // uint8_t
    io_struct.VrefCAR1Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58389),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR1Nib14 = l_temp8_even; // uint8_t
    io_struct.VrefCAR1Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5838a),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR1Nib16 = l_temp8_even; // uint8_t
    io_struct.VrefCAR1Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5838b),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR1Nib18 = l_temp8_even; // uint8_t
    io_struct.VrefCAR1Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5838c),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR2Nib0 = l_temp8_even; // uint8_t
    io_struct.VrefCAR2Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5838d),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR2Nib2 = l_temp8_even; // uint8_t
    io_struct.VrefCAR2Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5838e),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR2Nib4 = l_temp8_even; // uint8_t
    io_struct.VrefCAR2Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5838f),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR2Nib6 = l_temp8_even; // uint8_t
    io_struct.VrefCAR2Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58390),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR2Nib8 = l_temp8_even; // uint8_t
    io_struct.VrefCAR2Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58391),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR2Nib10 = l_temp8_even; // uint8_t
    io_struct.VrefCAR2Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58392),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR2Nib12 = l_temp8_even; // uint8_t
    io_struct.VrefCAR2Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58393),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR2Nib14 = l_temp8_even; // uint8_t
    io_struct.VrefCAR2Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58394),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR2Nib16 = l_temp8_even; // uint8_t
    io_struct.VrefCAR2Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58395),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR2Nib18 = l_temp8_even; // uint8_t
    io_struct.VrefCAR2Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58396),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR3Nib0 = l_temp8_even; // uint8_t
    io_struct.VrefCAR3Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58397),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR3Nib2 = l_temp8_even; // uint8_t
    io_struct.VrefCAR3Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58398),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR3Nib4 = l_temp8_even; // uint8_t
    io_struct.VrefCAR3Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58399),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR3Nib6 = l_temp8_even; // uint8_t
    io_struct.VrefCAR3Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5839a),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR3Nib8 = l_temp8_even; // uint8_t
    io_struct.VrefCAR3Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5839b),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR3Nib10 = l_temp8_even; // uint8_t
    io_struct.VrefCAR3Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5839c),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR3Nib12 = l_temp8_even; // uint8_t
    io_struct.VrefCAR3Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5839d),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR3Nib14 = l_temp8_even; // uint8_t
    io_struct.VrefCAR3Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5839e),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR3Nib16 = l_temp8_even; // uint8_t
    io_struct.VrefCAR3Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x5839f),
                             l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR3Nib18 = l_temp8_even; // uint8_t
    io_struct.VrefCAR3Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583a0),
                             l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB0LaneR0 = l_temp8_even; // uint8_t
    io_struct.DisabledDB1LaneR0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583a1),
                             l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB2LaneR0 = l_temp8_even; // uint8_t
    io_struct.DisabledDB3LaneR0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583a2),
                             l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB4LaneR0 = l_temp8_even; // uint8_t
    io_struct.DisabledDB5LaneR0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583a3),
                             l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB6LaneR0 = l_temp8_even; // uint8_t
    io_struct.DisabledDB7LaneR0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583a4),
                             l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB8LaneR0 = l_temp8_even; // uint8_t
    io_struct.DisabledDB9LaneR0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583a5),
                             l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB0LaneR1 = l_temp8_even; // uint8_t
    io_struct.DisabledDB1LaneR1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583a6),
                             l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB2LaneR1 = l_temp8_even; // uint8_t
    io_struct.DisabledDB3LaneR1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583a7),
                             l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB4LaneR1 = l_temp8_even; // uint8_t
    io_struct.DisabledDB5LaneR1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583a8),
                             l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB6LaneR1 = l_temp8_even; // uint8_t
    io_struct.DisabledDB7LaneR1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583a9),
                             l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB8LaneR1 = l_temp8_even; // uint8_t
    io_struct.DisabledDB9LaneR1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583aa),
                             l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB0LaneR2 = l_temp8_even; // uint8_t
    io_struct.DisabledDB1LaneR2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583ab),
                             l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB2LaneR2 = l_temp8_even; // uint8_t
    io_struct.DisabledDB3LaneR2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583ac),
                             l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB4LaneR2 = l_temp8_even; // uint8_t
    io_struct.DisabledDB5LaneR2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583ad),
                             l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB6LaneR2 = l_temp8_even; // uint8_t
    io_struct.DisabledDB7LaneR2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583ae),
                             l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB8LaneR2 = l_temp8_even; // uint8_t
    io_struct.DisabledDB9LaneR2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583af),
                             l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB0LaneR3 = l_temp8_even; // uint8_t
    io_struct.DisabledDB1LaneR3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583b0),
                             l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB2LaneR3 = l_temp8_even; // uint8_t
    io_struct.DisabledDB3LaneR3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583b1),
                             l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB4LaneR3 = l_temp8_even; // uint8_t
    io_struct.DisabledDB5LaneR3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583b2),
                             l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB6LaneR3 = l_temp8_even; // uint8_t
    io_struct.DisabledDB7LaneR3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583b3),
                             l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB8LaneR3 = l_temp8_even; // uint8_t
    io_struct.DisabledDB9LaneR3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583b4),
                             l_temp8_even, l_temp8_odd));
    io_struct.QCS_Dly_Margin_A0 = l_temp8_even; // uint8_t
    io_struct.QCA_Dly_Margin_A0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583b5),
                             l_temp8_even, l_temp8_odd));
    io_struct.QCS_Dly_Margin_A1 = l_temp8_even; // uint8_t
    io_struct.QCA_Dly_Margin_A1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583b6),
                             l_temp8_even, l_temp8_odd));
    io_struct.QCS_Dly_Margin_A2 = l_temp8_even; // uint8_t
    io_struct.QCA_Dly_Margin_A2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583b7),
                             l_temp8_even, l_temp8_odd));
    io_struct.QCS_Dly_Margin_A3 = l_temp8_even; // uint8_t
    io_struct.QCA_Dly_Margin_A3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583b8),
                             l_temp8_even, l_temp8_odd));
    io_struct.QCS_Dly_Margin_B0 = l_temp8_even; // uint8_t
    io_struct.QCA_Dly_Margin_B0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583b9),
                             l_temp8_even, l_temp8_odd));
    io_struct.QCS_Dly_Margin_B1 = l_temp8_even; // uint8_t
    io_struct.QCA_Dly_Margin_B1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583ba),
                             l_temp8_even, l_temp8_odd));
    io_struct.QCS_Dly_Margin_B2 = l_temp8_even; // uint8_t
    io_struct.QCA_Dly_Margin_B2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583bb),
                             l_temp8_even, l_temp8_odd));
    io_struct.QCS_Dly_Margin_B3 = l_temp8_even; // uint8_t
    io_struct.QCA_Dly_Margin_B3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583bc),
                             l_temp16));
    io_struct.PmuInternalRev0 = l_temp16; // uint16_t

    FAPI_TRY(read_dmem_field(i_target, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x583bd),
                             l_temp16));
    io_struct.PmuInternalRev1 = l_temp16; // uint16_t


fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper to read mode register data into attributes
/// @tparam MR the mode register class for which to process data
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank_infos the rank information class vector
/// @param[in] i_data_array the array of data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
template<typename MR>
fapi2::ReturnCode read_mr_from_block(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     const std::vector<mss::rank::info<mss::mc_type::ODYSSEY>>& i_rank_infos,
                                     const uint8_t (&i_data_array)[mss::ody::MAX_RANK_PER_PHY][mss::ody::MAX_NIBBLES_PER_PORT])
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    uint8_t l_dram_width = 0;
    MR l_mr(i_target, l_rc);

    FAPI_TRY(mss::attr::get_dram_width(i_target, l_dram_width));

    {
        const uint8_t INDEX = l_dram_width == fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X8 ? NIBBLES_PER_BYTE : 1;

        // Loops over all ranks
        for(const auto& l_rank_info : i_rank_infos)
        {
            // Loops over all of the DRAM
            uint8_t l_mc_dram = 0;

            for(uint8_t l_phy_dram = 0; l_phy_dram < mss::ody::MAX_NIBBLES_PER_PORT; l_phy_dram += INDEX, ++l_mc_dram)
            {
                FAPI_TRY(l_mr.read_from_data(l_rank_info, i_data_array[l_rank_info.get_phy_rank()][l_phy_dram], l_mc_dram));
            }
        }
    }

    FAPI_TRY(l_mr.set_attribute(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets the MR3 attributes based upon the outputted data from draminit
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank_infos the rank information class vector
/// @param[in] i_msg_blk message block structure
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode set_mr3_attributes(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     const std::vector<mss::rank::info<mss::mc_type::ODYSSEY>>& i_rank_infos,
                                     const _PMU_SMB_DDR5_1D_t& i_msg_block)
{
    // Assigns the data from the message block so it is easy to access
    const uint8_t DATA_ARRAY[mss::ody::MAX_RANK_PER_PHY][mss::ody::MAX_NIBBLES_PER_PORT] =
    {
        // Rank 0
        {
            i_msg_block.MR3R0Nib0,
            i_msg_block.MR3R0Nib1,
            i_msg_block.MR3R0Nib2,
            i_msg_block.MR3R0Nib3,
            i_msg_block.MR3R0Nib4,
            i_msg_block.MR3R0Nib5,
            i_msg_block.MR3R0Nib6,
            i_msg_block.MR3R0Nib7,
            i_msg_block.MR3R0Nib8,
            i_msg_block.MR3R0Nib9,
            i_msg_block.MR3R0Nib10,
            i_msg_block.MR3R0Nib11,
            i_msg_block.MR3R0Nib12,
            i_msg_block.MR3R0Nib13,
            i_msg_block.MR3R0Nib14,
            i_msg_block.MR3R0Nib15,
            i_msg_block.MR3R0Nib16,
            i_msg_block.MR3R0Nib17,
            i_msg_block.MR3R0Nib18,
            i_msg_block.MR3R0Nib19,
        },

        // Rank 1
        {
            i_msg_block.MR3R1Nib0,
            i_msg_block.MR3R1Nib1,
            i_msg_block.MR3R1Nib2,
            i_msg_block.MR3R1Nib3,
            i_msg_block.MR3R1Nib4,
            i_msg_block.MR3R1Nib5,
            i_msg_block.MR3R1Nib6,
            i_msg_block.MR3R1Nib7,
            i_msg_block.MR3R1Nib8,
            i_msg_block.MR3R1Nib9,
            i_msg_block.MR3R1Nib10,
            i_msg_block.MR3R1Nib11,
            i_msg_block.MR3R1Nib12,
            i_msg_block.MR3R1Nib13,
            i_msg_block.MR3R1Nib14,
            i_msg_block.MR3R1Nib15,
            i_msg_block.MR3R1Nib16,
            i_msg_block.MR3R1Nib17,
            i_msg_block.MR3R1Nib18,
            i_msg_block.MR3R1Nib19,
        },

        // Rank 2
        {
            i_msg_block.MR3R2Nib0,
            i_msg_block.MR3R2Nib1,
            i_msg_block.MR3R2Nib2,
            i_msg_block.MR3R2Nib3,
            i_msg_block.MR3R2Nib4,
            i_msg_block.MR3R2Nib5,
            i_msg_block.MR3R2Nib6,
            i_msg_block.MR3R2Nib7,
            i_msg_block.MR3R2Nib8,
            i_msg_block.MR3R2Nib9,
            i_msg_block.MR3R2Nib10,
            i_msg_block.MR3R2Nib11,
            i_msg_block.MR3R2Nib12,
            i_msg_block.MR3R2Nib13,
            i_msg_block.MR3R2Nib14,
            i_msg_block.MR3R2Nib15,
            i_msg_block.MR3R2Nib16,
            i_msg_block.MR3R2Nib17,
            i_msg_block.MR3R2Nib18,
            i_msg_block.MR3R2Nib19,
        },

        // Rank 3
        {
            i_msg_block.MR3R3Nib0,
            i_msg_block.MR3R3Nib1,
            i_msg_block.MR3R3Nib2,
            i_msg_block.MR3R3Nib3,
            i_msg_block.MR3R3Nib4,
            i_msg_block.MR3R3Nib5,
            i_msg_block.MR3R3Nib6,
            i_msg_block.MR3R3Nib7,
            i_msg_block.MR3R3Nib8,
            i_msg_block.MR3R3Nib9,
            i_msg_block.MR3R3Nib10,
            i_msg_block.MR3R3Nib11,
            i_msg_block.MR3R3Nib12,
            i_msg_block.MR3R3Nib13,
            i_msg_block.MR3R3Nib14,
            i_msg_block.MR3R3Nib15,
            i_msg_block.MR3R3Nib16,
            i_msg_block.MR3R3Nib17,
            i_msg_block.MR3R3Nib18,
            i_msg_block.MR3R3Nib19,
        },
    };

    return read_mr_from_block<mss::ddr5::mr3_data<mss::mc_type::ODYSSEY>>(i_target, i_rank_infos, DATA_ARRAY);
}

///
/// @brief Sets the MR10 attributes based upon the outputted data from draminit
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank_infos the rank information class vector
/// @param[in] i_msg_blk message block structure
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode set_mr10_attributes(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                      const std::vector<mss::rank::info<mss::mc_type::ODYSSEY>>& i_rank_infos,
                                      const _PMU_SMB_DDR5_1D_t& i_msg_block)
{
    // Assigns the data from the message block so it is easy to access
    const uint8_t DATA_ARRAY[mss::ody::MAX_RANK_PER_PHY][mss::ody::MAX_NIBBLES_PER_PORT] =
    {
        // Rank 0
        {
            i_msg_block.VrefDqR0Nib0,
            i_msg_block.VrefDqR0Nib1,
            i_msg_block.VrefDqR0Nib2,
            i_msg_block.VrefDqR0Nib3,
            i_msg_block.VrefDqR0Nib4,
            i_msg_block.VrefDqR0Nib5,
            i_msg_block.VrefDqR0Nib6,
            i_msg_block.VrefDqR0Nib7,
            i_msg_block.VrefDqR0Nib8,
            i_msg_block.VrefDqR0Nib9,
            i_msg_block.VrefDqR0Nib10,
            i_msg_block.VrefDqR0Nib11,
            i_msg_block.VrefDqR0Nib12,
            i_msg_block.VrefDqR0Nib13,
            i_msg_block.VrefDqR0Nib14,
            i_msg_block.VrefDqR0Nib15,
            i_msg_block.VrefDqR0Nib16,
            i_msg_block.VrefDqR0Nib17,
            i_msg_block.VrefDqR0Nib18,
            i_msg_block.VrefDqR0Nib19,
        },

        // Rank 1
        {
            i_msg_block.VrefDqR1Nib0,
            i_msg_block.VrefDqR1Nib1,
            i_msg_block.VrefDqR1Nib2,
            i_msg_block.VrefDqR1Nib3,
            i_msg_block.VrefDqR1Nib4,
            i_msg_block.VrefDqR1Nib5,
            i_msg_block.VrefDqR1Nib6,
            i_msg_block.VrefDqR1Nib7,
            i_msg_block.VrefDqR1Nib8,
            i_msg_block.VrefDqR1Nib9,
            i_msg_block.VrefDqR1Nib10,
            i_msg_block.VrefDqR1Nib11,
            i_msg_block.VrefDqR1Nib12,
            i_msg_block.VrefDqR1Nib13,
            i_msg_block.VrefDqR1Nib14,
            i_msg_block.VrefDqR1Nib15,
            i_msg_block.VrefDqR1Nib16,
            i_msg_block.VrefDqR1Nib17,
            i_msg_block.VrefDqR1Nib18,
            i_msg_block.VrefDqR1Nib19,
        },

        // Rank 2
        {
            i_msg_block.VrefDqR2Nib0,
            i_msg_block.VrefDqR2Nib1,
            i_msg_block.VrefDqR2Nib2,
            i_msg_block.VrefDqR2Nib3,
            i_msg_block.VrefDqR2Nib4,
            i_msg_block.VrefDqR2Nib5,
            i_msg_block.VrefDqR2Nib6,
            i_msg_block.VrefDqR2Nib7,
            i_msg_block.VrefDqR2Nib8,
            i_msg_block.VrefDqR2Nib9,
            i_msg_block.VrefDqR2Nib10,
            i_msg_block.VrefDqR2Nib11,
            i_msg_block.VrefDqR2Nib12,
            i_msg_block.VrefDqR2Nib13,
            i_msg_block.VrefDqR2Nib14,
            i_msg_block.VrefDqR2Nib15,
            i_msg_block.VrefDqR2Nib16,
            i_msg_block.VrefDqR2Nib17,
            i_msg_block.VrefDqR2Nib18,
            i_msg_block.VrefDqR2Nib19,
        },

        // Rank 3
        {
            i_msg_block.VrefDqR3Nib0,
            i_msg_block.VrefDqR3Nib1,
            i_msg_block.VrefDqR3Nib2,
            i_msg_block.VrefDqR3Nib3,
            i_msg_block.VrefDqR3Nib4,
            i_msg_block.VrefDqR3Nib5,
            i_msg_block.VrefDqR3Nib6,
            i_msg_block.VrefDqR3Nib7,
            i_msg_block.VrefDqR3Nib8,
            i_msg_block.VrefDqR3Nib9,
            i_msg_block.VrefDqR3Nib10,
            i_msg_block.VrefDqR3Nib11,
            i_msg_block.VrefDqR3Nib12,
            i_msg_block.VrefDqR3Nib13,
            i_msg_block.VrefDqR3Nib14,
            i_msg_block.VrefDqR3Nib15,
            i_msg_block.VrefDqR3Nib16,
            i_msg_block.VrefDqR3Nib17,
            i_msg_block.VrefDqR3Nib18,
            i_msg_block.VrefDqR3Nib19,
        },
    };

    return read_mr_from_block<mss::ddr5::mr10_data<mss::mc_type::ODYSSEY>>(i_target, i_rank_infos, DATA_ARRAY);
}

///
/// @brief Sets the MR11 attributes based upon the outputted data from draminit
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank_infos the rank information class vector
/// @param[in] i_msg_blk message block structure
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode set_mr11_attributes(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                      const std::vector<mss::rank::info<mss::mc_type::ODYSSEY>>& i_rank_infos,
                                      const _PMU_SMB_DDR5_1D_t& i_msg_block)
{
    // Assigns the data from the message block so it is easy to access
    uint8_t DATA_ARRAY[mss::ody::MAX_RANK_PER_PHY][mss::ody::MAX_NIBBLES_PER_PORT] =
    {
        // Rank 0
        {
            i_msg_block.VrefCAR0Nib0,
            i_msg_block.VrefCAR0Nib1,
            i_msg_block.VrefCAR0Nib2,
            i_msg_block.VrefCAR0Nib3,
            i_msg_block.VrefCAR0Nib4,
            i_msg_block.VrefCAR0Nib5,
            i_msg_block.VrefCAR0Nib6,
            i_msg_block.VrefCAR0Nib7,
            i_msg_block.VrefCAR0Nib8,
            i_msg_block.VrefCAR0Nib9,
            i_msg_block.VrefCAR0Nib10,
            i_msg_block.VrefCAR0Nib11,
            i_msg_block.VrefCAR0Nib12,
            i_msg_block.VrefCAR0Nib13,
            i_msg_block.VrefCAR0Nib14,
            i_msg_block.VrefCAR0Nib15,
            i_msg_block.VrefCAR0Nib16,
            i_msg_block.VrefCAR0Nib17,
            i_msg_block.VrefCAR0Nib18,
            i_msg_block.VrefCAR0Nib19,
        },

        // Rank 1
        {
            i_msg_block.VrefCAR1Nib0,
            i_msg_block.VrefCAR1Nib1,
            i_msg_block.VrefCAR1Nib2,
            i_msg_block.VrefCAR1Nib3,
            i_msg_block.VrefCAR1Nib4,
            i_msg_block.VrefCAR1Nib5,
            i_msg_block.VrefCAR1Nib6,
            i_msg_block.VrefCAR1Nib7,
            i_msg_block.VrefCAR1Nib8,
            i_msg_block.VrefCAR1Nib9,
            i_msg_block.VrefCAR1Nib10,
            i_msg_block.VrefCAR1Nib11,
            i_msg_block.VrefCAR1Nib12,
            i_msg_block.VrefCAR1Nib13,
            i_msg_block.VrefCAR1Nib14,
            i_msg_block.VrefCAR1Nib15,
            i_msg_block.VrefCAR1Nib16,
            i_msg_block.VrefCAR1Nib17,
            i_msg_block.VrefCAR1Nib18,
            i_msg_block.VrefCAR1Nib19,
        },

        // Rank 2
        {
            i_msg_block.VrefCAR2Nib0,
            i_msg_block.VrefCAR2Nib1,
            i_msg_block.VrefCAR2Nib2,
            i_msg_block.VrefCAR2Nib3,
            i_msg_block.VrefCAR2Nib4,
            i_msg_block.VrefCAR2Nib5,
            i_msg_block.VrefCAR2Nib6,
            i_msg_block.VrefCAR2Nib7,
            i_msg_block.VrefCAR2Nib8,
            i_msg_block.VrefCAR2Nib9,
            i_msg_block.VrefCAR2Nib10,
            i_msg_block.VrefCAR2Nib11,
            i_msg_block.VrefCAR2Nib12,
            i_msg_block.VrefCAR2Nib13,
            i_msg_block.VrefCAR2Nib14,
            i_msg_block.VrefCAR2Nib15,
            i_msg_block.VrefCAR2Nib16,
            i_msg_block.VrefCAR2Nib17,
            i_msg_block.VrefCAR2Nib18,
            i_msg_block.VrefCAR2Nib19,
        },

        // Rank 3
        {
            i_msg_block.VrefCAR3Nib0,
            i_msg_block.VrefCAR3Nib1,
            i_msg_block.VrefCAR3Nib2,
            i_msg_block.VrefCAR3Nib3,
            i_msg_block.VrefCAR3Nib4,
            i_msg_block.VrefCAR3Nib5,
            i_msg_block.VrefCAR3Nib6,
            i_msg_block.VrefCAR3Nib7,
            i_msg_block.VrefCAR3Nib8,
            i_msg_block.VrefCAR3Nib9,
            i_msg_block.VrefCAR3Nib10,
            i_msg_block.VrefCAR3Nib11,
            i_msg_block.VrefCAR3Nib12,
            i_msg_block.VrefCAR3Nib13,
            i_msg_block.VrefCAR3Nib14,
            i_msg_block.VrefCAR3Nib15,
            i_msg_block.VrefCAR3Nib16,
            i_msg_block.VrefCAR3Nib17,
            i_msg_block.VrefCAR3Nib18,
            i_msg_block.VrefCAR3Nib19,
        },
    };

    return read_mr_from_block<mss::ddr5::mr11_data<mss::mc_type::ODYSSEY>>(i_target, i_rank_infos, DATA_ARRAY);
}

///
/// @brief Sets the MR12 attributes based upon the outputted data from draminit
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank_infos the rank information class vector
/// @param[in] i_msg_blk message block structure
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode set_mr12_attributes(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                      const std::vector<mss::rank::info<mss::mc_type::ODYSSEY>>& i_rank_infos,
                                      const _PMU_SMB_DDR5_1D_t& i_msg_block)
{
    // Assigns the data from the message block so it is easy to access
    uint8_t DATA_ARRAY[mss::ody::MAX_RANK_PER_PHY][mss::ody::MAX_NIBBLES_PER_PORT] =
    {
        // Rank 0
        {
            i_msg_block.VrefCSR0Nib0,
            i_msg_block.VrefCSR0Nib1,
            i_msg_block.VrefCSR0Nib2,
            i_msg_block.VrefCSR0Nib3,
            i_msg_block.VrefCSR0Nib4,
            i_msg_block.VrefCSR0Nib5,
            i_msg_block.VrefCSR0Nib6,
            i_msg_block.VrefCSR0Nib7,
            i_msg_block.VrefCSR0Nib8,
            i_msg_block.VrefCSR0Nib9,
            i_msg_block.VrefCSR0Nib10,
            i_msg_block.VrefCSR0Nib11,
            i_msg_block.VrefCSR0Nib12,
            i_msg_block.VrefCSR0Nib13,
            i_msg_block.VrefCSR0Nib14,
            i_msg_block.VrefCSR0Nib15,
            i_msg_block.VrefCSR0Nib16,
            i_msg_block.VrefCSR0Nib17,
            i_msg_block.VrefCSR0Nib18,
            i_msg_block.VrefCSR0Nib19,
        },

        // Rank 1
        {
            i_msg_block.VrefCSR1Nib0,
            i_msg_block.VrefCSR1Nib1,
            i_msg_block.VrefCSR1Nib2,
            i_msg_block.VrefCSR1Nib3,
            i_msg_block.VrefCSR1Nib4,
            i_msg_block.VrefCSR1Nib5,
            i_msg_block.VrefCSR1Nib6,
            i_msg_block.VrefCSR1Nib7,
            i_msg_block.VrefCSR1Nib8,
            i_msg_block.VrefCSR1Nib9,
            i_msg_block.VrefCSR1Nib10,
            i_msg_block.VrefCSR1Nib11,
            i_msg_block.VrefCSR1Nib12,
            i_msg_block.VrefCSR1Nib13,
            i_msg_block.VrefCSR1Nib14,
            i_msg_block.VrefCSR1Nib15,
            i_msg_block.VrefCSR1Nib16,
            i_msg_block.VrefCSR1Nib17,
            i_msg_block.VrefCSR1Nib18,
            i_msg_block.VrefCSR1Nib19,
        },

        // Rank 2
        {
            i_msg_block.VrefCSR2Nib0,
            i_msg_block.VrefCSR2Nib1,
            i_msg_block.VrefCSR2Nib2,
            i_msg_block.VrefCSR2Nib3,
            i_msg_block.VrefCSR2Nib4,
            i_msg_block.VrefCSR2Nib5,
            i_msg_block.VrefCSR2Nib6,
            i_msg_block.VrefCSR2Nib7,
            i_msg_block.VrefCSR2Nib8,
            i_msg_block.VrefCSR2Nib9,
            i_msg_block.VrefCSR2Nib10,
            i_msg_block.VrefCSR2Nib11,
            i_msg_block.VrefCSR2Nib12,
            i_msg_block.VrefCSR2Nib13,
            i_msg_block.VrefCSR2Nib14,
            i_msg_block.VrefCSR2Nib15,
            i_msg_block.VrefCSR2Nib16,
            i_msg_block.VrefCSR2Nib17,
            i_msg_block.VrefCSR2Nib18,
            i_msg_block.VrefCSR2Nib19,
        },

        // Rank 3
        {
            i_msg_block.VrefCSR3Nib0,
            i_msg_block.VrefCSR3Nib1,
            i_msg_block.VrefCSR3Nib2,
            i_msg_block.VrefCSR3Nib3,
            i_msg_block.VrefCSR3Nib4,
            i_msg_block.VrefCSR3Nib5,
            i_msg_block.VrefCSR3Nib6,
            i_msg_block.VrefCSR3Nib7,
            i_msg_block.VrefCSR3Nib8,
            i_msg_block.VrefCSR3Nib9,
            i_msg_block.VrefCSR3Nib10,
            i_msg_block.VrefCSR3Nib11,
            i_msg_block.VrefCSR3Nib12,
            i_msg_block.VrefCSR3Nib13,
            i_msg_block.VrefCSR3Nib14,
            i_msg_block.VrefCSR3Nib15,
            i_msg_block.VrefCSR3Nib16,
            i_msg_block.VrefCSR3Nib17,
            i_msg_block.VrefCSR3Nib18,
            i_msg_block.VrefCSR3Nib19,
        },
    };

    return read_mr_from_block<mss::ddr5::mr12_data<mss::mc_type::ODYSSEY>>(i_target, i_rank_infos, DATA_ARRAY);
}

///
/// @brief Sets the mode register attributes based upon the outputted data from draminit
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_msg_blk message block structure
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode set_mr_attributes(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                    const _PMU_SMB_DDR5_1D_t& i_msg_block)
{
    // Gets the rank information vector
    std::vector<mss::rank::info<mss::mc_type::ODYSSEY>> l_rank_infos;

    FAPI_TRY(mss::rank::ranks_on_port(i_target, l_rank_infos));

    // Checks that we have at least one rank (we should)
    if(l_rank_infos.empty())
    {
        FAPI_INF( TARGTIDFORMAT "has no ranks! Skipping setting the MR attributes", TARGTID );
        return fapi2::FAPI2_RC_SUCCESS;
    }

    {
        // Gets the DIMM target - any DIMM target should work as Odyssey should only have one DIMM
        const auto l_dimm = l_rank_infos[0].get_dimm_target();

        // Sets the mode register attributes
        FAPI_TRY(set_mr3_attributes(l_dimm, l_rank_infos, i_msg_block));
        FAPI_TRY(set_mr10_attributes(l_dimm, l_rank_infos, i_msg_block));
        FAPI_TRY(set_mr11_attributes(l_dimm, l_rank_infos, i_msg_block));
        FAPI_TRY(set_mr12_attributes(l_dimm, l_rank_infos, i_msg_block));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets the generic attributes based upon the outputted data from draminit
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_msg_blk message block structure
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode set_generic_attributes(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const _PMU_SMB_DDR5_1D_t& i_msg_block)
{
    FAPI_TRY(mss::attr::set_ody_draminit_fw_revision(i_target, i_msg_block.PmuRevision));
    FAPI_TRY(mss::attr::set_ody_draminit_internal_fw_revision0(i_target, i_msg_block.PmuInternalRev0));
    FAPI_TRY(mss::attr::set_ody_draminit_internal_fw_revision1(i_target, i_msg_block.PmuInternalRev1));
    FAPI_TRY(mss::attr::set_ody_draminit_fw_data_addr_offset(i_target, i_msg_block.ResultAddrOffset));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets the attributes based upon the outputted data from draminit
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_msg_blk message block structure
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode set_attributes(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                 const _PMU_SMB_DDR5_1D_t& i_msg_block)
{
    FAPI_TRY(set_mr_attributes(i_target, i_msg_block));
    FAPI_TRY(set_generic_attributes(i_target, i_msg_block));

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
    FAPI_INF("  .CDD_ChA_RR_3_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RR_3_2, TARGTID);
    FAPI_INF("  .CDD_ChA_RR_3_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RR_3_1, TARGTID);
    FAPI_INF("  .CDD_ChA_RR_3_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RR_3_0, TARGTID);
    FAPI_INF("  .CDD_ChA_RR_2_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RR_2_3, TARGTID);
    FAPI_INF("  .CDD_ChA_RR_2_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RR_2_1, TARGTID);
    FAPI_INF("  .CDD_ChA_RR_2_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RR_2_0, TARGTID);
    FAPI_INF("  .CDD_ChA_RR_1_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RR_1_3, TARGTID);
    FAPI_INF("  .CDD_ChA_RR_1_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RR_1_2, TARGTID);
    FAPI_INF("  .CDD_ChA_RR_1_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RR_1_0, TARGTID);
    FAPI_INF("  .CDD_ChA_RR_0_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RR_0_3, TARGTID);
    FAPI_INF("  .CDD_ChA_RR_0_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RR_0_2, TARGTID);
    FAPI_INF("  .CDD_ChA_RR_0_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RR_0_1, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_3_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_3_3, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_3_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_3_2, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_3_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_3_1, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_3_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_3_0, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_2_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_2_3, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_2_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_2_2, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_2_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_2_1, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_2_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_2_0, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_1_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_1_3, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_1_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_1_2, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_1_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_1_1, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_1_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_1_0, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_0_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_0_3, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_0_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_0_2, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_0_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_0_1, TARGTID);
    FAPI_INF("  .CDD_ChA_RW_0_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_RW_0_0, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_3_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_3_3, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_3_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_3_2, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_3_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_3_1, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_3_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_3_0, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_2_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_2_3, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_2_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_2_2, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_2_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_2_1, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_2_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_2_0, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_1_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_1_3, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_1_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_1_2, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_1_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_1_1, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_1_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_1_0, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_0_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_0_3, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_0_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_0_2, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_0_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_0_1, TARGTID);
    FAPI_INF("  .CDD_ChA_WR_0_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WR_0_0, TARGTID);
    FAPI_INF("  .CDD_ChA_WW_3_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WW_3_2, TARGTID);
    FAPI_INF("  .CDD_ChA_WW_3_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WW_3_1, TARGTID);
    FAPI_INF("  .CDD_ChA_WW_3_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WW_3_0, TARGTID);
    FAPI_INF("  .CDD_ChA_WW_2_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WW_2_3, TARGTID);
    FAPI_INF("  .CDD_ChA_WW_2_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WW_2_1, TARGTID);
    FAPI_INF("  .CDD_ChA_WW_2_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WW_2_0, TARGTID);
    FAPI_INF("  .CDD_ChA_WW_1_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WW_1_3, TARGTID);
    FAPI_INF("  .CDD_ChA_WW_1_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WW_1_2, TARGTID);
    FAPI_INF("  .CDD_ChA_WW_1_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WW_1_0, TARGTID);
    FAPI_INF("  .CDD_ChA_WW_0_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WW_0_3, TARGTID);
    FAPI_INF("  .CDD_ChA_WW_0_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WW_0_2, TARGTID);
    FAPI_INF("  .CDD_ChA_WW_0_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChA_WW_0_1, TARGTID);
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
    FAPI_INF("  .CDD_ChB_RR_3_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RR_3_2, TARGTID);
    FAPI_INF("  .CDD_ChB_RR_3_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RR_3_1, TARGTID);
    FAPI_INF("  .CDD_ChB_RR_3_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RR_3_0, TARGTID);
    FAPI_INF("  .CDD_ChB_RR_2_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RR_2_3, TARGTID);
    FAPI_INF("  .CDD_ChB_RR_2_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RR_2_1, TARGTID);
    FAPI_INF("  .CDD_ChB_RR_2_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RR_2_0, TARGTID);
    FAPI_INF("  .CDD_ChB_RR_1_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RR_1_3, TARGTID);
    FAPI_INF("  .CDD_ChB_RR_1_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RR_1_2, TARGTID);
    FAPI_INF("  .CDD_ChB_RR_1_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RR_1_0, TARGTID);
    FAPI_INF("  .CDD_ChB_RR_0_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RR_0_3, TARGTID);
    FAPI_INF("  .CDD_ChB_RR_0_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RR_0_2, TARGTID);
    FAPI_INF("  .CDD_ChB_RR_0_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RR_0_1, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_3_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_3_3, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_3_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_3_2, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_3_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_3_1, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_3_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_3_0, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_2_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_2_3, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_2_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_2_2, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_2_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_2_1, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_2_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_2_0, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_1_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_1_3, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_1_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_1_2, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_1_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_1_1, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_1_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_1_0, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_0_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_0_3, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_0_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_0_2, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_0_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_0_1, TARGTID);
    FAPI_INF("  .CDD_ChB_RW_0_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_RW_0_0, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_3_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_3_3, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_3_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_3_2, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_3_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_3_1, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_3_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_3_0, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_2_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_2_3, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_2_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_2_2, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_2_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_2_1, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_2_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_2_0, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_1_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_1_3, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_1_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_1_2, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_1_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_1_1, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_1_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_1_0, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_0_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_0_3, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_0_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_0_2, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_0_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_0_1, TARGTID);
    FAPI_INF("  .CDD_ChB_WR_0_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WR_0_0, TARGTID);
    FAPI_INF("  .CDD_ChB_WW_3_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WW_3_2, TARGTID);
    FAPI_INF("  .CDD_ChB_WW_3_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WW_3_1, TARGTID);
    FAPI_INF("  .CDD_ChB_WW_3_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WW_3_0, TARGTID);
    FAPI_INF("  .CDD_ChB_WW_2_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WW_2_3, TARGTID);
    FAPI_INF("  .CDD_ChB_WW_2_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WW_2_1, TARGTID);
    FAPI_INF("  .CDD_ChB_WW_2_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WW_2_0, TARGTID);
    FAPI_INF("  .CDD_ChB_WW_1_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WW_1_3, TARGTID);
    FAPI_INF("  .CDD_ChB_WW_1_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WW_1_2, TARGTID);
    FAPI_INF("  .CDD_ChB_WW_1_0       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WW_1_0, TARGTID);
    FAPI_INF("  .CDD_ChB_WW_0_3       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WW_0_3, TARGTID);
    FAPI_INF("  .CDD_ChB_WW_0_2       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WW_0_2, TARGTID);
    FAPI_INF("  .CDD_ChB_WW_0_1       = %d; // " TARGTIDFORMAT, i_msg_block.CDD_ChB_WW_0_1, TARGTID);
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

///
/// @brief Checks the training status from mail and message block
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_status the final mail status from training
/// @param[in] i_msg_block_response the message block
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode check_training_result(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                        const uint64_t i_status,
                                        const _PMU_SMB_DDR5_1D_t& i_msg_block_response)
{
    constexpr uint8_t MSG_BLOCK_TRAIN_PASS = 0x00;

    mss::ody::phy::bad_bit_interface l_interface(i_msg_block_response);

    // Check training complete mail message
    FAPI_ASSERT((i_status == SUCCESSFUL_COMPLETION),
                fapi2::ODY_DRAMINIT_TRAINING_FAILURE_MAIL()
                .set_PORT_TARGET(i_target)
                .set_TRAINING_STATUS(i_status)
                .set_EXPECTED_STATUS(SUCCESSFUL_COMPLETION)
                .set_PMU_REVISION(i_msg_block_response.PmuRevision),
                TARGTIDFORMAT " DRAM training returned a non-success status "
                "mail message: 0x%02x (expected 0x%02x)",
                TARGTID, i_status, SUCCESSFUL_COMPLETION);

    // Check message block return code
    FAPI_ASSERT((i_msg_block_response.CsTestFail == MSG_BLOCK_TRAIN_PASS),
                fapi2::ODY_DRAMINIT_TRAINING_FAILURE_MSG_BLOCK()
                .set_PORT_TARGET(i_target)
                .set_ACTUAL_CSTESTFAIL(i_msg_block_response.CsTestFail)
                .set_EXPECTED_CSTESTFAIL(MSG_BLOCK_TRAIN_PASS)
                .set_PMU_REVISION(i_msg_block_response.PmuRevision),
                TARGTIDFORMAT " DRAM training returned a non-success status "
                "in the message block: 0x%02x (expected 0x%02x)",
                TARGTID, i_msg_block_response.CsTestFail, MSG_BLOCK_TRAIN_PASS);

    // Check for FIRs then record the bad bits data into our attribute if there are no FIRs set
    // Hostboot will consume the bad bits attribute in the host_draminit procedure
    FAPI_TRY(mss::record_bad_bits<mss::mc_type::ODYSSEY>(i_target, l_interface));

    FAPI_INF(TARGTIDFORMAT " DRAM training returned PASSING status", TARGTID);
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace phy
} // namespace ody
} // namespace mss
