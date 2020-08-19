/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/eff_dimm.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Aandre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_EFF_DIMM_H_
#define _MSS_EFF_DIMM_H_

#include <fapi2.H>
#include <lib/shared/mss_kind.H>
#include <lib/shared/mss_const.H>
#include <generic/memory/lib/spd/spd_facade.H>
#include <generic/memory/lib/spd/common/rcw_settings.H>
#include <lib/spd/spd_factory.H>
#include <lib/eff_config/timing.H>
#include <lib/eff_config/pre_data_init.H>
#include <generic/memory/lib/spd/spd_utils.H>

namespace mss
{

///
/// @brief Gets the JEDEC train and range values from the encoded VPD value
/// @param[in] i_target - the DIMM target on which to operate
/// @param[out] o_range - the JEDEC VREFDQ range
/// @param[out] o_value - the JEDEC VREFDQ value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode get_vpd_wr_vref_range_and_value( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_range,
        uint8_t& o_value );

///
/// @class mss::dimm::eff_dimm
/// @brief A class made to perform eff_config functions based on the different dimm kinds (gen, type, buffer type)
/// @note this is a base class
///
class eff_dimm
{
    protected:
        fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_dimm;
        fapi2::Target<fapi2::TARGET_TYPE_MCA> iv_mca;
        fapi2::Target<fapi2::TARGET_TYPE_MCS> iv_mcs;
        size_t iv_port_index;
        size_t iv_dimm_index;
        int64_t iv_ftb; // fine timebase
        int64_t iv_mtb; // medium timebase
        rcw_settings iv_raw_card;
        uint8_t iv_dram_width;
        uint8_t iv_dram_die_count;

    public:
        uint64_t iv_freq;
        int64_t iv_tCK_in_ps;
        spd::facade iv_spd_decoder;
        uint8_t iv_dram_density;

        // Assists testing with write ability on these MRW
        // settings that are normally NOT writable
        // using attribute accessors
        // Could create getters & setters...
        uint8_t iv_refresh_mode;
        uint8_t iv_refresh_rate_request;

        ///
        ///@brief Encoding for QSID for RC08,
        ///@note  placing here so we can use the enum for calculate_chip_id and for RCBX
        ///
        enum qsid
        {
            ALL_ENABLE = 0b00,
            ZERO_ENABLE = 0b10,
            ZERO_ONE_ENABLE = 0b01,
            ALL_DISABLE = 0b11,

        };

        // eff_config SPD raw values to attribute mappings
        static const std::vector<std::pair<uint8_t, uint8_t> > DEVICE_WIDTH_MAP;
        static const std::vector<std::pair<uint8_t, uint8_t> > SDRAM_DENSITY_MAP;
        static const std::vector<std::pair<uint8_t, uint8_t> > SOFT_PPR_MAP;
        static const std::vector<std::pair<uint8_t, uint8_t> > BUS_WIDTH_MAP;
        static const std::vector< std::pair<uint8_t, uint8_t> > BANK_ADDR_BITS_MAP;
        static const std::vector<std::pair<uint8_t, uint8_t> > ROW_ADDRESS_BITS_MAP;
        static const std::vector<std::pair<uint8_t, uint8_t> > PRIM_DIE_COUNT_MAP;
        static const std::vector<std::pair<uint8_t, uint8_t> > SEC_DIE_COUNT_MAP;

        //Delete the default
        eff_dimm () = delete;

        ///
        /// @brief constructor for the base eff_dimm class
        /// @param[in] i_spd_decoder the SPD decoder
        /// @param[out] o_rc fapi2::ReturnCode
        /// @note also sets class variables for parent MCA/ MCS and for freqs
        ///
        eff_dimm( const spd::facade& i_spd_decoder,
                  const rcw_settings& i_rcw,
                  fapi2::ReturnCode& o_rc ):
            iv_raw_card(i_rcw),
            iv_spd_decoder(i_spd_decoder)
        {
            // Targeting and index info
            iv_dimm = i_spd_decoder.get_target();
            FAPI_DBG("Constructing eff_dimm object for %s", mss::c_str(iv_dimm));

            iv_mca = find_target<fapi2::TARGET_TYPE_MCA>(iv_dimm);
            iv_mcs = find_target<fapi2::TARGET_TYPE_MCS>(iv_dimm);
            iv_port_index = mss::index(iv_mca);
            iv_dimm_index = mss::index(iv_dimm);

            // Set widely used parameters
            FAPI_TRY( spd::get_timebases(iv_spd_decoder, iv_mtb, iv_ftb) );
            FAPI_TRY( set_dram_width_instance() );
            FAPI_TRY( set_prim_dram_die_count_instance() );
            FAPI_TRY( set_dram_density_instance() );
            FAPI_TRY( clock_period(iv_dimm, iv_tCK_in_ps), "Failed to calculate clock period (tCK)" );
            FAPI_TRY( mss::mrw_refresh_rate_request(iv_refresh_rate_request), "Failed mrw_temp_refresh_rate_request()" );
            FAPI_TRY( mss::mrw_fine_refresh_mode(iv_refresh_mode), "Failed mrw_fine_refresh_mode()" );
            FAPI_TRY( mss::freq(find_target<fapi2::TARGET_TYPE_MCBIST>(iv_dimm), iv_freq),
                      "Failed accessing mss::freq in eff_dimm");

            FAPI_INF("Calculated clock period - tCK (ps): %d for %s", iv_tCK_in_ps, mss::c_str(iv_dimm));
            FAPI_INF("Calculated frequency (ps): %d for %s", iv_freq, mss::c_str(iv_dimm));

        fapi_try_exit:
            o_rc = fapi2::current_err;
            return;
        }

