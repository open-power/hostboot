/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/ddimm/ddr4/efd_ddr4_custom_microchip_decoder.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file efd_ddr4_custom_microchip.H
/// @brief DDIMM Extended Functional Data (EFD) common fields
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _EFD_DDR4_CUSTOM_MICROCHIP_DECODER_H_
#define _EFD_DDR4_CUSTOM_MICROCHIP_DECODER_H_


#include <cstdint>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/spd/ddimm/efd_decoder.H>
#include <generic/memory/lib/utils/mss_buffer_utils.H>

namespace mss
{

namespace efd
{

///
/// @class decoder
/// @tparam R SPD revision - partial specialization
/// @brief RDIMM module SPD DRAM decoder
///
template < mss::spd::rev R >
class decoder<mss::spd::device_type::DDR4, DDR4_CUSTOM_MICROCHIP, R > : public base_decoder
{
    private:

        using fields_t = fields<mss::spd::device_type::DDR4, DDR4_CUSTOM_MICROCHIP>;

    public:

        // deleted default ctor
        decoder() = delete;

        ///
        /// @brief ctor
        /// @param[in] i_target dimm target
        /// @param[in] i_spd_data vector DIMM SPD data
        /// @param[in] i_rank the current rank
        ///
        decoder(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                const std::vector<uint8_t>& i_spd_data,
                const size_t i_rank):
            base_decoder(i_target, i_spd_data, i_rank)
        {
            // Using the emulation value here
            static_assert( R <= mss::spd::rev::DDIMM_MAX, " R > rev::DDIMM_MAX");
        }

