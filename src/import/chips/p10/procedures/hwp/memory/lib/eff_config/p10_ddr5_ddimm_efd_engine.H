/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/eff_config/p10_ddr5_ddimm_efd_engine.H $ */
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
///
/// @file p10_ddr5_ddimm_efd_engine.H
/// @brief DDR5 DDIMM EFD eff_config engine
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP FW Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:CI
// EKB-Mirror-To: hostboot

#ifndef _P10_DDR5_DDIMM_EFD_ENGINE_H_
#define _P10_DDR5_DDIMM_EFD_ENGINE_H_

#include <cstring>
#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <lib/shared/ody_consts.H>
#include <generic/memory/lib/data_engine/data_engine_utils.H>
#include <generic/memory/lib/spd/spd_field.H>
#include <generic/memory/lib/spd/ddimm/ddr5/efd_fields_ddr5.H>
#include <generic/memory/lib/utils/find.H>

#include <mss_pmic_attribute_setters.H>
#include <mss_odyssey_attribute_setters.H>
#include <mss_generic_attribute_setters.H>
#include <lib/eff_config/p10_ddimm_efd_engine.H>
#include <generic/memory/lib/data_engine/data_engine.H>
#include <lib/dimm/ody_rank.H>


namespace mss
{
namespace efd
{
namespace ddr5
{

///
/// @brief Class for base EFD section of SPD - specifically DDR5
///
class ddimm_0_0 : public mss::efd::base
{
        static constexpr uint8_t DRAMINIT_NUM_ADDR_DELAYS = 8;

        using F = mss::efd::fields<mss::spd::device_type::DDR5, mss::efd::id::DDR5_CUSTOM_IBM>;

    protected:
        uint8_t iv_port_rel_pos;

    public:

        ///
        /// @brief Construct a new DDR5 DDIMM EFD rev 0.0 object
        /// @param[in] i_dimm DIMM target
        /// @param[in] i_dimm_rank the current DIMM rank to create rank info class
        /// @param[out] o_rc return code
        ///
        ddimm_0_0(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
                  const uint16_t i_dimm_rank,
                  fapi2::ReturnCode& o_rc) :
            base(i_dimm, o_rc)
        {

            // Had to move this creating rank info here from
            // base class because it is used for DDR4 and DDR5
            const mss::rank::info<mss::mc_type::ODYSSEY> l_rank_info(i_dimm, i_dimm_rank, o_rc);
            iv_dimm_rank = l_rank_info.get_dimm_rank();
            iv_efd_rank = l_rank_info.get_efd_rank();
            iv_port_rel_pos = mss::relative_pos<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>(iv_port);
        }

        ///
        /// @brief Destroy the ddimm_efd_0_3 object
        ///
        virtual ~ddimm_0_0() = default;

        ///
        /// @brief Get the spd revision
        /// @return mss::spd::rev enum value
        ///
        virtual mss::spd::rev get_spd_revision() const
        {
            return mss::spd::rev::V0_0;
        }

        ///
        /// @brief Get the DRAM generation
        /// @return DRAM generation value
        ///
        virtual uint8_t get_dram_generation() const
        {
            return fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR5;
        }

        // Check functions here return true when any value is valid (0x00 through 0xFF)

        ///
        /// @brief Traits pmic rail volt offset
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_pmic_rail_volt_off(const uint8_t i_field) const
        {
            return (i_field <= 0x3F);
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

        //
        /// @brief Traits for phy drv imp pull up
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        ///
        virtual bool check_phy_drv_imp_pu(const uint8_t i_field) const
        {
            return (i_field <= 0x11);
        }

        ///
        /// @brief Set the cac delay b field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_2n_mode(const std::vector<uint8_t>& i_efd) const
        {
            constexpr uint8_t FIELD_2N = 0;
            uint8_t l_field = 0;
            uint32_t l_omi_freq = 0;
            const auto& l_proc_chip = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(iv_ocmb);

            // =========================================================
            // EFD Byte 1: 2N Requirements
            // Attribute: ATTR_MEM_2N_MODE
            // MODE REG: MR2
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 137
            // =========================================================
            // The omi frequencies are 25600,32000,38400
            // Get the supported omi freq from attr to check for the 2N mode
            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_FREQ_OMI_MHZ, l_proc_chip, l_omi_freq) );