        ///
        /// @brief Grab the VPD blobs and decode into attributes
        /// @param[in] i_target FAPI2 target (MCS)
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        static fapi2::ReturnCode decode_vpd(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target);

        ///
        /// @brief factory to make an eff_config DIMM object based on dimm kind (type, gen, and revision number)
        /// @param[in] i_spd_decoder the SPD decoder
        /// @param[out] o_fact_obj a shared pointer of the eff_dimm type
        ///
        static fapi2::ReturnCode factory ( const spd::facade& i_spd_decoder,
                                           std::shared_ptr<eff_dimm>& o_fact_obj);

        ///
        /// @brief Determines & sets effective config for buffer and rev type
        /// @param[in] i_target FAPI2 target
        /// @param[in] i_spd_decoder the SPD decoder
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        static fapi2::ReturnCode register_and_buffer_type( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const spd::facade& i_spd_decoder );

        ///
        /// @brief Default destructor
        ///
        virtual ~eff_dimm() = default;

        ///
        /// @brief Determines & sets effective config for eff_dram_mfg_id type from SPD
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_mfg_id();

        ///
        /// @brief Determines & sets effective config for eff_rcd_mfg_id type from SPD
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode rcd_mfg_id();

        ///
        /// @brief Determines & sets effective config for eff_register_type from SPD
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode register_type();

        ///
        /// @brief Determines & sets effective config for eff_register_rev type from SPD
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode register_rev();

        ///
        /// @brief Determines & sets effective config for primary stack type
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode primary_stack_type();

        ///
        /// @brief Determines & sets effective config for refresh interval time (tREFI)
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_trefi();

        ///
        /// @brief Determines & sets effective config for refresh cycle time (tRFC)
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_trfc();

        ///
        /// @brief Determines & sets effective config for refresh cycle time (logical ranks) (tRFC_DLR)
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_trfc_dlr();

        ///
        /// @brief Determines & sets effective config for dram density
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_density();

        ///
        /// @brief Determines & sets effective config for dram width
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_width();
        ///
        /// @brief Determines & sets effective config for dimm rcd mirror mode
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode rcd_mirror_mode();

        ///
        /// @brief Determines & sets effective config for dimm size
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_size();

        ///
        /// @brief Determines & sets effective config for dram bank bits
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_bank_bits();

        ///
        /// @brief Determines & sets effective config for dram row bits
        ///  @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_row_bits();

        ///
        /// @brief Determines & sets effective config for the die count for the DIMM
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode prim_die_count();

        ///
        /// @brief Determines & sets effective config for number of ranks per dimm
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode ranks_per_dimm();

        ///
        /// @brief Determines & sets effective config for number of master ranks per dimm
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode master_ranks_per_dimm();

        ///
        /// @brief Determines & sets effective config for tDQS
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_dqs_time();

        ///
        /// @brief Determines & sets effective config for DRAM output driver impedance control
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_odic() = 0;

        ///
        /// @brief Determines & sets effective config for tCCD_L
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_tccd_l();

        ///
        /// @brief Determines & sets effective config for DIMM RC00
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc00();

        ///
        /// @brief Determines & sets effective config for DIMM RC01
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc01();

        ///
        /// @brief Determines & sets effective config for DIMM RC02
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc02();

        ///
        /// @brief Determines & sets effective config for DIMM RC03
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc03();

        ///
        /// @brief Determines & sets effective config for DIMM RC04
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc04();

        ///
        /// @brief Determines & sets effective config for DIMM RC05
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc05();

