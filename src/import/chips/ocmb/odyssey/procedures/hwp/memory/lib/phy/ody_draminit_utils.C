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
#include <lib/shared/ody_consts.H>
#include <generic/memory/lib/utils/num.H>
#include <lib/dimm/ody_rank.H>
#include <generic/memory/lib/utils/fapi_try_lambda.H>

#include <generic/memory/lib/dimm/ddr5/ddr5_mr3.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr10.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr11.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr12.H>

#if !defined(__PPE__) && !defined(__HOSTBOOT_MODULE)
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
        FAPI_TRY_LAMBDA(fapi2::getScom(i_target, scomt::mp::DWC_DDRPHYA_APBONLY0_UCTSHADOWREGS, l_data));
        return (l_data.getBit<scomt::mp::DWC_DDRPHYA_APBONLY0_UCTSHADOWREGS_UCTWRITEPROTSHADOW>() == MESSAGE_AVAILABLE);

    fapi_try_exit_lambda:
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
        FAPI_TRY_LAMBDA(fapi2::getScom(i_target, scomt::mp::DWC_DDRPHYA_APBONLY0_UCTSHADOWREGS, l_data));
        return (l_data.getBit<scomt::mp::DWC_DDRPHYA_APBONLY0_UCTSHADOWREGS_UCTWRITEPROTSHADOW>() == ACK_MESSAGE);

    fapi_try_exit_lambda:
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
        FAPI_TRY_LAMBDA(mss::ody::phy::get_mail(i_target, l_mode, l_mailbox_poll_count, l_mail));

        // Process and decode 'major' messages, and handle SMBus and streaming message protocol if necessary
        FAPI_TRY_LAMBDA(check_for_completion_and_decode(i_target, l_mail, o_log_data, l_loop_end));

        if (l_loop_end)
        {
            return(l_loop_end);
        }
        FAPI_TRY_LAMBDA(fapi2::delay(mss::DELAY_1MS, 200));

        return false;

    fapi_try_exit_lambda:
        FAPI_ERR("mss::poll() hit an error in mss::getScom");
        // Exit the poll if we hit a fapi error
        return true;
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
            FAPI_INF(TARGTIDFORMAT" Successful completion, code: " UINT64FORMAT, TARGTID, UINT64_VALUE(i_mail));
            break;

        case FAILED_COMPLETION:
            o_loop_end = true;
            FAPI_INF(TARGTIDFORMAT" Failed completion, code: " UINT64FORMAT, TARGTID, UINT64_VALUE(i_mail));
            break;

        case END_OF_INITILIAZATION:
            FAPI_INF(TARGTIDFORMAT" End of initialization, code: " UINT64FORMAT, TARGTID, UINT64_VALUE(i_mail));
            break;

        case END_OF_FINE_WRITE_LEVELING:
            FAPI_INF(TARGTIDFORMAT" End of fine write leveling, code: " UINT64FORMAT, TARGTID, UINT64_VALUE(i_mail));
            break;

        case END_OF_READ_ENABLE_TRAINING:
            FAPI_INF(TARGTIDFORMAT" End of read enable training, code: " UINT64FORMAT, TARGTID, UINT64_VALUE(i_mail));
            break;

        case END_OF_RD_DLY_CNTR_OPT:
            FAPI_INF(TARGTIDFORMAT" End of read delay center optimization, code: " UINT64FORMAT, TARGTID, UINT64_VALUE(i_mail));
            break;

        case END_OF_WR_DLY_CNTR_OPT:
            FAPI_INF(TARGTIDFORMAT" End of write delay center optimization, code: " UINT64FORMAT, TARGTID, UINT64_VALUE(i_mail));
            break;

        case END_OF_2D_RD_DLY_V_CNTR_OPT:
            FAPI_INF(TARGTIDFORMAT" End of 2D read delay /voltage center optimization, code: " UINT64FORMAT, TARGTID,
                     UINT64_VALUE(i_mail));
            break;

        case END_OF_2D_WR_DLY_V_CNTR_OPT:
            FAPI_INF(TARGTIDFORMAT" End of 2D write delay /voltage center optimization, code: " UINT64FORMAT, TARGTID,
                     UINT64_VALUE(i_mail));
            break;

        case END_OF_MAX_RD_LAT_TRAINING:
            FAPI_INF(TARGTIDFORMAT" End of max read latency training, code: " UINT64FORMAT, TARGTID, UINT64_VALUE(i_mail));
            break;

        case END_OF_RD_DQ_DSKEW_TRAINING:
            FAPI_INF(TARGTIDFORMAT" End of read DQ deskew training, code: " UINT64FORMAT, TARGTID, UINT64_VALUE(i_mail));
            break;

        case TRAINING_STAGE_RESERVED:
            FAPI_INF(TARGTIDFORMAT" Reserved, code: " UINT64FORMAT, TARGTID, UINT64_VALUE(i_mail));
            break;

        case END_OF_CS_CA_TRAINING:
            FAPI_INF(TARGTIDFORMAT" End of CS/CA training, code: " UINT64FORMAT, TARGTID, UINT64_VALUE(i_mail));
            break;

        case END_OF_RCD_QCS_QCA_TRAINING:
            FAPI_INF(TARGTIDFORMAT" End of RCD QCS/QCA training, code: " UINT64FORMAT, TARGTID, UINT64_VALUE(i_mail));
            break;

        case END_OF_LRDIMM_MREP_TRAINING:
            FAPI_INF(TARGTIDFORMAT" End of LRDIMM MREP training, code: " UINT64FORMAT, TARGTID, UINT64_VALUE(i_mail));
            break;

        case END_OF_LRDIMM_DWL_TRAINING:
            FAPI_INF(TARGTIDFORMAT" End of LRDIMM DWL training, code: " UINT64FORMAT, TARGTID, UINT64_VALUE(i_mail));
            break;

        case END_OF_LRDIMM_MRD_TRAINING:
            FAPI_INF(TARGTIDFORMAT" End of LRDIMM MRD training, code: " UINT64FORMAT, TARGTID, UINT64_VALUE(i_mail));
            break;

        case END_OF_LRDIMM_MWD_TRAINING:
            FAPI_INF(TARGTIDFORMAT" End of LRDIMM MWD training, code: " UINT64FORMAT, TARGTID, UINT64_VALUE(i_mail));
            break;

        case GEN_WRT_NOISE_SYN:
            FAPI_INF(TARGTIDFORMAT" Generate write noise synchronization Stage, code: " UINT64FORMAT, TARGTID,
                     UINT64_VALUE(i_mail));
            break;

        case END_OF_MPR_RD_DLY_CNTR_OPT:
            FAPI_INF(TARGTIDFORMAT" End of MPR read delay center optimization Stage, code: " UINT64FORMAT, TARGTID,
                     UINT64_VALUE(i_mail));
            break;

        case END_OF_WR_LVL_COARSE_DLY:
            FAPI_INF(TARGTIDFORMAT" End of write level coarse delay Stage, code: " UINT64FORMAT, TARGTID, UINT64_VALUE(i_mail));
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
            FAPI_INF(TARGTIDFORMAT" Unknown major message: " UINT64FORMAT, TARGTID, UINT64_VALUE(i_mail));
            break;
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

// Not needed for PPE as this is only being used for initial bringup/simulation which will not be running PPE
#ifndef __PPE__
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
    o_struct.PmuInternalRev0       = 0;
    o_struct.PmuInternalRev1       = 0;

    o_struct.VrefCS_Sweep_Min      = 0;
    o_struct.VrefCS_Sweep_Max      = 0;
    o_struct.VrefCA_Sweep_Min      = 0;
    o_struct.VrefCA_Sweep_Max      = 0;

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
        o_struct.MR32R0Nib0     = 0;
        o_struct.MR32R0Nib1     = 0;
        o_struct.MR32R0Nib10     = 0;
        o_struct.MR32R0Nib11     = 0;
        o_struct.MR32R0Nib12     = 0;
        o_struct.MR32R0Nib13     = 0;
        o_struct.MR32R0Nib14     = 0;
        o_struct.MR32R0Nib15     = 0;
        o_struct.MR32R0Nib16     = 0;
        o_struct.MR32R0Nib17     = 0;
        o_struct.MR32R0Nib18     = 0;
        o_struct.MR32R0Nib19     = 0;
        o_struct.MR32R0Nib2     = 0;
        o_struct.MR32R0Nib3     = 0;
        o_struct.MR32R0Nib4     = 0;
        o_struct.MR32R0Nib5     = 0;
        o_struct.MR32R0Nib6     = 0;
        o_struct.MR32R0Nib7     = 0;
        o_struct.MR32R0Nib8     = 0;
        o_struct.MR32R0Nib9     = 0;
        o_struct.MR32R1Nib0     = 0;
        o_struct.MR32R1Nib1     = 0;
        o_struct.MR32R1Nib10     = 0;
        o_struct.MR32R1Nib11     = 0;
        o_struct.MR32R1Nib12     = 0;
        o_struct.MR32R1Nib13     = 0;
        o_struct.MR32R1Nib14     = 0;
        o_struct.MR32R1Nib15     = 0;
        o_struct.MR32R1Nib16     = 0;
        o_struct.MR32R1Nib17     = 0;
        o_struct.MR32R1Nib18     = 0;
        o_struct.MR32R1Nib19     = 0;
        o_struct.MR32R1Nib2     = 0;
        o_struct.MR32R1Nib3     = 0;
        o_struct.MR32R1Nib4     = 0;
        o_struct.MR32R1Nib5     = 0;
        o_struct.MR32R1Nib6     = 0;
        o_struct.MR32R1Nib7     = 0;
        o_struct.MR32R1Nib8     = 0;
        o_struct.MR32R1Nib9     = 0;
        o_struct.MR32R2Nib0     = 0;
        o_struct.MR32R2Nib1     = 0;
        o_struct.MR32R2Nib10     = 0;
        o_struct.MR32R2Nib11     = 0;
        o_struct.MR32R2Nib12     = 0;
        o_struct.MR32R2Nib13     = 0;
        o_struct.MR32R2Nib14     = 0;
        o_struct.MR32R2Nib15     = 0;
        o_struct.MR32R2Nib16     = 0;
        o_struct.MR32R2Nib17     = 0;
        o_struct.MR32R2Nib18     = 0;
        o_struct.MR32R2Nib19     = 0;
        o_struct.MR32R2Nib2     = 0;
        o_struct.MR32R2Nib3     = 0;
        o_struct.MR32R2Nib4     = 0;
        o_struct.MR32R2Nib5     = 0;
        o_struct.MR32R2Nib6     = 0;
        o_struct.MR32R2Nib7     = 0;
        o_struct.MR32R2Nib8     = 0;
        o_struct.MR32R2Nib9     = 0;
        o_struct.MR32R3Nib0     = 0;
        o_struct.MR32R3Nib1     = 0;
        o_struct.MR32R3Nib10     = 0;
        o_struct.MR32R3Nib11     = 0;
        o_struct.MR32R3Nib12     = 0;
        o_struct.MR32R3Nib13     = 0;
        o_struct.MR32R3Nib14     = 0;
        o_struct.MR32R3Nib15     = 0;
        o_struct.MR32R3Nib16     = 0;
        o_struct.MR32R3Nib17     = 0;
        o_struct.MR32R3Nib18     = 0;
        o_struct.MR32R3Nib19     = 0;
        o_struct.MR32R3Nib2     = 0;
        o_struct.MR32R3Nib3     = 0;
        o_struct.MR32R3Nib4     = 0;
        o_struct.MR32R3Nib5     = 0;
        o_struct.MR32R3Nib6     = 0;
        o_struct.MR32R3Nib7     = 0;
        o_struct.MR32R3Nib8     = 0;
        o_struct.MR32R3Nib9     = 0;

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
#endif

