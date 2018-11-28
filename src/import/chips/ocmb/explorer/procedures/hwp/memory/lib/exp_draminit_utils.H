/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/exp_draminit_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#include <mss_generic_attribute_getters.H>
#include <mss_explorer_attribute_getters.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/mss_buffer_utils.H>

namespace mss
{
namespace exp
{

///
/// @brief defines the supported DIMM types in Explorer
///
enum msdg_dimm_types
{
    MSDG_UDIMM = 0x0000,
    MSDG_RDIMM = 0x0001,
    MSDG_LRDIMM = 0x0002,
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
fapi2::ReturnCode setup_phy_params(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                   user_input_msdg& o_param );

///
/// @class phy_params_t
/// @brief Structure of variables
///
struct phy_params_t
{
    ///
    /// Declare variables to be used
    ///
    uint8_t iv_dimm_type[MAX_DIMM_PER_PORT];
    uint8_t iv_chip_select;
    uint8_t iv_dram_data_width[MAX_DIMM_PER_PORT];
    uint8_t iv_height_3DS;
    uint16_t iv_dbyte_macro;
    uint32_t iv_nibble;
    uint8_t iv_addr_mirror[MAX_DIMM_PER_PORT];
    uint8_t iv_column_width[MAX_DIMM_PER_PORT];
    uint8_t iv_row_width[MAX_DIMM_PER_PORT];
    uint32_t iv_spdcl_support;
    uint8_t iv_taa_min;
    uint8_t iv_rank4_mode;
    uint8_t iv_ddp_compatible;
    uint8_t iv_tsv8h;
    uint8_t iv_mram_support;
    uint8_t iv_num_pstate;
    uint64_t iv_frequency;
    uint8_t iv_odt_impedance;
    uint8_t iv_drv_impedance_pu[MSDG_MAX_PSTATE];
    uint8_t iv_drv_impedance_pd[MSDG_MAX_PSTATE];
    uint8_t iv_slew_rate[MSDG_MAX_PSTATE];
    uint8_t iv_atx_impedance;
    uint8_t iv_atx_slew_rate;
    uint8_t iv_ck_tx_impedance;
    uint8_t iv_ck_tx_slew_rate;
    uint8_t iv_alert_odt_impedance;
    uint8_t iv_dram_rtt_nom[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];
    uint8_t iv_dram_rtt_wr[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];
    uint8_t iv_dram_rtt_park[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];
    uint8_t iv_dram_dic[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];
    uint8_t iv_dram_preamble;
    uint8_t iv_phy_equalization;
    uint8_t iv_init_vref_dq;
    uint16_t iv_init_phy_vref;
    uint8_t iv_odt_wr_map_cs;
    uint8_t iv_odt_rd_map_cs;
    uint8_t iv_geardown_mode[MAX_DIMM_PER_PORT];
    uint8_t iv_ca_latency_adder[MAX_DIMM_PER_PORT];
    uint8_t iv_bist_cal_mode[MAX_DIMM_PER_PORT];
    uint8_t iv_bist_ca_parity_latency[MAX_DIMM_PER_PORT];
    uint8_t iv_rcd_dic;
    uint8_t iv_rcd_voltage_ctrl;
    uint8_t iv_f0rc7x[MAX_DIMM_PER_PORT];
    uint8_t iv_f1rc00[MAX_DIMM_PER_PORT];
    uint16_t iv_rcd_slew_rate;
    uint8_t iv_firmware_mode;
};

///
/// @class phy_params
///
/// @note This class provides storage and methods for setting
/// up the parameters for user_input_msdg structure
///
class phy_params
{
    private:
        phy_params_t iv_params;

    public:
        ///
        /// @brief Delete default constructor
        ///
        phy_params() = delete;

