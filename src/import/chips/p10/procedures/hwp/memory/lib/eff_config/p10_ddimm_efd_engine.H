/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/eff_config/p10_ddimm_efd_engine.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
/// @file p10_ddimm_efd_engine.H
/// @brief DDIMM EFD eff_config engine
///
// *HWP HWP Owner: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP FW Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:CI
// EKB-Mirror-To: hostboot

#ifndef _P10_DDIMM_EFD_ENGINE_H_
#define _P10_DDIMM_EFD_ENGINE_H_

#include <cstring>
#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/data_engine/data_engine_utils.H>
#include <generic/memory/lib/spd/spd_field.H>
#include <generic/memory/lib/spd/ddimm/ddr4/efd_fields_ddr4.H>
#include <generic/memory/lib/utils/find.H>

#include <mss_pmic_attribute_setters.H>
#include <mss_explorer_attribute_setters.H>
#include <mss_generic_attribute_setters.H>
#include <lib/eff_config/explorer_attr_engine_traits.H>
#include <generic/memory/lib/data_engine/data_engine.H>
#include <lib/dimm/exp_rank.H>

namespace mss
{
namespace efd
{

///
/// @brief Class for DDIMM EFD Rev 0.3
///
class ddimm_efd_0_3
{
        // From exp_data_structs.H
        static constexpr uint8_t DRAMINIT_NUM_ADDR_DELAYS = 8;

        using F = mss::efd::fields<mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>;

    protected:
        fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_dimm;
        fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> iv_port;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> iv_ocmb;
        uint8_t iv_dimm_rank;
        uint8_t iv_phy_rank;

    public:

        ///
        /// @brief Construct a new DDIMM EFD rev 0.3 object
        /// @param[in] i_dimm DIMM target
        /// @param[in] i_rank_info the current rank info class
        ///
        ddimm_efd_0_3(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
                      const mss::rank::info<mss::mc_type::EXPLORER>& i_rank_info) :
            iv_dimm(i_dimm),
            iv_port(mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_dimm)),
            iv_ocmb(mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_dimm)),
            iv_dimm_rank(i_rank_info.get_dimm_rank()),
            iv_phy_rank(i_rank_info.get_phy_rank()) {}

        ///
        /// @brief Destroy the ddimm_efd_0_3 object
        ///
        virtual ~ddimm_efd_0_3() = default;

        // Check functions here return true when any value is valid (0x00 through 0xFF)

        ///
        /// @brief Traits for cac_dly_fields
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_cac_dly_field(const uint8_t i_field) const
        {
            // Bit 5 is reserved, but our max value could still be 0b01011111 = 0x5F
            // TK - perhaps we split this up into two fields - one for the inversion (bit 6),
            // and then this existing one
            constexpr uint8_t RESERVED = 0b00100000;
            return (i_field <= 0x5F) && !(i_field & RESERVED);
        }

        ///
        /// @brief Traits for wr vref dq range
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_wr_vref_dq_range(const uint8_t i_field) const
        {
            return (i_field <= 0x01);
        }

        ///
        /// @brief Traits for wr vref dq value
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_wr_vref_dq_value(const uint8_t i_field) const
        {
            return (i_field <= 0x32);
        }

        ///
        /// @brief Traits for init phy vref
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_init_phy_vref(const uint8_t i_field) const
        {
            return (i_field <= 0x7F);
        }

        ///
        /// @brief Traits for rcd dic 1
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_rcd_dic_1(const uint8_t i_field) const
        {
            return (i_field == 0x00);
        }

        ///
        /// @brief Traits for rcd dic 0
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_rcd_dic_0(const uint8_t i_field) const
        {
            return (i_field == 0x00);
        }

        ///
        /// @brief Traits for rcd voltage ctrl 0
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_rcd_voltage_ctrl_0(const uint8_t i_field) const
        {
            return (i_field == 0x00);
        }

        ///
        /// @brief Traits for rcd voltage ctrl 1
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_rcd_voltage_ctrl_1(const uint8_t i_field) const
        {
            return (i_field == 0x00);
        }