            if(l_omi_freq == fapi2::ENUM_ATTR_FREQ_OMI_MHZ_32000)
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::MODE_2N_REQUIREMENTS_32000, i_efd, SET_2N_MODE, l_field));
            }
            else if (l_omi_freq == fapi2::ENUM_ATTR_FREQ_OMI_MHZ_38400)
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::MODE_2N_REQUIREMENTS_38400, i_efd, SET_2N_MODE, l_field));
            }
            else
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::MODE_2N_REQUIREMENTS_25600, i_efd, SET_2N_MODE, l_field));
            }

            // Convert from the field description to the attribute value
            // For the field, a value of 0 indicates 2N mode while a value of a 1 indicates 1N mode
            l_field = l_field == FIELD_2N ? fapi2::ENUM_ATTR_MEM_2N_MODE_2N : fapi2::ENUM_ATTR_MEM_2N_MODE_1N;

            // Set the attr
            FAPI_TRY(mss::attr::set_mem_2n_mode(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the init phy vref dq fields
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_init_phy_vref_dq(const std::vector<uint8_t>& i_efd) const
        {

            uint8_t l_field = 0;

            // =========================================================
            // EFD Byte 3-4: Initial Phy0 and PHY1 VRef Setting
            // Attribute: ATTR_MEM_EFF_DDR5_PHY_VREF_RD
            // MODE REG: MR5
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 138
            // =========================================================

            if(iv_port_rel_pos == 0)
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PHY0_CHANNELS_VREF, i_efd, SET_PHY0_VREF, l_field));
            }
            else
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PHY1_CHANNELS_VREF, i_efd, SET_PHY1_VREF, l_field));
            }

            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_phy_vref_rd(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the DRAM Pullup drv impedance
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dram_pu_drv_imp(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_dram_pu_drv_imp = 0;
            uint8_t l_field[mss::ddr5::mr::ATTR_RANKS] = {0};

            // =========================================================
            // EFD Byte 5: DRAM DIC
            // Attribute: ATTR_DRAM_PU_DRV_IMP
            // MODE REG: MR5
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 138
            // =========================================================
            static const std::vector< std::pair<uint8_t, uint8_t> > DRAM_PU_DRV_IMP_MAP =
            {
                // {key byte, PHY DRIVE IMP PULL UP VAL (ohms)}
                {0b0001, fapi2::ENUM_ATTR_DRAM_PU_DRV_IMP_OHM_34},
                {0b0010, fapi2::ENUM_ATTR_DRAM_PU_DRV_IMP_OHM_40},
                {0b0011, fapi2::ENUM_ATTR_DRAM_PU_DRV_IMP_OHM_48},
                // All others reserved/not used for DDR5
            };

            FAPI_TRY(mss::attr::get_dram_pu_drv_imp(iv_dimm, l_field));

            // Get the field value from i_efd into l_phy_drv_imp_pu
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_DIC_PULLUP, i_efd, mss::SET_DRAM_DRV_PU_DRV_IMP_PU,
                                             l_dram_pu_drv_imp));

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, DRAM_PU_DRV_IMP_MAP, mss::SET_DRAM_DRV_PU_DRV_IMP_PU,
                                        l_dram_pu_drv_imp, l_field[iv_dimm_rank]));

            // Set the attr
            FAPI_TRY(mss::attr::set_dram_pu_drv_imp(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the DRAM Pulldown drv impedance
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dram_pd_drv_imp(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_dram_pd_drv_imp = 0;
            uint8_t l_field[mss::ddr5::mr::ATTR_RANKS] = {0};

            // =========================================================
            // EFD Byte 5: DRAM DIC
            // Attribute: ATTR_DRAM_PD_DRV_IMP
            // MODE REG: MR5
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 138
            // =========================================================
            static const std::vector< std::pair<uint8_t, uint8_t> > DRAM_PD_DRV_IMP_MAP =
            {
                // {key byte, PHY DRIVE IMP PULL UP VAL (ohms)}
                {0b0001, fapi2::ENUM_ATTR_DRAM_PD_DRV_IMP_OHM_34},
                {0b0010, fapi2::ENUM_ATTR_DRAM_PD_DRV_IMP_OHM_40},
                {0b0011, fapi2::ENUM_ATTR_DRAM_PD_DRV_IMP_OHM_48},
                // All others reserved/not used for DDR5
            };

            FAPI_TRY(mss::attr::get_dram_pd_drv_imp(iv_dimm, l_field));

            // Get the field value from i_efd into l_phy_drv_imp_pu
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_DIC_PULLDOWN, i_efd, mss::SET_DRAM_DRV_PU_DRV_IMP_PD,
                                             l_dram_pd_drv_imp));

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, DRAM_PD_DRV_IMP_MAP, mss::SET_DRAM_DRV_PU_DRV_IMP_PU,
                                        l_dram_pd_drv_imp, l_field[iv_dimm_rank]));

            // Set the attr
            FAPI_TRY(mss::attr::set_dram_pd_drv_imp(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the dram rd preamble field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dram_rd_preamble(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field = 0;
            uint8_t l_dram_rd_preamble = 0;

            // =========================================================
            // EFD Byte 9: DRAM Preamble and Postamble Setting
            // Attribute: ATTR_DDR5_DRAM_RD_PREAMBLE
            // MODE REG: MR8
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 139
            // =========================================================
            static const std::vector< std::pair<uint8_t, uint8_t> > DRAM_RD_PREAMBLE_MAP =
            {
                // {key byte, read preamble settings}
                {0b000, fapi2::ENUM_ATTR_DDR5_DRAM_RD_PREAMBLE_TCK1},
                {0b001, fapi2::ENUM_ATTR_DDR5_DRAM_RD_PREAMBLE_TCK2_OPT1},
                {0b010, fapi2::ENUM_ATTR_DDR5_DRAM_RD_PREAMBLE_TCK2_OPT2},
                {0b011, fapi2::ENUM_ATTR_DDR5_DRAM_RD_PREAMBLE_TCK3},
                {0b100, fapi2::ENUM_ATTR_DDR5_DRAM_RD_PREAMBLE_TCK4},
                // All others reserved/not used for DDR5
            };

            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RD_PREAMBLE, i_efd, SET_RD_PREAMBLE, l_field));

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, DRAM_RD_PREAMBLE_MAP, SET_RD_PREAMBLE,
                                        l_field, l_dram_rd_preamble));

            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_dram_rd_preamble(iv_port, l_dram_rd_preamble));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the dram wr preamble field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dram_wr_preamble(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field = 0;
            uint8_t l_dram_wr_preamble = 0;

            // =========================================================
            // EFD Byte 9: DRAM Preamble and Postamble Setting
            // Attribute: ATTR_DDR5_DRAM_WR_PREAMBLE
            // MODE REG: MR8
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 139
            // =========================================================
            static const std::vector< std::pair<uint8_t, uint8_t> > DRAM_WR_PREAMBLE_MAP =
            {
                // {key byte, write preamble settings}
                {0b01, fapi2::ENUM_ATTR_DDR5_DRAM_WR_PREAMBLE_TCK2},
                {0b10, fapi2::ENUM_ATTR_DDR5_DRAM_WR_PREAMBLE_TCK3},
                {0b11, fapi2::ENUM_ATTR_DDR5_DRAM_WR_PREAMBLE_TCK4},
                // All others reserved/not used for DDR5
            };

            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_WR_PREAMBLE, i_efd, SET_WR_PREAMBLE, l_field));

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, DRAM_WR_PREAMBLE_MAP, SET_WR_PREAMBLE,
                                        l_field, l_dram_wr_preamble));

            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_dram_wr_preamble(iv_port, l_dram_wr_preamble));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the dram rd postamble field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dram_rd_postamble(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field = 0;

            // =========================================================
            // EFD Byte 9: DRAM Preamble and Postamble Setting
            // Attribute: ATTR_DDR5_DRAM_RD_POSTAMBLE
            // MODE REG: MR8
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 139
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RD_POSTAMBLE, i_efd, SET_RD_POSTAMBLE, l_field));

            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_dram_rd_postamble(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the dram wr postamble field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dram_wr_postamble(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field = 0;

            // =========================================================
            // EFD Byte 9: DRAM Preamble and Postamble Setting
            // Attribute: ATTR_DDR5_DRAM_RD_POSTAMBLE
            // MODE REG: MR8
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 139
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_WR_POSTAMBLE, i_efd, SET_WR_POSTAMBLE, l_field));

            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_dram_wr_postamble(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the initial dram vref DQ field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dram_vref_dq(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_dram_vref_byte[4] = {0};
            uint8_t l_byte_index = 0;
            uint8_t l_vref_dq[mss::ddr5::mr::ATTR_RANKS][20] = {};

            // =========================================================
            // EFD Byte 10-17: Initial DRAM VRef Setting
            // Attribute: ATTR_DDR5_DRAM_WR_VREFDQ
            // MODE REG: MR10
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 139
            // =========================================================
            // Get the attr so that only the bits that changed are written
            // when we set the attr
            FAPI_TRY(mss::attr::get_ddr5_dram_wr_vrefdq(iv_dimm, l_vref_dq));

            // For Port 0 Channel 0
            // A0 R0: Byte 0
            // B0 R0: Byte 2
            // A0 R1: Byte 1
            // B0 R1: Byte 3
            // For Port 0 Channel 1
            // A1 R0: Byte 4
            // B1 R0: Byte 5
            // A1 R1: Byte 6
            // B1 R1: Byte 7
            // Same as above is repeated for Port 1 Channel 0 and Port 1 Channel 1
            if (iv_port_rel_pos == 0) // Port 0
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_VREF_BYTE0, i_efd, SET_WR_VREF_DQ, l_dram_vref_byte[0]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_VREF_BYTE1, i_efd, SET_WR_VREF_DQ, l_dram_vref_byte[1]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_VREF_BYTE2, i_efd, SET_WR_VREF_DQ, l_dram_vref_byte[2]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_VREF_BYTE3, i_efd, SET_WR_VREF_DQ, l_dram_vref_byte[3]));
            }
            else // Port 1
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_VREF_BYTE4, i_efd, SET_WR_VREF_DQ, l_dram_vref_byte[0]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_VREF_BYTE5, i_efd, SET_WR_VREF_DQ, l_dram_vref_byte[1]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_VREF_BYTE6, i_efd, SET_WR_VREF_DQ, l_dram_vref_byte[2]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_VREF_BYTE7, i_efd, SET_WR_VREF_DQ, l_dram_vref_byte[3]));
            }

            // A0/A1 maps to the first 10 DRAMs
            // B0/B1 maps to the other 10 DRAMs
            l_byte_index = iv_dimm_rank % 2;

            for(uint8_t l_dram = 0; l_dram < 10; l_dram++)
            {
                // Byte index should be 0 for rank0 and 1 for rank1
                l_vref_dq[iv_dimm_rank][l_dram] = l_dram_vref_byte[l_byte_index];
            }

            for(uint8_t l_dram = 10; l_dram < 20; l_dram++)
            {
                // Byte index should be 2 for rank0 and 3 for rank1
                l_vref_dq[iv_dimm_rank][l_dram] = l_dram_vref_byte[l_byte_index + 2];
            }

            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_dram_wr_vrefdq(iv_dimm, l_vref_dq));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the DRAM DFE Settings
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dram_dfe_gain(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field;

            // =========================================================
            // EFD Byte 18: DRAM DFE Setting
            // Attribute: ATTR_MEM_DDR5_GLOBAL_DFE_GAIN
            // MODE REG: MR111
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 140
            // =========================================================

            // Get the field value from i_efd into l_field
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_DFE_EN, i_efd, mss::SET_DRAM_DFE_GAIN,
                                             l_field));

            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_global_dfe_gain(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the DRAM DFE Settings
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dram_dfe_tap1(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field;

            // =========================================================
            // EFD Byte 18: DRAM DFE Setting
            // Attribute: ATTR_MEM_DDR5_GLOBAL_DFE_TAP1
            // MODE REG: MR111
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 140
            // =========================================================

            // Get the field value from i_efd into l_field
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_DFE_TAP1, i_efd, mss::SET_DRAM_DFE_TAP1,
                                             l_field));

            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_global_dfe_tap1(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the DRAM DFE Settings
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dram_dfe_tap2(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field = 0;

            // =========================================================
            // EFD Byte 18: DRAM DFE Setting
            // Attribute: ATTR_MEM_DDR5_GLOBAL_DFE_TAP2
            // MODE REG: MR111
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 140
            // =========================================================

            // Get the field value from i_efd into l_field
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_DFE_TAP2, i_efd, mss::SET_DRAM_DFE_TAP2,
                                             l_field));

            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_global_dfe_tap2(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the DRAM DFE Settings
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dram_dfe_tap3(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field = 0;
            // =========================================================
            // EFD Byte 18: DRAM DFE Setting
            // Attribute: ATTR_MEM_DDR5_GLOBAL_DFE_TAP3
            // MODE REG: MR111
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 140
            // =========================================================

            // Get the field value from i_efd into l_field
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_DFE_TAP3, i_efd, mss::SET_DRAM_DFE_TAP3,
                                             l_field));

            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_global_dfe_tap3(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the DRAM DFE Settings
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dram_dfe_tap4(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field = 0;

            // =========================================================
            // EFD Byte 18: DRAM DFE Setting
            // Attribute: ATTR_MEM_DDR5_GLOBAL_DFE_TAP4
            // MODE REG: MR111
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 140
            // =========================================================

            // Get the field value from i_efd into l_field
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_DFE_TAP4, i_efd, mss::SET_DRAM_DFE_TAP4,
                                             l_field));

            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_global_dfe_tap4(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the DRAM DFE gain bias
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        /// @note: Coding this for channel A / Rank 0 only.
        virtual fapi2::ReturnCode set_dram_dfe_gain_bias(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_dram_dfe_gain_bias = 0;
            uint8_t l_field[mss::ddr5::mr::ATTR_RANKS] = {0};

            // =========================================================
            // EFD Byte 19-26: DRAM DFE Gain Bias
            // Attribute: ATTR_MEM_DDR5_DFE_GAIN_BIAS
            // MODE REG: MR112
            // DDR5 DDIMM SPD Document Release 1.21 (Page 140)
            // DDR5 Published spec 10-2021 JESD79-5A (Page 112)
            // =========================================================
            static const std::vector< std::pair<uint8_t, uint8_t> > GAIN_BIAS_MAP =
            {
                // {key byte, PHY DRIVE IMP PULL UP VAL (ohms)}
                {0b000, fapi2::ENUM_ATTR_MEM_DDR5_DFE_GAIN_BIAS_STEP0},
                {0b001, fapi2::ENUM_ATTR_MEM_DDR5_DFE_GAIN_BIAS_STEP1},
                {0b010, fapi2::ENUM_ATTR_MEM_DDR5_DFE_GAIN_BIAS_STEP2},
                {0b011, fapi2::ENUM_ATTR_MEM_DDR5_DFE_GAIN_BIAS_STEP3},
                // All others reserved/not used for DDR5
            };
            // Get the attr so that only the bits that changed are written
            // when we set the attr
            FAPI_TRY(mss::attr::get_ddr5_dfe_gain_bias(iv_dimm, l_field));

            // Get the field value from i_efd into l_phy_drv_imp_pu
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_DFE_GAIN_BIAS_BYTE0, i_efd, mss::SET_DRAM_DFE_GAIN_BIAS,
                                             l_dram_dfe_gain_bias));
            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, GAIN_BIAS_MAP, mss::SET_DRAM_DFE_GAIN_BIAS,
                                        l_dram_dfe_gain_bias, l_field[iv_dimm_rank]))

            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_dfe_gain_bias(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the DRAM DFE gain bias
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        /// @note: Coding this for channel A / Rank 0 only.
        virtual fapi2::ReturnCode set_dram_dfe_gain_bias_sign_bit(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_dram_dfe_gain_bias_sign_bit = 0;
            uint8_t l_field[mss::ddr5::mr::ATTR_RANKS] = {0};

            // =========================================================
            // EFD Byte 19-26: DRAM DFE Gain Bias
            // Attribute: ATTR_MEM_DDR5_DFE_SIGN_BIT
            // MODE REG: MR112
            // DDR5 DDIMM SPD Document Release 1.21 (Page 140)
            // DDR5 Published spec 10-2021 JESD79-5A (Page 112)
            // =========================================================

            // Get the attr so that only the bits that changed are written
            // when we set the attr
            FAPI_TRY(mss::attr::get_ddr5_dfe_sign_bit(iv_dimm, l_field));

            // Get the field value from i_efd into l_phy_drv_imp_pu
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_DFE_GAIN_BIAS_BYTE0_SIGN_BIT, i_efd, mss::SET_DRAM_DFE_GAIN_BIAS_SIGN,
                                             l_dram_dfe_gain_bias_sign_bit));

            // Set the available rank
            l_field[iv_dimm_rank] = l_dram_dfe_gain_bias_sign_bit;

            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_dfe_sign_bit(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the PHY ODT Impedance
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_phy_odt_imp(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_phy_odt_imp = 0;
            uint16_t l_field[mss::ddr5::mr::ATTR_RANKS] = {0};

            // =========================================================
            // EFD Byte 27: PHY ODT Impedance
            // Attribute: ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 141
            // =========================================================
            static const std::vector< std::pair<uint8_t, uint16_t> > PHY_ODT_MAP =
            {
                // {key byte, PHY DRIVE IMP PULL UP VAL (ohms)}
                {0b00000, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_DISABLE},
                {0b00001, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_25},
                {0b00010, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_27},
                {0b00011, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_28},
                {0b00100, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_30},
                {0b00101, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_32},
                {0b00110, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_34},
                {0b00111, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_36},
                {0b01000, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_40},
                {0b01001, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_43},
                {0b01010, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_48},
                {0b01011, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_53},
                {0b01100, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_60},
                {0b01101, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_68},
                {0b01110, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_80},
                {0b01111, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_96},
                {0b10000, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_120},
                {0b10001, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_160},
                {0b10010, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_240},
                {0b10011, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_OHM_480},
                // All others reserved/not used for DDR5
            };

            // Get the attr to do read modify write
            FAPI_TRY(mss::attr::get_si_mc_rcv_imp_dq_dqs(iv_dimm, l_field));

            // Get the field value from i_efd into l_phy_drv_imp_pu
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PHY_ODT_IMPEDANCE, i_efd, mss::SET_SI_MC_RCV_IMP_DQ_DQS,
                                             l_phy_odt_imp));

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, PHY_ODT_MAP, mss::SET_SI_MC_RCV_IMP_DQ_DQS,
                                        l_phy_odt_imp, l_field[iv_dimm_rank]));
            // Set the attr
            FAPI_TRY(mss::attr::set_si_mc_rcv_imp_dq_dqs(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the phy drive imp pull up field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_si_phy_drv_imp_pull_up(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_phy_drv_imp = 0;
            uint16_t l_field = 0;

            // =========================================================
            // EFD Byte 28: PHY DRV Impedance
            // Attribute: ATTR_MEM_SI_PHY_DRV_IMP_DQ_DQS_PULL_UP
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 141
            // =========================================================
            static const std::vector< std::pair<uint8_t, uint16_t> > PHY_DRV_IMP_MAP =
            {
                // {key byte, PHY DRIVE IMP PULL UP VAL (ohms)}
                {0b00000, fapi2::ENUM_ATTR_MEM_SI_PHY_DRV_IMP_DQ_DQS_PULL_UP_HIGH_IMP},
                {0b00001, fapi2::ENUM_ATTR_MEM_SI_PHY_DRV_IMP_DQ_DQS_PULL_UP_OHM_25},
                {0b00010, fapi2::ENUM_ATTR_MEM_SI_PHY_DRV_IMP_DQ_DQS_PULL_UP_OHM_27},
                {0b00011, fapi2::ENUM_ATTR_MEM_SI_PHY_DRV_IMP_DQ_DQS_PULL_UP_OHM_28},
                {0b00100, fapi2::ENUM_ATTR_MEM_SI_PHY_DRV_IMP_DQ_DQS_PULL_UP_OHM_30},
                {0b00101, fapi2::ENUM_ATTR_MEM_SI_PHY_DRV_IMP_DQ_DQS_PULL_UP_OHM_32},
                {0b00110, fapi2::ENUM_ATTR_MEM_SI_PHY_DRV_IMP_DQ_DQS_PULL_UP_OHM_34},
                {0b00111, fapi2::ENUM_ATTR_MEM_SI_PHY_DRV_IMP_DQ_DQS_PULL_UP_OHM_36},
                {0b01000, fapi2::ENUM_ATTR_MEM_SI_PHY_DRV_IMP_DQ_DQS_PULL_UP_OHM_40},
                {0b01001, fapi2::ENUM_ATTR_MEM_SI_PHY_DRV_IMP_DQ_DQS_PULL_UP_OHM_43},
                {0b01010, fapi2::ENUM_ATTR_MEM_SI_PHY_DRV_IMP_DQ_DQS_PULL_UP_OHM_48},
                {0b01011, fapi2::ENUM_ATTR_MEM_SI_PHY_DRV_IMP_DQ_DQS_PULL_UP_OHM_53},
                {0b01100, fapi2::ENUM_ATTR_MEM_SI_PHY_DRV_IMP_DQ_DQS_PULL_UP_OHM_60},
                {0b01101, fapi2::ENUM_ATTR_MEM_SI_PHY_DRV_IMP_DQ_DQS_PULL_UP_OHM_68},
                {0b01110, fapi2::ENUM_ATTR_MEM_SI_PHY_DRV_IMP_DQ_DQS_PULL_UP_OHM_80},
                {0b01111, fapi2::ENUM_ATTR_MEM_SI_PHY_DRV_IMP_DQ_DQS_PULL_UP_OHM_96},
                {0b10000, fapi2::ENUM_ATTR_MEM_SI_PHY_DRV_IMP_DQ_DQS_PULL_UP_OHM_120},
                {0b10001, fapi2::ENUM_ATTR_MEM_SI_PHY_DRV_IMP_DQ_DQS_PULL_UP_OHM_160},
                {0b10010, fapi2::ENUM_ATTR_MEM_SI_PHY_DRV_IMP_DQ_DQS_PULL_UP_OHM_240},
                {0b10011, fapi2::ENUM_ATTR_MEM_SI_PHY_DRV_IMP_DQ_DQS_PULL_UP_OHM_480},
                // All others reserved/not used for DDR5
            };

            // Get the attr to do read modify write
            FAPI_TRY(mss::attr::get_si_phy_drv_imp_dq_dqs_pull_up(iv_port, l_field));

            // Get the field value from i_efd into l_phy_drv_imp_pu
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PHY_DRIVE_IMPEDANCE_CTRL0, i_efd,
                                             mss::SET_SI_PHY_DRV_IMP_DQ_DQS_PULL_UP, l_phy_drv_imp));

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, PHY_DRV_IMP_MAP, mss::SET_SI_PHY_DRV_IMP_DQ_DQS_PULL_UP,
                                        l_phy_drv_imp, l_field));

            // Set the attr
            FAPI_TRY(mss::attr::set_si_phy_drv_imp_dq_dqs_pull_up(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the phy drive imp pull down field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_si_phy_drv_imp_tx_cntl1(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_phy_drv_imp = 0;
            uint16_t l_field = 0;

            // =========================================================
            // EFD Byte 29: PHY DRV Impedance
            // Attribute: ATTR_ODY_TX_IMPEDANCE_CTRL1
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 141-142
            // =========================================================
            static const std::vector< std::pair<uint8_t, uint16_t> > PHY_DRV_IMP_MAP =
            {
                // {key byte, PHY DRIVE IMP PULL UP VAL (ohms)}
                {0b00000, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL1_HIGH_IMP},
                {0b00001, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL1_OHM_25},
                {0b00010, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL1_OHM_27},
                {0b00011, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL1_OHM_28},
                {0b00100, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL1_OHM_30},
                {0b00101, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL1_OHM_32},
                {0b00110, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL1_OHM_34},
                {0b00111, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL1_OHM_36},
                {0b01000, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL1_OHM_40},
                {0b01001, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL1_OHM_43},
                {0b01010, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL1_OHM_48},
                {0b01011, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL1_OHM_53},
                {0b01100, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL1_OHM_60},
                {0b01101, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL1_OHM_68},
                {0b01110, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL1_OHM_80},
                {0b01111, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL1_OHM_96},
                {0b10000, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL1_OHM_120},
                {0b10001, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL1_OHM_160},
                {0b10010, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL1_OHM_240},
                {0b10011, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL1_OHM_480},
                // All others reserved/not used for DDR5
            };

            // Get the field value from i_efd into l_phy_drv_imp
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PHY_DRIVE_IMPEDANCE_CTRL1, i_efd,
                                             mss::SET_TX_IMP_CTRL1,
                                             l_phy_drv_imp));

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, PHY_DRV_IMP_MAP, mss::SET_TX_IMP_CTRL1,
                                        l_phy_drv_imp, l_field));

            // Set the attr
            FAPI_TRY(mss::attr::set_ody_phy_tx_impedance_ctrl1(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the phy drv impedance field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_si_phy_drv_imp_tx_cntl2(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_phy_drv_imp = 0;
            uint16_t l_field = 0;

            // =========================================================
            // EFD Byte 30: PHY DRV Impedance
            // Attribute: ATTR_ODY_TX_IMPEDANCE_CTRL2
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 142
            // =========================================================
            static const std::vector< std::pair<uint8_t, uint16_t> > PHY_DRV_IMP_MAP =
            {
                // {key byte, PHY DRIVE IMP PULL UP VAL (ohms)}
                {0b00000, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL2_HIGH_IMP},
                {0b00001, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL2_OHM_25},
                {0b00010, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL2_OHM_27},
                {0b00011, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL2_OHM_28},
                {0b00100, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL2_OHM_30},
                {0b00101, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL2_OHM_32},
                {0b00110, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL2_OHM_34},
                {0b00111, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL2_OHM_36},
                {0b01000, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL2_OHM_40},
                {0b01001, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL2_OHM_43},
                {0b01010, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL2_OHM_48},
                {0b01011, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL2_OHM_53},
                {0b01100, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL2_OHM_60},
                {0b01101, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL2_OHM_68},
                {0b01110, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL2_OHM_80},
                {0b01111, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL2_OHM_96},
                {0b10000, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL2_OHM_120},
                {0b10001, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL2_OHM_160},
                {0b10010, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL2_OHM_240},
                {0b10011, fapi2::ENUM_ATTR_ODY_TX_IMPEDANCE_CTRL2_OHM_480},
                // All others reserved/not used for DDR5
            };

            // Get the field value from i_efd into l_phy_drv_imp_pu
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PHY_DRIVE_IMPEDANCE_CTRL2, i_efd,
                                             mss::SET_TX_IMP_CTRL2,
                                             l_phy_drv_imp));

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, PHY_DRV_IMP_MAP, mss::SET_TX_IMP_CTRL2,
                                        l_phy_drv_imp, l_field));

            // Set the attr
            FAPI_TRY(mss::attr::set_ody_phy_tx_impedance_ctrl2(iv_port, l_field));

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
            uint8_t l_field[mss::ddr5::mr::ATTR_RANKS] = {0};
            uint8_t l_atx_impedance = 0;
            // =========================================================
            // EFD Byte 32: ATX Impedance
            // Attribute: ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 143
            // =========================================================
            static const std::vector< std::pair<uint8_t, uint8_t> > ATX_IMP_MAP =
            {
                // SDR {key byte, ATX IMP (ohm)}
                {0b0000, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_DISABLE},
                {0b0001, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_SDR_OHM_10},
                {0b0010, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_SDR_OHM_15A},
                {0b0011, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_SDR_OHM_15B},
                {0b0100, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_SDR_OHM_20},
                {0b0101, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_SDR_OHM_24},
                {0b0110, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_SDR_OHM_30},

                // DDR {key byte, ATX IMP (ohm)}
                {0b1001, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_DDR_OHM_10},
                {0b1010, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_DDR_OHM_15A},
                {0b1011, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_DDR_OHM_15B},
                {0b1100, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_DDR_OHM_20},
                {0b1101, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_DDR_OHM_24},
                {0b1110, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_DDR_OHM_30},

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
        /// @brief Set the atx slew rate rise field for channels A and B
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        /// @note: Coding this for both channel A and channel B
        virtual fapi2::ReturnCode set_atx_slew_rate_rise_ac_a0(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field[mss::ddr5::mr::ATTR_NUM_CHANNELS] = {0};
            const std::vector<uint8_t> l_reserved_bits{0x00, 0x04};
            // =========================================================
            // EFD Byte 33-34: ATX Slew Rate Rise
            // Attribute: ATTR_MEM_EFF_DDR5_TX_SLEW_RISE_AC
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 149-151
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ATX_SLEW_RISE_RATE_BYTE0, i_efd, mss::SET_SLEW_RATE_RISE,
                                             l_field[mss::ddr5::mr::ATTR_CHANNEL_A]));

            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ATX_SLEW_RISE_RATE_BYTE1, i_efd, mss::SET_SLEW_RATE_RISE,
                                             l_field[mss::ddr5::mr::ATTR_CHANNEL_B]));

            FAPI_ASSERT(l_field[mss::ddr5::mr::ATTR_CHANNEL_A] < mss::ody::sizes::SPD_TX_SLEW_DECODE_MAX,
                        fapi2::MSS_INVALID_SPD_RESERVED_BITS()
                        .set_FUNCTION_CODE(mss::SET_SLEW_RATE_RISE)
                        .set_FAILING_VALUE(l_field[mss::ddr5::mr::ATTR_CHANNEL_A])
                        .set_OCMB_TARGET(iv_ocmb),
                        "Reserved bits seen on %s. Value seen:0x%02x",
                        spd::c_str(iv_port), l_field[mss::ddr5::mr::ATTR_CHANNEL_A]);

            FAPI_ASSERT(l_field[mss::ddr5::mr::ATTR_CHANNEL_B] < mss::ody::sizes::SPD_TX_SLEW_DECODE_MAX,
                        fapi2::MSS_INVALID_SPD_RESERVED_BITS()
                        .set_FUNCTION_CODE(mss::SET_SLEW_RATE_RISE)
                        .set_FAILING_VALUE(l_field[mss::ddr5::mr::ATTR_CHANNEL_B])
                        .set_OCMB_TARGET(iv_ocmb),
                        "Reserved bits seen on %s. Value seen:0x%02x",
                        spd::c_str(iv_port), l_field[mss::ddr5::mr::ATTR_CHANNEL_B]);

            FAPI_TRY( mss::spd::check::reserved_values(iv_ocmb, l_reserved_bits, mss::SET_SLEW_RATE_RISE,
                      l_field[mss::ddr5::mr::ATTR_CHANNEL_A]) );
            FAPI_TRY( mss::spd::check::reserved_values(iv_ocmb, l_reserved_bits, mss::SET_SLEW_RATE_RISE,
                      l_field[mss::ddr5::mr::ATTR_CHANNEL_B]) );

            FAPI_TRY(mss::attr::set_ddr5_tx_slew_rise_ac(iv_port, l_field));


        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the atx slew rate fall field for channels A and B
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        /// @note: Coding this for both channel A and channel B.
        virtual fapi2::ReturnCode set_atx_slew_rate_fall_ac_a0(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field[mss::ddr5::mr::ATTR_NUM_CHANNELS] = {0};
            const std::vector<uint8_t> l_reserved_bits{0x00, 0x04};

            // =========================================================
            // EFD Byte 37-38: ATX Slew Rate Fall
            // Attribute: ATTR_MEM_EFF_DDR5_TX_SLEW_FALL_AC
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 151-152
            // =========================================================

            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ATX_SLEW_FALL_RATE_BYTE0, i_efd, mss::SET_SLEW_RATE_FALL,
                                             l_field[mss::ddr5::mr::ATTR_CHANNEL_A]));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ATX_SLEW_FALL_RATE_BYTE1, i_efd, mss::SET_SLEW_RATE_FALL,
                                             l_field[mss::ddr5::mr::ATTR_CHANNEL_B]));

            FAPI_ASSERT(l_field[mss::ddr5::mr::ATTR_CHANNEL_A] < mss::ody::sizes::SPD_TX_SLEW_DECODE_MAX,
                        fapi2::MSS_INVALID_SPD_RESERVED_BITS()
                        .set_FUNCTION_CODE(mss::SET_SLEW_RATE_FALL)
                        .set_FAILING_VALUE(l_field[mss::ddr5::mr::ATTR_CHANNEL_A])
                        .set_OCMB_TARGET(iv_ocmb),
                        "Reserved bits seen on %s. Value seen:0x%02x",
                        spd::c_str(iv_port), l_field[mss::ddr5::mr::ATTR_CHANNEL_A]);

            FAPI_ASSERT(l_field[mss::ddr5::mr::ATTR_CHANNEL_B] < mss::ody::sizes::SPD_TX_SLEW_DECODE_MAX,
                        fapi2::MSS_INVALID_SPD_RESERVED_BITS()
                        .set_FUNCTION_CODE(mss::SET_SLEW_RATE_FALL)
                        .set_FAILING_VALUE(l_field[mss::ddr5::mr::ATTR_CHANNEL_B])
                        .set_OCMB_TARGET(iv_ocmb),
                        "Reserved bits seen on %s. Value seen:0x%02x",
                        spd::c_str(iv_port), l_field[mss::ddr5::mr::ATTR_CHANNEL_B]);

            FAPI_TRY( mss::spd::check::reserved_values(iv_ocmb, l_reserved_bits, mss::SET_SLEW_RATE_FALL,
                      l_field[mss::ddr5::mr::ATTR_CHANNEL_A]) );
            FAPI_TRY( mss::spd::check::reserved_values(iv_ocmb, l_reserved_bits, mss::SET_SLEW_RATE_FALL,
                      l_field[mss::ddr5::mr::ATTR_CHANNEL_B]) );

            FAPI_TRY(mss::attr::set_ddr5_tx_slew_fall_ac(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the ck slew rate rise field for channels A and B
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        /// @note: Coding this for both channel A and channel B
        virtual fapi2::ReturnCode set_tx_slew_rate_rise_ck_a0(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field[mss::ddr5::mr::ATTR_NUM_CHANNELS] = {0};
            std::vector<uint8_t> l_reserved_bits{0b0000, 0b0011, 0b0101};
            // =========================================================
            // EFD Byte 41-42: CK Slew Rate Rise
            // Attribute: ATTR_MEM_EFF_DDR5_TX_SLEW_RISE_CK
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 152-154
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::CK_SLEW_RATE_RISE_BYTE0, i_efd, mss::SET_CK_SLEW_RATE_RISE,
                                             l_field[mss::ddr5::mr::ATTR_CHANNEL_A]));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::CK_SLEW_RATE_RISE_BYTE1, i_efd, mss::SET_CK_SLEW_RATE_RISE,
                                             l_field[mss::ddr5::mr::ATTR_CHANNEL_B]));

            FAPI_ASSERT(l_field[mss::ddr5::mr::ATTR_CHANNEL_A] < mss::ody::sizes::SPD_TX_SLEW_DECODE_MAX,
                        fapi2::MSS_INVALID_SPD_RESERVED_BITS()
                        .set_FUNCTION_CODE(mss::SET_CK_SLEW_RATE_RISE)
                        .set_FAILING_VALUE(l_field[mss::ddr5::mr::ATTR_CHANNEL_A])
                        .set_OCMB_TARGET(iv_ocmb),
                        "Reserved bits seen on %s. Value seen:0x%02x",
                        spd::c_str(iv_port), l_field[mss::ddr5::mr::ATTR_CHANNEL_A]);

            FAPI_ASSERT(l_field[mss::ddr5::mr::ATTR_CHANNEL_B] < mss::ody::sizes::SPD_TX_SLEW_DECODE_MAX,
                        fapi2::MSS_INVALID_SPD_RESERVED_BITS()
                        .set_FUNCTION_CODE(mss::SET_CK_SLEW_RATE_RISE)
                        .set_FAILING_VALUE(l_field[mss::ddr5::mr::ATTR_CHANNEL_B])
                        .set_OCMB_TARGET(iv_ocmb),
                        "Reserved bits seen on %s. Value seen:0x%02x",
                        spd::c_str(iv_port), l_field[mss::ddr5::mr::ATTR_CHANNEL_B]);

            FAPI_TRY( mss::spd::check::reserved_values(iv_ocmb, l_reserved_bits, mss::SET_CK_SLEW_RATE_RISE,
                      l_field[mss::ddr5::mr::ATTR_CHANNEL_A]) );
            FAPI_TRY( mss::spd::check::reserved_values(iv_ocmb, l_reserved_bits, mss::SET_CK_SLEW_RATE_RISE,
                      l_field[mss::ddr5::mr::ATTR_CHANNEL_B]) );

            FAPI_TRY(mss::attr::set_ddr5_tx_slew_rise_ck(iv_port, l_field));


        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the DRAM RTT PARK
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        /// @note: Coding this for channel A / Rank 0 only.
        virtual fapi2::ReturnCode set_dram_rtt_park(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field[mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_NUM_CHANNELS] = {};
            uint8_t l_dram_rtt_park_bytes[mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_NUM_CHANNELS] = {};

            // =========================================================
            // EFD Byte 60-67: RTT PARK and RTT WR Termination Settings
            //                 Per Channel Per Rank
            // Attribute: ATTR_DDR5_DRAM_RTT_PARK
            // MODE REG: 34
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 151
            // =========================================================
            const std::vector< std::pair<uint8_t, uint8_t> > DRAM_RTT_PARK_MAP =
            {
                // {key byte, DRAM RTT PARK (ohm)}
                {0b000, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_PARK_RTT_OFF},
                {0b001, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_PARK_OHM240},
                {0b010, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_PARK_OHM120},
                {0b011, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_PARK_OHM80},
                {0b100, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_PARK_OHM60},
                {0b101, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_PARK_OHM48},
                {0b110, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_PARK_OHM40},
                {0b111, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_PARK_OHM34},

                // All others reserved
            };

            // Get the attr for read modify write
            FAPI_TRY(mss::attr::get_ddr5_dram_rtt_park(iv_dimm, l_field));

            // Get all the bytes into the array
            // PORT | RANK | CHANNEL | BYTE NUMBER
            // ====================================
            //  0      0       0         60
            //  0      0       1         62
            //  0      1       0         61
            //  0      1       1         63
            if(iv_port_rel_pos == 0)
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_PARK_BYTE0, i_efd, mss::SET_SI_DRAM_RTT_PARK,
                                                 l_dram_rtt_park_bytes[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::ATTR_CHANNEL_A]));

                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_PARK_BYTE2, i_efd, mss::SET_SI_DRAM_RTT_PARK,
                                                 l_dram_rtt_park_bytes[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::ATTR_CHANNEL_B]));

                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_PARK_BYTE1, i_efd, mss::SET_SI_DRAM_RTT_PARK,
                                                 l_dram_rtt_park_bytes[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::ATTR_CHANNEL_A]));

                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_PARK_BYTE3, i_efd, mss::SET_SI_DRAM_RTT_PARK,
                                                 l_dram_rtt_park_bytes[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::ATTR_CHANNEL_B]));

            }
            // PORT | RANK | CHANNEL | BYTE NUMBER
            // ====================================
            //  1      0       0         64
            //  1      0       1         66
            //  1      1       0         65
            //  1      1       1         67
            else
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_PARK_BYTE4, i_efd, mss::SET_SI_DRAM_RTT_PARK,
                                                 l_dram_rtt_park_bytes[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::ATTR_CHANNEL_A]));

                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_PARK_BYTE6, i_efd, mss::SET_SI_DRAM_RTT_PARK,
                                                 l_dram_rtt_park_bytes[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::ATTR_CHANNEL_B]));

                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_PARK_BYTE5, i_efd, mss::SET_SI_DRAM_RTT_PARK,
                                                 l_dram_rtt_park_bytes[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::ATTR_CHANNEL_A]));

                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_PARK_BYTE7, i_efd, mss::SET_SI_DRAM_RTT_PARK,
                                                 l_dram_rtt_park_bytes[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::ATTR_CHANNEL_B]));
            }

            // Map SPD value to desired setting
            for(uint8_t l_channel = 0; l_channel < mss::ddr5::mr::ATTR_NUM_CHANNELS; l_channel++)
            {
                // Map SPD value to desired setting
                FAPI_TRY(lookup_table_check(iv_ocmb, DRAM_RTT_PARK_MAP, mss::SET_SI_DRAM_RTT_PARK,
                                            l_dram_rtt_park_bytes[iv_dimm_rank][l_channel],
                                            l_field[iv_dimm_rank][l_channel]));
            }

            FAPI_TRY(mss::attr::set_ddr5_dram_rtt_park(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the DRAM RTT WR
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        /// @note: Coding this for channel A / Rank 0 only.
        virtual fapi2::ReturnCode set_dram_rtt_wr(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field[mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_NUM_CHANNELS] = {};
            uint8_t l_dram_wr_park_bytes[mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_NUM_CHANNELS] = {};

            // =========================================================
            // EFD Byte 60-67: RTT_PARK and RTT_WR Termination Settings
            //                 Per Channel Per Rank
            // Attribute: ATTR_DDR5_DRAM_RTT_WR
            // MODE REG: MR34
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 148
            // =========================================================
            static const std::vector< std::pair<uint8_t, uint8_t> > DRAM_RTT_WR_MAP =
            {
                // {key byte, DRAM RTT WR (ohm)}
                {0b000, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_WR_RTT_OFF},
                {0b001, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_WR_OHM240},
                {0b010, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_WR_OHM120},
                {0b011, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_WR_OHM80},
                {0b100, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_WR_OHM60},
                {0b101, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_WR_OHM48},
                {0b110, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_WR_OHM40},
                {0b111, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_WR_OHM34},

                // All others reserved
            };

            // Get the attr for read modify write
            FAPI_TRY(mss::attr::get_ddr5_dram_rtt_wr(iv_dimm, l_field));

            // Get all the bytes into the array
            // PORT | RANK | CHANNEL | BYTE NUMBER
            // ====================================
            //  0      0       0         60
            //  0      0       1         62
            //  0      1       0         61
            //  0      1       1         63
            if(iv_port_rel_pos == 0)
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_WR_BYTE0, i_efd, mss::SET_SI_DRAM_RTT_WR,
                                                 l_dram_wr_park_bytes[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::ATTR_CHANNEL_A]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_WR_BYTE2, i_efd, mss::SET_SI_DRAM_RTT_WR,
                                                 l_dram_wr_park_bytes[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::ATTR_CHANNEL_B]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_WR_BYTE1, i_efd, mss::SET_SI_DRAM_RTT_WR,
                                                 l_dram_wr_park_bytes[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::ATTR_CHANNEL_A]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_WR_BYTE3, i_efd, mss::SET_SI_DRAM_RTT_WR,
                                                 l_dram_wr_park_bytes[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::ATTR_CHANNEL_B]));
            }
            // PORT | RANK | CHANNEL | BYTE NUMBER
            // ====================================
            //  1      0       0         64
            //  1      0       1         66
            //  1      1       0         65
            //  1      1       1         67
            else
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_WR_BYTE4, i_efd, mss::SET_SI_DRAM_RTT_WR,
                                                 l_dram_wr_park_bytes[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::ATTR_CHANNEL_A]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_WR_BYTE6, i_efd, mss::SET_SI_DRAM_RTT_WR,
                                                 l_dram_wr_park_bytes[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::ATTR_CHANNEL_B]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_WR_BYTE5, i_efd, mss::SET_SI_DRAM_RTT_WR,
                                                 l_dram_wr_park_bytes[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::ATTR_CHANNEL_A]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_WR_BYTE7, i_efd, mss::SET_SI_DRAM_RTT_WR,
                                                 l_dram_wr_park_bytes[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::ATTR_CHANNEL_B]));
            }

            // Map SPD value to desired setting
            for(uint8_t l_channel = 0; l_channel < mss::ddr5::mr::ATTR_NUM_CHANNELS; l_channel++)
            {
                // Map SPD value to desired setting
                FAPI_TRY(lookup_table_check(iv_ocmb, DRAM_RTT_WR_MAP, mss::SET_SI_DRAM_RTT_WR,
                                            l_dram_wr_park_bytes[iv_dimm_rank][l_channel],
                                            l_field[iv_dimm_rank][l_channel]));
            }

            FAPI_TRY(mss::attr::set_ddr5_dram_rtt_wr(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the DRAM RTT NOM WR
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dram_rtt_nom_wr(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field[mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_NUM_CHANNELS] = {};
            uint8_t l_dram_rtt_nom_wr_bytes[mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_NUM_CHANNELS] = {};

            // =========================================================
            // EFD Byte 68-75: RTT_NOM_WR and RTT_NOM_RD Termination Settings
            //                 Per Channel Per Rank
            // Attribute: ATTR_DDR5_DRAM_RTT_NOM_WR
            // MODE REG: MR35
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 148
            // =========================================================
            static const std::vector< std::pair<uint8_t, uint8_t> > DRAM_RTT_NOM_WR_MAP =
            {
                // {key byte, DRAM RTT PARK (ohm)}
                {0b000, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_NOM_WR_DISABLE},
                {0b001, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_NOM_WR_OHM240},
                {0b010, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_NOM_WR_OHM120},
                {0b011, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_NOM_WR_OHM80},
                {0b100, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_NOM_WR_OHM60},
                {0b101, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_NOM_WR_OHM48},
                {0b110, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_NOM_WR_OHM40},
                {0b111, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_NOM_WR_OHM34},

                // All others reserved
            };

            // Get the attr for read modify write
            FAPI_TRY(mss::attr::get_ddr5_dram_rtt_nom_wr(iv_dimm, l_field));

            // Get all the bytes into the array
            // PORT | RANK | CHANNEL | BYTE NUMBER
            // ====================================
            //  0      0       0         68
            //  0      0       1         70
            //  0      1       0         69
            //  0      1       1         71
            if (iv_port_rel_pos == 0)
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_NOM_BYTE0_WR, i_efd,
                                                 mss::SET_DRAM_RTT_NOM_WR,
                                                 l_dram_rtt_nom_wr_bytes[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::ATTR_CHANNEL_A]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_NOM_BYTE2_WR, i_efd,
                                                 mss::SET_DRAM_RTT_NOM_WR,
                                                 l_dram_rtt_nom_wr_bytes[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::ATTR_CHANNEL_B]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_NOM_BYTE1_WR, i_efd,
                                                 mss::SET_DRAM_RTT_NOM_WR,
                                                 l_dram_rtt_nom_wr_bytes[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::ATTR_CHANNEL_A]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_NOM_BYTE3_WR, i_efd,
                                                 mss::SET_DRAM_RTT_NOM_WR,
                                                 l_dram_rtt_nom_wr_bytes[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::ATTR_CHANNEL_B]));
            }
            // PORT | RANK | CHANNEL | BYTE NUMBER
            // ====================================
            //  1      0       0         72
            //  1      0       1         74
            //  1      1       0         73
            //  1      1       1         75
            else
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_NOM_BYTE4_WR, i_efd,
                                                 mss::SET_DRAM_RTT_NOM_WR,
                                                 l_dram_rtt_nom_wr_bytes[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::ATTR_CHANNEL_A]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_NOM_BYTE6_WR, i_efd,
                                                 mss::SET_DRAM_RTT_NOM_WR,
                                                 l_dram_rtt_nom_wr_bytes[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::ATTR_CHANNEL_B]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_NOM_BYTE5_WR, i_efd,
                                                 mss::SET_DRAM_RTT_NOM_WR,
                                                 l_dram_rtt_nom_wr_bytes[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::ATTR_CHANNEL_A]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_NOM_BYTE7_WR, i_efd,
                                                 mss::SET_DRAM_RTT_NOM_WR,
                                                 l_dram_rtt_nom_wr_bytes[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::ATTR_CHANNEL_B]));
            }

            // Map SPD value to desired setting
            for(uint8_t l_channel = 0; l_channel < mss::ddr5::mr::ATTR_NUM_CHANNELS; l_channel++)
            {
                FAPI_TRY(lookup_table_check(iv_ocmb, DRAM_RTT_NOM_WR_MAP, mss::SET_DRAM_RTT_NOM_WR,
                                            l_dram_rtt_nom_wr_bytes[iv_dimm_rank][l_channel],
                                            l_field[iv_dimm_rank][l_channel]));

            }

            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_dram_rtt_nom_wr(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the DRAM RTT NOM RD
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        /// @note: Coding this for channel A / Rank 0 only.
        virtual fapi2::ReturnCode set_dram_rtt_nom_rd(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_field[mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_NUM_CHANNELS] = {};
            uint8_t l_dram_rtt_nom_rd_bytes[mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_NUM_CHANNELS] = {};

            // =========================================================
            // EFD Byte 68-75: RTT_NOM_WR and RTT_NOM_RD Termination Settings
            //                 Per Channel Per Rank
            // Attribute: ATTR_DDR5_DRAM_RTT_NOM_RD
            // MODE REG: MR35
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 148
            // =========================================================
            static const std::vector< std::pair<uint8_t, uint8_t> > DRAM_RTT_NOM_RD_MAP =
            {
                // {key byte, DRAM RTT PARK (ohm)}
                {0b000, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_NOM_RD_DISABLE},
                {0b001, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_NOM_RD_OHM240},
                {0b010, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_NOM_RD_OHM120},
                {0b011, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_NOM_RD_OHM80},
                {0b100, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_NOM_RD_OHM60},
                {0b101, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_NOM_RD_OHM48},
                {0b110, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_NOM_RD_OHM40},
                {0b111, fapi2::ENUM_ATTR_DDR5_DRAM_RTT_NOM_RD_OHM34},

                // All others reserved
            };

            // Get the attr for read modify write
            FAPI_TRY(mss::attr::get_ddr5_dram_rtt_nom_rd(iv_dimm, l_field));

            // Get all the bytes into the array
            // PORT | RANK | CHANNEL | BYTE NUMBER
            // ====================================
            //  0      0       0         68
            //  0      0       1         70
            //  0      1       0         69
            //  0      1       1         71
            if (iv_port_rel_pos == 0)
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_NOM_BYTE0_RD, i_efd, mss::SET_DRAM_RTT_NOM_RD,
                                                 l_dram_rtt_nom_rd_bytes[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::ATTR_CHANNEL_A]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_NOM_BYTE2_RD, i_efd, mss::SET_DRAM_RTT_NOM_RD,
                                                 l_dram_rtt_nom_rd_bytes[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::ATTR_CHANNEL_B]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_NOM_BYTE1_RD, i_efd, mss::SET_DRAM_RTT_NOM_RD,
                                                 l_dram_rtt_nom_rd_bytes[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::ATTR_CHANNEL_A]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_NOM_BYTE3_RD, i_efd, mss::SET_DRAM_RTT_NOM_RD,
                                                 l_dram_rtt_nom_rd_bytes[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::ATTR_CHANNEL_B]));
            }
            // PORT | RANK | CHANNEL | BYTE NUMBER
            // ====================================
            //  1      0       0         72
            //  1      0       1         74
            //  1      1       0         73
            //  1      1       1         75
            else
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_NOM_BYTE4_RD, i_efd, mss::SET_DRAM_RTT_NOM_RD,
                                                 l_dram_rtt_nom_rd_bytes[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::ATTR_CHANNEL_A]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_NOM_BYTE6_RD, i_efd, mss::SET_DRAM_RTT_NOM_RD,
                                                 l_dram_rtt_nom_rd_bytes[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::ATTR_CHANNEL_B]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_NOM_BYTE5_RD, i_efd, mss::SET_DRAM_RTT_NOM_RD,
                                                 l_dram_rtt_nom_rd_bytes[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::ATTR_CHANNEL_A]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DRAM_RTT_NOM_BYTE7_RD, i_efd, mss::SET_DRAM_RTT_NOM_RD,
                                                 l_dram_rtt_nom_rd_bytes[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::ATTR_CHANNEL_B]));
            }

            // Map SPD value to desired setting
            for(uint8_t l_channel = 0; l_channel < mss::ddr5::mr::ATTR_NUM_CHANNELS; l_channel++)
            {
                FAPI_TRY(lookup_table_check(iv_ocmb, DRAM_RTT_NOM_RD_MAP, mss::SET_DRAM_RTT_NOM_RD,
                                            l_dram_rtt_nom_rd_bytes[iv_dimm_rank][l_channel],
                                            l_field[iv_dimm_rank][l_channel]));
            }

            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_dram_rtt_nom_rd(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the Non-Target ODT RD/WR fields
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_nt_odt_rd_wr(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_nt_odt_rd[mss::ddr5::mr::ATTR_RANKS] = {0};
            uint8_t l_nt_odt_wr[mss::ddr5::mr::ATTR_RANKS] = {0};
            uint8_t l_field_wr[mss::ddr5::mr::ATTR_RANKS] = {0};
            uint8_t l_field_rd[mss::ddr5::mr::ATTR_RANKS] = {0};


            // =========================================================
            // EFD Byte 77: Non-Target ODT Read and Write
            // Attribute: ATTR_MEM_EFF_DDR5_RTT_PARK_RD
            //            ATTR_MEM_EFF_DDR5_RTT_PARK_WR
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 152
            // =========================================================
            // Read all the bits for port0
            if(iv_port_rel_pos == 0)
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::NT_ODT_RD_A0_B0_RANK0, i_efd, mss::SET_NT_ODT_RD, l_field_rd[0]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::NT_ODT_WR_A0_B0_RANK0, i_efd, mss::SET_NT_ODT_WR, l_field_wr[0]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::NT_ODT_RD_A0_B0_RANK1, i_efd, mss::SET_NT_ODT_RD, l_field_rd[1]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::NT_ODT_WR_A0_B0_RANK1, i_efd, mss::SET_NT_ODT_WR, l_field_wr[1]));
            }
            else // Read all the bits for port1
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::NT_ODT_RD_A1_B1_RANK0, i_efd, mss::SET_NT_ODT_RD, l_field_rd[0]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::NT_ODT_WR_A1_B1_RANK0, i_efd, mss::SET_NT_ODT_WR, l_field_wr[0]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::NT_ODT_RD_A1_B1_RANK1, i_efd, mss::SET_NT_ODT_RD, l_field_rd[1]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::NT_ODT_WR_A1_B1_RANK1, i_efd, mss::SET_NT_ODT_WR, l_field_wr[1]));
            }

            // Read the attr before setting them to do read modify write
            FAPI_TRY(mss::attr::get_ddr5_rtt_park_rd(iv_dimm, l_nt_odt_rd));
            FAPI_TRY(mss::attr::get_ddr5_rtt_park_wr(iv_dimm, l_nt_odt_wr));

            // RD is read into l_field_rd[rank] set the opposite in the attr
            l_nt_odt_rd[iv_dimm_rank] = (l_field_rd[iv_dimm_rank] == 0) ? 0xf : 0x0;
            // WR is read into l_field_wr[rank] set the opposite in the attr
            l_nt_odt_wr[iv_dimm_rank] = (l_field_wr[iv_dimm_rank] == 0) ? 0xf : 0x0;

            // Set the attributes
            FAPI_TRY(mss::attr::set_ddr5_rtt_park_rd(iv_dimm, l_nt_odt_rd));
            FAPI_TRY(mss::attr::set_ddr5_rtt_park_wr(iv_dimm, l_nt_odt_wr));

        fapi_try_exit:
            return fapi2::current_err;
        }


        ///
        /// @brief Set the CK/CS ODT and CA Termination
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        /// @note: Decoding this for channel A
        virtual fapi2::ReturnCode set_ck_odt(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_ck_odt_byte[mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_STRAP] = {};
            uint16_t l_field[mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_STRAP] = {};

            // =========================================================
            // EFD Byte 82-97: CK/CS ODT and CA Termination
            // Attribute: ATTR_DDR5_DRAM_CK_ODT
            // MODE REG: MR32
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 150-151
            // =========================================================
            static const std::vector< std::pair<uint8_t, uint16_t> > CK_ODT_STRAP_MAP =
            {
                // {key byte, DRAM RTT PARK (ohm)}
                {0b000, fapi2::ENUM_ATTR_DDR5_DRAM_CK_ODT_DISABLE},
                {0b001, fapi2::ENUM_ATTR_DDR5_DRAM_CK_ODT_OHM480},
                {0b010, fapi2::ENUM_ATTR_DDR5_DRAM_CK_ODT_OHM240},
                {0b011, fapi2::ENUM_ATTR_DDR5_DRAM_CK_ODT_OHM120},
                {0b100, fapi2::ENUM_ATTR_DDR5_DRAM_CK_ODT_OHM80},
                {0b101, fapi2::ENUM_ATTR_DDR5_DRAM_CK_ODT_OHM60},
                {0b111, fapi2::ENUM_ATTR_DDR5_DRAM_CK_ODT_OHM40},

                // All others reserved
            };

            // Get the attr so that only the bits that changed are written
            // when we set the attr
            FAPI_TRY(mss::attr::get_ddr5_dram_ck_odt(iv_dimm, l_field));

            // [PORT][RANK][STRAP]
            //  [0]   [0]    [0] = ODT_CA_GRPA_CK_BYTE0
            //  [0]   [0]    [1] = ODT_CA_GRPB_CK_BYTE0
            //  [0]   [1]    [0] = ODT_CA_GRPA_CK_BYTE1
            //  [0]   [1]    [1] = ODT_CA_GRPB_CK_BYTE1
            //  [1]   [0]    [0] = ODT_CA_GRPA_CK_BYTE4
            //  [1]   [0]    [1] = ODT_CA_GRPB_CK_BYTE4
            //  [1]   [1]    [0] = ODT_CA_GRPA_CK_BYTE5
            //  [1]   [1]    [1] = ODT_CA_GRPB_CK_BYTE5
            if (iv_port_rel_pos == 0) // Port 0
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ODT_CA_GRPA_CK_BYTE0, i_efd, SET_ODT_CK_GRPA,
                                                 l_ck_odt_byte[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::STRAPA]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ODT_CA_GRPB_CK_BYTE0, i_efd, SET_ODT_CK_GRPB,
                                                 l_ck_odt_byte[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::STRAPB]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ODT_CA_GRPA_CK_BYTE1, i_efd, SET_ODT_CK_GRPA,
                                                 l_ck_odt_byte[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::STRAPA]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ODT_CA_GRPB_CK_BYTE1, i_efd, SET_ODT_CK_GRPB,
                                                 l_ck_odt_byte[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::STRAPB]));

            }
            else // Port 1
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ODT_CA_GRPA_CK_BYTE4, i_efd, SET_ODT_CK_GRPA,
                                                 l_ck_odt_byte[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::STRAPA]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ODT_CA_GRPB_CK_BYTE4, i_efd, SET_ODT_CK_GRPB,
                                                 l_ck_odt_byte[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::STRAPB]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ODT_CA_GRPA_CK_BYTE5, i_efd, SET_ODT_CK_GRPA,
                                                 l_ck_odt_byte[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::STRAPA]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ODT_CA_GRPB_CK_BYTE5, i_efd, SET_ODT_CK_GRPB,
                                                 l_ck_odt_byte[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::STRAPB]));
            }

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, CK_ODT_STRAP_MAP, SET_ODT_CK_GRPA,
                                        l_ck_odt_byte[iv_dimm_rank][mss::ddr5::mr::STRAPA],
                                        l_field[iv_dimm_rank][mss::ddr5::mr::STRAPA]));

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, CK_ODT_STRAP_MAP, SET_ODT_CK_GRPB,
                                        l_ck_odt_byte[iv_dimm_rank][mss::ddr5::mr::STRAPB],
                                        l_field[iv_dimm_rank][mss::ddr5::mr::STRAPB]));

            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_dram_ck_odt(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the CK/CS ODT and CA Termination
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_cs_odt(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_cs_odt_byte[mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_STRAP] = {};
            uint16_t l_field[mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_STRAP] = {};

            // =========================================================
            // EFD Byte 82-97: CK/CS ODT and CA Termination
            // Attribute: ATTR_DDR5_DRAM_CS_ODT
            // MODE REG: MR32
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 150-151
            // =========================================================

            static const std::vector< std::pair<uint8_t, uint16_t> > CS_ODT_STRAP_MAP =
            {
                // {key byte, DRAM RTT PARK (ohm)}
                {0b000, fapi2::ENUM_ATTR_DDR5_DRAM_CS_ODT_DISABLE},
                {0b001, fapi2::ENUM_ATTR_DDR5_DRAM_CS_ODT_OHM480},
                {0b010, fapi2::ENUM_ATTR_DDR5_DRAM_CS_ODT_OHM240},
                {0b011, fapi2::ENUM_ATTR_DDR5_DRAM_CS_ODT_OHM120},
                {0b100, fapi2::ENUM_ATTR_DDR5_DRAM_CS_ODT_OHM80},
                {0b101, fapi2::ENUM_ATTR_DDR5_DRAM_CS_ODT_OHM60},
                {0b111, fapi2::ENUM_ATTR_DDR5_DRAM_CS_ODT_OHM40},

                // All others reserved
            };

            // Get the attr so that only the bits that changed are written
            // when we set the attr
            FAPI_TRY(mss::attr::get_ddr5_dram_cs_odt(iv_dimm, l_field));

            // [PORT][RANK][STRAP]
            //  [0]   [0]    [0] = ODT_CA_GRPA_CS_BYTE0
            //  [0]   [0]    [1] = ODT_CA_GRPB_CS_BYTE0
            //  [0]   [1]    [0] = ODT_CA_GRPA_CS_BYTE1
            //  [0]   [1]    [1] = ODT_CA_GRPB_CS_BYTE1
            //  [1]   [0]    [0] = ODT_CA_GRPA_CS_BYTE4
            //  [1]   [0]    [1] = ODT_CA_GRPB_CS_BYTE4
            //  [1]   [1]    [0] = ODT_CA_GRPA_CS_BYTE5
            //  [1]   [1]    [1] = ODT_CA_GRPB_CS_BYTE5
            if (iv_port_rel_pos == 0) // Port 0
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ODT_CA_GRPA_CS_BYTE0, i_efd, SET_ODT_CS_GRPA,
                                                 l_cs_odt_byte[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::STRAPA]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ODT_CA_GRPB_CS_BYTE0, i_efd, SET_ODT_CS_GRPB,
                                                 l_cs_odt_byte[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::STRAPB]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ODT_CA_GRPA_CS_BYTE1, i_efd, SET_ODT_CS_GRPA,
                                                 l_cs_odt_byte[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::STRAPA]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ODT_CA_GRPB_CS_BYTE1, i_efd, SET_ODT_CS_GRPB,
                                                 l_cs_odt_byte[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::STRAPB]));

            }
            else // Port 1
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ODT_CA_GRPA_CS_BYTE4, i_efd, SET_ODT_CS_GRPA,
                                                 l_cs_odt_byte[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::STRAPA]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ODT_CA_GRPB_CS_BYTE4, i_efd, SET_ODT_CS_GRPB,
                                                 l_cs_odt_byte[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::STRAPB]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ODT_CA_GRPA_CS_BYTE5, i_efd, SET_ODT_CS_GRPA,
                                                 l_cs_odt_byte[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::STRAPA]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::ODT_CA_GRPB_CS_BYTE5, i_efd, SET_ODT_CS_GRPB,
                                                 l_cs_odt_byte[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::STRAPB]));
            }

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, CS_ODT_STRAP_MAP, SET_ODT_CS_GRPA,
                                        l_cs_odt_byte[iv_dimm_rank][mss::ddr5::mr::STRAPA],
                                        l_field[iv_dimm_rank][mss::ddr5::mr::STRAPA]));

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, CS_ODT_STRAP_MAP, SET_ODT_CS_GRPB,
                                        l_cs_odt_byte[iv_dimm_rank][mss::ddr5::mr::STRAPB],
                                        l_field[iv_dimm_rank][mss::ddr5::mr::STRAPB]));

            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_dram_cs_odt(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the CK/CS ODT and CA Termination
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_ck_odt_per_dram(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_dram_ck_odt_byte[mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_DRAM] = {};
            uint16_t l_dram_ck_odt[mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_DRAM] = {};

            // =========================================================
            // EFD Byte 98-177: CK/CS ODT and CA Termination Per DRAM
            // Attribute: ATTR_DDR5_DRAM_CK_ODT_PER_DRAM
            // MODE REG: MR32
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 152-153
            // =========================================================
            static const std::vector< std::pair<uint8_t, uint16_t> > CK_ODT_DRAM_MAP =
            {
                // {key byte, DRAM RTT PARK (ohm)}
                {0b000, fapi2::ENUM_ATTR_DDR5_DRAM_CK_ODT_PER_DRAM_DISABLE},
                {0b001, fapi2::ENUM_ATTR_DDR5_DRAM_CK_ODT_PER_DRAM_OHM480},
                {0b010, fapi2::ENUM_ATTR_DDR5_DRAM_CK_ODT_PER_DRAM_OHM240},
                {0b011, fapi2::ENUM_ATTR_DDR5_DRAM_CK_ODT_PER_DRAM_OHM120},
                {0b100, fapi2::ENUM_ATTR_DDR5_DRAM_CK_ODT_PER_DRAM_OHM80},
                {0b101, fapi2::ENUM_ATTR_DDR5_DRAM_CK_ODT_PER_DRAM_OHM60},
                {0b111, fapi2::ENUM_ATTR_DDR5_DRAM_CK_ODT_PER_DRAM_OHM40},

                // All others reserved
            };
            FAPI_TRY(mss::attr::get_ddr5_dram_ck_odt_per_dram(iv_dimm, l_dram_ck_odt));
            FAPI_TRY(mss::spd::set_bytes_per_dram_helper_func(iv_dimm, F::ODT_CA_CK_BYTE0, i_efd, SET_CK_ODT_DRAM, iv_dimm_rank,
                     iv_port_rel_pos, l_dram_ck_odt_byte));

            for(uint8_t l_dram = 0; l_dram < 20; l_dram++)
            {
                // Map SPD value to desired setting
                FAPI_TRY(lookup_table_check(iv_ocmb, CK_ODT_DRAM_MAP, SET_CK_ODT_DRAM, l_dram_ck_odt_byte[iv_dimm_rank][l_dram],
                                            l_dram_ck_odt[iv_dimm_rank][l_dram]));
            }

            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_dram_ck_odt_per_dram(iv_dimm, l_dram_ck_odt));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the CK/CS ODT and CA Termination
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_cs_odt_per_dram(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_dram_cs_odt_byte[mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_DRAM] = {};
            uint16_t l_dram_cs_odt[mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_DRAM] = {};

            // =========================================================
            // EFD Byte 98-177: CK/CS ODT and CA Termination Per DRAM
            // Attribute: ATTR_DDR5_DRAM_CS_ODT_PER_DRAM
            // MODE REG: MR32
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 152-153
            // =========================================================
            static const std::vector< std::pair<uint8_t, uint16_t> > CS_ODT_DRAM_MAP =
            {
                // {key byte, DRAM RTT PARK (ohm)}
                {0b000, fapi2::ENUM_ATTR_DDR5_DRAM_CS_ODT_PER_DRAM_DISABLE},
                {0b001, fapi2::ENUM_ATTR_DDR5_DRAM_CS_ODT_PER_DRAM_OHM480},
                {0b010, fapi2::ENUM_ATTR_DDR5_DRAM_CS_ODT_PER_DRAM_OHM240},
                {0b011, fapi2::ENUM_ATTR_DDR5_DRAM_CS_ODT_PER_DRAM_OHM120},
                {0b100, fapi2::ENUM_ATTR_DDR5_DRAM_CS_ODT_PER_DRAM_OHM80},
                {0b101, fapi2::ENUM_ATTR_DDR5_DRAM_CS_ODT_PER_DRAM_OHM60},
                {0b111, fapi2::ENUM_ATTR_DDR5_DRAM_CS_ODT_PER_DRAM_OHM40},

                // All others reserved
            };
            FAPI_TRY(mss::attr::get_ddr5_dram_cs_odt_per_dram(iv_dimm, l_dram_cs_odt));
            FAPI_TRY(mss::spd::set_bytes_per_dram_helper_func(iv_dimm, F::ODT_CA_CS_BYTE0, i_efd, SET_CS_ODT_DRAM, iv_dimm_rank,
                     iv_port_rel_pos, l_dram_cs_odt_byte));

            for(uint8_t l_dram = 0; l_dram < 20; l_dram++)
            {
                // Map SPD value to desired setting
                FAPI_TRY(lookup_table_check(iv_ocmb, CS_ODT_DRAM_MAP, SET_CS_ODT_DRAM, l_dram_cs_odt_byte[iv_dimm_rank][l_dram],
                                            l_dram_cs_odt[iv_dimm_rank][l_dram]));
            }

            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_dram_cs_odt_per_dram(iv_dimm, l_dram_cs_odt));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the CA ODT field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_ca_odt(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_ca_odt_byte[mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_STRAP] = {};
            uint16_t l_field[mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_STRAP] = {};

            // =========================================================
            // EFD Byte 178-193: : CA ODT and DQS Park Termination
            //                     Group A Settings Per Rank
            // Attribute: ATTR_DDR5_DRAM_CA_ODT
            // MODE REG: MR33
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 153-154
            // =========================================================
            static const std::vector< std::pair<uint8_t, uint16_t> > CA_ODT_STRAP_MAP =
            {
                // {key byte, DRAM RTT PARK (ohm)}
                {0b000, fapi2::ENUM_ATTR_DDR5_DRAM_CA_ODT_DISABLE},
                {0b001, fapi2::ENUM_ATTR_DDR5_DRAM_CA_ODT_OHM480},
                {0b010, fapi2::ENUM_ATTR_DDR5_DRAM_CA_ODT_OHM240},
                {0b011, fapi2::ENUM_ATTR_DDR5_DRAM_CA_ODT_OHM120},
                {0b100, fapi2::ENUM_ATTR_DDR5_DRAM_CA_ODT_OHM80},
                {0b101, fapi2::ENUM_ATTR_DDR5_DRAM_CA_ODT_OHM60},
                {0b111, fapi2::ENUM_ATTR_DDR5_DRAM_CA_ODT_OHM40},

                // All others reserved
            };

            // Get the attr so that only the bits that changed are written
            // when we set the attr
            FAPI_TRY(mss::attr::get_ddr5_dram_ca_odt(iv_dimm, l_field));

            // [PORT][RANK][STRAP]
            //  [0]   [0]    [0] = CA_ODT_DQS_GRPA_BYTE0
            //  [0]   [0]    [1] = CA_ODT_DQS_GRPB_BYTE0
            //  [0]   [1]    [0] = CA_ODT_DQS_GRPA_BYTE1
            //  [0]   [1]    [1] = CA_ODT_DQS_GRPB_BYTE1
            //  [1]   [0]    [0] = CA_ODT_DQS_GRPA_BYTE4
            //  [1]   [0]    [1] = CA_ODT_DQS_GRPB_BYTE4
            //  [1]   [1]    [0] = CA_ODT_DQS_GRPA_BYTE5
            //  [1]   [1]    [1] = CA_ODT_DQS_GRPB_BYTE5
            if (iv_port_rel_pos == 0) // Port 0
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::CA_ODT_DQS_GRPA_BYTE0, i_efd, SET_CA_ODT_GRPA,
                                                 l_ca_odt_byte[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::STRAPA]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::CA_ODT_DQS_GRPB_BYTE0, i_efd, SET_CA_ODT_GRPB,
                                                 l_ca_odt_byte[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::STRAPB]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::CA_ODT_DQS_GRPA_BYTE1, i_efd, SET_CA_ODT_GRPA,
                                                 l_ca_odt_byte[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::STRAPA]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::CA_ODT_DQS_GRPB_BYTE1, i_efd, SET_CA_ODT_GRPB,
                                                 l_ca_odt_byte[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::STRAPB]));

            }
            else // Port 1
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::CA_ODT_DQS_GRPA_BYTE4, i_efd, SET_CA_ODT_GRPA,
                                                 l_ca_odt_byte[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::STRAPA]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::CA_ODT_DQS_GRPB_BYTE4, i_efd, SET_CA_ODT_GRPB,
                                                 l_ca_odt_byte[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::STRAPB]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::CA_ODT_DQS_GRPA_BYTE5, i_efd, SET_CA_ODT_GRPA,
                                                 l_ca_odt_byte[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::STRAPA]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::CA_ODT_DQS_GRPB_BYTE5, i_efd, SET_CA_ODT_GRPB,
                                                 l_ca_odt_byte[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::STRAPB]));
            }

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, CA_ODT_STRAP_MAP, SET_CA_ODT_GRPA,
                                        l_ca_odt_byte[iv_dimm_rank][mss::ddr5::mr::STRAPA],
                                        l_field[iv_dimm_rank][mss::ddr5::mr::STRAPA]));

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, CA_ODT_STRAP_MAP, SET_CA_ODT_GRPB,
                                        l_ca_odt_byte[iv_dimm_rank][mss::ddr5::mr::STRAPB],
                                        l_field[iv_dimm_rank][mss::ddr5::mr::STRAPB]));

            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_dram_ca_odt(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the DQS field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dqs_odt(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_dqs_odt_byte[mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_STRAP] = {};
            uint8_t l_field[mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_STRAP] = {};

            // =========================================================
            // EFD Byte 178-193: : CA ODT and DQS Park Termination
            //                     Group A Settings Per Rank
            // Attribute: ATTR_DDR5_DRAM_DQS_RTT_PARK
            // MODE REG: MR33
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 153-154
            // =========================================================
            static const std::vector< std::pair<uint8_t, uint8_t> > DQS_ODT_STRAP_MAP =
            {
                // {key byte, DRAM RTT PARK (ohm)}
                {0b000, fapi2::ENUM_ATTR_DDR5_DRAM_DQS_RTT_PARK_DISABLE},
                {0b001, fapi2::ENUM_ATTR_DDR5_DRAM_DQS_RTT_PARK_OHM240},
                {0b010, fapi2::ENUM_ATTR_DDR5_DRAM_DQS_RTT_PARK_OHM120},
                {0b011, fapi2::ENUM_ATTR_DDR5_DRAM_DQS_RTT_PARK_OHM80},
                {0b100, fapi2::ENUM_ATTR_DDR5_DRAM_DQS_RTT_PARK_OHM60},
                {0b101, fapi2::ENUM_ATTR_DDR5_DRAM_DQS_RTT_PARK_OHM48},
                {0b110, fapi2::ENUM_ATTR_DDR5_DRAM_DQS_RTT_PARK_OHM40},
                {0b111, fapi2::ENUM_ATTR_DDR5_DRAM_DQS_RTT_PARK_OHM34},

                // All others reserved
            };

            // Get the attr so that only the bits that changed are written
            // when we set the attr
            FAPI_TRY(mss::attr::get_ddr5_dram_dqs_rtt_park(iv_dimm, l_field));

            // [PORT][RANK][STRAP]
            //  [0]   [0]    [0] = DQS_RTT_PARK_GRPA_BYTE0
            //  [0]   [0]    [1] = DQS_RTT_PARK_GRPB_BYTE0
            //  [0]   [1]    [0] = DQS_RTT_PARK_GRPA_BYTE1
            //  [0]   [1]    [1] = DQS_RTT_PARK_GRPB_BYTE1
            //  [1]   [0]    [0] = DQS_RTT_PARK_GRPA_BYTE4
            //  [1]   [0]    [1] = DQS_RTT_PARK_GRPB_BYTE4
            //  [1]   [1]    [0] = DQS_RTT_PARK_GRPA_BYTE5
            //  [1]   [1]    [1] = DQS_RTT_PARK_GRPB_BYTE5
            if (iv_port_rel_pos == 0) // Port 0
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DQS_RTT_PARK_GRPA_BYTE0, i_efd, SET_DQS_ODT_GRPA,
                                                 l_dqs_odt_byte[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::STRAPA]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DQS_RTT_PARK_GRPB_BYTE0, i_efd, SET_DQS_ODT_GRPB,
                                                 l_dqs_odt_byte[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::STRAPB]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DQS_RTT_PARK_GRPA_BYTE1, i_efd, SET_DQS_ODT_GRPA,
                                                 l_dqs_odt_byte[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::STRAPA]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DQS_RTT_PARK_GRPB_BYTE1, i_efd, SET_DQS_ODT_GRPB,
                                                 l_dqs_odt_byte[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::STRAPB]));
            }
            else // Port 1
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DQS_RTT_PARK_GRPA_BYTE4, i_efd, SET_DQS_ODT_GRPA,
                                                 l_dqs_odt_byte[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::STRAPA]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DQS_RTT_PARK_GRPB_BYTE4, i_efd, SET_DQS_ODT_GRPB,
                                                 l_dqs_odt_byte[mss::common_consts::ATTR_RANK0][mss::ddr5::mr::STRAPB]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DQS_RTT_PARK_GRPA_BYTE5, i_efd, SET_DQS_ODT_GRPA,
                                                 l_dqs_odt_byte[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::STRAPA]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::DQS_RTT_PARK_GRPB_BYTE5, i_efd, SET_DQS_ODT_GRPB,
                                                 l_dqs_odt_byte[mss::common_consts::ATTR_RANK1][mss::ddr5::mr::STRAPB]));
            }

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, DQS_ODT_STRAP_MAP, SET_DQS_ODT_GRPA,
                                        l_dqs_odt_byte[iv_dimm_rank][mss::ddr5::mr::STRAPA],
                                        l_field[iv_dimm_rank][mss::ddr5::mr::STRAPA]));

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, DQS_ODT_STRAP_MAP, SET_DQS_ODT_GRPB,
                                        l_dqs_odt_byte[iv_dimm_rank][mss::ddr5::mr::STRAPB],
                                        l_field[iv_dimm_rank][mss::ddr5::mr::STRAPB]));

            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_dram_dqs_rtt_park(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the CA ODT field per DRAM
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_ca_odt_dram(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_dram_ca_odt_byte[mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_DRAM] = {};
            uint16_t l_dram_ca_odt[mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_DRAM] = {};

            // =========================================================
            // EFD Byte 194-273: : CA ODT and DQS Park Termination
            //                     Group A Settings Per DRAM
            // Attribute: ATTR_DDR5_DRAM_CA_ODT_PER_DRAM
            // MODE REG: MR33
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 154-155
            // =========================================================
            static const std::vector< std::pair<uint8_t, uint16_t> > CA_ODT_DRAM_MAP =
            {
                // {key byte, DRAM RTT PARK (ohm)}
                {0b000, fapi2::ENUM_ATTR_DDR5_DRAM_CA_ODT_PER_DRAM_DISABLE},
                {0b001, fapi2::ENUM_ATTR_DDR5_DRAM_CA_ODT_PER_DRAM_OHM480},
                {0b010, fapi2::ENUM_ATTR_DDR5_DRAM_CA_ODT_PER_DRAM_OHM240},
                {0b011, fapi2::ENUM_ATTR_DDR5_DRAM_CA_ODT_PER_DRAM_OHM120},
                {0b100, fapi2::ENUM_ATTR_DDR5_DRAM_CA_ODT_PER_DRAM_OHM80},
                {0b101, fapi2::ENUM_ATTR_DDR5_DRAM_CA_ODT_PER_DRAM_OHM60},
                {0b111, fapi2::ENUM_ATTR_DDR5_DRAM_CA_ODT_PER_DRAM_OHM40},

                // All others reserved
            };

            // Get the attr so that only the bits that changed are written
            // when we set the attr
            FAPI_TRY(mss::attr::get_ddr5_dram_ca_odt_per_dram(iv_dimm, l_dram_ca_odt));
            FAPI_TRY(mss::spd::set_bytes_per_dram_helper_func(iv_dimm, F::CA_ODT_BYTE0, i_efd, SET_CA_ODT_DRAM, iv_dimm_rank,
                     iv_port_rel_pos, l_dram_ca_odt_byte));

            for(uint8_t l_dram = 0; l_dram < mss::ddr5::mr::ATTR_DRAM; l_dram++)
            {
                // Map SPD value to desired setting
                FAPI_TRY(lookup_table_check(iv_ocmb, CA_ODT_DRAM_MAP, SET_CS_ODT_DRAM, l_dram_ca_odt_byte[iv_dimm_rank][l_dram],
                                            l_dram_ca_odt[iv_dimm_rank][l_dram]));
            }

            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_dram_ca_odt_per_dram(iv_dimm, l_dram_ca_odt));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the DQS field per DRAM
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dqs_odt_dram(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_dram_dqs_odt_byte[mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_DRAM] = {};
            uint8_t l_dram_dqs_odt[mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_DRAM] = {};

            // =========================================================
            // EFD Byte 194-273: : CA ODT and DQS Park Termination
            //                     Group A Settings Per DRAM
            // Attribute: ATTR_DDR5_DRAM_DQS_RTT_PARK_PER_DRAM
            // MODE REG: MR33
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 154-155
            // =========================================================
            static const std::vector< std::pair<uint8_t, uint8_t> > DQS_ODT_DRAM_MAP =
            {
                // {key byte, DRAM RTT PARK (ohm)}
                {0b000, fapi2::ENUM_ATTR_DDR5_DRAM_DQS_RTT_PARK_PER_DRAM_DISABLE},
                {0b001, fapi2::ENUM_ATTR_DDR5_DRAM_DQS_RTT_PARK_PER_DRAM_OHM240},
                {0b010, fapi2::ENUM_ATTR_DDR5_DRAM_DQS_RTT_PARK_PER_DRAM_OHM120},
                {0b011, fapi2::ENUM_ATTR_DDR5_DRAM_DQS_RTT_PARK_PER_DRAM_OHM80},
                {0b100, fapi2::ENUM_ATTR_DDR5_DRAM_DQS_RTT_PARK_PER_DRAM_OHM60},
                {0b101, fapi2::ENUM_ATTR_DDR5_DRAM_DQS_RTT_PARK_PER_DRAM_OHM48},
                {0b110, fapi2::ENUM_ATTR_DDR5_DRAM_DQS_RTT_PARK_PER_DRAM_OHM40},
                {0b111, fapi2::ENUM_ATTR_DDR5_DRAM_DQS_RTT_PARK_PER_DRAM_OHM34},
                // All others reserved
            };
            FAPI_TRY(mss::attr::get_ddr5_dram_dqs_rtt_park_per_dram(iv_dimm, l_dram_dqs_odt));
            FAPI_TRY(mss::spd::set_bytes_per_dram_helper_func(iv_dimm, F::DQS_RTT_PARK_BYTE0, i_efd, SET_DQS_ODT_DRAM, iv_dimm_rank,
                     iv_port_rel_pos, l_dram_dqs_odt_byte));

            for(uint8_t l_dram = 0; l_dram < mss::ddr5::mr::ATTR_DRAM; l_dram++)
            {
                // Map SPD value to desired setting
                FAPI_TRY(lookup_table_check(iv_ocmb, DQS_ODT_DRAM_MAP, SET_DQS_ODT_DRAM, l_dram_dqs_odt_byte[iv_dimm_rank][l_dram],
                                            l_dram_dqs_odt[iv_dimm_rank][l_dram]));
            }

            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_dram_dqs_rtt_park_per_dram(iv_dimm, l_dram_dqs_odt));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the ODTL ON WR
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        /// @note: Coding this for channel A only.
        virtual fapi2::ReturnCode set_odtlon_wr(const std::vector<uint8_t>& i_efd) const
        {
            int8_t l_field[mss::ddr5::mr::ATTR_RANKS] = {0};
            uint8_t l_odtlon_wr = 0;


            // =========================================================
            // EFD Byte 274-281: ODTL Write Control Offset
            //                 Per Channel Per Rank
            // Attribute: ATTR_DDR5_DRAM_ODTLON_WR
            // MODE REG: MR37
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 155-156
            // =========================================================
            static const std::vector< std::pair<uint8_t, int8_t> > ODTL_ON_WR_MAP =
            {
                // {key byte, clocks}
                {0b001, -4},
                {0b010, -3},
                {0b011, -2},
                {0b100, -1},
                {0b101,  0},
                {0b110,  1},
                {0b111,  2},

                // All others reserved
            };

            FAPI_TRY(mss::attr::get_ddr5_dram_odtlon_wr(iv_dimm, l_field));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb,
                                             F::ODTL_WR_CNTRL_ON_OFFSET[mss::ddr5::mr::ATTR_CHANNEL_A][iv_port_rel_pos][iv_dimm_rank],
                                             i_efd,
                                             mss::SET_ODTLON_WR,
                                             l_odtlon_wr));

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, ODTL_ON_WR_MAP, mss::SET_ODTLON_WR,
                                        l_odtlon_wr, l_field[iv_dimm_rank]));

            FAPI_TRY(mss::attr::set_ddr5_dram_odtlon_wr(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the ODTL OFF WR
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        /// @note: Coding this for channel A only.
        virtual fapi2::ReturnCode set_odtloff_wr(const std::vector<uint8_t>& i_efd) const
        {
            int8_t l_field[mss::ddr5::mr::ATTR_RANKS] = {0};
            uint8_t l_odtloff_wr = 0;

            // =========================================================
            // EFD Byte 274-281: ODTL Write Control Offset
            //                 Per Channel Per Rank
            // Attribute: ATTR_DDR5_DRAM_ODTLOFF_WR
            // MODE REG: MR37
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 155-156
            // =========================================================
            static const std::vector< std::pair<uint8_t, int8_t> > ODTL_OFF_WR_MAP =
            {
                // {key byte, clocks}
                {0b001,  4},
                {0b010,  3},
                {0b011,  2},
                {0b100,  1},
                {0b101,  0},
                {0b110, -1},
                {0b111, -2},

                // All others reserved
            };

            FAPI_TRY(mss::attr::get_ddr5_dram_odtloff_wr(iv_dimm, l_field));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb,
                                             F::ODTL_WR_CNTRL_OFF_OFFSET[mss::ddr5::mr::ATTR_CHANNEL_A][iv_port_rel_pos][iv_dimm_rank],
                                             i_efd,
                                             mss::SET_ODTLOFF_WR,
                                             l_odtloff_wr));

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, ODTL_OFF_WR_MAP, mss::SET_ODTLOFF_WR,
                                        l_odtloff_wr, l_field[iv_dimm_rank]));

            FAPI_TRY(mss::attr::set_ddr5_dram_odtloff_wr(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the ODTL ON WR NT
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        /// @note: Coding this for channel A only.
        virtual fapi2::ReturnCode set_odtlon_wr_nt(const std::vector<uint8_t>& i_efd) const
        {
            int8_t l_field[mss::ddr5::mr::ATTR_RANKS] = {0};
            uint8_t l_odtlon_wr_nt = 0;

            // =========================================================
            // EFD Byte 282-289: ODTL NT Write Control Offset
            //                 Per Channel Per Rank
            // Attribute: ATTR_DDR5_DRAM_ODTLON_WR_NT
            // MODE REG: MR38
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 156
            // =========================================================
            static const std::vector< std::pair<uint8_t, int8_t> > ODTL_ON_WR_NT_MAP =
            {
                // {key byte, clocks}
                {0b001, -4},
                {0b010, -3},
                {0b011, -2},
                {0b100, -1},
                {0b101,  0},
                {0b110,  1},
                {0b111,  2},

                // All others reserved
            };

            FAPI_TRY(mss::attr::get_ddr5_dram_odtlon_wr_nt(iv_dimm, l_field));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb,
                                             F::ODTL_NT_WR_CNTRL_ON_OFFSET[mss::ddr5::mr::ATTR_CHANNEL_A][iv_port_rel_pos][iv_dimm_rank],
                                             i_efd,
                                             mss::SET_ODTLON_WR_NT,
                                             l_odtlon_wr_nt));

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, ODTL_ON_WR_NT_MAP, mss::SET_ODTLON_WR_NT,
                                        l_odtlon_wr_nt, l_field[iv_dimm_rank]));

            FAPI_TRY(mss::attr::set_ddr5_dram_odtlon_wr_nt(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the ODTL OFF WR NT
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        /// @note: Coding this for channel A only.
        virtual fapi2::ReturnCode set_odtloff_wr_nt(const std::vector<uint8_t>& i_efd) const
        {
            int8_t l_field[mss::ddr5::mr::ATTR_RANKS] = {0};
            uint8_t l_odtloff_wr_nt = 0;

            // =========================================================
            // EFD Byte 282-289: ODTL NT Write Control Offset
            //                 Per Channel Per Rank
            // Attribute: ATTR_DDR5_DRAM_ODTLOFF_WR_NT
            // MODE REG: MR38
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 156
            // =========================================================
            static const std::vector< std::pair<uint8_t, int8_t> > ODTL_OFF_WR_NT_MAP =
            {
                // {key byte, clocks}
                {0b001,  4},
                {0b010,  3},
                {0b011,  2},
                {0b100,  1},
                {0b101,  0},
                {0b110, -1},
                {0b111, -2},

                // All others reserved
            };

            FAPI_TRY(mss::attr::get_ddr5_dram_odtloff_wr_nt(iv_dimm, l_field));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb,
                                             F::ODTL_NT_WR_CNTRL_OFF_OFFSET[mss::ddr5::mr::ATTR_CHANNEL_A][iv_port_rel_pos][iv_dimm_rank],
                                             i_efd,
                                             mss::SET_ODTLOFF_WR_NT,
                                             l_odtloff_wr_nt));

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, ODTL_OFF_WR_NT_MAP, mss::SET_ODTLOFF_WR_NT,
                                        l_odtloff_wr_nt, l_field[iv_dimm_rank]));

            FAPI_TRY(mss::attr::set_ddr5_dram_odtloff_wr_nt(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the ODTL ON RD NT
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        /// @note: Coding this for channel A only.
        virtual fapi2::ReturnCode set_odtlon_rd_nt(const std::vector<uint8_t>& i_efd) const
        {
            int8_t l_field[mss::ddr5::mr::ATTR_RANKS] = {0};
            uint8_t l_odtlon_rd_nt = 0;

            // =========================================================
            // EFD Byte 290-297: ODTL NT Read Control Offset
            //                 Per Channel Per Rank
            // Attribute: ATTR_DDR5_DRAM_ODTLON_RD_NT
            // MODE REG: MR39
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 156
            // =========================================================
            static const std::vector< std::pair<uint8_t, int8_t> > ODTL_ON_RD_NT_MAP =
            {
                // {key byte, clocks}
                {0b010, -3},
                {0b011, -2},
                {0b100, -1},
                {0b101,  0},
                {0b110,  1},
                // All others reserved
            };

            FAPI_TRY(mss::attr::get_ddr5_dram_odtlon_rd_nt(iv_dimm, l_field));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb,
                                             F::ODTL_NT_RD_CNTRL_ON_OFFSET[mss::ddr5::mr::ATTR_CHANNEL_A][iv_port_rel_pos][iv_dimm_rank],
                                             i_efd,
                                             mss::SET_ODTLON_RD_NT,
                                             l_odtlon_rd_nt));

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, ODTL_ON_RD_NT_MAP, mss::SET_ODTLON_RD_NT,
                                        l_odtlon_rd_nt, l_field[iv_dimm_rank]));

            FAPI_TRY(mss::attr::set_ddr5_dram_odtlon_rd_nt(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the ODTL OFF WR NT
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        /// @note: Coding this for channel A only.
        virtual fapi2::ReturnCode set_odtloff_rd_nt(const std::vector<uint8_t>& i_efd) const
        {
            int8_t l_field[mss::ddr5::mr::ATTR_RANKS] = {0};
            uint8_t l_odtloff_rd_nt = 0;

            // =========================================================
            // EFD Byte 290-297: ODTL NT Read Control Offset
            //                 Per Channel Per Rank
            // Attribute: ATTR_DDR5_DRAM_ODTLOFF_RD_NT
            // MODE REG: MR39
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 156
            // =========================================================
            static const std::vector< std::pair<uint8_t, int8_t> > ODTL_OFF_RD_NT_MAP =
            {
                // {key byte, clocks}
                {0b010,  3},
                {0b011,  2},
                {0b100,  1},
                {0b101,  0},
                {0b110, -1},
                // All others reserved
            };

            FAPI_TRY(mss::attr::get_ddr5_dram_odtloff_rd_nt(iv_dimm, l_field));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb,
                                             F::ODTL_NT_RD_CNTRL_OFF_OFFSET[mss::ddr5::mr::ATTR_CHANNEL_A][iv_port_rel_pos][iv_dimm_rank],
                                             i_efd,
                                             mss::SET_ODTLOFF_RD_NT,
                                             l_odtloff_rd_nt));

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_ocmb, ODTL_OFF_RD_NT_MAP, mss::SET_ODTLOFF_RD_NT,
                                        l_odtloff_rd_nt, l_field[iv_dimm_rank]));

            FAPI_TRY(mss::attr::set_ddr5_dram_odtloff_rd_nt(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the VREF CA MAX operatiing point field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dram_vrefca_sweep_max(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_vrefca_sweep_max;

            // Documentation: DDR5 Published spec 10-2021 JESD79-5A
            // Vref_max: 97.5%
            // MAX Value encoding for 97.5% is 00000000
            l_vrefca_sweep_max = 0;
            // =========================================================
            // EFD Byte:
            // Attribute: ATTR_MEM_EFF_DDR5_VREFCA_SWEEP_MAX
            // MODE REG: MR11
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 157-158
            // =========================================================
            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_vrefca_sweep_max(iv_port, l_vrefca_sweep_max));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the VREF CA MIN operating field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dram_vrefca_sweep_min(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_vrefca_sweep_min;

            // Documentation: DDR5 Published spec 10-2021 JESD79-5A
            // Vref_min: 45%
            // MIN Value encoding for 45% is 01101001
            l_vrefca_sweep_min = 0x69;
            // =========================================================
            // EFD Byte:
            // Attribute: ATTR_MEM_EFF_DDR5_VREFCA_SWEEP_MIN
            // MODE REG: MR11
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 157-158
            // =========================================================
            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_vrefca_sweep_min(iv_port, l_vrefca_sweep_min));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the VREF CS MAX operatiing point field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dram_vrefcs_sweep_max(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_vrefcs_sweep_max;

            // Documentation: DDR5 Published spec 10-2021 JESD79-5A
            // Vref_max: 97.5%
            // MAX Value encoding for 97.5% is 00000000
            l_vrefcs_sweep_max = 0;
            // =========================================================
            // EFD Byte:
            // Attribute: ATTR_MEM_EFF_DDR5_VREFCS_SWEEP_MAX
            // MODE REG: MR11
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 157-158
            // =========================================================
            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_vrefcs_sweep_max(iv_port, l_vrefcs_sweep_max));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the VREF CA MIN operating field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dram_vrefcs_sweep_min(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_vrefcs_sweep_min;

            // Documentation: DDR5 Published spec 10-2021 JESD79-5A
            // Vref_min: 45%
            // MIN Value encoding for 45% is 01101001
            l_vrefcs_sweep_min = 0x69;
            // =========================================================
            // EFD Byte:
            // Attribute: ATTR_MEM_EFF_DDR5_VREFCS_SWEEP_MIN
            // MODE REG: MR11
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 157-158
            // =========================================================
            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_vrefcs_sweep_min(iv_port, l_vrefcs_sweep_min));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the VREF CA field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dram_vrefca(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_dram_vrefca_byte[mss::ody::sizes::MAX_RANK_PER_DIMM] = {};
            uint8_t l_dram_vrefca_offset_step[mss::ody::sizes::MAX_RANK_PER_DIMM][mss::ddr5::mr::ATTR_DRAM] = {};
            uint8_t l_dram_vrefca_offset_step_add_sub[mss::ody::sizes::MAX_RANK_PER_DIMM][mss::ddr5::mr::ATTR_DRAM] = {};
            uint8_t l_vref_mult = 0;
            uint8_t l_dram_vrefca_offset_mult = 0;
            uint8_t l_vrefca[mss::ody::sizes::MAX_RANK_PER_DIMM][mss::ddr5::mr::ATTR_DRAM] = {};

            constexpr uint8_t INDEX_A0R0 = 0;
            constexpr uint8_t INDEX_A0R1 = 1;
            constexpr uint8_t INDEX_B0R0 = 2;
            constexpr uint8_t INDEX_B0R1 = 3;

            constexpr uint8_t INDEX_A1R0 = 0;
            constexpr uint8_t INDEX_A1R1 = 1;
            constexpr uint8_t INDEX_B1R0 = 2;
            constexpr uint8_t INDEX_B1R1 = 3;

            // =========================================================
            // EFD Byte 306-313: Base Vref CA Settings Per Rank
            // Attribute: ATTR_DDR5_DRAM_VREFCA
            // MODE REG: MR11
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 157-158
            // =========================================================
            // Get the attr so that only the bits that changed are written
            // when we set the attr
            FAPI_TRY(mss::attr::get_ddr5_dram_vrefca(iv_dimm, l_vrefca));

            // For Port 0 Channel 0
            // A0 R0: Byte 0
            // B0 R0: Byte 2
            // A0 R1: Byte 1
            // B0 R1: Byte 3
            // For Port 0 Channel 1
            // A1 R0: Byte 4
            // B1 R0: Byte 5
            // A1 R1: Byte 6
            // B1 R1: Byte 7
            // Same as above is repeated for Port 1 Channel 0 and Port 1 Channel 1
            if (iv_port_rel_pos == 0) // Port 0
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::BASE_VREF_CA_BYTE0, i_efd, SET_WR_VREFCA_DQ,
                                                 l_dram_vrefca_byte[INDEX_A0R0]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::BASE_VREF_CA_BYTE1, i_efd, SET_WR_VREFCA_DQ,
                                                 l_dram_vrefca_byte[INDEX_A0R1]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::BASE_VREF_CA_BYTE2, i_efd, SET_WR_VREFCA_DQ,
                                                 l_dram_vrefca_byte[INDEX_B0R0]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::BASE_VREF_CA_BYTE3, i_efd, SET_WR_VREFCA_DQ,
                                                 l_dram_vrefca_byte[INDEX_B0R1]));
            }
            else // Port 1
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::BASE_VREF_CA_BYTE4, i_efd, SET_WR_VREFCA_DQ,
                                                 l_dram_vrefca_byte[INDEX_A1R0]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::BASE_VREF_CA_BYTE5, i_efd, SET_WR_VREFCA_DQ,
                                                 l_dram_vrefca_byte[INDEX_A1R1]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::BASE_VREF_CA_BYTE6, i_efd, SET_WR_VREFCA_DQ,
                                                 l_dram_vrefca_byte[INDEX_B1R0]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::BASE_VREF_CA_BYTE7, i_efd, SET_WR_VREFCA_DQ,
                                                 l_dram_vrefca_byte[INDEX_B1R1]));

            }

            // BYTE 324-403 Vref ca offset value and add sub
            FAPI_TRY(mss::spd::set_bytes_per_dram_helper_func(iv_dimm, F::VREF_CA_OFFSET_STEP_BYTE0, i_efd, SET_WR_VREFCA_DQ,
                     iv_dimm_rank,
                     iv_port_rel_pos, l_dram_vrefca_offset_step));

            FAPI_TRY(mss::spd::set_bytes_per_dram_helper_func(iv_dimm, F::VREF_CA_OFFSET_BYTE0_ADD_SUB, i_efd, SET_WR_VREFCA_DQ,
                     iv_dimm_rank,
                     iv_port_rel_pos, l_dram_vrefca_offset_step_add_sub));


            // BYTE 322 Vrefca offset step multiplier
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::VREF_CA_OFFSET_MULT, i_efd, SET_WR_VREFCA_DQ, l_dram_vrefca_offset_mult));
            static const std::vector< std::pair<uint8_t, uint8_t> > VREF_MULT_MAP =
            {
                // {key bits, multiplier}
                {0b001,  1},
                {0b010,  2},
                {0b011,  3},
                {0b100,  4},
                // All others reserved
            };

            FAPI_TRY(lookup_table_check(iv_ocmb, VREF_MULT_MAP, SET_WR_VREFCA_DQ,
                                        l_dram_vrefca_offset_mult, l_vref_mult));

            // Apply offset using helper funct
            FAPI_TRY(mss::gen::ddr5::apply_vref_offset_mult(iv_port,
                     iv_dimm_rank,
                     SET_WR_VREFCA_DQ,
                     l_dram_vrefca_byte,
                     l_dram_vrefca_offset_step_add_sub,
                     l_vref_mult,
                     l_dram_vrefca_offset_step,
                     l_vrefca));
            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_dram_vrefca(iv_dimm, l_vrefca));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the VREF CS field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dram_vrefcs(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_dram_vrefcs_byte[mss::ody::sizes::MAX_RANK_PER_DIMM] = {};
            uint8_t l_dram_vrefcs_offset_step[mss::ody::sizes::MAX_RANK_PER_DIMM][mss::ddr5::mr::ATTR_DRAM] = {};
            uint8_t l_dram_vrefcs_offset_step_add_sub[mss::ody::sizes::MAX_RANK_PER_DIMM][mss::ddr5::mr::ATTR_DRAM] = {};
            uint8_t l_vref_mult = 0;
            uint8_t l_dram_vrefcs_offset_mult = 0;
            uint8_t l_vrefcs[mss::ody::sizes::MAX_RANK_PER_DIMM][mss::ddr5::mr::ATTR_DRAM] = {};

            constexpr uint8_t INDEX_A0R0 = 0;
            constexpr uint8_t INDEX_A0R1 = 1;
            constexpr uint8_t INDEX_B0R0 = 2;
            constexpr uint8_t INDEX_B0R1 = 3;

            constexpr uint8_t INDEX_A1R0 = 0;
            constexpr uint8_t INDEX_A1R1 = 1;
            constexpr uint8_t INDEX_B1R0 = 2;
            constexpr uint8_t INDEX_B1R1 = 3;

            // =========================================================
            // EFD Byte 314-321: Base Vref CS Settings Per Rank
            // Attribute: ATTR_DDR5_DRAM_VREFCS
            // MODE REG: MR12
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 158
            // =========================================================
            // Get the attr so that only the bits that changed are written
            // when we set the attr
            FAPI_TRY(mss::attr::get_ddr5_dram_vrefcs(iv_dimm, l_vrefcs));

            // For Port 0 Channel 0
            // A0 R0: Byte 0
            // B0 R0: Byte 2
            // A0 R1: Byte 1
            // B0 R1: Byte 3
            // For Port 0 Channel 1
            // A1 R0: Byte 4
            // B1 R0: Byte 5
            // A1 R1: Byte 6
            // B1 R1: Byte 7
            // Same as above is repeated for Port 1 Channel 0 and Port 1 Channel 1
            if (iv_port_rel_pos == 0) // Port 0
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::BASE_VREF_CS_BYTE0, i_efd, SET_WR_VREFCS_DQ,
                                                 l_dram_vrefcs_byte[INDEX_A0R0]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::BASE_VREF_CS_BYTE1, i_efd, SET_WR_VREFCS_DQ,
                                                 l_dram_vrefcs_byte[INDEX_A0R1]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::BASE_VREF_CS_BYTE2, i_efd, SET_WR_VREFCS_DQ,
                                                 l_dram_vrefcs_byte[INDEX_B0R0]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::BASE_VREF_CS_BYTE3, i_efd, SET_WR_VREFCS_DQ,
                                                 l_dram_vrefcs_byte[INDEX_B0R1]));
            }
            else // Port 1
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::BASE_VREF_CS_BYTE4, i_efd, SET_WR_VREFCS_DQ,
                                                 l_dram_vrefcs_byte[INDEX_A1R0]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::BASE_VREF_CS_BYTE5, i_efd, SET_WR_VREFCS_DQ,
                                                 l_dram_vrefcs_byte[INDEX_A1R1]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::BASE_VREF_CS_BYTE6, i_efd, SET_WR_VREFCS_DQ,
                                                 l_dram_vrefcs_byte[INDEX_B1R0]));
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::BASE_VREF_CS_BYTE7, i_efd, SET_WR_VREFCS_DQ,
                                                 l_dram_vrefcs_byte[INDEX_B1R1]));
            }

            // BYTE 324-403 Vref CS offset value and add sub
            FAPI_TRY(mss::spd::set_bytes_per_dram_helper_func(iv_dimm, F::VREF_CS_OFFSET_STEP_BYTE0, i_efd, SET_WR_VREFCS_DQ,
                     iv_dimm_rank,
                     iv_port_rel_pos, l_dram_vrefcs_offset_step));

            FAPI_TRY(mss::spd::set_bytes_per_dram_helper_func(iv_dimm, F::VREF_CS_OFFSET_BYTE0_ADD_SUB, i_efd, SET_WR_VREFCS_DQ,
                     iv_dimm_rank,
                     iv_port_rel_pos, l_dram_vrefcs_offset_step_add_sub));

            // BYTE 322 Vrefca offset step multiplier
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::VREF_CS_OFFSET_MULT, i_efd, SET_WR_VREFCS_DQ, l_dram_vrefcs_offset_mult));

            static const std::vector< std::pair<uint8_t, uint8_t> > VREF_MULT_MAP =
            {
                // {key byte, MULT}
                {0b001,  1},
                {0b010,  2},
                {0b011,  3},
                {0b100,  4},
                // All others reserved
            };

            FAPI_TRY(lookup_table_check(iv_ocmb, VREF_MULT_MAP, SET_WR_VREFCS_DQ,
                                        l_dram_vrefcs_offset_mult, l_vref_mult));

            // Apply offset using helper funct
            FAPI_TRY(mss::gen::ddr5::apply_vref_offset_mult(iv_port,
                     iv_dimm_rank,
                     SET_WR_VREFCS_DQ,
                     l_dram_vrefcs_byte,
                     l_dram_vrefcs_offset_step_add_sub,
                     l_vref_mult,
                     l_dram_vrefcs_offset_step,
                     l_vrefcs));

            // Set the attr
            FAPI_TRY(mss::attr::set_ddr5_dram_vrefcs(iv_dimm, l_vrefcs));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swa volt off field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swa_voltage_offset(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            // =========================================================
            // EFD Byte 478: PMIC0 SWA Additional EFD Voltage Offset
            // Attribute: ATTR_MEM_EFF_EFD_PMIC0_SWA_VOLTAGE_OFFSET
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 169-170
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC0_SWA_VOLT_OFF, i_efd, pmic::SET_PMIC0_SWA_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC0_SWA_OFF_DIRECTION, i_efd, pmic::SET_PMIC0_SWA_VOLTAGE_OFFSET,
                                             l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC0_SWA_VOLT_OFF.get_byte(i_efd),
                                  l_offset,
                                  pmic::SET_PMIC0_SWA_VOLTAGE_OFFSET,
                                  "PMIC0 SWA offset"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_efd_pmic0_swa_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swb volt off field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swb_voltage_offset(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            // =========================================================
            // EFD Byte 479: PMIC0 SWB Additional EFD Voltage Offset
            // Attribute: ATTR_MEM_EFF_EFD_PMIC0_SWB_VOLTAGE_OFFSET
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 169-170
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC0_SWB_VOLT_OFF, i_efd, pmic::SET_PMIC0_SWB_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC0_SWB_OFF_DIRECTION, i_efd, pmic::SET_PMIC0_SWB_VOLTAGE_OFFSET,
                                             l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC0_SWB_VOLT_OFF.get_byte(i_efd),
                                  l_offset,
                                  pmic::SET_PMIC0_SWB_VOLTAGE_OFFSET,
                                  "PMIC0 SWB offset"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_efd_pmic0_swb_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swc volt off field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swc_voltage_offset(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            // =========================================================
            // EFD Byte 480: PMIC0 SWC Additional EFD Voltage Offset
            // Attribute: ATTR_MEM_EFF_EFD_PMIC0_SWC_VOLTAGE_OFFSET
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 169-170
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC0_SWC_VOLT_OFF, i_efd, pmic::SET_PMIC0_SWC_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC0_SWC_OFF_DIRECTION, i_efd, pmic::SET_PMIC0_SWC_VOLTAGE_OFFSET,
                                             l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC0_SWC_VOLT_OFF.get_byte(i_efd),
                                  l_offset,
                                  pmic::SET_PMIC0_SWC_VOLTAGE_OFFSET,
                                  "PMIC0 SWC offset"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_efd_pmic0_swc_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swd volt off field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swd_voltage_offset(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            // =========================================================
            // EFD Byte 481: PMIC0 SWD Additional EFD Voltage Offset
            // Attribute: ATTR_MEM_EFF_EFD_PMIC0_SWD_VOLTAGE_OFFSET
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 169-170
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC0_SWD_VOLT_OFF, i_efd, pmic::SET_PMIC0_SWD_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC0_SWD_OFF_DIRECTION, i_efd, pmic::SET_PMIC0_SWD_VOLTAGE_OFFSET,
                                             l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC0_SWD_VOLT_OFF.get_byte(i_efd),
                                  l_offset,
                                  pmic::SET_PMIC0_SWD_VOLTAGE_OFFSET,
                                  "PMIC0 SWC offset"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_efd_pmic0_swd_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swa volt off field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swa_voltage_offset(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            // =========================================================
            // EFD Byte 482: PMIC1 SWA Additional EFD Voltage Offset
            // Attribute: ATTR_MEM_EFF_EFD_PMIC1_SWA_VOLTAGE_OFFSET
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 169-170
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC1_SWA_VOLT_OFF, i_efd, pmic::SET_PMIC1_SWA_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC1_SWA_OFF_DIRECTION, i_efd, pmic::SET_PMIC1_SWA_VOLTAGE_OFFSET,
                                             l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC1_SWA_VOLT_OFF.get_byte(i_efd),
                                  l_offset,
                                  pmic::SET_PMIC1_SWA_VOLTAGE_OFFSET,
                                  "PMIC1 SWA offset"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_efd_pmic1_swa_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swb volt off field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swb_voltage_offset(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            // =========================================================
            // EFD Byte 483: PMIC1 SWB Additional EFD Voltage Offset
            // Attribute: ATTR_MEM_EFF_EFD_PMIC1_SWB_VOLTAGE_OFFSET
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 169-170
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC1_SWB_VOLT_OFF, i_efd, pmic::SET_PMIC1_SWB_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC1_SWB_OFF_DIRECTION, i_efd, pmic::SET_PMIC1_SWB_VOLTAGE_OFFSET,
                                             l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC1_SWB_VOLT_OFF.get_byte(i_efd),
                                  l_offset,
                                  pmic::SET_PMIC1_SWB_VOLTAGE_OFFSET,
                                  "PMIC1 SWB offset"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_efd_pmic1_swb_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swc volt off field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swc_voltage_offset(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            // =========================================================
            // EFD Byte 484: PMIC1 SWC Additional EFD Voltage Offset
            // Attribute: ATTR_MEM_EFF_EFD_PMIC1_SWC_VOLTAGE_OFFSET
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 169-170
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC1_SWC_VOLT_OFF, i_efd, pmic::SET_PMIC1_SWC_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC1_SWC_OFF_DIRECTION, i_efd, pmic::SET_PMIC1_SWC_VOLTAGE_OFFSET,
                                             l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC1_SWC_VOLT_OFF.get_byte(i_efd),
                                  l_offset,
                                  pmic::SET_PMIC1_SWC_VOLTAGE_OFFSET,
                                  "PMIC1 SWC offset"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_efd_pmic1_swc_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swd volt off field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swd_voltage_offset(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            // =========================================================
            // EFD Byte 485: PMIC1 SWD Additional EFD Voltage Offset
            // Attribute: ATTR_MEM_EFF_EFD_PMIC1_SWD_VOLTAGE_OFFSET
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 169-170
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC1_SWD_VOLT_OFF, i_efd, pmic::SET_PMIC1_SWD_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC1_SWD_OFF_DIRECTION, i_efd, pmic::SET_PMIC1_SWD_VOLTAGE_OFFSET,
                                             l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC1_SWD_VOLT_OFF.get_byte(i_efd),
                                  l_offset,
                                  pmic::SET_PMIC1_SWD_VOLTAGE_OFFSET,
                                  "PMIC1 SWC offset"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_efd_pmic1_swd_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swa volt off field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swa_voltage_offset(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            // =========================================================
            // EFD Byte 486: PMIC2 SWA Additional EFD Voltage Offset
            // Attribute: ATTR_MEM_EFF_EFD_PMIC2_SWA_VOLTAGE_OFFSET
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 169-170
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC2_SWA_VOLT_OFF, i_efd, pmic::SET_PMIC2_SWA_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC2_SWA_OFF_DIRECTION, i_efd, pmic::SET_PMIC2_SWA_VOLTAGE_OFFSET,
                                             l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC2_SWA_VOLT_OFF.get_byte(i_efd),
                                  l_offset,
                                  pmic::SET_PMIC2_SWA_VOLTAGE_OFFSET,
                                  "PMIC2 SWA offset"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_efd_pmic2_swa_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swb volt off field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swb_voltage_offset(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            // =========================================================
            // EFD Byte 487: PMIC2 SWB Additional EFD Voltage Offset
            // Attribute: ATTR_MEM_EFF_EFD_PMIC2_SWB_VOLTAGE_OFFSET
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 169-170
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC2_SWB_VOLT_OFF, i_efd, pmic::SET_PMIC2_SWB_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC2_SWB_OFF_DIRECTION, i_efd, pmic::SET_PMIC2_SWB_VOLTAGE_OFFSET,
                                             l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC2_SWB_VOLT_OFF.get_byte(i_efd),
                                  l_offset,
                                  pmic::SET_PMIC2_SWB_VOLTAGE_OFFSET,
                                  "PMIC2 SWB offset"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_efd_pmic2_swb_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swc volt off field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swc_voltage_offset(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            // =========================================================
            // EFD Byte 488: PMIC2 SWC Additional EFD Voltage Offset
            // Attribute: ATTR_MEM_EFF_EFD_PMIC2_SWC_VOLTAGE_OFFSET
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 169-170
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC2_SWC_VOLT_OFF, i_efd, pmic::SET_PMIC2_SWC_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC2_SWC_OFF_DIRECTION, i_efd, pmic::SET_PMIC2_SWC_VOLTAGE_OFFSET,
                                             l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC2_SWC_VOLT_OFF.get_byte(i_efd),
                                  l_offset,
                                  pmic::SET_PMIC2_SWC_VOLTAGE_OFFSET,
                                  "PMIC2 SWC offset"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_efd_pmic2_swc_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swd volt off field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swd_voltage_offset(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            // =========================================================
            // EFD Byte 489: PMIC2 SWD Additional EFD Voltage Offset
            // Attribute: ATTR_MEM_EFF_EFD_PMIC2_SWD_VOLTAGE_OFFSET
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 169-170
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC2_SWD_VOLT_OFF, i_efd, pmic::SET_PMIC2_SWD_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC2_SWD_OFF_DIRECTION, i_efd, pmic::SET_PMIC2_SWD_VOLTAGE_OFFSET,
                                             l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC2_SWD_VOLT_OFF.get_byte(i_efd),
                                  l_offset,
                                  pmic::SET_PMIC2_SWD_VOLTAGE_OFFSET,
                                  "PMIC2 SWC offset"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_efd_pmic2_swd_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swa volt off field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swa_voltage_offset(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            // =========================================================
            // EFD Byte 490: PMIC3 SWA Additional EFD Voltage Offset
            // Attribute: ATTR_MEM_EFF_EFD_PMIC3_SWA_VOLTAGE_OFFSET
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 169-170
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC3_SWA_VOLT_OFF, i_efd, pmic::SET_PMIC3_SWA_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC3_SWA_OFF_DIRECTION, i_efd, pmic::SET_PMIC3_SWA_VOLTAGE_OFFSET,
                                             l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC3_SWA_VOLT_OFF.get_byte(i_efd),
                                  l_offset,
                                  pmic::SET_PMIC3_SWA_VOLTAGE_OFFSET,
                                  "PMIC3 SWA offset"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_efd_pmic3_swa_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swb volt off field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swb_voltage_offset(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            // =========================================================
            // EFD Byte 491: PMIC3 SWB Additional EFD Voltage Offset
            // Attribute: ATTR_MEM_EFF_EFD_PMIC3_SWB_VOLTAGE_OFFSET
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 169-170
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC3_SWB_VOLT_OFF, i_efd, pmic::SET_PMIC3_SWB_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC3_SWB_OFF_DIRECTION, i_efd, pmic::SET_PMIC3_SWB_VOLTAGE_OFFSET,
                                             l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC3_SWB_VOLT_OFF.get_byte(i_efd),
                                  l_offset,
                                  pmic::SET_PMIC3_SWB_VOLTAGE_OFFSET,
                                  "PMIC3 SWB offset"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_efd_pmic3_swb_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swc volt off field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swc_voltage_offset(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            // =========================================================
            // EFD Byte 492: PMIC3 SWC Additional EFD Voltage Offset
            // Attribute: ATTR_MEM_EFF_EFD_PMIC3_SWC_VOLTAGE_OFFSET
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 169-170
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC3_SWC_VOLT_OFF, i_efd, pmic::SET_PMIC3_SWC_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC3_SWC_OFF_DIRECTION, i_efd, pmic::SET_PMIC3_SWC_VOLTAGE_OFFSET,
                                             l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC3_SWC_VOLT_OFF.get_byte(i_efd),
                                  l_offset,
                                  pmic::SET_PMIC3_SWC_VOLTAGE_OFFSET,
                                  "PMIC3 SWC offset"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_efd_pmic3_swc_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swd volt off field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swd_voltage_offset(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            // =========================================================
            // EFD Byte 493: PMIC3 SWD Additional EFD Voltage Offset
            // Attribute: ATTR_MEM_EFF_EFD_PMIC3_SWD_VOLTAGE_OFFSET
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 169-170
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC3_SWD_VOLT_OFF, i_efd, pmic::SET_PMIC3_SWD_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC3_SWD_OFF_DIRECTION, i_efd, pmic::SET_PMIC3_SWD_VOLTAGE_OFFSET,
                                             l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC3_SWD_VOLT_OFF.get_byte(i_efd),
                                  l_offset,
                                  pmic::SET_PMIC3_SWD_VOLTAGE_OFFSET,
                                  "PMIC3 SWC offset"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_efd_pmic3_swd_voltage_offset(iv_ocmb, l_field));

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

            // =========================================================
            // EFD Byte 494: PMIC0 SWA Recommended Current Consumption
            //               Warning Threshold
            // Attribute: ATTR_MEM_EFF_PMIC0_SWA_CURRENT_WARNING
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 171-172
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC0_SWA_CURRENT_WARNING, i_efd, SET_PMIC0_SWA_CURRENT_WARNING,
                                             l_warning));

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

            // =========================================================
            // EFD Byte 495: PMIC0 SWB Recommended Current Consumption
            //               Warning Threshold
            // Attribute: ATTR_MEM_EFF_PMIC0_SWB_CURRENT_WARNING
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 171-172
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC0_SWB_CURRENT_WARNING, i_efd, SET_PMIC0_SWB_CURRENT_WARNING,
                                             l_warning));

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

            // =========================================================
            // EFD Byte 496: PMIC0 SWC Recommended Current Consumption
            //               Warning Threshold
            // Attribute: ATTR_MEM_EFF_PMIC0_SWC_CURRENT_WARNING
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 171-172
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC0_SWC_CURRENT_WARNING, i_efd, SET_PMIC0_SWC_CURRENT_WARNING,
                                             l_warning));

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

            // =========================================================
            // EFD Byte 497: PMIC0 SWD Recommended Current Consumption
            //               Warning Threshold
            // Attribute: ATTR_MEM_EFF_PMIC0_SWD_CURRENT_WARNING
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 171-172
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC0_SWD_CURRENT_WARNING, i_efd, SET_PMIC0_SWD_CURRENT_WARNING,
                                             l_warning));

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

            // =========================================================
            // EFD Byte 498: PMIC1 SWA Recommended Current Consumption
            //               Warning Threshold
            // Attribute: ATTR_MEM_EFF_PMIC1_SWA_CURRENT_WARNING
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 171-172
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC1_SWA_CURRENT_WARNING, i_efd, SET_PMIC1_SWA_CURRENT_WARNING,
                                             l_warning));

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

            // =========================================================
            // EFD Byte 499: PMIC1 SWB Recommended Current Consumption
            //               Warning Threshold
            // Attribute: ATTR_MEM_EFF_PMIC1_SWB_CURRENT_WARNING
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 171-172
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC1_SWB_CURRENT_WARNING, i_efd, SET_PMIC1_SWB_CURRENT_WARNING,
                                             l_warning));

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

            // =========================================================
            // EFD Byte 500: PMIC1 SWC Recommended Current Consumption
            //               Warning Threshold
            // Attribute: ATTR_MEM_EFF_PMIC1_SWC_CURRENT_WARNING
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 171-172
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC1_SWC_CURRENT_WARNING, i_efd, SET_PMIC1_SWC_CURRENT_WARNING,
                                             l_warning));

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

            // =========================================================
            // EFD Byte 501: PMIC1 SWD Recommended Current Consumption
            //               Warning Threshold
            // Attribute: ATTR_MEM_EFF_PMIC1_SWD_CURRENT_WARNING
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 171-172
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC1_SWD_CURRENT_WARNING, i_efd, SET_PMIC1_SWD_CURRENT_WARNING,
                                             l_warning));

            FAPI_TRY(mss::attr::set_pmic1_swd_current_warning(iv_ocmb, l_warning));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swa current warning field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swa_current_warning(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_warning = 0;

            // =========================================================
            // EFD Byte 502: PMIC2 SWA Recommended Current Consumption
            //               Warning Threshold
            // Attribute: ATTR_MEM_EFF_PMIC2_SWA_CURRENT_WARNING
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 171-172
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC2_SWA_CURRENT_WARNING, i_efd, SET_PMIC2_SWA_CURRENT_WARNING,
                                             l_warning));

            FAPI_TRY(mss::attr::set_pmic2_swa_current_warning(iv_ocmb, l_warning));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swb current warning field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swb_current_warning(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_warning = 0;

            // =========================================================
            // EFD Byte 503: PMIC2 SWB Recommended Current Consumption
            //               Warning Threshold
            // Attribute: ATTR_MEM_EFF_PMIC2_SWB_CURRENT_WARNING
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 171-172
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC2_SWB_CURRENT_WARNING, i_efd, SET_PMIC2_SWB_CURRENT_WARNING,
                                             l_warning));

            FAPI_TRY(mss::attr::set_pmic2_swb_current_warning(iv_ocmb, l_warning));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swc current warning field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swc_current_warning(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_warning = 0;

            // =========================================================
            // EFD Byte 504: PMIC2 SWC Recommended Current Consumption
            //               Warning Threshold
            // Attribute: ATTR_MEM_EFF_PMIC2_SWC_CURRENT_WARNING
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 171-172
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC2_SWC_CURRENT_WARNING, i_efd, SET_PMIC2_SWC_CURRENT_WARNING,
                                             l_warning));

            FAPI_TRY(mss::attr::set_pmic2_swc_current_warning(iv_ocmb, l_warning));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swd current warning field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swd_current_warning(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_warning = 0;

            // =========================================================
            // EFD Byte 505: PMIC2 SWD Recommended Current Consumption
            //               Warning Threshold
            // Attribute: ATTR_MEM_EFF_PMIC2_SWD_CURRENT_WARNING
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 171-172
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC2_SWD_CURRENT_WARNING, i_efd, SET_PMIC2_SWD_CURRENT_WARNING,
                                             l_warning));

            FAPI_TRY(mss::attr::set_pmic2_swd_current_warning(iv_ocmb, l_warning));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swa current warning field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swa_current_warning(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_warning = 0;

            // =========================================================
            // EFD Byte 506: PMIC3 SWA Recommended Current Consumption
            //               Warning Threshold
            // Attribute: ATTR_MEM_EFF_PMIC3_SWA_CURRENT_WARNING
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 171-172
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC3_SWA_CURRENT_WARNING, i_efd, SET_PMIC3_SWA_CURRENT_WARNING,
                                             l_warning));

            FAPI_TRY(mss::attr::set_pmic3_swa_current_warning(iv_ocmb, l_warning));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swb current warning field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swb_current_warning(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_warning = 0;

            // =========================================================
            // EFD Byte 506: PMIC3 SWB Recommended Current Consumption
            //               Warning Threshold
            // Attribute: ATTR_MEM_EFF_PMIC3_SWB_CURRENT_WARNING
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 171-172
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC3_SWB_CURRENT_WARNING, i_efd, SET_PMIC3_SWB_CURRENT_WARNING,
                                             l_warning));

            FAPI_TRY(mss::attr::set_pmic3_swb_current_warning(iv_ocmb, l_warning));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swc current warning field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swc_current_warning(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_warning = 0;

            // =========================================================
            // EFD Byte 508: PMIC3 SWC Recommended Current Consumption
            //               Warning Threshold
            // Attribute: ATTR_MEM_EFF_PMIC3_SWC_CURRENT_WARNING
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 171-172
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC3_SWC_CURRENT_WARNING, i_efd, SET_PMIC3_SWC_CURRENT_WARNING,
                                             l_warning));

            FAPI_TRY(mss::attr::set_pmic3_swc_current_warning(iv_ocmb, l_warning));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swd current warning field
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swd_current_warning(const std::vector<uint8_t>& i_efd) const
        {
            uint8_t l_warning = 0;

            // =========================================================
            // EFD Byte 509: PMIC3 SWD Recommended Current Consumption
            //               Warning Threshold
            // Attribute: ATTR_MEM_EFF_PMIC3_SWD_CURRENT_WARNING
            // MODE REG: N/A
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 171-172
            // =========================================================
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PMIC3_SWD_CURRENT_WARNING, i_efd, SET_PMIC3_SWD_CURRENT_WARNING,
                                             l_warning));

            FAPI_TRY(mss::attr::set_pmic3_swd_current_warning(iv_ocmb, l_warning));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the write leveling adjust start field
        ///
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_wl_adj_start() const
        {
            // The Synopsys PHY has 128 fine steps per clock
            constexpr uint16_t FINE_STEPS_PER_TCK_DIV_4 = 128 / 4;

            uint16_t l_field = 0;
            uint8_t l_wr_preamble = 0;

            FAPI_TRY(mss::attr::get_ddr5_dram_wr_preamble(iv_port, l_wr_preamble));

            // =========================================================
            // Algorithm based on DDR5 spec JESD79-5B_v1-2
            // Section 4.21.4 Write Leveling Internal Cycle Alignment Operation
            // =========================================================
            switch (l_wr_preamble)
            {
                case fapi2::ENUM_ATTR_DDR5_DRAM_WR_PREAMBLE_TCK2:
                    // For tWPRE = 2tCK, WL_ADJ_START = -0.75 tCK
                    // and the message block field is the absolute value
                    l_field = 3 * FINE_STEPS_PER_TCK_DIV_4;
                    break;

                case fapi2::ENUM_ATTR_DDR5_DRAM_WR_PREAMBLE_TCK3:
                    // For tWPRE = 3tCK, WL_ADJ_START = -1.25 tCK
                    // and the message block field is the absolute value
                    l_field = 5 * FINE_STEPS_PER_TCK_DIV_4;
                    break;

                case fapi2::ENUM_ATTR_DDR5_DRAM_WR_PREAMBLE_TCK4:
                    // For tWPRE = 4tCK, WL_ADJ_START = -2.25 tCK
                    // and the message block field is the absolute value
                    l_field = 9 * FINE_STEPS_PER_TCK_DIV_4;
                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::MSS_INVALID_DDR5_DRAM_WR_PREAMBLE().
                                set_PORT_TARGET(iv_port).
                                set_VALUE(l_wr_preamble),
                                "%s Invalid value for ATTR_DDR5_DRAM_WR_PREAMBLE: %d (must be 1, 2, or 3)",
                                spd::c_str(iv_port), l_wr_preamble);
            }

            FAPI_TRY(mss::attr::set_ddr5_wl_adj_start(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the write leveling adjust end field
        ///
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_wl_adj_end() const
        {
            // The Synopsys PHY has 128 fine steps per clock
            constexpr uint16_t FINE_STEPS_PER_TCK_DIV_4 = 128 / 4;

            uint16_t l_field = 0;
            uint8_t l_wr_preamble = 0;

            FAPI_TRY(mss::attr::get_ddr5_dram_wr_preamble(iv_port, l_wr_preamble));

            // =========================================================
            // Algorithm based on DDR5 spec JESD79-5B_v1-2
            // Section 4.21.4 Write Leveling Internal Cycle Alignment Operation
            // =========================================================
            switch (l_wr_preamble)
            {
                case fapi2::ENUM_ATTR_DDR5_DRAM_WR_PREAMBLE_TCK2:
                    // For tWPRE = 2tCK, WL_ADJ_START = 1.25 tCK
                    l_field = 5 * FINE_STEPS_PER_TCK_DIV_4;
                    break;

                case fapi2::ENUM_ATTR_DDR5_DRAM_WR_PREAMBLE_TCK3:
                    // For tWPRE = 3tCK, WL_ADJ_START = 1.75 tCK
                    l_field = 7 * FINE_STEPS_PER_TCK_DIV_4;
                    break;

                case fapi2::ENUM_ATTR_DDR5_DRAM_WR_PREAMBLE_TCK4:
                    // For tWPRE = 4tCK, WL_ADJ_START = 2.75 tCK
                    l_field = 11 * FINE_STEPS_PER_TCK_DIV_4;
                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::MSS_INVALID_DDR5_DRAM_WR_PREAMBLE().
                                set_PORT_TARGET(iv_port).
                                set_VALUE(l_wr_preamble),
                                "%s Invalid value for ATTR_DDR5_DRAM_WR_PREAMBLE: %d (must be 1, 2, or 3)",
                                spd::c_str(iv_port), l_wr_preamble);
            }

            FAPI_TRY(mss::attr::set_ddr5_wl_adj_end(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }


        /// @brief Process the fields for DDR5 DDIMM EFD
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode process(const std::vector<uint8_t>& i_efd) const
        {
            // Odyssey EFD fields
            FAPI_TRY(set_2n_mode(i_efd));
            FAPI_TRY(set_init_phy_vref_dq(i_efd));
            FAPI_TRY(set_dram_pu_drv_imp(i_efd));
            FAPI_TRY(set_dram_pd_drv_imp(i_efd));
            FAPI_TRY(set_dram_rd_preamble(i_efd));
            FAPI_TRY(set_dram_wr_preamble(i_efd));
            FAPI_TRY(set_dram_rd_postamble(i_efd));
            FAPI_TRY(set_dram_wr_postamble(i_efd));
            FAPI_TRY(set_dram_vref_dq(i_efd));
            FAPI_TRY(set_dram_dfe_gain(i_efd));
            FAPI_TRY(set_dram_dfe_tap1(i_efd));
            FAPI_TRY(set_dram_dfe_tap2(i_efd));
            FAPI_TRY(set_dram_dfe_tap3(i_efd));
            FAPI_TRY(set_dram_dfe_tap4(i_efd));
            FAPI_TRY(set_dram_dfe_gain_bias(i_efd));
            FAPI_TRY(set_dram_dfe_gain_bias_sign_bit(i_efd));
            FAPI_TRY(set_ck_odt(i_efd));
            FAPI_TRY(set_cs_odt(i_efd));
            FAPI_TRY(set_ck_odt_per_dram(i_efd));
            FAPI_TRY(set_cs_odt_per_dram(i_efd));
            FAPI_TRY(set_ca_odt(i_efd));
            FAPI_TRY(set_dqs_odt(i_efd));
            FAPI_TRY(set_ca_odt_dram(i_efd));
            FAPI_TRY(set_dqs_odt_dram(i_efd));
            FAPI_TRY(set_atx_slew_rate_rise_ac_a0(i_efd));
            FAPI_TRY(set_atx_slew_rate_fall_ac_a0(i_efd));
            FAPI_TRY(set_tx_slew_rate_rise_ck_a0(i_efd));
            FAPI_TRY(set_dram_rtt_nom_wr(i_efd));
            FAPI_TRY(set_dram_rtt_nom_rd(i_efd));
            FAPI_TRY(set_nt_odt_rd_wr(i_efd));
            FAPI_TRY(set_odtlon_wr(i_efd));
            FAPI_TRY(set_odtloff_wr(i_efd));
            FAPI_TRY(set_odtlon_wr_nt(i_efd));
            FAPI_TRY(set_odtloff_wr_nt(i_efd));
            FAPI_TRY(set_odtlon_rd_nt(i_efd));
            FAPI_TRY(set_odtloff_rd_nt(i_efd));
            FAPI_TRY(set_dram_vrefca_sweep_max(i_efd));
            FAPI_TRY(set_dram_vrefca_sweep_min(i_efd));
            FAPI_TRY(set_dram_vrefcs_sweep_max(i_efd));
            FAPI_TRY(set_dram_vrefcs_sweep_min(i_efd));
            FAPI_TRY(set_dram_vrefca(i_efd));
            FAPI_TRY(set_dram_vrefcs(i_efd));

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
                FAPI_TRY(set_pmic2_swa_voltage_offset(i_efd));
                FAPI_TRY(set_pmic2_swb_voltage_offset(i_efd));
                FAPI_TRY(set_pmic2_swc_voltage_offset(i_efd));
                FAPI_TRY(set_pmic2_swd_voltage_offset(i_efd));
                FAPI_TRY(set_pmic3_swa_voltage_offset(i_efd));
                FAPI_TRY(set_pmic3_swb_voltage_offset(i_efd));
                FAPI_TRY(set_pmic3_swc_voltage_offset(i_efd));
                FAPI_TRY(set_pmic3_swd_voltage_offset(i_efd));

                FAPI_TRY(set_pmic0_swa_current_warning(i_efd));
                FAPI_TRY(set_pmic0_swb_current_warning(i_efd));
                FAPI_TRY(set_pmic0_swc_current_warning(i_efd));
                FAPI_TRY(set_pmic0_swd_current_warning(i_efd));
                FAPI_TRY(set_pmic1_swa_current_warning(i_efd));
                FAPI_TRY(set_pmic1_swb_current_warning(i_efd));
                FAPI_TRY(set_pmic1_swc_current_warning(i_efd));
                FAPI_TRY(set_pmic1_swd_current_warning(i_efd));
                FAPI_TRY(set_pmic2_swa_current_warning(i_efd));
                FAPI_TRY(set_pmic2_swb_current_warning(i_efd));
                FAPI_TRY(set_pmic2_swc_current_warning(i_efd));
                FAPI_TRY(set_pmic2_swd_current_warning(i_efd));
                FAPI_TRY(set_pmic3_swa_current_warning(i_efd));
                FAPI_TRY(set_pmic3_swb_current_warning(i_efd));
                FAPI_TRY(set_pmic3_swc_current_warning(i_efd));
                FAPI_TRY(set_pmic3_swd_current_warning(i_efd));
            }

            // SI attrs
            FAPI_TRY(set_phy_odt_imp(i_efd));
            FAPI_TRY(set_si_phy_drv_imp_pull_up(i_efd));
            FAPI_TRY(set_si_phy_drv_imp_tx_cntl1(i_efd));
            FAPI_TRY(set_si_phy_drv_imp_tx_cntl2(i_efd));
            FAPI_TRY(set_si_mc_drv_imp_cmd_addr(i_efd));
            FAPI_TRY(set_dram_rtt_park(i_efd));
            FAPI_TRY(set_dram_rtt_wr(i_efd));

            // Derived from other values (need to be run last!)
            FAPI_TRY(set_wl_adj_start());
            FAPI_TRY(set_wl_adj_end());

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Process any overrides from the base SPD (planar support)
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode process_overrides(const std::vector<uint8_t>& i_spd) const
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }
};

}// ddr5

}// efd

}// mss

#endif
