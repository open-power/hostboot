/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/eff_dimm.C $ */
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
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB
#include <lib/shared/nimbus_defaults.H>
#include <math.h>

// fapi2
#include <fapi2.H>
#include <vpd_access.H>
#include <utility>

// mss lib
#include <lib/dimm/mrs_traits_nimbus.H>
#include <lib/ccs/ccs_traits_nimbus.H>
#include <lib/freq/nimbus_freq_traits.H>

#include <lib/utils/fake_vpd.H>
#include <lib/mss_vpd_decoder.H>
#include <generic/memory/lib/spd/common/rcw_settings.H>
#include <lib/eff_config/timing.H>
#include <lib/dimm/ddr4/mrs_load_ddr4_nimbus.H>
#include <lib/dimm/rank.H>
#include <lib/utils/mss_nimbus_conversions.H>
#include <lib/utils/nimbus_find.H>
#include <lib/dimm/eff_dimm.H>

#include <lib/shared/mss_kind.H>
#include <lib/phy/dp16.H>
#include <lib/mss_attribute_accessors_manual.H>
#include <generic/memory/lib/utils/freq/gen_mss_freq.H>
#include <lib/workarounds/eff_config_workarounds.H>

namespace mss
{

using fapi2::TARGET_TYPE_DIMM;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCBIST;

//
// Note SPD mappings included are settings only supported by Nimbus.
// We purposely omit certain settings that exist in the JEDEC SPD spec
// if they are not supported in HW. This simplifies error catching and
// explicitly depicts supported mappings.
//

// =========================================================
// Byte 4 maps
// Item JC-45-2220.01x
// Page 18
// DDR4 SPD Document Release 3
// Byte 4 (0x004): SDRAM Density and Banks
// =========================================================
const std::vector<std::pair<uint8_t, uint8_t> > eff_dimm::SDRAM_DENSITY_MAP =
{
    // {key byte, capacity in GBs}
    {4, fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_4G},
    {5, fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_8G},
    {6, fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_16G},
};

// =========================================================
// Byte 4 maps
// Item JC-45-2220.01x
// Page 18
// DDR4 SPD Document Release 3
// Byte 4 (0x004): SDRAM Density and Banks
// =========================================================
const std::vector< std::pair<uint8_t, uint8_t> > eff_dimm::BANK_ADDR_BITS_MAP =
{
    // {key byte, number of bank address bits}
    {0, 2},
    {1, 3}
};

// =========================================================
// Byte 5 maps
// Item JC-45-2220.01x
// Page 18
// DDR4 SPD Document Release 3
// Byte 5 (0x005): SDRAM Addressing
// =========================================================
const std::vector<std::pair<uint8_t, uint8_t> > eff_dimm::ROW_ADDRESS_BITS_MAP =
{
    //{key byte,row address bits}
    {2, fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM14},
    {3, fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM15},
    {4, fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM16},
    {5, fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM17},
    {6, fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM18}
};

// =========================================================
// Byte 6 maps
// Item JC-45-2220.01x
// Page 19
// DDR4 SPD Document Release 3
// Byte 6 (0x006): Primary SDRAM Package Type
// =========================================================
const std::vector<std::pair<uint8_t, uint8_t> > eff_dimm::PRIM_DIE_COUNT_MAP =
{
    // {key byte, number of die}
    {0, 1},
    {1, 2},
    {2, 3},
    {3, 4},
    {4, 5},
    {5, 6},
    {6, 7},
    {7, 8}
};

// =========================================================
// Byte 9 maps
// Item JC-45-2220.01x
// Page 21
// DDR4 SPD Document Release 3
// Byte 9 (0x009): Other SDRAM Optional Features
// =========================================================
const std::vector<std::pair<uint8_t, uint8_t> > eff_dimm::SOFT_PPR_MAP =
{
    // {key byte, value }
    {0, fapi2::ENUM_ATTR_EFF_DRAM_SOFT_PPR_NOT_SUPPORTED},
    {1, fapi2::ENUM_ATTR_EFF_DRAM_SOFT_PPR_SUPPORTED}
};

// =========================================================
// Byte 10 maps
// Item JC-45-2220.01x
// Page 21-22
// DDR4 SPD Document Release 3
// Byte 10 (0x00A): Secondary SDRAM Package Type
// =========================================================
const std::vector<std::pair<uint8_t, uint8_t> > eff_dimm::SEC_DIE_COUNT_MAP =
{
    // {key byte, number of die}
    {0, 1},
    {1, 2},
    {2, 3},
    {3, 4},
    {4, 5},
    {5, 6},
    {6, 7},
    {7, 8}
};

// =========================================================
// Byte 12 maps
// Item JC-45-2220.01x
// Page 23
// DDR4 SPD Document Release 3
// Byte 12 (0x00C): Module Organization
// =========================================================
const std::vector<std::pair<uint8_t, uint8_t> > eff_dimm::DEVICE_WIDTH_MAP =
{
    // {key byte, device width (bits)}
    {0, fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4},
    {1, fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8},
    {2, fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X16},
    {3, fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X32},
    // All others reserved
};

// =========================================================
// Byte 13 maps
// Item JC-45-2220.01x
// Page 27
// DDR4 SPD Document Release 3
// Byte 13 (0x00D): Module Memory Bus Width
// =========================================================
const std::vector<std::pair<uint8_t, uint8_t> > eff_dimm::BUS_WIDTH_MAP =
{
    // {key byte, bus width (in bits)
    {0, 8},
    {1, 16},
    {2, 32},
    {3, 64}
    // All others reserved
};

///
/// @brief bit encodings for RC02
/// From DDR4 Register v1.0
///
enum rc02_encode
{
    A17_POS = 7,
    A17_ENABLE = 0,
    A17_DISABLE = 1
};

///
/// @brief bit encodings for Frequencies RC08
/// @note valid frequency values for Nimbus systems
/// From DDR4 Register v1.0
/// DA[3] : DA17 Input Buffer and QxA17
/// DA[2] QxPAR disabled
/// DA [1:0] QxC[2:0] (Chip ID)
///
enum rc08_encode
{
    CID_START = 6,
    CID_LENGTH = 2,
    DA17_START = 4,
    DA17_LENGTH = 1,
    DA17_QA17_LOCATION = 4,
    DA17_QA17_ENABLE = 0b0,
    DA17_QA17_DISABLE = 0b1,
    QXPAR_LOCATION = 5,
    RC08_PARITY_ENABLE = 0,
    PARITY_DISABLE = 1,
    MAX_SLAVE_RANKS = 8,
    NUM_SLAVE_RANKS_ENCODED_IN_ONE_BIT = 2,
    NUM_SLAVE_RANKS_ENCODED_IN_TWO_BITS = 4,
    NUM_SLAVE_RANKS_ENCODED_IN_THREE_BITS = 8,
};

///
/// @brief bit encodings for Frequencies RCBX
/// @note valid frequency values for Nimbus systems
/// From DDR4 Register v1.0
///
enum rcbx_encode
{
    DC0_POS = 7,
    DC1_POS = 6,
    DC2_POS = 5,
    DC_ENABLE = 0b0,
    DC_DISABLE = 0b1,
};
///
/// @brief bit encodings for Frequencies RC0A (RC0A)
/// @note valid frequency values for Nimbus systems
/// From DDR4 Register v1.0
/// More encodings available but they won't be used due to system constrains
///
//  TODO: RTC 167542
//Do we need to implement v2.0? It would be easy with the new structure - JLH
enum rc0a_encode : uint8_t
{
    DDR4_1866 = 0b001,
    DDR4_2133 = 0b010,
    DDR4_2400 = 0b011,
    DDR4_2666 = 0b100,
};

///
/// @brief bit encodings for RC0D (RC0A here) - DIMM Configuration Control Word RC0D (RC0A here)
/// From DDR4 Register v1.0
///
enum rc0d_encode : uint8_t
{
    DUAL_DIRECT_CS_MODE = 0b00, ///< Direct DualCS mode: Register uses two DCS_n inputs
    QUAD_ENCODE_CS_MODE = 0b11, ///< Direct DualCS mode: Register uses two DCS_n inputs
    LRDIMM = 0,
    RDIMM = 1,
};

///
/// @brief bit encodings for RC0E
/// From DDR4 Register v1.0
///
enum rc0e_encode : uint8_t
{
    RC0E_PARITY_ENABLE_BIT = 7,
    RC0E_PARITY_ENABLE = 1,

    RC0E_ALERT_N_ASSERT_BIT = 5,
    RC0E_ALERT_N_ASERT_PULSE = 1,