        ///
        /// @brief Traits for rcd ibt
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_rcd_ibt(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits for rcd db dic
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_rcd_db_dic(const uint8_t i_field) const
        {
            // Mask to ensure bits 0-4 and 6 are unset
            constexpr uint8_t REVERSE_MASK = 0xFA;
            return ((i_field & REVERSE_MASK) == 0);
        }

        ///
        /// @brief Traits for f1rc1x
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_f1rc1x(const uint8_t i_field) const
        {
            return (i_field == 0x00);
        }

        ///
        /// @brief Traits for f1rc2x
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_f1rc2x(const uint8_t i_field) const
        {
            return (i_field == 0x00);
        }

        ///
        /// @brief Traits for f1rc3x
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_f1rc3x(const uint8_t i_field) const
        {
            return (i_field == 0x00);
        }

        ///
        /// @brief Traits for f1rc4x
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_f1rc4x(const uint8_t i_field) const
        {
            return (i_field == 0x00);
        }

        ///
        /// @brief Traits for f1rc5x
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_f1rc5x(const uint8_t i_field) const
        {
            return (i_field == 0x00);
        }

        ///
        /// @brief Traits for f1rc6x
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_f1rc6x(const uint8_t i_field) const
        {
            return (i_field == 0x00);
        }

        ///
        /// @brief Traits for f1rc7x
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_f1rc7x(const uint8_t i_field) const
        {
            return (i_field == 0x00);
        }

        ///
        /// @brief Traits for rcd slew rate ctrl 1
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_rcd_slew_rate_ctrl_1(const uint8_t i_field) const
        {
            // Masks to ensure no bit pair has both bits set
            constexpr uint8_t REVERSE_MASK_0 = 0xC0;
            constexpr uint8_t REVERSE_MASK_1 = 0x30;
            constexpr uint8_t REVERSE_MASK_2 = 0x0C;
            constexpr uint8_t REVERSE_MASK_3 = 0x03;

            const uint8_t MASK_RESULT_0 = i_field & REVERSE_MASK_0;
            const uint8_t MASK_RESULT_1 = i_field & REVERSE_MASK_1;
            const uint8_t MASK_RESULT_2 = i_field & REVERSE_MASK_2;
            const uint8_t MASK_RESULT_3 = i_field & REVERSE_MASK_3;

            return !(MASK_RESULT_0 == REVERSE_MASK_0 ||
                     MASK_RESULT_1 == REVERSE_MASK_1 ||
                     MASK_RESULT_2 == REVERSE_MASK_2 ||
                     MASK_RESULT_3 == REVERSE_MASK_3);
        }

        ///
        /// @brief Traits for rcd slew rate ctrl 0
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_rcd_slew_rate_ctrl_0(const uint8_t i_field) const
        {
            // Masks to ensure no bit pair has both bits set
            constexpr uint8_t REVERSE_MASK_0 = 0xC0;
            constexpr uint8_t REVERSE_MASK_1 = 0x30;
            constexpr uint8_t REVERSE_MASK_2 = 0x0C;
            constexpr uint8_t REVERSE_MASK_3 = 0x03;

            const uint8_t MASK_RESULT_0 = i_field & REVERSE_MASK_0;
            const uint8_t MASK_RESULT_1 = i_field & REVERSE_MASK_1;
            const uint8_t MASK_RESULT_2 = i_field & REVERSE_MASK_2;
            const uint8_t MASK_RESULT_3 = i_field & REVERSE_MASK_3;

            return !(MASK_RESULT_0 == REVERSE_MASK_0 ||
                     MASK_RESULT_1 == REVERSE_MASK_1 ||
                     MASK_RESULT_2 == REVERSE_MASK_2 ||
                     MASK_RESULT_3 == REVERSE_MASK_3);
        }

        ///
        /// @brief Traits for bist ca latency mode
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_bist_ca_latency_mode(const uint8_t i_field) const
        {
            return (i_field <= 0x08);
        }

        ///
        /// @brief Traits for bist ca pl mode
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_bist_ca_pl_mode(const uint8_t i_field) const
        {
            return (i_field <= 0x08);
        }

        ///
        /// @brief Traits for dfimrl ddrclk
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_dfimrl_ddrclk(const uint8_t i_field) const
        {
            return (i_field <= 0x0F);
        }

        // PMIC traits common to all rails of PMIC0 and PMIC1

        ///
        /// @brief Traits for pmic rail offset
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_pmic_rail_offset(const uint8_t i_field) const
        {
            return (i_field <= 0x3F);
        }

        ///
        /// @brief Traits for pmic rail offset direction
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_pmic_rail_offset_direction(const uint8_t i_field) const
        {
            return (i_field <= 0x01);
        }

        ///
        /// @brief Traits for pmic rail current warning
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_pmic_rail_current_warning(const uint8_t i_field) const
        {
            // Mask to ensure bits 6 and 7 are unset
            constexpr uint8_t REVERSE_MASK = 0x03;
            return ((i_field & REVERSE_MASK) == 0x00);
        }

        ///
        /// @brief Traits for phy slew rate dq dqs
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_phy_slew_rate_dq_dqs(const uint8_t i_field) const
        {
            return (i_field == 0x00 || i_field == 0x0F);
        }

        ///
        /// @brief Traits for atx slew rate
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_atx_slew_rate(const uint8_t i_field) const
        {
            constexpr uint8_t REVERSE_MASK_RESERVED = 0xF0;
            constexpr uint8_t REVERSE_MASK_RESERVED_MODE = 0x03;
            const uint8_t MASK_RESULT_0 = i_field & REVERSE_MASK_RESERVED;
            const uint8_t MASK_RESULT_1 = i_field & REVERSE_MASK_RESERVED_MODE;

            return ((MASK_RESULT_0 == 0x00) && (MASK_RESULT_1 != 0x03));
        }

        ///
        /// @brief Traits for ck slew rate
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_ck_slew_rate(const uint8_t i_field) const
        {
            constexpr uint8_t REVERSE_MASK_RESERVED = 0xF0;
            constexpr uint8_t REVERSE_MASK_RESERVED_MODE = 0x03;
            const uint8_t MASK_RESULT_0 = i_field & REVERSE_MASK_RESERVED;
            const uint8_t MASK_RESULT_1 = i_field & REVERSE_MASK_RESERVED_MODE;

            return ((MASK_RESULT_0 == 0x00) && (MASK_RESULT_1 != 0x03));
        }

        ///
        /// @brief Traits read preamble
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_read_preamble(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits for write preamble
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_write_preamble(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits for phy equalization
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_phy_equalization(const uint8_t i_field) const
        {
            return (i_field <= 0x03);
        }

        ///
        /// @brief Traits for odt WR / RD map
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_odt_map(const uint8_t i_field) const
        {
            return (i_field <= 0x0F);
        }

        ///
        /// @brief Traits for geardown during training
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_geardown_during_training(const uint8_t i_field) const
        {
            return (i_field <= 0x01);
        }

        ///
        /// @brief Set the cac delay a field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_cac_delay_a(const std::vector<uint8_t>& i_efd) const
        {
            // Get the data
            uint8_t l_addr_delay_a[DRAMINIT_NUM_ADDR_DELAYS] = {};

            // Pairs of DLY_A_X to array index
            const std::array<mss::field_t<mss::endian::LITTLE>, DRAMINIT_NUM_ADDR_DELAYS> DLY_FIELDS
            {
                F::CAC_DLY_A_0,
                F::CAC_DLY_A_1,
                F::CAC_DLY_A_2,
                F::CAC_DLY_A_3,
                F::CAC_DLY_A_4,
                F::CAC_DLY_A_5,
                F::CAC_DLY_A_6,
                F::CAC_DLY_A_7,
            };

            FAPI_TRY(mss::attr::get_exp_atxdly_a(iv_port, l_addr_delay_a));

            for (uint8_t l_idx = 0; l_idx < DRAMINIT_NUM_ADDR_DELAYS; l_idx++)
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, DLY_FIELDS[l_idx], i_efd, SET_CAC_DELAY_A, l_addr_delay_a[l_idx]));
                FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                      iv_ocmb,
                                      check_cac_dly_field(l_addr_delay_a[l_idx]),
                                      DLY_FIELDS[l_idx].get_byte(i_efd),
                                      l_addr_delay_a[l_idx],
                                      SET_CAC_DELAY_A,
                                      "CAC_DELAY_A"));
            }

            // Set the attribute
            FAPI_TRY(mss::attr::set_exp_atxdly_a(iv_port, l_addr_delay_a));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the cac delay b field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_cac_delay_b(const std::vector<uint8_t>& i_efd) const
        {
            // Get the data
            uint8_t l_addr_delay_b[DRAMINIT_NUM_ADDR_DELAYS] = {};

            // Pairs of DLY_A_X to array index
            const std::array<mss::field_t<mss::endian::LITTLE>, DRAMINIT_NUM_ADDR_DELAYS> DLY_FIELDS
            {
                F::CAC_DLY_B_0,
                F::CAC_DLY_B_1,
                F::CAC_DLY_B_2,
                F::CAC_DLY_B_3,
                F::CAC_DLY_B_4,
                F::CAC_DLY_B_5,
                F::CAC_DLY_B_6,
                F::CAC_DLY_B_7,
            };

            FAPI_TRY(mss::attr::get_exp_atxdly_b(iv_port, l_addr_delay_b));

            for (uint8_t l_idx = 0; l_idx < DRAMINIT_NUM_ADDR_DELAYS; l_idx++)
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, DLY_FIELDS[l_idx], i_efd, SET_CAC_DELAY_B, l_addr_delay_b[l_idx]));
                FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                      iv_ocmb,
                                      check_cac_dly_field(l_addr_delay_b[l_idx]),
                                      DLY_FIELDS[l_idx].get_byte(i_efd),
                                      l_addr_delay_b[l_idx],
                                      SET_CAC_DELAY_B,
                                      "CAC_DELAY_B"));
            }

            // Set the attribute
            FAPI_TRY(mss::attr::set_exp_atxdly_b(iv_port, l_addr_delay_b));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the init vref dq field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_init_vref_dq(const std::vector<uint8_t>& i_efd) const
        {
            // See Byte 44 of EFD Document (Bit 6 from right = Bit 1 from left)
            const uint8_t VREF_RANGE_BIT_LEFT_ALGINED = 1;

            // Get the data
            uint8_t l_vref_dq[mss::exp::sizes::MAX_RANK_PER_DIMM] = {0};

            uint8_t l_range = 0;
            uint8_t l_value = 0;
            fapi2::buffer<uint8_t> l_combined_vref;

            FAPI_TRY(mss::attr::get_exp_init_vref_dq(iv_dimm, l_vref_dq));

            // Piece together the field
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::WR_VREF_DQ_RANGE, i_efd, SET_INIT_VREF_DQ, l_range));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::WR_VREF_DQ_VALUE, i_efd, SET_INIT_VREF_DQ, l_value));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_wr_vref_dq_range(l_range),
                                  F::WR_VREF_DQ_RANGE.get_byte(i_efd),
                                  l_range,
                                  SET_INIT_VREF_DQ,
                                  "Initial WR VREF DQ Range"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_wr_vref_dq_value(l_value),
                                  F::WR_VREF_DQ_VALUE.get_byte(i_efd),
                                  l_value,
                                  SET_INIT_VREF_DQ,
                                  "Initial WR VREF DQ Value"));

            l_combined_vref = l_value;
            l_combined_vref.writeBit<VREF_RANGE_BIT_LEFT_ALGINED>(l_range);

            // Insert
            l_vref_dq[iv_dimm_rank] = l_combined_vref;

            // Set the attribute
            FAPI_TRY(mss::attr::set_exp_init_vref_dq(iv_dimm, l_vref_dq));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the init phy vref field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_init_phy_vref(const std::vector<uint8_t>& i_efd) const
        {
            // Get the data
            uint8_t l_phy_vref[mss::exp::sizes::MAX_RANK_PER_DIMM] = {0};
            FAPI_TRY(mss::attr::get_exp_init_phy_vref(iv_dimm, l_phy_vref));

            // Update the values
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::INIT_PHY_VREF, i_efd, SET_INIT_PHY_VREF, l_phy_vref[iv_dimm_rank]));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_init_phy_vref(l_phy_vref[iv_dimm_rank]),
                                  F::INIT_PHY_VREF.get_byte(i_efd),
                                  l_phy_vref[iv_dimm_rank],
                                  SET_INIT_PHY_VREF,
                                  "Host RD VREF DQ"));

            // Set the attribute
            FAPI_TRY(mss::attr::set_exp_init_phy_vref(iv_dimm, l_phy_vref));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the rcd dic field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_rcd_dic(const std::vector<uint8_t>& i_efd) const
        {
            // Get the data
            uint16_t l_rcd_dic = 0;
            uint8_t l_byte = 0;

            // In the EFD, byte1 is the MSB and byte0 is the LSB
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::RCD_DIC_1, i_efd, SET_RCD_DIC, l_byte));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_rcd_dic_1(l_byte),
                                  F::RCD_DIC_1.get_byte(i_efd),
                                  l_byte,
                                  SET_RCD_DIC,
                                  "RCD driver impedance control Byte 1"));

            l_rcd_dic = l_byte << BITS_PER_BYTE;
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::RCD_DIC_0, i_efd, SET_RCD_DIC, l_byte));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_rcd_dic_0(l_byte),
                                  F::RCD_DIC_0.get_byte(i_efd),
                                  l_byte,
                                  SET_RCD_DIC,
                                  "RCD driver impedance control Byte 0"));

            l_rcd_dic |= l_byte;

            // Set the attribute
            FAPI_TRY(mss::attr::set_exp_rcd_dic(iv_dimm, l_rcd_dic));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the rcd voltage ctrl field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_rcd_voltage_ctrl(const std::vector<uint8_t>& i_efd) const
        {
            // Get the data
            uint16_t l_rcd_voltage_ctrl = 0;
            uint8_t l_byte = 0;

            // In the EFD, we get bits 3:0 in byte 0 and 11:4 in byte 1
            // We do a bit of shifting to get this to work out
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::RCD_VOLTAGE_CTRL_0, i_efd, SET_RCD_VOLTAGE_CTRL, l_byte));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_rcd_voltage_ctrl_0(l_byte),
                                  F::RCD_VOLTAGE_CTRL_0.get_byte(i_efd),
                                  l_byte,
                                  SET_RCD_VOLTAGE_CTRL,
                                  "RCD voltage control Byte 0"));

            l_rcd_voltage_ctrl = l_byte;
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::RCD_VOLTAGE_CTRL_1, i_efd, SET_RCD_VOLTAGE_CTRL, l_byte));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_rcd_voltage_ctrl_1(l_byte),
                                  F::RCD_VOLTAGE_CTRL_1.get_byte(i_efd),
                                  l_byte,
                                  SET_RCD_VOLTAGE_CTRL,
                                  "RCD voltage control Byte 1"));

            l_rcd_voltage_ctrl |= (l_byte << BITS_PER_NIBBLE);

            // Set the attribute
            FAPI_TRY(mss::attr::set_exp_rcd_voltage_ctrl(iv_dimm, l_rcd_voltage_ctrl));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the dimm ddr4 f0rc7x field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dimm_ddr4_f0rc7x(const std::vector<uint8_t>& i_efd) const
        {
            // Get the data
            uint8_t l_f0rc7x = 0;

            FAPI_TRY(mss::attr::get_dimm_ddr4_f0rc7x(iv_dimm, l_f0rc7x));

            // Update the values
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::RCD_IBT, i_efd, SET_DIMM_DDR4_F0RC7X, l_f0rc7x));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_rcd_ibt(l_f0rc7x),
                                  F::RCD_IBT.get_byte(i_efd),
                                  l_f0rc7x,
                                  SET_DIMM_DDR4_F0RC7X,
                                  "RCD Input Bus Termination"));

            // Set the attribute
            FAPI_TRY(mss::attr::set_dimm_ddr4_f0rc7x(iv_dimm, l_f0rc7x));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the dimm ddr4 f1rc00 field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dimm_ddr4_f1rc00(const std::vector<uint8_t>& i_efd) const
        {
            // Get the data
            uint8_t l_f1rc00 = 0;

            FAPI_TRY(mss::attr::get_dimm_ddr4_f1rc00(iv_dimm, l_f1rc00));

            // Update the values
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::RCD_DB_DIC, i_efd, SET_DIMM_DDR4_F1RC00, l_f1rc00));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_rcd_db_dic(l_f1rc00),
                                  F::RCD_DB_DIC.get_byte(i_efd),
                                  l_f1rc00,
                                  SET_DIMM_DDR4_F1RC00,
                                  "RCD data buffer driver impedance control"));

            // Set the attribute
            FAPI_TRY(mss::attr::set_dimm_ddr4_f1rc00(iv_dimm, l_f1rc00));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the dimm ddr4 f1rc1x object
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dimm_ddr4_f1rc1x(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(mss::attr::get_ddr4_f1rc1x(iv_dimm, l_field));

            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::F1RC1X, i_efd, SET_DIMM_DDR4_F1RC1X, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_f1rc1x(l_field),
                                  F::F1RC1X.get_byte(i_efd),
                                  l_field,
                                  SET_DIMM_DDR4_F1RC1X,
                                  "F1RC1X"));

            FAPI_TRY(mss::attr::set_ddr4_f1rc1x(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the dimm ddr4 f1rc2x object
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dimm_ddr4_f1rc2x(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(mss::attr::get_ddr4_f1rc2x(iv_dimm, l_field));

            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::F1RC2X, i_efd, SET_DIMM_DDR4_F1RC2X, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_f1rc2x(l_field),
                                  F::F1RC2X.get_byte(i_efd),
                                  l_field,
                                  SET_DIMM_DDR4_F1RC2X,
                                  "F1RC2X"));

            FAPI_TRY(mss::attr::set_ddr4_f1rc2x(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the dimm ddr4 f1rc3x object
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dimm_ddr4_f1rc3x(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(mss::attr::get_ddr4_f1rc3x(iv_dimm, l_field));

            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::F1RC3X, i_efd, SET_DIMM_DDR4_F1RC3X, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_f1rc3x(l_field),
                                  F::F1RC3X.get_byte(i_efd),
                                  l_field,
                                  SET_DIMM_DDR4_F1RC3X,
                                  "F1RC3X"));

            FAPI_TRY(mss::attr::set_ddr4_f1rc3x(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the dimm ddr4 f1rc4x object
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dimm_ddr4_f1rc4x(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(mss::attr::get_ddr4_f1rc4x(iv_dimm, l_field));

            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::F1RC4X, i_efd, SET_DIMM_DDR4_F1RC4X, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_f1rc4x(l_field),
                                  F::F1RC4X.get_byte(i_efd),
                                  l_field,
                                  SET_DIMM_DDR4_F1RC4X,
                                  "F1RC4X"));

            FAPI_TRY(mss::attr::set_ddr4_f1rc4x(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the dimm ddr4 f1rc5x object
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dimm_ddr4_f1rc5x(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(mss::attr::get_ddr4_f1rc5x(iv_dimm, l_field));

            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::F1RC5X, i_efd, SET_DIMM_DDR4_F1RC5X, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_f1rc5x(l_field),
                                  F::F1RC5X.get_byte(i_efd),
                                  l_field,
                                  SET_DIMM_DDR4_F1RC5X,
                                  "F1RC5X"));

            FAPI_TRY(mss::attr::set_ddr4_f1rc5x(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the dimm ddr4 f1rc6x object
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dimm_ddr4_f1rc6x(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(mss::attr::get_ddr4_f1rc6x(iv_dimm, l_field));

            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::F1RC6X, i_efd, SET_DIMM_DDR4_F1RC6X, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_f1rc6x(l_field),
                                  F::F1RC6X.get_byte(i_efd),
                                  l_field,
                                  SET_DIMM_DDR4_F1RC6X,
                                  "F1RC6X"));

            FAPI_TRY(mss::attr::set_ddr4_f1rc6x(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the dimm ddr4 f1rc7x object
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dimm_ddr4_f1rc7x(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(mss::attr::get_ddr4_f1rc7x(iv_dimm, l_field));

            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::F1RC7X, i_efd, SET_DIMM_DDR4_F1RC7X, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_f1rc7x(l_field),
                                  F::F1RC7X.get_byte(i_efd),
                                  l_field,
                                  SET_DIMM_DDR4_F1RC7X,
                                  "F1RC7X"));

            FAPI_TRY(mss::attr::set_ddr4_f1rc7x(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the rcd slew rate field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_rcd_slew_rate(const std::vector<uint8_t>& i_efd) const
        {
            // Get the data
            uint16_t l_rcd_slew_rate = 0;
            uint8_t l_byte = 0;

            // In the EFD, byte0 is the LSB and byte1 is the MSB
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::RCD_SLEW_RATE_CTRL_1, i_efd, SET_RCD_SLEW_RATE, l_byte));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_rcd_slew_rate_ctrl_1(l_byte),
                                  F::RCD_SLEW_RATE_CTRL_1.get_byte(i_efd),
                                  l_byte,
                                  SET_RCD_SLEW_RATE,
                                  "RCD slew rate control Byte 1"));

            l_rcd_slew_rate = l_byte << BITS_PER_BYTE;
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::RCD_SLEW_RATE_CTRL_0, i_efd, SET_RCD_SLEW_RATE, l_byte));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_rcd_slew_rate_ctrl_0(l_byte),
                                  F::RCD_SLEW_RATE_CTRL_0.get_byte(i_efd),
                                  l_byte,
                                  SET_RCD_SLEW_RATE,
                                  "RCD slew rate control Byte 0"));

            l_rcd_slew_rate |= l_byte;

            // Set the attribute
            FAPI_TRY(mss::attr::set_exp_rcd_slew_rate(iv_dimm, l_rcd_slew_rate));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the cs cmd latency field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_cs_cmd_latency(const std::vector<uint8_t>& i_efd) const
        {
            // Get the data
            uint8_t l_cmd_latency = 0;
            uint8_t l_cmd_latency_key = 0;

            // Note: using a one-to-one mapping to allow us to re-use the API
            // We really just need to check that the value exists in the list
            const std::vector<std::pair<uint8_t, uint8_t>> ALLOWED_VALUES =
            {
                {0b0000, 0b0000},
                {0b0011, 0b0011},
                {0b0100, 0b0100},
                {0b0101, 0b0101},
                {0b0110, 0b0110},
                {0b1000, 0b1000},
            };

            FAPI_TRY(mss::attr::get_cs_cmd_latency(iv_dimm, l_cmd_latency));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::BIST_CA_LATENCY_MODE, i_efd, EFD_CA_LATENCY_MODE, l_cmd_latency_key));

            // Map EFD value to desired setting
            // Value and key should be the same thing, just creating a helper variable to avoid confusion
            FAPI_TRY(lookup_table_check(iv_dimm, ALLOWED_VALUES, EFD_CA_LATENCY_MODE, l_cmd_latency_key, l_cmd_latency));

            // Set the attribute
            FAPI_TRY(mss::attr::set_cs_cmd_latency(iv_dimm, l_cmd_latency));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the ca parity latency field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_ca_parity_latency(const std::vector<uint8_t>& i_efd) const
        {
            // Get the data
            uint8_t l_ca_parity_latency = 0;
            uint8_t l_ca_parity_latency_key = 0;

            // Note: using a one-to-one mapping to allow us to re-use the API
            // We really just need to check that the value exists in the list
            const std::vector<std::pair<uint8_t, uint8_t>> ALLOWED_VALUES =
            {
                {0b0000, 0b0000},
                {0b0100, 0b0100},
                {0b0101, 0b0101},
                {0b0110, 0b0110},
                {0b1000, 0b1000},
            };

            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::BIST_CA_PL_MODE, i_efd, EFD_CA_PL_MODE, l_ca_parity_latency_key));

            // Map EFD value to desired setting
            // Value and key should be the same thing, just creating a helper variable to avoid confusion if we return with a bad value and an RC
            FAPI_TRY(lookup_table_check(iv_dimm, ALLOWED_VALUES, EFD_CA_PL_MODE, l_ca_parity_latency_key, l_ca_parity_latency));

            // Set the attribute
            FAPI_TRY(mss::attr::set_ca_parity_latency(iv_dimm, l_ca_parity_latency));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the dfimrl ddrclk field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dfimrl_ddrclk(const std::vector<uint8_t>& i_efd) const
        {
            // Get the data
            uint8_t l_dfimrl_ddrclk = 0;

            FAPI_TRY(mss::attr::get_exp_dfimrl_clk(iv_port, l_dfimrl_ddrclk));

            // Update the values
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DFIMRL_DDRCLK, i_efd, SET_DFIMRL_DDRCLK, l_dfimrl_ddrclk));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_dfimrl_ddrclk(l_dfimrl_ddrclk),
                                  F::DFIMRL_DDRCLK.get_byte(i_efd),
                                  l_dfimrl_ddrclk,
                                  SET_DFIMRL_DDRCLK,
                                  "DFI Max RD Latency"));

            // Set the attribute
            FAPI_TRY(mss::attr::set_exp_dfimrl_clk(iv_port, l_dfimrl_ddrclk));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swa voltage offset field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swa_voltage_offset(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC0_SWA_OFFSET, i_efd, SET_PMIC0_SWA_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC0_SWA_OFFSET_DIRECTION, i_efd, SET_PMIC0_SWA_VOLTAGE_OFFSET,
                                             l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_offset(l_offset),
                                  F::PMIC0_SWA_OFFSET.get_byte(i_efd),
                                  l_offset,
                                  SET_PMIC0_SWA_VOLTAGE_OFFSET,
                                  "PMIC0 SWA Offset"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_offset_direction(l_direction),
                                  F::PMIC0_SWA_OFFSET_DIRECTION.get_byte(i_efd),
                                  l_direction,
                                  SET_PMIC0_SWA_VOLTAGE_OFFSET,
                                  "PMIC0 SWA Offset Direction"));

            {
                int8_t l_signed_offset = mss::pmic::convert_to_signed_offset(l_offset, l_direction);
                FAPI_TRY(mss::attr::set_efd_pmic0_swa_voltage_offset(iv_ocmb, l_signed_offset));
            }

        fapi_try_exit:
            return fapi2::current_err;
        }


        ///
        /// @brief Set the pmic0 swb voltage offset field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swb_voltage_offset(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC0_SWB_OFFSET, i_efd, SET_PMIC0_SWB_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC0_SWB_OFFSET_DIRECTION, i_efd, SET_PMIC0_SWB_VOLTAGE_OFFSET,
                                             l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_offset(l_offset),
                                  F::PMIC0_SWB_OFFSET.get_byte(i_efd),
                                  l_offset,
                                  SET_PMIC0_SWB_VOLTAGE_OFFSET,
                                  "PMIC0 SWB Offset"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_offset_direction(l_direction),
                                  F::PMIC0_SWB_OFFSET_DIRECTION.get_byte(i_efd),
                                  l_direction,
                                  SET_PMIC0_SWB_VOLTAGE_OFFSET,
                                  "PMIC0 SWB Offset Direction"));

            {
                int8_t l_signed_offset = mss::pmic::convert_to_signed_offset(l_offset, l_direction);
                FAPI_TRY(mss::attr::set_efd_pmic0_swb_voltage_offset(iv_ocmb, l_signed_offset));
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swc voltage offset field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swc_voltage_offset(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC0_SWC_OFFSET, i_efd, SET_PMIC0_SWC_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC0_SWC_OFFSET_DIRECTION, i_efd, SET_PMIC0_SWC_VOLTAGE_OFFSET,
                                             l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_offset(l_offset),
                                  F::PMIC0_SWC_OFFSET.get_byte(i_efd),
                                  l_offset,
                                  SET_PMIC0_SWC_VOLTAGE_OFFSET,
                                  "PMIC0 SWC Offset"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_offset_direction(l_direction),
                                  F::PMIC0_SWC_OFFSET_DIRECTION.get_byte(i_efd),
                                  l_direction,
                                  SET_PMIC0_SWC_VOLTAGE_OFFSET,
                                  "PMIC0 SWC Offset Direction"));

            {
                int8_t l_signed_offset = mss::pmic::convert_to_signed_offset(l_offset, l_direction);
                FAPI_TRY(mss::attr::set_efd_pmic0_swc_voltage_offset(iv_ocmb, l_signed_offset));
            }

        fapi_try_exit:
            return fapi2::current_err;
        }


        ///
        /// @brief Set the pmic0 swd voltage offset field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swd_voltage_offset(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC0_SWD_OFFSET, i_efd, SET_PMIC0_SWD_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC0_SWD_OFFSET_DIRECTION, i_efd, SET_PMIC0_SWD_VOLTAGE_OFFSET,
                                             l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_offset(l_offset),
                                  F::PMIC0_SWD_OFFSET.get_byte(i_efd),
                                  l_offset,
                                  SET_PMIC0_SWD_VOLTAGE_OFFSET,
                                  "PMIC0 SWD Offset"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_offset_direction(l_direction),
                                  F::PMIC0_SWD_OFFSET_DIRECTION.get_byte(i_efd),
                                  l_direction,
                                  SET_PMIC0_SWD_VOLTAGE_OFFSET,
                                  "PMIC0 SWD Offset Direction"));

            {
                int8_t l_signed_offset = mss::pmic::convert_to_signed_offset(l_offset, l_direction);
                FAPI_TRY(mss::attr::set_efd_pmic0_swd_voltage_offset(iv_ocmb, l_signed_offset));
            }

        fapi_try_exit:
            return fapi2::current_err;
        }


        ///
        /// @brief Set the pmic1 swa voltage offset field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swa_voltage_offset(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC1_SWA_OFFSET, i_efd, SET_PMIC1_SWA_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC1_SWA_OFFSET_DIRECTION, i_efd, SET_PMIC1_SWA_VOLTAGE_OFFSET,
                                             l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_offset(l_offset),
                                  F::PMIC1_SWA_OFFSET.get_byte(i_efd),
                                  l_offset,
                                  SET_PMIC1_SWA_VOLTAGE_OFFSET,
                                  "PMIC1 SWA Offset"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_offset_direction(l_direction),
                                  F::PMIC1_SWA_OFFSET_DIRECTION.get_byte(i_efd),
                                  l_direction,
                                  SET_PMIC1_SWA_VOLTAGE_OFFSET,
                                  "PMIC1 SWA Offset Direction"));

            {
                int8_t l_signed_offset = mss::pmic::convert_to_signed_offset(l_offset, l_direction);
                FAPI_TRY(mss::attr::set_efd_pmic1_swa_voltage_offset(iv_ocmb, l_signed_offset));
            }

        fapi_try_exit:
            return fapi2::current_err;
        }


        ///
        /// @brief Set the pmic1 swb voltage offset field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swb_voltage_offset(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC1_SWB_OFFSET, i_efd, SET_PMIC1_SWB_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC1_SWB_OFFSET_DIRECTION, i_efd, SET_PMIC1_SWB_VOLTAGE_OFFSET,
                                             l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_offset(l_offset),
                                  F::PMIC1_SWB_OFFSET.get_byte(i_efd),
                                  l_offset,
                                  SET_PMIC1_SWB_VOLTAGE_OFFSET,
                                  "PMIC1 SWB Offset"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_offset_direction(l_direction),
                                  F::PMIC1_SWB_OFFSET_DIRECTION.get_byte(i_efd),
                                  l_direction,
                                  SET_PMIC1_SWB_VOLTAGE_OFFSET,
                                  "PMIC1 SWB Offset Direction"));

            {
                int8_t l_signed_offset = mss::pmic::convert_to_signed_offset(l_offset, l_direction);
                FAPI_TRY(mss::attr::set_efd_pmic1_swb_voltage_offset(iv_ocmb, l_signed_offset));
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swc voltage offset field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swc_voltage_offset(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC1_SWC_OFFSET, i_efd, SET_PMIC1_SWC_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC1_SWC_OFFSET_DIRECTION, i_efd, SET_PMIC1_SWC_VOLTAGE_OFFSET,
                                             l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_offset(l_offset),
                                  F::PMIC1_SWC_OFFSET.get_byte(i_efd),
                                  l_offset,
                                  SET_PMIC1_SWC_VOLTAGE_OFFSET,
                                  "PMIC1 SWC Offset"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_offset_direction(l_direction),
                                  F::PMIC1_SWC_OFFSET_DIRECTION.get_byte(i_efd),
                                  l_direction,
                                  SET_PMIC1_SWC_VOLTAGE_OFFSET,
                                  "PMIC1 SWC Offset Direction"));

            {
                int8_t l_signed_offset = mss::pmic::convert_to_signed_offset(l_offset, l_direction);
                FAPI_TRY(mss::attr::set_efd_pmic1_swc_voltage_offset(iv_ocmb, l_signed_offset));
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swd voltage offset field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swd_voltage_offset(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC1_SWD_OFFSET, i_efd, SET_PMIC1_SWD_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC1_SWD_OFFSET_DIRECTION, i_efd, SET_PMIC1_SWD_VOLTAGE_OFFSET,
                                             l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_offset(l_offset),
                                  F::PMIC1_SWD_OFFSET.get_byte(i_efd),
                                  l_offset,
                                  SET_PMIC1_SWD_VOLTAGE_OFFSET,
                                  "PMIC1 SWD Offset"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_offset_direction(l_direction),
                                  F::PMIC1_SWD_OFFSET_DIRECTION.get_byte(i_efd),
                                  l_direction,
                                  SET_PMIC1_SWD_VOLTAGE_OFFSET,
                                  "PMIC1 SWD Offset Direction"));

            {
                int8_t l_signed_offset = mss::pmic::convert_to_signed_offset(l_offset, l_direction);
                FAPI_TRY(mss::attr::set_efd_pmic1_swd_voltage_offset(iv_ocmb, l_signed_offset));
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swa current warning field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swa_current_warning(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_warning = 0;
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC0_SWA_CURRENT_WARNING, i_efd, SET_PMIC0_SWA_CURRENT_WARNING,
                                             l_warning));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_current_warning(l_warning),
                                  F::PMIC0_SWA_CURRENT_WARNING.get_byte(i_efd),
                                  l_warning,
                                  SET_PMIC0_SWA_CURRENT_WARNING,
                                  "PMIC0 SWA Current Consumption Warning Threshold"));

            FAPI_TRY(mss::attr::set_pmic0_swa_current_warning(iv_ocmb, l_warning));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swb current warning field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swb_current_warning(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_warning = 0;
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC0_SWB_CURRENT_WARNING, i_efd, SET_PMIC0_SWB_CURRENT_WARNING,
                                             l_warning));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_current_warning(l_warning),
                                  F::PMIC0_SWB_CURRENT_WARNING.get_byte(i_efd),
                                  l_warning,
                                  SET_PMIC0_SWB_CURRENT_WARNING,
                                  "PMIC0 SWB Current Consumption Warning Threshold"));

            FAPI_TRY(mss::attr::set_pmic0_swb_current_warning(iv_ocmb, l_warning));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swc current warning field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swc_current_warning(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_warning = 0;
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC0_SWC_CURRENT_WARNING, i_efd, SET_PMIC0_SWC_CURRENT_WARNING,
                                             l_warning));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_current_warning(l_warning),
                                  F::PMIC0_SWC_CURRENT_WARNING.get_byte(i_efd),
                                  l_warning,
                                  SET_PMIC0_SWC_CURRENT_WARNING,
                                  "PMIC0 SWC Current Consumption Warning Threshold"));

            FAPI_TRY(mss::attr::set_pmic0_swc_current_warning(iv_ocmb, l_warning));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swd current warning field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swd_current_warning(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_warning = 0;
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC0_SWD_CURRENT_WARNING, i_efd, SET_PMIC0_SWD_CURRENT_WARNING,
                                             l_warning));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_current_warning(l_warning),
                                  F::PMIC0_SWD_CURRENT_WARNING.get_byte(i_efd),
                                  l_warning,
                                  SET_PMIC0_SWD_CURRENT_WARNING,
                                  "PMIC0 SWD Current Consumption Warning Threshold"));

            FAPI_TRY(mss::attr::set_pmic0_swd_current_warning(iv_ocmb, l_warning));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swa current warning field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swa_current_warning(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_warning = 0;
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC1_SWA_CURRENT_WARNING, i_efd, SET_PMIC1_SWA_CURRENT_WARNING,
                                             l_warning));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_current_warning(l_warning),
                                  F::PMIC1_SWA_CURRENT_WARNING.get_byte(i_efd),
                                  l_warning,
                                  SET_PMIC1_SWA_CURRENT_WARNING,
                                  "PMIC1 SWA Current Consumption Warning Threshold"));

            FAPI_TRY(mss::attr::set_pmic1_swa_current_warning(iv_ocmb, l_warning));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swb current warning field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swb_current_warning(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_warning = 0;
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC1_SWB_CURRENT_WARNING, i_efd, SET_PMIC1_SWB_CURRENT_WARNING,
                                             l_warning));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_current_warning(l_warning),
                                  F::PMIC1_SWB_CURRENT_WARNING.get_byte(i_efd),
                                  l_warning,
                                  SET_PMIC1_SWB_CURRENT_WARNING,
                                  "PMIC1 SWB Current Consumption Warning Threshold"));

            FAPI_TRY(mss::attr::set_pmic1_swb_current_warning(iv_ocmb, l_warning));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swc current warning field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swc_current_warning(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_warning = 0;
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC1_SWC_CURRENT_WARNING, i_efd, SET_PMIC1_SWC_CURRENT_WARNING,
                                             l_warning));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_current_warning(l_warning),
                                  F::PMIC1_SWC_CURRENT_WARNING.get_byte(i_efd),
                                  l_warning,
                                  SET_PMIC1_SWC_CURRENT_WARNING,
                                  "PMIC1 SWC Current Consumption Warning Threshold"));

            FAPI_TRY(mss::attr::set_pmic1_swc_current_warning(iv_ocmb, l_warning));

        fapi_try_exit:
            return fapi2::current_err;
        }


        ///
        /// @brief Set the pmic1 swd current warning field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swd_current_warning(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_warning = 0;
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC1_SWD_CURRENT_WARNING, i_efd, SET_PMIC1_SWD_CURRENT_WARNING,
                                             l_warning));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_current_warning(l_warning),
                                  F::PMIC1_SWD_CURRENT_WARNING.get_byte(i_efd),
                                  l_warning,
                                  SET_PMIC1_SWD_CURRENT_WARNING,
                                  "PMIC1 SWD Current Consumption Warning Threshold"));

            FAPI_TRY(mss::attr::set_pmic1_swd_current_warning(iv_ocmb, l_warning));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Get the si mc rcv imp dq dqs map
        ///
        /// @return ODT_IMP map
        /// @note 0.3 revision version
        ///
        virtual std::vector<std::pair<uint8_t, uint8_t>> get_si_mc_rcv_imp_dq_dqs_map() const
        {
            // std::vector when returned will be std::move'd instead of copied, but HB likely will not
            // do this. So, we may need to revisit if the copy proves to be too slow/costly

            // Make this static so we don't have to rebuild it each time this is called
            const std::vector< std::pair<uint8_t, uint8_t> > ODT_IMP_MAP_0_3 =
            {
                // {key byte, PHY ODT IMP (ohms)}
                {0b0000, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_DISABLE},
                {0b0001, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_40},
                {0b0010, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_60},
                {0b0011, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_80},
                {0b0100, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_120},
                {0b0101, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_240},

                // All others reserved
            };

            return ODT_IMP_MAP_0_3;
        }

        ///
        /// @brief Set the si mc rcv imp dq dqs field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        /// @note Rev 0.3 version
        ///
        virtual fapi2::ReturnCode set_si_mc_rcv_imp_dq_dqs(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field[mss::exp::sizes::MAX_RANK_PER_DIMM] = {0};
            uint8_t l_odt_impedance = 0;

            FAPI_TRY(mss::attr::get_si_mc_rcv_imp_dq_dqs(iv_dimm, l_field));

            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PHY_ODT_IMPEDANCE, i_efd, mss::SET_SI_MC_RCV_IMP_DQ_DQS, l_odt_impedance));
            FAPI_TRY(lookup_table_check(iv_ocmb, get_si_mc_rcv_imp_dq_dqs_map(), mss::SET_SI_MC_RCV_IMP_DQ_DQS, l_odt_impedance,
                                        l_field[iv_dimm_rank]));

            FAPI_TRY(mss::attr::set_si_mc_rcv_imp_dq_dqs(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the si mc drv imp dq dqs pull up field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_si_mc_drv_imp_dq_dqs_pull_up(const std::vector<uint8_t>& i_efd) const
        {
            uint16_t l_field[mss::exp::sizes::MAX_RANK_PER_DIMM] = {0};
            uint8_t l_phy_drv_imp_pu = 0;

            const std::vector< std::pair<uint16_t, uint16_t> > PHY_DRV_IMP_PU_MAP =
            {
                // {key byte, DRV IMP PU (ohms)}
                {0b000000, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_DISABLE},
                {0b000001, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_28},
                {0b000010, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_30},
                {0b000011, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_32},
                {0b000100, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_34},
                {0b000101, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_36},
                {0b000110, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_40},
                {0b000111, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_43},
                {0b001000, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_48},
                {0b001001, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_53},
                {0b001010, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_60},
                {0b001011, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_68},
                {0b001100, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_80},
                {0b001101, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_96},
                {0b001110, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_120},
                {0b001111, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_160},
                {0b010000, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_240},
                {0b010001, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_480},

                // All others reserved
            };

            FAPI_TRY(mss::attr::get_si_mc_drv_imp_dq_dqs_pull_up(iv_dimm, l_field));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PHY_DRIVE_IMPEDANCE_PULL_UP, i_efd, mss::SET_SI_MC_DRV_IMP_DQ_DQS_PULL_UP,
                                             l_phy_drv_imp_pu));

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, PHY_DRV_IMP_PU_MAP, mss::SET_SI_MC_DRV_IMP_DQ_DQS_PULL_UP,
                                        static_cast<uint16_t>(l_phy_drv_imp_pu), l_field[iv_dimm_rank]));


            FAPI_TRY(mss::attr::set_si_mc_drv_imp_dq_dqs_pull_up(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the si mc drv imp dq dqs pull down field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_si_mc_drv_imp_dq_dqs_pull_down(const std::vector<uint8_t>& i_efd) const
        {
            uint16_t l_field[mss::exp::sizes::MAX_RANK_PER_DIMM] = {0};
            uint8_t l_phy_drv_imp_pd = 0;

            const std::vector< std::pair<uint16_t, uint16_t> > PHY_DRV_IMP_PD_MAP =
            {
                // {key byte, DRV IMP PD (ohms)}
                {0b000000, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_DISABLE},
                {0b000001, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_28},
                {0b000010, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_30},
                {0b000011, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_32},
                {0b000100, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_34},
                {0b000101, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_36},
                {0b000110, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_40},
                {0b000111, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_43},
                {0b001000, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_48},
                {0b001001, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_53},
                {0b001010, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_60},
                {0b001011, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_68},
                {0b001100, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_80},
                {0b001101, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_96},
                {0b001110, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_120},
                {0b001111, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_160},
                {0b010000, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_240},
                {0b010001, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_480},

                // All others reserved
            };

            FAPI_TRY(mss::attr::get_si_mc_drv_imp_dq_dqs_pull_down(iv_dimm, l_field));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PHY_DRIVE_IMPEDANCE_PULL_DOWN, i_efd,
                                             mss::SET_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN, l_phy_drv_imp_pd));

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, PHY_DRV_IMP_PD_MAP, mss::SET_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN,
                                        static_cast<uint16_t>(l_phy_drv_imp_pd), l_field[iv_dimm_rank]));

            FAPI_TRY(mss::attr::set_si_mc_drv_imp_dq_dqs_pull_down(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the si mc drv slew rate dq dqs field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_si_mc_drv_slew_rate_dq_dqs(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field[mss::exp::sizes::MAX_RANK_PER_DIMM] = {0};
            FAPI_TRY(mss::attr::get_si_mc_drv_slew_rate_dq_dqs(iv_dimm, l_field));

            // Processing here
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PHY_SLEW_RATE_DQ_DQS, i_efd, mss::SET_SI_MC_DRV_SLEW_RATE_DQ_DQS,
                                             l_field[iv_dimm_rank]));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_phy_slew_rate_dq_dqs(l_field[iv_dimm_rank]),
                                  F::PHY_SLEW_RATE_DQ_DQS.get_byte(i_efd),
                                  l_field[iv_dimm_rank],
                                  SET_SI_MC_DRV_SLEW_RATE_DQ_DQS,
                                  "PHY Slew Rate DQ_DQS"));

            FAPI_TRY(mss::attr::set_si_mc_drv_slew_rate_dq_dqs(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the si mc drv imp cmd addr field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_si_mc_drv_imp_cmd_addr(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field[mss::exp::sizes::MAX_RANK_PER_DIMM] = {0};
            uint8_t l_atx_impedance = 0;

            const std::vector< std::pair<uint8_t, uint8_t> > ATX_IMP_MAP =
            {
                // {key byte, ATX IMP (ohm)}
                {0b0000, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_DISABLE},
                {0b0001, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_OHM_20},
                {0b0010, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_OHM_24},
                {0b0011, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_OHM_30},
                {0b0100, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_OHM_40},
                {0b0101, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_OHM_60},
                {0b0110, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_OHM_120},

                // All others reserved
            };

            FAPI_TRY(mss::attr::get_si_mc_drv_imp_cmd_addr(iv_dimm, l_field));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ATX_IMPEDANCE, i_efd, mss::SET_SI_MC_DRV_IMP_CMD_ADDR, l_atx_impedance));

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, ATX_IMP_MAP, mss::SET_SI_MC_DRV_IMP_CMD_ADDR, l_atx_impedance,
                                        l_field[iv_dimm_rank]));

            FAPI_TRY(mss::attr::set_si_mc_drv_imp_cmd_addr(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the si mc drv slew rate cmd addr field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_si_mc_drv_slew_rate_cmd_addr(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field[mss::exp::sizes::MAX_RANK_PER_DIMM] = {0};
            FAPI_TRY(mss::attr::get_si_mc_drv_slew_rate_cmd_addr(iv_dimm, l_field));

            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ATX_SLEW_RATE, i_efd, mss::SET_SI_MC_DRV_SLEW_RATE_CMD_ADDR,
                                             l_field[iv_dimm_rank]));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_atx_slew_rate(l_field[iv_dimm_rank]),
                                  F::ATX_SLEW_RATE.get_byte(i_efd),
                                  l_field[iv_dimm_rank],
                                  SET_SI_MC_DRV_SLEW_RATE_CMD_ADDR,
                                  "ATX Slew rate"));

            FAPI_TRY(mss::attr::set_si_mc_drv_slew_rate_cmd_addr(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the si mc drv imp clk field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_si_mc_drv_imp_clk(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field[mss::exp::sizes::MAX_RANK_PER_DIMM] = {0};
            uint8_t l_ck_impedance = 0;

            const std::vector< std::pair<uint8_t, uint8_t> > CK_IMP_MAP =
            {
                // {key byte, CK IMP (ohm)}
                {0b0000, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CLK_DISABLE},
                {0b0001, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CLK_OHM_20},
                {0b0010, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CLK_OHM_24},
                {0b0011, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CLK_OHM_30},
                {0b0100, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CLK_OHM_40},
                {0b0101, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CLK_OHM_60},
                {0b0110, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CLK_OHM_120},

                // All others reserved
            };

            FAPI_TRY(mss::attr::get_si_mc_drv_imp_clk(iv_dimm, l_field));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::CK_IMPEDANCE, i_efd, mss::SET_SI_MC_DRV_IMP_CLK, l_ck_impedance));

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, CK_IMP_MAP, mss::SET_SI_MC_DRV_IMP_CLK, l_ck_impedance, l_field[iv_dimm_rank]));

            FAPI_TRY(mss::attr::set_si_mc_drv_imp_clk(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the si mc drv slew rate clk field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_si_mc_drv_slew_rate_clk(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field[mss::exp::sizes::MAX_RANK_PER_DIMM] = {0};
            FAPI_TRY(mss::attr::get_si_mc_drv_slew_rate_clk(iv_dimm, l_field));

            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::CK_SLEW_RATE, i_efd, mss::SET_SI_MC_DRV_SLEW_RATE_CLK,
                                             l_field[iv_dimm_rank]));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_ck_slew_rate(l_field[iv_dimm_rank]),
                                  F::CK_SLEW_RATE.get_byte(i_efd),
                                  l_field[iv_dimm_rank],
                                  SET_SI_MC_DRV_SLEW_RATE_CLK,
                                  "CK Slew rate"));

            FAPI_TRY(mss::attr::set_si_mc_drv_slew_rate_clk(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the si mc rcv imp alert n field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_si_mc_rcv_imp_alert_n(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field[mss::exp::sizes::MAX_RANK_PER_DIMM] = {0};
            uint8_t l_alert_odt_imp = 0;

            const std::vector< std::pair<uint8_t, uint8_t> > ALERT_ODT_IMP_MAP =
            {
                // {key byte, ALERT ODT IMP (ohms)}
                {0b0000, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_ALERT_N_DISABLE},
                {0b0001, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_ALERT_N_OHM_40},
                {0b0010, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_ALERT_N_OHM_48},
                {0b0011, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_ALERT_N_OHM_60},
                {0b0100, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_ALERT_N_OHM_80},
                {0b0101, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_ALERT_N_OHM_120},
                {0b0110, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_ALERT_N_OHM_240},

                // All others reserved
            };

            FAPI_TRY(mss::attr::get_si_mc_rcv_imp_alert_n(iv_dimm, l_field));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ALERT_ODT_IMPEDANCE, i_efd, mss::SET_SI_MC_RCV_IMP_ALERT_N,
                                             l_alert_odt_imp));

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, ALERT_ODT_IMP_MAP, mss::SET_SI_MC_RCV_IMP_ALERT_N, l_alert_odt_imp,
                                        l_field[iv_dimm_rank]));
            FAPI_TRY(mss::attr::set_si_mc_rcv_imp_alert_n(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the si dram rtt nom field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_si_dram_rtt_nom(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field[mss::exp::sizes::MAX_RANK_PER_DIMM] = {0};
            uint8_t l_rtt_nom = 0;

            const std::vector< std::pair<uint8_t, uint8_t> > RTT_NOM_MAP =
            {
                {0b0000, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_NOM_DISABLE},
                {0b0001, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_NOM_OHM34},
                {0b0010, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_NOM_OHM40},
                {0b0011, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_NOM_OHM60},
                {0b0100, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_NOM_OHM80},
                {0b0101, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_NOM_OHM120},
                {0b0110, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_NOM_OHM240},
                // All others reserved
            };

            FAPI_TRY(mss::attr::get_si_dram_rtt_nom(iv_dimm, l_field));

            // Switch on the PHY rank as our SI information is stored in terms of the PHY rank perspective
            switch(iv_phy_rank)
            {
                case 0:
                    FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_NOM_RANK0, i_efd, mss::SET_SI_DRAM_RTT_NOM, l_rtt_nom));
                    break;

                case 1:
                    FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_NOM_RANK1, i_efd, mss::SET_SI_DRAM_RTT_NOM, l_rtt_nom));
                    break;

                case 2:
                    FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_NOM_RANK2, i_efd, mss::SET_SI_DRAM_RTT_NOM, l_rtt_nom));
                    break;

                case 3:
                    FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_NOM_RANK3, i_efd, mss::SET_SI_DRAM_RTT_NOM, l_rtt_nom));
                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::MSS_INVALID_SPD_RANK().
                                set_FUNCTION(SET_SI_DRAM_RTT_NOM).
                                set_PHY_RANK(iv_phy_rank).
                                set_PORT_TARGET(iv_port).
                                set_DIMM_TARGET(iv_dimm),
                                "%s SPD decoder returned invalid PHY rank: %u in %s",
                                spd::c_str(iv_dimm),
                                iv_phy_rank,
                                "RTT_NOM");
                    break;
            };

            // We store the data in terms of the DIMM rank as the attributes are encoded in terms of the IBM perspective
            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, RTT_NOM_MAP, mss::SET_SI_DRAM_RTT_NOM, l_rtt_nom, l_field[iv_dimm_rank]));

            FAPI_TRY(mss::attr::set_si_dram_rtt_nom(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the si dram rtt wr field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_si_dram_rtt_wr(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field[mss::exp::sizes::MAX_RANK_PER_DIMM] = {0};
            uint8_t l_rtt_wr = 0;

            const std::vector< std::pair<uint8_t, uint8_t> > RTT_WR_MAP =
            {
                {0b0000, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_WR_DISABLE},
                {0b0001, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_WR_OHM80},
                {0b0010, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_WR_OHM120},
                {0b0011, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_WR_OHM240},
                // All others reserved
            };

            FAPI_TRY(mss::attr::get_si_dram_rtt_wr(iv_dimm, l_field));

            // Switch on the PHY rank as our SI information is stored in terms of the PHY rank perspective
            switch(iv_phy_rank)
            {
                case 0:
                    FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_WR_RANK0, i_efd, mss::SET_SI_DRAM_RTT_WR, l_rtt_wr));
                    break;

                case 1:
                    FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_WR_RANK1, i_efd, mss::SET_SI_DRAM_RTT_WR, l_rtt_wr));
                    break;

                case 2:
                    FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_WR_RANK2, i_efd, mss::SET_SI_DRAM_RTT_WR, l_rtt_wr));
                    break;

                case 3:
                    FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_WR_RANK3, i_efd, mss::SET_SI_DRAM_RTT_WR, l_rtt_wr));
                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::MSS_INVALID_SPD_RANK().
                                set_FUNCTION(SET_SI_DRAM_RTT_WR).
                                set_PHY_RANK(iv_phy_rank).
                                set_PORT_TARGET(iv_port).
                                set_DIMM_TARGET(iv_dimm),
                                "%s SPD decoder returned invalid PHY rank: %u in %s",
                                spd::c_str(iv_dimm),
                                iv_phy_rank,
                                "RTT_WR");
                    break;
            };

            // We store the data in terms of the DIMM rank as the attributes are encoded in terms of the IBM perspective
            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, RTT_WR_MAP, mss::SET_SI_DRAM_RTT_WR, l_rtt_wr, l_field[iv_dimm_rank]));

            FAPI_TRY(mss::attr::set_si_dram_rtt_wr(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the si dram rtt park field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_si_dram_rtt_park(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field[mss::exp::sizes::MAX_RANK_PER_DIMM] = {0};
            uint8_t l_rtt_park = 0;

            const std::vector< std::pair<uint8_t, uint8_t> > RTT_PARK_MAP =
            {
                // {key byte, RTT PARK (ohms)}
                {0b0000, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_PARK_DISABLE},
                {0b0001, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_PARK_OHM34},
                {0b0010, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_PARK_OHM40},
                {0b0011, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_PARK_OHM48},
                {0b0100, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_PARK_OHM60},
                {0b0101, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_PARK_OHM80},
                {0b0110, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_PARK_OHM120},
                {0b0111, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_PARK_OHM240},
                // All others reserved
            };

            FAPI_TRY(mss::attr::get_si_dram_rtt_park(iv_dimm, l_field));

            // Switch on the PHY rank as our SI information is stored in terms of the PHY rank perspective
            switch(iv_phy_rank)
            {
                case 0:
                    FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_PARK_RANK0, i_efd, mss::SET_SI_DRAM_RTT_PARK, l_rtt_park));
                    break;

                case 1:
                    FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_PARK_RANK1, i_efd, mss::SET_SI_DRAM_RTT_PARK, l_rtt_park));
                    break;

                case 2:
                    FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_PARK_RANK2, i_efd, mss::SET_SI_DRAM_RTT_PARK, l_rtt_park));
                    break;

                case 3:
                    FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_PARK_RANK3, i_efd, mss::SET_SI_DRAM_RTT_PARK, l_rtt_park));
                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::MSS_INVALID_SPD_RANK().
                                set_FUNCTION(SET_SI_DRAM_RTT_PARK).
                                set_PHY_RANK(iv_phy_rank).
                                set_PORT_TARGET(iv_port).
                                set_DIMM_TARGET(iv_dimm),
                                "%s SPD decoder returned invalid PHY rank: %u in %s",
                                spd::c_str(iv_dimm),
                                iv_phy_rank,
                                "RTT_PARK");
                    break;
            };

            // We store the data in terms of the DIMM rank as the attributes are encoded in terms of the IBM perspective
            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, RTT_PARK_MAP, mss::SET_SI_DRAM_RTT_PARK, l_rtt_park, l_field[iv_dimm_rank]));

            FAPI_TRY(mss::attr::set_si_dram_rtt_park(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the si dram preamble field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_si_dram_preamble(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field[mss::exp::sizes::MAX_RANK_PER_DIMM] = {0};
            uint8_t l_read_preamble = 0;
            uint8_t l_write_preamble = 0;

            FAPI_TRY(mss::attr::get_si_dram_preamble(iv_dimm, l_field));

            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::READ_PREAMBLE, i_efd, mss::SET_SI_DRAM_PREAMBLE, l_read_preamble));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::WRITE_PREAMBLE, i_efd, mss::SET_SI_DRAM_PREAMBLE, l_write_preamble));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_read_preamble(l_read_preamble),
                                  F::READ_PREAMBLE.get_byte(i_efd),
                                  l_read_preamble,
                                  SET_SI_DRAM_PREAMBLE,
                                  "Read Preamble"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_write_preamble(l_write_preamble),
                                  F::WRITE_PREAMBLE.get_byte(i_efd),
                                  l_write_preamble,
                                  SET_SI_DRAM_PREAMBLE,
                                  "Write Preamble"));

            l_field[iv_dimm_rank] = mss::gen::align_preamble_to_attr(l_read_preamble, l_write_preamble);

            FAPI_TRY(mss::attr::set_si_dram_preamble(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the phy_equalization field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_si_phy_equalization(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field[mss::exp::sizes::MAX_RANK_PER_DIMM] = {0};
            FAPI_TRY(mss::attr::get_si_phy_equalization(iv_dimm, l_field));

            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PHY_EQUALIZATION, i_efd, mss::SET_SI_PHY_EQUALIZATION,
                                             l_field[iv_dimm_rank]));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_phy_equalization(l_field[iv_dimm_rank]),
                                  F::PHY_EQUALIZATION.get_byte(i_efd),
                                  l_field[iv_dimm_rank],
                                  SET_SI_PHY_EQUALIZATION,
                                  "PHY Equalization"));

            FAPI_TRY(mss::attr::set_si_phy_equalization(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the si dram drv imp dq dqs field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_si_dram_drv_imp_dq_dqs(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field[mss::exp::sizes::MAX_RANK_PER_DIMM] = {0};
            uint8_t l_dram_dic = 0;

            const std::vector< std::pair<uint8_t, uint8_t> > DRAM_DIC_MAP =
            {
                // {key byte, DRAM DIC (ohms)}
                {0, fapi2::ENUM_ATTR_MEM_SI_DRAM_DRV_IMP_DQ_DQS_DISABLE},
                {1, fapi2::ENUM_ATTR_MEM_SI_DRAM_DRV_IMP_DQ_DQS_OHM34},
                {2, fapi2::ENUM_ATTR_MEM_SI_DRAM_DRV_IMP_DQ_DQS_OHM48},
            };

            FAPI_TRY(mss::attr::get_si_dram_drv_imp_dq_dqs(iv_dimm, l_field));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_DIC, i_efd, mss::SET_SI_DRAM_DRV_IMP_DQ_DQS, l_dram_dic));

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, DRAM_DIC_MAP, SET_SI_DRAM_DRV_IMP_DQ_DQS, l_dram_dic, l_field[iv_dimm_rank]));
            FAPI_TRY(mss::attr::set_si_dram_drv_imp_dq_dqs(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the si odt wr field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_si_odt_wr(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field[mss::exp::sizes::MAX_RANK_PER_DIMM] = {0};
            uint8_t l_si_odt_wr = 0;

            FAPI_TRY(mss::attr::get_si_odt_wr(iv_dimm, l_field));

            // Switch on the PHY rank as our SI information is stored in terms of the PHY rank perspective
            switch(iv_phy_rank)
            {
                case 0:
                    FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ODT_WR_MAP_RANK0, i_efd, mss::SET_SI_ODT_WR, l_si_odt_wr));
                    break;

                case 1:
                    FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ODT_WR_MAP_RANK1, i_efd, mss::SET_SI_ODT_WR, l_si_odt_wr));
                    break;

                case 2:
                    FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ODT_WR_MAP_RANK2, i_efd, mss::SET_SI_ODT_WR, l_si_odt_wr));
                    break;

                case 3:
                    FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ODT_WR_MAP_RANK3, i_efd, mss::SET_SI_ODT_WR, l_si_odt_wr));
                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::MSS_INVALID_SPD_RANK().
                                set_FUNCTION(SET_SI_ODT_WR).
                                set_PHY_RANK(iv_phy_rank).
                                set_PORT_TARGET(iv_port).
                                set_DIMM_TARGET(iv_dimm),
                                "%s SPD decoder returned invalid PHY rank: %u in %s",
                                spd::c_str(iv_dimm),
                                iv_phy_rank,
                                "ODT_WR");
                    break;
            };

            // In the interest of saving some space, this will still check the
            // correct field, but we'll use RANK0 for the FFDC so we don't
            // have to make 4 copies of this same check
            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_odt_map(l_si_odt_wr),
                                  F::ODT_WR_MAP_RANK0.get_byte(i_efd),
                                  l_si_odt_wr,
                                  SET_SI_ODT_WR,
                                  "ODT WR Map"));

            // We store the data in terms of the DIMM rank as the attributes are encoded in terms of the IBM perspective
            // Map to attribute bitmap
            l_field[iv_dimm_rank] = mss::gen::align_odt_field_to_attr(l_si_odt_wr);

            FAPI_TRY(mss::attr::set_si_odt_wr(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the si odt rd field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_si_odt_rd(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field[mss::exp::sizes::MAX_RANK_PER_DIMM] = {0};
            uint8_t l_si_odt_rd = 0;
            FAPI_TRY(mss::attr::get_si_odt_rd(iv_dimm, l_field));

            // Switch on the PHY rank as our SI information is stored in terms of the PHY rank perspective
            switch(iv_phy_rank)
            {
                case 0:
                    FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ODT_RD_MAP_RANK0, i_efd, mss::SET_SI_ODT_RD, l_si_odt_rd));
                    break;

                case 1:
                    FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ODT_RD_MAP_RANK1, i_efd, mss::SET_SI_ODT_RD, l_si_odt_rd));
                    break;

                case 2:
                    FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ODT_RD_MAP_RANK2, i_efd, mss::SET_SI_ODT_RD, l_si_odt_rd));
                    break;

                case 3:
                    FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ODT_RD_MAP_RANK3, i_efd, mss::SET_SI_ODT_RD, l_si_odt_rd));
                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::MSS_INVALID_SPD_RANK().
                                set_FUNCTION(SET_SI_ODT_RD).
                                set_PHY_RANK(iv_phy_rank).
                                set_PORT_TARGET(iv_port).
                                set_DIMM_TARGET(iv_dimm),
                                "%s SPD decoder returned invalid PHY rank: %u in %s",
                                spd::c_str(iv_dimm),
                                iv_phy_rank,
                                "ODT_RD");
                    break;
            };

            // In the interest of saving some space, this will still check the
            // correct field, but we'll use RANK0 for the FFDC so we don't
            // have to make 4 copies of this same check
            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_odt_map(l_si_odt_rd),
                                  F::ODT_RD_MAP_RANK0.get_byte(i_efd),
                                  l_si_odt_rd,
                                  SET_SI_ODT_RD,
                                  "ODT RD Map"));

            // We store the data in terms of the DIMM rank as the attributes are encoded in terms of the IBM perspective
            // Map to attribute bitmap
            l_field[iv_dimm_rank] = mss::gen::align_odt_field_to_attr(l_si_odt_rd);

            FAPI_TRY(mss::attr::set_si_odt_rd(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the si geardown mode field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_si_geardown_mode(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field[mss::exp::sizes::MAX_RANK_PER_DIMM] = {0};
            FAPI_TRY(mss::attr::get_si_geardown_mode(iv_dimm, l_field));

            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::GEARDOWN_DURING_TRAINING, i_efd, mss::SET_SI_GEARDOWN_MODE,
                                             l_field[iv_dimm_rank]));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_geardown_during_training(l_field[iv_dimm_rank]),
                                  F::GEARDOWN_DURING_TRAINING.get_byte(i_efd),
                                  l_field[iv_dimm_rank],
                                  SET_SI_GEARDOWN_MODE,
                                  "Geardown during training"));

            FAPI_TRY(mss::attr::set_si_geardown_mode(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }


        ///
        /// @brief Process the fields for ddimm efd rev 0.3
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode process(const std::vector<uint8_t>& i_efd) const
        {
            // Explorer EFD fields
            FAPI_TRY(set_cac_delay_a(i_efd));
            FAPI_TRY(set_cac_delay_b(i_efd));
            FAPI_TRY(set_init_vref_dq(i_efd));
            FAPI_TRY(set_init_phy_vref(i_efd));
            FAPI_TRY(set_rcd_dic(i_efd));
            FAPI_TRY(set_rcd_voltage_ctrl(i_efd));
            FAPI_TRY(set_dimm_ddr4_f0rc7x(i_efd));
            FAPI_TRY(set_dimm_ddr4_f1rc00(i_efd));
            FAPI_TRY(set_dimm_ddr4_f1rc1x(i_efd));
            FAPI_TRY(set_dimm_ddr4_f1rc2x(i_efd));
            FAPI_TRY(set_dimm_ddr4_f1rc3x(i_efd));
            FAPI_TRY(set_dimm_ddr4_f1rc4x(i_efd));
            FAPI_TRY(set_dimm_ddr4_f1rc5x(i_efd));
            FAPI_TRY(set_dimm_ddr4_f1rc6x(i_efd));
            FAPI_TRY(set_dimm_ddr4_f1rc7x(i_efd));
            FAPI_TRY(set_rcd_slew_rate(i_efd));
            FAPI_TRY(set_cs_cmd_latency(i_efd));
            FAPI_TRY(set_ca_parity_latency(i_efd));
            FAPI_TRY(set_dfimrl_ddrclk(i_efd));

            // PMIC EFD Fields do not change per rank, and only need to be run once
            if (iv_dimm_rank == 0)
            {
                FAPI_TRY(set_pmic0_swa_voltage_offset(i_efd));
                FAPI_TRY(set_pmic0_swb_voltage_offset(i_efd));
                FAPI_TRY(set_pmic0_swc_voltage_offset(i_efd));
                FAPI_TRY(set_pmic0_swd_voltage_offset(i_efd));
                FAPI_TRY(set_pmic1_swa_voltage_offset(i_efd));
                FAPI_TRY(set_pmic1_swb_voltage_offset(i_efd));
                FAPI_TRY(set_pmic1_swc_voltage_offset(i_efd));
                FAPI_TRY(set_pmic1_swd_voltage_offset(i_efd));

                FAPI_TRY(set_pmic0_swa_current_warning(i_efd));
                FAPI_TRY(set_pmic0_swb_current_warning(i_efd));
                FAPI_TRY(set_pmic0_swc_current_warning(i_efd));
                FAPI_TRY(set_pmic0_swd_current_warning(i_efd));
                FAPI_TRY(set_pmic1_swa_current_warning(i_efd));
                FAPI_TRY(set_pmic1_swb_current_warning(i_efd));
                FAPI_TRY(set_pmic1_swc_current_warning(i_efd));
                FAPI_TRY(set_pmic1_swd_current_warning(i_efd));
            }

            // SI attrs
            FAPI_TRY(set_si_mc_rcv_imp_dq_dqs(i_efd));
            FAPI_TRY(set_si_mc_drv_imp_dq_dqs_pull_up(i_efd));
            FAPI_TRY(set_si_mc_drv_imp_dq_dqs_pull_down(i_efd));
            FAPI_TRY(set_si_mc_drv_slew_rate_dq_dqs(i_efd));
            FAPI_TRY(set_si_mc_drv_imp_cmd_addr(i_efd));
            FAPI_TRY(set_si_mc_drv_slew_rate_cmd_addr(i_efd));
            FAPI_TRY(set_si_mc_drv_imp_clk(i_efd));
            FAPI_TRY(set_si_mc_drv_slew_rate_clk(i_efd));
            FAPI_TRY(set_si_mc_rcv_imp_alert_n(i_efd));
            FAPI_TRY(set_si_dram_rtt_nom(i_efd));
            FAPI_TRY(set_si_dram_rtt_wr(i_efd));
            FAPI_TRY(set_si_dram_rtt_park(i_efd));
            FAPI_TRY(set_si_dram_preamble(i_efd));
            FAPI_TRY(set_si_phy_equalization(i_efd));
            FAPI_TRY(set_si_dram_drv_imp_dq_dqs(i_efd));
            FAPI_TRY(set_si_odt_wr(i_efd));
            FAPI_TRY(set_si_odt_rd(i_efd));
            FAPI_TRY(set_si_geardown_mode(i_efd));

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }
};