        ///
        /// @brief Determines & sets effective config for DIMM RC06_07
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc06_07();

        ///
        /// @brief Determines how many chip select ID bits are needed for the iv_dimm
        /// @param[out] o_qs a qsid encoding denoting if 0, 1, 2, or all three QSID's are needed
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode calculate_chip_ids( qsid& o_qs);

        ///
        /// @brief Determines how many chip select ID bits are needed for the iv_dimm on the input to the RCD
        /// @param[out] o_qs a qsid encoding denoting if 0, 1, 2, or all three QSID's are needed
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode calculate_chip_ids_inputs( qsid& o_qs);

        ///
        /// @brief Determines how many chip select ID bits are needed for the iv_dimm on the output from the RCD
        /// @param[out] o_qs a qsid encoding denoting if 0, 1, 2, or all three QSID's are needed
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode calculate_chip_ids_outputs( qsid& o_qs);

        ///
        /// @brief Determines & sets effective config for DIMM RC08
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc08();

        ///
        /// @brief Determines & sets effective config for DIMM RC09
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc09();

        ///
        /// @brief Determines & sets effective config for DIMM RC0A
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc0a();

        ///
        /// @brief Determines & sets effective config for DIMM RC0B
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc0b();

        ///
        /// @brief Determines & sets effective config for DIMM RC0C
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc0c();

        ///
        /// @brief Determines & sets effective config for DIMM RC0D
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc0d();

        ///
        /// @brief Determines & sets effective config for DIMM RC0E
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc0e();

        ///
        /// @brief Determines & sets effective config for DIMM RC0F
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc0f();

        ///
        /// @brief Determines & sets effective config for DIMM RC_1x
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc1x();

        ///
        /// @brief Determines & sets effective config for DIMM RC_2x
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc2x();

        ///
        /// @brief Determines & sets effective config for DIMM RC_3x
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc3x();

        ///
        /// @brief Determines & sets effective config for DIMM RC_4x
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc4x();

        ///
        /// @brief Determines & sets effective config for DIMM RC_5x
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc5x();

        ///
        /// @brief Determines & sets effective config for DIMM RC_6x
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc6x();

        ///
        /// @brief Determines & sets effective config for DIMM RC_7x
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc7x();

        ///
        /// @brief Determines & sets effective config for DIMM RC_8x
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc8x();

        ///
        /// @brief Determines & sets effective config for DIMM RC_9x
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc9x();


        ///
        /// @brief Determines & sets effective config for DIMM RC_AX
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rcax();


        ///
        /// @brief Determines & sets effective config for DIMM RC_BX
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rcbx();

        ///
        /// @brief Determines & sets effective config for tWR
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_twr();

        ///
        /// @brief Determines & sets effective config for RBT
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode read_burst_type();

        ///
        /// @brief Determines & sets effective config for TM
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_tm();

        ///
        /// @brief Determines & sets effective config for cwl
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_cwl();

        ///
        /// @brief Determines & sets effective config for lpasr
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_lpasr();

        ///
        /// @brief Determines & sets effective config for additive latency
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode additive_latency();

        ///
        /// @brief Determines & sets effective config for DLL Reset
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dll_reset();

        ///
        /// @brief Determines & sets effective config for DLL Enable
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dll_enable();

        ///
        /// @brief Determines & sets effective config for Write Level Enable
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode write_level_enable();

        ///
        /// @brief Determines & sets effective config for Output Buffer
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        /// @note The value and range attributes are combined as offsetting the WR VREF percentage can cause both the value and range to shift
        /// The calculations would have to be done twice if the calculations were done separately. As such, they are combined below
        ///
        fapi2::ReturnCode output_buffer();


        ///
        /// @brief Determines & sets effective config for Vref DQ Train Value and Range
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode vref_dq_train_value_and_range();

        ///
        /// @brief Determines & sets effective config for Vref DQ Train Enable
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode vref_dq_train_enable();

        ///
        /// @brief Determines & sets effective config for CA Parity Latency
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode ca_parity_latency();

        ///
        /// @brief Determines & sets effective config for CA Parity
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode ca_parity();

        ///
        /// @brief Determines & sets effective config for CRC Error Clear
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode crc_error_clear();

        ///
        /// @brief Determines & sets effective config for CA Parity Error Status
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode ca_parity_error_status();

        ///
        /// @brief Determines & sets effective config for ODT Input Buffer
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode odt_input_buffer();

        ///
        /// @brief Determines & sets effective ODT write values
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode odt_wr() = 0;

