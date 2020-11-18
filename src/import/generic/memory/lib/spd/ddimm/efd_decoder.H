/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/ddimm/efd_decoder.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file efd_decoder.H
/// @brief DDIMM Extended Functional Data (EFD) decoder
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _EFD_DECODER_H_
#define _EFD_DECODER_H_

#include <fapi2.H>
#include <vector>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/spd/ddimm/ddr4/efd_traits_ddr4.H>
#include <generic/memory/lib/spd/spd_reader.H>

namespace mss
{

namespace efd
{
///
/// @brief EFD reader
/// @tparam F the SPD field to read
/// @tparam R the SPD revision
/// @tparam IT data input type
/// @tparam OT data output type
/// @tparam TT traits associated with reader, defaulted to readerTraits<F, T>
/// @param[in] i_target the dimm target
/// @param[in] i_spd_data the SPD data
/// @param[out] o_value raw value for this SPD field
/// @return FAPI2_RC_SUCCESS iff okay
///
template< const field_t<endian::LITTLE>& F,
          mss::spd::rev R,
          typename IT,
          typename OT,
          typename TT = readerTraits<F, R> >
inline fapi2::ReturnCode reader( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                 const std::vector<IT>& i_spd_data,
                                 OT& o_value)
{
    FAPI_TRY( (mss::get_field<endian::LITTLE, F, TT>(i_target, i_spd_data, mss::READ_SPD_FIELD, o_value)),
              "Failed efd::read_field() for %s", spd::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @class base_decoder
/// @brief Abstract class for the base EFD decoder, regardless of size
/// @note Includes all generic EFD values
///
class base_decoder
{
    protected:

        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> iv_target;
        std::vector<uint8_t> iv_data;
        size_t iv_rank;

    public:

        ///
        /// @brief default ctor
        ///
        base_decoder() = default;

        ///
        /// @brief ctor
        /// @param[in] i_target DIMM target on which to operate
        /// @param[in] i_target EFD data
        /// @param[in] i_rank the current rank
        ///
        base_decoder(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                     const std::vector<uint8_t>& i_data,
                     const size_t i_rank):
            iv_target(i_target),
            iv_data(i_data),
            iv_rank(i_rank)
        {
        }

        ///
        /// @brief default dtor
        ///
        virtual ~base_decoder() = default;

        ///
        /// @brief Gets decoder target
        /// @return fapi2::Target<fapi2::TARGET_TYPE_DIMM>
        ///
        virtual fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> get_target() const
        {
            return iv_target;
        }

        ///
        /// @brief Gets rank tied to this decoder
        /// @return size_t
        ///
        virtual size_t get_rank() const
        {
            return iv_rank;
        }

        ///
        /// @brief Gets decoder SPD data
        /// @return std::vector<uint8_t>
        ///
        virtual std::vector<uint8_t> get_data() const
        {
            return iv_data;
        }

        ///
        /// @brief Sets decoder SPD data
        /// @param[in] i_spd_data SPD data in a vector reference
        ///
        virtual void set_data(const std::vector<uint8_t>& i_spd_data)
        {
            iv_data = i_spd_data;
        }

        ///
        /// @brief Decodes Host Speed Supported -> HOST_SPEED_SUPPORTED
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode host_speed_supported(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PHY ODT impedance -> PHY_ODT_IMPEDANCE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode phy_odt_impedance(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PHY Drive impedance pull up -> PHY_DRIVE_IMPEDANCE_PULL_UP
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode phy_drive_impedance_pull_up(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PHY Drive impedance pull down -> PHY_DRIVE_IMPEDANCE_PULL_DOWN
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode phy_drive_impedance_pull_down(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PHY Drive Impedance -> PHY_DRIVE_IMPEDANCE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode phy_drive_impedance(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Master Ranks Supported -> MASTER_RANKS_SUPPORTED
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode master_ranks_supported(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PHY Slew Rate DQ_DQS -> PHY_SLEW_RATE_DQ_DQS
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode phy_slew_rate_dq_dqs(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes ATX impedance -> ATX_IMPEDANCE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode atx_impedance(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes ATX Slew rate -> ATX_SLEW_RATE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode atx_slew_rate(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes CK Impedance -> CK_IMPEDANCE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode ck_impedance(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes CK Slew rate -> CK_SLEW_RATE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode ck_slew_rate(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Alert ODT Impedance -> ALERT_ODT_IMPEDANCE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode alert_odt_impedance(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM RTT Nom -> DRAM_RTT_NOM
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_nom(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM RTT Nom rank0 -> DRAM_RTT_NOM_RANK0
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_nom_rank0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM RTT Nom rank1 -> DRAM_RTT_NOM_RANK1
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_nom_rank1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM RTT Nom rank2 -> DRAM_RTT_NOM_RANK2
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_nom_rank2(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM RTT Nom rank3 -> DRAM_RTT_NOM_RANK3
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_nom_rank3(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM RTT WR -> DRAM_RTT_WR
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_wr(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM RTT WR rank0 -> DRAM_RTT_WR_RANK0
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_wr_rank0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM RTT WR rank1 -> DRAM_RTT_WR_RANK1
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_wr_rank1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM RTT WR rank2 -> DRAM_RTT_WR_RANK2
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_wr_rank2(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM RTT WR rank3 -> DRAM_RTT_WR_RANK3
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_wr_rank3(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM RTT Park -> DRAM_RTT_PARK
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_park(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM RTT Park rank0 -> DRAM_RTT_PARK_RANK0
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_park_rank0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM RTT Park rank1 -> DRAM_RTT_PARK_RANK1
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_park_rank1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM RTT Park rank2 -> DRAM_RTT_PARK_RANK2
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_park_rank2(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM RTT Park rank3 -> DRAM_RTT_PARK_RANK3
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_park_rank3(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM DIC -> DRAM_DIC
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_dic(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM Preamble -> WRITE_PREAMBLE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode write_preamble(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM Preamble -> READ_PREAMBLE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode read_preamble(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PHY Equalization -> PHY_EQUALIZATION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode phy_equalization(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Initial VREF DQ setting -> WR_VREF_DQ_RANGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode wr_vref_dq_range(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Initial VREF DQ setting -> WR_VREF_DQ_VALUE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode wr_vref_dq_value(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Initial PHY VREF -> INIT_PHY_VREF
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode init_phy_vref(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes RCD driver impedance control -> EXP_RCD_DIC
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode rcd_dic(uint16_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes RCD voltage control -> EXP_RCD_VOLTAGE_CTRL
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode rcd_voltage_ctrl(uint16_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes RCD Input Bus Termination -> DIMM_DDR4_F0RC7X
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_ddr4_f0rc7x(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes RCD data buffer driver impedance control -> DIMM_DDR4_F1RC00
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_ddr4_f1rc00(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief F1RC1X - QxCSn_n Output Delay Control Word
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_ddr4_f1rc1x(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief F1RC2X - QxCN Output Delay Control Word
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_ddr4_f1rc2x(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief F1RC3X - QxCKEn Output Delay Control Word
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_ddr4_f1rc3x(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief F1RC4X - QxODTn Output Delay Control Word
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_ddr4_f1rc4x(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief  F1RC5X - QxCA Output Delay Control Word
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_ddr4_f1rc5x(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief F1RC6X – Y1/Y3 Output Delay Control Word
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_ddr4_f1rc6x(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief F1RC7X – Y0/Y2 Output Delay Control Word
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_ddr4_f1rc7x(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes RCD slew rate control -> RCD_SLEW_RATE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode rcd_slew_rate(uint16_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes ODT WR Map CS Byte0 -> ODT_WR_MAP_RANK3
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode odt_wr_map_rank3(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes ODT WR Map CS Byte0 -> ODT_WR_MAP_RANK2
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode odt_wr_map_rank2(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes ODT WR Map CS Byte0 -> ODT_WR_MAP_RANK1
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode odt_wr_map_rank1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes ODT WR Map CS Byte0 -> ODT_WR_MAP_RANK0
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode odt_wr_map_rank0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes ODT RD Map CS Byte0 -> ODT_RD_MAP_RANK3
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode odt_rd_map_rank3(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes ODT RD Map CS Byte0 -> ODT_RD_MAP_RANK2
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode odt_rd_map_rank2(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes ODT RD Map CS Byte0 -> ODT_RD_MAP_RANK1
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode odt_rd_map_rank1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes ODT RD Map CS Byte0 -> ODT_RD_MAP_RANK0
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode odt_rd_map_rank0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Geardown during training -> GEARDOWN_DURING_TRAINING
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode geardown_during_training(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes BIST CAL Mode -> BIST_CA_LATENCY_MODE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode bist_ca_latency_mode(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes BIST CA Parity Latency Mode -> BIST_CA_PL_MODE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode bist_ca_pl_mode(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DFI Max RD Latency -> DFIMRL_DDRCLK
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dfimrl_ddrclk(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes CAC Delay A side Group 0 -> CAC_DLY_A_0
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode cac_delay_a_side_group_0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes CAC Delay A side Group 1 -> CAC_DLY_A_1
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode cac_delay_a_side_group_1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes CAC Delay A side Group 2 -> CAC_DLY_A_2
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode cac_delay_a_side_group_2(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes CAC Delay A side Group 3 -> CAC_DLY_A_3
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode cac_delay_a_side_group_3(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes CAC Delay A side Group 4 -> CAC_DLY_A_4
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode cac_delay_a_side_group_4(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes CAC Delay A side Group 5 -> CAC_DLY_A_5
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode cac_delay_a_side_group_5(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes CAC Delay A side Group 6 -> CAC_DLY_A_6
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode cac_delay_a_side_group_6(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes CAC Delay A side Group 7 -> CAC_DLY_A_7
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode cac_delay_a_side_group_7(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes CAC Delay B side Group 0 -> CAC_DLY_B_0
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode cac_delay_b_side_group_0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes CAC Delay B side Group 1 -> CAC_DLY_B_1
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode cac_delay_b_side_group_1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes CAC Delay B side Group 2 -> CAC_DLY_B_2
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode cac_delay_b_side_group_2(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes CAC Delay B side Group 3 -> CAC_DLY_B_3
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode cac_delay_b_side_group_3(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes CAC Delay B side Group 4 -> CAC_DLY_B_4
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode cac_delay_b_side_group_4(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes CAC Delay B side Group 5 -> CAC_DLY_B_5
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode cac_delay_b_side_group_5(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes CAC Delay B side Group 6 -> CAC_DLY_B_6
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode cac_delay_b_side_group_6(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes CAC Delay B side Group 7 -> CAC_DLY_B_7
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode cac_delay_b_side_group_7(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWA Volt -> PMIC0_SWA_OFFSET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic0_swa_offset(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWA Volt -> PMIC0_SWA_OFFSET_DIRECTION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic0_swa_offset_direction(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWB Volt -> PMIC0_SWB_OFFSET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic0_swb_offset(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWB Volt -> PMIC0_SWB_OFFSET_DIRECTION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic0_swb_offset_direction(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWC Volt -> PMIC0_SWC_OFFSET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic0_swc_offset(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWC Volt -> PMIC0_SWC_OFFSET_DIRECTION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic0_swc_offset_direction(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWD Volt -> PMIC0_SWD_OFFSET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic0_swd_offset(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWD Volt -> PMIC0_SWD_OFFSET_DIRECTION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic0_swd_offset_direction(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWA Volt -> PMIC1_SWA_OFFSET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic1_swa_offset(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWA Volt -> PMIC1_SWA_OFFSET_DIRECTION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic1_swa_offset_direction(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWB Volt -> PMIC1_SWB_OFFSET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic1_swb_offset(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWB Volt -> PMIC1_SWB_OFFSET_DIRECTION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic1_swb_offset_direction(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWC Volt -> PMIC1_SWC_OFFSET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic1_swc_offset(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWC Volt -> PMIC1_SWC_OFFSET_DIRECTION
        /// @param[out] o_output ncoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic1_swc_offset_direction(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWD Volt -> PMIC1_SWD_OFFSET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic1_swd_offset(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWD Volt -> PMIC1_SWD_OFFSET_DIRECTION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic1_swd_offset_direction(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWA Current Warning -> PMIC0_SWA_CURRENT_WARNING
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic0_swa_current_warning(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWB Current Warning -> PMIC0_SWB_CURRENT_WARNING
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic0_swb_current_warning(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWC Current Warning -> PMIC0_SWC_CURRENT_WARNING
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic0_swc_current_warning(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWD Current Warning -> PMIC0_SWD_CURRENT_WARNING
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic0_swd_current_warning(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWA Current Warning -> PMIC1_SWA_CURRENT_WARNING
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic1_swa_current_warning(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWB Current Warning -> PMIC1_SWB_CURRENT_WARNING
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic1_swb_current_warning(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWC Current Warning -> PMIC1_SWC_CURRENT_WARNING
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic1_swc_current_warning(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWD Current Warning -> PMIC1_SWD_CURRENT_WARNING
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic1_swd_current_warning(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
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
        virtual fapi2::ReturnCode channels_supported(uint32_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DIMMs supported -> DIMMS_SUPPORTED
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimms_supported(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }


};

///
/// @class decoder
/// @tparam D device type (DDR4, etc.)
/// @tparam E EFD type (ie custom EFD type 1)
/// @tparam R SPD revision (e.g. rev 1.1, 1.2, etc.)
/// @brief Base SPD DRAM decoder
///
template < mss::spd::device_type D, mss::efd::id E,  mss::spd::rev R >
class decoder;

} // ns efd
} // ns mss

#endif