///
/// @brief Class for base module section of EFD Rev 0.4
///
class ddimm_efd_0_4 : public ddimm_efd_0_3
{
        using F = mss::efd::fields<mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>;

    public:
        ///
        /// @brief Construct a new ddimm efd rev 0.4 object
        ///
        /// @param[in] i_dimm DIMM target
        /// @param[in] i_rank_info the current rank info class
        ///
        ddimm_efd_0_4(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
                      const mss::rank::info<mss::mc_type::EXPLORER>& i_rank_info)
            : ddimm_efd_0_3(i_dimm, i_rank_info)
        {
        }

        virtual ~ddimm_efd_0_4() = default;

        ///
        /// @brief Traits for pmic rail current warning
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        /// @note 0.4 revision version
        ///
        virtual bool check_pmic_rail_current_warning(const uint8_t i_field) const override
        {
            // Mask to ensure bits 6 amd 7 are unset
            constexpr uint8_t REVERSE_MASK = 0x03;
            return ((i_field & REVERSE_MASK) == 0x00);
        }

        ///
        /// @brief Traits for rcd dic 1
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        /// @note 0.4 revision version
        ///
        virtual bool check_rcd_dic_1(const uint8_t i_field) const
        {
            return (i_field <= 0x0F);
        }

        ///
        /// @brief Traits for rcd dic 0
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        /// @note 0.4 revision version
        ///
        virtual bool check_rcd_dic_0(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits for rcd voltage ctrl 0
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        /// @note 0.4 revision version
        ///
        virtual bool check_rcd_voltage_ctrl_0(const uint8_t i_field) const
        {
            return (i_field <= 0x0F);
        }

        ///
        /// @brief Traits for rcd voltage ctrl 1
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        /// @note 0.4 revision version
        ///
        virtual bool check_rcd_voltage_ctrl_1(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits for rcd db dic
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        /// @note 0.4 revision version
        ///
        virtual bool check_rcd_db_dic(const uint8_t i_field) const
        {
            // Mask to ensure bits 0-4 and 6 are unset
            constexpr uint8_t REVERSE_MASK = 0xFA;
            return ((i_field & REVERSE_MASK) == 0);
        }

        ///
        /// @brief Traits for f1rc1x
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        /// @note 0.4 revision version
        ///
        virtual bool check_f1rc1x(const uint8_t i_field) const override
        {
            return (i_field <= 0x9F);
        }

        ///
        /// @brief Traits for f1rc2x
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        /// @note 0.4 revision version
        ///
        virtual bool check_f1rc2x(const uint8_t i_field) const override
        {
            return (i_field <= 0x9F);
        }

        ///
        /// @brief Traits for f1rc3x
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        /// @note 0.4 revision version
        ///
        virtual bool check_f1rc3x(const uint8_t i_field) const override
        {
            return (i_field <= 0x9F);
        }

        ///
        /// @brief Traits for f1rc4x
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        /// @note 0.4 revision version
        ///
        virtual bool check_f1rc4x(const uint8_t i_field) const override
        {
            return (i_field <= 0x9F);
        }

        ///
        /// @brief Traits for f1rc5x
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        /// @note 0.4 revision version
        ///
        virtual bool check_f1rc5x(const uint8_t i_field) const override
        {
            return (i_field <= 0x9F);
        }

        ///
        /// @brief Traits for f1rc6x
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        /// @note 0.4 revision version
        ///
        virtual bool check_f1rc6x(const uint8_t i_field) const override
        {
            return (i_field <= 0xBF);
        }

        ///
        /// @brief Traits for f1rc7x
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        /// @note 0.4 revision version
        ///
        virtual bool check_f1rc7x(const uint8_t i_field) const override
        {
            return (i_field <= 0xBF);
        }

        ///
        /// @brief Traits for rcd slew rate ctrl 1
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        /// @note 0.4 revision version
        ///
        virtual bool check_rcd_slew_rate_ctrl_1(const uint8_t i_field) const override
        {
            // Masks to ensure no bit pair has both bits set
            constexpr uint8_t REVERSE_MASK_0 = 0xC0;
            constexpr uint8_t REVERSE_MASK_1 = 0x30;
            constexpr uint8_t REVERSE_MASK_2 = 0x0C;
            constexpr uint8_t REVERSE_MASK_3 = 0x03;

            const uint8_t MASK_RESULT_0 = i_field & REVERSE_MASK_0;
            const uint8_t MASK_RESULT_1 = i_field & REVERSE_MASK_1;
            const uint8_t MASK_RESULT_2 = i_field & REVERSE_MASK_2;
            const uint8_t MASK_RESULT_3 = i_field & REVERSE_MASK_3;

            return !(MASK_RESULT_0 == REVERSE_MASK_0 ||
                     MASK_RESULT_1 == REVERSE_MASK_1 ||
                     MASK_RESULT_2 == REVERSE_MASK_2 ||
                     MASK_RESULT_3 == REVERSE_MASK_3);
        }

        ///
        /// @brief Traits for rcd slew rate ctrl 0
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        /// @note 0.4 revision version
        ///
        virtual bool check_rcd_slew_rate_ctrl_0(const uint8_t i_field) const override
        {
            // Masks to ensure no bit pair has both bits set
            constexpr uint8_t REVERSE_MASK_0 = 0xC0;
            constexpr uint8_t REVERSE_MASK_1 = 0x30;
            constexpr uint8_t REVERSE_MASK_2 = 0x0C;
            constexpr uint8_t REVERSE_MASK_3 = 0x03;

            const uint8_t MASK_RESULT_0 = i_field & REVERSE_MASK_0;
            const uint8_t MASK_RESULT_1 = i_field & REVERSE_MASK_1;
            const uint8_t MASK_RESULT_2 = i_field & REVERSE_MASK_2;
            const uint8_t MASK_RESULT_3 = i_field & REVERSE_MASK_3;

            return !(MASK_RESULT_0 == REVERSE_MASK_0 ||
                     MASK_RESULT_1 == REVERSE_MASK_1 ||
                     MASK_RESULT_2 == REVERSE_MASK_2 ||
                     MASK_RESULT_3 == REVERSE_MASK_3);
        }

        // Virtual function overloads go here

        ///
        /// @brief Get the si mc rcv imp dq dqs map
        ///
        /// @return ODT_IMP map
        /// @note 0.4 revision version
        ///
        virtual std::vector<std::pair<uint8_t, uint8_t>> get_si_mc_rcv_imp_dq_dqs_map() const override
        {
            // std::vector when returned will be std::move'd instead of copied, but HB likely will not
            // do this. So, we may need to revisit if the copy proves to be too slow/costly

            // Make this static so we don't have to rebuild it each time this is called
            const std::vector< std::pair<uint8_t, uint8_t> > ODT_IMP_MAP_NEWER =
            {
                // {key byte, PHY ODT IMP (ohms)}
                {0b00000, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_DISABLE},
                {0b00001, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_40},
                {0b00010, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_48},
                {0b00011, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_60},
                {0b00100, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_80},
                {0b00101, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_120},
                {0b00110, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_240},

                // All others reserved
            };

            return ODT_IMP_MAP_NEWER;
        }

        /// @brief Process the fields for ddimm efd rev 0.4
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        fapi2::ReturnCode process(const std::vector<uint8_t>& i_efd) const
        {
            // The naming here is a bit tricky: 0.3 process will process fields
            // that originated in 0.3, but will use any field processors/traits
            // that were overridden for the current class type (ex. ddimm_efd_0_4)
            // (such as the f1rc?X traits and set_si_mc_rcv_imp_dq_dqs)

            // Only brand new fields for this revision should be explicitly
            // called here below the call to this function
            FAPI_TRY(ddimm_efd_0_3::process(i_efd));

            // DDIMM EFD Rev 0.4 new field processing goes here

        fapi_try_exit:
            return fapi2::current_err;
        }
};

//
// Can be updated with the earliest supported ddimm efd revision
//
using ddimm_efd_base = ddimm_efd_0_3;
using ddimm_efd_latest = ddimm_efd_0_4;

}// efd

}// mss

#endif