        ///
        /// @brief Determines & sets effective ODT read values
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode odt_rd() = 0;

        ///
        /// @brief Determines & sets effective PHY RLO values
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode phy_rlo() = 0;

        ///
        /// @brief Determines & sets effective PHY WLO values
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode phy_wlo() = 0;

        ///
        /// @brief Determines & sets effective config for data_mask
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode data_mask();

        ///
        /// @brief Determines & sets effective config for write_dbi
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode write_dbi();

        ///
        /// @brief Determines & sets effective config for read_dbi
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode read_dbi();

        ///
        /// @brief Determines & sets effective config for Post Package Repair
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode post_package_repair();

        ///
        /// @brief Determines & sets effective config for Soft Post Package Repair
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode soft_post_package_repair();

        ///
        /// @brief Determines & sets effective config for rd_preamble_train
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode read_preamble_train();

        ///
        /// @brief Determines & sets effective config for rd_preamble
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode read_preamble();

        ///
        /// @brief Determines & sets effective config for wr_preamble
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode write_preamble();

        ///
        /// @brief Determines & sets effective config for self_ref_abort
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode self_refresh_abort();

        ///
        /// @brief Determines & sets effective config for cs_cmd_latency
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode cs_to_cmd_addr_latency();

        ///
        /// @brief Determines & sets effective config for int_vref_mon
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode internal_vref_monitor();

        ///
        /// @brief Determines & sets effective config for powerdown_mode
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode max_powerdown_mode();

        ///
        /// @brief Determines & sets effective config for mpr_rd_format
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode mpr_read_format();

        ///
        /// @brief Determines & sets effective config for CRC write latency
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode crc_wr_latency();

        ///
        /// @brief Determines & sets effective config for temperature readout
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode temp_readout();

        ///
        /// @brief Determines & sets effective config for per DRAM addressability
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode per_dram_addressability();

        ///
        /// @brief Determines & sets effective config for geardown mode
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode geardown_mode();

        ///
        /// @brief Determines & sets effective config for geardown mode
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode mpr_page();

        ///
        /// @brief Determines & sets effective config for MPR mode
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode mpr_mode();

        ///
        /// @brief Determines & sets effective config for write CRC
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode write_crc();

        ///
        /// @brief Determines & sets effective config for ZQ Calibration
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode zqcal_interval();

        ///
        /// @brief Determines & sets effective config for MEMCAL Calibration
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode memcal_interval();

        ///
        /// @brief Determines & sets effective config for tRP
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_trp();

        ///
        /// @brief Determines & sets effective config for tRCD
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_trcd();

        ///
        /// @brief Determines & sets effective config for tRC
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_trc();

        ///
        /// @brief Determines & sets effective config for tWTR_L
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_twtr_l();

        ///
        /// @brief Determines & sets effective config for tWTR_S
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_twtr_s();

        ///
        /// @brief Determines & sets effective config for the nibble map
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode nibble_map();

        ///
        /// @brief Determines & sets effective config for the package rank map
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode package_rank_map();

        ///
        /// @brief Determines & sets effective config for the wr_crc
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode wr_crc();

        ///
        /// @brief Determines & sets effective config for tRRD_S (tRRD_S_slr)
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_trrd_s();

        ///
        /// @brief Determines & sets effective config for tRRD_L (or tRRD_L_slr)
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_trrd_l();

        ///
        /// @brief Determines & sets effective config for tRRD_DLR
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_trrd_dlr();

        ///
        /// @brief Determines & sets effective config for tFAW (or tFAW_slr)
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_tfaw();

        ///
        /// @brief Determines & sets effective config for tFAW_DLR
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_tfaw_dlr();

        ///
        /// @brief Determines & sets effective config for tRAS
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_tras();

        ///
        /// @brief Determines & sets effective config for tRTP
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_trtp();

        ///
        /// @brief Determines and sets the cal_step_enable values
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode cal_step_enable();

        ///
        /// @brief Determines and sets the is_m386a8k40cm2_ctd7y values
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode is_m386a8k40cm2_ctd7y();