        ///
        /// @brief default dtor
        ///
        virtual ~decoder() = default;
        ///
        /// @brief Decodes Host Speed Supported -> HOST_SPEED_SUPPORTED
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode host_speed_supported(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::HOST_SPEED_SUPPORTED, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PHY ODT impedance -> PHY_ODT_IMPEDANCE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode phy_odt_impedance(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::PHY_ODT_IMPEDANCE, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PHY Drive impedance pull up -> PHY_DRIVE_IMPEDANCE_PULL_UP
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode phy_drive_impedance_pull_up(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::PHY_DRIVE_IMPEDANCE_PULL_UP, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PHY Drive impedance pull down -> PHY_DRIVE_IMPEDANCE_PULL_DOWN
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode phy_drive_impedance_pull_down(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::PHY_DRIVE_IMPEDANCE_PULL_DOWN, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PHY Drive Impedance -> PHY_DRIVE_IMPEDANCE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode phy_drive_impedance(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::PHY_DRIVE_IMPEDANCE, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Master Ranks Supported -> MASTER_RANKS_SUPPORTED
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode master_ranks_supported(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::MASTER_RANKS_SUPPORTED, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PHY Slew Rate DQ_DQS -> PHY_SLEW_RATE_DQ_DQS
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode phy_slew_rate_dq_dqs(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::PHY_SLEW_RATE_DQ_DQS, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes ATX impedance -> ATX_IMPEDANCE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode atx_impedance(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::ATX_IMPEDANCE, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes ATX Slew rate -> ATX_SLEW_RATE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode atx_slew_rate(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::ATX_SLEW_RATE, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes CK Impedance -> CK_IMPEDANCE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode ck_impedance(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::CK_IMPEDANCE, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes CK Slew rate -> CK_SLEW_RATE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode ck_slew_rate(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::CK_SLEW_RATE, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Alert ODT Impedance -> ALERT_ODT_IMPEDANCE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode alert_odt_impedance(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::ALERT_ODT_IMPEDANCE, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM RTT Nom -> DRAM_RTT_NOM
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_nom(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::DRAM_RTT_NOM, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM RTT Nom rank0 -> DRAM_RTT_NOM_RANK0
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_nom_rank0(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::DRAM_RTT_NOM_RANK0, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM RTT Nom rank1 -> DRAM_RTT_NOM_RANK1
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_nom_rank1(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::DRAM_RTT_NOM_RANK1, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM RTT Nom rank2 -> DRAM_RTT_NOM_RANK2
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_nom_rank2(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::DRAM_RTT_NOM_RANK2, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM RTT Nom rank3 -> DRAM_RTT_NOM_RANK3
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_nom_rank3(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::DRAM_RTT_NOM_RANK3, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM RTT WR -> DRAM_RTT_WR
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_wr(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::DRAM_RTT_WR, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM RTT WR rank0 -> DRAM_RTT_WR_RANK0
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_wr_rank0(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::DRAM_RTT_WR_RANK0, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM RTT WR rank1 -> DRAM_RTT_WR_RANK1
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_wr_rank1(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::DRAM_RTT_WR_RANK1, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM RTT WR rank2 -> DRAM_RTT_WR_RANK2
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_wr_rank2(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::DRAM_RTT_WR_RANK2, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM RTT WR rank3 -> DRAM_RTT_WR_RANK3
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_wr_rank3(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::DRAM_RTT_WR_RANK3, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM RTT Park -> DRAM_RTT_PARK
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_park(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::DRAM_RTT_PARK, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM RTT Park rank0 -> DRAM_RTT_PARK_RANK0
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_park_rank0(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::DRAM_RTT_PARK_RANK0, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM RTT Park rank1 -> DRAM_RTT_PARK_RANK1
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_park_rank1(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::DRAM_RTT_PARK_RANK1, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM RTT Park rank2 -> DRAM_RTT_PARK_RANK2
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_park_rank2(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::DRAM_RTT_PARK_RANK2, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM RTT Park rank3 -> DRAM_RTT_PARK_RANK3
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_park_rank3(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::DRAM_RTT_PARK_RANK3, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM DIC -> DRAM_DIC
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_dic(uint8_t& o_output) const override
        {
            FAPI_TRY( (reader<fields_t::DRAM_DIC, R>
                       (iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM Preamble -> WRITE_PREAMBLE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode write_preamble(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::WRITE_PREAMBLE, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM Preamble -> READ_PREAMBLE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode read_preamble(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::READ_PREAMBLE, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PHY Equalization -> PHY_EQUALIZATION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode phy_equalization(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::PHY_EQUALIZATION, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Initial WR VREF DQ setting -> WR_VREF_DQ_RANGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode wr_vref_dq_range(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::WR_VREF_DQ_RANGE, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Initial WR VREF DQ setting -> WR_VREF_DQ_VALUE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode wr_vref_dq_value(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::WR_VREF_DQ_VALUE, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes ODT WR Map CS Byte0 -> ODT_WR_MAP_RANK3
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode odt_wr_map_rank3(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::ODT_WR_MAP_RANK3, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes ODT WR Map CS Byte0 -> ODT_WR_MAP_RANK2
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode odt_wr_map_rank2(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::ODT_WR_MAP_RANK2, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes ODT WR Map CS Byte0 -> ODT_WR_MAP_RANK1
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode odt_wr_map_rank1(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::ODT_WR_MAP_RANK1, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes ODT WR Map CS Byte0 -> ODT_WR_MAP_RANK0
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode odt_wr_map_rank0(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::ODT_WR_MAP_RANK0, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes ODT RD Map CS Byte0 -> ODT_RD_MAP_RANK3
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode odt_rd_map_rank3(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::ODT_RD_MAP_RANK3, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes ODT RD Map CS Byte0 -> ODT_RD_MAP_RANK2
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode odt_rd_map_rank2(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::ODT_RD_MAP_RANK2, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes ODT RD Map CS Byte0 -> ODT_RD_MAP_RANK1
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode odt_rd_map_rank1(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::ODT_RD_MAP_RANK1, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes ODT RD Map CS Byte0 -> ODT_RD_MAP_RANK0
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode odt_rd_map_rank0(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::ODT_RD_MAP_RANK0, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Geardown during training -> GEARDOWN_DURING_TRAINING
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode geardown_during_training(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::GEARDOWN_DURING_TRAINING, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWA Volt -> PMIC0_SWA_SETTING
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic0_swa_setting(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::PMIC0_SWA_SETTING, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWA Volt -> PMIC0_SWA_RANGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic0_swa_range(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::PMIC0_SWA_RANGE, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWB Volt -> PMIC0_SWB_SETTING
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic0_swb_setting(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::PMIC0_SWB_SETTING, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWB Volt -> PMIC0_SWB_RANGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic0_swb_range(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::PMIC0_SWB_RANGE, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWC Volt -> PMIC0_SWC_SETTING
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic0_swc_setting(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::PMIC0_SWC_SETTING, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWC Volt -> PMIC0_SWC_RANGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic0_swc_range(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::PMIC0_SWC_RANGE, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWD Volt -> PMIC0_SWD_SETTING
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic0_swd_setting(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::PMIC0_SWD_SETTING, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWD Volt -> PMIC0_SWD_RANGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic0_swd_range(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::PMIC0_SWD_RANGE, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWA Volt -> PMIC1_SWA_SETTING
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic1_swa_setting(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::PMIC1_SWA_SETTING, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWA Volt -> PMIC1_SWA_RANGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic1_swa_range(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::PMIC1_SWA_RANGE, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWB Volt -> PMIC1_SWB_SETTING
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic1_swb_setting(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::PMIC1_SWB_SETTING, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWB Volt -> PMIC1_SWB_RANGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic1_swb_range(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::PMIC1_SWB_RANGE, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWC Volt -> PMIC1_SWC_SETTING
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic1_swc_setting(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::PMIC1_SWC_SETTING, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWC Volt -> PMIC1_SWC_RANGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic1_swc_range(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::PMIC1_SWC_RANGE, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWD Volt -> PMIC1_SWD_SETTING
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic1_swd_setting(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::PMIC1_SWD_SETTING, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWD Volt -> PMIC1_SWD_RANGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic1_swd_range(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::PMIC1_SWD_RANGE, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Channels supported byte3
        /// @param[out] o_output encoding from SPD - multiple fields used
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Uses the following bytes and fields to build up the combined data:
        /// Byte 3: CHANNELS_SUPPORTED_BYTE0
        /// Byte 4: CHANNELS_SUPPORTED_BYTE1
        /// Byte 5: CHANNELS_SUPPORTED_BYTE2
        /// Byte 6: CHANNELS_SUPPORTED_BYTE3
        ///
        virtual fapi2::ReturnCode channels_supported(uint32_t& o_output) const override
        {
            uint8_t l_byte0 = 0;
            uint8_t l_byte1 = 0;
            uint8_t l_byte2 = 0;
            uint8_t l_byte3 = 0;

            FAPI_TRY(( reader<fields_t::CHANNELS_SUPPORTED_BYTE0, R>(iv_target, iv_data, l_byte0)) );
            FAPI_TRY(( reader<fields_t::CHANNELS_SUPPORTED_BYTE1, R>(iv_target, iv_data, l_byte1)) );
            FAPI_TRY(( reader<fields_t::CHANNELS_SUPPORTED_BYTE2, R>(iv_target, iv_data, l_byte2)) );
            FAPI_TRY(( reader<fields_t::CHANNELS_SUPPORTED_BYTE3, R>(iv_target, iv_data, l_byte3)) );

            {
                fapi2::buffer<uint32_t> l_buffer;
                right_aligned_insert(l_buffer, l_byte3, l_byte2, l_byte1, l_byte0);
                o_output = l_buffer;
                FAPI_INF("%s. Register Manufacturer ID Code: 0x%04x",
                         spd::c_str(iv_target),
                         o_output);
            }
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DIMMs supported -> DIMMS_SUPPORTED
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimms_supported(uint8_t& o_output) const override
        {
            FAPI_TRY(( reader<fields_t::DIMMS_SUPPORTED, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }
};

} // ns efd
} // ns mss
#endif