///
/// @brief SPD to PHY nibble swizzle is implemented in the getBits indexing
/// @param[in] i_nibble_enables nibble enable attr value
/// @param[out] o_byte_disables DQ byte disable bits
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode nibble_enable_db_disable(const fapi2::buffer<uint32_t>& i_nibble_enables,
        uint8_t(&o_byte_disables)[10])
{
    fapi2::buffer<uint8_t> l_byte_disable;
    constexpr uint8_t DB0 = 31;
    constexpr uint8_t DB1 = 29;
    constexpr uint8_t DB2 = 27;
    constexpr uint8_t DB3 = 25;
    constexpr uint8_t DB4 = 21;
    constexpr uint8_t DB5 = 19;
    constexpr uint8_t DB6 = 17;
    constexpr uint8_t DB7 = 15;
    constexpr uint8_t DB8 = 23;
    constexpr uint8_t DB9 = 13;
    constexpr uint8_t SYNOPSYS_NIBBLE0 = BITS_PER_NIBBLE;
    constexpr uint8_t SYNOPSYS_NIBBLE1 = 0;

    l_byte_disable.writeBit<SYNOPSYS_NIBBLE0, BITS_PER_NIBBLE>(!i_nibble_enables.getBit<DB0>());
    l_byte_disable.writeBit<SYNOPSYS_NIBBLE1, BITS_PER_NIBBLE>(!i_nibble_enables.getBit < DB0 - 1 > ());
    o_byte_disables[0] = l_byte_disable;

    l_byte_disable.writeBit<SYNOPSYS_NIBBLE0, BITS_PER_NIBBLE>(!i_nibble_enables.getBit<DB1>());
    l_byte_disable.writeBit<SYNOPSYS_NIBBLE1, BITS_PER_NIBBLE>(!i_nibble_enables.getBit < DB1 - 1 > ());
    o_byte_disables[1] = l_byte_disable;

    l_byte_disable.writeBit<SYNOPSYS_NIBBLE0, BITS_PER_NIBBLE>(!i_nibble_enables.getBit<DB2>());
    l_byte_disable.writeBit<SYNOPSYS_NIBBLE1, BITS_PER_NIBBLE>(!i_nibble_enables.getBit < DB2 - 1 > ());
    o_byte_disables[2] = l_byte_disable;

    l_byte_disable.writeBit<SYNOPSYS_NIBBLE0, BITS_PER_NIBBLE>(!i_nibble_enables.getBit<DB3>());
    l_byte_disable.writeBit<SYNOPSYS_NIBBLE1, BITS_PER_NIBBLE>(!i_nibble_enables.getBit < DB3 - 1 > ());
    o_byte_disables[3] = l_byte_disable;

    l_byte_disable.writeBit<SYNOPSYS_NIBBLE0, BITS_PER_NIBBLE>(!i_nibble_enables.getBit<DB4>());
    l_byte_disable.writeBit<SYNOPSYS_NIBBLE1, BITS_PER_NIBBLE>(!i_nibble_enables.getBit < DB4 - 1 > ());
    o_byte_disables[4] = l_byte_disable;

    l_byte_disable.writeBit<SYNOPSYS_NIBBLE0, BITS_PER_NIBBLE>(!i_nibble_enables.getBit<DB5>());
    l_byte_disable.writeBit<SYNOPSYS_NIBBLE1, BITS_PER_NIBBLE>(!i_nibble_enables.getBit < DB5 - 1 > ());
    o_byte_disables[5] = l_byte_disable;

    l_byte_disable.writeBit<SYNOPSYS_NIBBLE0, BITS_PER_NIBBLE>(!i_nibble_enables.getBit<DB6>());
    l_byte_disable.writeBit<SYNOPSYS_NIBBLE1, BITS_PER_NIBBLE>(!i_nibble_enables.getBit < DB6 - 1 > ());
    o_byte_disables[6] = l_byte_disable;

    l_byte_disable.writeBit<SYNOPSYS_NIBBLE0, BITS_PER_NIBBLE>(!i_nibble_enables.getBit<DB7>());
    l_byte_disable.writeBit<SYNOPSYS_NIBBLE1, BITS_PER_NIBBLE>(!i_nibble_enables.getBit < DB7 - 1 > ());
    o_byte_disables[7] = l_byte_disable;

    l_byte_disable.writeBit<SYNOPSYS_NIBBLE0, BITS_PER_NIBBLE>(!i_nibble_enables.getBit<DB8>());
    l_byte_disable.writeBit<SYNOPSYS_NIBBLE1, BITS_PER_NIBBLE>(!i_nibble_enables.getBit < DB8 - 1 > ());
    o_byte_disables[8] = l_byte_disable;

    l_byte_disable.writeBit<SYNOPSYS_NIBBLE0, BITS_PER_NIBBLE>(!i_nibble_enables.getBit<DB9>());
    l_byte_disable.writeBit<SYNOPSYS_NIBBLE1, BITS_PER_NIBBLE>(!i_nibble_enables.getBit < DB9 - 1 > ());
    o_byte_disables[9] = l_byte_disable;

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
    FAPI_TRY(l_msg_block_config.setup_vref_sweeps(o_struct));
    FAPI_TRY(l_msg_block_config.setup_MR32_per_dram(o_struct));
    FAPI_TRY(l_msg_block_config.setup_reserved7(o_struct));
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
/// @brief Configures the msg block on to snps phy
/// @param[in] i_target the target on which to operate
/// @param[in,out] io_msg_block the message block to configure and load
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode configure_dram_train_message_block(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>&
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
        // SBE does not support using the hardcodes as they are only for initial bringup/simulation
#ifdef __PPE__
        // Skipping trace to reduce SBE code size
        FAPI_ASSERT(false,
                    fapi2::ODY_DRAMINIT_HARDCODE_UNSUPPORTED().set_PORT_TARGET(i_target),
                    "hardcoded attributes are unsupported by the SBE");
#else
        FAPI_TRY(configure_dram_train_message_block_hardcodes(i_target, io_msg_block));
#endif
    }
    else
    {
        FAPI_TRY(configure_dram_train_message_block(i_target, l_sim, io_msg_block));
    }

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Configure and load the msg block on to snps phy
/// @param[in] i_target the target on which to operate
/// @param[in,out] io_msg_block the message block to configure and load
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode configure_and_load_dram_train_message_block(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>&
        i_target,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    FAPI_TRY(configure_dram_train_message_block(i_target, io_msg_block));

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

#if !defined(__PPE__) && !defined(__HOSTBOOT_MODULE)
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

#if !defined(__PPE__) && !defined(__HOSTBOOT_MODULE)
        {
            // Report progress at 1% intervals (only in Cronus)
            // Percentage of the number of bytes copied so far
            uint32_t l_new_progress_pct = 100 * (l_bytes_copied) / i_mem_size;

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

        FAPI_INF(TARGTIDFORMAT " RCW info. Channel id: 0x%x, DIMM id: 0x%x, RCW id: 0x%02x",
                 TARGTID, l_rcw_info.iv_channel_id, l_rcw_info.iv_dimm_id, l_rcw_info.iv_rcw_id);
        FAPI_INF(TARGTIDFORMAT " RCW page: 0x%02x, RCW val: 0x%02x",
                 TARGTID, l_rcw_info.iv_rcw_page, l_rcw_info.iv_rcw_val);

        // Send the RCW: Note: we cannot do this yet see the below TODO
        // TODO:ZEN:MST-1541 Add DDR5 RCW writes using i2c when SMBus message is received
    }

    // Look for the SMBus complete message (only 16 bits!)
    FAPI_TRY(mss::ody::phy::get_mail(i_target, MAJOR_MSG_MODE, LOOP_COUNT, l_mail));

    // If we do not get the SMBus complete message, assert but log the error as recovered
    // We might be able to continue, but this is definitely weird
    // Note: uint16_t is ok for the print as the mail is only 16bits
    FAPI_ASSERT(l_mail == SMBUS_SYNC,
                fapi2::ODY_DRAMINIT_SMBUS_SYNC_MSG_NOT_FOUND()
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
/// @brief Conducts an endian swap if needed on this message block address
/// @param[in] i_address the current address to load
/// @param[in] i_end_it the ending iterator of this array
/// @param[in,out] io_no_swap_it the current iterator to check for the address
/// @param[in,out] io_data the register data to update if needed
///
void endian_swap_msg_block_data(const uint64_t i_address, const uint32_t* const i_end_it,
                                const uint32_t*& io_no_swap_it, fapi2::buffer<uint64_t>& io_data)
{
    if (io_no_swap_it < i_end_it && i_address == *io_no_swap_it)
    {
        ++io_no_swap_it;
    }
    else
    {
        constexpr uint64_t BYTE0 = 56;
        constexpr uint64_t BYTE1 = 48;
        uint8_t l_byte0 = 0;
        uint8_t l_byte1 = 0;
        io_data.extractToRight<BYTE0, BITS_PER_BYTE>(l_byte0)
        .extractToRight<BYTE1, BITS_PER_BYTE>(l_byte1);

        io_data.insertFromRight<BYTE0, BITS_PER_BYTE>(l_byte1)
        .insertFromRight<BYTE1, BITS_PER_BYTE>(l_byte0);
    }
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
    fapi2::buffer<uint64_t> l_data;
    uint16_t* l_struct_data = (uint16_t*)&i_struct;
    uint32_t l_address = 0;

    const mss::pair<uint32_t, uint32_t> SKIP_ADDR[] =
    {
        //If first element address is reached , skip to the second address of pair.
        {0x58013, 0x5802d},
        {0x5804f, 0x58051},
        {0x58075, 0x58077},
        {0x5807f, 0x58087},
        {0x580c5, 0x580c7},
        {0x580eb, 0x580ed},
        {0x580f5, 0x580fd},
        {0x583b3, 0x583bd},
    };

    // Array to hold list of address that is needed for successful write operation as a even/odd pair of addresses.
    const uint32_t FLUSH_ADDR[]__attribute__ ((aligned (8))) = {0x58001,
                                                                0x5800a,
                                                                0x58013,
                                                                0x5802e,
                                                                0x5803d,
                                                                0x5803e,
                                                                0x58063,
                                                                0x58064,
                                                                0x58089,
                                                                0x580a4,
                                                                0x580b3,
                                                                0x580b4,
                                                                0x580d9,
                                                                0x580da,
                                                               };

#ifdef __PPE__
    // Array to hold list of addresses that are uint16_t's and do NOT need endianness swapping for SBE
    const uint32_t NO_SWAP_ADDR[]__attribute__ ((aligned (8))) =
    {
        0x58003,
        0x58008,
        0x58011,
        0x580fe,
        0x580ff,
    };
    auto l_no_swap_it = std::begin(NO_SWAP_ADDR);
    const auto NO_SWAP_END = std::end(NO_SWAP_ADDR);

#endif

    auto l_flush_it = std::begin(FLUSH_ADDR);
    auto l_skip_it = std::begin(SKIP_ADDR);
    const auto FLUSH_END = std::end(FLUSH_ADDR);
    const auto SKIP_END = std::end(SKIP_ADDR);

    // End address is calculated by the structure size :
    // every 2 byte of structure (16 bits) makes 1 increment in the address.
    constexpr uint32_t END_ADDR = 0x58000 + sizeof(_PMU_SMB_DDR5_1D_t) / 2;

    for ( l_address = 0x58000; l_address <= END_ADDR; l_address++)
    {
        // We need to flush the buffer and write before skipping following addresses
        // to have the previous unskipped address's write become successful.
        // As write operations are successful in pair of consecutive addresses.
        if (l_flush_it < FLUSH_END && *(l_flush_it) == l_address)
        {
            l_data.flush<0>();
            l_flush_it++;
        }
        else
        {
            l_data = *(l_struct_data);

            // If in PPE, check if we need a data swap
#ifdef __PPE__
            endian_swap_msg_block_data(l_address, NO_SWAP_END, l_no_swap_it, l_data);
#endif
        }

        FAPI_TRY(putScom_synopsys_addr_wrapper(i_target, l_address, l_data));
        l_struct_data++ ;

        if (l_skip_it < SKIP_END && l_address == l_skip_it->first)
        {
            l_address = l_skip_it->second;
            const uint32_t l_struct_increment = l_skip_it->second - l_skip_it->first;
            l_struct_data = l_struct_data + l_struct_increment;
            l_skip_it++ ;
        }
    }

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

    FAPI_TRY(read_dmem_field(i_target, 0x58001, l_temp16));
    io_struct.PmuRevision = l_temp16; // uint16_t

    FAPI_TRY(read_dmem_field(i_target, 0x58007, l_temp8_even, l_temp8_odd));
    io_struct.CsTestFail = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5800a, l_temp16));
    io_struct.ResultAddrOffset = l_temp16; // uint16_t

    FAPI_TRY(read_dmem_field(i_target, 0x58013, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RR_3_2 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RR_3_1 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58014, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RR_3_0 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RR_2_3 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58015, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RR_2_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RR_2_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58016, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RR_1_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RR_1_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58017, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RR_1_0 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RR_0_3 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58018, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RR_0_2 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RR_0_1 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58019, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RW_3_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RW_3_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5801a, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RW_3_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RW_3_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5801b, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RW_2_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RW_2_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5801c, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RW_2_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RW_2_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5801d, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RW_1_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RW_1_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5801e, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RW_1_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RW_1_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5801f, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RW_0_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RW_0_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58020, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_RW_0_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_RW_0_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58021, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WR_3_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WR_3_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58022, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WR_3_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WR_3_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58023, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WR_2_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WR_2_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58024, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WR_2_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WR_2_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58025, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WR_1_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WR_1_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58026, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WR_1_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WR_1_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58027, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WR_0_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WR_0_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58028, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WR_0_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WR_0_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58029, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WW_3_2 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WW_3_1 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5802a, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WW_3_0 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WW_2_3 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5802b, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WW_2_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WW_2_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5802c, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WW_1_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WW_1_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5802d, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WW_1_0 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WW_0_3 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5802e, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChA_WW_0_2 = l_temp8_even; // int8_t
    io_struct.CDD_ChA_WW_0_1 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5803d, l_temp8_even, l_temp8_odd));
    io_struct.CS_Dly_Margin_A0 = l_temp8_even; // uint8_t
    io_struct.CS_Vref_Margin_A0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5803e, l_temp8_even, l_temp8_odd));
    io_struct.CA_Dly_Margin_A0 = l_temp8_even; // uint8_t
    io_struct.CA_Vref_Margin_A0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58050, l_temp8_even, l_temp8_odd));
    io_struct.CS_Dly_Margin_A1 = l_temp8_even; // uint8_t
    io_struct.CS_Vref_Margin_A1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58051, l_temp8_even, l_temp8_odd));
    io_struct.CA_Dly_Margin_A1 = l_temp8_even; // uint8_t
    io_struct.CA_Vref_Margin_A1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58063, l_temp8_even, l_temp8_odd));
    io_struct.CS_Dly_Margin_A2 = l_temp8_even; // uint8_t
    io_struct.CS_Vref_Margin_A2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58064, l_temp8_even, l_temp8_odd));
    io_struct.CA_Dly_Margin_A2 = l_temp8_even; // uint8_t
    io_struct.CA_Vref_Margin_A2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58076, l_temp8_even, l_temp8_odd));
    io_struct.CS_Dly_Margin_A3 = l_temp8_even; // uint8_t
    io_struct.CS_Vref_Margin_A3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58077, l_temp8_even, l_temp8_odd));
    io_struct.CA_Dly_Margin_A3 = l_temp8_even; // uint8_t
    io_struct.CA_Vref_Margin_A3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58080, l_temp8_even, l_temp8_odd));
    io_struct.RxClkDly_Margin_A0 = l_temp8_even; // uint8_t
    io_struct.VrefDac_Margin_A0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58081, l_temp8_even, l_temp8_odd));
    io_struct.TxDqDly_Margin_A0 = l_temp8_even; // uint8_t
    io_struct.DeviceVref_Margin_A0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58082, l_temp8_even, l_temp8_odd));
    io_struct.RxClkDly_Margin_A1 = l_temp8_even; // uint8_t
    io_struct.VrefDac_Margin_A1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58083, l_temp8_even, l_temp8_odd));
    io_struct.TxDqDly_Margin_A1 = l_temp8_even; // uint8_t
    io_struct.DeviceVref_Margin_A1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58084, l_temp8_even, l_temp8_odd));
    io_struct.RxClkDly_Margin_A2 = l_temp8_even; // uint8_t
    io_struct.VrefDac_Margin_A2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58085, l_temp8_even, l_temp8_odd));
    io_struct.TxDqDly_Margin_A2 = l_temp8_even; // uint8_t
    io_struct.DeviceVref_Margin_A2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58086, l_temp8_even, l_temp8_odd));
    io_struct.RxClkDly_Margin_A3 = l_temp8_even; // uint8_t
    io_struct.VrefDac_Margin_A3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58087, l_temp8_even, l_temp8_odd));
    io_struct.TxDqDly_Margin_A3 = l_temp8_even; // uint8_t
    io_struct.DeviceVref_Margin_A3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58089, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RR_3_2 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RR_3_1 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5808a, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RR_3_0 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RR_2_3 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5808b, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RR_2_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RR_2_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5808c, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RR_1_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RR_1_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5808d, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RR_1_0 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RR_0_3 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5808e, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RR_0_2 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RR_0_1 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5808f, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RW_3_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RW_3_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58090, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RW_3_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RW_3_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58091, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RW_2_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RW_2_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58092, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RW_2_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RW_2_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58093, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RW_1_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RW_1_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58094, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RW_1_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RW_1_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58095, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RW_0_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RW_0_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58096, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_RW_0_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_RW_0_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58097, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WR_3_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WR_3_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58098, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WR_3_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WR_3_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58099, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WR_2_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WR_2_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5809a, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WR_2_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WR_2_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5809b, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WR_1_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WR_1_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5809c, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WR_1_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WR_1_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5809d, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WR_0_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WR_0_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5809e, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WR_0_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WR_0_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5809f, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WW_3_2 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WW_3_1 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x580a0, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WW_3_0 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WW_2_3 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x580a1, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WW_2_1 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WW_2_0 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x580a2, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WW_1_3 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WW_1_2 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x580a3, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WW_1_0 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WW_0_3 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x580a4, l_temp8_even, l_temp8_odd));
    io_struct.CDD_ChB_WW_0_2 = l_temp8_even; // int8_t
    io_struct.CDD_ChB_WW_0_1 = l_temp8_odd; // int8_t

    FAPI_TRY(read_dmem_field(i_target, 0x580b3, l_temp8_even, l_temp8_odd));
    io_struct.CS_Dly_Margin_B0 = l_temp8_even; // uint8_t
    io_struct.CS_Vref_Margin_B0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x580b4, l_temp8_even, l_temp8_odd));
    io_struct.CA_Dly_Margin_B0 = l_temp8_even; // uint8_t
    io_struct.CA_Vref_Margin_B0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x580c6, l_temp8_even, l_temp8_odd));
    io_struct.CS_Dly_Margin_B1 = l_temp8_even; // uint8_t
    io_struct.CS_Vref_Margin_B1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x580c7, l_temp8_even, l_temp8_odd));
    io_struct.CA_Dly_Margin_B1 = l_temp8_even; // uint8_t
    io_struct.CA_Vref_Margin_B1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x580d9, l_temp8_even, l_temp8_odd));
    io_struct.CS_Dly_Margin_B2 = l_temp8_even; // uint8_t
    io_struct.CS_Vref_Margin_B2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x580da, l_temp8_even, l_temp8_odd));
    io_struct.CA_Dly_Margin_B2 = l_temp8_even; // uint8_t
    io_struct.CA_Vref_Margin_B2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x580ec, l_temp8_even, l_temp8_odd));
    io_struct.CS_Dly_Margin_B3 = l_temp8_even; // uint8_t
    io_struct.CS_Vref_Margin_B3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x580ed, l_temp8_even, l_temp8_odd));
    io_struct.CA_Dly_Margin_B3 = l_temp8_even; // uint8_t
    io_struct.CA_Vref_Margin_B3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x580f1, l_temp8_even, l_temp8_odd));
    io_struct.Reserved1E3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x580f6, l_temp8_even, l_temp8_odd));
    io_struct.RxClkDly_Margin_B0 = l_temp8_even; // uint8_t
    io_struct.VrefDac_Margin_B0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x580f7, l_temp8_even, l_temp8_odd));
    io_struct.TxDqDly_Margin_B0 = l_temp8_even; // uint8_t
    io_struct.DeviceVref_Margin_B0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x580f8, l_temp8_even, l_temp8_odd));
    io_struct.RxClkDly_Margin_B1 = l_temp8_even; // uint8_t
    io_struct.VrefDac_Margin_B1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x580f9, l_temp8_even, l_temp8_odd));
    io_struct.TxDqDly_Margin_B1 = l_temp8_even; // uint8_t
    io_struct.DeviceVref_Margin_B1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x580fa, l_temp8_even, l_temp8_odd));
    io_struct.RxClkDly_Margin_B2 = l_temp8_even; // uint8_t
    io_struct.VrefDac_Margin_B2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x580fb, l_temp8_even, l_temp8_odd));
    io_struct.TxDqDly_Margin_B2 = l_temp8_even; // uint8_t
    io_struct.DeviceVref_Margin_B2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x580fc, l_temp8_even, l_temp8_odd));
    io_struct.RxClkDly_Margin_B3 = l_temp8_even; // uint8_t
    io_struct.VrefDac_Margin_B3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x580fd, l_temp8_even, l_temp8_odd));
    io_struct.TxDqDly_Margin_B3 = l_temp8_even; // uint8_t
    io_struct.DeviceVref_Margin_B3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58120, l_temp8_even, l_temp8_odd));
    io_struct.RCW40_ChA_D0 = l_temp8_even; // uint8_t
    io_struct.RCW41_ChA_D0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58121, l_temp8_even, l_temp8_odd));
    io_struct.RCW42_ChA_D0 = l_temp8_even; // uint8_t
    io_struct.RCW43_ChA_D0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58122, l_temp8_even, l_temp8_odd));
    io_struct.RCW44_ChA_D0 = l_temp8_even; // uint8_t
    io_struct.RCW45_ChA_D0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58123, l_temp8_even, l_temp8_odd));
    io_struct.RCW46_ChA_D0 = l_temp8_even; // uint8_t
    io_struct.RCW47_ChA_D0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58124, l_temp8_even, l_temp8_odd));
    io_struct.RCW48_ChA_D0 = l_temp8_even; // uint8_t
    io_struct.RCW49_ChA_D0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x581a0, l_temp8_even, l_temp8_odd));
    io_struct.RCW40_ChA_D1 = l_temp8_even; // uint8_t
    io_struct.RCW41_ChA_D1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x581a1, l_temp8_even, l_temp8_odd));
    io_struct.RCW42_ChA_D1 = l_temp8_even; // uint8_t
    io_struct.RCW43_ChA_D1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x581a2, l_temp8_even, l_temp8_odd));
    io_struct.RCW44_ChA_D1 = l_temp8_even; // uint8_t
    io_struct.RCW45_ChA_D1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x581a3, l_temp8_even, l_temp8_odd));
    io_struct.RCW46_ChA_D1 = l_temp8_even; // uint8_t
    io_struct.RCW47_ChA_D1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x581a4, l_temp8_even, l_temp8_odd));
    io_struct.RCW48_ChA_D1 = l_temp8_even; // uint8_t
    io_struct.RCW49_ChA_D1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58220, l_temp8_even, l_temp8_odd));
    io_struct.RCW40_ChB_D0 = l_temp8_even; // uint8_t
    io_struct.RCW41_ChB_D0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58221, l_temp8_even, l_temp8_odd));
    io_struct.RCW42_ChB_D0 = l_temp8_even; // uint8_t
    io_struct.RCW43_ChB_D0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58222, l_temp8_even, l_temp8_odd));
    io_struct.RCW44_ChB_D0 = l_temp8_even; // uint8_t
    io_struct.RCW45_ChB_D0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58223, l_temp8_even, l_temp8_odd));
    io_struct.RCW46_ChB_D0 = l_temp8_even; // uint8_t
    io_struct.RCW47_ChB_D0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58224, l_temp8_even, l_temp8_odd));
    io_struct.RCW48_ChB_D0 = l_temp8_even; // uint8_t
    io_struct.RCW49_ChB_D0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x582a0, l_temp8_even, l_temp8_odd));
    io_struct.RCW40_ChB_D1 = l_temp8_even; // uint8_t
    io_struct.RCW41_ChB_D1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x582a1, l_temp8_even, l_temp8_odd));
    io_struct.RCW42_ChB_D1 = l_temp8_even; // uint8_t
    io_struct.RCW43_ChB_D1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x582a2, l_temp8_even, l_temp8_odd));
    io_struct.RCW44_ChB_D1 = l_temp8_even; // uint8_t
    io_struct.RCW45_ChB_D1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x582a3, l_temp8_even, l_temp8_odd));
    io_struct.RCW46_ChB_D1 = l_temp8_even; // uint8_t
    io_struct.RCW47_ChB_D1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x582a4, l_temp8_even, l_temp8_odd));
    io_struct.RCW48_ChB_D1 = l_temp8_even; // uint8_t
    io_struct.RCW49_ChB_D1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58300, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR0Nib0 = l_temp8_even; // uint8_t
    io_struct.VrefDqR0Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58301, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR0Nib2 = l_temp8_even; // uint8_t
    io_struct.VrefDqR0Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58302, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR0Nib4 = l_temp8_even; // uint8_t
    io_struct.VrefDqR0Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58303, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR0Nib6 = l_temp8_even; // uint8_t
    io_struct.VrefDqR0Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58304, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR0Nib8 = l_temp8_even; // uint8_t
    io_struct.VrefDqR0Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58305, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR0Nib10 = l_temp8_even; // uint8_t
    io_struct.VrefDqR0Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58306, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR0Nib12 = l_temp8_even; // uint8_t
    io_struct.VrefDqR0Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58307, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR0Nib14 = l_temp8_even; // uint8_t
    io_struct.VrefDqR0Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58308, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR0Nib16 = l_temp8_even; // uint8_t
    io_struct.VrefDqR0Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58309, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR0Nib18 = l_temp8_even; // uint8_t
    io_struct.VrefDqR0Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5830a, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR1Nib0 = l_temp8_even; // uint8_t
    io_struct.VrefDqR1Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5830b, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR1Nib2 = l_temp8_even; // uint8_t
    io_struct.VrefDqR1Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5830c, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR1Nib4 = l_temp8_even; // uint8_t
    io_struct.VrefDqR1Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5830d, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR1Nib6 = l_temp8_even; // uint8_t
    io_struct.VrefDqR1Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5830e, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR1Nib8 = l_temp8_even; // uint8_t
    io_struct.VrefDqR1Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5830f, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR1Nib10 = l_temp8_even; // uint8_t
    io_struct.VrefDqR1Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58310, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR1Nib12 = l_temp8_even; // uint8_t
    io_struct.VrefDqR1Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58311, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR1Nib14 = l_temp8_even; // uint8_t
    io_struct.VrefDqR1Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58312, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR1Nib16 = l_temp8_even; // uint8_t
    io_struct.VrefDqR1Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58313, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR1Nib18 = l_temp8_even; // uint8_t
    io_struct.VrefDqR1Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58314, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR2Nib0 = l_temp8_even; // uint8_t
    io_struct.VrefDqR2Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58315, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR2Nib2 = l_temp8_even; // uint8_t
    io_struct.VrefDqR2Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58316, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR2Nib4 = l_temp8_even; // uint8_t
    io_struct.VrefDqR2Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58317, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR2Nib6 = l_temp8_even; // uint8_t
    io_struct.VrefDqR2Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58318, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR2Nib8 = l_temp8_even; // uint8_t
    io_struct.VrefDqR2Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58319, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR2Nib10 = l_temp8_even; // uint8_t
    io_struct.VrefDqR2Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5831a, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR2Nib12 = l_temp8_even; // uint8_t
    io_struct.VrefDqR2Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5831b, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR2Nib14 = l_temp8_even; // uint8_t
    io_struct.VrefDqR2Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5831c, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR2Nib16 = l_temp8_even; // uint8_t
    io_struct.VrefDqR2Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5831d, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR2Nib18 = l_temp8_even; // uint8_t
    io_struct.VrefDqR2Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5831e, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR3Nib0 = l_temp8_even; // uint8_t
    io_struct.VrefDqR3Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5831f, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR3Nib2 = l_temp8_even; // uint8_t
    io_struct.VrefDqR3Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58320, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR3Nib4 = l_temp8_even; // uint8_t
    io_struct.VrefDqR3Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58321, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR3Nib6 = l_temp8_even; // uint8_t
    io_struct.VrefDqR3Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58322, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR3Nib8 = l_temp8_even; // uint8_t
    io_struct.VrefDqR3Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58323, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR3Nib10 = l_temp8_even; // uint8_t
    io_struct.VrefDqR3Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58324, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR3Nib12 = l_temp8_even; // uint8_t
    io_struct.VrefDqR3Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58325, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR3Nib14 = l_temp8_even; // uint8_t
    io_struct.VrefDqR3Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58326, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR3Nib16 = l_temp8_even; // uint8_t
    io_struct.VrefDqR3Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58327, l_temp8_even, l_temp8_odd));
    io_struct.VrefDqR3Nib18 = l_temp8_even; // uint8_t
    io_struct.VrefDqR3Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58328, l_temp8_even, l_temp8_odd));
    io_struct.MR3R0Nib0 = l_temp8_even; // uint8_t
    io_struct.MR3R0Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58329, l_temp8_even, l_temp8_odd));
    io_struct.MR3R0Nib2 = l_temp8_even; // uint8_t
    io_struct.MR3R0Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5832a, l_temp8_even, l_temp8_odd));
    io_struct.MR3R0Nib4 = l_temp8_even; // uint8_t
    io_struct.MR3R0Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5832b, l_temp8_even, l_temp8_odd));
    io_struct.MR3R0Nib6 = l_temp8_even; // uint8_t
    io_struct.MR3R0Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5832c, l_temp8_even, l_temp8_odd));
    io_struct.MR3R0Nib8 = l_temp8_even; // uint8_t
    io_struct.MR3R0Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5832d, l_temp8_even, l_temp8_odd));
    io_struct.MR3R0Nib10 = l_temp8_even; // uint8_t
    io_struct.MR3R0Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5832e, l_temp8_even, l_temp8_odd));
    io_struct.MR3R0Nib12 = l_temp8_even; // uint8_t
    io_struct.MR3R0Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5832f, l_temp8_even, l_temp8_odd));
    io_struct.MR3R0Nib14 = l_temp8_even; // uint8_t
    io_struct.MR3R0Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58330, l_temp8_even, l_temp8_odd));
    io_struct.MR3R0Nib16 = l_temp8_even; // uint8_t
    io_struct.MR3R0Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58331, l_temp8_even, l_temp8_odd));
    io_struct.MR3R0Nib18 = l_temp8_even; // uint8_t
    io_struct.MR3R0Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58332, l_temp8_even, l_temp8_odd));
    io_struct.MR3R1Nib0 = l_temp8_even; // uint8_t
    io_struct.MR3R1Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58333, l_temp8_even, l_temp8_odd));
    io_struct.MR3R1Nib2 = l_temp8_even; // uint8_t
    io_struct.MR3R1Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58334, l_temp8_even, l_temp8_odd));
    io_struct.MR3R1Nib4 = l_temp8_even; // uint8_t
    io_struct.MR3R1Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58335, l_temp8_even, l_temp8_odd));
    io_struct.MR3R1Nib6 = l_temp8_even; // uint8_t
    io_struct.MR3R1Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58336, l_temp8_even, l_temp8_odd));
    io_struct.MR3R1Nib8 = l_temp8_even; // uint8_t
    io_struct.MR3R1Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58337, l_temp8_even, l_temp8_odd));
    io_struct.MR3R1Nib10 = l_temp8_even; // uint8_t
    io_struct.MR3R1Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58338, l_temp8_even, l_temp8_odd));
    io_struct.MR3R1Nib12 = l_temp8_even; // uint8_t
    io_struct.MR3R1Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58339, l_temp8_even, l_temp8_odd));
    io_struct.MR3R1Nib14 = l_temp8_even; // uint8_t
    io_struct.MR3R1Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5833a, l_temp8_even, l_temp8_odd));
    io_struct.MR3R1Nib16 = l_temp8_even; // uint8_t
    io_struct.MR3R1Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5833b, l_temp8_even, l_temp8_odd));
    io_struct.MR3R1Nib18 = l_temp8_even; // uint8_t
    io_struct.MR3R1Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5833c, l_temp8_even, l_temp8_odd));
    io_struct.MR3R2Nib0 = l_temp8_even; // uint8_t
    io_struct.MR3R2Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5833d, l_temp8_even, l_temp8_odd));
    io_struct.MR3R2Nib2 = l_temp8_even; // uint8_t
    io_struct.MR3R2Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5833e, l_temp8_even, l_temp8_odd));
    io_struct.MR3R2Nib4 = l_temp8_even; // uint8_t
    io_struct.MR3R2Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5833f, l_temp8_even, l_temp8_odd));
    io_struct.MR3R2Nib6 = l_temp8_even; // uint8_t
    io_struct.MR3R2Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58340, l_temp8_even, l_temp8_odd));
    io_struct.MR3R2Nib8 = l_temp8_even; // uint8_t
    io_struct.MR3R2Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58341, l_temp8_even, l_temp8_odd));
    io_struct.MR3R2Nib10 = l_temp8_even; // uint8_t
    io_struct.MR3R2Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58342, l_temp8_even, l_temp8_odd));
    io_struct.MR3R2Nib12 = l_temp8_even; // uint8_t
    io_struct.MR3R2Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58343, l_temp8_even, l_temp8_odd));
    io_struct.MR3R2Nib14 = l_temp8_even; // uint8_t
    io_struct.MR3R2Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58344, l_temp8_even, l_temp8_odd));
    io_struct.MR3R2Nib16 = l_temp8_even; // uint8_t
    io_struct.MR3R2Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58345, l_temp8_even, l_temp8_odd));
    io_struct.MR3R2Nib18 = l_temp8_even; // uint8_t
    io_struct.MR3R2Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58346, l_temp8_even, l_temp8_odd));
    io_struct.MR3R3Nib0 = l_temp8_even; // uint8_t
    io_struct.MR3R3Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58347, l_temp8_even, l_temp8_odd));
    io_struct.MR3R3Nib2 = l_temp8_even; // uint8_t
    io_struct.MR3R3Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58348, l_temp8_even, l_temp8_odd));
    io_struct.MR3R3Nib4 = l_temp8_even; // uint8_t
    io_struct.MR3R3Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58349, l_temp8_even, l_temp8_odd));
    io_struct.MR3R3Nib6 = l_temp8_even; // uint8_t
    io_struct.MR3R3Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5834a, l_temp8_even, l_temp8_odd));
    io_struct.MR3R3Nib8 = l_temp8_even; // uint8_t
    io_struct.MR3R3Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5834b, l_temp8_even, l_temp8_odd));
    io_struct.MR3R3Nib10 = l_temp8_even; // uint8_t
    io_struct.MR3R3Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5834c, l_temp8_even, l_temp8_odd));
    io_struct.MR3R3Nib12 = l_temp8_even; // uint8_t
    io_struct.MR3R3Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5834d, l_temp8_even, l_temp8_odd));
    io_struct.MR3R3Nib14 = l_temp8_even; // uint8_t
    io_struct.MR3R3Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5834e, l_temp8_even, l_temp8_odd));
    io_struct.MR3R3Nib16 = l_temp8_even; // uint8_t
    io_struct.MR3R3Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5834f, l_temp8_even, l_temp8_odd));
    io_struct.MR3R3Nib18 = l_temp8_even; // uint8_t
    io_struct.MR3R3Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58350, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR0Nib0 = l_temp8_even; // uint8_t
    io_struct.VrefCSR0Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58351, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR0Nib2 = l_temp8_even; // uint8_t
    io_struct.VrefCSR0Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58352, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR0Nib4 = l_temp8_even; // uint8_t
    io_struct.VrefCSR0Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58353, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR0Nib6 = l_temp8_even; // uint8_t
    io_struct.VrefCSR0Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58354, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR0Nib8 = l_temp8_even; // uint8_t
    io_struct.VrefCSR0Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58355, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR0Nib10 = l_temp8_even; // uint8_t
    io_struct.VrefCSR0Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58356, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR0Nib12 = l_temp8_even; // uint8_t
    io_struct.VrefCSR0Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58357, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR0Nib14 = l_temp8_even; // uint8_t
    io_struct.VrefCSR0Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58358, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR0Nib16 = l_temp8_even; // uint8_t
    io_struct.VrefCSR0Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58359, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR0Nib18 = l_temp8_even; // uint8_t
    io_struct.VrefCSR0Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5835a, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR1Nib0 = l_temp8_even; // uint8_t
    io_struct.VrefCSR1Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5835b, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR1Nib2 = l_temp8_even; // uint8_t
    io_struct.VrefCSR1Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5835c, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR1Nib4 = l_temp8_even; // uint8_t
    io_struct.VrefCSR1Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5835d, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR1Nib6 = l_temp8_even; // uint8_t
    io_struct.VrefCSR1Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5835e, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR1Nib8 = l_temp8_even; // uint8_t
    io_struct.VrefCSR1Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5835f, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR1Nib10 = l_temp8_even; // uint8_t
    io_struct.VrefCSR1Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58360, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR1Nib12 = l_temp8_even; // uint8_t
    io_struct.VrefCSR1Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58361, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR1Nib14 = l_temp8_even; // uint8_t
    io_struct.VrefCSR1Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58362, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR1Nib16 = l_temp8_even; // uint8_t
    io_struct.VrefCSR1Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58363, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR1Nib18 = l_temp8_even; // uint8_t
    io_struct.VrefCSR1Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58364, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR2Nib0 = l_temp8_even; // uint8_t
    io_struct.VrefCSR2Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58365, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR2Nib2 = l_temp8_even; // uint8_t
    io_struct.VrefCSR2Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58366, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR2Nib4 = l_temp8_even; // uint8_t
    io_struct.VrefCSR2Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58367, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR2Nib6 = l_temp8_even; // uint8_t
    io_struct.VrefCSR2Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58368, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR2Nib8 = l_temp8_even; // uint8_t
    io_struct.VrefCSR2Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58369, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR2Nib10 = l_temp8_even; // uint8_t
    io_struct.VrefCSR2Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5836a, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR2Nib12 = l_temp8_even; // uint8_t
    io_struct.VrefCSR2Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5836b, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR2Nib14 = l_temp8_even; // uint8_t
    io_struct.VrefCSR2Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5836c, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR2Nib16 = l_temp8_even; // uint8_t
    io_struct.VrefCSR2Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5836d, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR2Nib18 = l_temp8_even; // uint8_t
    io_struct.VrefCSR2Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5836e, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR3Nib0 = l_temp8_even; // uint8_t
    io_struct.VrefCSR3Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5836f, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR3Nib2 = l_temp8_even; // uint8_t
    io_struct.VrefCSR3Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58370, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR3Nib4 = l_temp8_even; // uint8_t
    io_struct.VrefCSR3Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58371, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR3Nib6 = l_temp8_even; // uint8_t
    io_struct.VrefCSR3Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58372, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR3Nib8 = l_temp8_even; // uint8_t
    io_struct.VrefCSR3Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58373, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR3Nib10 = l_temp8_even; // uint8_t
    io_struct.VrefCSR3Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58374, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR3Nib12 = l_temp8_even; // uint8_t
    io_struct.VrefCSR3Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58375, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR3Nib14 = l_temp8_even; // uint8_t
    io_struct.VrefCSR3Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58376, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR3Nib16 = l_temp8_even; // uint8_t
    io_struct.VrefCSR3Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58377, l_temp8_even, l_temp8_odd));
    io_struct.VrefCSR3Nib18 = l_temp8_even; // uint8_t
    io_struct.VrefCSR3Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58378, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR0Nib0 = l_temp8_even; // uint8_t
    io_struct.VrefCAR0Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58379, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR0Nib2 = l_temp8_even; // uint8_t
    io_struct.VrefCAR0Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5837a, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR0Nib4 = l_temp8_even; // uint8_t
    io_struct.VrefCAR0Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5837b, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR0Nib6 = l_temp8_even; // uint8_t
    io_struct.VrefCAR0Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5837c, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR0Nib8 = l_temp8_even; // uint8_t
    io_struct.VrefCAR0Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5837d, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR0Nib10 = l_temp8_even; // uint8_t
    io_struct.VrefCAR0Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5837e, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR0Nib12 = l_temp8_even; // uint8_t
    io_struct.VrefCAR0Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5837f, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR0Nib14 = l_temp8_even; // uint8_t
    io_struct.VrefCAR0Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58380, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR0Nib16 = l_temp8_even; // uint8_t
    io_struct.VrefCAR0Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58381, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR0Nib18 = l_temp8_even; // uint8_t
    io_struct.VrefCAR0Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58382, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR1Nib0 = l_temp8_even; // uint8_t
    io_struct.VrefCAR1Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58383, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR1Nib2 = l_temp8_even; // uint8_t
    io_struct.VrefCAR1Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58384, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR1Nib4 = l_temp8_even; // uint8_t
    io_struct.VrefCAR1Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58385, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR1Nib6 = l_temp8_even; // uint8_t
    io_struct.VrefCAR1Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58386, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR1Nib8 = l_temp8_even; // uint8_t
    io_struct.VrefCAR1Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58387, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR1Nib10 = l_temp8_even; // uint8_t
    io_struct.VrefCAR1Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58388, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR1Nib12 = l_temp8_even; // uint8_t
    io_struct.VrefCAR1Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58389, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR1Nib14 = l_temp8_even; // uint8_t
    io_struct.VrefCAR1Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5838a, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR1Nib16 = l_temp8_even; // uint8_t
    io_struct.VrefCAR1Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5838b, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR1Nib18 = l_temp8_even; // uint8_t
    io_struct.VrefCAR1Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5838c, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR2Nib0 = l_temp8_even; // uint8_t
    io_struct.VrefCAR2Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5838d, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR2Nib2 = l_temp8_even; // uint8_t
    io_struct.VrefCAR2Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5838e, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR2Nib4 = l_temp8_even; // uint8_t
    io_struct.VrefCAR2Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5838f, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR2Nib6 = l_temp8_even; // uint8_t
    io_struct.VrefCAR2Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58390, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR2Nib8 = l_temp8_even; // uint8_t
    io_struct.VrefCAR2Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58391, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR2Nib10 = l_temp8_even; // uint8_t
    io_struct.VrefCAR2Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58392, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR2Nib12 = l_temp8_even; // uint8_t
    io_struct.VrefCAR2Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58393, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR2Nib14 = l_temp8_even; // uint8_t
    io_struct.VrefCAR2Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58394, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR2Nib16 = l_temp8_even; // uint8_t
    io_struct.VrefCAR2Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58395, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR2Nib18 = l_temp8_even; // uint8_t
    io_struct.VrefCAR2Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58396, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR3Nib0 = l_temp8_even; // uint8_t
    io_struct.VrefCAR3Nib1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58397, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR3Nib2 = l_temp8_even; // uint8_t
    io_struct.VrefCAR3Nib3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58398, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR3Nib4 = l_temp8_even; // uint8_t
    io_struct.VrefCAR3Nib5 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x58399, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR3Nib6 = l_temp8_even; // uint8_t
    io_struct.VrefCAR3Nib7 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5839a, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR3Nib8 = l_temp8_even; // uint8_t
    io_struct.VrefCAR3Nib9 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5839b, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR3Nib10 = l_temp8_even; // uint8_t
    io_struct.VrefCAR3Nib11 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5839c, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR3Nib12 = l_temp8_even; // uint8_t
    io_struct.VrefCAR3Nib13 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5839d, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR3Nib14 = l_temp8_even; // uint8_t
    io_struct.VrefCAR3Nib15 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5839e, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR3Nib16 = l_temp8_even; // uint8_t
    io_struct.VrefCAR3Nib17 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x5839f, l_temp8_even, l_temp8_odd));
    io_struct.VrefCAR3Nib18 = l_temp8_even; // uint8_t
    io_struct.VrefCAR3Nib19 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583a0, l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB0LaneR0 = l_temp8_even; // uint8_t
    io_struct.DisabledDB1LaneR0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583a1, l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB2LaneR0 = l_temp8_even; // uint8_t
    io_struct.DisabledDB3LaneR0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583a2, l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB4LaneR0 = l_temp8_even; // uint8_t
    io_struct.DisabledDB5LaneR0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583a3, l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB6LaneR0 = l_temp8_even; // uint8_t
    io_struct.DisabledDB7LaneR0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583a4, l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB8LaneR0 = l_temp8_even; // uint8_t
    io_struct.DisabledDB9LaneR0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583a5, l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB0LaneR1 = l_temp8_even; // uint8_t
    io_struct.DisabledDB1LaneR1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583a6, l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB2LaneR1 = l_temp8_even; // uint8_t
    io_struct.DisabledDB3LaneR1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583a7, l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB4LaneR1 = l_temp8_even; // uint8_t
    io_struct.DisabledDB5LaneR1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583a8, l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB6LaneR1 = l_temp8_even; // uint8_t
    io_struct.DisabledDB7LaneR1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583a9, l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB8LaneR1 = l_temp8_even; // uint8_t
    io_struct.DisabledDB9LaneR1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583aa, l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB0LaneR2 = l_temp8_even; // uint8_t
    io_struct.DisabledDB1LaneR2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583ab, l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB2LaneR2 = l_temp8_even; // uint8_t
    io_struct.DisabledDB3LaneR2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583ac, l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB4LaneR2 = l_temp8_even; // uint8_t
    io_struct.DisabledDB5LaneR2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583ad, l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB6LaneR2 = l_temp8_even; // uint8_t
    io_struct.DisabledDB7LaneR2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583ae, l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB8LaneR2 = l_temp8_even; // uint8_t
    io_struct.DisabledDB9LaneR2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583af, l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB0LaneR3 = l_temp8_even; // uint8_t
    io_struct.DisabledDB1LaneR3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583b0, l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB2LaneR3 = l_temp8_even; // uint8_t
    io_struct.DisabledDB3LaneR3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583b1, l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB4LaneR3 = l_temp8_even; // uint8_t
    io_struct.DisabledDB5LaneR3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583b2, l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB6LaneR3 = l_temp8_even; // uint8_t
    io_struct.DisabledDB7LaneR3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583b3, l_temp8_even, l_temp8_odd));
    io_struct.DisabledDB8LaneR3 = l_temp8_even; // uint8_t
    io_struct.DisabledDB9LaneR3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583b4, l_temp8_even, l_temp8_odd));
    io_struct.QCS_Dly_Margin_A0 = l_temp8_even; // uint8_t
    io_struct.QCA_Dly_Margin_A0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583b5, l_temp8_even, l_temp8_odd));
    io_struct.QCS_Dly_Margin_A1 = l_temp8_even; // uint8_t
    io_struct.QCA_Dly_Margin_A1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583b6, l_temp8_even, l_temp8_odd));
    io_struct.QCS_Dly_Margin_A2 = l_temp8_even; // uint8_t
    io_struct.QCA_Dly_Margin_A2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583b7, l_temp8_even, l_temp8_odd));
    io_struct.QCS_Dly_Margin_A3 = l_temp8_even; // uint8_t
    io_struct.QCA_Dly_Margin_A3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583b8, l_temp8_even, l_temp8_odd));
    io_struct.QCS_Dly_Margin_B0 = l_temp8_even; // uint8_t
    io_struct.QCA_Dly_Margin_B0 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583b9, l_temp8_even, l_temp8_odd));
    io_struct.QCS_Dly_Margin_B1 = l_temp8_even; // uint8_t
    io_struct.QCA_Dly_Margin_B1 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583ba, l_temp8_even, l_temp8_odd));
    io_struct.QCS_Dly_Margin_B2 = l_temp8_even; // uint8_t
    io_struct.QCA_Dly_Margin_B2 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583bb, l_temp8_even, l_temp8_odd));
    io_struct.QCS_Dly_Margin_B3 = l_temp8_even; // uint8_t
    io_struct.QCA_Dly_Margin_B3 = l_temp8_odd; // uint8_t

    FAPI_TRY(read_dmem_field(i_target, 0x583bc, l_temp16));
    io_struct.PmuInternalRev0 = l_temp16; // uint16_t

    FAPI_TRY(read_dmem_field(i_target, 0x583bd, l_temp16));
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
    FAPI_TRY(l_mr.attr_setter(i_rank_infos[0]));

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
#ifndef __PPE__
    FAPI_INF("   _PMU_SMB_DDR5_1D_t   = { // " TARGTIDFORMAT, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "AdvTrainOpt          ", i_msg_block.AdvTrainOpt, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MsgMisc              ", i_msg_block.MsgMisc, TARGTID);
    FAPI_INF("  .%s= 0x%04x; // " TARGTIDFORMAT, "PmuRevision          ", i_msg_block.PmuRevision, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Pstate               ", i_msg_block.Pstate, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "PllBypassEn          ", i_msg_block.PllBypassEn, TARGTID);
    FAPI_INF("  .%s= 0x%04x; // " TARGTIDFORMAT, "DRAMFreq             ", i_msg_block.DRAMFreq, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW05_next           ", i_msg_block.RCW05_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW06_next           ", i_msg_block.RCW06_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RXEN_ADJ             ", i_msg_block.RXEN_ADJ, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RX2D_DFE_Misc        ", i_msg_block.RX2D_DFE_Misc, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "PhyVref              ", i_msg_block.PhyVref, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "D5Misc               ", i_msg_block.D5Misc, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "WL_ADJ               ", i_msg_block.WL_ADJ, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CsTestFail           ", i_msg_block.CsTestFail, TARGTID);
    FAPI_INF("  .%s= 0x%04x; // " TARGTIDFORMAT, "SequenceCtrl         ", i_msg_block.SequenceCtrl, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "HdtCtrl              ", i_msg_block.HdtCtrl, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "PhyCfg               ", i_msg_block.PhyCfg, TARGTID);
    FAPI_INF("  .%s= 0x%04x; // " TARGTIDFORMAT, "ResultAddrOffset     ", i_msg_block.ResultAddrOffset, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DFIMRLMargin         ", i_msg_block.DFIMRLMargin, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "X16Present           ", i_msg_block.X16Present, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "UseBroadcastMR       ", i_msg_block.UseBroadcastMR, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "D5Quickboot          ", i_msg_block.D5Quickboot, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDbyte        ", i_msg_block.DisabledDbyte, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CATrainOpt           ", i_msg_block.CATrainOpt, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "TX2D_DFE_Misc        ", i_msg_block.TX2D_DFE_Misc, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RX2D_TrainOpt        ", i_msg_block.RX2D_TrainOpt, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "TX2D_TrainOpt        ", i_msg_block.TX2D_TrainOpt, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Share2DVrefResult    ", i_msg_block.Share2DVrefResult, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MRE_MIN_PULSE        ", i_msg_block.MRE_MIN_PULSE, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DWL_MIN_PULSE        ", i_msg_block.DWL_MIN_PULSE, TARGTID);
    FAPI_INF("  .%s= 0x%04x; // " TARGTIDFORMAT, "PhyConfigOverride    ", i_msg_block.PhyConfigOverride, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "EnabledDQsChA        ", i_msg_block.EnabledDQsChA, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CsPresentChA         ", i_msg_block.CsPresentChA, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RR_3_2       ", i_msg_block.CDD_ChA_RR_3_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RR_3_1       ", i_msg_block.CDD_ChA_RR_3_1, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RR_3_0       ", i_msg_block.CDD_ChA_RR_3_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RR_2_3       ", i_msg_block.CDD_ChA_RR_2_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RR_2_1       ", i_msg_block.CDD_ChA_RR_2_1, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RR_2_0       ", i_msg_block.CDD_ChA_RR_2_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RR_1_3       ", i_msg_block.CDD_ChA_RR_1_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RR_1_2       ", i_msg_block.CDD_ChA_RR_1_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RR_1_0       ", i_msg_block.CDD_ChA_RR_1_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RR_0_3       ", i_msg_block.CDD_ChA_RR_0_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RR_0_2       ", i_msg_block.CDD_ChA_RR_0_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RR_0_1       ", i_msg_block.CDD_ChA_RR_0_1, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RW_3_3       ", i_msg_block.CDD_ChA_RW_3_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RW_3_2       ", i_msg_block.CDD_ChA_RW_3_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RW_3_1       ", i_msg_block.CDD_ChA_RW_3_1, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RW_3_0       ", i_msg_block.CDD_ChA_RW_3_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RW_2_3       ", i_msg_block.CDD_ChA_RW_2_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RW_2_2       ", i_msg_block.CDD_ChA_RW_2_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RW_2_1       ", i_msg_block.CDD_ChA_RW_2_1, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RW_2_0       ", i_msg_block.CDD_ChA_RW_2_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RW_1_3       ", i_msg_block.CDD_ChA_RW_1_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RW_1_2       ", i_msg_block.CDD_ChA_RW_1_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RW_1_1       ", i_msg_block.CDD_ChA_RW_1_1, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RW_1_0       ", i_msg_block.CDD_ChA_RW_1_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RW_0_3       ", i_msg_block.CDD_ChA_RW_0_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RW_0_2       ", i_msg_block.CDD_ChA_RW_0_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RW_0_1       ", i_msg_block.CDD_ChA_RW_0_1, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_RW_0_0       ", i_msg_block.CDD_ChA_RW_0_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WR_3_3       ", i_msg_block.CDD_ChA_WR_3_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WR_3_2       ", i_msg_block.CDD_ChA_WR_3_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WR_3_1       ", i_msg_block.CDD_ChA_WR_3_1, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WR_3_0       ", i_msg_block.CDD_ChA_WR_3_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WR_2_3       ", i_msg_block.CDD_ChA_WR_2_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WR_2_2       ", i_msg_block.CDD_ChA_WR_2_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WR_2_1       ", i_msg_block.CDD_ChA_WR_2_1, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WR_2_0       ", i_msg_block.CDD_ChA_WR_2_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WR_1_3       ", i_msg_block.CDD_ChA_WR_1_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WR_1_2       ", i_msg_block.CDD_ChA_WR_1_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WR_1_1       ", i_msg_block.CDD_ChA_WR_1_1, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WR_1_0       ", i_msg_block.CDD_ChA_WR_1_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WR_0_3       ", i_msg_block.CDD_ChA_WR_0_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WR_0_2       ", i_msg_block.CDD_ChA_WR_0_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WR_0_1       ", i_msg_block.CDD_ChA_WR_0_1, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WR_0_0       ", i_msg_block.CDD_ChA_WR_0_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WW_3_2       ", i_msg_block.CDD_ChA_WW_3_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WW_3_1       ", i_msg_block.CDD_ChA_WW_3_1, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WW_3_0       ", i_msg_block.CDD_ChA_WW_3_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WW_2_3       ", i_msg_block.CDD_ChA_WW_2_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WW_2_1       ", i_msg_block.CDD_ChA_WW_2_1, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WW_2_0       ", i_msg_block.CDD_ChA_WW_2_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WW_1_3       ", i_msg_block.CDD_ChA_WW_1_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WW_1_2       ", i_msg_block.CDD_ChA_WW_1_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WW_1_0       ", i_msg_block.CDD_ChA_WW_1_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WW_0_3       ", i_msg_block.CDD_ChA_WW_0_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WW_0_2       ", i_msg_block.CDD_ChA_WW_0_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChA_WW_0_1       ", i_msg_block.CDD_ChA_WW_0_1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR0_A0               ", i_msg_block.MR0_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR2_A0               ", i_msg_block.MR2_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3_A0               ", i_msg_block.MR3_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR4_A0               ", i_msg_block.MR4_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR5_A0               ", i_msg_block.MR5_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR6_A0               ", i_msg_block.MR6_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_A0_next         ", i_msg_block.MR32_A0_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR8_A0               ", i_msg_block.MR8_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_ORG_A0_next     ", i_msg_block.MR32_ORG_A0_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR10_A0              ", i_msg_block.MR10_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR11_A0              ", i_msg_block.MR11_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR12_A0              ", i_msg_block.MR12_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR13_A0              ", i_msg_block.MR13_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR14_A0              ", i_msg_block.MR14_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR15_A0              ", i_msg_block.MR15_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR111_A0             ", i_msg_block.MR111_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_A0              ", i_msg_block.MR32_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_A0              ", i_msg_block.MR33_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR34_A0              ", i_msg_block.MR34_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR35_A0              ", i_msg_block.MR35_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_ORG_A0          ", i_msg_block.MR32_ORG_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR37_A0              ", i_msg_block.MR37_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR38_A0              ", i_msg_block.MR38_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR39_A0              ", i_msg_block.MR39_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_ORG_A0          ", i_msg_block.MR33_ORG_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR11_A0_next         ", i_msg_block.MR11_A0_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR12_A0_next         ", i_msg_block.MR12_A0_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR13_A0_next         ", i_msg_block.MR13_A0_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CS_Dly_Margin_A0     ", i_msg_block.CS_Dly_Margin_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CS_Vref_Margin_A0    ", i_msg_block.CS_Vref_Margin_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CA_Dly_Margin_A0     ", i_msg_block.CA_Dly_Margin_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CA_Vref_Margin_A0    ", i_msg_block.CA_Vref_Margin_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_ORG_A0_next     ", i_msg_block.MR33_ORG_A0_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_A0_next         ", i_msg_block.MR33_A0_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR50_A0              ", i_msg_block.MR50_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR51_A0              ", i_msg_block.MR51_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR52_A0              ", i_msg_block.MR52_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DFE_GainBias_A0      ", i_msg_block.DFE_GainBias_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR0_A1               ", i_msg_block.MR0_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR2_A1               ", i_msg_block.MR2_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3_A1               ", i_msg_block.MR3_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR4_A1               ", i_msg_block.MR4_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR5_A1               ", i_msg_block.MR5_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR6_A1               ", i_msg_block.MR6_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_A1_next         ", i_msg_block.MR32_A1_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR8_A1               ", i_msg_block.MR8_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_ORG_A1_next     ", i_msg_block.MR32_ORG_A1_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR10_A1              ", i_msg_block.MR10_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR11_A1              ", i_msg_block.MR11_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR12_A1              ", i_msg_block.MR12_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR13_A1              ", i_msg_block.MR13_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR14_A1              ", i_msg_block.MR14_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR15_A1              ", i_msg_block.MR15_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR111_A1             ", i_msg_block.MR111_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_A1              ", i_msg_block.MR32_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_A1              ", i_msg_block.MR33_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR34_A1              ", i_msg_block.MR34_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR35_A1              ", i_msg_block.MR35_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_ORG_A1          ", i_msg_block.MR32_ORG_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR37_A1              ", i_msg_block.MR37_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR38_A1              ", i_msg_block.MR38_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR39_A1              ", i_msg_block.MR39_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_ORG_A1          ", i_msg_block.MR33_ORG_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR11_A1_next         ", i_msg_block.MR11_A1_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR12_A1_next         ", i_msg_block.MR12_A1_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR13_A1_next         ", i_msg_block.MR13_A1_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CS_Dly_Margin_A1     ", i_msg_block.CS_Dly_Margin_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CS_Vref_Margin_A1    ", i_msg_block.CS_Vref_Margin_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CA_Dly_Margin_A1     ", i_msg_block.CA_Dly_Margin_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CA_Vref_Margin_A1    ", i_msg_block.CA_Vref_Margin_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_ORG_A1_next     ", i_msg_block.MR33_ORG_A1_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_A1_next         ", i_msg_block.MR33_A1_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR50_A1              ", i_msg_block.MR50_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR51_A1              ", i_msg_block.MR51_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR52_A1              ", i_msg_block.MR52_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DFE_GainBias_A1      ", i_msg_block.DFE_GainBias_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR0_A2               ", i_msg_block.MR0_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR2_A2               ", i_msg_block.MR2_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3_A2               ", i_msg_block.MR3_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR4_A2               ", i_msg_block.MR4_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR5_A2               ", i_msg_block.MR5_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR6_A2               ", i_msg_block.MR6_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_A2_next         ", i_msg_block.MR32_A2_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR8_A2               ", i_msg_block.MR8_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_ORG_A2_next     ", i_msg_block.MR32_ORG_A2_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR10_A2              ", i_msg_block.MR10_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR11_A2              ", i_msg_block.MR11_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR12_A2              ", i_msg_block.MR12_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR13_A2              ", i_msg_block.MR13_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR14_A2              ", i_msg_block.MR14_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR15_A2              ", i_msg_block.MR15_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR111_A2             ", i_msg_block.MR111_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_A2              ", i_msg_block.MR32_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_A2              ", i_msg_block.MR33_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR34_A2              ", i_msg_block.MR34_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR35_A2              ", i_msg_block.MR35_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_ORG_A2          ", i_msg_block.MR32_ORG_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR37_A2              ", i_msg_block.MR37_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR38_A2              ", i_msg_block.MR38_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR39_A2              ", i_msg_block.MR39_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_ORG_A2          ", i_msg_block.MR33_ORG_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR11_A2_next         ", i_msg_block.MR11_A2_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR12_A2_next         ", i_msg_block.MR12_A2_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR13_A2_next         ", i_msg_block.MR13_A2_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CS_Dly_Margin_A2     ", i_msg_block.CS_Dly_Margin_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CS_Vref_Margin_A2    ", i_msg_block.CS_Vref_Margin_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CA_Dly_Margin_A2     ", i_msg_block.CA_Dly_Margin_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CA_Vref_Margin_A2    ", i_msg_block.CA_Vref_Margin_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_ORG_A2_next     ", i_msg_block.MR33_ORG_A2_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_A2_next         ", i_msg_block.MR33_A2_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR50_A2              ", i_msg_block.MR50_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR51_A2              ", i_msg_block.MR51_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR52_A2              ", i_msg_block.MR52_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DFE_GainBias_A2      ", i_msg_block.DFE_GainBias_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR0_A3               ", i_msg_block.MR0_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR2_A3               ", i_msg_block.MR2_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3_A3               ", i_msg_block.MR3_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR4_A3               ", i_msg_block.MR4_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR5_A3               ", i_msg_block.MR5_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR6_A3               ", i_msg_block.MR6_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_A3_next         ", i_msg_block.MR32_A3_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR8_A3               ", i_msg_block.MR8_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_ORG_A3_next     ", i_msg_block.MR32_ORG_A3_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR10_A3              ", i_msg_block.MR10_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR11_A3              ", i_msg_block.MR11_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR12_A3              ", i_msg_block.MR12_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR13_A3              ", i_msg_block.MR13_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR14_A3              ", i_msg_block.MR14_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR15_A3              ", i_msg_block.MR15_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR111_A3             ", i_msg_block.MR111_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_A3              ", i_msg_block.MR32_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_A3              ", i_msg_block.MR33_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR34_A3              ", i_msg_block.MR34_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR35_A3              ", i_msg_block.MR35_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_ORG_A3          ", i_msg_block.MR32_ORG_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR37_A3              ", i_msg_block.MR37_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR38_A3              ", i_msg_block.MR38_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR39_A3              ", i_msg_block.MR39_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_ORG_A3          ", i_msg_block.MR33_ORG_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR11_A3_next         ", i_msg_block.MR11_A3_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR12_A3_next         ", i_msg_block.MR12_A3_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR13_A3_next         ", i_msg_block.MR13_A3_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CS_Dly_Margin_A3     ", i_msg_block.CS_Dly_Margin_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CS_Vref_Margin_A3    ", i_msg_block.CS_Vref_Margin_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CA_Dly_Margin_A3     ", i_msg_block.CA_Dly_Margin_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CA_Vref_Margin_A3    ", i_msg_block.CA_Vref_Margin_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_ORG_A3_next     ", i_msg_block.MR33_ORG_A3_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_A3_next         ", i_msg_block.MR33_A3_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR50_A3              ", i_msg_block.MR50_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR51_A3              ", i_msg_block.MR51_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR52_A3              ", i_msg_block.MR52_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DFE_GainBias_A3      ", i_msg_block.DFE_GainBias_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "ReservedF6           ", i_msg_block.ReservedF6, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "ReservedF7           ", i_msg_block.ReservedF7, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "ReservedF8           ", i_msg_block.ReservedF8, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "ReservedF9           ", i_msg_block.ReservedF9, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW04_next           ", i_msg_block.BCW04_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW05_next           ", i_msg_block.BCW05_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "WR_RD_RTT_PARK_A0    ", i_msg_block.WR_RD_RTT_PARK_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "WR_RD_RTT_PARK_A1    ", i_msg_block.WR_RD_RTT_PARK_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "WR_RD_RTT_PARK_A2    ", i_msg_block.WR_RD_RTT_PARK_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "WR_RD_RTT_PARK_A3    ", i_msg_block.WR_RD_RTT_PARK_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RxClkDly_Margin_A0   ", i_msg_block.RxClkDly_Margin_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDac_Margin_A0    ", i_msg_block.VrefDac_Margin_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "TxDqDly_Margin_A0    ", i_msg_block.TxDqDly_Margin_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DeviceVref_Margin_A0 ", i_msg_block.DeviceVref_Margin_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RxClkDly_Margin_A1   ", i_msg_block.RxClkDly_Margin_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDac_Margin_A1    ", i_msg_block.VrefDac_Margin_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "TxDqDly_Margin_A1    ", i_msg_block.TxDqDly_Margin_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DeviceVref_Margin_A1 ", i_msg_block.DeviceVref_Margin_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RxClkDly_Margin_A2   ", i_msg_block.RxClkDly_Margin_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDac_Margin_A2    ", i_msg_block.VrefDac_Margin_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "TxDqDly_Margin_A2    ", i_msg_block.TxDqDly_Margin_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DeviceVref_Margin_A2 ", i_msg_block.DeviceVref_Margin_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RxClkDly_Margin_A3   ", i_msg_block.RxClkDly_Margin_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDac_Margin_A3    ", i_msg_block.VrefDac_Margin_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "TxDqDly_Margin_A3    ", i_msg_block.TxDqDly_Margin_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DeviceVref_Margin_A3 ", i_msg_block.DeviceVref_Margin_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "EnabledDQsChB        ", i_msg_block.EnabledDQsChB, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CsPresentChB         ", i_msg_block.CsPresentChB, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RR_3_2       ", i_msg_block.CDD_ChB_RR_3_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RR_3_1       ", i_msg_block.CDD_ChB_RR_3_1, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RR_3_0       ", i_msg_block.CDD_ChB_RR_3_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RR_2_3       ", i_msg_block.CDD_ChB_RR_2_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RR_2_1       ", i_msg_block.CDD_ChB_RR_2_1, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RR_2_0       ", i_msg_block.CDD_ChB_RR_2_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RR_1_3       ", i_msg_block.CDD_ChB_RR_1_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RR_1_2       ", i_msg_block.CDD_ChB_RR_1_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RR_1_0       ", i_msg_block.CDD_ChB_RR_1_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RR_0_3       ", i_msg_block.CDD_ChB_RR_0_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RR_0_2       ", i_msg_block.CDD_ChB_RR_0_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RR_0_1       ", i_msg_block.CDD_ChB_RR_0_1, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RW_3_3       ", i_msg_block.CDD_ChB_RW_3_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RW_3_2       ", i_msg_block.CDD_ChB_RW_3_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RW_3_1       ", i_msg_block.CDD_ChB_RW_3_1, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RW_3_0       ", i_msg_block.CDD_ChB_RW_3_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RW_2_3       ", i_msg_block.CDD_ChB_RW_2_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RW_2_2       ", i_msg_block.CDD_ChB_RW_2_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RW_2_1       ", i_msg_block.CDD_ChB_RW_2_1, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RW_2_0       ", i_msg_block.CDD_ChB_RW_2_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RW_1_3       ", i_msg_block.CDD_ChB_RW_1_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RW_1_2       ", i_msg_block.CDD_ChB_RW_1_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RW_1_1       ", i_msg_block.CDD_ChB_RW_1_1, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RW_1_0       ", i_msg_block.CDD_ChB_RW_1_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RW_0_3       ", i_msg_block.CDD_ChB_RW_0_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RW_0_2       ", i_msg_block.CDD_ChB_RW_0_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RW_0_1       ", i_msg_block.CDD_ChB_RW_0_1, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_RW_0_0       ", i_msg_block.CDD_ChB_RW_0_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WR_3_3       ", i_msg_block.CDD_ChB_WR_3_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WR_3_2       ", i_msg_block.CDD_ChB_WR_3_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WR_3_1       ", i_msg_block.CDD_ChB_WR_3_1, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WR_3_0       ", i_msg_block.CDD_ChB_WR_3_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WR_2_3       ", i_msg_block.CDD_ChB_WR_2_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WR_2_2       ", i_msg_block.CDD_ChB_WR_2_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WR_2_1       ", i_msg_block.CDD_ChB_WR_2_1, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WR_2_0       ", i_msg_block.CDD_ChB_WR_2_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WR_1_3       ", i_msg_block.CDD_ChB_WR_1_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WR_1_2       ", i_msg_block.CDD_ChB_WR_1_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WR_1_1       ", i_msg_block.CDD_ChB_WR_1_1, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WR_1_0       ", i_msg_block.CDD_ChB_WR_1_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WR_0_3       ", i_msg_block.CDD_ChB_WR_0_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WR_0_2       ", i_msg_block.CDD_ChB_WR_0_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WR_0_1       ", i_msg_block.CDD_ChB_WR_0_1, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WR_0_0       ", i_msg_block.CDD_ChB_WR_0_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WW_3_2       ", i_msg_block.CDD_ChB_WW_3_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WW_3_1       ", i_msg_block.CDD_ChB_WW_3_1, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WW_3_0       ", i_msg_block.CDD_ChB_WW_3_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WW_2_3       ", i_msg_block.CDD_ChB_WW_2_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WW_2_1       ", i_msg_block.CDD_ChB_WW_2_1, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WW_2_0       ", i_msg_block.CDD_ChB_WW_2_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WW_1_3       ", i_msg_block.CDD_ChB_WW_1_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WW_1_2       ", i_msg_block.CDD_ChB_WW_1_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WW_1_0       ", i_msg_block.CDD_ChB_WW_1_0, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WW_0_3       ", i_msg_block.CDD_ChB_WW_0_3, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WW_0_2       ", i_msg_block.CDD_ChB_WW_0_2, TARGTID);
    FAPI_INF("  .%s= %d; // " TARGTIDFORMAT, "CDD_ChB_WW_0_1       ", i_msg_block.CDD_ChB_WW_0_1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR0_B0               ", i_msg_block.MR0_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR2_B0               ", i_msg_block.MR2_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3_B0               ", i_msg_block.MR3_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR4_B0               ", i_msg_block.MR4_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR5_B0               ", i_msg_block.MR5_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR6_B0               ", i_msg_block.MR6_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_B0_next         ", i_msg_block.MR32_B0_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR8_B0               ", i_msg_block.MR8_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_ORG_B0_next     ", i_msg_block.MR32_ORG_B0_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR10_B0              ", i_msg_block.MR10_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR11_B0              ", i_msg_block.MR11_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR12_B0              ", i_msg_block.MR12_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR13_B0              ", i_msg_block.MR13_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR14_B0              ", i_msg_block.MR14_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR15_B0              ", i_msg_block.MR15_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR111_B0             ", i_msg_block.MR111_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_B0              ", i_msg_block.MR32_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_B0              ", i_msg_block.MR33_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR34_B0              ", i_msg_block.MR34_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR35_B0              ", i_msg_block.MR35_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_ORG_B0          ", i_msg_block.MR32_ORG_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR37_B0              ", i_msg_block.MR37_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR38_B0              ", i_msg_block.MR38_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR39_B0              ", i_msg_block.MR39_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_ORG_B0          ", i_msg_block.MR33_ORG_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR11_B0_next         ", i_msg_block.MR11_B0_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR12_B0_next         ", i_msg_block.MR12_B0_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR13_B0_next         ", i_msg_block.MR13_B0_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CS_Dly_Margin_B0     ", i_msg_block.CS_Dly_Margin_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CS_Vref_Margin_B0    ", i_msg_block.CS_Vref_Margin_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CA_Dly_Margin_B0     ", i_msg_block.CA_Dly_Margin_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CA_Vref_Margin_B0    ", i_msg_block.CA_Vref_Margin_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_ORG_B0_next     ", i_msg_block.MR33_ORG_B0_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_B0_next         ", i_msg_block.MR33_B0_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR50_B0              ", i_msg_block.MR50_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR51_B0              ", i_msg_block.MR51_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR52_B0              ", i_msg_block.MR52_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DFE_GainBias_B0      ", i_msg_block.DFE_GainBias_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR0_B1               ", i_msg_block.MR0_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR2_B1               ", i_msg_block.MR2_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3_B1               ", i_msg_block.MR3_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR4_B1               ", i_msg_block.MR4_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR5_B1               ", i_msg_block.MR5_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR6_B1               ", i_msg_block.MR6_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_B1_next         ", i_msg_block.MR32_B1_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR8_B1               ", i_msg_block.MR8_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_ORG_B1_next     ", i_msg_block.MR32_ORG_B1_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR10_B1              ", i_msg_block.MR10_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR11_B1              ", i_msg_block.MR11_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR12_B1              ", i_msg_block.MR12_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR13_B1              ", i_msg_block.MR13_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR14_B1              ", i_msg_block.MR14_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR15_B1              ", i_msg_block.MR15_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR111_B1             ", i_msg_block.MR111_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_B1              ", i_msg_block.MR32_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_B1              ", i_msg_block.MR33_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR34_B1              ", i_msg_block.MR34_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR35_B1              ", i_msg_block.MR35_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_ORG_B1          ", i_msg_block.MR32_ORG_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR37_B1              ", i_msg_block.MR37_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR38_B1              ", i_msg_block.MR38_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR39_B1              ", i_msg_block.MR39_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_ORG_B1          ", i_msg_block.MR33_ORG_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR11_B1_next         ", i_msg_block.MR11_B1_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR12_B1_next         ", i_msg_block.MR12_B1_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR13_B1_next         ", i_msg_block.MR13_B1_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CS_Dly_Margin_B1     ", i_msg_block.CS_Dly_Margin_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CS_Vref_Margin_B1    ", i_msg_block.CS_Vref_Margin_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CA_Dly_Margin_B1     ", i_msg_block.CA_Dly_Margin_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CA_Vref_Margin_B1    ", i_msg_block.CA_Vref_Margin_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_ORG_B1_next     ", i_msg_block.MR33_ORG_B1_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_B1_next         ", i_msg_block.MR33_B1_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR50_B1              ", i_msg_block.MR50_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR51_B1              ", i_msg_block.MR51_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR52_B1              ", i_msg_block.MR52_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DFE_GainBias_B1      ", i_msg_block.DFE_GainBias_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR0_B2               ", i_msg_block.MR0_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR2_B2               ", i_msg_block.MR2_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3_B2               ", i_msg_block.MR3_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR4_B2               ", i_msg_block.MR4_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR5_B2               ", i_msg_block.MR5_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR6_B2               ", i_msg_block.MR6_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_B2_next         ", i_msg_block.MR32_B2_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR8_B2               ", i_msg_block.MR8_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_ORG_B2_next     ", i_msg_block.MR32_ORG_B2_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR10_B2              ", i_msg_block.MR10_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR11_B2              ", i_msg_block.MR11_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR12_B2              ", i_msg_block.MR12_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR13_B2              ", i_msg_block.MR13_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR14_B2              ", i_msg_block.MR14_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR15_B2              ", i_msg_block.MR15_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR111_B2             ", i_msg_block.MR111_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_B2              ", i_msg_block.MR32_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_B2              ", i_msg_block.MR33_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR34_B2              ", i_msg_block.MR34_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR35_B2              ", i_msg_block.MR35_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_ORG_B2          ", i_msg_block.MR32_ORG_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR37_B2              ", i_msg_block.MR37_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR38_B2              ", i_msg_block.MR38_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR39_B2              ", i_msg_block.MR39_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_ORG_B2          ", i_msg_block.MR33_ORG_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR11_B2_next         ", i_msg_block.MR11_B2_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR12_B2_next         ", i_msg_block.MR12_B2_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR13_B2_next         ", i_msg_block.MR13_B2_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CS_Dly_Margin_B2     ", i_msg_block.CS_Dly_Margin_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CS_Vref_Margin_B2    ", i_msg_block.CS_Vref_Margin_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CA_Dly_Margin_B2     ", i_msg_block.CA_Dly_Margin_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CA_Vref_Margin_B2    ", i_msg_block.CA_Vref_Margin_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_ORG_B2_next     ", i_msg_block.MR33_ORG_B2_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_B2_next         ", i_msg_block.MR33_B2_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR50_B2              ", i_msg_block.MR50_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR51_B2              ", i_msg_block.MR51_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR52_B2              ", i_msg_block.MR52_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DFE_GainBias_B2      ", i_msg_block.DFE_GainBias_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR0_B3               ", i_msg_block.MR0_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR2_B3               ", i_msg_block.MR2_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3_B3               ", i_msg_block.MR3_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR4_B3               ", i_msg_block.MR4_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR5_B3               ", i_msg_block.MR5_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR6_B3               ", i_msg_block.MR6_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_B3_next         ", i_msg_block.MR32_B3_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR8_B3               ", i_msg_block.MR8_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_ORG_B3_next     ", i_msg_block.MR32_ORG_B3_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR10_B3              ", i_msg_block.MR10_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR11_B3              ", i_msg_block.MR11_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR12_B3              ", i_msg_block.MR12_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR13_B3              ", i_msg_block.MR13_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR14_B3              ", i_msg_block.MR14_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR15_B3              ", i_msg_block.MR15_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR111_B3             ", i_msg_block.MR111_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_B3              ", i_msg_block.MR32_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_B3              ", i_msg_block.MR33_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR34_B3              ", i_msg_block.MR34_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR35_B3              ", i_msg_block.MR35_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32_ORG_B3          ", i_msg_block.MR32_ORG_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR37_B3              ", i_msg_block.MR37_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR38_B3              ", i_msg_block.MR38_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR39_B3              ", i_msg_block.MR39_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_ORG_B3          ", i_msg_block.MR33_ORG_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR11_B3_next         ", i_msg_block.MR11_B3_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR12_B3_next         ", i_msg_block.MR12_B3_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR13_B3_next         ", i_msg_block.MR13_B3_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CS_Dly_Margin_B3     ", i_msg_block.CS_Dly_Margin_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CS_Vref_Margin_B3    ", i_msg_block.CS_Vref_Margin_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CA_Dly_Margin_B3     ", i_msg_block.CA_Dly_Margin_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "CA_Vref_Margin_B3    ", i_msg_block.CA_Vref_Margin_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_ORG_B3_next     ", i_msg_block.MR33_ORG_B3_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR33_B3_next         ", i_msg_block.MR33_B3_next, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR50_B3              ", i_msg_block.MR50_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR51_B3              ", i_msg_block.MR51_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR52_B3              ", i_msg_block.MR52_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DFE_GainBias_B3      ", i_msg_block.DFE_GainBias_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved1E2          ", i_msg_block.Reserved1E2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved1E3          ", i_msg_block.Reserved1E3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved1E4          ", i_msg_block.Reserved1E4, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved1E5          ", i_msg_block.Reserved1E5, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved1E6          ", i_msg_block.Reserved1E6, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved1E7          ", i_msg_block.Reserved1E7, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "WR_RD_RTT_PARK_B0    ", i_msg_block.WR_RD_RTT_PARK_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "WR_RD_RTT_PARK_B1    ", i_msg_block.WR_RD_RTT_PARK_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "WR_RD_RTT_PARK_B2    ", i_msg_block.WR_RD_RTT_PARK_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "WR_RD_RTT_PARK_B3    ", i_msg_block.WR_RD_RTT_PARK_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RxClkDly_Margin_B0   ", i_msg_block.RxClkDly_Margin_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDac_Margin_B0    ", i_msg_block.VrefDac_Margin_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "TxDqDly_Margin_B0    ", i_msg_block.TxDqDly_Margin_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DeviceVref_Margin_B0 ", i_msg_block.DeviceVref_Margin_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RxClkDly_Margin_B1   ", i_msg_block.RxClkDly_Margin_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDac_Margin_B1    ", i_msg_block.VrefDac_Margin_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "TxDqDly_Margin_B1    ", i_msg_block.TxDqDly_Margin_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DeviceVref_Margin_B1 ", i_msg_block.DeviceVref_Margin_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RxClkDly_Margin_B2   ", i_msg_block.RxClkDly_Margin_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDac_Margin_B2    ", i_msg_block.VrefDac_Margin_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "TxDqDly_Margin_B2    ", i_msg_block.TxDqDly_Margin_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DeviceVref_Margin_B2 ", i_msg_block.DeviceVref_Margin_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RxClkDly_Margin_B3   ", i_msg_block.RxClkDly_Margin_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDac_Margin_B3    ", i_msg_block.VrefDac_Margin_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "TxDqDly_Margin_B3    ", i_msg_block.TxDqDly_Margin_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DeviceVref_Margin_B3 ", i_msg_block.DeviceVref_Margin_B3, TARGTID);
    FAPI_INF("  .%s= 0x%04x; // " TARGTIDFORMAT, "WL_ADJ_START         ", i_msg_block.WL_ADJ_START, TARGTID);
    FAPI_INF("  .%s= 0x%04x; // " TARGTIDFORMAT, "WL_ADJ_END           ", i_msg_block.WL_ADJ_END, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW00_ChA_D0         ", i_msg_block.RCW00_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW01_ChA_D0         ", i_msg_block.RCW01_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW02_ChA_D0         ", i_msg_block.RCW02_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW03_ChA_D0         ", i_msg_block.RCW03_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW04_ChA_D0         ", i_msg_block.RCW04_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW05_ChA_D0         ", i_msg_block.RCW05_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW06_ChA_D0         ", i_msg_block.RCW06_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW07_ChA_D0         ", i_msg_block.RCW07_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW08_ChA_D0         ", i_msg_block.RCW08_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW09_ChA_D0         ", i_msg_block.RCW09_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW0A_ChA_D0         ", i_msg_block.RCW0A_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW0B_ChA_D0         ", i_msg_block.RCW0B_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW0C_ChA_D0         ", i_msg_block.RCW0C_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW0D_ChA_D0         ", i_msg_block.RCW0D_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW0E_ChA_D0         ", i_msg_block.RCW0E_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW0F_ChA_D0         ", i_msg_block.RCW0F_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW10_ChA_D0         ", i_msg_block.RCW10_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW11_ChA_D0         ", i_msg_block.RCW11_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW12_ChA_D0         ", i_msg_block.RCW12_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW13_ChA_D0         ", i_msg_block.RCW13_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW14_ChA_D0         ", i_msg_block.RCW14_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW15_ChA_D0         ", i_msg_block.RCW15_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW16_ChA_D0         ", i_msg_block.RCW16_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW17_ChA_D0         ", i_msg_block.RCW17_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW18_ChA_D0         ", i_msg_block.RCW18_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW19_ChA_D0         ", i_msg_block.RCW19_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW1A_ChA_D0         ", i_msg_block.RCW1A_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW1B_ChA_D0         ", i_msg_block.RCW1B_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW1C_ChA_D0         ", i_msg_block.RCW1C_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW1D_ChA_D0         ", i_msg_block.RCW1D_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW1E_ChA_D0         ", i_msg_block.RCW1E_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW1F_ChA_D0         ", i_msg_block.RCW1F_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW20_ChA_D0         ", i_msg_block.RCW20_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW21_ChA_D0         ", i_msg_block.RCW21_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW22_ChA_D0         ", i_msg_block.RCW22_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW23_ChA_D0         ", i_msg_block.RCW23_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW24_ChA_D0         ", i_msg_block.RCW24_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW25_ChA_D0         ", i_msg_block.RCW25_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW26_ChA_D0         ", i_msg_block.RCW26_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW27_ChA_D0         ", i_msg_block.RCW27_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW28_ChA_D0         ", i_msg_block.RCW28_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW29_ChA_D0         ", i_msg_block.RCW29_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW2A_ChA_D0         ", i_msg_block.RCW2A_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW2B_ChA_D0         ", i_msg_block.RCW2B_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW2C_ChA_D0         ", i_msg_block.RCW2C_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW2D_ChA_D0         ", i_msg_block.RCW2D_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW2E_ChA_D0         ", i_msg_block.RCW2E_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW2F_ChA_D0         ", i_msg_block.RCW2F_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW30_ChA_D0         ", i_msg_block.RCW30_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW31_ChA_D0         ", i_msg_block.RCW31_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW32_ChA_D0         ", i_msg_block.RCW32_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW33_ChA_D0         ", i_msg_block.RCW33_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW34_ChA_D0         ", i_msg_block.RCW34_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW35_ChA_D0         ", i_msg_block.RCW35_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW36_ChA_D0         ", i_msg_block.RCW36_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW37_ChA_D0         ", i_msg_block.RCW37_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW38_ChA_D0         ", i_msg_block.RCW38_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW39_ChA_D0         ", i_msg_block.RCW39_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW3A_ChA_D0         ", i_msg_block.RCW3A_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW3B_ChA_D0         ", i_msg_block.RCW3B_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW3C_ChA_D0         ", i_msg_block.RCW3C_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW3D_ChA_D0         ", i_msg_block.RCW3D_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW3E_ChA_D0         ", i_msg_block.RCW3E_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW3F_ChA_D0         ", i_msg_block.RCW3F_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW40_ChA_D0         ", i_msg_block.RCW40_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW41_ChA_D0         ", i_msg_block.RCW41_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW42_ChA_D0         ", i_msg_block.RCW42_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW43_ChA_D0         ", i_msg_block.RCW43_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW44_ChA_D0         ", i_msg_block.RCW44_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW45_ChA_D0         ", i_msg_block.RCW45_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW46_ChA_D0         ", i_msg_block.RCW46_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW47_ChA_D0         ", i_msg_block.RCW47_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW48_ChA_D0         ", i_msg_block.RCW48_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW49_ChA_D0         ", i_msg_block.RCW49_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW4A_ChA_D0         ", i_msg_block.RCW4A_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW4B_ChA_D0         ", i_msg_block.RCW4B_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW4C_ChA_D0         ", i_msg_block.RCW4C_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW4D_ChA_D0         ", i_msg_block.RCW4D_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW4E_ChA_D0         ", i_msg_block.RCW4E_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW4F_ChA_D0         ", i_msg_block.RCW4F_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW50_ChA_D0         ", i_msg_block.RCW50_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW51_ChA_D0         ", i_msg_block.RCW51_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW52_ChA_D0         ", i_msg_block.RCW52_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW53_ChA_D0         ", i_msg_block.RCW53_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW54_ChA_D0         ", i_msg_block.RCW54_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW55_ChA_D0         ", i_msg_block.RCW55_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW56_ChA_D0         ", i_msg_block.RCW56_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW57_ChA_D0         ", i_msg_block.RCW57_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW58_ChA_D0         ", i_msg_block.RCW58_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW59_ChA_D0         ", i_msg_block.RCW59_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW5A_ChA_D0         ", i_msg_block.RCW5A_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW5B_ChA_D0         ", i_msg_block.RCW5B_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW5C_ChA_D0         ", i_msg_block.RCW5C_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW5D_ChA_D0         ", i_msg_block.RCW5D_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW5E_ChA_D0         ", i_msg_block.RCW5E_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW5F_ChA_D0         ", i_msg_block.RCW5F_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW60_ChA_D0         ", i_msg_block.RCW60_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW61_ChA_D0         ", i_msg_block.RCW61_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW62_ChA_D0         ", i_msg_block.RCW62_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW63_ChA_D0         ", i_msg_block.RCW63_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW64_ChA_D0         ", i_msg_block.RCW64_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW65_ChA_D0         ", i_msg_block.RCW65_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW66_ChA_D0         ", i_msg_block.RCW66_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW67_ChA_D0         ", i_msg_block.RCW67_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW68_ChA_D0         ", i_msg_block.RCW68_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW69_ChA_D0         ", i_msg_block.RCW69_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW6A_ChA_D0         ", i_msg_block.RCW6A_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW6B_ChA_D0         ", i_msg_block.RCW6B_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW6C_ChA_D0         ", i_msg_block.RCW6C_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW6D_ChA_D0         ", i_msg_block.RCW6D_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW6E_ChA_D0         ", i_msg_block.RCW6E_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW6F_ChA_D0         ", i_msg_block.RCW6F_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW70_ChA_D0         ", i_msg_block.RCW70_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW71_ChA_D0         ", i_msg_block.RCW71_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW72_ChA_D0         ", i_msg_block.RCW72_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW73_ChA_D0         ", i_msg_block.RCW73_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW74_ChA_D0         ", i_msg_block.RCW74_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW75_ChA_D0         ", i_msg_block.RCW75_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW76_ChA_D0         ", i_msg_block.RCW76_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW77_ChA_D0         ", i_msg_block.RCW77_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW78_ChA_D0         ", i_msg_block.RCW78_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW79_ChA_D0         ", i_msg_block.RCW79_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW7A_ChA_D0         ", i_msg_block.RCW7A_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW7B_ChA_D0         ", i_msg_block.RCW7B_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW7C_ChA_D0         ", i_msg_block.RCW7C_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW7D_ChA_D0         ", i_msg_block.RCW7D_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW7E_ChA_D0         ", i_msg_block.RCW7E_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW7F_ChA_D0         ", i_msg_block.RCW7F_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW00_ChA_D0         ", i_msg_block.BCW00_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW01_ChA_D0         ", i_msg_block.BCW01_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW02_ChA_D0         ", i_msg_block.BCW02_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW03_ChA_D0         ", i_msg_block.BCW03_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW04_ChA_D0         ", i_msg_block.BCW04_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW05_ChA_D0         ", i_msg_block.BCW05_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW06_ChA_D0         ", i_msg_block.BCW06_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW07_ChA_D0         ", i_msg_block.BCW07_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW08_ChA_D0         ", i_msg_block.BCW08_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW09_ChA_D0         ", i_msg_block.BCW09_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW0A_ChA_D0         ", i_msg_block.BCW0A_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW0B_ChA_D0         ", i_msg_block.BCW0B_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW0C_ChA_D0         ", i_msg_block.BCW0C_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW0D_ChA_D0         ", i_msg_block.BCW0D_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW0E_ChA_D0         ", i_msg_block.BCW0E_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW0F_ChA_D0         ", i_msg_block.BCW0F_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW10_ChA_D0         ", i_msg_block.BCW10_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW11_ChA_D0         ", i_msg_block.BCW11_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW12_ChA_D0         ", i_msg_block.BCW12_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW13_ChA_D0         ", i_msg_block.BCW13_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW14_ChA_D0         ", i_msg_block.BCW14_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW15_ChA_D0         ", i_msg_block.BCW15_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW16_ChA_D0         ", i_msg_block.BCW16_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW17_ChA_D0         ", i_msg_block.BCW17_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW18_ChA_D0         ", i_msg_block.BCW18_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW19_ChA_D0         ", i_msg_block.BCW19_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW1A_ChA_D0         ", i_msg_block.BCW1A_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW1B_ChA_D0         ", i_msg_block.BCW1B_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW1C_ChA_D0         ", i_msg_block.BCW1C_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW1D_ChA_D0         ", i_msg_block.BCW1D_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW1E_ChA_D0         ", i_msg_block.BCW1E_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW1F_ChA_D0         ", i_msg_block.BCW1F_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW20_ChA_D0         ", i_msg_block.BCW20_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW21_ChA_D0         ", i_msg_block.BCW21_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW22_ChA_D0         ", i_msg_block.BCW22_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW23_ChA_D0         ", i_msg_block.BCW23_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW24_ChA_D0         ", i_msg_block.BCW24_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW25_ChA_D0         ", i_msg_block.BCW25_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW26_ChA_D0         ", i_msg_block.BCW26_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW27_ChA_D0         ", i_msg_block.BCW27_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW28_ChA_D0         ", i_msg_block.BCW28_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW29_ChA_D0         ", i_msg_block.BCW29_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW2A_ChA_D0         ", i_msg_block.BCW2A_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW2B_ChA_D0         ", i_msg_block.BCW2B_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW2C_ChA_D0         ", i_msg_block.BCW2C_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW2D_ChA_D0         ", i_msg_block.BCW2D_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW2E_ChA_D0         ", i_msg_block.BCW2E_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW2F_ChA_D0         ", i_msg_block.BCW2F_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW30_ChA_D0         ", i_msg_block.BCW30_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW31_ChA_D0         ", i_msg_block.BCW31_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW32_ChA_D0         ", i_msg_block.BCW32_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW33_ChA_D0         ", i_msg_block.BCW33_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW34_ChA_D0         ", i_msg_block.BCW34_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW35_ChA_D0         ", i_msg_block.BCW35_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW36_ChA_D0         ", i_msg_block.BCW36_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW37_ChA_D0         ", i_msg_block.BCW37_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW38_ChA_D0         ", i_msg_block.BCW38_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW39_ChA_D0         ", i_msg_block.BCW39_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW3A_ChA_D0         ", i_msg_block.BCW3A_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW3B_ChA_D0         ", i_msg_block.BCW3B_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW3C_ChA_D0         ", i_msg_block.BCW3C_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW3D_ChA_D0         ", i_msg_block.BCW3D_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW3E_ChA_D0         ", i_msg_block.BCW3E_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW3F_ChA_D0         ", i_msg_block.BCW3F_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW40_ChA_D0         ", i_msg_block.BCW40_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW41_ChA_D0         ", i_msg_block.BCW41_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW42_ChA_D0         ", i_msg_block.BCW42_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW43_ChA_D0         ", i_msg_block.BCW43_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW44_ChA_D0         ", i_msg_block.BCW44_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW45_ChA_D0         ", i_msg_block.BCW45_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW46_ChA_D0         ", i_msg_block.BCW46_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW47_ChA_D0         ", i_msg_block.BCW47_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW48_ChA_D0         ", i_msg_block.BCW48_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW49_ChA_D0         ", i_msg_block.BCW49_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW4A_ChA_D0         ", i_msg_block.BCW4A_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW4B_ChA_D0         ", i_msg_block.BCW4B_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW4C_ChA_D0         ", i_msg_block.BCW4C_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW4D_ChA_D0         ", i_msg_block.BCW4D_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW4E_ChA_D0         ", i_msg_block.BCW4E_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW4F_ChA_D0         ", i_msg_block.BCW4F_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW50_ChA_D0         ", i_msg_block.BCW50_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW51_ChA_D0         ", i_msg_block.BCW51_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW52_ChA_D0         ", i_msg_block.BCW52_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW53_ChA_D0         ", i_msg_block.BCW53_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW54_ChA_D0         ", i_msg_block.BCW54_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW55_ChA_D0         ", i_msg_block.BCW55_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW56_ChA_D0         ", i_msg_block.BCW56_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW57_ChA_D0         ", i_msg_block.BCW57_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW58_ChA_D0         ", i_msg_block.BCW58_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW59_ChA_D0         ", i_msg_block.BCW59_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW5A_ChA_D0         ", i_msg_block.BCW5A_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW5B_ChA_D0         ", i_msg_block.BCW5B_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW5C_ChA_D0         ", i_msg_block.BCW5C_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW5D_ChA_D0         ", i_msg_block.BCW5D_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW5E_ChA_D0         ", i_msg_block.BCW5E_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW5F_ChA_D0         ", i_msg_block.BCW5F_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW60_ChA_D0         ", i_msg_block.BCW60_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW61_ChA_D0         ", i_msg_block.BCW61_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW62_ChA_D0         ", i_msg_block.BCW62_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW63_ChA_D0         ", i_msg_block.BCW63_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW64_ChA_D0         ", i_msg_block.BCW64_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW65_ChA_D0         ", i_msg_block.BCW65_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW66_ChA_D0         ", i_msg_block.BCW66_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW67_ChA_D0         ", i_msg_block.BCW67_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW68_ChA_D0         ", i_msg_block.BCW68_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW69_ChA_D0         ", i_msg_block.BCW69_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW6A_ChA_D0         ", i_msg_block.BCW6A_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW6B_ChA_D0         ", i_msg_block.BCW6B_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW6C_ChA_D0         ", i_msg_block.BCW6C_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW6D_ChA_D0         ", i_msg_block.BCW6D_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW6E_ChA_D0         ", i_msg_block.BCW6E_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW6F_ChA_D0         ", i_msg_block.BCW6F_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW70_ChA_D0         ", i_msg_block.BCW70_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW71_ChA_D0         ", i_msg_block.BCW71_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW72_ChA_D0         ", i_msg_block.BCW72_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW73_ChA_D0         ", i_msg_block.BCW73_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW74_ChA_D0         ", i_msg_block.BCW74_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW75_ChA_D0         ", i_msg_block.BCW75_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW76_ChA_D0         ", i_msg_block.BCW76_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW77_ChA_D0         ", i_msg_block.BCW77_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW78_ChA_D0         ", i_msg_block.BCW78_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW79_ChA_D0         ", i_msg_block.BCW79_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW7A_ChA_D0         ", i_msg_block.BCW7A_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW7B_ChA_D0         ", i_msg_block.BCW7B_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW7C_ChA_D0         ", i_msg_block.BCW7C_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW7D_ChA_D0         ", i_msg_block.BCW7D_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW7E_ChA_D0         ", i_msg_block.BCW7E_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW7F_ChA_D0         ", i_msg_block.BCW7F_ChA_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW00_ChA_D1         ", i_msg_block.RCW00_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW01_ChA_D1         ", i_msg_block.RCW01_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW02_ChA_D1         ", i_msg_block.RCW02_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW03_ChA_D1         ", i_msg_block.RCW03_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW04_ChA_D1         ", i_msg_block.RCW04_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW05_ChA_D1         ", i_msg_block.RCW05_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW06_ChA_D1         ", i_msg_block.RCW06_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW07_ChA_D1         ", i_msg_block.RCW07_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW08_ChA_D1         ", i_msg_block.RCW08_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW09_ChA_D1         ", i_msg_block.RCW09_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW0A_ChA_D1         ", i_msg_block.RCW0A_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW0B_ChA_D1         ", i_msg_block.RCW0B_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW0C_ChA_D1         ", i_msg_block.RCW0C_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW0D_ChA_D1         ", i_msg_block.RCW0D_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW0E_ChA_D1         ", i_msg_block.RCW0E_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW0F_ChA_D1         ", i_msg_block.RCW0F_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW10_ChA_D1         ", i_msg_block.RCW10_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW11_ChA_D1         ", i_msg_block.RCW11_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW12_ChA_D1         ", i_msg_block.RCW12_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW13_ChA_D1         ", i_msg_block.RCW13_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW14_ChA_D1         ", i_msg_block.RCW14_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW15_ChA_D1         ", i_msg_block.RCW15_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW16_ChA_D1         ", i_msg_block.RCW16_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW17_ChA_D1         ", i_msg_block.RCW17_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW18_ChA_D1         ", i_msg_block.RCW18_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW19_ChA_D1         ", i_msg_block.RCW19_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW1A_ChA_D1         ", i_msg_block.RCW1A_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW1B_ChA_D1         ", i_msg_block.RCW1B_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW1C_ChA_D1         ", i_msg_block.RCW1C_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW1D_ChA_D1         ", i_msg_block.RCW1D_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW1E_ChA_D1         ", i_msg_block.RCW1E_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW1F_ChA_D1         ", i_msg_block.RCW1F_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW20_ChA_D1         ", i_msg_block.RCW20_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW21_ChA_D1         ", i_msg_block.RCW21_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW22_ChA_D1         ", i_msg_block.RCW22_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW23_ChA_D1         ", i_msg_block.RCW23_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW24_ChA_D1         ", i_msg_block.RCW24_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW25_ChA_D1         ", i_msg_block.RCW25_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW26_ChA_D1         ", i_msg_block.RCW26_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW27_ChA_D1         ", i_msg_block.RCW27_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW28_ChA_D1         ", i_msg_block.RCW28_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW29_ChA_D1         ", i_msg_block.RCW29_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW2A_ChA_D1         ", i_msg_block.RCW2A_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW2B_ChA_D1         ", i_msg_block.RCW2B_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW2C_ChA_D1         ", i_msg_block.RCW2C_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW2D_ChA_D1         ", i_msg_block.RCW2D_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW2E_ChA_D1         ", i_msg_block.RCW2E_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW2F_ChA_D1         ", i_msg_block.RCW2F_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW30_ChA_D1         ", i_msg_block.RCW30_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW31_ChA_D1         ", i_msg_block.RCW31_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW32_ChA_D1         ", i_msg_block.RCW32_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW33_ChA_D1         ", i_msg_block.RCW33_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW34_ChA_D1         ", i_msg_block.RCW34_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW35_ChA_D1         ", i_msg_block.RCW35_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW36_ChA_D1         ", i_msg_block.RCW36_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW37_ChA_D1         ", i_msg_block.RCW37_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW38_ChA_D1         ", i_msg_block.RCW38_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW39_ChA_D1         ", i_msg_block.RCW39_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW3A_ChA_D1         ", i_msg_block.RCW3A_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW3B_ChA_D1         ", i_msg_block.RCW3B_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW3C_ChA_D1         ", i_msg_block.RCW3C_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW3D_ChA_D1         ", i_msg_block.RCW3D_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW3E_ChA_D1         ", i_msg_block.RCW3E_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW3F_ChA_D1         ", i_msg_block.RCW3F_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW40_ChA_D1         ", i_msg_block.RCW40_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW41_ChA_D1         ", i_msg_block.RCW41_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW42_ChA_D1         ", i_msg_block.RCW42_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW43_ChA_D1         ", i_msg_block.RCW43_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW44_ChA_D1         ", i_msg_block.RCW44_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW45_ChA_D1         ", i_msg_block.RCW45_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW46_ChA_D1         ", i_msg_block.RCW46_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW47_ChA_D1         ", i_msg_block.RCW47_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW48_ChA_D1         ", i_msg_block.RCW48_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW49_ChA_D1         ", i_msg_block.RCW49_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW4A_ChA_D1         ", i_msg_block.RCW4A_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW4B_ChA_D1         ", i_msg_block.RCW4B_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW4C_ChA_D1         ", i_msg_block.RCW4C_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW4D_ChA_D1         ", i_msg_block.RCW4D_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW4E_ChA_D1         ", i_msg_block.RCW4E_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW4F_ChA_D1         ", i_msg_block.RCW4F_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW50_ChA_D1         ", i_msg_block.RCW50_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW51_ChA_D1         ", i_msg_block.RCW51_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW52_ChA_D1         ", i_msg_block.RCW52_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW53_ChA_D1         ", i_msg_block.RCW53_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW54_ChA_D1         ", i_msg_block.RCW54_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW55_ChA_D1         ", i_msg_block.RCW55_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW56_ChA_D1         ", i_msg_block.RCW56_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW57_ChA_D1         ", i_msg_block.RCW57_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW58_ChA_D1         ", i_msg_block.RCW58_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW59_ChA_D1         ", i_msg_block.RCW59_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW5A_ChA_D1         ", i_msg_block.RCW5A_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW5B_ChA_D1         ", i_msg_block.RCW5B_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW5C_ChA_D1         ", i_msg_block.RCW5C_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW5D_ChA_D1         ", i_msg_block.RCW5D_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW5E_ChA_D1         ", i_msg_block.RCW5E_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW5F_ChA_D1         ", i_msg_block.RCW5F_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW60_ChA_D1         ", i_msg_block.RCW60_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW61_ChA_D1         ", i_msg_block.RCW61_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW62_ChA_D1         ", i_msg_block.RCW62_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW63_ChA_D1         ", i_msg_block.RCW63_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW64_ChA_D1         ", i_msg_block.RCW64_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW65_ChA_D1         ", i_msg_block.RCW65_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW66_ChA_D1         ", i_msg_block.RCW66_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW67_ChA_D1         ", i_msg_block.RCW67_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW68_ChA_D1         ", i_msg_block.RCW68_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW69_ChA_D1         ", i_msg_block.RCW69_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW6A_ChA_D1         ", i_msg_block.RCW6A_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW6B_ChA_D1         ", i_msg_block.RCW6B_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW6C_ChA_D1         ", i_msg_block.RCW6C_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW6D_ChA_D1         ", i_msg_block.RCW6D_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW6E_ChA_D1         ", i_msg_block.RCW6E_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW6F_ChA_D1         ", i_msg_block.RCW6F_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW70_ChA_D1         ", i_msg_block.RCW70_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW71_ChA_D1         ", i_msg_block.RCW71_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW72_ChA_D1         ", i_msg_block.RCW72_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW73_ChA_D1         ", i_msg_block.RCW73_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW74_ChA_D1         ", i_msg_block.RCW74_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW75_ChA_D1         ", i_msg_block.RCW75_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW76_ChA_D1         ", i_msg_block.RCW76_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW77_ChA_D1         ", i_msg_block.RCW77_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW78_ChA_D1         ", i_msg_block.RCW78_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW79_ChA_D1         ", i_msg_block.RCW79_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW7A_ChA_D1         ", i_msg_block.RCW7A_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW7B_ChA_D1         ", i_msg_block.RCW7B_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW7C_ChA_D1         ", i_msg_block.RCW7C_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW7D_ChA_D1         ", i_msg_block.RCW7D_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW7E_ChA_D1         ", i_msg_block.RCW7E_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW7F_ChA_D1         ", i_msg_block.RCW7F_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW00_ChA_D1         ", i_msg_block.BCW00_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW01_ChA_D1         ", i_msg_block.BCW01_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW02_ChA_D1         ", i_msg_block.BCW02_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW03_ChA_D1         ", i_msg_block.BCW03_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW04_ChA_D1         ", i_msg_block.BCW04_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW05_ChA_D1         ", i_msg_block.BCW05_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW06_ChA_D1         ", i_msg_block.BCW06_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW07_ChA_D1         ", i_msg_block.BCW07_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW08_ChA_D1         ", i_msg_block.BCW08_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW09_ChA_D1         ", i_msg_block.BCW09_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW0A_ChA_D1         ", i_msg_block.BCW0A_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW0B_ChA_D1         ", i_msg_block.BCW0B_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW0C_ChA_D1         ", i_msg_block.BCW0C_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW0D_ChA_D1         ", i_msg_block.BCW0D_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW0E_ChA_D1         ", i_msg_block.BCW0E_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW0F_ChA_D1         ", i_msg_block.BCW0F_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW10_ChA_D1         ", i_msg_block.BCW10_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW11_ChA_D1         ", i_msg_block.BCW11_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW12_ChA_D1         ", i_msg_block.BCW12_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW13_ChA_D1         ", i_msg_block.BCW13_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW14_ChA_D1         ", i_msg_block.BCW14_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW15_ChA_D1         ", i_msg_block.BCW15_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW16_ChA_D1         ", i_msg_block.BCW16_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW17_ChA_D1         ", i_msg_block.BCW17_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW18_ChA_D1         ", i_msg_block.BCW18_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW19_ChA_D1         ", i_msg_block.BCW19_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW1A_ChA_D1         ", i_msg_block.BCW1A_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW1B_ChA_D1         ", i_msg_block.BCW1B_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW1C_ChA_D1         ", i_msg_block.BCW1C_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW1D_ChA_D1         ", i_msg_block.BCW1D_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW1E_ChA_D1         ", i_msg_block.BCW1E_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW1F_ChA_D1         ", i_msg_block.BCW1F_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW20_ChA_D1         ", i_msg_block.BCW20_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW21_ChA_D1         ", i_msg_block.BCW21_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW22_ChA_D1         ", i_msg_block.BCW22_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW23_ChA_D1         ", i_msg_block.BCW23_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW24_ChA_D1         ", i_msg_block.BCW24_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW25_ChA_D1         ", i_msg_block.BCW25_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW26_ChA_D1         ", i_msg_block.BCW26_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW27_ChA_D1         ", i_msg_block.BCW27_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW28_ChA_D1         ", i_msg_block.BCW28_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW29_ChA_D1         ", i_msg_block.BCW29_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW2A_ChA_D1         ", i_msg_block.BCW2A_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW2B_ChA_D1         ", i_msg_block.BCW2B_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW2C_ChA_D1         ", i_msg_block.BCW2C_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW2D_ChA_D1         ", i_msg_block.BCW2D_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW2E_ChA_D1         ", i_msg_block.BCW2E_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW2F_ChA_D1         ", i_msg_block.BCW2F_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW30_ChA_D1         ", i_msg_block.BCW30_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW31_ChA_D1         ", i_msg_block.BCW31_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW32_ChA_D1         ", i_msg_block.BCW32_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW33_ChA_D1         ", i_msg_block.BCW33_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW34_ChA_D1         ", i_msg_block.BCW34_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW35_ChA_D1         ", i_msg_block.BCW35_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW36_ChA_D1         ", i_msg_block.BCW36_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW37_ChA_D1         ", i_msg_block.BCW37_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW38_ChA_D1         ", i_msg_block.BCW38_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW39_ChA_D1         ", i_msg_block.BCW39_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW3A_ChA_D1         ", i_msg_block.BCW3A_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW3B_ChA_D1         ", i_msg_block.BCW3B_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW3C_ChA_D1         ", i_msg_block.BCW3C_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW3D_ChA_D1         ", i_msg_block.BCW3D_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW3E_ChA_D1         ", i_msg_block.BCW3E_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW3F_ChA_D1         ", i_msg_block.BCW3F_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW40_ChA_D1         ", i_msg_block.BCW40_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW41_ChA_D1         ", i_msg_block.BCW41_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW42_ChA_D1         ", i_msg_block.BCW42_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW43_ChA_D1         ", i_msg_block.BCW43_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW44_ChA_D1         ", i_msg_block.BCW44_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW45_ChA_D1         ", i_msg_block.BCW45_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW46_ChA_D1         ", i_msg_block.BCW46_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW47_ChA_D1         ", i_msg_block.BCW47_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW48_ChA_D1         ", i_msg_block.BCW48_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW49_ChA_D1         ", i_msg_block.BCW49_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW4A_ChA_D1         ", i_msg_block.BCW4A_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW4B_ChA_D1         ", i_msg_block.BCW4B_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW4C_ChA_D1         ", i_msg_block.BCW4C_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW4D_ChA_D1         ", i_msg_block.BCW4D_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW4E_ChA_D1         ", i_msg_block.BCW4E_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW4F_ChA_D1         ", i_msg_block.BCW4F_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW50_ChA_D1         ", i_msg_block.BCW50_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW51_ChA_D1         ", i_msg_block.BCW51_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW52_ChA_D1         ", i_msg_block.BCW52_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW53_ChA_D1         ", i_msg_block.BCW53_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW54_ChA_D1         ", i_msg_block.BCW54_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW55_ChA_D1         ", i_msg_block.BCW55_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW56_ChA_D1         ", i_msg_block.BCW56_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW57_ChA_D1         ", i_msg_block.BCW57_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW58_ChA_D1         ", i_msg_block.BCW58_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW59_ChA_D1         ", i_msg_block.BCW59_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW5A_ChA_D1         ", i_msg_block.BCW5A_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW5B_ChA_D1         ", i_msg_block.BCW5B_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW5C_ChA_D1         ", i_msg_block.BCW5C_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW5D_ChA_D1         ", i_msg_block.BCW5D_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW5E_ChA_D1         ", i_msg_block.BCW5E_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW5F_ChA_D1         ", i_msg_block.BCW5F_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW60_ChA_D1         ", i_msg_block.BCW60_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW61_ChA_D1         ", i_msg_block.BCW61_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW62_ChA_D1         ", i_msg_block.BCW62_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW63_ChA_D1         ", i_msg_block.BCW63_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW64_ChA_D1         ", i_msg_block.BCW64_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW65_ChA_D1         ", i_msg_block.BCW65_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW66_ChA_D1         ", i_msg_block.BCW66_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW67_ChA_D1         ", i_msg_block.BCW67_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW68_ChA_D1         ", i_msg_block.BCW68_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW69_ChA_D1         ", i_msg_block.BCW69_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW6A_ChA_D1         ", i_msg_block.BCW6A_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW6B_ChA_D1         ", i_msg_block.BCW6B_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW6C_ChA_D1         ", i_msg_block.BCW6C_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW6D_ChA_D1         ", i_msg_block.BCW6D_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW6E_ChA_D1         ", i_msg_block.BCW6E_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW6F_ChA_D1         ", i_msg_block.BCW6F_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW70_ChA_D1         ", i_msg_block.BCW70_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW71_ChA_D1         ", i_msg_block.BCW71_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW72_ChA_D1         ", i_msg_block.BCW72_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW73_ChA_D1         ", i_msg_block.BCW73_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW74_ChA_D1         ", i_msg_block.BCW74_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW75_ChA_D1         ", i_msg_block.BCW75_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW76_ChA_D1         ", i_msg_block.BCW76_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW77_ChA_D1         ", i_msg_block.BCW77_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW78_ChA_D1         ", i_msg_block.BCW78_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW79_ChA_D1         ", i_msg_block.BCW79_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW7A_ChA_D1         ", i_msg_block.BCW7A_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW7B_ChA_D1         ", i_msg_block.BCW7B_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW7C_ChA_D1         ", i_msg_block.BCW7C_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW7D_ChA_D1         ", i_msg_block.BCW7D_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW7E_ChA_D1         ", i_msg_block.BCW7E_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW7F_ChA_D1         ", i_msg_block.BCW7F_ChA_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW00_ChB_D0         ", i_msg_block.RCW00_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW01_ChB_D0         ", i_msg_block.RCW01_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW02_ChB_D0         ", i_msg_block.RCW02_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW03_ChB_D0         ", i_msg_block.RCW03_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW04_ChB_D0         ", i_msg_block.RCW04_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW05_ChB_D0         ", i_msg_block.RCW05_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW06_ChB_D0         ", i_msg_block.RCW06_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW07_ChB_D0         ", i_msg_block.RCW07_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW08_ChB_D0         ", i_msg_block.RCW08_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW09_ChB_D0         ", i_msg_block.RCW09_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW0A_ChB_D0         ", i_msg_block.RCW0A_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW0B_ChB_D0         ", i_msg_block.RCW0B_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW0C_ChB_D0         ", i_msg_block.RCW0C_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW0D_ChB_D0         ", i_msg_block.RCW0D_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW0E_ChB_D0         ", i_msg_block.RCW0E_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW0F_ChB_D0         ", i_msg_block.RCW0F_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW10_ChB_D0         ", i_msg_block.RCW10_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW11_ChB_D0         ", i_msg_block.RCW11_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW12_ChB_D0         ", i_msg_block.RCW12_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW13_ChB_D0         ", i_msg_block.RCW13_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW14_ChB_D0         ", i_msg_block.RCW14_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW15_ChB_D0         ", i_msg_block.RCW15_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW16_ChB_D0         ", i_msg_block.RCW16_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW17_ChB_D0         ", i_msg_block.RCW17_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW18_ChB_D0         ", i_msg_block.RCW18_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW19_ChB_D0         ", i_msg_block.RCW19_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW1A_ChB_D0         ", i_msg_block.RCW1A_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW1B_ChB_D0         ", i_msg_block.RCW1B_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW1C_ChB_D0         ", i_msg_block.RCW1C_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW1D_ChB_D0         ", i_msg_block.RCW1D_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW1E_ChB_D0         ", i_msg_block.RCW1E_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW1F_ChB_D0         ", i_msg_block.RCW1F_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW20_ChB_D0         ", i_msg_block.RCW20_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW21_ChB_D0         ", i_msg_block.RCW21_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW22_ChB_D0         ", i_msg_block.RCW22_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW23_ChB_D0         ", i_msg_block.RCW23_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW24_ChB_D0         ", i_msg_block.RCW24_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW25_ChB_D0         ", i_msg_block.RCW25_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW26_ChB_D0         ", i_msg_block.RCW26_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW27_ChB_D0         ", i_msg_block.RCW27_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW28_ChB_D0         ", i_msg_block.RCW28_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW29_ChB_D0         ", i_msg_block.RCW29_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW2A_ChB_D0         ", i_msg_block.RCW2A_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW2B_ChB_D0         ", i_msg_block.RCW2B_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW2C_ChB_D0         ", i_msg_block.RCW2C_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW2D_ChB_D0         ", i_msg_block.RCW2D_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW2E_ChB_D0         ", i_msg_block.RCW2E_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW2F_ChB_D0         ", i_msg_block.RCW2F_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW30_ChB_D0         ", i_msg_block.RCW30_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW31_ChB_D0         ", i_msg_block.RCW31_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW32_ChB_D0         ", i_msg_block.RCW32_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW33_ChB_D0         ", i_msg_block.RCW33_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW34_ChB_D0         ", i_msg_block.RCW34_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW35_ChB_D0         ", i_msg_block.RCW35_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW36_ChB_D0         ", i_msg_block.RCW36_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW37_ChB_D0         ", i_msg_block.RCW37_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW38_ChB_D0         ", i_msg_block.RCW38_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW39_ChB_D0         ", i_msg_block.RCW39_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW3A_ChB_D0         ", i_msg_block.RCW3A_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW3B_ChB_D0         ", i_msg_block.RCW3B_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW3C_ChB_D0         ", i_msg_block.RCW3C_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW3D_ChB_D0         ", i_msg_block.RCW3D_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW3E_ChB_D0         ", i_msg_block.RCW3E_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW3F_ChB_D0         ", i_msg_block.RCW3F_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW40_ChB_D0         ", i_msg_block.RCW40_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW41_ChB_D0         ", i_msg_block.RCW41_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW42_ChB_D0         ", i_msg_block.RCW42_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW43_ChB_D0         ", i_msg_block.RCW43_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW44_ChB_D0         ", i_msg_block.RCW44_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW45_ChB_D0         ", i_msg_block.RCW45_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW46_ChB_D0         ", i_msg_block.RCW46_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW47_ChB_D0         ", i_msg_block.RCW47_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW48_ChB_D0         ", i_msg_block.RCW48_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW49_ChB_D0         ", i_msg_block.RCW49_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW4A_ChB_D0         ", i_msg_block.RCW4A_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW4B_ChB_D0         ", i_msg_block.RCW4B_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW4C_ChB_D0         ", i_msg_block.RCW4C_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW4D_ChB_D0         ", i_msg_block.RCW4D_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW4E_ChB_D0         ", i_msg_block.RCW4E_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW4F_ChB_D0         ", i_msg_block.RCW4F_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW50_ChB_D0         ", i_msg_block.RCW50_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW51_ChB_D0         ", i_msg_block.RCW51_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW52_ChB_D0         ", i_msg_block.RCW52_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW53_ChB_D0         ", i_msg_block.RCW53_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW54_ChB_D0         ", i_msg_block.RCW54_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW55_ChB_D0         ", i_msg_block.RCW55_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW56_ChB_D0         ", i_msg_block.RCW56_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW57_ChB_D0         ", i_msg_block.RCW57_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW58_ChB_D0         ", i_msg_block.RCW58_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW59_ChB_D0         ", i_msg_block.RCW59_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW5A_ChB_D0         ", i_msg_block.RCW5A_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW5B_ChB_D0         ", i_msg_block.RCW5B_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW5C_ChB_D0         ", i_msg_block.RCW5C_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW5D_ChB_D0         ", i_msg_block.RCW5D_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW5E_ChB_D0         ", i_msg_block.RCW5E_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW5F_ChB_D0         ", i_msg_block.RCW5F_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW60_ChB_D0         ", i_msg_block.RCW60_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW61_ChB_D0         ", i_msg_block.RCW61_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW62_ChB_D0         ", i_msg_block.RCW62_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW63_ChB_D0         ", i_msg_block.RCW63_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW64_ChB_D0         ", i_msg_block.RCW64_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW65_ChB_D0         ", i_msg_block.RCW65_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW66_ChB_D0         ", i_msg_block.RCW66_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW67_ChB_D0         ", i_msg_block.RCW67_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW68_ChB_D0         ", i_msg_block.RCW68_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW69_ChB_D0         ", i_msg_block.RCW69_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW6A_ChB_D0         ", i_msg_block.RCW6A_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW6B_ChB_D0         ", i_msg_block.RCW6B_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW6C_ChB_D0         ", i_msg_block.RCW6C_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW6D_ChB_D0         ", i_msg_block.RCW6D_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW6E_ChB_D0         ", i_msg_block.RCW6E_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW6F_ChB_D0         ", i_msg_block.RCW6F_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW70_ChB_D0         ", i_msg_block.RCW70_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW71_ChB_D0         ", i_msg_block.RCW71_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW72_ChB_D0         ", i_msg_block.RCW72_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW73_ChB_D0         ", i_msg_block.RCW73_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW74_ChB_D0         ", i_msg_block.RCW74_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW75_ChB_D0         ", i_msg_block.RCW75_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW76_ChB_D0         ", i_msg_block.RCW76_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW77_ChB_D0         ", i_msg_block.RCW77_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW78_ChB_D0         ", i_msg_block.RCW78_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW79_ChB_D0         ", i_msg_block.RCW79_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW7A_ChB_D0         ", i_msg_block.RCW7A_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW7B_ChB_D0         ", i_msg_block.RCW7B_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW7C_ChB_D0         ", i_msg_block.RCW7C_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW7D_ChB_D0         ", i_msg_block.RCW7D_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW7E_ChB_D0         ", i_msg_block.RCW7E_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW7F_ChB_D0         ", i_msg_block.RCW7F_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW00_ChB_D0         ", i_msg_block.BCW00_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW01_ChB_D0         ", i_msg_block.BCW01_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW02_ChB_D0         ", i_msg_block.BCW02_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW03_ChB_D0         ", i_msg_block.BCW03_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW04_ChB_D0         ", i_msg_block.BCW04_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW05_ChB_D0         ", i_msg_block.BCW05_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW06_ChB_D0         ", i_msg_block.BCW06_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW07_ChB_D0         ", i_msg_block.BCW07_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW08_ChB_D0         ", i_msg_block.BCW08_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW09_ChB_D0         ", i_msg_block.BCW09_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW0A_ChB_D0         ", i_msg_block.BCW0A_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW0B_ChB_D0         ", i_msg_block.BCW0B_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW0C_ChB_D0         ", i_msg_block.BCW0C_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW0D_ChB_D0         ", i_msg_block.BCW0D_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW0E_ChB_D0         ", i_msg_block.BCW0E_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW0F_ChB_D0         ", i_msg_block.BCW0F_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW10_ChB_D0         ", i_msg_block.BCW10_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW11_ChB_D0         ", i_msg_block.BCW11_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW12_ChB_D0         ", i_msg_block.BCW12_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW13_ChB_D0         ", i_msg_block.BCW13_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW14_ChB_D0         ", i_msg_block.BCW14_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW15_ChB_D0         ", i_msg_block.BCW15_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW16_ChB_D0         ", i_msg_block.BCW16_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW17_ChB_D0         ", i_msg_block.BCW17_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW18_ChB_D0         ", i_msg_block.BCW18_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW19_ChB_D0         ", i_msg_block.BCW19_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW1A_ChB_D0         ", i_msg_block.BCW1A_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW1B_ChB_D0         ", i_msg_block.BCW1B_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW1C_ChB_D0         ", i_msg_block.BCW1C_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW1D_ChB_D0         ", i_msg_block.BCW1D_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW1E_ChB_D0         ", i_msg_block.BCW1E_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW1F_ChB_D0         ", i_msg_block.BCW1F_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW20_ChB_D0         ", i_msg_block.BCW20_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW21_ChB_D0         ", i_msg_block.BCW21_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW22_ChB_D0         ", i_msg_block.BCW22_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW23_ChB_D0         ", i_msg_block.BCW23_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW24_ChB_D0         ", i_msg_block.BCW24_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW25_ChB_D0         ", i_msg_block.BCW25_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW26_ChB_D0         ", i_msg_block.BCW26_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW27_ChB_D0         ", i_msg_block.BCW27_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW28_ChB_D0         ", i_msg_block.BCW28_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW29_ChB_D0         ", i_msg_block.BCW29_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW2A_ChB_D0         ", i_msg_block.BCW2A_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW2B_ChB_D0         ", i_msg_block.BCW2B_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW2C_ChB_D0         ", i_msg_block.BCW2C_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW2D_ChB_D0         ", i_msg_block.BCW2D_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW2E_ChB_D0         ", i_msg_block.BCW2E_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW2F_ChB_D0         ", i_msg_block.BCW2F_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW30_ChB_D0         ", i_msg_block.BCW30_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW31_ChB_D0         ", i_msg_block.BCW31_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW32_ChB_D0         ", i_msg_block.BCW32_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW33_ChB_D0         ", i_msg_block.BCW33_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW34_ChB_D0         ", i_msg_block.BCW34_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW35_ChB_D0         ", i_msg_block.BCW35_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW36_ChB_D0         ", i_msg_block.BCW36_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW37_ChB_D0         ", i_msg_block.BCW37_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW38_ChB_D0         ", i_msg_block.BCW38_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW39_ChB_D0         ", i_msg_block.BCW39_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW3A_ChB_D0         ", i_msg_block.BCW3A_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW3B_ChB_D0         ", i_msg_block.BCW3B_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW3C_ChB_D0         ", i_msg_block.BCW3C_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW3D_ChB_D0         ", i_msg_block.BCW3D_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW3E_ChB_D0         ", i_msg_block.BCW3E_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW3F_ChB_D0         ", i_msg_block.BCW3F_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW40_ChB_D0         ", i_msg_block.BCW40_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW41_ChB_D0         ", i_msg_block.BCW41_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW42_ChB_D0         ", i_msg_block.BCW42_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW43_ChB_D0         ", i_msg_block.BCW43_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW44_ChB_D0         ", i_msg_block.BCW44_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW45_ChB_D0         ", i_msg_block.BCW45_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW46_ChB_D0         ", i_msg_block.BCW46_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW47_ChB_D0         ", i_msg_block.BCW47_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW48_ChB_D0         ", i_msg_block.BCW48_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW49_ChB_D0         ", i_msg_block.BCW49_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW4A_ChB_D0         ", i_msg_block.BCW4A_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW4B_ChB_D0         ", i_msg_block.BCW4B_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW4C_ChB_D0         ", i_msg_block.BCW4C_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW4D_ChB_D0         ", i_msg_block.BCW4D_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW4E_ChB_D0         ", i_msg_block.BCW4E_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW4F_ChB_D0         ", i_msg_block.BCW4F_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW50_ChB_D0         ", i_msg_block.BCW50_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW51_ChB_D0         ", i_msg_block.BCW51_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW52_ChB_D0         ", i_msg_block.BCW52_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW53_ChB_D0         ", i_msg_block.BCW53_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW54_ChB_D0         ", i_msg_block.BCW54_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW55_ChB_D0         ", i_msg_block.BCW55_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW56_ChB_D0         ", i_msg_block.BCW56_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW57_ChB_D0         ", i_msg_block.BCW57_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW58_ChB_D0         ", i_msg_block.BCW58_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW59_ChB_D0         ", i_msg_block.BCW59_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW5A_ChB_D0         ", i_msg_block.BCW5A_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW5B_ChB_D0         ", i_msg_block.BCW5B_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW5C_ChB_D0         ", i_msg_block.BCW5C_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW5D_ChB_D0         ", i_msg_block.BCW5D_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW5E_ChB_D0         ", i_msg_block.BCW5E_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW5F_ChB_D0         ", i_msg_block.BCW5F_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW60_ChB_D0         ", i_msg_block.BCW60_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW61_ChB_D0         ", i_msg_block.BCW61_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW62_ChB_D0         ", i_msg_block.BCW62_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW63_ChB_D0         ", i_msg_block.BCW63_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW64_ChB_D0         ", i_msg_block.BCW64_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW65_ChB_D0         ", i_msg_block.BCW65_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW66_ChB_D0         ", i_msg_block.BCW66_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW67_ChB_D0         ", i_msg_block.BCW67_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW68_ChB_D0         ", i_msg_block.BCW68_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW69_ChB_D0         ", i_msg_block.BCW69_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW6A_ChB_D0         ", i_msg_block.BCW6A_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW6B_ChB_D0         ", i_msg_block.BCW6B_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW6C_ChB_D0         ", i_msg_block.BCW6C_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW6D_ChB_D0         ", i_msg_block.BCW6D_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW6E_ChB_D0         ", i_msg_block.BCW6E_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW6F_ChB_D0         ", i_msg_block.BCW6F_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW70_ChB_D0         ", i_msg_block.BCW70_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW71_ChB_D0         ", i_msg_block.BCW71_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW72_ChB_D0         ", i_msg_block.BCW72_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW73_ChB_D0         ", i_msg_block.BCW73_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW74_ChB_D0         ", i_msg_block.BCW74_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW75_ChB_D0         ", i_msg_block.BCW75_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW76_ChB_D0         ", i_msg_block.BCW76_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW77_ChB_D0         ", i_msg_block.BCW77_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW78_ChB_D0         ", i_msg_block.BCW78_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW79_ChB_D0         ", i_msg_block.BCW79_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW7A_ChB_D0         ", i_msg_block.BCW7A_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW7B_ChB_D0         ", i_msg_block.BCW7B_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW7C_ChB_D0         ", i_msg_block.BCW7C_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW7D_ChB_D0         ", i_msg_block.BCW7D_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW7E_ChB_D0         ", i_msg_block.BCW7E_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW7F_ChB_D0         ", i_msg_block.BCW7F_ChB_D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW00_ChB_D1         ", i_msg_block.RCW00_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW01_ChB_D1         ", i_msg_block.RCW01_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW02_ChB_D1         ", i_msg_block.RCW02_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW03_ChB_D1         ", i_msg_block.RCW03_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW04_ChB_D1         ", i_msg_block.RCW04_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW05_ChB_D1         ", i_msg_block.RCW05_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW06_ChB_D1         ", i_msg_block.RCW06_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW07_ChB_D1         ", i_msg_block.RCW07_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW08_ChB_D1         ", i_msg_block.RCW08_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW09_ChB_D1         ", i_msg_block.RCW09_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW0A_ChB_D1         ", i_msg_block.RCW0A_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW0B_ChB_D1         ", i_msg_block.RCW0B_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW0C_ChB_D1         ", i_msg_block.RCW0C_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW0D_ChB_D1         ", i_msg_block.RCW0D_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW0E_ChB_D1         ", i_msg_block.RCW0E_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW0F_ChB_D1         ", i_msg_block.RCW0F_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW10_ChB_D1         ", i_msg_block.RCW10_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW11_ChB_D1         ", i_msg_block.RCW11_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW12_ChB_D1         ", i_msg_block.RCW12_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW13_ChB_D1         ", i_msg_block.RCW13_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW14_ChB_D1         ", i_msg_block.RCW14_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW15_ChB_D1         ", i_msg_block.RCW15_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW16_ChB_D1         ", i_msg_block.RCW16_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW17_ChB_D1         ", i_msg_block.RCW17_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW18_ChB_D1         ", i_msg_block.RCW18_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW19_ChB_D1         ", i_msg_block.RCW19_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW1A_ChB_D1         ", i_msg_block.RCW1A_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW1B_ChB_D1         ", i_msg_block.RCW1B_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW1C_ChB_D1         ", i_msg_block.RCW1C_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW1D_ChB_D1         ", i_msg_block.RCW1D_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW1E_ChB_D1         ", i_msg_block.RCW1E_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW1F_ChB_D1         ", i_msg_block.RCW1F_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW20_ChB_D1         ", i_msg_block.RCW20_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW21_ChB_D1         ", i_msg_block.RCW21_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW22_ChB_D1         ", i_msg_block.RCW22_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW23_ChB_D1         ", i_msg_block.RCW23_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW24_ChB_D1         ", i_msg_block.RCW24_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW25_ChB_D1         ", i_msg_block.RCW25_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW26_ChB_D1         ", i_msg_block.RCW26_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW27_ChB_D1         ", i_msg_block.RCW27_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW28_ChB_D1         ", i_msg_block.RCW28_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW29_ChB_D1         ", i_msg_block.RCW29_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW2A_ChB_D1         ", i_msg_block.RCW2A_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW2B_ChB_D1         ", i_msg_block.RCW2B_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW2C_ChB_D1         ", i_msg_block.RCW2C_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW2D_ChB_D1         ", i_msg_block.RCW2D_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW2E_ChB_D1         ", i_msg_block.RCW2E_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW2F_ChB_D1         ", i_msg_block.RCW2F_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW30_ChB_D1         ", i_msg_block.RCW30_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW31_ChB_D1         ", i_msg_block.RCW31_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW32_ChB_D1         ", i_msg_block.RCW32_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW33_ChB_D1         ", i_msg_block.RCW33_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW34_ChB_D1         ", i_msg_block.RCW34_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW35_ChB_D1         ", i_msg_block.RCW35_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW36_ChB_D1         ", i_msg_block.RCW36_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW37_ChB_D1         ", i_msg_block.RCW37_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW38_ChB_D1         ", i_msg_block.RCW38_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW39_ChB_D1         ", i_msg_block.RCW39_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW3A_ChB_D1         ", i_msg_block.RCW3A_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW3B_ChB_D1         ", i_msg_block.RCW3B_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW3C_ChB_D1         ", i_msg_block.RCW3C_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW3D_ChB_D1         ", i_msg_block.RCW3D_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW3E_ChB_D1         ", i_msg_block.RCW3E_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW3F_ChB_D1         ", i_msg_block.RCW3F_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW40_ChB_D1         ", i_msg_block.RCW40_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW41_ChB_D1         ", i_msg_block.RCW41_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW42_ChB_D1         ", i_msg_block.RCW42_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW43_ChB_D1         ", i_msg_block.RCW43_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW44_ChB_D1         ", i_msg_block.RCW44_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW45_ChB_D1         ", i_msg_block.RCW45_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW46_ChB_D1         ", i_msg_block.RCW46_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW47_ChB_D1         ", i_msg_block.RCW47_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW48_ChB_D1         ", i_msg_block.RCW48_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW49_ChB_D1         ", i_msg_block.RCW49_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW4A_ChB_D1         ", i_msg_block.RCW4A_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW4B_ChB_D1         ", i_msg_block.RCW4B_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW4C_ChB_D1         ", i_msg_block.RCW4C_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW4D_ChB_D1         ", i_msg_block.RCW4D_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW4E_ChB_D1         ", i_msg_block.RCW4E_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW4F_ChB_D1         ", i_msg_block.RCW4F_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW50_ChB_D1         ", i_msg_block.RCW50_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW51_ChB_D1         ", i_msg_block.RCW51_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW52_ChB_D1         ", i_msg_block.RCW52_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW53_ChB_D1         ", i_msg_block.RCW53_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW54_ChB_D1         ", i_msg_block.RCW54_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW55_ChB_D1         ", i_msg_block.RCW55_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW56_ChB_D1         ", i_msg_block.RCW56_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW57_ChB_D1         ", i_msg_block.RCW57_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW58_ChB_D1         ", i_msg_block.RCW58_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW59_ChB_D1         ", i_msg_block.RCW59_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW5A_ChB_D1         ", i_msg_block.RCW5A_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW5B_ChB_D1         ", i_msg_block.RCW5B_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW5C_ChB_D1         ", i_msg_block.RCW5C_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW5D_ChB_D1         ", i_msg_block.RCW5D_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW5E_ChB_D1         ", i_msg_block.RCW5E_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW5F_ChB_D1         ", i_msg_block.RCW5F_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW60_ChB_D1         ", i_msg_block.RCW60_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW61_ChB_D1         ", i_msg_block.RCW61_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW62_ChB_D1         ", i_msg_block.RCW62_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW63_ChB_D1         ", i_msg_block.RCW63_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW64_ChB_D1         ", i_msg_block.RCW64_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW65_ChB_D1         ", i_msg_block.RCW65_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW66_ChB_D1         ", i_msg_block.RCW66_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW67_ChB_D1         ", i_msg_block.RCW67_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW68_ChB_D1         ", i_msg_block.RCW68_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW69_ChB_D1         ", i_msg_block.RCW69_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW6A_ChB_D1         ", i_msg_block.RCW6A_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW6B_ChB_D1         ", i_msg_block.RCW6B_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW6C_ChB_D1         ", i_msg_block.RCW6C_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW6D_ChB_D1         ", i_msg_block.RCW6D_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW6E_ChB_D1         ", i_msg_block.RCW6E_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW6F_ChB_D1         ", i_msg_block.RCW6F_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW70_ChB_D1         ", i_msg_block.RCW70_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW71_ChB_D1         ", i_msg_block.RCW71_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW72_ChB_D1         ", i_msg_block.RCW72_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW73_ChB_D1         ", i_msg_block.RCW73_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW74_ChB_D1         ", i_msg_block.RCW74_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW75_ChB_D1         ", i_msg_block.RCW75_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW76_ChB_D1         ", i_msg_block.RCW76_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW77_ChB_D1         ", i_msg_block.RCW77_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW78_ChB_D1         ", i_msg_block.RCW78_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW79_ChB_D1         ", i_msg_block.RCW79_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW7A_ChB_D1         ", i_msg_block.RCW7A_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW7B_ChB_D1         ", i_msg_block.RCW7B_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW7C_ChB_D1         ", i_msg_block.RCW7C_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW7D_ChB_D1         ", i_msg_block.RCW7D_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW7E_ChB_D1         ", i_msg_block.RCW7E_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "RCW7F_ChB_D1         ", i_msg_block.RCW7F_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW00_ChB_D1         ", i_msg_block.BCW00_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW01_ChB_D1         ", i_msg_block.BCW01_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW02_ChB_D1         ", i_msg_block.BCW02_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW03_ChB_D1         ", i_msg_block.BCW03_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW04_ChB_D1         ", i_msg_block.BCW04_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW05_ChB_D1         ", i_msg_block.BCW05_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW06_ChB_D1         ", i_msg_block.BCW06_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW07_ChB_D1         ", i_msg_block.BCW07_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW08_ChB_D1         ", i_msg_block.BCW08_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW09_ChB_D1         ", i_msg_block.BCW09_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW0A_ChB_D1         ", i_msg_block.BCW0A_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW0B_ChB_D1         ", i_msg_block.BCW0B_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW0C_ChB_D1         ", i_msg_block.BCW0C_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW0D_ChB_D1         ", i_msg_block.BCW0D_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW0E_ChB_D1         ", i_msg_block.BCW0E_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW0F_ChB_D1         ", i_msg_block.BCW0F_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW10_ChB_D1         ", i_msg_block.BCW10_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW11_ChB_D1         ", i_msg_block.BCW11_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW12_ChB_D1         ", i_msg_block.BCW12_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW13_ChB_D1         ", i_msg_block.BCW13_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW14_ChB_D1         ", i_msg_block.BCW14_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW15_ChB_D1         ", i_msg_block.BCW15_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW16_ChB_D1         ", i_msg_block.BCW16_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW17_ChB_D1         ", i_msg_block.BCW17_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW18_ChB_D1         ", i_msg_block.BCW18_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW19_ChB_D1         ", i_msg_block.BCW19_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW1A_ChB_D1         ", i_msg_block.BCW1A_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW1B_ChB_D1         ", i_msg_block.BCW1B_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW1C_ChB_D1         ", i_msg_block.BCW1C_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW1D_ChB_D1         ", i_msg_block.BCW1D_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW1E_ChB_D1         ", i_msg_block.BCW1E_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW1F_ChB_D1         ", i_msg_block.BCW1F_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW20_ChB_D1         ", i_msg_block.BCW20_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW21_ChB_D1         ", i_msg_block.BCW21_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW22_ChB_D1         ", i_msg_block.BCW22_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW23_ChB_D1         ", i_msg_block.BCW23_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW24_ChB_D1         ", i_msg_block.BCW24_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW25_ChB_D1         ", i_msg_block.BCW25_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW26_ChB_D1         ", i_msg_block.BCW26_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW27_ChB_D1         ", i_msg_block.BCW27_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW28_ChB_D1         ", i_msg_block.BCW28_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW29_ChB_D1         ", i_msg_block.BCW29_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW2A_ChB_D1         ", i_msg_block.BCW2A_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW2B_ChB_D1         ", i_msg_block.BCW2B_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW2C_ChB_D1         ", i_msg_block.BCW2C_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW2D_ChB_D1         ", i_msg_block.BCW2D_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW2E_ChB_D1         ", i_msg_block.BCW2E_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW2F_ChB_D1         ", i_msg_block.BCW2F_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW30_ChB_D1         ", i_msg_block.BCW30_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW31_ChB_D1         ", i_msg_block.BCW31_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW32_ChB_D1         ", i_msg_block.BCW32_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW33_ChB_D1         ", i_msg_block.BCW33_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW34_ChB_D1         ", i_msg_block.BCW34_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW35_ChB_D1         ", i_msg_block.BCW35_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW36_ChB_D1         ", i_msg_block.BCW36_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW37_ChB_D1         ", i_msg_block.BCW37_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW38_ChB_D1         ", i_msg_block.BCW38_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW39_ChB_D1         ", i_msg_block.BCW39_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW3A_ChB_D1         ", i_msg_block.BCW3A_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW3B_ChB_D1         ", i_msg_block.BCW3B_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW3C_ChB_D1         ", i_msg_block.BCW3C_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW3D_ChB_D1         ", i_msg_block.BCW3D_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW3E_ChB_D1         ", i_msg_block.BCW3E_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW3F_ChB_D1         ", i_msg_block.BCW3F_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW40_ChB_D1         ", i_msg_block.BCW40_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW41_ChB_D1         ", i_msg_block.BCW41_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW42_ChB_D1         ", i_msg_block.BCW42_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW43_ChB_D1         ", i_msg_block.BCW43_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW44_ChB_D1         ", i_msg_block.BCW44_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW45_ChB_D1         ", i_msg_block.BCW45_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW46_ChB_D1         ", i_msg_block.BCW46_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW47_ChB_D1         ", i_msg_block.BCW47_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW48_ChB_D1         ", i_msg_block.BCW48_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW49_ChB_D1         ", i_msg_block.BCW49_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW4A_ChB_D1         ", i_msg_block.BCW4A_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW4B_ChB_D1         ", i_msg_block.BCW4B_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW4C_ChB_D1         ", i_msg_block.BCW4C_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW4D_ChB_D1         ", i_msg_block.BCW4D_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW4E_ChB_D1         ", i_msg_block.BCW4E_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW4F_ChB_D1         ", i_msg_block.BCW4F_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW50_ChB_D1         ", i_msg_block.BCW50_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW51_ChB_D1         ", i_msg_block.BCW51_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW52_ChB_D1         ", i_msg_block.BCW52_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW53_ChB_D1         ", i_msg_block.BCW53_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW54_ChB_D1         ", i_msg_block.BCW54_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW55_ChB_D1         ", i_msg_block.BCW55_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW56_ChB_D1         ", i_msg_block.BCW56_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW57_ChB_D1         ", i_msg_block.BCW57_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW58_ChB_D1         ", i_msg_block.BCW58_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW59_ChB_D1         ", i_msg_block.BCW59_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW5A_ChB_D1         ", i_msg_block.BCW5A_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW5B_ChB_D1         ", i_msg_block.BCW5B_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW5C_ChB_D1         ", i_msg_block.BCW5C_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW5D_ChB_D1         ", i_msg_block.BCW5D_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW5E_ChB_D1         ", i_msg_block.BCW5E_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW5F_ChB_D1         ", i_msg_block.BCW5F_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW60_ChB_D1         ", i_msg_block.BCW60_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW61_ChB_D1         ", i_msg_block.BCW61_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW62_ChB_D1         ", i_msg_block.BCW62_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW63_ChB_D1         ", i_msg_block.BCW63_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW64_ChB_D1         ", i_msg_block.BCW64_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW65_ChB_D1         ", i_msg_block.BCW65_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW66_ChB_D1         ", i_msg_block.BCW66_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW67_ChB_D1         ", i_msg_block.BCW67_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW68_ChB_D1         ", i_msg_block.BCW68_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW69_ChB_D1         ", i_msg_block.BCW69_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW6A_ChB_D1         ", i_msg_block.BCW6A_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW6B_ChB_D1         ", i_msg_block.BCW6B_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW6C_ChB_D1         ", i_msg_block.BCW6C_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW6D_ChB_D1         ", i_msg_block.BCW6D_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW6E_ChB_D1         ", i_msg_block.BCW6E_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW6F_ChB_D1         ", i_msg_block.BCW6F_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW70_ChB_D1         ", i_msg_block.BCW70_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW71_ChB_D1         ", i_msg_block.BCW71_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW72_ChB_D1         ", i_msg_block.BCW72_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW73_ChB_D1         ", i_msg_block.BCW73_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW74_ChB_D1         ", i_msg_block.BCW74_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW75_ChB_D1         ", i_msg_block.BCW75_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW76_ChB_D1         ", i_msg_block.BCW76_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW77_ChB_D1         ", i_msg_block.BCW77_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW78_ChB_D1         ", i_msg_block.BCW78_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW79_ChB_D1         ", i_msg_block.BCW79_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW7A_ChB_D1         ", i_msg_block.BCW7A_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW7B_ChB_D1         ", i_msg_block.BCW7B_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW7C_ChB_D1         ", i_msg_block.BCW7C_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW7D_ChB_D1         ", i_msg_block.BCW7D_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW7E_ChB_D1         ", i_msg_block.BCW7E_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "BCW7F_ChB_D1         ", i_msg_block.BCW7F_ChB_D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR0Nib0         ", i_msg_block.VrefDqR0Nib0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR0Nib1         ", i_msg_block.VrefDqR0Nib1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR0Nib2         ", i_msg_block.VrefDqR0Nib2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR0Nib3         ", i_msg_block.VrefDqR0Nib3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR0Nib4         ", i_msg_block.VrefDqR0Nib4, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR0Nib5         ", i_msg_block.VrefDqR0Nib5, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR0Nib6         ", i_msg_block.VrefDqR0Nib6, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR0Nib7         ", i_msg_block.VrefDqR0Nib7, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR0Nib8         ", i_msg_block.VrefDqR0Nib8, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR0Nib9         ", i_msg_block.VrefDqR0Nib9, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR0Nib10        ", i_msg_block.VrefDqR0Nib10, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR0Nib11        ", i_msg_block.VrefDqR0Nib11, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR0Nib12        ", i_msg_block.VrefDqR0Nib12, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR0Nib13        ", i_msg_block.VrefDqR0Nib13, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR0Nib14        ", i_msg_block.VrefDqR0Nib14, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR0Nib15        ", i_msg_block.VrefDqR0Nib15, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR0Nib16        ", i_msg_block.VrefDqR0Nib16, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR0Nib17        ", i_msg_block.VrefDqR0Nib17, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR0Nib18        ", i_msg_block.VrefDqR0Nib18, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR0Nib19        ", i_msg_block.VrefDqR0Nib19, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR1Nib0         ", i_msg_block.VrefDqR1Nib0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR1Nib1         ", i_msg_block.VrefDqR1Nib1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR1Nib2         ", i_msg_block.VrefDqR1Nib2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR1Nib3         ", i_msg_block.VrefDqR1Nib3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR1Nib4         ", i_msg_block.VrefDqR1Nib4, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR1Nib5         ", i_msg_block.VrefDqR1Nib5, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR1Nib6         ", i_msg_block.VrefDqR1Nib6, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR1Nib7         ", i_msg_block.VrefDqR1Nib7, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR1Nib8         ", i_msg_block.VrefDqR1Nib8, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR1Nib9         ", i_msg_block.VrefDqR1Nib9, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR1Nib10        ", i_msg_block.VrefDqR1Nib10, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR1Nib11        ", i_msg_block.VrefDqR1Nib11, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR1Nib12        ", i_msg_block.VrefDqR1Nib12, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR1Nib13        ", i_msg_block.VrefDqR1Nib13, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR1Nib14        ", i_msg_block.VrefDqR1Nib14, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR1Nib15        ", i_msg_block.VrefDqR1Nib15, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR1Nib16        ", i_msg_block.VrefDqR1Nib16, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR1Nib17        ", i_msg_block.VrefDqR1Nib17, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR1Nib18        ", i_msg_block.VrefDqR1Nib18, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR1Nib19        ", i_msg_block.VrefDqR1Nib19, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR2Nib0         ", i_msg_block.VrefDqR2Nib0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR2Nib1         ", i_msg_block.VrefDqR2Nib1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR2Nib2         ", i_msg_block.VrefDqR2Nib2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR2Nib3         ", i_msg_block.VrefDqR2Nib3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR2Nib4         ", i_msg_block.VrefDqR2Nib4, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR2Nib5         ", i_msg_block.VrefDqR2Nib5, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR2Nib6         ", i_msg_block.VrefDqR2Nib6, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR2Nib7         ", i_msg_block.VrefDqR2Nib7, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR2Nib8         ", i_msg_block.VrefDqR2Nib8, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR2Nib9         ", i_msg_block.VrefDqR2Nib9, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR2Nib10        ", i_msg_block.VrefDqR2Nib10, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR2Nib11        ", i_msg_block.VrefDqR2Nib11, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR2Nib12        ", i_msg_block.VrefDqR2Nib12, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR2Nib13        ", i_msg_block.VrefDqR2Nib13, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR2Nib14        ", i_msg_block.VrefDqR2Nib14, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR2Nib15        ", i_msg_block.VrefDqR2Nib15, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR2Nib16        ", i_msg_block.VrefDqR2Nib16, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR2Nib17        ", i_msg_block.VrefDqR2Nib17, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR2Nib18        ", i_msg_block.VrefDqR2Nib18, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR2Nib19        ", i_msg_block.VrefDqR2Nib19, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR3Nib0         ", i_msg_block.VrefDqR3Nib0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR3Nib1         ", i_msg_block.VrefDqR3Nib1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR3Nib2         ", i_msg_block.VrefDqR3Nib2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR3Nib3         ", i_msg_block.VrefDqR3Nib3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR3Nib4         ", i_msg_block.VrefDqR3Nib4, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR3Nib5         ", i_msg_block.VrefDqR3Nib5, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR3Nib6         ", i_msg_block.VrefDqR3Nib6, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR3Nib7         ", i_msg_block.VrefDqR3Nib7, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR3Nib8         ", i_msg_block.VrefDqR3Nib8, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR3Nib9         ", i_msg_block.VrefDqR3Nib9, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR3Nib10        ", i_msg_block.VrefDqR3Nib10, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR3Nib11        ", i_msg_block.VrefDqR3Nib11, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR3Nib12        ", i_msg_block.VrefDqR3Nib12, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR3Nib13        ", i_msg_block.VrefDqR3Nib13, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR3Nib14        ", i_msg_block.VrefDqR3Nib14, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR3Nib15        ", i_msg_block.VrefDqR3Nib15, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR3Nib16        ", i_msg_block.VrefDqR3Nib16, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR3Nib17        ", i_msg_block.VrefDqR3Nib17, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR3Nib18        ", i_msg_block.VrefDqR3Nib18, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefDqR3Nib19        ", i_msg_block.VrefDqR3Nib19, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R0Nib0            ", i_msg_block.MR3R0Nib0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R0Nib1            ", i_msg_block.MR3R0Nib1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R0Nib2            ", i_msg_block.MR3R0Nib2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R0Nib3            ", i_msg_block.MR3R0Nib3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R0Nib4            ", i_msg_block.MR3R0Nib4, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R0Nib5            ", i_msg_block.MR3R0Nib5, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R0Nib6            ", i_msg_block.MR3R0Nib6, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R0Nib7            ", i_msg_block.MR3R0Nib7, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R0Nib8            ", i_msg_block.MR3R0Nib8, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R0Nib9            ", i_msg_block.MR3R0Nib9, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R0Nib10           ", i_msg_block.MR3R0Nib10, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R0Nib11           ", i_msg_block.MR3R0Nib11, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R0Nib12           ", i_msg_block.MR3R0Nib12, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R0Nib13           ", i_msg_block.MR3R0Nib13, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R0Nib14           ", i_msg_block.MR3R0Nib14, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R0Nib15           ", i_msg_block.MR3R0Nib15, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R0Nib16           ", i_msg_block.MR3R0Nib16, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R0Nib17           ", i_msg_block.MR3R0Nib17, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R0Nib18           ", i_msg_block.MR3R0Nib18, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R0Nib19           ", i_msg_block.MR3R0Nib19, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R1Nib0            ", i_msg_block.MR3R1Nib0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R1Nib1            ", i_msg_block.MR3R1Nib1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R1Nib2            ", i_msg_block.MR3R1Nib2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R1Nib3            ", i_msg_block.MR3R1Nib3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R1Nib4            ", i_msg_block.MR3R1Nib4, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R1Nib5            ", i_msg_block.MR3R1Nib5, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R1Nib6            ", i_msg_block.MR3R1Nib6, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R1Nib7            ", i_msg_block.MR3R1Nib7, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R1Nib8            ", i_msg_block.MR3R1Nib8, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R1Nib9            ", i_msg_block.MR3R1Nib9, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R1Nib10           ", i_msg_block.MR3R1Nib10, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R1Nib11           ", i_msg_block.MR3R1Nib11, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R1Nib12           ", i_msg_block.MR3R1Nib12, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R1Nib13           ", i_msg_block.MR3R1Nib13, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R1Nib14           ", i_msg_block.MR3R1Nib14, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R1Nib15           ", i_msg_block.MR3R1Nib15, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R1Nib16           ", i_msg_block.MR3R1Nib16, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R1Nib17           ", i_msg_block.MR3R1Nib17, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R1Nib18           ", i_msg_block.MR3R1Nib18, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R1Nib19           ", i_msg_block.MR3R1Nib19, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R2Nib0            ", i_msg_block.MR3R2Nib0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R2Nib1            ", i_msg_block.MR3R2Nib1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R2Nib2            ", i_msg_block.MR3R2Nib2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R2Nib3            ", i_msg_block.MR3R2Nib3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R2Nib4            ", i_msg_block.MR3R2Nib4, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R2Nib5            ", i_msg_block.MR3R2Nib5, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R2Nib6            ", i_msg_block.MR3R2Nib6, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R2Nib7            ", i_msg_block.MR3R2Nib7, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R2Nib8            ", i_msg_block.MR3R2Nib8, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R2Nib9            ", i_msg_block.MR3R2Nib9, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R2Nib10           ", i_msg_block.MR3R2Nib10, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R2Nib11           ", i_msg_block.MR3R2Nib11, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R2Nib12           ", i_msg_block.MR3R2Nib12, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R2Nib13           ", i_msg_block.MR3R2Nib13, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R2Nib14           ", i_msg_block.MR3R2Nib14, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R2Nib15           ", i_msg_block.MR3R2Nib15, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R2Nib16           ", i_msg_block.MR3R2Nib16, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R2Nib17           ", i_msg_block.MR3R2Nib17, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R2Nib18           ", i_msg_block.MR3R2Nib18, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R2Nib19           ", i_msg_block.MR3R2Nib19, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R3Nib0            ", i_msg_block.MR3R3Nib0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R3Nib1            ", i_msg_block.MR3R3Nib1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R3Nib2            ", i_msg_block.MR3R3Nib2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R3Nib3            ", i_msg_block.MR3R3Nib3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R3Nib4            ", i_msg_block.MR3R3Nib4, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R3Nib5            ", i_msg_block.MR3R3Nib5, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R3Nib6            ", i_msg_block.MR3R3Nib6, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R3Nib7            ", i_msg_block.MR3R3Nib7, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R3Nib8            ", i_msg_block.MR3R3Nib8, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R3Nib9            ", i_msg_block.MR3R3Nib9, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R3Nib10           ", i_msg_block.MR3R3Nib10, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R3Nib11           ", i_msg_block.MR3R3Nib11, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R3Nib12           ", i_msg_block.MR3R3Nib12, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R3Nib13           ", i_msg_block.MR3R3Nib13, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R3Nib14           ", i_msg_block.MR3R3Nib14, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R3Nib15           ", i_msg_block.MR3R3Nib15, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R3Nib16           ", i_msg_block.MR3R3Nib16, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R3Nib17           ", i_msg_block.MR3R3Nib17, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R3Nib18           ", i_msg_block.MR3R3Nib18, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR3R3Nib19           ", i_msg_block.MR3R3Nib19, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR0Nib0         ", i_msg_block.VrefCSR0Nib0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR0Nib1         ", i_msg_block.VrefCSR0Nib1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR0Nib2         ", i_msg_block.VrefCSR0Nib2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR0Nib3         ", i_msg_block.VrefCSR0Nib3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR0Nib4         ", i_msg_block.VrefCSR0Nib4, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR0Nib5         ", i_msg_block.VrefCSR0Nib5, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR0Nib6         ", i_msg_block.VrefCSR0Nib6, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR0Nib7         ", i_msg_block.VrefCSR0Nib7, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR0Nib8         ", i_msg_block.VrefCSR0Nib8, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR0Nib9         ", i_msg_block.VrefCSR0Nib9, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR0Nib10        ", i_msg_block.VrefCSR0Nib10, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR0Nib11        ", i_msg_block.VrefCSR0Nib11, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR0Nib12        ", i_msg_block.VrefCSR0Nib12, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR0Nib13        ", i_msg_block.VrefCSR0Nib13, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR0Nib14        ", i_msg_block.VrefCSR0Nib14, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR0Nib15        ", i_msg_block.VrefCSR0Nib15, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR0Nib16        ", i_msg_block.VrefCSR0Nib16, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR0Nib17        ", i_msg_block.VrefCSR0Nib17, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR0Nib18        ", i_msg_block.VrefCSR0Nib18, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR0Nib19        ", i_msg_block.VrefCSR0Nib19, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR1Nib0         ", i_msg_block.VrefCSR1Nib0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR1Nib1         ", i_msg_block.VrefCSR1Nib1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR1Nib2         ", i_msg_block.VrefCSR1Nib2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR1Nib3         ", i_msg_block.VrefCSR1Nib3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR1Nib4         ", i_msg_block.VrefCSR1Nib4, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR1Nib5         ", i_msg_block.VrefCSR1Nib5, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR1Nib6         ", i_msg_block.VrefCSR1Nib6, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR1Nib7         ", i_msg_block.VrefCSR1Nib7, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR1Nib8         ", i_msg_block.VrefCSR1Nib8, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR1Nib9         ", i_msg_block.VrefCSR1Nib9, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR1Nib10        ", i_msg_block.VrefCSR1Nib10, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR1Nib11        ", i_msg_block.VrefCSR1Nib11, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR1Nib12        ", i_msg_block.VrefCSR1Nib12, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR1Nib13        ", i_msg_block.VrefCSR1Nib13, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR1Nib14        ", i_msg_block.VrefCSR1Nib14, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR1Nib15        ", i_msg_block.VrefCSR1Nib15, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR1Nib16        ", i_msg_block.VrefCSR1Nib16, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR1Nib17        ", i_msg_block.VrefCSR1Nib17, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR1Nib18        ", i_msg_block.VrefCSR1Nib18, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR1Nib19        ", i_msg_block.VrefCSR1Nib19, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR2Nib0         ", i_msg_block.VrefCSR2Nib0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR2Nib1         ", i_msg_block.VrefCSR2Nib1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR2Nib2         ", i_msg_block.VrefCSR2Nib2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR2Nib3         ", i_msg_block.VrefCSR2Nib3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR2Nib4         ", i_msg_block.VrefCSR2Nib4, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR2Nib5         ", i_msg_block.VrefCSR2Nib5, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR2Nib6         ", i_msg_block.VrefCSR2Nib6, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR2Nib7         ", i_msg_block.VrefCSR2Nib7, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR2Nib8         ", i_msg_block.VrefCSR2Nib8, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR2Nib9         ", i_msg_block.VrefCSR2Nib9, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR2Nib10        ", i_msg_block.VrefCSR2Nib10, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR2Nib11        ", i_msg_block.VrefCSR2Nib11, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR2Nib12        ", i_msg_block.VrefCSR2Nib12, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR2Nib13        ", i_msg_block.VrefCSR2Nib13, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR2Nib14        ", i_msg_block.VrefCSR2Nib14, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR2Nib15        ", i_msg_block.VrefCSR2Nib15, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR2Nib16        ", i_msg_block.VrefCSR2Nib16, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR2Nib17        ", i_msg_block.VrefCSR2Nib17, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR2Nib18        ", i_msg_block.VrefCSR2Nib18, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR2Nib19        ", i_msg_block.VrefCSR2Nib19, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR3Nib0         ", i_msg_block.VrefCSR3Nib0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR3Nib1         ", i_msg_block.VrefCSR3Nib1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR3Nib2         ", i_msg_block.VrefCSR3Nib2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR3Nib3         ", i_msg_block.VrefCSR3Nib3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR3Nib4         ", i_msg_block.VrefCSR3Nib4, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR3Nib5         ", i_msg_block.VrefCSR3Nib5, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR3Nib6         ", i_msg_block.VrefCSR3Nib6, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR3Nib7         ", i_msg_block.VrefCSR3Nib7, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR3Nib8         ", i_msg_block.VrefCSR3Nib8, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR3Nib9         ", i_msg_block.VrefCSR3Nib9, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR3Nib10        ", i_msg_block.VrefCSR3Nib10, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR3Nib11        ", i_msg_block.VrefCSR3Nib11, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR3Nib12        ", i_msg_block.VrefCSR3Nib12, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR3Nib13        ", i_msg_block.VrefCSR3Nib13, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR3Nib14        ", i_msg_block.VrefCSR3Nib14, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR3Nib15        ", i_msg_block.VrefCSR3Nib15, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR3Nib16        ", i_msg_block.VrefCSR3Nib16, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR3Nib17        ", i_msg_block.VrefCSR3Nib17, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR3Nib18        ", i_msg_block.VrefCSR3Nib18, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCSR3Nib19        ", i_msg_block.VrefCSR3Nib19, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR0Nib0         ", i_msg_block.VrefCAR0Nib0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR0Nib1         ", i_msg_block.VrefCAR0Nib1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR0Nib2         ", i_msg_block.VrefCAR0Nib2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR0Nib3         ", i_msg_block.VrefCAR0Nib3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR0Nib4         ", i_msg_block.VrefCAR0Nib4, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR0Nib5         ", i_msg_block.VrefCAR0Nib5, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR0Nib6         ", i_msg_block.VrefCAR0Nib6, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR0Nib7         ", i_msg_block.VrefCAR0Nib7, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR0Nib8         ", i_msg_block.VrefCAR0Nib8, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR0Nib9         ", i_msg_block.VrefCAR0Nib9, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR0Nib10        ", i_msg_block.VrefCAR0Nib10, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR0Nib11        ", i_msg_block.VrefCAR0Nib11, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR0Nib12        ", i_msg_block.VrefCAR0Nib12, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR0Nib13        ", i_msg_block.VrefCAR0Nib13, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR0Nib14        ", i_msg_block.VrefCAR0Nib14, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR0Nib15        ", i_msg_block.VrefCAR0Nib15, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR0Nib16        ", i_msg_block.VrefCAR0Nib16, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR0Nib17        ", i_msg_block.VrefCAR0Nib17, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR0Nib18        ", i_msg_block.VrefCAR0Nib18, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR0Nib19        ", i_msg_block.VrefCAR0Nib19, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR1Nib0         ", i_msg_block.VrefCAR1Nib0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR1Nib1         ", i_msg_block.VrefCAR1Nib1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR1Nib2         ", i_msg_block.VrefCAR1Nib2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR1Nib3         ", i_msg_block.VrefCAR1Nib3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR1Nib4         ", i_msg_block.VrefCAR1Nib4, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR1Nib5         ", i_msg_block.VrefCAR1Nib5, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR1Nib6         ", i_msg_block.VrefCAR1Nib6, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR1Nib7         ", i_msg_block.VrefCAR1Nib7, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR1Nib8         ", i_msg_block.VrefCAR1Nib8, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR1Nib9         ", i_msg_block.VrefCAR1Nib9, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR1Nib10        ", i_msg_block.VrefCAR1Nib10, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR1Nib11        ", i_msg_block.VrefCAR1Nib11, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR1Nib12        ", i_msg_block.VrefCAR1Nib12, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR1Nib13        ", i_msg_block.VrefCAR1Nib13, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR1Nib14        ", i_msg_block.VrefCAR1Nib14, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR1Nib15        ", i_msg_block.VrefCAR1Nib15, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR1Nib16        ", i_msg_block.VrefCAR1Nib16, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR1Nib17        ", i_msg_block.VrefCAR1Nib17, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR1Nib18        ", i_msg_block.VrefCAR1Nib18, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR1Nib19        ", i_msg_block.VrefCAR1Nib19, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR2Nib0         ", i_msg_block.VrefCAR2Nib0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR2Nib1         ", i_msg_block.VrefCAR2Nib1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR2Nib2         ", i_msg_block.VrefCAR2Nib2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR2Nib3         ", i_msg_block.VrefCAR2Nib3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR2Nib4         ", i_msg_block.VrefCAR2Nib4, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR2Nib5         ", i_msg_block.VrefCAR2Nib5, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR2Nib6         ", i_msg_block.VrefCAR2Nib6, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR2Nib7         ", i_msg_block.VrefCAR2Nib7, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR2Nib8         ", i_msg_block.VrefCAR2Nib8, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR2Nib9         ", i_msg_block.VrefCAR2Nib9, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR2Nib10        ", i_msg_block.VrefCAR2Nib10, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR2Nib11        ", i_msg_block.VrefCAR2Nib11, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR2Nib12        ", i_msg_block.VrefCAR2Nib12, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR2Nib13        ", i_msg_block.VrefCAR2Nib13, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR2Nib14        ", i_msg_block.VrefCAR2Nib14, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR2Nib15        ", i_msg_block.VrefCAR2Nib15, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR2Nib16        ", i_msg_block.VrefCAR2Nib16, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR2Nib17        ", i_msg_block.VrefCAR2Nib17, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR2Nib18        ", i_msg_block.VrefCAR2Nib18, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR2Nib19        ", i_msg_block.VrefCAR2Nib19, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR3Nib0         ", i_msg_block.VrefCAR3Nib0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR3Nib1         ", i_msg_block.VrefCAR3Nib1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR3Nib2         ", i_msg_block.VrefCAR3Nib2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR3Nib3         ", i_msg_block.VrefCAR3Nib3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR3Nib4         ", i_msg_block.VrefCAR3Nib4, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR3Nib5         ", i_msg_block.VrefCAR3Nib5, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR3Nib6         ", i_msg_block.VrefCAR3Nib6, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR3Nib7         ", i_msg_block.VrefCAR3Nib7, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR3Nib8         ", i_msg_block.VrefCAR3Nib8, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR3Nib9         ", i_msg_block.VrefCAR3Nib9, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR3Nib10        ", i_msg_block.VrefCAR3Nib10, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR3Nib11        ", i_msg_block.VrefCAR3Nib11, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR3Nib12        ", i_msg_block.VrefCAR3Nib12, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR3Nib13        ", i_msg_block.VrefCAR3Nib13, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR3Nib14        ", i_msg_block.VrefCAR3Nib14, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR3Nib15        ", i_msg_block.VrefCAR3Nib15, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR3Nib16        ", i_msg_block.VrefCAR3Nib16, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR3Nib17        ", i_msg_block.VrefCAR3Nib17, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR3Nib18        ", i_msg_block.VrefCAR3Nib18, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCAR3Nib19        ", i_msg_block.VrefCAR3Nib19, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB0LaneR0    ", i_msg_block.DisabledDB0LaneR0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB1LaneR0    ", i_msg_block.DisabledDB1LaneR0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB2LaneR0    ", i_msg_block.DisabledDB2LaneR0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB3LaneR0    ", i_msg_block.DisabledDB3LaneR0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB4LaneR0    ", i_msg_block.DisabledDB4LaneR0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB5LaneR0    ", i_msg_block.DisabledDB5LaneR0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB6LaneR0    ", i_msg_block.DisabledDB6LaneR0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB7LaneR0    ", i_msg_block.DisabledDB7LaneR0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB8LaneR0    ", i_msg_block.DisabledDB8LaneR0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB9LaneR0    ", i_msg_block.DisabledDB9LaneR0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB0LaneR1    ", i_msg_block.DisabledDB0LaneR1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB1LaneR1    ", i_msg_block.DisabledDB1LaneR1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB2LaneR1    ", i_msg_block.DisabledDB2LaneR1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB3LaneR1    ", i_msg_block.DisabledDB3LaneR1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB4LaneR1    ", i_msg_block.DisabledDB4LaneR1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB5LaneR1    ", i_msg_block.DisabledDB5LaneR1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB6LaneR1    ", i_msg_block.DisabledDB6LaneR1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB7LaneR1    ", i_msg_block.DisabledDB7LaneR1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB8LaneR1    ", i_msg_block.DisabledDB8LaneR1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB9LaneR1    ", i_msg_block.DisabledDB9LaneR1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB0LaneR2    ", i_msg_block.DisabledDB0LaneR2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB1LaneR2    ", i_msg_block.DisabledDB1LaneR2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB2LaneR2    ", i_msg_block.DisabledDB2LaneR2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB3LaneR2    ", i_msg_block.DisabledDB3LaneR2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB4LaneR2    ", i_msg_block.DisabledDB4LaneR2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB5LaneR2    ", i_msg_block.DisabledDB5LaneR2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB6LaneR2    ", i_msg_block.DisabledDB6LaneR2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB7LaneR2    ", i_msg_block.DisabledDB7LaneR2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB8LaneR2    ", i_msg_block.DisabledDB8LaneR2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB9LaneR2    ", i_msg_block.DisabledDB9LaneR2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB0LaneR3    ", i_msg_block.DisabledDB0LaneR3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB1LaneR3    ", i_msg_block.DisabledDB1LaneR3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB2LaneR3    ", i_msg_block.DisabledDB2LaneR3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB3LaneR3    ", i_msg_block.DisabledDB3LaneR3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB4LaneR3    ", i_msg_block.DisabledDB4LaneR3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB5LaneR3    ", i_msg_block.DisabledDB5LaneR3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB6LaneR3    ", i_msg_block.DisabledDB6LaneR3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB7LaneR3    ", i_msg_block.DisabledDB7LaneR3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB8LaneR3    ", i_msg_block.DisabledDB8LaneR3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "DisabledDB9LaneR3    ", i_msg_block.DisabledDB9LaneR3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "QCS_Dly_Margin_A0    ", i_msg_block.QCS_Dly_Margin_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "QCA_Dly_Margin_A0    ", i_msg_block.QCA_Dly_Margin_A0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "QCS_Dly_Margin_A1    ", i_msg_block.QCS_Dly_Margin_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "QCA_Dly_Margin_A1    ", i_msg_block.QCA_Dly_Margin_A1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "QCS_Dly_Margin_A2    ", i_msg_block.QCS_Dly_Margin_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "QCA_Dly_Margin_A2    ", i_msg_block.QCA_Dly_Margin_A2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "QCS_Dly_Margin_A3    ", i_msg_block.QCS_Dly_Margin_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "QCA_Dly_Margin_A3    ", i_msg_block.QCA_Dly_Margin_A3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "QCS_Dly_Margin_B0    ", i_msg_block.QCS_Dly_Margin_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "QCA_Dly_Margin_B0    ", i_msg_block.QCA_Dly_Margin_B0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "QCS_Dly_Margin_B1    ", i_msg_block.QCS_Dly_Margin_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "QCA_Dly_Margin_B1    ", i_msg_block.QCA_Dly_Margin_B1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "QCS_Dly_Margin_B2    ", i_msg_block.QCS_Dly_Margin_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "QCA_Dly_Margin_B2    ", i_msg_block.QCA_Dly_Margin_B2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "QCS_Dly_Margin_B3    ", i_msg_block.QCS_Dly_Margin_B3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "QCA_Dly_Margin_B3    ", i_msg_block.QCA_Dly_Margin_B3, TARGTID);
    FAPI_INF("  .%s= 0x%04x; // " TARGTIDFORMAT, "PmuInternalRev0      ", i_msg_block.PmuInternalRev0, TARGTID);
    FAPI_INF("  .%s= 0x%04x; // " TARGTIDFORMAT, "PmuInternalRev1      ", i_msg_block.PmuInternalRev1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCS_Sweep_Min     ", i_msg_block.VrefCS_Sweep_Min, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCS_Sweep_Max     ", i_msg_block.VrefCS_Sweep_Max, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCA_Sweep_Min     ", i_msg_block.VrefCA_Sweep_Min, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "VrefCA_Sweep_Max     ", i_msg_block.VrefCA_Sweep_Max, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R0Nib0           ", i_msg_block.MR32R0Nib0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R0Nib1           ", i_msg_block.MR32R0Nib1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R0Nib2           ", i_msg_block.MR32R0Nib2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R0Nib3           ", i_msg_block.MR32R0Nib3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R0Nib4           ", i_msg_block.MR32R0Nib4, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R0Nib5           ", i_msg_block.MR32R0Nib5, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R0Nib6           ", i_msg_block.MR32R0Nib6, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R0Nib7           ", i_msg_block.MR32R0Nib7, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R0Nib8           ", i_msg_block.MR32R0Nib8, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R0Nib9           ", i_msg_block.MR32R0Nib9, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R0Nib10          ", i_msg_block.MR32R0Nib10, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R0Nib11          ", i_msg_block.MR32R0Nib11, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R0Nib12          ", i_msg_block.MR32R0Nib12, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R0Nib13          ", i_msg_block.MR32R0Nib13, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R0Nib14          ", i_msg_block.MR32R0Nib14, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R0Nib15          ", i_msg_block.MR32R0Nib15, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R0Nib16          ", i_msg_block.MR32R0Nib16, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R0Nib17          ", i_msg_block.MR32R0Nib17, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R0Nib18          ", i_msg_block.MR32R0Nib18, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R0Nib19          ", i_msg_block.MR32R0Nib19, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R1Nib0           ", i_msg_block.MR32R1Nib0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R1Nib1           ", i_msg_block.MR32R1Nib1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R1Nib2           ", i_msg_block.MR32R1Nib2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R1Nib3           ", i_msg_block.MR32R1Nib3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R1Nib4           ", i_msg_block.MR32R1Nib4, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R1Nib5           ", i_msg_block.MR32R1Nib5, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R1Nib6           ", i_msg_block.MR32R1Nib6, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R1Nib7           ", i_msg_block.MR32R1Nib7, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R1Nib8           ", i_msg_block.MR32R1Nib8, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R1Nib9           ", i_msg_block.MR32R1Nib9, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R1Nib10          ", i_msg_block.MR32R1Nib10, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R1Nib11          ", i_msg_block.MR32R1Nib11, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R1Nib12          ", i_msg_block.MR32R1Nib12, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R1Nib13          ", i_msg_block.MR32R1Nib13, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R1Nib14          ", i_msg_block.MR32R1Nib14, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R1Nib15          ", i_msg_block.MR32R1Nib15, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R1Nib16          ", i_msg_block.MR32R1Nib16, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R1Nib17          ", i_msg_block.MR32R1Nib17, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R1Nib18          ", i_msg_block.MR32R1Nib18, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R1Nib19          ", i_msg_block.MR32R1Nib19, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R2Nib0           ", i_msg_block.MR32R2Nib0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R2Nib1           ", i_msg_block.MR32R2Nib1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R2Nib2           ", i_msg_block.MR32R2Nib2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R2Nib3           ", i_msg_block.MR32R2Nib3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R2Nib4           ", i_msg_block.MR32R2Nib4, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R2Nib5           ", i_msg_block.MR32R2Nib5, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R2Nib6           ", i_msg_block.MR32R2Nib6, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R2Nib7           ", i_msg_block.MR32R2Nib7, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R2Nib8           ", i_msg_block.MR32R2Nib8, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R2Nib9           ", i_msg_block.MR32R2Nib9, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R2Nib10          ", i_msg_block.MR32R2Nib10, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R2Nib11          ", i_msg_block.MR32R2Nib11, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R2Nib12          ", i_msg_block.MR32R2Nib12, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R2Nib13          ", i_msg_block.MR32R2Nib13, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R2Nib14          ", i_msg_block.MR32R2Nib14, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R2Nib15          ", i_msg_block.MR32R2Nib15, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R2Nib16          ", i_msg_block.MR32R2Nib16, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R2Nib17          ", i_msg_block.MR32R2Nib17, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R2Nib18          ", i_msg_block.MR32R2Nib18, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R2Nib19          ", i_msg_block.MR32R2Nib19, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R3Nib0           ", i_msg_block.MR32R3Nib0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R3Nib1           ", i_msg_block.MR32R3Nib1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R3Nib2           ", i_msg_block.MR32R3Nib2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R3Nib3           ", i_msg_block.MR32R3Nib3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R3Nib4           ", i_msg_block.MR32R3Nib4, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R3Nib5           ", i_msg_block.MR32R3Nib5, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R3Nib6           ", i_msg_block.MR32R3Nib6, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R3Nib7           ", i_msg_block.MR32R3Nib7, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R3Nib8           ", i_msg_block.MR32R3Nib8, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R3Nib9           ", i_msg_block.MR32R3Nib9, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R3Nib10          ", i_msg_block.MR32R3Nib10, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R3Nib11          ", i_msg_block.MR32R3Nib11, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R3Nib12          ", i_msg_block.MR32R3Nib12, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R3Nib13          ", i_msg_block.MR32R3Nib13, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R3Nib14          ", i_msg_block.MR32R3Nib14, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R3Nib15          ", i_msg_block.MR32R3Nib15, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R3Nib16          ", i_msg_block.MR32R3Nib16, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R3Nib17          ", i_msg_block.MR32R3Nib17, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R3Nib18          ", i_msg_block.MR32R3Nib18, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "MR32R3Nib19          ", i_msg_block.MR32R3Nib19, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7D0          ", i_msg_block.Reserved7D0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7D1          ", i_msg_block.Reserved7D1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7D2          ", i_msg_block.Reserved7D2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7D3          ", i_msg_block.Reserved7D3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7D4          ", i_msg_block.Reserved7D4, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7D5          ", i_msg_block.Reserved7D5, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7D6          ", i_msg_block.Reserved7D6, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7D7          ", i_msg_block.Reserved7D7, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7D8          ", i_msg_block.Reserved7D8, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7D9          ", i_msg_block.Reserved7D9, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7DA          ", i_msg_block.Reserved7DA, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7DB          ", i_msg_block.Reserved7DB, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7DC          ", i_msg_block.Reserved7DC, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7DD          ", i_msg_block.Reserved7DD, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7DE          ", i_msg_block.Reserved7DE, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7DF          ", i_msg_block.Reserved7DF, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7E0          ", i_msg_block.Reserved7E0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7E1          ", i_msg_block.Reserved7E1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7E2          ", i_msg_block.Reserved7E2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7E3          ", i_msg_block.Reserved7E3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7E4          ", i_msg_block.Reserved7E4, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7E5          ", i_msg_block.Reserved7E5, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7E6          ", i_msg_block.Reserved7E6, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7E7          ", i_msg_block.Reserved7E7, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7E8          ", i_msg_block.Reserved7E8, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7E9          ", i_msg_block.Reserved7E9, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7EA          ", i_msg_block.Reserved7EA, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7EB          ", i_msg_block.Reserved7EB, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7EC          ", i_msg_block.Reserved7EC, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7ED          ", i_msg_block.Reserved7ED, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7EE          ", i_msg_block.Reserved7EE, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7EF          ", i_msg_block.Reserved7EF, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7F0          ", i_msg_block.Reserved7F0, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7F1          ", i_msg_block.Reserved7F1, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7F2          ", i_msg_block.Reserved7F2, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7F3          ", i_msg_block.Reserved7F3, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7F4          ", i_msg_block.Reserved7F4, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7F5          ", i_msg_block.Reserved7F5, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7F6          ", i_msg_block.Reserved7F6, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7F7          ", i_msg_block.Reserved7F7, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7F8          ", i_msg_block.Reserved7F8, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7F9          ", i_msg_block.Reserved7F9, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7FA          ", i_msg_block.Reserved7FA, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7FB          ", i_msg_block.Reserved7FB, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7FC          ", i_msg_block.Reserved7FC, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7FD          ", i_msg_block.Reserved7FD, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7FE          ", i_msg_block.Reserved7FE, TARGTID);
    FAPI_INF("  .%s= 0x%02x; // " TARGTIDFORMAT, "Reserved7FF          ", i_msg_block.Reserved7FF, TARGTID);
    FAPI_INF("} // _PMU_SMB_DDR5_1D_t " TARGTIDFORMAT, TARGTID);
#endif
}

///
/// @brief Checks the FW revision in the message block
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_is_sim true if this is a simulation run
/// @param[in] i_msg_block_response the message block
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode check_fw_revision(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                    const uint8_t i_is_sim,
                                    const _PMU_SMB_DDR5_1D_t& i_msg_block_response)
{
    // If this is a simulation run, just exit out successfully, the version might not be correct
    if(i_is_sim)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Version corresponding with the M19 drop
    constexpr uint16_t EXPECTED_PMU_REVISION = PMU_REV;
    FAPI_ASSERT((i_msg_block_response.PmuRevision == EXPECTED_PMU_REVISION),
                fapi2::ODY_DRAMINIT_TRAINING_FW_MISMATCH()
                .set_PORT_TARGET(i_target)
                .set_MSG_FW_VERSION(i_msg_block_response.PmuRevision)
                .set_EXPECTED_FW_VERSION(EXPECTED_PMU_REVISION),
                TARGTIDFORMAT " DRAM training response's FW version does not match the expected FW version"
                " response version:0x%04x expected:0x%04x. Please update the FW",
                TARGTID, i_msg_block_response.PmuRevision, EXPECTED_PMU_REVISION);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
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
    bool l_firs_found = false;
    uint8_t l_is_sim = 0;
    FAPI_TRY( mss::attr::get_is_simulation(l_is_sim) );

    // First check for a mismatch between the Synopsys binary FW revision and the FW revision the code expects
    // A mismatch in the FW revision is a catastrophic error and needs to be handled by code and FW binary updates
    FAPI_TRY(check_fw_revision(i_target, l_is_sim, i_msg_block_response));

    // Check for catastrophic training failure. No need to check FIRs if training failed completely
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
    // Hostboot will consume the bad bits attribute in the memdiags procedure
    FAPI_TRY(mss::check::blame_firs<mss::mc_type::ODYSSEY>(i_target, l_firs_found));

    if (!l_firs_found)
    {
        FAPI_TRY(mss::record_bad_bits(i_target, l_interface));
    }

    FAPI_INF(TARGTIDFORMAT " DRAM training returned PASSING status", TARGTID);
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}


} // namespace phy
} // namespace ody
} // namespace mss