    RC0E_ALERT_N_REENABLE_BIT = 4,
    RC0E_ALERT_N_REENABLE_TRUE = 1,
};

///
/// @brief bit encodings for RC3x - Fine Granularity RDIMM Operating Speed
/// @note Only limited encodings here, more available
/// From DDR4 Register v1.0
///
enum rc3x_encode : uint8_t
{
    MT1860_TO_MT1880 = 0x1F,
    MT2120_TO_MT2140 = 0x2C,
    MT2380_TO_MT2400 = 0x39,
    MT2660_TO_MT2680 = 0x47,
};

///
/// @brief bc03_encode enums for Host Interface DQ Driver Control Word
/// From DDR4 Databuffer 01 rev 1.0 and same for DDR4 DataBuffer 02 rev 0.95
///
enum bc03_encode : uint8_t
{
    // Bit position of the BC03 bit to enable/ disable DQ/ DQS drivers
    BC03_HOST_DQ_DISABLE_POS = 4,
    BC03_HOST_DQ_DISABLE = 1,
    BC03_HOST_DQ_ENABLE = 0,
};

///
/// @brief bc05_encode enums for DRAM Interface MDQ Driver Control Word
///
enum bc05_encode : uint8_t
{
    // Bit position of the BC05 bit to enable/ disable DQ/ DQS drivers
    BC05_DRAM_DQ_DRIVER_DISABLE_POS = 4,
    BC05_DRAM_DQ_DRIVER_DISABLE = 1,
    BC05_DRAM_DQ_DRIVER_ENABLE = 0,
};


///
/// @brief bc09_encode enums Power Saving Settings Control Word
///
//Used for hard coding currently
enum bc09_encode : uint8_t
{
    BC09_CKE_POWER_DOWN_DISABLE = 0,
    BC09_CKE_POWER_DOWN_ENABLE = 1,
    BC09_CKE_POWER_DOWN_ENABLE_POS = 4,
    BC09_CKE_POWER_ODT_OFF = 1,
    BC09_CKE_POWER_ODT_ON = 0,
    BC09_CKE_POWER_ODT_POS = 5,
};

///
/// @brief encoding for DB01 and DB02 as seen from SPD
///
enum lrdimm_databuffers
{
    LRDIMM_DB01 = 0b0000,
    LRDIMM_DB02 = 0b0001
};

///
/// @brief encoding for MSS_INVALID_FREQ so we can look up functions based on encoding
///
enum invalid_freq_function_encoding : uint8_t
{
    RC0A = 0x0a,
    RC3X = 0x30,
    BC0A = 0x0a,
    F0BC6X = 0x60,
};

/////////////////////////
// Non-member function implementations
/////////////////////////

///
/// @brief Helper function to calculate logical ranks
/// @param[in] i_signal_loading signal loading from SPD
/// @param[in] i_dram_die_count DRAM die count from SPD
/// @param[in] i_master_ranks number of master ranks from SPD
///
static uint8_t calc_logical_ranks(const uint8_t i_signal_loading,
                                  const uint8_t i_dram_die_count,
                                  const uint8_t i_master_ranks)
{
    // For single-load-stack(3DS) the logical ranks per package ends up being the same as the die count.
    // For MONOLITHIC & MULTI_LOAD_STACK
    // The die count isn't guaranteed to be 1 (e.g. SDP - 1 die package, DDP - 2 die package).
    // Value of 1 has no meaning and is used for calculation purposes as defined by the SPD spec.
    const uint8_t l_multiplier = (i_signal_loading == spd::SINGLE_LOAD_STACK) ? i_dram_die_count : 1;

    return (i_master_ranks * l_multiplier);
}

///
/// @brief Returns logical ranks in Primary SDRAM type
/// @param[out] o_logical_ranks number of logical ranks
/// @return fapi2::FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode eff_dimm::prim_sdram_logical_ranks( uint8_t& o_logical_ranks ) const
{
    uint8_t l_signal_loading = 0;
    uint8_t l_master_ranks = 0;

    // Number of master ranks taken from attribute since we need mapped value
    // and not the encoded raw value from SPD.
    FAPI_TRY( mss::eff_num_master_ranks_per_dimm(iv_dimm, l_master_ranks) );
    FAPI_TRY( iv_spd_decoder.prim_sdram_signal_loading(l_signal_loading) );

    o_logical_ranks = calc_logical_ranks(l_signal_loading, iv_dram_die_count, l_master_ranks);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function that returns logical ranks in SDRAM type
/// @param[out] o_logical_ranks number of logical ranks
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::sec_sdram_logical_ranks( uint8_t& o_logical_ranks ) const
{
    uint8_t l_signal_loading = 0;
    uint8_t l_master_ranks = 0;
    uint8_t l_spd_die_count = 0;
    uint8_t l_die_count = 0;

    // Grabbing signal loading
    FAPI_TRY( iv_spd_decoder.sec_sdram_signal_loading(l_signal_loading) );

    // Number of master ranks taken from attribute since we need mapped value
    // and not the encoded raw value from SPD.
    FAPI_TRY( mss::eff_num_master_ranks_per_dimm(iv_dimm, l_master_ranks) );

    // Getting die count
    FAPI_TRY( iv_spd_decoder.sec_sdram_die_count(l_spd_die_count) );

    FAPI_ASSERT( mss::find_value_from_key(SEC_DIE_COUNT_MAP, l_spd_die_count, l_die_count),
                 fapi2::MSS_LOOKUP_FAILED()
                 .set_KEY(l_spd_die_count)
                 .set_DATA(l_die_count)
                 .set_TARGET(iv_dimm),
                 "Could not a mapped value that matched the key (%d) for %s",
                 l_spd_die_count, mss::c_str(iv_dimm) );

    o_logical_ranks = calc_logical_ranks(l_signal_loading, l_die_count, l_master_ranks);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Returns logical ranks per DIMM
/// @param[out] o_logical_ranks number of logical ranks
/// @return fapi2::FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode eff_dimm::logical_ranks_per_dimm( uint8_t& o_logical_rank_per_dimm ) const
{
    uint8_t l_prim_logical_rank_per_dimm = 0;
    uint8_t l_rank_mix = 0;

    FAPI_TRY( iv_spd_decoder.rank_mix(l_rank_mix) );
    FAPI_TRY( prim_sdram_logical_ranks(l_prim_logical_rank_per_dimm) );

    if(l_rank_mix == fapi2::ENUM_ATTR_EFF_DRAM_RANK_MIX_SYMMETRICAL)
    {
        o_logical_rank_per_dimm = l_prim_logical_rank_per_dimm;
    }
    else
    {
        // Rank mix is ASYMMETRICAL
        uint8_t l_sec_logical_rank_per_dimm = 0;
        FAPI_TRY( sec_sdram_logical_ranks(l_sec_logical_rank_per_dimm) );

        o_logical_rank_per_dimm = l_prim_logical_rank_per_dimm + l_sec_logical_rank_per_dimm;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Gets the JEDEC train and range values from the encoded VPD value
/// @param[in] i_target - the DIMM target on which to operate
/// @param[out] o_range - the JEDEC VREFDQ range
/// @param[out] o_value - the JEDEC VREFDQ value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode get_vpd_wr_vref_range_and_value( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_range,
        uint8_t& o_value )
{
    fapi2::buffer<uint8_t> l_vpd_value;
    constexpr uint64_t VPD_TRAIN_RANGE_START = 1;
    constexpr uint64_t VPD_TRAIN_VALUE_START = 2;
    constexpr uint64_t VPD_TRAIN_VALUE_LEN   = 6;

    FAPI_TRY(mss::vpd_mt_vref_dram_wr(i_target, l_vpd_value));

    o_range = l_vpd_value.getBit<VPD_TRAIN_RANGE_START>() ?
              fapi2::ENUM_ATTR_EFF_VREF_DQ_TRAIN_RANGE_RANGE2 :
              fapi2::ENUM_ATTR_EFF_VREF_DQ_TRAIN_RANGE_RANGE1;
    l_vpd_value.extractToRight<VPD_TRAIN_VALUE_START, VPD_TRAIN_VALUE_LEN>(o_value);

    FAPI_INF("%s JEDEC range 0x%02x JEDEC value 0x%02x", mss::c_str(i_target), o_range, o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief IBT helper - maps from VPD definition of IBT to the RCD control word bit fields
/// @param[in] i_ibt the IBT from VPD (e.g., 10, 15, ...), stored as 10% of original val (10 in VPD == 100 Ohms)
/// @return the IBT bit field e.g., 00, 01 ... (right aligned)
/// @note Unrecognized IBT values will force an assertion.
///
static uint64_t ibt_helper(const uint8_t i_ibt)
{
    switch(i_ibt)
    {
        // Off
        case 0:
            return 0b11;
            break;

        // 100 Ohm
        case 10:
            return 0b00;
            break;

        // 150 Ohm
        case 15:
            return 0b01;
            break;

        // 300 Ohm
        case 30:
            return 0b10;
            break;

        default:
            FAPI_ERR("unknown IBT value %d", i_ibt);
            fapi2::Assert(false);
    };

    // Not reached, but 'return' off ...
    return 0b11;
}

///
/// @brief Helper function to set dram width instance variable
/// @return fapi2::FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode eff_dimm::set_dram_width_instance()
{
    uint8_t l_spd_device_width = 0;
    FAPI_TRY( iv_spd_decoder.device_width(l_spd_device_width),
              "Failed accessing device width from SPD %s", mss::c_str(iv_dimm) );

    FAPI_ASSERT( mss::find_value_from_key(DEVICE_WIDTH_MAP, l_spd_device_width, iv_dram_width),
                 fapi2::MSS_LOOKUP_FAILED()
                 .set_KEY(l_spd_device_width)
                 .set_DATA(iv_dram_width)
                 .set_FUNCTION(SET_DRAM_WIDTH_INSTANCE)
                 .set_TARGET(iv_dimm),
                 "Could not find a mapped value that matched the key (%d) for %s",
                 l_spd_device_width, mss::c_str(iv_dimm) );

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to set dram density instance variable
/// @return fapi2::FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode eff_dimm::set_dram_density_instance()
{
    uint8_t l_spd_dram_density = 0;
    FAPI_TRY( iv_spd_decoder.sdram_density(l_spd_dram_density), "Failed to get dram_density from SPD %s",
              mss::c_str(iv_dimm) );

    FAPI_ASSERT( mss::find_value_from_key(SDRAM_DENSITY_MAP, l_spd_dram_density, iv_dram_density),
                 fapi2::MSS_LOOKUP_FAILED()
                 .set_KEY(l_spd_dram_density)
                 .set_DATA(iv_dram_density)
                 .set_FUNCTION(SET_DRAM_DENSITY_INSTANCE)
                 .set_TARGET(iv_dimm),
                 "Could not find a mapped value that matched the key (%d) for %s",
                 l_spd_dram_density, mss::c_str(iv_dimm) );

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to set dram density instance variable
/// @return fapi2::FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode eff_dimm::set_prim_dram_die_count_instance()
{
    uint8_t l_decoder_val = 0;
    FAPI_TRY( iv_spd_decoder.prim_sdram_die_count(l_decoder_val),
              "Failed to get the die count for the dimm %s", mss::c_str(iv_dimm) );

    FAPI_ASSERT( mss::find_value_from_key(PRIM_DIE_COUNT_MAP, l_decoder_val, iv_dram_die_count),
                 fapi2::MSS_LOOKUP_FAILED()
                 .set_KEY(l_decoder_val)
                 .set_DATA(iv_dram_die_count)
                 .set_FUNCTION(PRIM_DIE_COUNT)
                 .set_TARGET(iv_dimm),
                 "Could not find a mapped value that matched the key (%d) for %s",
                 l_decoder_val, mss::c_str(iv_dimm) );

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}
///
/// @brief factory to make an eff_config DIMM object based on dimm kind (type, gen, and revision number)
/// @param[in] i_spd_decoder the spd::decoder for the dimm target
/// @param[out] o_fact_obj a shared pointer of the eff_dimm type
///
fapi2::ReturnCode eff_dimm::factory ( const spd::facade& i_spd_decoder,
                                      std::shared_ptr<eff_dimm>& o_fact_obj )
{
    uint8_t l_type = 0;
    uint8_t l_gen = 0;
    uint8_t l_buffer_type = 0;
    kind_t l_dimm_kind = DEFAULT_KIND;
    rcw_settings l_raw_card;
    uint8_t l_master_ranks = 0;

    fapi2::ReturnCode l_rc;
    const auto l_dimm = i_spd_decoder.get_target();

    // Now time to get the three attributes to tell which dimm we're working with.
    // Dram_gen and dimm_type are set in mss_freq and we'll call the SPD decoder to get the reg and buff type
    FAPI_TRY( eff_dram_gen(l_dimm, l_gen), "Failed eff_dram_gen() accessor for %s", mss::c_str(l_dimm) );
    FAPI_TRY( eff_dimm_type(l_dimm, l_type), "Failed eff_dimm_type() accessor for %s", mss::c_str(l_dimm) );
    FAPI_TRY( eff_num_master_ranks_per_dimm(l_dimm, l_master_ranks), "Failed eff_dimm_type() accessor for %s",
              mss::c_str(l_dimm) );

    FAPI_TRY( i_spd_decoder.register_and_buffer_type(l_buffer_type),
              "Failed decoding register and buffer type from SPD for %s", mss::c_str(l_dimm) );

    FAPI_TRY(raw_card_factory(l_dimm, i_spd_decoder, l_raw_card));

    l_dimm_kind = mss::dimm_kind(l_type, l_gen);

    switch (l_dimm_kind)
    {
        case KIND_LRDIMM_DDR4:
            switch (l_buffer_type)
            {
                case LRDIMM_DB01:
                    o_fact_obj = std::make_shared<eff_lrdimm_db01>( i_spd_decoder, l_raw_card, l_master_ranks, l_rc );

                    // Assert that l_rc is good and o_fact_object isn't null
                    FAPI_ASSERT( ((l_rc == fapi2::FAPI2_RC_SUCCESS) && (o_fact_obj != nullptr)),
                                 fapi2::MSS_ERROR_CREATING_EFF_CONFIG_DIMM_OBJECT().
                                 set_DIMM_TYPE(l_type).
                                 set_DRAM_GEN(l_gen).
                                 set_REG_AND_BUFF_TYPE(l_buffer_type).
                                 set_DIMM_TARGET(l_dimm),
                                 "Failure creating an eff_dimm object for an LRDIMM DB01 for target %s buff_type %d",
                                 mss::c_str(l_dimm),
                                 l_buffer_type);
                    break;

                case LRDIMM_DB02:
                    o_fact_obj = std::make_shared<eff_lrdimm_db02>( i_spd_decoder, l_raw_card, l_master_ranks, l_rc );

                    // Assert that l_rc is good and o_fact_object isn't null
                    FAPI_ASSERT( ((l_rc == fapi2::FAPI2_RC_SUCCESS) && (o_fact_obj != nullptr)),
                                 fapi2::MSS_ERROR_CREATING_EFF_CONFIG_DIMM_OBJECT().
                                 set_DIMM_TYPE(l_type).
                                 set_DRAM_GEN(l_gen).
                                 set_REG_AND_BUFF_TYPE(l_buffer_type).
                                 set_DIMM_TARGET(l_dimm),
                                 "Failure creating an eff_dimm object for an LRDIMM DB02 for target %s buff_type %d",
                                 mss::c_str(l_dimm),
                                 l_buffer_type);
                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::MSS_INVALID_LRDIMM_DB().
                                set_DATA_BUFFER_GEN(l_buffer_type).
                                set_DIMM_TARGET(l_dimm),
                                "Error when creating a LRDIMM dimm object due to invalid databuffer type (%d) for target %s",
                                l_buffer_type,
                                mss::c_str(l_dimm));
                    return fapi2::FAPI2_RC_INVALID_PARAMETER;
            }

            break;

        case KIND_RDIMM_DDR4:
            o_fact_obj = std::make_shared<eff_rdimm>( i_spd_decoder, l_raw_card, l_rc );
            // Assert that l_rc is good and o_fact_object isn't null
            FAPI_ASSERT( ((l_rc == fapi2::FAPI2_RC_SUCCESS) && (o_fact_obj != nullptr)),
                         fapi2::MSS_ERROR_CREATING_EFF_CONFIG_DIMM_OBJECT().
                         set_DIMM_TYPE(l_type).
                         set_DRAM_GEN(l_gen).
                         set_REG_AND_BUFF_TYPE(l_buffer_type).
                         set_DIMM_TARGET(l_dimm),
                         "Failure creating an eff_dimm object for an RDIMM for target %s register type %d",
                         mss::c_str(l_dimm),
                         l_buffer_type);
            break;

        default:
            FAPI_ERR("Wrong kind of DIMM plugged in (not DDR4 LRDIMM or RDIMM for target %s", mss::c_str(l_dimm));
            FAPI_ASSERT(false,
                        fapi2::MSS_UNSUPPORTED_DIMM_KIND().
                        set_DIMM_KIND(l_dimm_kind).
                        set_DIMM_TYPE(l_type).
                        set_DRAM_GEN(l_gen).
                        set_DIMM_TARGET(l_dimm),
                        "Invalid dimm target when passed into eff_config: kind %d, type %d, gen %d for target %s",
                        l_dimm_kind,
                        l_type,
                        l_gen,
                        mss::c_str(l_dimm));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for eff_rcd_mfg_id from SPD
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::rcd_mfg_id()
{
    uint16_t l_decoder_val = 0;
    uint16_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Get & update MCS attribute
    FAPI_TRY( eff_rcd_mfg_id(iv_mcs, &l_mcs_attrs[0][0]), "Failed accessing ATTR_MSS_EFF_RCD_MFG_ID" );
    FAPI_TRY( iv_spd_decoder.reg_manufacturer_id_code(l_decoder_val),
              "Failed getting rcd id code from SPD %s",
              mss::c_str(iv_dimm) );

    switch (l_decoder_val)
    {
        case fapi2::ENUM_ATTR_EFF_RCD_MFG_ID_IDT:
            FAPI_INF("%s Register Manufacturer is %s", mss::c_str(iv_dimm), "IDT");
            break;

        case fapi2::ENUM_ATTR_EFF_RCD_MFG_ID_INPHI:
            FAPI_INF("%s Register Manufacturer is %s", mss::c_str(iv_dimm), "INPHI");
            break;

        case fapi2::ENUM_ATTR_EFF_RCD_MFG_ID_MONTAGE:
            FAPI_INF("%s Register Manufacturer is %s", mss::c_str(iv_dimm), "MONTAGE");
            break;

        default:
            FAPI_INF("%s Register Manufacturer is 0x%04x", mss::c_str(iv_dimm), l_decoder_val);
            break;
    }

    l_mcs_attrs[iv_port_index][iv_dimm_index] = l_decoder_val;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_RCD_MFG_ID, iv_mcs, l_mcs_attrs), "Failed to set ATTR_EFF_RCD_MFG_ID" );

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Determines & sets effective config for eff_register_type from SPD
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::register_type()
{
    uint8_t l_decoder_val = 0;
    uint8_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Get & update MCS attribute
    FAPI_TRY( eff_register_type(iv_mcs, &l_mcs_attrs[0][0]), "Failed accessing ATTR_MSS_REGISTER_TYPE" );
    FAPI_TRY( iv_spd_decoder.register_and_buffer_type(l_decoder_val),
              "Failed getting register_type code from SPD %s",
              mss::c_str(iv_dimm) );

    FAPI_INF("%s Register type is %s", mss::c_str(iv_dimm), l_decoder_val ? "RCD01" : "RCD02");

    l_mcs_attrs[iv_port_index][iv_dimm_index] = l_decoder_val;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_REGISTER_TYPE, iv_mcs, l_mcs_attrs), "Failed to set ATTR_EFF_REGISTER_TYPE" );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for eff_register_rev type from SPD
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::register_rev()
{
    uint8_t l_decoder_val = 0;
    uint8_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Get & update MCS attribute
    FAPI_TRY( eff_register_rev(iv_mcs, &l_mcs_attrs[0][0]), "Failed accessing ATTR_MSS_REGISTER_REV" );
    FAPI_TRY( iv_spd_decoder.register_rev_num(l_decoder_val),
              "Failed getting register_rev code from SPD %s",
              mss::c_str(iv_dimm) );

    FAPI_INF("%s Register rev is 0x%02x", mss::c_str(iv_dimm), l_decoder_val);
    l_mcs_attrs[iv_port_index][iv_dimm_index] = l_decoder_val;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_REGISTER_REV, iv_mcs, l_mcs_attrs), "Failed to set ATTR_EFF_REGISTER_REV" );

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Determines & sets effective config for eff_dram_mfg_id type from SPD
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dram_mfg_id()
{
    uint16_t l_decoder_val = 0;
    uint16_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Get & update MCS attribute
    FAPI_TRY( eff_dram_mfg_id(iv_mcs, &l_mcs_attrs[0][0]), "Failed accessing ATTR_MSS_EFF_DRAM_MFG_ID" );
    FAPI_TRY( iv_spd_decoder.dram_manufacturer_id_code(l_decoder_val), "Failed getting dram id code from SPD %s",
              mss::c_str(iv_dimm) );

    fapi2::endian_swap(l_decoder_val);

    switch (l_decoder_val)
    {
        case fapi2::ENUM_ATTR_EFF_DRAM_MFG_ID_MICRON:
            FAPI_INF("%s Dram Manufacturer is %s", mss::c_str(iv_dimm), "MICRON");
            break;

        case fapi2::ENUM_ATTR_EFF_DRAM_MFG_ID_HYNIX:
            FAPI_INF("%s Dram Manufacturer is %s", mss::c_str(iv_dimm), "HYNIX");
            break;

        case fapi2::ENUM_ATTR_EFF_DRAM_MFG_ID_SAMSUNG:
            FAPI_INF("%s Dram Manufacturer is %s", mss::c_str(iv_dimm), "SAMSUNG");
            break;

        default:
            FAPI_INF("%s Dram Manufacturer is 0x%04x", mss::c_str(iv_dimm), l_decoder_val);
            break;
    }

    l_mcs_attrs[iv_port_index][iv_dimm_index] = l_decoder_val;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_MFG_ID, iv_mcs, l_mcs_attrs), "Failed to set ATTR_EFF_DRAM_MFG_ID" );

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Determines & sets effective config for dram width
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dram_width()
{
    uint8_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Get & update MCS attribute
    FAPI_TRY( eff_dram_width(iv_mcs, &l_mcs_attrs[0][0]), "Failed getting EFF_DRAM_WIDTH" );

    l_mcs_attrs[iv_port_index][iv_dimm_index] = iv_dram_width;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_WIDTH, iv_mcs, l_mcs_attrs), "Failed setting ATTR_EFF_DRAM_WIDTH" );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for dram density
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dram_density()
{
    // Get & update MCS attribute
    uint8_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dram_density(iv_mcs, &l_mcs_attrs[0][0]), "Failed to get ATTR_MSS_EFF_DRAM_DENSITY" );

    l_mcs_attrs[iv_port_index][iv_dimm_index] = iv_dram_density;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_DENSITY, iv_mcs, l_mcs_attrs), "Failed to set ATTR_EFF_DRAM_DENSITY" );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for number of ranks per dimm
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::ranks_per_dimm()
{
    uint8_t l_ranks_per_dimm = 0;
    uint8_t l_attrs_ranks_per_dimm[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Get & update MCS attribute
    FAPI_TRY( eff_num_ranks_per_dimm(iv_mcs, &l_attrs_ranks_per_dimm[0][0]), "Failed to get EFF_NUM_RANKS_PER_DIMM" );
    FAPI_TRY( logical_ranks_per_dimm(l_ranks_per_dimm),
              "Failed to get logical_ranks_per_dimm %s", mss::c_str(iv_dimm) );

    l_attrs_ranks_per_dimm[iv_port_index][iv_dimm_index] = l_ranks_per_dimm;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_NUM_RANKS_PER_DIMM, iv_mcs, l_attrs_ranks_per_dimm),
              "Failed to set ATTR_EFF_NUM_RANKS_PER_DIMM" );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for the die count for the DIMM
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::prim_die_count()
{
    uint8_t l_attr[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Get & update MCS attribute
    FAPI_TRY( eff_prim_die_count(iv_mcs, &l_attr[0][0]), "Failed to get EFF_PRIM_DIE_COUNT" );

    l_attr[iv_port_index][iv_dimm_index] = iv_dram_die_count;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_PRIM_DIE_COUNT, iv_mcs, l_attr),
              "Failed to set ATTR_EFF_PRIM_DIE_COUNT" );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for stack type
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::primary_stack_type()
{
    constexpr size_t BYTE = 6;
    uint8_t l_stack_type = 0;
    uint8_t l_package_type = 0;

    FAPI_TRY( iv_spd_decoder.prim_sdram_signal_loading(l_stack_type),
              "Failed to get dram_signal_loading from SPD %s", mss::c_str(iv_dimm) );
    FAPI_TRY( iv_spd_decoder.prim_sdram_package_type(l_package_type),
              "Failed to get prim_sdram_package_type from SPD %s", mss::c_str(iv_dimm) );

    // Check to see if monolithic DRAM/ SDP
    switch (l_package_type)
    {
        case mss::spd::MONOLITHIC:
            // JEDEC standard says if the SPD says monolithic in A[7],
            // stack type must be 00 or "SDP" which is what our enum is set to
            FAPI_ASSERT( (l_stack_type == fapi2::ENUM_ATTR_EFF_PRIM_STACK_TYPE_SDP),
                         fapi2::MSS_FAILED_DATA_INTEGRITY_CHECK().
                         set_VALUE(l_stack_type).
                         set_BYTE(BYTE).
                         set_TARGET(iv_dimm).
                         set_FFDC_CODE(PRIMARY_STACK_TYPE),
                         "Invalid SPD for calculating ATTR_EFF_PRIM_STACK_TYPE for %s",
                         mss::c_str(iv_dimm) );

            break;

        case mss::spd::NON_MONOLITHIC:
            FAPI_ASSERT( (l_stack_type == fapi2::ENUM_ATTR_EFF_PRIM_STACK_TYPE_DDP_QDP) ||
                         (l_stack_type == fapi2::ENUM_ATTR_EFF_PRIM_STACK_TYPE_3DS),
                         fapi2::MSS_FAILED_DATA_INTEGRITY_CHECK().
                         set_VALUE(l_stack_type).
                         set_BYTE(BYTE).
                         set_TARGET(iv_dimm).
                         set_FFDC_CODE(PRIMARY_STACK_TYPE),
                         "Invalid SPD for calculating ATTR_EFF_PRIM_STACK_TYPE for %s",
                         mss::c_str(iv_dimm) );
            break;

        default:
            // SPD decoder should limit this two just two types, if we get here, there was a coding error
            FAPI_ERR("Error decoding prim_sdram_package_type");
            fapi2::Assert(false);
    };

    // Get & update MCS attribute
    {
        uint8_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
        FAPI_TRY( eff_prim_stack_type(iv_mcs, &l_mcs_attrs[0][0]), "Failed to get ATTR_MSS_EFF_PRIM_STACK_TYPE" );

        l_mcs_attrs[iv_port_index][iv_dimm_index] = l_stack_type;
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_PRIM_STACK_TYPE, iv_mcs, l_mcs_attrs), "Failed to set EFF_PRIM_STACK_TYPE" );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for dimm size
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dimm_size()
{
    std::vector<uint32_t> l_dimm_sizes = { fapi2::ENUM_ATTR_EFF_DIMM_SIZE_4GB,
                                           fapi2::ENUM_ATTR_EFF_DIMM_SIZE_8GB,
                                           fapi2::ENUM_ATTR_EFF_DIMM_SIZE_16GB,
                                           fapi2::ENUM_ATTR_EFF_DIMM_SIZE_32GB,
                                           fapi2::ENUM_ATTR_EFF_DIMM_SIZE_64GB,
                                           fapi2::ENUM_ATTR_EFF_DIMM_SIZE_128GB,
                                           fapi2::ENUM_ATTR_EFF_DIMM_SIZE_256GB,
                                           fapi2::ENUM_ATTR_EFF_DIMM_SIZE_512GB,
                                         };

    // Retrieve values needed to calculate dimm size
    uint8_t l_bus_width = 0;
    uint8_t l_logical_rank_per_dimm = 0;

    {
        uint8_t l_spd_bus_width = 0;
        FAPI_TRY( iv_spd_decoder.prim_bus_width(l_spd_bus_width), "Failed to get prim bus width from SPD %s",
                  mss::c_str(iv_dimm) );

        FAPI_ASSERT( mss::find_value_from_key(BUS_WIDTH_MAP, l_spd_bus_width, l_bus_width),
                     fapi2::MSS_LOOKUP_FAILED()
                     .set_KEY(l_spd_bus_width)
                     .set_DATA(l_bus_width)
                     .set_FUNCTION(DIMM_SIZE)
                     .set_TARGET(iv_dimm),
                     "Could not find a mapped value that matched the key (%d) for %s",
                     l_spd_bus_width, mss::c_str(iv_dimm) );
    }

    FAPI_TRY( logical_ranks_per_dimm(l_logical_rank_per_dimm),
              "Failed to get logical ranks from SPD %s", mss::c_str(iv_dimm) );

    // Let's sort the dimm size vector just to be super duper safe
    std::sort( l_dimm_sizes.begin(), l_dimm_sizes.end() );
    {

        // Double checking to avoid divide by zero errors
        // If this fails, there was a problem with the check in SPD function
        FAPI_ASSERT( iv_dram_density != 0,
                     fapi2::MSS_BAD_SDRAM_DENSITY_DECODER()
                     .set_DRAM_DENSITY(iv_dram_density)
                     .set_DIMM_TARGET(iv_dimm),
                     "SPD decoder messed up and returned a 0. Should have been caught already %s",
                     mss::c_str(iv_dimm));

        // Calculate dimm size
        // Formula from SPD Spec (seriously, they don't have parenthesis in the spec)
        // Total = SDRAM Capacity / 8 * Primary Bus Width / SDRAM Width * Logical Ranks per DIMM
        const uint32_t l_dimm_size = (iv_dram_density * l_bus_width * l_logical_rank_per_dimm) / (8 * iv_dram_width);

        FAPI_ASSERT( (std::binary_search(l_dimm_sizes.begin(), l_dimm_sizes.end(), l_dimm_size) == true),
                     fapi2::MSS_INVALID_CALCULATED_DIMM_SIZE()
                     .set_CALCULATED_SIZE(l_dimm_size)
                     .set_SDRAM_WIDTH(iv_dram_width)
                     .set_BUS_WIDTH(l_bus_width)
                     .set_DRAM_DENSITY(iv_dram_density)
                     .set_LOGICAL_RANKS(l_logical_rank_per_dimm)
                     .set_DIMM_TARGET(iv_dimm),
                     "Recieved an invalid dimm size (%d) for calculated DIMM_SIZE for target %s"
                     "(iv_dram_density %d * l_bus_width %d * l_logical_rank_per_dimm %d) / (8 * iv_dram_width %d",
                     l_dimm_size,
                     mss::c_str(iv_dimm),
                     iv_dram_width,
                     l_bus_width,
                     iv_dram_density,
                     l_logical_rank_per_dimm);

        // Get & update MCS attribute
        uint32_t l_attrs_dimm_size[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
        FAPI_TRY( eff_dimm_size(iv_mcs, &l_attrs_dimm_size[0][0]), "Failed to get ATTR_MSS_EFF_DIMM_SIZE" );

        l_attrs_dimm_size[iv_port_index][iv_dimm_index] = l_dimm_size;
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_SIZE, iv_mcs, l_attrs_dimm_size), "Failed to get ATTR_MSS_EFF_DIMM_SIZE" );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for refresh interval time (tREFI)
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dram_trefi()
{
    uint64_t l_trefi_in_ps = 0;

    // Calculates appropriate tREFI based on fine refresh mode
    switch(iv_refresh_mode)
    {
        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_NORMAL:

            FAPI_TRY( calc_trefi( mss::refresh_rate::REF1X,
                                  iv_refresh_rate_request,
                                  l_trefi_in_ps),
                      "Failed to calculate tREF1 for target %s", mss::c_str(iv_dimm) );
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FIXED_2X:
        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FLY_2X:

            FAPI_TRY( calc_trefi( mss::refresh_rate::REF2X,
                                  iv_refresh_rate_request,
                                  l_trefi_in_ps),
                      "Failed to calculate tREF2 for target %s", mss::c_str(iv_dimm) );
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FIXED_4X:
        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FLY_4X:

            FAPI_TRY( calc_trefi( mss::refresh_rate::REF4X,
                                  iv_refresh_rate_request,
                                  l_trefi_in_ps),
                      "Failed to calculate tREF4  for target %s", mss::c_str(iv_dimm) );
            break;

        default:
            // Fine Refresh Mode will be a platform attribute set by the MRW,
            // which they "shouldn't" mess up as long as use "attribute" enums.
            // if openpower messes this up we can at least catch it
            FAPI_ASSERT(false,
                        fapi2::MSS_INVALID_FINE_REFRESH_MODE().
                        set_FINE_REF_MODE(iv_refresh_mode),
                        "%s Incorrect Fine Refresh Mode received: %d ",
                        mss::c_str(iv_dimm),
                        iv_refresh_mode);
            break;
    };

    {
        // Calculate refresh cycle time in nCK & set attribute
        constexpr double PERCENT_ADJUST = 0.99;
        std::vector<uint16_t> l_mcs_attrs_trefi(PORTS_PER_MCS, 0);

        uint64_t l_trefi_in_nck  = 0;

        // Retrieve MCS attribute data
        FAPI_TRY( eff_dram_trefi(iv_mcs, l_mcs_attrs_trefi.data()) );

        // Calculate nck
        FAPI_TRY(  spd::calc_nck( l_trefi_in_ps,
                                  static_cast<uint64_t>(iv_tCK_in_ps),
                                  spd::INVERSE_DDR4_CORRECTION_FACTOR,
                                  l_trefi_in_nck),
                   "Error in calculating tREFI for target %s, with value of l_trefi_in_ps: %d", mss::c_str(iv_dimm), l_trefi_in_ps);

        // Lab requested 99% of tREFI calculation to avoid any latency impact and violation of any
        // refresh specification (across all number of ranks and frequencies) observed
        // during lab power/thermal tests.

        FAPI_INF("For %s, adjusting tREFI calculation by 99%, calculated tREFI (nck): %lu, adjusted tREFI (nck): %lu,",
                 mss::c_str(iv_dimm), l_trefi_in_nck, l_trefi_in_nck * PERCENT_ADJUST);

        // The compiler does this under the covers but just to be explicit on intent:
        // Floating point arithmetic and truncation of result saved to an unsigned integer
        l_trefi_in_nck = static_cast<double>(l_trefi_in_nck * PERCENT_ADJUST);

        FAPI_INF("tCK (ps): %d, tREFI (ps): %d, tREFI (nck): %d",
                 iv_tCK_in_ps, l_trefi_in_ps, l_trefi_in_nck);

        // Update MCS attribute
        l_mcs_attrs_trefi[iv_port_index] = l_trefi_in_nck;

        // casts vector into the type FAPI_ATTR_SET is expecting by deduction
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TREFI,
                                iv_mcs,
                                UINT16_VECTOR_TO_1D_ARRAY(l_mcs_attrs_trefi, PORTS_PER_MCS)),
                  "Failed to set tREFI attribute");
    }

fapi_try_exit:
    return fapi2::current_err;

}// refresh_interval

///
/// @brief Determines & sets effective config for refresh cycle time (tRFC)
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dram_trfc()
{
    int64_t l_trfc_mtb = 0;
    int64_t l_trfc_in_ps = 0;

    // Selects appropriate tRFC based on fine refresh mode
    switch(iv_refresh_mode)
    {
        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_NORMAL:
            FAPI_TRY( iv_spd_decoder.min_trfc1(l_trfc_mtb),
                      "Failed to decode SPD for tRFC1" );
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FIXED_2X:
        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FLY_2X:
            FAPI_TRY( iv_spd_decoder.min_trfc2(l_trfc_mtb),
                      "Failed to decode SPD for tRFC2" );
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FIXED_4X:
        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FLY_4X:
            FAPI_TRY( iv_spd_decoder.min_trfc4(l_trfc_mtb),
                      "Failed to decode SPD for tRFC4" );
            break;

        default:
            // Fine Refresh Mode will be a platform attribute set by the MRW,
            // which they "shouldn't" mess up as long as use "attribute" enums.
            // if openpower messes this up we can at least catch it
            FAPI_ASSERT(false,
                        fapi2::MSS_INVALID_FINE_REFRESH_MODE().
                        set_FINE_REF_MODE(iv_refresh_mode),
                        "%s Incorrect Fine Refresh Mode received: %d ",
                        mss::c_str(iv_dimm),
                        iv_refresh_mode);
            break;

    }// switch

    // Calculate trfc (in ps)
    {
        constexpr int64_t l_trfc_ftb = 0;
        FAPI_INF( "%s medium timebase (ps): %ld, fine timebase (ps): %ld, tRFC (MTB): %ld, tRFC(FTB): %ld",
                  mss::c_str(iv_dimm), iv_mtb, iv_ftb, l_trfc_mtb, l_trfc_ftb );

        l_trfc_in_ps = spd::calc_timing_from_timebase(l_trfc_mtb, iv_mtb, l_trfc_ftb, iv_ftb);
    }

    {
        // Calculate refresh cycle time in nCK & set attribute

        uint16_t l_trfc_in_nck = 0;
        std::vector<uint16_t> l_mcs_attrs_trfc(PORTS_PER_MCS, 0);

        // Retrieve MCS attribute data
        FAPI_TRY( eff_dram_trfc(iv_mcs, l_mcs_attrs_trfc.data()),
                  "Failed to retrieve tRFC attribute" );

        // Calculate nck
        FAPI_TRY( spd::calc_nck(l_trfc_in_ps, iv_tCK_in_ps, spd::INVERSE_DDR4_CORRECTION_FACTOR, l_trfc_in_nck),
                  "Error in calculating l_tRFC for target %s, with value of l_trfc_in_ps: %d", mss::c_str(iv_dimm), l_trfc_in_ps);

        FAPI_INF("tCK (ps): %d, tRFC (ps): %d, tRFC (nck): %d",
                 iv_tCK_in_ps, l_trfc_in_ps, l_trfc_in_nck);

        // DIMM's can have separate timings in a dual-drop system.
        // In those cases, we want to take the safest (most pessimistic) values
        l_mcs_attrs_trfc[iv_port_index] = std::max(l_mcs_attrs_trfc[iv_port_index], l_trfc_in_nck);

        // casts vector into the type FAPI_ATTR_SET is expecting by deduction
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRFC,
                                iv_mcs,
                                UINT16_VECTOR_TO_1D_ARRAY(l_mcs_attrs_trfc, PORTS_PER_MCS) ),
                  "Failed to set tRFC attribute" );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for refresh cycle time (different logical ranks - tRFC_DLR)
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dram_trfc_dlr()
{

    uint64_t l_tCK_in_ps = 0;
    uint64_t l_trfc_dlr_in_ps = 0;
    uint8_t l_trfc_dlr_in_nck = 0;
    std::vector<uint8_t> l_mcs_attrs_trfc_dlr(PORTS_PER_MCS, 0);

    // Retrieve map params
    FAPI_INF("Retrieved SDRAM density: %d, fine refresh mode: %d",
             iv_dram_density, iv_refresh_mode);

    // Calculate refresh cycle time in ps
    FAPI_TRY( calc_trfc_dlr(iv_dimm, iv_refresh_mode, iv_dram_density, l_trfc_dlr_in_ps), "Failed calc_trfc_dlr()" );

    // Calculate clock period (tCK) from selected freq from mss_freq
    FAPI_TRY( clock_period(iv_dimm, l_tCK_in_ps), "Failed to calculate clock period (tCK)");

    // Calculate refresh cycle time in nck
    FAPI_TRY( spd::calc_nck(l_trfc_dlr_in_ps, l_tCK_in_ps, spd::INVERSE_DDR4_CORRECTION_FACTOR, l_trfc_dlr_in_nck));

    FAPI_INF("tCK (ps): %d, tRFC_DLR (ps): %d, tRFC_DLR (nck): %d",
             l_tCK_in_ps, l_trfc_dlr_in_ps, l_trfc_dlr_in_nck);

    // Retrieve MCS attribute data
    FAPI_TRY( eff_dram_trfc_dlr(iv_mcs, l_mcs_attrs_trfc_dlr.data()), "Failed to retrieve tRFC_DLR attribute" );

    // Update MCS attribute
    l_mcs_attrs_trfc_dlr[iv_port_index] = l_trfc_dlr_in_nck;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRFC_DLR,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_mcs_attrs_trfc_dlr, PORTS_PER_MCS) ),
              "Failed to set tRFC_DLR attribute" );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for dimm rcd mirror mode
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::rcd_mirror_mode()
{
    // Retrieve MCS attribute data
    uint8_t l_mirror_mode = 0;
    uint8_t l_attrs_mirror_mode[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    FAPI_TRY( eff_dimm_rcd_mirror_mode(iv_mcs, &l_attrs_mirror_mode[0][0]) );

    // Update MCS attribute
    FAPI_TRY( iv_spd_decoder.register_to_dram_addr_mapping(l_mirror_mode) );
    l_attrs_mirror_mode[iv_port_index][iv_dimm_index] = l_mirror_mode;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_RCD_MIRROR_MODE, iv_mcs, l_attrs_mirror_mode) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for dram bank bits
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dram_bank_bits()
{
    uint8_t l_bank_bits = 0;
    uint8_t l_decoder_val = 0;
    uint8_t l_attrs_bank_bits[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    FAPI_TRY( eff_dram_bank_bits(iv_mcs, &l_attrs_bank_bits[0][0]) );
    FAPI_TRY( iv_spd_decoder.bank_bits(l_decoder_val) );

    FAPI_ASSERT( mss::find_value_from_key(BANK_ADDR_BITS_MAP, l_decoder_val, l_bank_bits),
                 fapi2::MSS_LOOKUP_FAILED()
                 .set_KEY(l_decoder_val)
                 .set_DATA(l_bank_bits)
                 .set_FUNCTION(DRAM_BANK_BITS)
                 .set_TARGET(iv_dimm),
                 "Could not find a mapped value that matched the key (%d) for %s",
                 l_decoder_val, mss::c_str(iv_dimm) );

    l_attrs_bank_bits[iv_port_index][iv_dimm_index] = l_bank_bits;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_BANK_BITS, iv_mcs, l_attrs_bank_bits) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for dram row bits
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dram_row_bits()
{
    uint8_t l_decoder_val = 0;
    uint8_t l_row_bits = 0;
    uint8_t l_attrs_row_bits[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    FAPI_TRY( eff_dram_row_bits(iv_mcs, &l_attrs_row_bits[0][0]) );
    FAPI_TRY( iv_spd_decoder.row_address_bits(l_decoder_val) );

    FAPI_ASSERT( mss::find_value_from_key(ROW_ADDRESS_BITS_MAP, l_decoder_val, l_row_bits),
                 fapi2::MSS_LOOKUP_FAILED()
                 .set_KEY(l_decoder_val)
                 .set_DATA(l_row_bits)
                 .set_FUNCTION(DRAM_ROW_BITS)
                 .set_TARGET(iv_dimm),
                 "Could not find a mapped value that matched the key (%d) for %s",
                 l_decoder_val, mss::c_str(iv_dimm) );

    l_attrs_row_bits[iv_port_index][iv_dimm_index] = l_row_bits;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_ROW_BITS, iv_mcs, l_attrs_row_bits) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tDQS
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Sets TDQS to off for x4, sets to on for x8
///
fapi2::ReturnCode eff_dimm::dram_dqs_time()
{
    uint8_t l_attrs_dqs_time[PORTS_PER_MCS] = {};

    // Get & update MCS attribute
    FAPI_TRY( eff_dram_tdqs(iv_mcs, &l_attrs_dqs_time[0]) );
    FAPI_INF("SDRAM width: %d for target %s", iv_dram_width, mss::c_str(iv_dimm));

    // Only possible dram width are x4, x8. If x8, tdqs is available, else not available
    l_attrs_dqs_time[iv_port_index] = (iv_dram_width == fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8) ?
                                      fapi2::ENUM_ATTR_EFF_DRAM_TDQS_ENABLE : fapi2::ENUM_ATTR_EFF_DRAM_TDQS_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TDQS, iv_mcs, l_attrs_dqs_time) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DRAM output driver impedance control
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_rdimm::dram_odic()
{
    uint8_t l_dram_odic[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};
    uint8_t l_vpd_odic[MAX_RANK_PER_DIMM];
    FAPI_TRY( eff_dram_odic(iv_mcs, &l_dram_odic[0][0][0]));

    // Gets the VPD value
    FAPI_TRY( mss::vpd_mt_dram_drv_imp_dq_dqs(iv_dimm, &(l_vpd_odic[0])));

    // Updates DRAM ODIC with the VPD value
    memcpy(&(l_dram_odic[iv_port_index][iv_dimm_index][0]), l_vpd_odic, MAX_RANK_PER_DIMM);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_ODIC, iv_mcs, l_dram_odic) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tCCD_L
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dram_tccd_l()
{
    int64_t l_tccd_in_ps = 0;

    // Get the tCCD_L timing values
    // tCCD_L is speed bin independent and is
    // the same for all bins within a speed grade.
    // It is safe to read this from SPD because the correct nck
    // value will be calulated based on our dimm speed.

    {
        int64_t l_tccd_mtb = 0;
        int64_t l_tccd_ftb = 0;

        FAPI_TRY( iv_spd_decoder.min_tccd_l(l_tccd_mtb),
                  "Failed min_tccd_l() for %s", mss::c_str(iv_dimm) );
        FAPI_TRY( iv_spd_decoder.fine_offset_min_tccd_l(l_tccd_ftb),
                  "Failed fine_offset_min_tccd_l() for %s", mss::c_str(iv_dimm) );

        FAPI_INF("%s medium timebase (ps): %ld, fine timebase (ps): %ld, tCCD_L (MTB): %ld, tCCD_L(FTB): %ld",
                 mss::c_str(iv_dimm), iv_mtb, iv_ftb, l_tccd_mtb, l_tccd_ftb );

        l_tccd_in_ps = spd::calc_timing_from_timebase(l_tccd_mtb, iv_mtb, l_tccd_ftb, iv_ftb);
    }

    {
        // Calculate refresh cycle time in nCK & set attribute
        uint8_t l_tccd_in_nck = 0;
        std::vector<uint8_t> l_mcs_attrs_tccd(PORTS_PER_MCS, 0);

        // Retrieve MCS attribute data
        FAPI_TRY( eff_dram_tccd_l(iv_mcs, l_mcs_attrs_tccd.data()),
                  "Failed to retrieve tCCD attribute" );

        // Calculate nck
        FAPI_TRY(  spd::calc_nck(l_tccd_in_ps, iv_tCK_in_ps, spd::INVERSE_DDR4_CORRECTION_FACTOR, l_tccd_in_nck),
                   "Error in calculating tccd  for target %s, with value of l_tccd_in_ps: %d", mss::c_str(iv_dimm), l_tccd_in_ps);

        FAPI_INF("tCK (ps): %d, tCCD_L (ps): %d, tCCD_L (nck): %d",
                 iv_tCK_in_ps, l_tccd_in_ps, l_tccd_in_nck);

        // DIMM's can have separate timings in a dual-drop system.
        // In those cases, we want to take the safest (most pessimistic) values
        l_mcs_attrs_tccd[iv_port_index] = std::max(l_tccd_in_nck, l_mcs_attrs_tccd[iv_port_index]);

        // casts vector into the type FAPI_ATTR_SET is expecting by deduction
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TCCD_L,
                                iv_mcs,
                                UINT8_VECTOR_TO_1D_ARRAY(l_mcs_attrs_tccd, PORTS_PER_MCS) ),
                  "Failed to set tCCD_L attribute" );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC00
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Global Features Control Word
///
fapi2::ReturnCode eff_dimm::dimm_rc00()
{
    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc00[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc00(iv_mcs, &l_attrs_dimm_rc00[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc00[iv_port_index][iv_dimm_index] = iv_raw_card.iv_rc00;

    FAPI_INF("%s: RC00 settting: 0x%02x", mss::c_str(iv_dimm), l_attrs_dimm_rc00[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC00, iv_mcs, l_attrs_dimm_rc00) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC01
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Clock Driver Enable Control Word
///
fapi2::ReturnCode eff_dimm::dimm_rc01()
{
    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc01[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc01(iv_mcs, &l_attrs_dimm_rc01[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc01[iv_port_index][iv_dimm_index] = iv_raw_card.iv_rc01;

    FAPI_INF("%s: RC01 settting: %d", mss::c_str(iv_dimm), l_attrs_dimm_rc01[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC01, iv_mcs, l_attrs_dimm_rc01) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC02
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dimm_rc02()
{
    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc02[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    fapi2::buffer<uint8_t> l_temp;

    bool is_a17 = false;
    FAPI_TRY( is_a17_needed<mss::mc_type::NIMBUS>( iv_dimm, is_a17), "%s Failed to get a17 boolean", mss::c_str(iv_dimm) );

    l_temp.writeBit<rc02_encode::A17_POS>(is_a17 ? rc02_encode::A17_ENABLE : rc02_encode::A17_DISABLE);
    FAPI_TRY( eff_dimm_ddr4_rc02(iv_mcs, &l_attrs_dimm_rc02[0][0]) );

    l_attrs_dimm_rc02[iv_port_index][iv_dimm_index] = l_temp;

    FAPI_INF("%s: RC02 settting: %d", mss::c_str(iv_dimm), l_attrs_dimm_rc02[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC02, iv_mcs, l_attrs_dimm_rc02) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC03
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dimm_rc03()
{
    constexpr uint8_t NVDIMM_RCW_WORKAROUND_VALUE = 0x08;
    fapi2::buffer<uint8_t> l_buffer;

    uint8_t l_attrs_dimm_rc03[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    uint8_t l_cs_output_drive = 0;
    uint8_t l_ca_output_drive = 0;

    FAPI_TRY( iv_spd_decoder.cs_signal_output_driver(l_cs_output_drive) );
    FAPI_TRY( iv_spd_decoder.ca_signal_output_driver(l_ca_output_drive) );

    FAPI_INF( "%s: Retrieved register output drive, for CA: %d, CS: %d",
              mss::c_str(iv_dimm), l_ca_output_drive, l_cs_output_drive );

    // Lets construct encoding byte for RCD setting
    {
        // Buffer insert constants for CS and CA output drive
        constexpr size_t CS_START = 4;
        constexpr size_t CA_START = 6;
        constexpr size_t LEN = 2;

        l_buffer.insertFromRight<CA_START, LEN>(l_ca_output_drive)
        .insertFromRight<CS_START, LEN>(l_cs_output_drive);
    }

    // Update the value if the NVDIMM workaround is needed
    FAPI_TRY(mss::workarounds::eff_config::nvdimm_rc_drive_strength(iv_dimm, NVDIMM_RCW_WORKAROUND_VALUE, l_buffer));

    // Retrieve MCS attribute data
    FAPI_TRY( eff_dimm_ddr4_rc03(iv_mcs, &l_attrs_dimm_rc03[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc03[iv_port_index][iv_dimm_index] = l_buffer;

    FAPI_INF("%s: RC03 settting: %d", mss::c_str(iv_dimm), l_attrs_dimm_rc03[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC03, iv_mcs, l_attrs_dimm_rc03) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC04
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dimm_rc04()
{
    constexpr uint8_t NVDIMM_RCW_WORKAROUND_VALUE = 0x0a;
    uint8_t l_attrs_dimm_rc04[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    uint8_t l_odt_output_drive = 0;
    uint8_t l_cke_output_drive = 0;

    fapi2::buffer<uint8_t> l_buffer;

    FAPI_TRY( iv_spd_decoder.odt_signal_output_driver(l_odt_output_drive) );
    FAPI_TRY( iv_spd_decoder.cke_signal_output_driver(l_cke_output_drive) );

    FAPI_INF( "%s: Retrieved signal driver output, for CKE: %d, ODT: %d",
              mss::c_str(iv_dimm), l_cke_output_drive, l_odt_output_drive );

    // Lets construct encoding byte for RCD setting
    {
        // Buffer insert constants for ODT and CKE output drive
        constexpr size_t CKE_START = 6;
        constexpr size_t ODT_START = 4;
        constexpr size_t LEN = 2;

        l_buffer.insertFromRight<CKE_START, LEN>(l_cke_output_drive)
        .insertFromRight<ODT_START, LEN>(l_odt_output_drive);
    }

    // Update the value if the NVDIMM workaround is needed
    FAPI_TRY(mss::workarounds::eff_config::nvdimm_rc_drive_strength(iv_dimm, NVDIMM_RCW_WORKAROUND_VALUE, l_buffer));

    // Retrieve MCS attribute data
    FAPI_TRY( eff_dimm_ddr4_rc04(iv_mcs, &l_attrs_dimm_rc04[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc04[iv_port_index][iv_dimm_index] = l_buffer;

    FAPI_INF("%s: RC04 setting: 0x%02x", mss::c_str(iv_dimm), l_attrs_dimm_rc04[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC04, iv_mcs, l_attrs_dimm_rc04) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC05
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dimm_rc05()
{
    constexpr uint8_t NVDIMM_RCW_WORKAROUND_VALUE = 0x0a;
    uint8_t l_attrs_dimm_rc05[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    uint8_t l_a_side_output_drive = 0;
    uint8_t l_b_side_output_drive = 0;

    fapi2::buffer<uint8_t> l_buffer;

    FAPI_TRY( iv_spd_decoder.a_side_clk_output_driver(l_a_side_output_drive) );
    FAPI_TRY( iv_spd_decoder.b_side_clk_output_driver(l_b_side_output_drive) );

    FAPI_INF( "%s: Retrieved register output drive for clock, b-side (Y0,Y2): %d, a-side (Y1,Y3): %d",
              mss::c_str(iv_dimm), l_b_side_output_drive, l_a_side_output_drive );

    {
        // Buffer insert constants for ODT and CKE output drive
        constexpr size_t B_START = 6;
        constexpr size_t A_START = 4;
        constexpr size_t LEN = 2;

        // Lets construct encoding byte for RCD setting
        l_buffer.insertFromRight<B_START, LEN>(l_b_side_output_drive)
        .insertFromRight<A_START, LEN>(l_a_side_output_drive);
    }

    // Update the value if the NVDIMM workaround is needed
    FAPI_TRY(mss::workarounds::eff_config::nvdimm_rc_drive_strength(iv_dimm, NVDIMM_RCW_WORKAROUND_VALUE, l_buffer));

    // Retrieve MCS attribute data
    FAPI_TRY( eff_dimm_ddr4_rc05(iv_mcs, &l_attrs_dimm_rc05[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc05[iv_port_index][iv_dimm_index] = l_buffer;

    FAPI_INF( "%s: RC05 setting: 0x%02x", mss::c_str(iv_dimm), l_attrs_dimm_rc05[iv_port_index][iv_dimm_index] )
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC05, iv_mcs, l_attrs_dimm_rc05) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC06_07
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Command Space Control Word -- used to issue register commands
///
fapi2::ReturnCode eff_dimm::dimm_rc06_07()
{
    constexpr uint64_t NO_OP = 0x0F;
    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc06_07[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc06_07(iv_mcs, &l_attrs_dimm_rc06_07[0][0]) );

    // Update MCS attribute
    // Set to NO_OP state. Will be used for rcd commands
    l_attrs_dimm_rc06_07[iv_port_index][iv_dimm_index] = NO_OP;

    FAPI_INF( "%s: RC06_07 setting: 0x%02x", mss::c_str(iv_dimm), l_attrs_dimm_rc06_07[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC06_07, iv_mcs, l_attrs_dimm_rc06_07) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines how many chip ID bits are needed for the iv_dimm
/// @param[out] o_qs a qsid encoding denoting if 0, 1, 2, or all three QSID's are needed
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::calculate_chip_ids( qsid& o_qs)
{
    uint8_t l_total_ranks = 0;
    uint8_t l_master_ranks = 0;
    uint8_t l_num_slave_ranks = 0;
    uint8_t l_stack_type = 0;

    FAPI_TRY( mss::eff_num_master_ranks_per_dimm(iv_dimm, l_master_ranks) );
    FAPI_TRY( mss::eff_num_ranks_per_dimm(iv_dimm, l_total_ranks) );

    // Calling this eff_dimm's setter function and then the function to get the attribute
    // While this is less efficient than calling the decoder function, it makes testing 3DS DIMMs easier
    // This allows us to use attribute overrides to test the DIMMS as SDP's
    FAPI_TRY( eff_prim_stack_type(iv_dimm, l_stack_type));

    // Little assert, but this shouldn't be possible and should be caught in the decoder function
    if (l_master_ranks == 0)
    {
        FAPI_ERR("Error getting master_ranks attribute. Should have already been caught if bad SPD");
        fapi2::Assert(false);
    }

    // Slave ranks = total ranks (aka logical ranks)  / master ranks (aka package ranks)
    l_num_slave_ranks = l_total_ranks / l_master_ranks;

    // Let's assert that our math is correct. total_ranks % l_master_ranks should equal 0. It should be cleanly divisible
    FAPI_ASSERT( !(l_total_ranks % l_master_ranks),
                 fapi2::MSS_INVALID_SPD_SLAVE_RANKS()
                 .set_LOGICAL_RANKS(l_total_ranks)
                 .set_MASTER_RANKS(l_master_ranks)
                 .set_DIMM_TARGET(iv_dimm),
                 "%s Logical ranks(%d) are not divisible by master ranks(%d). Bad SPD?",
                 mss::c_str(iv_dimm), l_total_ranks, l_master_ranks);

    // If we are 3DS we need to enable chip ID signal with QxC
    switch( l_stack_type)
    {
        case fapi2::ENUM_ATTR_EFF_PRIM_STACK_TYPE_DDP_QDP:
        case fapi2::ENUM_ATTR_EFF_PRIM_STACK_TYPE_SDP:
            FAPI_INF("%s Disabling CID's", mss::c_str(iv_dimm));
            o_qs = ALL_DISABLE;
            break;

        // If 3DS, we have slave ranks and thus need some chip ID bits to be enabled
        case fapi2::ENUM_ATTR_EFF_PRIM_STACK_TYPE_3DS:

            // Check according Rank Matrix for Summetrical Modules
            // Page 24 of DDR4 SPD Contents JC-45-2220.01x
            // 3DS DIMM has to have 2 or more logical ranks per package rank
            // Meaning, it has to have at least 2 slave ranks for each "master" rank
            // If it does not or we are testing just 1 package rank, we should set the stack type to SDP
            FAPI_ASSERT( l_total_ranks > l_master_ranks,
                         fapi2::MSS_INVALID_CALCULATED_NUM_SLAVE_RANKS()
                         .set_NUM_SLAVE_RANKS(l_num_slave_ranks)
                         .set_NUM_TOTAL_RANKS(l_total_ranks)
                         .set_NUM_MASTER_RANKS(l_master_ranks)
                         .set_DIMM_TARGET(iv_dimm),
                         "For target %s: Invalid total_ranks %d seen with %d master ranks",
                         mss::c_str(iv_dimm),
                         l_total_ranks,
                         l_master_ranks);


            FAPI_INF("Target %s seeing %d total ranks, %d master ranks, %d slave ranks",
                     mss::c_str(iv_dimm),
                     l_total_ranks,
                     l_master_ranks,
                     l_num_slave_ranks);

            // Double check we calculated this correctly
            FAPI_ASSERT( ((l_num_slave_ranks != 0) ||  (l_num_slave_ranks < NUM_SLAVE_RANKS_ENCODED_IN_THREE_BITS)),
                         fapi2::MSS_INVALID_CALCULATED_NUM_SLAVE_RANKS()
                         .set_NUM_SLAVE_RANKS(l_num_slave_ranks)
                         .set_NUM_TOTAL_RANKS(l_total_ranks)
                         .set_NUM_MASTER_RANKS(l_master_ranks)
                         .set_DIMM_TARGET(iv_dimm),
                         "For target %s: Invalid number of slave ranks calculated (%d) from (total_ranks %d / master %d)",
                         mss::c_str(iv_dimm),
                         l_num_slave_ranks,
                         l_total_ranks,
                         l_master_ranks);

            // These are based off of log base 2.
            if (l_num_slave_ranks <= NUM_SLAVE_RANKS_ENCODED_IN_ONE_BIT)
            {
                o_qs = ZERO_ENABLE;
            }
            // Only need 2 bits to encode 4 slave ranks per master rank with chip IDs
            else if (l_num_slave_ranks <= NUM_SLAVE_RANKS_ENCODED_IN_TWO_BITS)
            {
                o_qs = ZERO_ONE_ENABLE;
            }
            else
            {
                // 5-8 slave ranks, Gonna need all three bits
                o_qs = ALL_ENABLE;
            }

            FAPI_INF("%s Chip ID bits are %x", mss::c_str(iv_dimm), o_qs);

            break;

        default:
            FAPI_ERR("Target %s: Error, incorrect ATTR_EFF_PRIM_STACK_TYPE found", mss::c_str(iv_dimm));
            // If this fails
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_PRIM_STACK_TYPE()
                         .set_STACK_TYPE(l_stack_type)
                         .set_DIMM_TARGET(iv_dimm),
                         "For target %s: An invalid stack type (%d) found for MSS ATTR_EFF_PRIM_STACK_TYPE",
                         mss::c_str(iv_dimm),
                         l_stack_type);
    };

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines how many chip select ID bits are needed for the iv_dimm on the output from the RCD
/// @param[out] o_qs a qsid encoding denoting if 0, 1, 2, or all three QSID's are needed
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::calculate_chip_ids_outputs( qsid& o_qs)
{
    // So, CID's on the output side of the RCD function as dual-purpose signals
    // They function as either CID's or as CS2/3 depending upon the rawcard in question and the RCD's configuration
    // If we have 4 master ranks, we need to go into quad encoded mode
    // At that point, CID 0/1's outputs become CS2/3
    // Here, we override the output values to enable CID0/1 if we have 4 ranks
    // If not, we just pass back the value we already calculated
    uint8_t l_master_ranks = 0;
    FAPI_TRY( mss::eff_num_master_ranks_per_dimm(iv_dimm, l_master_ranks) );
    FAPI_TRY(calculate_chip_ids(o_qs));
    o_qs = l_master_ranks == 4 ? ZERO_ONE_ENABLE : o_qs;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines how many chip select ID bits are needed for the iv_dimm on the input to the RCD
/// @param[out] o_qs a qsid encoding denoting if 0, 1, 2, or all three QSID's are needed
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::calculate_chip_ids_inputs( qsid& o_qs)
{
    // So, CID's on the input side of the RCD function as dual-purpose signals
    // They function as either CID's or as CS2/3 depending upon the board wiring in question and the RCD's configuration
    // If we have 4 master ranks, we need to go into quad encoded mode
    // At that point, CID 0 becomes used as part of the encoded CS
    // Here, we override the output values to enable CID0 if we have 4 ranks
    // If not, we just pass back the value we already calculated
    uint8_t l_master_ranks = 0;
    FAPI_TRY( mss::eff_num_master_ranks_per_dimm(iv_dimm, l_master_ranks) );
    FAPI_TRY(calculate_chip_ids(o_qs));
    o_qs = l_master_ranks == 4 ? ZERO_ENABLE : o_qs;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC08
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note DA[1:0] enable/ disable QxC
///
fapi2::ReturnCode eff_dimm::dimm_rc08()
{
    uint8_t l_attrs_dimm_rc08[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    fapi2::buffer<uint8_t> l_buffer = 0;

    qsid l_qs_enabled = ALL_DISABLE;
    FAPI_TRY( eff_dimm::calculate_chip_ids_outputs(l_qs_enabled) );
    l_buffer.insertFromRight<CID_START, CID_LENGTH>(l_qs_enabled);

    // Let's set the other bits
    l_buffer.writeBit<QXPAR_LOCATION>(RC08_PARITY_ENABLE);

    // Now for A17 bit
    {
        bool l_is_a17 = false;

        FAPI_TRY( is_a17_needed<mss::mc_type::NIMBUS>( iv_dimm, l_is_a17), "%s Failed to get a17 boolean",
                  mss::c_str(iv_dimm) );
        l_buffer.writeBit<DA17_QA17_LOCATION>(l_is_a17 ? DA17_QA17_ENABLE : DA17_QA17_DISABLE);

        FAPI_INF("%s Turning %s DA17", mss::c_str(iv_dimm), (l_is_a17 ? "on" : "off"));
    }

    FAPI_TRY( eff_dimm_ddr4_rc08(iv_mcs, &l_attrs_dimm_rc08[0][0]) );
    l_attrs_dimm_rc08[iv_port_index][iv_dimm_index] = l_buffer;

    FAPI_INF( "%s: RC08 setting: 0x%02x", mss::c_str(iv_dimm), l_attrs_dimm_rc08[iv_port_index][iv_dimm_index] );

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC08, iv_mcs, l_attrs_dimm_rc08) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC09
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Power Saving Settings Control Word
///
fapi2::ReturnCode eff_dimm::dimm_rc09()
{
    // Sets up constant values
    constexpr uint64_t CKE_POWER_DOWN_MODE_ENABLE_POS = 4;
    constexpr uint64_t CKE_POWER_DOWN_MODE_ENABLE = 1;

    constexpr uint64_t ODT_POS_OFFSET = 4;
    constexpr uint64_t ODT_ATTR_LEN = 2;
    constexpr uint64_t IBT_OFF_POS = 5;
    constexpr uint64_t IBT_OFF = 1;
    constexpr uint64_t IBT_ON = 0;

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc09[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    fapi2::buffer<uint8_t> l_rc09;
    l_rc09.writeBit<CKE_POWER_DOWN_MODE_ENABLE_POS>(CKE_POWER_DOWN_MODE_ENABLE)
    .writeBit<IBT_OFF_POS>(IBT_OFF);

    // If CKE power down mode is on and we're in dual drop mode, then we need to configure the IBT mode
    if((l_rc09.getBit<CKE_POWER_DOWN_MODE_ENABLE_POS>() == CKE_POWER_DOWN_MODE_ENABLE)
       && (mss::count_dimm(iv_mca) == MAX_DIMM_PER_PORT))
    {
        FAPI_INF("%s Checking whether the DIMM needs IBT mode on or off", mss::c_str(iv_dimm));

        // RCD's can be powered down to conserve power similar to DRAMs (by dropping CKE)
        // This functionality is enabled by bit RC09 (bit 4 in our attribute)
        // If CKE power down mode is enabled and the system has a dual drop on this MCA, then we need to reconfigure the attribute
        // Currently, that is the case (check out the if above)
        // The broadcast of ODT's to the DRAMs can be disabled if no ODT's are needed by the other DIMM for writes or reads
        // So, we need to check that
        // Steps to do so:
        // 1) Gets the other DIMM
        // 2) Gets the ODT values for the other DIMM
        // 3) Checks whether this DIMM's ODTs are used for writes or reads that target the other DIMMs
        // 4) Modify the value for IBT

        // 1) Gets the other DIMM
        const auto l_dimms = mss::find_targets<fapi2::TARGET_TYPE_DIMM>(iv_mca);
        const auto l_this_dimm_pos = mss::relative_pos<fapi2::TARGET_TYPE_MCA>(iv_dimm);
        const auto l_other_dimm_pos = l_this_dimm_pos == 0 ? 1 : 0;
        const auto l_other_dimm = l_dimms[l_other_dimm_pos];
        bool l_ibt = IBT_OFF;

        // 2) Gets the ODT values for the other DIMM
        uint8_t l_wr_odt[MAX_RANK_PER_DIMM] = {};
        uint8_t l_rd_odt[MAX_RANK_PER_DIMM] = {};
        FAPI_TRY(eff_odt_rd(l_other_dimm, l_rd_odt));
        FAPI_TRY(eff_odt_wr(l_other_dimm, l_wr_odt));

        // 3) Checks whether this DIMM's ODTs are used for writes or reads that target the other DIMMs
        for(uint8_t l_rank = 0; l_rank < MAX_RANK_PER_DIMM; ++l_rank)
        {
            // Temporary buffers to make the math a bit easier
            const fapi2::buffer<uint8_t> l_temp_wr(l_wr_odt[l_rank]);
            const fapi2::buffer<uint8_t> l_temp_rd(l_rd_odt[l_rank]);

            // The ODT attribute consists of a bitmask as follows 0->7
            // [DIMM0 ODT0][DIMM0 ODT1][N/A][N/A][DIMM1 ODT0][DIMM1 ODT1][N/A][N/A]
            // As we need whether any ODT is enabled for this DIMM, compute the appropriate offset based upon the DIMM index value
            const auto l_this_dimm_odt = l_this_dimm_pos * ODT_POS_OFFSET;

            // Are either the writed or read ODT's enabled for this DIMM?
            if(l_temp_wr.getBit(l_this_dimm_odt, ODT_ATTR_LEN) || l_temp_rd.getBit(l_this_dimm_odt, ODT_ATTR_LEN))
            {
                l_ibt = IBT_ON;
                break;
            }
        }

        // 4) Modifies the value
        l_rc09.writeBit<IBT_OFF_POS>(l_ibt);
        FAPI_INF("%s has IBT value of %s giving a value of 0x%02x", mss::c_str(iv_dimm), l_ibt == IBT_OFF ? "OFF" : "ON",
                 uint8_t(l_rc09));
    }

    FAPI_TRY( eff_dimm_ddr4_rc09(iv_mcs, &l_attrs_dimm_rc09[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc09[iv_port_index][iv_dimm_index] = l_rc09;

    FAPI_INF( "%s: RC09 setting: 0x%02x", mss::c_str(iv_dimm), l_attrs_dimm_rc09[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC09, iv_mcs, l_attrs_dimm_rc09) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC0A
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dimm_rc0a()
{
    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc0a[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc0a(iv_mcs, &l_attrs_dimm_rc0a[0][0]) );


    switch(iv_freq)
    {
        case fapi2::ENUM_ATTR_MSS_FREQ_MT1866:
            l_attrs_dimm_rc0a[iv_port_index][iv_dimm_index] = rc0a_encode::DDR4_1866;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2133:
            l_attrs_dimm_rc0a[iv_port_index][iv_dimm_index] = rc0a_encode::DDR4_2133;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2400:
            l_attrs_dimm_rc0a[iv_port_index][iv_dimm_index] = rc0a_encode::DDR4_2400;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2666:
            l_attrs_dimm_rc0a[iv_port_index][iv_dimm_index] = rc0a_encode::DDR4_2666;
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_FREQ_RC()
                         .set_FREQ(iv_freq)
                         .set_RC_NUM(RC0A)
                         .set_DIMM_TARGET(iv_dimm),
                         "Invalid frequency for rc0a encoding received: %d", iv_freq);
            break;
    }

    FAPI_INF( "%s: RC0A setting: 0x%02x", mss::c_str(iv_dimm), l_attrs_dimm_rc0a[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC0A, iv_mcs, l_attrs_dimm_rc0a) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC0B
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Operating Voltage VDD and VrefCA Source Control Word
///
fapi2::ReturnCode eff_dimm::dimm_rc0b()
{
    // Settings for rc0b:
    // Input Receiver Vref Source to:     External VrefCA input
    // QVrefCA and BVrefCA Sources to:    External VrefCA input connected to QVrefCA and BVrefCA
    // Register VDD Operating Voltage to: 1.2 V
    constexpr uint8_t RC0B = 0x0E;

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc0b[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc0b(iv_mcs, &l_attrs_dimm_rc0b[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc0b[iv_port_index][iv_dimm_index] = RC0B;

    FAPI_INF( "%s: RC0B setting: 0x%02x", mss::c_str(iv_dimm), l_attrs_dimm_rc0b[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC0B, iv_mcs, l_attrs_dimm_rc0b) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC0C
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Training Control Word
///
fapi2::ReturnCode eff_dimm::dimm_rc0c()
{
    // Setting to normal operating mode
    constexpr uint8_t NORMAL_OP_MODE = 0x00;

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc0c[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc0c(iv_mcs, &l_attrs_dimm_rc0c[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc0c[iv_port_index][iv_dimm_index] = NORMAL_OP_MODE;

    FAPI_INF( "%s: RC0C setting: 0x%02x", mss::c_str(iv_dimm), l_attrs_dimm_rc0c[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC0C, iv_mcs, l_attrs_dimm_rc0c) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC0D
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dimm_rc0d()
{
    uint8_t l_attrs_dimm_rc0d[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    fapi2::buffer<uint8_t> l_buffer;

    uint8_t l_mirror_mode = 0;
    uint8_t l_dimm_type = 0;
    uint8_t l_rc0d_dimm_type = 0;

    uint8_t l_master_ranks = 0;

    // Number of master ranks taken from attribute since we need mapped value
    // and not the encoded raw value from SPD.
    FAPI_TRY( mss::eff_num_master_ranks_per_dimm(iv_dimm, l_master_ranks) );
    FAPI_TRY(mss::eff_dimm_type(iv_dimm, l_dimm_type));

    l_rc0d_dimm_type = (l_dimm_type == fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM) ?
                       rc0d_encode::RDIMM :
                       rc0d_encode::LRDIMM;

    FAPI_TRY( iv_spd_decoder.register_to_dram_addr_mapping(l_mirror_mode) );

    // Lets construct encoding byte for RCD setting
    {
        // CS
        constexpr size_t CS_START = 6;
        constexpr size_t CS_LEN = 2;

        // DIMM TYPE
        constexpr size_t DIMM_TYPE_START = 5;
        constexpr size_t DIMM_TYPE_LEN = 1;

        // MIRROR mode
        constexpr size_t MIRROR_START = 4;
        constexpr size_t MIRROR_LEN = 1;

        // 4rank DIMM's need to use quad encoded CS mode, otherwise we're dual direct
        const auto l_cs_mode = l_master_ranks == 4 ?
                               rc0d_encode::QUAD_ENCODE_CS_MODE :
                               rc0d_encode::DUAL_DIRECT_CS_MODE;

        l_buffer.insertFromRight<CS_START, CS_LEN>(l_cs_mode)
        .insertFromRight<DIMM_TYPE_START, DIMM_TYPE_LEN>(l_rc0d_dimm_type)
        .insertFromRight<MIRROR_START, MIRROR_LEN>(l_mirror_mode);
    }

    // Retrieve MCS attribute data
    FAPI_TRY( eff_dimm_ddr4_rc0d(iv_mcs, &l_attrs_dimm_rc0d[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc0d[iv_port_index][iv_dimm_index] = l_buffer;

    FAPI_INF( "%s: RC0D setting: 0x%02x", mss::c_str(iv_dimm), l_attrs_dimm_rc0d[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC0D, iv_mcs, l_attrs_dimm_rc0d) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC0E
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dimm_rc0e()
{
    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc0e[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    uint8_t l_sim = 0;
    fapi2::buffer<uint8_t> l_rc0e;

    FAPI_TRY( mss::is_simulation (l_sim) );
    FAPI_TRY( eff_dimm_ddr4_rc0e(iv_mcs, &l_attrs_dimm_rc0e[0][0]) );

    // Values are the same for all DIMMs
    // Moved to eff_config instead of raw card data because it's cleaner here
    if (!l_sim)
    {
        l_rc0e.writeBit<RC0E_PARITY_ENABLE_BIT>(RC0E_PARITY_ENABLE);
        l_rc0e.writeBit<RC0E_ALERT_N_ASSERT_BIT>(RC0E_ALERT_N_ASERT_PULSE);
        l_rc0e.writeBit<RC0E_ALERT_N_REENABLE_BIT>(RC0E_ALERT_N_REENABLE_TRUE);
    }

    l_attrs_dimm_rc0e[iv_port_index][iv_dimm_index] = l_rc0e;
    FAPI_INF( "%s: RC0E setting: 0x%0x", mss::c_str(iv_dimm), l_attrs_dimm_rc0e[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC0E, iv_mcs, l_attrs_dimm_rc0e) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC0F
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Command Latency Adder Control Word
///
fapi2::ReturnCode eff_dimm::dimm_rc0f()
{
    // Normal mode:
    // Set 1 nCK latency adder to Qn1, QxCSn, QxCKEn2, QxODTn
    // 0nCK latency adder to QxPAR
    constexpr uint8_t NORMAL_MODE = 0x00;

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc0f[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc0f(iv_mcs, &l_attrs_dimm_rc0f[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc0f[iv_port_index][iv_dimm_index] = NORMAL_MODE;

    FAPI_INF( "%s: RC0F setting: 0x%02x", mss::c_str(iv_dimm), l_attrs_dimm_rc0f[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC0F, iv_mcs, l_attrs_dimm_rc0f) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC_1x
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Internal VrefCA Control Word
///
fapi2::ReturnCode eff_dimm::dimm_rc1x()
{
    // Normal Mode: VDDR/2
    constexpr uint8_t HALF_VDDR = 0x00;

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc_1x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc_1x(iv_mcs, &l_attrs_dimm_rc_1x[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc_1x[iv_port_index][iv_dimm_index] = HALF_VDDR;

    FAPI_INF( "%s: RC1X setting: 0x%02x", mss::c_str(iv_dimm), l_attrs_dimm_rc_1x[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_1x, iv_mcs, l_attrs_dimm_rc_1x) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC_2x
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note I2C Bus Control Word
///
fapi2::ReturnCode eff_dimm::dimm_rc2x()
{
    //Normal mode
    constexpr uint8_t NORMAL_MODE = 0x00;

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc_2x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc_2x(iv_mcs, &l_attrs_dimm_rc_2x[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc_2x[iv_port_index][iv_dimm_index] = NORMAL_MODE;

    FAPI_INF( "%s: RC2X setting: 0x%02x", mss::c_str(iv_dimm), l_attrs_dimm_rc_2x[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_2x, iv_mcs, l_attrs_dimm_rc_2x) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC_3x
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dimm_rc3x()
{
    uint8_t l_attrs_dimm_rc_3x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Retrieve MCS attribute data
    FAPI_TRY( eff_dimm_ddr4_rc_3x(iv_mcs, &l_attrs_dimm_rc_3x[0][0]) );

    switch(iv_freq)
    {
        case fapi2::ENUM_ATTR_MSS_FREQ_MT1866:
            l_attrs_dimm_rc_3x[iv_port_index][iv_dimm_index] = rc3x_encode::MT1860_TO_MT1880;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2133:
            l_attrs_dimm_rc_3x[iv_port_index][iv_dimm_index] = rc3x_encode::MT2120_TO_MT2140;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2400:
            l_attrs_dimm_rc_3x[iv_port_index][iv_dimm_index] = rc3x_encode::MT2380_TO_MT2400;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2666:
            l_attrs_dimm_rc_3x[iv_port_index][iv_dimm_index] = rc3x_encode::MT2660_TO_MT2680;
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_FREQ_RC()
                         .set_FREQ(iv_freq)
                         .set_RC_NUM(RC3X)
                         .set_DIMM_TARGET(iv_dimm),
                         "%s: Invalid frequency for RC_3X encoding received: %d",
                         mss::c_str(iv_dimm),
                         iv_freq);
            break;
    }

    FAPI_INF( "%s: RC3X setting: 0x%02x", mss::c_str(iv_dimm), l_attrs_dimm_rc_3x[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_3x, iv_mcs, l_attrs_dimm_rc_3x) );


fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC_4x
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note CW Source Selection Control Word
///
fapi2::ReturnCode eff_dimm::dimm_rc4x()
{
    // This will get overwritten when sending rcw's
    // Defaulting to control word selection function space 0
    constexpr uint8_t CW_SELECTION_FS0 = 0x00;

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc_4x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc_4x(iv_mcs, &l_attrs_dimm_rc_4x[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc_4x[iv_port_index][iv_dimm_index] = CW_SELECTION_FS0;

    FAPI_INF( "%s: RC4X setting: 0x%02x", mss::c_str(iv_dimm), l_attrs_dimm_rc_4x[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_4x, iv_mcs, l_attrs_dimm_rc_4x) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC_5x
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note CW Destination Selection & Write/Read Additional QxODT[1:0] Signal High
///
fapi2::ReturnCode eff_dimm::dimm_rc5x()
{
    // Default 0nCK addition to ODT
    constexpr uint8_t DEFAULT_0_ODT_ADD = 0x00;

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc_5x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc_5x(iv_mcs, &l_attrs_dimm_rc_5x[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc_5x[iv_port_index][iv_dimm_index] = DEFAULT_0_ODT_ADD;

    FAPI_INF( "%s: RC5X setting: 0x%02x", mss::c_str(iv_dimm), l_attrs_dimm_rc_5x[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_5x, iv_mcs, l_attrs_dimm_rc_5x) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC_6x
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note CW Data Control Word
///
fapi2::ReturnCode eff_dimm::dimm_rc6x()
{
    // Attribute gets overwritten for rcd commands
    constexpr uint8_t RC6X = 0x00;

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc_6x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc_6x(iv_mcs, &l_attrs_dimm_rc_6x[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc_6x[iv_port_index][iv_dimm_index] = RC6X;

    FAPI_INF( "%s: RC6X setting: 0x%02x", mss::c_str(iv_dimm), l_attrs_dimm_rc_6x[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_6x, iv_mcs, l_attrs_dimm_rc_6x) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC_7x
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dimm_rc7x()
{
    uint8_t l_attrs_dimm_rc_7x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    fapi2::buffer<uint8_t> l_rcd7x = 0;

    // All the IBT bit fields in the RCD control word are 2 bits long.
    constexpr uint64_t LEN = 2;

    // CA starts at bit 6, others are the same. So the field runs from START for LEN bits,
    // for example CA field is bits 6:7
    constexpr uint64_t CA_START = 6;
    uint8_t l_ibt_ca = 0;

    constexpr uint64_t CKE_START = 2;
    uint8_t l_ibt_cke = 0;

    constexpr uint64_t CS_START = 4;
    uint8_t l_ibt_cs = 0;

    constexpr uint64_t ODT_START = 0;
    uint8_t l_ibt_odt = 0;

    // Pull the individual settings from VPD, and shuffle them into RCD7x
    FAPI_TRY( mss::vpd_mt_dimm_rcd_ibt_ca(iv_dimm, l_ibt_ca) );
    FAPI_TRY( mss::vpd_mt_dimm_rcd_ibt_cke(iv_dimm, l_ibt_cke) );
    FAPI_TRY( mss::vpd_mt_dimm_rcd_ibt_cs(iv_dimm, l_ibt_cs) );
    FAPI_TRY( mss::vpd_mt_dimm_rcd_ibt_odt(iv_dimm, l_ibt_odt) );

    l_rcd7x.insertFromRight<CA_START, LEN>( ibt_helper(l_ibt_ca) );
    l_rcd7x.insertFromRight<CKE_START, LEN>( ibt_helper(l_ibt_cke) );
    l_rcd7x.insertFromRight<CS_START, LEN>( ibt_helper(l_ibt_cs) );
    l_rcd7x.insertFromRight<ODT_START, LEN>( ibt_helper(l_ibt_odt) );

    // Now write RCD7x out to the effective attribute
    FAPI_TRY( eff_dimm_ddr4_rc_7x(iv_mcs, &l_attrs_dimm_rc_7x[0][0]) );
    l_attrs_dimm_rc_7x[iv_port_index][iv_dimm_index] = l_rcd7x;

    FAPI_INF( "%s: RC7X setting is 0x%x", mss::c_str(iv_dimm), l_attrs_dimm_rc_7x[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_7x, iv_mcs, l_attrs_dimm_rc_7x) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC_8x
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @notw ODT Input Buffer/IBT, QxODT Output Buffer and Timing Control Word
///
fapi2::ReturnCode eff_dimm::dimm_rc8x()
{
    // Setting to defaults:
    // QxODT[1:0] asserted same time as Write Command
    // QxODT[1:0] asserted same time as Read Command
    constexpr uint8_t DEFAULT_QXODT_TIMING = 0x00;

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc_8x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc_8x(iv_mcs, &l_attrs_dimm_rc_8x[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc_8x[iv_port_index][iv_dimm_index] = DEFAULT_QXODT_TIMING;

    FAPI_INF( "%s: RC8X setting: 0x%02x", mss::c_str(iv_dimm), l_attrs_dimm_rc_8x[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_8x, iv_mcs, l_attrs_dimm_rc_8x) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC_9x
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note QxODT[1:0] Write Pattern Control Word
///
fapi2::ReturnCode eff_dimm::dimm_rc9x()
{
    // Setting to Default's : QxODT's are not asserted during writes
    constexpr uint8_t RC9X = 0x00;

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc_9x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc_9x(iv_mcs, &l_attrs_dimm_rc_9x[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc_9x[iv_port_index][iv_dimm_index] = RC9X;

    FAPI_INF( "%s: RC9X setting: 0x%02x", mss::c_str(iv_dimm), l_attrs_dimm_rc_9x[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_9x, iv_mcs, l_attrs_dimm_rc_9x) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC_AX
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note QxODT[1:0] Read Pattern Control Word
///
fapi2::ReturnCode eff_dimm::dimm_rcax()
{
    // Setting to Default's : QxODT's are not asserted during reads
    constexpr uint8_t RCAX = 0x00;

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc_ax[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc_ax(iv_mcs, &l_attrs_dimm_rc_ax[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc_ax[iv_port_index][iv_dimm_index] = RCAX;

    FAPI_INF( "%s: RCAX setting: 0x%02x", mss::c_str(iv_dimm), l_attrs_dimm_rc_ax[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_Ax, iv_mcs, l_attrs_dimm_rc_ax) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC_BX
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dimm_rcbx()
{
    fapi2::buffer<uint8_t> l_buf;

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc_bx[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    qsid l_qs_enabled = ALL_DISABLE;
    FAPI_TRY( eff_dimm::calculate_chip_ids_inputs( l_qs_enabled) );

    switch (l_qs_enabled)
    {
        case ALL_DISABLE:
            l_buf.writeBit<DC0_POS>(DC_DISABLE)
            .writeBit<DC1_POS>(DC_DISABLE)
            .writeBit<DC2_POS>(DC_DISABLE);
            break;

        case ZERO_ENABLE:
            l_buf.writeBit<DC0_POS>(DC_ENABLE)
            .writeBit<DC1_POS>(DC_DISABLE)
            .writeBit<DC2_POS>(DC_DISABLE);
            break;

        case ZERO_ONE_ENABLE:
            l_buf.writeBit<DC0_POS>(DC_ENABLE)
            .writeBit<DC1_POS>(DC_ENABLE)
            .writeBit<DC2_POS>(DC_DISABLE);
            break;

        case ALL_ENABLE:
            l_buf.writeBit<DC0_POS>(DC_ENABLE)
            .writeBit<DC1_POS>(DC_ENABLE)
            .writeBit<DC2_POS>(DC_ENABLE);
            break;

        default:
            FAPI_ERR("%s Error with C++ enum in eff_dimm.C. %d received", mss::c_str(iv_dimm), l_qs_enabled);
            fapi2::Assert(false);
    }

    FAPI_TRY( eff_dimm_ddr4_rc_bx(iv_mcs, &l_attrs_dimm_rc_bx[0][0]) );
    l_attrs_dimm_rc_bx[iv_port_index][iv_dimm_index] = l_buf;

    FAPI_INF( "%s: RCBX setting: 0x%02x", mss::c_str(iv_dimm), l_attrs_dimm_rc_bx[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_Bx, iv_mcs, l_attrs_dimm_rc_bx) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tWR
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dram_twr()
{
    int64_t l_twr_in_ps = 0;

    // Get the tWR timing values
    // tWR is speed bin independent and is
    // the same for all bins within a speed grade.
    // It is safe to read this from SPD because the correct nck
    // value will be calulated based on our dimm speed.
    {
        constexpr int64_t l_twr_ftb = 0;
        int64_t l_twr_mtb = 0;

        FAPI_TRY( iv_spd_decoder.min_twr(l_twr_mtb),
                  "Failed min_twr() for %s", mss::c_str(iv_dimm) );

        FAPI_INF("%s medium timebase (ps): %ld, fine timebase (ps): %ld, tWR (MTB): %ld, tWR(FTB): %ld",
                 mss::c_str(iv_dimm), iv_mtb, iv_ftb, l_twr_mtb, l_twr_ftb);

        // Calculate twr (in ps)
        l_twr_in_ps = spd::calc_timing_from_timebase(l_twr_mtb, iv_mtb, l_twr_ftb, iv_ftb);
    }

    {
        std::vector<uint8_t> l_attrs_dram_twr(PORTS_PER_MCS, 0);
        uint8_t l_twr_in_nck = 0;

        // Calculate tNCK
        FAPI_TRY( spd::calc_nck(l_twr_in_ps, iv_tCK_in_ps, spd::INVERSE_DDR4_CORRECTION_FACTOR,  l_twr_in_nck),
                  "Error in calculating l_twr_in_nck for target %s, with value of l_twr_in_ps: %d", mss::c_str(iv_dimm), l_twr_in_ps);

        FAPI_INF( "tCK (ps): %d, tWR (ps): %d, tWR (nck): %d for target: %s",
                  iv_tCK_in_ps, l_twr_in_ps, l_twr_in_nck, mss::c_str(iv_dimm) );

        // Get & update MCS attribute
        FAPI_TRY( eff_dram_twr(iv_mcs, l_attrs_dram_twr.data()) );

        // DIMM's can have separate timings in a dual-drop system.
        // In those cases, we want to take the safest (most pessimistic) values
        l_attrs_dram_twr[iv_port_index] = std::max(l_twr_in_nck, l_attrs_dram_twr[iv_port_index]);
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TWR,
                                iv_mcs,
                                UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_twr, PORTS_PER_MCS)),
                  "Failed setting attribute for DRAM_TWR");
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for RBT
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::read_burst_type()
{
    uint8_t l_attrs_rbt[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    FAPI_TRY( eff_dram_rbt(iv_mcs, &l_attrs_rbt[0][0]) );

    l_attrs_rbt[iv_port_index][iv_dimm_index] = fapi2::ENUM_ATTR_EFF_DRAM_RBT_SEQUENTIAL;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_RBT, iv_mcs, l_attrs_rbt),
              "Failed setting attribute for RTB");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for TM
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note dram testing mode
/// @note always disabled
///
fapi2::ReturnCode eff_dimm::dram_tm()
{
    uint8_t l_attrs_tm[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    FAPI_TRY( eff_dram_tm(iv_mcs, &l_attrs_tm[0][0]) );

    l_attrs_tm[iv_port_index][iv_dimm_index] = fapi2::ENUM_ATTR_EFF_DRAM_TM_NORMAL;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TM, iv_mcs, l_attrs_tm),
              "Failed setting attribute for BL");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for cwl
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Sets CAS Write Latency, depending on frequency and ATTR_MSS_MT_PREAMBLE
///
fapi2::ReturnCode eff_dimm::dram_cwl()
{

    // Taken from DDR4 JEDEC spec 1716.78C
    // Proposed DDR4 Full spec update(79-4A)
    // Page 26, Table 7
    static constexpr std::pair<uint64_t, uint8_t> CWL_TABLE_1 [] =
    {
        {fapi2::ENUM_ATTR_MSS_FREQ_MT1866, 10},
        {fapi2::ENUM_ATTR_MSS_FREQ_MT2133, 11},
        {fapi2::ENUM_ATTR_MSS_FREQ_MT2400, 12},
        {fapi2::ENUM_ATTR_MSS_FREQ_MT2666, 14},
    };

    static constexpr std::pair<uint64_t, uint8_t> CWL_TABLE_2 [] =
    {
        {fapi2::ENUM_ATTR_MSS_FREQ_MT2400, 14},
        {fapi2::ENUM_ATTR_MSS_FREQ_MT2666, 16},
    };

    std::vector<uint8_t> l_attrs_cwl(PORTS_PER_MCS, 0);
    uint8_t l_cwl = 0;
    uint8_t l_preamble = 0;

    FAPI_TRY( vpd_mt_preamble (iv_mca, l_preamble) );

    // get the first nibble as according to vpd. 4-7 is read, 0-3 for write
    l_preamble = l_preamble & 0x0F;

    FAPI_ASSERT( ((l_preamble == 0) || (l_preamble == 1)),
                 fapi2::MSS_INVALID_VPD_MT_PREAMBLE()
                 .set_VALUE(l_preamble)
                 .set_DIMM_TARGET(iv_dimm)
                 .set_MCS_TARGET(iv_mcs),
                 "Target %s VPD_MT_PREAMBLE is invalid (not 1 or 0), value is %d",
                 mss::c_str(iv_dimm),
                 l_preamble );

    // Using an if branch because a ternary conditional wasn't working with params for find_value_from_key
    if (l_preamble == 0)
    {
        FAPI_ASSERT( mss::find_value_from_key( CWL_TABLE_1,
                                               iv_freq,
                                               l_cwl),
                     fapi2::MSS_DRAM_CWL_ERROR()
                     .set_TARGET(iv_mca)
                     .set_FREQ(iv_freq)
                     .set_PREAMBLE(l_preamble),
                     "Failed finding CAS Write Latency (cwl), freq: %d, preamble %d",
                     iv_freq,
                     l_preamble);
    }
    else
    {
        FAPI_ASSERT( mss::find_value_from_key( CWL_TABLE_2,
                                               iv_freq,
                                               l_cwl),
                     fapi2::MSS_DRAM_CWL_ERROR()
                     .set_TARGET(iv_mca)
                     .set_FREQ(iv_freq)
                     .set_PREAMBLE(l_preamble),
                     "Failed finding CAS Write Latency (cwl), freq: %d, preamble %d",
                     iv_freq,
                     l_preamble);

    }

    FAPI_TRY( eff_dram_cwl(iv_mcs, l_attrs_cwl.data()) );
    l_attrs_cwl[iv_port_index] = l_cwl;

    FAPI_INF("Calculated CAS Write Latency is %d", l_cwl);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_CWL,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_cwl, PORTS_PER_MCS)),
              "Failed setting attribute for cwl");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for lpasr
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note from JEDEC DDR4 DRAM MR2 page 26
/// @note All DDR4 supports auto refresh, setting to default
///
fapi2::ReturnCode eff_dimm::dram_lpasr()
{
    // Retreive attribute
    std::vector<uint8_t> l_attrs_lpasr(PORTS_PER_MCS, 0);
    FAPI_TRY( eff_dram_lpasr(iv_mcs, l_attrs_lpasr.data()) );

    switch(iv_refresh_rate_request)
    {
        case fapi2::ENUM_ATTR_MSS_MRW_REFRESH_RATE_REQUEST_DOUBLE:
        case fapi2::ENUM_ATTR_MSS_MRW_REFRESH_RATE_REQUEST_DOUBLE_10_PERCENT_FASTER:
            l_attrs_lpasr[iv_port_index] =  fapi2::ENUM_ATTR_EFF_DRAM_LPASR_MANUAL_EXTENDED;
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_REFRESH_RATE_REQUEST_SINGLE:
        case fapi2::ENUM_ATTR_MSS_MRW_REFRESH_RATE_REQUEST_SINGLE_10_PERCENT_FASTER:
            l_attrs_lpasr[iv_port_index] =  fapi2::ENUM_ATTR_EFF_DRAM_LPASR_MANUAL_NORMAL;
            break;

        default:
            // Will catch incorrect MRW value set
            FAPI_ASSERT(false,
                        fapi2::MSS_INVALID_REFRESH_RATE_REQUEST().set_REFRESH_RATE_REQUEST(iv_refresh_rate_request),
                        "Incorrect refresh request rate received: %d for %s",
                        iv_refresh_rate_request, mss::c_str(iv_mcs));
            break;
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_LPASR,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_lpasr, PORTS_PER_MCS)),
              "Failed setting attribute for LPASR on %s", mss::c_str(iv_mcs));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for additive latency
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::additive_latency()
{
    std::vector<uint8_t> l_attrs_dram_al(PORTS_PER_MCS, 0);

    FAPI_TRY( eff_dram_al(iv_mcs, l_attrs_dram_al.data()) );

    l_attrs_dram_al[iv_port_index] = fapi2::ENUM_ATTR_EFF_DRAM_AL_DISABLE;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_AL,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_al, PORTS_PER_MCS)),
              "Failed setting attribute for DRAM_AL");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DLL Reset
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dll_reset()
{
    uint8_t l_attrs_dll_reset[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    FAPI_TRY( eff_dram_dll_reset(iv_mcs, &l_attrs_dll_reset[0][0]) );

    // Default is to reset DLLs during IPL.
    l_attrs_dll_reset[iv_port_index][iv_dimm_index] = fapi2::ENUM_ATTR_EFF_DRAM_DLL_RESET_YES;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_DLL_RESET, iv_mcs, l_attrs_dll_reset),
              "Failed setting attribute for BL");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DLL Enable
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dll_enable()
{
    uint8_t l_attrs_dll_enable[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    FAPI_TRY( eff_dram_dll_enable(iv_mcs, &l_attrs_dll_enable[0][0]) );

    // Enable DLLs by default.
    l_attrs_dll_enable[iv_port_index][iv_dimm_index] = fapi2::ENUM_ATTR_EFF_DRAM_DLL_ENABLE_YES;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_DLL_ENABLE, iv_mcs, l_attrs_dll_enable),
              "Failed setting attribute for BL");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for Write Level Enable
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::write_level_enable()
{
    std::vector<uint8_t> l_attrs_wr_lvl_enable(PORTS_PER_MCS, 0);

    FAPI_TRY( eff_dram_wr_lvl_enable(iv_mcs, l_attrs_wr_lvl_enable.data()) );

    l_attrs_wr_lvl_enable[iv_port_index] = fapi2::ENUM_ATTR_EFF_DRAM_WR_LVL_ENABLE_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_WR_LVL_ENABLE,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_wr_lvl_enable, PORTS_PER_MCS)),
              "Failed setting attribute for WR_LVL_ENABLE");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for Output Buffer
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::output_buffer()
{
    std::vector<uint8_t> l_attrs_output_buffer(PORTS_PER_MCS, 0);

    FAPI_TRY( eff_dram_output_buffer(iv_mcs, l_attrs_output_buffer.data()) );

    l_attrs_output_buffer[iv_port_index] = fapi2::ENUM_ATTR_EFF_DRAM_OUTPUT_BUFFER_ENABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_OUTPUT_BUFFER,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_output_buffer, PORTS_PER_MCS)),
              "Failed setting attribute for OUTPUT_BUFFER");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for Vref DQ Train Value and Range
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note The value and range attributes are combined as offsetting the WR VREF percentage can cause both the value and range to shift
/// The calculations would have to be done twice if the calculations were done separately. As such, they are combined below
///
fapi2::ReturnCode eff_dimm::vref_dq_train_value_and_range()
{
    // Taken from DDR4 (this attribute is DDR4 only) spec MRS6 section VrefDQ training: values table
    constexpr uint8_t JEDEC_MAX_TRAIN_VALUE   = 0b00110010;

    uint8_t l_attrs_vref_dq_train_val[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};
    uint8_t l_attrs_vref_dq_train_range[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};
    std::vector< uint64_t > l_ranks;

    // Gets the JEDEC VREFDQ range and value
    fapi2::buffer<uint8_t> l_train_value;
    fapi2::buffer<uint8_t> l_train_range;
    FAPI_TRY(mss::get_vpd_wr_vref_range_and_value(iv_dimm, l_train_range, l_train_value));

    FAPI_ASSERT(l_train_value <= JEDEC_MAX_TRAIN_VALUE,
                fapi2::MSS_INVALID_VPD_VREF_DRAM_WR_RANGE()
                .set_MAX(JEDEC_MAX_TRAIN_VALUE)
                .set_VALUE(l_train_value)
                .set_MCS_TARGET(iv_mcs),
                "%s VPD DRAM VREF value out of range max 0x%02x value 0x%02x", mss::c_str(iv_dimm),
                JEDEC_MAX_TRAIN_VALUE, l_train_value );

    // Updates the training values and ranges
    FAPI_TRY(mss::dp16::wr_vref::offset_values(iv_mca, l_train_range, l_train_value),
             "Failed to offset VPD WR VREF values %s", mss::c_str(iv_mca));


    // Attribute to set num dimm ranks is a pre-requisite
    FAPI_TRY( eff_vref_dq_train_value(iv_mcs, &l_attrs_vref_dq_train_val[0][0][0]) );
    FAPI_TRY( mss::rank::ranks(iv_dimm, l_ranks) );

    for(const auto& l_rank : l_ranks)
    {
        l_attrs_vref_dq_train_val[iv_port_index][iv_dimm_index][index(l_rank)] = l_train_value;
        l_attrs_vref_dq_train_range[iv_port_index][iv_dimm_index][index(l_rank)] = l_train_range;
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_VREF_DQ_TRAIN_VALUE, iv_mcs, l_attrs_vref_dq_train_val),
              "Failed setting attribute for ATTR_EFF_VREF_DQ_TRAIN_VALUE");

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_VREF_DQ_TRAIN_RANGE, iv_mcs, l_attrs_vref_dq_train_range),
              "Failed setting attribute for ATTR_EFF_VREF_DQ_TRAIN_RANGE");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for Vref DQ Train Value and Range
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_lrdimm::vref_dq_train_value_and_range()
{
    // Bits for range decode from the SPD
    constexpr uint8_t RANK0 = 7;
    constexpr uint8_t RANK1 = 6;
    constexpr uint8_t RANK2 = 5;
    constexpr uint8_t RANK3 = 4;
    uint8_t l_vref_dq_train_value[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};
    uint8_t l_vref_dq_train_range[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};
    fapi2::buffer<uint8_t > l_range;

    // Gets the attributes
    FAPI_TRY( eff_vref_dq_train_value(iv_mcs, &l_vref_dq_train_value[0][0][0]) );
    FAPI_TRY( eff_vref_dq_train_range(iv_mcs, &l_vref_dq_train_range[0][0][0]) );

    // Value is easy, just drop the values in from the SPD
    FAPI_TRY( iv_spd_decoder.dram_vref_dq_rank0(l_vref_dq_train_value[iv_port_index][iv_dimm_index][ATTR_RANK0]));
    FAPI_TRY( iv_spd_decoder.dram_vref_dq_rank1(l_vref_dq_train_value[iv_port_index][iv_dimm_index][ATTR_RANK1]));
    FAPI_TRY( iv_spd_decoder.dram_vref_dq_rank2(l_vref_dq_train_value[iv_port_index][iv_dimm_index][ATTR_RANK2]));
    FAPI_TRY( iv_spd_decoder.dram_vref_dq_rank3(l_vref_dq_train_value[iv_port_index][iv_dimm_index][ATTR_RANK3]));

    // Range requires some decoding
    FAPI_TRY( iv_spd_decoder.dram_vref_dq_range(l_range));

    // Do the decode for each rank
    l_vref_dq_train_range[iv_port_index][iv_dimm_index][ATTR_RANK0] = l_range.getBit<RANK0>() ?
            fapi2::ENUM_ATTR_EFF_VREF_DQ_TRAIN_RANGE_RANGE2 :
            fapi2::ENUM_ATTR_EFF_VREF_DQ_TRAIN_RANGE_RANGE1;

    l_vref_dq_train_range[iv_port_index][iv_dimm_index][ATTR_RANK1] = l_range.getBit<RANK1>() ?
            fapi2::ENUM_ATTR_EFF_VREF_DQ_TRAIN_RANGE_RANGE2 :
            fapi2::ENUM_ATTR_EFF_VREF_DQ_TRAIN_RANGE_RANGE1;

    l_vref_dq_train_range[iv_port_index][iv_dimm_index][ATTR_RANK2] = l_range.getBit<RANK2>() ?
            fapi2::ENUM_ATTR_EFF_VREF_DQ_TRAIN_RANGE_RANGE2 :
            fapi2::ENUM_ATTR_EFF_VREF_DQ_TRAIN_RANGE_RANGE1;

    l_vref_dq_train_range[iv_port_index][iv_dimm_index][ATTR_RANK3] = l_range.getBit<RANK3>() ?
            fapi2::ENUM_ATTR_EFF_VREF_DQ_TRAIN_RANGE_RANGE2 :
            fapi2::ENUM_ATTR_EFF_VREF_DQ_TRAIN_RANGE_RANGE1;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_VREF_DQ_TRAIN_VALUE, iv_mcs, l_vref_dq_train_value),
              "Failed setting attribute for ATTR_EFF_VREF_DQ_TRAIN_VALUE");

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_VREF_DQ_TRAIN_RANGE, iv_mcs, l_vref_dq_train_range),
              "Failed setting attribute for ATTR_EFF_VREF_DQ_TRAIN_RANGE");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for Vref DQ Train Enable
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::vref_dq_train_enable()
{
    // Default mode for train enable should be normal operation mode - 0x00
    static constexpr uint8_t NORMAL_MODE = 0x00;
    uint8_t l_attrs_vref_dq_train_enable[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};
    std::vector< uint64_t > l_ranks;

    // Attribute to set num dimm ranks is a pre-requisite
    FAPI_TRY( eff_vref_dq_train_enable(iv_mcs, &l_attrs_vref_dq_train_enable[0][0][0]) );
    FAPI_TRY( mss::rank::ranks(iv_dimm, l_ranks) );

    for(const auto& l_rank : l_ranks)
    {
        l_attrs_vref_dq_train_enable[iv_port_index][iv_dimm_index][index(l_rank)] = NORMAL_MODE;
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_VREF_DQ_TRAIN_ENABLE, iv_mcs, l_attrs_vref_dq_train_enable),
              "Failed setting attribute for ATTR_EFF_VREF_DQ_TRAIN_ENABLE");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for CA Parity Latency
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::ca_parity_latency()
{
    std::vector<uint8_t> l_attrs_ca_parity_latency(PORTS_PER_MCS, 0);

    FAPI_TRY( eff_ca_parity_latency(iv_mcs, l_attrs_ca_parity_latency.data()) );
    l_attrs_ca_parity_latency[iv_port_index] = fapi2::ENUM_ATTR_EFF_CA_PARITY_LATENCY_DISABLE;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_CA_PARITY_LATENCY,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_ca_parity_latency, PORTS_PER_MCS)),
              "Failed setting attribute for CA_PARITY_LATENCY");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for CRC Error Clear
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::crc_error_clear()
{
    std::vector<uint8_t> l_attrs_crc_error_clear(PORTS_PER_MCS, 0);

    FAPI_TRY( eff_crc_error_clear(iv_mcs, l_attrs_crc_error_clear.data()) );

    l_attrs_crc_error_clear[iv_port_index] = fapi2::ENUM_ATTR_EFF_CRC_ERROR_CLEAR_CLEAR;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_CRC_ERROR_CLEAR,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_crc_error_clear, PORTS_PER_MCS)),
              "Failed setting attribute for CRC_ERROR_CLEAR");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for CA Parity Error Status
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::ca_parity_error_status()
{
    std::vector<uint8_t> l_attrs_ca_parity_error_status(PORTS_PER_MCS, 0);

    FAPI_TRY( eff_ca_parity_error_status(iv_mcs, l_attrs_ca_parity_error_status.data()) );

    l_attrs_ca_parity_error_status[iv_port_index] = fapi2::ENUM_ATTR_EFF_CA_PARITY_ERROR_STATUS_CLEAR;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_CA_PARITY_ERROR_STATUS,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_ca_parity_error_status, PORTS_PER_MCS)),
              "Failed setting attribute for CA_PARITY_ERROR_STATUS");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for CA Parity
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::ca_parity()
{
    std::vector<uint8_t> l_attrs_ca_parity(PORTS_PER_MCS, 0);

    FAPI_TRY( eff_ca_parity(iv_mcs, l_attrs_ca_parity.data()) );

    l_attrs_ca_parity[iv_port_index] = fapi2::ENUM_ATTR_EFF_CA_PARITY_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_CA_PARITY,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_ca_parity, PORTS_PER_MCS)),
              "Failed setting attribute for CA_PARITY");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for ODT Input Buffer
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::odt_input_buffer()
{
    // keeping this value as 0x01, given that we know that that works in sim
    constexpr uint8_t SIM_VALUE = 0x01;
    std::vector<uint8_t> l_attrs_odt_input_buffer(PORTS_PER_MCS, 0);

    // Targets

    // keep simulation to values we know work
    uint8_t l_sim = 0;
    FAPI_TRY( mss::is_simulation(l_sim) );

    FAPI_TRY( eff_odt_input_buff(iv_mcs, l_attrs_odt_input_buffer.data()) );

    // sim vs actual hardware value
    l_attrs_odt_input_buffer[iv_port_index] = l_sim ? SIM_VALUE : fapi2::ENUM_ATTR_EFF_ODT_INPUT_BUFF_ACTIVATED;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_ODT_INPUT_BUFF,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_odt_input_buffer, PORTS_PER_MCS)),
              "Failed setting attribute for ODT_INPUT_BUFF");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for data_mask
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Datamask is unnused and not needed because no DBI.
/// @note Defaulted to 0
///
fapi2::ReturnCode eff_dimm::data_mask()
{
    std::vector<uint8_t> l_attrs_data_mask(PORTS_PER_MCS, 0);

    FAPI_TRY( eff_data_mask(iv_mcs, l_attrs_data_mask.data()) );

    l_attrs_data_mask[iv_port_index] = fapi2::ENUM_ATTR_EFF_DATA_MASK_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DATA_MASK,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_data_mask, PORTS_PER_MCS)),
              "Failed setting attribute for DATA_MASK");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for write_dbi
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note write_dbi is not supported, so set to DISABLED (0)
///
fapi2::ReturnCode eff_dimm::write_dbi()
{
    std::vector<uint8_t> l_attrs_write_dbi(PORTS_PER_MCS, 0);

    FAPI_TRY( eff_write_dbi(iv_mcs, l_attrs_write_dbi.data()) );

    l_attrs_write_dbi[iv_port_index] = fapi2::ENUM_ATTR_EFF_WRITE_DBI_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_WRITE_DBI,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_write_dbi, PORTS_PER_MCS)),
              "Failed setting attribute for WRITE_DBI");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for read_dbi
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note read_dbi is not supported, so set to DISABLED (0)
/// @note No logic for DBI
///
fapi2::ReturnCode eff_dimm::read_dbi()
{

    std::vector<uint8_t> l_attrs_read_dbi(PORTS_PER_MCS, 0);
    FAPI_TRY( eff_read_dbi(iv_mcs, l_attrs_read_dbi.data()) );

    l_attrs_read_dbi[iv_port_index] = fapi2::ENUM_ATTR_EFF_READ_DBI_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_READ_DBI,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_read_dbi, PORTS_PER_MCS)),
              "Failed setting attribute for READ_DBI");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for Post Package Repair
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::post_package_repair()
{

    uint8_t l_decoder_val = 0;
    uint8_t l_attrs_dram_ppr[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    FAPI_TRY( eff_dram_ppr(iv_mcs, &l_attrs_dram_ppr[0][0]) );
    FAPI_TRY( iv_spd_decoder.post_package_repair(l_decoder_val) );

    l_attrs_dram_ppr[iv_port_index][iv_dimm_index] = l_decoder_val;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_PPR, iv_mcs, l_attrs_dram_ppr),
              "Failed setting attribute for DRAM_PPR");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for soft post package repair
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::soft_post_package_repair()
{
    uint8_t l_sppr_decoder_val = 0;
    uint8_t l_rev_decoder_val = 0;

    uint8_t l_sppr = 0;
    uint8_t l_attrs_dram_soft_ppr[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    FAPI_TRY( eff_dram_soft_ppr(iv_mcs, &l_attrs_dram_soft_ppr[0][0]) );

    FAPI_TRY( iv_spd_decoder.soft_post_package_repair(l_sppr_decoder_val) );
    FAPI_TRY( iv_spd_decoder.revision(l_rev_decoder_val) );

    if(l_rev_decoder_val == spd::rev::V1_0 &&
       l_sppr_decoder_val == fapi2::ENUM_ATTR_EFF_DRAM_SOFT_PPR_SUPPORTED)
    {
        // Lab observes DIMMs that are SPD rev 1.0 but have sPPR enabled that is considered
        // invalid per the SPD spec.  For backward compatability of those DIMMs (known past vendor issue)
        // we set it to a valid value.
        FAPI_INF("Invalid sPPR (0x%02x) for SPD rev 0x%02x on %s.  Setting sPPR to 0x%02x",
                 l_sppr_decoder_val, l_rev_decoder_val, mss::c_str(iv_dimm),
                 fapi2::ENUM_ATTR_EFF_DRAM_SOFT_PPR_NOT_SUPPORTED);

        l_sppr_decoder_val = fapi2::ENUM_ATTR_EFF_DRAM_SOFT_PPR_NOT_SUPPORTED;
    }

    FAPI_ASSERT( mss::find_value_from_key(SOFT_PPR_MAP, l_sppr_decoder_val, l_sppr),
                 fapi2::MSS_LOOKUP_FAILED()
                 .set_KEY(l_sppr_decoder_val)
                 .set_DATA(l_sppr)
                 .set_FUNCTION(SOFT_POST_PACKAGE_REPAIR)
                 .set_TARGET(iv_dimm),
                 "Could not find a mapped value that matched the key (%d) for %s",
                 l_sppr_decoder_val, mss::c_str(iv_dimm) );

    l_attrs_dram_soft_ppr[iv_port_index][iv_dimm_index] = l_sppr;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_SOFT_PPR, iv_mcs, l_attrs_dram_soft_ppr),
              "Failed setting attribute for DRAM_SOFT_PPR");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for rd_preamble_train
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::read_preamble_train()
{
    std::vector<uint8_t> l_attrs_rd_preamble_train(PORTS_PER_MCS, 0);
    FAPI_TRY( eff_rd_preamble_train(iv_mcs, l_attrs_rd_preamble_train.data()) );

    l_attrs_rd_preamble_train[iv_port_index] = fapi2::ENUM_ATTR_EFF_RD_PREAMBLE_TRAIN_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_RD_PREAMBLE_TRAIN,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_rd_preamble_train, PORTS_PER_MCS)),
              "Failed setting attribute for RD_PREAMBLE_TRAIN");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for rd_preamble
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::read_preamble()
{
    std::vector<uint8_t> l_attrs_rd_preamble(PORTS_PER_MCS, 0);
    uint8_t l_preamble = 0;

    FAPI_TRY( vpd_mt_preamble (iv_mca, l_preamble) ) ;
    l_preamble = l_preamble & 0xF0;
    l_preamble = l_preamble >> 4;


    FAPI_ASSERT( ((l_preamble == 0) || (l_preamble == 1)),
                 fapi2::MSS_INVALID_VPD_MT_PREAMBLE()
                 .set_VALUE(l_preamble)
                 .set_DIMM_TARGET(iv_mca)
                 .set_MCS_TARGET(iv_mcs),
                 "Target %s VPD_MT_PREAMBLE is invalid (not 1 or 0), value is %d",
                 mss::c_str(iv_dimm),
                 l_preamble );

    FAPI_TRY( eff_rd_preamble(iv_mcs, l_attrs_rd_preamble.data()) );

    l_attrs_rd_preamble[iv_port_index] = l_preamble;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_RD_PREAMBLE,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_rd_preamble, PORTS_PER_MCS)),
              "Failed setting attribute for RD_PREAMBLE");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for wr_preamble
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::write_preamble()
{
    std::vector<uint8_t> l_attrs_wr_preamble(PORTS_PER_MCS, 0);
    uint8_t l_preamble = 0;

    FAPI_TRY( vpd_mt_preamble (iv_mca, l_preamble) ) ;
    l_preamble = l_preamble & 0x0F;
    FAPI_INF("WR preamble is %d", l_preamble);

    FAPI_ASSERT( ((l_preamble == 0) || (l_preamble == 1)),
                 fapi2::MSS_INVALID_VPD_MT_PREAMBLE()
                 .set_VALUE(l_preamble)
                 .set_DIMM_TARGET(iv_mca)
                 .set_MCS_TARGET(iv_mcs),
                 "Target %s VPD_MT_PREAMBLE is invalid (not 1 or 0), value is %d",
                 mss::c_str(iv_dimm),
                 l_preamble );

    FAPI_TRY( eff_wr_preamble(iv_mcs, l_attrs_wr_preamble.data()) );

    l_attrs_wr_preamble[iv_port_index] = l_preamble;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_WR_PREAMBLE,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_wr_preamble, PORTS_PER_MCS)),
              "Failed setting attribute for RD_PREAMBLE");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for self_ref_abort
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::self_refresh_abort()
{
    std::vector<uint8_t> l_attrs_self_ref_abort(PORTS_PER_MCS, 0);

    FAPI_TRY( eff_self_ref_abort(iv_mcs, l_attrs_self_ref_abort.data()) );

    l_attrs_self_ref_abort[iv_port_index] = fapi2::ENUM_ATTR_EFF_SELF_REF_ABORT_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_SELF_REF_ABORT,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_self_ref_abort, PORTS_PER_MCS)),
              "Failed setting attribute for SELF_REF_ABORT");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for cs_cmd_latency
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::cs_to_cmd_addr_latency()
{
    std::vector<uint8_t> l_attrs_cs_cmd_latency(PORTS_PER_MCS, 0);

    FAPI_TRY( eff_cs_cmd_latency(iv_mcs, l_attrs_cs_cmd_latency.data()) );

    l_attrs_cs_cmd_latency[iv_port_index] = fapi2::ENUM_ATTR_EFF_CS_CMD_LATENCY_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_CS_CMD_LATENCY,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_cs_cmd_latency, PORTS_PER_MCS)),
              "Failed setting attribute for CS_CMD_LATENCY");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for int_vref_mon
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::internal_vref_monitor()
{
    std::vector<uint8_t> l_attrs_int_vref_mon(PORTS_PER_MCS, 0);

    FAPI_TRY( eff_internal_vref_monitor(iv_mcs, l_attrs_int_vref_mon.data()) );

    l_attrs_int_vref_mon[iv_port_index] = fapi2::ENUM_ATTR_EFF_INTERNAL_VREF_MONITOR_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_INTERNAL_VREF_MONITOR,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_int_vref_mon, PORTS_PER_MCS)),
              "Failed setting attribute for INT_VREF_MON");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for powerdown_mode
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::max_powerdown_mode()
{
    std::vector<uint8_t> l_attrs_powerdown_mode(PORTS_PER_MCS, 0);

    FAPI_TRY( eff_max_powerdown_mode(iv_mcs, l_attrs_powerdown_mode.data()) );

    l_attrs_powerdown_mode[iv_port_index] = fapi2::ENUM_ATTR_EFF_MAX_POWERDOWN_MODE_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_MAX_POWERDOWN_MODE,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_powerdown_mode, PORTS_PER_MCS)),
              "Failed setting attribute for POWERDOWN_MODE");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for mpr_rd_format
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::mpr_read_format()
{
    std::vector<uint8_t> l_attrs_mpr_rd_format(PORTS_PER_MCS, 0);

    FAPI_TRY( eff_mpr_rd_format(iv_mcs, l_attrs_mpr_rd_format.data()) );

    // Serial format is standard for Nimbus and needed for PHY calibration (draminit_training)
    l_attrs_mpr_rd_format[iv_port_index] = fapi2::ENUM_ATTR_EFF_MPR_RD_FORMAT_SERIAL;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_MPR_RD_FORMAT,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_mpr_rd_format, PORTS_PER_MCS)),
              "Failed setting attribute for MPR_RD_FORMAT");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for CRC write latency
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::crc_wr_latency()
{
    std::vector<uint8_t> l_attrs_crc_wr_latency(PORTS_PER_MCS, 0);

    // keep simulation to values we know work
    uint8_t l_sim = 0;
    FAPI_TRY( mss::is_simulation(l_sim) );

    FAPI_TRY( eff_crc_wr_latency(iv_mcs, l_attrs_crc_wr_latency.data()) );

    // keep simulation to values we know work
    if(l_sim)
    {
        l_attrs_crc_wr_latency[iv_port_index] = 0x05;
    }
    // set the attribute according to frequency
    else
    {
        // TODO RTC:159481 - update CRC write latency to include 2667
        // currently, JEDEC defines the following
        // crc wr latency - freq
        // 4              - 1600
        // 5              - 1866, 2133, 2400
        // 6              - TBD
        // Nimbus only supports 1866->2400 on the current list
        // 2667 is not noted. We will set crc_wr_latency to 0x05 until JEDEC value is updated
        // When JEDEC defines the 2667 value we can change this, but leave the sim value as 0x05
        l_attrs_crc_wr_latency[iv_port_index] = 0x05;
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_CRC_WR_LATENCY,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_crc_wr_latency, PORTS_PER_MCS)),
              "Failed setting attribute for CRC WRITE LATENCY");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for temperature readout
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::temp_readout()
{
    std::vector<uint8_t> l_attrs_temp_readout(PORTS_PER_MCS, 0);

    FAPI_TRY( eff_temp_readout(iv_mcs, l_attrs_temp_readout.data()) );

    // Disabled for mainline mode
    l_attrs_temp_readout[iv_port_index] = fapi2::ENUM_ATTR_EFF_TEMP_READOUT_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_TEMP_READOUT,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_temp_readout, PORTS_PER_MCS)),
              "Failed setting attribute for TEMP_READOUT");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for per DRAM addressability
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::per_dram_addressability()
{
    std::vector<uint8_t> l_attrs_per_dram_access(PORTS_PER_MCS, 0);

    FAPI_TRY( eff_per_dram_access(iv_mcs, l_attrs_per_dram_access.data()) );

    // PDA is disabled in mainline functionality
    l_attrs_per_dram_access[iv_port_index] = fapi2::ENUM_ATTR_EFF_PER_DRAM_ACCESS_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_PER_DRAM_ACCESS,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_per_dram_access, PORTS_PER_MCS)),
              "Failed setting attribute for PER_DRAM_ACCESS");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for geardown mode
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::geardown_mode()
{
    std::vector<uint8_t> l_attrs_geardown_mode(PORTS_PER_MCS, 0);

    // Geardown maps directly to autoset = 0 gets 1/2 rate, 1 get 1/4 rate.
    FAPI_TRY( eff_geardown_mode(iv_mcs, l_attrs_geardown_mode.data()) );

    // If the MRW states 'auto' we use what's in VPD, otherwise we use what's in the MRW.
    // We remove 1 from the value as that matches the expectations in the MR perfectly.
    l_attrs_geardown_mode[iv_port_index] = mss::two_n_mode_helper(iv_dimm);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_GEARDOWN_MODE,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_geardown_mode, PORTS_PER_MCS)),
              "Failed setting attribute for GEARDOWN_MODE");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for MPR page
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::mpr_page()
{
    std::vector<uint8_t> l_attrs_mpr_page(PORTS_PER_MCS, 0);

    FAPI_TRY( eff_mpr_page(iv_mcs, l_attrs_mpr_page.data()) );

    // page0 is needed for PHY calibration algorithm (run in draminit_training)
    l_attrs_mpr_page[iv_port_index] = fapi2::ENUM_ATTR_EFF_MPR_PAGE_PG0;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_MPR_PAGE,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_mpr_page, PORTS_PER_MCS)),
              "Failed setting attribute for MPR_PAGE");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for MPR mode
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::mpr_mode()
{
    std::vector<uint8_t> l_attrs_mpr_mode(PORTS_PER_MCS, 0);

    FAPI_TRY( eff_mpr_mode(iv_mcs, l_attrs_mpr_mode.data()) );

    // MPR mode is disabled for mainline functionality
    l_attrs_mpr_mode[iv_port_index] = fapi2::ENUM_ATTR_EFF_MPR_MODE_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_MPR_MODE,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_mpr_mode, PORTS_PER_MCS)),
              "Failed setting attribute for MPR_MODE");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for write CRC
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::write_crc()
{
    std::vector<uint8_t> l_attrs_write_crc(PORTS_PER_MCS, 0);

    uint8_t l_mrw = 0;

    FAPI_TRY( eff_write_crc(iv_mcs, l_attrs_write_crc.data()) );
    FAPI_TRY( mrw_dram_write_crc(l_mrw) );

    l_attrs_write_crc[iv_port_index] = (l_mrw == fapi2::ENUM_ATTR_MSS_MRW_DRAM_WRITE_CRC_ENABLE) ?
                                       fapi2::ENUM_ATTR_EFF_WRITE_CRC_ENABLE :
                                       fapi2::ENUM_ATTR_EFF_WRITE_CRC_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_WRITE_CRC,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_write_crc, PORTS_PER_MCS)),
              "Failed setting attribute for WRITE_CRC");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for ZQ Calibration
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::zqcal_interval()
{
    std::vector<uint32_t> l_attrs_zqcal_interval(PORTS_PER_MCS, 0);

    FAPI_TRY( eff_zqcal_interval(iv_mcs, l_attrs_zqcal_interval.data()) );

    // Calculate ZQCAL Interval based on the following equation from Ken:
    //               0.5
    // ------------------------------ = 13.333ms
    //     (1.5 * 10) + (0.15 * 150)
    //  (13333 * ATTR_MSS_FREQ) / 2

    l_attrs_zqcal_interval[iv_port_index] = 13333 * iv_freq / 2;


    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_ZQCAL_INTERVAL,
                            iv_mcs,
                            UINT32_VECTOR_TO_1D_ARRAY(l_attrs_zqcal_interval, PORTS_PER_MCS)),
              "Failed setting attribute for ZQCAL_INTERVAL");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for MEMCAL Calibration
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::memcal_interval()
{
    std::vector<uint32_t> l_attrs_memcal_interval(PORTS_PER_MCS, 0);

    FAPI_TRY( eff_memcal_interval(iv_mcs, l_attrs_memcal_interval.data()) );

    // Calculate MEMCAL Interval based on 1sec interval across all bits per DP16
    // (62500 * ATTR_MSS_FREQ) / 2
    l_attrs_memcal_interval[iv_port_index] = 62500 * iv_freq / 2;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_MEMCAL_INTERVAL,
                            iv_mcs,
                            UINT32_VECTOR_TO_1D_ARRAY(l_attrs_memcal_interval, PORTS_PER_MCS)),
              "Failed setting attribute for MEMCAL_INTERVAL");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tRP
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dram_trp()
{

    int64_t l_trp_in_ps = 0;

    // Calculate tRP (in ps)
    {
        int64_t l_trp_mtb = 0;
        int64_t l_trp_ftb = 0;

        FAPI_TRY( iv_spd_decoder.min_trp(l_trp_mtb),
                  "Failed min_trp() for %s", mss::c_str(iv_dimm) );

        FAPI_TRY( iv_spd_decoder.fine_offset_min_trp(l_trp_ftb),
                  "Failed fine_offset_min_trp() for %s", mss::c_str(iv_dimm) );

        FAPI_INF("%s medium timebase (ps): %ld, fine timebase (ps): %ld, tRP (MTB): %ld, tRP(FTB): %ld",
                 mss::c_str(iv_dimm), iv_mtb, iv_ftb, l_trp_mtb, l_trp_ftb);

        l_trp_in_ps = spd::calc_timing_from_timebase(l_trp_mtb, iv_mtb, l_trp_ftb, iv_ftb);
    }

    // SPD spec gives us the minimum... compute our worstcase (maximum) from JEDEC
    {
        // Declaring as int64_t to fix std::max compile
        const int64_t l_trp = mss::ps_to_cycles(iv_dimm, mss::trtp());
        l_trp_in_ps = std::max( l_trp_in_ps , l_trp );
    }

    {
        std::vector<uint8_t> l_attrs_dram_trp(PORTS_PER_MCS, 0);
        uint8_t l_trp_in_nck = 0;

        // Calculate nck
        FAPI_TRY( spd::calc_nck(l_trp_in_ps, iv_tCK_in_ps, spd::INVERSE_DDR4_CORRECTION_FACTOR, l_trp_in_nck),
                  "Error in calculating dram_tRP nck for target %s, with value of l_trp_in_ps: %d", mss::c_str(iv_dimm), l_trp_in_ps);

        FAPI_INF( "tCK (ps): %d, tRP (ps): %d, tRP (nck): %d for target: %s",
                  iv_tCK_in_ps, l_trp_in_ps, l_trp_in_nck, mss::c_str(iv_dimm) );

        // Get & update MCS attribute
        FAPI_TRY( eff_dram_trp(iv_mcs, l_attrs_dram_trp.data()) );

        // DIMM's can have separate timings in a dual-drop system.
        // In those cases, we want to take the safest (most pessimistic) values
        l_attrs_dram_trp[iv_port_index] = std::max(l_trp_in_nck, l_attrs_dram_trp[iv_port_index]);
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRP,
                                iv_mcs,
                                UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_trp, PORTS_PER_MCS)),
                  "Failed setting attribute for DRAM_TRP");
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tRCD
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dram_trcd()
{
    int64_t l_trcd_in_ps = 0;

    // Calculate tRCD (in ps)
    // Get the tRCD timing values
    // tRCD is speed bin dependent and has a unique
    // value for each speed bin so it is safe to
    // read from SPD because the correct nck
    // value will be calulated based on our dimm speed.
    {
        int64_t l_trcd_mtb = 0;
        int64_t l_trcd_ftb = 0;

        FAPI_TRY( iv_spd_decoder.min_trcd(l_trcd_mtb),
                  "Failed min_trcd() for %s", mss::c_str(iv_dimm) );

        FAPI_TRY( iv_spd_decoder.fine_offset_min_trcd(l_trcd_ftb),
                  "Failed fine_offset_min_trcd() for %s", mss::c_str(iv_dimm) );

        FAPI_INF("%s medium timebase MTB (ps): %ld, fine timebase FTB (ps): %ld, tRCD (MTB): %ld, tRCD (FTB): %ld",
                 mss::c_str(iv_dimm), iv_mtb, iv_ftb, l_trcd_mtb, l_trcd_ftb);

        l_trcd_in_ps = spd::calc_timing_from_timebase(l_trcd_mtb, iv_mtb, l_trcd_ftb, iv_ftb);
    }

    {
        std::vector<uint8_t> l_attrs_dram_trcd(PORTS_PER_MCS, 0);
        uint8_t l_trcd_in_nck = 0;

        // Calculate nck
        FAPI_TRY( spd::calc_nck(l_trcd_in_ps, iv_tCK_in_ps, spd::INVERSE_DDR4_CORRECTION_FACTOR, l_trcd_in_nck),
                  "Error in calculating trcd for target %s, with value of l_trcd_in_ps: %d", mss::c_str(iv_dimm), l_trcd_in_ps);

        FAPI_INF("tCK (ps): %d, tRCD (ps): %d, tRCD (nck): %d for target: %s",
                 iv_tCK_in_ps, l_trcd_in_ps, l_trcd_in_nck, mss::c_str(iv_dimm));

        // Get & update MCS attribute
        FAPI_TRY( eff_dram_trcd(iv_mcs, l_attrs_dram_trcd.data()) );

        // DIMM's can have separate timings in a dual-drop system.
        // In those cases, we want to take the safest (most pessimistic) values
        l_attrs_dram_trcd[iv_port_index] = std::max(l_trcd_in_nck, l_attrs_dram_trcd[iv_port_index]);
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRCD,
                                iv_mcs,
                                UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_trcd, PORTS_PER_MCS)),
                  "Failed setting attribute for DRAM_TRCD");
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tRC
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dram_trc()
{
    int64_t l_trc_in_ps = 0;

    // Calculate trc (in ps)
    {
        int64_t l_trc_mtb = 0;
        int64_t l_trc_ftb = 0;

        FAPI_TRY( iv_spd_decoder.min_trc(l_trc_mtb),
                  "Failed min_trc() for %s", mss::c_str(iv_dimm) );

        FAPI_TRY( iv_spd_decoder.fine_offset_min_trc(l_trc_ftb),
                  "Failed fine_offset_min_trc() for %s", mss::c_str(iv_dimm) );

        FAPI_INF("%s medium timebase MTB (ps): %ld, fine timebase FTB (ps): %ld, tRCmin (MTB): %ld, tRCmin(FTB): %ld",
                 mss::c_str(iv_dimm), iv_mtb, iv_ftb, l_trc_mtb, l_trc_ftb);

        l_trc_in_ps = spd::calc_timing_from_timebase(l_trc_mtb, iv_mtb, l_trc_ftb, iv_ftb);
    }

    {
        std::vector<uint8_t> l_attrs_dram_trc(PORTS_PER_MCS, 0);
        uint8_t l_trc_in_nck = 0;

        // Calculate nck
        FAPI_TRY( spd::calc_nck(l_trc_in_ps, iv_tCK_in_ps, spd::INVERSE_DDR4_CORRECTION_FACTOR, l_trc_in_nck),
                  "Error in calculating trc for target %s, with value of l_trc_in_ps: %d",
                  mss::c_str(iv_dimm), l_trc_in_ps );

        FAPI_INF( "tCK (ps): %d, tRC (ps): %d, tRC (nck): %d for target: %s",
                  iv_tCK_in_ps, l_trc_in_ps, l_trc_in_nck, mss::c_str(iv_dimm) );

        // Get & update MCS attribute
        FAPI_TRY( eff_dram_trc(iv_mcs, l_attrs_dram_trc.data()) );

        // DIMM's can have separate timings in a dual-drop system.
        // In those cases, we want to take the safest (most pessimistic) values
        l_attrs_dram_trc[iv_port_index] = std::max(l_trc_in_nck, l_attrs_dram_trc[iv_port_index]);
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRC,
                                iv_mcs,
                                UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_trc, PORTS_PER_MCS)),
                  "Failed setting attribute for DRAM_TRC");
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tWTR_L
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dram_twtr_l()
{
    int64_t l_twtr_l_in_ps = 0;

    // Calculate twtr_l (in ps)
    {
        constexpr int64_t l_twtr_l_ftb = 0;
        int64_t l_twtr_l_mtb = 0;

        FAPI_TRY( iv_spd_decoder.min_twtr_l(l_twtr_l_mtb) );

        FAPI_INF("%s medium timebase (ps): %ld, fine timebase (ps): %ld, tWTR_S (MTB): %ld, tWTR_S (FTB): %ld",
                 mss::c_str(iv_dimm), iv_mtb, iv_ftb, l_twtr_l_mtb, l_twtr_l_ftb );

        l_twtr_l_in_ps = spd::calc_timing_from_timebase(l_twtr_l_mtb, iv_mtb, l_twtr_l_ftb, iv_ftb);
    }


    {
        std::vector<uint8_t> l_attrs_dram_twtr_l(PORTS_PER_MCS, 0);
        int8_t l_twtr_l_in_nck = 0;

        // Calculate nck
        FAPI_TRY( spd::calc_nck(l_twtr_l_in_ps, iv_tCK_in_ps, spd::INVERSE_DDR4_CORRECTION_FACTOR, l_twtr_l_in_nck),
                  "Error in calculating tWTR_L for target %s, with value of l_twtr_in_ps: %d", mss::c_str(iv_dimm), l_twtr_l_in_ps );

        FAPI_INF( "tCK (ps): %d,  tWTR_L (ps): %d, tWTR_L (nck): %d for target: %s",
                  iv_tCK_in_ps, l_twtr_l_in_ps, l_twtr_l_in_nck, mss::c_str(iv_dimm) );

        // Get & update MCS attribute
        FAPI_TRY( eff_dram_twtr_l(iv_mcs, l_attrs_dram_twtr_l.data()) );

        // DIMM's can have separate timings in a dual-drop system.
        // In those cases, we want to take the safest (most pessimistic) values
        l_attrs_dram_twtr_l[iv_port_index] = std::max(static_cast<uint8_t>(l_twtr_l_in_nck),
                                             l_attrs_dram_twtr_l[iv_port_index]);
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TWTR_L,
                                iv_mcs,
                                UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_twtr_l, PORTS_PER_MCS)),
                  "Failed setting attribute for DRAM_TWTR_L");
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tWTR_S
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dram_twtr_s()
{
    int64_t l_twtr_s_in_ps = 0;

    // Calculate twtr_s (in ps)
    {
        constexpr int64_t l_twtr_s_ftb = 0;
        int64_t l_twtr_s_mtb = 0;

        FAPI_TRY( iv_spd_decoder.min_twtr_s(l_twtr_s_mtb) );

        FAPI_INF("%s medium timebase (ps): %ld, fine timebase (ps): %ld, tWTR_S (MTB): %ld, tWTR_S (FTB): %ld",
                 mss::c_str(iv_dimm), iv_mtb, iv_ftb, l_twtr_s_mtb, l_twtr_s_ftb );

        l_twtr_s_in_ps = spd::calc_timing_from_timebase(l_twtr_s_mtb, iv_mtb, l_twtr_s_ftb, iv_ftb);
    }

    {
        std::vector<uint8_t> l_attrs_dram_twtr_s(PORTS_PER_MCS, 0);
        uint8_t l_twtr_s_in_nck = 0;

        // Calculate nck
        FAPI_TRY( spd::calc_nck(l_twtr_s_in_ps, iv_tCK_in_ps, spd::INVERSE_DDR4_CORRECTION_FACTOR, l_twtr_s_in_nck),
                  "Error in calculating tWTR_S for target %s, with value of l_twtr_in_ps: %d", mss::c_str(iv_dimm), l_twtr_s_in_ps);

        FAPI_INF("tCK (ps): %d, tWTR_S (ps): %d, tWTR_S (nck): %d for target: %s",
                 iv_tCK_in_ps, l_twtr_s_in_ps, l_twtr_s_in_nck, mss::c_str(iv_dimm) );

        // Get & update MCS attribute
        FAPI_TRY( eff_dram_twtr_s(iv_mcs, l_attrs_dram_twtr_s.data()) );

        // DIMM's can have separate timings in a dual-drop system.
        // In those cases, we want to take the safest (most pessimistic) values
        l_attrs_dram_twtr_s[iv_port_index] = std::max(l_twtr_s_in_nck, l_attrs_dram_twtr_s[iv_port_index]);
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TWTR_S,
                                iv_mcs,
                                UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_twtr_s, PORTS_PER_MCS)),
                  "Failed setting attribute for DRAM_TWTR_S");
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for nibble
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::nibble_map()
{
    uint8_t l_attr[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_DQ_NIBBLES] = {};

    std::vector<uint8_t> l_nibble_bitmap;
    FAPI_TRY( iv_spd_decoder.nibble_map(l_nibble_bitmap) );

    // Sanity check we retrieved a vector w/the right size
    FAPI_ASSERT( l_nibble_bitmap.size() == MAX_DQ_NIBBLES,
                 fapi2::MSS_UNEXPECTED_VALUE_SEEN().
                 set_TARGET(iv_dimm).
                 set_EXPECTED(MAX_DQ_NIBBLES).
                 set_ACTUAL(l_nibble_bitmap.size()).
                 set_FUNCTION(NIBBLE_MAP_FUNC),
                 "Expected vector size %d, actual size %d for %s",
                 MAX_DQ_NIBBLES, l_nibble_bitmap.size(), mss::c_str(iv_dimm) );

    // Get & update MCS attribute
    FAPI_TRY( eff_nibble_map(iv_mcs, &l_attr[0][0][0]) );

    memcpy(&(l_attr[iv_port_index][iv_dimm_index][0]), l_nibble_bitmap.data(), MAX_DQ_NIBBLES);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_NIBBLE_MAP, iv_mcs, l_attr),
              "Failed setting attribute ATTR_EFF_NIBBLE_MAP for %s", mss::c_str(iv_mcs));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for the package rank map
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::package_rank_map()
{
    uint8_t l_attr[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_DQ_NIBBLES] = {};

    std::vector<uint8_t> l_package_rank_map;
    FAPI_TRY( iv_spd_decoder.package_rank_map(l_package_rank_map) );

    // Sanity check we retrieved a vector w/the right size
    FAPI_ASSERT( l_package_rank_map.size() == MAX_DQ_NIBBLES,
                 fapi2::MSS_UNEXPECTED_VALUE_SEEN().
                 set_TARGET(iv_dimm).
                 set_EXPECTED(MAX_DQ_NIBBLES).
                 set_ACTUAL(l_package_rank_map.size()).
                 set_FUNCTION(PACKAGE_RANK_MAP_FUNC),
                 "Expected vector size %d, actual size %d for %s",
                 MAX_DQ_NIBBLES, l_package_rank_map.size(), mss::c_str(iv_dimm) );

    // Get & update MCS attribute
    FAPI_TRY( eff_package_rank_map(iv_mcs, &l_attr[0][0][0]) );

    memcpy(&(l_attr[iv_port_index][iv_dimm_index][0]), l_package_rank_map.data(), MAX_DQ_NIBBLES);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_PACKAGE_RANK_MAP, iv_mcs, l_attr),
              "Failed setting attribute ATTR_EFF_PACKAGE_RANK_MAP for %s", mss::c_str(iv_mcs));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for the wr_crc
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @warning eff_package_rank_map must be set before calling this method
///
fapi2::ReturnCode eff_dimm::wr_crc()
{
    uint8_t l_attr[PORTS_PER_MCS] = {};

    // Get & update MCS attribute
    FAPI_TRY( eff_wr_crc(iv_mcs, &l_attr[0]) );

    // By default write CRC will be disabled. For us to actually enable it in a product,
    // we'd have to be taking more bit flips on the write data interface than scrub can keep up with,
    // plus we'd have to take the performance hit of enabling it... so pretty high bar to enable it.
    l_attr[iv_port_index] = fapi2::ENUM_ATTR_MSS_EFF_WR_CRC_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EFF_WR_CRC, iv_mcs, l_attr),
              "Failed setting attribute ATTR_MSS_EFF_WR_CRC for %s", mss::c_str(iv_mcs));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tRRD_S
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dram_trrd_s()
{
    std::vector<uint8_t> l_attrs_dram_trrd_s(PORTS_PER_MCS, 0);
    uint64_t l_trrd_s_in_nck = 0;
    int64_t l_trrd_s_in_ps = 0;
    uint64_t l_jedec_trrd = 0;

    // Calculate tRRD_S
    {
        int64_t l_trrd_s_mtb = 0;
        int64_t l_trrd_s_ftb = 0;

        FAPI_TRY( iv_spd_decoder.min_trrd_s(l_trrd_s_mtb),
                  "Failed min_trrd_s() for %s", mss::c_str(iv_dimm) );

        FAPI_TRY( iv_spd_decoder.fine_offset_min_trrd_s(l_trrd_s_ftb),
                  "Failed fine_offset_min_trrd_s() for %s", mss::c_str(iv_dimm) );

        FAPI_INF("%s medium timebase (ps): %ld, fine timebase (ps): %ld, trrd_s (MTB): %ld",
                 mss::c_str(iv_dimm), iv_mtb, iv_ftb, l_trrd_s_mtb);

        l_trrd_s_in_ps = spd::calc_timing_from_timebase(l_trrd_s_mtb, iv_mtb, l_trrd_s_ftb, iv_ftb);

        FAPI_ASSERT( l_trrd_s_in_ps >= 0,
                     fapi2::MSS_INVALID_TIMING_VALUE()
                     .set_VALUE(l_trrd_s_in_ps)
                     .set_DIMM_TARGET(iv_dimm)
                     .set_FUNCTION(TRRD_S),
                     "%s Error calculating tRRD_S (%d). Less than or equal to 0",
                     mss::c_str(iv_dimm),
                     l_trrd_s_in_ps);

        FAPI_DBG("TRRD_S in ps is %d", l_trrd_s_in_ps);

        FAPI_TRY( spd::calc_nck(l_trrd_s_in_ps, iv_tCK_in_ps, spd::INVERSE_DDR4_CORRECTION_FACTOR, l_trrd_s_in_nck),
                  "Error in calculating l_tFAW for target %s, with value of l_trrd_s_in_ps: %d",
                  mss::c_str(iv_dimm),
                  l_trrd_s_in_nck);
    }

    FAPI_TRY( trrd_s( iv_dimm, iv_dram_width, iv_freq, l_jedec_trrd) );

    // Taking the worst case between the required minimum JEDEC value and the proposed value from SPD
    if (l_jedec_trrd != l_trrd_s_in_nck)
    {
        FAPI_INF("%s TRRD_S from JEDEC (%d) and from SPD (%d) don't match. Choosing worst case. dram width %d, freq %d",
                 mss::c_str(iv_dimm),
                 l_jedec_trrd,
                 l_trrd_s_in_nck,
                 iv_dram_width,
                 iv_freq);

        l_trrd_s_in_nck = std::max( l_jedec_trrd, l_trrd_s_in_nck);
    }

    FAPI_INF("SDRAM width: %d, tFAW (nck): %d for target: %s",
             iv_dram_width, l_trrd_s_in_nck, mss::c_str(iv_dimm));

    // Get & update MCS attribute
    FAPI_TRY( eff_dram_trrd_s(iv_mcs, l_attrs_dram_trrd_s.data()) );


    // DIMM's can have separate timings in a dual-drop system.
    // In those cases, we want to take the safest (most pessimistic) values
    l_attrs_dram_trrd_s[iv_port_index] = std::max(static_cast<uint8_t>(l_trrd_s_in_nck),
                                         l_attrs_dram_trrd_s[iv_port_index]);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRRD_S,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_trrd_s, PORTS_PER_MCS)),
              "Failed setting attribute for DRAM_TRRD_S");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tRRD_L
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dram_trrd_l()
{
    std::vector<uint8_t> l_attrs_dram_trrd_l(PORTS_PER_MCS, 0);
    uint64_t l_trrd_l_in_nck = 0;
    int64_t l_trrd_l_in_ps = 0;
    uint64_t l_jedec_trrd = 0;
    // Calculate tRRD_L
    {
        int64_t l_trrd_l_mtb = 0;
        int64_t l_trrd_l_ftb = 0;

        FAPI_TRY( iv_spd_decoder.min_trrd_l(l_trrd_l_mtb),
                  "Failed min_trrd_l() for %s", mss::c_str(iv_dimm) );

        FAPI_TRY( iv_spd_decoder.fine_offset_min_trrd_l(l_trrd_l_ftb),
                  "Failed fine_offset_min_trrd_l() for %s", mss::c_str(iv_dimm) );

        FAPI_INF("%s medium timebase (ps): %ld, fine timebase (ps): %ld, trrd_l (MTB): %ld",
                 mss::c_str(iv_dimm), iv_mtb, iv_ftb, l_trrd_l_mtb);

        l_trrd_l_in_ps = spd::calc_timing_from_timebase(l_trrd_l_mtb, iv_mtb, l_trrd_l_ftb, iv_ftb);

        FAPI_ASSERT( l_trrd_l_in_ps >= 0,
                     fapi2::MSS_INVALID_TIMING_VALUE()
                     .set_VALUE(l_trrd_l_in_ps)
                     .set_DIMM_TARGET(iv_dimm)
                     .set_FUNCTION(TRRD_L),
                     "%s Error calculating tRRD_L (%d). Less than or equal to 0",
                     mss::c_str(iv_dimm),
                     l_trrd_l_in_ps);


        FAPI_DBG("TRRD_L in ps is %d", l_trrd_l_in_ps);

        FAPI_TRY( spd::calc_nck(l_trrd_l_in_ps, iv_tCK_in_ps, spd::INVERSE_DDR4_CORRECTION_FACTOR, l_trrd_l_in_nck),
                  "Error in calculating l_tFAW for target %s, with value of l_trrd_l_in_ps: %d",
                  mss::c_str(iv_dimm),
                  l_trrd_l_in_nck);
    }

    FAPI_TRY( trrd_l( iv_dimm, iv_dram_width, iv_freq, l_jedec_trrd) );

    // Taking the worst case between the required minimum JEDEC value and the proposed value from SPD
    if (l_jedec_trrd != l_trrd_l_in_nck)
    {
        FAPI_INF("%s TRRD_L from JEDEC (%d) and from SPD (%d) don't match. Choosing worst case. dram width %d, freq %d",
                 mss::c_str(iv_dimm),
                 l_jedec_trrd,
                 l_trrd_l_in_nck,
                 iv_dram_width,
                 iv_freq);

        l_trrd_l_in_nck = std::max( l_jedec_trrd, l_trrd_l_in_nck);
    }

    FAPI_INF("SDRAM width: %d, tFAW (nck): %d for target: %s",
             iv_dram_width, l_trrd_l_in_nck, mss::c_str(iv_dimm));

    // Get & update MCS attribute
    FAPI_TRY( eff_dram_trrd_l(iv_mcs, l_attrs_dram_trrd_l.data()) );

    // DIMM's can have separate timings in a dual-drop system.
    // In those cases, we want to take the safest (most pessimistic) values
    l_attrs_dram_trrd_l[iv_port_index] = std::max(static_cast<uint8_t>(l_trrd_l_in_nck),
                                         l_attrs_dram_trrd_l[iv_port_index]);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRRD_L,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_trrd_l, PORTS_PER_MCS)),
              "Failed setting attribute for DRAM_TRRD_L");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tRRD_dlr
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dram_trrd_dlr()
{

    std::vector<uint8_t> l_attrs_dram_trrd_dlr(PORTS_PER_MCS, 0);
    constexpr uint64_t l_trrd_dlr_in_nck = trrd_dlr();

    FAPI_INF("tRRD_dlr (nck): %d for target: %s", l_trrd_dlr_in_nck, mss::c_str(iv_dimm));

    // Get & update MCS attribute
    FAPI_TRY( eff_dram_trrd_dlr(iv_mcs, l_attrs_dram_trrd_dlr.data()) );

    l_attrs_dram_trrd_dlr[iv_port_index] = l_trrd_dlr_in_nck;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRRD_DLR,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_trrd_dlr, PORTS_PER_MCS)),
              "Failed setting attribute for DRAM_TRRD_DLR");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tfaw
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dram_tfaw()
{
    std::vector<uint8_t> l_attrs_dram_tfaw(PORTS_PER_MCS, 0);
    uint64_t l_tfaw_in_nck = 0;
    uint64_t l_jedec_tfaw_in_nck = 0;
    int64_t l_tfaw_in_ps = 0;
    int64_t l_tfaw_ftb = 0;

    // Calculate tFAW
    {
        int64_t l_tfaw_mtb = 0;

        FAPI_TRY( iv_spd_decoder.min_tfaw(l_tfaw_mtb),
                  "Failed min_tfaw() for %s", mss::c_str(iv_dimm) );

        FAPI_INF("%s medium timebase (ps): %ld, fine timebase (ps): %ld, tfaw (MTB): %ld",
                 mss::c_str(iv_dimm), iv_mtb, iv_ftb, l_tfaw_mtb);

        l_tfaw_in_ps = spd::calc_timing_from_timebase(l_tfaw_mtb, iv_mtb, l_tfaw_ftb, iv_ftb);

        FAPI_ASSERT( l_tfaw_in_ps >= 0,
                     fapi2::MSS_INVALID_TIMING_VALUE()
                     .set_VALUE(l_tfaw_in_ps)
                     .set_DIMM_TARGET(iv_dimm)
                     .set_FUNCTION(TFAW),
                     "%s Error calculating tFAW (%d). Less than or equal to 0",
                     mss::c_str(iv_dimm),
                     l_tfaw_in_ps);

        FAPI_DBG("%s TFAW in ps is %d", mss::c_str(iv_dimm), l_tfaw_in_ps);

        FAPI_TRY( spd::calc_nck(l_tfaw_in_ps, iv_tCK_in_ps, spd::INVERSE_DDR4_CORRECTION_FACTOR, l_tfaw_in_nck),
                  "Error in calculating l_tFAW for target %s, with value of l_tfaw_in_ps: %d",
                  mss::c_str(iv_dimm),
                  l_tfaw_in_nck);
    }

    FAPI_TRY( mss::tfaw(iv_dimm, iv_dram_width, iv_freq, l_jedec_tfaw_in_nck), "Failed tfaw()" );

    // Taking the worst case between the required minimum JEDEC value and the proposed value from SPD
    if (l_jedec_tfaw_in_nck != l_tfaw_in_nck)
    {
        FAPI_INF("%s TFAW from JEDEC (%d) and from SPD (%d) don't match. Choosing worst case. dram width %d, freq %d",
                 mss::c_str(iv_dimm),
                 l_jedec_tfaw_in_nck,
                 l_tfaw_in_nck,
                 iv_dram_width,
                 iv_freq);

        l_tfaw_in_nck = std::max(l_jedec_tfaw_in_nck, l_tfaw_in_nck);
    }

    FAPI_INF("SDRAM width: %d, tFAW (nck): %d for target: %s",
             iv_dram_width, l_tfaw_in_nck, mss::c_str(iv_dimm));

    // Get & update MCS attribute
    FAPI_TRY( eff_dram_tfaw(iv_mcs, l_attrs_dram_tfaw.data()) );

    // DIMM's can have separate timings in a dual-drop system.
    // In those cases, we want to take the safest (most pessimistic) values
    l_attrs_dram_tfaw[iv_port_index] = std::max(static_cast<uint8_t>(l_tfaw_in_nck), l_attrs_dram_tfaw[iv_port_index]);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TFAW,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_tfaw, PORTS_PER_MCS)),
              "Failed setting attribute for DRAM_TFAW");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tFAW_DLR
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dram_tfaw_dlr()
{

    std::vector<uint8_t> l_attrs_dram_tfaw_dlr(PORTS_PER_MCS, 0);
    constexpr uint64_t l_tfaw_dlr_in_nck = tfaw_dlr();

    FAPI_INF("tFAW_dlr (nck): %d for target: %s", l_tfaw_dlr_in_nck, mss::c_str(iv_dimm));

    // Get & update MCS attribute
    FAPI_TRY( eff_dram_tfaw_dlr(iv_mcs, l_attrs_dram_tfaw_dlr.data()) );

    l_attrs_dram_tfaw_dlr[iv_port_index] = l_tfaw_dlr_in_nck;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TFAW_DLR,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_tfaw_dlr, PORTS_PER_MCS)),
              "Failed setting attribute for DRAM_TFAW_DLR");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tRAS
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dram_tras()
{

    // tRAS is bin independent so we don't read this from SPD
    // which will give the best timing value for the dimm
    // (like 2400 MT/s) which may be different than the system
    // speed (if we were being limited by VPD or MRW restrictions)
    uint64_t l_tras_in_ps;
    uint64_t l_freq = 0;
    uint8_t l_tras_in_nck = 0;

    // Calculate nck
    std::vector<uint8_t> l_attrs_dram_tras(PORTS_PER_MCS, 0);

    FAPI_TRY( freq(mss::find_target<fapi2::TARGET_TYPE_MCBIST>(iv_dimm), l_freq) );
    l_tras_in_ps = mss::tras(iv_dimm, l_freq);

    // Cast needed for calculations to be done on the same integral type
    // as required by template deduction. We have iv_tCK_in_ps as a signed
    // integer because we have other timing values that calculations do
    // addition with negative integers.
    FAPI_TRY( spd::calc_nck(l_tras_in_ps,
                            static_cast<uint64_t>(iv_tCK_in_ps),
                            spd::INVERSE_DDR4_CORRECTION_FACTOR,
                            l_tras_in_nck),
              "Error in calculating tras_l for target %s, with value of l_twtr_in_ps: %d",
              mss::c_str(iv_dimm), l_tras_in_ps);

    FAPI_INF("tCK (ps): %d, tRAS (ps): %d, tRAS (nck): %d for target: %s",
             iv_tCK_in_ps, l_tras_in_ps, l_tras_in_nck, mss::c_str(iv_dimm));

    // Get & update MCS attribute
    FAPI_TRY( eff_dram_tras(iv_mcs, l_attrs_dram_tras.data()) );

    // DIMM's can have separate timings in a dual-drop system.
    // In those cases, we want to take the safest (most pessimistic) values
    l_attrs_dram_tras[iv_port_index] = std::max(l_tras_in_nck, l_attrs_dram_tras[iv_port_index]);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRAS,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_tras, PORTS_PER_MCS)),
              "Failed setting attribute for tRAS");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tRTP
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::dram_trtp()
{
    // Values from proposed DDR4 Full spec update(79-4A)
    // Item No. 1716.78C
    // Page 241 & 246
    int64_t constexpr l_max_trtp_in_ps = trtp();

    std::vector<uint8_t> l_attrs_dram_trtp(PORTS_PER_MCS, 0);
    uint8_t l_calc_trtp_in_nck = 0;

    // Calculate nck
    FAPI_TRY( spd::calc_nck(l_max_trtp_in_ps, iv_tCK_in_ps, spd::INVERSE_DDR4_CORRECTION_FACTOR, l_calc_trtp_in_nck),
              "Error in calculating trtp  for target %s, with value of l_twtr_in_ps: %d",
              mss::c_str(iv_dimm), l_max_trtp_in_ps);

    FAPI_INF("tCK (ps): %d, tRTP (ps): %d, tRTP (nck): %d",
             iv_tCK_in_ps, l_max_trtp_in_ps, l_calc_trtp_in_nck);

    // Get & update MCS attribute
    FAPI_TRY( eff_dram_trtp(iv_mcs, l_attrs_dram_trtp.data()) );

    // DIMM's can have separate timings in a dual-drop system.
    // In those cases, we want to take the safest (most pessimistic) values
    l_attrs_dram_trtp[iv_port_index] = std::max(l_attrs_dram_trtp[iv_port_index], l_calc_trtp_in_nck);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRTP,
                            iv_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_trtp, PORTS_PER_MCS)),
              "Failed setting attribute for DRAM_TRTP");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets the RTT_NOM value for the eff_dimm
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note used for MRS01
///
fapi2::ReturnCode eff_rdimm::dram_rtt_nom()
{
    constexpr size_t RTT_NOM_MAP_SIZE = 8;
    uint8_t l_decoder_val = 0;
    uint8_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};

    // Temp holders to grab attributes to then parse into value for this dimm and rank
    uint8_t l_rtt_nom[MAX_RANK_PER_DIMM] {};
    // Indexed by denominator. So, if RQZ is 240, and you have OHM240, then you're looking
    // for mss::index 1. So this doesn't correspond directly with the table in the JEDEC spec,
    // as that's not in "denominator order."
    //                                                  0  RQZ/1  RQZ/2  RQZ/3  RQZ/4  RQZ/5  RQZ/6  RQZ/7
    constexpr uint8_t rtt_nom_map[RTT_NOM_MAP_SIZE] = { 0, 0b100, 0b010, 0b110, 0b001, 0b101, 0b011, 0b111 };

    size_t l_rtt_nom_index = 0;
    std::vector< uint64_t > l_ranks;

    FAPI_TRY( mss::vpd_mt_dram_rtt_nom(iv_dimm, &(l_rtt_nom[0])) );
    FAPI_TRY( eff_dram_rtt_nom(iv_mcs, &l_mcs_attrs[0][0][0]) );

    // Calculate the value for each rank and store in attribute

    FAPI_TRY(mss::rank::ranks(iv_dimm, l_ranks));

    for (const auto& l_rank : l_ranks)
    {
        // We have to be careful about 0
        l_rtt_nom_index = (l_rtt_nom[mss::index(l_rank)] == 0) ?
                          0 : fapi2::ENUM_ATTR_MSS_VPD_MT_DRAM_RTT_NOM_OHM240 / l_rtt_nom[mss::index(l_rank)];

        // Make sure it's a valid mss::index
        FAPI_ASSERT( l_rtt_nom_index < RTT_NOM_MAP_SIZE,
                     fapi2::MSS_INVALID_RTT_NOM_CALCULATIONS()
                     .set_RANK(l_rank)
                     .set_RTT_NOM_INDEX(l_rtt_nom_index)
                     .set_RTT_NOM_FROM_VPD(l_rtt_nom[mss::index(l_rank)])
                     .set_DIMM_TARGET(iv_dimm),
                     "Error calculating RTT_NOM for target %s rank %d, rtt_nom from vpd is %d, index is %d",
                     mss::c_str(iv_dimm),
                     l_rank,
                     l_rtt_nom[mss::index(l_rank)],
                     l_rtt_nom_index);

        // Map from RTT_NOM array to the value in the map
        l_decoder_val = rtt_nom_map[l_rtt_nom_index];

        // Store value and move to next rank
        l_mcs_attrs[iv_port_index][iv_dimm_index][mss::index(l_rank)] = l_decoder_val;
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_RTT_NOM, iv_mcs, l_mcs_attrs) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for the RTT_NOM value
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note used for MRS01
///
fapi2::ReturnCode eff_lrdimm::dram_rtt_nom()
{
    constexpr uint8_t DRAM_RTT_VALUES[NUM_VALID_RANKS_CONFIGS] =
    {
        0b111, // 2R - 34Ohm
        0b111, // 4R - 34Ohm
    };
    std::vector< uint64_t > l_ranks;

    uint8_t l_decoder_val = 0;
    uint8_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};

    mss::states l_ism386 = mss::states::NO;

    FAPI_TRY( eff_dram_rtt_nom(iv_mcs, &l_mcs_attrs[0][0][0]) );

    // Get the value from the LRDIMM SPD
    FAPI_TRY( iv_spd_decoder.dram_rtt_nom(iv_freq, l_decoder_val));

    // Plug into every rank position for the attribute so it'll fit the same style as the RDIMM value
    // Same value for every rank for LRDIMMs
    FAPI_TRY(mss::rank::ranks(iv_dimm, l_ranks));

    for (const auto& l_rank : l_ranks)
    {
        // Workaround in m386a8k40cm2_ctd7y
        // Use specific ODT values for specific dimm according to dimm part number.
        FAPI_TRY( is_m386a8k40cm2_ctd7y_helper(l_ism386));

        if(l_ism386 != mss::states::NO)
        {
            l_mcs_attrs[iv_port_index][iv_dimm_index][mss::index(l_rank)] = DRAM_RTT_VALUES[iv_master_ranks_index];
        }
        else
        {
            l_mcs_attrs[iv_port_index][iv_dimm_index][mss::index(l_rank)] = l_decoder_val;
        }
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_RTT_NOM, iv_mcs, l_mcs_attrs) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for the RTT_WR value from SPD
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note used for MRS02
///
fapi2::ReturnCode eff_rdimm::dram_rtt_wr()
{
    std::vector< uint64_t > l_ranks;
    uint8_t l_encoding = 0;
    uint8_t l_dram_rtt_wr[MAX_RANK_PER_DIMM] = {};
    uint8_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};

    // RTT_WR mapping
    static const std::vector< std::pair<uint8_t, uint8_t> > l_rtt_wr_map =
    {
        { fapi2::ENUM_ATTR_MSS_VPD_MT_DRAM_RTT_WR_DISABLE, 0b000 },
        { fapi2::ENUM_ATTR_MSS_VPD_MT_DRAM_RTT_WR_HIGHZ,   0b011 },
        { fapi2::ENUM_ATTR_MSS_VPD_MT_DRAM_RTT_WR_OHM80,   0b100 },
        { fapi2::ENUM_ATTR_MSS_VPD_MT_DRAM_RTT_WR_OHM120,  0b001 },
        { fapi2::ENUM_ATTR_MSS_VPD_MT_DRAM_RTT_WR_OHM240,  0b010 }
    };

    // Retrieve current MCS level attribute
    FAPI_TRY( eff_dram_rtt_wr(iv_mcs, &l_mcs_attrs[0][0][0]) );

    // Get RTT_WR from VPD
    FAPI_TRY( mss::vpd_mt_dram_rtt_wr(iv_dimm, &(l_dram_rtt_wr[0])) );

    // Calculate the value for each rank and store in attribute
    FAPI_TRY(mss::rank::ranks(iv_dimm, l_ranks));

    for (const auto& l_rank : l_ranks)
    {
        FAPI_ASSERT( mss::find_value_from_key(l_rtt_wr_map, l_dram_rtt_wr[mss::index(l_rank)], l_encoding),
                     fapi2::MSS_INVALID_RTT_WR()
                     .set_RTT_WR(l_dram_rtt_wr[l_rank])
                     .set_RANK(mss::index(l_rank)),
                     "unknown RTT_WR 0x%x (%s rank %d), dynamic odt off",
                     l_dram_rtt_wr[mss::index(l_rank)],
                     mss::c_str(iv_dimm),
                     mss::index(l_rank));

        // Store value and move to next rank
        l_mcs_attrs[iv_port_index][iv_dimm_index][mss::index(l_rank)] = l_encoding;
    }

    // Set the attribute
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_RTT_WR, iv_mcs, l_mcs_attrs) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for the RTT_WR value from SPD
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note used for MRS02
///
fapi2::ReturnCode eff_lrdimm::dram_rtt_wr()
{
    constexpr uint8_t DRAM_RTT_VALUES[NUM_VALID_RANKS_CONFIGS] =
    {
        0b000, // 2R - disable
        0b001, // 4R - 120Ohm
    };
    std::vector< uint64_t > l_ranks;

    uint8_t l_decoder_val = 0;
    uint8_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};
    FAPI_TRY( eff_dram_rtt_wr(iv_mcs, &l_mcs_attrs[0][0][0]) );

    // Get the value from the LRDIMM SPD
    FAPI_TRY( iv_spd_decoder.dram_rtt_wr(iv_freq, l_decoder_val));

    // Plug into every rank position for the attribute so it'll fit the same style as the RDIMM value
    // Same value for every rank for LRDIMMs
    FAPI_TRY(mss::rank::ranks(iv_dimm, l_ranks));

    for (const auto& l_rank : l_ranks)
    {
        // Workaround in m386a8k40cm2_ctd7y
        // Use specific ODT values for specific dimm according to dimm part number.
        mss::states l_ism386 = mss::states::NO;
        FAPI_TRY( is_m386a8k40cm2_ctd7y_helper(l_ism386));

        if(l_ism386 != mss::states::NO)
        {
            l_mcs_attrs[iv_port_index][iv_dimm_index][mss::index(l_rank)] = DRAM_RTT_VALUES[iv_master_ranks_index];
        }
        else
        {
            l_mcs_attrs[iv_port_index][iv_dimm_index][mss::index(l_rank)] = l_decoder_val;
        }
    }

    // Set the attribute
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_RTT_WR, iv_mcs, l_mcs_attrs) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for the RTT_PARK value from SPD
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note used for MRS05
///
fapi2::ReturnCode eff_rdimm::dram_rtt_park()
{
    std::vector< uint64_t > l_ranks;

    uint8_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};

    // Indexed by denominator. So, if RQZ is 240, and you have OHM240, then you're looking
    // for mss::index 1. So this doesn't correspond directly with the table in the JEDEC spec,
    // as that's not in "denominator order."
    constexpr uint64_t RTT_PARK_COUNT = 8;
    //                                                       0  RQZ/1  RQZ/2  RQZ/3  RQZ/4  RQZ/5  RQZ/6  RQZ/7
    constexpr uint8_t const rtt_park_map[RTT_PARK_COUNT] = { 0, 0b100, 0b010, 0b110, 0b001, 0b101, 0b011, 0b111 };

    uint8_t l_rtt_park[MAX_RANK_PER_DIMM] = {};

    FAPI_TRY( mss::vpd_mt_dram_rtt_park(iv_dimm, &(l_rtt_park[0])) );
    FAPI_TRY( eff_dram_rtt_park(iv_mcs, &l_mcs_attrs[0][0][0]) );

    // Calculate the value for each rank and store in attribute
    FAPI_TRY(mss::rank::ranks(iv_dimm, l_ranks));

    for (const auto& l_rank : l_ranks)
    {
        uint8_t l_rtt_park_index = 0;

        // We have to be careful about 0
        l_rtt_park_index = (l_rtt_park[mss::index(l_rank)] == 0) ?
                           0 : fapi2::ENUM_ATTR_MSS_VPD_MT_DRAM_RTT_PARK_240OHM / l_rtt_park[mss::index(l_rank)];

        // Map from RTT_PARK array to the value in the map
        l_mcs_attrs[iv_port_index][iv_dimm_index][mss::index(l_rank)] = rtt_park_map[l_rtt_park_index];
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_RTT_PARK, iv_mcs, l_mcs_attrs) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for the RTT_PARK value from SPD
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note used for MRS05
///
fapi2::ReturnCode eff_lrdimm::dram_rtt_park()
{
    constexpr uint8_t DRAM_RTT_VALUES[NUM_VALID_RANKS_CONFIGS] =
    {
        0b000, // 2R - disable
        0b010, // 4R - 120Ohm
    };
    uint8_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};
    uint8_t l_decoder_val_01 = 0;
    uint8_t l_decoder_val_23 = 0;
    mss::states l_ism386 = mss::states::NO;

    FAPI_TRY( eff_dram_rtt_park(iv_mcs, &l_mcs_attrs[0][0][0]) );

    // Workaround in m386a8k40cm2_ctd7y
    // Use specific ODT values for specific dimm according to dimm part number.
    FAPI_TRY( is_m386a8k40cm2_ctd7y_helper(l_ism386));

    if(l_ism386 != mss::states::NO)
    {
        for(uint64_t l_rank = 0; l_rank < MAX_RANK_PER_DIMM; ++l_rank)
        {
            // Gets the ODT scheme for the DRAM for this DIMM - we only want to toggle ODT to the DIMM we are writing to
            // We do a bitwise mask here to only get the ODT for the current DIMM
            l_mcs_attrs[iv_port_index][iv_dimm_index][mss::index(l_rank)] = DRAM_RTT_VALUES[iv_master_ranks_index];
        }
    }
    else
    {
        // Get the value from the LRDIMM SPD
        FAPI_TRY( iv_spd_decoder.dram_rtt_park_ranks0_1(iv_freq, l_decoder_val_01),
                  "%s failed to decode RTT_PARK for ranks 0/1", mss::c_str(iv_mcs) );
        FAPI_TRY( iv_spd_decoder.dram_rtt_park_ranks2_3(iv_freq, l_decoder_val_23),
                  "%s failed to decode RTT_PARK for ranks 2/3", mss::c_str(iv_mcs) );

        // Setting the four rank values for this dimm
        // Rank 0 and 1 have the same value, l_decoder_val_01
        // Rank 2 and 3 have the same value, l_decoder_val_23
        l_mcs_attrs[iv_port_index][iv_dimm_index][ATTR_RANK0] = l_decoder_val_01;
        l_mcs_attrs[iv_port_index][iv_dimm_index][ATTR_RANK1] = l_decoder_val_01;
        l_mcs_attrs[iv_port_index][iv_dimm_index][ATTR_RANK2] = l_decoder_val_23;
        l_mcs_attrs[iv_port_index][iv_dimm_index][ATTR_RANK3] = l_decoder_val_23;
    }

    // Set the attribute
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_RTT_PARK, iv_mcs, l_mcs_attrs) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets the LRDIMM training pattern
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_lrdimm::lrdimm_training_pattern()
{
    // Default patterns are taken from experiments
    // Patterns were selected for having a good balance of transitions
    // We need the temporary variable due to how FAPI_ATTR_SET works
    uint8_t l_default_patterns[NUM_LRDIMM_TRAINING_PATTERNS] =
    {
        0x2b,
        0x3c,
        0x96,
        0x35,
        0x6a,
    };

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_LRDIMM_TRAINING_PATTERN, iv_mcs, l_default_patterns) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM BC00
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Host Interface DQ RTT_NOM Control
/// From DDR4DB02 Spec Rev 0.95
/// Page 56 table 23
///
fapi2::ReturnCode eff_lrdimm::dimm_bc00()
{
    // RTT WR has a timing issue for the host interface for LRDIMM, so we set RTT_WR's value into RTT_NOM
    // RTT_WR mapping -> RTT_NOM's equivalent values
    static const std::vector< std::pair<uint8_t, uint8_t> > l_rtt_wr_map =
    {
        { fapi2::ENUM_ATTR_MSS_VPD_MT_DRAM_RTT_WR_DISABLE, 0b000 },
        // Hi-z to disable - best we can do
        { fapi2::ENUM_ATTR_MSS_VPD_MT_DRAM_RTT_WR_HIGHZ,   0b000 },
        { fapi2::ENUM_ATTR_MSS_VPD_MT_DRAM_RTT_WR_OHM80,   0b110 },
        { fapi2::ENUM_ATTR_MSS_VPD_MT_DRAM_RTT_WR_OHM120,  0b010 },
        { fapi2::ENUM_ATTR_MSS_VPD_MT_DRAM_RTT_WR_OHM240,  0b100 }
    };

    // All LRDIMMS in the eyes of the MC are 1 rank, so say it's rank 0 for calculations
    constexpr uint8_t l_rank = 0;

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_bc00[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Temp holders to grab attributes to then parse into value for this dimm and rank
    uint8_t l_vpd[MAX_RANK_PER_DIMM] = {};
    uint8_t l_encoding = 0;

    FAPI_TRY( mss::vpd_mt_dram_rtt_wr(iv_dimm, &(l_vpd[0])) );

    // Calculate the value for each rank and store in attribute
    FAPI_ASSERT( mss::find_value_from_key(l_rtt_wr_map, l_vpd[mss::index(l_rank)], l_encoding),
                 fapi2::MSS_INVALID_RTT_WR()
                 .set_RTT_WR(l_vpd[l_rank])
                 .set_RANK(mss::index(l_rank)),
                 "unknown RTT_WR 0x%x (%s rank %d), dynamic odt off",
                 l_vpd[mss::index(l_rank)],
                 mss::c_str(iv_dimm),
                 mss::index(l_rank));

    // Read, modify, write
    FAPI_TRY( eff_dimm_ddr4_bc00(iv_mcs, &l_attrs_dimm_bc00[0][0]) );
    l_attrs_dimm_bc00[iv_port_index][iv_dimm_index] = l_encoding;

    FAPI_INF("%s: BC00 settting: %d", mss::c_str(iv_dimm), l_attrs_dimm_bc00[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_BC00, iv_mcs, l_attrs_dimm_bc00) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM BC01
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Host Interface DQ RTT_WR Control
/// From DDR4DB02 Spec Rev 0.95
/// Page 56 Table 24
///
fapi2::ReturnCode eff_lrdimm::dimm_bc01()
{
    // LRDIMM has a timing issue for RTT_WR
    constexpr uint8_t RTT_WR_DISABLE = 0b000;

    // Read, modify, write
    uint8_t l_attrs_dimm_bc01[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_bc01(iv_mcs, &l_attrs_dimm_bc01[0][0]) );

    l_attrs_dimm_bc01[iv_port_index][iv_dimm_index] = RTT_WR_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_BC01, iv_mcs, l_attrs_dimm_bc01) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM BC02
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Host Interface DQ RTT_PARK Control
/// From DDR4DB02 Spec Rev 0.95
/// Page 56 Table 25
///
fapi2::ReturnCode eff_lrdimm::dimm_bc02()
{
    // Due to RTT_WR being set to RTT_NOM, we set RTT_NOM to RTT_PARK
    uint8_t l_decoder_val = 0;
    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_bc02[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    uint8_t l_rank = 0;
    // Indexed by denominator. So, if RQZ is 240, and you have OHM240, then you're looking
    // for mss::index 1. So this doesn't correspond directly with the table in the JEDEC spec,
    // as that's not in "denominator order."
    constexpr uint64_t RTT_PARK_COUNT = 8;
    //                                                               0     RQZ/1    RQZ/2    RQZ/3   RQZ/4    RQZ/5    RQZ/6    RQZ/7
    constexpr uint8_t rtt_park_map[RTT_PARK_COUNT] = { 0, 0b100, 0b010, 0b110, 0b001, 0b101, 0b011, 0b111 };

    uint8_t l_rtt_park[MAX_RANK_PER_DIMM];
    uint8_t l_rtt_park_index = 0;

    FAPI_TRY( mss::vpd_mt_dram_rtt_nom(iv_dimm, &(l_rtt_park[0])) );

    // We have to be careful about 0
    l_rtt_park_index = (l_rtt_park[l_rank] == 0) ?
                       0 : fapi2::ENUM_ATTR_MSS_VPD_MT_DRAM_RTT_PARK_240OHM / l_rtt_park[l_rank];

    // Make sure it's a valid index
    FAPI_ASSERT( l_rtt_park_index < RTT_PARK_COUNT,
                 fapi2::MSS_INVALID_RTT_PARK_CALCULATIONS()
                 .set_RANK(l_rank)
                 .set_RTT_PARK_INDEX(l_rtt_park_index)
                 .set_RTT_PARK_FROM_VPD(l_rtt_park[mss::index(l_rank)])
                 .set_DIMM_TARGET(iv_dimm),
                 "Error calculating RTT_PARK for target %s rank %d, rtt_park from vpd is %d, index is %d",
                 mss::c_str(iv_dimm),
                 l_rank,
                 l_rtt_park[mss::index(l_rank)],
                 l_rtt_park_index);

    // Map from RTT_PARK array to the value in the map
    l_decoder_val = rtt_park_map[l_rtt_park_index];

    FAPI_TRY( eff_dimm_ddr4_bc02(iv_mcs, &l_attrs_dimm_bc02[0][0]) );
    l_attrs_dimm_bc02[iv_port_index][iv_dimm_index] = l_decoder_val;

    FAPI_INF("%s: BC02 settting: %d", mss::c_str(iv_dimm), l_attrs_dimm_bc02[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_BC02, iv_mcs, l_attrs_dimm_bc02) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM BC03
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Host Interface DQ Driver Control Word
/// From DDR4DB01 Spec Rev 1.0
/// 2.5.5 Page 57 table 36
///
fapi2::ReturnCode eff_lrdimm_db01::dimm_bc03()
{
    uint8_t l_attrs_dimm_bc03[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // constants
    // Little table to map Output Driver Imepdance Control according to DDR4DB02 4.5
    static const std::vector< std::pair<uint64_t, uint8_t> > l_odic_map =
    {
        // Yes, this is the encoding listed in the JEDEC spec...
        {fapi2::ENUM_ATTR_MSS_VPD_MT_DRAM_DRV_IMP_DQ_DQS_OHM34, 0b001},
        {fapi2::ENUM_ATTR_MSS_VPD_MT_DRAM_DRV_IMP_DQ_DQS_OHM40, 0b000},
        {fapi2::ENUM_ATTR_MSS_VPD_MT_DRAM_DRV_IMP_DQ_DQS_OHM48, 0b010},
    };

    // Treat buffer as 0th rank. LRDIMM in memory controller's eyes only have 1 rank
    constexpr size_t l_rank = 0;
    fapi2::buffer<uint8_t> l_result = 0;
    uint64_t l_ohm_value = 0;
    uint8_t l_encoding = 0;
    // attributes
    uint8_t l_odic[MAX_RANK_PER_DIMM] = {};
    FAPI_TRY( mss::vpd_mt_dram_drv_imp_dq_dqs(iv_dimm, &(l_odic[0])) );
    // Get the Ohm value for rank 0
    l_ohm_value = l_odic[l_rank];

    // Now get the proper encoding for that value. Fail if not found
    // Change for rev level
    FAPI_ASSERT( mss::find_value_from_key(l_odic_map, l_ohm_value, l_encoding),
                 fapi2::MSS_BAD_MR_PARAMETER()
                 .set_MR_NUMBER(1)
                 .set_PARAMETER(OUTPUT_IMPEDANCE)
                 .set_PARAMETER_VALUE(l_odic[mss::index(l_rank)])
                 .set_DIMM_IN_ERROR(iv_dimm),
                 "Bad value for output driver impedance: %d (%s)",
                 l_odic[mss::index(l_rank)], mss::c_str(iv_dimm));

    l_result = l_encoding;

    // Using a writeBit for clarity sake
    // Enabling Host interface DQ/DQS driver
    l_result.writeBit<BC03_HOST_DQ_DISABLE_POS>(BC03_HOST_DQ_ENABLE);

    FAPI_TRY( eff_dimm_ddr4_bc03(iv_mcs, &l_attrs_dimm_bc03[0][0]) );
    l_attrs_dimm_bc03[iv_port_index][iv_dimm_index] = l_result;

    FAPI_INF("%s: BC03 settting: %d", mss::c_str(iv_dimm), l_attrs_dimm_bc03[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_BC03, iv_mcs, l_attrs_dimm_bc03) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM BC03
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Host Interface DQ Driver Control Word
/// From DDR4DB02 Spec Rev 0.95
/// Page 57 Table 26
///
fapi2::ReturnCode eff_lrdimm_db02::dimm_bc03()
{
    uint8_t l_attrs_dimm_bc03[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // constants
    // Little table to map Output Driver Imepdance Control according to DDR4DB02 4.5
    static const std::vector< std::pair<uint64_t, uint8_t> > l_odic_map =
    {
        // Yes, this is the order and encoding listed in the JEDEC spec...
        {fapi2::ENUM_ATTR_MSS_VPD_MT_DRAM_DRV_IMP_DQ_DQS_OHM30, 0b011},
        {fapi2::ENUM_ATTR_MSS_VPD_MT_DRAM_DRV_IMP_DQ_DQS_OHM34, 0b001},
        {fapi2::ENUM_ATTR_MSS_VPD_MT_DRAM_DRV_IMP_DQ_DQS_OHM40, 0b000},
        {fapi2::ENUM_ATTR_MSS_VPD_MT_DRAM_DRV_IMP_DQ_DQS_OHM48, 0b010}
    };

    // Treat buffer as 0th rank. LRDIMM in our eyes only have 1 rank
    constexpr size_t l_rank = 0;
    fapi2::buffer<uint8_t> l_result;
    uint64_t l_ohm_value = 0;
    uint8_t l_encoding = 0;
    // attributes
    uint8_t l_odic[MAX_RANK_PER_DIMM] = {};
    FAPI_TRY( mss::vpd_mt_dram_drv_imp_dq_dqs(iv_dimm, &(l_odic[0])) );
    // Get the Ohm value for rank 0
    l_ohm_value = l_odic[l_rank];

    // Now get the proper encoding for that value. Fail if not found
    // Change for rev level
    FAPI_ASSERT( mss::find_value_from_key(l_odic_map, l_ohm_value, l_encoding),
                 fapi2::MSS_BAD_MR_PARAMETER()
                 .set_MR_NUMBER(1)
                 .set_PARAMETER(OUTPUT_IMPEDANCE)
                 .set_PARAMETER_VALUE(l_odic[mss::index(l_rank)])
                 .set_DIMM_IN_ERROR(iv_dimm),
                 "Bad value for output driver impedance: %d (%s)",
                 l_odic[mss::index(l_rank)], mss::c_str(iv_dimm));

    l_result = l_encoding;

    // Using a writeBit for clarity sake
    // Enabling DQ/DQS drivers
    l_result.writeBit<BC03_HOST_DQ_DISABLE_POS>(BC03_HOST_DQ_ENABLE);

    // Retrieve MCS attribute data
    FAPI_TRY( eff_dimm_ddr4_bc03(iv_mcs, &l_attrs_dimm_bc03[0][0]) );
    l_attrs_dimm_bc03[iv_port_index][iv_dimm_index] = l_result;

    FAPI_INF("%s: BC03 settting: %d, vpd_drv_dram_imp is %d",
             mss::c_str(iv_dimm),
             l_attrs_dimm_bc03[iv_port_index][iv_dimm_index],
             l_ohm_value);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_BC03, iv_mcs, l_attrs_dimm_bc03) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM BC04
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note DRAM Interface MDQ RTT Control Word
/// From DDR4DB02 Spec Rev 0.95
/// Page 60 Table 24
/// @note Uses MDQ Read Termination Strength (RTT)
/// From DDR4DB02 Spec Rev 0.95
/// Page 57 Table 27
/// DRAM Interface MDQ/MDQS ODT Strength for Data Buffer
/// Comes from SPD
///
fapi2::ReturnCode eff_lrdimm::dimm_bc04()
{
    uint8_t l_decoder_val = 0;
    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_bc04[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_bc04(iv_mcs, &l_attrs_dimm_bc04[0][0]) );

    // So the encoding from the SPD is the same as the encoding for the buffer control encoding
    // Simple grab and insert
    // Value is checked in decoder function for validity
    FAPI_TRY( iv_spd_decoder.data_buffer_mdq_rtt(iv_freq, l_decoder_val) );
    l_attrs_dimm_bc04[iv_port_index][iv_dimm_index] = l_decoder_val;

    // Update MCS attribute
    FAPI_INF("%s: BC04 settting (MDQ_RTT): %d", mss::c_str(iv_dimm), l_attrs_dimm_bc04[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_BC04, iv_mcs, l_attrs_dimm_bc04) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM BC05
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note DRAM Interface MDQ Driver Control Word
/// From DDR4DB02 Spec Rev 0.95
/// Page 57 Table 28
/// @note DRAM Interface MDQ/MDQS Output Driver Impedance control
///
fapi2::ReturnCode eff_lrdimm::dimm_bc05()
{
    uint8_t l_decoder_val = 0;

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_bc05[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_bc05(iv_mcs, &l_attrs_dimm_bc05[0][0]) );

    // Same as BC04, grab from SPD and put into BC
    FAPI_TRY( iv_spd_decoder.data_buffer_mdq_drive_strength(iv_freq, l_decoder_val) );
    l_attrs_dimm_bc05[iv_port_index][iv_dimm_index] = l_decoder_val;

    FAPI_INF("%s: BC05 settting (MDQ Drive Strength): %d", mss::c_str(iv_dimm),
             l_attrs_dimm_bc05[iv_port_index][iv_dimm_index] );

    // Updates the attribute
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_BC05, iv_mcs, l_attrs_dimm_bc05) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM BC06
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @noteCommand Space Control Word
/// From DDR4DB02 Spec Rev 0.95
/// Page 57 Table 28
/// @note DRAM Interface MDQ/MDQS Output Driver Impedance control
///
fapi2::ReturnCode eff_lrdimm::dimm_bc06()
{
    constexpr uint8_t RESET_DLL = 0x00;

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_bc06[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_bc06(iv_mcs, &l_attrs_dimm_bc06[0][0]) );

    l_attrs_dimm_bc06[iv_port_index][iv_dimm_index] = RESET_DLL;

    FAPI_INF("%s: BC06 settting (Command Space Control Word): 0x%02x", mss::c_str(iv_dimm),
             l_attrs_dimm_bc06[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_BC06, iv_mcs, l_attrs_dimm_bc06) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM BC07
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Rank Presence Control Word
/// From DDR4DB02 Spec Rev 0.95
/// 2.5.9 Page 58 Table 30
/// Tells the buffer which drams are enabled
///
fapi2::ReturnCode eff_lrdimm::dimm_bc07()
{
    // Map for the bc07 attribute, Each bit and its position represents one rank
    // 0b0 == enabled, 0b1 == disabled
    //                                                      1 rank  2 rank  3 rank  4 rank
    constexpr uint8_t const dram_map [MAX_RANK_PER_DIMM] = {0b1110, 0b1100, 0b1000, 0b0000};
    uint8_t l_ranks_per_dimm = 0;

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_bc07[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // It is safe to use the attribute accessor directly since it is set in mss_freq
    FAPI_TRY( eff_num_master_ranks_per_dimm(iv_dimm, l_ranks_per_dimm) );
    FAPI_TRY( eff_dimm_ddr4_bc07(iv_mcs, &l_attrs_dimm_bc07[0][0]) );

    // Subtract so 1 rank == 0, 2 rank == 1, etc. For array mss::indexing
    --l_ranks_per_dimm;
    // Make sure we didn't overflow or screw up somehow
    // TK Thoughts on if we need an official error code below??
    FAPI_ASSERT(l_ranks_per_dimm < MAX_RANK_PER_DIMM,
                fapi2::MSS_OUT_OF_BOUNDS_INDEXING()
                .set_TARGET(iv_dimm)
                .set_INDEX(l_ranks_per_dimm)
                .set_LIST_SIZE(MAX_RANK_PER_DIMM)
                .set_FUNCTION(EFF_BC07),
                "%s has ranks per dimm (%u) out of bounds: %u",
                mss::c_str(iv_dimm), l_ranks_per_dimm, MAX_RANK_PER_DIMM);

    l_attrs_dimm_bc07[iv_port_index][iv_dimm_index] = dram_map[l_ranks_per_dimm];

    FAPI_INF("%s: BC07 settting: %d", mss::c_str(iv_dimm), l_attrs_dimm_bc07[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_BC07, iv_mcs, l_attrs_dimm_bc07) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM BC08
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Power Saving Settings Control Word
/// From DDR4DB02 Spec Rev 0.95
/// Page 60 Table 24
///
fapi2::ReturnCode eff_lrdimm::dimm_bc08()
{
    // Some constants made for changing code in the future
    // Hard coding values for now until characterization can be done.
    // Not sure if info needs to be added to VPD or MRW or what

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_bc08[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Update MCS attribute
    FAPI_TRY( eff_dimm_ddr4_bc08(iv_mcs, &l_attrs_dimm_bc08[0][0]) );
    // BC08 is used to set the rank for Write Leveling training modes
    // This value is used in training so a value of 0 is fine for now
    l_attrs_dimm_bc08[iv_port_index][iv_dimm_index] = 0;

    FAPI_INF("%s: BC08 settting: %d", mss::c_str(iv_dimm), l_attrs_dimm_bc08[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_BC08, iv_mcs, l_attrs_dimm_bc08) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM BC09
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Power Saving Settings Control Word
/// From DDR4DB02 Spec Rev 0.95
/// Page 60 Table 24
///
fapi2::ReturnCode eff_lrdimm::dimm_bc09()
{
    // Some constants made for changing code in the future
    // Hard coding values for now until characterization can be done.
    // Not sure if info needs to be added to VPD or MRW or what
    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_bc09[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    fapi2::buffer<uint8_t> l_setting = 0;

    // Enabling power down mode (when CKE's are low!) to bring us inline with RC09/RCD powerdown mode
    l_setting.writeBit<BC09_CKE_POWER_DOWN_ENABLE_POS>(BC09_CKE_POWER_DOWN_ENABLE)
    .writeBit<BC09_CKE_POWER_ODT_POS>(BC09_CKE_POWER_ODT_OFF);

    // Update MCS attribute
    FAPI_TRY( eff_dimm_ddr4_bc09(iv_mcs, &l_attrs_dimm_bc09[0][0]) );
    l_attrs_dimm_bc09[iv_port_index][iv_dimm_index] = l_setting;

    FAPI_INF("%s: BC09 settting: %d", mss::c_str(iv_dimm), l_attrs_dimm_bc09[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_BC09, iv_mcs, l_attrs_dimm_bc09) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets  config for DIMM BC0a
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note LRDIMM Operating Speed
/// From DDR4DB02 Spec Rev 0.95
/// Page 60 Table 24
///
fapi2::ReturnCode eff_lrdimm::dimm_bc0a()
{
    uint8_t l_encoding = 0;

    static const std::vector< std::pair<uint64_t, uint8_t> > l_freq_map =
    {
        // There's also 1600, 2933, and 3200 but Nimbus can't support those...
        {fapi2::ENUM_ATTR_MSS_FREQ_MT1866, 0b001},
        {fapi2::ENUM_ATTR_MSS_FREQ_MT2133, 0b010},
        {fapi2::ENUM_ATTR_MSS_FREQ_MT2400, 0b011},
        {fapi2::ENUM_ATTR_MSS_FREQ_MT2666, 0b100},
    };

    uint8_t l_attrs_dimm_bc0a[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Find the correct mapping from freq to encoding
    FAPI_ASSERT( mss::find_value_from_key(l_freq_map, uint64_t(iv_freq), l_encoding),
                 fapi2::MSS_INVALID_FREQ_BC()
                 .set_FREQ(iv_freq)
                 .set_BC_NUM(BC0A)
                 .set_DIMM_TARGET(iv_dimm),
                 "unknown FREQ %d for %s in bc0a",
                 iv_freq,
                 mss::c_str(iv_dimm));

    // Retrieve MCS attribute data
    FAPI_TRY( eff_dimm_ddr4_bc0a(iv_mcs, &l_attrs_dimm_bc0a[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_bc0a[iv_port_index][iv_dimm_index] = l_encoding;

    FAPI_INF("%s: BC0a settting: %d", mss::c_str(iv_dimm), l_attrs_dimm_bc0a[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_BC0A, iv_mcs, l_attrs_dimm_bc0a) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM BC0b
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// From DDR4DB01 Spec Rev 1.0
/// 2.5.13 Page 60 table 34
/// @note Operating Voltage
///
fapi2::ReturnCode eff_lrdimm_db01::dimm_bc0b()
{
    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_bc0b[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_bc0b(iv_mcs, &l_attrs_dimm_bc0b[0][0]) );

    // Update MCS attribute
    // Only option is to set it to 0 to signify 1.2 operating Voltage, everything else is reserved
    // Per the IBM signal integrity team, the default value should be sufficient
    l_attrs_dimm_bc0b[iv_port_index][iv_dimm_index] = 0;

    FAPI_INF("%s: BC0b settting: %d", mss::c_str(iv_dimm), l_attrs_dimm_bc0b[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_BC0B, iv_mcs, l_attrs_dimm_bc0b) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM BC0b
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Operating Voltage and Host Side Output Slew Rate Control Word
/// From DDR4DB02 Spec Rev 0.95
/// Page 60 Table 24
///
fapi2::ReturnCode eff_lrdimm_db02::dimm_bc0b()
{
    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_bc0b[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_bc0b(iv_mcs, &l_attrs_dimm_bc0b[0][0]) );

    // Update MCS attribute
    // Bits 0~1 (IBM numbering) are for slew rate
    // Bit 3 is reserved, Bit 4 has to be 0 to signal 1.2 V Buffer Vdd Voltage
    // Hard coding values to 0, sets slew rate to Moderate (according to Dan Phipps, this is fine)
    // Per the IBM signal integrity team, the default value should be sufficient
    l_attrs_dimm_bc0b[iv_port_index][iv_dimm_index] = 0;

    FAPI_INF("%s: BC0b settting: %d", mss::c_str(iv_dimm), l_attrs_dimm_bc0b[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_BC0B, iv_mcs, l_attrs_dimm_bc0b) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM BC0c
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note LDQ Operation Control Word
/// From DDR4DB01 Spec Rev 1.0
/// Page 60 Table 24
///
fapi2::ReturnCode eff_lrdimm_db01::dimm_bc0c()
{
    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_bc0c[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_bc0c(iv_mcs, &l_attrs_dimm_bc0c[0][0]) );

    // Update MCS attribute
    // This attribute is used to set the training mode
    // Setting it to 0 to signal default normal mode
    l_attrs_dimm_bc0c[iv_port_index][iv_dimm_index] = 0;

    FAPI_INF("%s: BC0c settting: %d", mss::c_str(iv_dimm), l_attrs_dimm_bc0c[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_BC0D, iv_mcs, l_attrs_dimm_bc0c) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM BC0c
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note LDQ Operation Control Word
/// From DDR4DB02 Spec Rev 0.95
/// Page 60 Table 24
///
fapi2::ReturnCode eff_lrdimm_db02::dimm_bc0c()
{
    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_bc0c[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_bc0c(iv_mcs, &l_attrs_dimm_bc0c[0][0]) );

    // Update MCS attribute
    // Setting it to 0 to signal default normal mode
    // This attribute is used to set the training mode
    l_attrs_dimm_bc0c[iv_port_index][iv_dimm_index] = 0;

    FAPI_INF("%s: BC0c settting: %d", mss::c_str(iv_dimm), l_attrs_dimm_bc0c[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_BC0D, iv_mcs, l_attrs_dimm_bc0c) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM BC0d
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Reserved for future use - set it to 0 for now
/// From DDR4DB01 Spec Rev 1.0
/// Page 61 Table 25
/// All values are reserved for DB01, setting to 0
///
fapi2::ReturnCode eff_lrdimm_db01::dimm_bc0d()
{
    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_bc0d[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_bc0d(iv_mcs, &l_attrs_dimm_bc0d[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_bc0d[iv_port_index][iv_dimm_index] = 0;

    FAPI_INF("%s: BC0d settting: %d", mss::c_str(iv_dimm), l_attrs_dimm_bc0d[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_BC0D, iv_mcs, l_attrs_dimm_bc0d) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM BC0d
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Reserved for future use - set it to 0 for now
/// From DDR4DB02 Spec Rev 0.95
/// Page 60 Table 24
/// @note This register is used by the Non Volatile controller (NVC) to change the mode of operation of the DDR4DB02
/// Setting to 0 (LDQ port disabled, normal operation)
///
fapi2::ReturnCode eff_lrdimm_db02::dimm_bc0d()
{
    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_bc0d[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_bc0d(iv_mcs, &l_attrs_dimm_bc0d[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_bc0d[iv_port_index][iv_dimm_index] = 0;

    FAPI_INF("%s: BC0d settting: %d", mss::c_str(iv_dimm), l_attrs_dimm_bc0d[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_BC0D, iv_mcs, l_attrs_dimm_bc0d) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM BC0e
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Parity Control Word
/// From DDR4DB02 Spec Rev 0.95
/// Page 60 Table 24
///
fapi2::ReturnCode eff_lrdimm::dimm_bc0e()
{
    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_bc0e[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_bc0e(iv_mcs, &l_attrs_dimm_bc0e[0][0]) );

    // Update MCS attribute
    // Disabling parity checking for the BCOM bus (interal DRAM to buffer on dimm) and sequence checking by the data buffer
    l_attrs_dimm_bc0e[iv_port_index][iv_dimm_index] = 0;


    FAPI_INF("%s: BC0e settting: %d", mss::c_str(iv_dimm), l_attrs_dimm_bc0e[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_BC0E, iv_mcs, l_attrs_dimm_bc0e) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM BC0f
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Error Status Word for parity and sequence error
///
fapi2::ReturnCode eff_lrdimm::dimm_bc0f()
{
    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_bc0f[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_bc0f(iv_mcs, &l_attrs_dimm_bc0f[0][0]) );

    // Update MCS attribute
    // BC0F is an error register so setting to 0 and it will change as reads as performed
    l_attrs_dimm_bc0f[iv_port_index][iv_dimm_index] = 0;

    FAPI_INF("%s: BC0f settting: %d", mss::c_str(iv_dimm), l_attrs_dimm_bc0f[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_BC0E, iv_mcs, l_attrs_dimm_bc0f) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines and sets DIMM BC1x
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_lrdimm::dimm_f0bc1x()
{
    // Enables package rank timing
    // The LR buffers will have the same timing communicating to the host
    constexpr uint8_t DEFAULT = 0x80;
    uint8_t l_attrs_dimm_bc_1x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Retrieve MCS attribute data
    FAPI_TRY( eff_dimm_ddr4_f0bc1x(iv_mcs, &l_attrs_dimm_bc_1x[0][0]) );

    // Setup to default as we want to be in runtime mode
    l_attrs_dimm_bc_1x[iv_port_index][iv_dimm_index] = DEFAULT;

    FAPI_INF( "%s: F0BC1X setting: 0x%02x", mss::c_str(iv_dimm), l_attrs_dimm_bc_1x[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_F0BC1x, iv_mcs, l_attrs_dimm_bc_1x) );


fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines and sets DIMM BC6x
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_lrdimm::dimm_f0bc6x()
{
    uint8_t l_attrs_dimm_bc_6x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Retrieve MCS attribute data
    FAPI_TRY( eff_dimm_ddr4_f0bc6x(iv_mcs, &l_attrs_dimm_bc_6x[0][0]) );

    // Frequency encoding is the same as rc3x, so reusing here
    switch(iv_freq)
    {
        case fapi2::ENUM_ATTR_MSS_FREQ_MT1866:
            l_attrs_dimm_bc_6x[iv_port_index][iv_dimm_index] = rc3x_encode::MT1860_TO_MT1880;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2133:
            l_attrs_dimm_bc_6x[iv_port_index][iv_dimm_index] = rc3x_encode::MT2120_TO_MT2140;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2400:
            l_attrs_dimm_bc_6x[iv_port_index][iv_dimm_index] = rc3x_encode::MT2380_TO_MT2400;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2666:
            l_attrs_dimm_bc_6x[iv_port_index][iv_dimm_index] = rc3x_encode::MT2660_TO_MT2680;
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_FREQ_RC()
                         .set_FREQ(iv_freq)
                         .set_RC_NUM(F0BC6X)
                         .set_DIMM_TARGET(iv_dimm),
                         "%s: Invalid frequency for BC_6X encoding received: %d",
                         mss::c_str(iv_dimm),
                         iv_freq);
            break;
    }

    FAPI_INF( "%s: F0BC6X setting: 0x%02x", mss::c_str(iv_dimm), l_attrs_dimm_bc_6x[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_F0BC6x, iv_mcs, l_attrs_dimm_bc_6x) );


fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines and sets DIMM F2BCEx
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_lrdimm::dimm_f2bcex()
{
    uint8_t l_attrs_dimm_f2bcex[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Retrieve MCS attribute data
    FAPI_TRY( eff_dimm_ddr4_f2bcex(iv_mcs, &l_attrs_dimm_f2bcex[0][0]) );

    // Setup to default as we want to be in runtime mode (not DFE mode)
    l_attrs_dimm_f2bcex[iv_port_index][iv_dimm_index] = 0;

    FAPI_INF( "%s: F2BCEX setting: 0x%02x", mss::c_str(iv_dimm), l_attrs_dimm_f2bcex[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_F2BCEx, iv_mcs, l_attrs_dimm_f2bcex) );


fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines and sets DIMM F5BC5x
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_lrdimm::dimm_f5bc5x()
{
    // Taken from DDR4 (this attribute is DDR4 only) spec MRS6 section VrefDQ training: values table
    constexpr uint8_t JEDEC_MAX_TRAIN_VALUE   = 0b00110010;

    // Gets the JEDEC VREFDQ range and value
    fapi2::buffer<uint8_t> l_train_value;
    fapi2::buffer<uint8_t> l_train_range;
    uint8_t l_attrs_dimm_f5bc5x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Retrieve MCS attribute data
    FAPI_TRY( eff_dimm_ddr4_f5bc5x(iv_mcs, &l_attrs_dimm_f5bc5x[0][0]) );
    FAPI_TRY(mss::get_vpd_wr_vref_range_and_value(iv_dimm, l_train_range, l_train_value));

    FAPI_ASSERT(l_train_value <= JEDEC_MAX_TRAIN_VALUE,
                fapi2::MSS_INVALID_VPD_VREF_DRAM_WR_RANGE()
                .set_MAX(JEDEC_MAX_TRAIN_VALUE)
                .set_VALUE(l_train_value)
                .set_MCS_TARGET(iv_mcs),
                "%s VPD DRAM VREF value out of range max 0x%02x value 0x%02x", mss::c_str(iv_dimm),
                JEDEC_MAX_TRAIN_VALUE, l_train_value );

    // F5BC5x is just the VREF training range
    l_attrs_dimm_f5bc5x[iv_port_index][iv_dimm_index] = l_train_value;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_F5BC5x, iv_mcs, l_attrs_dimm_f5bc5x),
              "Failed setting attribute for ATTR_EFF_DIMM_DDR4_F5BC5x");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines and sets DIMM F5BC6x
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_lrdimm::dimm_f5bc6x()
{
    uint8_t l_decode = 0;
    uint8_t l_attrs_dimm_f5bc6x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Retrieve MCS attribute data
    FAPI_TRY( eff_dimm_ddr4_f5bc6x(iv_mcs, &l_attrs_dimm_f5bc6x[0][0]) );

    // Gets the SPD value
    FAPI_TRY( iv_spd_decoder.data_buffer_vref_dq(l_decode));

    // F5BC6x is just the VREF training range
    l_attrs_dimm_f5bc6x[iv_port_index][iv_dimm_index] = l_decode;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_F5BC6x, iv_mcs, l_attrs_dimm_f5bc6x),
              "Failed setting attribute for ATTR_EFF_DIMM_DDR4_F5BC6x");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines and sets DIMM F6BC4x
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_lrdimm::dimm_f6bc4x()
{
    constexpr uint64_t WR_VREFDQ_BIT = 6;
    constexpr uint64_t RD_VREFDQ_BIT = 5;

    uint8_t l_attrs_dimm_f6bc4x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    uint8_t l_buffer_rd_vref_range = 0;
    uint8_t l_buffer_wr_vref_range = 0;
    uint8_t l_wr_vref_value = 0; // Used in F5BC5x, but we need it for a helper function
    fapi2::buffer<uint8_t> l_temp;

    // Retrieve MCS attribute data
    FAPI_TRY( eff_dimm_ddr4_f6bc4x(iv_mcs, &l_attrs_dimm_f6bc4x[0][0]) );

    // Gets the WR VREF range
    FAPI_TRY( get_vpd_wr_vref_range_and_value(iv_dimm, l_buffer_wr_vref_range, l_wr_vref_value) );

    // Gets the RD VREF range
    FAPI_TRY( iv_spd_decoder.data_buffer_vref_dq_range(l_buffer_rd_vref_range) );

    // Setup to default as we want to be in runtime mode
    l_temp.writeBit<WR_VREFDQ_BIT>(l_buffer_wr_vref_range)
    .writeBit<RD_VREFDQ_BIT>(l_buffer_rd_vref_range);
    l_attrs_dimm_f6bc4x[iv_port_index][iv_dimm_index] = l_temp;

    FAPI_INF( "%s: F6BC4X setting: 0x%02x", mss::c_str(iv_dimm), l_attrs_dimm_f6bc4x[iv_port_index][iv_dimm_index] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_F6BC4x, iv_mcs, l_attrs_dimm_f6bc4x) );


fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DRAM output driver impedance control
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_lrdimm::dram_odic()
{
    constexpr uint8_t DRAM_ODIC_VALUES[NUM_VALID_RANKS_CONFIGS] =
    {
        fapi2::ENUM_ATTR_MSS_VPD_MT_DRAM_DRV_IMP_DQ_DQS_OHM34, // 2 ranks per DIMM
        fapi2::ENUM_ATTR_MSS_VPD_MT_DRAM_DRV_IMP_DQ_DQS_OHM34, // 4 ranks per DIMM
    };

    uint8_t l_dram_odic[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};
    FAPI_TRY( eff_dram_odic(iv_mcs, &l_dram_odic[0][0][0]));

    // Updates DRAM ODIC with the VPD value
    for(uint8_t l_rank = 0; l_rank < MAX_RANK_PER_DIMM; ++l_rank)
    {
        // JEDEC setting - taken from SI spreadsheet
        l_dram_odic[iv_port_index][iv_dimm_index][mss::index(l_rank)] = DRAM_ODIC_VALUES[iv_master_ranks_index];
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_ODIC, iv_mcs, l_dram_odic) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Grab the VPD blobs and decode into attributes
/// @param[in] i_target FAPI2 target (MCS)
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::decode_vpd(const fapi2::Target<TARGET_TYPE_MCS>& i_target)
{
    uint8_t l_mr_blob[mss::VPD_KEYWORD_MAX] = {};
    uint8_t l_cke_blob[mss::VPD_KEYWORD_MAX] = {};
    uint8_t l_dq_blob[mss::VPD_KEYWORD_MAX] = {};
    uint64_t l_freq = 0;

    std::vector<uint8_t*> l_mt_blobs(PORTS_PER_MCS, nullptr);
    fapi2::VPDInfo<fapi2::TARGET_TYPE_MCS> l_vpd_info(fapi2::MemVpdData::MT);

    // For sanity. Not sure this will break us, but we're certainly making assumptions below.
    static_assert(MAX_DIMM_PER_PORT == 2, "Max DIMM per port isn't 2");
    FAPI_TRY( mss::freq(find_target<fapi2::TARGET_TYPE_MCBIST>(i_target), l_freq));

    // We need to set up all VPD info before calling getVPD, the API assumes this
    // For MR we need to tell the VPDInfo the frequency (err ... mt/s - why is this mhz?)
    l_vpd_info.iv_freq_mhz = l_freq;
    FAPI_INF("%s. VPD info - dimm data rate: %d MT/s", mss::c_str(i_target), l_vpd_info.iv_freq_mhz);

    // Make sure to create 0 filled blobs for all the possible blobs, not just for the
    // chiplets which are configured. This prevents the decoder from accessing nullptrs
    // but the code which uses the VPD will only access the information for the chiplets
    // which exist - so the 0's are meaningless
    for (auto& b : l_mt_blobs)
    {
        b = new uint8_t[mss::VPD_KEYWORD_MAX];
        memset(b, 0, mss::VPD_KEYWORD_MAX);
    }

    // For MT we need to fill in the rank information
    // But, of course, the rank information can differ per port. However, the vpd interface doesn't
    // allow this in a straight-forward way. So, we have to get VPD blobs for MCS which contain
    // ports which have the rank configuration in question. This means, basically, we pass a MCS MT
    // blob to the decoder for each MCA, regardless of whether the port configurations are the same.
    for (const auto& p : find_targets<TARGET_TYPE_MCA>(i_target))
    {
        if (mss::count_dimm(p) == 0)
        {
            FAPI_INF("No DIMMs found for %s... skipping", mss::c_str(i_target));
            continue;
        }

        // Find our blob in the vector of blob pointers
        uint8_t* l_mt_blob = l_mt_blobs[mss::index(p)];

        // Sets up the number of ranks for this port
        FAPI_TRY(configure_vpd_ranks<mss::proc_type::NIMBUS>(p, l_vpd_info), "%s failed to configure the ranks on the VPD",
                 mss::c_str(p));

        FAPI_INF("%s. VPD info - rank count for dimm_0: %d, dimm_1: %d",
                 mss::c_str(i_target), l_vpd_info.iv_rank_count_dimm_0, l_vpd_info.iv_rank_count_dimm_1);

        // Get the MCS blob for this specific rank combination *only if* we have DIMM. Remember,
        // Cronus can give us functional MCA which have no DIMM - and we'd puke getting the VPD.
        // Which again, shouldn't happen w/the DIMM check above.

        // If getVPD returns us an error, then we don't have VPD for the DIMM configuration.
        // This is the root of our plug-rules: if you want a configuration of DIMM to be
        // supported, it needs to have VPD defined. Likewise, if you don't want a configuration
        // of DIMM supported be sure to leave it out of the VPD. Note that we don't return a specific
        // plug-rule error as f/w (Dan) suggested this would duplicate errors leading to confusion.
        l_vpd_info.iv_vpd_type = fapi2::MemVpdData::MT;

        // Check the max for giggles. Programming bug so we should assert.
        FAPI_TRY( fapi2::getVPD(i_target, l_vpd_info, nullptr),
                  "Failed to retrieve MT size from VPD");

        FAPI_ASSERT( l_vpd_info.iv_size <= mss::VPD_KEYWORD_MAX,
                     fapi2::MSS_INVALID_VPD_KEYWORD_MAX().
                     set_MAX(mss::VPD_KEYWORD_MAX).
                     set_ACTUAL(l_vpd_info.iv_size).
                     set_KEYWORD(fapi2::MemVpdData::MT).
                     set_VPD_TARGET(i_target),
                     "VPD MT keyword size retrieved: %d, is larger than max: %d for %s",
                     l_vpd_info.iv_size, mss::VPD_KEYWORD_MAX, mss::c_str(i_target));

        // Log any error code from getVPD separately in case the error code is meaningful
        FAPI_TRY( fapi2::getVPD(i_target, l_vpd_info, &(l_mt_blob[0])) );

        // Only get the MR blob if we have a freq. It's possible for Cronus to give us an MCS which
        // is connected to a controller which has 0 DIMM installed. In this case, we won't have
        // a frequency, and thus we'd fail getting the VPD. So we initiaized the VPD to 0's and if
        // there's no freq, we use a 0 filled VPD.
        if (l_vpd_info.iv_freq_mhz != 0)
        {
            l_vpd_info.iv_vpd_type = fapi2::MemVpdData::MR;

            // Check the max for giggles. Programming bug so we should assert.
            FAPI_TRY( fapi2::getVPD(i_target, l_vpd_info, nullptr),
                      "Failed to retrieve MR size from VPD");

            FAPI_ASSERT( l_vpd_info.iv_size <= mss::VPD_KEYWORD_MAX,
                         fapi2::MSS_INVALID_VPD_KEYWORD_MAX().
                         set_MAX(mss::VPD_KEYWORD_MAX).
                         set_ACTUAL(l_vpd_info.iv_size).
                         set_KEYWORD(fapi2::MemVpdData::MR).
                         set_VPD_TARGET(i_target),
                         "VPD MR keyword size retrieved: %d, is larger than max: %d for %s",
                         l_vpd_info.iv_size, mss::VPD_KEYWORD_MAX, mss::c_str(i_target));

            // Log any error code from getVPD separately in case the error code is meaningful
            FAPI_TRY( fapi2::getVPD(i_target, l_vpd_info, &(l_mr_blob[0])) );
        }
    }// mca

    // Get CKE data
    l_vpd_info.iv_vpd_type = fapi2::MemVpdData::CK;

    // Check the max for giggles. Programming bug so we should assert.
    FAPI_TRY( fapi2::getVPD(i_target, l_vpd_info, nullptr),
              "Failed to retrieve CK size from VPD");

    FAPI_ASSERT( l_vpd_info.iv_size <= mss::VPD_KEYWORD_MAX,
                 fapi2::MSS_INVALID_VPD_KEYWORD_MAX().
                 set_MAX(mss::VPD_KEYWORD_MAX).
                 set_ACTUAL(l_vpd_info.iv_size).
                 set_KEYWORD(fapi2::MemVpdData::CK).
                 set_VPD_TARGET(i_target),
                 "VPD CK keyword size retrieved: %d, is larger than max: %d for %s",
                 l_vpd_info.iv_size, mss::VPD_KEYWORD_MAX, mss::c_str(i_target));

    FAPI_TRY( fapi2::getVPD(i_target, l_vpd_info, &(l_cke_blob[0])),
              "Failed to retrieve DQ VPD");

    // Get DQ data
    l_vpd_info.iv_vpd_type = fapi2::MemVpdData::DQ;

    // Check the max for giggles. Programming bug so we should assert.
    FAPI_TRY( fapi2::getVPD(i_target, l_vpd_info, nullptr),
              "Failed to retrieve DQ size from VPD");

    FAPI_ASSERT( l_vpd_info.iv_size <= mss::VPD_KEYWORD_MAX,
                 fapi2::MSS_INVALID_VPD_KEYWORD_MAX().
                 set_MAX(mss::VPD_KEYWORD_MAX).
                 set_ACTUAL(l_vpd_info.iv_size).
                 set_KEYWORD(fapi2::MemVpdData::DQ).
                 set_VPD_TARGET(i_target),
                 "VPD DQ keyword size retrieved: %d, is larger than max: %d for %s",
                 l_vpd_info.iv_size, mss::VPD_KEYWORD_MAX, mss::c_str(i_target));

    FAPI_TRY( fapi2::getVPD(i_target, l_vpd_info, &(l_dq_blob[0])),
              "Failed to retrieve DQ VPD");

    FAPI_TRY( mss::eff_decode(i_target, l_mt_blobs, l_mr_blob, l_cke_blob, l_dq_blob) );

fapi_try_exit:

    // delete the mt blobs
    for (auto p : l_mt_blobs)
    {
        if (p != nullptr)
        {
            delete[] p;
        }
    }

    return fapi2::current_err;
}

///
/// @brief Determines and sets the CUSTOM_TRAINING_ADV_PATTERNS settings for training advance
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note overwrite the attribute to default values if it's set to 0
///
fapi2::ReturnCode eff_dimm::training_adv_pattern()
{
    uint32_t l_special_patterns [PORTS_PER_MCS] = {};
    FAPI_TRY( custom_training_adv_patterns( iv_mcs, &(l_special_patterns[0])) );

    // Let's not write the defaults if someone wants to overwrite the attribute
    // 0 is an invalid pattern, so if it's 0, the attribute is empty
    if ( l_special_patterns[mss::index(iv_mca)] == 0)
    {
        fapi2::buffer<uint32_t> l_temp;

        l_temp.insertFromRight<PATTERN0_START, PATTERN0_LEN>
        (fapi2::ENUM_ATTR_MSS_CUSTOM_TRAINING_ADV_PATTERNS_DEFAULT_PATTERN0);

        l_temp.insertFromRight<PATTERN1_START, PATTERN1_LEN>
        (fapi2::ENUM_ATTR_MSS_CUSTOM_TRAINING_ADV_PATTERNS_DEFAULT_PATTERN1);

        l_special_patterns[mss::index(iv_mca)] = l_temp;

        FAPI_INF("%s setting training_adv_pattern as 0x%08x", mss::c_str(iv_mca), l_temp);

        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_CUSTOM_TRAINING_ADV_PATTERNS, iv_mcs, l_special_patterns) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines and sets the CUSTOM_TRAINING_ADV_BACKUP_PATTERNS settings for training advance
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note overwrite the attribute to default values if it's set to 0
///
fapi2::ReturnCode eff_dimm::training_adv_backup_pattern()
{
    uint32_t l_special_patterns [PORTS_PER_MCS] = {};
    FAPI_TRY( custom_training_adv_backup_patterns( iv_mcs, &(l_special_patterns[0])) );

    // Let's set the backup pattern as well
    if ( l_special_patterns[mss::index(iv_mca)] == 0)
    {
        fapi2::buffer<uint32_t> l_temp;

        l_temp.insertFromRight<PATTERN0_START, PATTERN0_LEN>
        (fapi2::ENUM_ATTR_MSS_CUSTOM_TRAINING_ADV_BACKUP_PATTERNS_DEFAULT_PATTERN0);

        l_temp.insertFromRight<PATTERN1_START, PATTERN1_LEN>
        (fapi2::ENUM_ATTR_MSS_CUSTOM_TRAINING_ADV_BACKUP_PATTERNS_DEFAULT_PATTERN1);

        l_special_patterns[mss::index(iv_mca)] = l_temp;

        FAPI_INF("%s setting training_adv_backup_pattern as 0x%08x", mss::c_str(iv_mca), l_temp);

        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_CUSTOM_TRAINING_ADV_BACKUP_PATTERNS, iv_mcs, l_special_patterns) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines and sets the ATTR_MSS_CUSTOM_TRAINING_ADV_BACKUP_PATTERNS2 settings
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note overwrite the attribute to default values if it's set to 0
///
fapi2::ReturnCode eff_dimm::training_adv_backup_pattern2()
{
    uint32_t l_special_patterns [PORTS_PER_MCS] = {};
    FAPI_TRY( custom_training_adv_backup_patterns2( iv_mcs, &(l_special_patterns[0])) );

    // Let's set the backup pattern as well
    if ( l_special_patterns[mss::index(iv_mca)] == 0)
    {
        fapi2::buffer<uint32_t> l_temp;

        l_temp.insertFromRight<PATTERN0_START, PATTERN0_LEN>
        (fapi2::ENUM_ATTR_MSS_CUSTOM_TRAINING_ADV_BACKUP_PATTERNS2_DEFAULT_PATTERN0);

        l_temp.insertFromRight<PATTERN1_START, PATTERN1_LEN>
        (fapi2::ENUM_ATTR_MSS_CUSTOM_TRAINING_ADV_BACKUP_PATTERNS2_DEFAULT_PATTERN1);

        l_special_patterns[mss::index(iv_mca)] = l_temp;

        FAPI_INF("%s setting training_adv_backup_pattern2 as 0x%08x", mss::c_str(iv_mca), l_temp);

        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_CUSTOM_TRAINING_ADV_BACKUP_PATTERNS2, iv_mcs, l_special_patterns) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines and sets the ATTR_MSS_CUSTOM_TRAINING_ADV_WR_PATTERN settings
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note overwrite the attribute to default values if it's set to 0
///
fapi2::ReturnCode eff_dimm::training_adv_wr_pattern()
{
    uint8_t l_special_patterns [PORTS_PER_MCS] = {};
    FAPI_TRY( custom_training_adv_wr_pattern( iv_mcs, &(l_special_patterns[0])) );

    // Let's set the backup pattern as well
    if ( l_special_patterns[mss::index(iv_mca)] == 0)
    {
        l_special_patterns[mss::index(iv_mca)] = fapi2::ENUM_ATTR_MSS_CUSTOM_TRAINING_ADV_WR_PATTERN_DEFAULT;

        FAPI_INF("%s setting training_adv_backup_pattern as 0x%02x", mss::c_str(iv_mca),
                 l_special_patterns[mss::index(iv_mca)]);

        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_CUSTOM_TRAINING_ADV_WR_PATTERN, iv_mcs, l_special_patterns) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines and sets the cal_step_enable values
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::cal_step_enable()
{
    fapi2::buffer<uint32_t> l_cal_step_value = (mss::chip_ec_feature_skip_hw_vref_cal(iv_mcs) ?
            RUN_CAL_SKIP_WR_RD_2D_VREF : RUN_ALL_CAL_STEPS);

    // We only run draminit training advance on DD2 modules
    constexpr uint64_t NUM_TRAIN_ADV = 2;
    l_cal_step_value = l_cal_step_value.writeBit<mss::TRAINING_ADV_RD, NUM_TRAIN_ADV>( !mss::chip_ec_nimbus_lt_2_0(
                           iv_mcs) );

    FAPI_DBG("%s %s running HW VREF cal. cal_step value: 0x%08x VREF, running training advance %s",
             mss::c_str(iv_mcs),
             mss::chip_ec_feature_skip_hw_vref_cal(iv_mcs) ? "not" : "",
             l_cal_step_value,
             l_cal_step_value.getBit<mss::TRAINING_ADV_RD>() ? "yes" : "no");

    // Sets up the vector
    std::vector<uint32_t> l_cal_step(PORTS_PER_MCS, l_cal_step_value);

    // Sets the value
    return FAPI_ATTR_SET(fapi2::ATTR_MSS_CAL_STEP_ENABLE, iv_mcs, UINT32_VECTOR_TO_1D_ARRAY(l_cal_step, PORTS_PER_MCS));
}

///
/// @brief if this dimm is M386A8K40CM2-CTD7Y
/// @param o_value record if this dimm is M386A8K40CM2-CTD7Y
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::is_m386a8k40cm2_ctd7y_helper(mss::states& o_value)
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
/// @brief Determines and sets the is_m386a8k40cm2_ctd7y values
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::is_m386a8k40cm2_ctd7y()
{
    // Sets up the vector
    mss::states l_ism386 = mss::states::NO;

    // Workaround in m386a8k40cm2_ctd7y
    // Use specific ODT values for specific dimm according to dimm part number.
    FAPI_TRY( is_m386a8k40cm2_ctd7y_helper(l_ism386));

    {
        // Sets up the vector
        std::vector<uint8_t> l_data_vector(PORTS_PER_MCS, l_ism386 == mss::states::NO ? 0 : 1);

        // Sets the value
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_IS_M386A8K40CM2_CTD7Y, iv_mcs, UINT8_VECTOR_TO_1D_ARRAY(l_data_vector,
                                PORTS_PER_MCS)));
    }

fapi_try_exit:
    return fapi2::current_err;
}
///
/// @brief Determines and sets the rdvref_enable_bit settings
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::rdvref_enable_bit()
{
    // This enables which bits should be run for RD VREF, all 1's indicates that all bits should be run
    constexpr uint16_t DISABLE = 0x0000;
    constexpr uint16_t ENABLE = 0xFFFF;

    const uint16_t l_vref_enable_value = (mss::chip_ec_feature_skip_hw_vref_cal(iv_mcs) ? DISABLE : ENABLE);

    FAPI_DBG("%s %s running HW VREF cal. VREF enable value: 0x%0x", mss::c_str(iv_mcs),
             mss::chip_ec_feature_skip_hw_vref_cal(iv_mcs) ? "not" : "", l_vref_enable_value);

    // Sets up the vector
    std::vector<uint16_t> l_vref_enable(PORTS_PER_MCS, l_vref_enable_value);

    // Sets the values
    return FAPI_ATTR_SET(fapi2::ATTR_MSS_RDVREF_CAL_ENABLE,
                         iv_mcs,
                         UINT16_VECTOR_TO_1D_ARRAY(l_vref_enable, PORTS_PER_MCS));
}

///
/// @brief Determines and sets ATTR_MSS_PHY_SEQ_REFRESH
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_dimm::phy_seq_refresh()
{
    // default setting is to turn on this workaround, this
    // isn't an ec_chip_feature attribute because there is no
    // known fix for this coming in DD2.0 modules. But the
    // lab wants a control switch
    constexpr size_t ENABLE = 1;

    FAPI_DBG("Setting PHY_SEQ_REFRESH to %d on %s", ENABLE, mss::c_str(iv_mcs));

    // Sets up the vector
    std::vector<uint8_t> l_phy_seq_ref_enable(PORTS_PER_MCS, ENABLE);

    // Sets the values
    return FAPI_ATTR_SET(fapi2::ATTR_MSS_PHY_SEQ_REFRESH,
                         iv_mcs,
                         UINT8_VECTOR_TO_1D_ARRAY(l_phy_seq_ref_enable, PORTS_PER_MCS));
}

///
/// @brief Determines & sets effective ODT write values
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_rdimm::odt_wr()
{
    uint8_t l_mcs_attr[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};
    uint8_t l_vpd_odt[MAX_RANK_PER_DIMM];

    // Gets the VPD value
    FAPI_TRY( mss::vpd_mt_odt_wr(iv_dimm, &(l_vpd_odt[0])));
    FAPI_TRY( eff_odt_wr( iv_mcs, &(l_mcs_attr[0][0][0])) );


    memcpy(&(l_mcs_attr[iv_port_index][iv_dimm_index][0]), l_vpd_odt, MAX_RANK_PER_DIMM);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EFF_ODT_WR, iv_mcs, l_mcs_attr) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective ODT write values
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_lrdimm::odt_wr()
{
    // Values were obtained experimentally
    // For 2R, opposite termination is ideal
    // For 4R, terminating everything is ideal
    constexpr uint8_t DRAM_ODT_VALUES[NUM_VALID_RANKS_CONFIGS][MAX_RANK_PER_DIMM] =
    {
        { 0x44, 0x88, 0x00, 0x00, }, // 2 ranks per DIMM
        { 0xcc, 0xcc, 0xcc, 0xcc, }, // 4 ranks per DIMM
    };

    constexpr uint8_t DRAM_ODT_VALUES_M386A8K40CM2[NUM_VALID_RANKS_CONFIGS][MAX_RANK_PER_DIMM] =
    {
        { 0x44, 0x88, 0x00, 0x00, }, // 2 ranks per DIMM
        { 0x44, 0x88, 0x44, 0x88, }, // 4 ranks per DIMM
    };
    // Masks on the ODT for a specific DIMM
    constexpr uint8_t DIMM_ODT_MASK[MAX_DIMM_PER_PORT] = { 0xf0, 0x0f };

    uint8_t l_mcs_attr[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};

    // Due to our RTT_WR->NOM->PARK swap, we just want to issue ODT's only to our DIMM
    // As the ODT values above do that for us, we're good to go (minus the DIMM masking)
    FAPI_TRY( eff_odt_wr( iv_mcs, &(l_mcs_attr[0][0][0])) );

    // Loops through and sets/updates all ranks
    for(uint64_t l_rank = 0; l_rank < MAX_RANK_PER_DIMM; ++l_rank)
    {
        // Gets the ODT scheme for the DRAM for this DIMM - we only want to toggle ODT to the DIMM we are writing to
        // We do a bitwise mask here to only get the ODT for the current DIMM
        auto l_dram_odt = DRAM_ODT_VALUES[iv_master_ranks_index][l_rank] & DIMM_ODT_MASK[iv_dimm_index];

        // Workaround in m386a8k40cm2_ctd7y
        // Use specific ODT values for specific dimm according to dimm part number.
        mss::states l_ism386 = mss::states::NO;
        FAPI_TRY( is_m386a8k40cm2_ctd7y_helper(l_ism386));

        if(l_ism386 != mss::states::NO)
        {
            l_dram_odt = DRAM_ODT_VALUES_M386A8K40CM2[iv_master_ranks_index][l_rank] & DIMM_ODT_MASK[iv_dimm_index];
        }

        // Do the final bitwise or
        l_mcs_attr[iv_port_index][iv_dimm_index][l_rank] = l_dram_odt;
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EFF_ODT_WR, iv_mcs, l_mcs_attr) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective PHY RLO values
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_rdimm::phy_rlo()
{
    uint8_t l_mcs_attr[PORTS_PER_MCS] = {};
    uint8_t l_vpd = 0;

    // Gets the VPD value
    FAPI_TRY( mss::vpd_mr_dphy_rlo(iv_mca, l_vpd));
    FAPI_TRY( eff_dphy_rlo( iv_mcs, &(l_mcs_attr[0])) );

    // Sets up the value
    l_mcs_attr[iv_port_index] = l_vpd;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EFF_DPHY_RLO, iv_mcs, l_mcs_attr) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective PHY RLO values
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_lrdimm::phy_rlo()
{
    constexpr uint8_t LR_OFFSET = 1;
    constexpr uint8_t RLO_MAX = 7;
    uint8_t l_mcs_attr[PORTS_PER_MCS] = {};
    uint8_t l_vpd = 0;

    // Gets the VPD value
    FAPI_TRY( mss::vpd_mr_dphy_rlo(iv_mca, l_vpd));
    FAPI_TRY( eff_dphy_rlo( iv_mcs, &(l_mcs_attr[0])) );

    // Sets up the value - ensure we don't have a rollover case
    l_mcs_attr[iv_port_index] = std::min(uint8_t(l_vpd + LR_OFFSET), RLO_MAX);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EFF_DPHY_RLO, iv_mcs, l_mcs_attr) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective PHY WLO values
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_rdimm::phy_wlo()
{
    uint8_t l_mcs_attr[PORTS_PER_MCS] = {};
    uint8_t l_vpd = 0;

    // Gets the VPD value
    FAPI_TRY( mss::vpd_mr_dphy_wlo(iv_mca, l_vpd));
    FAPI_TRY( eff_dphy_wlo( iv_mcs, &(l_mcs_attr[0])) );

    // Sets up the value
    l_mcs_attr[iv_port_index] = l_vpd;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EFF_DPHY_WLO, iv_mcs, l_mcs_attr) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective PHY WLO values
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_lrdimm::phy_wlo()
{
    constexpr uint8_t LR_OFFSET = 2;
    uint8_t l_mcs_attr[PORTS_PER_MCS] = {};
    uint8_t l_vpd = 0;

    // Gets the VPD value
    FAPI_TRY( mss::vpd_mr_dphy_wlo(iv_mca, l_vpd));
    FAPI_TRY( eff_dphy_wlo( iv_mcs, &(l_mcs_attr[0])) );

    // Sets up the value - ensure we don't have an underflow case
    l_mcs_attr[iv_port_index] = (l_vpd < LR_OFFSET) ? 0 : (l_vpd - LR_OFFSET);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EFF_DPHY_WLO, iv_mcs, l_mcs_attr) );

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Determines & sets effective ODT read values
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_rdimm::odt_rd()
{
    uint8_t l_mcs_attr[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};
    uint8_t l_vpd_odt[MAX_RANK_PER_DIMM];

    // Gets the VPD value
    FAPI_TRY( mss::vpd_mt_odt_rd(iv_dimm, &(l_vpd_odt[0])));
    FAPI_TRY( eff_odt_rd( iv_mcs, &(l_mcs_attr[0][0][0])) );


    memcpy(&(l_mcs_attr[iv_port_index][iv_dimm_index][0]), l_vpd_odt, MAX_RANK_PER_DIMM);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EFF_ODT_RD, iv_mcs, l_mcs_attr) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective ODT read values
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_lrdimm::odt_rd()
{
    constexpr uint8_t DRAM_ODT_VALUES[NUM_VALID_RANKS_CONFIGS][MAX_RANK_PER_DIMM] =
    {
        { 0x00, 0x00, 0x00, 0x00, }, // 2 ranks per DIMM
        { 0x44, 0x88, 0x44, 0x88, }, // 4 ranks per DIMM
    };

    // Masks on the ODT for a specific DIMM
    constexpr uint8_t DIMM_ODT_MASK[MAX_DIMM_PER_PORT] = { 0xf0, 0x0f };

    uint8_t l_mcs_attr[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};

    // Gets the VPD value
    FAPI_TRY( eff_odt_rd( iv_mcs, &(l_mcs_attr[0][0][0])) );

    // Due to our RTT_WR->NOM->PARK swap, we just want to issue ODT's only to our DIMM
    // As the ODT values above do that for us, we're good to go (minus the DIMM masking)
    // Loops through and sets/updates all ranks
    for(uint64_t l_rank = 0; l_rank < MAX_RANK_PER_DIMM; ++l_rank)
    {
        // Gets the ODT scheme for the DRAM for this DIMM - we only want to toggle ODT to the DIMM we are writing to
        // We do a bitwise mask here to only get the ODT for the current DIMM
        const auto l_dram_odt = DRAM_ODT_VALUES[iv_master_ranks_index][l_rank] & DIMM_ODT_MASK[iv_dimm_index];

        // Do the final bitwise or
        l_mcs_attr[iv_port_index][iv_dimm_index][l_rank] = l_dram_odt;
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EFF_ODT_RD, iv_mcs, l_mcs_attr) );

fapi_try_exit:
    return fapi2::current_err;
}

}//mss
