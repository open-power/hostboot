/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/exp_draminit_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
#include <lib/shared/exp_defaults.H>
#include <lib/dimm/exp_rank.H>
#include <lib/shared/exp_consts.H>
#include <lib/dimm/exp_kind.H>
#include <exp_data_structs.H>
#include <mss_generic_attribute_getters.H>
#include <mss_explorer_attribute_getters.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/mss_buffer_utils.H>
#include <lib/phy/exp_train_display.H>
#include <lib/phy/exp_train_handler.H>
#include <lib/exp_attribute_accessors_manual.H>
#include <lib/inband/exp_inband.H>

namespace mss
{
namespace exp
{

///
/// @brief Phy init mode for host_fw_command struct
///
enum phy_init_mode
{
    NORMAL = 0,
    EYE_CAPTURE_STEP_1 = 1,
    EYE_CAPTURE_STEP_2 = 2,
    RESET = 3,
};

///
/// @brief defines the supported DIMM types in Explorer
///
enum msdg_dimm_types
{
    MSDG_UDIMM      = 0x0000,
    MSDG_RDIMM      = 0x0001,
    MSDG_LRDIMM     = 0x0002,
    MSDG_MDS_LRDIMM = 0x0003,
    MSDG_MDS        = 0x0004
};

///
/// @brief defines the supported DRAM data width in Explorer
///
enum msdg_dram_data_width
{
    MSDG_X4 = 0x0004,
    MSDG_X8 = 0x0008,
    MSDG_X16 = 0x0010,
};

///
/// @brief Defines CS encoding mode
///
enum msdg_cs_encode_mode
{
    MSDG_QUAD_ENCODE_MODE = 1,
    MSDG_DUAL_DIRECT_MODE = 0,
};

///
/// @brief defines the valid 3DS stack in Explorer
///
enum msdg_height_3DS
{
    MSDG_SDP = 0x0000,
    MSDG_DDP_QDP = 0x0002,
    MSDG_3DS = 0x0004,
};

///
/// @brief defines the flags for valid and invalid values
///
enum msdg_flags
{
    MSDG_VALID = 1,
    MSDG_INVALID = 0,
    MSDG_TRUE = 1,
    MSDG_FALSE = 0,
};

///
/// @brief defines the ranks
///
enum msdg_ranks
{
    MSDG_1RANK = 0x0001,
    MSDG_2RANK = 0x0002,
    MSDG_4RANK = 0x0004,
    MSDG_NO_RANK = 0x0000,
};

///
/// @brief defines the value for initialization
///
enum msdg_height
{
    MSDG_PLANAR = 0x0000,
    MSDG_H2 = 0x0002,
    MSDG_H4 = 0x0004,
    MSDG_H8 = 0x0008,
};

///
/// @brief defines variables for Enable/Disable
///
enum msdg_enable
{
    MSDG_ENABLE = 0x0001,
    MSDG_DISABLE = 0x0000,
};

///
/// @brief defines fields for the ODT RD/WR params
///
enum odt_fields
{
    R2_FLD_LENGTH = 2, // R2 = 2 rank (normal / 2 rank mode: makes use of 2 bits)
    R4_FLD_LENGTH = 4, // R4 = 4 rank (4 rank mode: makes use of 4 bits)
    ODT_MIDPOINT = 4,
    R4_SHIFT = 2,
    RANK3 = 12,
    RANK2 = 8,
    RANK1 = 4,
    RANK0 = 0,
};

///
/// @class phy_param_info
/// @brief Structure to hold common user_input_msdg information
///
struct phy_param_info
{
    size_t iv_size;
    uint32_t iv_crc;
};

///
/// @brief Helper to check bootleg version
/// @param[in] i_fw_version FW version
///
inline bool is_new_fw_msdg_supported(const uint32_t i_fw_version)
{
    return ( (i_fw_version > fw_version::FW_VER_OLD) || (i_fw_version == fw_version::FW_VER_BOOTLEG) );
}

///
/// @brief Check that the rsp_data size returned from the PHY_INIT command matches the expected size
///
/// @param[in] i_target OCMB target
/// @param[in] i_actual_size size enum expected for the given phy init mode
/// @param[in] i_mode phy init mode. Expected to be a valid enum value since we asserted as such in exp_draminit.C
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff matching, else MSS_EXP_INVALID_PHY_INIT_RSP_DATA_LENGTH
///
fapi2::ReturnCode check_rsp_data_size(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint16_t i_actual_size,
    const phy_init_mode i_mode);

///
/// @brief Perform normal host FW phy init
///
/// @param[in] i_target OCMB target
/// @param[in] i_phy_info phy information of interest
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode host_fw_phy_normal_init(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const phy_param_info& i_phy_info);

///
/// @brief Process return codes from PHY init with eye capture operations
///
/// @param[in] i_target OCMB target
/// @param[in] i_response_1 response struct for EYE_CAPTURE_STEP_1
/// @param[in] i_response_2 response struct for EYE_CAPTURE_STEP_2
/// @param[in] i_response_1_rc response from check_host_fw_response from EYE_CAPTURE_STEP_1
/// @param[in] i_response_2_rc response from check_host_fw_response from EYE_CAPTURE_STEP_2
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else an error from above as defined in the function algorithm
/// @note return codes are passed by value, caller should not expect these to change
///
fapi2::ReturnCode process_eye_capture_return_codes(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const user_2d_eye_response_1_msdg& i_response_1,
        const user_2d_eye_response_2_msdg& i_response_2,
        fapi2::ReturnCode i_response_1_rc,
        fapi2::ReturnCode i_response_2_rc);

///
/// @brief Send PHY init command given the provided phy mode and CRC
///
/// @param[in] i_target OCMB target
/// @param[in] i_phy_info phy information of interest
/// @param[in] i_phy_init_mode normal / eye capture step 1 or 2
/// @param[out] host_fw_command_struct used for initialization
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode send_host_phy_init_cmd(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const phy_param_info& i_phy_info,
        const uint8_t i_phy_init_mode,
        host_fw_command_struct& o_cmd);

///
/// @brief Get and check the host fw response from the explorer
/// @param[in] i_target OCMB chip
/// @param[in] i_cmd host_fw_command_struct used to generate the response
/// @param[out] o_rsp_data response data
/// @param[out] o_rc return code from mss::exp::check::response()
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode check_host_fw_response(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        host_fw_command_struct& i_cmd,
        std::vector<uint8_t>& o_rsp_data,
        fapi2::ReturnCode& o_rc);

///
/// @brief Reads and displays the normal draminit training response
///
/// @param[in] i_target OCMB target
/// @param[in] i_resp_data RESP data
/// @param[in] i_rc return code from checking response
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode read_and_display_normal_training_repsonse(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const std::vector<uint8_t> i_resp_data,
    const fapi2::ReturnCode i_rc);

///
/// @brief Reads and displays the user 2d eye response 1
///
/// @tparam T response struct
/// @param[in] i_target OCMB target
/// @param[in] i_resp_data RESP data
/// @param[out] o_rc return code from checking response
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff success
///
template <typename T>
fapi2::ReturnCode read_and_display_user_2d_eye_response(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const std::vector<uint8_t> i_resp_data,
    T& o_train_response)
{
    // Proccesses the response data
    FAPI_TRY(mss::exp::read_user_2d_eye_response<T>(i_target, i_resp_data, o_train_response),
             "Failed read_training_response for %s", mss::c_str(i_target));

    // Displays the training response
    FAPI_TRY(mss::exp::train::display_user_2d_eye_info<T>(i_target, o_train_response));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to set rc response attrs
/// @param[in] i_target the fapi2 OCMB target
/// @param[in] i_rc_resp the Explorer rc response
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode set_rc_resp_attrs(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                    const user_response_rc_msdg_t& i_rc_resp);

///
/// @brief Helper function to set rc response attrs
/// @param[in] i_target the fapi2 OCMB target
/// @param[in] i_read_display_response_1_rc ReturnCode for display_response_1
/// @param[in] i_read_display_response_2_rc ReturnCode for display_response_2
/// @param[in] i_response_1 the user_2d_eye_response_1_msdg
/// @param[in] i_response_2 user_2d_eye_response_2_msdg
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode set_rc_resp_attrs(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                    const fapi2::ReturnCode& i_read_display_response_1_rc,
                                    const fapi2::ReturnCode& i_read_display_response_2_rc,
                                    const user_2d_eye_response_1_msdg& i_response_1,
                                    const user_2d_eye_response_2_msdg& i_response_2);

///
/// @brief Perform normal host FW phy init
/// @param[in] i_target OCMB target
/// @param[in] i_phy_info phy information of interest
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode host_fw_phy_init(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                   const uint8_t i_phy_init_mode);

///
/// @brief Initialize user_input_msdg_t and copy to Explorer internal buffer
/// @param[in] i_target an explorer chip
/// @param[out] o_phy_params phy initialization struct
/// @param[out] o_phy_data phy information we want to pass around
/// @return FAPI2_RC_SUCCESS iff okay
/// @note attr for fw_version will select proper initialization at run-time
///
fapi2::ReturnCode init_phy_params(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                  user_input_msdg& o_phy_params,
                                  phy_param_info& o_phy_info);

///
/// @brief Initialize user_input_msdg_t and copy to Explorer internal buffer
/// @param[in] i_target an explorer chip
/// @param[out] o_phy_data phy information of interest
/// @return FAPI2_RC_SUCCESS iff okay
/// @note attr for fw_version will select proper initialization at run-time
///
fapi2::ReturnCode init_phy_params(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                  phy_param_info& o_phy_data);

///
/// @brief Perform host FW phy init with eye capture
/// @param[in] i_target OCMB target
/// @param[in] i_phy_params phy initialization resp. struct
/// @param[in] i_phy_info phy information of interest
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
/// @note the goal here is to attempt to send both phy_inits even
/// in the event of a bad return code from the read & display
///
fapi2::ReturnCode host_fw_phy_init_with_eye_capture(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const user_input_msdg& i_phy_params,
    const phy_param_info& i_phy_info);

///
/// @brief host_fw_command_struct structure setup
/// @param[in] i_target the OCMB being acted upon
/// @param[in] i_cmd_data_crc the command data CRC
/// @param[in] i_cmd_length the length of the command present in the data buffer (if any)
/// @param[in] i_phy_init_mode PHY init mode
/// @param[out] o_cmd the command parameters to set
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode setup_cmd_params(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint32_t i_cmd_data_crc,
    const uint32_t i_cmd_length,
    const uint8_t i_phy_init_mode,
    host_fw_command_struct& o_cmd);

///
/// @class user_input_msdg_attrs
/// @brief Structure of user_input_msdg variables
///
struct user_input_msdg_attrs
{
    ///
    /// Declare variables to be used
    ///
    uint32_t iv_version_number;
    uint8_t iv_dimm_type[MAX_DIMM_PER_PORT];
    uint8_t iv_chip_select[MAX_DIMM_PER_PORT];
    uint8_t iv_dram_data_width[MAX_DIMM_PER_PORT];
    uint16_t iv_height_3DS[MAX_DIMM_PER_PORT];
    uint16_t iv_dbyte_macro[MAX_DIMM_PER_PORT];
    uint32_t iv_nibble[MAX_DIMM_PER_PORT];
    uint8_t iv_addr_mirror[MAX_DIMM_PER_PORT];
    uint8_t iv_column_width[MAX_DIMM_PER_PORT];
    uint8_t iv_row_width[MAX_DIMM_PER_PORT];
    uint32_t iv_spdcl_support;
    uint16_t iv_taa_min;
    uint8_t iv_rank4_mode[MAX_DIMM_PER_PORT];
    uint16_t iv_encoded_quadcs;
    uint8_t iv_ddp_compatible[MAX_DIMM_PER_PORT];
    uint8_t iv_tsv8h[MAX_DIMM_PER_PORT];
    uint8_t iv_mram_support[MAX_DIMM_PER_PORT];
    uint8_t iv_mdssupport;
    uint8_t iv_num_pstate[MAX_DIMM_PER_PORT];
    uint64_t iv_frequency;
    uint8_t iv_odt_impedance[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];
    uint16_t iv_drv_impedance_pu[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];
    uint16_t iv_drv_impedance_pd[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];
    uint8_t iv_slew_rate[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];
    uint8_t iv_atx_impedance[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];
    uint8_t iv_atx_slew_rate[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];
    uint8_t iv_ck_tx_impedance[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];
    uint8_t iv_ck_tx_slew_rate[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];
    uint8_t iv_alert_odt_impedance[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];
    uint8_t iv_dram_rtt_nom[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];
    uint8_t iv_dram_rtt_wr[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];
    uint8_t iv_dram_rtt_park[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];
    uint8_t iv_dram_dic[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];
    uint8_t iv_dram_preamble[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];
    uint8_t iv_phy_equalization[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];
    uint8_t iv_init_vref_dq[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];
    uint8_t iv_init_phy_vref[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];
    uint8_t iv_odt_wr_map_cs[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];
    uint8_t iv_odt_rd_map_cs[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];
    uint8_t iv_geardown_mode[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];
    uint8_t iv_ca_latency_adder[MAX_DIMM_PER_PORT];
    uint8_t iv_bist_cal_mode[MAX_DIMM_PER_PORT];
    uint8_t iv_bist_ca_parity_latency[MAX_DIMM_PER_PORT];
    uint16_t iv_rcd_dic[MAX_DIMM_PER_PORT];
    uint16_t iv_rcd_voltage_ctrl[MAX_DIMM_PER_PORT];
    uint8_t iv_f0rc7x[MAX_DIMM_PER_PORT];
    uint8_t iv_f1rc00[MAX_DIMM_PER_PORT];
    uint16_t iv_rcd_slew_rate[MAX_DIMM_PER_PORT];
    uint8_t iv_dfimrl_ddrclk;
    uint8_t iv_atxdly_a[DRAMINIT_NUM_ADDR_DELAYS];
    uint8_t iv_atxdly_b[DRAMINIT_NUM_ADDR_DELAYS];
    uint8_t iv_f1rc1x[MAX_DIMM_PER_PORT];
    uint8_t iv_f1rc2x[MAX_DIMM_PER_PORT];
    uint8_t iv_f1rc3x[MAX_DIMM_PER_PORT];
    uint8_t iv_f1rc4x[MAX_DIMM_PER_PORT];
    uint8_t iv_f1rc5x[MAX_DIMM_PER_PORT];
    uint8_t iv_f1rc6x[MAX_DIMM_PER_PORT];
    uint8_t iv_f1rc7x[MAX_DIMM_PER_PORT];
};

///
/// @class phy_params
/// @brief Provides storage and methods for setting up user_input_msdg structure
///
class phy_params
{
    private:

        fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> iv_target;
        user_input_msdg_attrs iv_attrs_params;
        std::vector<mss::rank::info<>> iv_rank_info;

        ///
        /// @brief Set the rank-based phy field from the attribute
        ///
        /// @param[in] i_phy_param_ranks array of pointers to the rank fields to be filled in
        /// @param[in] i_phy_param_attr pointer to the iv array indexed by dimm & rank
        /// @note this function assumes i_phy_param_ranks is properly populated with 4 fields (1 per phy rank)
        ///
        void set_phy_field_by_rank(const std::vector<uint16_t*>& i_phy_param_ranks,
                                   const uint8_t (&i_phy_param_attr)[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM]) const
        {
            // First, zero everything out
            for (uint8_t l_rank = 0; l_rank < i_phy_param_ranks.size(); ++l_rank)
            {
                *i_phy_param_ranks[l_rank] = 0;
            }

            // For each rank, the phy rank value (0-4) is what needs to be filled in for draminit
            // This maps to the field corresponding to the ATTR index value
            // indexed by the rank's dimm index and dimm rank
            for (const auto& l_rank : iv_rank_info)
            {
                const uint8_t l_dimm_index = mss::index(l_rank.get_dimm_target());
                const uint8_t l_dimm_rank = l_rank.get_dimm_rank();
                *i_phy_param_ranks[l_rank.get_phy_rank()] = i_phy_param_attr[l_dimm_index][l_dimm_rank];
            }
        }

        ///
        /// @brief Maps the ODT RD/WR attributes to the form needed for exp_draminit
        ///
        /// @param[in] i_odt_rd_wr_attr iv array indexed by dimm & rank
        /// @param[out] o_odt_buffer buffer to populate
        ///
        fapi2::ReturnCode populate_odt_buffer(const uint8_t (&i_odt_rd_wr_attr)[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM],
                                              fapi2::buffer<uint16_t>& o_odt_buffer) const
        {
            // TK - Update code for encoded quad CS, waiting on SPD
            // static constexpr bool ENCODED_QUAD_CS_ENABLE = true;

            // Const vector to map phy ranks to their buffer offset position
            const std::vector<uint8_t> l_buffer_rank_offset =
            {
                odt_fields::RANK0,
                odt_fields::RANK1,
                odt_fields::RANK2,
                odt_fields::RANK3,
            };

            for (const auto& l_rank : iv_rank_info)
            {
                if (iv_attrs_params.iv_rank4_mode[0] == fapi2::ENUM_ATTR_MEM_EFF_FOUR_RANK_MODE_ENABLE)
                {
                    // A & B separate. We need to do a bit if shifting from our attribute
                    // our attribute is aligned XX00YY00 but we want XXYY0000
                    // The attr must be populated this way, as we only have 4 ODTs and they are aligned as such
                    // Otherwise, we have problems on the SPD/decoder side
                    // where XX is A0A1 (bits 0,1) and YY is B0B1 (bits 4,5)

                    // From MCHP spec:
                    // OdtRdMapCs BIT [1:0] ODT_A[1:0] value when reading to rank 0
                    // OdtRdMapCs BIT [3:2] ODT_B[1:0] value when reading to rank 0
                    // ...

                    const auto OFFSET = l_buffer_rank_offset[l_rank.get_phy_rank()];
                    const auto DIMM_RANK = l_rank.get_dimm_rank();
                    const auto DIMM_INDEX = mss::index(l_rank.get_dimm_target());

                    uint8_t l_data = 0;

                    // l_data populated as such:
                    // XX000000 || 0000YY00 << 2
                    l_data = i_odt_rd_wr_attr[DIMM_INDEX][DIMM_RANK];
                    l_data |= (i_odt_rd_wr_attr[DIMM_INDEX][DIMM_RANK] << odt_fields::R4_SHIFT);

                    // Sanity check: bitwise and the relevant bits
                    l_data &= 0b11110000;

                    // Now we have XXYY0000
                    // Insert into the buffer
                    FAPI_TRY(o_odt_buffer.insert(l_data, OFFSET, odt_fields::R4_FLD_LENGTH));
                }

                else
                {
                    // For DDIMM:
                    // A & B together. B0 (ODT2) mirrors A0 (ODT0), B1 (ODT3) mirrors A1 (ODT1)
                    // ODTA/B [1:0] == [ODT3/1:ODT2/0]

                    // From MCHP spec:
                    // OdtRdMapCs BIT [1:0] ODTA/B[1:0] value when reading to rank 0
                    // So it already accounts for any mirroring, we just need to plop in the value

                    const auto OFFSET = l_buffer_rank_offset[l_rank.get_phy_rank()];
                    const auto DIMM_RANK = l_rank.get_dimm_rank();
                    const auto DIMM_INDEX = mss::index(l_rank.get_dimm_target());

                    uint8_t l_data = 0;
                    l_data = i_odt_rd_wr_attr[DIMM_INDEX][DIMM_RANK];

                    // Finally, put it back

                    // Insert l_data (attribute) from the corresponding dimm's position:
                    // DIMM0 (ODT0, ODT1) (bits 0,1) or DIMM1 ODT0, ODT1 (bits 4,5) (though DIMM1 probably wouldn't be applicable here)
                    // at the offset to match the draminit field.
                    //
                    FAPI_TRY(o_odt_buffer.insert(l_data, OFFSET, odt_fields::R2_FLD_LENGTH, DIMM_INDEX * odt_fields::ODT_MIDPOINT));
                }
            }

            // Rest of the buffer should already be zeroed from declaration
            // Our attribute values come in left aligned (LSB left), our buffers are left aligned, but MCHP wants things right aligned:
            // (rank0 == [1:0], rank1 == [5:4])
            // So we can set it up from the buffer perspective, but then flip the whole buffer, getting the values back to their
            // correct form (MSB right aligned) in addition to flipping the rank positions to their expected locations
            o_odt_buffer.reverse();

        fapi_try_exit:
            return fapi2::current_err;
        }

    public:

        /// default constructor is deleted
        phy_params() = delete;

        ///
        /// @brief Constructor to fetch attributes
        ///
        /// @brief fetch the attributes and initialize it to the params
        /// @param[in] i_target the fapi2 target
        /// @param[out] ReturnCode to report error in class construction
        ///
        phy_params(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                   fapi2::ReturnCode& o_rc):
            iv_target(i_target)
        {
            uint32_t l_fw_version = 0;
            uint8_t l_master_ranks[MAX_DIMM_PER_PORT] = {};

            FAPI_TRY(mss::get_booted_fw_version(mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(iv_target), l_fw_version));
            FAPI_TRY(mss::attr::get_num_master_ranks_per_dimm(i_target, l_master_ranks));

            {
                // We're in quad encoded mode IF
                // 1) 4R per DIMM
                // 2) we have an RCD
                bool l_has_rcd = false;
                const bool l_4r = l_master_ranks[0] == fapi2::ENUM_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM_4R;

                FAPI_TRY(mss::dimm::has_rcd<mss::mc_type::EXPLORER>(i_target, l_has_rcd));
                iv_attrs_params.iv_encoded_quadcs = (l_has_rcd && l_4r) ? MSDG_QUAD_ENCODE_MODE : MSDG_DUAL_DIRECT_MODE;
            }

            if (is_new_fw_msdg_supported(l_fw_version))
            {
                iv_attrs_params.iv_version_number = NEW_DRAMINIT_STRUCTURE_VERSION;
            }
            else
            {
                iv_attrs_params.iv_version_number = OLD_DRAMINIT_STRUCTURE_VERSION;
            }

            FAPI_TRY(mss::rank::ranks_on_port(i_target, iv_rank_info));
            // Fetch attributes and populate the member variables
            FAPI_TRY(mss::attr::get_dimm_type(i_target, iv_attrs_params.iv_dimm_type));
            FAPI_TRY(mss::attr::get_dimm_ranks_configed(i_target, iv_attrs_params.iv_chip_select));
            FAPI_TRY(mss::attr::get_dram_width(i_target, iv_attrs_params.iv_dram_data_width));
            FAPI_TRY(mss::attr::get_3ds_height(i_target, iv_attrs_params.iv_height_3DS));
            FAPI_TRY(mss::attr::get_byte_enables(i_target, iv_attrs_params.iv_dbyte_macro));
            FAPI_TRY(mss::attr::get_nibble_enables(i_target, iv_attrs_params.iv_nibble));
            FAPI_TRY(mss::attr::get_exp_dram_address_mirroring(i_target, iv_attrs_params.iv_addr_mirror));
            FAPI_TRY(mss::attr::get_dram_column_bits(i_target, iv_attrs_params.iv_column_width));
            FAPI_TRY(mss::attr::get_dram_row_bits(i_target, iv_attrs_params.iv_row_width));
            FAPI_TRY(mss::attr::get_exp_spd_cl_supported(i_target, iv_attrs_params.iv_spdcl_support));
            FAPI_TRY(mss::attr::get_exp_spd_taa_min(i_target, iv_attrs_params.iv_taa_min));
            FAPI_TRY(mss::attr::get_four_rank_mode(i_target, iv_attrs_params.iv_rank4_mode));
            FAPI_TRY(mss::attr::get_ddp_compatibility(i_target, iv_attrs_params.iv_ddp_compatible));
            FAPI_TRY(mss::attr::get_tsv_8h_support(i_target, iv_attrs_params.iv_tsv8h));
            FAPI_TRY(mss::attr::get_mram_support(i_target, iv_attrs_params.iv_mram_support));
            FAPI_TRY(mss::attr::get_dram_mds(i_target, iv_attrs_params.iv_mdssupport));
            FAPI_TRY(mss::attr::get_pstates(i_target, iv_attrs_params.iv_num_pstate));
            FAPI_TRY(mss::attr::get_freq(i_target, iv_attrs_params.iv_frequency));
            FAPI_TRY(mss::attr::get_si_mc_rcv_imp_dq_dqs(i_target, iv_attrs_params.iv_odt_impedance));
            FAPI_TRY(mss::attr::get_si_mc_drv_imp_dq_dqs_pull_up(i_target, iv_attrs_params.iv_drv_impedance_pu));
            FAPI_TRY(mss::attr::get_si_mc_drv_imp_dq_dqs_pull_down(i_target, iv_attrs_params.iv_drv_impedance_pd));
            FAPI_TRY(mss::attr::get_si_mc_drv_slew_rate_dq_dqs(i_target, iv_attrs_params.iv_slew_rate));
            FAPI_TRY(mss::attr::get_si_mc_drv_imp_cmd_addr(i_target, iv_attrs_params.iv_atx_impedance));
            FAPI_TRY(mss::attr::get_si_mc_drv_slew_rate_cmd_addr(i_target, iv_attrs_params.iv_atx_slew_rate));
            FAPI_TRY(mss::attr::get_si_mc_drv_imp_clk(i_target, iv_attrs_params.iv_ck_tx_impedance));
            FAPI_TRY(mss::attr::get_si_mc_drv_slew_rate_clk(i_target, iv_attrs_params.iv_ck_tx_slew_rate));
            FAPI_TRY(mss::attr::get_si_mc_rcv_imp_alert_n(i_target, iv_attrs_params.iv_alert_odt_impedance));
            FAPI_TRY(mss::attr::get_si_dram_rtt_nom(i_target, iv_attrs_params.iv_dram_rtt_nom));
            FAPI_TRY(mss::attr::get_si_dram_rtt_wr(i_target, iv_attrs_params.iv_dram_rtt_wr));
            FAPI_TRY(mss::attr::get_si_dram_rtt_park(i_target, iv_attrs_params.iv_dram_rtt_park));
            FAPI_TRY(mss::attr::get_si_dram_drv_imp_dq_dqs(i_target, iv_attrs_params.iv_dram_dic));
            FAPI_TRY(mss::attr::get_si_dram_preamble(i_target, iv_attrs_params.iv_dram_preamble));
            FAPI_TRY(mss::attr::get_si_mc_rcv_eq_dq_dqs(i_target, iv_attrs_params.iv_phy_equalization));
            FAPI_TRY(mss::attr::get_exp_init_vref_dq(i_target, iv_attrs_params.iv_init_vref_dq));
            FAPI_TRY(mss::attr::get_exp_init_phy_vref(i_target, iv_attrs_params.iv_init_phy_vref));
            FAPI_TRY(mss::attr::get_si_odt_wr(i_target, iv_attrs_params.iv_odt_wr_map_cs));
            FAPI_TRY(mss::attr::get_si_odt_rd(i_target, iv_attrs_params.iv_odt_rd_map_cs));
            FAPI_TRY(mss::attr::get_si_geardown_mode(i_target, iv_attrs_params.iv_geardown_mode));
            FAPI_TRY(mss::attr::get_dimm_ddr4_f0rc0f(i_target, iv_attrs_params.iv_ca_latency_adder));
            FAPI_TRY(mss::attr::get_cs_cmd_latency(i_target, iv_attrs_params.iv_bist_cal_mode));
            FAPI_TRY(mss::attr::get_ca_parity_latency(i_target, iv_attrs_params.iv_bist_ca_parity_latency));
            FAPI_TRY(mss::attr::get_exp_rcd_dic(i_target, iv_attrs_params.iv_rcd_dic));
            FAPI_TRY(mss::attr::get_exp_rcd_voltage_ctrl(i_target, iv_attrs_params.iv_rcd_voltage_ctrl));
            FAPI_TRY(mss::attr::get_dimm_ddr4_f0rc7x(i_target, iv_attrs_params.iv_f0rc7x));
            FAPI_TRY(mss::attr::get_dimm_ddr4_f1rc00(i_target, iv_attrs_params.iv_f1rc00));
            FAPI_TRY(mss::attr::get_exp_rcd_slew_rate(i_target, iv_attrs_params.iv_rcd_slew_rate));
            FAPI_TRY(mss::attr::get_exp_dfimrl_clk(i_target, iv_attrs_params.iv_dfimrl_ddrclk));
            FAPI_TRY(mss::attr::get_exp_atxdly_a(i_target, iv_attrs_params.iv_atxdly_a));
            FAPI_TRY(mss::attr::get_exp_atxdly_b(i_target, iv_attrs_params.iv_atxdly_b));
            FAPI_TRY(mss::attr::get_ddr4_f1rc1x(i_target, iv_attrs_params.iv_f1rc1x));
            FAPI_TRY(mss::attr::get_ddr4_f1rc2x(i_target, iv_attrs_params.iv_f1rc2x));
            FAPI_TRY(mss::attr::get_ddr4_f1rc3x(i_target, iv_attrs_params.iv_f1rc3x));
            FAPI_TRY(mss::attr::get_ddr4_f1rc4x(i_target, iv_attrs_params.iv_f1rc4x));
            FAPI_TRY(mss::attr::get_ddr4_f1rc5x(i_target, iv_attrs_params.iv_f1rc5x));
            FAPI_TRY(mss::attr::get_ddr4_f1rc6x(i_target, iv_attrs_params.iv_f1rc6x));
            FAPI_TRY(mss::attr::get_ddr4_f1rc7x(i_target, iv_attrs_params.iv_f1rc7x));

        fapi_try_exit:
            o_rc = fapi2::current_err;
        }


        ///
        /// @brief Constructor
        ///
        /// @brief Set params as per the value initialized (useful for testing)
        /// @param[in] i_target the fapi2 target
        /// @param[in] i_phy_param_attrs explorer specific data structure
        /// @param[in] i_rank_info rank information
        ///
        phy_params(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                   const user_input_msdg_attrs& i_phy_param_attrs,
                   const std::vector<mss::rank::info<>> i_rank_info):
            iv_target(i_target), iv_attrs_params(i_phy_param_attrs), iv_rank_info(i_rank_info)
        {}

        ///
        /// @brief default copy assignment operator
        ///
        phy_params& operator= (const phy_params&) = default;

        ///
        /// @brief default copy constructor
        ///
        phy_params(const phy_params&) = default;

        ///
        /// @brief default move assignment operator
        ///
        phy_params& operator= (phy_params&&) = default;

        ///
        /// @brief default move constructor
        ///
        phy_params(phy_params&&) = default;

        ///
        /// @brief default dtor
        ///
        ~phy_params() = default;

        ///
        /// @brief user_input_msdg structure setup for parameter DimmType
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_DimmType(user_input_msdg& io_phy_params) const
        {
            switch (iv_attrs_params.iv_dimm_type[0])
            {
                case fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_RDIMM:
                    io_phy_params.iv_user_msdg_upto_ver397559.DimmType = MSDG_RDIMM;
                    break;

                // DDIMM can either have an unregistered MC to DRAM interface (1U/2U) or RCD (4U)
                case fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_DDIMM:
                    {
                        bool l_has_rcd = false;

                        FAPI_TRY(mss::dimm::has_rcd<mss::mc_type::EXPLORER>(iv_target, l_has_rcd));
                        io_phy_params.iv_user_msdg_upto_ver397559.DimmType = l_has_rcd ? MSDG_RDIMM : MSDG_UDIMM;
                    }
                    break;

                case fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_UDIMM:
                    io_phy_params.iv_user_msdg_upto_ver397559.DimmType = MSDG_UDIMM;
                    break;

                case fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_LRDIMM:
                    io_phy_params.iv_user_msdg_upto_ver397559.DimmType = MSDG_LRDIMM;
                    break;

                case fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_MDS_LRDIMM:
                    io_phy_params.iv_user_msdg_upto_ver397559.DimmType = MSDG_MDS_LRDIMM;
                    break;

                case fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_MDS:
                    io_phy_params.iv_user_msdg_upto_ver397559.DimmType = MSDG_MDS;
                    break;

                default:
                    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(iv_target);
                    FAPI_ASSERT(false,
                                fapi2::MSS_EXP_DRAMINIT_UNSUPPORTED_DIMM_TYPE().
                                set_OCMB_TARGET(l_ocmb).
                                set_PORT(iv_target).
                                set_TYPE(iv_attrs_params.iv_dimm_type[0]),
                                "%s DIMM0 is not a supported DIMM type (%d)",
                                mss::c_str(iv_target), iv_attrs_params.iv_dimm_type[0]);
                    break;
            }

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief user_input_msdg structure setup for parameter CsPresent
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_CsPresent(user_input_msdg& io_phy_params) const
        {
            fapi2::buffer<uint8_t> l_cs_present(iv_attrs_params.iv_chip_select[0]);

            // Flip buffer (Needs to be right aligned, currently 0bXXXX0000)
            l_cs_present.reverse();

            // Now extend to 16 bits for phy_params struct
            io_phy_params.iv_user_msdg_upto_ver397559.CsPresent = static_cast<uint16_t>(l_cs_present);

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief user_input_msdg structure setup for parameter DramDataWidth
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_DramDataWidth(user_input_msdg& io_phy_params) const
        {
            switch (iv_attrs_params.iv_dram_data_width[0])
            {
                case fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X4:
                    io_phy_params.iv_user_msdg_upto_ver397559.DramDataWidth = MSDG_X4;
                    break;

                case fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X8:
                    io_phy_params.iv_user_msdg_upto_ver397559.DramDataWidth = MSDG_X8;
                    break;

                case fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X16:
                    io_phy_params.iv_user_msdg_upto_ver397559.DramDataWidth = MSDG_X16;
                    break;

                default:
                    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(iv_target);
                    FAPI_ASSERT(false,
                                fapi2::MSS_EXP_DRAMINIT_UNSUPPORTED_DRAM_WIDTH().
                                set_OCMB_TARGET(l_ocmb).
                                set_PORT(iv_target).
                                set_DATA_WIDTH(iv_attrs_params.iv_dram_data_width[0]),
                                "%s DRAM Data Width of DIMM0 is not a supported (%d)",
                                mss::c_str(iv_target), iv_attrs_params.iv_dram_data_width[0]);
                    break;
            }

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief user_input_msdg structure setup for parameter Height3DS
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_Height3DS(user_input_msdg& io_phy_params) const
        {
            switch (iv_attrs_params.iv_height_3DS[0])
            {
                case fapi2::ENUM_ATTR_MEM_3DS_HEIGHT_PLANAR:
                    io_phy_params.iv_user_msdg_upto_ver397559.Height3DS = MSDG_PLANAR;
                    break;

                case fapi2::ENUM_ATTR_MEM_3DS_HEIGHT_H2:
                    io_phy_params.iv_user_msdg_upto_ver397559.Height3DS = MSDG_H2;
                    break;

                case fapi2::ENUM_ATTR_MEM_3DS_HEIGHT_H4:
                    io_phy_params.iv_user_msdg_upto_ver397559.Height3DS = MSDG_H4;
                    break;

                case fapi2::ENUM_ATTR_MEM_3DS_HEIGHT_H8:
                    io_phy_params.iv_user_msdg_upto_ver397559.Height3DS = MSDG_H8;
                    break;

                default:
                    const auto l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(iv_target);
                    FAPI_ASSERT(false,
                                fapi2::MSS_EXP_DRAMINIT_UNSUPPORTED_3DS_HEIGHT().
                                set_OCMB_TARGET(l_ocmb).
                                set_PORT(iv_target).
                                set_HEIGHT(iv_attrs_params.iv_height_3DS[0]),
                                "%s 3DS Height is not a supported (%d)",
                                mss::c_str(iv_target), iv_attrs_params.iv_height_3DS[0]);
                    break;
            }

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Get the value for parameter ActiveDBYTE
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_ActiveDBYTE(user_input_msdg& io_phy_params) const
        {
            // TK add checks for same DIMM/RANK info
            io_phy_params.iv_user_msdg_upto_ver397559.ActiveDBYTE = iv_attrs_params.iv_dbyte_macro[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter ActiveNibble
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_ActiveNibble(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.ActiveNibble = iv_attrs_params.iv_nibble[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter AddrMirror
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_AddrMirror(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.AddrMirror = iv_attrs_params.iv_addr_mirror[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter ColumnAddrWidth
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_ColumnAddrWidth(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.ColumnAddrWidth = iv_attrs_params.iv_column_width[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter RowAddrWidth
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_RowAddrWidth(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.RowAddrWidth = iv_attrs_params.iv_row_width[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter SpdCLSupported
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_SpdCLSupported(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.SpdCLSupported = iv_attrs_params.iv_spdcl_support;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter SpdtAAmin
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_SpdtAAmin(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.SpdtAAmin = iv_attrs_params.iv_taa_min;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter Rank4Mode
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_Rank4Mode(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.Rank4Mode = iv_attrs_params.iv_rank4_mode[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter DDPCompatible
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_DDPCompatible(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.DDPCompatible = iv_attrs_params.iv_ddp_compatible[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter TSV8HSupport
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_TSV8HSupport(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.TSV8HSupport = iv_attrs_params.iv_tsv8h[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter MRAMSupport
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_MRAMSupport(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.MRAMSupport = iv_attrs_params.iv_mram_support[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter NumPStates
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_NumPStates(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.NumPStates = iv_attrs_params.iv_num_pstate[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter Frequency
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_Frequency(user_input_msdg& io_phy_params) const
        {
            // Divide by 2 to convert from DRAM freq to MEMCLK freq
            io_phy_params.iv_user_msdg_upto_ver397559.Frequency[0] = static_cast<uint16_t>(iv_attrs_params.iv_frequency / 2);
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter PhyOdtImpedance
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_PhyOdtImpedance(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.PhyOdtImpedance[0] = iv_attrs_params.iv_odt_impedance[0][0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter PhyDrvImpedancePU
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_PhyDrvImpedancePU(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.PhyDrvImpedancePU[0] = iv_attrs_params.iv_drv_impedance_pu[0][0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter PhyDrvImpedancePD
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_PhyDrvImpedancePD(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.PhyDrvImpedancePD[0] = iv_attrs_params.iv_drv_impedance_pd[0][0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter PhySlewRate
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_PhySlewRate(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.PhySlewRate[0] = iv_attrs_params.iv_slew_rate[0][0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter ATxImpedance
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_ATxImpedance(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.ATxImpedance = iv_attrs_params.iv_atx_impedance[0][0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter ATxSlewRate
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_ATxSlewRate(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.ATxSlewRate = iv_attrs_params.iv_atx_slew_rate[0][0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter CKTxImpedance
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_CKTxImpedance(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.CKTxImpedance = iv_attrs_params.iv_ck_tx_impedance[0][0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter CKTxSlewRate
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_CKTxSlewRate(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.CKTxSlewRate = iv_attrs_params.iv_ck_tx_slew_rate[0][0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter AlertOdtImpedance
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_AlertOdtImpedance(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.AlertOdtImpedance = iv_attrs_params.iv_alert_odt_impedance[0][0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter RttNom
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_RttNom(user_input_msdg& io_phy_params) const
        {
            const std::vector<uint16_t*> l_rtt_noms =
            {
                &io_phy_params.iv_user_msdg_upto_ver397559.DramRttNomR0[0],
                &io_phy_params.iv_user_msdg_upto_ver397559.DramRttNomR1[0],
                &io_phy_params.iv_user_msdg_upto_ver397559.DramRttNomR2[0],
                &io_phy_params.iv_user_msdg_upto_ver397559.DramRttNomR3[0],
            };

            set_phy_field_by_rank(l_rtt_noms, iv_attrs_params.iv_dram_rtt_nom);
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter RttWr
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_RttWr(user_input_msdg& io_phy_params) const
        {
            const std::vector<uint16_t*> l_rtt_wrs =
            {
                &io_phy_params.iv_user_msdg_upto_ver397559.DramRttWrR0[0],
                &io_phy_params.iv_user_msdg_upto_ver397559.DramRttWrR1[0],
                &io_phy_params.iv_user_msdg_upto_ver397559.DramRttWrR2[0],
                &io_phy_params.iv_user_msdg_upto_ver397559.DramRttWrR3[0],
            };

            set_phy_field_by_rank(l_rtt_wrs, iv_attrs_params.iv_dram_rtt_wr);
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter RttPark
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_RttPark(user_input_msdg& io_phy_params) const
        {
            const std::vector<uint16_t*> l_rtt_parks =
            {
                &io_phy_params.iv_user_msdg_upto_ver397559.DramRttParkR0[0],
                &io_phy_params.iv_user_msdg_upto_ver397559.DramRttParkR1[0],
                &io_phy_params.iv_user_msdg_upto_ver397559.DramRttParkR2[0],
                &io_phy_params.iv_user_msdg_upto_ver397559.DramRttParkR3[0],
            };

            set_phy_field_by_rank(l_rtt_parks, iv_attrs_params.iv_dram_rtt_park);
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter DramDic
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_DramDic(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.DramDic[0] = iv_attrs_params.iv_dram_dic[0][0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter DramWritePreamble
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_DramWritePreamble(user_input_msdg& io_phy_params) const
        {
            fapi2::buffer<uint8_t> l_dram_preamble_buf(iv_attrs_params.iv_dram_preamble[0][0]);
            io_phy_params.iv_user_msdg_upto_ver397559.DramWritePreamble[0] =
                l_dram_preamble_buf.getBit<fapi2::ENUM_ATTR_MEM_SI_DRAM_PREAMBLE_WRITE_PREAMBLE_BIT>();
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter DramReadPreamble
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_DramReadPreamble(user_input_msdg& io_phy_params) const
        {
            fapi2::buffer<uint8_t> l_dram_preamble_buf(iv_attrs_params.iv_dram_preamble[0][0]);
            io_phy_params.iv_user_msdg_upto_ver397559.DramReadPreamble[0] =
                l_dram_preamble_buf.getBit<fapi2::ENUM_ATTR_MEM_SI_DRAM_PREAMBLE_READ_PREAMBLE_BIT>();
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter PhyEqualization
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_PhyEqualization(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.PhyEqualization[0] = iv_attrs_params.iv_phy_equalization[0][0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter InitVrefDQ
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_InitVrefDQ(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.InitVrefDQ[0] = iv_attrs_params.iv_init_vref_dq[0][0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter InitPhyVref
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_InitPhyVref(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.InitPhyVref[0] = iv_attrs_params.iv_init_phy_vref[0][0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter OdtWrMapCs
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_OdtWrMapCs(user_input_msdg& io_phy_params) const
        {
            fapi2::buffer<uint16_t> odt_wr_map_cs_buff;

            FAPI_TRY(populate_odt_buffer(iv_attrs_params.iv_odt_wr_map_cs, odt_wr_map_cs_buff));
            io_phy_params.iv_user_msdg_upto_ver397559.OdtWrMapCs[0] = odt_wr_map_cs_buff;

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Get the value for parameter OdtRdMapCs
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_OdtRdMapCs(user_input_msdg& io_phy_params) const
        {
            fapi2::buffer<uint16_t> odt_rd_map_cs_buff;

            FAPI_TRY(populate_odt_buffer(iv_attrs_params.iv_odt_rd_map_cs, odt_rd_map_cs_buff));
            io_phy_params.iv_user_msdg_upto_ver397559.OdtRdMapCs[0] = odt_rd_map_cs_buff;

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Get the value for parameter Geardown
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_Geardown(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.Geardown[0] = iv_attrs_params.iv_geardown_mode[0][0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter CALatencyAdder
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_CALatencyAdder(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.CALatencyAdder[0] = iv_attrs_params.iv_ca_latency_adder[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter BistCALMode
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_BistCALMode(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.BistCALMode[0] = iv_attrs_params.iv_bist_cal_mode[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter BistCAParityLatency
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_BistCAParityLatency(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.BistCAParityLatency[0] = iv_attrs_params.iv_bist_ca_parity_latency[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter RcdDic
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_RcdDic(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.RcdDic[0] = iv_attrs_params.iv_rcd_dic[0];

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter RcdVoltageCtrl
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_RcdVoltageCtrl(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.RcdVoltageCtrl[0] = iv_attrs_params.iv_rcd_voltage_ctrl[0];

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter RcdIBTCtrl
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_RcdIBTCtrl(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.RcdIBTCtrl[0] = iv_attrs_params.iv_f0rc7x[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter RcdDBDic
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_RcdDBDic(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.RcdDBDic[0] = iv_attrs_params.iv_f1rc00[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter RcdSlewRate
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_RcdSlewRate(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.RcdSlewRate[0] = iv_attrs_params.iv_rcd_slew_rate[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        // Version 2 updates

        ///
        /// @brief Get the value for parameter version_number
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_version_number(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.version_number = iv_attrs_params.iv_version_number;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter version_number
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_EncodedQuadCs(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.EncodedQuadCs = iv_attrs_params.iv_encoded_quadcs;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter MDSSupport
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_MDSSupport(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.MDSSupport = iv_attrs_params.iv_mdssupport;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter DFIMRL_DDRCLK
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_DFIMRL_DDRCLK(user_input_msdg& io_phy_params) const
        {
            io_phy_params.iv_user_msdg_upto_ver397559.DFIMRL_DDRCLK = iv_attrs_params.iv_dfimrl_ddrclk;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter DFIMRL_DDRCLK
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_ATxDly_A(user_input_msdg& io_phy_params) const
        {
            memcpy(&io_phy_params.iv_user_msdg_upto_ver397559.ATxDly_A[0][0], &iv_attrs_params.iv_atxdly_a[0],
                   DRAMINIT_NUM_ADDR_DELAYS);
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter DFIMRL_DDRCLK
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_ATxDly_B(user_input_msdg& io_phy_params) const
        {
            memcpy(&io_phy_params.iv_user_msdg_upto_ver397559.ATxDly_B[0][0], &iv_attrs_params.iv_atxdly_b[0],
                   DRAMINIT_NUM_ADDR_DELAYS);
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter iv_encoded_quadcs
        /// @return iv_encoded_quadcs value
        /// @note thi funciton is for unit testing
        ///
        uint16_t get_EncodedQuadCs() const
        {
            return iv_attrs_params.iv_encoded_quadcs;
        }

        ///
        /// @brief Get the value for parameter F1RC1x
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_F1RC1x(user_input_msdg& io_phy_params) const
        {
            io_phy_params.F1RC1x = iv_attrs_params.iv_f1rc1x[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter F1RC2x
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_F1RC2x(user_input_msdg& io_phy_params) const
        {
            io_phy_params.F1RC2x = iv_attrs_params.iv_f1rc2x[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter F1RC3x
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_F1RC3x(user_input_msdg& io_phy_params) const
        {
            io_phy_params.F1RC3x = iv_attrs_params.iv_f1rc3x[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter F1RC4x
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_F1RC4x(user_input_msdg& io_phy_params) const
        {
            io_phy_params.F1RC4x = iv_attrs_params.iv_f1rc4x[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter F1RC5x
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_F1RC5x(user_input_msdg& io_phy_params) const
        {
            io_phy_params.F1RC5x = iv_attrs_params.iv_f1rc5x[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter F1RC6x
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_F1RC6x(user_input_msdg& io_phy_params) const
        {
            io_phy_params.F1RC6x = iv_attrs_params.iv_f1rc6x[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter F1RC7x
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_F1RC7x(user_input_msdg& io_phy_params) const
        {
            io_phy_params.F1RC7x = iv_attrs_params.iv_f1rc7x[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }
};

namespace impl_details
{
///
/// @brief Sets eye capture mode and checks resp
/// @tparam T eye_response struct
/// @param[in] i_phy_init_mode phy_init_mode
/// @param[in] i_phy_info phy information of interest
/// @param[out] o_check_response_rc response RC
/// @param[out] o_read_display_response_rc display response RC
/// @param[out] o_response_rc eye response
/// @return FAPI2_RC_SUCCESS iff okay
///
template <typename T>
fapi2::ReturnCode common_init_eye_capture(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const phy_init_mode i_phy_init_mode,
        const phy_param_info& i_phy_info,
        fapi2::ReturnCode& o_check_response_rc,
        fapi2::ReturnCode& o_read_display_response_rc,
        T& o_response_rc)
{
    std::vector<uint8_t> l_rsp_data;

    host_fw_command_struct l_cmd;
    FAPI_TRY(send_host_phy_init_cmd(i_target, i_phy_info, i_phy_init_mode, l_cmd));

    // Return code output param is that of check::response
    // A fail of getRSP will go to fapi_try_exit
    FAPI_TRY(mss::exp::check_host_fw_response(i_target, l_cmd, l_rsp_data, o_check_response_rc));

    o_read_display_response_rc = check_rsp_data_size(i_target,
                                 l_rsp_data.size(),
                                 i_phy_init_mode);

    // Check the return codes at the end
    if (o_read_display_response_rc == fapi2::FAPI2_RC_SUCCESS)
    {
        o_read_display_response_rc = mss::exp::read_and_display_user_2d_eye_response(i_target, l_rsp_data, o_response_rc);
    }
    else
    {
        //If check_rsp_data_size fails we reset the state since
        // return code processing is done in process_eye_capture_return_codes().
        // We could have returned success but the reset isn't guaranteed unless
        // we can guarantee the caller uses a FAPI_TRY and NOT a local rc variable
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    }

fapi_try_exit:
    return fapi2::current_err;
}
} // impl_details ns

///
/// @brief user_input_msdg structure setup
/// @param[in] i_target the fapi2 target
/// @param[out] o_phy_params the phy initialization struct
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode setup_phy_params(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                   user_input_msdg& o_phy_params);

///
/// @brief Print user_input_msdg structure
/// @param[in] i_target the fapi2 target
/// @param[in] i_phy_params the phy initialization struct
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode print_phy_params(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const user_input_msdg& i_phy_params);

}// exp
}// mss

#endif