        ///
        /// @brief if this dimm is M386A8K40CM2-CTD7Y
        /// @param o_value record if this dimm is M386A8K40CM2-CTD7Y
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode is_m386a8k40cm2_ctd7y_helper(mss::states& o_value)
        {
            constexpr uint8_t COMPARISON_VAL[mss::MODULE_PARTNUMBER_ATTR] = {'M', '3', '8', '6', 'A', '8', 'K', '4', '0', 'C', 'M', '2', '-', 'C', 'T', 'D', ' ', ' ', ' ', ' '};
            uint16_t l_decoder_val = 0;

            uint8_t l_module_pn[mss::MODULE_PARTNUMBER_ATTR] = {};
            FAPI_TRY( iv_spd_decoder.module_partnumber(l_module_pn));

            iv_spd_decoder.reg_manufacturer_id_code(l_decoder_val);

            // If the comparison value is not equal to our PN, then no workaround is needed
            if(memcmp(l_module_pn, COMPARISON_VAL, mss::MODULE_PARTNUMBER_ATTR) != MEMCMP_EQUAL)
            {
                o_value = mss::states::NO;
            }
            // Otherwise, check the RCD vendor
            else if(l_decoder_val == fapi2::ENUM_ATTR_EFF_RCD_MFG_ID_IDT)
            {
                o_value = mss::states::YES;
            }
            else
            {
                o_value = mss::states::NO;
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Determines and sets the rdvref_enable_bit settings
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode rdvref_enable_bit();

        ///
        /// @brief Determines and sets the ATTR_MSS_CUSTOM_TRAINING_ADV_PATTERNS settings
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        /// @note overwrite the attribute to default values if it's set to 0
        ///
        fapi2::ReturnCode training_adv_pattern();

        ///
        /// @brief Determines and sets the ATTR_MSS_CUSTOM_TRAINING_ADV_BACKUP_PATTERNS settings
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        /// @note overwrite the attribute to default values if it's set to 0
        ///
        fapi2::ReturnCode training_adv_backup_pattern();

        ///
        /// @brief Determines and sets the ATTR_MSS_CUSTOM_TRAINING_ADV_BACKUP_PATTERNS2 settings
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        /// @note overwrite the attribute to default values if it's set to 0
        ///
        fapi2::ReturnCode training_adv_backup_pattern2();

        ///
        /// @brief Determines and sets the ATTR_MSS_CUSTOM_TRAINING_ADV_WR_PATTERN settings
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        /// @note overwrite the attribute to default values if it's set to 0
        ///
        fapi2::ReturnCode training_adv_wr_pattern();

        ///
        /// @brief Determines and sets ATTR_MSS_PHY_SEQ_REFRESH_
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode phy_seq_refresh();

        ///
        /// @brief Sets the RTT_NOM value from SPD
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        /// @note used for MRS01
        ///
        virtual fapi2::ReturnCode dram_rtt_nom() = 0;

        ///
        /// @brief Sets the RTT_NOM value from SPD
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        /// @note used for MRS02
        ///
        virtual fapi2::ReturnCode dram_rtt_wr() = 0;

        ///
        /// @brief Sets the RTT_PARK value from SPD
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        /// @note used for MRS05
        ///
        virtual fapi2::ReturnCode dram_rtt_park() = 0;

        ///
        /// @brief Sets the LRDIMM training pattern
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode lrdimm_training_pattern() = 0;

        ///
        /// @brief Determines and sets DIMM BC00
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc00() = 0;

        ///
        /// @brief Determines and sets DIMM BC01
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc01() = 0;

        ///
        /// @brief Determines and sets DIMM BC02
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc02() = 0;

        ///
        /// @brief Determines and sets DIMM BC03
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc03() = 0;

        ///
        /// @brief Determines and sets DIMM BC04
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc04() = 0;

        ///
        /// @brief Determines and sets DIMM BC05
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc05() = 0;

        ///
        /// @brief Determines and sets DIMM BC06
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc06() = 0;

        ///
        /// @brief Determines and sets DIMM BC07
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc07() = 0;

        ///
        /// @brief Determines and sets DIMM BC08
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc08() = 0;


        ///
        /// @brief Determines and sets DIMM BC09
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc09() = 0;

        ///
        /// @brief Determines and sets DIMM BC0a
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc0a() = 0;

        ///
        /// @brief Determines and sets DIMM BC0b
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc0b() = 0;

        ///
        /// @brief Determines and sets DIMM BC0c
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc0c() = 0;

        ///
        /// @brief Determines and sets DIMM BC0d
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc0d() = 0;

        ///
        /// @brief Determines and sets DIMM BC0e
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc0e() = 0;

        ///
        /// @brief Determines and sets DIMM BC0f
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc0f() = 0;

        ///
        /// @brief Determines and sets DIMM F0BC1x
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_f0bc1x() = 0;

        ///
        /// @brief Determines and sets DIMM F0BC6x
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_f0bc6x() = 0;

        ///
        /// @brief Determines and sets DIMM F2BCEx
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_f2bcex() = 0;

        ///
        /// @brief Determines and sets DIMM F5BC5x
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_f5bc5x() = 0;

        ///
        /// @brief Determines and sets DIMM F5BC6x
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_f5bc6x() = 0;


        ///
        /// @brief Determines and sets DIMM F6BC4x
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_f6bc4x() = 0;

    private:

        ///
        /// @brief Returns Logical ranks in Primary SDRAM type
        /// @param[out] o_logical_ranks number of logical ranks
        /// @return fapi2::FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode prim_sdram_logical_ranks( uint8_t& o_logical_ranks ) const;

        ///
        /// @brief Helper function that returns Logical ranks in SDRAM type
        /// @param[out] o_logical_ranks number of logical ranks
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode sec_sdram_logical_ranks( uint8_t& o_logical_ranks ) const;

        ///
        /// @brief Returns Logical ranks per DIMM
        /// @param[out] o_logical_ranks number of logical ranks
        /// @return fapi2::FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode logical_ranks_per_dimm( uint8_t& o_logical_rank_per_dimm ) const;

        ///
        /// @brief Helper function to set dram width instance variable
        /// @return fapi2::FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode set_dram_width_instance();

        ///
        /// @brief Helper function to set dram density instance variable
        /// @return fapi2::FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode set_dram_density_instance();

        ///
        /// @brief Helper function to set dram density instance variable
        /// @return fapi2::FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode set_prim_dram_die_count_instance();
};

///
/// @class mss::dimm::eff_lrdimm : eff_dimm
/// @brief A class made to perform eff_config functions for DDR4 LRDIMMS
/// @note this is a subclass of eff_dimm and parent class to eff_lrdimm_db01 and eff_lrdimm_db02
///
class eff_lrdimm : public eff_dimm
{
    protected:
        uint8_t iv_master_ranks_index;

    public:
        enum
        {
            NUM_VALID_RANKS_CONFIGS = 2,
        };


        ///
        /// @brief constructor for the eff_lrdimm class
        /// @param[in] i_spd_decoder the SPD decoder
        /// @param[in] i_rcw the RCW settings for this DIMM
        /// @param[in] i_master_ranks the number of master ranks on this DIMM
        /// @param[out] o_rc fapi2::ReturnCode
        /// @note also sets class variables for parent MCA/ MCS and for freqs
        /// @note calls eff_dimm ctor
        ///
        eff_lrdimm( const spd::facade& i_spd_decoder,
                    const rcw_settings& i_rcw,
                    const uint8_t i_master_rank,
                    fapi2::ReturnCode& o_rc ):
            eff_dimm ( i_spd_decoder, i_rcw, o_rc ),
            iv_master_ranks_index(master_ranks_to_index(i_master_rank))
        {
            FAPI_DBG("Constructing LRDIMM for %s with %u master ranks", mss::c_str(iv_dimm), i_master_rank);
        }

        ///
        /// @brief Finds the master rank index
        /// @param[in] i_master_rank number of master ranks for this DIMM
        /// @return master rank index - 0 if 2R, 1 otherwise (4R)
        /// @note LRDIMM's should only support 2R and 4R
        /// We use an index to speed up our lookups for LR settings
        ///
        uint8_t master_ranks_to_index(const uint8_t i_master_rank) const
        {
            return i_master_rank == 2 ? 0 : 1;
        }

        ///
        /// @brief Sets the master rank index based upon the number of master ranks
        /// @param[in] i_master_rank the number of master ranks on this DIMM
        ///
        void set_master_rank_index(const uint8_t i_master_rank)
        {
            iv_master_ranks_index = master_ranks_to_index(i_master_rank);
        }

        ///
        /// @brief default destructor
        ///
        virtual ~eff_lrdimm() = default;


        ///
        /// @brief Determines & sets effective config for Vref DQ Train Value and Range
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode vref_dq_train_value_and_range() final;

        ///
        /// @brief Determines & sets effective ODT write values
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode odt_wr() final;

        ///
        /// @brief Determines & sets effective ODT read values
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode odt_rd() final;

        ///
        /// @brief Determines & sets effective PHY RLO values
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode phy_rlo() final;

        ///
        /// @brief Determines & sets effective PHY WLO values
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode phy_wlo() final;


        ///
        /// @brief Sets the RTT_NOM value from SPD
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        /// @note used for MRS01
        ///
        virtual fapi2::ReturnCode dram_rtt_nom() final;

        ///
        /// @brief Sets the RTT_NOM value from SPD
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        /// @note used for MRS02
        ///
        virtual fapi2::ReturnCode dram_rtt_wr() final;

        ///
        /// @brief Sets the RTT_PARK value from SPD
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        /// @note used for MRS05
        ///
        virtual fapi2::ReturnCode dram_rtt_park() final;

        ///
        /// @brief Determines & sets effective config for DRAM output driver impedance control
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_odic() final;

        ///
        /// @brief Sets the LRDIMM training pattern
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode lrdimm_training_pattern() final;

        ///
        /// @brief Determines and sets DIMM BC00
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc00() final;

        ///
        /// @brief Determines and sets DIMM BC01
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc01() final;

        ///
        /// @brief Determines and sets DIMM BC02
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc02() final;

        ///
        /// @brief Determines and sets DIMM BC03
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc03() = 0;

        ///
        /// @brief Determines and sets DIMM BC04
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc04() final;

        ///
        /// @brief Determines and sets DIMM BC05
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc05() final;

        ///
        /// @brief Determines and sets DIMM BC09
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc06() final;

        ///
        /// @brief Determines and sets DIMM BC07
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc07() final;

        ///
        /// @brief Determines and sets DIMM BC08
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc08() final;

        ///
        /// @brief Determines and sets DIMM BC09
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc09() final;

        ///
        /// @brief Determines and sets DIMM BC0a
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc0a() final;

        ///
        /// @brief Determines and sets DIMM BC0b
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc0b() = 0;

        ///
        /// @brief Determines and sets DIMM BC0c
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc0c() = 0;

        ///
        /// @brief Determines and sets DIMM BC0d
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc0d() = 0;

        ///
        /// @brief Determines and sets DIMM BC0e
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc0e() final;

        ///
        /// @brief Determines and sets DIMM BC0f
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc0f() final;

        ///
        /// @brief Determines and sets DIMM F0BC1x
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_f0bc1x() final;

        ///
        /// @brief Determines and sets DIMM F0BC6x
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_f0bc6x() final;

        ///
        /// @brief Determines and sets DIMM F2BCex
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_f2bcex() final;

        ///
        /// @brief Determines and sets DIMM F5BC5x
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_f5bc5x() final;

        ///
        /// @brief Determines and sets DIMM F5BC6x
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_f5bc6x() final;

        ///
        /// @brief Determines and sets DIMM F6BC4x
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_f6bc4x() final;
};

///
/// @class mss::dimm::eff_lrdimm_db01 : eff_lrdimm
/// @brief A class made to perform eff_config functions for DDR4 LRDIMMS with Databuffer type 01
///
class eff_lrdimm_db01 : public eff_lrdimm
{
    protected:
    public:
        //Delete default
        eff_lrdimm_db01() = delete;

        ///
        /// @brief constructor for the eff_lrdimm_db01 (LRDIMM DataBuffer 1) class
        /// @param[in] i_spd_decoder the SPD decoder
        /// @param[in] i_rcw the RCW settings for this DIMM
        /// @param[in] i_master_ranks the number of master ranks on this DIMM
        /// @param[out] o_rc fapi2::ReturnCode
        /// @note also sets class variables for parent MCA/ MCS and for freqs
        /// @note calls eff_dimm ctor
        ///
        eff_lrdimm_db01( const spd::facade& i_spd_decoder,
                         const rcw_settings& i_rcw,
                         const uint8_t i_master_rank,
                         fapi2::ReturnCode& o_rc ) :
            eff_lrdimm( i_spd_decoder, i_rcw, i_master_rank, o_rc )
        {
            FAPI_DBG("Constructing LRDIMM_DB01 for %s", mss::c_str(iv_dimm))
        }

        ///
        /// @brief default destructor
        ///
        ~eff_lrdimm_db01() = default;

        ///
        /// @brief Determines and sets DIMM BC03
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc03();

        ///
        /// @brief Determines and sets DIMM BC0b
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc0b();


        ///
        /// @brief Determines and sets DIMM BC0c
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc0c();

        ///
        /// @brief Determines and sets DIMM BC0d
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc0d();
};

///
/// @class mss::dimm::eff_lrdimm_db02 : eff_lrdimm
/// @brief A class made to perform eff_config functions for DDR4 LRDIMMS with Databuffer type 02
///
class eff_lrdimm_db02 : public eff_lrdimm
{
    protected:
    public:
        //Delete default
        eff_lrdimm_db02() = delete;

        ///
        /// @brief constructor for the eff_lrdimm_db02 (LRDIMM DataBuffer 2) class
        /// @param[in] i_spd_decoder the SPD decoder
        /// @param[in] i_rcw the RCW settings for this DIMM
        /// @param[in] i_master_ranks the number of master ranks on this DIMM
        /// @param[out] o_rc fapi2::ReturnCode
        /// @note also sets class variables for parent MCA/ MCS and for freqs
        /// @note calls eff_dimm ctor
        ///
        eff_lrdimm_db02( const spd::facade& i_spd_decoder,
                         const rcw_settings& i_rcw,
                         const uint8_t i_master_rank,
                         fapi2::ReturnCode& o_rc ) :
            eff_lrdimm( i_spd_decoder, i_rcw, i_master_rank, o_rc )
        {
            FAPI_DBG("Constructing LRDIMM_DB02 for %s", mss::c_str(iv_dimm));
        }

        ///
        /// @brief default destructor
        ///
        ~eff_lrdimm_db02() = default;

        ///
        /// @brief Determines and sets DIMM BC03
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc03();

        ///
        /// @brief Determines and sets DIMM BC0b
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc0b();

        ///
        /// @brief Determines and sets DIMM BC0c
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc0c();

        ///
        /// @brief Determines and sets DIMM BC0d
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_bc0d();
};

///
/// @class mss::dimm::eff_rdimm : eff_dimm
/// @brief A class made to perform eff_config functions for DDR4 RDIMMS
///
class eff_rdimm : public eff_dimm
{
    public:
        eff_rdimm() = delete;

        ///
        /// @brief constructor for the eff_rdimm_db01 (LRDIMM DataBuffer 1) class
        /// @param[in] i_spd_decoder the SPD decoder
        /// @param[out] o_rc fapi2::ReturnCode
        /// @note also sets class variables for parent MCA/ MCS and for freqs
        /// @note calls eff_dimm ctor
        ///
        eff_rdimm( const spd::facade& i_spd_decoder,
                   const rcw_settings& i_rcw,
                   fapi2::ReturnCode& o_rc ) :
            eff_dimm( i_spd_decoder, i_rcw, o_rc )
        {
            FAPI_DBG("Constructing RDIMM for %s", mss::c_str(iv_dimm));
        }

        ///
        /// @brief default destructor
        ///
        ~eff_rdimm() = default;

        ///
        /// @brief Determines & sets effective ODT write values
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode odt_wr() final;

        ///
        /// @brief Determines & sets effective ODT read values
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode odt_rd() final;

        ///
        /// @brief Determines & sets effective PHY RLO values
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode phy_rlo() final;

        ///
        /// @brief Determines & sets effective PHY WLO values
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode phy_wlo() final;


        ///
        /// @brief Sets the RTT_NOM value from SPD
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        /// @note used for MRS01
        ///
        fapi2::ReturnCode dram_rtt_nom() final;

        ///
        /// @brief Sets the RTT_NOM value from SPD
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        /// @note used for MRS02
        ///
        fapi2::ReturnCode dram_rtt_wr() final;

        ///
        /// @brief Sets the RTT_PARK value from SPD
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        /// @note used for MRS05
        ///
        fapi2::ReturnCode dram_rtt_park() final;

        ///
        /// @brief Determines & sets effective config for DRAM output driver impedance control
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_odic() final;

        ///
        /// @brief Sets the LRDIMM training pattern
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode lrdimm_training_pattern()
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Determines and sets DIMM BC00
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_bc00() final
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Determines and sets DIMM BC01
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_bc01() final
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Determines and sets DIMM BC02
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_bc02() final
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Determines and sets DIMM BC03
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_bc03() final
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Determines and sets DIMM BC04
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_bc04() final
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Determines and sets DIMM BC05
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_bc05() final
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Determines and sets DIMM BC06
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_bc06() final
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Determines and sets DIMM BC07
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_bc07() final
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Determines and sets DIMM BC08
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_bc08() final
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Determines and sets DIMM BC09
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_bc09() final
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Determines and sets DIMM BC0a
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_bc0a() final
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Determines and sets DIMM BC0b
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_bc0b() final
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Determines and sets DIMM BC0c
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_bc0c() final
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Determines and sets DIMM BC0d
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_bc0d() final
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Determines and sets DIMM BC0e
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_bc0e() final
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Determines and sets DIMM BC0f
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_bc0f() final
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Determines and sets DIMM F0BC1x
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_f0bc1x() final
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Determines and sets DIMM F0BC6x
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_f0bc6x() final
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Determines and sets DIMM F2BCEx
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_f2bcex() final
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Determines and sets DIMM F5BC5x
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_f5bc5x() final
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Determines and sets DIMM F5BC6x
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_f5bc6x() final
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }


        ///
        /// @brief Determines and sets DIMM F6BC4x
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dimm_f6bc4x() final
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }
};
}//mss

#endif