        ///
        /// @brief Constructor to fetch attributes
        ///
        /// @brief fetch the attributes and initialize it to the params
        /// @param[in] i_port the fapi2 target
        /// @param[in,out] o_rc the fapi2 output
        ///
        phy_params(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_port, fapi2::ReturnCode o_rc)
        {
            // Fetch attributes and populate the member variables
            FAPI_TRY(mss::attr::get_dimm_type(i_port, iv_params.iv_dimm_type));
            FAPI_TRY(mss::attr::get_exp_chip_select(i_port, iv_params.iv_chip_select));
            FAPI_TRY(mss::attr::get_dram_width(i_port, iv_params.iv_dram_data_width));
            FAPI_TRY(mss::attr::get_3ds_height(i_port, iv_params.iv_height_3DS));
            FAPI_TRY(mss::attr::get_byte_enables(i_port, iv_params.iv_dbyte_macro));
            FAPI_TRY(mss::attr::get_nibble_enables(i_port, iv_params.iv_nibble));
            FAPI_TRY(mss::attr::get_exp_dram_address_mirroring(i_port, iv_params.iv_addr_mirror));
            FAPI_TRY(mss::attr::get_dram_column_bits(i_port, iv_params.iv_column_width));
            FAPI_TRY(mss::attr::get_dram_row_bits(i_port, iv_params.iv_row_width));
            FAPI_TRY(mss::attr::get_exp_spd_cl(i_port, iv_params.iv_spdcl_support));
            FAPI_TRY(mss::attr::get_taa_min(i_port, iv_params.iv_taa_min));
            FAPI_TRY(mss::attr::get_rank4_mode(i_port, iv_params.iv_rank4_mode));
            FAPI_TRY(mss::attr::get_ddp_compatibility(i_port, iv_params.iv_ddp_compatible));
            FAPI_TRY(mss::attr::get_tsv8h_support(i_port, iv_params.iv_tsv8h));
            FAPI_TRY(mss::attr::get_mram_support(i_port, iv_params.iv_mram_support));
            FAPI_TRY(mss::attr::get_pstates(i_port, iv_params.iv_num_pstate));
            FAPI_TRY(mss::attr::get_freq(i_port, iv_params.iv_frequency));
            FAPI_TRY(mss::attr::get_si_mc_drv_imp_cntl(i_port, iv_params.iv_odt_impedance));
            FAPI_TRY(mss::attr::get_si_mc_drv_imp_dq_dqs_pull_up(i_port, iv_params.iv_drv_impedance_pu));
            FAPI_TRY(mss::attr::get_si_mc_drv_imp_dq_dqs_pull_down(i_port, iv_params.iv_drv_impedance_pd));
            FAPI_TRY(mss::attr::get_si_mc_drv_slew_rate_dq_dqs(i_port, iv_params.iv_slew_rate));
            FAPI_TRY(mss::attr::get_si_mc_drv_imp_cmd_addr(i_port, iv_params.iv_atx_impedance));
            FAPI_TRY(mss::attr::get_si_mc_drv_slew_rate_cmd_addr(i_port, iv_params.iv_atx_slew_rate));
            FAPI_TRY(mss::attr::get_si_mc_drv_imp_clk(i_port, iv_params.iv_ck_tx_impedance));
            FAPI_TRY(mss::attr::get_si_mc_drv_slew_rate_clk(i_port, iv_params.iv_ck_tx_slew_rate));
            FAPI_TRY(mss::attr::get_si_mc_rcv_imp_alert_n(i_port, iv_params.iv_alert_odt_impedance));
            FAPI_TRY(mss::attr::get_si_dram_rtt_nom(i_port, iv_params.iv_dram_rtt_nom));
            FAPI_TRY(mss::attr::get_si_dram_rtt_wr(i_port, iv_params.iv_dram_rtt_wr));
            FAPI_TRY(mss::attr::get_si_dram_rtt_park(i_port, iv_params.iv_dram_rtt_park));
            FAPI_TRY(mss::attr::get_si_dram_drv_imp_dq_dqs(i_port, iv_params.iv_dram_dic));
            FAPI_TRY(mss::attr::get_si_dram_preamble(i_port, iv_params.iv_dram_preamble));
            FAPI_TRY(mss::attr::get_exp_phy_equalization(i_port, iv_params.iv_phy_equalization));
            FAPI_TRY(mss::attr::get_exp_init_vref_dq(i_port, iv_params.iv_init_vref_dq));
            FAPI_TRY(mss::attr::get_exp_init_phy_vref(i_port, iv_params.iv_init_phy_vref));
            FAPI_TRY(mss::attr::get_exp_odt_map_cs_wr(i_port, iv_params.iv_odt_wr_map_cs));
            FAPI_TRY(mss::attr::get_exp_odt_map_cs_rd(i_port, iv_params.iv_odt_rd_map_cs));
            FAPI_TRY(mss::attr::get_geardown_mode(i_port, iv_params.iv_geardown_mode));
            FAPI_TRY(mss::attr::get_dimm_ddr4_f0rc0f(i_port, iv_params.iv_ca_latency_adder));
            FAPI_TRY(mss::attr::get_cs_cmd_latency(i_port, iv_params.iv_bist_cal_mode));
            FAPI_TRY(mss::attr::get_ca_parity_latency(i_port, iv_params.iv_bist_ca_parity_latency));
            FAPI_TRY(mss::attr::get_exp_rcd_dic(i_port, iv_params.iv_rcd_dic));
            FAPI_TRY(mss::attr::get_exp_rcd_voltage_ctrl(i_port, iv_params.iv_rcd_voltage_ctrl));
            FAPI_TRY(mss::attr::get_dimm_ddr4_f0rc7x(i_port, iv_params.iv_f0rc7x));
            FAPI_TRY(mss::attr::get_dimm_ddr4_f1rc00(i_port, iv_params.iv_f1rc00));
            FAPI_TRY(mss::attr::get_exp_rcd_slew_rate(i_port, iv_params.iv_rcd_slew_rate));
            FAPI_TRY(mss::attr::get_exp_firmware_emulation_mode(i_port, iv_params.iv_firmware_mode));

        fapi_try_exit:
            o_rc = fapi2::current_err;
        }

