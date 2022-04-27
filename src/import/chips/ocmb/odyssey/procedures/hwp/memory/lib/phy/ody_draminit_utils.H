/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/phy/ody_draminit_utils.H $ */
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
/// @file ody_draminit_utils.H
/// @brief Odyssey PHY draminit utility functions
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _ODY_DRAMINIT_UTILS_H_
#define _ODY_DRAMINIT_UTILS_H_

#include <fapi2.H>
#include <lib/phy/ody_snps_dram_train_msg_blk.H>

namespace mss
{
namespace ody
{
namespace phy
{

///
/// @class rcw_id
/// @brief Contains information for RCW's as processed from the SMBus messages
///
struct rcw_id
{
    // Note: the comments show the Synopsys mappings
    // The IBM data starts at bit 32 and increases from there
    // So a Synopsys mapping of 31:28 will be an IBM mapping of 32:35
    enum bit_mappings
    {
        CHANNEL_ID     = 32, // Synopsys 31:28
        CHANNEL_ID_LEN = 4,
        DIMM_ID        = 36, // Synopsys 27:24
        DIMM_ID_LEN    = 4,
        RCW_ID         = 40, // Synopsys 23:16
        RCW_ID_LEN     = 8,
        RCW_PAGE       = 48, // Synopsys 15: 8
        RCW_PAGE_LEN   = 8,
        RCW_VAL        = 56, // Synopsys  7: 0
        RCW_VAL_LEN    = 8,
    };

    rcw_id() = delete;

    ///
    /// @brief Reads in and processes the SMBus formatted message
    ///
    rcw_id(const fapi2::buffer<uint64_t>& i_mail) :
        iv_channel_id(0),
        iv_dimm_id(0),
        iv_rcw_id(0),
        iv_rcw_page(0),
        iv_rcw_val(0)
    {
        i_mail.extractToRight<CHANNEL_ID, CHANNEL_ID_LEN>(iv_channel_id)
        .extractToRight<DIMM_ID, DIMM_ID_LEN>(iv_dimm_id)
        .extractToRight<RCW_ID, RCW_ID_LEN>(iv_rcw_id)
        .extractToRight<RCW_PAGE, RCW_PAGE_LEN>(iv_rcw_page)
        .extractToRight<RCW_VAL, RCW_VAL_LEN>(iv_rcw_val);
    }

    ///
    /// @brief rcw_id default destructor
    ///
    ~rcw_id() = default;

    uint8_t iv_channel_id = 0;
    uint8_t iv_dimm_id = 0;
    uint8_t iv_rcw_id = 0;
    uint8_t iv_rcw_page = 0;
    uint8_t iv_rcw_val = 0;
};

///
/// @brief Initializes the protocol for mailbox interaction
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode init_mailbox_protocol(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

///
/// @brief Get the message passed through the mailbox protocol
/// @param[in] i_target the target on which to operate
/// @param[in] i_mode 16 bit or 32 bit to read major message or streaming & SMBus messages
/// @param[in] i_loop_count poll count for reading UCT_PROT_SHADOW.
/// @param[out] o_mail message read from the mailbox protocol.
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode get_mail (const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                            const uint8_t i_mode,
                            const uint64_t i_loop_count,
                            fapi2::buffer<uint64_t>& o_mail);

///
/// @brief Poll for mail to be available
/// @param[in] i_target the target on which to operate
/// @param[in] i_mailbox_poll_count poll count for reading UCT_PROT_SHADOW.
/// note: mode is set in the calling function. mail is returned based on that.
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode poll_for_message_available (const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint64_t i_mailbox_poll_count);

///
/// @brief reads the message after it is available
/// @param[in] i_target the target on which to operate
/// @param[in] i_mode 16 bit or 32 bit to read major message or streaming & SMBus messages
/// @param[out] o_mail message read from the mailbox protocol.
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode read_message(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                               const uint8_t i_mode,
                               fapi2::buffer<uint64_t>& o_mail);

//
/// @brief Acknowledges that mail is received
/// @param[in] i_target the target on which to operate
/// @param[in] i_mailbox_poll_count poll count for reading UCT_PROT_SHADOW.
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode acknowledge_mail (const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                    const uint64_t i_mailbox_poll_count);


///
/// @brief Polls the mail until completion message is received
/// @param[in] i_target the target on which to operate
/// @param[in] i_training_poll_count poll count for getting mail.
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode poll_for_completion(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                      const uint64_t i_training_poll_count);
///
/// @brief Checks the completion condition for training
/// @param[in] i_mail mail content to check for completion
/// @return True if mail content is same as one of the completion values , false otherwise
///
bool check_for_completion(const fapi2::buffer<uint64_t>& i_mail);

///
/// @brief Configures the DRAM training message block
/// @param[in] i_target the memory port on which to operate
/// @param[out] o_struct the message block
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode configure_dram_train_message_block(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        PMU_SMB_DDR5U_1D_t& o_struct);

///
/// @brief Processes a streaming message from the mailbox protocol
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode process_streaming_message(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

///
/// @brief Processes an SMBus message request (aka runs an RCW via i2c)
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note This function only handles the message interface for right now
/// TODO:ZEN:MST-1541 Add DDR5 RCW writes using i2c when SMBus message is received
///
fapi2::ReturnCode process_smbus_message(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

///
/// @brief Starts the firmware draminit training
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note Assumes that the firmware binaries and data structures are loaded appropriately
///
fapi2::ReturnCode start_training(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

///
/// @brief Stops the ARC processor
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode stall_arc_processor(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

///
/// @brief Cleans up from the firmware draminit training
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note puts the processor into a stall state
///
fapi2::ReturnCode cleanup_training(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

///
/// @brief constants for mailbox interaction
///
enum mailbox_consts
{
    // Initialization of protocol
    PROTOCOL_INIT = 1,

    // Responses received as major message
    SUCCESSFUL_COMPLETION = 0x07,
    FAILED_COMPLETION = 0xFF,
    STREAMING_MSG = 0x08,
    SMBUS_MSG = 0x50,
    SMBUS_SYNC = 0x51,

    // Mode for reading major message vs streaming msg/SMBus msg
    MAJOR_MSG_MODE = 16,
    STREAMING_SMBUS_MSG_MODE = 32,

    // Register data for different messages
    MESSAGE_AVAILABLE = 0,
    RECEPTION_ACK = 0,
    ACK_MESSAGE = 1,
};

/// @brief Prints the fields from the message block structure
/// @param[in] i_target the target on which to operate
/// @param[in] i_msg_blk message block structure
/// @return None
///
void display_msg_block(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                       const _PMU_SMB_DDR5_1D_t& i_msg_block);



} // namespace phy
} // namespace ody
} // namespace mss
#endif