        ///
        /// @brief Constructor for UTs
        ///
        /// @brief Set params as per the value initialized for the UT
        /// @param[in] i_phy_params - data struct for UT
        ///
        phy_params(const phy_params_t& i_phy_params): iv_params(i_phy_params) {}

        ///
        /// @brief Destructor
        ///
        ~phy_params() = default;

        ///
        /// @brief user_input_msdg structure setup for parameter DimmType
        /// @param[in] i_port the fapi2 target
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_DimmType(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_port,
                                         user_input_msdg& io_phy_params) const
        {
            switch (iv_params.iv_dimm_type[0])
            {
                case fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_RDIMM:
                    io_phy_params.DimmType = MSDG_RDIMM;
                    break;

                case fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_UDIMM:
                    io_phy_params.DimmType = MSDG_UDIMM;
                    break;

                case fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_LRDIMM:
                    io_phy_params.DimmType = MSDG_LRDIMM;
                    break;

                default:
                    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_port);
                    FAPI_ASSERT(false,
                                fapi2::MSS_EXP_DRAMINIT_UNSUPPORTED_DIMM_TYPE().
                                set_OCMB_TARGET(l_ocmb).
                                set_PORT(i_port).
                                set_TYPE(iv_params.iv_dimm_type[0]),
                                "%s DIMM0 is not a supported DIMM type (%d)",
                                mss::c_str(i_port), iv_params.iv_dimm_type[0]);
                    break;
            }

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief user_input_msdg structure setup for parameter CsPresent
        /// @param[in] i_port the fapi2 target
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_CsPresent(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_port,
                                          user_input_msdg& io_phy_params) const
        {
            io_phy_params.CsPresent = iv_params.iv_chip_select;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief user_input_msdg structure setup for parameter DramDataWidth
        /// @param[in] i_port the fapi2 target
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_DramDataWidth(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_port,
                                              user_input_msdg& io_phy_params) const
        {
            switch (iv_params.iv_dram_data_width[0])
            {
                case fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X4:
                    io_phy_params.DramDataWidth = MSDG_X4;
                    break;

                case fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X8:
                    io_phy_params.DramDataWidth = MSDG_X8;
                    break;

                case fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X16:
                    io_phy_params.DramDataWidth = MSDG_X16;
                    break;

                default:
                    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_port);
                    FAPI_ASSERT(false,
                                fapi2::MSS_EXP_DRAMINIT_UNSUPPORTED_DRAM_WIDTH().
                                set_OCMB_TARGET(l_ocmb).
                                set_PORT(i_port).
                                set_DATA_WIDTH(iv_params.iv_dram_data_width[0]),
                                "%s DRAM Data Width of DIMM0 is not a supported (%d)",
                                mss::c_str(i_port), iv_params.iv_dram_data_width[0]);
                    break;
            }

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief user_input_msdg structure setup for parameter Height3DS
        /// @param[in] i_port the fapi2 target
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_Height3DS(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_port,
                                          user_input_msdg& io_phy_params) const
        {
            switch (iv_params.iv_height_3DS)
            {
                case fapi2::ENUM_ATTR_MEM_EFF_3DS_HEIGHT_PLANAR:
                    io_phy_params.Height3DS = MSDG_PLANAR;
                    break;

                case fapi2::ENUM_ATTR_MEM_EFF_3DS_HEIGHT_H2:
                    io_phy_params.Height3DS = MSDG_H2;
                    break;

                case fapi2::ENUM_ATTR_MEM_EFF_3DS_HEIGHT_H4:
                    io_phy_params.Height3DS = MSDG_H4;
                    break;

                case fapi2::ENUM_ATTR_MEM_EFF_3DS_HEIGHT_H8:
                    io_phy_params.Height3DS = MSDG_H8;
                    break;

                default:
                    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_port);
                    FAPI_ASSERT(false,
                                fapi2::MSS_EXP_DRAMINIT_UNSUPPORTED_3DS_HEIGHT().
                                set_OCMB_TARGET(l_ocmb).
                                set_PORT(i_port).
                                set_HEIGHT(iv_params.iv_height_3DS),
                                "%s 3DS Height is not a supported (%d)",
                                mss::c_str(i_port), iv_params.iv_height_3DS);
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
            io_phy_params.ActiveDBYTE = iv_params.iv_dbyte_macro;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter ActiveNibble
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_ActiveNibble(user_input_msdg& io_phy_params) const
        {
            io_phy_params.ActiveNibble = iv_params.iv_nibble;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter AddrMirror
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_AddrMirror(user_input_msdg& io_phy_params) const
        {
            io_phy_params.AddrMirror = iv_params.iv_addr_mirror[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter ColumnAddrWidth
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_ColumnAddrWidth(user_input_msdg& io_phy_params) const
        {
            io_phy_params.ColumnAddrWidth = iv_params.iv_column_width[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter RowAddrWidth
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_RowAddrWidth(user_input_msdg& io_phy_params) const
        {
            io_phy_params.RowAddrWidth = iv_params.iv_row_width[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter SpdCLSupported
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_SpdCLSupported(user_input_msdg& io_phy_params) const
        {
            io_phy_params.SpdCLSupported = iv_params.iv_spdcl_support;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter SpdtAAmin
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_SpdtAAmin(user_input_msdg& io_phy_params) const
        {
            io_phy_params.SpdtAAmin = iv_params.iv_taa_min;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter Rank4Mode
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_Rank4Mode(user_input_msdg& io_phy_params) const
        {
            io_phy_params.Rank4Mode = iv_params.iv_rank4_mode;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter DDPCompatible
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_DDPCompatible(user_input_msdg& io_phy_params) const
        {
            io_phy_params.DDPCompatible = iv_params.iv_ddp_compatible;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter TSV8HSupport
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_TSV8HSupport(user_input_msdg& io_phy_params) const
        {
            io_phy_params.TSV8HSupport = iv_params.iv_tsv8h;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter MRAMSupport
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_MRAMSupport(user_input_msdg& io_phy_params) const
        {
            io_phy_params.MRAMSupport = iv_params.iv_mram_support;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter NumPStates
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_NumPStates(user_input_msdg& io_phy_params) const
        {
            io_phy_params.NumPStates = iv_params.iv_num_pstate;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter Frequency
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_Frequency(user_input_msdg& io_phy_params) const
        {
            io_phy_params.Frequency[0] = static_cast<uint16_t>(iv_params.iv_frequency);
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter PhyOdtImpedance
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_PhyOdtImpedance(user_input_msdg& io_phy_params) const
        {
            io_phy_params.PhyOdtImpedance[0] = iv_params.iv_odt_impedance;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter PhyDrvImpedancePU
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_PhyDrvImpedancePU(user_input_msdg& io_phy_params) const
        {
            io_phy_params.PhyDrvImpedancePU[0] = iv_params.iv_drv_impedance_pu[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter PhyDrvImpedancePD
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_PhyDrvImpedancePD(user_input_msdg& io_phy_params) const
        {
            io_phy_params.PhyDrvImpedancePD[0] = iv_params.iv_drv_impedance_pd[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter PhySlewRate
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_PhySlewRate(user_input_msdg& io_phy_params) const
        {
            io_phy_params.PhySlewRate[0] = iv_params.iv_slew_rate[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter ATxImpedance
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_ATxImpedance(user_input_msdg& io_phy_params) const
        {
            io_phy_params.ATxImpedance = iv_params.iv_atx_impedance;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter ATxSlewRate
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_ATxSlewRate(user_input_msdg& io_phy_params) const
        {
            io_phy_params.ATxSlewRate = iv_params.iv_atx_slew_rate;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter CKTxImpedance
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_CKTxImpedance(user_input_msdg& io_phy_params) const
        {
            io_phy_params.CKTxImpedance = iv_params.iv_ck_tx_impedance;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter CKTxSlewRate
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_CKTxSlewRate(user_input_msdg& io_phy_params) const
        {
            io_phy_params.CKTxSlewRate = iv_params.iv_ck_tx_slew_rate;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter AlertOdtImpedance
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_AlertOdtImpedance(user_input_msdg& io_phy_params) const
        {
            io_phy_params.AlertOdtImpedance = iv_params.iv_alert_odt_impedance;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter RttNom
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_RttNom(user_input_msdg& io_phy_params) const
        {
            io_phy_params.DramRttNomR0[0] = iv_params.iv_dram_rtt_nom[0][0];
            io_phy_params.DramRttNomR1[0] = iv_params.iv_dram_rtt_nom[0][1];
            io_phy_params.DramRttNomR2[0] = iv_params.iv_dram_rtt_nom[0][2];
            io_phy_params.DramRttNomR3[0] = iv_params.iv_dram_rtt_nom[0][3];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter RttWr
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_RttWr(user_input_msdg& io_phy_params) const
        {
            io_phy_params.DramRttWrR0[0] = iv_params.iv_dram_rtt_wr[0][0];
            io_phy_params.DramRttWrR1[0] = iv_params.iv_dram_rtt_wr[0][1];
            io_phy_params.DramRttWrR2[0] = iv_params.iv_dram_rtt_wr[0][2];
            io_phy_params.DramRttWrR3[0] = iv_params.iv_dram_rtt_wr[0][3];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter RttPark
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_RttPark(user_input_msdg& io_phy_params) const
        {
            io_phy_params.DramRttParkR0[0] = iv_params.iv_dram_rtt_park[0][0];
            io_phy_params.DramRttParkR1[0] = iv_params.iv_dram_rtt_park[0][1];
            io_phy_params.DramRttParkR2[0] = iv_params.iv_dram_rtt_park[0][2];
            io_phy_params.DramRttParkR3[0] = iv_params.iv_dram_rtt_park[0][3];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter DramDic
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_DramDic(user_input_msdg& io_phy_params) const
        {
            io_phy_params.DramDic[0] = iv_params.iv_dram_dic[0][0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter DramWritePreamble
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_DramWritePreamble(user_input_msdg& io_phy_params) const
        {
            fapi2::buffer<uint8_t> l_dram_preamble_buf(iv_params.iv_dram_preamble);
            io_phy_params.DramWritePreamble[0] =
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
            fapi2::buffer<uint8_t> l_dram_preamble_buf(iv_params.iv_dram_preamble);
            io_phy_params.DramReadPreamble[0] =
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
            io_phy_params.PhyEqualization = iv_params.iv_phy_equalization;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter InitVrefDQ
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_InitVrefDQ(user_input_msdg& io_phy_params) const
        {
            io_phy_params.InitVrefDQ[0] = iv_params.iv_init_vref_dq;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter InitPhyVref
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_InitPhyVref(user_input_msdg& io_phy_params) const
        {
            // Attr Vref = percentage of VDDQ, Receiver Vref = VDDQ*PhyVref[6:0]/128
            // conversion is attr_value * 128 / 100
            io_phy_params.InitPhyVref[0] = iv_params.iv_init_phy_vref * 128 / 100;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter OdtWrMapCs
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_OdtWrMapCs(user_input_msdg& io_phy_params) const
        {
            io_phy_params.OdtWrMapCs[0] = iv_params.iv_odt_wr_map_cs;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter OdtRdMapCs
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_OdtRdMapCs(user_input_msdg& io_phy_params) const
        {
            io_phy_params.OdtRdMapCs[0] = iv_params.iv_odt_rd_map_cs;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter Geardown
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_Geardown(user_input_msdg& io_phy_params) const
        {
            io_phy_params.Geardown[0] = iv_params.iv_geardown_mode[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter CALatencyAdder
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_CALatencyAdder(user_input_msdg& io_phy_params) const
        {
            io_phy_params.CALatencyAdder[0] = iv_params.iv_ca_latency_adder[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter BistCALMode
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_BistCALMode(user_input_msdg& io_phy_params) const
        {
            io_phy_params.BistCALMode[0] = iv_params.iv_bist_cal_mode[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter BistCAParityLatency
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_BistCAParityLatency(user_input_msdg& io_phy_params) const
        {
            io_phy_params.BistCAParityLatency[0] = iv_params.iv_bist_ca_parity_latency[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter RcdDic
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_RcdDic(user_input_msdg& io_phy_params) const
        {
            io_phy_params.RcdDic[0] = iv_params.iv_rcd_dic;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter RcdVoltageCtrl
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_RcdVoltageCtrl(user_input_msdg& io_phy_params) const
        {
            io_phy_params.RcdVoltageCtrl[0] = iv_params.iv_rcd_voltage_ctrl;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter RcdIBTCtrl
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_RcdIBTCtrl(user_input_msdg& io_phy_params) const
        {
            io_phy_params.RcdIBTCtrl = iv_params.iv_f0rc7x[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter RcdDBDic
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_RcdDBDic(user_input_msdg& io_phy_params) const
        {
            io_phy_params.RcdDBDic = iv_params.iv_f1rc00[0];
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter RcdSlewRate
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_RcdSlewRate(user_input_msdg& io_phy_params) const
        {
            io_phy_params.RcdSlewRate = iv_params.iv_rcd_slew_rate;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get the value for parameter EmulationSupport
        /// @param[in,out] io_phy_params the phy params data struct
        /// @return FAPI2_RC_SUCCESS
        ///
        fapi2::ReturnCode set_EmulationSupport(user_input_msdg& io_phy_params) const
        {
            io_phy_params.EmulationSupport = iv_params.iv_firmware_mode;
            return fapi2::FAPI2_RC_SUCCESS;
        }
};

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
